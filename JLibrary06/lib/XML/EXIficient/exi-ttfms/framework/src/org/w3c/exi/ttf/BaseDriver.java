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

package org.w3c.exi.ttf;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.OutputStream;

import org.w3c.exi.ttf.datasink.DataSink;
import org.w3c.exi.ttf.datasource.DataSource;
import org.w3c.exi.ttf.parameters.DriverParameters;
import org.w3c.exi.ttf.parameters.TestCaseParameters;

import com.sun.japex.Constants;
import com.sun.japex.JapexDriverBase;
import com.sun.japex.TestCase;

/**
 * Base driver.  Candidate drivers should implement CustomDriver
 * or SAXDriver, and not BaseDriver.
 *
 * @author AgileDelta
 * @author Sun
 *
 */
public abstract class BaseDriver extends JapexDriverBase {
    /**
     * The data sink to write to.
     */
    protected DataSink _dataSink = null;

    /**
     * The data source to read from.
     */
    protected DataSource _dataSource = null;

    /**
     * The driver parameters.
     * <p>
     * This field is valid and constant in the scope of preparation, warmup, run
     * and finish.
     */
    protected DriverParameters _driverParams;

    /**
     * The test case parameters.
     * <p>
     * This field is valid and constant in the scope of preparation, warmup, run
     * and finish.
     */
    public TestCaseParameters _testCaseParams;

    /**
     * Prepare the test-case.
     *
     * @param driverParameters
     *            The driver parameters.
     * @param testCaseParams
     *            Test case parameters.
     */
    protected abstract void prepareTestCase(DriverParameters driverParameters,
            TestCaseParameters testCaseParams) throws Exception;

    /**
     * Transcode the given text-xml.
     *
     * @param xmlInput
     *            the input stream of the text-xml
     * @param encodedOutput
     */
    protected abstract void transcodeTestCase(InputStream xmlInput,
            OutputStream encodedOutput) throws Exception;

    /**
     * Validate that driver can (re)parse input
     *
     * @param encodedInput
     *            the input stream of the encoded xml
     * @param originalInput
     *            input stream to the xml to encode
     */
    protected abstract void validateStream(InputStream encodedInput,
            InputStream originalInput ) throws Exception;

    /**
     * Set up the test-case run. Delegates to initialize() for driver specific
     * initialization.
     */
    public void prepare(TestCase testCase) {
        try {
            // Create the driver parameters
            _driverParams = new DriverParameters(this);
            // Create the test case parameters
            _testCaseParams = new TestCaseParameters(testCase, _driverParams);

            // Prepate for the test case
            prepareTestCase(_driverParams, _testCaseParams);

            switch(_driverParams.measure) {
                case compactness:
                    _dataSink = DataSink.createInMemory(_driverParams);
                    transcodeTestCase(_testCaseParams.getXmlInputStream(),
                            _dataSink.getOutputStream());
                    _dataSink.finish();
                    DataSource validateSrc = DataSource.createInMemory(_driverParams, _dataSink.toByteArray());
                    validateStream(validateSrc.getInputStream(),
                                   _testCaseParams.getXmlInputStream());
                    break;
                case encode:
                    _dataSink = DataSink.create(_driverParams);
                    break;
                case decode:
                    _dataSink = DataSink.createInMemory(_driverParams);
                    transcodeTestCase(_testCaseParams.getXmlInputStream(),
                            _dataSink.getOutputStream());
                    _dataSink.finish();

                    _dataSource = DataSource.create(_driverParams,
                            _dataSink.toByteArray());
                    break;
                default:
            }
        } catch (Exception e) {
            System.err.println("Error preparing test: " + testCase.getName());
            e.printStackTrace();
	    try {
  	      if (_dataSink != null) _dataSink.close();
	      if (_dataSource != null) _dataSource.close();
	    }
	    catch (Exception ex) {}
            throw new RuntimeException(e);
        }
    }

    public void warmup(TestCase testCase) {
        // Is this due to a JIT problem ???
        // When using Japex with iterations instead of time
        // this will result in n^2 iterations for the warmup
        run(testCase);
    }

    public void finish(TestCase testCase) {
        try {
            switch (_driverParams.measure) {
                case compactness:
                    // Check if the size encoded data is 0
                    if (_dataSink.getSize() == 0) {
                        throw new RuntimeException("Encoded data size is 0");
                    }

                    testCase.setIntParam(Constants.RESULT_VALUE,
                            _dataSink.getSize());
                    _dataSink.close();
                    break;
                case decode:
                    _dataSource.close();
                case encode:
                    if (_dataSink.hasSize()) {
                        testCase.setIntParam(Constants.RESULT_VALUE_X,
                                _dataSink.getSize());
                    }
                    _dataSink.close();
                    break;
                default:
            }
        } catch (Exception e) {
            System.err.println("Error finishing test: " + testCase.getName());
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }

}
