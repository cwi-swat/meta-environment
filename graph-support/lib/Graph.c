#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Graph.h"

/*{{{  typedefs */

typedef struct ATerm _Graph;
typedef struct ATerm _NodeList;
typedef struct ATerm _Node;
typedef struct ATerm _NodeId;
typedef struct ATerm _AttributeList;
typedef struct ATerm _Attribute;
typedef struct ATerm _Color;
typedef struct ATerm _Style;
typedef struct ATerm _Shape;
typedef struct ATerm _Direction;
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
/*{{{  NodeId NodeIdFromTerm(ATerm t) */

NodeId NodeIdFromTerm(ATerm t)
{
  return (NodeId)t;
}

/*}}}  */
/*{{{  ATerm NodeIdToTerm(NodeId arg) */

ATerm NodeIdToTerm(NodeId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AttributeList AttributeListFromTerm(ATerm t) */

AttributeList AttributeListFromTerm(ATerm t)
{
  return (AttributeList)t;
}

/*}}}  */
/*{{{  ATerm AttributeListToTerm(AttributeList arg) */

ATerm AttributeListToTerm(AttributeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Attribute AttributeFromTerm(ATerm t) */

Attribute AttributeFromTerm(ATerm t)
{
  return (Attribute)t;
}

/*}}}  */
/*{{{  ATerm AttributeToTerm(Attribute arg) */

ATerm AttributeToTerm(Attribute arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Color ColorFromTerm(ATerm t) */

Color ColorFromTerm(ATerm t)
{
  return (Color)t;
}

/*}}}  */
/*{{{  ATerm ColorToTerm(Color arg) */

ATerm ColorToTerm(Color arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Style StyleFromTerm(ATerm t) */

Style StyleFromTerm(ATerm t)
{
  return (Style)t;
}

/*}}}  */
/*{{{  ATerm StyleToTerm(Style arg) */

ATerm StyleToTerm(Style arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Shape ShapeFromTerm(ATerm t) */

Shape ShapeFromTerm(ATerm t)
{
  return (Shape)t;
}

/*}}}  */
/*{{{  ATerm ShapeToTerm(Shape arg) */

ATerm ShapeToTerm(Shape arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  Direction DirectionFromTerm(ATerm t) */

Direction DirectionFromTerm(ATerm t)
{
  return (Direction)t;
}

/*}}}  */
/*{{{  ATerm DirectionToTerm(Direction arg) */

ATerm DirectionToTerm(Direction arg)
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
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

/*{{{  Graph makeGraphDefault(NodeList nodes, EdgeList edges, AttributeList attributes) */

Graph makeGraphDefault(NodeList nodes, EdgeList edges, AttributeList attributes)
{
  return (Graph)(ATerm)ATmakeAppl3(afun0, (ATerm)nodes, (ATerm)edges, (ATerm)attributes);
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
/*{{{  Node makeNodeDefault(NodeId id, AttributeList attributes) */

Node makeNodeDefault(NodeId id, AttributeList attributes)
{
  return (Node)(ATerm)ATmakeAppl2(afun1, (ATerm)id, (ATerm)attributes);
}

/*}}}  */
/*{{{  NodeId makeNodeIdDefault(char* id) */

NodeId makeNodeIdDefault(char* id)
{
  return (NodeId)(ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue));
}

/*}}}  */
/*{{{  AttributeList makeAttributeListEmpty() */

AttributeList makeAttributeListEmpty()
{
  return (AttributeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  AttributeList makeAttributeListMulti(Attribute head, AttributeList tail) */

AttributeList makeAttributeListMulti(Attribute head, AttributeList tail)
{
  return (AttributeList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  Attribute makeAttributeBoundingBox(Point first, Point second) */

Attribute makeAttributeBoundingBox(Point first, Point second)
{
  return (Attribute)(ATerm)ATmakeAppl2(afun2, (ATerm)first, (ATerm)second);
}

/*}}}  */
/*{{{  Attribute makeAttributeColor(Color color) */

Attribute makeAttributeColor(Color color)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun3, (ATerm)color);
}

/*}}}  */
/*{{{  Attribute makeAttributeCurvePoints(Polygon points) */

Attribute makeAttributeCurvePoints(Polygon points)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun4, (ATerm)points);
}

/*}}}  */
/*{{{  Attribute makeAttributeDirection(Direction direction) */

Attribute makeAttributeDirection(Direction direction)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun5, (ATerm)direction);
}

/*}}}  */
/*{{{  Attribute makeAttributeFillColor(Color color) */

Attribute makeAttributeFillColor(Color color)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun6, (ATerm)color);
}

/*}}}  */
/*{{{  Attribute makeAttributeInfo(char* key, ATerm value) */

Attribute makeAttributeInfo(char* key, ATerm value)
{
  return (Attribute)(ATerm)ATmakeAppl2(afun7, (ATerm)ATmakeAppl0(ATmakeAFun(key, 0, ATtrue)), (ATerm)value);
}

/*}}}  */
/*{{{  Attribute makeAttributeLabel(char* label) */

Attribute makeAttributeLabel(char* label)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun8, (ATerm)ATmakeAppl0(ATmakeAFun(label, 0, ATtrue)));
}

/*}}}  */
/*{{{  Attribute makeAttributeLocation(int x, int y) */

Attribute makeAttributeLocation(int x, int y)
{
  return (Attribute)(ATerm)ATmakeAppl2(afun9, (ATerm)ATmakeInt(x), (ATerm)ATmakeInt(y));
}

/*}}}  */
/*{{{  Attribute makeAttributeShape(Shape shape) */

Attribute makeAttributeShape(Shape shape)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun10, (ATerm)shape);
}

/*}}}  */
/*{{{  Attribute makeAttributeSize(int width, int height) */

Attribute makeAttributeSize(int width, int height)
{
  return (Attribute)(ATerm)ATmakeAppl2(afun11, (ATerm)ATmakeInt(width), (ATerm)ATmakeInt(height));
}

/*}}}  */
/*{{{  Attribute makeAttributeStyle(Style style) */

Attribute makeAttributeStyle(Style style)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun12, (ATerm)style);
}

/*}}}  */
/*{{{  Color makeColorRgb(int red, int green, int blue) */

Color makeColorRgb(int red, int green, int blue)
{
  return (Color)(ATerm)ATmakeAppl3(afun13, (ATerm)ATmakeInt(red), (ATerm)ATmakeInt(green), (ATerm)ATmakeInt(blue));
}

/*}}}  */
/*{{{  Style makeStyleBold() */

Style makeStyleBold()
{
  return (Style)(ATerm)ATmakeAppl0(afun14);
}

/*}}}  */
/*{{{  Style makeStyleDashed() */

Style makeStyleDashed()
{
  return (Style)(ATerm)ATmakeAppl0(afun15);
}

/*}}}  */
/*{{{  Style makeStyleDotted() */

Style makeStyleDotted()
{
  return (Style)(ATerm)ATmakeAppl0(afun16);
}

/*}}}  */
/*{{{  Style makeStyleFilled() */

Style makeStyleFilled()
{
  return (Style)(ATerm)ATmakeAppl0(afun17);
}

/*}}}  */
/*{{{  Style makeStyleInvisible() */

Style makeStyleInvisible()
{
  return (Style)(ATerm)ATmakeAppl0(afun18);
}

/*}}}  */
/*{{{  Style makeStyleSolid() */

Style makeStyleSolid()
{
  return (Style)(ATerm)ATmakeAppl0(afun19);
}

/*}}}  */
/*{{{  Shape makeShapeBox() */

Shape makeShapeBox()
{
  return (Shape)(ATerm)ATmakeAppl0(afun20);
}

/*}}}  */
/*{{{  Shape makeShapeCircle() */

Shape makeShapeCircle()
{
  return (Shape)(ATerm)ATmakeAppl0(afun21);
}

/*}}}  */
/*{{{  Shape makeShapeDiamond() */

Shape makeShapeDiamond()
{
  return (Shape)(ATerm)ATmakeAppl0(afun22);
}

/*}}}  */
/*{{{  Shape makeShapeEgg() */

Shape makeShapeEgg()
{
  return (Shape)(ATerm)ATmakeAppl0(afun23);
}

/*}}}  */
/*{{{  Shape makeShapeEllipse() */

Shape makeShapeEllipse()
{
  return (Shape)(ATerm)ATmakeAppl0(afun24);
}

/*}}}  */
/*{{{  Shape makeShapeHexagon() */

Shape makeShapeHexagon()
{
  return (Shape)(ATerm)ATmakeAppl0(afun25);
}

/*}}}  */
/*{{{  Shape makeShapeHouse() */

Shape makeShapeHouse()
{
  return (Shape)(ATerm)ATmakeAppl0(afun26);
}

/*}}}  */
/*{{{  Shape makeShapeOctagon() */

Shape makeShapeOctagon()
{
  return (Shape)(ATerm)ATmakeAppl0(afun27);
}

/*}}}  */
/*{{{  Shape makeShapeParallelogram() */

Shape makeShapeParallelogram()
{
  return (Shape)(ATerm)ATmakeAppl0(afun28);
}

/*}}}  */
/*{{{  Shape makeShapePlaintext() */

Shape makeShapePlaintext()
{
  return (Shape)(ATerm)ATmakeAppl0(afun29);
}

/*}}}  */
/*{{{  Shape makeShapeTrapezium() */

Shape makeShapeTrapezium()
{
  return (Shape)(ATerm)ATmakeAppl0(afun30);
}

/*}}}  */
/*{{{  Shape makeShapeTriangle() */

Shape makeShapeTriangle()
{
  return (Shape)(ATerm)ATmakeAppl0(afun31);
}

/*}}}  */
/*{{{  Direction makeDirectionForward() */

Direction makeDirectionForward()
{
  return (Direction)(ATerm)ATmakeAppl0(afun32);
}

/*}}}  */
/*{{{  Direction makeDirectionBack() */

Direction makeDirectionBack()
{
  return (Direction)(ATerm)ATmakeAppl0(afun33);
}

/*}}}  */
/*{{{  Direction makeDirectionBoth() */

Direction makeDirectionBoth()
{
  return (Direction)(ATerm)ATmakeAppl0(afun34);
}

/*}}}  */
/*{{{  Direction makeDirectionNone() */

Direction makeDirectionNone()
{
  return (Direction)(ATerm)ATmakeAppl0(afun35);
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
/*{{{  Edge makeEdgeDefault(NodeId from, NodeId to, AttributeList attributes) */

Edge makeEdgeDefault(NodeId from, NodeId to, AttributeList attributes)
{
  return (Edge)(ATerm)ATmakeAppl3(afun36, (ATerm)from, (ATerm)to, (ATerm)attributes);
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
  return (Point)(ATerm)ATmakeAppl2(afun37, (ATerm)ATmakeInt(x), (ATerm)ATmakeInt(y));
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

ATbool isEqualNodeId(NodeId arg0, NodeId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualAttributeList(AttributeList arg0, AttributeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualAttribute(Attribute arg0, Attribute arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualColor(Color arg0, Color arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualStyle(Style arg0, Style arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualShape(Shape arg0, Shape arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool isEqualDirection(Direction arg0, Direction arg1)
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
  assert(ATmatchTerm((ATerm)arg, patternGraphDefault, NULL, NULL, NULL));
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
/*{{{  ATbool hasGraphAttributes(Graph arg) */

ATbool hasGraphAttributes(Graph arg)
{
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AttributeList getGraphAttributes(Graph arg) */

AttributeList getGraphAttributes(Graph arg)
{
  
    return (AttributeList)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  Graph setGraphAttributes(Graph arg, AttributeList attributes) */

Graph setGraphAttributes(Graph arg, AttributeList attributes)
{
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)attributes, 2);
  }

  ATabort("Graph has no Attributes: %t\n", arg);
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
  if (isNodeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isNodeDefault(Node arg) */

inline ATbool isNodeDefault(Node arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternNodeDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasNodeId(Node arg) */

ATbool hasNodeId(Node arg)
{
  if (isNodeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  NodeId getNodeId(Node arg) */

NodeId getNodeId(Node arg)
{
  
    return (NodeId)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Node setNodeId(Node arg, NodeId id) */

Node setNodeId(Node arg, NodeId id)
{
  if (isNodeDefault(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("Node has no Id: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */
/*{{{  ATbool hasNodeAttributes(Node arg) */

ATbool hasNodeAttributes(Node arg)
{
  if (isNodeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AttributeList getNodeAttributes(Node arg) */

AttributeList getNodeAttributes(Node arg)
{
  
    return (AttributeList)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  Node setNodeAttributes(Node arg, AttributeList attributes) */

Node setNodeAttributes(Node arg, AttributeList attributes)
{
  if (isNodeDefault(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)attributes, 1);
  }

  ATabort("Node has no Attributes: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  NodeId accessors */

/*{{{  ATbool isValidNodeId(NodeId arg) */

ATbool isValidNodeId(NodeId arg)
{
  if (isNodeIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isNodeIdDefault(NodeId arg) */

inline ATbool isNodeIdDefault(NodeId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternNodeIdDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasNodeIdId(NodeId arg) */

ATbool hasNodeIdId(NodeId arg)
{
  if (isNodeIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* getNodeIdId(NodeId arg) */

char* getNodeIdId(NodeId arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)arg));
}

/*}}}  */
/*{{{  NodeId setNodeIdId(NodeId arg, char* id) */

NodeId setNodeIdId(NodeId arg, char* id)
{
  if (isNodeIdDefault(arg)) {
    return (NodeId)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue));
  }

  ATabort("NodeId has no Id: %t\n", arg);
  return (NodeId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AttributeList accessors */

/*{{{  ATbool isValidAttributeList(AttributeList arg) */

ATbool isValidAttributeList(AttributeList arg)
{
  if (isAttributeListEmpty(arg)) {
    return ATtrue;
  }
  else if (isAttributeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isAttributeListEmpty(AttributeList arg) */

inline ATbool isAttributeListEmpty(AttributeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternAttributeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool isAttributeListMulti(AttributeList arg) */

inline ATbool isAttributeListMulti(AttributeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternAttributeListMulti, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasAttributeListHead(AttributeList arg) */

ATbool hasAttributeListHead(AttributeList arg)
{
  if (isAttributeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Attribute getAttributeListHead(AttributeList arg) */

Attribute getAttributeListHead(AttributeList arg)
{
  
    return (Attribute)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  AttributeList setAttributeListHead(AttributeList arg, Attribute head) */

AttributeList setAttributeListHead(AttributeList arg, Attribute head)
{
  if (isAttributeListMulti(arg)) {
    return (AttributeList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("AttributeList has no Head: %t\n", arg);
  return (AttributeList)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeListTail(AttributeList arg) */

ATbool hasAttributeListTail(AttributeList arg)
{
  if (isAttributeListMulti(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AttributeList getAttributeListTail(AttributeList arg) */

AttributeList getAttributeListTail(AttributeList arg)
{
  
    return (AttributeList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  AttributeList setAttributeListTail(AttributeList arg, AttributeList tail) */

AttributeList setAttributeListTail(AttributeList arg, AttributeList tail)
{
  if (isAttributeListMulti(arg)) {
    return (AttributeList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("AttributeList has no Tail: %t\n", arg);
  return (AttributeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  Attribute accessors */

/*{{{  ATbool isValidAttribute(Attribute arg) */

ATbool isValidAttribute(Attribute arg)
{
  if (isAttributeBoundingBox(arg)) {
    return ATtrue;
  }
  else if (isAttributeColor(arg)) {
    return ATtrue;
  }
  else if (isAttributeCurvePoints(arg)) {
    return ATtrue;
  }
  else if (isAttributeDirection(arg)) {
    return ATtrue;
  }
  else if (isAttributeFillColor(arg)) {
    return ATtrue;
  }
  else if (isAttributeInfo(arg)) {
    return ATtrue;
  }
  else if (isAttributeLabel(arg)) {
    return ATtrue;
  }
  else if (isAttributeLocation(arg)) {
    return ATtrue;
  }
  else if (isAttributeShape(arg)) {
    return ATtrue;
  }
  else if (isAttributeSize(arg)) {
    return ATtrue;
  }
  else if (isAttributeStyle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isAttributeBoundingBox(Attribute arg) */

inline ATbool isAttributeBoundingBox(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeBoundingBox, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeColor(Attribute arg) */

inline ATbool isAttributeColor(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeColor, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeCurvePoints(Attribute arg) */

inline ATbool isAttributeCurvePoints(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeCurvePoints, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeDirection(Attribute arg) */

inline ATbool isAttributeDirection(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeDirection, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeFillColor(Attribute arg) */

inline ATbool isAttributeFillColor(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeFillColor, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeInfo(Attribute arg) */

inline ATbool isAttributeInfo(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeInfo, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeLabel(Attribute arg) */

inline ATbool isAttributeLabel(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeLabel, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeLocation(Attribute arg) */

inline ATbool isAttributeLocation(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeLocation, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeShape(Attribute arg) */

inline ATbool isAttributeShape(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeShape, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeSize(Attribute arg) */

inline ATbool isAttributeSize(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeSize, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeStyle(Attribute arg) */

inline ATbool isAttributeStyle(Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeStyle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool hasAttributeFirst(Attribute arg) */

ATbool hasAttributeFirst(Attribute arg)
{
  if (isAttributeBoundingBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Point getAttributeFirst(Attribute arg) */

Point getAttributeFirst(Attribute arg)
{
  
    return (Point)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Attribute setAttributeFirst(Attribute arg, Point first) */

Attribute setAttributeFirst(Attribute arg, Point first)
{
  if (isAttributeBoundingBox(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)first, 0);
  }

  ATabort("Attribute has no First: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeSecond(Attribute arg) */

ATbool hasAttributeSecond(Attribute arg)
{
  if (isAttributeBoundingBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Point getAttributeSecond(Attribute arg) */

Point getAttributeSecond(Attribute arg)
{
  
    return (Point)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  Attribute setAttributeSecond(Attribute arg, Point second) */

Attribute setAttributeSecond(Attribute arg, Point second)
{
  if (isAttributeBoundingBox(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)second, 1);
  }

  ATabort("Attribute has no Second: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeColor(Attribute arg) */

ATbool hasAttributeColor(Attribute arg)
{
  if (isAttributeColor(arg)) {
    return ATtrue;
  }
  else if (isAttributeFillColor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Color getAttributeColor(Attribute arg) */

Color getAttributeColor(Attribute arg)
{
  if (isAttributeColor(arg)) {
    return (Color)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (Color)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Attribute setAttributeColor(Attribute arg, Color color) */

Attribute setAttributeColor(Attribute arg, Color color)
{
  if (isAttributeColor(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)color, 0);
  }
  else if (isAttributeFillColor(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)color, 0);
  }

  ATabort("Attribute has no Color: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributePoints(Attribute arg) */

ATbool hasAttributePoints(Attribute arg)
{
  if (isAttributeCurvePoints(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Polygon getAttributePoints(Attribute arg) */

Polygon getAttributePoints(Attribute arg)
{
  
    return (Polygon)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Attribute setAttributePoints(Attribute arg, Polygon points) */

Attribute setAttributePoints(Attribute arg, Polygon points)
{
  if (isAttributeCurvePoints(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)points, 0);
  }

  ATabort("Attribute has no Points: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeDirection(Attribute arg) */

ATbool hasAttributeDirection(Attribute arg)
{
  if (isAttributeDirection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Direction getAttributeDirection(Attribute arg) */

Direction getAttributeDirection(Attribute arg)
{
  
    return (Direction)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Attribute setAttributeDirection(Attribute arg, Direction direction) */

Attribute setAttributeDirection(Attribute arg, Direction direction)
{
  if (isAttributeDirection(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)direction, 0);
  }

  ATabort("Attribute has no Direction: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeKey(Attribute arg) */

ATbool hasAttributeKey(Attribute arg)
{
  if (isAttributeInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* getAttributeKey(Attribute arg) */

char* getAttributeKey(Attribute arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  Attribute setAttributeKey(Attribute arg, char* key) */

Attribute setAttributeKey(Attribute arg, char* key)
{
  if (isAttributeInfo(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(key, 0, ATtrue)), 0);
  }

  ATabort("Attribute has no Key: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeValue(Attribute arg) */

ATbool hasAttributeValue(Attribute arg)
{
  if (isAttributeInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm getAttributeValue(Attribute arg) */

ATerm getAttributeValue(Attribute arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  Attribute setAttributeValue(Attribute arg, ATerm value) */

Attribute setAttributeValue(Attribute arg, ATerm value)
{
  if (isAttributeInfo(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)value, 1);
  }

  ATabort("Attribute has no Value: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeLabel(Attribute arg) */

ATbool hasAttributeLabel(Attribute arg)
{
  if (isAttributeLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* getAttributeLabel(Attribute arg) */

char* getAttributeLabel(Attribute arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  Attribute setAttributeLabel(Attribute arg, char* label) */

Attribute setAttributeLabel(Attribute arg, char* label)
{
  if (isAttributeLabel(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(label, 0, ATtrue)), 0);
  }

  ATabort("Attribute has no Label: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeX(Attribute arg) */

ATbool hasAttributeX(Attribute arg)
{
  if (isAttributeLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getAttributeX(Attribute arg) */

int getAttributeX(Attribute arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  Attribute setAttributeX(Attribute arg, int x) */

Attribute setAttributeX(Attribute arg, int x)
{
  if (isAttributeLocation(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(x), 0);
  }

  ATabort("Attribute has no X: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeY(Attribute arg) */

ATbool hasAttributeY(Attribute arg)
{
  if (isAttributeLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getAttributeY(Attribute arg) */

int getAttributeY(Attribute arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  Attribute setAttributeY(Attribute arg, int y) */

Attribute setAttributeY(Attribute arg, int y)
{
  if (isAttributeLocation(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(y), 1);
  }

  ATabort("Attribute has no Y: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeShape(Attribute arg) */

ATbool hasAttributeShape(Attribute arg)
{
  if (isAttributeShape(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Shape getAttributeShape(Attribute arg) */

Shape getAttributeShape(Attribute arg)
{
  
    return (Shape)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Attribute setAttributeShape(Attribute arg, Shape shape) */

Attribute setAttributeShape(Attribute arg, Shape shape)
{
  if (isAttributeShape(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)shape, 0);
  }

  ATabort("Attribute has no Shape: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeWidth(Attribute arg) */

ATbool hasAttributeWidth(Attribute arg)
{
  if (isAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getAttributeWidth(Attribute arg) */

int getAttributeWidth(Attribute arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  Attribute setAttributeWidth(Attribute arg, int width) */

Attribute setAttributeWidth(Attribute arg, int width)
{
  if (isAttributeSize(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(width), 0);
  }

  ATabort("Attribute has no Width: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeHeight(Attribute arg) */

ATbool hasAttributeHeight(Attribute arg)
{
  if (isAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getAttributeHeight(Attribute arg) */

int getAttributeHeight(Attribute arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  Attribute setAttributeHeight(Attribute arg, int height) */

Attribute setAttributeHeight(Attribute arg, int height)
{
  if (isAttributeSize(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(height), 1);
  }

  ATabort("Attribute has no Height: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  ATbool hasAttributeStyle(Attribute arg) */

ATbool hasAttributeStyle(Attribute arg)
{
  if (isAttributeStyle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Style getAttributeStyle(Attribute arg) */

Style getAttributeStyle(Attribute arg)
{
  
    return (Style)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Attribute setAttributeStyle(Attribute arg, Style style) */

Attribute setAttributeStyle(Attribute arg, Style style)
{
  if (isAttributeStyle(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)style, 0);
  }

  ATabort("Attribute has no Style: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  Color accessors */

/*{{{  ATbool isValidColor(Color arg) */

ATbool isValidColor(Color arg)
{
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isColorRgb(Color arg) */

inline ATbool isColorRgb(Color arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternColorRgb, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasColorRed(Color arg) */

ATbool hasColorRed(Color arg)
{
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getColorRed(Color arg) */

int getColorRed(Color arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  Color setColorRed(Color arg, int red) */

Color setColorRed(Color arg, int red)
{
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(red), 0);
  }

  ATabort("Color has no Red: %t\n", arg);
  return (Color)NULL;
}

/*}}}  */
/*{{{  ATbool hasColorGreen(Color arg) */

ATbool hasColorGreen(Color arg)
{
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getColorGreen(Color arg) */

int getColorGreen(Color arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  Color setColorGreen(Color arg, int green) */

Color setColorGreen(Color arg, int green)
{
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(green), 1);
  }

  ATabort("Color has no Green: %t\n", arg);
  return (Color)NULL;
}

/*}}}  */
/*{{{  ATbool hasColorBlue(Color arg) */

ATbool hasColorBlue(Color arg)
{
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int getColorBlue(Color arg) */

int getColorBlue(Color arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  Color setColorBlue(Color arg, int blue) */

Color setColorBlue(Color arg, int blue)
{
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(blue), 2);
  }

  ATabort("Color has no Blue: %t\n", arg);
  return (Color)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  Style accessors */

/*{{{  ATbool isValidStyle(Style arg) */

ATbool isValidStyle(Style arg)
{
  if (isStyleBold(arg)) {
    return ATtrue;
  }
  else if (isStyleDashed(arg)) {
    return ATtrue;
  }
  else if (isStyleDotted(arg)) {
    return ATtrue;
  }
  else if (isStyleFilled(arg)) {
    return ATtrue;
  }
  else if (isStyleInvisible(arg)) {
    return ATtrue;
  }
  else if (isStyleSolid(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isStyleBold(Style arg) */

inline ATbool isStyleBold(Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternStyleBold);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isStyleDashed(Style arg) */

inline ATbool isStyleDashed(Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternStyleDashed);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isStyleDotted(Style arg) */

inline ATbool isStyleDotted(Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternStyleDotted);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isStyleFilled(Style arg) */

inline ATbool isStyleFilled(Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternStyleFilled);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isStyleInvisible(Style arg) */

inline ATbool isStyleInvisible(Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternStyleInvisible);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isStyleSolid(Style arg) */

inline ATbool isStyleSolid(Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternStyleSolid);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  Shape accessors */

/*{{{  ATbool isValidShape(Shape arg) */

ATbool isValidShape(Shape arg)
{
  if (isShapeBox(arg)) {
    return ATtrue;
  }
  else if (isShapeCircle(arg)) {
    return ATtrue;
  }
  else if (isShapeDiamond(arg)) {
    return ATtrue;
  }
  else if (isShapeEgg(arg)) {
    return ATtrue;
  }
  else if (isShapeEllipse(arg)) {
    return ATtrue;
  }
  else if (isShapeHexagon(arg)) {
    return ATtrue;
  }
  else if (isShapeHouse(arg)) {
    return ATtrue;
  }
  else if (isShapeOctagon(arg)) {
    return ATtrue;
  }
  else if (isShapeParallelogram(arg)) {
    return ATtrue;
  }
  else if (isShapePlaintext(arg)) {
    return ATtrue;
  }
  else if (isShapeTrapezium(arg)) {
    return ATtrue;
  }
  else if (isShapeTriangle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isShapeBox(Shape arg) */

inline ATbool isShapeBox(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeBox);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeCircle(Shape arg) */

inline ATbool isShapeCircle(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeCircle);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeDiamond(Shape arg) */

inline ATbool isShapeDiamond(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeDiamond);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeEgg(Shape arg) */

inline ATbool isShapeEgg(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeEgg);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeEllipse(Shape arg) */

inline ATbool isShapeEllipse(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeEllipse);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeHexagon(Shape arg) */

inline ATbool isShapeHexagon(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeHexagon);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeHouse(Shape arg) */

inline ATbool isShapeHouse(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeHouse);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeOctagon(Shape arg) */

inline ATbool isShapeOctagon(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeOctagon);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeParallelogram(Shape arg) */

inline ATbool isShapeParallelogram(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeParallelogram);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapePlaintext(Shape arg) */

inline ATbool isShapePlaintext(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapePlaintext);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeTrapezium(Shape arg) */

inline ATbool isShapeTrapezium(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeTrapezium);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isShapeTriangle(Shape arg) */

inline ATbool isShapeTriangle(Shape arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternShapeTriangle);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  Direction accessors */

/*{{{  ATbool isValidDirection(Direction arg) */

ATbool isValidDirection(Direction arg)
{
  if (isDirectionForward(arg)) {
    return ATtrue;
  }
  else if (isDirectionBack(arg)) {
    return ATtrue;
  }
  else if (isDirectionBoth(arg)) {
    return ATtrue;
  }
  else if (isDirectionNone(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isDirectionForward(Direction arg) */

inline ATbool isDirectionForward(Direction arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternDirectionForward);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isDirectionBack(Direction arg) */

inline ATbool isDirectionBack(Direction arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternDirectionBack);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isDirectionBoth(Direction arg) */

inline ATbool isDirectionBoth(Direction arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternDirectionBoth);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isDirectionNone(Direction arg) */

inline ATbool isDirectionNone(Direction arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternDirectionNone);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool isEdgeDefault(Edge arg) */

inline ATbool isEdgeDefault(Edge arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternEdgeDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool hasEdgeFrom(Edge arg) */

ATbool hasEdgeFrom(Edge arg)
{
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  NodeId getEdgeFrom(Edge arg) */

NodeId getEdgeFrom(Edge arg)
{
  
    return (NodeId)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Edge setEdgeFrom(Edge arg, NodeId from) */

Edge setEdgeFrom(Edge arg, NodeId from)
{
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)from, 0);
  }

  ATabort("Edge has no From: %t\n", arg);
  return (Edge)NULL;
}

/*}}}  */
/*{{{  ATbool hasEdgeTo(Edge arg) */

ATbool hasEdgeTo(Edge arg)
{
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  NodeId getEdgeTo(Edge arg) */

NodeId getEdgeTo(Edge arg)
{
  
    return (NodeId)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  Edge setEdgeTo(Edge arg, NodeId to) */

Edge setEdgeTo(Edge arg, NodeId to)
{
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)to, 1);
  }

  ATabort("Edge has no To: %t\n", arg);
  return (Edge)NULL;
}

/*}}}  */
/*{{{  ATbool hasEdgeAttributes(Edge arg) */

ATbool hasEdgeAttributes(Edge arg)
{
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AttributeList getEdgeAttributes(Edge arg) */

AttributeList getEdgeAttributes(Edge arg)
{
  
    return (AttributeList)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  Edge setEdgeAttributes(Edge arg, AttributeList attributes) */

Edge setEdgeAttributes(Edge arg, AttributeList attributes)
{
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)attributes, 2);
  }

  ATabort("Edge has no Attributes: %t\n", arg);
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

/*{{{  Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList), AttributeList (*acceptAttributes)(AttributeList)) */

Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList), AttributeList (*acceptAttributes)(AttributeList))
{
  if (isGraphDefault(arg)) {
    return makeGraphDefault(
        acceptNodes ? acceptNodes(getGraphNodes(arg)) : getGraphNodes(arg),
        acceptEdges ? acceptEdges(getGraphEdges(arg)) : getGraphEdges(arg),
        acceptAttributes ? acceptAttributes(getGraphAttributes(arg)) : getGraphAttributes(arg));
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
/*{{{  Node visitNode(Node arg, NodeId (*acceptId)(NodeId), AttributeList (*acceptAttributes)(AttributeList)) */

Node visitNode(Node arg, NodeId (*acceptId)(NodeId), AttributeList (*acceptAttributes)(AttributeList))
{
  if (isNodeDefault(arg)) {
    return makeNodeDefault(
        acceptId ? acceptId(getNodeId(arg)) : getNodeId(arg),
        acceptAttributes ? acceptAttributes(getNodeAttributes(arg)) : getNodeAttributes(arg));
  }
  ATabort("not a Node: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */
/*{{{  NodeId visitNodeId(NodeId arg, char* (*acceptId)(char*)) */

NodeId visitNodeId(NodeId arg, char* (*acceptId)(char*))
{
  if (isNodeIdDefault(arg)) {
    return makeNodeIdDefault(
        acceptId ? acceptId(getNodeIdId(arg)) : getNodeIdId(arg));
  }
  ATabort("not a NodeId: %t\n", arg);
  return (NodeId)NULL;
}

/*}}}  */
/*{{{  AttributeList visitAttributeList(AttributeList arg, Attribute (*acceptHead)(Attribute)) */

AttributeList visitAttributeList(AttributeList arg, Attribute (*acceptHead)(Attribute))
{
  if (isAttributeListEmpty(arg)) {
    return makeAttributeListEmpty();
  }
  if (isAttributeListMulti(arg)) {
    return makeAttributeListMulti(
        acceptHead ? acceptHead(getAttributeListHead(arg)) : getAttributeListHead(arg),
        visitAttributeList(getAttributeListTail(arg), acceptHead));
  }
  ATabort("not a AttributeList: %t\n", arg);
  return (AttributeList)NULL;
}

/*}}}  */
/*{{{  Attribute visitAttribute(Attribute arg, Point (*acceptFirst)(Point), Point (*acceptSecond)(Point), Color (*acceptColor)(Color), Polygon (*acceptPoints)(Polygon), Direction (*acceptDirection)(Direction), char* (*acceptKey)(char*), ATerm (*acceptValue)(ATerm), char* (*acceptLabel)(char*), int (*acceptX)(int), int (*acceptY)(int), Shape (*acceptShape)(Shape), int (*acceptWidth)(int), int (*acceptHeight)(int), Style (*acceptStyle)(Style)) */

Attribute visitAttribute(Attribute arg, Point (*acceptFirst)(Point), Point (*acceptSecond)(Point), Color (*acceptColor)(Color), Polygon (*acceptPoints)(Polygon), Direction (*acceptDirection)(Direction), char* (*acceptKey)(char*), ATerm (*acceptValue)(ATerm), char* (*acceptLabel)(char*), int (*acceptX)(int), int (*acceptY)(int), Shape (*acceptShape)(Shape), int (*acceptWidth)(int), int (*acceptHeight)(int), Style (*acceptStyle)(Style))
{
  if (isAttributeBoundingBox(arg)) {
    return makeAttributeBoundingBox(
        acceptFirst ? acceptFirst(getAttributeFirst(arg)) : getAttributeFirst(arg),
        acceptSecond ? acceptSecond(getAttributeSecond(arg)) : getAttributeSecond(arg));
  }
  if (isAttributeColor(arg)) {
    return makeAttributeColor(
        acceptColor ? acceptColor(getAttributeColor(arg)) : getAttributeColor(arg));
  }
  if (isAttributeCurvePoints(arg)) {
    return makeAttributeCurvePoints(
        acceptPoints ? acceptPoints(getAttributePoints(arg)) : getAttributePoints(arg));
  }
  if (isAttributeDirection(arg)) {
    return makeAttributeDirection(
        acceptDirection ? acceptDirection(getAttributeDirection(arg)) : getAttributeDirection(arg));
  }
  if (isAttributeFillColor(arg)) {
    return makeAttributeFillColor(
        acceptColor ? acceptColor(getAttributeColor(arg)) : getAttributeColor(arg));
  }
  if (isAttributeInfo(arg)) {
    return makeAttributeInfo(
        acceptKey ? acceptKey(getAttributeKey(arg)) : getAttributeKey(arg),
        acceptValue ? acceptValue(getAttributeValue(arg)) : getAttributeValue(arg));
  }
  if (isAttributeLabel(arg)) {
    return makeAttributeLabel(
        acceptLabel ? acceptLabel(getAttributeLabel(arg)) : getAttributeLabel(arg));
  }
  if (isAttributeLocation(arg)) {
    return makeAttributeLocation(
        acceptX ? acceptX(getAttributeX(arg)) : getAttributeX(arg),
        acceptY ? acceptY(getAttributeY(arg)) : getAttributeY(arg));
  }
  if (isAttributeShape(arg)) {
    return makeAttributeShape(
        acceptShape ? acceptShape(getAttributeShape(arg)) : getAttributeShape(arg));
  }
  if (isAttributeSize(arg)) {
    return makeAttributeSize(
        acceptWidth ? acceptWidth(getAttributeWidth(arg)) : getAttributeWidth(arg),
        acceptHeight ? acceptHeight(getAttributeHeight(arg)) : getAttributeHeight(arg));
  }
  if (isAttributeStyle(arg)) {
    return makeAttributeStyle(
        acceptStyle ? acceptStyle(getAttributeStyle(arg)) : getAttributeStyle(arg));
  }
  ATabort("not a Attribute: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Color visitColor(Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int)) */

Color visitColor(Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int))
{
  if (isColorRgb(arg)) {
    return makeColorRgb(
        acceptRed ? acceptRed(getColorRed(arg)) : getColorRed(arg),
        acceptGreen ? acceptGreen(getColorGreen(arg)) : getColorGreen(arg),
        acceptBlue ? acceptBlue(getColorBlue(arg)) : getColorBlue(arg));
  }
  ATabort("not a Color: %t\n", arg);
  return (Color)NULL;
}

/*}}}  */
/*{{{  Style visitStyle(Style arg) */

Style visitStyle(Style arg)
{
  if (isStyleBold(arg)) {
    return makeStyleBold();
  }
  if (isStyleDashed(arg)) {
    return makeStyleDashed();
  }
  if (isStyleDotted(arg)) {
    return makeStyleDotted();
  }
  if (isStyleFilled(arg)) {
    return makeStyleFilled();
  }
  if (isStyleInvisible(arg)) {
    return makeStyleInvisible();
  }
  if (isStyleSolid(arg)) {
    return makeStyleSolid();
  }
  ATabort("not a Style: %t\n", arg);
  return (Style)NULL;
}

/*}}}  */
/*{{{  Shape visitShape(Shape arg) */

Shape visitShape(Shape arg)
{
  if (isShapeBox(arg)) {
    return makeShapeBox();
  }
  if (isShapeCircle(arg)) {
    return makeShapeCircle();
  }
  if (isShapeDiamond(arg)) {
    return makeShapeDiamond();
  }
  if (isShapeEgg(arg)) {
    return makeShapeEgg();
  }
  if (isShapeEllipse(arg)) {
    return makeShapeEllipse();
  }
  if (isShapeHexagon(arg)) {
    return makeShapeHexagon();
  }
  if (isShapeHouse(arg)) {
    return makeShapeHouse();
  }
  if (isShapeOctagon(arg)) {
    return makeShapeOctagon();
  }
  if (isShapeParallelogram(arg)) {
    return makeShapeParallelogram();
  }
  if (isShapePlaintext(arg)) {
    return makeShapePlaintext();
  }
  if (isShapeTrapezium(arg)) {
    return makeShapeTrapezium();
  }
  if (isShapeTriangle(arg)) {
    return makeShapeTriangle();
  }
  ATabort("not a Shape: %t\n", arg);
  return (Shape)NULL;
}

/*}}}  */
/*{{{  Direction visitDirection(Direction arg) */

Direction visitDirection(Direction arg)
{
  if (isDirectionForward(arg)) {
    return makeDirectionForward();
  }
  if (isDirectionBack(arg)) {
    return makeDirectionBack();
  }
  if (isDirectionBoth(arg)) {
    return makeDirectionBoth();
  }
  if (isDirectionNone(arg)) {
    return makeDirectionNone();
  }
  ATabort("not a Direction: %t\n", arg);
  return (Direction)NULL;
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
/*{{{  Edge visitEdge(Edge arg, NodeId (*acceptFrom)(NodeId), NodeId (*acceptTo)(NodeId), AttributeList (*acceptAttributes)(AttributeList)) */

Edge visitEdge(Edge arg, NodeId (*acceptFrom)(NodeId), NodeId (*acceptTo)(NodeId), AttributeList (*acceptAttributes)(AttributeList))
{
  if (isEdgeDefault(arg)) {
    return makeEdgeDefault(
        acceptFrom ? acceptFrom(getEdgeFrom(arg)) : getEdgeFrom(arg),
        acceptTo ? acceptTo(getEdgeTo(arg)) : getEdgeTo(arg),
        acceptAttributes ? acceptAttributes(getEdgeAttributes(arg)) : getEdgeAttributes(arg));
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
