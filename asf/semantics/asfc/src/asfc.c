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

#include <asc-support2-me.h> 
#include <asc-apply-me.h>

#include <aterm2.h>

#include "asfc.tif.h"
#include "sdf.h"
#include "asfsdf2muasf.h"

ATbool run_verbose;

char myname[] = "asfc";
char myversion[] = "1.3";

static char *outputDirName = NULL;

static char myarguments[] = "hi:n:e:o:vV";

static ATerm compile(char *name, SDF_ModuleList modules, 
		     ASF_CondEquationList equations);
static void set_output_dir(char *dirName);

void usage(void)
{
  ATwarning(
            "Usage: %s [options]\n"
            "Options:\n"
            "\t-h              display help information (usage)\n"
            "\t-e filename     input equations from file (default stdin)\n"
            "\t-i filename     input syntax from file (default stdin)\n"
            "\t-n name         name of the specification\n"
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

ATerm compile_module(int cid, char *moduleName, ATerm syntax, ATerm equations, 
		     char *output_dir)
{
  PT_ParseTree   pt;
  SDF_SDF        sdf;
  SDF_Definition definition;
  SDF_ModuleList moduleList;
  ASF_CondEquationList eqsList;
  ATerm result;/* temporary */

  set_output_dir(output_dir);

  pt         = PT_makeParseTreeFromTerm(syntax);
  sdf        = SDF_makeSDFFromTerm(
                 PT_makeTermFromTree(PT_getParseTreeTree(pt)));
  definition = SDF_getSDFDefinition(sdf);
  moduleList = SDF_getDefinitionList(definition);
  eqsList    = ASF_makeCondEquationListFromTerm(equations);

  result = compile(moduleName, moduleList, eqsList);

  ATwriteToNamedTextFile(result, output_dir); /* temporary */

  return ATmake("snd-value(compilation-done)");
}                              


void set_output_dir(char *dirName)
{
  int len = strlen(dirName) + 1;

  outputDirName = (char *) realloc(outputDirName, len);

  if (outputDirName == NULL) {
    ATerror("compiler: unable to allocate %d bytes\n", len);
  }
  else {
    strcpy(outputDirName, dirName);
  }
}

char* get_output_dir(void)
{
  if (outputDirName != NULL) {
    return outputDirName;
  }
  else if (getenv("COMPILER_OUTPUT") != NULL) {
    return getenv("COMPILER_OUTPUT");
  }
  else {
    return ".";
  }
}

static ATerm compile(char *name, SDF_ModuleList modules, 
	       ASF_CondEquationList equations)
{
  SDF_ProductionList productions = getModuleListProductions(modules);
  SDF_ModuleName moduleName = makeModuleNameFromString(name);
  MA_Module muasf = asfSdfToMuASF(moduleName, productions,equations);

  /* put MuASF2C here and reshuffler too */ 

  return (ATerm) muasf;
}


int main(int argc, char *argv[])
{
  ATerm bottom;
  int c, toolbus_mode = 0;
  char *syntax = "-";
  char *equations = "-";
  char *dir = "-";
  char *name = "";

  ATerm eqs;
  ATerm syn;

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
      case 'e':  equations=optarg;      break;
      case 'i':  syntax=optarg;         break;
      case 'n':  name=optarg;           break;
      case 'o':  dir=optarg;         break;
      case 'V':  version();             break;
      case 'h':  /* drop intended */
      default:   usage();               break;
      }
    }

    if (strlen(name) == 0) {
      usage();
      exit(1);
    }

    syn = ATreadFromNamedFile(syntax);
    eqs = ATreadFromNamedFile(equations);

    if (syn == NULL || eqs == NULL) {
      exit(1);
    }

    compile_module(0,name,syn,eqs,dir);
  }

  return 0;
}

