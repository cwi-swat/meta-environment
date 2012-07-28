/*
 * Created on 16.apr.2006
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU General Public License, v2
 */
package org.spoofax.jsglr;

import java.io.Serializable;

import aterm.ATerm;

public class ProductionAttributes implements Serializable {

    private static final long serialVersionUID = 556855017447626835L;

    public final static int NO_TYPE = 0;

    public final static int LEFT_ASSOCIATIVE = 1;

    public final static int RIGHT_ASSOCIATIVE = 2;

    public final static int PREFER = 3;

    public final static int AVOID = 4;

    public final static int BRACKET = 5;

    public final static int REJECT = 6;

    protected final int type;

    protected final ATerm abstractCtor;

    ProductionAttributes(int type, ATerm ctor) {
        this.type = type;
        this.abstractCtor = ctor;
    }

    public final int getType() {
        return type;
    }

    public final ATerm getTerm() {
        return abstractCtor;
    }

    public boolean isMoreEager(ProductionAttributes other) {
        return type != other.type && (type == PREFER || other.type == AVOID);
    }
}
