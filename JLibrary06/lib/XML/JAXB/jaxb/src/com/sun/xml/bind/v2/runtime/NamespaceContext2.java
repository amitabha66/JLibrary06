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

package com.sun.xml.bind.v2.runtime;

import javax.xml.namespace.NamespaceContext;

import com.sun.istack.NotNull;

/**
 * Maintains namespace&lt;->prefix bindings.
 * 
 * <p>
 * This interface extends {@link NamespaceContext} and provides
 * an additional functionality, which is necessary to declare
 * namespaced attributes on elements. The added method is for
 * self-consumption by the marshaller.
 * 
 * This object is composed into a Serializer.
 */
public interface NamespaceContext2 extends NamespaceContext
{
    /**
     * Declares a new namespace binding within the current context.
     * 
     * <p>
     * The prefix is automatically assigned by MarshallingContext. If
     * a given namespace URI is already declared, nothing happens.
     * 
     * <p>
     * It is <b>NOT</b> an error to declare the same namespace URI
     * more than once.
     * 
     * <p>
     * For marshalling to work correctly, all namespace bindings
     * for an element must be declared between its startElement method and
     * its endAttributes event. Calling the same method with the same
     * parameter between the endAttributes and the endElement returns
     * the same prefix.
     * 
     * @param   requirePrefix
     *      If this parameter is true, this method must assign a prefix
     *      to this namespace, even if it's already bound to the default
     *      namespace. IOW, this method will never return null if this
     *      flag is true. This functionality is necessary to declare
     *      namespace URI used for attribute names.
     * @param   preferedPrefix
     *      If the caller has any particular preference to the
     *      prefix, pass that as a parameter. The callee will try
     *      to honor it. Set null if there's no particular preference.
     * 
     * @return
     *      returns the assigned prefix. If the namespace is bound to
     *      the default namespace, null is returned.
     */
    String declareNamespace( String namespaceUri, String preferedPrefix, boolean requirePrefix );

    /**
     * Forcibly make a namespace declaration in effect.
     *
     * If the (prefix,uri) binding is already in-scope, this method
     * simply returns the assigned prefix index. Otherwise a new
     * declaration will be put. 
     */
    int force(@NotNull String uri, @NotNull String prefix);
}
