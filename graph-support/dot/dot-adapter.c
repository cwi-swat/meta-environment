
/*{{{  includes */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "dot.h"
#include "Graph.h"

#include "dot-adapter.tif.h"


/*}}}  */

static ATermList termStore = NULL;
static ATermList nodeList;
static ATermTable nodeTable;
static ATermTable edgeTable;

static char myversion[] = "1.0";

/*{{{  static void initTermStore() */

static void initTermStore()
{
  termStore = ATempty;
  nodeList = ATempty;
}

/*}}}  */
/*{{{  void protectTerm(ATerm term) */

void protectTerm(ATerm term)
{
  termStore = ATinsert(termStore, term);
}

/*}}}  */

/*{{{  static float pixelToInch(int pixel) */

static float pixelToInch(int pixel)
{
  return ((float)pixel)/72.0;
}

/*}}}  */

/*{{{  static void printPoint(Point point, FILE *file) */

static void printPoint(Point point, FILE *file)
{
  fprintf(file, "%d,%d", getPointX(point), getPointY(point));
}

/*}}}  */
/*{{{  static void printPolygon(Polygon poly, FILE *file) */

static void printPolygon(Polygon poly, FILE *file)
{
  ATfprintf(file, "pos=\"");
  while (!isPolygonEmpty(poly)) {
    printPoint(getPolygonHead(poly), file);
    poly = getPolygonTail(poly);
    if (!isPolygonEmpty(poly)) {
      fputc(' ', file);
    }
  }
  ATfprintf(file, "\"");
}

/*}}}  */
/*{{{  static void printAttribute(Attribute attr, FILE *file) */

static void printAttribute(Attribute attr, FILE *file)
{
  if (isAttributeLabel(attr)) {
    ATfprintf(file, "name=%y", ATmakeAFun(getAttributeLabel(attr), 0, ATtrue));
  } else if (isAttributeShape(attr)) {
    ATfprintf(file, "shape=%t", ShapeToTerm(getAttributeShape(attr)));
  } else if (isAttributeLocation(attr)) {
    ATfprintf(file, "pos=\"%f,%f\"", pixelToInch(getAttributeX(attr)),
	      pixelToInch(getAttributeY(attr)));
  } else if (isAttributeSize(attr)) {
    ATfprintf(file, "width=\"%f\" ", pixelToInch(getAttributeWidth(attr)));
    ATfprintf(file, "height=\"%f\"", pixelToInch(getAttributeHeight(attr)));
  } else if (isAttributeCurvePoints(attr)) {
    printPolygon(getAttributePoints(attr), file);
  } else {
    ATabort("unknown attribute type: %t\n", attr);
  }
}

/*}}}  */
/*{{{  static void printAttributes(AttributeList attrs, FILE *file) */

static void printAttributes(AttributeList attrs, FILE *file)
{
  while (!isAttributeListEmpty(attrs)) {
    printAttribute(getAttributeListHead(attrs), file);
    attrs = getAttributeListTail(attrs);
    fprintf(file, " ");
  }
}

/*}}}  */
/*{{{  static void printNode(Node node, FILE *file) */

static void printNode(Node node, FILE *file)
{
  ATfprintf(file, "%t [", NodeIdToTerm(getNodeId(node)));
  printAttributes(getNodeAttributes(node), file);
  fprintf(file, "]\n");
}

/*}}}  */
/*{{{  static void printNodes(NodeList nodes, FILE *file) */

static void printNodes(NodeList nodes, FILE *file)
{
  while (!isNodeListEmpty(nodes)) {
    printNode(getNodeListHead(nodes), file);
    nodes = getNodeListTail(nodes);
  }
}

/*}}}  */
/*{{{  static void printEdge(Edge edge, FILE *file) */

static void printEdge(Edge edge, FILE *file)
{
  // Edges are reversed to get the graph in the Meta-Environt to look 'right'
  ATfprintf(file, "%t -> %t ", getEdgeTo(edge), getEdgeFrom(edge));
  printAttributes(getEdgeAttributes(edge), file);
  ATfprintf(file, "\n");
}

/*}}}  */
/*{{{  static void printEdges(EdgeList edges, FILE *file) */

static void printEdges(EdgeList edges, FILE *file)
{
  while (!isEdgeListEmpty(edges)) {
    printEdge(getEdgeListHead(edges), file);
    edges = getEdgeListTail(edges);
  }
}

/*}}}  */
/*{{{  static void printGraph(Graph graph, FILE *file) */

static void printGraph(Graph graph, FILE *file)
{
  fprintf(file, "digraph TheGraph { ordering=out;\n");

  printNodes(getGraphNodes(graph), file);
  printEdges(getGraphEdges(graph), file);

  fprintf(file, "\n}\n");
}

/*}}}  */

/*{{{  void layoutGraph(Graph graph) */

void layoutGraph(Graph graph)
{
  int old_stdin, old_stdout, fd_to_dot, fd_from_dot, pid;
  char to_template[] = "/tmp/dotto-XXXXXX";
  char from_template[] = "/tmp/dotfrom-XXXXXX";
  FILE *f_to_dot;

  old_stdin = dup(0);

  if ((fd_to_dot = mkstemp(to_template)) < 0) {
    fprintf(stderr, "Can't create to dot file");
    exit(1);
  }
  f_to_dot = fdopen(fd_to_dot, "w");
  printGraph(graph, f_to_dot);
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

}

/*}}}  */

/*{{{  static void storeNodes(NodeList nodes) */

static void storeNodes(NodeList nodes)
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
/*{{{  static void storeEdges(EdgeList edges) */

static void storeEdges(EdgeList edges)
{
  edgeTable = ATtableCreate(11024, 75);
  while (!isEdgeListEmpty(edges)) {
    Edge edge = getEdgeListHead(edges);
    NodeId from = getEdgeFrom(edge);
    NodeId to = getEdgeTo(edge);
    ATerm key = (ATerm)ATmakeList2(NodeIdToTerm(from), NodeIdToTerm(to));
    ATtablePut(edgeTable, key, EdgeToTerm(edge));
    edges = getEdgeListTail(edges);
  }
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
/*{{{  AFun getAttributeType(Attribute attr) */

AFun getAttributeType(Attribute attr)
{
  return ATgetAFun((ATermAppl)AttributeToTerm(attr));
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

void mergeEdgeAttributes(NodeId from, NodeId to, AttributeList attrs)
{
  // Edges are reversed to get the graph in the Meta-Environt to look 'right'
  ATerm key = (ATerm)ATmakeList2(NodeIdToTerm(to), NodeIdToTerm(from));
  Edge edge = EdgeFromTerm(ATtableGet(edgeTable, key));

  edge = setEdgeAttributes(edge, mergeAttributes(getEdgeAttributes(edge), attrs));
  ATtablePut(edgeTable, key, EdgeToTerm(edge));
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

  edges = EdgeListFromTerm((ATerm)ATtableValues(edgeTable));

  return makeGraphDefault(NodeListFromTerm((ATerm)nodes), edges);
}

/*}}}  */

/*{{{  void rec_terminate(int conn, ATerm arg) */

void rec_terminate(int conn, ATerm arg)
{
  exit(0);
}

/*}}}  */
/*{{{  ATerm layout_graph(int conn, ATerm g) */

ATerm layout_graph(int conn, ATerm g)
{
  Graph graph = GraphFromTerm(g);

  storeNodes(getGraphNodes(graph));
  storeEdges(getGraphEdges(graph));

  assert(isValidGraph(graph));

  layoutGraph(graph);

  graph = buildGraph();

  initTermStore();
  ATtableReset(nodeTable);
  ATtableReset(edgeTable);

  return ATmake("snd-value(graph-layouted(<term>))", GraphToTerm(graph));
}

/*}}}  */

/*{{{  static void usage(char *prg, ATbool is_err) */

static void usage(char *prg, ATbool is_err)
{
  ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
  ATwarning("use '%s -at-help' to get more options.\n", prg);
  ATwarning("This program can only be used as a ToolBus tool!\n");
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  static void version(const char *msg) */

static void version(const char *msg)
{
  ATwarning("%s v%s\n", msg, myversion);
  exit(1);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int i;

  for (i=1; i<argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      usage(argv[0], ATfalse);
    } else if (strcmp(argv[i], "-V") == 0) {
      version(argv[0]);
    }
  }

  ATBinit(argc, argv, &bottomOfStack);
  initGraphApi();

  /*ATsetChecking(ATtrue);*/

  initTermStore();
  ATprotect((ATerm *)&termStore);

  ATBconnect(NULL, NULL, -1, dot_adapter_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
