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
package com.sun.tools.xjc.util;

import java.io.IOException;
import java.io.OutputStream;

/**
 * Just consumes the byte stream. Kind of like /dev/null.
 * 
 * @author
 *     Kohsuke Kawaguchi (kohsuke.kawaguchi@sun.com)
 */
public class NullStream extends OutputStream {

    public void write(int b) throws IOException {
    }
    
    public void close() throws IOException {
    }

    public void flush() throws IOException {
    }

    public void write(byte[] b, int off, int len) throws IOException {
    }

    public void write(byte[] b) throws IOException {
    }
}
