package nl.cwi.sen1.gui.plugin.prefusedot;

import java.util.Iterator;


import prefuse.action.layout.Layout;
import prefuse.data.Graph;
import prefuse.visual.VisualItem;

public class DotLayout extends Layout {
 
    public DotLayout(String group) {
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

                setX(node, null, x);
                setY(node, null, y);
            }
        }
    }
}