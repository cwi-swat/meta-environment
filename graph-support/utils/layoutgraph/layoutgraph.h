#ifndef LAYOUTGRAPH_H
#define LAYOUTGRAPH_H

#include <Graph.h>

Graph layoutGraph(Graph graph);

void protectTerm(ATerm term);
AFun getAttributeType(Attribute attr);
void mergeNodeAttributes(NodeId nodeId, AttributeList attrs);
void mergeEdgeAttributes(NodeId from, NodeId to, AttributeList attrs);

#endif
