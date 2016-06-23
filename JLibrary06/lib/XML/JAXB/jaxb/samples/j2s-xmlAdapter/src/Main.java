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

/*
 * $Id: Main.java,v 1.1 2005/12/20 15:03:54 rebeccas Exp $
 *
 * Copyright 2005 Sun Microsystems, Inc. All Rights Reserved.
 * 
 * This software is the proprietary information of Sun Microsystems, Inc.  
 * Use is subject to license terms.
 * 
 */


import java.io.File;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;
import shoppingCart.KitchenWorldBasket;

public class Main {
    public static void main(String[] args) throws Exception {
        JAXBContext jc = JAXBContext.newInstance(KitchenWorldBasket.class);
        Unmarshaller u = jc.createUnmarshaller();
        Marshaller m = jc.createMarshaller();
        m.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
        try {
            KitchenWorldBasket kwBasket = (KitchenWorldBasket)u.unmarshal(new File("src/shoppingCartData.xml"));
            
            // Demonstrate adapter's unmarshal integrated data into HashMap properly
            System.out.println(kwBasket.toString());
            
            // Demonstate adapter's marshal writes the data properly
            m.marshal(kwBasket, System.out);
        } catch(javax.xml.bind.UnmarshalException e){
            System.out.println("Main: " + e);
        }    
    }
}

