/*
 * Created on 04.des.2005
 *
 * Copyright (c) 2005, Karl Trygve Kalleberg <karltk@ii.uib.no>
 * 
 * Licensed under the GNU Lesser General Public License, v2.1
 */
package org.spoofax.jsglr;

import java.util.List;
import java.io.Serializable;

public class Production implements Serializable {

    static final long serialVersionUID = 8767621343854666185L;

    public final int arity;

    public final int label;

    public final int status;

    // FIXME: These should be factored out in a separate constant class.
    public static final int NORMAL = Reduce.NORMAL;

    public static final int PREFER = Reduce.PREFER;

    public static final int AVOID = Reduce.AVOID;

    public static final int REJECT = Reduce.REJECT;

    public Production(int arity, int label, int status) {
        this.arity = arity;
        this.label = label;
        this.status = status;

    }


    public IParseNode apply(List<IParseNode> kids) {
        switch(status) {
        case REJECT:
            return new ParseReject(label, kids);
        case AVOID:
            return new ParseAvoid(label, kids);
        case PREFER:
            return new ParsePrefer(label, kids);
        case NORMAL:
            return new ParseNode(label, kids);
        }
        throw new FatalException();
    }

    boolean isReject() {
        return status == REJECT;
    }

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Production))
            return false;
        Production o = (Production)obj;
        return arity == o.arity && label == o.label && status == o.status;
    }
}
