package test;


import com.saxonica.validate.SchemaAwareConfiguration;
import net.sf.saxon.AugmentedSource;
import net.sf.saxon.Configuration;
import net.sf.saxon.StandardErrorListener;
import net.sf.saxon.Version;
import net.sf.saxon.om.*;
import net.sf.saxon.pattern.NameTest;
import net.sf.saxon.pattern.NodeKindTest;
import net.sf.saxon.query.StaticQueryContext;
import net.sf.saxon.trans.XPathException;
import net.sf.saxon.type.SchemaException;
import net.sf.saxon.type.Type;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Source;
import javax.xml.transform.TransformerException;
import javax.xml.transform.stream.StreamSource;
import java.io.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.Date;
import java.util.HashMap;
import java.util.regex.Pattern;

/**
 * This class runs the W3C XML Schema Test Suite, driven from the test catalog.
 */
public class SchemaTestSuiteDriver {

    public final static String testNS = "http://www.w3.org/XML/2004/xml-schema-test-suite/";
    /**
     * Run the testsuite using Saxon.
     *
     * @param args Array of parameters passed to the application
     * via the command line.
     */
    public static void main(String[] args) throws Exception {
        if (args.length == 0 || args[0].equals("-?")) {
            System.err.println("SchemaTestSuiteDriver testDir [-w] -c:contributor? -s:setName? -g:groupName?");
        }
        System.err.println("Testing Saxon " + Version.getProductVersion());
        new SchemaTestSuiteDriver().go(args);
    }

    String testSuiteDir;
    SchemaAwareConfiguration catalogConfig;
    XMLReader parser;
    boolean showWarnings = true;

    Writer results;
    int xlinkHref;

    private NameTest elementNameTest(NamePool pool, String local) {
        int nameFP = pool.allocate("", testNS, local) & NamePool.FP_MASK;
        return new NameTest(Type.ELEMENT, nameFP, pool);
    }

    private NodeInfo getChildElement(NodeInfo parent, NameTest child) {
        return (NodeInfo)parent.iterateAxis(Axis.CHILD, child).next();
    }

    private DocumentInfo getLinkedDocument(NodeInfo element, SchemaAwareConfiguration targetConfig, boolean validate)
    throws URISyntaxException, XPathException {
        String href = element.getAttributeValue(xlinkHref);
        URI target = new URI(element.getBaseURI()).resolve(href);
        Source ss = new StreamSource(target.toString());
        ss = AugmentedSource.makeAugmentedSource(ss);
        ((AugmentedSource)ss).setLineNumbering(true);
        if (validate) {
            ((AugmentedSource)ss).setSchemaValidationMode(Validation.STRICT);
        }
        return targetConfig.buildDocument((AugmentedSource)ss);
    }

    public void go(String[] args) throws SAXException, ParserConfigurationException,
            XPathException, IOException, URISyntaxException {


        testSuiteDir = args[0];
        Pattern testSetPattern = null;
        Pattern testGroupPattern = null;
        String contributor = null;
        HashMap exceptions = new HashMap();

        for (int i=1; i<args.length; i++) {
            if (args[i].equals("-w")) {
                showWarnings = true;
            } else if (args[i].startsWith("-c:")) {
                contributor = args[i].substring(3);
            } else if (args[i].startsWith("-s:")) {
                testSetPattern = Pattern.compile(args[i].substring(3));
            } else if (args[i].startsWith("-g:")) {
                testGroupPattern = Pattern.compile(args[i].substring(3));
            } else if (args[i].equals("-?")) {
                System.err.println("Usage: SchemaTestSuiteDriver testDir [-w] [-s:testSetPattern] [-g:testGroupPattern]");
            }
        }

        try {

            NamePool pool = new NamePool();
            catalogConfig = new SchemaAwareConfiguration();
            catalogConfig.setNamePool(pool);
            catalogConfig.setHostLanguage(Configuration.XML_SCHEMA);
            parser = catalogConfig.getSourceParser();

            xlinkHref = pool.allocate("", "http://www.w3.org/1999/xlink", "href");

            int testCaseFP = pool.allocate("", "", "testcase") & NamePool.FP_MASK;
            NameTest testCaseNT = new NameTest(Type.ELEMENT, testCaseFP, pool);
            int commentFP = pool.allocate("", "", "comment") & NamePool.FP_MASK;
            NameTest commentNT = new NameTest(Type.ELEMENT, commentFP, pool);

            NameTest testSetRefNT = elementNameTest(pool, "testSetRef");
            NameTest testGroupNT = elementNameTest(pool, "testGroup");
            NameTest testSetNT = elementNameTest(pool, "testSet");
            NameTest schemaTestNT = elementNameTest(pool, "schemaTest");
            NameTest instanceTestNT = elementNameTest(pool, "instanceTest");
            NameTest schemaDocumentNT = elementNameTest(pool, "schemaDocument");
            NameTest instanceDocumentNT = elementNameTest(pool, "instanceDocument");
            NameTest expectedNT = elementNameTest(pool, "expected");
            NameTest currentNT = elementNameTest(pool, "current");

            int validityAtt = pool.allocate("", "", "validity") & NamePool.FP_MASK;
            int nameAtt = pool.allocate("", "", "name") & NamePool.FP_MASK;
            int contributorAtt = pool.allocate("", "", "contributor") & NamePool.FP_MASK;
            int setAtt = pool.allocate("", "", "set") & NamePool.FP_MASK;
            int groupAtt = pool.allocate("", "", "group") & NamePool.FP_MASK;
            int statusAtt = pool.allocate("", "", "status") & NamePool.FP_MASK;
            int bugzillaAtt = pool.allocate("", "", "bugzilla") & NamePool.FP_MASK;
            int targetNamespaceAtt = pool.allocate("", "", "targetNamespace") & NamePool.FP_MASK;


            DocumentInfo catalog = new StaticQueryContext(catalogConfig).buildDocument(
                    new StreamSource(new File(testSuiteDir + "/suite.xml"))
            );

            results = new BufferedWriter(new FileWriter(new File(testSuiteDir + "/SaxonResults"
                        + Version.getProductVersion() + ".xml")));

            results.write("<testSuiteResults xmlns='" + testNS + "' xmlns:saxon='http://saxon.sf.net/' " +
                    "suite='TS_2006' " +
                    "processor='Saxon-SA (Java) 8.8++' submitDate='2007-01-05' publicationPermission='public'>\n");

            DocumentInfo exceptionsDoc = new StaticQueryContext(catalogConfig).buildDocument(
                    new StreamSource(new File(testSuiteDir + "/exceptions.xml"))
            );

            AxisIterator exceptionTestCases = exceptionsDoc.iterateAxis(Axis.DESCENDANT, testCaseNT);
            while (true) {
                NodeInfo testCase = (NodeInfo)exceptionTestCases.next();
                if (testCase == null) {
                    break;
                }
                String set = testCase.getAttributeValue(setAtt);
                String group = testCase.getAttributeValue(groupAtt);
                String comment = getChildElement(testCase, commentNT).getStringValue();
                exceptions.put(set + "#" + group, comment);
            }

            long startTime = (new Date()).getTime();

            AxisIterator testSets = catalog.iterateAxis(Axis.DESCENDANT, testSetRefNT);
            while (true) {
                NodeInfo testSetRef = (NodeInfo)testSets.next();
                if (testSetRef == null) {
                    break;
                }

                DocumentInfo testSetDoc = getLinkedDocument(testSetRef, catalogConfig, false);
                NodeInfo testSetElement = getChildElement(testSetDoc, testSetNT);

                if (testSetElement == null) {
                    System.err.println("test set doc has no TestSet child: " + testSetDoc.getBaseURI());
                    continue;
                }

                String testSetName = testSetElement.getAttributeValue(nameAtt);
                if (testSetPattern != null && !testSetPattern.matcher(testSetName).matches()) {
                    continue;
                }
                if (contributor != null && !contributor.equals(testSetElement.getAttributeValue(contributorAtt))) {
                    continue;
                }

                AxisIterator testGroups = testSetElement.iterateAxis(Axis.CHILD, testGroupNT);
                while (true) {
                    NodeInfo testGroup = (NodeInfo)testGroups.next();
                    if (testGroup == null) {
                        break;
                    }

                    String testGroupName = testGroup.getAttributeValue(nameAtt);
                    String exception = (String)exceptions.get(testSetName + "#" + testGroupName);

                    if (testGroupPattern != null && !testGroupPattern.matcher(testGroupName).matches()) {
                        continue;
                    }
                    System.err.println("TEST SET " + testSetName + " GROUP " + testGroupName);
                    SchemaAwareConfiguration testConfig = new SchemaAwareConfiguration();
                    testConfig.setHostLanguage(Configuration.XML_SCHEMA);
                    AxisIterator schemaTests = testGroup.iterateAxis(Axis.CHILD, schemaTestNT);
                    boolean schemaQueried = false;
                    String bugzillaRef = null;

                    while (true) {
                        NodeInfo schemaTest = (NodeInfo)schemaTests.next();
                        if (schemaTest == null) {
                            break;
                        }
                        bugzillaRef = null;
                        String testName = schemaTest.getAttributeValue(nameAtt);
                        if (exception != null) {
                            results.write("<testResult set='" + testSetName +
                                    "' group='" + testGroupName +
                                    "' test='" + testName +
                                    "' validity='notKnown' saxon:outcome='notRun' saxon:comment='" + exception +
                                    "'/>\n");
                            continue;
                        }
                        boolean queried = false;
                        NodeInfo statusElement = getChildElement(schemaTest, currentNT);
                        if (statusElement != null) {
                            String status = statusElement.getAttributeValue(statusAtt);
                            queried = "queried".equals(status);
                            bugzillaRef = statusElement.getAttributeValue(bugzillaAtt);
                        }
                        if (queried) {
                            schemaQueried = true;
                        }
                        System.err.println("TEST SCHEMA " + testName + (queried ? " (queried)" : ""));
                        boolean success = true;
                        AxisIterator schemata = schemaTest.iterateAxis(Axis.CHILD, schemaDocumentNT);
                        while (true) {
                            NodeInfo schemaDocumentRef = (NodeInfo)schemata.next();
                            if (schemaDocumentRef == null) {
                                break;
                            }
                            System.err.println("Loading schema at " + schemaDocumentRef.getAttributeValue(xlinkHref));
                            DocumentInfo schemaDoc = getLinkedDocument(schemaDocumentRef, testConfig, false);
                            NodeInfo schemaElement =
                                    (NodeInfo)schemaDoc.iterateAxis(Axis.CHILD, NodeKindTest.ELEMENT).next();
                            String targetNamespace = schemaElement.getAttributeValue(targetNamespaceAtt);
                            if (targetNamespace != null && testConfig.isSchemaAvailable(targetNamespace)) {
                                // do nothing
                                // TODO: this is the only way I can get MS additional test addB132 to work.
                                // It's not ideal: addSchemaSource() ought to be a no-op if the schema components
                                // are already loaded, but in fact recompiling the imported schema document on its
                                // own is losing the substitution group membership that was defined in the
                                // importing document.
                            } else {
                                try {
                                    testConfig.addSchemaSource(schemaDoc); // TODO: use an ErrorListener
                                } catch (SchemaException err) {
                                    success = false;
                                }
                            }
                        }
                        NodeInfo expected = getChildElement(schemaTest, expectedNT);
                        boolean expectedSuccess = expected.getAttributeValue(validityAtt).equals("valid");
//                        if (expectedSuccess == success) {
//                            results.write("SchemaTest " + testName + " OK");
//                        } else {
//                            results.write("SchemaTest " + testName + " failed (expected "
//                                    + expectedSuccess + " got " + success);
//                        }
                        results.write("<testResult set='" + testSetName +
                                "' group='" + testGroupName +
                                "' test='" + testName +
                                "' validity='" + (success ? "valid" : "invalid" ) +
                                (queried ? "' saxon:queried='true' saxon:bugzilla='" + bugzillaRef : "") +
                                "' saxon:outcome='" + (success==expectedSuccess ? "same" : "different") +
                                "'/>\n");
                    }
                    AxisIterator instanceTests = testGroup.iterateAxis(Axis.CHILD, instanceTestNT);
                    while (true) {
                        NodeInfo instanceTest = (NodeInfo)instanceTests.next();
                        if (instanceTest == null) {
                            break;
                        }
                        String testName = instanceTest.getAttributeValue(nameAtt);

                        if (exception != null) {
                            results.write("<testResult set='" + testSetName +
                                    "' group='" + testGroupName +
                                    "' test='" + testName +
                                    "' validity='notKnown' saxon:outcome='notRun' saxon:comment='" + exception +
                                    "'/>\n");
                            continue;
                        }

                        boolean queried = false;
                        NodeInfo statusElement = getChildElement(instanceTest, currentNT);
                        if (statusElement != null) {
                            String status = statusElement.getAttributeValue(statusAtt);
                            queried = "queried".equals(status);
                            String instanceBug = statusElement.getAttributeValue(bugzillaAtt);
                            if (instanceBug != null) {
                                bugzillaRef = instanceBug;
                            }
                        }
                        queried |= schemaQueried;

                        System.err.println("TEST INSTANCE " + testName + (queried ? " (queried)" : ""));

                        NodeInfo instanceDocument = getChildElement(instanceTest, instanceDocumentNT);

                        boolean success = true;
                        try {
                            DocumentInfo instanceDoc = getLinkedDocument(instanceDocument, testConfig, true);
                        } catch (XPathException err) {
                            System.err.println(err.getMessage());
                            success = false;
                        }
                        NodeInfo expected = getChildElement(instanceTest, expectedNT);
                        boolean expectedSuccess = expected.getAttributeValue(validityAtt).equals("valid");
                        results.write("<testResult set='" + testSetName +
                                "' group='" + testGroupName +
                                "' test='" + testName +
                                "' validity='" + (success ? "valid" : "invalid" ) +
                                (queried ? "' saxon:queried='true' saxon:bugzilla='" + bugzillaRef : "") +
                                "' saxon:outcome='" + (success==expectedSuccess ? "same" : "different") +
                                "'/>\n");

                    }
                }
            }

            results.write("</testSuiteResults>");
            results.close();

            System.err.println("Time: " + (new Date().getTime() - startTime) + " ms");

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    protected String getResultDirectoryName() {
        return "SaxonResults";
    }

    protected boolean isExcluded(String testName) {
        return false;
    }



    private class MyErrorListener extends StandardErrorListener {

        public String errorCode;

        /**
         * Receive notification of a recoverable error.
         */

        public void error(TransformerException exception) throws TransformerException {
            if (exception instanceof XPathException) {
                String code = ((XPathException)exception).getErrorCodeLocalPart();
                if (code != null) {
                    errorCode = code;
                }
                if ("FODC0005".equals(errorCode)) {
                    fatalError(exception);
                }
            }
            super.error(exception);
        }

        /**
         * Receive notification of a non-recoverable error.
         */

        public void fatalError(TransformerException exception) throws TransformerException {
            if (exception instanceof XPathException) {
                String code = ((XPathException)exception).getErrorCodeLocalPart();
                if (code != null) {
                    errorCode = code;
                }
            }
            super.fatalError(exception);
        }

        /**
         * Receive notification of a warning.
         */

        public void warning(TransformerException exception) throws TransformerException {
            if (showWarnings) {
                super.warning(exception);
            }
        }

        /**
         * Make a clean copy of this ErrorListener. This is necessary because the
         * standard error listener is stateful (it remembers how many errors there have been)
         */

        public StandardErrorListener makeAnother(int hostLanguage) {
            return new MyErrorListener();
        }

    }
}
