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

static char *name;

ATbool run_verbose;

static char *ptchars;
static int ptsize = 0;

static char myname[] = "parsetablegen";
static char myversion[] = "1.4";

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "bhi:o:tsvV";

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
  if(ATmatchTerm(term, pattern_asfix_term,
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
                        ATparse("prod(id(\"Sdf2-Parse-Table\"),w(\"\"),[l(\"normalize\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SDF\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"), 
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
  ATerm t_name;
  ATerm t_mod_name;
  ATerm prod, appl;
  ATerm abbrevs;
  ATerm term_open, term_close, term_ws;
  ATerm lit[2],w[4],id,arg;

  if(ATmatchTerm(term,pattern_asfix_term,
                 &lit[0],&w[0],&lit[1],&w[1],&id,&w[2],&arg,&w[3],NULL)) {
    t_mod_name = ATparse("id(\"Sdf2-Parse-Table\")");
    t_name = ATparse("l(\"normalize\")");
    abbrevs = ATparse("abbreviations([])");
    term_open = ATparse("l(\"(\")");
    term_close = ATparse("l(\")\")");
    term_ws = ATparse("w(\"\")");     

    prod = AFmakeProd(t_mod_name,
                      ATmakeList(7,t_name,term_ws,term_open,term_ws,
                                 ATparse("sort(\"SDF\")"),
                                 term_ws,term_close),
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
/*{{{  ATerm add_parsetable_function(ATerm term) */

ATerm add_parsetable_function(ATerm term)
{
  ATerm t_name;
  ATerm t_mod_name;
  ATerm prod, appl;
  ATerm abbrevs;
  ATerm term_open, term_close, term_ws;
  ATerm lit[2],w[4],id,arg;

  if(ATmatchTerm(term,pattern_asfix_term,
                 &lit[0],&w[0],&lit[1],&w[1],&id,&w[2],&arg,&w[3],NULL)) {
    t_mod_name = ATparse("id(\"Sdf2-Parse-Table\")");
    t_name = ATparse("l(\"parse-table\")");
    abbrevs = ATparse("abbreviations([])");
    term_open = ATparse("l(\"(\")");
    term_close = ATparse("l(\")\")");
    term_ws = ATparse("w(\"\")");

    prod = AFmakeProd(t_mod_name,
                      ATmakeList(7,t_name,term_ws,term_open,term_ws,
                                 ATparse("sort(\"SDF\")"),
                                 term_ws,term_close),
                      ATparse("sort(\"ATerm\")"),
                      ATparse("no-attrs"));
    appl = AFmakeAppl(prod,
                      ATmakeList(7,t_name,term_ws,term_open,term_ws,
                                 arg,
                                 term_ws,term_close));
    appl = AFmakeAppl(prod,
                      ATmakeList(7,t_name,term_ws,term_open,term_ws,
                                 arg,
                                 term_ws,term_close));
    return ATmake("term(<term>,<term>,<term>,<term>,<term>,<term>," \
                  "<term>,<term>,<term>)",
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

  if(ATmatchTerm(sdf2term, pattern_asfix_term, NULL, NULL,
                 &filename, NULL, &modname, NULL, &term, NULL, NULL)) {
    reduct = innermost(term);

/*
    ATwarning("Reduction finished\n");
*/

    ksdf = toasfix(reduct, filename, modname); 

    if(run_verbose) 
      ATwarning("Normalization finished\n");

    ATwarning("Normalization finished\n");

    /*print_memo_table_sizes();*/

    init_table_gen();
    nr_of_states = 0;

    if(ksdf) 
      pt = generate_parse_table(ksdf);
  }
 
  return pt;
}

/*}}}  */
/*{{{  ATerm generate_parsetable(ATerm sdf2) */

ATerm generate_parsetable(ATerm sdf2term)
{
  ATerm ptable = NULL, filename, modname, term, reduct, aptable;
  int ptneeded;

  if(ATmatchTerm(sdf2term, pattern_asfix_term, NULL, NULL,
                 &filename, NULL, &modname, NULL, &term, NULL, NULL)) {
    reduct = innermost(term);
    aptable = toasfix(reduct, filename, modname);

    ptneeded = AFsourceSize(aptable);
    if(ptneeded > ptsize) {
      if(ptchars)
        free(ptchars);
      if(!(ptchars =  (char *)malloc(ptneeded)))
        ATerror("Generate parse table: Not enough memory\n");
      ptsize = ptneeded;
    }
    ptchars[0] = '\0';
    AFsource(aptable, ptchars);
    
    ptable = ATreadFromString(ptchars);
  }
  else {
    ATwarning("not an asfix term: %t\n", sdf2term);
  }

  return ptable;
}

/*}}}  */
/*{{{  ATerm generate_table(int cid, ATerm sdf, char *name, char *ext) */

ATerm generate_table(int cid, ATerm sdf, char *name, char *ext)
{
  FILE *file;
  char full[1024];
  ATerm pt, expsdf, normsdf;

  expsdf = AFexpandTerm(sdf);  
  normsdf = add_name_norm_function(name, expsdf);   

  pt = normalize_and_generate_table(normsdf);
 
  if(pt) {
    strcpy(full, name);
    strcat(full, ".");
    strcat(full, ext);
    file = fopen(full, "w");
    if (!file)
      ATerror("asource: Could not open %s\n", full);

    ATwriteToBinaryFile(pt,file);

    fclose(file);
  }
  /*return ATmake("snd-value(generation-finished(<str>))",full);*/
  return ATmake("snd-value(generation-finished(<term>))",ATBpack(pt));
}

/*}}}  */
/*{{{  void usage(void)    
 *     Usage: displays helpful usage information
 */

void usage(void)
{
    static char *myargumentsexplained = NULL;

    /*  Represent the argument string in a slightly friendlier manner  */
    if(!myargumentsexplained && *myarguments) {
        int  i, hyphen = 0;
        char *ptr0, *ptr1;

        for(ptr0 = myarguments, i=0; *ptr0; ptr0++)
            if(*ptr0 == ':')
                i++;
        ptr1 = myargumentsexplained =
            (char *) malloc(strlen(myarguments) + 8*i + 2);
        for(ptr0 = myarguments; *ptr0; ptr0++)
            if(!*(ptr0+1) || *(ptr0+1) != ':') {
                if(!hyphen++) {
                    *ptr1++ = ' ';
                    *ptr1++ = '-';
                }
                *ptr1++ = *ptr0;            } else {
                hyphen = 0;
                if(*(ptr1-1) != ' ')
                    *ptr1++ = ' ';
                *ptr1++ = '-'; *ptr1++ = *ptr0++; *ptr1++ = ' ';
                *ptr1++ = 'f'; *ptr1++ = 'i'; *ptr1++ = 'l'; *ptr1++ = 'e';
            }
        *ptr1++ = '\0';
    }

    ATwarning(
        "Usage: %s%s . . .\n"
        "Options:\n"
        "\t-b              output terms in BAF format (default)\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-t              output terms in plaintext format\n"
        "\t-v              verbose mode\n"
        "\t-s              slow mode (use compiled ASF+SDF)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myargumentsexplained, myversion);
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
  ATerm bottomOfStack, term, pt, expterm, normterm, ptterm;
  char *input = "-";
  char *output = "-";
  int bafmode = 1;
  int slowmode = 0;
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
        case 'b':  bafmode = 1;                            break;
        case 't':  bafmode = 0;                            break;
        case 'v':  run_verbose = ATtrue;                   break;
        case 'i':  input=optarg;                           break;
        case 'o':  output=optarg;                          break;
        case 's':  slowmode = 1;                           break;
        case 'V':  version(); proceed = 0;                 break;

        case 'h':
        default:   usage(); proceed = 0;                   break;
      }
    }
    argc -= optind;
    argv += optind;

    if(proceed) {
      if (!strcmp(input, "") || !strcmp(input, "-"))
        iofile = stdin;
      else if (!(iofile = fopen(input, "r")))
        ATerror("%s: cannot open %s\n", myname, input);

      term = ATreadFromFile(iofile);
      expterm = AFexpandTerm(term);  
  
      if(slowmode) {
        if(run_verbose) ATwarning("Parse table generation in slow mode\n");

        ptterm = add_parsetable_function(expterm);
        pt = generate_parsetable(ptterm);
      }
      else {
        if(run_verbose) ATwarning("Parse table generation in fast mode\n");

        normterm = add_norm_function(expterm);   
        pt = normalize_and_generate_table(normterm);
      }

      if (!strcmp(output, "") || !strcmp(output, "-"))
        iofile = stdout;
      else if (!(iofile = fopen(output, "w")))
        ATerror("%s: cannot open %s\n", myname, output);

      if(bafmode)
        ATwriteToBinaryFile(pt, iofile);
      else
        ATwriteToTextFile(pt, iofile);
    }
  }
  return 0;
}

/*}}}  */


