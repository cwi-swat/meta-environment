/* $Id$ */

#include <assert.h>
#include <atb-tool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>  
#include <sys/times.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


#include <SDFME-utils.h>  
#include <ASFME-utils.h>
#include <MEPT-utils.h>
#include <MuASF.h>

#include <aterm2.h>

#include "asfc.tif.h"
#include "sdf.h"
#include "asf2muasf.h"
#include "muasf2c.h"

ATbool run_verbose;

char myname[] = "asfc";
char myversion[] = "2.0";

static char myarguments[] = "hi:n:o:vV";

static ATerm compile(char *name, ASF_CondEquationList equations);

void usage(void)
{
  ATwarning(
            "Usage: %s [options]\n"
            "Options:\n"
            "\t-h              display help information (usage)\n"
            "\t-i filename     input equations from file (default stdin)\n"
            "\t-n name         name of the specification (obligatory)\n"
            "\t-o filename     output to file (default stdout)\n"
            "\t-v              verbose mode\n"
            "\t-V              reveal program version (i.e. %s)\n",
            myname, myversion);
  exit(0);
}

void version(void)
{
  ATwarning("%s v%s\n", myname, myversion);
  exit(0);
}

void rec_terminate(int cid, ATerm t) 
{
  exit(0);
}

ATerm compile_module(int cid, char *moduleName, ATerm equations, 
		     char *output)
{
  ASF_CondEquationList eqsList;
  ATerm result;

  eqsList    = ASF_makeCondEquationListFromTerm(equations);

  result = compile(moduleName, eqsList);

  ATwriteToNamedTextFile(result, output); 

  return ATmake("snd-value(compilation-done)");
}                              

static ATerm compile(char *name, ASF_CondEquationList equations)
{
  MA_Module muasf = asfToMuASF(name, equations);

  return (ATerm) muasf; /* muasfToC(muasf); */
}


int main(int argc, char *argv[])
{
  ATerm bottom;
  int c, toolbus_mode = 0;
  char *equations = "-";
  char *output = "-";
  char *name = "";

  ATerm eqs;

  run_verbose = ATfalse;

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
      case 'i':  equations=optarg;         break;
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

