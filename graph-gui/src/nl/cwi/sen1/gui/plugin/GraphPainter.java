package nl.cwi.sen1.gui.plugin;

import java.awt.FontMetrics;
import java.awt.event.ActionEvent;
import java.awt.event.MouseEvent;
import java.util.HashMap;
import java.util.Map;

import javax.swing.AbstractAction;
import javax.swing.ButtonGroup;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JSeparator;

import nl.cwi.sen1.configapi.types.Event;
import nl.cwi.sen1.graph.Factory;
import nl.cwi.sen1.graph.types.Graph;
import nl.cwi.sen1.graph.types.NodeId;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.util.PopupHandler;
import nl.cwi.sen1.util.Preferences;
import nl.cwi.sen1.util.StudioPopupMenu;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class GraphPainter extends DefaultStudioPlugin implements
		GraphPainterTif {
	private static final String TOOL_NAME = "graph-painter";

	private static final String RESOURCE_DIR = "/resources";

	private Studio studio;

	private Factory graphFactory;

	private Map<String, GraphPanel> graphs;

	private Map<String, StudioComponent> forcePanels;

	private Preferences preferences;

	private GraphPainterBridge bridge;

	private MouseEvent popupEvent;

	public GraphPainter() {
		String propertyPath = new String(RESOURCE_DIR + '/' + TOOL_NAME
				+ ".properties");
		this.preferences = new Preferences(getClass().getResourceAsStream(
				propertyPath));
		this.graphs = new HashMap<String, GraphPanel>();
		this.forcePanels = new HashMap<String, StudioComponent>();
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		graphFactory = Factory.getInstance((PureFactory) studio
				.getATermFactory());
		bridge = new GraphPainterBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}

	public void displayGraph(String graphType, ATerm graphId, ATerm graphTerm) {
		GraphPanel panel = getPanel(graphType, graphId.toString());
		if (panel != null) {
			Graph graph = graphFactory.GraphFromTerm(graphTerm);
			panel.setGraph(new GraphAdapter(graph));
		}
		else {
			System.err.println("Graph not displayed because it was not created before");
		}
	}

	private boolean isTrue(ATerm bool) {
		return !bool.isEqual(bool.getFactory().parse("false"));
	}
	
	/**
	 * create a panel for displaying a graph. Before sizing, or displaying a graph
	 * a graph panel must be created.
	 * 
	 * @param graphType  The type of graph shown, for identifying apropriate menu's etc.
	 * @param graphId  The unique id of the graph (modulo graphId)
	 * @param shared   Reuse a panel if a panel with the same (graphId,graphId) exists
	 * @param closable Let the user be able to close the panel 
	 */
	public ATerm createPanel(String graphType, ATerm graphId, ATerm shared, ATerm closable) 
	{
		createPanel(graphType, graphId, isTrue(shared), isTrue(closable));
		return shared.getFactory().parse("snd-value(panel-created)");
	}
	
	private void createPanel(final String graphType, final ATerm graphId, boolean shared, boolean close) {
		GraphPanel panel = getPanel(graphType, graphId.toString());

		if (!shared && panel != null) {
			System.err.println("Graph not created because a panel with the same id exists already.");
			return;
		}
		
		if (panel == null) {
			panel = new GraphPanel(graphType, graphId.toString(), preferences, close);
			final GraphPanel graphPanel = panel;
			StudioComponent comp = new StudioComponentImpl(panelKey(graphType, graphId.toString()), panel) {
				public void requestClose() throws CloseAbortedException {
					if (!graphPanel.isClosable()) {
						throw new CloseAbortedException();
					}
                    removePanel(graphType, graphId.toString());
                    studio.removeComponent(this);
                    bridge.postEvent(studio.getATermFactory().make(
                    		"panel-closed(<str>,<term>)", graphType, graphId));
				}
			};

			panel.setGraphPanelListener(new GraphPanelListener() {
				public void nodeSelected(String id) {
					NodeId nodeId = graphFactory.NodeIdFromString(id);
					bridge.postEvent(studio.getATermFactory().make(
							"node-selected(<str>,<term>,<term>)", graphType, graphId,
							nodeId.toTerm()));
				}

				public void popupRequested(String id, MouseEvent e) {
					popupEvent = e;

					NodeId nodeId = graphFactory.NodeIdFromString(id);
					bridge.postEvent(studio.getATermFactory().make(
							"request-popup-event(<str>,<term>,<term>)", graphType, graphId,
							nodeId.toTerm()));
				}
			});
			
			setPanel(graphType, graphId.toString(), panel);
			((StudioWithPredefinedLayout) studio).addComponent(comp,
					StudioImplWithPredefinedLayout.TOP_RIGHT);
			studio.addComponentMenu(comp, createGraphMenu(panel, "Dot"));
			panel.setLayout("Dot");
		}
	}

	private JMenu createGraphMenu(final GraphPanel panel, String initialLayout) {
		JMenu graph = new JMenu("Graph");
		JMenu layouts = createLayoutMenu(graph, panel, initialLayout);
		graph.add(new JSeparator());
		JMenu toggles = createTogglesMenu(graph, panel);

		graph.add(layouts);
		graph.add(toggles);

		JMenuItem export = new JMenuItem("Export");
		export.addActionListener(panel.getSaveImageAction());
		graph.add(export);

		JMenuItem reset = new JMenuItem("Reset view");
		reset.addActionListener(new AbstractAction() {
			public void actionPerformed(ActionEvent e) {
				panel.restoreZoomAndPan();
			}
		});
		graph.add(reset);

		return graph;
	}

	private JMenu createTogglesMenu(JMenu menu, final GraphPanel panel) {
		JMenuItem item;
		ButtonGroup edge = new ButtonGroup();

		item = new JRadioButtonMenuItem("Curved edges");
		item.addActionListener(new AbstractAction() {
			public void actionPerformed(ActionEvent e) {
				panel.setCurvedEdges();
			}
		});
		edge.add(item);
		menu.add(item);

		item = new JRadioButtonMenuItem("Straight edges");
		item.addActionListener(new AbstractAction() {
			public void actionPerformed(ActionEvent e) {
				panel.setStraightEdges();
			}
		});
		item.setSelected(true);
		edge.add(item);
		menu.add(item);

		menu.add(new JSeparator());

		ButtonGroup animation = new ButtonGroup();
		item = new JRadioButtonMenuItem("Linear animation");
		item.addActionListener(new AbstractAction() {
			public void actionPerformed(ActionEvent e) {
				panel.setLinearAnimation();
			}
		});
		animation.add(item);
		menu.add(item);

		item = new JRadioButtonMenuItem("Polar animation");
		item.addActionListener(new AbstractAction() {
			public void actionPerformed(ActionEvent e) {
				panel.setPolarAnimation();
			}
		});
		animation.add(item);
		menu.add(item);

		item = new JRadioButtonMenuItem("No animation");
		item.addActionListener(new AbstractAction() {
			public void actionPerformed(ActionEvent e) {
				panel.setNoAnimation();
			}
		});
		animation.add(item);
		item.setSelected(true);
		menu.add(item);

		menu.add(new JSeparator());

		// item = new JCheckBoxMenuItem("Show force panel");
		// item.addActionListener(new AbstractAction() {
		// public void actionPerformed(ActionEvent e) {
		// JCheckBoxMenuItem item = (JCheckBoxMenuItem) e.getSource();
		// if (item.isSelected()) {
		// showForcePanel(panel.getId(), true);
		// } else {
		// showForcePanel(panel.getId(), false);
		// }
		// }
		// });
		// item.setSelected(false);
		// menu.add(item);

		return menu;
	}

	protected void showForcePanel(String graphType, String graphId, boolean show) {
		if (show) {
			GraphPanel graphPanel = getPanel(graphType, graphId);
			GraphForcePanel forcePanel = new GraphForcePanel(graphPanel
					.getForceSimulator(), preferences);
			StudioComponent comp = new StudioComponentImpl("Forces for " + graphType,
					forcePanel);
			((StudioWithPredefinedLayout) studio).addComponent(comp,
					StudioImplWithPredefinedLayout.BOTTOM_LEFT);
			setForcePanel(graphType, graphId, comp);
		} else {
			StudioComponent comp = getForcePanel(graphType, graphId);
			if (comp != null) {
				studio.removeComponent(comp);
				forcePanels.remove(graphType);
			}
		}
	}

	private StudioComponent getForcePanel(String graphType, String graphId) {
		return forcePanels.get(panelKey(graphType, graphId));
	}

	private void setForcePanel(String graphType, String graphId, StudioComponent comp) {
		forcePanels.put(panelKey(graphType, graphId), comp);
	}

	private String panelKey(String graphType, String graphId) {
		return graphType + ":" + graphId;
	}

	private JMenu createLayoutMenu(JMenu menu, final GraphPanel panel,
			String initial) {
		ButtonGroup group = new ButtonGroup();

		final Object[] layouts = panel.getLayouts();

		for (int i = 0; i < layouts.length; i++) {
			final String name = (String) layouts[i];
			JRadioButtonMenuItem random = new JRadioButtonMenuItem(name);
			random.addActionListener(new AbstractAction() {
				public void actionPerformed(ActionEvent e) {
					panel.setLayout(name);
				}
			});

			if (initial.equals(name)) {
				random.setSelected(true);
			}
			group.add(random);
			menu.add(random);
		}

		return menu;
	}

	private GraphPanel getPanel(String graphType, String graphId) {
		return graphs.get(panelKey(graphType, graphId));
	}
	
	private void setPanel(String graphType, String graphId, GraphPanel panel) {
		graphs.put(panelKey(graphType, graphId), panel);
	}
	
	private void removePanel(String graphType, String graphId) {
		graphs.remove(panelKey(graphType, graphId));
	}

	public String getName() {
		return TOOL_NAME;
	}

	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();
	}

	public void recAckEvent(ATerm t0) {
	}

	public void selectNode(String graphType, ATerm graphId, ATerm nodeId) {
		GraphPanel panel = getPanel(graphType, graphId.toString());
		if (panel != null) {
			panel.setSelectedNode(nodeId.toString());
		}
	}

	public void showPopup(final String graphType, final ATerm graphId, final ATerm nodeId, ATerm menu) {
		StudioPopupMenu popup = new StudioPopupMenu((ATermList) menu);
		popup.setPopupHandler(new PopupHandler() {
			public void popupSelected(Event action) {
				bridge.postEvent(studio.getATermFactory().make(
						"popup-menu-event(<str>,<term>,<term>,<term>)", graphType, graphId,
						nodeId, action.toTerm()));
			}
		});
		popup.show(popupEvent.getComponent(), popupEvent.getX(), popupEvent
				.getY());
	}

	public ATerm sizeGraph(String graphType, ATerm graphId, ATerm graphTerm) {
		GraphPanel panel = getPanel(graphType, graphId.toString());
		
		if (panel != null) {
		Graph graph = graphFactory.GraphFromTerm(graphTerm);
		FontMetrics metrics = panel.getFontMetrics(preferences
				.getFont(GraphConstants.NODE_FONT));
		graph = GraphAdapter.sizeGraph(metrics, preferences, graph);
		return graphFactory.getPureFactory().make(
				"snd-value(sized-graph(<term>))", graph.toTerm());
		}
        System.err.println("graph not sized, because a panel was not created yet");
        return graphFactory.getPureFactory().make(
        		"snd-value(sized-graph(<term>))", graphTerm);
	}
}
