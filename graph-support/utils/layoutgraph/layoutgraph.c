
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
  ATprotect((ATerm *)&termStore);

  nodeList = ATempty;
  ATprotect((ATerm*) &nodeList);

  edgeList = makeEdgeListEmpty();
  ATprotect((ATerm*) &edgeList);
  
  graphAttributeList = makeAttributeListEmpty();
  ATprotect((ATerm*) &graphAttributeList);
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
 
  for (list=nodeList; !ATisEmpty(list); list=ATgetNext(list)) {
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
  termStore = ATinsert(termStore, term);
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
  int old_stdin, old_stdout, fd_to_dot, fd_from_dot, pid;
  char to_template[] = "/tmp/dotto-XXXXXX";
  char from_template[] = "/tmp/dotfrom-XXXXXX";
  FILE *f_to_dot;

  initTermStore();

  storeNodes(getGraphNodes(graph));

  old_stdin = dup(0);

  if ((fd_to_dot = mkstemp(to_template)) < 0) {
    fprintf(stderr, "Can't create to dot file");
    exit(1);
  }
  f_to_dot = fdopen(fd_to_dot, "w");
  graph2dot(graph, f_to_dot);
  fflush(f_to_dot);

  old_stdout = dup(1);
  if ((fd_from_dot = mkstemp(from_template)) < 0) {
    fprintf(stderr, "Can't create 'from dot' file");
    exit(1);
  }

  if ((pid = fork())) {
    /* Parent */
    if (pid < 0) {
      fprintf(stderr, "Can't fork");
      exit(1);
    }
    do {
      int status;
      if (waitpid(pid, &status, 0) == -1) {
	if (errno != EINTR) {
	  fprintf(stderr, "child killed\n");
	  exit(1);
	}
      } else {
	if (status != 0) {
	  fprintf(stderr, "child exited with error code %d\n", status);
	  exit(1);
	} else {
	  break;
	}
      }
    } while (1);

    lseek(fd_from_dot, 0, SEEK_SET);

    {
    extern FILE *yyin;
    yyin = fdopen(fd_from_dot, "r");
    }

    yyparse();

    close(fd_from_dot);
    close(fd_to_dot);
    unlink(to_template);
    unlink(from_template);
  } else {
    /* Child */
    close(fileno(stdin));
    if (dup2(fd_to_dot, fileno(stdin)) < 0) {
      perror("dup2 to_dot");
    }
    if (lseek(fileno(stdin), 0, SEEK_SET) < 0) {
      perror("lseek");
    }

    close(1);
    if (dup2(fd_from_dot, 1) < 0) {
      perror("dup2 from_dot");
    }

    if (execl(DOT_COMMAND, NULL) < 0) {
      perror("exec");
    }
  }

  graph = buildGraph();

  initTermStore();
  ATtableReset(nodeTable);
  /*ATtableReset(edgeTable);*/
  edgeList = makeEdgeListEmpty();

  return graph;
}

/*}}}  */
