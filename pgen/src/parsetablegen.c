/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        `The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#include <SDF-utils.h>
#include <asc-support2.h>
#include "ksdf2table.h"

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

static char myname[] = "parsetablegen";
static char myversion[] = "2.3";

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "bchi:lm:o:tvV";

/*}}}  */
/*{{{  external functions */

extern void register_all();
extern void resolve_all();
extern void init_all();
 
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

static PT_Tree addNormalizeFunction(char *str, PT_ParseTree parseTree)
{
  SDF_ModuleName sdfModuleName = SDF_makeModuleNameUnparameterized(
                               SDF_makeModuleIdWord(str));
  PT_Tree ptModuleName = PT_makeTreeFromTerm(
                           SDF_makeTermFromModuleName(sdfModuleName));
  PT_Tree newTree = NULL;

  if (PT_isValidParseTree(parseTree)) {
    PT_Tree ptSyntax = PT_getParseTreeTree(parseTree);

    newTree = ASC_applyFunction("normalize",
                                "Sdf2-Normalization",
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

static PT_ParseTree normalize(char *topModule, PT_ParseTree parseTree)
{
  PT_Tree tree = addNormalizeFunction(topModule, parseTree);

  ATerm reduct = innermost(tree);
  return toasfix(reduct);
}

static ATerm normalize_and_generate_table(char *name, PT_ParseTree sdf2term)
{
  ATerm pt = NULL;
  PT_ParseTree ksdf;

  IF_STATISTICS(PT_Timer()); 

  ksdf = normalize(name, sdf2term); 

  IF_STATISTICS(fprintf(PT_log(), 
                "Normalization to Kernel-Sdf took %.6fs\n", PT_Timer())); 

  init_table_gen();
  nr_of_states = 0;
  nr_of_actions = 0;
  max_nr_actions = 0;
  nr_of_gotos = 0;
  max_nr_gotos = 0;
  nr_of_items = 0;
  max_nr_items = 0;

  if (ksdf)  {
    pt = generate_parse_table(ksdf);
  }
  destroy_table_gen();       

  IF_STATISTICS(fprintf(PT_log(), 
                "Parse table generation took %.6fs\n", PT_Timer())); 
 
  return pt;
}

/*}}}  */
/*{{{  ATerm generate_table(int cid, ATerm sdf, char *name, char *ext) */

ATerm generate_table(int cid, ATerm sdf, char *name, char *ext)
{
  ATerm pt = normalize_and_generate_table(name, PT_makeParseTreeFromTerm(sdf));
  ATerm packed = ATBpack(pt);

  packed = ATmake("lazy-unpack(<term>)", ATgetArgument((ATermAppl)packed, 0));
  return ATmake("snd-value(generation-finished(<term>))", packed);
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
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-l              display statistic information\n"
        "\t-m modulename   name of top module (default Main)\n"
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
  char *input = "-";
  char *output = "-";
  char *moduleName = "-";
  int bafMode = 1;
  int proceed = 1;
  
  extern char *optarg;
  extern int   optind;
  int c, toolbus_mode = 0;
  run_verbose = ATfalse;

  /*  Check whether we're a ToolBus process  */
  for(c=1; !toolbus_mode && c<argc; c++)
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");

  AFinit(argc, argv, &bottomOfStack);

  AFinitAsFixPatterns();

  ASC_initRunTime(INITIAL_TABLE_SIZE);
  SDF_initSDFApi(); 

  register_all();
  resolve_all();
  init_all();

  if(toolbus_mode) {
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
        case 'i':  input=optarg;                           break;
        case 'l':  statisticsMode = ATtrue;                break;
        case 'm':  moduleName=optarg;                      break;
        case 'o':  output=optarg;                          break;
        case 't':  bafMode = 0;                            break;
        case 'v':  run_verbose = ATtrue;                   break;
        case 'V':  version(); proceed = 0;                 break;
	case 'c':  ATsetChecking(ATtrue);		   break;

        case 'h':
        default:   usage(); proceed = 0;                   break;
      }
    }
    argc -= optind;
    argv += optind;

    if(proceed) {
      if (!strcmp(input, "") || !strcmp(input, "-")) {
        iofile = stdin;
      }
      else if (!(iofile = fopen(input, "r")))
        ATerror("%s: cannot open %s\n", myname, input);

      term = PT_makeParseTreeFromTerm(ATreadFromFile(iofile));
  
      if (run_verbose) {
        ATwarning("Parse table generation in fast mode\n");
      }

      IF_STATISTICS(
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

      if (!strcmp(output, "") || !strcmp(output, "-"))
        iofile = stdout;
      else if (!(iofile = fopen(output, "w")))
        ATerror("%s: cannot open %s\n", myname, output);

      if (bafMode) {
        ATwriteToBinaryFile(pt, iofile);
      }
      else {
        ATwriteToTextFile(pt, iofile);
      }
    }
  }
  return 0;
}

/*}}}  */


