/*******************************************************************************
 * Copyright (c) 2003, 2005 IBM Corporation and others.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     IBM Corporation - initial API and implementation
 *******************************************************************************/
package org.dancingbear.graphbrowser.layout.dot;

import java.util.ArrayList;

/**
 * For internal use only. A list of lists.
 * 
 * @author hudsonr
 * @since 2.1.2
 */
public final class RankList {
    ArrayList<Rank> ranks = new ArrayList<Rank>();

    /**
     * Returns the specified rank.
     * 
     * @param rank the row
     * @return the rank
     */
    public Rank getRank(int rank) {
        while (ranks.size() <= rank)
            ranks.add(new Rank());
        return ranks.get(rank);
    }

    /**
     * Returns the total number or ranks.
     * 
     * @return the total number of ranks
     */
    public int size() {
        return ranks.size();
    }

}
