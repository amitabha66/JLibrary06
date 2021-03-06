/*
 * The contents of this file are subject to the terms
 * of the Common Development and Distribution License
 * (the "License").  You may not use this file except
 * in compliance with the License.
 * 
 * You can obtain a copy of the license at
 * https://jwsdp.dev.java.net/CDDLv1.0.html
 * See the License for the specific language governing
 * permissions and limitations under the License.
 * 
 * When distributing Covered Code, include this CDDL
 * HEADER in each file and include the License file at
 * https://jwsdp.dev.java.net/CDDLv1.0.html  If applicable,
 * add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your
 * own identifying information: Portions Copyright [yyyy]
 * [name of copyright owner]
 */
package com.sun.tools.xjc.reader.xmlschema;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import com.sun.tools.xjc.reader.Ring;
import com.sun.tools.xjc.reader.xmlschema.bindinfo.BIDeclaration;
import com.sun.xml.xsom.XSAnnotation;
import com.sun.xml.xsom.XSAttContainer;
import com.sun.xml.xsom.XSAttGroupDecl;
import com.sun.xml.xsom.XSAttributeDecl;
import com.sun.xml.xsom.XSAttributeUse;
import com.sun.xml.xsom.XSComplexType;
import com.sun.xml.xsom.XSComponent;
import com.sun.xml.xsom.XSContentType;
import com.sun.xml.xsom.XSElementDecl;
import com.sun.xml.xsom.XSFacet;
import com.sun.xml.xsom.XSIdentityConstraint;
import com.sun.xml.xsom.XSListSimpleType;
import com.sun.xml.xsom.XSModelGroup;
import com.sun.xml.xsom.XSModelGroupDecl;
import com.sun.xml.xsom.XSNotation;
import com.sun.xml.xsom.XSParticle;
import com.sun.xml.xsom.XSRestrictionSimpleType;
import com.sun.xml.xsom.XSSchema;
import com.sun.xml.xsom.XSSchemaSet;
import com.sun.xml.xsom.XSSimpleType;
import com.sun.xml.xsom.XSUnionSimpleType;
import com.sun.xml.xsom.XSWildcard;
import com.sun.xml.xsom.XSXPath;
import com.sun.xml.xsom.visitor.XSSimpleTypeVisitor;
import com.sun.xml.xsom.visitor.XSVisitor;

/**
 * Reports all unacknowledged customizations as errors.
 * 
 * @author
 *     Kohsuke Kawaguchi (kohsuke.kawaguchi@sun.com)
 */
class UnusedCustomizationChecker extends BindingComponent implements XSVisitor, XSSimpleTypeVisitor {
    private final BGMBuilder builder = Ring.get(BGMBuilder.class);

    private final Set<XSComponent> visitedComponents = new HashSet<XSComponent>();

    /**
     * Runs the check.
     */
    void run() {
        for( XSSchema s : Ring.get(XSSchemaSet.class).getSchemas() ) {
            schema(s);
            run( s.getAttGroupDecls() );
            run( s.getAttributeDecls() );
            run( s.getComplexTypes() );
            run( s.getElementDecls() );
            run( s.getModelGroupDecls() );
            run( s.getNotations() );
            run( s.getSimpleTypes() );
        }
    }
    
    private void run( Map<String,? extends XSComponent> col ) {
        for( XSComponent c : col.values() )
            c.visit(this);
    }


    /**
     * Checks unused customizations on this component
     * and returns true if this is the first time this
     * component is checked.
     */
    private boolean check( XSComponent c ) {
        if( !visitedComponents.add(c) )
            return false;   // already processed

        for( BIDeclaration decl : builder.getBindInfo(c).getDecls() )
            check(decl, c);

        return true;
    }

    private void check(BIDeclaration decl, XSComponent c) {
        if( !decl.isAcknowledged() ) {
            getErrorReporter().error(
                decl.getLocation(),
                Messages.ERR_UNACKNOWLEDGED_CUSTOMIZATION,
                decl.getName().getLocalPart()
                );
            getErrorReporter().error(
                c.getLocator(),
                Messages.ERR_UNACKNOWLEDGED_CUSTOMIZATION_LOCATION);
            // mark it as acknowledged to avoid
            // duplicated error messages.
            decl.markAsAcknowledged();
        }
        for (BIDeclaration d : decl.getChildren())
            check(d,c);
    }


    public void annotation(XSAnnotation ann) {}
    
    public void attGroupDecl(XSAttGroupDecl decl) {
        if(check(decl))
            attContainer(decl);
    }

    public void attributeDecl(XSAttributeDecl decl) {
        if(check(decl))
            decl.getType().visit((XSSimpleTypeVisitor)this);
    }

    public void attributeUse(XSAttributeUse use) {
        if(check(use))
            use.getDecl().visit(this);
    }

    public void complexType(XSComplexType type) {
        if(check(type)) {
            // don't need to check the base type -- it must be global, thus
            // it is covered already
            type.getContentType().visit(this);
            attContainer(type);
        }
    }
    
    private void attContainer( XSAttContainer cont ) {
        for( Iterator itr = cont.iterateAttGroups(); itr.hasNext(); )
            ((XSAttGroupDecl)itr.next()).visit(this);
            
        for( Iterator itr = cont.iterateDeclaredAttributeUses(); itr.hasNext(); )
            ((XSAttributeUse)itr.next()).visit(this);
        
        XSWildcard wc = cont.getAttributeWildcard();
        if(wc!=null)        wc.visit(this);
    }

    public void schema(XSSchema schema) {
        check(schema);
    }

    public void facet(XSFacet facet) {
        check(facet);
    }

    public void notation(XSNotation notation) {
        check(notation);
    }

    public void wildcard(XSWildcard wc) {
        check(wc);
    }

    public void modelGroupDecl(XSModelGroupDecl decl) {
        if(check(decl))
            decl.getModelGroup().visit(this);
    }

    public void modelGroup(XSModelGroup group) {
        if(check(group)) {
            for( int i=0; i<group.getSize(); i++ )
                group.getChild(i).visit(this);
        }
    }

    public void elementDecl(XSElementDecl decl) {
        if(check(decl)) {
            decl.getType().visit(this);
            for( XSIdentityConstraint id : decl.getIdentityConstraints() )
                id.visit(this);
        }
    }

    public void simpleType(XSSimpleType simpleType) {
        if(check(simpleType))
            simpleType.visit( (XSSimpleTypeVisitor)this );
    }

    public void particle(XSParticle particle) {
        if(check(particle))
            particle.getTerm().visit(this);
    }

    public void empty(XSContentType empty) {
        check(empty);
    }

    public void listSimpleType(XSListSimpleType type) {
        if(check(type))
            type.getItemType().visit((XSSimpleTypeVisitor)this);
    }

    public void restrictionSimpleType(XSRestrictionSimpleType type) {
        if(check(type))
            type.getBaseType().visit(this);
    }

    public void unionSimpleType(XSUnionSimpleType type) {
        if(check(type)) {
            for( int i=0; i<type.getMemberSize(); i++ )
                type.getMember(i).visit((XSSimpleTypeVisitor)this);
        }
    }

    public void identityConstraint(XSIdentityConstraint id) {
        if(check(id)) {
            id.getSelector().visit(this);
            for( XSXPath xp : id.getFields() )
                xp.visit(this);
        }
    }

    public void xpath(XSXPath xp) {
        check(xp);
    }

}
