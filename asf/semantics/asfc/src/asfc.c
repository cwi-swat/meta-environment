/* $Id$ */

/*{{{  standard includes */

#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>  
#include <sys/times.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


/*}}}  */
/*{{{  meta includes */

#include <ASFME-utils.h>
#include <MEPT-utils.h>
#include <MuASF.h>
#include <aterm2.h>
#include <atb-tool.h>


/*}}}  */
/*{{{  local includes */

#include "asfc.tif.h"
#include "asf2muasf.h"
#include "muasf2c.h"
#include "c-code.h"
#include "c-compiler.h"
#include "chars.h"
#include "idef.h"

/*}}}  */
/*{{{  global variables */

ATbool run_verbose;
ATbool toolbus_mode;
ATbool make_toolbus_tool;
ATbool output_muasf;
ATbool input_muasf;
ATbool use_c_compiler;

int toolbus_id;

char myname[] = "asfc";
char myversion[] = "2.5";

static char myarguments[] = "chi:lmn:o:p:tvV";


/*}}}  */

/*{{{  static void VERBOSE(const char* msg) */

static void VERBOSE(const char* msg)
{
  if (toolbus_mode) {
    ATBwriteTerm(toolbus_id, ATmake("snd-event(asfc-progress(<str>))", msg));
    ATBhandleOne(toolbus_id);
  }
  else if (run_verbose) {
    ATwarning("%s\n", msg);
  }
}

/*}}}  */
/*{{{  static void usage(void) */

static void usage(void)
{
  ATwarning(
	    "Usage: %s [options]\n"
	    "Options:\n"
	    "\t-c              toggle compilation to a binary(default: %s)   \n"
	    "\t-h              display this message                           \n"
	    "\t-i filename     input equations from file     (default stdin) \n"
	    "\t-l              input muasf code              (default %s)    \n"
	    "\t-m              output muasf code             (default %s)    \n"
	    "\t-n name         name of the tool              (default <basename>)\n"
	    "\t-o filename     output c code to file         (default stdout)\n"
	    "\t-p filename     include parse table           (default none)\n"
	    "\t-t              make toolbus tool             (default %s)\n"
	    "\t-v              verbose mode                                   \n"
	    "\t-V              reveal program version         (i.e. %s)       \n",
	    myname, 
	    use_c_compiler ? "on" : "off",
	    input_muasf ? "on" : "off", 
	    output_muasf ? "on" : "off", 
	    make_toolbus_tool ? "on" : "off",
	    myversion);
  exit(0);
}

/*}}}  */
/*{{{  static void version(void) */

static void version(void)
{
  ATwarning("%s v%s\n", myname, myversion);
  exit(0);
}

/*}}}  */

/*{{{  static char *basename(const char *source, const char *suffix) */

static char *basename(const char *source)
{
  char *duplicate = strdup(source);
  char *basename = NULL;
  char *p;
  p = strrchr(duplicate, '.');
  if (p != NULL) {
    *p = '\0';
  }
  p = strrchr(duplicate, '/'); /* OS dependent :-( */
  if (p != NULL) {
    basename = strdup(p+1);
  }
  else {
    basename = strdup(duplicate);
  }
  free(duplicate);
  return basename;
}

/*}}}  */
/*{{{  static PT_ParseTree compile(char *name, ATerm equations, char *output) */

static PT_ParseTree compile(char *name, ATerm eqs, ATerm parseTable, 
			    char *output)
{
  MA_Module muasf;
  PT_ParseTree c_code;
  FILE *fp = NULL;
  char *saveName = NULL;

  saveName = dashesToUnderscores(name);

  if (input_muasf) {
    PT_ParseTree parse_tree = PT_ParseTreeFromTerm(eqs);
    ATerm tree = PT_TreeToTerm(PT_getParseTreeTree(parse_tree));
    muasf = MA_ModuleFromTerm(tree);
  } else {
    VERBOSE("transforming ASF to MuASF");

    muasf = asfToMuASF(saveName, ASF_ASFConditionalEquationListFromTerm(eqs));
  }

  if (muasf == NULL) {
    return NULL;
  }

  if (output_muasf) {
    PT_ParseTree pt =
      PT_makeParseTreeTree(
        PT_makeSymbolsList(PT_makeSymbolSort("Module"), PT_makeSymbolsEmpty()),
        PT_makeTreeLayoutEmpty(),
        (PT_Tree) muasf,
        PT_makeTreeLayoutEmpty(),
        0);

    ATwriteToNamedTextFile((ATerm) pt, output);

    return pt;
  }
  else {
    
    VERBOSE("transforming MuASF to C");

    c_code = muasfToC(muasf); 

    if (!strcmp(output, "-")) {
      fp = stdout;
    }
    else {
      fp = fopen(output, "wb");
    }
    if (fp == NULL) {
      ATerror("Error: unable to open %s for writing\n", output);
    }

    VERBOSE("pretty printing C code");
    ToC_code(saveName, c_code, parseTable, fp , myversion);
    fclose(fp);

    if (make_toolbus_tool) {
      VERBOSE("generating idef script");

      make_idef_script(saveName);
      
      if (use_c_compiler) {
	idef2c(saveName);
      }
    }

    if (use_c_compiler) {
      
      VERBOSE("invoking C compiler");

      call_c_compiler(name, saveName, output);
    }

  }

  free(saveName);

  return c_code;
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t)  */

void rec_terminate(int cid, ATerm t) 
{
  exit(0);
}

/*}}}  */
/*{{{  void rec_ack_event(int cid, ATerm t) */

void rec_ack_event(int cid, ATerm t)
{
  return;
}

/*}}}  */
/*{{{  ATerm compile_module(int cid, char *moduleName, ATerm equations, char *output) */

ATerm compile_module(int cid, char *moduleName, ATerm equations)
{
  char output[_POSIX_PATH_MAX];
  PT_ParseTree result;

  toolbus_id = cid;

  sprintf(output, "%s.c", moduleName);

  result = compile(moduleName, ATBunpack(equations), NULL, output);

  return ATmake("snd-value(compilation-done)");
}                              

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottom;
  int c;
  char *equations = "-";
  char *output = "-";
  char *name = "";
  char *table = NULL;

  ATerm eqs;
  ATerm parseTable = NULL;

  run_verbose = ATfalse;
  input_muasf = ATfalse;
  output_muasf = ATfalse;
  use_c_compiler = ATfalse;
  toolbus_mode = ATfalse;
  make_toolbus_tool = ATfalse;

  /*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    if(!strcmp(argv[c], "-TB_TOOL_NAME")) {
      toolbus_mode = ATtrue;
      use_c_compiler = ATtrue;
    }
  }

  ATinit(argc, argv, &bottom);
  PT_initMEPTApi();
  ASF_initASFMEApi();
  MA_initMuASFApi();

  /*ATsetChecking(ATtrue);*/

  if (toolbus_mode) {
    ATBinit(argc, argv, &bottom);  
    ATBconnect(NULL, NULL, -1, asfc_handler);
    ATBeventloop();
  } 
  else {
    
    /* Check commandline */ 
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
      case 'c':  use_c_compiler = !use_c_compiler; break;	
      case 'v':  run_verbose = ATtrue;  break;
      case 'i':  equations=optarg;      break;
      case 'l':  input_muasf=ATtrue;    break;
      case 'm':  output_muasf=ATtrue;   break;
      case 'n':  name=optarg;           break;
      case 'o':  output=optarg;         break;
      case 'p':  table=optarg;          break;
      case 't':  make_toolbus_tool=ATtrue; break;
      case 'V':  version();             break;
      case 'h':  /* drop intended */
      default:   usage();               break;
      }
    }

    if (strlen(name) == 0) {
      if (!strcmp(equations,"-")) {
	ATwarning("The -n option is obligatory when reading from stdin.\n\n");
	usage();
	exit(1);
      }
      else {
	name = basename(equations);
      }
    }

    if (table != NULL) {
      parseTable = ATreadFromNamedFile(table);
      if (parseTable == NULL) {
	ATerror("Unable to read table from %s\n", table);
      }
    }

    if (use_c_compiler && !output_muasf && strcmp(output, "-") == 0) {
      char tmp[_POSIX_PATH_MAX];
      sprintf(tmp, "%s.c", name);
      output = strdup(tmp);
      if (!output) {
	ATerror("Unable to allocate memory for string %s\n", tmp);
      }
    }

    eqs = ATreadFromNamedFile(equations);

    if (eqs == NULL) {
      exit(1);
    }

    compile(name, eqs, parseTable, output);
  }

  return 0;
}

/*}}}  */
