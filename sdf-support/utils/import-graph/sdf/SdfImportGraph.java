package sdf;

import java.io.IOException;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import nl.cwi.sen.api.graph.graph.Factory;
import nl.cwi.sen.api.graph.graph.types.Attribute;
import nl.cwi.sen.api.graph.graph.types.AttributeList;
import nl.cwi.sen.api.graph.graph.types.Edge;
import nl.cwi.sen.api.graph.graph.types.EdgeList;
import nl.cwi.sen.api.graph.graph.types.Graph;
import nl.cwi.sen.api.graph.graph.types.Node;
import nl.cwi.sen.api.graph.graph.types.NodeId;
import nl.cwi.sen.api.graph.graph.types.NodeList;
import nl.cwi.sen.api.graph.graph.types.Shape;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class SdfImportGraph implements SdfImportGraphTif {
	private static PureFactory factory;
	private static Factory graphFactory;
	private static SdfImportGraphBridge bridge;

	public static void main(String[] args) throws IOException {
		factory = new PureFactory();
		graphFactory = new Factory(factory);
		new SdfImportGraph(args);
	}

	private SdfImportGraph(String[] args) throws IOException {

		bridge = new SdfImportGraphBridge(factory, this);
		bridge.init(args);
		bridge.connect();
		bridge.run();
	}

	public static Graph fromImportList(ATermList imports) {
		Set nodeSet = new HashSet();
		List nodeSequence = new LinkedList();

		EdgeList edges = graphFactory.makeEdgeList_Empty();

		while (!imports.isEmpty()) {
			ATermList pair = (ATermList) imports.getFirst();
			imports = imports.getNext();

			ATerm fromTerm = pair.getFirst();
			if (nodeSet.add(fromTerm)) {
				nodeSequence.add(fromTerm);
			}
			ATermList elems = (ATermList) pair.getNext().getFirst();

			while (!elems.isEmpty()) {
				ATerm toTerm = elems.getFirst();
				elems = elems.getNext();

				NodeId from = graphFactory.NodeIdFromTerm(fromTerm);
				NodeId to = graphFactory.NodeIdFromTerm(toTerm);

				if (nodeSet.add(toTerm)) {
					nodeSequence.add(toTerm);
				}

				AttributeList attrs = graphFactory.makeAttributeList_Empty();
				Edge edge = graphFactory.makeEdge_Default(from, to, attrs);
				edges = graphFactory.makeEdgeList_Multi(edge, edges);
			}
		}

		NodeList nodes = graphFactory.makeNodeList_Empty();

		Iterator iter = nodeSequence.iterator();
		while (iter.hasNext()) {
			ATerm name = (ATerm) iter.next();
			NodeId id = graphFactory.NodeIdFromTerm(name);
			Shape shape = graphFactory.makeShape_Box();
			Attribute shapeAttr = graphFactory.makeAttribute_Shape(shape);
			Attribute labelAttr = graphFactory
					.makeAttribute_Label(makeLabel(name));
			AttributeList attrs = graphFactory.makeAttributeList_Empty();
			attrs = graphFactory.makeAttributeList_Multi(shapeAttr, attrs);
			attrs = graphFactory.makeAttributeList_Multi(labelAttr, attrs);
			Node node = graphFactory.makeNode_Default(id, attrs);
			nodes = graphFactory.makeNodeList_Multi(node, nodes);
		}

		return graphFactory.makeGraph_Default(nodes, edges, graphFactory
				.makeAttributeList_Empty());
	}

	private static String makeLabel(ATerm name) {
		String label = ((ATermAppl) name).getName();
		int index = label.lastIndexOf('/');

		if (index != -1) {
			return label.substring(index + 1);
		} else {
			return label;
		}
	}

	public ATerm importRelationToGraph(ATerm importRelation) {
		Graph importGraph = fromImportList((ATermList) importRelation);
		return factory.make("snd-value(graph(<term>))", importGraph.toTerm());
	}

	public void recTerminate(ATerm t0) {

	}
}
