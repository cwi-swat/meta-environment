/*
 * Created on Apr 18, 2005
 *
 * To change the template for this generated file go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */
package nl.cwi.sen1.gui.plugin;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.HashMap;
import java.util.Map;

import javax.swing.JScrollPane;

import nl.cwi.sen1.data.graph.Graph;
import nl.cwi.sen1.data.graph.MetaGraphFactory;
import nl.cwi.sen1.data.graph.Node;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponentAdapter;
import nl.cwi.sen1.gui.StudioPlugin;
import nl.cwi.sen1.util.PopupHandler;
import nl.cwi.sen1.util.StudioPopupMenu;
import nl.cwi.sen1.util.Preferences;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class GraphPainter implements StudioPlugin, GraphPainterTif {
	private static final String TOOL_NAME = "graph-painter";

	private static final String RESOURCE_DIR = "/resources";

	private Studio studio;

	private MetaGraphFactory graphFactory;

	private Map graphs;

	private Preferences preferences;

	private GraphPainterBridge bridge;

	private boolean suspendSelectionNotification;

	private MouseEvent popupEvent;

	public GraphPainter() {
		String propertyPath = new String(RESOURCE_DIR + '/' + TOOL_NAME
				+ ".properties");
		this.preferences = new Preferences(getClass().getResourceAsStream(
				propertyPath));
		this.graphs = new HashMap();
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		graphFactory = new MetaGraphFactory((PureFactory) studio
				.getATermFactory());
		bridge = new GraphPainterBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}

	public void displayGraph(String id, ATerm graphTerm) {
		GraphPanel panel = getPanel(id);
		if (panel != null) {
			Graph graph = graphFactory.GraphFromTerm(graphTerm);
			panel.setGraph(graph);
		}
	}

	private MouseListener makeMouseListener(final GraphPanel panel) {
		return new MouseAdapter() {
			public void mousePressed(MouseEvent event) {
				Node node = panel.getNodeAt(event.getX(), event.getY());
				if (node != null && !suspendSelectionNotification) {
					String graphId = panel.getId();
					String nodeId = node.getId().getId();
					if (event.isPopupTrigger()) {
						popupEvent = event;
						bridge.postEvent(studio.getATermFactory().make(
								"request-popup-event(<str>,<str>)", graphId,
								nodeId));
					} else {
						panel.setSelectedNode(node);
						bridge.postEvent(studio.getATermFactory().make(
								"node-selected(<str>,<str>)", graphId, nodeId));
					}
				}
			}

			public void mouseReleased(MouseEvent event) {
				mousePressed(event);
			}
		};
	}

	private GraphPanel createPanel(final String id) {
		GraphPanel panel = getPanel(id);
		if (panel == null) {
			panel = new GraphPanel(id, preferences);
			panel.addMouseListener(makeMouseListener(panel));
			graphs.put(id, panel);
			JScrollPane scrollPane = new JScrollPane(panel);
			studio.addComponent(new StudioComponentAdapter(id, scrollPane));
		}
		return panel;
	}

	public ATerm sizeGraph(String id, ATerm graphTerm) {
		GraphPanel panel = createPanel(id);
		Graph graph = graphFactory.GraphFromTerm(graphTerm);

		graph = panel.sizeGraph(graph);
		return graphFactory.getPureFactory().make(
				"snd-value(sized-graph(<term>))", graph.toTerm());
	}

	private GraphPanel getPanel(String id) {
		return (GraphPanel) graphs.get(id);
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void recTerminate(ATerm t0) {
	}

	public void recAckEvent(ATerm t0) {
	}

	public void selectNode(String graphId, String nodeId) {
		GraphPanel panel = getPanel(graphId);
		if (panel != null) {
			suspendSelectionNotification = true;
			panel.setSelectedNode(nodeId);
			suspendSelectionNotification = false;
		}
	}

	public void showPopup(final String graphId, final String nodeId, ATerm menu) {
		StudioPopupMenu popup = new StudioPopupMenu((ATermList) menu);
		popup.setPopupHandler(new PopupHandler() {
			public void popupSelected(ATerm action) {
				bridge.postEvent(studio.getATermFactory().make(
						"popup-menu-event(<str>,<str>,<term>)", graphId,
						nodeId, action));
			}
		});
		popup.show(popupEvent.getComponent(), popupEvent.getX(), popupEvent
				.getY());
	}
}
