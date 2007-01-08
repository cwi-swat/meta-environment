package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.geom.AffineTransform;
import java.awt.geom.NoninvertibleTransformException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import javax.swing.AbstractAction;
import javax.swing.JPanel;

import nl.cwi.sen1.graph.types.Attribute;
import nl.cwi.sen1.util.Preferences;
import prefuse.Constants;
import prefuse.Display;
import prefuse.Visualization;
import prefuse.action.Action;
import prefuse.action.ActionList;
import prefuse.action.RepaintAction;
import prefuse.action.animate.LocationAnimator;
import prefuse.action.animate.PolarLocationAnimator;
import prefuse.action.assignment.ColorAction;
import prefuse.action.assignment.FontAction;
import prefuse.action.layout.CircleLayout;
import prefuse.action.layout.RandomLayout;
import prefuse.action.layout.graph.ForceDirectedLayout;
import prefuse.action.layout.graph.FruchtermanReingoldLayout;
import prefuse.action.layout.graph.NodeLinkTreeLayout;
import prefuse.action.layout.graph.RadialTreeLayout;
import prefuse.activity.Activity;
import prefuse.activity.SlowInSlowOutPacer;
import prefuse.controls.Control;
import prefuse.controls.ControlAdapter;
import prefuse.controls.DragControl;
import prefuse.controls.FocusControl;
import prefuse.controls.PanControl;
import prefuse.controls.ZoomControl;
import prefuse.controls.ZoomToFitControl;
import prefuse.data.Graph;
import prefuse.data.Tuple;
import prefuse.data.event.TupleSetListener;
import prefuse.data.tuple.TupleSet;
import prefuse.render.DefaultRendererFactory;
import prefuse.render.EdgeRenderer;
import prefuse.render.LabelRenderer;
import prefuse.util.ColorLib;
import prefuse.util.display.ExportDisplayAction;
import prefuse.util.force.DragForce;
import prefuse.util.force.ForceSimulator;
import prefuse.util.force.NBodyForce;
import prefuse.util.force.SpringForce;
import prefuse.visual.VisualItem;
import prefuse.visual.expression.InGroupPredicate;

public class GraphPanel extends JPanel {
	private String type;

	private String id;

	private Display display;

	private Visualization vis;

	private GraphPanelListener listener;

	private Activity currentLayout;

	private Activity currentAnimation;

	private Set<String> layouts;

	private EdgeRenderer edgeRenderer;

	private ForceSimulator forceSimulator;

	private Boolean closable;

	public void setClosable(Boolean closable) {
		this.closable = closable;
	}

	public Boolean isClosable() {
		return closable;
	}

	public GraphPanel(String type, String id, final Preferences prefs,
			boolean closable) {
		this.id = id;
		this.type = type;
		this.closable = closable;
		setLayout(new BorderLayout());

		vis = new Visualization();

		LabelRenderer lr = new GraphNodeRenderer(GraphConstants.LABEL);
		lr.setHorizontalPadding(prefs.getInt(GraphConstants.NODE_BORDER_WIDTH));
		lr.setVerticalPadding(prefs.getInt(GraphConstants.NODE_BORDER_HEIGHT));
		edgeRenderer = new GraphEdgeRenderer(Constants.EDGE_TYPE_LINE,
				Constants.EDGE_ARROW_FORWARD);
		vis.setRendererFactory(new DefaultRendererFactory(lr, edgeRenderer));

		ColorAction nStroke = new ColorAction(GraphConstants.NODES,
				VisualItem.STROKECOLOR);
		nStroke.setDefaultColor(prefs.getColor(GraphConstants.NODE_FOREGROUND)
				.getRGB());
		nStroke.add(new InGroupPredicate(Visualization.FOCUS_ITEMS), prefs
				.getColor(GraphConstants.NODE_SELECTED_FOREGROUND).getRGB());

		ColorAction nFill = new GraphColorAction(GraphConstants.NODES,
				GraphConstants.FILLCOLOR, VisualItem.FILLCOLOR);
		nFill.setDefaultColor(prefs.getColor(GraphConstants.NODE_BACKGROUND)
				.getRGB());
		nFill.add(new InGroupPredicate(Visualization.FOCUS_ITEMS), prefs
				.getColor(GraphConstants.NODE_SELECTED_BACKGROUND).getRGB());

		ColorAction eStroke = new ColorAction(GraphConstants.EDGES,
				VisualItem.STROKECOLOR);
		eStroke.setDefaultColor(Color.BLACK.getRGB());

		ColorAction eFill = new ColorAction(GraphConstants.EDGES,
				VisualItem.FILLCOLOR);
		eStroke.setDefaultColor(Color.BLACK.getRGB());

		ColorAction text = new ColorAction(GraphConstants.NODES,
				VisualItem.TEXTCOLOR);
		text.setDefaultColor(ColorLib.gray(50));

		FontAction font = new FontAction(GraphConstants.NODES, prefs
				.getFont(GraphConstants.NODE_FONT));

		ActionList draw = new ActionList();
		draw.add(text);
		draw.add(nStroke);
		draw.add(nFill);
		draw.add(eStroke);
		draw.add(eFill);
		draw.add(font);
		draw.add(new RepaintAction());

		vis.putAction("draw", draw);

		display = new Display(vis);
		display.setHighQuality(true);
		display.addControlListener(new DragControl());
		display.addControlListener(new ZoomControl());
		ZoomToFitControl ztf = new ZoomToFitControl();
		ztf.setZoomOverItem(false);
		display.addControlListener(ztf);
		display.addControlListener(new PanControl());
		display.addControlListener(new FocusControl());
		display.addControlListener(new ControlAdapter() {
			public void itemEntered(VisualItem item, MouseEvent e) {
				if (item.isInGroup(GraphConstants.NODES)) {
					item.setFillColor(prefs.getColor(
							GraphConstants.NODE_HOVERED_BACKGROUND).getRGB());
					item.setStrokeColor(prefs.getColor(
							GraphConstants.NODE_HOVERED_FOREGROUND).getRGB());
					item.getVisualization().repaint();
				}
			}

			public void itemExited(VisualItem item, MouseEvent e) {
				if (item.isInGroup(GraphConstants.NODES)) {
					item.setFillColor(item.getInt(GraphConstants.FILLCOLOR));
					item.setStrokeColor(prefs.getColor(
							GraphConstants.NODE_FOREGROUND).getRGB());
					item.getVisualization().repaint();
				}
			}

			/*
			 * public void itemPressed(VisualItem item, MouseEvent e) { if
			 * (e.isPopupTrigger()) { String id =
			 * item.getString(GraphConstants.ID); if (id != null) {
			 * firePopupRequested(id, e); } } } }
			 */
		});

		TupleSet focusGroup = vis.getGroup(Visualization.FOCUS_ITEMS);
		focusGroup.addTupleSetListener(new TupleSetListener() {
			public void tupleSetChanged(TupleSet ts, Tuple[] add, Tuple[] rem) {
				for (Tuple t : add) {
					fireNodeSelected(((VisualItem) t)
							.getString(GraphConstants.ID));
				}
			}
		});

		createLayouts();
		setPolarAnimation();

		add(display, BorderLayout.CENTER);
	}

	public void addControlListener(Control cl) {
		display.addControlListener(cl);
	}

	public AbstractAction getSaveImageAction() {
		return new ExportDisplayAction(display);
	}

	public void setCurvedEdges() {
		edgeRenderer.setEdgeType(Constants.EDGE_TYPE_CURVE);
		runNow();
	}

	public void setStraightEdges() {
		edgeRenderer.setEdgeType(Constants.EDGE_TYPE_LINE);
		runNow();
	}

	public void setNoAnimation() {
		ActionList animation = new ActionList(vis);
		animation.add(new RepaintAction());
		vis.putAction("no-animation", animation);
		currentAnimation = animation;
	}

	public void setPolarAnimation() {
		ActionList animation = new ActionList(vis, 1500);
		animation.setPacingFunction(new SlowInSlowOutPacer());
		animation.add(new PolarLocationAnimator());
		animation.add(new RepaintAction());
		vis.putAction("polar-animation", animation);
		currentAnimation = animation;
	}

	public void setLinearAnimation() {
		ActionList animation = new ActionList(vis, 1500);
		animation.setPacingFunction(new SlowInSlowOutPacer());
		animation.add(new LocationAnimator());
		animation.add(new RepaintAction());
		vis.putAction("linear-animation", animation);
		currentAnimation = animation;
	}

	private void createLayouts() {
		layouts = new HashSet<String>();

		ActionList dot = new ActionList();
		dot.add(new GraphDotLayout(GraphConstants.GRAPH));
		vis.putAction("Dot", dot);
		layouts.add("Dot");

		forceSimulator = new ForceSimulator();
		forceSimulator.addForce(new NBodyForce());
		forceSimulator.addForce(new SpringForce());
		forceSimulator.addForce(new DragForce());

		ActionList contforce = new ActionList(Action.INFINITY);
		contforce.add(new ForceDirectedLayout(GraphConstants.GRAPH,
				forceSimulator, false));
		contforce.add(new RepaintAction());
		vis.putAction("Force", contforce);
		layouts.add("Force");

		ActionList random = new ActionList();
		random.add(new RandomLayout());
		vis.putAction("Random", random);
		layouts.add("Random");

		ActionList circle = new ActionList();
		circle.add(new CircleLayout(GraphConstants.NODES));
		vis.putAction("Circle", circle);
		layouts.add("Circle");

		ActionList nodeLink = new ActionList();
		nodeLink.add(new NodeLinkTreeLayout(GraphConstants.GRAPH));
		vis.putAction("NodeLink Horizontal", nodeLink);
		layouts.add("NodeLink Horizontal");

		ActionList nodeLinkV = new ActionList();
		NodeLinkTreeLayout nodeLinkVlayout = new NodeLinkTreeLayout(
				GraphConstants.GRAPH);
		nodeLinkVlayout.setOrientation(Constants.ORIENT_TOP_BOTTOM);
		nodeLinkV.add(nodeLinkVlayout);
		vis.putAction("NodeLink Vertical", nodeLinkV);
		layouts.add("NodeLink Vertical");

		ActionList radialTree = new ActionList();
		radialTree.add(new RadialTreeLayout(GraphConstants.GRAPH));
		vis.putAction("Radial", radialTree);
		layouts.add("Radial");

		ActionList funny = new ActionList();
		funny.add(new FruchtermanReingoldLayout(GraphConstants.GRAPH));
		vis.putAction("Funny", funny);
		layouts.add("Funny");
	}

	public ForceSimulator getForceSimulator() {
		return forceSimulator;
	}

	public Object[] getLayouts() {
		return layouts.toArray();
	}

	public void setLayout(String name) {
		Action newLayout = vis.getAction(name);

		if (newLayout != null) {
			cancel();
			currentLayout = newLayout;
			runNow();
		} else {
			throw new UnsupportedOperationException("Layout " + name
					+ " does not exist");
		}
	}

	private void runNow() {
		if (currentLayout != null) {
			vis.run("draw");
			currentLayout.run();
			vis.repaint();
			currentAnimation.run();
		} else {
			System.err.println("No current layout!");
		}
	}

	private void cancel() {
		if (currentLayout != null) {
			currentLayout.cancel();
		}
	}

	protected void resize() {
		setSize(getParent().getWidth(), getParent().getHeight());
	}

	void setGraphPanelListener(GraphPanelListener l) {
		this.listener = l;
	}

	protected void fireNodeSelected(String selectedNodeId) {
		listener.nodeSelected(selectedNodeId);
	}

	void setGraph(Graph g) {
		vis.removeGroup(GraphConstants.GRAPH);
		vis.addGraph(GraphConstants.GRAPH, g);
		Activity oldAnimation = currentAnimation;
		setNoAnimation();
		runNow();
		currentAnimation = oldAnimation;
	}

	public void updateNode(String nodeId, Attribute attr) {
		VisualItem node = findNode(nodeId);
		if (node != null) {
			GraphAdapter.updateNode(node, attr);
			node.setValidated(false);
			vis.run("draw");
			vis.repaint();
			System.err.println("Updated " + nodeId + ": " + attr.toString());
		}
	}

	public void setSelectedNode(String nodeId) {
		VisualItem node = findNode(nodeId);
		if (node != null) {
			TupleSet focusGroup = vis.getGroup(Visualization.FOCUS_ITEMS);
			focusGroup.setTuple(node);
		}
	}

	private VisualItem findNode(String nodeId) {
		Graph g = (Graph) vis.getGroup(GraphConstants.GRAPH);
		if (g != null) {
			Iterator nodeIter = g.nodes();
			while (nodeIter.hasNext()) {
				VisualItem node = (VisualItem) nodeIter.next();
				if (node.getString(GraphConstants.ID).equals(nodeId)) {
					return node;
				}
			}
		}

		return null;
	}

	public void restoreZoomAndPan() {
		try {
			display.setTransform(new AffineTransform());
			display.repaint();
		} catch (NoninvertibleTransformException e) {
			// this does not happen
		}
	}

	public String getId() {
		return id;
	}

	public String getType() {
		return type;
	}
}
