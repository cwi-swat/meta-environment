
/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include "dot.h"
#include "Graph.h"
#include "graph2dot.h"
#include "layoutgraph.h"

/*}}}  */

static ATermList termStore = NULL;
static ATermTable nodeTable = NULL;
static ATermTable edgeTable = NULL;
static ATermList subgraphStack = NULL;

/*{{{  static void initTermStore() */

static void initTermStore()
{
  termStore = ATempty;
  ATprotect((ATerm*)((void*)&termStore));

  edgeTable = ATtableCreate(1024, 75);
  nodeTable = ATtableCreate(1024, 75);

  subgraphStack = ATempty;
  ATprotectList(&subgraphStack);
}

/*}}}  */

/*{{{  AFun getAttributeType(Attribute attr) */

AFun getAttributeType(Attribute attr)
{
  return ATgetAFun((ATermAppl)AttributeToTerm(attr));
}

/*}}}  */

/*{{{  static AttributeList deleteAttribute(AttributeList attrs, Attribute attr) */

static AttributeList deleteAttribute(AttributeList attrs, Attribute attr)
{
  Attribute head;
  AttributeList tail;

  if (isAttributeListEmpty(attrs)) {
    return attrs;
  }

  head = getAttributeListHead(attrs);
  tail = getAttributeListTail(attrs);
  if (getAttributeType(head) == getAttributeType(attr)) {
    return tail;
  } else {
    AttributeList result = deleteAttribute(tail, attr);
    if (isEqualAttributeList(result, tail)) {
      return attrs;
    } else {
      return makeAttributeListMany(head, result);
    }
  }

}

/*}}}  */
/*{{{  static AttributeList mergeAttribute(AttributeList attrs, Attribute attr) */

static AttributeList mergeAttribute(AttributeList attrs, Attribute attr)
{
  attrs = deleteAttribute(attrs, attr);
  attrs = makeAttributeListMany(attr, attrs);

  return attrs;
}

/*}}}  */
/*{{{  static AttributeList mergeAttributes(AttributeList orig, AttributeList attrs) */

static AttributeList mergeAttributes(AttributeList orig, AttributeList attrs)
{
  while (!isAttributeListEmpty(attrs)) {
    Attribute attr = getAttributeListHead(attrs);
    orig = mergeAttribute(orig, attr);
    attrs = getAttributeListTail(attrs);
  }

  return orig;
}

/*}}}  */


static Node buildSubgraph(Node graph);
/*{{{  static NodeList buildNodeList(NodeList list) */

static NodeList buildNodeList(NodeList list)
{
  NodeList nodes = makeNodeListEmpty();

  for ( ; !isNodeListEmpty(list); list=getNodeListTail(list)) {
    Node node = getNodeListHead(list);
    NodeId id = getNodeId(node);
    Node newNode = NULL;

    if (isNodeNode(node)) {
      newNode = (Node) ATtableGet(nodeTable, NodeIdToTerm(id));
    }
    else if (isNodeSubgraph(node)) {
      newNode = buildSubgraph(node);
    }

    if (newNode != NULL) {
      nodes = makeNodeListMany(newNode, nodes);
    }
    else {
      ATwarning("no stored node for %t (%t)\n", node, id);
    }
  }

  return nodes;
}

/*}}}  */
/*{{{  static EdgeList buildEdgeList(EdgeList elist) */

static EdgeList buildEdgeList(EdgeList elist)
{
  EdgeList edges = makeEdgeListEmpty();

  for ( ; !isEdgeListEmpty(elist); elist=getEdgeListTail(elist)) {
    Edge edge = getEdgeListHead(elist);
    Edge newEdge = NULL;
    Edge key = setEdgeAttributes(edge, makeAttributeListEmpty());

    newEdge = (Edge) ATtableGet(edgeTable, EdgeToTerm(key));

    if (newEdge != NULL) {
      edges = makeEdgeListMany(newEdge, edges);
    }
  }
  edges = reverseEdgeList(edges);

  return edges;
}

/*}}}  */
/*{{{  static Node buildSubGraph(Node graph) */

static Node buildSubgraph(Node graph)
{
  NodeList nodes = buildNodeList(getNodeNodes(graph));
  EdgeList edges = buildEdgeList(getNodeEdges(graph));
  NodeId id = getNodeId(graph);
  Node storedNode = (Node) ATtableGet(nodeTable, NodeIdToTerm(id));
  AttributeList attrs = getNodeAttributes(storedNode);

  return makeNodeSubgraph(id, nodes, edges, attrs);
}

/*}}}  */
/*{{{  static Graph buildGraph() */

static Graph buildGraph(Graph graph)
{
  NodeId id = makeNodeIdDefault(ATparse("graph"));
  Node subgraph = makeNodeSubgraph(id,
				   getGraphNodes(graph),
				   getGraphEdges(graph),
				   getGraphAttributes(graph));

  subgraph = buildSubgraph(subgraph);

  return makeGraphDefault(getNodeNodes(subgraph), 
			  getNodeEdges(subgraph), 
			  getNodeAttributes(subgraph));
}

/*}}}  */

/*{{{  void protectTerm(ATerm term) */

void protectTerm(ATerm term)
{
  termStore = ATinsert((ATermList)termStore, term);
}

/*}}}  */
/*{{{  void storeEdges(EdgeList edges) */

void storeEdges(EdgeList edges)
{
  while (!isEdgeListEmpty(edges)) {
    Edge edge = getEdgeListHead(edges);
    Edge edgeNoAttrs = setEdgeAttributes(edge, makeAttributeListEmpty());
    ATtablePut(edgeTable, EdgeToTerm(edgeNoAttrs), EdgeToTerm(edge));

    edges = getEdgeListTail(edges);
  }
}

/*}}}  */
/*{{{  void storeNodes(NodeList nodes) */

void storeNodes(NodeList nodes)
{
  while (!isNodeListEmpty(nodes)) {
    Node node = getNodeListHead(nodes);
    ATtablePut(nodeTable, NodeIdToTerm(getNodeId(node)), NodeToTerm(node));

    if (isNodeSubgraph(node)) {
      storeNodes(getNodeNodes(node));
      storeEdges(getNodeEdges(node));
    }

    nodes = getNodeListTail(nodes);
  }
}

/*}}}  */
/*{{{  void storeGraph(Graph graph) */

void storeGraph(Graph graph)
{
  Node subgraph = makeNodeSubgraph(makeNodeIdDefault(ATparse("graph")),
				   getGraphNodes(graph),
				   getGraphEdges(graph),
				   getGraphAttributes(graph));

  ATtablePut(nodeTable, 
	     NodeIdToTerm(getNodeId(subgraph)), 
	     NodeToTerm(subgraph));

  storeNodes(getGraphNodes(graph));
  storeEdges(getGraphEdges(graph));
}

/*}}}  */
/*{{{  void mergeNodeAttributes(NodeId nodeId, AttributeList attrs) */

void mergeNodeAttributes(NodeId nodeId, AttributeList attrs)
{
  ATerm key = NodeIdToTerm(nodeId);
  Node node = NodeFromTerm(ATtableGet(nodeTable, key));

  if (node) {
    node = setNodeAttributes(node, mergeAttributes(getNodeAttributes(node), attrs));
    ATtablePut(nodeTable, key, NodeToTerm(node));
  }
}

/*}}}  */
/*{{{  void mergeEdgeAttributes(NodeId from, NodeId to, AttributeList attrs) */

void mergeEdgeAttributes(NodeId from, NodeId to, AttributeList attrs)
{
  Edge key = makeEdgeDefault(from, to, makeAttributeListEmpty());
  Edge edge = (Edge) ATtableGet(edgeTable, EdgeToTerm(key));

  if (edge) {
    AttributeList eattrs = getEdgeAttributes(edge);
    edge = setEdgeAttributes(edge, mergeAttributes(eattrs, attrs));
    ATtablePut(edgeTable, EdgeToTerm(key), EdgeToTerm(edge));
  }
}

/*}}}  */

/*{{{  Graph layoutGraph(Graph graph) */

Graph layoutGraph(Graph graph)
{
  char dot_input[] = "/tmp/dotto-XXXXXX";
  char dot_output[] = "/tmp/dotfrom-XXXXXX";
  int fd;
  FILE *f;
  char invoke_dot[BUFSIZ];
  extern FILE *yyin;

  fd = mkstemp(dot_input);
  if (fd < 0) {
    perror("mkstemp:dot_input");
    exit(errno);
  }

  f = fdopen(fd, "w");
  if (f == NULL) {
    perror("fdopen:dot_input");
    exit(errno);
  }

  initTermStore();

  storeGraph(graph);
  
  graph2dot(graph, f);

  if (fclose(f) == -1) {
    perror("fclose:dot_input");
    exit(errno);
  }

  fd = mkstemp(dot_output);
  if (fd < 0) {
    perror("mkstemp:dot_output");
    exit(errno);
  }

  yyin = fdopen(fd, "r");
  if (yyin == NULL) {
    perror("fdopen:dot_output");
    exit(errno);
  }

  sprintf(invoke_dot, "%s -y -o %s %s", DOT_COMMAND, dot_output, dot_input);
  if (system(invoke_dot) == -1) {
    perror(invoke_dot);
    exit(errno);
  }

  if (fseek(yyin, 0, SEEK_SET) == -1) {
    perror("fseek");
    exit(errno);
  }

  yyparse();
  if (fclose(yyin) == -1) {
    perror("fclose:dot_output");
    exit(errno);
  }

  if (unlink(dot_input) == -1) {
    perror("unlink:dot_input");
    exit(errno);
  }

  if (unlink(dot_output) == -1) {
    perror("unlink:dot_output");
    exit(errno);
  }

  return buildGraph(graph);
}

/*}}}  */
