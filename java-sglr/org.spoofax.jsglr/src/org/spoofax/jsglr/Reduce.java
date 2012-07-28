/*
 * Created on 05.des.2005
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU Lesser General Public License, v2.1
 */
package org.spoofax.jsglr;

public class Reduce extends ActionItem {

    private static final long serialVersionUID = 8620275049778432244L;

    public final int arity;

    public final int label;

    public final int status;

    public final Production production;
    
    public static final int NORMAL = 0;
    public static final int REJECT = 1;
    public static final int PREFER = 2;
    public static final int AVOID = 4;

    
    public Reduce(int arity, int label, int status) {
        
        super(REDUCE);
        
        this.arity = arity;
        this.label = label;
        this.status = status;
      
        production = new Production(arity, label, status);
    }
    
    
    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Reduce))
            return false;
        Reduce o = (Reduce)obj;
        return arity == o.arity && label == o.label && status == o.status;
    }
    
    @Override
    public int hashCode() {
        return arity + status * 10 + label * 100;
    }
    
    
    public String toString() {
        return "reduce(" + arity + ", " + label + ", " + status + ")";
    }
}
