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

/*
   Author: Merijn de Jonge (mdejonge@cwi.nl)
   
   $Id$
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <aterm2.h>
#include <AsFix.h>
#include <AsFix2src.h>
#include <AsFix-access.h>
#include <AsFix-expand.h>
#include <AsFix-init-patterns.h>
#include <deprecated.h>
#include <asc-support.h>

#include "asf-interface.h"

#define INITIAL_TABLE_SIZE 8191

#define DB {fprintf(stderr, "%d-%s\n", __LINE__, __FILE__);}


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

ATerm normalize(ATerm sdf2term, char* topModule )
{
   ATerm filename, modname, term, reduct, ksdf;

   sdf2term = add_name_norm_function( topModule, AFexpandTerm( sdf2term ) );
   
   if(ATmatchTerm(sdf2term, pattern_asfix_term, NULL, NULL,
                 &filename, NULL, &modname, NULL, &term, NULL, NULL)) {

      reduct = innermost(term);
      ksdf = toasfix(reduct, filename, modname); 
   }
   else
      abort();
   return ksdf;
}

void asc_init()
{
   init_patterns();
   c_rehash(INITIAL_TABLE_SIZE);
   register_all();
   resolve_all();
   init_all();
}
