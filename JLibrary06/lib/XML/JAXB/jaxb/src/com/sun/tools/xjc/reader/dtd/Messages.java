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

package com.sun.tools.xjc.reader.dtd;

import java.text.MessageFormat;
import java.util.ResourceBundle;

/**
 * Formats error messages.
 */
class Messages
{
    /** Loads a string resource and formats it with specified arguments. */
    static String format( String property, Object... args ) {
        String text = ResourceBundle.getBundle(Messages.class.getPackage().getName() + ".MessageBundle").getString(property);
        return MessageFormat.format(text,args);
    }
    

    public static final String ERR_NO_ROOT_ELEMENT = // arg:0
        "TDTDReader.NoRootElement";

    public static final String ERR_UNDEFINED_ELEMENT_IN_BINDINFO = // arg:1
        "TDTDReader.UndefinedElementInBindInfo";

    public static final String ERR_CONVERSION_FOR_NON_VALUE_ELEMENT = // arg:1
        "TDTDReader.ConversionForNonValueElement";

    public static final String ERR_CONTENT_PROPERTY_PARTICLE_MISMATCH = // arg:1
        "TDTDReader.ContentProperty.ParticleMismatch";

    public static final String ERR_CONTENT_PROPERTY_DECLARATION_TOO_SHORT = // arg:1
        "TDTDReader.ContentProperty.DeclarationTooShort";
    
    public static final String ERR_BINDINFO_NON_EXISTENT_ELEMENT_DECLARATION = // arg:1
        "TDTDReader.BindInfo.NonExistentElementDeclaration";

    public static final String ERR_BINDINFO_NON_EXISTENT_INTERFACE_MEMBER = // arg:1
        "TDTDReader.BindInfo.NonExistentInterfaceMember";
        
}
