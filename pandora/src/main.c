/*{{{  includes */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <MEPT-utils.h>
#include <PTMEPT.h>
#include <asc-support2-me.h>
#include <Error.h>

#include "pandora.h"
#include "pandora.tif.h"

/*}}}  */
/*{{{  variables */

static char* myname = "pandora";
static char* myversion = VERSION;
static char* myarguments = "bi:o:tvVh";

static ATbool run_verbose = ATfalse;

/*}}}  */
/*{{{  defines */

#define INITIAL_TABLE_SIZE 8191

/*}}}  */

/*{{{  external functions */

extern void register_Box_to_Text();
extern void resolve_Box_to_Text();
extern void init_Box_to_Text();

/*}}}  */

/*{{{  void usage(void) */

/*
 *     Usage: displays helpful usage information
 */

static void usage(void)
{
  ATwarning(
	    "Usage: %s [options]\n"
	    "Options:\n"
	    "\t-b              output box format\n"
	    "\t-h              display help information\n"
	    "\t-i filename     input (parsed) file                [stdin]\n"
	    "\t-o filename     output (parsed) file               [stdout]\n"
	    "\t-v              verbose mode\n"
	    "\t-V              reveal program version (i.e. %s)\n",
	    myname, myversion);
}

/*}}}  */
/*{{{  void version(void) */

static void version(void)
{
  ATwarning("%s v%s\n", myname, myversion);
}

/*}}}  */

/*{{{  static PT_Tree addBoxToTextFunction(PT_ParseTree parseTree) */

static PT_Tree addBoxToTextFunction(PT_ParseTree parseTree)
{
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) 
  {
    PT_Tree ptBox = PT_getParseTreeTree(parseTree);

    newTree = PT_applyFunctionToTree("box2text", "Text", 1, ptBox);
  }
  else 
  {
    ATerror("addBoxToTextFunction: not a proper parse tree: %t\n",
	    (ATerm) parseTree);
    return (PT_Tree) NULL;
  }
  return newTree;
}

/*}}}  */
/*{{{  static PT_ParseTree toText(PT_ParseTree parseTree) */

static PT_ParseTree toText(PT_ParseTree parseTree)
{
  PT_Tree tree = addBoxToTextFunction(parseTree);

  ATerm reduct = innermost(tree);
  return toasfixNoLayout(reduct);
}

/*}}}  */

/*{{{  ATerm pretty_print(int cid, ATerm input)  */

ATerm pretty_print(int cid, ATerm input) 
{
  PT_ParseTree parsetree;
  BOX_Start box;
  PT_ParseTree result = NULL;

  parsetree = PT_ParseTreeFromTerm(ATBunpack(input));
  box = pandora(parsetree);

  if (box != NULL) {
    result = toText(PT_ParseTreeFromTerm(BOX_StartToTerm(box)));
  }

  if (result != NULL) {
    ATerm value = ATBpack(PT_ParseTreeToTerm(result));
    return ATmake("snd-value(pretty-printed(<term>))", value);
  }
  else {
    ERR_Summary summary = ERR_makeSummarySummary("pandora","all", 
						  ERR_makeErrorListEmpty());
    return ATmake("snd-value(pretty-print-error(<term>))", summary);
  }
}

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm msg) */

void rec_terminate(int cid, ATerm msg)
{
  exit(0);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[]) 
{
  ATerm bottomOfStack;
  ATerm at_tree;
  char *ATlibArgv[] = {"pandora", "-at-termtable", "21"};
  PT_ParseTree tree, ptText;
  BOX_Start box;
  char *input = "-";
  char *output = "-";
  ATbool boxOutput = ATfalse;
  int c;
  int i;
  ATbool useToolbus = ATfalse;

  ATinit(3, ATlibArgv, &bottomOfStack); 
  ASC_initRunTime(INITIAL_TABLE_SIZE);
  PT_initMEPTApi(); 
  PTPT_initPTMEPTApi();
  BOX_initBoxApi();

  register_Box_to_Text();
  resolve_Box_to_Text();
  init_Box_to_Text();


  for (i=1; !useToolbus && i < argc; i++) {
    useToolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (useToolbus) {
    int cid;
    ATBinit(argc, argv, &bottomOfStack);
    cid = ATBconnect(NULL, NULL, -1, pandora_handler);
    ATBeventloop();
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
	case 'b':  boxOutput=ATtrue; break;
	case 'i':  input=optarg; break;
	case 'o':  output=optarg; break;
	case 'v':  run_verbose = ATtrue; break;
	case 'V':  version(); exit(0);
	case 'h':  usage(); exit(0);
	default:   usage(); exit(1); 
      }
    }

    at_tree = ATreadFromNamedFile(input);

    if (at_tree != NULL) {
      tree = PT_ParseTreeFromTerm(at_tree);

      if (run_verbose) {
	ATwarning("pandora: mapping parse trees to "
		  "BOX using default rules\n");
      }

      box = pandora(tree);

      if (!boxOutput) {      
	if (run_verbose) {
	  ATwarning("pandora: rendering BOX to list of characters\n");
	}

	ptText = toText(PT_ParseTreeFromTerm(BOX_StartToTerm(box)));


	if (run_verbose) {
	  ATwarning("pandora: yielding characters to output\n");
	}

	if (!strcmp(output, "-")) {
	  PT_yieldTreeToFile(PT_getParseTreeTop(ptText), stdout, ATfalse);
	}
	else {
	  FILE *fp = fopen(output, "wb");
	  if (fp != NULL) {
	    PT_yieldTreeToFile(PT_getParseTreeTop(ptText), fp, ATfalse);
	  }
	  else {
	    ATerror("Could not open %s for writing.\n", output);
	  }
	}
      }
      else {
	ptText = PT_ParseTreeFromTerm(BOX_StartToTerm(box));
	ATwriteToNamedSharedTextFile((ATerm) ptText, output);
      }
    }
    else {
      ATwarning("No such file: %s\n", input); 
      return 1; 
    }
  }

  return 0;
}

/*}}}  */
