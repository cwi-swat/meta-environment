/*
 * Created on 05.des.2005
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU Lesser General Public License, v2.1
 */
package org.spoofax.jsglr;

import java.io.Serializable;

public class Goto implements Serializable {

    static final long serialVersionUID = 4361136767191244085L;
    
    private Range[] ranges;
    public final int nextState;
    
    public Goto(Range[] ranges, int nextState) {
        this.ranges = ranges;
        this.nextState = nextState;
    }

    public boolean hasProd(int label) {
        for (Range r : ranges) {
            if(r.within(label)) {
                return true;
            }
        }
        return false;
    }
    
    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Goto))
            return false;
        Goto o = (Goto)obj;
        if(nextState != o.nextState)
            return false;
        if(ranges.length != o.ranges.length)
            return false;
        for(int i=0;i<ranges.length;i++)
            if(ranges[i].equals(o.ranges[i]))
                return false;
        return true;
    }
    
    @Override
    public int hashCode() {
        // FIXME Can probably be made to work a lot better
        int r = nextState * 94716;
        for(int i = 0; i < ranges.length; i++)
            r += ranges[i].hashCode() + i * 3617;
        return r;
    }
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("goto([");
        for(int i = 0;i < ranges.length;i++) {
            sb.append(ranges[i].toString());
            if(i < ranges.length - 1) 
                sb.append(",");
        }
        sb.append("], ");
        sb.append(nextState);
        sb.append(")");
        return sb.toString(); 
    }
}
