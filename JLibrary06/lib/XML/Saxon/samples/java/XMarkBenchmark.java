
import com.saxonica.SchemaAwareTransformerFactory;
import com.saxonica.deploy.CompiledUserQuery;
import com.saxonica.validate.SchemaAwareConfiguration;
import net.sf.saxon.Configuration;
import net.sf.saxon.TransformerFactoryImpl;
import net.sf.saxon.Version;
import net.sf.saxon.event.Sink;
import net.sf.saxon.om.DocumentInfo;
import net.sf.saxon.om.Validation;
import net.sf.saxon.query.DynamicQueryContext;
import net.sf.saxon.query.StaticQueryContext;
import net.sf.saxon.query.XQueryExpression;
import net.sf.saxon.trans.XPathException;

import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.Templates;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.OutputStream;
import java.net.URL;
import java.net.URLClassLoader;
import java.text.DecimalFormat;
import java.util.Properties;


/**
 * Runs the XMark XQuery benchmark: see
 * <a href="http://monetdb.cwi.nl/xml/index.html">http://monetdb.cwi.nl/xml/index.html</a
 *
 */
public class XMarkBenchmark {

    /**
     * Class is not instantiated, so give it a private constructor
     */
    private XMarkBenchmark() {
    }

    static boolean pull = false;
    static boolean lazy = false;
    static boolean saproduct = false;
    static boolean satests = false;
    static boolean xslt = false;
    static boolean runCompiled = false;
    static boolean checkResults = false;
    static int test = -1;

    /**
     * Method main
     */
    public static void main(String argv[]) throws Exception {


        for (int i=0; i<argv.length; i++) {
            if (argv[i].equals("-pull")) pull = true;
            if (argv[i].equals("-lazy")) lazy = true;
            if (argv[i].equals("-sa")) saproduct = true;
                // means use Saxon-SA optimizer (not the schema-aware version of the tests)
            if (argv[i].equals("-satests")) satests = true;
            if (argv[i].equals("-xslt")) xslt = true;
            if (argv[i].equals("-runcomp")) runCompiled = true;
            if (argv[i].equals("-check")) checkResults = true;
            if (argv[i].startsWith("-q")) {
                test = Integer.parseInt(argv[i].substring(2));
            }
            if (argv[i].equals("-?")) {
                System.err.println("Options: -pull -lazy -sa -xslt -compile -runcomp");
            }
        }


        if (xslt) {
            transform(pull, lazy, saproduct);
        } else {
            query();
        }
    }

    public static void query() throws Exception {

        String dir = (satests ? "c:\\javalib\\xmark\\sa\\" : "c:\\javalib\\xmark\\");
        String[] tests = {"xmark1.xml", "xmark4.xml", "xmark10.xml"};
        String options = "";
        if (saproduct) options += "-sa ";
        if (satests) options += "-satests ";
        if (pull) options += "-pull ";
        if (lazy) options += "-lazy ";
        if (runCompiled) options += "-runcomp";
        System.out.println("<xmark-results product='Saxon' lang='query' version='" + Version.getProductVersion() +
                "' options='" + options + "'>");

        for (int f=0; f<tests.length; f++) {
            File file = new File(dir + tests[f]);

            Configuration config = (saproduct ? new SchemaAwareConfiguration() : new Configuration());
            if (lazy) {
                config.setLazyConstructionMode(true);
                config.setAllNodesUntyped(true);
            }
            if (satests) {
                config.setSchemaValidationMode(Validation.STRICT);
                config.addSchemaSource(new StreamSource(new File(dir + "schema.xsd")),
                        config.getErrorListener());
            }

            Source streamSource = new StreamSource(file);
            long pstart = System.currentTimeMillis();
            DocumentInfo doc = config.buildDocument(streamSource);
            long pend = System.currentTimeMillis();

            System.out.println("  <file name='" + tests[f] +
                    "' size='" + file.length() +
                    "' build-time='" + (pend-pstart) + "'>");
            Properties props = new Properties();
            props.setProperty("method", "xml");
            props.setProperty("indent", "yes");

            if (runCompiled) {
                for (int q=1; q<=20; q++) {
                    if (test != -1 && test != q) {
                        continue;
                    }
                    try {

                        ClassLoader usercodeLoader = new URLClassLoader(
                                new URL[]{new URL("file:///c:/javalib/xMark/java/")});
                        Class userClass = usercodeLoader.loadClass("Q" + q);
                        CompiledUserQuery cuq = (CompiledUserQuery) userClass.newInstance();
                        cuq.setConfiguration(config);
                        final DynamicQueryContext dqc = new DynamicQueryContext(config);
                        cuq.setDynamicContext(dqc);

                        int runs = 0;
                        long totalTime = 0;
                        long min = Integer.MAX_VALUE;
                        long max = 0;
                        if (checkResults && f==0) {
                            dqc.setContextItem(doc);
                            File out = new File("c:/javalib/xmark/output/q" + q + ".out");
                            //out.mkdirs();
                            OutputStream os = new FileOutputStream(out);
                            Result result = new StreamResult(os);
                            cuq.run(result, props);
                            os.close();
                            compare(new File("c:/javalib/xmark/output/q" + q + ".out"),
                                    new File("c:/javalib/xmark/gold1m/q" + q + ".out"));
                        }
                        for (int t=0; t<1000; t++) {

                            dqc.setContextItem(doc);
                            Result result = new Sink();
                            long start, end;
                            start = System.currentTimeMillis();
                            cuq.run(result, props);
                            end = System.currentTimeMillis();

                            runs++;
                            long time = (end - start);
                            if (time < min) min = time;
                            if (time > max) max = time;
                            totalTime += time;
                            if (totalTime > 30000 && t>=2) break;
                        }
                        double avg = ((double)totalTime) / runs;
                        String avgs = format.format(avg);
                        System.out.println("    <query q='" + q +
                                    "' avg='" + avgs +
                                    "' runs='" + runs +
                                    "' min='" + min +
                                    "' max='" + max + "'/>");
                    } catch (XPathException err) {
                        System.err.println("Error in test " + q);
                        System.err.println(err.getMessageAndLocation());
                    }
                }
            } else {

                for (int q=1; q<=20; q++) {
                    if (test != -1 && test != q) {
                        continue;
                    }
                    try {
                        File query = new File(dir + 'q' + q + ".xq");
                        StaticQueryContext qenv = new StaticQueryContext(config);
                        qenv.setBaseURI(query.toURI().toString());
                        XQueryExpression exp = qenv.compileQuery(new FileReader(query));
                        int runs = 0;
                        long totalTime = 0;
                        long min = Integer.MAX_VALUE;
                        long max = 0;
                        for (int t=0; t<1000; t++) {
                            final DynamicQueryContext context = new DynamicQueryContext(config);
                            context.setContextItem(doc);
                            Result result = new Sink();
                            long start, end;
                            if (pull) {
                                start = System.currentTimeMillis();
                                exp.pull(context, result, props);
                                end = System.currentTimeMillis();
                            } else {
                                start = System.currentTimeMillis();
                                exp.run(context, result, props);
                                end = System.currentTimeMillis();
                            }
                            runs++;
                            long time = (end - start);
                            if (time < min) min = time;
                            if (time > max) max = time;
                            totalTime += time;
                            if (totalTime > 30000 && t>=2) break;
                        }
                        double avg = ((double)totalTime) / runs;
                        String avgs = format.format(avg);
                        System.out.println("    <query q='" + q +
                                    "' avg='" + avgs +
                                    "' runs='" + runs +
                                    "' min='" + min +
                                    "' max='" + max + "'/>");
                    } catch (XPathException err) {
                        System.err.println("Error in test " + q);
                        System.err.println(err.getMessageAndLocation());
                    }
                }
            }
            System.out.println("  </file>");
        }
        System.out.println("</xmark-results>");
    }

    public static void transform(boolean pull, boolean lazy, boolean sa) throws Exception {

        String dir = "c:\\javalib\\xmark\\";
        String[] tests = {"xmark1.xml", "xmark4.xml", "xmark10.xml"};

        System.out.println("<xmark-results product='Saxon' lang='xslt' version='" + Version.getProductVersion() + "'>");

        for (int f=0; f<tests.length; f++) {
            File file = new File(dir + tests[f]);

//            String factoryName = (sa ? "com.saxonica.SchemaAwareTransformerFactory" : "net.sf.saxon.TransformerFactoryImpl");
//            System.setProperty("java.xml.transform.TransformerFactory", factoryName);
            TransformerFactory factory;
            if (sa) {
                factory = new SchemaAwareTransformerFactory();
            } else {
                factory = new TransformerFactoryImpl();
            }
            Configuration config = ((TransformerFactoryImpl)factory).getConfiguration();
            if (lazy) {
                config.setLazyConstructionMode(true);
            }

            Source streamSource = new StreamSource(file);
            long pstart = System.currentTimeMillis();
            DocumentInfo doc = config.buildDocument(streamSource);
            long pend = System.currentTimeMillis();

            System.out.println("  <file name='" + tests[f] +
                    "' size='" + file.length() +
                    "' schema-aware='" + config.isSchemaAware(Configuration.XSLT) +
                    "' build-time='" + (pend-pstart) + "'>");
            Properties props = new Properties();



            for (int q=1; q<=20; q++) {
                //if (q==9) continue;
                File sheet = new File(dir + 'q' + q + ".xsl");
                if (!sheet.exists()) {
                    continue;
                }
                Templates templates = factory.newTemplates(new StreamSource(sheet));

                int runs = 0;
                long totalTime = 0;
                long min = Integer.MAX_VALUE;
                long max = 0;
                for (int t=0; t<10; t++) {
                    Result result = new Sink();
                    long start, end;

                    start = System.currentTimeMillis();
                    templates.newTransformer().transform(doc, result);
                    end = System.currentTimeMillis();

                    runs++;
                    long time = (end - start);
                    if (time < min) min = time;
                    if (time > max) max = time;
                    totalTime += time;
                    if (totalTime > 1000 && t>=2) break;
                }
                System.out.println("    <query q='" + q +
                            "' avg='" + (totalTime / runs) +
                            "' runs='" + runs +
                            "' min='" + min +
                            "' max='" + max + "'/>");
            }
            System.out.println("  </file>");
        }
        System.out.println("</xmark-results>");
    }

    /**
     * Compare two files
     */

    private static void compare(File actual, File gold) {
        try {
            // This is decoding bytes assuming the platform default encoding
            FileReader reader1 = new FileReader(actual);
            FileReader reader2 = new FileReader(gold);
            char[] contents1 = new char[65536];
            char[] contents2 = new char[65536];
            int size1 = reader1.read(contents1, 0, 65536);
            int size2 = reader2.read(contents2, 0, 65536);
            reader1.close();
            reader2.close();
            int offset1 = 0;
            int offset2 = 0;
            if (contents1[0]=='\u00ef' && contents1[1]=='\u00bb' && contents1[2]=='\u00bf') {
                offset1 += 3;
            }
            if (contents2[0]=='\u00ef' && contents2[1]=='\u00bb' && contents2[2]=='\u00bf') {
                offset2 += 3;
            }
            String actResult = (size1==-1 ? "" : new String(contents1, offset1, size1-offset1));
            String refResult = (size2==-1 ? "" : new String(contents2, offset2, size2-offset2));

//            actResult = actResult.replace("\r\n", "\n");
//            refResult = refResult.replace("\r\n", "\n");
            if (actResult.equals(refResult)) {
                System.err.println("Results compared OK");
            } else {
                System.err.println("*** Results do not match");
            }
        } catch (Exception err) {
            System.err.println("Failed to compare with gold results: " + err.getMessage());
        }
    }

    private final static DecimalFormat format = new DecimalFormat("######0.00");


}

//
// The contents of this file are subject to the Mozilla Public License Version 1.0 (the "License");
// you may not use this file except in compliance with the License. You may obtain a copy of the
// License at http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied.
// See the License for the specific language governing rights and limitations under the License.
//
// The Original Code is: all this file.
//
// The Initial Developer of the Original Code is Michael H. Kay.
//
// Portions created by (your name) are Copyright (C) (your legal entity). All Rights Reserved.
//
// Contributor(s): none.
//
