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

/*}}}  */

/*{{{  global variables */

ATbool run_verbose;
ATbool output_muasf;

char myname[] = "asfc";
char myversion[] = "2.0";

static char myarguments[] = "hi:mn:o:vV";


/*}}}  */

/*{{{  static void usage(void) */

static void usage(void)
{
  ATwarning(
            "Usage: %s [options]\n"
            "Options:\n"
            "\t-h              display this message\n"
            "\t-i filename     input equations from file (default stdin)\n"
	    "\t-m              output muasf code         (default %s)\n"
            "\t-n name         name of the specification (obligatory)\n"
            "\t-o filename     output to file            (default stdout)\n"
            "\t-v              verbose mode\n"
            "\t-V              reveal program version (i.e. %s)\n",
            myname, 
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

static PT_ParseTree compile(char *name, ASF_CondEquationList equations)
{
  MA_Module muasf = asfToMuASF(name, equations);

  if (output_muasf) {
    return (PT_ParseTree) muasf;
  }

  return muasfToC(muasf); 
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t)  */

void rec_terminate(int cid, ATerm t) 
{
  exit(0);
}

/*}}}  */
/*{{{  ATerm compile_module(int cid, char *moduleName, ATerm equations,  */

ATerm compile_module(int cid, char *moduleName, ATerm equations, 
		     char *output)
{
  ASF_CondEquationList eqsList;
  PT_ParseTree result;
  FILE *fp;

  eqsList    = ASF_makeCondEquationListFromTerm(equations);

  result = compile(moduleName, eqsList);

  if (output_muasf) {
    ATwriteToNamedBinaryFile( 
      (ATerm) PT_makeParseTreeTree(
	PT_makeSymbolsList(PT_makeSymbolSort("Module"), PT_makeSymbolsEmpty()), 
	PT_makeTreeLayoutEmpty(),
	(PT_Tree) result,
	PT_makeTreeLayoutEmpty(),
	0), output); 
  }
  else {
    if (!strcmp(output, "-")) {
      fp = stdout;
    }
    else {
      fp = fopen(output, "w");
    }
    if (fp == NULL) {
      ATerror("Error: unable to open %s for writing\n", output);
    }

    ToC_code(moduleName, result, fp , myversion);
  }

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
    ATBinit(argc, argv, &bottom);  
    ATBconnect(NULL, NULL, -1, asfc_handler);
    ATBeventloop();
  } 
  else {
    
    /* Check commandline */ 
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
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

    eqs = ATreadFromNamedFile(equations);

    if (eqs == NULL) {
      exit(1);
    }

    compile_module(0,name,eqs,output);
  }

  return 0;
}

/*}}}  */

