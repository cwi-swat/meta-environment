/*
 * $Id$
 */

/*{{{  standard includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*}}}  */

/*{{{  meta includes */

#include <aterm1.h>
#include <MEPT-utils.h>


/*}}}  */

/*{{{  globals */

static char myname[] = "tree2dot";
static char myversion[] = "2.0";
static char myarguments[] = "chi:lmo:Vxps";


/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
  fprintf(stderr,
	  "Usage: %s -h -i <file> -o <file> -Vlmxps . . .\n"

	  "Options:\n"
	  "\t-c              enable sharing of characters    (default: off)\n"
	  "\t-h              display help information        (usage)\n"
	  "\t-i filename     input from file                 (default stdin)\n"
	  "\t-l              show layout                     (default: off)\n"
	  "\t-m              show literals                   (default: on)\n"
	  "\t-o filename     output to file                  (default stdout)\n"
	  "\t-V              reveal program version          (i.e. %s)\n"
	  "\t-x              show characters                 (default: off)\n"
	  "\t-p              show productions as nodes       (default: off)\n"
	  "\t-s              enable maximal sharing of nodes (default: off)\n",
	  myname, myversion);
}


/*}}}  */

/*{{{  int main (int argc, char *argv[]) */

int main (int argc, char *argv[])
{
  int c; /* option character */
  ATerm bottomOfStack;
  ATerm tree;
  char *dot = NULL;

  char   *input_file_name  = "-";
  char   *output_file_name = "-";

  ATbool characters = ATfalse;
  ATbool sharing = ATfalse;
  ATbool characters_sharing = ATfalse;
  ATbool productions = ATfalse;
  ATbool layout = ATfalse;
  ATbool literals = ATtrue;

  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'c':  characters_sharing = ATtrue;  break;
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'l':  layout = ATtrue;              break;
      case 'm':  literals = ATfalse;           break;
      case 'o':  output_file_name = optarg;    break;
      case 'x':  characters = ATtrue;          break;
      case 'p':  productions = ATtrue;         break;
      case 's':  sharing = ATtrue;         break;
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  usage();                      exit(1);
  }

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();

  tree = ATreadFromNamedFile(input_file_name);

  if(tree == NULL) {
    ATerror("%s: could not read term from input file %s\n", 
	    myname, input_file_name);
  }

  dot = PT_printAnyToDot(tree, sharing, characters,
			 characters_sharing, productions,
			 layout,literals);

  if (!strcmp(output_file_name,"-")) {
    fprintf(stdout,dot);
  }
  else {
    FILE *fp = fopen(output_file_name,"wb");

    if (fp != NULL) {
      fprintf(fp,dot);
      fclose(fp);
    }
    else {
      ATerror("Could not open %s for writing\n", output_file_name);
      return 1;
    }
  }

  return 0;
}

/*}}}  */
