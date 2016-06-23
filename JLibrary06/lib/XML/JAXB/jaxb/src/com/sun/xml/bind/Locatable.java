/*
 * @(#)$Id: Locatable.java,v 1.2 2005/09/10 19:07:38 kohsuke Exp $
 */

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
package com.sun.xml.bind;

import com.sun.xml.bind.annotation.XmlLocation;

import org.xml.sax.Locator;

/**
 * Optional interface implemented by JAXB objects to expose
 * location information from which an object is unmarshalled.
 *
 * <p>
 * This is used during JAXB RI 1.0.x.
 * In JAXB 2.0, use {@link XmlLocation}.
 *
 * @author
 *     Kohsuke Kawaguchi (kohsuke.kawaguchi@sun.com)
 *
 * @since JAXB RI 1.0
 */
public interface Locatable {
    /**
     * @return
     *      null if the location information is unavaiable,
     *      or otherwise return a immutable valid {@link Locator}
     *      object.
     */
    Locator sourceLocation();
}