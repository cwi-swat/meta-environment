#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Graph.h"

/*{{{  conversion functions */

ATerm stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}

char charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

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

/*{{{  protect functions */

void protectGraph(Graph *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectNodeList(NodeList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectNode(Node *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectNodeId(NodeId *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectAttributeList(AttributeList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectAttribute(Attribute *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectColor(Color *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectStyle(Style *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectShape(Shape *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectDirection(Direction *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectEdgeList(EdgeList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectEdge(Edge *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectPolygon(Polygon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void protectPoint(Point *arg)
{
  ATprotect((ATerm*)((void*) arg));
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

int getNodeListLength (NodeList arg) {
  return ATgetLength((ATermList) arg);
}
NodeList reverseNodeList(NodeList arg) {
  return (NodeList) ATreverse((ATermList) arg);
}
NodeList appendNodeList(NodeList arg, Node elem) {
  return (NodeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
NodeList concatNodeList(NodeList arg0, NodeList arg1) {
  return (NodeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
NodeList sliceNodeList(NodeList arg, int start, int end) {
  return (NodeList) ATgetSlice((ATermList) arg, start, end);
}
Node getNodeListNodeAt(NodeList arg, int index) {
 return (Node)ATelementAt((ATermList) arg,index);
}
NodeList replaceNodeListNodeAt(NodeList arg, Node elem, int index) {
 return (NodeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
NodeList makeNodeList2(Node elem1, Node elem2) {
  return (NodeList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
NodeList makeNodeList3(Node elem1, Node elem2, Node elem3) {
  return (NodeList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
NodeList makeNodeList4(Node elem1, Node elem2, Node elem3, Node elem4) {
  return (NodeList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
NodeList makeNodeList5(Node elem1, Node elem2, Node elem3, Node elem4, Node elem5) {
  return (NodeList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
NodeList makeNodeList6(Node elem1, Node elem2, Node elem3, Node elem4, Node elem5, Node elem6) {
  return (NodeList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int getAttributeListLength (AttributeList arg) {
  return ATgetLength((ATermList) arg);
}
AttributeList reverseAttributeList(AttributeList arg) {
  return (AttributeList) ATreverse((ATermList) arg);
}
AttributeList appendAttributeList(AttributeList arg, Attribute elem) {
  return (AttributeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
AttributeList concatAttributeList(AttributeList arg0, AttributeList arg1) {
  return (AttributeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
AttributeList sliceAttributeList(AttributeList arg, int start, int end) {
  return (AttributeList) ATgetSlice((ATermList) arg, start, end);
}
Attribute getAttributeListAttributeAt(AttributeList arg, int index) {
 return (Attribute)ATelementAt((ATermList) arg,index);
}
AttributeList replaceAttributeListAttributeAt(AttributeList arg, Attribute elem, int index) {
 return (AttributeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
AttributeList makeAttributeList2(Attribute elem1, Attribute elem2) {
  return (AttributeList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
AttributeList makeAttributeList3(Attribute elem1, Attribute elem2, Attribute elem3) {
  return (AttributeList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
AttributeList makeAttributeList4(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4) {
  return (AttributeList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
AttributeList makeAttributeList5(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4, Attribute elem5) {
  return (AttributeList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
AttributeList makeAttributeList6(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4, Attribute elem5, Attribute elem6) {
  return (AttributeList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int getEdgeListLength (EdgeList arg) {
  return ATgetLength((ATermList) arg);
}
EdgeList reverseEdgeList(EdgeList arg) {
  return (EdgeList) ATreverse((ATermList) arg);
}
EdgeList appendEdgeList(EdgeList arg, Edge elem) {
  return (EdgeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
EdgeList concatEdgeList(EdgeList arg0, EdgeList arg1) {
  return (EdgeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
EdgeList sliceEdgeList(EdgeList arg, int start, int end) {
  return (EdgeList) ATgetSlice((ATermList) arg, start, end);
}
Edge getEdgeListEdgeAt(EdgeList arg, int index) {
 return (Edge)ATelementAt((ATermList) arg,index);
}
EdgeList replaceEdgeListEdgeAt(EdgeList arg, Edge elem, int index) {
 return (EdgeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
EdgeList makeEdgeList2(Edge elem1, Edge elem2) {
  return (EdgeList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
EdgeList makeEdgeList3(Edge elem1, Edge elem2, Edge elem3) {
  return (EdgeList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
EdgeList makeEdgeList4(Edge elem1, Edge elem2, Edge elem3, Edge elem4) {
  return (EdgeList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
EdgeList makeEdgeList5(Edge elem1, Edge elem2, Edge elem3, Edge elem4, Edge elem5) {
  return (EdgeList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
EdgeList makeEdgeList6(Edge elem1, Edge elem2, Edge elem3, Edge elem4, Edge elem5, Edge elem6) {
  return (EdgeList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int getPolygonLength (Polygon arg) {
  return ATgetLength((ATermList) arg);
}
Polygon reversePolygon(Polygon arg) {
  return (Polygon) ATreverse((ATermList) arg);
}
Polygon appendPolygon(Polygon arg, Point elem) {
  return (Polygon) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
Polygon concatPolygon(Polygon arg0, Polygon arg1) {
  return (Polygon) ATconcat((ATermList) arg0, (ATermList) arg1);
}
Polygon slicePolygon(Polygon arg, int start, int end) {
  return (Polygon) ATgetSlice((ATermList) arg, start, end);
}
Point getPolygonPointAt(Polygon arg, int index) {
 return (Point)ATelementAt((ATermList) arg,index);
}
Polygon replacePolygonPointAt(Polygon arg, Point elem, int index) {
 return (Polygon) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
Polygon makePolygon2(Point elem1, Point elem2) {
  return (Polygon) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
Polygon makePolygon3(Point elem1, Point elem2, Point elem3) {
  return (Polygon) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
Polygon makePolygon4(Point elem1, Point elem2, Point elem3, Point elem4) {
  return (Polygon) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
Polygon makePolygon5(Point elem1, Point elem2, Point elem3, Point elem4, Point elem5) {
  return (Polygon) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
Polygon makePolygon6(Point elem1, Point elem2, Point elem3, Point elem4, Point elem5, Point elem6) {
  return (Polygon) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  Graph makeGraphDefault(NodeList nodes, EdgeList edges, AttributeList attributes) */

Graph makeGraphDefault(NodeList nodes, EdgeList edges, AttributeList attributes)
{
  return (Graph)(ATerm)ATmakeAppl3(afun0, (ATerm) nodes, (ATerm) edges, (ATerm) attributes);
}

/*}}}  */
/*{{{  NodeList makeNodeListEmpty(void) */

NodeList makeNodeListEmpty(void)
{
  return (NodeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  NodeList makeNodeListSingle(Node head) */

NodeList makeNodeListSingle(Node head)
{
  return (NodeList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  NodeList makeNodeListMany(Node head, NodeList tail) */

NodeList makeNodeListMany(Node head, NodeList tail)
{
  return (NodeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  Node makeNodeDefault(NodeId id, AttributeList attributes) */

Node makeNodeDefault(NodeId id, AttributeList attributes)
{
  return (Node)(ATerm)ATmakeAppl2(afun1, (ATerm) id, (ATerm) attributes);
}

/*}}}  */
/*{{{  NodeId makeNodeIdDefault(const char* id) */

NodeId makeNodeIdDefault(const char* id)
{
  return (NodeId)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue));
}

/*}}}  */
/*{{{  AttributeList makeAttributeListEmpty(void) */

AttributeList makeAttributeListEmpty(void)
{
  return (AttributeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  AttributeList makeAttributeListSingle(Attribute head) */

AttributeList makeAttributeListSingle(Attribute head)
{
  return (AttributeList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  AttributeList makeAttributeListMany(Attribute head, AttributeList tail) */

AttributeList makeAttributeListMany(Attribute head, AttributeList tail)
{
  return (AttributeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  Attribute makeAttributeBoundingBox(Point first, Point second) */

Attribute makeAttributeBoundingBox(Point first, Point second)
{
  return (Attribute)(ATerm)ATmakeAppl2(afun2, (ATerm) first, (ATerm) second);
}

/*}}}  */
/*{{{  Attribute makeAttributeColor(Color color) */

Attribute makeAttributeColor(Color color)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun3, (ATerm) color);
}

/*}}}  */
/*{{{  Attribute makeAttributeCurvePoints(Polygon points) */

Attribute makeAttributeCurvePoints(Polygon points)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun4, (ATerm) points);
}

/*}}}  */
/*{{{  Attribute makeAttributeDirection(Direction direction) */

Attribute makeAttributeDirection(Direction direction)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun5, (ATerm) direction);
}

/*}}}  */
/*{{{  Attribute makeAttributeFillColor(Color color) */

Attribute makeAttributeFillColor(Color color)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun6, (ATerm) color);
}

/*}}}  */
/*{{{  Attribute makeAttributeInfo(const char* key, ATerm value) */

Attribute makeAttributeInfo(const char* key, ATerm value)
{
  return (Attribute)(ATerm)ATmakeAppl2(afun7, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(key, 0, ATtrue)), (ATerm) value);
}

/*}}}  */
/*{{{  Attribute makeAttributeLabel(const char* label) */

Attribute makeAttributeLabel(const char* label)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun8, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue)));
}

/*}}}  */
/*{{{  Attribute makeAttributeLocation(int x, int y) */

Attribute makeAttributeLocation(int x, int y)
{
  return (Attribute)(ATerm)ATmakeAppl2(afun9, (ATerm) (ATerm) ATmakeInt(x), (ATerm) (ATerm) ATmakeInt(y));
}

/*}}}  */
/*{{{  Attribute makeAttributeShape(Shape shape) */

Attribute makeAttributeShape(Shape shape)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun10, (ATerm) shape);
}

/*}}}  */
/*{{{  Attribute makeAttributeSize(int width, int height) */

Attribute makeAttributeSize(int width, int height)
{
  return (Attribute)(ATerm)ATmakeAppl2(afun11, (ATerm) (ATerm) ATmakeInt(width), (ATerm) (ATerm) ATmakeInt(height));
}

/*}}}  */
/*{{{  Attribute makeAttributeStyle(Style style) */

Attribute makeAttributeStyle(Style style)
{
  return (Attribute)(ATerm)ATmakeAppl1(afun12, (ATerm) style);
}

/*}}}  */
/*{{{  Color makeColorRgb(int red, int green, int blue) */

Color makeColorRgb(int red, int green, int blue)
{
  return (Color)(ATerm)ATmakeAppl3(afun13, (ATerm) (ATerm) ATmakeInt(red), (ATerm) (ATerm) ATmakeInt(green), (ATerm) (ATerm) ATmakeInt(blue));
}

/*}}}  */
/*{{{  Style makeStyleBold(void) */

Style makeStyleBold(void)
{
  return (Style)(ATerm)ATmakeAppl0(afun14);
}

/*}}}  */
/*{{{  Style makeStyleDashed(void) */

Style makeStyleDashed(void)
{
  return (Style)(ATerm)ATmakeAppl0(afun15);
}

/*}}}  */
/*{{{  Style makeStyleDotted(void) */

Style makeStyleDotted(void)
{
  return (Style)(ATerm)ATmakeAppl0(afun16);
}

/*}}}  */
/*{{{  Style makeStyleFilled(void) */

Style makeStyleFilled(void)
{
  return (Style)(ATerm)ATmakeAppl0(afun17);
}

/*}}}  */
/*{{{  Style makeStyleInvisible(void) */

Style makeStyleInvisible(void)
{
  return (Style)(ATerm)ATmakeAppl0(afun18);
}

/*}}}  */
/*{{{  Style makeStyleSolid(void) */

Style makeStyleSolid(void)
{
  return (Style)(ATerm)ATmakeAppl0(afun19);
}

/*}}}  */
/*{{{  Shape makeShapeBox(void) */

Shape makeShapeBox(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun20);
}

/*}}}  */
/*{{{  Shape makeShapeCircle(void) */

Shape makeShapeCircle(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun21);
}

/*}}}  */
/*{{{  Shape makeShapeDiamond(void) */

Shape makeShapeDiamond(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun22);
}

/*}}}  */
/*{{{  Shape makeShapeEgg(void) */

Shape makeShapeEgg(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun23);
}

/*}}}  */
/*{{{  Shape makeShapeEllipse(void) */

Shape makeShapeEllipse(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun24);
}

/*}}}  */
/*{{{  Shape makeShapeHexagon(void) */

Shape makeShapeHexagon(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun25);
}

/*}}}  */
/*{{{  Shape makeShapeHouse(void) */

Shape makeShapeHouse(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun26);
}

/*}}}  */
/*{{{  Shape makeShapeOctagon(void) */

Shape makeShapeOctagon(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun27);
}

/*}}}  */
/*{{{  Shape makeShapeParallelogram(void) */

Shape makeShapeParallelogram(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun28);
}

/*}}}  */
/*{{{  Shape makeShapePlaintext(void) */

Shape makeShapePlaintext(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun29);
}

/*}}}  */
/*{{{  Shape makeShapeTrapezium(void) */

Shape makeShapeTrapezium(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun30);
}

/*}}}  */
/*{{{  Shape makeShapeTriangle(void) */

Shape makeShapeTriangle(void)
{
  return (Shape)(ATerm)ATmakeAppl0(afun31);
}

/*}}}  */
/*{{{  Direction makeDirectionForward(void) */

Direction makeDirectionForward(void)
{
  return (Direction)(ATerm)ATmakeAppl0(afun32);
}

/*}}}  */
/*{{{  Direction makeDirectionBack(void) */

Direction makeDirectionBack(void)
{
  return (Direction)(ATerm)ATmakeAppl0(afun33);
}

/*}}}  */
/*{{{  Direction makeDirectionBoth(void) */

Direction makeDirectionBoth(void)
{
  return (Direction)(ATerm)ATmakeAppl0(afun34);
}

/*}}}  */
/*{{{  Direction makeDirectionNone(void) */

Direction makeDirectionNone(void)
{
  return (Direction)(ATerm)ATmakeAppl0(afun35);
}

/*}}}  */
/*{{{  EdgeList makeEdgeListEmpty(void) */

EdgeList makeEdgeListEmpty(void)
{
  return (EdgeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  EdgeList makeEdgeListSingle(Edge head) */

EdgeList makeEdgeListSingle(Edge head)
{
  return (EdgeList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  EdgeList makeEdgeListMany(Edge head, EdgeList tail) */

EdgeList makeEdgeListMany(Edge head, EdgeList tail)
{
  return (EdgeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  Edge makeEdgeDefault(NodeId from, NodeId to, AttributeList attributes) */

Edge makeEdgeDefault(NodeId from, NodeId to, AttributeList attributes)
{
  return (Edge)(ATerm)ATmakeAppl3(afun36, (ATerm) from, (ATerm) to, (ATerm) attributes);
}

/*}}}  */
/*{{{  Polygon makePolygonEmpty(void) */

Polygon makePolygonEmpty(void)
{
  return (Polygon)(ATerm)ATempty;
}

/*}}}  */
/*{{{  Polygon makePolygonSingle(Point head) */

Polygon makePolygonSingle(Point head)
{
  return (Polygon)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  Polygon makePolygonMany(Point head, Polygon tail) */

Polygon makePolygonMany(Point head, Polygon tail)
{
  return (Polygon)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  Point makePointDefault(int x, int y) */

Point makePointDefault(int x, int y)
{
  return (Point)(ATerm)ATmakeAppl2(afun37, (ATerm) (ATerm) ATmakeInt(x), (ATerm) (ATerm) ATmakeInt(y));
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
/*{{{  ATbool hasGraphEdges(Graph arg) */

ATbool hasGraphEdges(Graph arg)
{
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  NodeList getGraphNodes(Graph arg) */

NodeList getGraphNodes(Graph arg)
{
  
    return (NodeList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  EdgeList getGraphEdges(Graph arg) */

EdgeList getGraphEdges(Graph arg)
{
  
    return (EdgeList)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  AttributeList getGraphAttributes(Graph arg) */

AttributeList getGraphAttributes(Graph arg)
{
  
    return (AttributeList)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  Graph setGraphNodes(Graph arg, NodeList nodes) */

Graph setGraphNodes(Graph arg, NodeList nodes)
{
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) nodes), 0);
  }

  ATabort("Graph has no Nodes: %t\n", arg);
  return (Graph)NULL;
}

/*}}}  */
/*{{{  Graph setGraphEdges(Graph arg, EdgeList edges) */

Graph setGraphEdges(Graph arg, EdgeList edges)
{
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) edges), 1);
  }

  ATabort("Graph has no Edges: %t\n", arg);
  return (Graph)NULL;
}

/*}}}  */
/*{{{  Graph setGraphAttributes(Graph arg, AttributeList attributes) */

Graph setGraphAttributes(Graph arg, AttributeList attributes)
{
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 2);
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
  else if (isNodeListSingle(arg)) {
    return ATtrue;
  }
  else if (isNodeListMany(arg)) {
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
/*{{{  inline ATbool isNodeListSingle(NodeList arg) */

inline ATbool isNodeListSingle(NodeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternNodeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isNodeListMany(NodeList arg) */

inline ATbool isNodeListMany(NodeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternNodeListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool hasNodeListHead(NodeList arg) */

ATbool hasNodeListHead(NodeList arg)
{
  if (isNodeListSingle(arg)) {
    return ATtrue;
  }
  else if (isNodeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool hasNodeListTail(NodeList arg) */

ATbool hasNodeListTail(NodeList arg)
{
  if (isNodeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Node getNodeListHead(NodeList arg) */

Node getNodeListHead(NodeList arg)
{
  if (isNodeListSingle(arg)) {
    return (Node)ATgetFirst((ATermList)arg);
  }
  else 
    return (Node)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  NodeList getNodeListTail(NodeList arg) */

NodeList getNodeListTail(NodeList arg)
{
  
    return (NodeList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  NodeList setNodeListHead(NodeList arg, Node head) */

NodeList setNodeListHead(NodeList arg, Node head)
{
  if (isNodeListSingle(arg)) {
    return (NodeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (isNodeListMany(arg)) {
    return (NodeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("NodeList has no Head: %t\n", arg);
  return (NodeList)NULL;
}

/*}}}  */
/*{{{  NodeList setNodeListTail(NodeList arg, NodeList tail) */

NodeList setNodeListTail(NodeList arg, NodeList tail)
{
  if (isNodeListMany(arg)) {
    return (NodeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
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
/*{{{  ATbool hasNodeAttributes(Node arg) */

ATbool hasNodeAttributes(Node arg)
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
/*{{{  AttributeList getNodeAttributes(Node arg) */

AttributeList getNodeAttributes(Node arg)
{
  
    return (AttributeList)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  Node setNodeId(Node arg, NodeId id) */

Node setNodeId(Node arg, NodeId id)
{
  if (isNodeDefault(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) id), 0);
  }

  ATabort("Node has no Id: %t\n", arg);
  return (Node)NULL;
}

/*}}}  */
/*{{{  Node setNodeAttributes(Node arg, AttributeList attributes) */

Node setNodeAttributes(Node arg, AttributeList attributes)
{
  if (isNodeDefault(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 1);
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
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/*}}}  */
/*{{{  NodeId setNodeIdId(NodeId arg, const char* id) */

NodeId setNodeIdId(NodeId arg, const char* id)
{
  if (isNodeIdDefault(arg)) {
    return (NodeId)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)));
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
  else if (isAttributeListSingle(arg)) {
    return ATtrue;
  }
  else if (isAttributeListMany(arg)) {
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
/*{{{  inline ATbool isAttributeListSingle(AttributeList arg) */

inline ATbool isAttributeListSingle(AttributeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isAttributeListMany(AttributeList arg) */

inline ATbool isAttributeListMany(AttributeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool hasAttributeListHead(AttributeList arg) */

ATbool hasAttributeListHead(AttributeList arg)
{
  if (isAttributeListSingle(arg)) {
    return ATtrue;
  }
  else if (isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool hasAttributeListTail(AttributeList arg) */

ATbool hasAttributeListTail(AttributeList arg)
{
  if (isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Attribute getAttributeListHead(AttributeList arg) */

Attribute getAttributeListHead(AttributeList arg)
{
  if (isAttributeListSingle(arg)) {
    return (Attribute)ATgetFirst((ATermList)arg);
  }
  else 
    return (Attribute)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  AttributeList getAttributeListTail(AttributeList arg) */

AttributeList getAttributeListTail(AttributeList arg)
{
  
    return (AttributeList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  AttributeList setAttributeListHead(AttributeList arg, Attribute head) */

AttributeList setAttributeListHead(AttributeList arg, Attribute head)
{
  if (isAttributeListSingle(arg)) {
    return (AttributeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (isAttributeListMany(arg)) {
    return (AttributeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("AttributeList has no Head: %t\n", arg);
  return (AttributeList)NULL;
}

/*}}}  */
/*{{{  AttributeList setAttributeListTail(AttributeList arg, AttributeList tail) */

AttributeList setAttributeListTail(AttributeList arg, AttributeList tail)
{
  if (isAttributeListMany(arg)) {
    return (AttributeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
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
/*{{{  ATbool hasAttributeSecond(Attribute arg) */

ATbool hasAttributeSecond(Attribute arg)
{
  if (isAttributeBoundingBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool hasAttributePoints(Attribute arg) */

ATbool hasAttributePoints(Attribute arg)
{
  if (isAttributeCurvePoints(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool hasAttributeKey(Attribute arg) */

ATbool hasAttributeKey(Attribute arg)
{
  if (isAttributeInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool hasAttributeLabel(Attribute arg) */

ATbool hasAttributeLabel(Attribute arg)
{
  if (isAttributeLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool hasAttributeY(Attribute arg) */

ATbool hasAttributeY(Attribute arg)
{
  if (isAttributeLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool hasAttributeWidth(Attribute arg) */

ATbool hasAttributeWidth(Attribute arg)
{
  if (isAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool hasAttributeStyle(Attribute arg) */

ATbool hasAttributeStyle(Attribute arg)
{
  if (isAttributeStyle(arg)) {
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
/*{{{  Point getAttributeSecond(Attribute arg) */

Point getAttributeSecond(Attribute arg)
{
  
    return (Point)ATgetArgument((ATermAppl)arg, 1);
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
/*{{{  Polygon getAttributePoints(Attribute arg) */

Polygon getAttributePoints(Attribute arg)
{
  
    return (Polygon)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Direction getAttributeDirection(Attribute arg) */

Direction getAttributeDirection(Attribute arg)
{
  
    return (Direction)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* getAttributeKey(Attribute arg) */

char* getAttributeKey(Attribute arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ATerm getAttributeValue(Attribute arg) */

ATerm getAttributeValue(Attribute arg)
{
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  char* getAttributeLabel(Attribute arg) */

char* getAttributeLabel(Attribute arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  int getAttributeX(Attribute arg) */

int getAttributeX(Attribute arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int getAttributeY(Attribute arg) */

int getAttributeY(Attribute arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  Shape getAttributeShape(Attribute arg) */

Shape getAttributeShape(Attribute arg)
{
  
    return (Shape)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  int getAttributeWidth(Attribute arg) */

int getAttributeWidth(Attribute arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int getAttributeHeight(Attribute arg) */

int getAttributeHeight(Attribute arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  Style getAttributeStyle(Attribute arg) */

Style getAttributeStyle(Attribute arg)
{
  
    return (Style)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  Attribute setAttributeFirst(Attribute arg, Point first) */

Attribute setAttributeFirst(Attribute arg, Point first)
{
  if (isAttributeBoundingBox(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) first), 0);
  }

  ATabort("Attribute has no First: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeSecond(Attribute arg, Point second) */

Attribute setAttributeSecond(Attribute arg, Point second)
{
  if (isAttributeBoundingBox(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) second), 1);
  }

  ATabort("Attribute has no Second: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeColor(Attribute arg, Color color) */

Attribute setAttributeColor(Attribute arg, Color color)
{
  if (isAttributeColor(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }
  else if (isAttributeFillColor(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }

  ATabort("Attribute has no Color: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributePoints(Attribute arg, Polygon points) */

Attribute setAttributePoints(Attribute arg, Polygon points)
{
  if (isAttributeCurvePoints(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) points), 0);
  }

  ATabort("Attribute has no Points: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeDirection(Attribute arg, Direction direction) */

Attribute setAttributeDirection(Attribute arg, Direction direction)
{
  if (isAttributeDirection(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) direction), 0);
  }

  ATabort("Attribute has no Direction: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeKey(Attribute arg, const char* key) */

Attribute setAttributeKey(Attribute arg, const char* key)
{
  if (isAttributeInfo(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(key, 0, ATtrue))), 0);
  }

  ATabort("Attribute has no Key: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeValue(Attribute arg, ATerm value) */

Attribute setAttributeValue(Attribute arg, ATerm value)
{
  if (isAttributeInfo(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) value), 1);
  }

  ATabort("Attribute has no Value: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeLabel(Attribute arg, const char* label) */

Attribute setAttributeLabel(Attribute arg, const char* label)
{
  if (isAttributeLabel(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue))), 0);
  }

  ATabort("Attribute has no Label: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeX(Attribute arg, int x) */

Attribute setAttributeX(Attribute arg, int x)
{
  if (isAttributeLocation(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(x)), 0);
  }

  ATabort("Attribute has no X: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeY(Attribute arg, int y) */

Attribute setAttributeY(Attribute arg, int y)
{
  if (isAttributeLocation(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(y)), 1);
  }

  ATabort("Attribute has no Y: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeShape(Attribute arg, Shape shape) */

Attribute setAttributeShape(Attribute arg, Shape shape)
{
  if (isAttributeShape(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) shape), 0);
  }

  ATabort("Attribute has no Shape: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeWidth(Attribute arg, int width) */

Attribute setAttributeWidth(Attribute arg, int width)
{
  if (isAttributeSize(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(width)), 0);
  }

  ATabort("Attribute has no Width: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeHeight(Attribute arg, int height) */

Attribute setAttributeHeight(Attribute arg, int height)
{
  if (isAttributeSize(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(height)), 1);
  }

  ATabort("Attribute has no Height: %t\n", arg);
  return (Attribute)NULL;
}

/*}}}  */
/*{{{  Attribute setAttributeStyle(Attribute arg, Style style) */

Attribute setAttributeStyle(Attribute arg, Style style)
{
  if (isAttributeStyle(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) style), 0);
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
/*{{{  ATbool hasColorGreen(Color arg) */

ATbool hasColorGreen(Color arg)
{
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  int getColorRed(Color arg) */

int getColorRed(Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int getColorGreen(Color arg) */

int getColorGreen(Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  int getColorBlue(Color arg) */

int getColorBlue(Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  Color setColorRed(Color arg, int red) */

Color setColorRed(Color arg, int red)
{
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(red)), 0);
  }

  ATabort("Color has no Red: %t\n", arg);
  return (Color)NULL;
}

/*}}}  */
/*{{{  Color setColorGreen(Color arg, int green) */

Color setColorGreen(Color arg, int green)
{
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(green)), 1);
  }

  ATabort("Color has no Green: %t\n", arg);
  return (Color)NULL;
}

/*}}}  */
/*{{{  Color setColorBlue(Color arg, int blue) */

Color setColorBlue(Color arg, int blue)
{
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(blue)), 2);
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
  else if (isEdgeListSingle(arg)) {
    return ATtrue;
  }
  else if (isEdgeListMany(arg)) {
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
/*{{{  inline ATbool isEdgeListSingle(EdgeList arg) */

inline ATbool isEdgeListSingle(EdgeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternEdgeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isEdgeListMany(EdgeList arg) */

inline ATbool isEdgeListMany(EdgeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternEdgeListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool hasEdgeListHead(EdgeList arg) */

ATbool hasEdgeListHead(EdgeList arg)
{
  if (isEdgeListSingle(arg)) {
    return ATtrue;
  }
  else if (isEdgeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool hasEdgeListTail(EdgeList arg) */

ATbool hasEdgeListTail(EdgeList arg)
{
  if (isEdgeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Edge getEdgeListHead(EdgeList arg) */

Edge getEdgeListHead(EdgeList arg)
{
  if (isEdgeListSingle(arg)) {
    return (Edge)ATgetFirst((ATermList)arg);
  }
  else 
    return (Edge)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  EdgeList getEdgeListTail(EdgeList arg) */

EdgeList getEdgeListTail(EdgeList arg)
{
  
    return (EdgeList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  EdgeList setEdgeListHead(EdgeList arg, Edge head) */

EdgeList setEdgeListHead(EdgeList arg, Edge head)
{
  if (isEdgeListSingle(arg)) {
    return (EdgeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (isEdgeListMany(arg)) {
    return (EdgeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("EdgeList has no Head: %t\n", arg);
  return (EdgeList)NULL;
}

/*}}}  */
/*{{{  EdgeList setEdgeListTail(EdgeList arg, EdgeList tail) */

EdgeList setEdgeListTail(EdgeList arg, EdgeList tail)
{
  if (isEdgeListMany(arg)) {
    return (EdgeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
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
/*{{{  ATbool hasEdgeTo(Edge arg) */

ATbool hasEdgeTo(Edge arg)
{
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  NodeId getEdgeFrom(Edge arg) */

NodeId getEdgeFrom(Edge arg)
{
  
    return (NodeId)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  NodeId getEdgeTo(Edge arg) */

NodeId getEdgeTo(Edge arg)
{
  
    return (NodeId)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  AttributeList getEdgeAttributes(Edge arg) */

AttributeList getEdgeAttributes(Edge arg)
{
  
    return (AttributeList)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  Edge setEdgeFrom(Edge arg, NodeId from) */

Edge setEdgeFrom(Edge arg, NodeId from)
{
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) from), 0);
  }

  ATabort("Edge has no From: %t\n", arg);
  return (Edge)NULL;
}

/*}}}  */
/*{{{  Edge setEdgeTo(Edge arg, NodeId to) */

Edge setEdgeTo(Edge arg, NodeId to)
{
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) to), 1);
  }

  ATabort("Edge has no To: %t\n", arg);
  return (Edge)NULL;
}

/*}}}  */
/*{{{  Edge setEdgeAttributes(Edge arg, AttributeList attributes) */

Edge setEdgeAttributes(Edge arg, AttributeList attributes)
{
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 2);
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
  else if (isPolygonSingle(arg)) {
    return ATtrue;
  }
  else if (isPolygonMany(arg)) {
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
/*{{{  inline ATbool isPolygonSingle(Polygon arg) */

inline ATbool isPolygonSingle(Polygon arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternPolygonSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool isPolygonMany(Polygon arg) */

inline ATbool isPolygonMany(Polygon arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternPolygonMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool hasPolygonHead(Polygon arg) */

ATbool hasPolygonHead(Polygon arg)
{
  if (isPolygonSingle(arg)) {
    return ATtrue;
  }
  else if (isPolygonMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool hasPolygonTail(Polygon arg) */

ATbool hasPolygonTail(Polygon arg)
{
  if (isPolygonMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  Point getPolygonHead(Polygon arg) */

Point getPolygonHead(Polygon arg)
{
  if (isPolygonSingle(arg)) {
    return (Point)ATgetFirst((ATermList)arg);
  }
  else 
    return (Point)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  Polygon getPolygonTail(Polygon arg) */

Polygon getPolygonTail(Polygon arg)
{
  
    return (Polygon)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  Polygon setPolygonHead(Polygon arg, Point head) */

Polygon setPolygonHead(Polygon arg, Point head)
{
  if (isPolygonSingle(arg)) {
    return (Polygon)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (isPolygonMany(arg)) {
    return (Polygon)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Polygon has no Head: %t\n", arg);
  return (Polygon)NULL;
}

/*}}}  */
/*{{{  Polygon setPolygonTail(Polygon arg, Polygon tail) */

Polygon setPolygonTail(Polygon arg, Polygon tail)
{
  if (isPolygonMany(arg)) {
    return (Polygon)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
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
/*{{{  ATbool hasPointY(Point arg) */

ATbool hasPointY(Point arg)
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
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int getPointY(Point arg) */

int getPointY(Point arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  Point setPointX(Point arg, int x) */

Point setPointX(Point arg, int x)
{
  if (isPointDefault(arg)) {
    return (Point)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(x)), 0);
  }

  ATabort("Point has no X: %t\n", arg);
  return (Point)NULL;
}

/*}}}  */
/*{{{  Point setPointY(Point arg, int y) */

Point setPointY(Point arg, int y)
{
  if (isPointDefault(arg)) {
    return (Point)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(y)), 1);
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
  if (isNodeListSingle(arg)) {
    return makeNodeListSingle(
        acceptHead ? acceptHead(getNodeListHead(arg)) : getNodeListHead(arg));
  }
  if (isNodeListMany(arg)) {
    return makeNodeListMany(
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
  if (isAttributeListSingle(arg)) {
    return makeAttributeListSingle(
        acceptHead ? acceptHead(getAttributeListHead(arg)) : getAttributeListHead(arg));
  }
  if (isAttributeListMany(arg)) {
    return makeAttributeListMany(
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
  if (isEdgeListSingle(arg)) {
    return makeEdgeListSingle(
        acceptHead ? acceptHead(getEdgeListHead(arg)) : getEdgeListHead(arg));
  }
  if (isEdgeListMany(arg)) {
    return makeEdgeListMany(
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
  if (isPolygonSingle(arg)) {
    return makePolygonSingle(
        acceptHead ? acceptHead(getPolygonHead(arg)) : getPolygonHead(arg));
  }
  if (isPolygonMany(arg)) {
    return makePolygonMany(
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
