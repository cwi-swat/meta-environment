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

#include <SDFME-utils.h>  
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

/*}}}  */

/*{{{  global variables */

ATbool run_verbose;
ATbool output_muasf;
ATbool use_c_compiler;

char myname[] = "asfc";
char myversion[] = "2.0";

static char myarguments[] = "chi:mn:o:vV";


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
	    "\t-m              output muasf code             (default %s)    \n"
            "\t-n name         name of the tool              (obligatory)    \n"
            "\t-o filename     output c code to file         (default <name>.c)\n"
            "\t-v              verbose mode                                   \n"
            "\t-V              reveal program version         (i.e. %s)       \n",
            myname, 
	    use_c_compiler ? "on" : "off",
	    output_muasf ? "on" : "off", 
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

/*{{{  static PT_ParseTree compile(char *name, ASF_CondEquationList equations) */

static PT_ParseTree compile(char *name, ASF_CondEquationList equations, 
			    char *output)
{
  MA_Module muasf;
  PT_ParseTree c_code;
  FILE *fp = NULL;
  char *saveName = NULL;

  saveName = dashesToUnderscores(name);

  if (run_verbose) {
    ATwarning("transforming asf to muasf\n");
  }

  muasf = asfToMuASF(saveName, equations);

  if (output_muasf) {
      return PT_makeParseTreeTree(
        PT_makeSymbolsList(PT_makeSymbolSort("Module"), PT_makeSymbolsEmpty()),
        PT_makeTreeLayoutEmpty(),
        (PT_Tree) muasf,
        PT_makeTreeLayoutEmpty(),
        0);
  }
  else {
    if (run_verbose) {
      ATwarning("transforming muasf to c\n");
    }

    c_code = muasfToC(muasf); 

    if (!strcmp(output, "-")) {
      fp = stdout;
    }
    else {
      fp = fopen(output, "w");
    }
    if (fp == NULL) {
      ATerror("Error: unable to open %s for writing\n", output);
    }

    if (run_verbose) {
      ATwarning("pretty printing c code\n");
    }

    ToC_code(saveName, c_code, fp , myversion);
    fclose(fp);

    if (use_c_compiler) {
      if (run_verbose) {
	ATwarning("calling c compiler\n");
      }
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
/*{{{  ATerm compile_module(int cid, char *moduleName, ATerm equations, char *output) */

ATerm compile_module(int cid, char *moduleName, ATerm equations)
{
  char output[2000];
  ASF_CondEquationList eqsList;
  PT_ParseTree result;

  sprintf(output, "%s.c", moduleName);

  eqsList    = ASF_makeCondEquationListFromTerm(equations);

  result = compile(moduleName, eqsList, output);

  return ATmake("snd-value(compilation-done)");
}                              

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottom;
  int c, toolbus_mode = 0;
  char *equations = "-";
  char *output = "-";
  char *name = "";

  ATerm eqs;

  run_verbose = ATfalse;
  output_muasf = ATfalse;
  use_c_compiler = ATtrue;

  /*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottom);
  PT_initMEPTApi();
  SDF_initSDFMEApi();
  ASF_initASFMEApi();
  MA_initMuASFApi();

  ATsetChecking(ATtrue);

  if (toolbus_mode) {
    use_c_compiler = ATfalse;
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
      case 'm':  output_muasf=ATtrue;   break;
      case 'n':  name=optarg;           break;
      case 'o':  output=optarg;         break;
      case 'V':  version();             break;
      case 'h':  /* drop intended */
      default:   usage();               break;
      }
    }

    if (strlen(name) == 0) {
      usage();
      exit(1);
    }

    if (use_c_compiler && !output_muasf && strcmp(output, "-") == 0) {
      char tmp[1024];
      sprintf(tmp,"%s.c",name);
      output = strdup(tmp);
      if (!output) {
	ATerror("Unable to allocate memory for string %s\n", tmp);
      }
    }

    eqs = ATreadFromNamedFile(equations);

    if (eqs == NULL) {
      exit(1);
    }

    compile(name,ASF_CondEquationListFromTerm(eqs),output);
  }

  return 0;
}

/*}}}  */

