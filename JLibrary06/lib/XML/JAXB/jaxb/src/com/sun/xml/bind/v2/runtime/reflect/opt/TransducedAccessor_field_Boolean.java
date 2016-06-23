package com.sun.xml.bind.v2.runtime.reflect.opt;

import com.sun.xml.bind.DatatypeConverterImpl;
import com.sun.xml.bind.v2.runtime.reflect.TransducedAccessor;
import com.sun.xml.bind.v2.runtime.reflect.DefaultTransducedAccessor;

/**
 * Template {@link TransducedAccessor} for a boolean field.
 *
 * <p>
 * All the TransducedAccessor_field are generated from <code>TransducedAccessor_field_B y t e</code>
 *
 * @author Kohsuke Kawaguchi
 *
 * @see TransducedAccessor#get
 */
public final class TransducedAccessor_field_Boolean extends DefaultTransducedAccessor {
    public String print(Object o) {
        return DatatypeConverterImpl._printBoolean( ((Bean)o).f_boolean );
    }

    public void parse(Object o, CharSequence lexical) {
        ((Bean)o).f_boolean=DatatypeConverterImpl._parseBoolean(lexical);
    }

    public boolean hasValue(Object o) {
        return true;
    }
}
