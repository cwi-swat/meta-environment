#ifndef _GRAPH_H
#define _GRAPH_H

/*{{{  includes */

#include <aterm1.h>
#include "Graph_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _Graph *Graph;
typedef struct _NodeList *NodeList;
typedef struct _Node *Node;
typedef struct _EdgeList *EdgeList;
typedef struct _Edge *Edge;
typedef struct _Polygon *Polygon;
typedef struct _Point *Point;

/*}}}  */

void initGraphApi(void);

/*{{{  term conversion functions */

Graph GraphFromTerm(ATerm t);
ATerm GraphToTerm(Graph arg);
NodeList NodeListFromTerm(ATerm t);
ATerm NodeListToTerm(NodeList arg);
Node NodeFromTerm(ATerm t);
ATerm NodeToTerm(Node arg);
EdgeList EdgeListFromTerm(ATerm t);
ATerm EdgeListToTerm(EdgeList arg);
Edge EdgeFromTerm(ATerm t);
ATerm EdgeToTerm(Edge arg);
Polygon PolygonFromTerm(ATerm t);
ATerm PolygonToTerm(Polygon arg);
Point PointFromTerm(ATerm t);
ATerm PointToTerm(Point arg);

/*}}}  */
/*{{{  constructors */

Graph makeGraphDefault(NodeList nodes, EdgeList edges);
NodeList makeNodeListEmpty();
NodeList makeNodeListMulti(Node head, NodeList tail);
Node makeNodeUnpositioned(char * name, int width, int height);
Node makeNodePositioned(char * name, int x, int y, int width, int height);
EdgeList makeEdgeListEmpty();
EdgeList makeEdgeListMulti(Edge head, EdgeList tail);
Edge makeEdgeUnpositioned(char * from, char * to);
Edge makeEdgePositioned(char * from, char * to, Polygon polygon);
Polygon makePolygonEmpty();
Polygon makePolygonMulti(Point head, Polygon tail);
Point makePointDefault(int x, int y);

/*}}}  */
/*{{{  equality functions */

ATbool isEqualGraph(Graph arg0, Graph arg1);
ATbool isEqualNodeList(NodeList arg0, NodeList arg1);
ATbool isEqualNode(Node arg0, Node arg1);
ATbool isEqualEdgeList(EdgeList arg0, EdgeList arg1);
ATbool isEqualEdge(Edge arg0, Edge arg1);
ATbool isEqualPolygon(Polygon arg0, Polygon arg1);
ATbool isEqualPoint(Point arg0, Point arg1);

/*}}}  */
/*{{{  Graph accessors */

ATbool isValidGraph(Graph arg);
inline ATbool isGraphDefault(Graph arg);
ATbool hasGraphNodes(Graph arg);
NodeList getGraphNodes(Graph arg);
Graph setGraphNodes(Graph arg, NodeList nodes);
ATbool hasGraphEdges(Graph arg);
EdgeList getGraphEdges(Graph arg);
Graph setGraphEdges(Graph arg, EdgeList edges);

/*}}}  */
/*{{{  NodeList accessors */

ATbool isValidNodeList(NodeList arg);
inline ATbool isNodeListEmpty(NodeList arg);
inline ATbool isNodeListMulti(NodeList arg);
ATbool hasNodeListHead(NodeList arg);
Node getNodeListHead(NodeList arg);
NodeList setNodeListHead(NodeList arg, Node head);
ATbool hasNodeListTail(NodeList arg);
NodeList getNodeListTail(NodeList arg);
NodeList setNodeListTail(NodeList arg, NodeList tail);

/*}}}  */
/*{{{  Node accessors */

ATbool isValidNode(Node arg);
inline ATbool isNodeUnpositioned(Node arg);
inline ATbool isNodePositioned(Node arg);
ATbool hasNodeName(Node arg);
char * getNodeName(Node arg);
Node setNodeName(Node arg, char * name);
ATbool hasNodeWidth(Node arg);
int getNodeWidth(Node arg);
Node setNodeWidth(Node arg, int width);
ATbool hasNodeHeight(Node arg);
int getNodeHeight(Node arg);
Node setNodeHeight(Node arg, int height);
ATbool hasNodeX(Node arg);
int getNodeX(Node arg);
Node setNodeX(Node arg, int x);
ATbool hasNodeY(Node arg);
int getNodeY(Node arg);
Node setNodeY(Node arg, int y);

/*}}}  */
/*{{{  EdgeList accessors */

ATbool isValidEdgeList(EdgeList arg);
inline ATbool isEdgeListEmpty(EdgeList arg);
inline ATbool isEdgeListMulti(EdgeList arg);
ATbool hasEdgeListHead(EdgeList arg);
Edge getEdgeListHead(EdgeList arg);
EdgeList setEdgeListHead(EdgeList arg, Edge head);
ATbool hasEdgeListTail(EdgeList arg);
EdgeList getEdgeListTail(EdgeList arg);
EdgeList setEdgeListTail(EdgeList arg, EdgeList tail);

/*}}}  */
/*{{{  Edge accessors */

ATbool isValidEdge(Edge arg);
inline ATbool isEdgeUnpositioned(Edge arg);
inline ATbool isEdgePositioned(Edge arg);
ATbool hasEdgeFrom(Edge arg);
char * getEdgeFrom(Edge arg);
Edge setEdgeFrom(Edge arg, char * from);
ATbool hasEdgeTo(Edge arg);
char * getEdgeTo(Edge arg);
Edge setEdgeTo(Edge arg, char * to);
ATbool hasEdgePolygon(Edge arg);
Polygon getEdgePolygon(Edge arg);
Edge setEdgePolygon(Edge arg, Polygon polygon);

/*}}}  */
/*{{{  Polygon accessors */

ATbool isValidPolygon(Polygon arg);
inline ATbool isPolygonEmpty(Polygon arg);
inline ATbool isPolygonMulti(Polygon arg);
ATbool hasPolygonHead(Polygon arg);
Point getPolygonHead(Polygon arg);
Polygon setPolygonHead(Polygon arg, Point head);
ATbool hasPolygonTail(Polygon arg);
Polygon getPolygonTail(Polygon arg);
Polygon setPolygonTail(Polygon arg, Polygon tail);

/*}}}  */
/*{{{  Point accessors */

ATbool isValidPoint(Point arg);
inline ATbool isPointDefault(Point arg);
ATbool hasPointX(Point arg);
int getPointX(Point arg);
Point setPointX(Point arg, int x);
ATbool hasPointY(Point arg);
int getPointY(Point arg);
Point setPointY(Point arg, int y);

/*}}}  */
/*{{{  sort visitors */

Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList));
NodeList visitNodeList(NodeList arg, Node (*acceptHead)(Node));
Node visitNode(Node arg, char * (*acceptName)(char *), int (*acceptWidth)(int), int (*acceptHeight)(int), int (*acceptX)(int), int (*acceptY)(int));
EdgeList visitEdgeList(EdgeList arg, Edge (*acceptHead)(Edge));
Edge visitEdge(Edge arg, char * (*acceptFrom)(char *), char * (*acceptTo)(char *), Polygon (*acceptPolygon)(Polygon));
Polygon visitPolygon(Polygon arg, Point (*acceptHead)(Point));
Point visitPoint(Point arg, int (*acceptX)(int), int (*acceptY)(int));

/*}}}  */

#endif /* _GRAPH_H */
