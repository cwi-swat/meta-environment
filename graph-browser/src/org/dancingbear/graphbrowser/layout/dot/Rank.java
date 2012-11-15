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

import org.dancingbear.graphbrowser.layout.model.Node;
import org.dancingbear.graphbrowser.layout.model.NodeList;

/**
 * For Internal Use only.
 * 
 * @author hudsonr
 * @since 2.1.2
 */
public class Rank extends NodeList {
	private static final long serialVersionUID = 4773818895063752261L;
	
	int bottomPadding;
    int height;
    int location;

    final int hash = new Object().hashCode();
    int topPadding;
    int total;

    public boolean add(Node n) {
        return super.add(n);
    }

    void assignIndices() {
        total = 0;
        Node node;

        int mag;
        for (int i = 0; i < size(); i++) {
            node = getNode(i);
            mag = Math.max(1, node.getIncoming().size()
                    + node.getOutgoing().size());
            mag = Math.min(mag, 5);
            total += mag;
            node.setIndex(total);
            total += mag;
        }
    }

    /**
     * Returns the number of nodes in this rank.
     * 
     * @return the number of nodes
     */
    public int count() {
        return super.size();
    }

    /**
     * @see Object#equals(Object)
     */
    public boolean equals(Object o) {
        return o == this;
    }

    /**
     * @see Object#hashCode() Overridden for speed based on equality.
     */
    public int hashCode() {
        return hash;
    }

    void setDimensions(int location, int rowHeight) {
        this.height = rowHeight;
        this.location = location;
        for (int i = 0; i < size(); i++) {
            Node n = getNode(i);
            n.setY(location);
            n.setHeight(rowHeight);
        }
    }

    /**
     * @deprecated Do not call
     */
    public void sort() {
    }

}
