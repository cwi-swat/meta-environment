package nl.cwi.sen1.gui.plugin.prefusedot;

import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;
import java.text.CharacterIterator;
import java.text.StringCharacterIterator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import prefuse.data.Edge;
import prefuse.data.Graph;
import prefuse.data.Node;

/**
 * @author Jurgen Vinju
 * 
 * This class wraps a prefuse Graph in order to provide a bridge to AT&T's
 * graphviz. The idea is to build a graph via this interface and call the
 * doDotLayout() method after constructing the graph in memory. This will start
 * a session with the external dot tool via pipes, and annotate the graph with
 * x,y position information, and store the locations for the curved edges also.
 * @see nl.cwi.sen1.gui.plugin.prefusedot.DotNodeLayout for how this information will later be used to actually
 *      layout the graph.
 */
public class DotAdapter extends Graph {
	private static final int dpi = 72;

	public static final String DOT_CURVE_POINTS = "curve-points";
	public static final String DOT_X = "dotX";
	public static final String DOT_Y = "dotY";
	public static final String DOT_WIDTH = "dotWidth";
	public static final String DOT_HEIGHT = "dotHeight";
	public static final String DOT_LABEL = "label";
	public static final String DOT_ID = "id";
	public static final String DOT_SHAPE = "shape";
	
	private double scale;

	private Map<String, Node> nodeIds = new HashMap<String, Node>();

	public DotAdapter() {
		super(true);
		addColumn(DOT_ID, String.class);
		addColumn(DOT_LABEL, String.class);
		addColumn(DOT_X, int.class);
		addColumn(DOT_Y, int.class);
		addColumn(DOT_CURVE_POINTS, Point2D[].class);
		addColumn(DOT_WIDTH, int.class);
		addColumn(DOT_HEIGHT, int.class);
		addColumn(DOT_SHAPE, String.class);
	}

	/**
	 * Run the Dot layout algorithm and store the results as attributes in the graph
	 * table. These attributes can later be used by a prefuse layout algorithm.
	 * @see DotNodeLayout and @see DotLabelLayout for details. This method assumes
	 * you have added nodes and edges using the @method addNode() and @method addEdge() methods.
	 *
	 */
	public void doDotLayout() {
		executeDot();
	}

	private void executeDot() {
		try {
			String command = "dot -y -Tplain";
			Process child = Runtime.getRuntime().exec(command);

			OutputStream out = child.getOutputStream();
			printDot(new PrintStream(out));
			out.close();

			InputStream in = child.getInputStream();
			parseDot(in);
			in.close();
		} catch (IOException e) {
			// TODO do something with this error
		}
	}

	private Node getNode(String id) {
		return nodeIds.get(id);
	}

	private void storeNode(String id, Node node) {
		nodeIds.put(id, node);
	}

	/**
	 * This private class stores pre-compiled regular expressions for parsing
	 * the dot -Tplain output format.
	 */
	private static class Patterns {
		/*
		 *   graph scale width height
         *   node name x y width height label style shape color fillcolor
         *   edge tail head n x1 y1 .. xn yn [label xl yl] style color
         *   stop
		 */
		static final String id = "(\\w+|(?:\"(?:[^\\\"]|(?:\\\")|(?:\\\\))*\"))";
		static final String w = "(\\S+)";
		static final String d = "([0-9]+)";
		static final String r = "([0-9]+\\.[0-9]+)";
		static final String s = "\\s+";
		static final String any = "(.*)";

		static final Pattern start = Pattern.compile("graph" + s + r + s + r
				+ s + r);
		static final Pattern node = Pattern.compile("node" + s + id + s + r + s
				+ r + s + r + s + r + s + any);
		static final Pattern edge = Pattern.compile("edge" + s + id + s + id
				+ s + d + s + any);
		static final Pattern point = Pattern
				.compile("\\s*(\\S+)\\s+(\\S+)(.*)");
	}

	private void parseDot(InputStream in) {
		BufferedReader i = new BufferedReader(new InputStreamReader(in));

		try {
			do {
				String line = i.readLine();

				if (line != null) {
					Matcher m;

					m = Patterns.start.matcher(line);
					if (m.matches()) {
						parseStart(m.group(1), m.group(3));
						continue;
					}

					m = Patterns.node.matcher(line);
					if (m.matches()) {
						parseNode(m.group(1), m.group(2), m.group(3), m.group(4), m.group(5));
						continue;
					}

					m = Patterns.edge.matcher(line);
					if (m.matches()) {
						parseEdge(m.group(1), m.group(2), m.group(3), m
								.group(4));
						continue;
					}
				}
			} while (i.ready());
		} catch (IOException e) {
			// TODO : do something with this error
		}
	}

	/**
	 * Returns a list of edges from the source node to the target node.
	 */
	public List<Integer> getAllEdges(int source, int target) {
		List<Integer> result = new LinkedList<Integer>();
		int outd = getOutDegree(source);
		if (outd > 0) {
			int[] edges = (int[]) m_links.get(source, OUTLINKS);
			for (int i = 0; i < outd; ++i) {
				if (getTargetNode(edges[i]) == target) {
					result.add(new Integer(edges[i]));
				}
			}
		}
		return result;
	}

	/**
	 * Returns a list of edges between the source and target node
	 * 
	 * @param source
	 *            the source Node
	 * @param target
	 *            the target Node
	 * @return an Edge with given source and target nodes, or null if no such
	 *         edge is found.
	 */
	public List<Edge> getAllEdges(Node source, Node target) {
		nodeCheck(source, true);
		nodeCheck(target, true);
		List<Integer> edges = getAllEdges(source.getRow(), target.getRow());
		List<Edge> result = new LinkedList<Edge>();
		for (Integer i : edges) {
			result.add(getEdge(i.intValue()));
		}
		return result;
	}

	private void parseEdge(String toString, String fromString,
			String pointCount, String pointsStr) {
		String to = idFromDot(toString);
		String from = idFromDot(fromString);
		Point2D[] points = parseEdgePoints(Integer.parseInt(pointCount),
				pointsStr);

		List<Edge> edges = getAllEdges(getNode(to), getNode(from));
		for (Edge edge : edges) {
			Object tmp = edge.get(DOT_CURVE_POINTS);
			if (tmp == null) {
				edge.set(DOT_CURVE_POINTS, points);
				break;
			}
		}
	}

	private Point2D[] parseEdgePoints(int count, String rest) {
		List<Point2D> points = new LinkedList<Point2D>();

		for (; count > 0; count--) {
			Matcher n = Patterns.point.matcher(rest);

			if (n.matches()) {
				int x = (int) (Double.parseDouble(n.group(1)) * scale * dpi);
				int y = (int) (Double.parseDouble(n.group(2)) * scale * dpi);
				points.add(new Point2D.Float(x, y));
				rest = n.group(3);
			} else {
				break;
			}
		}

		Point2D[] result = new Point2D[points.size()];
		Iterator<Point2D> iter = points.iterator();

		for (int i = 0; iter.hasNext(); i++) {
			result[i] = iter.next();
		}

		return result;
	}
 
	private void parseNode(String id, String xstr, String ystr, String widthStr, String heightStr) {
		id = idFromDot(id);
		int x = (int) (Double.parseDouble(xstr) * scale * dpi);
		int y = (int) (Double.parseDouble(ystr) * scale * dpi);
		int width = (int) (Double.parseDouble(widthStr) * scale * dpi);
		int height = (int) (Double.parseDouble(heightStr) * scale * dpi);
		
		x = x - width / 2;
		y = y - height / 2;
		Node node = getNode(id);

		if (node != null) {
			node.setInt(DOT_X, x);
			node.setInt(DOT_Y, y);
			node.setInt(DOT_WIDTH, width);
			node.setInt(DOT_HEIGHT, height);
		} else {
			System.err.println("Node not found: " + id);
		}
	}

	private void parseStart(String scaleStr, String heightStr) {
		scale = Double.parseDouble(scaleStr);
	}

	/**
	 * Prints out the prefuse graph to Graphviz Dot format
	 * @param b PrintStream to output the graph to
	 */
	public void printDot(PrintStream b) {
		b.append("digraph prefuseGraph {\n");
		printNodes(b);
		printEdges(b);
		b.append("}\n");
	}

	private void printEdges(PrintStream b) {
		Iterator<?> iter = edges();

		while (iter.hasNext()) {
			Edge t = (Edge) iter.next();
			int from = t.getInt(Graph.DEFAULT_SOURCE_KEY);
			int to = t.getInt(Graph.DEFAULT_TARGET_KEY);
			String fromId = getNode(from).getString(DOT_ID);
			String toId = getNode(to).getString(DOT_ID);
			b.append(idToDot(fromId) + " -> " + idToDot(toId) + "\n");
		}
	}

	private void printNodes(PrintStream b) {
		Iterator<?> iter = nodes();

		while (iter.hasNext()) {
			Node t = (Node) iter.next();
			String id = idToDot(t.getString(DOT_ID));
			storeNode(id, t);
			b.append(id + " [");
			
			for (int i = t.getColumnCount() - 1; i >= 0; i--) {
				String key = t.getColumnName(i);
				if (t.canGetString(key)) {
				  String value = t.getString(i);
				  if (value != null) {
  				    b.append(" " + key + "=\"" + escape(value) + "\" ");
				  }
				}
			}
			b.append(" ]\n");
		}
	}

	private String escape(String string) {
		StringBuffer result = new StringBuffer();
		StringCharacterIterator i = new StringCharacterIterator(string);
		char ch = i.current();

		while (ch != CharacterIterator.DONE) {
			switch (ch) {
			case '\"':
				result.append('\\');
				result.append('\"');
				break;
			case '\n':
				result.append('\\');
				result.append('n');
				break;
			case '\t':
				result.append('\\');
				result.append('t');
				break;
			case '\\':
				if (ch != CharacterIterator.DONE) {
					ch = i.next();
					switch (ch) {
					case '\"':
					case '\n':
					case '\t':
						result.append('\\');
						result.append('\\');
						result.append('\\');
						break;
					default:
						result.append('\\');
					}
				} else {
					result.append(ch);
				}
			default:
				result.append(ch);
			}

			ch = i.next();
		}

		return result.toString();
	}
	
	/**
	 * A safe method to set an attribute of a node. If the attribute's column
	 * was not declared yet, it will be declared by this method first.
	 * @param node 
	 * @param key
	 * @param value
	 */
	public void setNodeAttribute(Node node, String key, Object value) {
		if (node.getColumnIndex(key) == -1) {
			addColumn(key, value.getClass());
		}
		
		node.set(key, value);
	}

	private String idToDot(String string) {
		String result = escape(string);
		return "\"" + result + "\"";
	}

	private String idFromDot(String id) {
		if (id.charAt(0) == '\"') {
			return id;
		}
		
		return "\"" + id + "\"";
	}

	public static void main(String[] args) {
		DotAdapter a = new DotAdapter();

		Node n = a.addNode();
		n.set(DotAdapter.DOT_ID, "{ aap }");
		n.set(DotAdapter.DOT_LABEL, "{ aap }");
		a.setNodeAttribute(n, "height", "1.5");
		a.setNodeAttribute(n, "width", "2.5");

		Node m = a.addNode();
		m.set(DotAdapter.DOT_ID, "[A-Z a-z]");
		m.set(DotAdapter.DOT_LABEL, "[A-Z a-z]");
		a.setNodeAttribute(n, "height", "2.5");
		a.setNodeAttribute(n, "width", "1.25");

		a.addEdge(m, n);

		n = a.addNode();
		n.set(DotAdapter.DOT_ID, "Aap");
		n.set(DotAdapter.DOT_LABEL, "Aap");

		m = a.addNode();
		m.set(DotAdapter.DOT_ID, "Noot");
		m.set(DotAdapter.DOT_LABEL, "Noot");

		a.addEdge(m, n);
		a.addEdge(m, n);
		a.printDot(System.err);
		a.doDotLayout();
		return;
	}

	
}
