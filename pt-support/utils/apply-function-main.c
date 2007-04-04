/*
 * $Id$
 */

#include <stdio.h>
#include <aterm1.h>
#include <aterm2.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <MEPT-utils.h> 
 
#ifndef WITHOUT_TOOLBUS
#include "apply-function.h"
#endif

static char myname[]    = "apply-function";
static char myversion[] = "1.2";
static char myarguments[] = "f:s:hi:o:V";

#define MAX_ARGS 32
/*
    Usage: displays helpful usage information
 */
void 
usage(void)
{
    fprintf(stderr,
	"\nApply-function encapsulates parsed terms with a quoted or unquoted prefix function.\n\n"
        "Usage: apply-function [paramaters]\n"
        "Parameters:\n"
	"\t-f name         name of prefix function\n"
	"\t-s sort         result sort of function\n"
        "\t-i filename     input argument tree from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-h              display help information (usage)\n"
        "\t-V              reveal program version (i.e. %s)\n"
        "\n"
        "Supply a -i <file> option for each argument from left to right.\n",
        myversion);
}

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

ATerm equal_trees(int cid, ATerm tree1, ATerm tree2)
{
  if (ATisEqual(ATremoveAllAnnotations(ATBunpack(tree1)),  
                ATremoveAllAnnotations(ATBunpack(tree2)))) {
    return ATmake("snd-value(result(true))");
  }
  else {
    return ATmake("snd-value(result(false))");
  }
}

ATerm get_argument_given_nr(int cid, ATerm tree, int argNr)
{
  PT_ParseTree parseTree, newParseTree;
  PT_Args args;
  PT_Tree argTree;

  parseTree = PT_ParseTreeFromTerm(tree);
  args = PT_getTreeArgs(PT_getParseTreeTree(parseTree));
  argTree = PT_getArgsTreeAt(args, argNr);
  newParseTree = PT_makeValidParseTreeFromTree(argTree);

  return ATmake("snd-value(tree(<term>))", 
                PT_ParseTreeToTerm(newParseTree));
}

ATerm apply_function_to_args(int cid, const char *function, const char *sort, ATerm args)
{
  PT_ParseTree newParseTree;
  PT_Args ptArgs = PT_makeArgsEmpty(); 
  ATermList argsList = (ATermList)args;

  while (!ATisEmpty(argsList)) {
    ATerm arg = ATgetFirst(argsList);
    PT_ParseTree parseTree = PT_ParseTreeFromTerm(ATBunpack(arg));
    argsList = ATgetNext(argsList);
    ptArgs = PT_makeArgsMany(PT_getParseTreeTree(parseTree), ptArgs);
  }
 
  newParseTree = PT_applyFunctionToArgsParseTree(function, sort, ptArgs);
 
  return ATmake("snd-value(tree(<term>))", 
                ATBpack(PT_ParseTreeToTerm(newParseTree)));
}

int 
main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;

  PT_ParseTree parseTree = NULL, newParseTree = NULL;
  char *inputs[MAX_ARGS] = { "-" };
  int  nInputs = 0;
  char *output = "-";
  char *function = "";
  char *sort = "";
  PT_Args args;
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
    cid = ATBconnect(NULL, NULL, -1, apply_function_handler);
    ATBeventloop();
  }
  else 
#endif
  {
    if(argc == 1) { /* no arguments */
      usage();
      exit(1);
    }

    while ((c = getopt(argc, argv, myarguments)) != EOF) {
      switch (c) {
        case 'h':  
	  usage();                      
	  exit(0);
        case 'i':
	  if (nInputs < MAX_ARGS) {
	    inputs[nInputs++] = strdup(optarg);  
	  } else {
	    ATerror("Maximum number of %s arguments exceeded.\n", MAX_ARGS);
	  }
	  break;
        case 'o':  
	  output = strdup(optarg);    
	  break;
        case 'f':  function = optarg;            break;  
        case 's':  sort = optarg;                break;
        case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
		   exit(0);
        default :  usage();                      exit(1);
      }
    }
   
    if (nInputs == 0) {
      nInputs = 1;
    }
  
    /* check if all needed arguments were supplied */
    if (!function || !strcmp(function, "") || !sort || !strcmp(sort,"")) {
      usage();
      exit(1);
    }
  
    ATinit(argc, argv, &bottomOfStack); 
    PT_initMEPTApi();

    args = PT_makeArgsEmpty(); 
  
    for (--nInputs; nInputs >= 0; nInputs--) {
      parseTree = PT_ParseTreeFromTerm(ATreadFromNamedFile(inputs[nInputs]));
      if (parseTree == NULL) {
        ATerror("Unable to read in %s\n", inputs[nInputs]);
        exit(1);
      }
      args = PT_makeArgsMany(PT_getParseTreeTree(parseTree), args);
    }
   
    newParseTree = PT_applyFunctionToArgsParseTree(function, sort, args);

    ATwriteToNamedBinaryFile(PT_ParseTreeToTerm(newParseTree), output);
  }
  return 0;
}
