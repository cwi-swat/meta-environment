/* $Id$ */
/*{{{  includes */

#include <MEPT-utils.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "Graph.h"
#include <aterm2.h>

/*}}}  */

/*{{{  globals */

static ATbool characters_on;
static ATbool productions_on;
static ATbool layout_on;
static ATbool literals_on;
static ATbool sharing_on;
static ATermIndexedSet done;

static ATermList parentStack;

static long   unique_key;
static size_t size;

static int nr_of_nodes;

#define MAX_NR_OF_NODES 3000
#define  INITIAL_SIZE 4096
#define  STEP_SIZE    2048
#define XOR(p,q) ((!p && q) || (!q && p))
/*}}}  */

/*{{{  char* escape(const char* str) */

char* escape(const char* str)
{
  int i,j;
  int len = strlen(str);
  char *escaped = (char*) malloc(2 * len * sizeof(char) + 1);

  if (escaped == NULL) {
    ATerror("escape: could not allocate enough memory for escaping:\n%s\n",str);
    return NULL;
  }

  i = 0;
  j = 0;

  for (; i < len; i++, j++) {
    switch(str[i]) {
      case '\n':
	escaped[j++] = '\\';
	escaped[j] = 'n';
	break;
      case '\t':
	escaped[j++] = '\\';
	escaped[j] = 't';
	break;
      case '\r':
	escaped[j++] = '\\';
	escaped[j] = 'r';
	break;
      case '\\':
	escaped[j++] = '\\';
	escaped[j] = '\\';
	break;
      case ' ':
	escaped[j++] = '\\';
	escaped[j] = ' ';
	break;
      default:
	escaped[j] = str[i];
    }
  }

  escaped[j] = '\0';

  return escaped;
}

/*}}}  */

/*{{{  static void pushParent(long id) */

static void pushParent(long id)
{
  ATermInt value = ATmakeInt(id);
  parentStack = ATinsert(parentStack, (ATerm) value);
}

/*}}}  */
/*{{{  static void popParent() */

static void popParent()
{
  parentStack = ATgetNext(parentStack);
  return;
}

/*}}}  */
/*{{{  static long getParent(int distance) */

static long getParent(int distance)
{
  ATerm result = ATelementAt(parentStack, distance);

  if (result != NULL) {
    return ATgetInt((ATermInt) result);
  }
  else {
    return -1;
  }
}

/*}}}  */

/*{{{  static long makeNodeId(PT_Tree tree) */

static long makeNodeId(PT_Tree tree)
{
  long key;

  if (!sharing_on) {
    key = ++unique_key;
  }
  else {
    key = (long) tree;
  }

  return key;
}

/*}}}  */

/*{{{  static Graph printOverFlowNode(Graph graph, int parent, int node) */

static Graph printOverFlowNode(Graph graph, 
                               int parentNr, 
                               int nodeNr)
{
  char str[BUFSIZ];
  Attribute nameAttr;
  AttributeList attrList = makeAttributeListEmpty();
  Node node;
  NodeList nodes;
  Edge edge;
  EdgeList edges;
  Attribute shapeAttr;
  NodeId nodeId;
  NodeId parentId;

  sprintf(str, "N%d", nodeNr); 
  nodeId = makeNodeIdDefault(str);

  sprintf(str, "N%d", parentNr);
  parentId = makeNodeIdDefault(str);
   
  sprintf(str, "Graph contains more than %d nodes!", MAX_NR_OF_NODES);
  nameAttr = makeAttributeLabel(str);
  attrList = makeAttributeListMany(nameAttr, attrList);
  
  shapeAttr = makeAttributeShape(makeShapeEllipse());
  attrList = makeAttributeListMany(shapeAttr, attrList);

  node = makeNodeDefault(nodeId, attrList);

  nodes = getGraphNodes(graph);
  nodes = makeNodeListMany(node, nodes);
  graph = setGraphNodes(graph, nodes);

  if (parentNr != 0) {
    Attribute dir = makeAttributeDirection(makeDirectionNone());
    AttributeList l = makeAttributeListMany(dir, makeAttributeListEmpty()); 
    edge = makeEdgeDefault(parentId, nodeId, l);

    edges = getGraphEdges(graph);
    edges = makeEdgeListMany(edge, edges);
    graph = setGraphEdges(graph, edges);
  }

  return graph;
}

/*}}}  */
/*{{{  static Graph printNode(Graph graph, int parent, int node, char *contents) */

static Graph printNode(const char *name,
                       Graph graph, 
		       Shape shape,
		       Attribute level,
                       int parentNr, 
                       int nodeNr, 
                       char *contents, 
		       char *attr,
                       ATerm posInfo)
{
  char str[BUFSIZ];
  Attribute nameAttr;
  AttributeList attrList = makeAttributeListEmpty();
  Node node;
  NodeList nodes;
  Edge edge;
  EdgeList edges;
  Attribute shapeAttr;
  Attribute messageAttr;
  NodeId nodeId;
  NodeId parentId;

  sprintf(str, "N%d", nodeNr); 
  nodeId = makeNodeIdDefault(str);

  sprintf(str, "N%d", parentNr);
  parentId = makeNodeIdDefault(str);
   
  nameAttr = makeAttributeLabel(contents);
  attrList = makeAttributeListMany(nameAttr, attrList);
  
  shapeAttr = makeAttributeShape(shape);
  attrList = makeAttributeListMany(shapeAttr, attrList);

  if (level != NULL) {
    attrList = makeAttributeListMany(level, attrList);
  }

  if (posInfo) {
    messageAttr = makeAttributeInfo("origin", posInfo);
    attrList = makeAttributeListMany(messageAttr, attrList);
  }
  node = makeNodeDefault(nodeId, attrList);

  nodes = getGraphNodes(graph);
  nodes = makeNodeListMany(node, nodes);
  graph = setGraphNodes(graph, nodes);

  if (parentNr != 0) {
    Attribute dir = makeAttributeDirection(makeDirectionForward());
    AttributeList l = makeAttributeListSingle(dir);
    edge = makeEdgeDefault(parentId, nodeId, l);

    edges = getGraphEdges(graph);
    edges = makeEdgeListMany(edge, edges);
    graph = setGraphEdges(graph, edges);
  }

  return graph;
}

/*}}}  */
/*{{{  static Graph printAmbNode(Graph graph, int parent, int node, char *contents) */

static Graph printAmbNode(Graph graph, int parentNr, int nodeNr, char *contents)
{
  char str[BUFSIZ];
  Attribute nameAttr;
  AttributeList attrList = makeAttributeListEmpty();
  Node node;
  Shape shape;
  NodeList nodes;
  Edge edge;
  EdgeList edges; 
  Style style;
  Attribute styleAttr;
  Color color;
  Attribute colorAttr;
  Attribute shapeAttr;
  NodeId nodeId;
  NodeId parentId;
 
  sprintf(str, "N%d", nodeNr);
  nodeId = makeNodeIdDefault(str);
 
  sprintf(str, "N%d", parentNr);
  parentId = makeNodeIdDefault(str);
 
  nameAttr = makeAttributeLabel(contents);
  attrList = makeAttributeListMany(nameAttr, attrList);
   
  shape = makeShapeDiamond(); 
  shapeAttr = makeAttributeShape(shape);
  attrList = makeAttributeListMany(shapeAttr, attrList);

  color = makeColorRgb(205, 55, 0);
  colorAttr = makeAttributeColor(color);
  attrList = makeAttributeListMany(colorAttr, attrList);

  color = makeColorRgb(255, 165, 0);
  colorAttr = makeAttributeFillColor(color);
  attrList = makeAttributeListMany(colorAttr, attrList);

  style = makeStyleFilled();
  styleAttr = makeAttributeStyle(style);
  attrList = makeAttributeListMany(styleAttr, attrList);
 
  node = makeNodeDefault(nodeId, attrList);

  nodes = getGraphNodes(graph);
  nodes = makeNodeListMany(node, nodes);
  graph = setGraphNodes(graph, nodes);

  if (parentNr != 0) {
    Attribute dir = makeAttributeDirection(makeDirectionForward());
    AttributeList l = makeAttributeListSingle(dir);
    edge = makeEdgeDefault(parentId, nodeId, l);

    edges = getGraphEdges(graph);
    edges = makeEdgeListMany(edge, edges);
    graph = setGraphEdges(graph, edges);
  }

  return graph;
}

/*}}}  */

/*{{{  static Graph addEdge(Graph graph, int from, int to) */

static Graph addEdge(Graph graph, int from, int to)
{
  char str[BUFSIZ];
  Attribute dir = makeAttributeDirection(makeDirectionForward());
  AttributeList l = makeAttributeListSingle(dir);
  NodeId fromId, toId;
  Edge edge;
  EdgeList edges;

  sprintf(str, "N%d", from);
  fromId = makeNodeIdDefault(str);

  sprintf(str, "N%d", to);
  toId = makeNodeIdDefault(str);

  edge = makeEdgeDefault(fromId, toId, l);
  edges = getGraphEdges(graph);
  edges = makeEdgeListMany(edge, edges);
  graph = setGraphEdges(graph, edges);

  return graph;
}

/*}}}  */

/*{{{  static Graph treeToGraph(Graph graph, PT_Tree tree, int parent) */

static Graph treeToGraph(const char *name, Graph graph, PT_Tree tree, int parent, int argnr)
{
  long key = makeNodeId(tree);
  ATerm posInfoArea = (ATerm)PT_getTreeLocation(tree);
  ATbool isNew = ATfalse;

  if (sharing_on) {
    (void) ATindexedSetPut(done, 
			   ATmake("(<int>,<int>,<term>)", argnr, parent,
				  PT_TreeToTerm(tree)), &isNew);
    if (!isNew) {
      return graph;
    }
  }
  
  nr_of_nodes++;
  if (nr_of_nodes == MAX_NR_OF_NODES) {
    return printOverFlowNode(graph, parent, key);
  }
  if (nr_of_nodes > MAX_NR_OF_NODES) {
    return graph;
  }

  if (PT_isTreeChar(tree)) {
    /*{{{  handle characters */

    if (characters_on) {
      char ch[2] = { '\0', '\0'};
      ch[0] = PT_getTreeCharacter(tree);

      graph = printNode(name, graph, makeShapeEllipse(),
			makeAttributeLevel("characters"), parent,key,
			escape(ch),"character", posInfoArea);
    }

    /*}}}  */
  }
  else if (PT_isTreeCycle(tree)) {
    int length  = PT_getTreeCycleLength(tree);
    long pointer = getParent(length - 1);
    graph = addEdge(graph, parent, pointer);
  }
  else if (PT_isTreeAppl(tree)) {
    /*{{{  handle appl */
    PT_Args args = PT_getTreeArgs(tree);
    PT_Production prod = PT_getTreeProd(tree);
    PT_Symbol rhs = PT_getProductionRhs(prod);
    ATbool layout = PT_isTreeLayout(tree);
    ATbool literal = PT_isSymbolLit(rhs); /* for asfix2 compliance */
    Shape shape = XOR(PT_isProductionList(prod),productions_on) ? 
                                              makeShapeBox() : 
                                              makeShapeEllipse();

    if (!layout && (literals_on || !literal)) {
      graph = printNode(name, graph, shape, NULL, parent,key,productions_on ?
				PT_yieldProduction(PT_getTreeProd(tree)) :
				PT_yieldSymbol(rhs),
				productions_on ? "" :
				PT_yieldProduction(PT_getTreeProd(tree)), 
				posInfoArea);
    }
    else if (layout && layout_on) {
      graph = printNode(name, graph,shape,NULL, parent,key, "LAYOUT?","layout", 
			posInfoArea); 
    }

    if (!characters_on && PT_isLexicalInjectionProd(prod)) {
      return graph;
    }

    if ((layout_on || !layout) && (literals_on || !literal)) {
      int argnr;

      pushParent(key);
      for(argnr = 0;PT_hasArgsHead(args); 
	  args = PT_getArgsTail(args), argnr++) {
	  PT_Tree arg = PT_getArgsHead(args);
	  graph = treeToGraph(name, graph,arg,key,argnr);
      }
      popParent(key);
    }

    /*}}}  */
  }
  else if (PT_isTreeAmb(tree)) {
    /*{{{  handle amb cluster */

    PT_Args args = PT_getTreeArgs(tree);
    PT_Tree first = PT_getArgsHead(args);
    PT_Production prod = PT_getTreeProd(first);
    PT_Symbol symbol = PT_getProductionRhs(prod);
      
    graph = printAmbNode(graph,parent,key,PT_yieldSymbol(symbol));


    pushParent(key);
    for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      graph = treeToGraph(name, graph,arg,key,0);
    }
    popParent();

    /*}}}  */
  }
  else {
    ATerror("treeToGraph: unhandled tree: %t\n", tree);
    return NULL;
  }

  return graph;
}

/*}}}  */

/*{{{  Graph PT_printTreeToGraph(PT_Tree tree, ATbool characters,  */

Graph PT_printTreeToGraph(const char *name, PT_Tree tree, ATbool characters, 
			  ATbool productions, 
			  ATbool layout, ATbool literals, ATbool sharing)
{
  NodeList nodes;
  Graph graph = makeGraphDefault(makeNodeListEmpty(), makeEdgeListEmpty(),
				 makeAttributeListEmpty());

  characters_on = characters;
  productions_on = productions;
  layout_on = layout;
  literals_on = literals;
  sharing_on = sharing;

  if (sharing_on) {
    done = ATindexedSetCreate(1024, 80);
  }

  parentStack = ATempty;
  ATprotectList(&parentStack);

  unique_key = 0;
  size = INITIAL_SIZE;
  
  nr_of_nodes = 0;

  graph = treeToGraph(name, graph, tree, 0, 0);

  /* Reverse edgelist to keep the original order */
  nodes = getGraphNodes(graph);
  nodes = NodeListFromTerm((ATerm)ATreverse((ATermList)NodeListToTerm(nodes)));
  graph = setGraphNodes(graph, nodes);

  return graph;
}

/*}}}  */
/*{{{  Graph PT_printParseTreeToGraph(PT_ParseTree parsetree,  */

Graph PT_printParseTreeToGraph(const char *name, PT_ParseTree parsetree, 
			      ATbool characters, 
			      ATbool productions, ATbool layout, 
			      ATbool literals, ATbool sharing)
{
  return PT_printTreeToGraph(name, PT_getParseTreeTop(parsetree),characters,
			     productions, layout, literals, sharing);
}

/*}}}  */

/*{{{  Graph PT_printAnyToGraph(char *name, ATerm term, ATbool characters,  */

Graph PT_printAnyToGraph(const char *name, ATerm term, ATbool characters, 
  		         ATbool productions, 
		         ATbool layout, ATbool literals, ATbool sharing)
{
  if (ATmatchTerm(term, PT_patternParseTreeTop, NULL, NULL)){
    return PT_printParseTreeToGraph(name, (PT_ParseTree) term, characters, 
				    productions, layout,
				    literals, sharing);
  }
  else if (ATgetType(term) == AT_LIST) {
    PT_Production prod = PT_makeProductionList(PT_makeSymbolLit("*dummy*"));
    PT_Tree dummy = PT_makeTreeAppl(prod, (PT_Args) term);

    return PT_printTreeToGraph(name, dummy, characters, 
			       productions, layout, literals, sharing);
  }

  return PT_printTreeToGraph(name, (PT_Tree) term, characters, 
			     productions, layout, literals, sharing);
}

/*}}}  */

