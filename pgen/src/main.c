/* $Id$ */

/* The parse table is generated based on an LR automaton.
 * The LR automaton is a set of states. A state is consists of a number, 
 * the corresponding itemset, goto-set, action-set. 
 */

#include <assert.h>
#include <SDFME-utils.h>
#include <asc-support2-me.h>
#include <options.h>
#include <logging.h>
#include <rsrc-usage.h>

#include "ksdf2table.h"
#include "characters.h"
#include "item.h"
#include "first.h"
#include "follow.h"
#include "goto.h"
#include "parseTable-data.h"
#include "pgenOptions.h"
#include "parseTable-stats.h"

#define INITIAL_TABLE_SIZE 8191  
#define MAX_INPUTS 256

static char *name;

static char myname[] = "parsetablegen";
static char myversion[] = "4.1";
static char myarguments[] = "bcghi:lm:no:tvV";
static char *input[MAX_INPUTS] = { "-" };
static int numberOfInputs = 0;

/* Functions are defined in Sdf2-Normalization.c which is generated from the 
 * asf equations in Sdf2-Normailazation.eqs. */
extern void register_Sdf2_Normalization();
extern void resolve_Sdf2_Normalization();
extern void init_Sdf2_Normalization();


ATerm get_name(int cid) {
  return ATmake("snd-value(name(<str>))", name);
}

void rec_terminate(int cid, ATerm t) {
  exit(0);
}

static PTBL_ParseTable generateParseTable() {
  int i;

  ATermList vertex; 

  PTBL_State state;
  PTBL_States statelist = PTBL_makeStatesEmpty();
  PTBL_Gotos gotos; 
  PTBL_Choices actions;

  
  calc_first_table();
  calc_follow_table();
  createDFA();

  for (i = PGEN_getNumberOfStates()-1; i >= 0; i--) {
    vertex = PGEN_getStateOfStateNumber(i);

    gotos = (PTBL_Gotos)PGEN_getGotosOfState(vertex);
    if (!gotos) {
      gotos = PTBL_makeGotosEmpty();
    } 
    else if (PGEN_getStatsFlag()) {
      PGEN_increaseNumberOfGotos(PTBL_getGotosLength(gotos));
    }

    actions = PGEN_getActionsOfState(vertex);
    if (!actions) {
      actions = PTBL_makeChoicesEmpty();
    }
    else if (PGEN_getStatsFlag()) {
      PGEN_increaseNumberOfActions(PTBL_getChoicesLength(actions));
    }

    state = PTBL_makeStateDefault(i, gotos, actions);
    statelist = PTBL_makeStatesMany(state, statelist);
  }

  if (PGEN_getStatsFlag()) { PGEN_printStats(); }

  return PTBL_makeParseTableParseTable(PTBL_makeVersionDefault(), PGEN_getInitialStateNumber(), PGEN_getLabelSection(), statelist, PGEN_getPrioSection());
/*}
else {
  ATwarning("parsetablegen: unexpected error in syntax definition!\n");
  ATwarning("\tdumped grammar to ./parsetablegen.bug\n");
  ATwriteToNamedTextFile((ATerm) grammarTerm, "./parsetablegen.bug");

  return (PTBL_ParseTable)ATmake("parse-table(0,0,[],states([]),priorities([]))");
  */
}

static PT_Tree addNormalizeFunction(const char *str, PT_ParseTree parseTree) {
  SDF_ModuleName sdfModuleName = SDF_makeModuleName((char*) str);
  PT_Tree ptModuleName = PT_TreeFromTerm(SDF_ModuleNameToTerm(sdfModuleName));
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = PT_applyFunctionToTree("normalize",
        "Grammar",
        2,
        ptModuleName,
        ptSyntax);
  }
  else {
    ATerror("addNormalizeFunction: not a proper parse tree: %t\n",
        (ATerm) parseTree);

    return (PT_Tree) NULL;
  }

  return newTree;

}

static PT_Tree normalizeGrammar(const char *topModule, PT_ParseTree parseTree) {
  PT_Tree tree = addNormalizeFunction(topModule, parseTree);

  ATerm reduct = innermost(tree);
  return toasfix(reduct);
}

static ATerm normalize_and_generate_table(const char *name, PT_ParseTree sdf2term) {
  PTBL_ParseTable pt = NULL;
  PT_Tree ksdf;

  if (PGEN_getStatsFlag()) {
    STATS_Timer(); 
  } 

  if (PGEN_getGenerationModeFlag()) {
    ksdf = PT_getParseTreeTree(sdf2term);
  } else {
    ksdf = normalizeGrammar(name, sdf2term); 
  }

  if (PGEN_getStatsFlag()) {
      fprintf(LOG_log(), "Normalization to Kernel-Sdf took %.6fs\n", STATS_Timer());
  }

  if (PGEN_getNormalizationModeFlag()) {
    return PT_ParseTreeToTerm(PT_makeValidParseTreeFromTree(ksdf));
  }

  if (ksdf)  {
    PGEN_initTableGen();
    PGEN_processGrammar(ksdf);
    
    pt = generateParseTable();
    
    PGEN_destroyTableGen();       
  }

  if (PGEN_getStatsFlag()) { 
    fprintf(LOG_log(), "Parse table generation took %.6fs\n", STATS_Timer()); 
  }
  
  return (ATerm)pt;
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
      "Usage: %s [options]\n"
      "Options:\n"
      "\t-b              output terms in BAF format (default)\n"
      "\t-c              activate ATerm debugging mode (expensive!)\n"
      "\t-g              take kernel sdf as input and generate table\n"
      "\t-h              display help information (usage)\n"
      "\t-i filename     input from file (default stdin, can be repeated)\n"
      "\t-l              display statistic information\n"
      "\t-m modulename   name of top module (default Main)\n"
      "\t-n              only normalization of grammar\n"
      "\t-o filename     output to file (default stdout)\n"
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
  int proceed = 1;
  extern char *optarg;
  extern int   optind;
 
  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'b':  PGEN_setBafModeFlag(ATtrue);            break;
      case 'c':  PGEN_setATermDebugFlag(ATtrue);	     break;
      case 'g':  PGEN_setGenerationModeFlag(ATtrue);     break;
      case 'i':  assert(numberOfInputs < (MAX_INPUTS-1));
                 input[numberOfInputs++]=optarg;         break;
      case 'l':  PGEN_setStatsFlag(ATtrue);              break;
      case 'm':  PGEN_setTopModule(optarg);              break;
      case 'n':  PGEN_setNormalizationModeFlag(ATtrue);  break;
      case 'o':  PGEN_setOutputFilename(optarg);         break;
      case 't':  PGEN_setBafModeFlag(ATfalse);           break;
      case 'v':  PGEN_setVerboseModeFlag(ATtrue);        break;
      case 'V':  version(); proceed = 0;                 break;
      case 'h':
      default:   usage(); proceed = 0;                   break;
    }
  }
  argc -= optind;
  argv += optind;

  if (numberOfInputs > 1 && strcmp(PGEN_getOutputFilename(), "-") != 0) {
    usage();
    proceed = 0;
  }

  if (numberOfInputs == 0) {
    numberOfInputs = 1; /* Use stdin */
  }

  return proceed;
}

int main(int argc, char *argv[]) {
  FILE *iofile;
  int cid;
  int i;
  int c;
  int toolbus_mode = 0;
  ATbool need_closing;
  ATerm bottomOfStack; 
  ATerm pt;
  PT_ParseTree term;

  /*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack); 
  /*ATsetChecking(ATtrue);*/

  ASC_initRunTime(INITIAL_TABLE_SIZE);
  SDF_initSDFMEApi(); 
  PTBL_initPtableApi();

  register_Sdf2_Normalization();
  resolve_Sdf2_Normalization();
  init_Sdf2_Normalization();

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
      for (i=0; i < numberOfInputs; i++) {
        if (!strcmp(input[i], "") || !strcmp(input[i], "-")) {
          iofile = stdin;
        }
        else {
          if (!(iofile = fopen(input[i], "rb"))) {
            ATerror("%s: cannot open %s\n", myname, input[i]);
          }
        }

        if (PGEN_getVerboseModeFlag()) {
          ATwarning("generating parsetable from %s\n", input[i]);
        }

        term = PT_ParseTreeFromTerm(ATreadFromFile(iofile));
        assert(term);

        if (PGEN_getStatsFlag()) {
            LOG_OpenLog(myname, "pgen-stats.txt");
        }

        if (!strcmp(PGEN_getTopModule(), "-")) {
          pt = normalize_and_generate_table("Main", term);
        }
        else {
          pt = normalize_and_generate_table(PGEN_getTopModule(), term);
        }

        if (pt == NULL) {
          exit (1);
        }

        if (numberOfInputs > 1) {
          char buf[BUFSIZ];
          sprintf(buf, "%s.tbl", input[i]);
          iofile = fopen(buf, "wb");
          if (iofile == NULL) {
            ATerror("%s: cannot open %s\n", myname, buf);
          }
          need_closing = ATtrue;
        } else if (!strcmp(PGEN_getOutputFilename(), "") || 
            !strcmp(PGEN_getOutputFilename(), "-")) {
          iofile = stdout;
          need_closing = ATfalse;
        }
        else {
          iofile = fopen(PGEN_getOutputFilename(), "wb");
          if (iofile == NULL) {
            ATerror("%s: cannot open %s\n", myname, PGEN_getOutputFilename());
          }
          need_closing = ATtrue;
        }

        if (PGEN_getBafModeFlag()) {
          ATwriteToBinaryFile(pt, iofile);
        }
        else {
          ATwriteToTextFile(pt, iofile);
        }
        if (need_closing && iofile != NULL) {
          fclose(iofile);
        }
      }
    }
  }
  return 0;
}

