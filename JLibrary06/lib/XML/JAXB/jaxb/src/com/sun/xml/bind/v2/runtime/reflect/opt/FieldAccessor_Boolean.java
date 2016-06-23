package com.sun.xml.bind.v2.runtime.reflect.opt;

import com.sun.xml.bind.v2.runtime.reflect.Accessor;

/**
 * Template {@link Accessor} for boolean fields.
 *
 * <p>
 * All the FieldAccessors are generated from <code>FieldAccessor_B y t e</code>
 * 
 * @author Kohsuke Kawaguchi
 */
public class FieldAccessor_Boolean extends Accessor {
    public FieldAccessor_Boolean() {
        super(Boolean.class);
    }

    public Object get(Object bean) {
        return ((Bean)bean).f_boolean;
    }

    public void set(Object bean, Object value) {
        ((Bean)bean).f_boolean = value==null ? Const.default_value_boolean : (Boolean)value;
    }
}
