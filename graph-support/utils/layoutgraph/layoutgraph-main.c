#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include "layoutgraph.h"
#include "layoutgraph.h"
#include "layoutgraph.tif.h"
#include <Graph.h>

static char myname[] = "layoutgraph";
static char myversion[] = "1.0";
static char myarguments[] = "hi:o:tV";


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

static void usage()
{
  ATwarning("Computes a nice graph layout using dot from AT&T graphviz.\n"
	    "Usage: %s [%s]\n"
	    "Options:\n"
	    "\t-h             prints this usage\n"
	    "\t-i filename    input graph term (default stdin)\n"
	    "\t-o filename    output graph term (default stdout)\n"
	    "\t-V             reveal program version (i.e. %s)\n",
	    myname, myarguments, myversion);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  ATbool use_toolbus = ATfalse;
  ATbool binary = ATtrue;
    
  char   *input_file_name  = "-";
  char   *output_file_name = "-";
  ATerm term;
  Graph graph;
  int i;

  for (i=1; !use_toolbus && i < argc; i++) {
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (use_toolbus) {
    ATBinit(argc, argv, &bottomOfStack);
    initGraphApi();
    ATBconnect(NULL, NULL, -1, layoutgraph_handler);
    ATBeventloop();
  }
  else {
    int c;
    while ((c = getopt(argc, argv, myarguments)) != EOF) {
      switch (c) {
	case 't':  binary = ATfalse;             break;
	case 'h':  usage();                      exit(0);
	case 'i':  input_file_name  = optarg;    break;
	case 'o':  output_file_name = optarg;    break;
	case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
		   exit(0);
	default :  usage();                      exit(1);
      }
    }

    ATinit(argc, argv, &bottomOfStack);
    initGraphApi();

    term = ATreadFromNamedFile(input_file_name);
    if(term == NULL) {
      ATerror("%s: could not read graph from input file %s\n",
	      myname, input_file_name);
    }

    graph = GraphFromTerm(term);
 
    assert(isValidGraph(graph));
    graph = layoutGraph(graph);

    term = GraphToTerm(graph);

     if (binary) {
       ATwriteToNamedBinaryFile(term, output_file_name);
     } 
     else {
       ATwriteToNamedTextFile(term, output_file_name);
     } 
  }

  return 0;
}

/*}}}  */
