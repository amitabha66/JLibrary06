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

package org.w3c.exi.ttf.parameters;

import com.sun.japex.Params;
import java.net.URI;
import java.net.URISyntaxException;

/**
 * TTFMS driver parameters.
 *
 * @author AgileDelta
 * @author Sun
 * 
 */
public final class DriverParameters {
    /**
     * The application class parameter.
     */
    static public final String APPLICATION_CLASS
            = "org.w3c.exi.ttf.applicationClass";
    
    static public final String APPLICATION_CLASS_DOCUMENT_ANALYSING_GZIP = 
            "org.w3c.exi.ttf.applicationClass.documentAnalysing.GZIP";
    
    static public final String MEASURE = "org.w3c.exi.ttf.measurementProperty";
    
    static public final String DRIVER_IS_XML_PROCESSOR =
          "org.w3c.exi.ttf.driver.isXmlProcessor";

    /**
     * The string interning parameter.
     * <p>
     * TODO: This parameter may only be relevant to Java-based decoders that 
     * perform string interning (see the SAX string interning property).
     * Some XML parsers like Xerces always perform string interning. Some
     * applications, like XML binders, rely on string interning by parsers
     * for efficient string comparison.
     */
    static public final String STRING_INTERNING 
            = "org.w3c.exi.ttf.stringInterning"; 
    
    /**
     * The URI of the data source/sink.
     */
    public static final String DATA_SOURCE_SINK_URI 
            = "org.w3c.exi.ttf.dataSourceSink.URI";
        
    public final Params params;

    /**
     * The application class.
     */
    public final ApplicationClassParam applicationClass;

    /**
     * The measure property.
     */
    public final MeasureParam measure;

    /**
     * True if {@link #applicationClass} is document or both.
     */
    public final boolean isDocumentAnalysing;
    
    /**
     * True if {@link #applicationClass} is document or both
     * and GZIP is used.
     */
    public final boolean isDocumentAnalysingUsingGZIP;
    
    /**
     * True if {@link #applicationClass} is schema or both.
     */
    public final boolean isSchemaOptimizing;

    /**
     * True if the driver is a vanilla XML Processor (aka. XML Parser)
     */
    public final boolean isXmlProcessor;
    
    /**
     * True if when decoding string interning should be performed.
     * <p>
     * String interning MUST conform to the SAX inter
     */
    public final boolean isStringInterning;

    /**
     * The URI representing the data source/sink.
     */
    public final URI dataSourceSinkURI;
    
    /**
     * The scheme of the data source/sink URI.
     */
    public final DataSourceSinkParam dataSourceSink;
    
    
    public DriverParameters(Params params) {
        this.params = params;
        
        applicationClass = ApplicationClassParam.createApplicationClass(
                params.getParam(APPLICATION_CLASS));
        measure = MeasureParam.createMeasure(params.getParam(MEASURE));
        isDocumentAnalysing = (applicationClass == ApplicationClassParam.document || 
                applicationClass == ApplicationClassParam.both)
                ? true : false;
        isDocumentAnalysingUsingGZIP = (isDocumentAnalysing)
            ? params.getBooleanParam(
                    APPLICATION_CLASS_DOCUMENT_ANALYSING_GZIP)
            : false;
        isSchemaOptimizing = (applicationClass == ApplicationClassParam.schema || 
                applicationClass == ApplicationClassParam.both)
                ? true : false;
        
        isXmlProcessor = params.getBooleanParam(DRIVER_IS_XML_PROCESSOR);
        
        isStringInterning = params.getBooleanParam(STRING_INTERNING);

        try {
            String uri = params.getParam(DATA_SOURCE_SINK_URI);
            if (uri == null) uri = "memory:/";
            
            dataSourceSinkURI = new URI(uri);
            dataSourceSink = DataSourceSinkParam.createDataSourceSinkParam(
                    dataSourceSinkURI);
        } catch (URISyntaxException e) {
            throw new RuntimeException(e);
        }
    } 
}
