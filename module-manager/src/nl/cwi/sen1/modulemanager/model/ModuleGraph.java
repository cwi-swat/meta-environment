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
        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            boolean shapeSet = false;
            ModuleId moduleId = iter.next();
            NodeId nodeId = factory.makeNodeId_Default(moduleId.toTerm());

            Module module = modules.get(moduleId);
            AttributeList attrList = factory.makeAttributeList();

            AttributeTable table = module.getAttributes(namespace);
            if (table != null) {
                Map<ATerm, ATerm> entries = table.getEntries();
                
                for (Iterator<ATerm> iterEntries = entries.keySet().iterator(); iterEntries
                        .hasNext();) {
                    ATerm value = entries.get(iterEntries.next());

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
        for (Iterator<ModuleId> iter = children.keySet().iterator(); iter
                .hasNext();) {
            ModuleId moduleId = iter.next();
            NodeId nodeFromId = factory.makeNodeId_Default(moduleId.toTerm());

            Set<ModuleId> dependingModules = children.get(moduleId);

            for (Iterator<ModuleId> depsIter = dependingModules.iterator(); depsIter
                    .hasNext();) {
                NodeId nodeToId = factory.makeNodeId_Default(iter.next()
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
