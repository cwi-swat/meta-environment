
#include <stdio.h>
#include <stdlib.h>

#include <atb-tool.h>

#include "Graph.h"

FILE *output = NULL;

/*{{{  static void add_to_write_buf(char *data, int len) */

static void add_to_write_buf(char *data, int len)
{
  fwrite(data, 1, len, output);
}

/*}}}  */
/*{{{  static void add_string_to_write_buf(char *s) */

static void add_string_to_write_buf(char *s)
{
  add_to_write_buf(s, strlen(s));
}

/*}}}  */

/*{{{  static void add_graph_to_write_buf(Graph graph) */

static void add_graph_to_write_buf(Graph graph)
{
  NodeList nodes;
  EdgeList edges;
  Node node;
  Edge edge;
  char buf[BUFSIZ];
  float width, height;

  add_string_to_write_buf("digraph Term2Dot { node [shape=box];\n");
  nodes = getGraphNodes(graph);

  while (!isNodeListEmpty(nodes)) {
    node = getNodeListHead(nodes);
    nodes = getNodeListTail(nodes);
    /*ATfprintf(stderr, "node = %t\n", node);*/
    width = ((float)getNodeWidth(node))/72.0;
    height = ((float)getNodeHeight(node))/72.0;
    sprintf(buf, "\"%s\" [width=\"%2.2f\", height=\"%2.2f\"];\n",
	    getNodeName(node), width, height);
    add_string_to_write_buf(buf);
  }

  edges = getGraphEdges(graph);
  while (!isEdgeListEmpty(edges)) {
    edge = getEdgeListHead(edges);
    edges = getEdgeListTail(edges);
    sprintf(buf, "\"%s\" -> \"%s\";\n", getEdgeFrom(edge), getEdgeTo(edge));
    add_string_to_write_buf(buf);
  }

  add_string_to_write_buf("}\n");
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  ATerm t;

  output = stdout;

  ATinit(argc, argv, &bottomOfStack);
  initGraphApi();

  t = ATreadFromFile(stdin);

  if (t == NULL) {
    fprintf(stderr, "invalid term.\n");
    exit(1);
  }

  add_graph_to_write_buf(GraphFromTerm(t));

  return 0;
}

/*}}}  */
