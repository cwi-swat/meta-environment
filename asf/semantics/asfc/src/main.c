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

#include "asfc.h"
#include "asf2muasf.h"
#include "muasf2c.h"
#include "c-code.h"
#include "c-compiler.h"
#include "chars.h"

/*}}}  */
/*{{{  global variables */

ATbool run_verbose;
ATbool toolbus_mode;
ATbool output_muasf;
ATbool input_muasf;
ATbool use_c_compiler;
ATbool keep_annos;
ATbool keep_asfc_layout;
ATbool parse_io;
ATbool recompile;
ATbool indent;

int toolbus_id;

char myname[] = "asfc";
char myversion[] = "3.0";

static char myarguments[] = "acC:hi:IlLmn:o:p:rstvV";


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
	    "\t-a              rewriting with annotations    (%s)\n"
	    "\t-c              toggle compilation to a binary(%s)   \n"
	    "\t-C              provide alternative CFLAGS\n"
	    "\t-h              display this message                           \n"
	    "\t-i filename     input equations from file     (default stdin) \n"
	    "\t-I              use 'indent' before gcc       (default off)\n"
	    "\t-L              rewriting with layout         (%s)\n"
	    "\t-l              input muasf code              (%s)    \n"
	    "\t-m              output muasf code             (%s)    \n"
	    "\t-n name         name of the tool              (default <basename>)\n"
	    "\t-o filename     output c code to file         (default stdout)\n"
	    "\t-p filename     include parse table           (default none)\n"
	    "\t-r              re-compile an existing C file \n"
	    "\t-s              parse input and output, requires -p option (%s)\n"
	    "\t-v              verbose mode                                   \n"
	    "\t-V              reveal program version         (i.e. %s)       \n",
	    myname, 
	    keep_annos ? "on" : "off",
	    use_c_compiler ? "on" : "off",
	    keep_asfc_layout ? "on" : "off",
	    input_muasf ? "on" : "off", 
	    output_muasf ? "on" : "off", 
	    parse_io ? "on" : "off",
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
/*{{{  static char *remove_extension(const char *source) */

static char *remove_extension(const char *source)
{
  char *duplicate = strdup(source);
  char *p;
  p = strrchr(duplicate, '.');
  if (p != NULL) {
    *p = '\0';
  }
  return duplicate;
}

/*}}}  */
/*{{{  static PT_ParseTree compile(char *name, ATerm equations, char *output) */

static PT_ParseTree compile(const char *name, const char *cflags, ATerm eqs, ATerm parseTable, 
			    const char *output)
{
  MA_Module muasf;
  PT_ParseTree c_code;
  FILE *fp = NULL;
  char *saveName = NULL;
  char *prefix = remove_extension(output);

  saveName = dashesToUnderscores(name);

  if (!recompile) {
    if (input_muasf) {
      PT_ParseTree parse_tree = PT_ParseTreeFromTerm(eqs);
      ATerm tree = PT_TreeToTerm(PT_getParseTreeTree(parse_tree));
      muasf = MA_ModuleFromTerm(tree);
    } else {
      VERBOSE("transforming ASF to MuASF");

      muasf = asfToMuASF(saveName, ASF_ASFConditionalEquationListFromTerm(eqs), keep_asfc_layout);
    }

    if (muasf == NULL) {
      return NULL;
    }

    if (output_muasf) {
      PT_ParseTree pt =
	PT_makeParseTreeTree(
			     PT_makeSymbolsMany(PT_makeSymbolSort("Module"), PT_makeSymbolsEmpty()),
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
	ATwarning("Error: unable to open %s for writing\n", output);
	return NULL;
      }

      VERBOSE("pretty printing C code");
      ToC_code(parse_io, keep_annos, keep_asfc_layout, 
	       saveName, c_code, parseTable, fp , 
	       myversion);
      fclose(fp);

      if (indent) {
	char command[1024];
	sprintf(command,"indent %s\n", output);
	VERBOSE("invoking indent");
	system(command);
      }

      if (use_c_compiler) {

	VERBOSE("invoking C compiler");

	call_c_compiler(cflags, keep_annos, prefix, saveName, prefix, output);
      }

    }
    free(saveName);
    free(prefix);

    return c_code;
  }
  else {
    VERBOSE("invoking C compiler");
    call_c_compiler(cflags, keep_annos, prefix, saveName, prefix, output);
    free(saveName);
    free(prefix);
  }

  return NULL;
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

ATerm compile_module(int cid, const char *moduleName, const char *output, 
		     ATerm equations, ATerm parsetable)
{
  PT_ParseTree result;

  toolbus_id = cid;

  parse_io = ATtrue;
  result = compile(moduleName, NULL, ATBunpack(equations), ATBunpack(parsetable),
		   output);

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
  char *cflags = NULL;

  ATerm eqs;
  ATerm parseTable = NULL;

  keep_annos = ATfalse;
  keep_asfc_layout = ATfalse;
  run_verbose = ATfalse;
  input_muasf = ATfalse;
  output_muasf = ATfalse;
  use_c_compiler = ATfalse;
  toolbus_mode = ATfalse;
  parse_io = ATfalse;
  recompile = ATfalse;
  indent = ATfalse;

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

  if (toolbus_mode) {
#ifndef NO_TOOLBUS
    ATBinit(argc, argv, &bottom);  
    ATBconnect(NULL, NULL, -1, asfc_handler);
    ATBeventloop();
#endif
  } 
  else {
    
    /* Check commandline */ 
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
      case 'a':  keep_annos = ATtrue; break;	
      case 'c':  use_c_compiler = !use_c_compiler; break;	
      case 'C':  cflags=optarg; break;
      case 'v':  run_verbose = ATtrue;  break;
      case 'i':  equations=optarg;      break;
      case 'I':  indent=ATtrue;         break;
      case 'l':  input_muasf=ATtrue;    break;
      case 'L':  keep_asfc_layout=ATtrue;    break;
      case 'm':  output_muasf=ATtrue;   break;
      case 'n':  name=optarg;           break;
      case 'o':  output=optarg;         break;
      case 'p':  table=optarg;          break;
      case 'r':  recompile=ATtrue;      break;
      case 's':  parse_io=ATtrue;       break;
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

    if (parse_io && table == NULL) {
      ATerror("-p option with parse table required\n");
    }

    if ((use_c_compiler || recompile) 
	&& !output_muasf && strcmp(output, "-") == 0) {
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

    compile(name, cflags, eqs, parseTable, output);
  }

  return 0;
}

/*}}}  */
