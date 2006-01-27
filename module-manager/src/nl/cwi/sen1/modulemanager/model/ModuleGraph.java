package nl.cwi.sen1.modulemanager.model;

import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.graph.Factory;
import nl.cwi.sen1.graph.types.Attribute;
import nl.cwi.sen1.graph.types.AttributeList;
import nl.cwi.sen1.graph.types.Edge;
import nl.cwi.sen1.graph.types.EdgeList;
import nl.cwi.sen1.graph.types.Graph;
import nl.cwi.sen1.graph.types.Node;
import nl.cwi.sen1.graph.types.NodeId;
import nl.cwi.sen1.graph.types.NodeList;
import nl.cwi.sen1.graph.types.Shape;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import aterm.ATerm;
import aterm.pure.PureFactory;

public class ModuleGraph extends ModuleDatabase {
	private NodeList nodeList;

	private EdgeList edgeList;

	private Factory factory;

	public ModuleGraph(PureFactory pureFactory, AttributeSetListener l) {
		super(l);
		factory = Factory.getInstance(pureFactory);
	}

	private void setNodes(ATerm namespace) {
		for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
			boolean shapeSet = false;
			ModuleId moduleId = (ModuleId) iter.next();
			NodeId nodeId = factory.makeNodeId_Default(moduleId.toTerm());

			Module module = (Module) modules.get(moduleId);
			AttributeList attrList = factory.makeAttributeList();

			AttributeTable table = module.getAttributes(namespace);
			if (table != null) {
				Map entries = table.getEntries();

				for (Iterator iterEntries = entries.keySet().iterator(); iterEntries
						.hasNext();) {
					ATerm key = (ATerm) iterEntries.next();
					ATerm value = (ATerm) entries.get(key);

					try {
						Attribute attr = factory.AttributeFromTerm(value);
						attrList = attrList.insert(attr);

						if (attr.isShape()) {
							shapeSet = true;
						}
					} catch (IllegalArgumentException exc) {
						System.err.println("Illegal graph attribute: " + value);
					}
				}

			}

			if (!shapeSet) {
				Shape shape = factory.makeShape_Box();
				attrList = attrList.insert(factory.makeAttribute_Shape(shape));
			}

			Node node = factory.makeNode_Default(nodeId, attrList);
			nodeList = nodeList.insert(node);
		}
	}

	private void setEdges() {
		for (Iterator iter = children.keySet().iterator(); iter.hasNext();) {
			ModuleId moduleId = (ModuleId) iter.next();
			NodeId nodeFromId = factory.makeNodeId_Default(moduleId.toTerm());

			Set dependingModules = (Set) children.get(moduleId);

			for (Iterator depsIter = dependingModules.iterator(); depsIter
					.hasNext();) {
				ModuleId dependencyId = (ModuleId) depsIter.next();
				NodeId nodeToId = factory.makeNodeId_Default(dependencyId
						.toTerm());

				Edge edge = factory.makeEdge_Default(nodeFromId, nodeToId,
						factory.makeAttributeList());

				edgeList = edgeList.insert(edge);
			}
		}
	}

	public Graph getModuleGraph(ATerm namespace) {
		nodeList = factory.makeNodeList();
		edgeList = factory.makeEdgeList();

		setNodes(namespace);
		setEdges();
		AttributeList attrList = factory.makeAttributeList();

		return factory.makeGraph_Default(nodeList, edgeList, attrList);
	}
}
