/*{{{  includes */

#include <assert.h>

#include <SDFME-utils.h>
#include <asc-support2-me.h>
#include "ksdf2table.h"
#include "characters.h"
#include "item.h"

/*}}}  */
/*{{{  defines */

#define MAX_INPUTS 256

/*}}}  */
/*{{{  global variables */

#define INITIAL_TABLE_SIZE 8191  

extern int nr_of_states;
extern int nr_of_actions;
extern int max_nr_actions;
extern int nr_of_gotos;
extern int max_nr_gotos;
extern int nr_of_items;
extern int max_nr_items;

static char *name;

ATbool run_verbose;
ATbool statisticsMode = ATfalse;
ATbool generationMode = ATfalse;
ATbool normalizationMode = ATfalse;

static char myname[] = "parsetablegen";
static char myversion[] = "4.1";

int version_nr = 6;

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "bcghi:lm:no:tvV";

/*}}}  */
/*{{{  external functions */

extern void register_Sdf2_Normalization();
extern void resolve_Sdf2_Normalization();
extern void init_Sdf2_Normalization();
 
/*}}}  */

/*{{{  ATerm *get_name(int cid) */

ATerm get_name(int cid)
{
  return ATmake("snd-value(name(<str>))", name);
}

/*}}}  */ 
/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t) {
  exit(0);
}

/*}}}  */

/*{{{  static PT_Tree addNormalizeFunction(char *str, PT_ParseTree parseTree) */

static PT_Tree addNormalizeFunction(const char *str, PT_ParseTree parseTree)
{
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

/*}}}  */

/*{{{  static PT_ParseTree normalize(char *topModule, PT_ParseTree parseTree) */

static PT_Tree normalize(const char *topModule, PT_ParseTree parseTree)
{
  PT_Tree tree = addNormalizeFunction(topModule, parseTree);

  ATerm reduct = innermost(tree);
  return toasfix(reduct);
}

/*}}}  */

/*{{{  static ATerm normalize_and_generate_table(char *name, PT_ParseTree sdf2term) */

static ATerm normalize_and_generate_table(const char *name, PT_ParseTree sdf2term)
{
  ATerm pt = NULL;
  PT_Tree ksdf;

  IF_PGEN_STATISTICS(PT_Timer()); 

  if (generationMode) {
    ksdf = PT_getParseTreeTree(sdf2term);
  } else {
    ksdf = normalize(name, sdf2term); 
  }

  IF_PGEN_STATISTICS(fprintf(PT_log(), 
                "Normalization to Kernel-Sdf took %.6fs\n", PT_Timer())); 

  if (normalizationMode) {
    return PT_ParseTreeToTerm(PT_makeValidParseTreeFromTree(ksdf));
  }

  init_table_gen();
  nr_of_states = 0;
  nr_of_actions = 0;
  max_nr_actions = 0;
  nr_of_gotos = 0;
  max_nr_gotos = 0;
  nr_of_items = 0;
  max_nr_items = 0;

  if (ksdf)  {
    pt = generate_parse_table(version_nr, SDF_GrammarFromTerm((ATerm)ksdf));
  }
  destroy_table_gen();       

  IF_PGEN_STATISTICS(fprintf(PT_log(), 
                "Parse table generation took %.6fs\n", PT_Timer())); 
 
  return pt;
}

/*}}}  */

/*{{{  ATerm generate_table(int cid, ATerm sdf, char *name, char *ext) */

ATerm generate_table(int cid, ATerm sdf, const char *name)
{
  ATerm pt, packed;
  ATerm unpackSdf;

  unpackSdf = ATBunpack(sdf);

  pt = normalize_and_generate_table(name, PT_ParseTreeFromTerm(unpackSdf));

  if (pt != NULL) {
    packed = ATBpack(pt);
    return ATmake("snd-value(generation-finished(<term>))", 
		  packed);
  }
  else {
    return ATmake("snd-value(generation-failed)");
  }
}

/*}}}  */
/*{{{  void usage(void) */

/*
 *     Usage: displays helpful usage information
 */

static void usage(void)
{
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

/*}}}  */
/*{{{  void version(void) */

static void version(void)
{
    ATwarning("%s v%s\n", myname, myversion);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[]) 
{
  FILE *iofile;

  int cid;
  ATerm bottomOfStack, pt;
  PT_ParseTree term;
  char *input[MAX_INPUTS] = { "-" };
  char *output = "-";
  char *moduleName = "-";
  int bafMode = 1;
  int proceed = 1;
  int i;
  int nr_inputs = 0;
  ATbool need_closing;
  
  extern char *optarg;
  extern int   optind;
  int c, toolbus_mode = 0;
  run_verbose = ATfalse;

  /*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack); 
  IT_init();

  ASC_initRunTime(INITIAL_TABLE_SIZE);
  SDF_initSDFMEApi(); 

  register_Sdf2_Normalization();
  resolve_Sdf2_Normalization();
  init_Sdf2_Normalization();

  if(toolbus_mode) {
    for (i=1; i<argc; i++) {
      if (strcmp(argv[i], "-l") == 0) {
	statisticsMode = ATtrue;
      }
    }
    #ifndef WIN32 /* Code with Toolbus calls, non Windows */
      ATBinit(argc, argv, &bottomOfStack);  
      cid = ATBconnect(NULL, NULL, -1, parsetablegen_handler);
      ATBeventloop();
    #else
      ATwarning("parsetablegen: Toolbus cannot be used in Windows.\n");
    #endif
  } 
  else {
#ifdef WIN32
    if( _setmode( _fileno( stdin ), _O_BINARY ) == -1 ) {
      perror( "Warning: Cannot set stdin to binary mode." );
    }
#endif
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'b':  bafMode = 1;                            break;
	case 'c':  ATsetChecking(ATtrue);		   break;
	case 'g':  generationMode = ATtrue;                break;
        case 'i':  assert(nr_inputs < (MAX_INPUTS-1));
		   input[nr_inputs++]=optarg;              break;
        case 'l':  statisticsMode = ATtrue;                break;
        case 'm':  moduleName=optarg;                      break;
        case 'n':  normalizationMode=ATtrue;               break;
        case 'o':  output=optarg;                          break;
        case 't':  bafMode = 0;                            break;
        case 'v':  run_verbose = ATtrue;                   break;
        case 'V':  version(); proceed = 0;                 break;

        case 'h':
        default:   usage(); proceed = 0;                   break;
      }
    }
    argc -= optind;
    argv += optind;

    if (nr_inputs > 1 && strcmp(output, "-") != 0) {
      usage();
      proceed = 0;
    }

    if (nr_inputs == 0) {
      nr_inputs = 1; /* Use stdin */
    }

    if(proceed) {
      for (i=0; i<nr_inputs; i++) {
	if (!strcmp(input[i], "") || !strcmp(input[i], "-")) {
	  iofile = stdin;
	}
	else {
	  if (!(iofile = fopen(input[i], "rb"))) {
	    ATerror("%s: cannot open %s\n", myname, input[i]);
	  }
	}

	if (run_verbose) {
	  ATwarning("generating parsetable from %s\n", input[i]);
	}

	term = PT_ParseTreeFromTerm(ATreadFromFile(iofile));
	assert(term);

	IF_PGEN_STATISTICS(
		      if(!PT_log()) {
		      ATwarning("Warning: implicitly opening logfile\n");
		      PT_OpenLog(myname, "pgen-stats.txt");
		      }
		     );

	if (!strcmp(moduleName, "-")) {
	  pt = normalize_and_generate_table("Main", term);
	}
	else {
	  pt = normalize_and_generate_table(moduleName, term);
	}

	if (pt == NULL) {
	  exit (1);
	}

	if (nr_inputs > 1) {
	  char buf[BUFSIZ];
	  sprintf(buf, "%s.tbl", input[i]);
	  iofile = fopen(buf, "wb");
	  if (iofile == NULL) {
	    ATerror("%s: cannot open %s\n", myname, buf);
	  }
	  need_closing = ATtrue;
	} else if (!strcmp(output, "") || !strcmp(output, "-")) {
	  iofile = stdout;
	  need_closing = ATfalse;
	}
	else {
	  iofile = fopen(output, "wb");
	  if (iofile == NULL) {
	    ATerror("%s: cannot open %s\n", myname, output);
	  }
	  need_closing = ATtrue;
	}

	if (bafMode) {
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

/*}}}  */

