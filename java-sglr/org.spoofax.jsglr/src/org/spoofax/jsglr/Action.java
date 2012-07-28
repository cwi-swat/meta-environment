/*
 * Created on 04.des.2005
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU Lesser General Public License, v2.1
 */
package org.spoofax.jsglr;

import java.io.Serializable;


public class Action implements Serializable {

    static final long serialVersionUID = -2742456888004361679L;

    private Range[] ranges;

    private ActionItem[] items;

    public Action(Range[] ranges, ActionItem[] items) {
        this.ranges = ranges;
        this.items = items;
    }

    public ActionItem[] getActionItems() {
        return items;
    }

    public boolean accepts(int currentToken) {
        for (Range r : ranges)
            if (r.within(currentToken))
                return true;
        return false;
    }

    public boolean rejectable() {
        for(ActionItem ai : items) {
            if(ai instanceof Reduce) {
                Reduce r = (Reduce) ai;
                if(r.status == Reduce.REJECT)
                    return true;
            }
                
        }
        return false;
    }

    public boolean hasPrefer() {
        for(ActionItem ai : items)
            if(ai instanceof Reduce) {
                Reduce r = (Reduce) ai;
                if(r.status == Reduce.PREFER)
                    return true;
            }
        return false;
    }

    public boolean hasAvoid() {
        for(ActionItem ai : items)
            if(ai instanceof Reduce) {
                Reduce r = (Reduce) ai;
                if(r.status == Reduce.AVOID) {
                    if(SGLR.isDebugging()) {
                        Tools.debug(this);
                    }
                    return true;
                }

            }
        return false;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("action([");
        for(int i=0;i<ranges.length;i++) {
            sb.append(ranges[i]);
            if(i < ranges.length - 1)
                sb.append(", ");
        }
        sb.append("], [");
        for(int i=0;i<items.length;i++) {
            sb.append(items[i]);
            if(i < items.length - 1)
                sb.append(", ");
        }
        sb.append("])");
        return sb.toString();
    }
}
