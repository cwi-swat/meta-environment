
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
static ATermList nodeList = NULL;
static AttributeList graphAttributeList = NULL;
static ATermTable nodeTable = NULL;
static EdgeList edgeList = NULL;


/*{{{  static void initTermStore() */

static void initTermStore()
{
  termStore = ATempty;
  ATprotect((ATerm*)((void*)&termStore));

  nodeList = ATempty;
  ATprotect((ATerm*)((void*)&nodeList));

  edgeList = makeEdgeListEmpty();
  ATprotect((ATerm*) ((void*)&edgeList));
  
  graphAttributeList = makeAttributeListEmpty();
  ATprotect((ATerm*) ((void*)&graphAttributeList));
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
      return makeAttributeListMulti(head, result);
    }
  }

}

/*}}}  */
/*{{{  static AttributeList mergeAttribute(AttributeList attrs, Attribute attr) */

static AttributeList mergeAttribute(AttributeList attrs, Attribute attr)
{
  attrs = deleteAttribute(attrs, attr);
  attrs = makeAttributeListMulti(attr, attrs);

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

/*{{{  static Graph buildGraph() */

static Graph buildGraph()
{
  /* We want to make sure the list of outgoing nodes is in the same
   * order as the list of incoming nodes */
  ATermList list, nodes = ATempty;
  EdgeList edges;
 
  for (list=(ATermList)nodeList; !ATisEmpty(list); list=ATgetNext(list)) {
    Node node = NodeFromTerm(ATgetFirst(list));
    NodeId id = getNodeId(node);
    ATerm newNode = ATtableGet(nodeTable, NodeIdToTerm(id));
    nodes = ATinsert(nodes, newNode);
  }
  nodes = ATreverse(nodes);

  edges = edgeList;

  return makeGraphDefault(NodeListFromTerm((ATerm)nodes), edges, 
			  graphAttributeList);
}

/*}}}  */

/*{{{  void protectTerm(ATerm term) */

void protectTerm(ATerm term)
{
  termStore = ATinsert((ATermList)termStore, term);
}

/*}}}  */
/*{{{  void storeNodes(NodeList nodes) */

void storeNodes(NodeList nodes)
{
  nodeList = (ATermList)NodeListToTerm(nodes);
  nodeTable = ATtableCreate(1024, 75);
  while (!isNodeListEmpty(nodes)) {
    Node node = getNodeListHead(nodes);
    ATtablePut(nodeTable, NodeIdToTerm(getNodeId(node)), NodeToTerm(node));
    nodes = getNodeListTail(nodes);
  }
}

/*}}}  */
/*{{{  void mergeNodeAttributes(NodeId nodeId, AttributeList attrs) */

void mergeNodeAttributes(NodeId nodeId, AttributeList attrs)
{
  ATerm key = NodeIdToTerm(nodeId);
  Node node = NodeFromTerm(ATtableGet(nodeTable, key));

  assert(node);
  node = setNodeAttributes(node, mergeAttributes(getNodeAttributes(node), attrs));
  ATtablePut(nodeTable, key, NodeToTerm(node));
}

/*}}}  */
/*{{{  void mergeEdgeAttributes(NodeId from, NodeId to, AttributeList attrs) */

void addEdge(NodeId from, NodeId to, AttributeList attrs)
{
  edgeList = makeEdgeListMulti(makeEdgeDefault(from, to, attrs), edgeList);
}

/*}}}  */
/*{{{  void mergeGraphAttributes(AttributeList attrs) */

void mergeGraphAttributes(AttributeList attrs)
{
  graphAttributeList = AttributeListFromTerm((ATerm) ATconcat(
                       (ATermList) AttributeListToTerm(attrs),
		       (ATermList) AttributeListToTerm(graphAttributeList)));
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
  storeNodes(getGraphNodes(graph));
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

  sprintf(invoke_dot, "%s -o %s %s", DOT_COMMAND, dot_output, dot_input);
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

  return buildGraph();
}

/*}}}  */
