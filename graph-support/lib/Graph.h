#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Graph_dict.h"

typedef struct _Graph *Graph;
typedef struct _NodeList *NodeList;
typedef struct _Node *Node;
typedef struct _NodeId *NodeId;
typedef struct _AttributeList *AttributeList;
typedef struct _Attribute *Attribute;
typedef struct _File *File;
typedef struct _Color *Color;
typedef struct _Style *Style;
typedef struct _Shape *Shape;
typedef struct _Direction *Direction;
typedef struct _EdgeList *EdgeList;
typedef struct _Edge *Edge;
typedef struct _Polygon *Polygon;
typedef struct _Point *Point;

#ifdef FAST_API
#define initGraphApi() (init_Graph_dict())
#else
void _initGraphApi(void);
#define initGraphApi() (_initGraphApi())
#endif

#ifdef FAST_API
#define protectGraph(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectGraph(Graph *arg);
#define protectGraph(arg) (_protectGraph(arg))
#endif
#ifdef FAST_API
#define unprotectGraph(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectGraph(Graph *arg);
#define unprotectGraph(arg) (_unprotectGraph(arg))
#endif
#ifdef FAST_API
#define protectNodeList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectNodeList(NodeList *arg);
#define protectNodeList(arg) (_protectNodeList(arg))
#endif
#ifdef FAST_API
#define unprotectNodeList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectNodeList(NodeList *arg);
#define unprotectNodeList(arg) (_unprotectNodeList(arg))
#endif
#ifdef FAST_API
#define protectNode(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectNode(Node *arg);
#define protectNode(arg) (_protectNode(arg))
#endif
#ifdef FAST_API
#define unprotectNode(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectNode(Node *arg);
#define unprotectNode(arg) (_unprotectNode(arg))
#endif
#ifdef FAST_API
#define protectNodeId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectNodeId(NodeId *arg);
#define protectNodeId(arg) (_protectNodeId(arg))
#endif
#ifdef FAST_API
#define unprotectNodeId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectNodeId(NodeId *arg);
#define unprotectNodeId(arg) (_unprotectNodeId(arg))
#endif
#ifdef FAST_API
#define protectAttributeList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectAttributeList(AttributeList *arg);
#define protectAttributeList(arg) (_protectAttributeList(arg))
#endif
#ifdef FAST_API
#define unprotectAttributeList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectAttributeList(AttributeList *arg);
#define unprotectAttributeList(arg) (_unprotectAttributeList(arg))
#endif
#ifdef FAST_API
#define protectAttribute(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectAttribute(Attribute *arg);
#define protectAttribute(arg) (_protectAttribute(arg))
#endif
#ifdef FAST_API
#define unprotectAttribute(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectAttribute(Attribute *arg);
#define unprotectAttribute(arg) (_unprotectAttribute(arg))
#endif
#ifdef FAST_API
#define protectFile(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectFile(File *arg);
#define protectFile(arg) (_protectFile(arg))
#endif
#ifdef FAST_API
#define unprotectFile(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectFile(File *arg);
#define unprotectFile(arg) (_unprotectFile(arg))
#endif
#ifdef FAST_API
#define protectColor(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectColor(Color *arg);
#define protectColor(arg) (_protectColor(arg))
#endif
#ifdef FAST_API
#define unprotectColor(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectColor(Color *arg);
#define unprotectColor(arg) (_unprotectColor(arg))
#endif
#ifdef FAST_API
#define protectStyle(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectStyle(Style *arg);
#define protectStyle(arg) (_protectStyle(arg))
#endif
#ifdef FAST_API
#define unprotectStyle(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectStyle(Style *arg);
#define unprotectStyle(arg) (_unprotectStyle(arg))
#endif
#ifdef FAST_API
#define protectShape(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectShape(Shape *arg);
#define protectShape(arg) (_protectShape(arg))
#endif
#ifdef FAST_API
#define unprotectShape(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectShape(Shape *arg);
#define unprotectShape(arg) (_unprotectShape(arg))
#endif
#ifdef FAST_API
#define protectDirection(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectDirection(Direction *arg);
#define protectDirection(arg) (_protectDirection(arg))
#endif
#ifdef FAST_API
#define unprotectDirection(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectDirection(Direction *arg);
#define unprotectDirection(arg) (_unprotectDirection(arg))
#endif
#ifdef FAST_API
#define protectEdgeList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectEdgeList(EdgeList *arg);
#define protectEdgeList(arg) (_protectEdgeList(arg))
#endif
#ifdef FAST_API
#define unprotectEdgeList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectEdgeList(EdgeList *arg);
#define unprotectEdgeList(arg) (_unprotectEdgeList(arg))
#endif
#ifdef FAST_API
#define protectEdge(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectEdge(Edge *arg);
#define protectEdge(arg) (_protectEdge(arg))
#endif
#ifdef FAST_API
#define unprotectEdge(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectEdge(Edge *arg);
#define unprotectEdge(arg) (_unprotectEdge(arg))
#endif
#ifdef FAST_API
#define protectPolygon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectPolygon(Polygon *arg);
#define protectPolygon(arg) (_protectPolygon(arg))
#endif
#ifdef FAST_API
#define unprotectPolygon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectPolygon(Polygon *arg);
#define unprotectPolygon(arg) (_unprotectPolygon(arg))
#endif
#ifdef FAST_API
#define protectPoint(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _protectPoint(Point *arg);
#define protectPoint(arg) (_protectPoint(arg))
#endif
#ifdef FAST_API
#define unprotectPoint(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _unprotectPoint(Point *arg);
#define unprotectPoint(arg) (_unprotectPoint(arg))
#endif
#ifdef FAST_API
#define GraphFromTerm(t) ((((union {Graph target; ATerm source; })(t)).target))
#else
Graph _GraphFromTerm(ATerm t);
#define GraphFromTerm(t) (_GraphFromTerm(t))
#endif
#ifdef FAST_API
#define GraphToTerm(arg) ((((union {Graph source; ATerm target; })(arg)).target))
#else
ATerm _GraphToTerm(Graph arg);
#define GraphToTerm(arg) (_GraphToTerm(arg))
#endif
#ifdef FAST_API
#define NodeListFromTerm(t) ((((union {NodeList target; ATerm source; })(t)).target))
#else
NodeList _NodeListFromTerm(ATerm t);
#define NodeListFromTerm(t) (_NodeListFromTerm(t))
#endif
#ifdef FAST_API
#define NodeListToTerm(arg) ((((union {NodeList source; ATerm target; })(arg)).target))
#else
ATerm _NodeListToTerm(NodeList arg);
#define NodeListToTerm(arg) (_NodeListToTerm(arg))
#endif
#ifdef FAST_API
#define NodeFromTerm(t) ((((union {Node target; ATerm source; })(t)).target))
#else
Node _NodeFromTerm(ATerm t);
#define NodeFromTerm(t) (_NodeFromTerm(t))
#endif
#ifdef FAST_API
#define NodeToTerm(arg) ((((union {Node source; ATerm target; })(arg)).target))
#else
ATerm _NodeToTerm(Node arg);
#define NodeToTerm(arg) (_NodeToTerm(arg))
#endif
#ifdef FAST_API
#define NodeIdFromTerm(t) ((((union {NodeId target; ATerm source; })(t)).target))
#else
NodeId _NodeIdFromTerm(ATerm t);
#define NodeIdFromTerm(t) (_NodeIdFromTerm(t))
#endif
#ifdef FAST_API
#define NodeIdToTerm(arg) ((((union {NodeId source; ATerm target; })(arg)).target))
#else
ATerm _NodeIdToTerm(NodeId arg);
#define NodeIdToTerm(arg) (_NodeIdToTerm(arg))
#endif
#ifdef FAST_API
#define AttributeListFromTerm(t) ((((union {AttributeList target; ATerm source; })(t)).target))
#else
AttributeList _AttributeListFromTerm(ATerm t);
#define AttributeListFromTerm(t) (_AttributeListFromTerm(t))
#endif
#ifdef FAST_API
#define AttributeListToTerm(arg) ((((union {AttributeList source; ATerm target; })(arg)).target))
#else
ATerm _AttributeListToTerm(AttributeList arg);
#define AttributeListToTerm(arg) (_AttributeListToTerm(arg))
#endif
#ifdef FAST_API
#define AttributeFromTerm(t) ((((union {Attribute target; ATerm source; })(t)).target))
#else
Attribute _AttributeFromTerm(ATerm t);
#define AttributeFromTerm(t) (_AttributeFromTerm(t))
#endif
#ifdef FAST_API
#define AttributeToTerm(arg) ((((union {Attribute source; ATerm target; })(arg)).target))
#else
ATerm _AttributeToTerm(Attribute arg);
#define AttributeToTerm(arg) (_AttributeToTerm(arg))
#endif
#ifdef FAST_API
#define FileFromTerm(t) ((((union {File target; ATerm source; })(t)).target))
#else
File _FileFromTerm(ATerm t);
#define FileFromTerm(t) (_FileFromTerm(t))
#endif
#ifdef FAST_API
#define FileToTerm(arg) ((((union {File source; ATerm target; })(arg)).target))
#else
ATerm _FileToTerm(File arg);
#define FileToTerm(arg) (_FileToTerm(arg))
#endif
#ifdef FAST_API
#define ColorFromTerm(t) ((((union {Color target; ATerm source; })(t)).target))
#else
Color _ColorFromTerm(ATerm t);
#define ColorFromTerm(t) (_ColorFromTerm(t))
#endif
#ifdef FAST_API
#define ColorToTerm(arg) ((((union {Color source; ATerm target; })(arg)).target))
#else
ATerm _ColorToTerm(Color arg);
#define ColorToTerm(arg) (_ColorToTerm(arg))
#endif
#ifdef FAST_API
#define StyleFromTerm(t) ((((union {Style target; ATerm source; })(t)).target))
#else
Style _StyleFromTerm(ATerm t);
#define StyleFromTerm(t) (_StyleFromTerm(t))
#endif
#ifdef FAST_API
#define StyleToTerm(arg) ((((union {Style source; ATerm target; })(arg)).target))
#else
ATerm _StyleToTerm(Style arg);
#define StyleToTerm(arg) (_StyleToTerm(arg))
#endif
#ifdef FAST_API
#define ShapeFromTerm(t) ((((union {Shape target; ATerm source; })(t)).target))
#else
Shape _ShapeFromTerm(ATerm t);
#define ShapeFromTerm(t) (_ShapeFromTerm(t))
#endif
#ifdef FAST_API
#define ShapeToTerm(arg) ((((union {Shape source; ATerm target; })(arg)).target))
#else
ATerm _ShapeToTerm(Shape arg);
#define ShapeToTerm(arg) (_ShapeToTerm(arg))
#endif
#ifdef FAST_API
#define DirectionFromTerm(t) ((((union {Direction target; ATerm source; })(t)).target))
#else
Direction _DirectionFromTerm(ATerm t);
#define DirectionFromTerm(t) (_DirectionFromTerm(t))
#endif
#ifdef FAST_API
#define DirectionToTerm(arg) ((((union {Direction source; ATerm target; })(arg)).target))
#else
ATerm _DirectionToTerm(Direction arg);
#define DirectionToTerm(arg) (_DirectionToTerm(arg))
#endif
#ifdef FAST_API
#define EdgeListFromTerm(t) ((((union {EdgeList target; ATerm source; })(t)).target))
#else
EdgeList _EdgeListFromTerm(ATerm t);
#define EdgeListFromTerm(t) (_EdgeListFromTerm(t))
#endif
#ifdef FAST_API
#define EdgeListToTerm(arg) ((((union {EdgeList source; ATerm target; })(arg)).target))
#else
ATerm _EdgeListToTerm(EdgeList arg);
#define EdgeListToTerm(arg) (_EdgeListToTerm(arg))
#endif
#ifdef FAST_API
#define EdgeFromTerm(t) ((((union {Edge target; ATerm source; })(t)).target))
#else
Edge _EdgeFromTerm(ATerm t);
#define EdgeFromTerm(t) (_EdgeFromTerm(t))
#endif
#ifdef FAST_API
#define EdgeToTerm(arg) ((((union {Edge source; ATerm target; })(arg)).target))
#else
ATerm _EdgeToTerm(Edge arg);
#define EdgeToTerm(arg) (_EdgeToTerm(arg))
#endif
#ifdef FAST_API
#define PolygonFromTerm(t) ((((union {Polygon target; ATerm source; })(t)).target))
#else
Polygon _PolygonFromTerm(ATerm t);
#define PolygonFromTerm(t) (_PolygonFromTerm(t))
#endif
#ifdef FAST_API
#define PolygonToTerm(arg) ((((union {Polygon source; ATerm target; })(arg)).target))
#else
ATerm _PolygonToTerm(Polygon arg);
#define PolygonToTerm(arg) (_PolygonToTerm(arg))
#endif
#ifdef FAST_API
#define PointFromTerm(t) ((((union {Point target; ATerm source; })(t)).target))
#else
Point _PointFromTerm(ATerm t);
#define PointFromTerm(t) (_PointFromTerm(t))
#endif
#ifdef FAST_API
#define PointToTerm(arg) ((((union {Point source; ATerm target; })(arg)).target))
#else
ATerm _PointToTerm(Point arg);
#define PointToTerm(arg) (_PointToTerm(arg))
#endif
#ifdef FAST_API
#define getNodeListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _getNodeListLength(NodeList arg);
#define getNodeListLength(arg) (_getNodeListLength(arg))
#endif
#ifdef FAST_API
#define reverseNodeList(arg) ((NodeList) ATreverse((ATermList) (arg)))
#else
NodeList _reverseNodeList(NodeList arg);
#define reverseNodeList(arg) (_reverseNodeList(arg))
#endif
#ifdef FAST_API
#define appendNodeList(arg, elem) ((NodeList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
NodeList _appendNodeList(NodeList arg, Node elem);
#define appendNodeList(arg, elem) (_appendNodeList(arg, elem))
#endif
#ifdef FAST_API
#define concatNodeList(arg0, arg1) ((NodeList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
NodeList _concatNodeList(NodeList arg0, NodeList arg1);
#define concatNodeList(arg0, arg1) (_concatNodeList(arg0, arg1))
#endif
#ifdef FAST_API
#define sliceNodeList(arg, start, end) ((NodeList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
NodeList _sliceNodeList(NodeList arg, int start, int end);
#define sliceNodeList(arg, start, end) (_sliceNodeList(arg, start, end))
#endif
#ifdef FAST_API
#define getNodeListNodeAt(arg, index) ((Node) (ATelementAt((ATermList) arg,index)))
#else
Node _getNodeListNodeAt(NodeList arg, int index);
#define getNodeListNodeAt(arg, index) (_getNodeListNodeAt(arg, index))
#endif
#ifdef FAST_API
#define replaceNodeListNodeAt(arg, elem, index) ((NodeList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
NodeList _replaceNodeListNodeAt(NodeList arg, Node elem, int index);
#define replaceNodeListNodeAt(arg, elem, index) (_replaceNodeListNodeAt(arg, elem, index))
#endif
#ifdef FAST_API
#define makeNodeList2(elem1,  elem2) ((NodeList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
NodeList _makeNodeList2(Node elem1, Node elem2);
#define makeNodeList2(elem1,  elem2) (_makeNodeList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define makeNodeList3(elem1, elem2,  elem3) ((NodeList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
NodeList _makeNodeList3(Node elem1, Node elem2, Node elem3);
#define makeNodeList3(elem1, elem2,  elem3) (_makeNodeList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define makeNodeList4(elem1, elem2, elem3,  elem4) ((NodeList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
NodeList _makeNodeList4(Node elem1, Node elem2, Node elem3, Node elem4);
#define makeNodeList4(elem1, elem2, elem3,  elem4) (_makeNodeList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define makeNodeList5(elem1, elem2, elem3, elem4,  elem5) ((NodeList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
NodeList _makeNodeList5(Node elem1, Node elem2, Node elem3, Node elem4, Node elem5);
#define makeNodeList5(elem1, elem2, elem3, elem4,  elem5) (_makeNodeList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define makeNodeList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((NodeList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
NodeList _makeNodeList6(Node elem1, Node elem2, Node elem3, Node elem4, Node elem5, Node elem6);
#define makeNodeList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_makeNodeList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define getAttributeListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _getAttributeListLength(AttributeList arg);
#define getAttributeListLength(arg) (_getAttributeListLength(arg))
#endif
#ifdef FAST_API
#define reverseAttributeList(arg) ((AttributeList) ATreverse((ATermList) (arg)))
#else
AttributeList _reverseAttributeList(AttributeList arg);
#define reverseAttributeList(arg) (_reverseAttributeList(arg))
#endif
#ifdef FAST_API
#define appendAttributeList(arg, elem) ((AttributeList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
AttributeList _appendAttributeList(AttributeList arg, Attribute elem);
#define appendAttributeList(arg, elem) (_appendAttributeList(arg, elem))
#endif
#ifdef FAST_API
#define concatAttributeList(arg0, arg1) ((AttributeList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
AttributeList _concatAttributeList(AttributeList arg0, AttributeList arg1);
#define concatAttributeList(arg0, arg1) (_concatAttributeList(arg0, arg1))
#endif
#ifdef FAST_API
#define sliceAttributeList(arg, start, end) ((AttributeList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
AttributeList _sliceAttributeList(AttributeList arg, int start, int end);
#define sliceAttributeList(arg, start, end) (_sliceAttributeList(arg, start, end))
#endif
#ifdef FAST_API
#define getAttributeListAttributeAt(arg, index) ((Attribute) (ATelementAt((ATermList) arg,index)))
#else
Attribute _getAttributeListAttributeAt(AttributeList arg, int index);
#define getAttributeListAttributeAt(arg, index) (_getAttributeListAttributeAt(arg, index))
#endif
#ifdef FAST_API
#define replaceAttributeListAttributeAt(arg, elem, index) ((AttributeList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
AttributeList _replaceAttributeListAttributeAt(AttributeList arg, Attribute elem, int index);
#define replaceAttributeListAttributeAt(arg, elem, index) (_replaceAttributeListAttributeAt(arg, elem, index))
#endif
#ifdef FAST_API
#define makeAttributeList2(elem1,  elem2) ((AttributeList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
AttributeList _makeAttributeList2(Attribute elem1, Attribute elem2);
#define makeAttributeList2(elem1,  elem2) (_makeAttributeList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define makeAttributeList3(elem1, elem2,  elem3) ((AttributeList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
AttributeList _makeAttributeList3(Attribute elem1, Attribute elem2, Attribute elem3);
#define makeAttributeList3(elem1, elem2,  elem3) (_makeAttributeList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define makeAttributeList4(elem1, elem2, elem3,  elem4) ((AttributeList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
AttributeList _makeAttributeList4(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4);
#define makeAttributeList4(elem1, elem2, elem3,  elem4) (_makeAttributeList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define makeAttributeList5(elem1, elem2, elem3, elem4,  elem5) ((AttributeList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
AttributeList _makeAttributeList5(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4, Attribute elem5);
#define makeAttributeList5(elem1, elem2, elem3, elem4,  elem5) (_makeAttributeList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define makeAttributeList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((AttributeList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
AttributeList _makeAttributeList6(Attribute elem1, Attribute elem2, Attribute elem3, Attribute elem4, Attribute elem5, Attribute elem6);
#define makeAttributeList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_makeAttributeList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define getEdgeListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _getEdgeListLength(EdgeList arg);
#define getEdgeListLength(arg) (_getEdgeListLength(arg))
#endif
#ifdef FAST_API
#define reverseEdgeList(arg) ((EdgeList) ATreverse((ATermList) (arg)))
#else
EdgeList _reverseEdgeList(EdgeList arg);
#define reverseEdgeList(arg) (_reverseEdgeList(arg))
#endif
#ifdef FAST_API
#define appendEdgeList(arg, elem) ((EdgeList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
EdgeList _appendEdgeList(EdgeList arg, Edge elem);
#define appendEdgeList(arg, elem) (_appendEdgeList(arg, elem))
#endif
#ifdef FAST_API
#define concatEdgeList(arg0, arg1) ((EdgeList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
EdgeList _concatEdgeList(EdgeList arg0, EdgeList arg1);
#define concatEdgeList(arg0, arg1) (_concatEdgeList(arg0, arg1))
#endif
#ifdef FAST_API
#define sliceEdgeList(arg, start, end) ((EdgeList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
EdgeList _sliceEdgeList(EdgeList arg, int start, int end);
#define sliceEdgeList(arg, start, end) (_sliceEdgeList(arg, start, end))
#endif
#ifdef FAST_API
#define getEdgeListEdgeAt(arg, index) ((Edge) (ATelementAt((ATermList) arg,index)))
#else
Edge _getEdgeListEdgeAt(EdgeList arg, int index);
#define getEdgeListEdgeAt(arg, index) (_getEdgeListEdgeAt(arg, index))
#endif
#ifdef FAST_API
#define replaceEdgeListEdgeAt(arg, elem, index) ((EdgeList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
EdgeList _replaceEdgeListEdgeAt(EdgeList arg, Edge elem, int index);
#define replaceEdgeListEdgeAt(arg, elem, index) (_replaceEdgeListEdgeAt(arg, elem, index))
#endif
#ifdef FAST_API
#define makeEdgeList2(elem1,  elem2) ((EdgeList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
EdgeList _makeEdgeList2(Edge elem1, Edge elem2);
#define makeEdgeList2(elem1,  elem2) (_makeEdgeList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define makeEdgeList3(elem1, elem2,  elem3) ((EdgeList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
EdgeList _makeEdgeList3(Edge elem1, Edge elem2, Edge elem3);
#define makeEdgeList3(elem1, elem2,  elem3) (_makeEdgeList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define makeEdgeList4(elem1, elem2, elem3,  elem4) ((EdgeList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
EdgeList _makeEdgeList4(Edge elem1, Edge elem2, Edge elem3, Edge elem4);
#define makeEdgeList4(elem1, elem2, elem3,  elem4) (_makeEdgeList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define makeEdgeList5(elem1, elem2, elem3, elem4,  elem5) ((EdgeList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
EdgeList _makeEdgeList5(Edge elem1, Edge elem2, Edge elem3, Edge elem4, Edge elem5);
#define makeEdgeList5(elem1, elem2, elem3, elem4,  elem5) (_makeEdgeList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define makeEdgeList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((EdgeList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
EdgeList _makeEdgeList6(Edge elem1, Edge elem2, Edge elem3, Edge elem4, Edge elem5, Edge elem6);
#define makeEdgeList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_makeEdgeList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define getPolygonLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _getPolygonLength(Polygon arg);
#define getPolygonLength(arg) (_getPolygonLength(arg))
#endif
#ifdef FAST_API
#define reversePolygon(arg) ((Polygon) ATreverse((ATermList) (arg)))
#else
Polygon _reversePolygon(Polygon arg);
#define reversePolygon(arg) (_reversePolygon(arg))
#endif
#ifdef FAST_API
#define appendPolygon(arg, elem) ((Polygon) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
Polygon _appendPolygon(Polygon arg, Point elem);
#define appendPolygon(arg, elem) (_appendPolygon(arg, elem))
#endif
#ifdef FAST_API
#define concatPolygon(arg0, arg1) ((Polygon) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
Polygon _concatPolygon(Polygon arg0, Polygon arg1);
#define concatPolygon(arg0, arg1) (_concatPolygon(arg0, arg1))
#endif
#ifdef FAST_API
#define slicePolygon(arg, start, end) ((Polygon) ATgetSlice((ATermList) (arg), (start), (end)))
#else
Polygon _slicePolygon(Polygon arg, int start, int end);
#define slicePolygon(arg, start, end) (_slicePolygon(arg, start, end))
#endif
#ifdef FAST_API
#define getPolygonPointAt(arg, index) ((Point) (ATelementAt((ATermList) arg,index)))
#else
Point _getPolygonPointAt(Polygon arg, int index);
#define getPolygonPointAt(arg, index) (_getPolygonPointAt(arg, index))
#endif
#ifdef FAST_API
#define replacePolygonPointAt(arg, elem, index) ((Polygon) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
Polygon _replacePolygonPointAt(Polygon arg, Point elem, int index);
#define replacePolygonPointAt(arg, elem, index) (_replacePolygonPointAt(arg, elem, index))
#endif
#ifdef FAST_API
#define makePolygon2(elem1,  elem2) ((Polygon) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
Polygon _makePolygon2(Point elem1, Point elem2);
#define makePolygon2(elem1,  elem2) (_makePolygon2(elem1,  elem2))
#endif
#ifdef FAST_API
#define makePolygon3(elem1, elem2,  elem3) ((Polygon) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
Polygon _makePolygon3(Point elem1, Point elem2, Point elem3);
#define makePolygon3(elem1, elem2,  elem3) (_makePolygon3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define makePolygon4(elem1, elem2, elem3,  elem4) ((Polygon) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
Polygon _makePolygon4(Point elem1, Point elem2, Point elem3, Point elem4);
#define makePolygon4(elem1, elem2, elem3,  elem4) (_makePolygon4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define makePolygon5(elem1, elem2, elem3, elem4,  elem5) ((Polygon) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
Polygon _makePolygon5(Point elem1, Point elem2, Point elem3, Point elem4, Point elem5);
#define makePolygon5(elem1, elem2, elem3, elem4,  elem5) (_makePolygon5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define makePolygon6(elem1, elem2, elem3, elem4, elem5,  elem6) ((Polygon) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
Polygon _makePolygon6(Point elem1, Point elem2, Point elem3, Point elem4, Point elem5, Point elem6);
#define makePolygon6(elem1, elem2, elem3, elem4, elem5,  elem6) (_makePolygon6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
Graph makeGraphDefault(NodeList nodes, EdgeList edges, AttributeList attributes);
NodeList makeNodeListEmpty(void);
NodeList makeNodeListSingle(Node head);
NodeList makeNodeListMany(Node head, NodeList tail);
Node makeNodeNode(NodeId id, AttributeList attributes);
Node makeNodeSubgraph(NodeId id, NodeList nodes, EdgeList edges, AttributeList attributes);
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
Attribute makeAttributeTooltip(const char* tooltip);
Attribute makeAttributeLocation(int x, int y);
Attribute makeAttributeShape(Shape shape);
Attribute makeAttributeSize(int width, int height);
Attribute makeAttributeStyle(Style style);
Attribute makeAttributeLevel(const char* level);
Attribute makeAttributeFile(File file);
File makeFileExternal(ATerm file);
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
#ifdef FAST_API
#define isEqualGraph(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualGraph(Graph arg0, Graph arg1);
#define isEqualGraph(arg0, arg1) (_isEqualGraph(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualNodeList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualNodeList(NodeList arg0, NodeList arg1);
#define isEqualNodeList(arg0, arg1) (_isEqualNodeList(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualNode(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualNode(Node arg0, Node arg1);
#define isEqualNode(arg0, arg1) (_isEqualNode(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualNodeId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualNodeId(NodeId arg0, NodeId arg1);
#define isEqualNodeId(arg0, arg1) (_isEqualNodeId(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualAttributeList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualAttributeList(AttributeList arg0, AttributeList arg1);
#define isEqualAttributeList(arg0, arg1) (_isEqualAttributeList(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualAttribute(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualAttribute(Attribute arg0, Attribute arg1);
#define isEqualAttribute(arg0, arg1) (_isEqualAttribute(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualFile(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualFile(File arg0, File arg1);
#define isEqualFile(arg0, arg1) (_isEqualFile(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualColor(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualColor(Color arg0, Color arg1);
#define isEqualColor(arg0, arg1) (_isEqualColor(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualStyle(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualStyle(Style arg0, Style arg1);
#define isEqualStyle(arg0, arg1) (_isEqualStyle(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualShape(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualShape(Shape arg0, Shape arg1);
#define isEqualShape(arg0, arg1) (_isEqualShape(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualDirection(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualDirection(Direction arg0, Direction arg1);
#define isEqualDirection(arg0, arg1) (_isEqualDirection(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualEdgeList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualEdgeList(EdgeList arg0, EdgeList arg1);
#define isEqualEdgeList(arg0, arg1) (_isEqualEdgeList(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualEdge(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualEdge(Edge arg0, Edge arg1);
#define isEqualEdge(arg0, arg1) (_isEqualEdge(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualPolygon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualPolygon(Polygon arg0, Polygon arg1);
#define isEqualPolygon(arg0, arg1) (_isEqualPolygon(arg0, arg1))
#endif
#ifdef FAST_API
#define isEqualPoint(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _isEqualPoint(Point arg0, Point arg1);
#define isEqualPoint(arg0, arg1) (_isEqualPoint(arg0, arg1))
#endif
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
ATbool isValidNode(Node arg);
inline ATbool isNodeNode(Node arg);
inline ATbool isNodeSubgraph(Node arg);
ATbool hasNodeId(Node arg);
ATbool hasNodeAttributes(Node arg);
ATbool hasNodeNodes(Node arg);
ATbool hasNodeEdges(Node arg);
NodeId getNodeId(Node arg);
AttributeList getNodeAttributes(Node arg);
NodeList getNodeNodes(Node arg);
EdgeList getNodeEdges(Node arg);
Node setNodeId(Node arg, NodeId id);
Node setNodeAttributes(Node arg, AttributeList attributes);
Node setNodeNodes(Node arg, NodeList nodes);
Node setNodeEdges(Node arg, EdgeList edges);
ATbool isValidNodeId(NodeId arg);
inline ATbool isNodeIdDefault(NodeId arg);
ATbool hasNodeIdId(NodeId arg);
ATerm getNodeIdId(NodeId arg);
NodeId setNodeIdId(NodeId arg, ATerm id);
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
ATbool isValidAttribute(Attribute arg);
inline ATbool isAttributeBoundingBox(Attribute arg);
inline ATbool isAttributeColor(Attribute arg);
inline ATbool isAttributeCurvePoints(Attribute arg);
inline ATbool isAttributeDirection(Attribute arg);
inline ATbool isAttributeFillColor(Attribute arg);
inline ATbool isAttributeInfo(Attribute arg);
inline ATbool isAttributeLabel(Attribute arg);
inline ATbool isAttributeTooltip(Attribute arg);
inline ATbool isAttributeLocation(Attribute arg);
inline ATbool isAttributeShape(Attribute arg);
inline ATbool isAttributeSize(Attribute arg);
inline ATbool isAttributeStyle(Attribute arg);
inline ATbool isAttributeLevel(Attribute arg);
inline ATbool isAttributeFile(Attribute arg);
ATbool hasAttributeFirst(Attribute arg);
ATbool hasAttributeSecond(Attribute arg);
ATbool hasAttributeColor(Attribute arg);
ATbool hasAttributePoints(Attribute arg);
ATbool hasAttributeDirection(Attribute arg);
ATbool hasAttributeKey(Attribute arg);
ATbool hasAttributeValue(Attribute arg);
ATbool hasAttributeLabel(Attribute arg);
ATbool hasAttributeTooltip(Attribute arg);
ATbool hasAttributeX(Attribute arg);
ATbool hasAttributeY(Attribute arg);
ATbool hasAttributeShape(Attribute arg);
ATbool hasAttributeWidth(Attribute arg);
ATbool hasAttributeHeight(Attribute arg);
ATbool hasAttributeStyle(Attribute arg);
ATbool hasAttributeLevel(Attribute arg);
ATbool hasAttributeFile(Attribute arg);
Point getAttributeFirst(Attribute arg);
Point getAttributeSecond(Attribute arg);
Color getAttributeColor(Attribute arg);
Polygon getAttributePoints(Attribute arg);
Direction getAttributeDirection(Attribute arg);
char* getAttributeKey(Attribute arg);
ATerm getAttributeValue(Attribute arg);
char* getAttributeLabel(Attribute arg);
char* getAttributeTooltip(Attribute arg);
int getAttributeX(Attribute arg);
int getAttributeY(Attribute arg);
Shape getAttributeShape(Attribute arg);
int getAttributeWidth(Attribute arg);
int getAttributeHeight(Attribute arg);
Style getAttributeStyle(Attribute arg);
char* getAttributeLevel(Attribute arg);
File getAttributeFile(Attribute arg);
Attribute setAttributeFirst(Attribute arg, Point first);
Attribute setAttributeSecond(Attribute arg, Point second);
Attribute setAttributeColor(Attribute arg, Color color);
Attribute setAttributePoints(Attribute arg, Polygon points);
Attribute setAttributeDirection(Attribute arg, Direction direction);
Attribute setAttributeKey(Attribute arg, const char* key);
Attribute setAttributeValue(Attribute arg, ATerm value);
Attribute setAttributeLabel(Attribute arg, const char* label);
Attribute setAttributeTooltip(Attribute arg, const char* tooltip);
Attribute setAttributeX(Attribute arg, int x);
Attribute setAttributeY(Attribute arg, int y);
Attribute setAttributeShape(Attribute arg, Shape shape);
Attribute setAttributeWidth(Attribute arg, int width);
Attribute setAttributeHeight(Attribute arg, int height);
Attribute setAttributeStyle(Attribute arg, Style style);
Attribute setAttributeLevel(Attribute arg, const char* level);
Attribute setAttributeFile(Attribute arg, File file);
ATbool isValidFile(File arg);
inline ATbool isFileExternal(File arg);
ATbool hasFileFile(File arg);
ATerm getFileFile(File arg);
File setFileFile(File arg, ATerm file);
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
ATbool isValidStyle(Style arg);
inline ATbool isStyleBold(Style arg);
inline ATbool isStyleDashed(Style arg);
inline ATbool isStyleDotted(Style arg);
inline ATbool isStyleFilled(Style arg);
inline ATbool isStyleInvisible(Style arg);
inline ATbool isStyleSolid(Style arg);
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
ATbool isValidDirection(Direction arg);
inline ATbool isDirectionForward(Direction arg);
inline ATbool isDirectionBack(Direction arg);
inline ATbool isDirectionBoth(Direction arg);
inline ATbool isDirectionNone(Direction arg);
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
ATbool isValidPoint(Point arg);
inline ATbool isPointDefault(Point arg);
ATbool hasPointX(Point arg);
ATbool hasPointY(Point arg);
int getPointX(Point arg);
int getPointY(Point arg);
Point setPointX(Point arg, int x);
Point setPointY(Point arg, int y);
Graph visitGraph(Graph arg, NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList), AttributeList (*acceptAttributes)(AttributeList));
NodeList visitNodeList(NodeList arg, Node (*acceptHead)(Node));
Node visitNode(Node arg, NodeId (*acceptId)(NodeId), AttributeList (*acceptAttributes)(AttributeList), NodeList (*acceptNodes)(NodeList), EdgeList (*acceptEdges)(EdgeList));
NodeId visitNodeId(NodeId arg, ATerm (*acceptId)(ATerm));
AttributeList visitAttributeList(AttributeList arg, Attribute (*acceptHead)(Attribute));
Attribute visitAttribute(Attribute arg, Point (*acceptFirst)(Point), Point (*acceptSecond)(Point), Color (*acceptColor)(Color), Polygon (*acceptPoints)(Polygon), Direction (*acceptDirection)(Direction), char* (*acceptKey)(char*), ATerm (*acceptValue)(ATerm), char* (*acceptLabel)(char*), char* (*acceptTooltip)(char*), int (*acceptX)(int), int (*acceptY)(int), Shape (*acceptShape)(Shape), int (*acceptWidth)(int), int (*acceptHeight)(int), Style (*acceptStyle)(Style), char* (*acceptLevel)(char*), File (*acceptFile)(File));
File visitFile(File arg, ATerm (*acceptFile)(ATerm));
Color visitColor(Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int));
Style visitStyle(Style arg);
Shape visitShape(Shape arg);
Direction visitDirection(Direction arg);
EdgeList visitEdgeList(EdgeList arg, Edge (*acceptHead)(Edge));
Edge visitEdge(Edge arg, NodeId (*acceptFrom)(NodeId), NodeId (*acceptTo)(NodeId), AttributeList (*acceptAttributes)(AttributeList));
Polygon visitPolygon(Polygon arg, Point (*acceptHead)(Point));
Point visitPoint(Point arg, int (*acceptX)(int), int (*acceptY)(int));

#endif /* _GRAPH_H */
