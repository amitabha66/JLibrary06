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

import com.sun.xml.analysis.frequency.FrequencyHandler;
import com.sun.xml.analysis.frequency.SchemaProcessor;
import com.sun.xml.fastinfoset.sax.SAXDocumentSerializer;
import java.io.File;
import java.util.regex.Pattern;
import javax.xml.parsers.SAXParser;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.TestCaseParameters;

/**
 *
 * @author Paul.Sandoz@Sun.Com
 */
public class Util {
        
    public static void setSerializerIndexing(DriverParameters driverParameters, 
            TestCaseParameters testCaseParams, SAXDocumentSerializer serializer) {        
        String indexedContent = driverParameters.params.getParam(
                FastInfosetDriverParameters.INDEXED_CONTENT);
        indexedContent = (indexedContent == null) ? "" : indexedContent.intern();
        if (indexedContent == FastInfosetDriverParameters.INDEXED_CONTENT_VALUE_FULL) {
            serializer.setCharacterContentChunkSizeLimit(Integer.MAX_VALUE);
            serializer.setAttributeValueSizeLimit(Integer.MAX_VALUE);
        } else if (indexedContent == 
                FastInfosetDriverParameters.INDEXED_CONTENT_VALUE_NONE) {
            serializer.setCharacterContentChunkSizeLimit(0);
            serializer.setAttributeValueSizeLimit(0);
        } else if (indexedContent == 
                FastInfosetDriverParameters.INDEXED_CONTENT_VALUE_DEFAULT) {
        } else {
            try {
                long v = driverParameters.params.getLongParam(
                        FastInfosetDriverParameters.CHARACTER_CONTENT_CHUNK_SIZE_LIMIT);
                if (v > 0) {
                    serializer.setCharacterContentChunkSizeLimit((int)v);
                }
            } catch (NumberFormatException e){
            }
            
            try {
                long v = driverParameters.params.getLongParam(
                        FastInfosetDriverParameters.ATTRIBUTE_VALUE_SIZE_LIMIT);
                if (v > 0) {
                    serializer.setAttributeValueSizeLimit((int)v);
                }
            } catch (NumberFormatException e){
            }
        }
    }
    
    public static FrequencyHandler createFrequencyHandler(DriverParameters driverParameters, 
            TestCaseParameters testCaseParams, SAXParser parser) throws Exception {
        
        File f = new File(testCaseParams.schemaLocation);
        SchemaProcessor sp = new SchemaProcessor(f.toURL(), false, false);
        sp.process();

        String instancesDir = testCaseParams.params.getParam("instancesDir");                
        FrequencyHandler fh = new FrequencyHandler(sp);
        if (driverParameters.params.getBooleanParam("useSamples")) {
            String instances = testCaseParams.params.getParam("instances");
            Pattern spacePattern = Pattern.compile("\\s");
            String[] instancesArray = spacePattern.split(instances);
            for (int i = 0; i < instancesArray.length; i++) {
                parser.parse(new File(instancesDir, instancesArray[i]), fh);
            }
        }
        
        fh.addXsiAttributes();
        fh.generateQNamesWithPrefix();
        return fh;
    }
}
