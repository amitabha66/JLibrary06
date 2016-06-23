package com.sun.xml.bind.v2.runtime.reflect.opt;

import com.sun.xml.bind.v2.runtime.reflect.Accessor;

/**
 * Template {@link Accessor} for char fields.
 *
 * <p>
 * All the FieldAccessors are generated from <code>FieldAccessor_B y t e</code>
 * 
 * @author Kohsuke Kawaguchi
 */
public class FieldAccessor_Character extends Accessor {
    public FieldAccessor_Character() {
        super(Character.class);
    }

    public Object get(Object bean) {
        return ((Bean)bean).f_char;
    }

    public void set(Object bean, Object value) {
        ((Bean)bean).f_char = value==null ? Const.default_value_char : (Character)value;
    }
}