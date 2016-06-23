package test;


import com.saxonica.validate.SchemaAwareConfiguration;
import net.sf.saxon.*;
import net.sf.saxon.om.*;
import net.sf.saxon.pattern.NameTest;
import net.sf.saxon.sxpath.XPathEvaluator;
import net.sf.saxon.sxpath.XPathExpression;
import net.sf.saxon.trans.DynamicError;
import net.sf.saxon.trans.StaticError;
import net.sf.saxon.trans.XPathException;
import net.sf.saxon.type.BuiltInAtomicType;
import net.sf.saxon.type.Type;
import net.sf.saxon.value.QNameValue;
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
import java.util.*;
import java.util.regex.Pattern;

/**
 * This class runs the W3C XSLT Test Suite, driven from the test catalog.
 */
public class XsltTestSuiteDriver {
    /**
     * Run the testsuite using Saxon.
     *
     * @param args Array of parameters passed to the application
     * via the command line.
     */
    public static void main(String[] args) throws Exception {
        if (args.length == 0 || args[0].equals("-?")) {
            System.err.println("XsltTestSuiteDriver testsuiteDir testName?");
        }

        System.err.println("Testing Saxon " + Version.getProductVersion());
        new XsltTestSuiteDriver().go(args);
    }

    String testSuiteDir;
    TransformerFactoryImpl factory = new TransformerFactoryImpl();
    TransformerFactoryImpl sfactory = new TransformerFactoryImpl();
    TransformerFactoryImpl factory11 = new TransformerFactoryImpl();
    TransformerFactoryImpl schemaAsFactory = new TransformerFactoryImpl();  // use a separate config for schemaas tests
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
    boolean timingOnly = false;

    Writer results;

    /**
     * Some tests use schemas that conflict with others, so they can't use the common schema cache.
     * These tests are run in a Configuration of their own. (Ideally we would put this list in a
     * catalogue file of some kind).
     */

    static HashSet noCacheTests = new HashSet(30);
    static {
        noCacheTests.add("schemainline20_005_01");
        noCacheTests.add("schemamatch20_001_01");
        noCacheTests.add("schemamatch20_003_01");
        noCacheTests.add("schemamatch20_005_01");
        noCacheTests.add("schemamatch20_007_01");
        noCacheTests.add("schemamatch20_036_01");
        noCacheTests.add("schemamatch20_038_01");
        noCacheTests.add("schemamatch20_061_01");
        noCacheTests.add("schemamatch20_079_01");
        noCacheTests.add("schemamatch20_092_01");
        noCacheTests.add("schemamatch20_123_01");
        noCacheTests.add("schemamatch20_140_01");
        noCacheTests.add("schemanodetest20_001_01");
        noCacheTests.add("schemanodetest20_023_01");
        noCacheTests.add("schvalid001");
        noCacheTests.add("schvalid009");
        noCacheTests.add("schvalid014");
        noCacheTests.add("schvalid015");
        noCacheTests.add("schvalid020");
        noCacheTests.add("striptype20_003_01");
        noCacheTests.add("striptype20_006_01");
        noCacheTests.add("striptype20_008_01");
        noCacheTests.add("striptype20_011_01");
        noCacheTests.add("striptype20_012_01");
        noCacheTests.add("striptype20_039_01");

    }

    private NameTest elementNameTest(NamePool pool, String local) {
        int nameFP = pool.allocate("", "http://www.w3.org/2005/05/xslt20-test-catalog", local) & NamePool.FP_MASK;
        return new NameTest(Type.ELEMENT, nameFP, pool);
    }

    private NodeInfo getChildElement(NodeInfo parent, NameTest child) {
        return (NodeInfo)parent.iterateAxis(Axis.CHILD, child).next();
    }

    public void go(String[] args) throws SAXException, ParserConfigurationException {


        testSuiteDir = args[0];
        HashSet exceptions = new HashSet();

        for (int i=1; i<args.length; i++) {
            if (args[i].equals("-w")) {
                showWarnings = true;
            } else if (args[i].equals("-t")) {
                timingOnly = true;
            } else {
                testPattern = Pattern.compile(args[1]);
            }
        }

        try {
//            parser = SAXParserFactory.newInstance().newSAXParser().getXMLReader();
//            if (!parser.getFeature("http://xml.org/sax/features/xml-1.1")) {
//                System.err.println("Warning: XML parser does not support XML 1.1 - " + parser.getClass());
//            };
            NamePool pool = new NamePool();
            Configuration config = new Configuration();
            parser = config.getSourceParser();
            if (!parser.getFeature("http://xml.org/sax/features/xml-1.1")) {
                System.err.println("Warning: XML parser does not support XML 1.1 - " + parser.getClass());
            };
            resultParser = config.getSourceParser();
            resultParser.setEntityResolver(
                    new EntityResolver() {
                        public InputSource resolveEntity(String publicId, String systemId) {
                            return new InputSource(new StringReader(""));
                        }
                    }
            );
            fragmentParser = config.getSourceParser();
            SchemaAwareConfiguration sconfig = new SchemaAwareConfiguration();
            SchemaAwareConfiguration sasconfig = new SchemaAwareConfiguration();
            Configuration config11 = new Configuration();
            config11.setXMLVersion(Configuration.XML11);
            config.setNamePool(pool);
            sconfig.setNamePool(pool);
            config11.setNamePool(pool);
            sfactory.setConfiguration(sconfig);
            factory.setConfiguration(config);
            factory11.setConfiguration(config11);
            schemaAsFactory.setConfiguration(sasconfig);

            errorListener = new MyErrorListener();
            factory.setErrorListener(errorListener);
            sfactory.setErrorListener(errorListener);

            String testURI = "http://www.w3.org/2005/05/xslt20-test-catalog";
            int testCaseFP = pool.allocate("", testURI, "testcase") & NamePool.FP_MASK;
            NameTest testCaseNT = new NameTest(Type.ELEMENT, testCaseFP, pool);

            NameTest nameNT = elementNameTest(pool, "name");
            NameTest inputNT = elementNameTest(pool, "input");
            NameTest outputNT = elementNameTest(pool, "output");
            NameTest stylesheetNT = elementNameTest(pool, "stylesheet");
            NameTest schemaNT = elementNameTest(pool, "schema");
            NameTest initialModeNT = elementNameTest(pool, "initial-mode");
            NameTest entryNamedTemplateNT = elementNameTest(pool, "entry-named-template");
            NameTest sourceDocumentNT = elementNameTest(pool, "source-document");
            NameTest stylesheetParametersNT = elementNameTest(pool, "stylesheet-parameters");
            NameTest paramNT = elementNameTest(pool, "param");
            NameTest resultDocumentNT = elementNameTest(pool, "result-document");
            NameTest errorNT = elementNameTest(pool, "error");
            NameTest validationNT = elementNameTest(pool, "validation");
            NameTest discretionaryItemsNT = elementNameTest(pool, "discretionary-items");
            NameTest discretionaryFeatureNT = elementNameTest(pool, "discretionary-feature");
            NameTest discretionaryChoiceNT = elementNameTest(pool, "discretionary-choice");
            NameTest initialContextNodeNT = elementNameTest(pool, "initial-context-node");


            int fileAtt = pool.allocate("", "", "file") & NamePool.FP_MASK;
            int errorIdAtt = pool.allocate("", "", "error-id") & NamePool.FP_MASK;
            int typeAtt = pool.allocate("", "", "type") & NamePool.FP_MASK;
            int nameAtt = pool.allocate("", "", "name") & NamePool.FP_MASK;
            int behaviorAtt = pool.allocate("", "", "behavior") & NamePool.FP_MASK;
            int qnameAtt = pool.allocate("", "", "qname") & NamePool.FP_MASK;
            int modeAtt = pool.allocate("", "", "mode") & NamePool.FP_MASK;
            int validatesAtt = pool.allocate("", "", "validates") & NamePool.FP_MASK;
            int roleAtt = pool.allocate("", "", "role") & NamePool.FP_MASK;

            DocumentInfo exceptionsDoc = config.buildDocument(
                    new StreamSource(new File(testSuiteDir + '/' + getResultDirectoryName() + "/exceptions.xml"))
            );

            AxisIterator exceptionTestCases = exceptionsDoc.iterateAxis(Axis.DESCENDANT, testCaseNT);
            while (true) {
                NodeInfo testCase = (NodeInfo)exceptionTestCases.next();
                if (testCase == null) {
                    break;
                }
                String name = testCase.getAttributeValue(nameAtt);
                StringTokenizer tok = new StringTokenizer(name);
                while (tok.hasMoreElements()) {
                    exceptions.add(tok.nextElement());
                }
            }


            DocumentInfo catalog = config.buildDocument(
                    new StreamSource(new File(testSuiteDir + "/catalog.xml"))
            );

            results = new BufferedWriter(new FileWriter(new File(testSuiteDir + "/SaxonResults/results"
                        + Version.getProductVersion() + ".xml")));

            results.write("<test-suite-result>\n");
            results.write(" <implementation name='Saxon-SA' version='" + Version.getProductVersion() +
                    "' anonymous-result-column='false'>\n");
            results.write("  <organization name='http://www.saxonica.com/' anonymous='false'/>\n");
            results.write("  <submitter name='Michael Kay' email='mike@saxonica.com'/>\n");
            outputDiscretionaryItems();
            results.write(" </implementation>\n");
            results.write(" <test-run dateRun='YYYY-MM-DD' testsuiteVersion='1.0.4'/>");

            long startTime = (new Date()).getTime();

            AxisIterator testCases = catalog.iterateAxis(Axis.DESCENDANT, testCaseNT);
            while (true) {
                boolean useAssociated = false;
                NodeInfo testCase = (NodeInfo)testCases.next();
                if (testCase == null) {
                    break;
                }

                String testName = getChildElement(testCase, nameNT).getStringValue();
                if (testPattern != null && !testPattern.matcher(testName).matches()) {
                    continue;
                }
                if (exceptions.contains(testName)) {
                    continue;
                }
                if (isExcluded(testName)) {
                    continue;
                }
                //if (!timingOnly) {
                    System.err.println("Test " + testName);
                //}
                NodeInfo testInput = getChildElement(testCase, inputNT);

                NodeInfo stylesheet = getChildElement(testInput, stylesheetNT);
                String absXSLName = null;
                if (stylesheet == null) {
                    useAssociated = true;
                } else {
                    absXSLName = testSuiteDir + "/TestInputs/" + stylesheet.getAttributeValue(fileAtt);
                }

                NodeInfo sourceDocument = getChildElement(testInput, sourceDocumentNT);
                String absXMLName = null;
                if (sourceDocument != null) {
                    absXMLName = testSuiteDir + "/TestInputs/" + sourceDocument.getAttributeValue(fileAtt);
                }

                boolean schemaAware = false;
                boolean recoverRecoverable = true;
                boolean backwardsCompatibility = true;
                boolean supportsDOE = true;
                boolean recoverSESU0007 = false;
                NodeInfo discretionaryItems = getChildElement(testCase, discretionaryItemsNT);
                if (discretionaryItems != null) {
                    AxisIterator features = discretionaryItems.iterateAxis(Axis.CHILD, discretionaryFeatureNT);
                    while (true) {
                        NodeInfo feature = (NodeInfo)features.next();
                        if (feature == null) break;
                        String featureName = feature.getAttributeValue(nameAtt);
                        if ("schema_aware".equals(featureName)) {
                            schemaAware = "on".equals(feature.getAttributeValue(behaviorAtt));
                        } else if ("XML_1.1".equals(featureName)) {
                            xml11 = "on".equals(feature.getAttributeValue(behaviorAtt));
                        } else if ("backwards_compatibility".equals(featureName)) {
                            backwardsCompatibility = "on".equals(feature.getAttributeValue(behaviorAtt));
                        } else if ("disabling_output_escaping".equals(featureName)) {
                            supportsDOE = "on".equals(feature.getAttributeValue(behaviorAtt));
                        }
                    }
                    AxisIterator choices = discretionaryItems.iterateAxis(Axis.CHILD, discretionaryChoiceNT);
                    while (true) {
                        NodeInfo choice = (NodeInfo)choices.next();
                        if (choice == null) break;
                        String featureName = choice.getAttributeValue(nameAtt);
                        if ("error".equals(choice.getAttributeValue(behaviorAtt))) {
                            recoverRecoverable = false;
                        } else if ("SESU0007".equals(featureName)) {
                            recoverSESU0007 = "recovery".equals(choice.getAttributeValue(behaviorAtt));
                        }
                    }
                }

                if (!backwardsCompatibility) {
                    // Saxon cannot run with BC switched off
                    results.write(" <testcase name='" + testName + "' result='not run' comment='requires backwards-compatibility=off'/>\n");
                    continue;
                }

                if (!supportsDOE) {
                    // Saxon cannot run with DOE switched off
                    results.write(" <testcase name='" + testName + "' result='not run' comment='requires disable-output-escaping=off'/>\n");
                    continue;
                }

                if (recoverSESU0007) {
                    // Saxon cannot recover from error SESU0007
                    results.write(" <testcase name='" + testName + "' result='not run' comment='requires recovery from error SESU0007'/>\n");
                    continue;
                }

                NodeInfo initialMode = getChildElement(testInput, initialModeNT);
                String initialModeClarkName = null;
                if (initialMode != null) {
                    initialModeClarkName = initialMode.getAttributeValue(qnameAtt);
                    if (initialModeClarkName.contains(":")) {
                        NamespaceResolver resolver = new InscopeNamespaceResolver(initialMode);
                        final NameChecker checker = config.getNameChecker();
                        String[] parts = checker.getQNameParts(initialModeClarkName);
                        String uri = resolver.getURIForPrefix(parts[0], false);
                        initialModeClarkName =
                                new QNameValue(parts[0], uri, parts[1], BuiltInAtomicType.QNAME, checker).getClarkName();
                    }
                }
                NodeInfo initialTemplate = getChildElement(testInput, entryNamedTemplateNT);
                String initialTemplateClarkName = null;
                if (initialTemplate != null) {
                    initialTemplateClarkName = initialTemplate.getAttributeValue(qnameAtt);
                    if (initialTemplateClarkName.contains(":")) {
                        NamespaceResolver resolver = new InscopeNamespaceResolver(initialTemplate);
                        final NameChecker checker = config.getNameChecker();
                        String[] parts = checker.getQNameParts(initialTemplateClarkName);
                        String uri = resolver.getURIForPrefix(parts[0], false);
                        initialTemplateClarkName =
                                new QNameValue(parts[0], uri, parts[1], BuiltInAtomicType.QNAME, checker).getClarkName();
                    }
                }
                NodeInfo initialContextNode = getChildElement(testInput, initialContextNodeNT);
                String initialContextPath = null;
                if (initialContextNode != null) {
                    initialContextPath = initialContextNode.getStringValue();
                }
                NodeInfo validation = getChildElement(testInput, validationNT);
                String validationMode = null;
                if (validation != null) {
                    validationMode = validation.getAttributeValue(modeAtt);
                }

                HashMap params = null;
                NodeInfo paramList = getChildElement(testInput, stylesheetParametersNT);
                if (paramList != null) {
                    params = new HashMap(5);
                    AxisIterator paramIter = paramList.iterateAxis(Axis.CHILD, paramNT);
                    while (true) {
                        NodeInfo param = (NodeInfo)paramIter.next();
                        if (param == null) break;
                        String name = param.getAttributeValue(qnameAtt);
                            // TODO: turn into a clark name
                        String value = param.getStringValue();
                        params.put(name, value);
                    }
                }
                SequenceIterator schemas = testInput.iterateAxis(Axis.CHILD, schemaNT);
                while (true) {
                    NodeInfo schema = (NodeInfo)schemas.next();
                    if (schema == null) {
                        break;
                    }
                    String role = schema.getAttributeValue(roleAtt);
                    if (("source-validator".equals(role) || "source-reference".equals(role))
                            /* && schema.getAttributeValue(validatesAtt) != null */) {
                        validationMode = "strict";
                        // TODO: control which source documents are validated...
                    }
                }
                NodeInfo testOutput = getChildElement(testCase, outputNT);
                NodeInfo resultDocument = getChildElement(testOutput, resultDocumentNT);
                    // TODO: handle alternative result documents
                String refFileName = null;
                String outFileName;
                String comparator = "xml";
                if (resultDocument != null) {
                    refFileName = testSuiteDir + "/ExpectedTestResults/" + resultDocument.getAttributeValue(fileAtt);
                    outFileName = testSuiteDir + '/' + getResultDirectoryName() + '/' + resultDocument.getAttributeValue(fileAtt);
                    comparator = resultDocument.getAttributeValue(typeAtt);
                } else {
                    outFileName = testSuiteDir + '/' + getResultDirectoryName() + "/temp.out";
                }
                NodeInfo error = getChildElement(testOutput, errorNT);
                String expectedError = null;
                if (error != null) {
                    expectedError = error.getAttributeValue(errorIdAtt);
                }
                boolean success;
                errorListener.errorCode = null;
                try {
                    runXSLT(testName, absXMLName, absXSLName, initialModeClarkName, initialTemplateClarkName,
                            outFileName, params, initialContextPath,
                            useAssociated, schemaAware, validationMode, recoverRecoverable);
                    success = true;
                    if (expectedError != null && resultDocument == null && !timingOnly) {
                        System.err.println("Test failed. Expected error " + expectedError + ", got success");
                        success = false;
                        results.write(" <testcase name='" + testName +
                                "' result='differ' comment='Expected error " +
                                expectedError + ", got success'/>\n");
                    }
                } catch (XPathException e) {
                    if (timingOnly) {
                        continue;
                    }
                    String actual = errorListener.errorCode;
                    if (actual == null) {
                        actual = e.getErrorCodeLocalPart();
                    }
                    if (expectedError != null && actual != null && actual.equals(expectedError)) {
                        System.err.println("Test succeeded (" + expectedError + ')');
                        results.write(" <testcase name='" + testName +
                                "' result='full' comment='Error " +
                                expectedError + " as expected'/>\n");
                    } else if (expectedError != null) {
                        System.err.println("Test succeeded (??) (expected " + expectedError + ", got " + actual + ')');
                        results.write(" <testcase name='" + testName +
                                "' result='different-error' comment='Expected " +
                                expectedError + " got " + actual + "'/>\n");
                    } else {
                        System.err.println("Test failed. Expected success, got " + actual);
                        results.write(" <testcase name='" + testName +
                                "' result='differ' comment='Expected success, got " +
                                actual + "'/>\n");
                    }
                    success = false;
                    continue;
                } catch (Exception e2) {
                    success = false;
                    e2.printStackTrace();
                }


                if (success && !timingOnly) {
                    boolean same = compare(outFileName, refFileName, comparator);
                    if (same) {
                        results.write(" <testcase name='" + testName + "' result='full'/>\n");
                    } else {
                        results.write(" <testcase name='" + testName + "' result='differ'/>\n");
                    }
                }

            }

            results.write("</test-suite-result>");
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

    protected void runXSLT(String testName, String xml, String xsl, String initialMode,
                           String initialTemplate, String out, HashMap params, String initialContextPath,
                           boolean useAssociated, boolean schemaAware,
                           String validationMode, boolean recoverRecoverable) throws XPathException {
        StreamResult sr = new StreamResult(new File(out));
        TransformerFactory f;
        if (noCacheTests.contains(testName) || testName.startsWith("schemaas20") ||
                testName.startsWith("striptype20") || testName.startsWith("notation20")) {
            f = new TransformerFactoryImpl();
            SchemaAwareConfiguration sconfig = new SchemaAwareConfiguration();
            sconfig.setNamePool(factory.getConfiguration().getNamePool());
            ((TransformerFactoryImpl)f).setConfiguration(sconfig);
        } else {
            if (schemaAware) {
                f = sfactory;
            } else if (xml11) {
                f = factory11;
//            } else if (testName.startsWith("schemaas20")) {
//                f = schemaAsFactory;
            } else {
                f = factory;
            }
        }

        Source source = null;
        if (xml != null) {
            source = buildSource(xml, validationMode);
            if (initialContextPath != null) {
                final Configuration config = ((TransformerFactoryImpl)f).getConfiguration();
                DocumentInfo doc = config.buildDocument(source);
                XPathEvaluator xpe = new XPathEvaluator(config);
                XPathExpression expr = xpe.createExpression(initialContextPath);
                NodeInfo node = (NodeInfo)expr.evaluateSingle(doc);
                source = node;
            }
        }
        Templates sheet = null;
        try {
            Source styleSource = null;
            if (useAssociated) {
                styleSource = f.getAssociatedStylesheet(source, null, null, null);
            } else {
                styleSource = new StreamSource(new File(xsl));
            }
            sheet = f.newTemplates(styleSource);
        } catch (TransformerConfigurationException e) {
            throw StaticError.makeStaticError(e);
        }

        Transformer inst = null;
        try {
            inst = sheet.newTransformer();
        } catch (TransformerConfigurationException e) {
            throw StaticError.makeStaticError(e);
        }
        if (initialMode != null) {
            ((Controller)inst).setInitialMode(initialMode);
        }
        if (initialTemplate != null) {
            ((Controller)inst).setInitialTemplate(initialTemplate);
        }
        if (params != null) {
            Iterator iter = params.keySet().iterator();
            while (iter.hasNext()) {
                String name = (String)iter.next();
                String value = (String)params.get(name);
                inst.setParameter(name, value);
            }
        }
        if ("strict".equals(validationMode)) {
            ((TransformerFactoryImpl)f).getConfiguration().setSchemaValidationMode(Validation.STRICT);
        } else {
            ((TransformerFactoryImpl)f).getConfiguration().setSchemaValidationMode(Validation.STRIP);
        }
        inst.setURIResolver(factory.getURIResolver());
        inst.setErrorListener(errorListener);
        ((Controller)inst).setRecoveryPolicy(recoverRecoverable ? Configuration.RECOVER_SILENTLY : Configuration.DO_NOT_RECOVER);
        // To avoid test results being dependent on the date and time (and timezone), set a fixed
        // date and time for the run
        //((Controller)inst).setCurrentDateTime(new DateTimeValue("2005-01-01T12:49:30.5+01:00"));

        try {
            inst.transform(source, sr);
        } catch (TransformerException e) {
            throw DynamicError.makeDynamicError(e);
        }
    }

    /**
     * Construct source object. This method allows subclassing e.g. to build a DOM or XOM source.
     * @param xml
     * @return
     * @throws XPathException
     */

    protected Source buildSource(String xml, String validationMode) throws XPathException {
        Source ss = new StreamSource(new File(xml));
        if ("strict".equals(validationMode)) {
            ss = AugmentedSource.makeAugmentedSource(ss);
            ((AugmentedSource)ss).setSchemaValidationMode(Validation.STRICT);
        }
        return ss;
    }


    static CanonicalXML canon = new CanonicalXML();

    private boolean compare(String outfile, String reffile, String comparator) {
        if (reffile == null) {
            System.err.println("*** No reference results available");
            return false;
        }
        File outfileFile = new File(outfile);
        File reffileFile = new File(reffile);

        if (!reffileFile.exists()) {
            System.err.println("*** No reference results available");
            return false;
        }

        // try direct comparison first

        String refResult = null;
        String actResult = null;

        try {
            // This is decoding bytes assuming the platform default encoding
            FileReader reader1 = new FileReader(outfileFile);
            FileReader reader2 = new FileReader(reffileFile);
            char[] contents1 = new char[65536];
            char[] contents2 = new char[65536];
            int size1 = reader1.read(contents1, 0, 65536);
            int size2 = reader2.read(contents2, 0, 65536);
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

            actResult = actResult.replace("\r\n", "\n");
            refResult = refResult.replace("\r\n", "\n");
            if (actResult.equals(refResult)) {
                return true;
            }
            if (size1 == 0) {
                System.err.println("** ACTUAL RESULTS EMPTY; REFERENCE RESULTS LENGTH " + size2);
                return false;
            }
            if (size2 == 0) {
                System.err.println("** REFERENCED RESULTS EMPTY; ACTUAL RESULTS LENGTH " + size2);
                return false;
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
                return compare(xml1.toString(), xml2.toString(), "xml");
            } catch (IOException e) {
                e.printStackTrace();
                return false;
            }
        } else if (comparator.equals("xhtml-output")) {
            refResult = canonizeXhtml(refResult);
            actResult = canonizeXhtml(actResult);
            return (actResult.equals(refResult));

        } else if (comparator.equals("xml-frag")) {
            try {
                return compareFragments(outfileFile, reffileFile, outfile);
            } catch (Exception err2) {
                System.err.println("Failed to compare results for: " + outfile);
                err2.printStackTrace();
                return false;
            }
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
                        return true;
                    } else {
                        System.err.println("Mismatch with reference results: " + outfile);
                        System.err.println("REFERENCE RESULTS:");
                        System.err.println(truncate(refxml));
                        System.err.println("ACTUAL RESULTS:");
                        System.err.println(truncate(outxml));
                        findDiff(refxml, outxml);
                        return false;
                    }
                } else {
                    return true;
                }
            } catch (Exception err) {
                try {
                    System.err.println("Failed to compare results for: " + outfile + ": " + err.getMessage());
                    System.err.println("** Attempting XML Fragment comparison");
                    boolean b = compareFragments(outfileFile, reffileFile, outfile);
                    System.err.println("** " + (b ? "Success" : "Still different"));
                    return b;
                } catch (Exception err2) {
                    System.err.println("Again failed to compare results for: " + outfile);
                    err2.printStackTrace();
                }
                return false;
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
            xhtmlCanonizer = factory.newTemplates(source);
        }
        return xhtmlCanonizer;
    }

    private boolean compareFragments(File outfileFile, File reffileFile, String outfile) {
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
            System.err.println("Mismatch with reference results: " + outfile);
            System.err.println("REFERENCE RESULTS:");
            System.err.println(truncate(refxml2));
            System.err.println("ACTUAL RESULTS:");
            System.err.println(truncate(outxml2));
            findDiff(refxml2, outxml2);
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

    private void outputDiscretionaryItems() throws java.io.IOException {
        results.write("  <discretionary-items/>\n");
    }

    private static String eval(XPathEvaluator xpath, String expression, Source source) throws XPathException {
        return (String)xpath.createExpression(expression).evaluateSingle(source);
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
