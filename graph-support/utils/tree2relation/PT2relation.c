/* $Id: PT2graph.c 21752 2007-03-08 18:06:45Z jurgenv $ */


#include <MEPT-utils.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "RStore.h"
#include <aterm2.h>



typedef struct __Graph {
  RS_RElemElements nodes;
  RS_RElemElements edges;
} _Graph;
typedef _Graph *Graph;




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


RS_RElem makeAttr(char* key, char* value)
{
  return RS_makeRElemTuple(RS_makeRElemElements2(RS_makeRElemStr(key), RS_makeRElemStr(value)));
}


static void pushParent(long id)
{
  ATermInt value = ATmakeInt(id);
  parentStack = ATinsert(parentStack, (ATerm) value);
}




static void popParent()
{
  parentStack = ATgetNext(parentStack);
  return;
}



static int getParent(int distance)
{
  ATerm result = ATelementAt(parentStack, distance);

  if (result != NULL) {
    return ATgetInt((ATermInt) result);
  }
  else {
    return -1;
  }
}


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



static Graph printOverFlowNode(Graph graph, 
                               int parentNr, 
                               int nodeNr)
{
  char str[BUFSIZ];
  RS_RElemElements attrs = RS_makeRElemElementsEmpty();
  RS_RElem node;
  RS_RElem attrSet;
  RS_RElem edge;
  RS_RElem nodeId;
  RS_RElem parentId;

  sprintf(str, "N%d", nodeNr); 
  nodeId = RS_makeRElemStr(str);

  sprintf(str, "N%d", parentNr);
  parentId = RS_makeRElemStr(str);

  sprintf(str, "Graph contains more than %d nodes!", MAX_NR_OF_NODES);
  attrs = RS_makeRElemElementsMany(makeAttr("label", str), attrs);
  attrs = RS_makeRElemElementsMany(makeAttr("shape", "ellipse"), attrs);

  attrSet = RS_makeRElemSet(attrs);
  node = RS_makeRElemTuple(RS_makeRElemElements2(nodeId, attrSet));
  graph->nodes = RS_makeRElemElementsMany(node, graph->nodes);

  if (parentNr != 0) {
    edge = RS_makeRElemTuple(RS_makeRElemElements2(parentId, nodeId));
    graph->edges = RS_makeRElemElementsMany(edge, graph->edges);
  }

  return graph;
}




static Graph printNode(Graph graph, 
		       char* shape,
		       char* level,
                       int parentNr, 
                       int nodeNr, 
                       char *contents, 
		       char *attr,
                       ATerm posInfo)
{
  char str[BUFSIZ];
  RS_RElem posAttr;
  RS_RElemElements attrs = RS_makeRElemElementsEmpty();
  RS_RElem node;
  RS_RElem attrSet;
  RS_RElem edge;
  RS_RElem nodeId;
  RS_RElem parentId;

  sprintf(str, "N%d", nodeNr); 
  nodeId = RS_makeRElemStr(str);

  sprintf(str, "N%d", parentNr);
  parentId = RS_makeRElemStr(str);

  attrs = RS_makeRElemElementsMany(makeAttr("label", contents), attrs);
  attrs = RS_makeRElemElementsMany(makeAttr("shape", shape), attrs);
  if (level != NULL) {
    attrs = RS_makeRElemElementsMany(makeAttr("level", level), attrs);
  }
  if (posInfo) {
    posAttr = makeAttr("origin", ATwriteToString(posInfo));
    attrs = RS_makeRElemElementsMany(posAttr, attrs);
  }

  attrSet = RS_makeRElemSet(attrs);
  node = RS_makeRElemTuple(RS_makeRElemElements2(nodeId, attrSet));
  graph->nodes = RS_makeRElemElementsMany(node, graph->nodes);

  if (parentNr != 0) {
    edge = RS_makeRElemTuple(RS_makeRElemElements2(parentId, nodeId));
    graph->edges = RS_makeRElemElementsMany(edge, graph->edges);
  }

  return graph;
}



static Graph printAmbNode(Graph graph, int parentNr, int nodeNr, char *contents)
{
  char str[BUFSIZ];
  RS_RElemElements attrs = RS_makeRElemElementsEmpty();
  RS_RElem node;
  RS_RElem attrSet;
  RS_RElem edge;
  RS_RElem nodeId;
  RS_RElem parentId;

  sprintf(str, "N%d", nodeNr); 
  nodeId = RS_makeRElemStr(str);

  sprintf(str, "N%d", parentNr);
  parentId = RS_makeRElemStr(str);

  attrs = RS_makeRElemElementsMany(makeAttr("label", contents), attrs);
  attrs = RS_makeRElemElementsMany(makeAttr("shape", "diamond"), attrs);
  attrs = RS_makeRElemElementsMany(makeAttr("color", "rgb(205,55,0)"), attrs);
  attrs = RS_makeRElemElementsMany(makeAttr("fillcolor", "rgb(255,165,0)"), attrs);
  attrs = RS_makeRElemElementsMany(makeAttr("style", "filled"), attrs);

  attrSet = RS_makeRElemSet(attrs);
  node = RS_makeRElemTuple(RS_makeRElemElements2(nodeId, attrSet));
  graph->nodes = RS_makeRElemElementsMany(node, graph->nodes);

  if (parentNr != 0) {
    edge = RS_makeRElemTuple(RS_makeRElemElements2(parentId, nodeId));
    graph->edges = RS_makeRElemElementsMany(edge, graph->edges);
  }

  return graph;
}



static Graph addEdge(Graph graph, int from, int to)
{
  char str[BUFSIZ];
  RS_RElem fromId, toId;
  RS_RElem edge;

  sprintf(str, "N%d", from); 
  fromId = RS_makeRElemStr(str);

  sprintf(str, "N%d", to);
  toId = RS_makeRElemStr(str);

  edge = RS_makeRElemTuple(RS_makeRElemElements2(fromId, toId));
  graph->edges = RS_makeRElemElementsMany(edge, graph->edges);

  return graph;
}



static Graph treeToRelation(Graph graph, PT_Tree tree, int parent, int argnr)
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
    

    if (characters_on) {
      char ch[2] = { '\0', '\0'};
      ch[0] = PT_getTreeCharacter(tree);

      graph = printNode(graph, "ellipse",
			"characters", parent,key,
			escape(ch),"character", posInfoArea);
    }
  }
  else if (PT_isTreeCycle(tree)) {
    int length  = PT_getTreeCycleLength(tree);
    int pointer = getParent(length - 1);
    if (pointer != -1) {
      graph = addEdge(graph, parent, pointer);
    }
    else {
      static char label[] = "Unreachable node on cyclic path";
      graph = printNode(graph, "ellipse", NULL, parent, key,
			label, "cycle", posInfoArea);
    }
  }
  else if (PT_isTreeAppl(tree)) {
    
    PT_Args args = PT_getTreeArgs(tree);
    PT_Production prod = PT_getTreeProd(tree);
    PT_Symbol rhs = PT_getProductionRhs(prod);
    ATbool layout = PT_isTreeLayout(tree);
    ATbool literal = PT_isSymbolLit(rhs); 
    char* shape = XOR(PT_isProductionList(prod),productions_on) ? 
      "box" : "ellipse";

    if (!layout && (literals_on || !literal)) {
      graph = printNode(graph, shape, NULL, parent,key,productions_on ?
				PT_yieldProduction(PT_getTreeProd(tree)) :
				PT_yieldSymbol(rhs),
				productions_on ? "" :
				PT_yieldProduction(PT_getTreeProd(tree)), 
				posInfoArea);
    }
    else if (layout && layout_on) {
      graph = printNode(graph,shape,NULL, parent,key, "LAYOUT?","layout", 
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
	  graph = treeToRelation(graph, arg, key, argnr);
      }
      popParent(key);
    }
  }
  else if (PT_isTreeAmb(tree)) {

    PT_Args args = PT_getTreeArgs(tree);
    PT_Tree first = PT_getArgsHead(args);
    PT_Production prod = PT_getTreeProd(first);
    PT_Symbol symbol = PT_getProductionRhs(prod);
      
    graph = printAmbNode(graph, parent, key, PT_yieldSymbol(symbol));

    pushParent(key);
    for(; PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      graph = treeToRelation(graph, arg, key, 0);
    }
    popParent();
  }
  else {
    ATerror("treeToRelation: unhandled tree: %t\n", tree);
    return NULL;
  }

  return graph;
}





RS_RStore PT_printTreeToRelation(PT_Tree tree, ATbool characters, 
			  ATbool productions, 
			  ATbool layout, ATbool literals, ATbool sharing)
{
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

  _Graph initGraph;
  initGraph.nodes = RS_makeRElemElementsEmpty();
  initGraph.edges = RS_makeRElemElementsEmpty();
  Graph graph = treeToRelation(&initGraph, tree, 0, 0);
  graph->edges = RS_reverseRElemElements(graph->edges);

  RS_IdCon name = RS_makeIdConIdCon("graph");
  RS_RType type = RS_RTypeFromTerm(ATreadFromString("tuple([relation([str, relation([str, str])]), relation([str, str])])"));
  RS_RElem elem = RS_makeRElemTuple(RS_makeRElemElements2(RS_makeRElemSet(graph->nodes), RS_makeRElemSet(graph->edges)));
  RS_RTuple tuple = RS_makeRTupleRtuple(name, type, elem);
  RS_RTupleRtuples tuples = RS_makeRTupleRtuplesSingle(tuple);
  RS_RStore rstore = RS_makeRStoreRstore(tuples);

  return rstore;
}




RS_RStore PT_printParseTreeToRelation(PT_ParseTree parsetree, 
			      ATbool characters, 
			      ATbool productions, ATbool layout, 
			      ATbool literals, ATbool sharing)
{
  return PT_printTreeToRelation(PT_getParseTreeTop(parsetree),characters,
			     productions, layout, literals, sharing);
}





RS_RStore PT_printAnyToRelation(ATerm term, ATbool characters, 
  		         ATbool productions, 
		         ATbool layout, ATbool literals, ATbool sharing)
{
  if (PT_isParseTreeTop((PT_ParseTree) term)) {
    return PT_printParseTreeToRelation((PT_ParseTree) term, characters, 
				    productions, layout,
				    literals, sharing);
  }
  else if (ATgetType(term) == AT_LIST) {
    PT_Production prod = PT_makeProductionList(PT_makeSymbolLit("*dummy*"));
    PT_Tree dummy = PT_makeTreeAppl(prod, (PT_Args) term);

    return PT_printTreeToRelation(dummy, characters, 
			       productions, layout, literals, sharing);
  }

  return PT_printTreeToRelation((PT_Tree) term, characters, 
			     productions, layout, literals, sharing);
}



