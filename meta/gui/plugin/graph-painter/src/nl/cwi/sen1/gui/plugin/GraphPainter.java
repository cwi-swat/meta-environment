/*
 * Created on Apr 18, 2005
 *
 * To change the template for this generated file go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */
package nl.cwi.sen1.gui.plugin;

import java.util.HashMap;
import java.util.Map;

import nl.cwi.sen1.data.graph.Graph;
import nl.cwi.sen1.data.graph.MetaGraphFactory;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioPlugin;
import nl.cwi.sen1.util.Preferences;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class GraphPainter implements StudioPlugin, GraphPainterTif {
	private static final String TOOL_NAME = "graph-painter";

	private static final String RESOURCE_DIR = "/resources";

	private Studio studio;

	private MetaGraphFactory graphFactory;

	private Map graphs;
	
	private Preferences preferences;

	public GraphPainter() {
		String propertyPath = new String(RESOURCE_DIR + '/' + TOOL_NAME
				+ ".properties");
		this.preferences = new Preferences(getClass().getResourceAsStream(propertyPath));
		this.graphs = new HashMap();
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		graphFactory = new MetaGraphFactory((PureFactory) studio.getFactory());

		GraphPainterBridge bridge = new GraphPainterBridge(studio.getFactory(),
				this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}

	public void displayGraph(String id, ATerm graphTerm) {
		GraphPanel panel = (GraphPanel) graphs.get(id);
		if (panel != null) {
			Graph graph = graphFactory.GraphFromTerm(graphTerm);
			panel.setGraph(graph);
			panel.repaint();
		}
	}

	public ATerm sizeGraph(String id, ATerm graphTerm) {
		GraphPanel panel = (GraphPanel) graphs.get(id);
		if (panel == null) {
			panel = new GraphPanel(id, preferences);
			graphs.put(id, panel);
			panel.setName(id);
			studio.addComponent(panel);
		}

		Graph graph = graphFactory.GraphFromTerm(graphTerm);

		graph = panel.sizeGraph(graph);
		return graphFactory.getPureFactory().make(
				"snd-value(sized-graph(<term>))", graph.toTerm());
	}

	public void recTerminate(ATerm t0) {
		// TODO Auto-generated method stub

	}

	public String getName() {
		return TOOL_NAME;
	}

}
