/* $Id$ */

/* The parse table is generated based on an LR automaton.
 * The LR automaton is a set of states. A state is consists of a number, 
 * the corresponding itemset, goto-set, action-set. 
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <SDFME-utils.h>
#include <options.h>
#include <atb-tool.h>
#include <asc-support2-me.h>
#include <logging.h>

#include "pgenOptions.h"
#include "sdf-generate.h"
#include "load.h"
#include "parsetablegen.h"

#define INITIAL_TABLE_SIZE 8191  
#define MAX_INPUTS 256

static char *name;

static char myname[] = "sdf2table";
static char myversion[] = "5.0";
static char myarguments[] = "bcdghi:l:m:no:p:tvV";


ATerm get_name(int cid) {
  return ATmake("snd-value(name(<str>))", name);
}

void rec_terminate(int cid, ATerm t) {
  exit(0);
}

/* Used when run from toolbus. */
ATerm generate_table(int cid, ATerm sdf, const char *name) {
  ATerm pt;
  ATerm packed;
  ATerm unpackSdf;

  unpackSdf = ATBunpack(sdf);

  pt = normalize_and_generate_table(name, PT_ParseTreeFromTerm(unpackSdf));

  if (pt != NULL) {
    packed = ATBpack((ATerm)pt);
    return ATmake("snd-value(generation-finished(<term>))", packed);
  }
  else {
    return ATmake("snd-value(generation-failed)");
  }
}

static void usage(void) {
  ATwarning(
      "Use this program to generate a parse table from an SDF definition.\n"
      "It can generate tables from full SDF definition files, parse trees\n"
      "of full SDF definition files, or search for modules itself starting\n"
      "from a top module name and using a search path.\n\n"
      "Common usage patterns:\n"
      "\tsdf2table -c -m <topModule> -o <file>.tbl\n"
      "\tsdf2table -c -m <topModule> -p <searchPath> -o <file>.tbl\n"
      "\tsdf2table -m <topModule> -i <definitionFile>.def -o <file>.tbl\n"
      "\tsdf2table -m <topModule> -i <definitionTree>.def.pt -o <file>.tbl\n"
      "\tsdf2table -c -d -m <topModule> -o <definitionFile>.def.pt\n\n"
      "Usage: %s [options]\n"
      "Options:\n"
      "\t-b              output terms in BAF format (default)\n"
      "\t-c              collect SDF modules from the search path\n"
      "\t-d              only collect an SDF definition\n"
      "\t-g              take kernel sdf as input and generate table\n"
      "\t-h              display help information (usage)\n"
      "\t-i filename     input from file (default stdin, can be repeated)\n"
      "\t-l filename     log statistic information\n"
      "\t-m modulename   name of top module (default Main)\n"
      "\t-n              only normalization of grammar\n"
      "\t-o filename     output to file (default stdout)\n"
      "\t-p path         colon separated search path for SDF modules (default \'.\')\n"
      "\t-t              output terms in plaintext format\n"
      "\t-v              verbose mode\n"
      "\t-V              reveal program version (i.e. %s)\n",
    myname, myversion);
}

static void version(void) {
  ATwarning("%s v%s\n", myname, myversion);
}

static int handleOptions(int argc, char **argv) {
  int c ;
  extern char *optarg;
  extern int   optind;

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'b':  PGEN_setSafModeFlag(ATtrue);            break;
      case 'c':  PGEN_setCollectFlag(ATtrue);	         break;
      case 'd':  PGEN_setDefinitionModeFlag(ATtrue);     break;
      case 'g':  PGEN_setGenerationModeFlag(ATtrue);     break;
      case 'i':  PGEN_setInputFilename(optarg);          break;
      case 'l':  PGEN_setStatsFlag(ATtrue);
                 PGEN_setStatsFilename(optarg);          break;
      case 'm':  PGEN_setTopModule(optarg);              break;
      case 'n':  PGEN_setNormalizationModeFlag(ATtrue);  break;
      case 'o':  PGEN_setOutputFilename(optarg);         break;
      case 'p':  PGEN_setSearchPath(optarg);             break;
      case 't':  PGEN_setSafModeFlag(ATfalse);           break;
      case 'v':  PGEN_setVerboseModeFlag(ATtrue);        break;
      case 'V':  version(); return ATfalse;
      case 'h':
      default:   usage(); return ATfalse;
    }
  }

  if (PGEN_getCollectFlag() && strcmp(PGEN_getInputFilename(), "-")) {
    ATwarning("The -c option can not be used with -i option\n\n");
    usage();
    return ATfalse;
  }

  if (PGEN_getDefinitionModeFlag() && PGEN_getNormalizationModeFlag()) {
    ATwarning("The -d option can not be used with the -n option\n\n");
    usage();
    return ATfalse;
  }

  if (PGEN_getDefinitionModeFlag() && PGEN_getGenerationModeFlag()) {
    ATwarning("The -d option can not be used wit the -g option\n\n");
    usage();
    return ATfalse;
  }

  if (PGEN_getCollectFlag() && PGEN_getGenerationModeFlag()) {
    ATwarning("The -c option can not be used with the -g option\n\n");
    usage();
    return ATfalse;
  }

  argc -= optind;
  argv += optind;

  #ifndef PGEN_COLLECT_STATISTICS
  if (PGEN_getStatsFlag) {
    ATfprintf(stderr, "%s: Cannot collect PGEN statistics! Compile PGEN with the PGEN_COLLECT_STATISTICS environment variable set.\n", myname);
    exit(1);
  }
  #endif

  return ATtrue;
}

int main(int argc, char *argv[]) {
  int cid;
  int i;
  int c;
  int toolbus_mode = 0;
  ATerm bottomOfStack; 
  ATerm pt;
  PT_ParseTree term = NULL;

  /*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack); 
  ASC_initRunTime(INITIAL_TABLE_SIZE);

  SDF_initSDFMEApi(); 
  PTBL_initPtableApi();

  OPT_initialize();
  PGEN_initializeDefaultOptions();

  if(toolbus_mode) {
    for (i=1; i<argc; i++) {
      if (strcmp(argv[i], "-l") == 0) {
        PGEN_setStatsFlag(ATtrue);
      }
    }
    ATBinit(argc, argv, &bottomOfStack);  
    cid = ATBconnect(NULL, NULL, -1, parsetablegen_handler);
    ATBeventloop();
  } 
  else {
    if (handleOptions(argc, argv)) {
      if (PGEN_getCollectFlag()) {
        if (PGEN_getVerboseModeFlag) {
          ATwarning("Loading definition for module %s using searchpath %s\n",
              PGEN_getTopModule(), PGEN_getSearchPath());
        }

        term = load(PGEN_getTopModule(), PGEN_getSearchPath());
      }
      else {
        if (PGEN_getVerboseModeFlag) {
          ATwarning("Loading definition from file %s\n",
              PGEN_getInputFilename());
        }

        term = PT_ParseTreeFromTerm(ATreadFromNamedFile(PGEN_getInputFilename()));
        if (term == NULL || 
            !PT_isValidParseTree(term)) {
          if (PGEN_getVerboseModeFlag) {
            ATwarning("Parsing definition from file %s\n", PGEN_getInputFilename());
          }

          term = parseDefinition(PGEN_getInputFilename());
        }
      }
    }

    if (term == NULL) {
      return 1;
    }

    assert(term);

    if (!PGEN_getDefinitionModeFlag()) {
      pt = normalize_and_generate_table(PGEN_getTopModule(), term);
    }
    else {
      pt = (ATerm) term;
    }

    if (pt == NULL) {
      exit (1);
    }

    if (PGEN_getSafModeFlag()) {
      ATwriteToNamedSAFFile(pt, PGEN_getOutputFilename());
    }
    else {
      ATwriteToNamedTextFile(pt, PGEN_getOutputFilename());
    }
  }

  return 0;
}

