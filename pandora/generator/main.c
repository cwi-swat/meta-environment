#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <MEPT-utils.h>
#include <asc-support2-me.h>

#include "pandora.h"
#include "pandora.tif.h"

static char* myname = "pandora";
static char* myversion = VERSION;
static char* myarguments = "i:o:vVhs:";
static ATbool run_verbose = ATfalse;

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
	    "\t-h              display help information\n"
	    "\t-i filename     input (parsed) file                [stdin]\n"
	    "\t-o filename     output (parsed) file               [stdout]\n"
	    "\t-s filename     input (parsed) syntax definition   [obligatory]\n"
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

    newTree = PT_applyFunctionToTree("box2text", "BText", 1, ptBox);
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
/*{{{  static PT_ParseTree normalize(char *topModule, PT_ParseTree parseTree) */

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
    return ATmake("snd-value(pretty-printed(<term>))", 
		  PT_ParseTreeToTerm(result));
  }
  else {
    ERR_Summary summary = ERR_makeSummaryFeedback("pandora","all", 
						  ERR_makeFeedbackListEmpty());
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
  PT_ParseTree tree, ptText;
  BOX_Start box;
  char *input = "";
  char *output = "";
  int c;
  int i;
  ATbool useToolbus = ATfalse;

  ATinit(argc, argv, &bottomOfStack); 
  ASC_initRunTime(INITIAL_TABLE_SIZE);
  PT_initMEPTApi(); 
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
      box = pandora(tree);

      ptText = toText(PT_ParseTreeFromTerm(BOX_StartToTerm(box)));
      ATwriteToNamedBinaryFile(PT_ParseTreeToTerm(ptText), output);
    }
    else {
      ATwarning("No such file: %s\n", input); 
      return 1; 
    }
  }

  return 0;
}

/*}}}  */
