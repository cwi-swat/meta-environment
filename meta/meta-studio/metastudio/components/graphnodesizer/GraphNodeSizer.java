package metastudio.components.graphnodesizer;

import java.awt.FontMetrics;
import java.io.IOException;

import metastudio.components.graphs.NodeSizer;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import metastudio.utils.Preferences;
import aterm.ATerm;

public class GraphNodeSizer implements GraphNodeSizerTif, Runnable {
	private static FontMetrics metrics;
	private MetaGraphFactory factory;
	private GraphNodeSizerBridge bridge;

	// TODO: get rid of this static method, another way must be possible.
	public static void registerFontMetrics(FontMetrics m) {
		metrics = m;
	}

	public GraphNodeSizer(MetaGraphFactory factory, String args[]) {
		this.factory = factory;

		try {
			bridge = new GraphNodeSizerBridge(factory.getPureFactory(), this);
			bridge.init(args);
			bridge.setLockObject(this);
			bridge.connect("graph-node-sizer", null, -1);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public ATerm sizeGraph(ATerm graphTerm) {
		Graph graph = factory.GraphFromTerm(graphTerm);

		System.err.println("Sizing a graph");
		
		if (metrics != null) {
			NodeSizer sizer = new NodeSizer() {
				public int getWidth(Node node) {
					return metrics.stringWidth(node.getLabel())
						+ Preferences.getInteger("graph.node.border.width") * 2;
				}
				public int getHeight(Node node) {
					return metrics.getHeight()
						+ Preferences.getInteger("graph.node.border.height") * 2;
				}
			};

			graph = orderNodes(graph);
			graph = sizeNodes(graph, sizer);
		}

		return factory.getPureFactory().make(
			"snd-value(sized-graph(<term>))",
			graph.toTerm());
	}

	protected Graph orderNodes(Graph graph) {
		return graph;
	}

	protected Graph sizeNodes(Graph graph, NodeSizer sizer) {
		return graph.sizeNodes(sizer);
	}

	public void recTerminate(ATerm t0) {
	}

	public void run() {
		bridge.run();
	}
}
