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
typedef struct _NodeId *NodeId;
typedef struct _AttributeList *AttributeList;
typedef struct _Attribute *Attribute;
typedef struct _Color *Color;
typedef struct _Style *Style;
typedef struct _Shape *Shape;
typedef struct _Direction *Direction;
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
NodeId NodeIdFromTerm(ATerm t);
ATerm NodeIdToTerm(NodeId arg);
AttributeList AttributeListFromTerm(ATerm t);
ATerm AttributeListToTerm(AttributeList arg);
Attribute AttributeFromTerm(ATerm t);
ATerm AttributeToTerm(Attribute arg);
Color ColorFromTerm(ATerm t);
ATerm ColorToTerm(Color arg);
Style StyleFromTerm(ATerm t);
ATerm StyleToTerm(Style arg);
Shape ShapeFromTerm(ATerm t);
ATerm ShapeToTerm(Shape arg);
Direction DirectionFromTerm(ATerm t);
ATerm DirectionToTerm(Direction arg);
EdgeList EdgeListFromTerm(ATerm t);
ATerm EdgeListToTerm(EdgeList arg);
Edge EdgeFromTerm(ATerm t);
ATerm EdgeToTerm(Edge arg);
Polygon PolygonFromTerm(ATerm t);
ATerm PolygonToTerm(Polygon arg);
Point PointFromTerm(ATerm t);
ATerm PointToTerm(Point arg);

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

Graph makeGraphDefault(NodeList nodes, EdgeList edges, AttributeList attributes);
NodeList makeNodeListEmpty();
NodeList makeNodeListMulti(Node head, NodeList tail);
Node makeNodeDefault(NodeId id, AttributeList attributes);
NodeId makeNodeIdDefault(char* id);
AttributeList makeAttributeListEmpty();
AttributeList makeAttributeListMulti(Attribute head, AttributeList tail);
Attribute makeAttributeBoundingBox(Point first, Point second);
Attribute makeAttributeColor(Color color);
Attribute makeAttributeCurvePoints(Polygon points);
Attribute makeAttributeDirection(Direction direction);
Attribute makeAttributeFillColor(Color color);
Attribute makeAttributeInfo(char* key, ATerm value);
Attribute makeAttributeLabel(char* label);
Attribute makeAttributeLocation(int x, int y);
Attribute makeAttributeShape(Shape shape);
Attribute makeAttributeSize(int width, int height);
Attribute makeAttributeStyle(Style style);
Color makeColorRgb(int red, int green, int blue);
Style makeStyleBold();
Style makeStyleDashed();
Style makeStyleDotted();
Style makeStyleFilled();
Style makeStyleInvisible();
Style makeStyleSolid();
Shape makeShapeBox();
Shape makeShapeCircle();
Shape makeShapeDiamond();
Shape makeShapeEgg();
Shape makeShapeEllipse();
Shape makeShapeHexagon();
Shape makeShapeHouse();
Shape makeShapeOctagon();
Shape makeShapeParallelogram();
Shape makeShapePlaintext();
Shape makeShapeTrapezium();
Shape makeShapeTriangle();
Direction makeDirectionForward();
Direction makeDirectionBack();
Direction makeDirectionBoth();
Direction makeDirectionNone();
EdgeList makeEdgeListEmpty();
EdgeList makeEdgeListMulti(Edge head, EdgeList tail);
Edge makeEdgeDefault(NodeId from, NodeId to, AttributeList attributes);
Polygon makePolygonEmpty();
Polygon makePolygonMulti(Point head, Polygon tail);
Point makePointDefault(int x, int y);

/*}}}  */
/*{{{  equality functions */

ATbool isEqualGraph(Graph arg0, Graph arg1);
ATbool isEqualNodeList(NodeList arg0, NodeList arg1);
ATbool isEqualNode(Node arg0, Node arg1);
ATbool isEqualNodeId(NodeId arg0, NodeId arg1);
ATbool isEqualAttributeList(AttributeList arg0, AttributeList arg1);
ATbool isEqualAttribute(Attribute arg0, Attribute arg1);
ATbool isEqualColor(Color arg0, Color arg1);
ATbool isEqualStyle(Style arg0, Style arg1);
ATbool isEqualShape(Shape arg0, Shape arg1);
ATbool isEqualDirection(Direction arg0, Direction arg1);
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
ATbool hasGraphAttributes(Graph arg);
AttributeList getGraphAttributes(Graph arg);
Graph setGraphAttributes(Graph arg, AttributeList attributes);

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
inline ATbool isNodeDefault(Node arg);
ATbool hasNodeId(Node arg);
NodeId getNodeId(Node arg);
Node setNodeId(Node arg, NodeId id);
ATbool hasNodeAttributes(Node arg);
AttributeList getNodeAttributes(Node arg);
Node setNodeAttributes(Node arg, AttributeList attributes);

/*}}}  */
/*{{{  NodeId accessors */

ATbool isValidNodeId(NodeId arg);
inline ATbool isNodeIdDefault(NodeId arg);
ATbool hasNodeIdId(NodeId arg);
char* getNodeIdId(NodeId arg);
NodeId setNodeIdId(NodeId arg, char* id);

/*}}}  */
/*{{{  AttributeList accessors */

ATbool isValidAttributeList(AttributeList arg);
inline ATbool isAttributeListEmpty(AttributeList arg);
inline ATbool isAttributeListMulti(AttributeList arg);
ATbool hasAttributeListHead(AttributeList arg);
Attribute getAttributeListHead(AttributeList arg);
AttributeList setAttributeListHead(AttributeList arg, Attribute head);
ATbool hasAttributeListTail(AttributeList arg);
AttributeList getAttributeListTail(AttributeList arg);
AttributeList setAttributeListTail(AttributeList arg, AttributeList tail);

/*}}}  */
/*{{{  Attribute accessors */

ATbool isValidAttribute(Attribute arg);
inline ATbool isAttributeBoundingBox(Attribute arg);
inline ATbool isAttributeColor(Attribute arg);
inline ATbool isAttributeCurvePoints(Attribute arg);
inline ATbool isAttributeDirection(Attribute arg);
inline ATbool isAttributeFillColor(Attribute arg);
inline ATbool isAttributeInfo(Attribute arg);
inline ATbool isAttributeLabel(Attribute arg);
inline ATbool isAttributeLocation(Attribute arg);
inline ATbool isAttributeShape(Attribute arg);
inline ATbool isAttributeSize(Attribute arg);
inline ATbool isAttributeStyle(Attribute arg);
ATbool hasAttributeFirst(Attribute arg);
Point getAttributeFirst(Attribute arg);
Attribute setAttributeFirst(Attribute arg, Point first);
ATbool hasAttributeSecond(Attribute arg);
Point getAttributeSecond(Attribute arg);
Attribute setAttributeSecond(Attribute arg, Point second);
ATbool hasAttributeColor(Attribute arg);
Color getAttributeColor(Attribute arg);
Attribute setAttributeColor(Attribute arg, Color color);
ATbool hasAttributePoints(Attribute arg);
Polygon getAttributePoints(Attribute arg);
Attribute setAttributePoints(Attribute arg, Polygon points);
ATbool hasAttributeDirection(Attribute arg);
Direction getAttributeDirection(Attribute arg);
Attribute setAttributeDirection(Attribute arg, Direction direction);
ATbool hasAttributeKey(Attribute arg);
char* getAttributeKey(Attribute arg);
Attribute setAttributeKey(Attribute arg, char* key);
ATbool hasAttributeValue(Attribute arg);
ATerm getAttributeValue(Attribute arg);
Attribute setAttributeValue(Attribute arg, ATerm value);
ATbool hasAttributeLabel(Attribute arg);
char* getAttributeLabel(Attribute arg);
Attribute setAttributeLabel(Attribute arg, char* label);
ATbool hasAttributeX(Attribute arg);
int getAttributeX(Attribute arg);
Attribute setAttributeX(Attribute arg, int x);
ATbool hasAttributeY(Attribute arg);
int getAttributeY(Attribute arg);
Attribute setAttributeY(Attribute arg, int y);
ATbool hasAttributeShape(Attribute arg);
Shape getAttributeShape(Attribute arg);
Attribute setAttributeShape(Attribute arg, Shape shape);
ATbool hasAttributeWidth(Attribute arg);
int getAttributeWidth(Attribute arg);
Attribute setAttributeWidth(Attribute arg, int width);
ATbool hasAttributeHeight(Attribute arg);
int getAttributeHeight(Attribute arg);
Attribute setAttributeHeight(Attribute arg, int height);
ATbool hasAttributeStyle(Attribute arg);
Style getAttributeStyle(Attribute arg);
Attribute setAttributeStyle(Attribute arg, Style style);

/*}}}  */
/*{{{  Color accessors */

ATbool isValidColor(Color arg);
inline ATbool isColorRgb(Color arg);
ATbool hasColorRed(Color arg);
int getColorRed(Color arg);
Color setColorRed(Color arg, int red);
ATbool hasColorGreen(Color arg);
int getColorGreen(Color arg);
Color setColorGreen(Color arg, int green);
ATbool hasColorBlue(Color arg);
int getColorBlue(Color arg);
Color setColorBlue(Color arg, int blue);

/*}}}  */
/*{{{  Style accessors */

ATbool isValidStyle(Style arg);
inline ATbool isStyleBold(Style arg);
inline ATbool isStyleDashed(Style arg);
inline ATbool isStyleDotted(Style arg);
inline ATbool isStyleFilled(Style arg);
inline ATbool isStyleInvisible(Style arg);
inline ATbool isStyleSolid(Style arg);

/*}}}  */
/*{{{  Shape accessors */

ATbool isValidShape(Shape arg);
inline ATbool isShapeBox(Shape arg);
inline ATbool isShapeCircle(Shape arg);
inline ATbool isShapeDiamond(Shape arg);
inline ATbool isShapeEgg(Shape arg);
inline ATbool isShapeEllipse(Shape arg);
inline ATbool isShapeHexagon(Shape arg);
inline ATbool isShapeHouse(Shape arg);
inline ATbool isShapeOctagon(Shape arg);
inline ATbool isShapeParallelogram(Shape arg);
inline ATbool isShapePlaintext(Shape arg);
inline ATbool isShapeTrapezium(Shape arg);
inline ATbool isShapeTriangle(Shape arg);

/*}}}  */
/*{{{  Direction accessors */

ATbool isValidDirection(Direction arg);
inline ATbool isDirectionForward(Direction arg);
inline ATbool isDirectionBack(Direction arg);
inline ATbool isDirectionBoth(Direction arg);
inline ATbool isDirectionNone(Direction arg);

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
inline ATbool isEdgeDefault(Edge arg);
ATbool hasEdgeFrom(Edge arg);
NodeId getEdgeFrom(Edge arg);
Edge setEdgeFrom(Edge arg, NodeId from);
ATbool hasEdgeTo(Edge arg);
NodeId getEdgeTo(Edge arg);
Edge setEdgeTo(Edge arg, NodeId to);
ATbool hasEdgeAttributes(Edge arg);
AttributeList getEdgeAttributes(Edge arg);
Edge setEdgeAttributes(Edge arg, AttributeList attributes);

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

Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList), AttributeList (*acceptAttributes)(AttributeList));
NodeList visitNodeList(NodeList arg, Node (*acceptHead)(Node));
Node visitNode(Node arg, NodeId (*acceptId)(NodeId), AttributeList (*acceptAttributes)(AttributeList));
NodeId visitNodeId(NodeId arg, char* (*acceptId)(char*));
AttributeList visitAttributeList(AttributeList arg, Attribute (*acceptHead)(Attribute));
Attribute visitAttribute(Attribute arg, Point (*acceptFirst)(Point), Point (*acceptSecond)(Point), Color (*acceptColor)(Color), Polygon (*acceptPoints)(Polygon), Direction (*acceptDirection)(Direction), char* (*acceptKey)(char*), ATerm (*acceptValue)(ATerm), char* (*acceptLabel)(char*), int (*acceptX)(int), int (*acceptY)(int), Shape (*acceptShape)(Shape), int (*acceptWidth)(int), int (*acceptHeight)(int), Style (*acceptStyle)(Style));
Color visitColor(Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int));
Style visitStyle(Style arg);
Shape visitShape(Shape arg);
Direction visitDirection(Direction arg);
EdgeList visitEdgeList(EdgeList arg, Edge (*acceptHead)(Edge));
Edge visitEdge(Edge arg, NodeId (*acceptFrom)(NodeId), NodeId (*acceptTo)(NodeId), AttributeList (*acceptAttributes)(AttributeList));
Polygon visitPolygon(Polygon arg, Point (*acceptHead)(Point));
Point visitPoint(Point arg, int (*acceptX)(int), int (*acceptY)(int));

/*}}}  */

#endif /* _GRAPH_H */
