/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands. 

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
/**
  * Library support for rewriting terms.
  *
  * Pieter Olivier
  * Thu Aug 14 11:36:34 MET DST 1997
  */

#ifndef WIN32
	/* These files can not be included in Windows NT*/
	#include <atb-tool.h>
	#include "addeqssyntax.tif.h"
#endif

#include <stdio.h>
#include <stdlib.h>	/* used for exit(0) */
#include <assert.h>
#include <ctype.h>
#include <unistd.h>   

#include <AsFix.h>
#include <AsFix-expand.h>
#include <AsFix-init-patterns.h>
#include <deprecated.h>

#include "asc-support.h"

/*{{{  globals */

static char *name;

ATbool run_verbose;      

static char myname[] = "addeqssyntax";
static char myversion[] = "1.0";  

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "bhi:o:tvV";   

extern ATerm pattern_asfix_term;
extern ATerm pattern_asfix_appl;
extern ATerm pattern_asfix_lex;

ATerm innermost(ATerm t);
ATerm toasfix(ATerm t, ATerm f, ATerm n);
void init_patterns();
void c_rehash(int newsize);

/*}}}  */
/*{{{  ATerm *get_name(int cid) */

ATerm get_name(int cid)
{
  return ATmake("snd-value(name(<str>))", name);
}

/*}}}  */
/*{{{  ATerm add_addeqssyntax_function_standalone(ATerm term) */

ATerm add_addeqssyntax_function_standalone(ATerm term)
{
  ATerm t[8], result = NULL, appl;
  ATerm t_name;
  ATerm abbrevs;
  ATerm term_open, term_comma, term_close, term_ws;

  if(ATmatchTerm(term, pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) { 

    t_name = ATparse("l(\"add-equation-module\")");
    abbrevs = ATparse("abbreviations([])");
    term_open = ATparse("l(\"(\")");
    term_comma = ATparse("l(\",\")");
    term_close = ATparse("l(\")\")");
    term_ws = ATparse("w(\"\")");
    result = ATmakeTerm(pattern_asfix_appl,
                      ATparse("prod(id(\"Add-Eqs-Syntax\"),w(\"\"),[ql(\"add-equation-module\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"SDF\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)"),
                      term_ws,
                      ATmakeList(7,t_name, term_ws,
                                   term_open, term_ws,
                                   appl, term_ws,
                                   term_close)); 
    term = ATmakeTerm(pattern_asfix_term,
                      ATparse("l(\"term\")"),
                      term_ws,
                      ATparse("l(\"X\")"),
                      term_ws,
                      ATparse("id(\"X\")"),
                      term_ws,
                      result,
                      term_ws,
                      ATparse("no-abbreviations"));
    return term;                                       
  }
  else {
    ATerror("not a legal term: %t\n", term);
    return NULL;
  }  
}

/*}}}  */
/*{{{  ATerm add_addeqssyntax_function(char *str, ATerm term) */

ATerm make_name_term(ATerm name)
{
  ATerm result = NULL;
  char *text;

  if(ATmatch(name,"<str>",&text)) {
    result = ATmakeTerm(pattern_asfix_lex,
                        text,
                        ATparse("sort(\"ModuleId\")"));
    result = ATmakeTerm(pattern_asfix_appl,
                        ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)")
,
                        ATparse("w(\"\")"),
                        ATmakeList1(result));
  }
  return result;
}      

ATerm add_addeqssyntax_function(char *str, ATerm term)
{
  ATerm t[8], result = NULL, appl, nameterm, name;
  ATerm t_name;
  ATerm abbrevs;
  ATerm term_open, term_comma, term_close, term_ws;

  name = ATmake("<str>",str);
  if(ATmatchTerm(term, pattern_asfix_term,
                 &t[0], &t[1], &t[2], &t[3], &t[4], &t[5],
                 &appl, &t[6], &t[7])) { 

    t_name = ATparse("l(\"add-equation-module\")");
    abbrevs = ATparse("abbreviations([])");
    term_open = ATparse("l(\"(\")");
    term_comma = ATparse("l(\",\")");
    term_close = ATparse("l(\")\")");
    term_ws = ATparse("w(\"\")");
    nameterm = make_name_term(name);
    result = ATmakeTerm(pattern_asfix_appl,
                      ATparse("prod(id(\"Add-Eqs-Syntax\"),w(\"\"),[ql(\"add-equation-module\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"SDF\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SDF\"),w(\"\"),no-attrs)"),
                      term_ws,
                      ATmakeList(11,t_name, term_ws,
                                    term_open, term_ws,
                                    nameterm, term_ws,
                                    term_comma, term_ws,
                                    appl, term_ws,
                                    term_close)); 
    term = ATmakeTerm(pattern_asfix_term,
                      ATparse("l(\"term\")"),
                      term_ws,
                      ATparse("l(\"X\")"),
                      term_ws,
                      ATparse("id(\"X\")"),
                      term_ws,
                      result,
                      term_ws,
                      ATparse("no-abbreviations"));
    return term;                                       
  }
  else {
    ATerror("not a legal term: %t\n", term);
    return NULL;
  }  
}

/*}}}  */
/*{{{  ATerm add_eqs_syntax(int cid, char *name, ATerm t) */

ATerm add_eqs_syntax(int cid, char *name, ATerm t)
{
  ATerm reduct, et, ft, asfix = NULL, file, modname, trm;

  et = AFexpandTerm(t);
  ft = add_addeqssyntax_function(name, et);

  if(ATmatchTerm(ft, pattern_asfix_term, NULL, NULL,
                 &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
    reduct = innermost(trm);
    asfix = toasfix(reduct, file, modname);
  } else
    ATerror("not an asfix term: %t\n", t);
  return ATmake("snd-value(extended-syntax(<term>))", asfix);
}

/*}}}  */
/*{{{  void rec_terminate(int cid) */

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
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

  ATerm t = NULL, et, trm, reduct, asfix, file, modname;

  char *input = "-";
  char *output = "-"; 
  int cid;
  int c, toolbus_mode = 0, bafmode = 1, proceed = 1;
  ATerm bottomOfStack;
  name = argv[0];

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
      ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
      cid = ATBconnect(NULL, NULL, -1, addeqssyntax_handler);
      ATBeventloop();
    #else
      ATwarning("asource: Toolbus cannot be used in Windows.\n");
    #endif
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'b':  bafmode = 1;                            break;
        case 't':  bafmode = 0;                            break;
        case 'v':  run_verbose = ATtrue;                   break;
        case 'i':  input=optarg;                           break;
        case 'o':  output=optarg;                          break;
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

      t = ATreadFromFile(iofile);
      t = AFexpandTerm(t);

      et = add_addeqssyntax_function_standalone(t);

      if(ATmatchTerm(et, pattern_asfix_term, NULL, NULL,
                     &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
        if(run_verbose) ATwarning("Reducing ...\n");
        reduct = innermost(trm);
        if(run_verbose) ATwarning("Reducing finished.\n");
        asfix = toasfix(reduct, file, modname);

        if (!strcmp(output, "") || !strcmp(output, "-"))
          iofile = stdout;
        else if (!(iofile = fopen(output, "w")))
          ATerror("%s: cannot open %s\n", myname, output);

        if(bafmode)
          ATwriteToBinaryFile(asfix, iofile);
        else
          ATwriteToTextFile(asfix, iofile); 
      }
      else { /* Alex added {} after 'else' for readability */
        ATwarning("not an asfix term: %t\n", t);
      }
    }
  }
  return 0;
}

/*}}}  */
