#ifndef WIN32
	/* These files can not be included in Windows NT*/
	#include <atb-tool.h>
	#include "addeqssyntax.tif.h"
#endif

#include <stdio.h>
#include <stdlib.h>	/* used for exit(0) */
#include <assert.h>
#include <ctype.h>
#include <unistd.h>   

#include <asc-support2-me.h>
#include <SDFME-utils.h>

/*{{{  globals */

static char *name;

ATbool run_verbose;      

static char myname[] = "addeqssyntax";
static char myversion[] = "2.1";  

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "m:hi:o:vV";   

void init_patterns();
void c_rehash(int newsize);

extern void register_Add_Eqs_Syntax();
extern void resolve_Add_Eqs_Syntax();
extern void init_Add_Eqs_Syntax();

/*}}}  */
/*{{{  ATerm *get_name(int cid) */

ATerm get_name(int cid)
{
  return ATmake("snd-value(name(<str>))", name);
}

/*}}}  */

static PT_Tree addEqsSyntaxFunction(char *name, PT_ParseTree parseTree)
{
  SDF_ModuleName sdfModuleName = SDF_makeModuleName(name);
  PT_Tree ptModuleName = PT_makeTreeFromTerm(
			   SDF_makeTermFromModuleName(sdfModuleName));
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = PT_applyFunctionToTree("add-equation-module",
				     "SDF",
				     2,
				     ptModuleName,
				     ptSyntax);

  } 
  else {
    ATerror("add_eqs_syntax: not a proper parse tree: %t\n", (ATerm) parseTree);
    return (PT_Tree) NULL;
  }

  return newTree;
}

static ATerm addEqsSyntax(char *name, ATerm term)
{
  PT_ParseTree parseTree = PT_makeParseTreeFromTerm(term);
  PT_Tree ptApplied = addEqsSyntaxFunction(name, parseTree);
  ATerm reduct           = innermost(ptApplied);
  PT_ParseTree asfix     = toasfix(reduct);
  
  return PT_makeTermFromParseTree(asfix);
}

/*{{{  ATerm add_eqs_syntax(int cid, char *name, ATerm t) */

ATerm add_eqs_syntax(int cid, char *name, ATerm term)
{
  ATerm  output = addEqsSyntax(name, ATBunpack(term));

  return ATmake("snd-value(extended-syntax(<term>))", ATBpack(output));
}

/*}}}  */
/*{{{  void rec_terminate(int cid) */

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}

/*}}}  */
/*{{{  void usage(void)
 *     Usage: displays helpful usage information
 */

void usage(void)
{
    ATwarning(
        "Usage: %s -m file -h -i file -o file -vV . . .\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
	"\t-m module       topmodule of specification (default: Main)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-v              verbose mode\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */    
/*{{{  void version(void) */

void version(void)
{
    ATwarning("%s v%s\n", myname, myversion);
}

/*}}}  */     
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm syntax = NULL, extended = NULL;
  char *moduleName = "Main";
  char *input = "-";
  char *output = "-"; 
  int cid;
  int c, toolbus_mode = 0;
  ATerm bottomOfStack;
  name = argv[0];

  /*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME"); 
  }
 
  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();

  ASC_initRunTime(INITIAL_TABLE_SIZE);

  register_Add_Eqs_Syntax();
  resolve_Add_Eqs_Syntax();
  init_Add_Eqs_Syntax();

  if(toolbus_mode) {
    #ifndef WIN32 /* Code with Toolbus calls, non Windows */
      ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
      cid = ATBconnect(NULL, NULL, -1, addeqssyntax_handler);
      ATBeventloop();
    #else
      ATwarning("addeqssyntax: Toolbus cannot be used in Windows.\n");
    #endif
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
	case 'm':  moduleName=optarg;                      break;
        case 'v':  run_verbose = ATtrue;                   break;
        case 'i':  input=optarg;                           break;
        case 'o':  output=optarg;                          break;
        case 'V':  version(); exit(0);                     break;

        case 'h':
        default:   usage(); exit(0);                       break;
      }
    } 
    argc -= optind;
    argv += optind;

    syntax = ATreadFromNamedFile(input);
   
    extended = addEqsSyntax(moduleName, syntax);  

    ATwriteToNamedBinaryFile(extended, output);
  }
  return 0;
}

/*}}}  */
