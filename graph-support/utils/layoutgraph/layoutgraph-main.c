#include <stdio.h>
#include <assert.h>
#include "layoutgraph.h"
#include "layoutgraph.h"
#include "layoutgraph.tif.h"
#include <Graph.h>

static char myversion[] = "1.0";

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
  
  assert(isValidGraph(graph));

  graph = layoutGraph(graph);

  return ATmake("snd-value(graph-layouted(<term>))", GraphToTerm(graph));
}

/*}}}  */

/*{{{  static void usage(char *prg, ATbool is_err) */

static void usage(char *prg, ATbool is_err)
{
  ATwarning("Computes a nice graph layout using dot from AT&T graphviz.\n"
	    "This program can only be used as a ToolBus tool.\n\n"
	    "input: a graph term,\n"
	    "output: a graph term with positional information.\n");
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


  ATBconnect(NULL, NULL, -1, layoutgraph_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
