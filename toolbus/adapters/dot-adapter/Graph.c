#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Graph.h"

/*{{{  typedefs */

typedef struct ATerm _Graph;
typedef struct ATerm _NodeList;
typedef struct ATerm _Node;
typedef struct ATerm _EdgeList;
typedef struct ATerm _Edge;
typedef struct ATerm _Polygon;
typedef struct ATerm _Point;

/*}}}  */

/*{{{  void initGraphApi(void) */

void initGraphApi(void)
{
  init_Graph_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  Graph GraphFromTerm(ATerm t) */

Graph GraphFromTerm(ATerm t)
{
  return (Graph)t;
}

/*}}}  */
/*{{{  ATerm GraphToTerm(Graph arg) */

ATerm GraphToTerm(Graph arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  NodeList NodeListFromTerm(ATerm t) */

NodeList NodeListFromTerm(ATerm t)
{
  return (NodeList)t;
}

/*}}}  */
/*{{{  ATerm NodeListToTerm(NodeList arg) */

ATerm NodeListToTerm(NodeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Node NodeFromTerm(ATerm t) */

Node NodeFromTerm(ATerm t)
{
  return (Node)t;
}

/*}}}  */
/*{{{  ATerm NodeToTerm(Node arg) */

ATerm NodeToTerm(Node arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  EdgeList EdgeListFromTerm(ATerm t) */

EdgeList EdgeListFromTerm(ATerm t)
{
  return (EdgeList)t;
}

/*}}}  */
/*{{{  ATerm EdgeListToTerm(EdgeList arg) */

ATerm EdgeListToTerm(EdgeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Edge EdgeFromTerm(ATerm t) */

Edge EdgeFromTerm(ATerm t)
{
  return (Edge)t;
}

/*}}}  */
/*{{{  ATerm EdgeToTerm(Edge arg) */

ATerm EdgeToTerm(Edge arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Polygon PolygonFromTerm(ATerm t) */

Polygon PolygonFromTerm(ATerm t)
{
  return (Polygon)t;
}

/*}}}  */
/*{{{  ATerm PolygonToTerm(Polygon arg) */

ATerm PolygonToTerm(Polygon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Point PointFromTerm(ATerm t) */

Point PointFromTerm(ATerm t)
{
  return (Point)t;
}

/*}}}  */
/*{{{  ATerm PointToTerm(Point arg) */

ATerm PointToTerm(Point arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  Graph makeGraphDefault(NodeList nodes, EdgeList edges) */

Graph makeGraphDefault(NodeList nodes, EdgeList edges)
{
  return (Graph)(ATerm)ATmakeAppl2(afun0, (ATerm)nodes, (ATerm)edges);
}

/*}}}  */
/*{{{  NodeList makeNodeListEmpty() */

NodeList makeNodeListEmpty()
{
  return (NodeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  NodeList makeNodeListMulti(Node head, NodeList tail) */

NodeList makeNodeListMulti(Node head, NodeList tail)
{
  return (NodeList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  Node makeNodeUnpositioned(char * name, int width, int height) */

Node makeNodeUnpositioned(char * name, int width, int height)
{
  return (Node)(ATerm)ATmakeAppl3(afun1, (ATerm)ATmakeAppl0(ATmakeAFun(name, 0, ATtrue)), (ATerm)ATmakeInt(width), (ATerm)ATmakeInt(height));
}

/*}}}  */
/*{{{  Node makeNodePositioned(char * name, int x, int y, int width, int height) */

Node makeNodePositioned(char * name, int x, int y, int width, int height)
{
  return (Node)(ATerm)ATmakeAppl5(afun2, (ATerm)ATmakeAppl0(ATmakeAFun(name, 0, ATtrue)), (ATerm)ATmakeInt(x), (ATerm)ATmakeInt(y), (ATerm)ATmakeInt(width), (ATerm)ATmakeInt(height));
}

/*}}}  */
/*{{{  EdgeList makeEdgeListEmpty() */

EdgeList makeEdgeListEmpty()
{
  return (EdgeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  EdgeList makeEdgeListMulti(Edge head, EdgeList tail) */

EdgeList makeEdgeListMulti(Edge head, EdgeList tail)
{
  return (EdgeList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  Edge makeEdgeUnpositioned(char * from, char * to) */

Edge makeEdgeUnpositioned(char * from, char * to)
{
  return (Edge)(ATerm)ATmakeAppl2(afun3, (ATerm)ATmakeAppl0(ATmakeAFun(from, 0, ATtrue)), (ATerm)ATmakeAppl0(ATmakeAFun(to, 0, ATtrue)));
}

/*}}}  */
/*{{{  Edge makeEdgePositioned(char * from, char * to, Polygon polygon) */

Edge makeEdgePositioned(char * from, char * to, Polygon polygon)
{
  return (Edge)(ATerm)ATmakeAppl3(afun4, (ATerm)ATmakeAppl0(ATmakeAFun(from, 0, ATtrue)), (ATerm)ATmakeAppl0(ATmakeAFun(to, 0, ATtrue)), (ATerm)polygon);
}

/*}}}  */
/*{{{  Polygon makePolygonEmpty() */

Polygon makePolygonEmpty()
{
  return (Polygon)(ATerm)ATempty;
}

/*}}}  */
/*{{{  Polygon makePolygonMulti(Point head, Polygon tail) */

Polygon makePolygonMulti(Point head, Polygon tail)
{
  return (Polygon)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  Point makePointDefault(int x, int y) */

Point makePointDefault(int x, int y)
{
  return (Point)(ATerm)ATmakeAppl2(afun5, (ATerm)ATmakeInt(x), (ATerm)ATmakeInt(y));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool isEqualGraph(Graph arg0, Graph arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualNodeList(NodeList arg0, NodeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualNode(Node arg0, Node arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualEdgeList(EdgeList arg0, EdgeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualEdge(Edge arg0, Edge arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualPolygon(Polygon arg0, Polygon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualPoint(Point arg0, Point arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  Graph accessors */

/*{{{  ATbool isValidGraph(Graph arg) */

ATbool isValidGraph(Graph arg)
{
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isGraphDefault(Graph arg) */

inline ATbool isGraphDefault(Graph arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternGraphDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasGraphNodes(Graph arg) */

ATbool hasGraphNodes(Graph arg)
{
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  NodeList getGraphNodes(Graph arg) */

NodeList getGraphNodes(Graph arg)
{
  
    return (NodeList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Graph setGraphNodes(Graph arg, NodeList nodes) */

Graph setGraphNodes(Graph arg, NodeList nodes)
{
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)nodes, 0);
  }

  ATabort("Graph has no Nodes: %t\n", arg);
  return (Graph)NULL;
}

/*}}}  */
/*{{{  ATbool hasGraphEdges(Graph arg) */

ATbool hasGraphEdges(Graph arg)
{
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  EdgeList getGraphEdges(Graph arg) */

EdgeList getGraphEdges(Graph arg)
{
  
    return (EdgeList)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  Graph setGraphEdges(Graph arg, EdgeList edges) */

Graph setGraphEdges(Graph arg, EdgeList edges)
{
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)edges, 1);
  }

  ATabort("Graph has no Edges: %t\n", arg);
  return (Graph)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  NodeList accessors */

/*{{{  ATbool isValidNodeList(NodeList arg) */

ATbool isValidNodeList(NodeList arg)
{
  if (isNodeListEmpty(arg)) {
    return ATtrue;
  }
  else if (isNodeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isNodeListEmpty(NodeList arg) */

inline ATbool isNodeListEmpty(NodeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternNodeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool isNodeListMulti(NodeList arg) */

inline ATbool isNodeListMulti(NodeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternNodeListMulti, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasNodeListHead(NodeList arg) */

ATbool hasNodeListHead(NodeList arg)
{
  if (isNodeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Node getNodeListHead(NodeList arg) */

Node getNodeListHead(NodeList arg)
{
  
    return (Node)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  NodeList setNodeListHead(NodeList arg, Node head) */

NodeList setNodeListHead(NodeList arg, Node head)
{
  if (isNodeListMulti(arg)) {
    return (NodeList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("NodeList has no Head: %t\n", arg);
  return (NodeList)NULL;
}

/*}}}  */
/*{{{  ATbool hasNodeListTail(NodeList arg) */

ATbool hasNodeListTail(NodeList arg)
{
  if (isNodeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  NodeList getNodeListTail(NodeList arg) */

NodeList getNodeListTail(NodeList arg)
{
  
    return (NodeList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  NodeList setNodeListTail(NodeList arg, NodeList tail) */

NodeList setNodeListTail(NodeList arg, NodeList tail)
{
  if (isNodeListMulti(arg)) {
    return (NodeList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("NodeList has no Tail: %t\n", arg);
  return (NodeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  Node accessors */

/*{{{  ATbool isValidNode(Node arg) */

ATbool isValidNode(Node arg)
{
  if (isNodeUnpositioned(arg)) {
    return ATtrue;
  }
  else if (isNodePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isNodeUnpositioned(Node arg) */

inline ATbool isNodeUnpositioned(Node arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(patternNodeUnpositioned)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternNodeUnpositioned, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool isNodePositioned(Node arg) */

inline ATbool isNodePositioned(Node arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(patternNodePositioned)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternNodePositioned, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasNodeName(Node arg) */

ATbool hasNodeName(Node arg)
{
  if (isNodeUnpositioned(arg)) {
    return ATtrue;
  }
  else if (isNodePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * getNodeName(Node arg) */

char * getNodeName(Node arg)
{
  if (isNodeUnpositioned(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  Node setNodeName(Node arg, char * name) */

Node setNodeName(Node arg, char * name)
{
  if (isNodeUnpositioned(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(name, 0, ATtrue)), 0);
  }
  else if (isNodePositioned(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(name, 0, ATtrue)), 0);
  }

  ATabort("Node has no Name: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */
/*{{{  ATbool hasNodeWidth(Node arg) */

ATbool hasNodeWidth(Node arg)
{
  if (isNodeUnpositioned(arg)) {
    return ATtrue;
  }
  else if (isNodePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getNodeWidth(Node arg) */

int getNodeWidth(Node arg)
{
  if (isNodeUnpositioned(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  Node setNodeWidth(Node arg, int width) */

Node setNodeWidth(Node arg, int width)
{
  if (isNodeUnpositioned(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(width), 1);
  }
  else if (isNodePositioned(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(width), 3);
  }

  ATabort("Node has no Width: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */
/*{{{  ATbool hasNodeHeight(Node arg) */

ATbool hasNodeHeight(Node arg)
{
  if (isNodeUnpositioned(arg)) {
    return ATtrue;
  }
  else if (isNodePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getNodeHeight(Node arg) */

int getNodeHeight(Node arg)
{
  if (isNodeUnpositioned(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 2));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 4));
}

/*}}}  */
/*{{{  Node setNodeHeight(Node arg, int height) */

Node setNodeHeight(Node arg, int height)
{
  if (isNodeUnpositioned(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(height), 2);
  }
  else if (isNodePositioned(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(height), 4);
  }

  ATabort("Node has no Height: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */
/*{{{  ATbool hasNodeX(Node arg) */

ATbool hasNodeX(Node arg)
{
  if (isNodePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getNodeX(Node arg) */

int getNodeX(Node arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  Node setNodeX(Node arg, int x) */

Node setNodeX(Node arg, int x)
{
  if (isNodePositioned(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(x), 1);
  }

  ATabort("Node has no X: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */
/*{{{  ATbool hasNodeY(Node arg) */

ATbool hasNodeY(Node arg)
{
  if (isNodePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getNodeY(Node arg) */

int getNodeY(Node arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  Node setNodeY(Node arg, int y) */

Node setNodeY(Node arg, int y)
{
  if (isNodePositioned(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(y), 2);
  }

  ATabort("Node has no Y: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  EdgeList accessors */

/*{{{  ATbool isValidEdgeList(EdgeList arg) */

ATbool isValidEdgeList(EdgeList arg)
{
  if (isEdgeListEmpty(arg)) {
    return ATtrue;
  }
  else if (isEdgeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isEdgeListEmpty(EdgeList arg) */

inline ATbool isEdgeListEmpty(EdgeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternEdgeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool isEdgeListMulti(EdgeList arg) */

inline ATbool isEdgeListMulti(EdgeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternEdgeListMulti, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasEdgeListHead(EdgeList arg) */

ATbool hasEdgeListHead(EdgeList arg)
{
  if (isEdgeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Edge getEdgeListHead(EdgeList arg) */

Edge getEdgeListHead(EdgeList arg)
{
  
    return (Edge)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  EdgeList setEdgeListHead(EdgeList arg, Edge head) */

EdgeList setEdgeListHead(EdgeList arg, Edge head)
{
  if (isEdgeListMulti(arg)) {
    return (EdgeList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("EdgeList has no Head: %t\n", arg);
  return (EdgeList)NULL;
}

/*}}}  */
/*{{{  ATbool hasEdgeListTail(EdgeList arg) */

ATbool hasEdgeListTail(EdgeList arg)
{
  if (isEdgeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  EdgeList getEdgeListTail(EdgeList arg) */

EdgeList getEdgeListTail(EdgeList arg)
{
  
    return (EdgeList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  EdgeList setEdgeListTail(EdgeList arg, EdgeList tail) */

EdgeList setEdgeListTail(EdgeList arg, EdgeList tail)
{
  if (isEdgeListMulti(arg)) {
    return (EdgeList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("EdgeList has no Tail: %t\n", arg);
  return (EdgeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  Edge accessors */

/*{{{  ATbool isValidEdge(Edge arg) */

ATbool isValidEdge(Edge arg)
{
  if (isEdgeUnpositioned(arg)) {
    return ATtrue;
  }
  else if (isEdgePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isEdgeUnpositioned(Edge arg) */

inline ATbool isEdgeUnpositioned(Edge arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(patternEdgeUnpositioned)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternEdgeUnpositioned, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool isEdgePositioned(Edge arg) */

inline ATbool isEdgePositioned(Edge arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(patternEdgePositioned)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternEdgePositioned, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasEdgeFrom(Edge arg) */

ATbool hasEdgeFrom(Edge arg)
{
  if (isEdgeUnpositioned(arg)) {
    return ATtrue;
  }
  else if (isEdgePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * getEdgeFrom(Edge arg) */

char * getEdgeFrom(Edge arg)
{
  if (isEdgeUnpositioned(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  Edge setEdgeFrom(Edge arg, char * from) */

Edge setEdgeFrom(Edge arg, char * from)
{
  if (isEdgeUnpositioned(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(from, 0, ATtrue)), 0);
  }
  else if (isEdgePositioned(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(from, 0, ATtrue)), 0);
  }

  ATabort("Edge has no From: %t\n", arg);
  return (Edge)NULL;
}

/*}}}  */
/*{{{  ATbool hasEdgeTo(Edge arg) */

ATbool hasEdgeTo(Edge arg)
{
  if (isEdgeUnpositioned(arg)) {
    return ATtrue;
  }
  else if (isEdgePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * getEdgeTo(Edge arg) */

char * getEdgeTo(Edge arg)
{
  if (isEdgeUnpositioned(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 1)));
  }
  else 
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  Edge setEdgeTo(Edge arg, char * to) */

Edge setEdgeTo(Edge arg, char * to)
{
  if (isEdgeUnpositioned(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(to, 0, ATtrue)), 1);
  }
  else if (isEdgePositioned(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(to, 0, ATtrue)), 1);
  }

  ATabort("Edge has no To: %t\n", arg);
  return (Edge)NULL;
}

/*}}}  */
/*{{{  ATbool hasEdgePolygon(Edge arg) */

ATbool hasEdgePolygon(Edge arg)
{
  if (isEdgePositioned(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Polygon getEdgePolygon(Edge arg) */

Polygon getEdgePolygon(Edge arg)
{
  
    return (Polygon)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  Edge setEdgePolygon(Edge arg, Polygon polygon) */

Edge setEdgePolygon(Edge arg, Polygon polygon)
{
  if (isEdgePositioned(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)polygon, 2);
  }

  ATabort("Edge has no Polygon: %t\n", arg);
  return (Edge)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  Polygon accessors */

/*{{{  ATbool isValidPolygon(Polygon arg) */

ATbool isValidPolygon(Polygon arg)
{
  if (isPolygonEmpty(arg)) {
    return ATtrue;
  }
  else if (isPolygonMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isPolygonEmpty(Polygon arg) */

inline ATbool isPolygonEmpty(Polygon arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternPolygonEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool isPolygonMulti(Polygon arg) */

inline ATbool isPolygonMulti(Polygon arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternPolygonMulti, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasPolygonHead(Polygon arg) */

ATbool hasPolygonHead(Polygon arg)
{
  if (isPolygonMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Point getPolygonHead(Polygon arg) */

Point getPolygonHead(Polygon arg)
{
  
    return (Point)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  Polygon setPolygonHead(Polygon arg, Point head) */

Polygon setPolygonHead(Polygon arg, Point head)
{
  if (isPolygonMulti(arg)) {
    return (Polygon)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Polygon has no Head: %t\n", arg);
  return (Polygon)NULL;
}

/*}}}  */
/*{{{  ATbool hasPolygonTail(Polygon arg) */

ATbool hasPolygonTail(Polygon arg)
{
  if (isPolygonMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Polygon getPolygonTail(Polygon arg) */

Polygon getPolygonTail(Polygon arg)
{
  
    return (Polygon)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  Polygon setPolygonTail(Polygon arg, Polygon tail) */

Polygon setPolygonTail(Polygon arg, Polygon tail)
{
  if (isPolygonMulti(arg)) {
    return (Polygon)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Polygon has no Tail: %t\n", arg);
  return (Polygon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  Point accessors */

/*{{{  ATbool isValidPoint(Point arg) */

ATbool isValidPoint(Point arg)
{
  if (isPointDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isPointDefault(Point arg) */

inline ATbool isPointDefault(Point arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternPointDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasPointX(Point arg) */

ATbool hasPointX(Point arg)
{
  if (isPointDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getPointX(Point arg) */

int getPointX(Point arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  Point setPointX(Point arg, int x) */

Point setPointX(Point arg, int x)
{
  if (isPointDefault(arg)) {
    return (Point)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(x), 0);
  }

  ATabort("Point has no X: %t\n", arg);
  return (Point)NULL;
}

/*}}}  */
/*{{{  ATbool hasPointY(Point arg) */

ATbool hasPointY(Point arg)
{
  if (isPointDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getPointY(Point arg) */

int getPointY(Point arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  Point setPointY(Point arg, int y) */

Point setPointY(Point arg, int y)
{
  if (isPointDefault(arg)) {
    return (Point)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(y), 1);
  }

  ATabort("Point has no Y: %t\n", arg);
  return (Point)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList)) */

Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList))
{
  if (isGraphDefault(arg)) {
    return makeGraphDefault(
        acceptNodes ? acceptNodes(getGraphNodes(arg)) : getGraphNodes(arg),
        acceptEdges ? acceptEdges(getGraphEdges(arg)) : getGraphEdges(arg));
  }
  ATabort("not a Graph: %t\n", arg);
  return (Graph)NULL;
}

/*}}}  */
/*{{{  NodeList visitNodeList(NodeList arg, Node (*acceptHead)(Node)) */

NodeList visitNodeList(NodeList arg, Node (*acceptHead)(Node))
{
  if (isNodeListEmpty(arg)) {
    return makeNodeListEmpty();
  }
  if (isNodeListMulti(arg)) {
    return makeNodeListMulti(
        acceptHead ? acceptHead(getNodeListHead(arg)) : getNodeListHead(arg),
        visitNodeList(getNodeListTail(arg), acceptHead));
  }
  ATabort("not a NodeList: %t\n", arg);
  return (NodeList)NULL;
}

/*}}}  */
/*{{{  Node visitNode(Node arg, char * (*acceptName)(char *), int (*acceptWidth)(int), int (*acceptHeight)(int), int (*acceptX)(int), int (*acceptY)(int)) */

Node visitNode(Node arg, char * (*acceptName)(char *), int (*acceptWidth)(int), int (*acceptHeight)(int), int (*acceptX)(int), int (*acceptY)(int))
{
  if (isNodeUnpositioned(arg)) {
    return makeNodeUnpositioned(
        acceptName ? acceptName(getNodeName(arg)) : getNodeName(arg),
        acceptWidth ? acceptWidth(getNodeWidth(arg)) : getNodeWidth(arg),
        acceptHeight ? acceptHeight(getNodeHeight(arg)) : getNodeHeight(arg));
  }
  if (isNodePositioned(arg)) {
    return makeNodePositioned(
        acceptName ? acceptName(getNodeName(arg)) : getNodeName(arg),
        acceptX ? acceptX(getNodeX(arg)) : getNodeX(arg),
        acceptY ? acceptY(getNodeY(arg)) : getNodeY(arg),
        acceptWidth ? acceptWidth(getNodeWidth(arg)) : getNodeWidth(arg),
        acceptHeight ? acceptHeight(getNodeHeight(arg)) : getNodeHeight(arg));
  }
  ATabort("not a Node: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */
/*{{{  EdgeList visitEdgeList(EdgeList arg, Edge (*acceptHead)(Edge)) */

EdgeList visitEdgeList(EdgeList arg, Edge (*acceptHead)(Edge))
{
  if (isEdgeListEmpty(arg)) {
    return makeEdgeListEmpty();
  }
  if (isEdgeListMulti(arg)) {
    return makeEdgeListMulti(
        acceptHead ? acceptHead(getEdgeListHead(arg)) : getEdgeListHead(arg),
        visitEdgeList(getEdgeListTail(arg), acceptHead));
  }
  ATabort("not a EdgeList: %t\n", arg);
  return (EdgeList)NULL;
}

/*}}}  */
/*{{{  Edge visitEdge(Edge arg, char * (*acceptFrom)(char *), char * (*acceptTo)(char *), Polygon (*acceptPolygon)(Polygon)) */

Edge visitEdge(Edge arg, char * (*acceptFrom)(char *), char * (*acceptTo)(char *), Polygon (*acceptPolygon)(Polygon))
{
  if (isEdgeUnpositioned(arg)) {
    return makeEdgeUnpositioned(
        acceptFrom ? acceptFrom(getEdgeFrom(arg)) : getEdgeFrom(arg),
        acceptTo ? acceptTo(getEdgeTo(arg)) : getEdgeTo(arg));
  }
  if (isEdgePositioned(arg)) {
    return makeEdgePositioned(
        acceptFrom ? acceptFrom(getEdgeFrom(arg)) : getEdgeFrom(arg),
        acceptTo ? acceptTo(getEdgeTo(arg)) : getEdgeTo(arg),
        acceptPolygon ? acceptPolygon(getEdgePolygon(arg)) : getEdgePolygon(arg));
  }
  ATabort("not a Edge: %t\n", arg);
  return (Edge)NULL;
}

/*}}}  */
/*{{{  Polygon visitPolygon(Polygon arg, Point (*acceptHead)(Point)) */

Polygon visitPolygon(Polygon arg, Point (*acceptHead)(Point))
{
  if (isPolygonEmpty(arg)) {
    return makePolygonEmpty();
  }
  if (isPolygonMulti(arg)) {
    return makePolygonMulti(
        acceptHead ? acceptHead(getPolygonHead(arg)) : getPolygonHead(arg),
        visitPolygon(getPolygonTail(arg), acceptHead));
  }
  ATabort("not a Polygon: %t\n", arg);
  return (Polygon)NULL;
}

/*}}}  */
/*{{{  Point visitPoint(Point arg, int (*acceptX)(int), int (*acceptY)(int)) */

Point visitPoint(Point arg, int (*acceptX)(int), int (*acceptY)(int))
{
  if (isPointDefault(arg)) {
    return makePointDefault(
        acceptX ? acceptX(getPointX(arg)) : getPointX(arg),
        acceptY ? acceptY(getPointY(arg)) : getPointY(arg));
  }
  ATabort("not a Point: %t\n", arg);
  return (Point)NULL;
}

/*}}}  */

/*}}}  */
