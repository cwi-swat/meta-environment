/*
 * Created on 08.des.2005
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU Lesser General Public License, v2.1
 */
package org.spoofax.jsglr;


public class InvalidParseTableException extends Exception {

    private static final long serialVersionUID = 7932152591235406499L;
    private final String reason;
    
    public InvalidParseTableException(String reason) {
        this.reason = reason;
    }

    public String toString() {
        return reason;
    }
}
