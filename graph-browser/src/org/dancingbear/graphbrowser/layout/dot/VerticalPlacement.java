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

import org.dancingbear.graphbrowser.layout.model.DirectedGraph;
import org.dancingbear.graphbrowser.layout.model.Node;
import org.eclipse.draw2d.geometry.Insets;

/**
 * Assigns the Y and Height values to the nodes in the graph. All nodes in the
 * same row are given the same height.
 * 
 * @author Randy Hudson
 * @since 2.1.2
 */
class VerticalPlacement extends GraphVisitor {

    void visit(DirectedGraph g) {
        Insets pad;
        int currentY = g.getMargin().top;
        int row, rowHeight;
        g.setRankLocations(new int[g.getRanks().size() + 1]);
        for (row = 0; row < g.getRanks().size(); row++) {
            g.getRankLocations()[row] = currentY;
            Rank rank = g.getRanks().getRank(row);
            rowHeight = 0;
            rank.topPadding = rank.bottomPadding = 0;
            for (int n = 0; n < rank.size(); n++) {
                Node node = rank.getNode(n);
                if (!g.isSubgraph() || g.getSubgraph().equals(node.getParent())) {
                    pad = g.getPadding(node);
                    rowHeight = Math.max(node.getHeight(), rowHeight);
                    rank.topPadding = Math.max(pad.top, rank.topPadding);
                    rank.bottomPadding = Math.max(pad.bottom,
                            rank.bottomPadding);
                }
            }
            currentY += rank.topPadding;
            rank.setDimensions(currentY, rowHeight);
            currentY += rank.height + rank.bottomPadding;
        }
        g.getRankLocations()[row] = currentY;
        g.getSize().height = currentY;
    }

}
