package test;


import com.saxonica.validate.SchemaAwareConfiguration;
import com.saxonica.codegen.QueryCompiler;
import net.sf.saxon.*;
import net.sf.saxon.value.SequenceExtent;
import net.sf.saxon.value.AnyURIValue;
import net.sf.saxon.value.StringValue;
import net.sf.saxon.om.*;
import net.sf.saxon.pattern.NameTest;
import net.sf.saxon.query.DynamicQueryContext;
import net.sf.saxon.query.StaticQueryContext;
import net.sf.saxon.query.XQueryExpression;
import net.sf.saxon.trans.XPathException;
import net.sf.saxon.type.Type;
import org.w3c.tidy.Tidy;
import org.xml.sax.EntityResolver;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.*;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import java.io.*;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.Properties;
import java.util.regex.Pattern;

/**
 * This class runs the W3C XQuery Test Suite, driven from the test catalog. It includes options to
 * run the tests intepretively or by compilation.
 */
public class XQueryTestSuiteDriver {
    /**
     * Run the testsuite using Saxon.
     *
     * @param args Array of parameters passed to the application
     * via the command line.
     */
    public static void main(String[] args) throws Exception {
        if (args.length == 0 || args[0].equals("-?")) {
            System.err.println(
                    "XQueryTestSuiteDriver testsuiteDir [testNamePattern] [-compile] [-runcomp] [-w] [-onwards] [-unfold]");
        }

        System.err.println("Testing Saxon " + Version.getProductVersion());
        new XQueryTestSuiteDriver().go(args);
    }

    String testSuiteDir;
    SchemaAwareConfiguration saConfig;
    MyErrorListener errorListener;
    String overridingModel = null;
    String model = "tinytree";
    String initialMode = null;
    XMLReader parser;
    XMLReader resultParser;
    XMLReader fragmentParser;
    boolean usePull = false;
    boolean useTrace = false;
    boolean traceParam = false;
    HashMap sourceMap;
    boolean dotNetPlatform = false;
    Pattern testPattern = null;
    boolean showWarnings = false;
    boolean xml11 = false;
    boolean compile = false;
    boolean onwards = false;
    boolean unfolded = false;
    boolean runCompiled = false;
    HashMap documentCache = new HashMap(50);

    TransformerFactory tfactory = new TransformerFactoryImpl();

    Writer results;
    Writer compileScript = null;
    HashSet directories = new HashSet(200);

    /**
     * Some tests use schemas that conflict with others, so they can't use the common schema cache.
     * These tests are run in a Configuration of their own. (Ideally we would put this list in a
     * catalogue file of some kind).
     */

    static HashSet noCacheTests = new HashSet(30);
    static {
        noCacheTests.add("schemainline20_005_01");

    }

    private NameTest elementNameTest(NamePool pool, String local) {
        int nameFP = pool.allocate("", "http://www.w3.org/2005/02/query-test-XQTSCatalog", local) & NamePool.FP_MASK;
        return new NameTest(Type.ELEMENT, nameFP, pool);
    }

    private NodeInfo getChildElement(NodeInfo parent, NameTest child) {
        return (NodeInfo)parent.iterateAxis(Axis.CHILD, child).next();
    }

    public void go(String[] args) throws SAXException, ParserConfigurationException {


        testSuiteDir = args[0];
        HashSet exceptions = new HashSet();

        for (int i=1; i<args.length; i++) {
            if (args[i].startsWith("-")) {
                if (args[i].equals("-w")) {
                    showWarnings = true;
                } else if (args[i].equals("-compile")) {
                    compile = true;
                } else if (args[i].equals("-onwards")) {
                    onwards = true;
                } else if (args[i].equals("-runcomp")) {
                    runCompiled = true;
                } else if (args[i].equals("-unfold")) {
                    unfolded = true;
                }
            } else {
                testPattern = Pattern.compile(args[i]);
            }
        }


        try {
//            parser = SAXParserFactory.newInstance().newSAXParser().getXMLReader();
//            if (!parser.getFeature("http://xml.org/sax/features/xml-1.1")) {
//                System.err.println("Warning: XML parser does not support XML 1.1 - " + parser.getClass());
//            };
            NamePool pool = new NamePool();
            saConfig = new SchemaAwareConfiguration();
            saConfig.setNamePool(pool);
            parser = saConfig.getSourceParser();

            boolean supports11 = false;
            try {
                supports11 = parser.getFeature("http://xml.org/sax/features/xml-1.1");
            } catch (Exception err) {}

            if (!supports11) {
                System.err.println("Warning: XML parser does not support XML 1.1 - " + parser.getClass());
            };
            resultParser = saConfig.getSourceParser();
            resultParser.setEntityResolver(
                    new EntityResolver() {
                        public InputSource resolveEntity(String publicId, String systemId) {
                            return new InputSource(new StringReader(""));
                        }
                    }
            );
            fragmentParser = saConfig.getSourceParser();

            //Configuration config11 = new Configuration();
            //config11.setXMLVersion(Configuration.XML11);
            //config11.setNamePool(pool);

            errorListener = new MyErrorListener();
            saConfig.setErrorListener(errorListener);
            saConfig.setErrorListener(errorListener);

            NameTest testCaseNT = elementNameTest(pool, "test-case");
            NameTest inputUriNT = elementNameTest(pool, "input-URI");
            NameTest inputFileNT = elementNameTest(pool, "input-file");
            NameTest queryNT = elementNameTest(pool, "query");
            NameTest inputQueryNT = elementNameTest(pool, "input-query");
            NameTest contextItemNT = elementNameTest(pool, "contextItem");
            NameTest outputFileNT = elementNameTest(pool, "output-file");
            NameTest sourceNT = elementNameTest(pool, "source");
            NameTest schemaNT = elementNameTest(pool, "schema");
            NameTest expectedErrorNT = elementNameTest(pool, "expected-error");
            NameTest collectionNT = elementNameTest(pool, "collection");
            NameTest defaultCollectionNT = elementNameTest(pool, "defaultCollection");


            int schemaAtt = pool.allocate("", "", "schema") & NamePool.FP_MASK;
            int nameAtt = pool.allocate("", "", "name") & NamePool.FP_MASK;
            int filePathAtt = pool.allocate("", "", "FilePath") & NamePool.FP_MASK;
            int fileNameAtt = pool.allocate("", "", "FileName") & NamePool.FP_MASK;
            int idAtt = pool.allocate("", "", "ID") & NamePool.FP_MASK;
            int compareAtt = pool.allocate("", "", "compare") & NamePool.FP_MASK;
            int variableAtt = pool.allocate("", "", "variable") & NamePool.FP_MASK;
            int scenarioAtt = pool.allocate("", "", "scenario") & NamePool.FP_MASK;

            /**
             * Look for an exceptions.xml document with the general format:
             *
             * <exceptions>
             *   <exception>
             *     <tests>testname1 testname2 ...</tests>
             *     <decription>text explanation</description>
             *   </exception>
             * </exceptions>
             *
             * Tests listed in this file will not be run.
             */

            DocumentInfo exceptionsDoc = saConfig.buildDocument(
                    new StreamSource(new File(testSuiteDir + '/' + getResultDirectoryName() + "/exceptions.xml"))
            );

            NameTest exceptionTestsNT = new NameTest(Type.ELEMENT, pool.allocate("", "", "tests"), pool);
            AxisIterator exceptionTestCases = exceptionsDoc.iterateAxis(Axis.DESCENDANT, exceptionTestsNT);
            while (true) {
                NodeInfo testCase = (NodeInfo)exceptionTestCases.next();
                if (testCase == null) {
                    break;
                }
                String name = testCase.getStringValue();
                StringTokenizer tok = new StringTokenizer(name);
                while (tok.hasMoreElements()) {
                    exceptions.add(tok.nextElement());
                }
            }


            DocumentInfo catalog = saConfig.buildDocument(
                    new StreamSource(new File(testSuiteDir + "/XQTScatalog.xml"))
            );

            results = new FileWriter(
                    new File(testSuiteDir + "/SaxonDriver/results" + Version.getProductVersion() + ".xml"));

            /**
             * If compiling tests to Java, generate a batch script to perform the Java compilations
             */

            if (compile) {
                compileScript = new FileWriter(
                        new File(testSuiteDir + "/SaxonDriver/compile.cmd"));
                compileScript.write("set JAVA=\"c:\\Program Files\\java\\jdk1.4.2_11\"\n");
                //compileScript.write("set CLASSPATH=\"C:\\Documents and Settings\\Mike\\IdeaProjects\\Saxon 8.x\\Saxon\\classes\";c:\\Javalib\\jsdk2.1\\servlet.jar\n");
                compileScript.write("set CLASSPATH=C:\\saxon-build\\8.9\\saj\\saxon8sa.jar;c:\\Javalib\\jsdk2.1\\servlet.jar\n");
            }

            Properties outputProps = new Properties();
            outputProps.setProperty("method", "xml");
            outputProps.setProperty("indent", "yes");
            results.write(" <implementation name='Saxon-SA' version='" + Version.getProductVersion() +
                    "' anonymous-result-column='false'>\n");
            results.write("  <organization name='Saxonica' website='http://www.saxonica.com/' anonymous='false'/>\n");
            results.write("  <submittor name='Michael Kay' title='Director' email='mike@saxonica.com'/>\n");
            outputDiscretionaryItems();
            results.write(" </implementation>\n");
            results.write(" <syntax>XQuery</syntax>");
            results.write(" <test-run dateRun='YYYY-MM-DD'>");
            results.write("   <test-suite version='1.0.4'/>");
            results.write("   <transformation/>");
            results.write("   <comparison/>");
            results.write("   <otherComments/>");
            results.write(" </test-run>");

            /**
             * Load all the schemas
             */

            AxisIterator schemas = catalog.iterateAxis(Axis.DESCENDANT, schemaNT);
            while (true) {
                NodeInfo schemaElement = (NodeInfo)schemas.next();
                if (schemaElement == null) {
                    break;
                }
                String fileName = schemaElement.getAttributeValue(fileNameAtt);
                System.err.println("Loading schema " + fileName);
                StreamSource ss = new StreamSource(new File(testSuiteDir + fileName));
                saConfig.addSchemaSource(ss);

            }

            /**
             * Unless we are compiling tests to Java, load the source documents
             */

            if (!compile) {
                AxisIterator sources = catalog.iterateAxis(Axis.DESCENDANT, sourceNT);
                while (true) {
                    NodeInfo sourceElement = (NodeInfo)sources.next();
                    if (sourceElement == null) {
                        break;
                    }
                    String schema = sourceElement.getAttributeValue(schemaAtt);
                    String id = sourceElement.getAttributeValue(idAtt);
                    String fileName = sourceElement.getAttributeValue(fileNameAtt);
                    System.err.println("Loading source " + fileName);
                    Source ss = new StreamSource(new File(testSuiteDir + fileName));
                    if (schema != null) {
                        ss = AugmentedSource.makeAugmentedSource(ss);
                        ((AugmentedSource)ss).setSchemaValidationMode(Validation.STRICT);
                    }
                    DocumentInfo doc = saConfig.buildDocument(ss);
                    documentCache.put(id, doc) ;

                }
            }

            AxisIterator testCases = catalog.iterateAxis(Axis.DESCENDANT, testCaseNT);
            while (true) {
                NodeInfo testCase = (NodeInfo)testCases.next();
                if (testCase == null) {
                    break;
                }

                String testName = testCase.getAttributeValue(nameAtt);
                if (testPattern != null && !testPattern.matcher(testName).matches()) {
                    continue;
                }
                if (onwards) {
                    testPattern = null;
                }
                if (exceptions.contains(testName)) {
                    continue;
                }
                if (isExcluded(testName)) {
                    continue;
                }
                System.err.println("Test " + testName);

                String filePath = testCase.getAttributeValue(filePathAtt);
                //NodeInfo testInput = getChildElement(testCase, inputFileNT);

                NodeInfo query = getChildElement(testCase, queryNT);
                String queryName = query.getAttributeValue(nameAtt);

                String absQueryName = testSuiteDir + "/Queries/" +
                        (unfolded ? "XQUnfolded/" : "XQuery/") +
                        filePath + queryName + ".xq";

                String outputFile = null;

                if (compile) {
                    if ("parse-error".equals(testCase.getAttributeValue(scenarioAtt))) {
                        continue;
                    }
                    QueryCompiler qc = new QueryCompiler(saConfig);
                    qc.setBaseURI(new File(absQueryName).toURI().toString());
                    String groupName = testCase.getParent().getAttributeValue(nameAtt);
                    groupName = lowercase(groupName);
                    queryName = lowercase(queryName);
                    qc.setClassName(makeClassName(groupName, queryName));
                    File dir = new File(testSuiteDir + "/SaxonDriver/java/");
                    dir.mkdir();
                    qc.setOutputDirectory(dir);
                    //qc.setClassPath(classPath);

                    try {

                        qc.compileQueryToJava(new FileInputStream(absQueryName), "utf8");
                        System.err.println("Java source code written "/* + qc.getJavaFile()*/);
                        String finaldir = dir + "/" + groupName;
                        if (!directories.contains(finaldir)) {
                            compileScript.write("%JAVA%\\bin\\javac -classpath %CLASSPATH% " + finaldir + "/*.java\n");
                            directories.add(finaldir);
                        }
                    } catch (XPathException err) {
                        System.err.println("Query compilation failed");
                        continue;
                    } catch (Exception err2) {
                        err2.printStackTrace();
                        continue;
                    }
//                    try {
//                        qc.compileJavaToByteCode();
//                    } catch (XPathException err) {
//                        System.err.println("Java compilation failed");
//                        continue;
//                    }
//
//                    System.err.println("Java compilation succeeded");
                    continue;


                } else if (runCompiled) {
                    if ("parse-error".equals(testCase.getAttributeValue(scenarioAtt))) {
                        continue;
                    }
                    QueryCompiler qc = new QueryCompiler(saConfig);
                    qc.setBaseURI(new File(absQueryName).toURI().toString());
                    String groupName = testCase.getParent().getAttributeValue(nameAtt);
                    groupName = lowercase(groupName);
                    queryName = lowercase(queryName);
                    qc.setClassName(makeClassName(groupName, queryName));
                    File dir = new File(testSuiteDir + "/SaxonDriver/java/");
                    dir.mkdir();
                    qc.setOutputDirectory(dir);
                    //qc.setClassPath(classPath);

                    DynamicQueryContext dqc = new DynamicQueryContext(saConfig);
                    dqc.setParameterValue("zlsJJ", StringValue.EMPTY_STRING);
                    NodeInfo contextItemElement = getChildElement(testCase, contextItemNT);
                    if (contextItemElement != null) {
                        DocumentInfo contextNode = loadDocument(contextItemElement.getStringValue());
                        dqc.setContextItem(contextNode);
                    }

                    processInputDocuments(testCase, inputFileNT, variableAtt, dqc);

                    SequenceIterator inputURIs = testCase.iterateAxis(Axis.CHILD, inputUriNT);
                    while (true) {
                        NodeInfo inputURI = (NodeInfo)inputURIs.next();
                        if (inputURI == null) {
                            break;
                        }
                        String variableName = inputURI.getAttributeValue(variableAtt);
                        variableName = toClarkName(variableName);
                        if (variableName != null) {
                            DocumentInfo document = loadDocument(inputURI.getStringValue());
                            if (document == null) {
                                System.err.println("*** Document " + inputURI + " not loaded");
                            } else {
                                String uri = document.getSystemId();
                                dqc.setParameterValue(variableName, new AnyURIValue(uri));
                            }
                        }
                    }

                    processInputQueries(testCase, inputQueryNT, variableAtt, nameAtt, filePath, dqc);

                    String outputDir = testSuiteDir + "/SaxonDriver/results/" + filePath;
                    new File(outputDir).mkdirs();
                    outputFile = testSuiteDir + "/SaxonDriver/results/" + filePath + testName + ".out";
                    StreamResult result = new StreamResult(new File(outputFile));
                    try {
                        qc.runQuery(dqc, result);
                    } catch (XPathException err) {
                        if (!err.hasBeenReported()) {
                            System.err.println(err.getMessage());
                        }
                        processError(err, testCase, testName, expectedErrorNT);
                        continue;
                    } catch (ClassNotFoundException err) {
                        // means the query had a static error
                        continue;
                    } catch (Exception err2) {
                        err2.printStackTrace();
                        continue;
                    }
                } else {
                    StaticQueryContext env = new StaticQueryContext(saConfig);
                    env.setModuleURIResolver(new XQTSModuleURIResolver(testCase));
                    env.setBaseURI(new File(absQueryName).toURI().toString());
                    XQueryExpression xqe = null;

                    try {
                        xqe = env.compileQuery(new FileInputStream(absQueryName), "UTF-8");
                    } catch (XPathException err) {
                        processError(err, testCase, testName, expectedErrorNT);
                        continue;
                    }

                    DynamicQueryContext dqc = new DynamicQueryContext(saConfig);

                    NodeInfo contextItemElement = getChildElement(testCase, contextItemNT);
                    if (contextItemElement != null) {
                        DocumentInfo contextNode = loadDocument(contextItemElement.getStringValue());
                        dqc.setContextItem(contextNode);
                    }

                    processInputQueries(testCase, inputQueryNT, variableAtt, nameAtt, filePath, dqc);

                    processInputDocuments(testCase, inputFileNT, variableAtt, dqc);

                    SequenceIterator inputURIs = testCase.iterateAxis(Axis.CHILD, inputUriNT);
                    while (true) {
                        NodeInfo inputURI = (NodeInfo)inputURIs.next();
                        if (inputURI == null) {
                            break;
                        }
                        String variableName = inputURI.getAttributeValue(variableAtt);
                        variableName = toClarkName(variableName);
                        if (variableName != null) {
                            String docName = inputURI.getStringValue();
                            if (docName.startsWith("collection")) {
                                NodeInfo collectionElement = getCollectionElement(catalog, docName, collectionNT, idAtt);
                                CollectionURIResolver r =
                                        new XQTSCollectionURIResolver(catalog, collectionElement, false);
                                saConfig.setCollectionURIResolver(r);
                                dqc.setParameterValue(variableName, new AnyURIValue(docName));
                            } else {
                                String uri = loadDocument(docName).getSystemId();
                                dqc.setParameterValue(variableName, new AnyURIValue(uri));
                            }
                        }
                    }

                    NodeInfo defaultCollection = getChildElement(testCase, defaultCollectionNT);
                    if (defaultCollection != null) {
                        String docName = defaultCollection.getStringValue();
                        NodeInfo collectionElement = getCollectionElement(catalog, docName, collectionNT, idAtt);
                        CollectionURIResolver r =
                                        new XQTSCollectionURIResolver(catalog, collectionElement, true);
                        saConfig.setCollectionURIResolver(r);
                    }


                    // Run the query

                    outputFile = testSuiteDir + "/SaxonDriver/results/" + filePath + testName + ".out";
                    StreamResult result = new StreamResult(new File(outputFile));
                    try {
                        xqe.run(dqc, result, outputProps);
                    } catch (XPathException err) {
                        processError(err, testCase, testName, expectedErrorNT);
                        continue;
                    }
                }

                // Compare the results

                boolean resultsMatched = false;
                String possibleMatch = null;
                SequenceIterator expectedResults = testCase.iterateAxis(Axis.CHILD, outputFileNT);
                boolean multipleResults = false;
                SequenceIterator ccc = expectedResults.getAnother();
                ccc.next();
                if (ccc.next() != null) {
                    multipleResults = true;
                }
                while (true) {
                    NodeInfo outputFileElement = (NodeInfo)expectedResults.next();
                    if (outputFileElement == null) {
                        break;
                    }
                    String resultsPath = testSuiteDir + "/ExpectedTestResults/" +
                            filePath + outputFileElement.getStringValue();
                    String comparisonMethod = outputFileElement.getAttributeValue(compareAtt);
                    String comparisonResult = compare(outputFile, resultsPath, comparisonMethod, multipleResults);
                    if (comparisonResult.equals("true")) {
                        // exact match
                        results.write("  <test-case name='" + testName + "' result='pass'/>\n");
                        resultsMatched = true;
                        break;
                    } else if (comparisonResult.equals("false")) {
                        continue;
                    } else {
                        possibleMatch = comparisonResult;
                        continue;
                    }
                }

                if (!resultsMatched) {
                    if (multipleResults) {
                        System.err.println("*** Failed to match any of the permitted results");
                    }
                    NodeInfo expectedError = getChildElement(testCase, expectedErrorNT);
                    if (possibleMatch != null) {
                        results.write("  <test-case name='" + testName + "' result='pass' comment='" +
                                possibleMatch + "'/>\n");
                    } else if (expectedError != null) {
                        results.write("  <test-case name='" + testName + "' result='fail' comment='" +
                                "expected " + expectedError.getStringValue() + ", got success'/>\n");
                    } else {
                        results.write("  <test-case name='" + testName + "' result='fail'/>\n");
                    }
                }
            }

            results.write("</test-suite-result>");
            results.close();
            if (compile) {
                compileScript.close();
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void processInputDocuments(NodeInfo testCase, NameTest inputFileNT, int variableAtt, DynamicQueryContext dqc) throws XPathException {
        SequenceIterator inputFiles = testCase.iterateAxis(Axis.CHILD, inputFileNT);
        while (true) {
            NodeInfo inputFile = (NodeInfo)inputFiles.next();
            if (inputFile == null) {
                break;
            }
            String variableName = inputFile.getAttributeValue(variableAtt);
            variableName = toClarkName(variableName);
            if (variableName != null) {
                DocumentInfo inputDoc = loadDocument(inputFile.getStringValue());
                dqc.setParameterValue(variableName, inputDoc);
            }
        }
    }

    private void processInputQueries(NodeInfo testCase, NameTest inputQueryNT, int variableAtt, int nameAtt, String filePath, DynamicQueryContext dqc) throws XPathException, IOException {
        SequenceIterator inputQueries = testCase.iterateAxis(Axis.CHILD, inputQueryNT);
        while (true) {
            NodeInfo inputQuery = (NodeInfo)inputQueries.next();
            if (inputQuery == null) {
                break;
            }
            String variableName = inputQuery.getAttributeValue(variableAtt);
            variableName = toClarkName(variableName);
            if (variableName != null) {
                String preQueryName = inputQuery.getAttributeValue(nameAtt);
                String subQueryFile = testSuiteDir + "/Queries/XQuery/" + filePath + preQueryName + ".xq";
                StaticQueryContext sqc2 = new StaticQueryContext(saConfig);
                XQueryExpression subQuery = sqc2.compileQuery(new FileReader(subQueryFile));
                SequenceIterator subQueryResult = subQuery.iterator(new DynamicQueryContext(saConfig));
                dqc.setParameterValue(variableName, SequenceExtent.makeSequenceExtent(subQueryResult));
            }
        }
    }

    private NodeInfo getCollectionElement(DocumentInfo catalog, String docName, NameTest collectionNT, int idAtt) {
        NodeInfo collectionElement = null;
        AxisIterator colls = catalog.iterateAxis(Axis.DESCENDANT, collectionNT);
        while (true) {
            NodeInfo coll = (NodeInfo)colls.next();
            if (coll == null) {
                break;
            }
            if (docName.equals(coll.getAttributeValue(idAtt))) {
                collectionElement = coll;
            }
        }
        return collectionElement;
    }

    protected String getResultDirectoryName() {
        return "SaxonDriver";
    }

    protected boolean isExcluded(String testName) {
        return false;
    }

    private static String toClarkName(String variableName) {
        // Crude handling of QName-valued variables (there aren't many in the catalog!)
        if (variableName == null) {
            return null;
        }
        if (variableName.startsWith("local:")) {
            return "{http://www.w3.org/2005/xquery-local-functions}" + variableName.substring(6);
        } else {
            return variableName;
        }

    }


    /**
     * Construct source object. This method allows subclassing e.g. to build a DOM or XOM source.
     * @param xml
     */

    private DocumentInfo loadDocument(String xml) {
        return (DocumentInfo)documentCache.get(xml);
    }

    /**
     * Process a static or dynamic error
     */

    private void processError(XPathException err, NodeInfo testCase, String testName, NameTest expectedErrorNT)
    throws java.io.IOException {
        String actualError = err.getErrorCodeLocalPart();
        AxisIterator expectedErrors = testCase.iterateAxis(Axis.CHILD, expectedErrorNT);
        FastStringBuffer expected = new FastStringBuffer(20);
        while (true) {
            NodeInfo expectedError = (NodeInfo)expectedErrors.next();
            if (expectedError == null) {
                break;
            }
            if (expectedError.getStringValue().equals(actualError)) {
                results.write("  <test-case name='" + testName + "' result='pass'/>\n");
                return;
            }
            expected.append(expectedError.getStringValue());
            expected.append(" ");
        }
        if (expected.length() > 0) {
            results.write("  <test-case name='" + testName + "' result='pass'" +
                    " comment='expected " + expected + ", got " + actualError + "'/>\n");
        } else {
            results.write("  <test-case name='" + testName + "' result='fail'" +
                    " comment='expected success, got " + actualError + "'/>\n");
        }

    }


    static CanonicalXML canon = new CanonicalXML();

    private String compare(String outfile, String reffile, String comparator, boolean silent) {
        if (reffile == null) {
            System.err.println("*** No reference results available");
            return "false";
        }
        File outfileFile = new File(outfile);
        File reffileFile = new File(reffile);

        if (!reffileFile.exists()) {
            System.err.println("*** No reference results available");
            return "false";
        }

        // try direct comparison first

        String refResult = null;
        String actResult = null;

        try {
            // This is decoding bytes assuming the platform default encoding
            FileReader reader1 = new FileReader(outfileFile);
            FileReader reader2 = new FileReader(reffileFile);
            char[] contents1 = new char[(int)outfileFile.length()];
            char[] contents2 = new char[(int)reffileFile.length()];
            int size1 = reader1.read(contents1, 0, (int)outfileFile.length());
            int size2 = reader2.read(contents2, 0, (int)reffileFile.length());
            int offset1 = 0;
            int offset2 = 0;
            if (contents1[0]=='\u00ef' && contents1[1]=='\u00bb' && contents1[2]=='\u00bf') {
                offset1 += 3;
            }
            if (contents2[0]=='\u00ef' && contents2[1]=='\u00bb' && contents2[2]=='\u00bf') {
                offset2 += 3;
            }
            actResult = (size1==-1 ? "" : new String(contents1, offset1, size1-offset1));
            refResult = (size2==-1 ? "" : new String(contents2, offset2, size2-offset2));

            actResult = normalizeNewlines(actResult);
            refResult = normalizeNewlines(refResult);
            if (actResult.equals(refResult)) {
                return "true";
            }
            if (size1 == 0) {
                if (!silent) {
                    System.err.println("** ACTUAL RESULTS EMPTY; REFERENCE RESULTS LENGTH " + size2);
                }
                return "false";
            }
            if (size2 == 0) {
                if (!silent) {
                    System.err.println("** REFERENCED RESULTS EMPTY; ACTUAL RESULTS LENGTH " + size2);
                }
                return "false";
            }
        } catch (Exception e) {
        }

        // HTML: can't do logical comparison

        if (comparator.equals("html-output")) {
            // TODO: Tidy gets upset by byte-order-marks. Use the strings constructed above as input.
            try {
                Tidy tidy = new Tidy();
                tidy.setXmlOut(true);
                tidy.setQuiet(true);
                tidy.setShowWarnings(false);
                tidy.setCharEncoding(org.w3c.tidy.Configuration.UTF8);
                InputStream in1 = new FileInputStream(outfile);
                File xml1 = new File(outfile + ".xml");
                xml1.createNewFile();
                OutputStream out1 = new FileOutputStream(xml1);
                tidy.parse(in1, out1);
                InputStream in2 = new FileInputStream(reffile);
                File xml2 = new File(reffile + ".xml");
                xml2.createNewFile();
                OutputStream out2 = new FileOutputStream(xml2);
                tidy.parse(in2, out2);
                return compare(xml1.toString(), xml2.toString(), "xml", silent);
            } catch (IOException e) {
                e.printStackTrace();
                return "false";
            }
        } else if (comparator.equals("xhtml-output")) {
            refResult = canonizeXhtml(refResult);
            actResult = canonizeXhtml(actResult);
            return Boolean.toString((actResult.equals(refResult)));

        } else if (comparator.equals("Fragment") || comparator.equals("Text")) {
            try {
                // try two comparison techniques hoping one will work...
                boolean b = false;
                try {
                    b = compareFragments2(actResult, refResult, outfile, silent);
                } catch (Exception err1) {
                    System.err.println("XQTS: First comparison attempt failed, trying again");
                }
                if (!b) b = compareFragments(outfileFile, reffileFile, outfile, silent);
                return Boolean.toString(b);
            } catch (Exception err2) {
                System.err.println("Failed to compare results for: " + outfile);
                err2.printStackTrace();
                return "false";
            }
        } else if (comparator.equals("Inspect")) {
            System.err.println("** Inspect results by hand");
            return "true";
        } else {
            // convert both files to Canonical XML and compare them again
            try {
                InputSource out = new InputSource(outfileFile.toURL().toString());
                InputSource ref = new InputSource(reffileFile.toURL().toString());
                String outxml = canon.toCanonicalXML2(resultParser, out, false);
                String refxml = canon.toCanonicalXML2(resultParser, ref, false);
//                String outxml = canon.toCanonicalXML3(factory, resultParser, actResult, false);
//                String refxml = canon.toCanonicalXML3(factory, resultParser, refResult, false);
                if (!outxml.equals(refxml)) {
                    // try comparing again, this time without whitespace nodes
                    outxml = canon.toCanonicalXML2(resultParser, out, true);
                    refxml = canon.toCanonicalXML2(resultParser, ref, true);
//                    outxml = canon.toCanonicalXML3(factory, resultParser, actResult, true);
//                    refxml = canon.toCanonicalXML3(factory, resultParser, refResult, true);
                    if (outxml.equals(refxml)) {
                        System.err.println("*** Match after stripping whitespace nodes: " + outfile);
                        return "*** Match after stripping whitespace nodes";
                    } else {
                        if (!silent) {
                            System.err.println("Mismatch with reference results: " + outfile);
                            System.err.println("REFERENCE RESULTS:");
                            System.err.println(truncate(refxml));
                            System.err.println("ACTUAL RESULTS:");
                            System.err.println(truncate(outxml));
                            findDiff(refxml, outxml);
                        }
                        return "false";
                    }
                } else {
                    return "true";
                }
            } catch (Exception err) {
                try {
                    System.err.println("Failed to compare results for: " + outfile + ": " + err.getMessage());
                    System.err.println("** Attempting XML Fragment comparison");
                    //boolean b = compareFragments(outfileFile, reffileFile, outfile, silent);
                    boolean b = compareFragments2(actResult, refResult, outfile, silent);
                    System.err.println("** " + (b ? "Success" : "Still different"));
                    return Boolean.toString(b);
                } catch (Exception err2) {
                    System.err.println("Again failed to compare results for: " + outfile);
                    err2.printStackTrace();
                }
                return "false";
            }
        }
    }

    Templates xhtmlCanonizer;

    private String canonizeXhtml(String input) {
        try {
            Templates canonizer = getXhtmlCanonizer();
            Transformer t = canonizer.newTransformer();
            StringWriter sw = new StringWriter();
            StreamResult r = new StreamResult(sw);
            InputSource is = new InputSource(new StringReader(input));
            SAXSource ss = new SAXSource(resultParser, is);
            t.transform(ss, r);
            return sw.toString();
        } catch (TransformerConfigurationException err) {
            System.err.println("*** Failed to compile XHTML canonicalizer stylesheet");
        } catch (TransformerException err) {
            System.err.println("*** Failed while running XHTML canonicalizer stylesheet");
        }
        return "";
    }

    private Templates getXhtmlCanonizer() throws TransformerConfigurationException {
        if (xhtmlCanonizer == null) {
            Source source = new StreamSource(new File(testSuiteDir + "/SaxonResults/canonizeXhtml.xsl"));
            xhtmlCanonizer = tfactory.newTemplates(source);
        }
        return xhtmlCanonizer;
    }

    private boolean compareFragments(File outfileFile, File reffileFile, String outfile, boolean silent) {
        // if we can't parse the output as a document, try it as an external entity, with space stripping
        String outurl = outfileFile.toURI().toString();
        String refurl = reffileFile.toURI().toString();
        String outdoc = "<?xml version='1.1'?><!DOCTYPE doc [ <!ENTITY e SYSTEM '" + outurl + "'>]><doc>&e;</doc>";
        String refdoc = "<?xml version='1.1'?><!DOCTYPE doc [ <!ENTITY e SYSTEM '" + refurl + "'>]><doc>&e;</doc>";
        InputSource out2 = new InputSource(new StringReader(outdoc));
        InputSource ref2 = new InputSource(new StringReader(refdoc));
        String outxml2 = canon.toCanonicalXML(fragmentParser, out2, true);
        String refxml2 = canon.toCanonicalXML(fragmentParser, ref2, true);
        if (outxml2 != null && refxml2 != null && !outxml2.equals(refxml2)) {
            if (!silent) {
                System.err.println("Mismatch with reference results: " + outfile);
                System.err.println("REFERENCE RESULTS:");
                System.err.println(truncate(refxml2));
                System.err.println("ACTUAL RESULTS:");
                System.err.println(truncate(outxml2));
                findDiff(refxml2, outxml2);
            }
            return false;
        } else if (outxml2 == null) {
            System.err.println("Cannot canonicalize actual results");
            return false;
        } else if (refxml2 == null) {
            System.err.println("Cannot canonicalize reference results");
            return false;
        }
        return true;
    }

    /**
     * With this method of fragment comparison we build the wrapper document ourselves. This is
     * mainly to circumvent a Java XML parsing bug
     * @param outFragment
     * @param refFragment
     * @param outfile
     * @param silent
     * @return
     */

    private boolean compareFragments2(String outFragment, String refFragment, String outfile, boolean silent) {

        if (outFragment.startsWith("<?xml")) {
            int x = outFragment.indexOf("?>");
            outFragment = outFragment.substring(x+2);
        }

        if (refFragment.startsWith("<?xml")) {
            int x = refFragment.indexOf("?>");
            refFragment = refFragment.substring(x+2);
        }

        String outdoc = "<?xml version='1.1'?><doc>" + outFragment.trim() + "</doc>";
        String refdoc = "<?xml version='1.1'?><doc>" + refFragment.trim() + "</doc>";
        InputSource out2 = new InputSource(new StringReader(outdoc));
        InputSource ref2 = new InputSource(new StringReader(refdoc));
        String outxml2 = canon.toCanonicalXML(fragmentParser, out2, true);
        String refxml2 = canon.toCanonicalXML(fragmentParser, ref2, true);
        if (outxml2 != null && refxml2 != null && !outxml2.equals(refxml2)) {
            if (!silent) {
                System.err.println("Mismatch with reference results: " + outfile);
                System.err.println("REFERENCE RESULTS:");
                System.err.println(truncate(refxml2));
                System.err.println("ACTUAL RESULTS:");
                System.err.println(truncate(outxml2));
                findDiff(refxml2, outxml2);
            }
            return false;
        } else if (outxml2 == null) {
            System.err.println("Cannot canonicalize actual results");
            return false;
        } else if (refxml2 == null) {
            System.err.println("Cannot canonicalize reference results");
            return false;
        }
        return true;
    }


    private static String truncate(String s) {
        if (s.length() > 200) return s.substring(0, 200);
        return s;
    }

    private static void findDiff(String s1, String s2) {
        FastStringBuffer sb1 = new FastStringBuffer(s1.length());
        sb1.append(s1);
        FastStringBuffer sb2 = new FastStringBuffer(s2.length());
        sb2.append(s2);
        int i = 0;
        while (true) {
            if (s1.charAt(i) != s2.charAt(i)) {
                int j = (i < 50 ? 0 : i - 50);
                int k = (i + 50 > s1.length() || i + 50 > s2.length() ? i + 1 : i + 50);
                System.err.println("Different at char " + i + "\n+" + s1.substring(j, k) +
                                   "\n+" + s2.substring(j, k));
                break;
            }
            if (i >= s1.length()) break;
            if (i >= s2.length()) break;
            i++;
        }
    }

    private void outputDiscretionaryItems() throws IOException {
        results.write("  <discretionary-items/>\n");
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

    private String lowercase(String name) {
        FastStringBuffer sb = new FastStringBuffer(name.length());
        name = name.toLowerCase();
        for (int p=0; p<name.length(); p++) {
            char c = name.charAt(p);
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    private String makeClassName(String groupName, String mainName) {
        FastStringBuffer sb = new FastStringBuffer(mainName.length());
        sb.append(groupName);
        sb.append(".");
        mainName = mainName.substring(0,1).toUpperCase() + mainName.substring(1).toLowerCase();
        sb.append(mainName);
        return sb.toString();
    }

    private String normalizeNewlines(String in) {
        int cr = in.indexOf('\r');
        if (cr >= 0 && in.indexOf(cr + 1) == '\n') {
            return in.substring(0, cr) + normalizeNewlines(in.substring(cr + 1));
        } else {
            return in;
        }
    }


}
