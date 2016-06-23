package net.sf.saxon.instruct;
import net.sf.saxon.Configuration;
import net.sf.saxon.expr.*;
import net.sf.saxon.om.Item;
import net.sf.saxon.om.Orphan;
import net.sf.saxon.om.SequenceIterator;
import net.sf.saxon.om.SingletonIterator;
import net.sf.saxon.trans.DynamicError;
import net.sf.saxon.trans.StaticError;
import net.sf.saxon.trans.XPathException;
import net.sf.saxon.type.BuiltInAtomicType;
import net.sf.saxon.type.ItemType;
import net.sf.saxon.type.TypeHierarchy;

import java.io.PrintStream;
import java.util.Iterator;

/**
 * Common superclass for XSLT instructions whose content template produces a text
 * value: xsl:attribute, xsl:comment, xsl:processing-instruction, xsl:namespace,
 * and xsl:text
 */

public abstract class SimpleNodeConstructor extends Instruction {

    protected Expression select = null;

    public SimpleNodeConstructor() {
    }

    public void setSelect(Expression select, Configuration config) throws StaticError {
        this.select = select;
        adoptChildExpression(select);
    }

    public Expression getSelect() {
        return select;
    }

    /**
     * Determine whether this instruction creates new nodes.
     * This implementation returns true.
     */

    public final boolean createsNewNodes() {
        return true;
    }

    /**
     * Get the cardinality of the sequence returned by evaluating this instruction
     * @return the static cardinality
     */

    public int computeCardinality() {
        return StaticProperty.EXACTLY_ONE;
    }        

    public Expression simplify(StaticContext env) throws XPathException {
        if (select != null) {
            select = select.simplify(env);
        }
        return this;
    }

    /**
     * Get the static properties of this expression (other than its type). The result is
     * bit-signficant. These properties are used for optimizations. In general, if
     * property bit is set, it is true, but if it is unset, the value is unknown.
     *
     * @return a set of flags indicating static properties of this expression
     */

    public int computeSpecialProperties() {
        return super.computeSpecialProperties() |
                StaticProperty.SINGLE_DOCUMENT_NODESET;
    }

    /**
     * Method to perform type-checking specific to the kind of instruction
     * @param env
     * @param contextItemType
     * @throws XPathException
     */

    public abstract void localTypeCheck(StaticContext env, ItemType contextItemType) throws XPathException;

    /**
     * The typeCheck() method is called in XQuery, where node constructors
     * are implemented as Expressions. In this case the required type for the
     * select expression is a single string.
     * @param env The static context for the query
     * @return the rewritten expression
     * @throws XPathException if any static errors are found in this expression
     * or any of its children
     */

    public Expression typeCheck(StaticContext env, ItemType contextItemType) throws XPathException {
        localTypeCheck(env, contextItemType);

        if (select != null) {
            final TypeHierarchy th = env.getConfiguration().getTypeHierarchy();
            select = select.typeCheck(env, contextItemType);
            if (!select.getItemType(th).isAtomicType()) {
                select = new Atomizer(select, env.getConfiguration());
            }
            if (!th.isSubType(select.getItemType(th), BuiltInAtomicType.STRING)) {
                select = new AtomicSequenceConverter(select, BuiltInAtomicType.STRING);
            }
            adoptChildExpression(select);
        }
        return this;
    }

    public Expression optimize(Optimizer opt, StaticContext env, ItemType contextItemType) throws XPathException {
        if (select != null) {
            select = select.optimize(opt, env, contextItemType);
            adoptChildExpression(select);
        }
        return this;
    }

    public Iterator iterateSubExpressions() {
        return new MonoIterator(select);
    }

    /**
     * Replace one subexpression by a replacement subexpression
     * @param original the original subexpression
     * @param replacement the replacement subexpression
     * @return true if the original subexpression is found
     */

    public boolean replaceSubExpression(Expression original, Expression replacement) {
        boolean found = false;
        if (select == original) {
            select = replacement;
            found = true;
        }
                return found;
    }


    /**
    * Expand the stylesheet elements subordinate to this one, returning the result
    * as a string. The expansion must not generate any element or attribute nodes.
    * @param context The dynamic context for the transformation
    */

    public CharSequence expandChildren(XPathContext context) throws XPathException {
        Item item = select.evaluateItem(context);
        if (item==null) {
            return "";
        } else {
            return item.getStringValueCS();
        }
    }

    /**
     * Evaluate as an expression. We rely on the fact that when these instructions
     * are generated by XQuery, there will always be a valueExpression to evaluate
     * the content
     */

    public Item evaluateItem(XPathContext context) throws XPathException {
        String content = (select==null ?
                    "" :
                    select.evaluateAsString(context));
        content = checkContent(content, context);
        final TypeHierarchy th = context.getConfiguration().getTypeHierarchy();
        Orphan o = new Orphan(context.getConfiguration());
        o.setNodeKind((short)getItemType(th).getPrimitiveType());
        o.setStringValue(content);
        o.setNameCode(evaluateNameCode(context));
        return o; 
    }

    /**
     * Check the content of the node, and adjust it if necessary. The checks depend on the node kind.
     * @param data the supplied content
     * @param context the dynamic context
     * @return the original content, unless adjustments are needed
     * @throws DynamicError if the content is invalid
     */

    protected String checkContent(String data, XPathContext context) throws DynamicError {
        return data;
    }

    public int evaluateNameCode(XPathContext context)
    throws XPathException, XPathException {
        return -1;
    }

    public SequenceIterator iterate(XPathContext context) throws XPathException {
        return SingletonIterator.makeIterator(evaluateItem(context));
    }

    /**
     * Display this instruction as an expression, for diagnostics
     */

    public void display(int level, PrintStream out, Configuration config) {
        if (select != null) {
            select.display(level, out, config);
        }
    }

    /**
      * Offer promotion for subexpressions. The offer will be accepted if the subexpression
      * is not dependent on the factors (e.g. the context item) identified in the PromotionOffer.
      * By default the offer is not accepted - this is appropriate in the case of simple expressions
      * such as constant values and variable references where promotion would give no performance
      * advantage. This method is always called at compile time.
      *
      * @param offer details of the offer, for example the offer to move
      *     expressions that don't depend on the context to an outer level in
      *     the containing expression
      * @exception XPathException if any error is detected
      */

     protected void promoteInst(PromotionOffer offer) throws XPathException {
         if (select != null) {
             select = doPromotion(select, offer);
         }
         super.promoteInst(offer);
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
