/* $Id: tree2relation-main.c 22222 2007-03-27 17:09:45Z jurgenv $ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <aterm1.h>
#include <MEPT-utils.h>
#include "PT2relation.h"

#ifndef WITHOUT_TOOLBUS
#include "tree2relation.h"
#endif

/*}}}  */

/*{{{  globals */

static char myname[] = "tree2relation";
static char myversion[] = "1.0";
static char myarguments[] = "bchi:lmo:pstV";


/*}}}  */

/*{{{  void usage(void) */
 
void usage(void)
{
  fprintf(stderr,
	  "Converts a parse tree to an rstore with a relation holding the tree.\n"
          "For every application of a production a node is created and for every\n"
          "character or literal a leaf is created.\n\n"
          "Usage: %s [%s]\n"
          "Options:\n"
          "\t-b              save rstore in binary format\n"
          "\t-c              display individual characters\n"
          "\t-h              display help information (usage)\n"
          "\t-i filename     input from file (default stdin)\n"
          "\t-l              display layout nodes\n"
          "\t-o filename     output to file (default stdout)\n"
          "\t-p              show the productions\n"
          "\t-s              sharing on\n"
          "\t-t              save rstore in textual format\n"
          "\t-V              reveal program version (i.e. %s)\n",
          myname, myarguments, myversion);
}
 
/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm t) */
 
void rec_terminate(int cid, ATerm t)
{
  exit(0);
}
 
/*}}}  */
/*{{{  ATerm tree2relation(int cid, ATerm tree, ATerm leaves_on, */

ATerm tree2relation(int cid, ATerm tree, ATerm layout_on, ATerm leaves_on,
		 ATerm sharing_on)
{
  ATbool layoutFlag = ATmatch(layout_on, "true");
  ATbool leavesFlag = ATmatch(leaves_on, "true");
  ATbool sharingFlag = ATmatch(sharing_on, "true");

  RS_RStore rstore = PT_printAnyToRelation(ATBunpack(tree), leavesFlag, ATtrue, layoutFlag, 
				   leavesFlag, sharingFlag);

  return ATmake("snd-value(relation(<term>))", RS_RStoreToTerm(rstore));
}

/*}}}  */

/*{{{  int main (int argc, char *argv[]) */

int main (int argc, char *argv[])
{
  int c; /* option character */
  ATerm bottomOfStack;
  ATerm tree;
  RS_RStore rstore;

  char   *input_file_name  = "-";
  char   *output_file_name = "-";

  ATbool characters = ATfalse;
  ATbool productions = ATfalse;
  ATbool layout = ATfalse;
  ATbool literals = ATtrue;
  ATbool binary = ATtrue;
  ATbool sharing = ATfalse;

#ifndef WITHOUT_TOOLBUS
  ATbool use_toolbus = ATfalse;
  int i;
 
  for (i=1; !use_toolbus && i < argc; i++) {
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }
 
  if (use_toolbus) {
    int cid;
    ATBinit(argc, argv, &bottomOfStack);
    PT_initMEPTApi();
    RS_initRStoreApi();
    cid = ATBconnect(NULL, NULL, -1, tree2relation_handler);
    ATBeventloop();
  }
  else
#endif
  {
    while ((c = getopt(argc, argv, myarguments)) != EOF)
      switch (c) {
        case 'b':  binary = ATtrue;              break;
        case 'c':  characters = ATtrue;          break;
        case 'h':  usage();                      exit(0);
        case 'i':  input_file_name  = optarg;    break;
        case 'l':  layout = ATtrue;              break;
        case 'm':  literals = ATfalse;           break;
        case 'o':  output_file_name = optarg;    break;
        case 'p':  productions = ATtrue;         break;
        case 't':  binary = ATfalse;             break;
        case 's':  sharing = ATtrue;             break;
        case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
                                                 exit(0);
        default :  usage();                      exit(1);
    }

    ATinit(argc, argv, &bottomOfStack);
    PT_initMEPTApi();
    RS_initRStoreApi();

    fprintf(stdout, "hallo\n");

    tree = ATreadFromNamedFile(input_file_name);

    if(tree == NULL) {
      ATerror("%s: could not read term from input file %s\n", 
	      myname, input_file_name);
    }

    fprintf(stdout, "start\n");

    rstore = PT_printAnyToRelation(tree, characters, productions,
			       layout, literals, sharing);
    fprintf(stdout, "bijna klaar: %i\n", (int)rstore);

    if (!strcmp(output_file_name,"-")) {
      if (binary) {
        ATwriteToBinaryFile(RS_RStoreToTerm(rstore), stdout);
      } 
      else {
        ATwriteToTextFile(RS_RStoreToTerm(rstore), stdout);
      } 
    }
    else {
      if (binary) {
        ATwriteToNamedBinaryFile(RS_RStoreToTerm(rstore), output_file_name);
      } 
      else {
        ATwriteToNamedTextFile(RS_RStoreToTerm(rstore), output_file_name);
      } 
    }
  }

  return 0;
}

/*}}}  */
