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
#include "ksdf2table.h"

/*{{{  global variables */

#define INITIAL_TABLE_SIZE 8191  

extern ATerm pattern_asfix_term;
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
 
void init_patterns();
void c_rehash(int newsize);  
ATerm innermost(ATerm t);
ATerm toasfix(ATerm t, ATerm f, ATerm n);        
ATerm generate_parse_table(ATerm g);
void init_table_gen();
void destroy_table_gen();

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
/*{{{  ATerm add_name_norm_function(char *name, ATerm term) */

ATerm make_name_term(ATerm name)
{
  ATerm result = NULL;
  char *text;

  if(ATmatch(name,"<str>",&text)) {
    result = ATmakeTerm(pattern_asfix_lex,
                        text,
                        ATparse("sort(\"ModuleId\")"));
    result = ATmakeTerm(pattern_asfix_appl,
                        ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)"),
                        ATparse("w(\"\")"),
                        ATmakeList1(result));
  }
  return result;
} 

ATerm add_name_norm_function(char *str, ATerm term)
{
  ATerm t[8], result, appl, nameterm, name;
  ATerm t_name;
  ATerm abbrevs;
  ATerm term_open, term_comma, term_close, term_ws;

  name = ATmake("<str>",str);
  if (ATmatchTerm(term, pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) {

    t_name = ATparse("l(\"normalize\")");
    abbrevs = ATparse("abbreviations([])");
    term_open = ATparse("l(\"(\")");
    term_comma = ATparse("l(\",\")");
    term_close = ATparse("l(\")\")");
    term_ws = ATparse("w(\"\")");     
    nameterm = make_name_term(name);

    result = ATmakeTerm(pattern_asfix_appl,
                        ATparse("prod(id(\"Sdf2-Normalization\"),w(\"\"),[ql(\"normalize\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"SDF\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"), 
                        term_ws,
                        ATmakeList(11,t_name, term_ws,
                                      term_open, term_ws,
                                      nameterm, term_ws,
                                      term_comma, term_ws,
                                      appl, term_ws,
                                      term_close));
    return ATmakeTerm(pattern_asfix_term,
                      ATparse("l(\"term\")"), term_ws,  
                      ATparse("l(\"X\")"), term_ws,  
                      ATparse("id(\"X\")"), term_ws,  
                      result, term_ws,  abbrevs);
  }
  else {
    ATerror("not a legal term: %t\n", term);
    return NULL;
  }
}                                                       

/*}}}  */
/*{{{  ATerm add_norm_function(ATerm term) */

ATerm add_norm_function(ATerm term)
{
  ATerm t_name, q_t_name;
  ATerm t_mod_name;
  ATerm prod, appl;
  ATerm abbrevs;
  ATerm term_open, q_term_open, term_close, q_term_close, term_ws;
  ATerm lit[2],w[4],id,arg;

  if(ATmatchTerm(term,pattern_asfix_term,
                 &lit[0],&w[0],&lit[1],&w[1],&id,&w[2],&arg,&w[3],NULL)) {
    t_mod_name = ATparse("id(\"Sdf2-Normalization\")");
    t_name = ATparse("l(\"normalize\")");
    q_t_name = ATparse("ql(\"normalize\")");
    abbrevs = ATparse("abbreviations([])");
    term_open = ATparse("l(\"(\")");
    q_term_open = ATparse("ql(\"(\")");
    term_close = ATparse("l(\")\")");
    q_term_close = ATparse("ql(\")\")");
    term_ws = ATparse("w(\"\")");     

    prod = AFmakeProd(t_mod_name,
                      ATmakeList(7,q_t_name,term_ws,q_term_open,term_ws,
                                 ATparse("sort(\"SDF\")"),
                                 term_ws,q_term_close),
                      ATparse("sort(\"Grammar\")"),
                      ATparse("no-attrs"));
    appl = AFmakeAppl(prod,
                      ATmakeList(7,t_name,term_ws,term_open,term_ws,
                                 arg,
                                 term_ws,term_close));
    return ATmakeTerm(pattern_asfix_term,
                   ATparse("l(\"term\")"),
                   term_ws,lit[1],term_ws,id,term_ws,
                   appl,term_ws,abbrevs);
  }
  else {
    ATerror("Illegal term %t\n", term);
    return NULL; /* Silence the compiler */
  }                             
}
/*}}}  */
/*{{{  ATerm normalize_and_generate_table(ATerm sdf2) */

ATerm normalize_and_generate_table(ATerm sdf2term)
{
  ATerm pt = NULL, filename, modname, term, reduct, ksdf;

  if (ATmatchTerm(sdf2term, pattern_asfix_term, NULL, NULL,
                 &filename, NULL, &modname, NULL, &term, NULL, NULL)) {

    IF_STATISTICS(PT_Timer()); 

    reduct = innermost(term);
    ksdf = toasfix(reduct, filename, modname); 

    IF_STATISTICS(fprintf(PT_log(), "Normalization to Kernel-Sdf took %.6fs\n", PT_Timer())); 

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
    IF_STATISTICS(fprintf(PT_log(), "Parse table generation took %.6fs\n", PT_Timer())); 
  }
 
  return pt;
}

/*}}}  */
/*{{{  ATerm generate_table(int cid, ATerm sdf, char *name, char *ext) */

ATerm generate_table(int cid, ATerm sdf, char *name, char *ext)
{
  ATerm pt, expsdf, normsdf, packed;

  expsdf = AFexpandTerm(sdf);  

  normsdf = add_name_norm_function(name, expsdf);   

  pt = normalize_and_generate_table(normsdf);
 
  packed = ATBpack(pt);
  packed = ATmake("lazy-unpack(<term>)", ATgetArgument((ATermAppl)packed, 0));
  return ATmake("snd-value(generation-finished(<term>))", packed);
}

/*}}}  */
/*{{{  void usage(void) */

/*
 *     Usage: displays helpful usage information
 */

void usage(void)
{
    ATwarning(
        "Usage: %s [options]\n"
        "Options:\n"
        "\t-b              output terms in BAF format (default)\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-m modulename   name of top module (default Main)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-t              output terms in plaintext format\n"
        "\t-v              verbose mode\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */
/*{{{  void version(void) */

void version(void)
{
    ATwarning("%s v%s\n", myname, myversion);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[]) 
{
  FILE *iofile;

  int cid;
  ATerm bottomOfStack, term, pt, expterm, normterm;
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
  init_patterns();
  AFinitAsFixPatterns();
  c_rehash(INITIAL_TABLE_SIZE);

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

      term = ATreadFromFile(iofile);
      expterm = AFexpandTerm(term);  
  
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
        normterm = add_norm_function(expterm);   
      }
      else {
        normterm = add_name_norm_function(moduleName, expterm);
      }
      pt = normalize_and_generate_table(normterm);

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


