package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JViewport;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.MouseInputAdapter;

import nl.cwi.sen1.data.graph.Graph;
import nl.cwi.sen1.data.graph.MetaGraphFactory;
import nl.cwi.sen1.data.graph.Node;
import nl.cwi.sen1.util.Preferences;

// TODO: extract functionality from the GraphPanel that should be here.
public class ZoomableGraphPanel extends JPanel {
	private int SLIDER_STEP_SIZE;

	private int SLIDER_MINIMUM;

	private int SLIDER_MAXIMUM;

	private int SLIDER_DEFAULT;

	private GraphPanel graphPanel;

	private JSlider slider;

	protected MetaGraphFactory factory;

	private JViewport view;

	private JLabel zoomToFit;

	public ZoomableGraphPanel(MetaGraphFactory factory, String id, Preferences preferences) {
		this.factory = factory;

		graphPanel = new GraphPanel(id, preferences);

		setLayout(new BorderLayout());

		// TODO: get this spaghetti crosslink out!
		// GraphNodeSizer.registerFontMetrics(graphPanel.getFontMetrics(Preferences.getFont(GraphPanel.PREF_NODE_FONT)));

		slider = createSlider();
		setSliderToolTip();
		MouseWheelListener wheel = new MouseWheelListener() {
			public void mouseWheelMoved(MouseWheelEvent e) {
				slider.setValue(slider.getValue() - e.getUnitsToScroll());
			}
		};

		JScrollPane scrolledPane = new JScrollPane(graphPanel);
		view = scrolledPane.getViewport();

		Color bgcolor = Color.WHITE;
		//Preferences.getColor("graph.background");
		view.setBackground(bgcolor);
		view.addMouseWheelListener(wheel);

		add(scrolledPane, BorderLayout.CENTER);

		JPanel sliderPanel = new JPanel();
		sliderPanel.setLayout(new BorderLayout());

		zoomToFit = new JLabel("Z", JLabel.CENTER);
		zoomToFit.setBackground(bgcolor);
		zoomToFit.addMouseListener(new MouseInputAdapter() {
			public void mouseClicked(MouseEvent e) {
				int scale = graphPanel
						.getZoomToFitFactor(view.getVisibleRect());
				slider.setValue(Math.min(scale, SLIDER_MAXIMUM));
			}
		});
		zoomToFit.setToolTipText("Zoom to fit");
		sliderPanel.add(zoomToFit, BorderLayout.NORTH);
		sliderPanel.add(slider, BorderLayout.CENTER);
		sliderPanel.setBackground(bgcolor);

		add(sliderPanel, BorderLayout.WEST);

		scrolledPane.getViewport().addMouseWheelListener(wheel);
		graphPanel.setScale(100);//Preferences.getInteger("graph.scale.default"));
	}

	public MetaGraphFactory getGraphFactory() {
		return factory;
	}

	private void setSliderToolTip() {
		slider.setToolTipText("Zoom" + slider.getValue() + "%");
	}

	private JSlider createSlider() {
		SLIDER_MINIMUM = 0;//Preferences.getInteger("graph.scale.minimum");
		SLIDER_MAXIMUM = 200;//Preferences.getInteger("graph.scale.maximum");
		SLIDER_STEP_SIZE = 5;//Preferences.getInteger("graph.scale.stepsize");
		SLIDER_DEFAULT = 100;//Preferences.getInteger("graph.scale.default");
		slider = new JSlider(SLIDER_MINIMUM, SLIDER_MAXIMUM, SLIDER_STEP_SIZE);
		slider.setOrientation(SwingConstants.VERTICAL);
		slider.setBackground(Color.WHITE);
		//Preferences.getColor("graph.scale.background");
		slider.setValue(SLIDER_DEFAULT);

		slider.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				graphPanel.setScale(slider.getValue());
				setSliderToolTip();
				graphPanel.setSelectedNode(graphPanel.getSelectedNode());
				graphPanel.setToolTipEnabled(slider.getValue() < 100);
			}
		});

		return slider;
	}

	public GraphPanel getGraphPanel() {
		return graphPanel;
	}

	public String getId() {
		return graphPanel.getId();
	}

	public Node getNodeAt(int x, int y) {
		return graphPanel.getNodeAt(x, y);
	}

	public void setDragEnabled(boolean on) {
		graphPanel.setDragEnabled(on);
	}

	public void setGraph(Graph graph) {
		graphPanel.setGraph(graph);
	}

	public void setSelectedNode(Node node) {
		graphPanel.setSelectedNode(node);
	}

	public int getIndex() {
		return graphPanel.getIndex();
	}

	public Node getNode(String string) {
		return graphPanel.getNode(string);
	}

	public synchronized void addMouseListener(MouseListener l) {
		graphPanel.addMouseListener(l);
	}
}
