/*
 * Created on Apr 18, 2005
 *
 * To change the template for this generated file go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */
package nl.cwi.sen1.gui.plugin;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Properties;

import nl.cwi.sen1.data.graph.Graph;
import nl.cwi.sen1.data.graph.MetaGraphFactory;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioPlugin;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class GraphPainter implements StudioPlugin, GraphPainterTif {
	private static final String TOOL_NAME = "graph-painter";

	private static final String RESOURCE_DIR = "/resources";

	private Studio studio;

	private MetaGraphFactory graphFactory;

	private Map graphs;

	private Properties properties;

	public GraphPainter() {
		graphs = new HashMap();
		String propertyPath = new String(RESOURCE_DIR + '/' + TOOL_NAME
				+ ".properties");
		InputStream stream = getClass().getResourceAsStream(propertyPath);
		properties = new Properties();
		try {
			properties.load(stream);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
        try {
            File file = new File(System.getProperty("user.home"), ".metarc");
            stream = new FileInputStream(file);
            properties.load(stream);
        } catch (IOException e) {
            // do nothing
        }

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
			panel = new GraphPanel(id, properties);
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
