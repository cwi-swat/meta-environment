package nl.cwi.sen1.visplugin.graphplugin;

import java.awt.Font;

import prefuse.util.ColorLib;

/**
 *
 * @author A. Belgraver
 * @author Anton Gerdessen (reviewer)
 * @author Jurgen Vinju
 * @date 07-3-2007
 */
public class GraphConstants {

    public static final String GRAPH = "graph";
    public static final String NODES = "graph.nodes";
    public static final String EDGES = "graph.edges";
    public static final String COLOR = "color";
    public static final String LAYOUT = "layout";
    public static final String LABELLAYOUT = "label-layout";
    public static final String LABELS = "labels";
    public static final String LABEL  = "label";

    /**
     * Node background color.
     */
    public static final int NODE_FILLCOLOR = ColorLib.rgb(245, 245, 245);

    /**
     * Node outline color.
     */
    public static final int NODE_LINECOLOR = ColorLib.rgb(0, 0, 0);

    /**
     * Node text font.
     */
    public static final Font NODE_FONT = new Font("Helvetica", Font.PLAIN, 12);

    /**
     * Text color
     */
    public static final int TEXTCOLOR = ColorLib.rgb(0, 0, 0);

    /**
     * Edge arrow color.
     */
    public static final int ARROWCOLOR = ColorLib.rgb(0, 0, 0);
	

}
