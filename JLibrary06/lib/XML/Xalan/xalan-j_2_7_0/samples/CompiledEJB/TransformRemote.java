/*
 * Copyright 2001-2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * $Id: TransformRemote.java,v 1.4 2004/02/17 19:04:22 minchau Exp $
 */

import java.rmi.RemoteException;

import javax.ejb.EJBObject;

/**
 * XSL transformation bean remote interface
 * @author Morten Jorgensen
 */
public interface TransformRemote extends EJBObject {
    public String transform(String document, String transletName) 
	throws RemoteException;
}
