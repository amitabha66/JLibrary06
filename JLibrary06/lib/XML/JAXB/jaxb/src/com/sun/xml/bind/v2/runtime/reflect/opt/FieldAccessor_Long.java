package com.sun.xml.bind.v2.runtime.reflect.opt;

import com.sun.xml.bind.v2.runtime.reflect.Accessor;

/**
 * Template {@link Accessor} for long fields.
 *
 * <p>
 * All the FieldAccessors are generated from <code>FieldAccessor_B y t e</code>
 * 
 * @author Kohsuke Kawaguchi
 */
public class FieldAccessor_Long extends Accessor {
    public FieldAccessor_Long() {
        super(Long.class);
    }

    public Object get(Object bean) {
        return ((Bean)bean).f_long;
    }

    public void set(Object bean, Object value) {
        ((Bean)bean).f_long = value==null ? Const.default_value_long : (Long)value;
    }
}
