/*
 * $Id$
 */

/*{{{  standard includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <Graph.h>
/*}}}  */

/*{{{  meta includes */

#include <aterm1.h>
#include <MEPT-utils.h>
#include "graph2dot.h"

/*}}}  */

/*{{{  globals */

static char myname[] = "graph2dot";
static char myversion[] = "1.0";
static char myarguments[] = "bchi:lmo:ptV";


/*}}}  */

/*{{{  void usage(void) */
 
void usage(void)
{
  fprintf(stderr,
	  "Converts an abstract graph (in ATerm format) to the dot format.\n\n"
          "Usage: %s [%s]\n"
          "Options:\n"
          "\t-h              display help information (usage)\n"
          "\t-i filename     input from file (default stdin)\n"
          "\t-o filename     output to file (default stdout)\n"
          "\t-V              reveal program version (i.e. %s)\n",
          myname, myarguments, myversion);
}
 
/*}}}  */
/*{{{  int main (int argc, char *argv[]) */

int main (int argc, char *argv[])
{
  int c; /* option character */
  ATerm bottomOfStack;
  ATerm tree;
  Graph graph;
  FILE *out = NULL;

  char   *input_file_name  = "-";
  char   *output_file_name = "-";

  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':  output_file_name = optarg;    break;
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
		 exit(0);
      default :  usage();                      exit(1);
    }

  ATinit(argc, argv, &bottomOfStack);
  initGraphApi();

  tree = ATreadFromNamedFile(input_file_name);

  if(tree == NULL) {
    ATerror("%s: could not read graph from input file %s\n", 
	    myname, input_file_name);
  }

  out = fopen(output_file_name,"w");

  if (out == NULL) {
    ATerror("%s: could not write dot to file %s\n",
	    myname, output_file_name);
  }

  graph = GraphFromTerm(tree);
  graph2dot(graph,out);

  return 0;
}

/*}}}  */
