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
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URI;
import java.util.Set;

/**
 * TTFMS test case parameters.
 *
 * @author AgileDelta
 * @author Sun
 * 
 */
public final class TestCaseParameters {
    
    /**
     * The input file parameter.
     */
    static public final String INPUT_FILE = "japex.inputFile";
    
    static public final String PARAM_RECORDDECODEDEVENTS 
            = "org.w3c.exi.ttf.recordDecodedEvents";
    
    /**
     * The preserve parameter
     */
    static public final String PRESERVE = "org.w3c.exi.ttf.preserve";
    static public final String IGNORE_FIDELITY_SETTINGS = "org.w3c.exi.ttf.ignoreFidelitySettings";
    
    /**
     * The schema location parameter
     */
    static public final String SCHEMA_LOCATION = "org.w3c.exi.ttf.schemaLocation";
    
    static public final String USE_CASES = "org.w3c.exi.ttf.useCases";
    
    static public final String SCHEMA_DEVIATIONS = "org.w3c.exi.ttf.schemaDeviations";
    static public final String FRAGMENTS = "org.w3c.exi.ttf.fragments";
    
    
    public final Params params;
    
    public final Set<PreserveParam> preserves;
    public boolean ignoreFidelitySettings;
    
    public final String schemaLocation;
    
    public final String xmlFile;
    public final String xmlSystemId;
    
    /**
     * Inidcate whether the read test record parse events or not.
     */
    public boolean traceRead;
    
    /**
     * Are deviations from the schema allowed?
     */
    public boolean schemaDeviations;
    
    /**
     * Are document fragments allowed?
     */
    public boolean fragments;
    
    public TestCaseParameters(Params params, DriverParameters driverParams) {
        this.params = params;
        
        xmlFile = params.getParam(INPUT_FILE);
        if (xmlFile == null)
            throw new RuntimeException(INPUT_FILE + " not specified");
        xmlSystemId = new File(xmlFile).toURI().toString();
        
        ignoreFidelitySettings = params.getBooleanParam(IGNORE_FIDELITY_SETTINGS);
        if (ignoreFidelitySettings)
        	params.setParam(PRESERVE, "");
        
        preserves = PreserveParam.createPreserveSet(params.getParam(PRESERVE));
        
        String workingSchemaLocation = params.getParam(SCHEMA_LOCATION);
        
        // Communicate schema in all cases. In Neither and Document modes
        // the resulting encoding MUST not be schema dependent
        if (workingSchemaLocation != null && workingSchemaLocation.length() == 0) {
            workingSchemaLocation = null;
        }
        schemaLocation = workingSchemaLocation;
        
        traceRead = params.getBooleanParam(PARAM_RECORDDECODEDEVENTS);

        schemaDeviations = params.getBooleanParam(SCHEMA_DEVIATIONS);
        
        fragments = params.getBooleanParam(FRAGMENTS);
    }
    
    public InputStream getXmlInputStream() throws IOException {
        return new BufferedInputStream(new FileInputStream(xmlFile));
    }
}
