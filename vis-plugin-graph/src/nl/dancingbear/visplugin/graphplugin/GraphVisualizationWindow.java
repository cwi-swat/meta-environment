package nl.dancingbear.visplugin.graphplugin;

import java.awt.BorderLayout;
import java.awt.event.MouseEvent;

import javax.swing.JPanel;

import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.Location;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import nl.cwi.sen1.relationstores.types.idcon.IdCon;
import nl.dancingbear.visplugin.VisualizationPluginWindow;
import prefuse.Display;
import prefuse.controls.ControlAdapter;
import prefuse.data.Graph;
import prefuse.visual.VisualItem;

/**
 * Graph Plugin VisualisationWindow. Shows a graph.
 * 
 * @author Anton Gerdessen (reviewer)
 * @date 07-3-2007
 */
public class GraphVisualizationWindow extends VisualizationPluginWindow {

    private static final int DOUBLE_CLICK = 2;

    private GraphBuilder graphBuilder;

    /**
     * @todo Needs better implementation needs to be resolved reflection,
     *       dynamic dispatch... in a the base or utility class for all plugins,
     *       remark by Anton G.
     */
    private final String m_relationGraph = "relation([str,str])";

    private final String m_relationGraphTuple = "relation([tuple([str,loc]),tuple([str,loc])])";

    /**
     * This method is the respondant for a double click on an graph node and
     * then signals to open the location
     * 
     * @param nodeId
     *            This is the identifier of the double clicked node
     * 
     * @author Renze de Vries
     * @date 14-03-2007
     */
    public void doLocationClick(String nodeId) {
        // This retrieves the location and gives null if no Location was present
        // for the node
        Location loc = graphBuilder.getOrCreateLocation(nodeId, null);

        // check if this graph node really has a Location bound to the node
        // and then open it
        if (loc != null) {
            openLocationInEditor(loc);
        }
    }

    /**
     * Render the RTuple in a graph chart.
     * 
     * @param fact
     *            RTuple with the information.
     * @return JPanel holding the pie chart.
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public JPanel render(RTuple fact) {
        // If the type issupported
        if (!isTypeSupported(fact)) {
            return new JPanel();
        }

        // Create graph from rtuple
        graphBuilder = new GraphBuilder(m_factory);
        Graph graph = graphBuilder.buildGraphFromRTuple(fact);
        GraphDisplayBuilder gvizBuilder = new GraphDisplayBuilder();
        Display d = gvizBuilder.createDisplayFromGraph(graph);

        d.addControlListener(new ControlAdapter() {
            @Override
            public void itemClicked(VisualItem item, MouseEvent e) {
                if (e.getClickCount() == DOUBLE_CLICK) {
                    String nodeId = item.getString(GraphConstants.ID);

                    doLocationClick(nodeId);
                }
            }
        });

        // Create and return the panel with the graph
        JPanel panel = new JPanel();
        BorderLayout layout = new BorderLayout();
        panel.setLayout(layout);
        panel.add(d, BorderLayout.CENTER);

        return panel;
    }

    /**
     * Set a new Factory object, for testing purposes.
     * 
     * @param factory
     *            Factory to use.
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     */
    public void setFactory(Factory factory) {
        m_factory = factory;
    }

    /**
     * Check to see if the RTuple is indeed a <str,str> relation.
     * 
     * @param fact
     *            RTuple to test.
     * @return True if it is the correct str,str type.
     * @author A. Belgraver
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     * @todo Needs better implementation needs to be resolved reflection,
     *       dynamic dispatch... in a the base or utility class for all plugins,
     *       remark by Anton G. *
     */
    public boolean isRelStrStr(RTuple fact) {
        RType rType = m_factory.RTypeFromString(m_relationGraph);
        return rType.equals(fact.getRtype());
    }

    /**
     * Check to see if the RTuple is indeed a tuple([str,loc]),tuple([str,loc])
     * relation.
     * 
     * @param fact
     *            RTuple to test.
     * @return True if it is the correct tuple[str,loc],tuple[str,loc] type.
     * @author Renze de Vries
     * @date 13-3-2007
     */
    public boolean isRelTupleTuple(RTuple fact) {
        RType rType = m_factory.RTypeFromString(m_relationGraphTuple);
        return rType.equals(fact.getRtype());
    }

    /**
     * Check if a given RType is supported by this visualisation.
     * 
     * @param fact
     *            The facts for which to verify if the type is supported
     * @return True if it itype is supported
     * @author Anton Gerdessen
     * 
     * @date 07-3-2007
     */
    public boolean isTypeSupported(RTuple fact) {
        return isRelStrStr(fact) || isRelTupleTuple(fact);
    }

    /**
     * Get the name of the RTuple.
     * 
     * @param fact
     *            RTuple holding information
     * @return String holding the name of the tuple
     * @author A. Belgraver
     * @author R. van Remortel
     * @author Aldert Boerhoop (reviewer)
     * @author Anton Gerdessen (reviewer)
     * @date 07-3-2007
     * @todo Needs better implementation needs to be resolved reflection,
     *       dynamic dispatch... in a the base or utility class for all plugins,
     *       remark by Anton G.
     */
    public String getRTupleName(RTuple fact) {
        IdCon idCon = (IdCon) fact.getVariable();
        return idCon.getString();
    }
}