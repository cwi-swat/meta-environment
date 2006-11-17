/*
 * Created on 06.des.2005
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU Lesser General Public License, v2.1
 */
package org.spoofax.jsglr;

import java.io.Serializable;

public class Priority implements Serializable {

    static final long serialVersionUID = -608253385493058906L;

    public static final int LEFT = 1;
    public static final int RIGHT = 2;
    public static final int NONASSOC = 3;
    public static final int GTR = 4;

    public final int left;
    public final int right;
    public final int type;

    public Priority(int type, int left, int right) {
        this.type = type;
        this.left = left;
        this.right = right;
    }
}
