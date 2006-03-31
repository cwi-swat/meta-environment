package nl.cwi.sen1.gui.plugin;

import java.util.Iterator;

import prefuse.action.layout.Layout;
import prefuse.data.Graph;
import prefuse.visual.VisualItem;

public class GraphDotLayout extends Layout {
    public static final String CURVE_POINTS = "curve-points";

    public static final String DOT_X = "dotX";

    public static final String DOT_Y = "dotY";

    public static final String DOT_WIDTH = "dotWidth";

    public static final String DOT_HEIGHT = "dotHeight";

    public GraphDotLayout(String group) {
        super(group);
    }

    public void run(double frac) {
        Graph g = (Graph) m_vis.getGroup(m_group);
        if (g != null) {
            Iterator nodeIter = g.nodes();
            while (nodeIter.hasNext()) {
                VisualItem node = (VisualItem) nodeIter.next();
                double x = node.getInt(DOT_X);
                double y = node.getInt(DOT_Y);

                setX(node, null, x);
                setY(node, null, y);
            }
        }
    }
}