package com.sun.xml.bind.v2.runtime.reflect.opt;

import com.sun.xml.bind.v2.runtime.reflect.Accessor;

/**
 * Template {@link Accessor} for double fields.
 *
 * <p>
 * All the FieldAccessors are generated from <code>FieldAccessor_B y t e</code>
 * 
 * @author Kohsuke Kawaguchi
 */
public class FieldAccessor_Double extends Accessor {
    public FieldAccessor_Double() {
        super(Double.class);
    }

    public Object get(Object bean) {
        return ((Bean)bean).f_double;
    }

    public void set(Object bean, Object value) {
        ((Bean)bean).f_double = value==null ? Const.default_value_double : (Double)value;
    }
}