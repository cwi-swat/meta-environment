package nl.cwi.sen1.gui.plugin.prefusedot;

import java.awt.geom.Rectangle2D;
import java.util.Iterator;


import prefuse.action.layout.Layout;
import prefuse.data.Graph;
import prefuse.visual.VisualItem;

public class DotNodeLayout extends Layout {
 
    public DotNodeLayout(String group) {
        super(group);
    }

    public void run(double frac) {
        Graph g = (Graph) m_vis.getGroup(m_group);
        if (g != null) {
            Iterator<?> nodeIter = g.nodes();
            while (nodeIter.hasNext()) {
                VisualItem node = (VisualItem) nodeIter.next();
                double x = node.getInt(DotAdapter.DOT_X);
                double y = node.getInt(DotAdapter.DOT_Y);
                double w = node.getInt(DotAdapter.DOT_WIDTH);
                double h = node.getInt(DotAdapter.DOT_HEIGHT);
                
                Rectangle2D bounds = (Rectangle2D) node.get(VisualItem.BOUNDS);
                bounds.setRect(x, y, w, h);
                node.set(VisualItem.BOUNDS,bounds);
                
                setX(node, null, x);
                setY(node, null, y);
            }
        }
    }
}