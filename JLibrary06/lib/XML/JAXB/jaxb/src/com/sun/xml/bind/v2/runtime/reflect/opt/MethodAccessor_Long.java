package com.sun.xml.bind.v2.runtime.reflect.opt;

import com.sun.xml.bind.v2.runtime.reflect.Accessor;

/**
 * Template {@link Accessor} for boolean getter/setter.
 *
 * <p>
 * All the MethodAccessors are generated from <code>MethodAccessor_B y t e</code>
 *
 * @author Kohsuke Kawaguchi
 */
public class MethodAccessor_Long extends Accessor {
    public MethodAccessor_Long() {
        super(Long.class);
    }

    public Object get(Object bean) {
        return ((Bean)bean).get_long();
    }

    public void set(Object bean, Object value) {
        ((Bean)bean).set_long( value==null ? Const.default_value_long : (Long)value );
    }
}
