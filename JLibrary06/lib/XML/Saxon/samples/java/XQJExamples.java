
import net.sf.saxon.javax.xml.xquery.*;
import net.sf.saxon.xqj.SaxonXQDataSource;
import org.w3c.dom.Node;

import javax.xml.namespace.QName;
import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamConstants;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Properties;


/**
 * Some examples to show how the Saxon XQuery API should be used
 */
public class XQJExamples {

    /**
     * Class is not instantiated, so give it a private constructor
     */
    private XQJExamples() {
    }

    /**
     * Method main
     */
    public static void main(String argv[]) {

        List tests = new ArrayList();
        tests.add(new TestA());
        tests.add(new TestB());
        tests.add(new TestC());
        tests.add(new TestD());
        tests.add(new TestE());
        tests.add(new TestF());
        tests.add(new TestG());
        tests.add(new TestH());
        tests.add(new TestI());

        String test = "all";
        if (argv.length > 0) {
            test = argv[0];
        }


        boolean found = false;
        Iterator allTests = tests.iterator();
        while (allTests.hasNext()) {
            Test next = (Test)allTests.next();
            if (test.equals("all") || next.name().equals(test)) {
                found = true;
                try {
                    System.out.println("\n==== " + next.name() + "====\n");
                    next.run();
                } catch (XQException ex) {
                    handleException(ex);
                }
            }
        }

        if (!found) {
            System.err.println("Please supply a valid test name, or 'all' (" + test + "' is invalid)");
        }


    }

    private interface Test {
        public String name();
        public void run() throws XQException;
    }

    /**
     * Show a query producing a document as its result and serializing this
     * directly to System.out
     */

    private static class TestA implements Test {
        public String name() {
            return "TestA";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQPreparedExpression exp = conn.prepareExpression("<a b='c'>{5+2}</a>");
            XQResultSequence result = exp.executeQuery();
            while (result.next()) {
                System.out.println(result.getItemAsString());
            }
        }
    }

    /**
     * Show a query compiled as a reusable XQExpression object, and returning a sequence
     * of integers
     */

    private static class TestB implements Test {
        public String name() {
            return "TestB";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQExpression exp = conn.createExpression();
            XQSequence seq = exp.executeQuery("for $n in 1 to 10 return $n*$n");
            int total = 0;
            while (seq.next()) {
                total += seq.getInt();
            }
            System.out.println("Total: " + total);
        }
    }

    /**
     * Show a query taking input from the context item, reusing the XQExpression object
     */

    private static class TestC implements Test {
        public String name() {
            return "TestC";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQExpression exp = conn.createExpression();

            exp.bindContextItem(ds.createItemFromObject("banana", null));
            XQSequence seq = exp.executeQuery("contains(., 'e')");
            seq.next();
            System.out.println("banana: " + seq.getBoolean());

            exp.bindContextItem(ds.createItemFromObject("apple", null));
            seq = exp.executeQuery("contains(., 'e')");
            seq.next();
            System.out.println("apple: " + seq.getBoolean());

            exp.bindContextItem(ds.createItemFromObject("orange", null));
            seq = exp.executeQuery("contains(., 'e')");
            seq.next();
            System.out.println("orange: " + seq.getBoolean());

        }
    }

    /**
     * Show a query taking input from a parameter, reusing the XQPreparedExpression object
     */

    private static class TestD implements Test {
        public String name() {
            return "TestD";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQPreparedExpression exp = conn.prepareExpression(
                    "declare variable $v as xs:string external; contains($v, 'e')");
            QName v = new QName("v");

            exp.bindObject(v, "banana", null);
            XQSequence seq = exp.executeQuery();
            seq.next();
            System.out.println("banana: " + seq.getBoolean());

            exp.bindObject(v, "apple", null);
            seq = exp.executeQuery();
            seq.next();
            System.out.println("apple: " + seq.getBoolean());

            exp.bindObject(v, "orange", null);
            seq = exp.executeQuery();
            seq.next();
            System.out.println("orange: " + seq.getBoolean());

        }
    }

    /**
     * Show a query producing a DOM as its output. The DOM is then used as input to
     * a second query that wraps it in an element node.
     */

    private static class TestE implements Test {
        public String name() {
            return "TestE";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQPreparedExpression exp = conn.prepareExpression(
                    "<a xmlns='http://a/uri' xmlns:a='another.uri'><b>text</b></a>");
            XQResultSequence result = exp.executeQuery();
            result.next();
            XQItem resultItem = result.getItem();
            Node node = result.getNode();
            System.out.println("DOM node name: " + node.getNodeName());
            System.out.println("DOM node namespace: " + node.getNamespaceURI());
            System.out.println("DOM node children: " + node.getChildNodes().getLength());

            XQItemType contextItemType = resultItem.getItemType();
            XQPreparedExpression copy = conn.prepareExpression("<doc>{.}</doc>", contextItemType);
            System.out.println("Expected result type: " + copy.getStaticResultType());
            copy.bindContextItem(ds.createItemFromNode(node, null));
            XQResultSequence result2 = copy.executeQuery();
            Properties props = new Properties();
            props.setProperty("method", "xml");
            props.setProperty("indent", "yes");
            props.setProperty("omit-xml-declaration", "yes");
            props.setProperty("{http://saxon.sf.net/}indent-spaces", "1");
            result2.writeSequence(System.out, props);
        }
    }

    /**
     * Show a query producing a SAX event stream as its output.
     */

    private static class TestF implements Test {
        public String name() {
            return "TestF";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQPreparedExpression exp = conn.prepareExpression(
                    "document { <a xmlns='http://a/uri' z:in='out' xmlns:z='http://z/uri'><b>{2+2}</b></a> }");
            XQResultSequence result = exp.executeQuery();
            result.next();
            result.writeItemToSAX(new ExampleContentHandler());
        }
    }

    /**
     * Show a query producing a document as its output, which is then read using a StAX client.
     */

    private static class TestG implements Test {
        public String name() {
            return "TestG";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQPreparedExpression exp = conn.prepareExpression(
                    "document { <a xmlns='http://a/uri' z:in='out' xmlns:z='http://z/uri'><b>{2+2}</b></a> }");
            XQResultSequence result = exp.executeQuery();
            XMLStreamReader reader = result.getSequenceAsStream();

            // The following code exploits a Saxon-specific extension to XQJ, which allows an instance
            // of javax.xml.stream.XMLStreamReader to be supplied to the XQJ DataFactory.createItemFromObject method.

            XQPreparedExpression copy = conn.prepareExpression(".");
            copy.bindContextItem(conn.createItemFromObject(reader, null));
            XQResultSequence result2 = copy.executeQuery();
            result2.writeSequence(System.out, new Properties());
        }
    }

    /**
     * Show a query producing a sequence of atomic values as its output, which is then read using a StAX client.
     */

    private static class TestH implements Test {
        public String name() {
            return "TestH";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQPreparedExpression exp = conn.prepareExpression(
                    "(1, 'peach', xs:date('1951-10-11'), xs:duration('PT5M'), 93.7e0, '<the end>')");
            XQResultSequence result = exp.executeQuery();
            XMLStreamReader reader = result.getSequenceAsStream();

            // The following code exploits a Saxon-specific extension to XQJ, which allows an instance
            // of javax.xml.stream.XMLStreamReader to be supplied to the XQJ DataFactory.createItemFromObject method.

            XQPreparedExpression copy = conn.prepareExpression(".");
            copy.bindContextItem(conn.createItemFromObject(reader, null));
            XQResultSequence result2 = copy.executeQuery();
            Properties props = new Properties();
            props.setProperty("method", "text");
            result2.writeSequence(System.out, props);
        }
    }

    /**
     * Show a query producing a document as its output, which is then read using a StAX client.
     * This is designed explitly to demonstrate that element names and namespaces are available
     * at end-element time.
     */

    private static class TestI implements Test {
        public String name() {
            return "TestI";
        }
        public void run() throws XQException {
            XQDataSource ds = new SaxonXQDataSource();
            XQConnection conn = ds.getConnection();
            XQPreparedExpression exp = conn.prepareExpression(
                    "document { <a xmlns='http://a/uri' z:in='out' xmlns:z='http://z/uri'>" +
                    "<b xmlns='http://b/uri'>{2+2}</b>" +
                    "</a> }");
            XQResultSequence result = exp.executeQuery();
            XMLStreamReader reader = result.getSequenceAsStream();
            try {
                while (reader.hasNext()) {
                    int event = reader.next();
                    if (event == XMLStreamConstants.START_ELEMENT) {
                        System.err.println("start {" + reader.getNamespaceURI() + "}" + reader.getLocalName());
                        for (int i=0; i<reader.getNamespaceCount(); i++) {
                            System.err.println("  start namespace " +
                                    reader.getNamespacePrefix(i) + "=" + reader.getNamespaceURI(i));
                        }
                    } else if (event == XMLStreamConstants.END_ELEMENT) {
                        System.err.println("end {" + reader.getNamespaceURI() + "}" + reader.getLocalName());
                        for (int i=0; i<reader.getNamespaceCount(); i++) {
                            System.err.println("  end namespace " +
                                    reader.getNamespacePrefix(i) + "=" + reader.getNamespaceURI(i));
                        }
                    }
                }
            } catch (XMLStreamException e) {
                throw new XQException(e.getMessage());
            }
        }
    }


    /**
     * Handle an exception thrown while running one of the examples
     *
     * @param ex the exception
     */
    private static void handleException(Exception ex) {
        System.out.println("EXCEPTION: " + ex);
        ex.printStackTrace();
    }

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
