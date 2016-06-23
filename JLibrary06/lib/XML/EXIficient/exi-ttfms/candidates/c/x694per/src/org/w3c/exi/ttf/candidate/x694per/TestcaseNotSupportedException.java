/*****************************************************************************/
/* Copyright (C) 2006 OSS Nokalva, Inc.  All rights reserved.                */
/*****************************************************************************/
/*****************************************************************************
 * $Id: TestcaseNotSupportedException.java,v 1.1 2006/05/29 22:12:01 pthorpe Exp $
 *****************************************************************************/

package org.w3c.exi.ttf.candidate.x694per;

/**
 * This exception can be thrown at test preparation phase to indicate that the
 * particular test is not supported by the native test driver.
 *
 * @author  OSS Nokalva
 * @version $Revision: 1.1 $, $Date: 2006/05/29 22:12:01 $
 * @since   NEW
 */
public class TestcaseNotSupportedException extends RuntimeException
{
    
    /**
     * Creates a new instance of <code>TestcaseNotSupportedException</code> without detail message.
     */
    public TestcaseNotSupportedException()
    {
    }
    
    /**
     * Constructs an instance of <code>TestcaseNotSupportedException</code> with the specified detail message.
     * @param msg the detail message.
     */
    public TestcaseNotSupportedException(String msg)
    {
	super(msg);
    }
}
