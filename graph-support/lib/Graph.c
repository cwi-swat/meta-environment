#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Graph.h"

/**
 * Converts a string to an ATermList of integers (ASCII values). 
 * \param[in] str An ASCII string
 * \return An ATermList containing the ASCII values of #arg as ATermInts
 */
ATerm stringToChars(const char *str) {
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

/**
 * Converts an ASCII char to an ATermInt. 
 * \param[in] ch an ASCII character
 * \return An ATerm representing the ASCII value of #arg
 */
ATerm byteToChar(char ch) {
    return (ATerm) ATmakeInt(ch);
}

/**
 * Converts a list of integers (ASCII values) to a C string. 
 * \param[in] arg An ATermList with ATermInts, such as [32,32,10]
 * \return String containing the characters from #arg as characters
 */
char *charsToString(ATerm arg) {
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

char charToByte(ATerm arg) {
    return (char) ATgetInt((ATermInt) arg);
}


typedef struct ATerm _Graph;
typedef struct ATerm _NodeList;
typedef struct ATerm _Node;
typedef struct ATerm _NodeId;
typedef struct ATerm _AttributeList;
typedef struct ATerm _Attribute;
typedef struct ATerm _File;
typedef struct ATerm _Color;
typedef struct ATerm _Style;
typedef struct ATerm _Shape;
typedef struct ATerm _Direction;
typedef struct ATerm _EdgeList;
typedef struct ATerm _Edge;
typedef struct ATerm _Polygon;
typedef struct ATerm _Point;

/**
 * Initializes the full API. Forgetting to call this function before using the API will lead to strange behaviour. ATinit() needs to be called before this function.
 */
void initGraphApi(void) {
  init_Graph_dict();
}

/**
 * Protect a Graph from the ATerm garbage collector. Every Graph that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Graph
 */
void protectGraph(Graph *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Graph from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Graph
 */
void unprotectGraph(Graph *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a NodeList from the ATerm garbage collector. Every NodeList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a NodeList
 */
void protectNodeList(NodeList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a NodeList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a NodeList
 */
void unprotectNodeList(NodeList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Node from the ATerm garbage collector. Every Node that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Node
 */
void protectNode(Node *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Node from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Node
 */
void unprotectNode(Node *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a NodeId from the ATerm garbage collector. Every NodeId that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a NodeId
 */
void protectNodeId(NodeId *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a NodeId from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a NodeId
 */
void unprotectNodeId(NodeId *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a AttributeList from the ATerm garbage collector. Every AttributeList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a AttributeList
 */
void protectAttributeList(AttributeList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a AttributeList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a AttributeList
 */
void unprotectAttributeList(AttributeList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Attribute from the ATerm garbage collector. Every Attribute that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Attribute
 */
void protectAttribute(Attribute *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Attribute from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Attribute
 */
void unprotectAttribute(Attribute *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a File from the ATerm garbage collector. Every File that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a File
 */
void protectFile(File *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a File from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a File
 */
void unprotectFile(File *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Color from the ATerm garbage collector. Every Color that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Color
 */
void protectColor(Color *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Color from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Color
 */
void unprotectColor(Color *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Style from the ATerm garbage collector. Every Style that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Style
 */
void protectStyle(Style *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Style from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Style
 */
void unprotectStyle(Style *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Shape from the ATerm garbage collector. Every Shape that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Shape
 */
void protectShape(Shape *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Shape from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Shape
 */
void unprotectShape(Shape *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Direction from the ATerm garbage collector. Every Direction that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Direction
 */
void protectDirection(Direction *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Direction from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Direction
 */
void unprotectDirection(Direction *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a EdgeList from the ATerm garbage collector. Every EdgeList that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a EdgeList
 */
void protectEdgeList(EdgeList *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a EdgeList from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a EdgeList
 */
void unprotectEdgeList(EdgeList *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Edge from the ATerm garbage collector. Every Edge that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Edge
 */
void protectEdge(Edge *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Edge from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Edge
 */
void unprotectEdge(Edge *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Polygon from the ATerm garbage collector. Every Polygon that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Polygon
 */
void protectPolygon(Polygon *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Polygon from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Polygon
 */
void unprotectPolygon(Polygon *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Protect a Point from the ATerm garbage collector. Every Point that is not rooted somewhere on the C call stack must be protected. Examples are global variables
 * \param[in] arg pointer to a Point
 */
void protectPoint(Point *arg) {
  ATprotect((ATerm*)((void*) arg));
}

/**
 * Unprotect a Point from the ATerm garbage collector. This improves the efficiency of the garbage collector, as well as provide opportunity for reclaiming space
 * \param[in] arg pointer to a Point
 */
void unprotectPoint(Point *arg) {
  ATunprotect((ATerm*)((void*) arg));
}

/**
 * Transforms an ATerm to a Graph. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Graph that was encoded by \arg
 */
Graph GraphFromTerm(ATerm t) {
  return (Graph)t;
}

/**
 * Transforms a Graphto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Graph to be converted
 * \return ATerm that represents the Graph
 */
ATerm GraphToTerm(Graph arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a NodeList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return NodeList that was encoded by \arg
 */
NodeList NodeListFromTerm(ATerm t) {
  return (NodeList)t;
}

/**
 * Transforms a NodeListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg NodeList to be converted
 * \return ATerm that represents the NodeList
 */
ATerm NodeListToTerm(NodeList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Node. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Node that was encoded by \arg
 */
Node NodeFromTerm(ATerm t) {
  return (Node)t;
}

/**
 * Transforms a Nodeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Node to be converted
 * \return ATerm that represents the Node
 */
ATerm NodeToTerm(Node arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a NodeId. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return NodeId that was encoded by \arg
 */
NodeId NodeIdFromTerm(ATerm t) {
  return (NodeId)t;
}

/**
 * Transforms a NodeIdto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg NodeId to be converted
 * \return ATerm that represents the NodeId
 */
ATerm NodeIdToTerm(NodeId arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a AttributeList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return AttributeList that was encoded by \arg
 */
AttributeList AttributeListFromTerm(ATerm t) {
  return (AttributeList)t;
}

/**
 * Transforms a AttributeListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg AttributeList to be converted
 * \return ATerm that represents the AttributeList
 */
ATerm AttributeListToTerm(AttributeList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Attribute. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Attribute that was encoded by \arg
 */
Attribute AttributeFromTerm(ATerm t) {
  return (Attribute)t;
}

/**
 * Transforms a Attributeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Attribute to be converted
 * \return ATerm that represents the Attribute
 */
ATerm AttributeToTerm(Attribute arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a File. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return File that was encoded by \arg
 */
File FileFromTerm(ATerm t) {
  return (File)t;
}

/**
 * Transforms a Fileto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg File to be converted
 * \return ATerm that represents the File
 */
ATerm FileToTerm(File arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Color. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Color that was encoded by \arg
 */
Color ColorFromTerm(ATerm t) {
  return (Color)t;
}

/**
 * Transforms a Colorto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Color to be converted
 * \return ATerm that represents the Color
 */
ATerm ColorToTerm(Color arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Style. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Style that was encoded by \arg
 */
Style StyleFromTerm(ATerm t) {
  return (Style)t;
}

/**
 * Transforms a Styleto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Style to be converted
 * \return ATerm that represents the Style
 */
ATerm StyleToTerm(Style arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Shape. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Shape that was encoded by \arg
 */
Shape ShapeFromTerm(ATerm t) {
  return (Shape)t;
}

/**
 * Transforms a Shapeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Shape to be converted
 * \return ATerm that represents the Shape
 */
ATerm ShapeToTerm(Shape arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Direction. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Direction that was encoded by \arg
 */
Direction DirectionFromTerm(ATerm t) {
  return (Direction)t;
}

/**
 * Transforms a Directionto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Direction to be converted
 * \return ATerm that represents the Direction
 */
ATerm DirectionToTerm(Direction arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a EdgeList. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return EdgeList that was encoded by \arg
 */
EdgeList EdgeListFromTerm(ATerm t) {
  return (EdgeList)t;
}

/**
 * Transforms a EdgeListto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg EdgeList to be converted
 * \return ATerm that represents the EdgeList
 */
ATerm EdgeListToTerm(EdgeList arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Edge. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Edge that was encoded by \arg
 */
Edge EdgeFromTerm(ATerm t) {
  return (Edge)t;
}

/**
 * Transforms a Edgeto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Edge to be converted
 * \return ATerm that represents the Edge
 */
ATerm EdgeToTerm(Edge arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Polygon. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Polygon that was encoded by \arg
 */
Polygon PolygonFromTerm(ATerm t) {
  return (Polygon)t;
}

/**
 * Transforms a Polygonto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Polygon to be converted
 * \return ATerm that represents the Polygon
 */
ATerm PolygonToTerm(Polygon arg) {
  return (ATerm)arg;
}

/**
 * Transforms an ATerm to a Point. This is just a wrapper for a cast, so no structural validation is done!
 * \param[in] t ATerm to be converted
 * \return Point that was encoded by \arg
 */
Point PointFromTerm(ATerm t) {
  return (Point)t;
}

/**
 * Transforms a Pointto an ATerm. This is just a wrapper for a cast.
 * \param[in] arg Point to be converted
 * \return ATerm that represents the Point
 */
ATerm PointToTerm(Point arg) {
  return (ATerm)arg;
}

/**
 * Retrieve the length of a NodeList. 
 * \param[in] arg input NodeList
 * \return The number of elements in the NodeList
 */
int getNodeListLength (NodeList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a NodeList. 
 * \param[in] arg NodeList to be reversed
 * \return a reversed #arg
 */
NodeList reverseNodeList(NodeList arg) {
  return (NodeList) ATreverse((ATermList) arg);
}

/**
 * Append a Node to the end of a NodeList. 
 * \param[in] arg NodeList to append the Node to
 * \param[in] elem Node to be appended
 * \return new NodeList with #elem appended
 */
NodeList appendNodeList(NodeList arg, Node elem) {
  return (NodeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two NodeLists. 
 * \param[in] arg0 first NodeList
 * \param[in] arg1 second NodeList
 * \return NodeList with the elements of #arg0 before the elements of #arg1
 */
NodeList concatNodeList(NodeList arg0, NodeList arg1) {
  return (NodeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a NodeList. 
 * \param[in] arg NodeList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new NodeList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
NodeList sliceNodeList(NodeList arg, int start, int end) {
  return (NodeList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the Node at #index from a NodeList. 
 * \param[in] arg NodeList to retrieve the Node from
 * \param[in] index index to use to point in the NodeList
 * \return Node at position #index in #arg
 */
Node getNodeListNodeAt(NodeList arg, int index) {
 return (Node)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the Node at #index from a NodeList by a new one. 
 * \param[in] arg NodeList to retrieve the Node from
 * \param[in] elem new Node to replace another
 * \param[in] index index to use to point in the NodeList
 * \return A new NodeListwith #elem replaced in #arg at position #index
 */
NodeList replaceNodeListNodeAt(NodeList arg, Node elem, int index) {
 return (NodeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a NodeList of 2 consecutive elements. 
 * \param[in] elem1 One Node element of the new NodeList
 * \param[in] elem2 One Node element of the new NodeList
 * \return A new NodeList consisting of 2 Nodes
 */
NodeList makeNodeList2(Node elem1, Node elem2) {
  return (NodeList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a NodeList of 3 consecutive elements. 
 * \param[in] elem1 One Node element of the new NodeList
 * \param[in] elem2 One Node element of the new NodeList
 * \param[in] elem3 One Node element of the new NodeList
 * \return A new NodeList consisting of 3 Nodes
 */
NodeList makeNodeList3(Node elem1, Node elem2, Node elem3) {
  return (NodeList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a NodeList of 4 consecutive elements. 
 * \param[in] elem1 One Node element of the new NodeList
 * \param[in] elem2 One Node element of the new NodeList
 * \param[in] elem3 One Node element of the new NodeList
 * \param[in] elem4 One Node element of the new NodeList
 * \return A new NodeList consisting of 4 Nodes
 */
NodeList makeNodeList4(Node elem1, Node elem2, Node elem3, Node elem4) {
  return (NodeList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a NodeList of 5 consecutive elements. 
 * \param[in] elem1 One Node element of the new NodeList
 * \param[in] elem2 One Node element of the new NodeList
 * \param[in] elem3 One Node element of the new NodeList
 * \param[in] elem4 One Node element of the new NodeList
 * \param[in] elem5 One Node element of the new NodeList
 * \return A new NodeList consisting of 5 Nodes
 */
NodeList makeNodeList5(Node elem1, Node elem2, Node elem3, Node elem4, Node elem5) {
  return (NodeList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a NodeList of 6 consecutive elements. 
 * \param[in] elem1 One Node element of the new NodeList
 * \param[in] elem2 One Node element of the new NodeList
 * \param[in] elem3 One Node element of the new NodeList
 * \param[in] elem4 One Node element of the new NodeList
 * \param[in] elem5 One Node element of the new NodeList
 * \param[in] elem6 One Node element of the new NodeList
 * \return A new NodeList consisting of 6 Nodes
 */
NodeList makeNodeList6(Node elem1, Node elem2, Node elem3, Node elem4, Node elem5, Node elem6) {
  return (NodeList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a AttributeList. 
 * \param[in] arg input AttributeList
 * \return The number of elements in the AttributeList
 */
int getAttributeListLength (AttributeList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a AttributeList. 
 * \param[in] arg AttributeList to be reversed
 * \return a reversed #arg
 */
AttributeList reverseAttributeList(AttributeList arg) {
  return (AttributeList) ATreverse((ATermList) arg);
}

/**
 * Append a Attribute to the end of a AttributeList. 
 * \param[in] arg AttributeList to append the Attribute to
 * \param[in] elem Attribute to be appended
 * \return new AttributeList with #elem appended
 */
AttributeList appendAttributeList(AttributeList arg, Attribute elem) {
  return (AttributeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two AttributeLists. 
 * \param[in] arg0 first AttributeList
 * \param[in] arg1 second AttributeList
 * \return AttributeList with the elements of #arg0 before the elements of #arg1
 */
AttributeList concatAttributeList(AttributeList arg0, AttributeList arg1) {
  return (AttributeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a AttributeList. 
 * \param[in] arg AttributeList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new AttributeList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
AttributeList sliceAttributeList(AttributeList arg, int start, int end) {
  return (AttributeList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the Attribute at #index from a AttributeList. 
 * \param[in] arg AttributeList to retrieve the Attribute from
 * \param[in] index index to use to point in the AttributeList
 * \return Attribute at position #index in #arg
 */
Attribute getAttributeListAttributeAt(AttributeList arg, int index) {
 return (Attribute)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the Attribute at #index from a AttributeList by a new one. 
 * \param[in] arg AttributeList to retrieve the Attribute from
 * \param[in] elem new Attribute to replace another
 * \param[in] index index to use to point in the AttributeList
 * \return A new AttributeListwith #elem replaced in #arg at position #index
 */
AttributeList replaceAttributeListAttributeAt(AttributeList arg, Attribute elem, int index) {
 return (AttributeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a AttributeList of 2 consecutive elements. 
 * \param[in] elem1 One Attribute element of the new AttributeList
 * \param[in] elem2 One Attribute element of the new AttributeList
 * \return A new AttributeList consisting of 2 Attributes
 */
AttributeList makeAttributeList2(Attribute elem1, Attribute elem2) {
  return (AttributeList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a AttributeList of 3 consecutive elements. 
 * \param[in] elem1 One Attribute element of the new AttributeList
 * \param[in] elem2 One Attribute element of the new AttributeList
 * \param[in] elem3 One Attribute element of the new AttributeList
 * \return A new AttributeList consisting of 3 Attributes
 */
AttributeList makeAttributeList3(Attribute elem1, Attribute elem2, Attribute elem3) {
  return (AttributeList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a AttributeList of 4 consecutive elements. 
 * \param[in] elem1 One Attribute element of the new AttributeList
 * \param[in] elem2 One Attribute element of the new AttributeList
 * \param[in] elem3 One Attribute element of the new AttributeList
 * \param[in] elem4 One Attribute element of the new AttributeList
 * \return A new AttributeList consisting of 4 Attributes
 */
AttributeList makeAttributeList4(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4) {
  return (AttributeList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a AttributeList of 5 consecutive elements. 
 * \param[in] elem1 One Attribute element of the new AttributeList
 * \param[in] elem2 One Attribute element of the new AttributeList
 * \param[in] elem3 One Attribute element of the new AttributeList
 * \param[in] elem4 One Attribute element of the new AttributeList
 * \param[in] elem5 One Attribute element of the new AttributeList
 * \return A new AttributeList consisting of 5 Attributes
 */
AttributeList makeAttributeList5(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4, Attribute elem5) {
  return (AttributeList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a AttributeList of 6 consecutive elements. 
 * \param[in] elem1 One Attribute element of the new AttributeList
 * \param[in] elem2 One Attribute element of the new AttributeList
 * \param[in] elem3 One Attribute element of the new AttributeList
 * \param[in] elem4 One Attribute element of the new AttributeList
 * \param[in] elem5 One Attribute element of the new AttributeList
 * \param[in] elem6 One Attribute element of the new AttributeList
 * \return A new AttributeList consisting of 6 Attributes
 */
AttributeList makeAttributeList6(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4, Attribute elem5, Attribute elem6) {
  return (AttributeList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a EdgeList. 
 * \param[in] arg input EdgeList
 * \return The number of elements in the EdgeList
 */
int getEdgeListLength (EdgeList arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a EdgeList. 
 * \param[in] arg EdgeList to be reversed
 * \return a reversed #arg
 */
EdgeList reverseEdgeList(EdgeList arg) {
  return (EdgeList) ATreverse((ATermList) arg);
}

/**
 * Append a Edge to the end of a EdgeList. 
 * \param[in] arg EdgeList to append the Edge to
 * \param[in] elem Edge to be appended
 * \return new EdgeList with #elem appended
 */
EdgeList appendEdgeList(EdgeList arg, Edge elem) {
  return (EdgeList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two EdgeLists. 
 * \param[in] arg0 first EdgeList
 * \param[in] arg1 second EdgeList
 * \return EdgeList with the elements of #arg0 before the elements of #arg1
 */
EdgeList concatEdgeList(EdgeList arg0, EdgeList arg1) {
  return (EdgeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a EdgeList. 
 * \param[in] arg EdgeList to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new EdgeList with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
EdgeList sliceEdgeList(EdgeList arg, int start, int end) {
  return (EdgeList) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the Edge at #index from a EdgeList. 
 * \param[in] arg EdgeList to retrieve the Edge from
 * \param[in] index index to use to point in the EdgeList
 * \return Edge at position #index in #arg
 */
Edge getEdgeListEdgeAt(EdgeList arg, int index) {
 return (Edge)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the Edge at #index from a EdgeList by a new one. 
 * \param[in] arg EdgeList to retrieve the Edge from
 * \param[in] elem new Edge to replace another
 * \param[in] index index to use to point in the EdgeList
 * \return A new EdgeListwith #elem replaced in #arg at position #index
 */
EdgeList replaceEdgeListEdgeAt(EdgeList arg, Edge elem, int index) {
 return (EdgeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a EdgeList of 2 consecutive elements. 
 * \param[in] elem1 One Edge element of the new EdgeList
 * \param[in] elem2 One Edge element of the new EdgeList
 * \return A new EdgeList consisting of 2 Edges
 */
EdgeList makeEdgeList2(Edge elem1, Edge elem2) {
  return (EdgeList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a EdgeList of 3 consecutive elements. 
 * \param[in] elem1 One Edge element of the new EdgeList
 * \param[in] elem2 One Edge element of the new EdgeList
 * \param[in] elem3 One Edge element of the new EdgeList
 * \return A new EdgeList consisting of 3 Edges
 */
EdgeList makeEdgeList3(Edge elem1, Edge elem2, Edge elem3) {
  return (EdgeList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a EdgeList of 4 consecutive elements. 
 * \param[in] elem1 One Edge element of the new EdgeList
 * \param[in] elem2 One Edge element of the new EdgeList
 * \param[in] elem3 One Edge element of the new EdgeList
 * \param[in] elem4 One Edge element of the new EdgeList
 * \return A new EdgeList consisting of 4 Edges
 */
EdgeList makeEdgeList4(Edge elem1, Edge elem2, Edge elem3, Edge elem4) {
  return (EdgeList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a EdgeList of 5 consecutive elements. 
 * \param[in] elem1 One Edge element of the new EdgeList
 * \param[in] elem2 One Edge element of the new EdgeList
 * \param[in] elem3 One Edge element of the new EdgeList
 * \param[in] elem4 One Edge element of the new EdgeList
 * \param[in] elem5 One Edge element of the new EdgeList
 * \return A new EdgeList consisting of 5 Edges
 */
EdgeList makeEdgeList5(Edge elem1, Edge elem2, Edge elem3, Edge elem4, Edge elem5) {
  return (EdgeList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a EdgeList of 6 consecutive elements. 
 * \param[in] elem1 One Edge element of the new EdgeList
 * \param[in] elem2 One Edge element of the new EdgeList
 * \param[in] elem3 One Edge element of the new EdgeList
 * \param[in] elem4 One Edge element of the new EdgeList
 * \param[in] elem5 One Edge element of the new EdgeList
 * \param[in] elem6 One Edge element of the new EdgeList
 * \return A new EdgeList consisting of 6 Edges
 */
EdgeList makeEdgeList6(Edge elem1, Edge elem2, Edge elem3, Edge elem4, Edge elem5, Edge elem6) {
  return (EdgeList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Retrieve the length of a Polygon. 
 * \param[in] arg input Polygon
 * \return The number of elements in the Polygon
 */
int getPolygonLength (Polygon arg) {
  return ATgetLength((ATermList) arg);
}

/**
 * Reverse a Polygon. 
 * \param[in] arg Polygon to be reversed
 * \return a reversed #arg
 */
Polygon reversePolygon(Polygon arg) {
  return (Polygon) ATreverse((ATermList) arg);
}

/**
 * Append a Point to the end of a Polygon. 
 * \param[in] arg Polygon to append the Point to
 * \param[in] elem Point to be appended
 * \return new Polygon with #elem appended
 */
Polygon appendPolygon(Polygon arg, Point elem) {
  return (Polygon) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}

/**
 * Concatenate two Polygons. 
 * \param[in] arg0 first Polygon
 * \param[in] arg1 second Polygon
 * \return Polygon with the elements of #arg0 before the elements of #arg1
 */
Polygon concatPolygon(Polygon arg0, Polygon arg1) {
  return (Polygon) ATconcat((ATermList) arg0, (ATermList) arg1);
}

/**
 * Extract a sublist from a Polygon. 
 * \param[in] arg Polygon to extract a slice from
 * \param[in] start inclusive start index of the sublist
 * \param[in] end exclusive end index of the sublist
 * \return new Polygon with a first element the element at index #start from #arg, and as last element the element at index (#end - 1).
 */
Polygon slicePolygon(Polygon arg, int start, int end) {
  return (Polygon) ATgetSlice((ATermList) arg, start, end);
}

/**
 * Retrieve the Point at #index from a Polygon. 
 * \param[in] arg Polygon to retrieve the Point from
 * \param[in] index index to use to point in the Polygon
 * \return Point at position #index in #arg
 */
Point getPolygonPointAt(Polygon arg, int index) {
 return (Point)ATelementAt((ATermList) arg,index);
}

/**
 * Replace the Point at #index from a Polygon by a new one. 
 * \param[in] arg Polygon to retrieve the Point from
 * \param[in] elem new Point to replace another
 * \param[in] index index to use to point in the Polygon
 * \return A new Polygonwith #elem replaced in #arg at position #index
 */
Polygon replacePolygonPointAt(Polygon arg, Point elem, int index) {
 return (Polygon) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}

/**
 * Builds a Polygon of 2 consecutive elements. 
 * \param[in] elem1 One Point element of the new Polygon
 * \param[in] elem2 One Point element of the new Polygon
 * \return A new Polygon consisting of 2 Points
 */
Polygon makePolygon2(Point elem1, Point elem2) {
  return (Polygon) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2));
}

/**
 * Builds a Polygon of 3 consecutive elements. 
 * \param[in] elem1 One Point element of the new Polygon
 * \param[in] elem2 One Point element of the new Polygon
 * \param[in] elem3 One Point element of the new Polygon
 * \return A new Polygon consisting of 3 Points
 */
Polygon makePolygon3(Point elem1, Point elem2, Point elem3) {
  return (Polygon) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3));
}

/**
 * Builds a Polygon of 4 consecutive elements. 
 * \param[in] elem1 One Point element of the new Polygon
 * \param[in] elem2 One Point element of the new Polygon
 * \param[in] elem3 One Point element of the new Polygon
 * \param[in] elem4 One Point element of the new Polygon
 * \return A new Polygon consisting of 4 Points
 */
Polygon makePolygon4(Point elem1, Point elem2, Point elem3, Point elem4) {
  return (Polygon) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4));
}

/**
 * Builds a Polygon of 5 consecutive elements. 
 * \param[in] elem1 One Point element of the new Polygon
 * \param[in] elem2 One Point element of the new Polygon
 * \param[in] elem3 One Point element of the new Polygon
 * \param[in] elem4 One Point element of the new Polygon
 * \param[in] elem5 One Point element of the new Polygon
 * \return A new Polygon consisting of 5 Points
 */
Polygon makePolygon5(Point elem1, Point elem2, Point elem3, Point elem4, Point elem5) {
  return (Polygon) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5));
}

/**
 * Builds a Polygon of 6 consecutive elements. 
 * \param[in] elem1 One Point element of the new Polygon
 * \param[in] elem2 One Point element of the new Polygon
 * \param[in] elem3 One Point element of the new Polygon
 * \param[in] elem4 One Point element of the new Polygon
 * \param[in] elem5 One Point element of the new Polygon
 * \param[in] elem6 One Point element of the new Polygon
 * \return A new Polygon consisting of 6 Points
 */
Polygon makePolygon6(Point elem1, Point elem2, Point elem3, Point elem4, Point elem5, Point elem6) {
  return (Polygon) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem6));
}

/**
 * Constructs a default of type Graph. Like all ATerm types, Graphs are maximally shared.
 * \param[in] nodes a child of the new default
 * \param[in] edges a child of the new default
 * \param[in] attributes a child of the new default
 * \return A pointer to a default, either newly constructed or shared
 */
Graph makeGraphDefault(NodeList nodes, EdgeList edges, AttributeList attributes) {
  return (Graph)(ATerm)ATmakeAppl3(afun0, (ATerm) nodes, (ATerm) edges, (ATerm) attributes);
}
/**
 * Constructs a empty of type NodeList. Like all ATerm types, NodeLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
NodeList makeNodeListEmpty(void) {
  return (NodeList)(ATerm)ATempty;
}
/**
 * Constructs a single of type NodeList. Like all ATerm types, NodeLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
NodeList makeNodeListSingle(Node head) {
  return (NodeList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type NodeList. Like all ATerm types, NodeLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
NodeList makeNodeListMany(Node head, NodeList tail) {
  return (NodeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a node of type Node. Like all ATerm types, Nodes are maximally shared.
 * \param[in] id a child of the new node
 * \param[in] attributes a child of the new node
 * \return A pointer to a node, either newly constructed or shared
 */
Node makeNodeNode(NodeId id, AttributeList attributes) {
  return (Node)(ATerm)ATmakeAppl2(afun1, (ATerm) id, (ATerm) attributes);
}
/**
 * Constructs a subgraph of type Node. Like all ATerm types, Nodes are maximally shared.
 * \param[in] id a child of the new subgraph
 * \param[in] nodes a child of the new subgraph
 * \param[in] edges a child of the new subgraph
 * \param[in] attributes a child of the new subgraph
 * \return A pointer to a subgraph, either newly constructed or shared
 */
Node makeNodeSubgraph(NodeId id, NodeList nodes, EdgeList edges, AttributeList attributes) {
  return (Node)(ATerm)ATmakeAppl4(afun2, (ATerm) id, (ATerm) nodes, (ATerm) edges, (ATerm) attributes);
}
/**
 * Constructs a default of type NodeId. Like all ATerm types, NodeIds are maximally shared.
 * \param[in] id a child of the new default
 * \return A pointer to a default, either newly constructed or shared
 */
NodeId makeNodeIdDefault(ATerm id) {
  return (NodeId)(ATerm) id;
}
/**
 * Constructs a empty of type AttributeList. Like all ATerm types, AttributeLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
AttributeList makeAttributeListEmpty(void) {
  return (AttributeList)(ATerm)ATempty;
}
/**
 * Constructs a single of type AttributeList. Like all ATerm types, AttributeLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
AttributeList makeAttributeListSingle(Attribute head) {
  return (AttributeList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type AttributeList. Like all ATerm types, AttributeLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
AttributeList makeAttributeListMany(Attribute head, AttributeList tail) {
  return (AttributeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a bounding-box of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] first a child of the new bounding-box
 * \param[in] second a child of the new bounding-box
 * \return A pointer to a bounding-box, either newly constructed or shared
 */
Attribute makeAttributeBoundingBox(Point first, Point second) {
  return (Attribute)(ATerm)ATmakeAppl2(afun3, (ATerm) first, (ATerm) second);
}
/**
 * Constructs a color of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] color a child of the new color
 * \return A pointer to a color, either newly constructed or shared
 */
Attribute makeAttributeColor(Color color) {
  return (Attribute)(ATerm)ATmakeAppl1(afun4, (ATerm) color);
}
/**
 * Constructs a curve-points of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] points a child of the new curve-points
 * \return A pointer to a curve-points, either newly constructed or shared
 */
Attribute makeAttributeCurvePoints(Polygon points) {
  return (Attribute)(ATerm)ATmakeAppl1(afun5, (ATerm) points);
}
/**
 * Constructs a direction of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] direction a child of the new direction
 * \return A pointer to a direction, either newly constructed or shared
 */
Attribute makeAttributeDirection(Direction direction) {
  return (Attribute)(ATerm)ATmakeAppl1(afun6, (ATerm) direction);
}
/**
 * Constructs a fill-color of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] color a child of the new fill-color
 * \return A pointer to a fill-color, either newly constructed or shared
 */
Attribute makeAttributeFillColor(Color color) {
  return (Attribute)(ATerm)ATmakeAppl1(afun7, (ATerm) color);
}
/**
 * Constructs a info of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] key a child of the new info
 * \param[in] value a child of the new info
 * \return A pointer to a info, either newly constructed or shared
 */
Attribute makeAttributeInfo(const char* key, ATerm value) {
  return (Attribute)(ATerm)ATmakeAppl2(afun8, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(key, 0, ATtrue)), (ATerm) value);
}
/**
 * Constructs a label of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] label a child of the new label
 * \return A pointer to a label, either newly constructed or shared
 */
Attribute makeAttributeLabel(const char* label) {
  return (Attribute)(ATerm)ATmakeAppl1(afun9, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue)));
}
/**
 * Constructs a tooltip of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] tooltip a child of the new tooltip
 * \return A pointer to a tooltip, either newly constructed or shared
 */
Attribute makeAttributeTooltip(const char* tooltip) {
  return (Attribute)(ATerm)ATmakeAppl1(afun10, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(tooltip, 0, ATtrue)));
}
/**
 * Constructs a location of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] x a child of the new location
 * \param[in] y a child of the new location
 * \return A pointer to a location, either newly constructed or shared
 */
Attribute makeAttributeLocation(int x, int y) {
  return (Attribute)(ATerm)ATmakeAppl2(afun11, (ATerm) (ATerm) ATmakeInt(x), (ATerm) (ATerm) ATmakeInt(y));
}
/**
 * Constructs a shape of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] shape a child of the new shape
 * \return A pointer to a shape, either newly constructed or shared
 */
Attribute makeAttributeShape(Shape shape) {
  return (Attribute)(ATerm)ATmakeAppl1(afun12, (ATerm) shape);
}
/**
 * Constructs a size of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] width a child of the new size
 * \param[in] height a child of the new size
 * \return A pointer to a size, either newly constructed or shared
 */
Attribute makeAttributeSize(int width, int height) {
  return (Attribute)(ATerm)ATmakeAppl2(afun13, (ATerm) (ATerm) ATmakeInt(width), (ATerm) (ATerm) ATmakeInt(height));
}
/**
 * Constructs a style of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] style a child of the new style
 * \return A pointer to a style, either newly constructed or shared
 */
Attribute makeAttributeStyle(Style style) {
  return (Attribute)(ATerm)ATmakeAppl1(afun14, (ATerm) style);
}
/**
 * Constructs a level of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] level a child of the new level
 * \return A pointer to a level, either newly constructed or shared
 */
Attribute makeAttributeLevel(const char* level) {
  return (Attribute)(ATerm)ATmakeAppl1(afun15, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(level, 0, ATtrue)));
}
/**
 * Constructs a file of type Attribute. Like all ATerm types, Attributes are maximally shared.
 * \param[in] file a child of the new file
 * \return A pointer to a file, either newly constructed or shared
 */
Attribute makeAttributeFile(File file) {
  return (Attribute)(ATerm)ATmakeAppl1(afun16, (ATerm) file);
}
/**
 * Constructs a external of type File. Like all ATerm types, Files are maximally shared.
 * \param[in] file a child of the new external
 * \return A pointer to a external, either newly constructed or shared
 */
File makeFileExternal(ATerm file) {
  return (File)(ATerm) file;
}
/**
 * Constructs a rgb of type Color. Like all ATerm types, Colors are maximally shared.
 * \param[in] red a child of the new rgb
 * \param[in] green a child of the new rgb
 * \param[in] blue a child of the new rgb
 * \return A pointer to a rgb, either newly constructed or shared
 */
Color makeColorRgb(int red, int green, int blue) {
  return (Color)(ATerm)ATmakeAppl3(afun17, (ATerm) (ATerm) ATmakeInt(red), (ATerm) (ATerm) ATmakeInt(green), (ATerm) (ATerm) ATmakeInt(blue));
}
/**
 * Constructs a bold of type Style. Like all ATerm types, Styles are maximally shared.
 * \return A pointer to a bold, either newly constructed or shared
 */
Style makeStyleBold(void) {
  return (Style)(ATerm)ATmakeAppl0(afun18);
}
/**
 * Constructs a dashed of type Style. Like all ATerm types, Styles are maximally shared.
 * \return A pointer to a dashed, either newly constructed or shared
 */
Style makeStyleDashed(void) {
  return (Style)(ATerm)ATmakeAppl0(afun19);
}
/**
 * Constructs a dotted of type Style. Like all ATerm types, Styles are maximally shared.
 * \return A pointer to a dotted, either newly constructed or shared
 */
Style makeStyleDotted(void) {
  return (Style)(ATerm)ATmakeAppl0(afun20);
}
/**
 * Constructs a filled of type Style. Like all ATerm types, Styles are maximally shared.
 * \return A pointer to a filled, either newly constructed or shared
 */
Style makeStyleFilled(void) {
  return (Style)(ATerm)ATmakeAppl0(afun21);
}
/**
 * Constructs a invisible of type Style. Like all ATerm types, Styles are maximally shared.
 * \return A pointer to a invisible, either newly constructed or shared
 */
Style makeStyleInvisible(void) {
  return (Style)(ATerm)ATmakeAppl0(afun22);
}
/**
 * Constructs a solid of type Style. Like all ATerm types, Styles are maximally shared.
 * \return A pointer to a solid, either newly constructed or shared
 */
Style makeStyleSolid(void) {
  return (Style)(ATerm)ATmakeAppl0(afun23);
}
/**
 * Constructs a box of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a box, either newly constructed or shared
 */
Shape makeShapeBox(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun24);
}
/**
 * Constructs a circle of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a circle, either newly constructed or shared
 */
Shape makeShapeCircle(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun25);
}
/**
 * Constructs a diamond of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a diamond, either newly constructed or shared
 */
Shape makeShapeDiamond(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun26);
}
/**
 * Constructs a egg of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a egg, either newly constructed or shared
 */
Shape makeShapeEgg(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun27);
}
/**
 * Constructs a ellipse of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a ellipse, either newly constructed or shared
 */
Shape makeShapeEllipse(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun28);
}
/**
 * Constructs a hexagon of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a hexagon, either newly constructed or shared
 */
Shape makeShapeHexagon(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun29);
}
/**
 * Constructs a house of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a house, either newly constructed or shared
 */
Shape makeShapeHouse(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun30);
}
/**
 * Constructs a octagon of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a octagon, either newly constructed or shared
 */
Shape makeShapeOctagon(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun31);
}
/**
 * Constructs a parallelogram of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a parallelogram, either newly constructed or shared
 */
Shape makeShapeParallelogram(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun32);
}
/**
 * Constructs a plaintext of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a plaintext, either newly constructed or shared
 */
Shape makeShapePlaintext(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun33);
}
/**
 * Constructs a trapezium of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a trapezium, either newly constructed or shared
 */
Shape makeShapeTrapezium(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun34);
}
/**
 * Constructs a triangle of type Shape. Like all ATerm types, Shapes are maximally shared.
 * \return A pointer to a triangle, either newly constructed or shared
 */
Shape makeShapeTriangle(void) {
  return (Shape)(ATerm)ATmakeAppl0(afun35);
}
/**
 * Constructs a forward of type Direction. Like all ATerm types, Directions are maximally shared.
 * \return A pointer to a forward, either newly constructed or shared
 */
Direction makeDirectionForward(void) {
  return (Direction)(ATerm)ATmakeAppl0(afun36);
}
/**
 * Constructs a back of type Direction. Like all ATerm types, Directions are maximally shared.
 * \return A pointer to a back, either newly constructed or shared
 */
Direction makeDirectionBack(void) {
  return (Direction)(ATerm)ATmakeAppl0(afun37);
}
/**
 * Constructs a both of type Direction. Like all ATerm types, Directions are maximally shared.
 * \return A pointer to a both, either newly constructed or shared
 */
Direction makeDirectionBoth(void) {
  return (Direction)(ATerm)ATmakeAppl0(afun38);
}
/**
 * Constructs a none of type Direction. Like all ATerm types, Directions are maximally shared.
 * \return A pointer to a none, either newly constructed or shared
 */
Direction makeDirectionNone(void) {
  return (Direction)(ATerm)ATmakeAppl0(afun39);
}
/**
 * Constructs a empty of type EdgeList. Like all ATerm types, EdgeLists are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
EdgeList makeEdgeListEmpty(void) {
  return (EdgeList)(ATerm)ATempty;
}
/**
 * Constructs a single of type EdgeList. Like all ATerm types, EdgeLists are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
EdgeList makeEdgeListSingle(Edge head) {
  return (EdgeList)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type EdgeList. Like all ATerm types, EdgeLists are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
EdgeList makeEdgeListMany(Edge head, EdgeList tail) {
  return (EdgeList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a default of type Edge. Like all ATerm types, Edges are maximally shared.
 * \param[in] from a child of the new default
 * \param[in] to a child of the new default
 * \param[in] attributes a child of the new default
 * \return A pointer to a default, either newly constructed or shared
 */
Edge makeEdgeDefault(NodeId from, NodeId to, AttributeList attributes) {
  return (Edge)(ATerm)ATmakeAppl3(afun40, (ATerm) from, (ATerm) to, (ATerm) attributes);
}
/**
 * Constructs a empty of type Polygon. Like all ATerm types, Polygons are maximally shared.
 * \return A pointer to a empty, either newly constructed or shared
 */
Polygon makePolygonEmpty(void) {
  return (Polygon)(ATerm)ATempty;
}
/**
 * Constructs a single of type Polygon. Like all ATerm types, Polygons are maximally shared.
 * \param[in] head a child of the new single
 * \return A pointer to a single, either newly constructed or shared
 */
Polygon makePolygonSingle(Point head) {
  return (Polygon)(ATerm)ATmakeList1((ATerm) head);
}
/**
 * Constructs a many of type Polygon. Like all ATerm types, Polygons are maximally shared.
 * \param[in] head a child of the new many
 * \param[in] tail a child of the new many
 * \return A pointer to a many, either newly constructed or shared
 */
Polygon makePolygonMany(Point head, Polygon tail) {
  return (Polygon)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}
/**
 * Constructs a default of type Point. Like all ATerm types, Points are maximally shared.
 * \param[in] x a child of the new default
 * \param[in] y a child of the new default
 * \return A pointer to a default, either newly constructed or shared
 */
Point makePointDefault(int x, int y) {
  return (Point)(ATerm)ATmakeAppl2(afun41, (ATerm) (ATerm) ATmakeInt(x), (ATerm) (ATerm) ATmakeInt(y));
}

/**
 * Tests equality of two Graphs. A constant time operation.
 * \param[in] arg0 first Graph to be compared
 * \param[in] arg1 second Graph to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualGraph(Graph arg0, Graph arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two NodeLists. A constant time operation.
 * \param[in] arg0 first NodeList to be compared
 * \param[in] arg1 second NodeList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualNodeList(NodeList arg0, NodeList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Nodes. A constant time operation.
 * \param[in] arg0 first Node to be compared
 * \param[in] arg1 second Node to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualNode(Node arg0, Node arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two NodeIds. A constant time operation.
 * \param[in] arg0 first NodeId to be compared
 * \param[in] arg1 second NodeId to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualNodeId(NodeId arg0, NodeId arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two AttributeLists. A constant time operation.
 * \param[in] arg0 first AttributeList to be compared
 * \param[in] arg1 second AttributeList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualAttributeList(AttributeList arg0, AttributeList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Attributes. A constant time operation.
 * \param[in] arg0 first Attribute to be compared
 * \param[in] arg1 second Attribute to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualAttribute(Attribute arg0, Attribute arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Files. A constant time operation.
 * \param[in] arg0 first File to be compared
 * \param[in] arg1 second File to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualFile(File arg0, File arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Colors. A constant time operation.
 * \param[in] arg0 first Color to be compared
 * \param[in] arg1 second Color to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualColor(Color arg0, Color arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Styles. A constant time operation.
 * \param[in] arg0 first Style to be compared
 * \param[in] arg1 second Style to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualStyle(Style arg0, Style arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Shapes. A constant time operation.
 * \param[in] arg0 first Shape to be compared
 * \param[in] arg1 second Shape to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualShape(Shape arg0, Shape arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Directions. A constant time operation.
 * \param[in] arg0 first Direction to be compared
 * \param[in] arg1 second Direction to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualDirection(Direction arg0, Direction arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two EdgeLists. A constant time operation.
 * \param[in] arg0 first EdgeList to be compared
 * \param[in] arg1 second EdgeList to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualEdgeList(EdgeList arg0, EdgeList arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Edges. A constant time operation.
 * \param[in] arg0 first Edge to be compared
 * \param[in] arg1 second Edge to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualEdge(Edge arg0, Edge arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Polygons. A constant time operation.
 * \param[in] arg0 first Polygon to be compared
 * \param[in] arg1 second Polygon to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualPolygon(Polygon arg0, Polygon arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Tests equality of two Points. A constant time operation.
 * \param[in] arg0 first Point to be compared
 * \param[in] arg1 second Point to be compared
 * \return ATtrue if #arg0 was equal to #arg1, ATfalse otherwise
 */
ATbool isEqualPoint(Point arg0, Point arg1) {
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/**
 * Assert whether a Graph is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Graph
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidGraph(Graph arg) {
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Graph is a default. Always returns ATtrue
 * \param[in] arg input Graph
 * \return ATtrue if #arg corresponds to the signature of a default, or ATfalse otherwise
 */
inline ATbool isGraphDefault(Graph arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternGraphDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a Graph has a nodes. 
 * \param[in] arg input Graph
 * \return ATtrue if the Graph had a nodes, or ATfalse otherwise
 */
ATbool hasGraphNodes(Graph arg) {
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Graph has a edges. 
 * \param[in] arg input Graph
 * \return ATtrue if the Graph had a edges, or ATfalse otherwise
 */
ATbool hasGraphEdges(Graph arg) {
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Graph has a attributes. 
 * \param[in] arg input Graph
 * \return ATtrue if the Graph had a attributes, or ATfalse otherwise
 */
ATbool hasGraphAttributes(Graph arg) {
  if (isGraphDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the nodes NodeList of a Graph. Note that the precondition is that this Graph actually has a nodes
 * \param[in] arg input Graph
 * \return the nodes of #arg, if it exist or an undefined value if it does not
 */
NodeList getGraphNodes(Graph arg) {
  
    return (NodeList)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the edges EdgeList of a Graph. Note that the precondition is that this Graph actually has a edges
 * \param[in] arg input Graph
 * \return the edges of #arg, if it exist or an undefined value if it does not
 */
EdgeList getGraphEdges(Graph arg) {
  
    return (EdgeList)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Get the attributes AttributeList of a Graph. Note that the precondition is that this Graph actually has a attributes
 * \param[in] arg input Graph
 * \return the attributes of #arg, if it exist or an undefined value if it does not
 */
AttributeList getGraphAttributes(Graph arg) {
  
    return (AttributeList)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Set the nodes of a Graph. The precondition being that this Graph actually has a nodes
 * \param[in] arg input Graph
 * \param[in] nodes new NodeList to set in #arg
 * \return A new Graph with nodes at the right place, or a core dump if #arg did not have a nodes
 */
Graph setGraphNodes(Graph arg, NodeList nodes) {
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) nodes), 0);
  }

  ATabort("Graph has no Nodes: %t\n", arg);
  return (Graph)NULL;
}

/**
 * Set the edges of a Graph. The precondition being that this Graph actually has a edges
 * \param[in] arg input Graph
 * \param[in] edges new EdgeList to set in #arg
 * \return A new Graph with edges at the right place, or a core dump if #arg did not have a edges
 */
Graph setGraphEdges(Graph arg, EdgeList edges) {
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) edges), 1);
  }

  ATabort("Graph has no Edges: %t\n", arg);
  return (Graph)NULL;
}

/**
 * Set the attributes of a Graph. The precondition being that this Graph actually has a attributes
 * \param[in] arg input Graph
 * \param[in] attributes new AttributeList to set in #arg
 * \return A new Graph with attributes at the right place, or a core dump if #arg did not have a attributes
 */
Graph setGraphAttributes(Graph arg, AttributeList attributes) {
  if (isGraphDefault(arg)) {
    return (Graph)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 2);
  }

  ATabort("Graph has no Attributes: %t\n", arg);
  return (Graph)NULL;
}

/**
 * Assert whether a NodeList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input NodeList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidNodeList(NodeList arg) {
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

/**
 * Assert whether a NodeList is a empty. . May not be used to assert correctness of the NodeList
 * \param[in] arg input NodeList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool isNodeListEmpty(NodeList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternNodeListEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a NodeList is a single. . May not be used to assert correctness of the NodeList
 * \param[in] arg input NodeList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool isNodeListSingle(NodeList arg) {
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

/**
 * Assert whether a NodeList is a many. . May not be used to assert correctness of the NodeList
 * \param[in] arg input NodeList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool isNodeListMany(NodeList arg) {
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

/**
 * Assert whether a NodeList has a head. 
 * \param[in] arg input NodeList
 * \return ATtrue if the NodeList had a head, or ATfalse otherwise
 */
ATbool hasNodeListHead(NodeList arg) {
  if (isNodeListSingle(arg)) {
    return ATtrue;
  }
  else if (isNodeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a NodeList has a tail. 
 * \param[in] arg input NodeList
 * \return ATtrue if the NodeList had a tail, or ATfalse otherwise
 */
ATbool hasNodeListTail(NodeList arg) {
  if (isNodeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head Node of a NodeList. Note that the precondition is that this NodeList actually has a head
 * \param[in] arg input NodeList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
Node getNodeListHead(NodeList arg) {
  if (isNodeListSingle(arg)) {
    return (Node)ATgetFirst((ATermList)arg);
  }
  else 
    return (Node)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail NodeList of a NodeList. Note that the precondition is that this NodeList actually has a tail
 * \param[in] arg input NodeList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
NodeList getNodeListTail(NodeList arg) {
  
    return (NodeList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a NodeList. The precondition being that this NodeList actually has a head
 * \param[in] arg input NodeList
 * \param[in] head new Node to set in #arg
 * \return A new NodeList with head at the right place, or a core dump if #arg did not have a head
 */
NodeList setNodeListHead(NodeList arg, Node head) {
  if (isNodeListSingle(arg)) {
    return (NodeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (isNodeListMany(arg)) {
    return (NodeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("NodeList has no Head: %t\n", arg);
  return (NodeList)NULL;
}

/**
 * Set the tail of a NodeList. The precondition being that this NodeList actually has a tail
 * \param[in] arg input NodeList
 * \param[in] tail new NodeList to set in #arg
 * \return A new NodeList with tail at the right place, or a core dump if #arg did not have a tail
 */
NodeList setNodeListTail(NodeList arg, NodeList tail) {
  if (isNodeListMany(arg)) {
    return (NodeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("NodeList has no Tail: %t\n", arg);
  return (NodeList)NULL;
}

/**
 * Assert whether a Node is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Node
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidNode(Node arg) {
  if (isNodeNode(arg)) {
    return ATtrue;
  }
  else if (isNodeSubgraph(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Node is a node. . May not be used to assert correctness of the Node
 * \param[in] arg input Node
 * \return ATtrue if #arg corresponds to the signature of a node, or ATfalse otherwise
 */
inline ATbool isNodeNode(Node arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternNodeNode, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a Node is a subgraph. . May not be used to assert correctness of the Node
 * \param[in] arg input Node
 * \return ATtrue if #arg corresponds to the signature of a subgraph, or ATfalse otherwise
 */
inline ATbool isNodeSubgraph(Node arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternNodeSubgraph, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a Node has a id. 
 * \param[in] arg input Node
 * \return ATtrue if the Node had a id, or ATfalse otherwise
 */
ATbool hasNodeId(Node arg) {
  if (isNodeNode(arg)) {
    return ATtrue;
  }
  else if (isNodeSubgraph(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Node has a attributes. 
 * \param[in] arg input Node
 * \return ATtrue if the Node had a attributes, or ATfalse otherwise
 */
ATbool hasNodeAttributes(Node arg) {
  if (isNodeNode(arg)) {
    return ATtrue;
  }
  else if (isNodeSubgraph(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Node has a nodes. 
 * \param[in] arg input Node
 * \return ATtrue if the Node had a nodes, or ATfalse otherwise
 */
ATbool hasNodeNodes(Node arg) {
  if (isNodeSubgraph(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Node has a edges. 
 * \param[in] arg input Node
 * \return ATtrue if the Node had a edges, or ATfalse otherwise
 */
ATbool hasNodeEdges(Node arg) {
  if (isNodeSubgraph(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the id NodeId of a Node. Note that the precondition is that this Node actually has a id
 * \param[in] arg input Node
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
NodeId getNodeId(Node arg) {
  if (isNodeNode(arg)) {
    return (NodeId)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (NodeId)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the attributes AttributeList of a Node. Note that the precondition is that this Node actually has a attributes
 * \param[in] arg input Node
 * \return the attributes of #arg, if it exist or an undefined value if it does not
 */
AttributeList getNodeAttributes(Node arg) {
  if (isNodeNode(arg)) {
    return (AttributeList)ATgetArgument((ATermAppl)arg, 1);
  }
  else 
    return (AttributeList)ATgetArgument((ATermAppl)arg, 3);
}

/**
 * Get the nodes NodeList of a Node. Note that the precondition is that this Node actually has a nodes
 * \param[in] arg input Node
 * \return the nodes of #arg, if it exist or an undefined value if it does not
 */
NodeList getNodeNodes(Node arg) {
  
    return (NodeList)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Get the edges EdgeList of a Node. Note that the precondition is that this Node actually has a edges
 * \param[in] arg input Node
 * \return the edges of #arg, if it exist or an undefined value if it does not
 */
EdgeList getNodeEdges(Node arg) {
  
    return (EdgeList)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Set the id of a Node. The precondition being that this Node actually has a id
 * \param[in] arg input Node
 * \param[in] id new NodeId to set in #arg
 * \return A new Node with id at the right place, or a core dump if #arg did not have a id
 */
Node setNodeId(Node arg, NodeId id) {
  if (isNodeNode(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) id), 0);
  }
  else if (isNodeSubgraph(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) id), 0);
  }

  ATabort("Node has no Id: %t\n", arg);
  return (Node)NULL;
}

/**
 * Set the attributes of a Node. The precondition being that this Node actually has a attributes
 * \param[in] arg input Node
 * \param[in] attributes new AttributeList to set in #arg
 * \return A new Node with attributes at the right place, or a core dump if #arg did not have a attributes
 */
Node setNodeAttributes(Node arg, AttributeList attributes) {
  if (isNodeNode(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 1);
  }
  else if (isNodeSubgraph(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 3);
  }

  ATabort("Node has no Attributes: %t\n", arg);
  return (Node)NULL;
}

/**
 * Set the nodes of a Node. The precondition being that this Node actually has a nodes
 * \param[in] arg input Node
 * \param[in] nodes new NodeList to set in #arg
 * \return A new Node with nodes at the right place, or a core dump if #arg did not have a nodes
 */
Node setNodeNodes(Node arg, NodeList nodes) {
  if (isNodeSubgraph(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) nodes), 1);
  }

  ATabort("Node has no Nodes: %t\n", arg);
  return (Node)NULL;
}

/**
 * Set the edges of a Node. The precondition being that this Node actually has a edges
 * \param[in] arg input Node
 * \param[in] edges new EdgeList to set in #arg
 * \return A new Node with edges at the right place, or a core dump if #arg did not have a edges
 */
Node setNodeEdges(Node arg, EdgeList edges) {
  if (isNodeSubgraph(arg)) {
    return (Node)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) edges), 2);
  }

  ATabort("Node has no Edges: %t\n", arg);
  return (Node)NULL;
}

/**
 * Assert whether a NodeId is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input NodeId
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidNodeId(NodeId arg) {
  if (isNodeIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a NodeId is a default. Always returns ATtrue
 * \param[in] arg input NodeId
 * \return ATtrue if #arg corresponds to the signature of a default, or ATfalse otherwise
 */
inline ATbool isNodeIdDefault(NodeId arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternNodeIdDefault, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a NodeId has a id. 
 * \param[in] arg input NodeId
 * \return ATtrue if the NodeId had a id, or ATfalse otherwise
 */
ATbool hasNodeIdId(NodeId arg) {
  if (isNodeIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the id ATerm of a NodeId. Note that the precondition is that this NodeId actually has a id
 * \param[in] arg input NodeId
 * \return the id of #arg, if it exist or an undefined value if it does not
 */
ATerm getNodeIdId(NodeId arg) {
  
    return (ATerm)arg;
}

/**
 * Set the id of a NodeId. The precondition being that this NodeId actually has a id
 * \param[in] arg input NodeId
 * \param[in] id new ATerm to set in #arg
 * \return A new NodeId with id at the right place, or a core dump if #arg did not have a id
 */
NodeId setNodeIdId(NodeId arg, ATerm id) {
  if (isNodeIdDefault(arg)) {
    return (NodeId)((ATerm) id);
  }

  ATabort("NodeId has no Id: %t\n", arg);
  return (NodeId)NULL;
}

/**
 * Assert whether a AttributeList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input AttributeList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidAttributeList(AttributeList arg) {
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

/**
 * Assert whether a AttributeList is a empty. . May not be used to assert correctness of the AttributeList
 * \param[in] arg input AttributeList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool isAttributeListEmpty(AttributeList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternAttributeListEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a AttributeList is a single. . May not be used to assert correctness of the AttributeList
 * \param[in] arg input AttributeList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool isAttributeListSingle(AttributeList arg) {
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

/**
 * Assert whether a AttributeList is a many. . May not be used to assert correctness of the AttributeList
 * \param[in] arg input AttributeList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool isAttributeListMany(AttributeList arg) {
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

/**
 * Assert whether a AttributeList has a head. 
 * \param[in] arg input AttributeList
 * \return ATtrue if the AttributeList had a head, or ATfalse otherwise
 */
ATbool hasAttributeListHead(AttributeList arg) {
  if (isAttributeListSingle(arg)) {
    return ATtrue;
  }
  else if (isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a AttributeList has a tail. 
 * \param[in] arg input AttributeList
 * \return ATtrue if the AttributeList had a tail, or ATfalse otherwise
 */
ATbool hasAttributeListTail(AttributeList arg) {
  if (isAttributeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head Attribute of a AttributeList. Note that the precondition is that this AttributeList actually has a head
 * \param[in] arg input AttributeList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
Attribute getAttributeListHead(AttributeList arg) {
  if (isAttributeListSingle(arg)) {
    return (Attribute)ATgetFirst((ATermList)arg);
  }
  else 
    return (Attribute)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail AttributeList of a AttributeList. Note that the precondition is that this AttributeList actually has a tail
 * \param[in] arg input AttributeList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
AttributeList getAttributeListTail(AttributeList arg) {
  
    return (AttributeList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a AttributeList. The precondition being that this AttributeList actually has a head
 * \param[in] arg input AttributeList
 * \param[in] head new Attribute to set in #arg
 * \return A new AttributeList with head at the right place, or a core dump if #arg did not have a head
 */
AttributeList setAttributeListHead(AttributeList arg, Attribute head) {
  if (isAttributeListSingle(arg)) {
    return (AttributeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (isAttributeListMany(arg)) {
    return (AttributeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("AttributeList has no Head: %t\n", arg);
  return (AttributeList)NULL;
}

/**
 * Set the tail of a AttributeList. The precondition being that this AttributeList actually has a tail
 * \param[in] arg input AttributeList
 * \param[in] tail new AttributeList to set in #arg
 * \return A new AttributeList with tail at the right place, or a core dump if #arg did not have a tail
 */
AttributeList setAttributeListTail(AttributeList arg, AttributeList tail) {
  if (isAttributeListMany(arg)) {
    return (AttributeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("AttributeList has no Tail: %t\n", arg);
  return (AttributeList)NULL;
}

/**
 * Assert whether a Attribute is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidAttribute(Attribute arg) {
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
  else if (isAttributeTooltip(arg)) {
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
  else if (isAttributeLevel(arg)) {
    return ATtrue;
  }
  else if (isAttributeFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute is a bounding-box. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a bounding-box, or ATfalse otherwise
 */
inline ATbool isAttributeBoundingBox(Attribute arg) {
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

/**
 * Assert whether a Attribute is a color. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a color, or ATfalse otherwise
 */
inline ATbool isAttributeColor(Attribute arg) {
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

/**
 * Assert whether a Attribute is a curve-points. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a curve-points, or ATfalse otherwise
 */
inline ATbool isAttributeCurvePoints(Attribute arg) {
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

/**
 * Assert whether a Attribute is a direction. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a direction, or ATfalse otherwise
 */
inline ATbool isAttributeDirection(Attribute arg) {
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

/**
 * Assert whether a Attribute is a fill-color. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a fill-color, or ATfalse otherwise
 */
inline ATbool isAttributeFillColor(Attribute arg) {
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

/**
 * Assert whether a Attribute is a info. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a info, or ATfalse otherwise
 */
inline ATbool isAttributeInfo(Attribute arg) {
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

/**
 * Assert whether a Attribute is a label. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a label, or ATfalse otherwise
 */
inline ATbool isAttributeLabel(Attribute arg) {
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

/**
 * Assert whether a Attribute is a tooltip. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a tooltip, or ATfalse otherwise
 */
inline ATbool isAttributeTooltip(Attribute arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeTooltip, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a Attribute is a location. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a location, or ATfalse otherwise
 */
inline ATbool isAttributeLocation(Attribute arg) {
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

/**
 * Assert whether a Attribute is a shape. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a shape, or ATfalse otherwise
 */
inline ATbool isAttributeShape(Attribute arg) {
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

/**
 * Assert whether a Attribute is a size. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a size, or ATfalse otherwise
 */
inline ATbool isAttributeSize(Attribute arg) {
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

/**
 * Assert whether a Attribute is a style. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a style, or ATfalse otherwise
 */
inline ATbool isAttributeStyle(Attribute arg) {
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

/**
 * Assert whether a Attribute is a level. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a level, or ATfalse otherwise
 */
inline ATbool isAttributeLevel(Attribute arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeLevel, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a Attribute is a file. . May not be used to assert correctness of the Attribute
 * \param[in] arg input Attribute
 * \return ATtrue if #arg corresponds to the signature of a file, or ATfalse otherwise
 */
inline ATbool isAttributeFile(Attribute arg) {
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, patternAttributeFile, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/**
 * Assert whether a Attribute has a first. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a first, or ATfalse otherwise
 */
ATbool hasAttributeFirst(Attribute arg) {
  if (isAttributeBoundingBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a second. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a second, or ATfalse otherwise
 */
ATbool hasAttributeSecond(Attribute arg) {
  if (isAttributeBoundingBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a color. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a color, or ATfalse otherwise
 */
ATbool hasAttributeColor(Attribute arg) {
  if (isAttributeColor(arg)) {
    return ATtrue;
  }
  else if (isAttributeFillColor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a points. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a points, or ATfalse otherwise
 */
ATbool hasAttributePoints(Attribute arg) {
  if (isAttributeCurvePoints(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a direction. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a direction, or ATfalse otherwise
 */
ATbool hasAttributeDirection(Attribute arg) {
  if (isAttributeDirection(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a key. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a key, or ATfalse otherwise
 */
ATbool hasAttributeKey(Attribute arg) {
  if (isAttributeInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a value. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a value, or ATfalse otherwise
 */
ATbool hasAttributeValue(Attribute arg) {
  if (isAttributeInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a label. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a label, or ATfalse otherwise
 */
ATbool hasAttributeLabel(Attribute arg) {
  if (isAttributeLabel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a tooltip. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a tooltip, or ATfalse otherwise
 */
ATbool hasAttributeTooltip(Attribute arg) {
  if (isAttributeTooltip(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a x. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a x, or ATfalse otherwise
 */
ATbool hasAttributeX(Attribute arg) {
  if (isAttributeLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a y. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a y, or ATfalse otherwise
 */
ATbool hasAttributeY(Attribute arg) {
  if (isAttributeLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a shape. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a shape, or ATfalse otherwise
 */
ATbool hasAttributeShape(Attribute arg) {
  if (isAttributeShape(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a width. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a width, or ATfalse otherwise
 */
ATbool hasAttributeWidth(Attribute arg) {
  if (isAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a height. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a height, or ATfalse otherwise
 */
ATbool hasAttributeHeight(Attribute arg) {
  if (isAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a style. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a style, or ATfalse otherwise
 */
ATbool hasAttributeStyle(Attribute arg) {
  if (isAttributeStyle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a level. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a level, or ATfalse otherwise
 */
ATbool hasAttributeLevel(Attribute arg) {
  if (isAttributeLevel(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Attribute has a file. 
 * \param[in] arg input Attribute
 * \return ATtrue if the Attribute had a file, or ATfalse otherwise
 */
ATbool hasAttributeFile(Attribute arg) {
  if (isAttributeFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the first Point of a Attribute. Note that the precondition is that this Attribute actually has a first
 * \param[in] arg input Attribute
 * \return the first of #arg, if it exist or an undefined value if it does not
 */
Point getAttributeFirst(Attribute arg) {
  
    return (Point)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the second Point of a Attribute. Note that the precondition is that this Attribute actually has a second
 * \param[in] arg input Attribute
 * \return the second of #arg, if it exist or an undefined value if it does not
 */
Point getAttributeSecond(Attribute arg) {
  
    return (Point)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Get the color Color of a Attribute. Note that the precondition is that this Attribute actually has a color
 * \param[in] arg input Attribute
 * \return the color of #arg, if it exist or an undefined value if it does not
 */
Color getAttributeColor(Attribute arg) {
  if (isAttributeColor(arg)) {
    return (Color)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (Color)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the points Polygon of a Attribute. Note that the precondition is that this Attribute actually has a points
 * \param[in] arg input Attribute
 * \return the points of #arg, if it exist or an undefined value if it does not
 */
Polygon getAttributePoints(Attribute arg) {
  
    return (Polygon)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the direction Direction of a Attribute. Note that the precondition is that this Attribute actually has a direction
 * \param[in] arg input Attribute
 * \return the direction of #arg, if it exist or an undefined value if it does not
 */
Direction getAttributeDirection(Attribute arg) {
  
    return (Direction)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the key char* of a Attribute. Note that the precondition is that this Attribute actually has a key
 * \param[in] arg input Attribute
 * \return the key of #arg, if it exist or an undefined value if it does not
 */
char* getAttributeKey(Attribute arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the value ATerm of a Attribute. Note that the precondition is that this Attribute actually has a value
 * \param[in] arg input Attribute
 * \return the value of #arg, if it exist or an undefined value if it does not
 */
ATerm getAttributeValue(Attribute arg) {
  
    return (ATerm)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Get the label char* of a Attribute. Note that the precondition is that this Attribute actually has a label
 * \param[in] arg input Attribute
 * \return the label of #arg, if it exist or an undefined value if it does not
 */
char* getAttributeLabel(Attribute arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the tooltip char* of a Attribute. Note that the precondition is that this Attribute actually has a tooltip
 * \param[in] arg input Attribute
 * \return the tooltip of #arg, if it exist or an undefined value if it does not
 */
char* getAttributeTooltip(Attribute arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the x int of a Attribute. Note that the precondition is that this Attribute actually has a x
 * \param[in] arg input Attribute
 * \return the x of #arg, if it exist or an undefined value if it does not
 */
int getAttributeX(Attribute arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the y int of a Attribute. Note that the precondition is that this Attribute actually has a y
 * \param[in] arg input Attribute
 * \return the y of #arg, if it exist or an undefined value if it does not
 */
int getAttributeY(Attribute arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the shape Shape of a Attribute. Note that the precondition is that this Attribute actually has a shape
 * \param[in] arg input Attribute
 * \return the shape of #arg, if it exist or an undefined value if it does not
 */
Shape getAttributeShape(Attribute arg) {
  
    return (Shape)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the width int of a Attribute. Note that the precondition is that this Attribute actually has a width
 * \param[in] arg input Attribute
 * \return the width of #arg, if it exist or an undefined value if it does not
 */
int getAttributeWidth(Attribute arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the height int of a Attribute. Note that the precondition is that this Attribute actually has a height
 * \param[in] arg input Attribute
 * \return the height of #arg, if it exist or an undefined value if it does not
 */
int getAttributeHeight(Attribute arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the style Style of a Attribute. Note that the precondition is that this Attribute actually has a style
 * \param[in] arg input Attribute
 * \return the style of #arg, if it exist or an undefined value if it does not
 */
Style getAttributeStyle(Attribute arg) {
  
    return (Style)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the level char* of a Attribute. Note that the precondition is that this Attribute actually has a level
 * \param[in] arg input Attribute
 * \return the level of #arg, if it exist or an undefined value if it does not
 */
char* getAttributeLevel(Attribute arg) {
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/**
 * Get the file File of a Attribute. Note that the precondition is that this Attribute actually has a file
 * \param[in] arg input Attribute
 * \return the file of #arg, if it exist or an undefined value if it does not
 */
File getAttributeFile(Attribute arg) {
  
    return (File)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Set the first of a Attribute. The precondition being that this Attribute actually has a first
 * \param[in] arg input Attribute
 * \param[in] first new Point to set in #arg
 * \return A new Attribute with first at the right place, or a core dump if #arg did not have a first
 */
Attribute setAttributeFirst(Attribute arg, Point first) {
  if (isAttributeBoundingBox(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) first), 0);
  }

  ATabort("Attribute has no First: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the second of a Attribute. The precondition being that this Attribute actually has a second
 * \param[in] arg input Attribute
 * \param[in] second new Point to set in #arg
 * \return A new Attribute with second at the right place, or a core dump if #arg did not have a second
 */
Attribute setAttributeSecond(Attribute arg, Point second) {
  if (isAttributeBoundingBox(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) second), 1);
  }

  ATabort("Attribute has no Second: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the color of a Attribute. The precondition being that this Attribute actually has a color
 * \param[in] arg input Attribute
 * \param[in] color new Color to set in #arg
 * \return A new Attribute with color at the right place, or a core dump if #arg did not have a color
 */
Attribute setAttributeColor(Attribute arg, Color color) {
  if (isAttributeColor(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }
  else if (isAttributeFillColor(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }

  ATabort("Attribute has no Color: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the points of a Attribute. The precondition being that this Attribute actually has a points
 * \param[in] arg input Attribute
 * \param[in] points new Polygon to set in #arg
 * \return A new Attribute with points at the right place, or a core dump if #arg did not have a points
 */
Attribute setAttributePoints(Attribute arg, Polygon points) {
  if (isAttributeCurvePoints(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) points), 0);
  }

  ATabort("Attribute has no Points: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the direction of a Attribute. The precondition being that this Attribute actually has a direction
 * \param[in] arg input Attribute
 * \param[in] direction new Direction to set in #arg
 * \return A new Attribute with direction at the right place, or a core dump if #arg did not have a direction
 */
Attribute setAttributeDirection(Attribute arg, Direction direction) {
  if (isAttributeDirection(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) direction), 0);
  }

  ATabort("Attribute has no Direction: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the key of a Attribute. The precondition being that this Attribute actually has a key
 * \param[in] arg input Attribute
 * \param[in] key new const char* to set in #arg
 * \return A new Attribute with key at the right place, or a core dump if #arg did not have a key
 */
Attribute setAttributeKey(Attribute arg, const char* key) {
  if (isAttributeInfo(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(key, 0, ATtrue))), 0);
  }

  ATabort("Attribute has no Key: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the value of a Attribute. The precondition being that this Attribute actually has a value
 * \param[in] arg input Attribute
 * \param[in] value new ATerm to set in #arg
 * \return A new Attribute with value at the right place, or a core dump if #arg did not have a value
 */
Attribute setAttributeValue(Attribute arg, ATerm value) {
  if (isAttributeInfo(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) value), 1);
  }

  ATabort("Attribute has no Value: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the label of a Attribute. The precondition being that this Attribute actually has a label
 * \param[in] arg input Attribute
 * \param[in] label new const char* to set in #arg
 * \return A new Attribute with label at the right place, or a core dump if #arg did not have a label
 */
Attribute setAttributeLabel(Attribute arg, const char* label) {
  if (isAttributeLabel(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(label, 0, ATtrue))), 0);
  }

  ATabort("Attribute has no Label: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the tooltip of a Attribute. The precondition being that this Attribute actually has a tooltip
 * \param[in] arg input Attribute
 * \param[in] tooltip new const char* to set in #arg
 * \return A new Attribute with tooltip at the right place, or a core dump if #arg did not have a tooltip
 */
Attribute setAttributeTooltip(Attribute arg, const char* tooltip) {
  if (isAttributeTooltip(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(tooltip, 0, ATtrue))), 0);
  }

  ATabort("Attribute has no Tooltip: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the x of a Attribute. The precondition being that this Attribute actually has a x
 * \param[in] arg input Attribute
 * \param[in] x new int to set in #arg
 * \return A new Attribute with x at the right place, or a core dump if #arg did not have a x
 */
Attribute setAttributeX(Attribute arg, int x) {
  if (isAttributeLocation(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(x)), 0);
  }

  ATabort("Attribute has no X: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the y of a Attribute. The precondition being that this Attribute actually has a y
 * \param[in] arg input Attribute
 * \param[in] y new int to set in #arg
 * \return A new Attribute with y at the right place, or a core dump if #arg did not have a y
 */
Attribute setAttributeY(Attribute arg, int y) {
  if (isAttributeLocation(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(y)), 1);
  }

  ATabort("Attribute has no Y: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the shape of a Attribute. The precondition being that this Attribute actually has a shape
 * \param[in] arg input Attribute
 * \param[in] shape new Shape to set in #arg
 * \return A new Attribute with shape at the right place, or a core dump if #arg did not have a shape
 */
Attribute setAttributeShape(Attribute arg, Shape shape) {
  if (isAttributeShape(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) shape), 0);
  }

  ATabort("Attribute has no Shape: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the width of a Attribute. The precondition being that this Attribute actually has a width
 * \param[in] arg input Attribute
 * \param[in] width new int to set in #arg
 * \return A new Attribute with width at the right place, or a core dump if #arg did not have a width
 */
Attribute setAttributeWidth(Attribute arg, int width) {
  if (isAttributeSize(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(width)), 0);
  }

  ATabort("Attribute has no Width: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the height of a Attribute. The precondition being that this Attribute actually has a height
 * \param[in] arg input Attribute
 * \param[in] height new int to set in #arg
 * \return A new Attribute with height at the right place, or a core dump if #arg did not have a height
 */
Attribute setAttributeHeight(Attribute arg, int height) {
  if (isAttributeSize(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(height)), 1);
  }

  ATabort("Attribute has no Height: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the style of a Attribute. The precondition being that this Attribute actually has a style
 * \param[in] arg input Attribute
 * \param[in] style new Style to set in #arg
 * \return A new Attribute with style at the right place, or a core dump if #arg did not have a style
 */
Attribute setAttributeStyle(Attribute arg, Style style) {
  if (isAttributeStyle(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) style), 0);
  }

  ATabort("Attribute has no Style: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the level of a Attribute. The precondition being that this Attribute actually has a level
 * \param[in] arg input Attribute
 * \param[in] level new const char* to set in #arg
 * \return A new Attribute with level at the right place, or a core dump if #arg did not have a level
 */
Attribute setAttributeLevel(Attribute arg, const char* level) {
  if (isAttributeLevel(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(level, 0, ATtrue))), 0);
  }

  ATabort("Attribute has no Level: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Set the file of a Attribute. The precondition being that this Attribute actually has a file
 * \param[in] arg input Attribute
 * \param[in] file new File to set in #arg
 * \return A new Attribute with file at the right place, or a core dump if #arg did not have a file
 */
Attribute setAttributeFile(Attribute arg, File file) {
  if (isAttributeFile(arg)) {
    return (Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) file), 0);
  }

  ATabort("Attribute has no File: %t\n", arg);
  return (Attribute)NULL;
}

/**
 * Assert whether a File is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input File
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidFile(File arg) {
  if (isFileExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a File is a external. Always returns ATtrue
 * \param[in] arg input File
 * \return ATtrue if #arg corresponds to the signature of a external, or ATfalse otherwise
 */
inline ATbool isFileExternal(File arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternFileExternal, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a File has a file. 
 * \param[in] arg input File
 * \return ATtrue if the File had a file, or ATfalse otherwise
 */
ATbool hasFileFile(File arg) {
  if (isFileExternal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the file ATerm of a File. Note that the precondition is that this File actually has a file
 * \param[in] arg input File
 * \return the file of #arg, if it exist or an undefined value if it does not
 */
ATerm getFileFile(File arg) {
  
    return (ATerm)arg;
}

/**
 * Set the file of a File. The precondition being that this File actually has a file
 * \param[in] arg input File
 * \param[in] file new ATerm to set in #arg
 * \return A new File with file at the right place, or a core dump if #arg did not have a file
 */
File setFileFile(File arg, ATerm file) {
  if (isFileExternal(arg)) {
    return (File)((ATerm) file);
  }

  ATabort("File has no File: %t\n", arg);
  return (File)NULL;
}

/**
 * Assert whether a Color is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Color
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidColor(Color arg) {
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Color is a rgb. Always returns ATtrue
 * \param[in] arg input Color
 * \return ATtrue if #arg corresponds to the signature of a rgb, or ATfalse otherwise
 */
inline ATbool isColorRgb(Color arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternColorRgb, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a Color has a red. 
 * \param[in] arg input Color
 * \return ATtrue if the Color had a red, or ATfalse otherwise
 */
ATbool hasColorRed(Color arg) {
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Color has a green. 
 * \param[in] arg input Color
 * \return ATtrue if the Color had a green, or ATfalse otherwise
 */
ATbool hasColorGreen(Color arg) {
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Color has a blue. 
 * \param[in] arg input Color
 * \return ATtrue if the Color had a blue, or ATfalse otherwise
 */
ATbool hasColorBlue(Color arg) {
  if (isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the red int of a Color. Note that the precondition is that this Color actually has a red
 * \param[in] arg input Color
 * \return the red of #arg, if it exist or an undefined value if it does not
 */
int getColorRed(Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the green int of a Color. Note that the precondition is that this Color actually has a green
 * \param[in] arg input Color
 * \return the green of #arg, if it exist or an undefined value if it does not
 */
int getColorGreen(Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Get the blue int of a Color. Note that the precondition is that this Color actually has a blue
 * \param[in] arg input Color
 * \return the blue of #arg, if it exist or an undefined value if it does not
 */
int getColorBlue(Color arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/**
 * Set the red of a Color. The precondition being that this Color actually has a red
 * \param[in] arg input Color
 * \param[in] red new int to set in #arg
 * \return A new Color with red at the right place, or a core dump if #arg did not have a red
 */
Color setColorRed(Color arg, int red) {
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(red)), 0);
  }

  ATabort("Color has no Red: %t\n", arg);
  return (Color)NULL;
}

/**
 * Set the green of a Color. The precondition being that this Color actually has a green
 * \param[in] arg input Color
 * \param[in] green new int to set in #arg
 * \return A new Color with green at the right place, or a core dump if #arg did not have a green
 */
Color setColorGreen(Color arg, int green) {
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(green)), 1);
  }

  ATabort("Color has no Green: %t\n", arg);
  return (Color)NULL;
}

/**
 * Set the blue of a Color. The precondition being that this Color actually has a blue
 * \param[in] arg input Color
 * \param[in] blue new int to set in #arg
 * \return A new Color with blue at the right place, or a core dump if #arg did not have a blue
 */
Color setColorBlue(Color arg, int blue) {
  if (isColorRgb(arg)) {
    return (Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(blue)), 2);
  }

  ATabort("Color has no Blue: %t\n", arg);
  return (Color)NULL;
}

/**
 * Assert whether a Style is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Style
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidStyle(Style arg) {
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

/**
 * Assert whether a Style is a bold. . May not be used to assert correctness of the Style
 * \param[in] arg input Style
 * \return ATtrue if #arg corresponds to the signature of a bold, or ATfalse otherwise
 */
inline ATbool isStyleBold(Style arg) {
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

/**
 * Assert whether a Style is a dashed. . May not be used to assert correctness of the Style
 * \param[in] arg input Style
 * \return ATtrue if #arg corresponds to the signature of a dashed, or ATfalse otherwise
 */
inline ATbool isStyleDashed(Style arg) {
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

/**
 * Assert whether a Style is a dotted. . May not be used to assert correctness of the Style
 * \param[in] arg input Style
 * \return ATtrue if #arg corresponds to the signature of a dotted, or ATfalse otherwise
 */
inline ATbool isStyleDotted(Style arg) {
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

/**
 * Assert whether a Style is a filled. . May not be used to assert correctness of the Style
 * \param[in] arg input Style
 * \return ATtrue if #arg corresponds to the signature of a filled, or ATfalse otherwise
 */
inline ATbool isStyleFilled(Style arg) {
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

/**
 * Assert whether a Style is a invisible. . May not be used to assert correctness of the Style
 * \param[in] arg input Style
 * \return ATtrue if #arg corresponds to the signature of a invisible, or ATfalse otherwise
 */
inline ATbool isStyleInvisible(Style arg) {
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

/**
 * Assert whether a Style is a solid. . May not be used to assert correctness of the Style
 * \param[in] arg input Style
 * \return ATtrue if #arg corresponds to the signature of a solid, or ATfalse otherwise
 */
inline ATbool isStyleSolid(Style arg) {
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

/**
 * Assert whether a Shape is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidShape(Shape arg) {
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

/**
 * Assert whether a Shape is a box. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a box, or ATfalse otherwise
 */
inline ATbool isShapeBox(Shape arg) {
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

/**
 * Assert whether a Shape is a circle. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a circle, or ATfalse otherwise
 */
inline ATbool isShapeCircle(Shape arg) {
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

/**
 * Assert whether a Shape is a diamond. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a diamond, or ATfalse otherwise
 */
inline ATbool isShapeDiamond(Shape arg) {
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

/**
 * Assert whether a Shape is a egg. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a egg, or ATfalse otherwise
 */
inline ATbool isShapeEgg(Shape arg) {
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

/**
 * Assert whether a Shape is a ellipse. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a ellipse, or ATfalse otherwise
 */
inline ATbool isShapeEllipse(Shape arg) {
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

/**
 * Assert whether a Shape is a hexagon. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a hexagon, or ATfalse otherwise
 */
inline ATbool isShapeHexagon(Shape arg) {
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

/**
 * Assert whether a Shape is a house. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a house, or ATfalse otherwise
 */
inline ATbool isShapeHouse(Shape arg) {
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

/**
 * Assert whether a Shape is a octagon. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a octagon, or ATfalse otherwise
 */
inline ATbool isShapeOctagon(Shape arg) {
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

/**
 * Assert whether a Shape is a parallelogram. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a parallelogram, or ATfalse otherwise
 */
inline ATbool isShapeParallelogram(Shape arg) {
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

/**
 * Assert whether a Shape is a plaintext. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a plaintext, or ATfalse otherwise
 */
inline ATbool isShapePlaintext(Shape arg) {
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

/**
 * Assert whether a Shape is a trapezium. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a trapezium, or ATfalse otherwise
 */
inline ATbool isShapeTrapezium(Shape arg) {
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

/**
 * Assert whether a Shape is a triangle. . May not be used to assert correctness of the Shape
 * \param[in] arg input Shape
 * \return ATtrue if #arg corresponds to the signature of a triangle, or ATfalse otherwise
 */
inline ATbool isShapeTriangle(Shape arg) {
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

/**
 * Assert whether a Direction is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Direction
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidDirection(Direction arg) {
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

/**
 * Assert whether a Direction is a forward. . May not be used to assert correctness of the Direction
 * \param[in] arg input Direction
 * \return ATtrue if #arg corresponds to the signature of a forward, or ATfalse otherwise
 */
inline ATbool isDirectionForward(Direction arg) {
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

/**
 * Assert whether a Direction is a back. . May not be used to assert correctness of the Direction
 * \param[in] arg input Direction
 * \return ATtrue if #arg corresponds to the signature of a back, or ATfalse otherwise
 */
inline ATbool isDirectionBack(Direction arg) {
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

/**
 * Assert whether a Direction is a both. . May not be used to assert correctness of the Direction
 * \param[in] arg input Direction
 * \return ATtrue if #arg corresponds to the signature of a both, or ATfalse otherwise
 */
inline ATbool isDirectionBoth(Direction arg) {
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

/**
 * Assert whether a Direction is a none. . May not be used to assert correctness of the Direction
 * \param[in] arg input Direction
 * \return ATtrue if #arg corresponds to the signature of a none, or ATfalse otherwise
 */
inline ATbool isDirectionNone(Direction arg) {
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

/**
 * Assert whether a EdgeList is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input EdgeList
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidEdgeList(EdgeList arg) {
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

/**
 * Assert whether a EdgeList is a empty. . May not be used to assert correctness of the EdgeList
 * \param[in] arg input EdgeList
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool isEdgeListEmpty(EdgeList arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternEdgeListEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a EdgeList is a single. . May not be used to assert correctness of the EdgeList
 * \param[in] arg input EdgeList
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool isEdgeListSingle(EdgeList arg) {
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

/**
 * Assert whether a EdgeList is a many. . May not be used to assert correctness of the EdgeList
 * \param[in] arg input EdgeList
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool isEdgeListMany(EdgeList arg) {
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

/**
 * Assert whether a EdgeList has a head. 
 * \param[in] arg input EdgeList
 * \return ATtrue if the EdgeList had a head, or ATfalse otherwise
 */
ATbool hasEdgeListHead(EdgeList arg) {
  if (isEdgeListSingle(arg)) {
    return ATtrue;
  }
  else if (isEdgeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a EdgeList has a tail. 
 * \param[in] arg input EdgeList
 * \return ATtrue if the EdgeList had a tail, or ATfalse otherwise
 */
ATbool hasEdgeListTail(EdgeList arg) {
  if (isEdgeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head Edge of a EdgeList. Note that the precondition is that this EdgeList actually has a head
 * \param[in] arg input EdgeList
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
Edge getEdgeListHead(EdgeList arg) {
  if (isEdgeListSingle(arg)) {
    return (Edge)ATgetFirst((ATermList)arg);
  }
  else 
    return (Edge)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail EdgeList of a EdgeList. Note that the precondition is that this EdgeList actually has a tail
 * \param[in] arg input EdgeList
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
EdgeList getEdgeListTail(EdgeList arg) {
  
    return (EdgeList)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a EdgeList. The precondition being that this EdgeList actually has a head
 * \param[in] arg input EdgeList
 * \param[in] head new Edge to set in #arg
 * \return A new EdgeList with head at the right place, or a core dump if #arg did not have a head
 */
EdgeList setEdgeListHead(EdgeList arg, Edge head) {
  if (isEdgeListSingle(arg)) {
    return (EdgeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (isEdgeListMany(arg)) {
    return (EdgeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("EdgeList has no Head: %t\n", arg);
  return (EdgeList)NULL;
}

/**
 * Set the tail of a EdgeList. The precondition being that this EdgeList actually has a tail
 * \param[in] arg input EdgeList
 * \param[in] tail new EdgeList to set in #arg
 * \return A new EdgeList with tail at the right place, or a core dump if #arg did not have a tail
 */
EdgeList setEdgeListTail(EdgeList arg, EdgeList tail) {
  if (isEdgeListMany(arg)) {
    return (EdgeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("EdgeList has no Tail: %t\n", arg);
  return (EdgeList)NULL;
}

/**
 * Assert whether a Edge is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Edge
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidEdge(Edge arg) {
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Edge is a default. Always returns ATtrue
 * \param[in] arg input Edge
 * \return ATtrue if #arg corresponds to the signature of a default, or ATfalse otherwise
 */
inline ATbool isEdgeDefault(Edge arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternEdgeDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a Edge has a from. 
 * \param[in] arg input Edge
 * \return ATtrue if the Edge had a from, or ATfalse otherwise
 */
ATbool hasEdgeFrom(Edge arg) {
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Edge has a to. 
 * \param[in] arg input Edge
 * \return ATtrue if the Edge had a to, or ATfalse otherwise
 */
ATbool hasEdgeTo(Edge arg) {
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Edge has a attributes. 
 * \param[in] arg input Edge
 * \return ATtrue if the Edge had a attributes, or ATfalse otherwise
 */
ATbool hasEdgeAttributes(Edge arg) {
  if (isEdgeDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the from NodeId of a Edge. Note that the precondition is that this Edge actually has a from
 * \param[in] arg input Edge
 * \return the from of #arg, if it exist or an undefined value if it does not
 */
NodeId getEdgeFrom(Edge arg) {
  
    return (NodeId)ATgetArgument((ATermAppl)arg, 0);
}

/**
 * Get the to NodeId of a Edge. Note that the precondition is that this Edge actually has a to
 * \param[in] arg input Edge
 * \return the to of #arg, if it exist or an undefined value if it does not
 */
NodeId getEdgeTo(Edge arg) {
  
    return (NodeId)ATgetArgument((ATermAppl)arg, 1);
}

/**
 * Get the attributes AttributeList of a Edge. Note that the precondition is that this Edge actually has a attributes
 * \param[in] arg input Edge
 * \return the attributes of #arg, if it exist or an undefined value if it does not
 */
AttributeList getEdgeAttributes(Edge arg) {
  
    return (AttributeList)ATgetArgument((ATermAppl)arg, 2);
}

/**
 * Set the from of a Edge. The precondition being that this Edge actually has a from
 * \param[in] arg input Edge
 * \param[in] from new NodeId to set in #arg
 * \return A new Edge with from at the right place, or a core dump if #arg did not have a from
 */
Edge setEdgeFrom(Edge arg, NodeId from) {
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) from), 0);
  }

  ATabort("Edge has no From: %t\n", arg);
  return (Edge)NULL;
}

/**
 * Set the to of a Edge. The precondition being that this Edge actually has a to
 * \param[in] arg input Edge
 * \param[in] to new NodeId to set in #arg
 * \return A new Edge with to at the right place, or a core dump if #arg did not have a to
 */
Edge setEdgeTo(Edge arg, NodeId to) {
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) to), 1);
  }

  ATabort("Edge has no To: %t\n", arg);
  return (Edge)NULL;
}

/**
 * Set the attributes of a Edge. The precondition being that this Edge actually has a attributes
 * \param[in] arg input Edge
 * \param[in] attributes new AttributeList to set in #arg
 * \return A new Edge with attributes at the right place, or a core dump if #arg did not have a attributes
 */
Edge setEdgeAttributes(Edge arg, AttributeList attributes) {
  if (isEdgeDefault(arg)) {
    return (Edge)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 2);
  }

  ATabort("Edge has no Attributes: %t\n", arg);
  return (Edge)NULL;
}

/**
 * Assert whether a Polygon is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Polygon
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidPolygon(Polygon arg) {
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

/**
 * Assert whether a Polygon is a empty. . May not be used to assert correctness of the Polygon
 * \param[in] arg input Polygon
 * \return ATtrue if #arg corresponds to the signature of a empty, or ATfalse otherwise
 */
inline ATbool isPolygonEmpty(Polygon arg) {
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternPolygonEmpty));
#endif
  return ATtrue;
}

/**
 * Assert whether a Polygon is a single. . May not be used to assert correctness of the Polygon
 * \param[in] arg input Polygon
 * \return ATtrue if #arg corresponds to the signature of a single, or ATfalse otherwise
 */
inline ATbool isPolygonSingle(Polygon arg) {
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

/**
 * Assert whether a Polygon is a many. . May not be used to assert correctness of the Polygon
 * \param[in] arg input Polygon
 * \return ATtrue if #arg corresponds to the signature of a many, or ATfalse otherwise
 */
inline ATbool isPolygonMany(Polygon arg) {
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

/**
 * Assert whether a Polygon has a head. 
 * \param[in] arg input Polygon
 * \return ATtrue if the Polygon had a head, or ATfalse otherwise
 */
ATbool hasPolygonHead(Polygon arg) {
  if (isPolygonSingle(arg)) {
    return ATtrue;
  }
  else if (isPolygonMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Polygon has a tail. 
 * \param[in] arg input Polygon
 * \return ATtrue if the Polygon had a tail, or ATfalse otherwise
 */
ATbool hasPolygonTail(Polygon arg) {
  if (isPolygonMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the head Point of a Polygon. Note that the precondition is that this Polygon actually has a head
 * \param[in] arg input Polygon
 * \return the head of #arg, if it exist or an undefined value if it does not
 */
Point getPolygonHead(Polygon arg) {
  if (isPolygonSingle(arg)) {
    return (Point)ATgetFirst((ATermList)arg);
  }
  else 
    return (Point)ATgetFirst((ATermList)arg);
}

/**
 * Get the tail Polygon of a Polygon. Note that the precondition is that this Polygon actually has a tail
 * \param[in] arg input Polygon
 * \return the tail of #arg, if it exist or an undefined value if it does not
 */
Polygon getPolygonTail(Polygon arg) {
  
    return (Polygon)ATgetNext((ATermList)arg);
}

/**
 * Set the head of a Polygon. The precondition being that this Polygon actually has a head
 * \param[in] arg input Polygon
 * \param[in] head new Point to set in #arg
 * \return A new Polygon with head at the right place, or a core dump if #arg did not have a head
 */
Polygon setPolygonHead(Polygon arg, Point head) {
  if (isPolygonSingle(arg)) {
    return (Polygon)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (isPolygonMany(arg)) {
    return (Polygon)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Polygon has no Head: %t\n", arg);
  return (Polygon)NULL;
}

/**
 * Set the tail of a Polygon. The precondition being that this Polygon actually has a tail
 * \param[in] arg input Polygon
 * \param[in] tail new Polygon to set in #arg
 * \return A new Polygon with tail at the right place, or a core dump if #arg did not have a tail
 */
Polygon setPolygonTail(Polygon arg, Polygon tail) {
  if (isPolygonMany(arg)) {
    return (Polygon)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Polygon has no Tail: %t\n", arg);
  return (Polygon)NULL;
}

/**
 * Assert whether a Point is any of the valid alternatives, or not. This analysis does not go any deeper than the top level
 * \param[in] arg input Point
 * \return ATtrue if #arg corresponds to the expected signature, or ATfalse otherwise
 */
ATbool isValidPoint(Point arg) {
  if (isPointDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Point is a default. Always returns ATtrue
 * \param[in] arg input Point
 * \return ATtrue if #arg corresponds to the signature of a default, or ATfalse otherwise
 */
inline ATbool isPointDefault(Point arg) {
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, patternPointDefault, NULL, NULL));
#endif
  return ATtrue;
}

/**
 * Assert whether a Point has a x. 
 * \param[in] arg input Point
 * \return ATtrue if the Point had a x, or ATfalse otherwise
 */
ATbool hasPointX(Point arg) {
  if (isPointDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Assert whether a Point has a y. 
 * \param[in] arg input Point
 * \return ATtrue if the Point had a y, or ATfalse otherwise
 */
ATbool hasPointY(Point arg) {
  if (isPointDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/**
 * Get the x int of a Point. Note that the precondition is that this Point actually has a x
 * \param[in] arg input Point
 * \return the x of #arg, if it exist or an undefined value if it does not
 */
int getPointX(Point arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/**
 * Get the y int of a Point. Note that the precondition is that this Point actually has a y
 * \param[in] arg input Point
 * \return the y of #arg, if it exist or an undefined value if it does not
 */
int getPointY(Point arg) {
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/**
 * Set the x of a Point. The precondition being that this Point actually has a x
 * \param[in] arg input Point
 * \param[in] x new int to set in #arg
 * \return A new Point with x at the right place, or a core dump if #arg did not have a x
 */
Point setPointX(Point arg, int x) {
  if (isPointDefault(arg)) {
    return (Point)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(x)), 0);
  }

  ATabort("Point has no X: %t\n", arg);
  return (Point)NULL;
}

/**
 * Set the y of a Point. The precondition being that this Point actually has a y
 * \param[in] arg input Point
 * \param[in] y new int to set in #arg
 * \return A new Point with y at the right place, or a core dump if #arg did not have a y
 */
Point setPointY(Point arg, int y) {
  if (isPointDefault(arg)) {
    return (Point)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(y)), 1);
  }

  ATabort("Point has no Y: %t\n", arg);
  return (Point)NULL;
}

/**
 * Apply functions to the children of a Graph. 
 * \return A new Graph with new children where the argument functions might have applied
 */
Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList), AttributeList (*acceptAttributes)(AttributeList)) {
  if (isGraphDefault(arg)) {
    return makeGraphDefault(
        acceptNodes ? acceptNodes(getGraphNodes(arg)) : getGraphNodes(arg),
        acceptEdges ? acceptEdges(getGraphEdges(arg)) : getGraphEdges(arg),
        acceptAttributes ? acceptAttributes(getGraphAttributes(arg)) : getGraphAttributes(arg));
  }
  ATabort("not a Graph: %t\n", arg);
  return (Graph)NULL;
}
/**
 * Apply functions to the children of a NodeList. 
 * \return A new NodeList with new children where the argument functions might have applied
 */
NodeList visitNodeList(NodeList arg, Node (*acceptHead)(Node)) {
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
/**
 * Apply functions to the children of a Node. 
 * \return A new Node with new children where the argument functions might have applied
 */
Node visitNode(Node arg, NodeId (*acceptId)(NodeId), AttributeList (*acceptAttributes)(AttributeList), NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList)) {
  if (isNodeNode(arg)) {
    return makeNodeNode(
        acceptId ? acceptId(getNodeId(arg)) : getNodeId(arg),
        acceptAttributes ? acceptAttributes(getNodeAttributes(arg)) : getNodeAttributes(arg));
  }
  if (isNodeSubgraph(arg)) {
    return makeNodeSubgraph(
        acceptId ? acceptId(getNodeId(arg)) : getNodeId(arg),
        acceptNodes ? acceptNodes(getNodeNodes(arg)) : getNodeNodes(arg),
        acceptEdges ? acceptEdges(getNodeEdges(arg)) : getNodeEdges(arg),
        acceptAttributes ? acceptAttributes(getNodeAttributes(arg)) : getNodeAttributes(arg));
  }
  ATabort("not a Node: %t\n", arg);
  return (Node)NULL;
}
/**
 * Apply functions to the children of a NodeId. 
 * \return A new NodeId with new children where the argument functions might have applied
 */
NodeId visitNodeId(NodeId arg, ATerm (*acceptId)(ATerm)) {
  if (isNodeIdDefault(arg)) {
    return makeNodeIdDefault(
        acceptId ? acceptId(getNodeIdId(arg)) : getNodeIdId(arg));
  }
  ATabort("not a NodeId: %t\n", arg);
  return (NodeId)NULL;
}
/**
 * Apply functions to the children of a AttributeList. 
 * \return A new AttributeList with new children where the argument functions might have applied
 */
AttributeList visitAttributeList(AttributeList arg, Attribute (*acceptHead)(Attribute)) {
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
/**
 * Apply functions to the children of a Attribute. 
 * \return A new Attribute with new children where the argument functions might have applied
 */
Attribute visitAttribute(Attribute arg, Point (*acceptFirst)(Point), Point (*acceptSecond)(Point), Color (*acceptColor)(Color), Polygon (*acceptPoints)(Polygon), Direction (*acceptDirection)(Direction), char* (*acceptKey)(char*), ATerm (*acceptValue)(ATerm), char* (*acceptLabel)(char*), char* (*acceptTooltip)(char*), int (*acceptX)(int), int (*acceptY)(int), Shape (*acceptShape)(Shape), int (*acceptWidth)(int), int (*acceptHeight)(int), Style (*acceptStyle)(Style), char* (*acceptLevel)(char*), File (*acceptFile)(File)) {
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
  if (isAttributeTooltip(arg)) {
    return makeAttributeTooltip(
        acceptTooltip ? acceptTooltip(getAttributeTooltip(arg)) : getAttributeTooltip(arg));
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
  if (isAttributeLevel(arg)) {
    return makeAttributeLevel(
        acceptLevel ? acceptLevel(getAttributeLevel(arg)) : getAttributeLevel(arg));
  }
  if (isAttributeFile(arg)) {
    return makeAttributeFile(
        acceptFile ? acceptFile(getAttributeFile(arg)) : getAttributeFile(arg));
  }
  ATabort("not a Attribute: %t\n", arg);
  return (Attribute)NULL;
}
/**
 * Apply functions to the children of a File. 
 * \return A new File with new children where the argument functions might have applied
 */
File visitFile(File arg, ATerm (*acceptFile)(ATerm)) {
  if (isFileExternal(arg)) {
    return makeFileExternal(
        acceptFile ? acceptFile(getFileFile(arg)) : getFileFile(arg));
  }
  ATabort("not a File: %t\n", arg);
  return (File)NULL;
}
/**
 * Apply functions to the children of a Color. 
 * \return A new Color with new children where the argument functions might have applied
 */
Color visitColor(Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int)) {
  if (isColorRgb(arg)) {
    return makeColorRgb(
        acceptRed ? acceptRed(getColorRed(arg)) : getColorRed(arg),
        acceptGreen ? acceptGreen(getColorGreen(arg)) : getColorGreen(arg),
        acceptBlue ? acceptBlue(getColorBlue(arg)) : getColorBlue(arg));
  }
  ATabort("not a Color: %t\n", arg);
  return (Color)NULL;
}
/**
 * Apply functions to the children of a Style. 
 * \return A new Style with new children where the argument functions might have applied
 */
Style visitStyle(Style arg) {
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
/**
 * Apply functions to the children of a Shape. 
 * \return A new Shape with new children where the argument functions might have applied
 */
Shape visitShape(Shape arg) {
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
/**
 * Apply functions to the children of a Direction. 
 * \return A new Direction with new children where the argument functions might have applied
 */
Direction visitDirection(Direction arg) {
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
/**
 * Apply functions to the children of a EdgeList. 
 * \return A new EdgeList with new children where the argument functions might have applied
 */
EdgeList visitEdgeList(EdgeList arg, Edge (*acceptHead)(Edge)) {
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
/**
 * Apply functions to the children of a Edge. 
 * \return A new Edge with new children where the argument functions might have applied
 */
Edge visitEdge(Edge arg, NodeId (*acceptFrom)(NodeId), NodeId (*acceptTo)(NodeId), AttributeList (*acceptAttributes)(AttributeList)) {
  if (isEdgeDefault(arg)) {
    return makeEdgeDefault(
        acceptFrom ? acceptFrom(getEdgeFrom(arg)) : getEdgeFrom(arg),
        acceptTo ? acceptTo(getEdgeTo(arg)) : getEdgeTo(arg),
        acceptAttributes ? acceptAttributes(getEdgeAttributes(arg)) : getEdgeAttributes(arg));
  }
  ATabort("not a Edge: %t\n", arg);
  return (Edge)NULL;
}
/**
 * Apply functions to the children of a Polygon. 
 * \return A new Polygon with new children where the argument functions might have applied
 */
Polygon visitPolygon(Polygon arg, Point (*acceptHead)(Point)) {
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
/**
 * Apply functions to the children of a Point. 
 * \return A new Point with new children where the argument functions might have applied
 */
Point visitPoint(Point arg, int (*acceptX)(int), int (*acceptY)(int)) {
  if (isPointDefault(arg)) {
    return makePointDefault(
        acceptX ? acceptX(getPointX(arg)) : getPointX(arg),
        acceptY ? acceptY(getPointY(arg)) : getPointY(arg));
  }
  ATabort("not a Point: %t\n", arg);
  return (Point)NULL;
}

