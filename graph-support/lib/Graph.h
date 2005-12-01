#ifndef _GRAPH_H
#define _GRAPH_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
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

/*{{{  protect functions */

void protectGraph(Graph *arg);
void protectNodeList(NodeList *arg);
void protectNode(Node *arg);
void protectNodeId(NodeId *arg);
void protectAttributeList(AttributeList *arg);
void protectAttribute(Attribute *arg);
void protectColor(Color *arg);
void protectStyle(Style *arg);
void protectShape(Shape *arg);
void protectDirection(Direction *arg);
void protectEdgeList(EdgeList *arg);
void protectEdge(Edge *arg);
void protectPolygon(Polygon *arg);
void protectPoint(Point *arg);

/*}}}  */
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

int getNodeListLength (NodeList arg);
NodeList reverseNodeList(NodeList arg);
NodeList appendNodeList(NodeList arg, Node elem);
NodeList concatNodeList(NodeList arg0, NodeList arg1);
NodeList sliceNodeList(NodeList arg, int start, int end);
Node getNodeListNodeAt(NodeList arg, int index);
NodeList replaceNodeListNodeAt(NodeList arg, Node elem, int index);
NodeList makeNodeList2(Node elem1, Node elem2);
NodeList makeNodeList3(Node elem1, Node elem2, Node elem3);
NodeList makeNodeList4(Node elem1, Node elem2, Node elem3, Node elem4);
NodeList makeNodeList5(Node elem1, Node elem2, Node elem3, Node elem4, Node elem5);
NodeList makeNodeList6(Node elem1, Node elem2, Node elem3, Node elem4, Node elem5, Node elem6);
int getAttributeListLength (AttributeList arg);
AttributeList reverseAttributeList(AttributeList arg);
AttributeList appendAttributeList(AttributeList arg, Attribute elem);
AttributeList concatAttributeList(AttributeList arg0, AttributeList arg1);
AttributeList sliceAttributeList(AttributeList arg, int start, int end);
Attribute getAttributeListAttributeAt(AttributeList arg, int index);
AttributeList replaceAttributeListAttributeAt(AttributeList arg, Attribute elem, int index);
AttributeList makeAttributeList2(Attribute elem1, Attribute elem2);
AttributeList makeAttributeList3(Attribute elem1, Attribute elem2, Attribute elem3);
AttributeList makeAttributeList4(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4);
AttributeList makeAttributeList5(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4, Attribute elem5);
AttributeList makeAttributeList6(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4, Attribute elem5, Attribute elem6);
int getEdgeListLength (EdgeList arg);
EdgeList reverseEdgeList(EdgeList arg);
EdgeList appendEdgeList(EdgeList arg, Edge elem);
EdgeList concatEdgeList(EdgeList arg0, EdgeList arg1);
EdgeList sliceEdgeList(EdgeList arg, int start, int end);
Edge getEdgeListEdgeAt(EdgeList arg, int index);
EdgeList replaceEdgeListEdgeAt(EdgeList arg, Edge elem, int index);
EdgeList makeEdgeList2(Edge elem1, Edge elem2);
EdgeList makeEdgeList3(Edge elem1, Edge elem2, Edge elem3);
EdgeList makeEdgeList4(Edge elem1, Edge elem2, Edge elem3, Edge elem4);
EdgeList makeEdgeList5(Edge elem1, Edge elem2, Edge elem3, Edge elem4, Edge elem5);
EdgeList makeEdgeList6(Edge elem1, Edge elem2, Edge elem3, Edge elem4, Edge elem5, Edge elem6);
int getPolygonLength (Polygon arg);
Polygon reversePolygon(Polygon arg);
Polygon appendPolygon(Polygon arg, Point elem);
Polygon concatPolygon(Polygon arg0, Polygon arg1);
Polygon slicePolygon(Polygon arg, int start, int end);
Point getPolygonPointAt(Polygon arg, int index);
Polygon replacePolygonPointAt(Polygon arg, Point elem, int index);
Polygon makePolygon2(Point elem1, Point elem2);
Polygon makePolygon3(Point elem1, Point elem2, Point elem3);
Polygon makePolygon4(Point elem1, Point elem2, Point elem3, Point elem4);
Polygon makePolygon5(Point elem1, Point elem2, Point elem3, Point elem4, Point elem5);
Polygon makePolygon6(Point elem1, Point elem2, Point elem3, Point elem4, Point elem5, Point elem6);

/*}}}  */
/*{{{  constructors */

Graph makeGraphDefault(NodeList nodes, EdgeList edges, AttributeList attributes);
NodeList makeNodeListEmpty(void);
NodeList makeNodeListSingle(Node head);
NodeList makeNodeListMany(Node head, NodeList tail);
Node makeNodeDefault(NodeId id, AttributeList attributes);
NodeId makeNodeIdDefault(ATerm id);
AttributeList makeAttributeListEmpty(void);
AttributeList makeAttributeListSingle(Attribute head);
AttributeList makeAttributeListMany(Attribute head, AttributeList tail);
Attribute makeAttributeBoundingBox(Point first, Point second);
Attribute makeAttributeColor(Color color);
Attribute makeAttributeCurvePoints(Polygon points);
Attribute makeAttributeDirection(Direction direction);
Attribute makeAttributeFillColor(Color color);
Attribute makeAttributeInfo(const char* key, ATerm value);
Attribute makeAttributeLabel(const char* label);
Attribute makeAttributeLocation(int x, int y);
Attribute makeAttributeShape(Shape shape);
Attribute makeAttributeSize(int width, int height);
Attribute makeAttributeStyle(Style style);
Attribute makeAttributeLevel(const char* level);
Color makeColorRgb(int red, int green, int blue);
Style makeStyleBold(void);
Style makeStyleDashed(void);
Style makeStyleDotted(void);
Style makeStyleFilled(void);
Style makeStyleInvisible(void);
Style makeStyleSolid(void);
Shape makeShapeBox(void);
Shape makeShapeCircle(void);
Shape makeShapeDiamond(void);
Shape makeShapeEgg(void);
Shape makeShapeEllipse(void);
Shape makeShapeHexagon(void);
Shape makeShapeHouse(void);
Shape makeShapeOctagon(void);
Shape makeShapeParallelogram(void);
Shape makeShapePlaintext(void);
Shape makeShapeTrapezium(void);
Shape makeShapeTriangle(void);
Direction makeDirectionForward(void);
Direction makeDirectionBack(void);
Direction makeDirectionBoth(void);
Direction makeDirectionNone(void);
EdgeList makeEdgeListEmpty(void);
EdgeList makeEdgeListSingle(Edge head);
EdgeList makeEdgeListMany(Edge head, EdgeList tail);
Edge makeEdgeDefault(NodeId from, NodeId to, AttributeList attributes);
Polygon makePolygonEmpty(void);
Polygon makePolygonSingle(Point head);
Polygon makePolygonMany(Point head, Polygon tail);
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
ATbool hasGraphEdges(Graph arg);
ATbool hasGraphAttributes(Graph arg);
NodeList getGraphNodes(Graph arg);
EdgeList getGraphEdges(Graph arg);
AttributeList getGraphAttributes(Graph arg);
Graph setGraphNodes(Graph arg, NodeList nodes);
Graph setGraphEdges(Graph arg, EdgeList edges);
Graph setGraphAttributes(Graph arg, AttributeList attributes);

/*}}}  */
/*{{{  NodeList accessors */

ATbool isValidNodeList(NodeList arg);
inline ATbool isNodeListEmpty(NodeList arg);
inline ATbool isNodeListSingle(NodeList arg);
inline ATbool isNodeListMany(NodeList arg);
ATbool hasNodeListHead(NodeList arg);
ATbool hasNodeListTail(NodeList arg);
Node getNodeListHead(NodeList arg);
NodeList getNodeListTail(NodeList arg);
NodeList setNodeListHead(NodeList arg, Node head);
NodeList setNodeListTail(NodeList arg, NodeList tail);

/*}}}  */
/*{{{  Node accessors */

ATbool isValidNode(Node arg);
inline ATbool isNodeDefault(Node arg);
ATbool hasNodeId(Node arg);
ATbool hasNodeAttributes(Node arg);
NodeId getNodeId(Node arg);
AttributeList getNodeAttributes(Node arg);
Node setNodeId(Node arg, NodeId id);
Node setNodeAttributes(Node arg, AttributeList attributes);

/*}}}  */
/*{{{  NodeId accessors */

ATbool isValidNodeId(NodeId arg);
inline ATbool isNodeIdDefault(NodeId arg);
ATbool hasNodeIdId(NodeId arg);
ATerm getNodeIdId(NodeId arg);
NodeId setNodeIdId(NodeId arg, ATerm id);

/*}}}  */
/*{{{  AttributeList accessors */

ATbool isValidAttributeList(AttributeList arg);
inline ATbool isAttributeListEmpty(AttributeList arg);
inline ATbool isAttributeListSingle(AttributeList arg);
inline ATbool isAttributeListMany(AttributeList arg);
ATbool hasAttributeListHead(AttributeList arg);
ATbool hasAttributeListTail(AttributeList arg);
Attribute getAttributeListHead(AttributeList arg);
AttributeList getAttributeListTail(AttributeList arg);
AttributeList setAttributeListHead(AttributeList arg, Attribute head);
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
inline ATbool isAttributeLevel(Attribute arg);
ATbool hasAttributeFirst(Attribute arg);
ATbool hasAttributeSecond(Attribute arg);
ATbool hasAttributeColor(Attribute arg);
ATbool hasAttributePoints(Attribute arg);
ATbool hasAttributeDirection(Attribute arg);
ATbool hasAttributeKey(Attribute arg);
ATbool hasAttributeValue(Attribute arg);
ATbool hasAttributeLabel(Attribute arg);
ATbool hasAttributeX(Attribute arg);
ATbool hasAttributeY(Attribute arg);
ATbool hasAttributeShape(Attribute arg);
ATbool hasAttributeWidth(Attribute arg);
ATbool hasAttributeHeight(Attribute arg);
ATbool hasAttributeStyle(Attribute arg);
ATbool hasAttributeLevel(Attribute arg);
Point getAttributeFirst(Attribute arg);
Point getAttributeSecond(Attribute arg);
Color getAttributeColor(Attribute arg);
Polygon getAttributePoints(Attribute arg);
Direction getAttributeDirection(Attribute arg);
char* getAttributeKey(Attribute arg);
ATerm getAttributeValue(Attribute arg);
char* getAttributeLabel(Attribute arg);
int getAttributeX(Attribute arg);
int getAttributeY(Attribute arg);
Shape getAttributeShape(Attribute arg);
int getAttributeWidth(Attribute arg);
int getAttributeHeight(Attribute arg);
Style getAttributeStyle(Attribute arg);
char* getAttributeLevel(Attribute arg);
Attribute setAttributeFirst(Attribute arg, Point first);
Attribute setAttributeSecond(Attribute arg, Point second);
Attribute setAttributeColor(Attribute arg, Color color);
Attribute setAttributePoints(Attribute arg, Polygon points);
Attribute setAttributeDirection(Attribute arg, Direction direction);
Attribute setAttributeKey(Attribute arg, const char* key);
Attribute setAttributeValue(Attribute arg, ATerm value);
Attribute setAttributeLabel(Attribute arg, const char* label);
Attribute setAttributeX(Attribute arg, int x);
Attribute setAttributeY(Attribute arg, int y);
Attribute setAttributeShape(Attribute arg, Shape shape);
Attribute setAttributeWidth(Attribute arg, int width);
Attribute setAttributeHeight(Attribute arg, int height);
Attribute setAttributeStyle(Attribute arg, Style style);
Attribute setAttributeLevel(Attribute arg, const char* level);

/*}}}  */
/*{{{  Color accessors */

ATbool isValidColor(Color arg);
inline ATbool isColorRgb(Color arg);
ATbool hasColorRed(Color arg);
ATbool hasColorGreen(Color arg);
ATbool hasColorBlue(Color arg);
int getColorRed(Color arg);
int getColorGreen(Color arg);
int getColorBlue(Color arg);
Color setColorRed(Color arg, int red);
Color setColorGreen(Color arg, int green);
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
inline ATbool isEdgeListSingle(EdgeList arg);
inline ATbool isEdgeListMany(EdgeList arg);
ATbool hasEdgeListHead(EdgeList arg);
ATbool hasEdgeListTail(EdgeList arg);
Edge getEdgeListHead(EdgeList arg);
EdgeList getEdgeListTail(EdgeList arg);
EdgeList setEdgeListHead(EdgeList arg, Edge head);
EdgeList setEdgeListTail(EdgeList arg, EdgeList tail);

/*}}}  */
/*{{{  Edge accessors */

ATbool isValidEdge(Edge arg);
inline ATbool isEdgeDefault(Edge arg);
ATbool hasEdgeFrom(Edge arg);
ATbool hasEdgeTo(Edge arg);
ATbool hasEdgeAttributes(Edge arg);
NodeId getEdgeFrom(Edge arg);
NodeId getEdgeTo(Edge arg);
AttributeList getEdgeAttributes(Edge arg);
Edge setEdgeFrom(Edge arg, NodeId from);
Edge setEdgeTo(Edge arg, NodeId to);
Edge setEdgeAttributes(Edge arg, AttributeList attributes);

/*}}}  */
/*{{{  Polygon accessors */

ATbool isValidPolygon(Polygon arg);
inline ATbool isPolygonEmpty(Polygon arg);
inline ATbool isPolygonSingle(Polygon arg);
inline ATbool isPolygonMany(Polygon arg);
ATbool hasPolygonHead(Polygon arg);
ATbool hasPolygonTail(Polygon arg);
Point getPolygonHead(Polygon arg);
Polygon getPolygonTail(Polygon arg);
Polygon setPolygonHead(Polygon arg, Point head);
Polygon setPolygonTail(Polygon arg, Polygon tail);

/*}}}  */
/*{{{  Point accessors */

ATbool isValidPoint(Point arg);
inline ATbool isPointDefault(Point arg);
ATbool hasPointX(Point arg);
ATbool hasPointY(Point arg);
int getPointX(Point arg);
int getPointY(Point arg);
Point setPointX(Point arg, int x);
Point setPointY(Point arg, int y);

/*}}}  */
/*{{{  sort visitors */

Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList), AttributeList (*acceptAttributes)(AttributeList));
NodeList visitNodeList(NodeList arg, Node (*acceptHead)(Node));
Node visitNode(Node arg, NodeId (*acceptId)(NodeId), AttributeList (*acceptAttributes)(AttributeList));
NodeId visitNodeId(NodeId arg, ATerm (*acceptId)(ATerm));
AttributeList visitAttributeList(AttributeList arg, Attribute (*acceptHead)(Attribute));
Attribute visitAttribute(Attribute arg, Point (*acceptFirst)(Point), Point (*acceptSecond)(Point), Color (*acceptColor)(Color), Polygon (*acceptPoints)(Polygon), Direction (*acceptDirection)(Direction), char* (*acceptKey)(char*), ATerm (*acceptValue)(ATerm), char* (*acceptLabel)(char*), int (*acceptX)(int), int (*acceptY)(int), Shape (*acceptShape)(Shape), int (*acceptWidth)(int), int (*acceptHeight)(int), Style (*acceptStyle)(Style), char* (*acceptLevel)(char*));
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
