#ifndef WIN32
	/* These files can not be included in Windows NT*/
	#include <atb-tool.h>
	#include "addapisyntax.tif.h"
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

static char myname[] = "addapisyntax";
static char myversion[] = "1.0";  

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "hi:o:vV";   

void init_patterns();
void c_rehash(int newsize);

extern void register_Add_API_Syntax();
extern void resolve_Add_API_Syntax();
extern void init_Add_API_Syntax();

/*}}}  */
/*{{{  ATerm *get_name(int cid) */

ATerm get_name(int cid)
{
  return ATmake("snd-value(name(<str>))", name);
}

/*}}}  */

/*{{{  static PT_Tree addAPISyntaxFunction(PT_ParseTree parseTree) */

static PT_Tree addAPISyntaxFunction(PT_ParseTree parseTree)
{
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = PT_applyFunctionToTree("add-api-syntax",
				     "SDF",
				     1,
				     ptSyntax);

  } 
  else {
    ATerror("add_api_syntax: not a proper parse tree: %t\n", (ATerm) parseTree);
    return (PT_Tree) NULL;
  }

  return newTree;
}

/*}}}  */

/*{{{  static ATerm addEqsSyntax(char *name, ATerm term) */

static ATerm addAPISyntax(ATerm term)
{
  PT_ParseTree parseTree = PT_makeParseTreeFromTerm(term);
  PT_Tree ptApplied = addAPISyntaxFunction(parseTree);
  ATerm reduct           = innermost(ptApplied);
  PT_ParseTree asfix     = toasfix(reduct);
  
  return PT_makeTermFromParseTree(asfix);
}

/*}}}  */

/*{{{  ATerm add_api(int cid, ATerm term) */

ATerm add_api_syntax(int cid, ATerm term)
{
  ATerm  output = addAPISyntax(term);

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
	"This tool adds syntax based on cons attributes and labels.\n"
        "A cons attribute generates a prefix function and a predicate \n"
	"and a label generates a getter and a setter function\n\n"	
        "Usage: %s -m file -h -i file -o file -vV . . .\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
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

  register_Add_API_Syntax();
  resolve_Add_API_Syntax();
  init_Add_API_Syntax();

  if(toolbus_mode) {
    #ifndef WIN32 /* Code with Toolbus calls, non Windows */
      ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
      cid = ATBconnect(NULL, NULL, -1, addapisyntax_handler);
      ATBeventloop();
    #else
      ATwarning("addeqssyntax: Toolbus cannot be used in Windows.\n");
    #endif
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
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
   
    extended = addAPISyntax(syntax);  

    ATwriteToNamedBinaryFile(extended, output);
  }
  return 0;
}

/*}}}  */
