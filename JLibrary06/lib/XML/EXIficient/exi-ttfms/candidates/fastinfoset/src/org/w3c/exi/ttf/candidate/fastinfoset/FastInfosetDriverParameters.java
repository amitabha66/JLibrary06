/*
 * EXI Testing Task Force Measurement Suite: http://www.w3.org/XML/EXI/
 *
 * Copyright © [2006] World Wide Web Consortium, (Massachusetts Institute of 
 * Technology, European Research Consortium for Informatics and Mathematics, 
 * Keio University). All Rights Reserved. This work is distributed under the 
 * W3C® Software License [1] in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * [1] http://www.w3.org/Consortium/Legal/2002/copyright-software-20021231
 */
package org.w3c.exi.ttf.candidate.fastinfoset;

/**
 * Fast Infoset specific Japex parameters.
 */
public final class FastInfosetDriverParameters {
    public static final String INDEXED_CONTENT = "org.w3c.exi.ttf.driver.candidate.fastinfoset.indexedContent";
    public static final String INDEXED_CONTENT_VALUE_DEFAULT = "default";
    public static final String INDEXED_CONTENT_VALUE_FULL = "full"; 
    public static final String INDEXED_CONTENT_VALUE_NONE = "none";
    
    public static final String CHARACTER_CONTENT_CHUNK_SIZE_LIMIT = "org.w3c.exi.ttf.driver.candidate.fastinfoset.characterContentChunkSizeLimit"; 
    public static final String ATTRIBUTE_VALUE_SIZE_LIMIT = "org.w3c.exi.ttf.driver.candidate.fastinfoset.attributeValueSizeLimit";
}
