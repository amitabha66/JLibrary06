/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: X694PERNativeDriver.java,v 1.3 2007/02/19 22:28:08 pthorpe Exp $
 *****************************************************************************/

package org.w3c.exi.ttf.candidate.x694per;

import com.sun.japex.TestCase;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;
import java.util.Properties;
import org.w3c.exi.ttf.BaseNativeDriver;
import org.w3c.exi.ttf.datasink.DataSink;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.TestCaseParameters;

/**
 *
 * @author  OSS Nokalva
 * @version $Revision: 1.3 $, $Date: 2007/02/19 22:28:08 $
 * @since   NEW
 */
public class X694PERNativeDriver extends BaseNativeDriver
{
    // Associates name of native library containing precompiled schema
    // with selected testcases.
    protected Properties _precompiled_schemas;
    
    public static class Constants extends com.sun.japex.Constants {
	// Vendor-specific parameters
	// Specifies the name of the property file that maps the name of the 
	// .xsd file or test case name to the name of the native library
	// that contains the precompiled schema
	public static final String PRE_SCHEMAS = "ossx.precompiledSchemas";
	// Specifies the pathname of the directory where precompiled schemas 
	// are stored
	public static final String PRE_SCHEMA_PATH = "ossx.precompiledSchemaPath";
	
	// Benchmark kinds
	public static final int BENCHMARK_ENCODE	= 1;
	public static final int BENCHMARK_DECODE	= 2;
	public static final int BENCHMARK_COMPACTNESS	= 3;
	// Compression kind
	public static final int COMPRESS_NONE		= 1;
	public static final int COMPRESS_DOCUMENT	= 2;
	public static final int COMPRESS_SCHEMA		= 4;
	public static final int COMPRESS_GZIP		= 8;
    }
    /**
     * Creates a new instance of X694PERNativeDriver
     */
    public X694PERNativeDriver()
    {
    }

    native public void terminateDriver(Object userData);
    native public Object initializeDriver(Object userData);
    native public int runLoopDuration(double duration, Object userData);
    native public void runLoopIterations(int iterations, Object userData);
    native public void warmup(TestCase testCase, Object userData);
    native public void run(TestCase testCase, Object userData);
    native public void prepare(TestCase testCase, Object userData);
    native public void finish(TestCase testCase, Object userData);
    
    /**
     * Maps benchmark kind to the native constant.
     */
    public int getActionID()
    {
	switch (_driverParams.measure) {
	    case compactness:
		return Constants.BENCHMARK_COMPACTNESS;
	    case encode:
		return Constants.BENCHMARK_ENCODE;
	    case decode:
		return Constants.BENCHMARK_DECODE;
	    default:
		return 0;
	}
    }
    
    /**
     * Maps compression kind to the native constant.
     */
    public int getCompressionID()
    {
	int id = Constants.COMPRESS_NONE;
	if (_driverParams.isDocumentAnalysing)
	    id = id + Constants.COMPRESS_DOCUMENT;
	if (_driverParams.isSchemaOptimizing)
	    id = id + Constants.COMPRESS_SCHEMA;
	if (_driverParams.isDocumentAnalysingUsingGZIP)
	    id = id + Constants.COMPRESS_GZIP;
	
	return id;
    }

    public void initPrecompiledSchemas()
    {
	if (!hasParam(Constants.PRE_SCHEMA_PATH))
	    throw new RuntimeException("the path of precompiled XML schemas is not specified");
	_precompiled_schemas = null;
	if (hasParam(Constants.PRE_SCHEMAS)) {
	    String name = _driver.getParam(Constants.PRE_SCHEMAS);
	    InputStream props = null;
	    try {
		Properties map = new Properties();
		props = new BufferedInputStream(
		    new FileInputStream(name)
		);
		map.load(props);
		_precompiled_schemas = map;
	    } catch (IOException e) {
	    } finally {
		if (props != null)
		    try {
			props.close();
		    }
		    catch (IOException e) {
		    }
	    }
	}
    }

    public String getPrecompiledSchema(TestCase testCase)
    {
	String name = lookupMap(testCase.getName());
	if (name == null && testCase.hasParam(TestCaseParameters.SCHEMA_LOCATION)) {
	    String schemaLocation = testCase.getParam(TestCaseParameters.SCHEMA_LOCATION);
	    name = lookupMap(schemaLocation);
	}
	
	return name;
    }
    
    /**
     * Returns the name of the native library that contains pre-compiled
     * XML schema or throws an exception if the parameter is not specified. The
     * name of the native library is the base name that is used in 
     * System.loadLibrary() and that is specified by the 'precompiledSchema'
     * parameter.
     */
    public String getPrecompiledXMLSchema(TestCase testCase)
    {
        String path = getParam(Constants.PRE_SCHEMA_PATH);
        String schema = getPrecompiledSchema(testCase);
        if (schema == null)
	    return null;
	else {	    
	    File schemaLib = new File(path, System.mapLibraryName(schema));
	    return schemaLib.getPath();
	}
    }
    /**
     * Used by native code to get non-Unicode nul-terminated pathname of the
     * shared library containing the precompiled schema.
     */
    public byte[] getEncodedPrecompiledXMLSchemaPath(TestCase testCase)
    {
	String path = getPrecompiledXMLSchema(testCase);
	if (path == null)
	    throw new TestcaseNotSupportedException("The precompiled XML schema is not available.");
	else
	    return (path + '\u0000').getBytes();
    }

    protected String lookupMap(String key)
    {
	if (_precompiled_schemas == null || key == null)
	    return null;
	for (Enumeration names = _precompiled_schemas.propertyNames(); 
		names.hasMoreElements(); ) {
	    String name = (String)names.nextElement();
	    if (key.matches((String)name))
		return _precompiled_schemas.getProperty((String)name);
	}
	
	return null;
    }

    public void transcodeTestCase(byte[] encoding) throws IOException
    {
	_dataSink.getOutputStream().write(encoding);
	_dataSink.finish();
    }
    
    public byte[] getInputAsByteArray()
    {
	File file = new File(_testCaseParams.xmlFile);
	long len = file.length();
	
	if (len > Integer.MAX_VALUE)
	    throw new TestcaseNotSupportedException(
		"Driver implementation limit: input file is too big"
	    );
	byte[] content = new byte[(int)len];
	try {
	    InputStream in = new BufferedInputStream(
		new FileInputStream(file)
	    );
	    in.read(content);
	} catch (IOException e) {
	    throw new RuntimeException(
		"Error when reading test input: " + e
	    );
	}
	return content;
    }
}
