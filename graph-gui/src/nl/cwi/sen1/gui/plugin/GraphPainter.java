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
import nl.cwi.sen1.gui.DefaultStudioPlugin;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponent;
import nl.cwi.sen1.gui.StudioComponentImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
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

    public void displayGraph(String id, ATerm graphTerm) {
        GraphPanel panel = getPanel(id);
        if (panel == null) {
            panel = createPanel(id);
        }

        Graph graph = graphFactory.GraphFromTerm(graphTerm);
        panel.setGraph(new GraphAdapter(graph));
    }

    private GraphPanel createPanel(final String graphId) {
        GraphPanel panel = getPanel(graphId);

        if (panel == null) {
            panel = new GraphPanel(graphId, preferences);
            StudioComponent comp = new StudioComponentImpl(graphId, panel) {
                public void requestClose() throws CloseAbortedException {
                    throw new CloseAbortedException();
                }
            };

            panel.setGraphPanelListener(new GraphPanelListener() {
                public void nodeSelected(String id) {
                    NodeId nodeId = graphFactory.NodeIdFromString(id);
                    bridge.postEvent(studio.getATermFactory().make(
                            "node-selected(<str>,<term>)", graphId,
                            nodeId.toTerm()));
                }

                public void popupRequested(String id, MouseEvent e) {
                    popupEvent = e;

                    NodeId nodeId = graphFactory.NodeIdFromString(id);
                    bridge.postEvent(studio.getATermFactory().make(
                            "request-popup-event(<str>,<term>)", graphId,
                            nodeId.toTerm()));
                }
            });
            graphs.put(graphId, panel);
            ((StudioWithPredefinedLayout) studio).addComponent(comp,
                    StudioImplWithPredefinedLayout.TOP_RIGHT);
            studio.addComponentMenu(comp, createGraphMenu(panel, "Dot"));
            panel.setLayout("Dot");
        }

        return panel;
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

//        item = new JCheckBoxMenuItem("Show force panel");
//        item.addActionListener(new AbstractAction() {
//            public void actionPerformed(ActionEvent e) {
//                JCheckBoxMenuItem item = (JCheckBoxMenuItem) e.getSource();
//                if (item.isSelected()) {
//                    showForcePanel(panel.getId(), true);
//                } else {
//                    showForcePanel(panel.getId(), false);
//                }
//            }
//        });
//        item.setSelected(false);
//        menu.add(item);

        return menu;
    }

    protected void showForcePanel(String id, boolean show) {
        if (show) {
            GraphPanel graphPanel = graphs.get(id);
            GraphForcePanel forcePanel = new GraphForcePanel(graphPanel.getForceSimulator(), preferences);
            StudioComponent comp = new StudioComponentImpl("Forces for "
                    + id, forcePanel);
            ((StudioWithPredefinedLayout) studio).addComponent(comp,
                    StudioImplWithPredefinedLayout.BOTTOM_LEFT);
            forcePanels.put(id, comp);
        } else {
            StudioComponent comp = forcePanels.get(id);
            if (comp != null) {
                studio.removeComponent(comp);
                forcePanels.remove(id);
            }
        }
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

    private GraphPanel getPanel(String id) {
        return graphs.get(id);
    }

    public String getName() {
        return TOOL_NAME;
    }

    public void recTerminate(ATerm t0) {
        fireStudioPluginClosed();
    }

    public void recAckEvent(ATerm t0) {
    }

    public void selectNode(String graphId, ATerm nodeId) {
        GraphPanel panel = getPanel(graphId);
        if (panel != null) {
            panel.setSelectedNode(nodeId.toString());
        }
    }

    public void showPopup(final String graphId, final ATerm nodeId, ATerm menu) {
        StudioPopupMenu popup = new StudioPopupMenu((ATermList) menu);
        popup.setPopupHandler(new PopupHandler() {
            public void popupSelected(Event action) {
                bridge.postEvent(studio.getATermFactory().make(
                        "popup-menu-event(<str>,<term>,<term>)", graphId,
                        nodeId, action.toTerm()));
            }
        });
        popup.show(popupEvent.getComponent(), popupEvent.getX(), popupEvent
                .getY());
    }

    public ATerm sizeGraph(String id, ATerm graphTerm) {
        GraphPanel panel = createPanel(id);
        Graph graph = graphFactory.GraphFromTerm(graphTerm);
        FontMetrics metrics = panel.getFontMetrics(preferences
                .getFont(GraphConstants.NODE_FONT));
        graph = GraphAdapter.sizeGraph(metrics, preferences, graph);
        return graphFactory.getPureFactory().make(
                "snd-value(sized-graph(<term>))", graph.toTerm());
    }
}
