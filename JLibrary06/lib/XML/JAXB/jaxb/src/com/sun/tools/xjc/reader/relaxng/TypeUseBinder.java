package com.sun.tools.xjc.reader.relaxng;

import com.sun.tools.xjc.model.CBuiltinLeafInfo;
import com.sun.tools.xjc.model.TypeUse;
import com.sun.tools.xjc.model.TypeUseFactory;

import org.kohsuke.rngom.digested.DAttributePattern;
import org.kohsuke.rngom.digested.DChoicePattern;
import org.kohsuke.rngom.digested.DContainerPattern;
import org.kohsuke.rngom.digested.DDataPattern;
import org.kohsuke.rngom.digested.DElementPattern;
import org.kohsuke.rngom.digested.DEmptyPattern;
import org.kohsuke.rngom.digested.DGrammarPattern;
import org.kohsuke.rngom.digested.DGroupPattern;
import org.kohsuke.rngom.digested.DInterleavePattern;
import org.kohsuke.rngom.digested.DListPattern;
import org.kohsuke.rngom.digested.DMixedPattern;
import org.kohsuke.rngom.digested.DNotAllowedPattern;
import org.kohsuke.rngom.digested.DOneOrMorePattern;
import org.kohsuke.rngom.digested.DOptionalPattern;
import org.kohsuke.rngom.digested.DPattern;
import org.kohsuke.rngom.digested.DPatternVisitor;
import org.kohsuke.rngom.digested.DRefPattern;
import org.kohsuke.rngom.digested.DTextPattern;
import org.kohsuke.rngom.digested.DValuePattern;
import org.kohsuke.rngom.digested.DZeroOrMorePattern;

/**
 * Walks the pattern tree and binds it to a {@link TypeUse}.
 *
 * The singleton instance is kept in {@link RELAXNGCompiler}.
 *
 * TODO: I should really normalize before process.
 *
 * @author Kohsuke Kawaguchi
 */
final class TypeUseBinder implements DPatternVisitor<TypeUse> {
    private final RELAXNGCompiler compiler;

    public TypeUseBinder(RELAXNGCompiler compiler) {
        this.compiler = compiler;
    }


    public TypeUse onGrammar(DGrammarPattern p) {
        return CBuiltinLeafInfo.STRING;
    }

    public TypeUse onChoice(DChoicePattern p) {
        // can't support unions
        return CBuiltinLeafInfo.STRING;
    }

    public TypeUse onData(DDataPattern p) {
        return onDataType(p.getDatatypeLibrary(), p.getType());
    }

    public TypeUse onValue(DValuePattern p) {
        return onDataType(p.getDatatypeLibrary(),p.getType());
    }

    private TypeUse onDataType(String datatypeLibrary, String type) {
        DatatypeLib lib = compiler.datatypes.get(datatypeLibrary);
        if(lib!=null) {
            TypeUse use = lib.get(type);
            if(use!=null)
                return use;
        }

        // unknown
        return CBuiltinLeafInfo.STRING;
    }

    public TypeUse onInterleave(DInterleavePattern p) {
        return onContainer(p);
    }

    public TypeUse onGroup(DGroupPattern p) {
        return onContainer(p);
    }

    private TypeUse onContainer(DContainerPattern p) {
        TypeUse t=null;
        for( DPattern child : p ) {
            TypeUse s = child.accept(this);
            if(t!=null && t!=s)
                return CBuiltinLeafInfo.STRING; // heterogenous
            t = s;
        }
        return t;
    }

    public TypeUse onNotAllowed(DNotAllowedPattern p) {
        // TODO
        return error();
    }

    public TypeUse onEmpty(DEmptyPattern p) {
        return CBuiltinLeafInfo.STRING;
    }

    public TypeUse onList(DListPattern p) {
        return p.getChild().accept(this);
    }

    public TypeUse onOneOrMore(DOneOrMorePattern p) {
        return TypeUseFactory.makeCollection( p.getChild().accept(this) );
    }

    public TypeUse onZeroOrMore(DZeroOrMorePattern p) {
        return TypeUseFactory.makeCollection( p.getChild().accept(this) );
    }

    public TypeUse onOptional(DOptionalPattern p) {
        return CBuiltinLeafInfo.STRING;
    }

    public TypeUse onRef(DRefPattern p) {
        // TODO: check for enums
        return p.getTarget().getPattern().accept(this);
    }

    public TypeUse onText(DTextPattern p) {
        return CBuiltinLeafInfo.STRING;
    }

//
//
// Not allowed in this context
//
//
    public TypeUse onAttribute(DAttributePattern p) {
        return error();
    }

    public TypeUse onElement(DElementPattern p) {
        return error();
    }

    public TypeUse onMixed(DMixedPattern p) {
        return error();
    }

    private TypeUse error() {
        throw new IllegalStateException();
    }
}
