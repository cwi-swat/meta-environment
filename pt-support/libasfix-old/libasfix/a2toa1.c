/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

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
/*  $Id$  */

#include <stdlib.h>
#include <string.h>

/* Some defines that are needed for pretty printing AsFix2 productions */
#include "buffer.h"
#define AF2PRODTOTEXT_BUFFER_SIZE 100
#define MAX_SYMBOL_INTEGER_SIZE   1000
#define MAX_SYMBOL_CHARACTER_SIZE 1000

#include <aterm2.h>
#include "deprecated.h"

#ifndef WIN32  /* MS-DOS doesn't do toolbus...  */
#include <atb-tool.h>
#if 0
#include "a2toa1.tif.h"
#endif
#endif


/* Function prototypes (only the badly needed ones) */

ATerm trans_term(ATerm);                    /* Standalone API */

ATerm internal_trans(ATerm, ATbool interpret_cons);
ATerm internal_trans_top(ATerm, ATbool, ATbool);
ATerm trm_yield(ATerm );

/*  patterns  */

/* Definition of AsFix2 patterns and their initialization */

ATerm asfix2_empty_iter = NULL;
ATerm asfix2_empty_iter_star = NULL;
ATerm asfix2_singleton_iter = NULL;
ATerm asfix2_singleton_iter_star = NULL;
ATerm asfix2_cons_iter = NULL;
ATerm asfix2_cons_iterstar = NULL;
ATerm asfix2_cons_iter_iterstar = NULL;
ATerm asfix2_cons_iterstar_iter = NULL;
ATerm asfix2_empty_iter_sep = NULL;
ATerm asfix2_empty_iter_star_sep = NULL;
ATerm asfix2_singleton_iter_sep = NULL;
ATerm asfix2_singleton_iter_star_sep = NULL;
ATerm asfix2_cons_iter_sep = NULL;
ATerm asfix2_cons_iterstar_sep = NULL;
ATerm asfix2_cons_iter_iterstar_sep = NULL;
ATerm asfix2_cons_iterstar_iter_sep = NULL;
ATerm asfix2_cf_pattern = NULL;
ATerm asfix2_lex_pattern = NULL;
ATerm asfix2_opt_layout_pattern = NULL;
ATerm asfix2_iter_star_sep_pattern = NULL;
ATerm asfix2_iter_sep_pattern = NULL;
ATerm asfix2_iter_star_pattern = NULL;
ATerm asfix2_iter_pattern = NULL;
ATerm asfix2_lit_pattern = NULL;
ATerm asfix2_prod_pattern = NULL;
ATerm asfix2_attrs_pattern = NULL;
ATerm asfix2_cons_pattern = NULL;
ATerm asfix2_aterm_cons_pattern = NULL;
ATerm asfix2_atr_pattern = NULL;
ATerm asfix2_id_pattern = NULL;
ATerm asfix2_appl_term_list_pattern = NULL;
ATerm asfix2_list_pattern = NULL;
ATerm asfix2_parsetree_pattern = NULL;
ATerm asfix2_amb_pattern = NULL;
ATerm asfix2_appl_lit_pattern = NULL;
ATerm asfix2_appl_layout_pattern = NULL;
ATerm asfix2_appl_optlayout_pattern = NULL;
ATerm asfix2_appl_lexical_pattern = NULL;
ATerm asfix2_appl_var_pattern = NULL;
ATerm asfix2_appl_starlist_sep_pattern = NULL;
ATerm asfix2_appl_pluslist_sep_pattern = NULL;
ATerm asfix2_appl_starlist_pattern = NULL;
ATerm asfix2_appl_pluslist_pattern = NULL;
ATerm asfix1_iter_pattern = NULL;
ATerm asfix1_itersep_pattern = NULL;
ATerm asfix1_iter_star_pattern = NULL;
ATerm asfix1_iter_plus_pattern = NULL;
ATerm asfix1_itersep_star_pattern = NULL;
ATerm asfix1_itersep_plus_pattern = NULL;

extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_lexterm;
extern ATerm pattern_asfix_varterm;
extern ATerm pattern_asfix_ws_term;
extern ATerm pattern_asfix_appl;
extern ATerm pattern_asfix_ews;
extern ATerm pattern_asfix_ql;
extern ATerm pattern_asfix_list;

/*  pattern initializations  */

void AFinitAsFixPatterns();
void init_asfix2_patterns();

void init_a2toa1_patterns(void)
{
  static ATbool patterns_initialized = ATfalse;

  if(patterns_initialized)
    return;
  patterns_initialized = ATtrue;

  AFinitAsFixPatterns();
  init_asfix2_patterns();
}

void init_asfix2_patterns()
{
  ATprotect(&asfix2_empty_iter);
  ATprotect(&asfix2_empty_iter_star);
  ATprotect(&asfix2_singleton_iter);
  ATprotect(&asfix2_singleton_iter_star);
  ATprotect(&asfix2_cons_iter);
  ATprotect(&asfix2_cons_iterstar);
  ATprotect(&asfix2_cons_iterstar_iter);
  ATprotect(&asfix2_cons_iter_iterstar);
  ATprotect(&asfix2_empty_iter_sep);
  ATprotect(&asfix2_empty_iter_star_sep);
  ATprotect(&asfix2_singleton_iter_sep);
  ATprotect(&asfix2_singleton_iter_star_sep);
  ATprotect(&asfix2_cons_iter_sep);
  ATprotect(&asfix2_cons_iterstar_sep);
  ATprotect(&asfix2_cons_iter_iterstar_sep);
  ATprotect(&asfix2_cons_iterstar_iter_sep);
  ATprotect(&asfix2_cf_pattern);
  ATprotect(&asfix2_lex_pattern);
  ATprotect(&asfix2_opt_layout_pattern);
  ATprotect(&asfix2_iter_star_sep_pattern);
  ATprotect(&asfix2_iter_sep_pattern);
  ATprotect(&asfix2_iter_star_pattern);
  ATprotect(&asfix2_iter_pattern);
  ATprotect(&asfix2_lit_pattern);
  ATprotect(&asfix2_prod_pattern);
  ATprotect(&asfix2_attrs_pattern);
  ATprotect(&asfix2_cons_pattern);
  ATprotect(&asfix2_aterm_cons_pattern);
  ATprotect(&asfix2_atr_pattern);
  ATprotect(&asfix2_id_pattern);
  ATprotect(&asfix2_appl_term_list_pattern);
  ATprotect(&asfix2_list_pattern);
  ATprotect(&asfix2_parsetree_pattern);
  ATprotect(&asfix2_amb_pattern);
  ATprotect(&asfix2_appl_lit_pattern);
  ATprotect(&asfix2_appl_layout_pattern);
  ATprotect(&asfix2_appl_optlayout_pattern);
  ATprotect(&asfix2_appl_lexical_pattern);
  ATprotect(&asfix2_appl_var_pattern);
  ATprotect(&asfix2_appl_starlist_sep_pattern);
  ATprotect(&asfix2_appl_pluslist_sep_pattern);
  ATprotect(&asfix2_appl_starlist_pattern);
  ATprotect(&asfix2_appl_pluslist_pattern);
  ATprotect(&asfix1_iter_pattern);
  ATprotect(&asfix1_itersep_pattern);
  ATprotect(&asfix1_iter_star_pattern);
  ATprotect(&asfix1_iter_plus_pattern);
  ATprotect(&asfix1_itersep_star_pattern);
  ATprotect(&asfix1_itersep_plus_pattern);

  asfix2_empty_iter =
    ATparse("appl(prod([],cf(iter(sort(<term>))),no-attrs),[])");
  asfix2_empty_iter_star =
    ATparse("appl(prod([],cf(iter-star(sort(<term>))),no-attrs),[])");
  asfix2_singleton_iter =
    ATparse("appl(prod([cf(<term>)],cf(iter(sort(<term>))),no-attrs)," \
            "[<list>])");
  asfix2_singleton_iter_star =
    ATparse("appl(prod([cf(<term>)],cf(iter-star(sort(<term>))),no-attrs)," \
            "[<list>])");
  asfix2_cons_iter =
    ATparse("appl(prod([cf(iter(<term>)),cf(opt(layout)),cf(iter(<term>))]," \
            "cf(iter(<term>)),<term>),[<list>])");
  asfix2_cons_iterstar =
    ATparse("appl(prod([cf(iter-star(<term>)),cf(opt(layout))," \
            "cf(iter-star(<term>))],cf(iter-star(<term>)),<term>),[<list>])");
  asfix2_cons_iterstar_iter =
    ATparse("appl(prod([cf(iter-star(<term>)),cf(opt(layout)),cf(iter(<term>))]," \
            "cf(iter(<term>)),<term>),[<list>])");
  asfix2_cons_iter_iterstar =
    ATparse("appl(prod([cf(iter(<term>)),cf(opt(layout)),cf(iter-star(<term>))]," \
            "cf(iter(<term>)),<term>),[<list>])");

  asfix2_empty_iter_sep =
    ATparse("appl(prod([],cf(iter-sep(sort(<term>),<term>)),no-attrs),[])");
  asfix2_empty_iter_star_sep =
    ATparse("appl(prod([],cf(iter-star-sep(sort(<term>),<term>)),no-attrs),[])");
  asfix2_singleton_iter_sep =
    ATparse("appl(prod([cf(<term>)],cf(iter-sep(sort(<term>),<term>)),no-attrs)," \
            "[<list>])");
  asfix2_singleton_iter_star_sep =
    ATparse("appl(prod([cf(<term>)],cf(iter-star-sep(sort(<term>),<term>)),no-attrs)," \
            "[<list>])");
  asfix2_cons_iter_sep =
    ATparse("appl(prod([cf(iter-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>),[<list>])");
  asfix2_cons_iterstar_sep =
    ATparse("appl(prod([cf(iter-star-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-star-sep(<list>))]," \
            "cf(iter-star-sep(<list>)),<term>),[<list>])");
  asfix2_cons_iter_iterstar_sep =
    ATparse("appl(prod([cf(iter-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-star-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>),[<list>])");
  asfix2_cons_iterstar_iter_sep =
    ATparse("appl(prod([cf(iter-star-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>),[<list>])");
  asfix2_cf_pattern = ATparse("cf(<term>)");
  asfix2_lex_pattern = ATparse("lex(<term>)");
  asfix2_opt_layout_pattern = ATparse("opt(layout)");
  asfix2_iter_star_sep_pattern =
    ATparse("iter-star-sep(sort(<str>),lit(<str>))");
  asfix2_iter_sep_pattern =
    ATparse("iter-sep(sort(<str>),lit(<str>))");
  asfix2_iter_star_pattern =
    ATparse("iter-star(sort(<str>)))");
  asfix2_iter_pattern =
    ATparse("iter(sort(<str>))");
  asfix2_lit_pattern =
    ATparse("lit(<str>)");
  asfix2_prod_pattern =
    ATparse("prod(<term>,<term>,<term>)");
  asfix2_attrs_pattern =
    ATparse("attrs([<list>])");
  asfix2_cons_pattern =
    ATparse("cons(<str>)");
  asfix2_aterm_cons_pattern =
    ATparse("aterm(cons(<str>))");
  asfix2_atr_pattern =
    ATparse("atr(<str>)");
  asfix2_id_pattern =
    ATparse("id(<str>)");
  asfix2_appl_term_list_pattern =
    ATparse("appl(<term>,[<list>])");
  asfix2_list_pattern =
    ATparse("[<list>]");
  asfix2_parsetree_pattern =
    ATparse("parsetree(<term>,<term>)");
  asfix2_amb_pattern =
    ATparse("amb([<list>])");
  asfix2_appl_lit_pattern =
    ATparse("appl(prod([<list>],lit(<str>),no-attrs),[<list>])");
  asfix2_appl_layout_pattern =
    ATparse("appl(prod([<list>],cf(layout),no-attrs),[<list>])");
  asfix2_appl_optlayout_pattern =
    ATparse("appl(prod([<list>],cf(opt(layout)),no-attrs),[<list>])");
  asfix2_appl_lexical_pattern =
    ATparse("appl(prod([lex(<term>)],cf(<term>),<term>),[<list>])");
  asfix2_appl_var_pattern =
    ATparse("appl(prod([varsym(<term>)],cf(<term>),<term>),[<list>])");
  asfix2_appl_starlist_sep_pattern =
    ATparse("appl(prod([<list>],cf(iter-star-sep(<term>,lit(<str>)))," \
            "<term>),[<list>])");
  asfix2_appl_pluslist_sep_pattern =
    ATparse("appl(prod([<list>],cf(iter-sep(<term>,lit(<str>)))," \
            "<term>),[<list>])");
  asfix2_appl_starlist_pattern =
    ATparse("appl(prod([<list>],cf(iter-star(<term>)),<term>),[<list>])");
  asfix2_appl_pluslist_pattern =
    ATparse("appl(prod([<list>],cf(iter(<term>)),<term>),[<list>])");
  asfix1_iter_pattern =
    ATparse("iter(<term>,w(\"\"),l(\"*\"))");
  asfix1_itersep_pattern =
    ATparse("iter-sep(l(\"{\"),w(\"\"),<term>,w(\"\"),ql(<str>)," \
            "w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))");
  asfix1_iter_star_pattern =
    ATparse("iter(sort(<str>),w(\"\"),l(\"*\"))");
  asfix1_iter_plus_pattern =
    ATparse("iter(sort(<str>),w(\"\"),l(\"+\"))");
  asfix1_itersep_star_pattern =
    ATparse("iter-sep(l(\"{\"),w(\"\"),sort(<str>),w(\"\"),ql(<str>)," \
            "w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))");
  asfix1_itersep_plus_pattern =
    ATparse("iter-sep(l(\"{\"),w(\"\"),sort(<str>),w(\"\"),ql(<str>)," \
            "w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))");
}


void AF2SymbolToText(buffer *text, ATerm symbol)
{
	char *name;
	ATerm arg, arg2;
	ATermList args;
	int c1, c2;

	if (ATmatch(symbol, "layout")) {
    AddStringToBuffer(text, "LAYOUT");
  } else if (ATmatch(symbol, "sort(<str>)", &name)) {
    AddStringToBuffer(text, name);
  } else if (ATmatch(symbol, "lit(<str>)", &name)) {
		AddStringToBuffer(text,"\\\"");
    AddStringToBuffer(text,name);
		AddStringToBuffer(text,"\\\"");
  } else if (ATmatch(symbol, "lex(<term>)", &arg)) {
    AF2SymbolToText(text, arg);
  } else if (ATmatch(symbol, "cf(<term>)", &arg)) {
    AF2SymbolToText(text, arg);
  } else if (ATmatch(symbol, "iter-star(<term>)", &arg)) {
    AF2SymbolToText(text, arg);
    AddStringToBuffer(text, "*");
  } else if (ATmatch(symbol, "iter(<term>)", &arg)) {
    AF2SymbolToText(text, arg);
    AddStringToBuffer(text, "+");
  } else if (ATmatch(symbol, "iter-sep(<term>,<term>)", &arg, &arg2)) {
    AddStringToBuffer(text, "{");
    AF2SymbolToText(text, arg);
    AddStringToBuffer(text, " ");
    AF2SymbolToText(text, arg2);
    AddStringToBuffer(text, "}+");
  } else if (ATmatch(symbol, "iter-star-sep(<term>,<term>)", &arg, &arg2)) {
    AddStringToBuffer(text, "{");
    AF2SymbolToText(text, arg);
    AddStringToBuffer(text, " ");
    AF2SymbolToText(text, arg2);
    AddStringToBuffer(text, "}*");
  } else if (ATmatch(symbol, "iter-n(<term>, <int>)", &arg, &c1)) {
		char number[MAX_SYMBOL_INTEGER_SIZE];  
    AF2SymbolToText(text, arg);
    sprintf(number, "%d", c1);
		AddStringToBuffer(text, number);
		AddStringToBuffer(text,"+");
	} else if (ATmatch(symbol, "iter-sep-n(<term>,<term>,<int>)", &arg, &arg2, &c1)) {
		char number[MAX_SYMBOL_INTEGER_SIZE];
		AddStringToBuffer(text, "{");
    AF2SymbolToText(text, arg);
    AddStringToBuffer(text, " ");
    AF2SymbolToText(text, arg2);
		sprintf(number, "%d", c1);
    AddStringToBuffer(text,"}");
		AddCharToBuffer(text,c1);
		AddStringToBuffer(text,"+");
  } else if (ATmatch(symbol, "seq([<list>])", &args)) {
    AddStringToBuffer(text, "(");
    for (;!ATisEmpty(args);args = ATgetNext(args)) {
      arg = ATgetFirst(args);
      AF2SymbolToText(text, arg);
      if (args) {
				AddStringToBuffer(text, " ");
			}
    }
    AddStringToBuffer(text, ")");
  } else if (ATmatch(symbol, "opt(<term>)", &arg)) {
    AF2SymbolToText(text, arg);
    AddStringToBuffer(text, "?");
  } else if (ATmatch(symbol, "alt(<term>,<term>)", &arg, &arg2)) {
    AF2SymbolToText(text, arg);
    AddStringToBuffer(text, "|");
    AF2SymbolToText(text, arg2);
  } else if (ATmatch(symbol, "char-class([<list>])", &args)) {
		AddStringToBuffer(text, "[");
    while (!ATisEmpty(args)) {
      char letter[MAX_SYMBOL_CHARACTER_SIZE];
      arg = ATgetFirst(args);
      args = ATgetNext(args);
      if (ATmatch(arg, "range(<int>,<int>)", &c1, &c2)) {
				if(isprint(c1)) {
					sprintf(letter,"%c", c1);
					AddStringToBuffer(text,letter);
				} else {
					sprintf(letter,"\\\\%d", c1);
					AddStringToBuffer(text,letter);
        }
				AddStringToBuffer(text,"-");

        if(isprint(c2)) {
					sprintf(letter,"%c", c2);
					AddStringToBuffer(text,letter);
				} else {
					sprintf(letter,"\\\\%d", c2);
					AddStringToBuffer(text,letter);
        }
			} else if (ATmatch(arg, "<int>", &c1)) {
				if(isprint(c1)) {
					sprintf(letter,"%c", c1);
					AddStringToBuffer(text,letter);
				} else {
					sprintf(letter,"\\\\%d", c1);
					AddStringToBuffer(text,letter);
        }
			}
    }
    AddStringToBuffer(text, "]");
	} else if (ATmatch(symbol, "varsym(<term>)", &arg)) {
    AF2SymbolToText(text, arg);
  } else {
		ATwarning("Unknown symbol type in AF2SymbolToText\n");
    return;
	}
	return;
}

void AF2ProdAttrsToText(buffer *text, ATerm attrs)
{
	ATermList list;
	char *str;

	if(ATmatch(attrs, "no-attrs")) {
		return;
	} else {
		if(ATmatchTerm(attrs, asfix2_attrs_pattern, &list)) {
			AddStringToBuffer(text," { ");
		
			for(; !ATisEmpty(list); list = ATgetNext(list)) {
				ATerm first = ATgetFirst(list);
				
				
				if(ATmatchTerm(first, asfix2_cons_pattern, &str)) {
					AddStringToBuffer(text,"cons(");
					AddStringToBuffer(text, str);
					AddStringToBuffer(text,")");
				} else if(ATmatchTerm(first, asfix2_aterm_cons_pattern, &str)) {
					AddStringToBuffer(text,"aterm(cons(");
					AddStringToBuffer(text, str);
					AddStringToBuffer(text,"))");
				} else if(ATmatchTerm(first, asfix2_atr_pattern, &str)) {
					AddStringToBuffer(text, str);
				} else if(ATmatchTerm(first, asfix2_id_pattern, &str)) {
					AddStringToBuffer(text,"id(");
					AddStringToBuffer(text, str);
					AddStringToBuffer(text,")");
 				} else if(ATmatch(first, "traverse")) {
					AddStringToBuffer(text, "traverse");
				}
				
				AddStringToBuffer(text," ");
				
			}

			AddStringToBuffer(text,"} ");
		}
	}
	return;
}

void AF2ProdArgsToText(buffer *text, ATermList args)
{
	ATerm sortname, sepname, litname;
	char *sep, *lit, *sort;

	for(; !ATisEmpty(args); args = ATgetNext(args)) {
		AF2SymbolToText(text, ATgetFirst(args));
    if(!ATisEmpty(ATgetNext(args))) {
			AddStringToBuffer(text," ");
    }
	}

	return;
}

/* ATerm AF2ProdToText(ATerm t)
 *
 * Prettyprints an asfix2 prod to an ATerm <str>
 */
ATerm AF2ProdToText(ATerm t) 
{
	buffer *text;
	ATerm args = NULL;
	ATerm result = NULL;
	ATerm attrs = NULL;
	ATerm str;

	init_a2toa1_patterns();

	text = CreateBuffer(AF2PRODTOTEXT_BUFFER_SIZE, /* initial buffer size       */ 
											AF2PRODTOTEXT_BUFFER_SIZE, /* step size when reallocing */
											sizeof(char));             /* size of atomic elements   */
	
	if(ATmatchTerm(t, asfix2_prod_pattern, &args, &result, &attrs)) {
		AF2ProdArgsToText(text, (ATermList) args);
		AddStringToBuffer(text, " -> ");
		AF2SymbolToText(text, result);
		AF2ProdAttrsToText(text, attrs);
	}
	
	AddCharToBuffer(text,'\0'); /* adding end of string */
	str = ATmake("<str>", GetBufferContent(text));
	DeleteBuffer(text);

	return str;
}

/*   ATermList trans_args(ATermList tl)  */

ATermList trans_args(ATermList tl, ATbool interpret_cons)
{
  if (ATisEmpty(tl))
    return tl;
  else
    return ATinsert(trans_args(ATgetNext(tl), interpret_cons),
                    internal_trans(ATgetFirst(tl), interpret_cons));
}

/*  ATermList trans_list(ATermList l)  */

ATermList trans_list(ATermList l, ATbool interpret_cons)
{
  ATerm         asfix1_iter, iter, sort, arg[3], t = NULL;
  ATermList     args, list;
  int           len = ATgetLength(l);

  switch(len) {
    case 0:
      return ATempty;
      break;
    case 1:
      t = ATgetFirst(l);
      break;
    default:
      ATerror("trans_list: unexpected list length %d, term %t\n", len, l);
      break;
  }

  /* Empty list */
  if(ATmatchTerm(t, asfix2_empty_iter, NULL)
     ||
     ATmatchTerm(t, asfix2_empty_iter_star, NULL)) {
    return ATempty;
  }
  /* Singleton */
  else if(ATmatchTerm(t, asfix2_singleton_iter, NULL, NULL, &list)) {
    arg[0] = ATgetFirst(list);
    return ATmakeList1(internal_trans(arg[0], interpret_cons));
  }
  else if(ATmatchTerm(t, asfix2_singleton_iter_star, NULL, NULL, &list)) {
    arg[0] = ATgetFirst(list);
    return trans_list(ATmakeList1(arg[0]), interpret_cons);
  }
  /* We are dealing with a list variable */
  else if (ATmatchTerm(t, asfix2_appl_var_pattern,
                       NULL, &iter, NULL, &args)) {
    if (ATmatchTerm(iter, asfix2_iter_pattern, &sort)) {
      asfix1_iter = ATmakeTerm(asfix1_iter_plus_pattern,sort);
      return ATmakeList1(ATmakeTerm(pattern_asfix_varterm,
                                    trm_yield((ATerm) args), asfix1_iter));
    }
    else if (ATmatchTerm(iter, asfix2_iter_star_pattern, &sort)) {
      asfix1_iter = ATmakeTerm(asfix1_iter_star_pattern,sort);
      return ATmakeList1(ATmakeTerm(pattern_asfix_varterm,
                                    trm_yield((ATerm) args), asfix1_iter));
    }
    else {
      ATerror("trans_list: funny iter: %t\n\n", iter);
      return(NULL);        /* Silence the compiler */
    }
  }
  /* Cons(List, Elem) */
  else if(ATmatchTerm(t, asfix2_cons_iter, NULL, NULL, NULL, NULL, &list) ||
          ATmatchTerm(t, asfix2_cons_iterstar,
                      NULL, NULL, NULL, NULL, &list) ||
          ATmatchTerm(t, asfix2_cons_iterstar_iter,
                      NULL, NULL, NULL, NULL, &list) ||
          ATmatchTerm(t, asfix2_cons_iter_iterstar,
                      NULL, NULL, NULL, NULL, &list)) {
    arg[0] = ATgetFirst(list);
    arg[1] = ATelementAt(list,1);
    arg[2] = ATelementAt(list,2);
    return ATconcat(trans_list(ATmakeList1(arg[0]), interpret_cons),
                    ATconcat(ATmakeList1(internal_trans(arg[1], interpret_cons)),
                             trans_list(ATmakeList1(arg[2]), interpret_cons)));
  }
  else {
    ATerror("trans_list: funny term: %t\n\n", t);
    return(NULL);        /* Silence the compiler */
  }
}

/*  ATermList trans_sep_list(ATermList l)  */

ATermList trans_sep_list(ATermList l, ATbool interpret_cons)
{
  char*         sep;
  ATerm         asfix1_iter, iter, sort, arg[5], t = NULL;
  ATermList     args, list;
  int           len = ATgetLength(l);

  switch(len) {
    case 0:
      return ATempty;
      break;
    case 1:
      t = ATgetFirst(l);
      break;
    default:
      ATerror("trans_sep_list: unexpected list length %d, term %t\n", len, l);
      break;
  }

  /* Empty list */
  if(ATmatchTerm(t, asfix2_empty_iter_sep, NULL, NULL)
     ||
     ATmatchTerm(t, asfix2_empty_iter_star_sep, NULL, NULL)) {
    return ATempty;
  }
  /* singleton */
  else if(ATmatchTerm(t, asfix2_singleton_iter_sep,
                      NULL, NULL, NULL, &list)) {
    arg[0] = ATgetFirst(list);
    return ATmakeList1(internal_trans(arg[0], interpret_cons));
  }
  else if(ATmatchTerm(t, asfix2_singleton_iter_star_sep,
                      NULL, NULL, NULL, &list)) {
    arg[0] = ATgetFirst(list);
    return trans_sep_list(ATmakeList1(arg[0]), interpret_cons);
  }
  /* We are dealing with a list variable */
  else if (ATmatchTerm(t, asfix2_appl_var_pattern,
                       NULL, &iter, NULL, &args)) {
    if (ATmatchTerm(iter, asfix2_iter_sep_pattern, &sort, &sep)) {
      asfix1_iter = ATmakeTerm(asfix1_itersep_plus_pattern,sort,sep);
      return ATmakeList1(ATmakeTerm(pattern_asfix_varterm,
                                    trm_yield((ATerm) args), asfix1_iter));
    }
    else if (ATmatchTerm(iter, asfix2_iter_star_sep_pattern, &sort, &sep)) {
      asfix1_iter = ATmakeTerm(asfix1_itersep_star_pattern,sort,sep);
      return ATmakeList1(ATmakeTerm(pattern_asfix_varterm,
                                    trm_yield((ATerm) args), asfix1_iter));
    }
    else {
      ATerror("trans_list: funny iter: %t\n\n", iter);
      return(NULL);        /* Silence the compiler */
    }
  }
  else if(ATmatchTerm(t, asfix2_cons_iter_sep,
                      NULL, NULL, NULL, NULL, NULL, &list) ||
          ATmatchTerm(t, asfix2_cons_iterstar_sep,
                      NULL, NULL, NULL, NULL, NULL, &list) ||
          ATmatchTerm(t, asfix2_cons_iter_iterstar_sep,
                      NULL, NULL, NULL, NULL, NULL, &list) ||
          ATmatchTerm(t, asfix2_cons_iterstar_iter_sep,
                      NULL, NULL, NULL, NULL, NULL, &list)) {
    arg[0] = ATgetFirst(list);
    arg[1] = ATelementAt(list,1);
    arg[2] = ATelementAt(list,2);
    arg[3] = ATelementAt(list,3);
    arg[4] = ATelementAt(list,4);
    return ATconcat(trans_sep_list(ATmakeList1(arg[0]), interpret_cons),
                    ATconcat(ATmakeList3(internal_trans(arg[1], interpret_cons),
                                         ATmake("sep(<term>)",
                                                trm_yield(arg[2])),
                                         internal_trans(arg[3], interpret_cons)),
                             trans_sep_list(ATmakeList1(arg[4]), interpret_cons)));
  }
  else if(ATmatch(t, "appl(prod([cf(iter-sep(<term>)),cf(layout),<term>,"
                  "cf(layout),cf(seq(<term>))],"
                  "cf(iter-sep(<term>)),no-attrs),"
                  "[<list>])",
                  NULL, NULL, NULL, NULL, NULL)
          ||
          ATmatch(t, "appl(prod([cf(seq(<term>))],"
                  "cf(iter-sep(seq(<term>),<term>)),no-attrs),"
                  "[<list>])",
                  NULL, NULL, NULL, NULL)) {
    ATerror("Error: seq is SDF2 specific, can't convert to AsFix1\n");
    return(NULL);                /* Hello compiler!  Having fun?        */
  }
  else {
    ATerror("trans_sep_list: funny term: %t\n\n", t);
    return(NULL);                /* Hello compiler!  Having fun?        */
  }
}

/*  ATerm trans_cf_lex(ATerm t)  */

ATerm trans_cf_lex(ATerm t)
{
  if(!ATmatchTerm(t,asfix2_cf_pattern,&t)) /* If either of these match... */
    ATmatchTerm(t,asfix2_lex_pattern,&t); /* ...the match is returned    */
  return t;                                /* Otherwise: the original     */
}

/*  char *escape_str(char *s)  */

char *escape_str(char *s)
{
  static size_t dstsize = 0;
  static char   *dst = NULL;
  char          *d;
  size_t        len, backslashes = 0;

  if(s == NULL)
    return NULL;

  /* Count the number of backslashes to be escaped  */
  for(d = s; *d; d++) {
    switch(*d) {
      case '\t':
      case '\n':
      case '\\':
        backslashes++;
        break;
      default:
        break;
    }
  }

  if(backslashes == 0)
    return s;
  
  /*
   Determine new len, and allocate a buffer to accomodate it;
   reuse the existing buffer whenever sufficiently large
   */
  len = strlen(s) + backslashes;
  if(len > dstsize) {
    if(dst != NULL)
      free(dst);
    dst = (char *) malloc(len);
    dstsize = len;
  }

  for(d = dst; *s; s++) {
    switch(*s) {
      case '\t':
        *d++ = '\\';
        *d++ = 't';
        break;
      case '\n':
        *d++ = '\\';
        *d++ = 'n';
        break;
      case '\\':
        *d++ = '\\';
        *d++ = '\\';
        break;
      default:
        *d++ = *s;
        break;
    }
  }
  *d = '\0';
  return(dst);
}

/*  ATermList trans_prod_args(ATermList args)  */

ATermList trans_prod_args(ATermList args)
{
  /*  Only happens when doing an SDF2 term. Removes cf and lex afuns.  */
  ATerm t;
  ATermList res = ATempty;
  char *sortname, *sepname, *litname;

  /*ATfprintf(stderr,"args: %t\n",args);*/

  while (!ATisEmpty(args)) {
    t = ATgetFirst(args);
    args = ATgetNext(args);

    t = trans_cf_lex(t);
    if (ATmatchTerm(t, asfix2_opt_layout_pattern))
      t = pattern_asfix_ews;
    else if (ATmatchTerm(t,asfix2_iter_star_sep_pattern,&sortname,&sepname)) {
      t = ATmakeTerm(asfix1_itersep_star_pattern, sortname,
                     escape_str(sepname));
    }
    else if (ATmatchTerm(t,asfix2_iter_sep_pattern,&sortname,&sepname)) {
      t = ATmakeTerm(asfix1_itersep_plus_pattern, sortname,
                     escape_str(sepname));
    }
    else if (ATmatchTerm(t,asfix2_iter_star_pattern,&sortname)) {
      t = ATmakeTerm(asfix1_iter_star_pattern, sortname);
    }
    else if (ATmatchTerm(t,asfix2_iter_pattern,&sortname)) {
      t = ATmakeTerm(asfix1_iter_plus_pattern, sortname);
    }
    else if (ATmatchTerm(t,asfix2_lit_pattern, &litname)) {
      t = ATmakeTerm(pattern_asfix_ql, escape_str(litname));
    }
    res = ATappend(res,t);
  }
  return res;
}

static ATerm cons_str(char *str)
{
  char *buf1, *buf2;
  ATerm cons;

  buf1  = escape_str(str);
  buf2 = malloc(strlen(buf1) + strlen("cons()") + 1);
  sprintf(buf2, "cons(%s)", buf1);
  cons = ATmakeTerm(pattern_asfix_ql, buf2);
  free(buf2);
  return cons;
}

/*  ATerm trans_prod(ATerm t)  */

ATerm trans_prod(ATerm t, ATbool interpret_cons)
{
  ATerm         res, attr, save_attr, result, id = NULL, res_attr = NULL;
  ATermList     attrs, args;
  char          *lit;

  if(!ATmatchTerm(t, asfix2_prod_pattern, &args, &res, &attr))
    ATerror("trans_prod: %t not a production\n", t);

  save_attr = attr;
  if(ATmatchTerm(attr, asfix2_attrs_pattern, &attrs)) {
    if(interpret_cons) {
      while(!ATisEmpty(attrs)) {
        attr = ATgetFirst(attrs);
        attrs = ATgetNext(attrs);
        if(ATmatchTerm(attr, asfix2_cons_pattern, &lit))
          return ATmake("<str>",lit);
        else if(ATmatchTerm(attr, asfix2_aterm_cons_pattern, &lit))
          return ATmake("<str>",lit);
      }
    }
  }

  /*
   If we were doing an SDF1 grammar, we have returned by now, so
   we're doing an SDF2 grammar

   We can  only have  one `atr'  attribute (left,  right, assoc, ...) in asfix1.2,
   so we'll just take the first one of these.

   For  proper modularization  however,  `id(Name)' can  (must?)
   also appear  in attrs, and  must be handled properly.   So we
   iterate over all terms in  the `attrs' list, either selecting
   or discarding them.
   */

  if(ATmatchTerm(save_attr, asfix2_attrs_pattern, &attrs)) {
    while(!ATisEmpty(attrs)) {
      attr = ATgetFirst(attrs);
      attrs = ATgetNext(attrs);

      if(ATmatchTerm(attr, asfix2_cons_pattern, &lit)
         || ATmatchTerm(attr, asfix2_aterm_cons_pattern, &lit)) {
        ATerm cons;
        cons = cons_str(lit);
        if(!res_attr) {
          res_attr = (ATerm) ATmakeList1(cons);
        } else {
          res_attr = (ATerm) ATconcat(
                                      (ATermList) res_attr,
                                      (ATermList) ATmake("[w(\"\"),sep(\",\"),w(\"\"),"
                                                         "<term>]", cons));
        }
      } else if(ATmatchTerm(attr, asfix2_atr_pattern, &lit)) {
        /* a common attribute (left, right, ...) */
        if(!res_attr) {     /* first attr */
          res_attr = (ATerm) ATmakeList1(ATmake("l(<str>)",lit));
        } else {            /* consecutive atts */
          res_attr = (ATerm) ATconcat(
                                      (ATermList) res_attr,
                                      (ATermList) ATmake("[w(\"\"),sep(\",\"),w(\"\"),"
                                                         "l(<str>)]", lit));
        }
      }
      else if(ATmatchTerm(attr, asfix2_id_pattern, NULL)) {
        /* the ModuleName identifier */
        id = attr;
      }
      else if(ATmatchTerm(attr,ATparse("traverse"))) {
        if(!res_attr) { /* first attr */
           res_attr = (ATerm) ATmakeList1(ATmake("l(\"traverse\")"));
        } else {
           res_attr = (ATerm) ATconcat(
                                      (ATermList) res_attr,
                                      (ATermList) ATmake("[w(\"\"),sep(\",\"),w(\"\"),"
                                                         "l(\"traverse\")]", lit));
        }
      } else {
        /* unrecognized ATerm */
        ATerror("trans_prod[0]: strange term \"%t\"\n", attr);
      }
    }
  } else if(!ATmatch(save_attr, "no-attrs")) {
    ATerror("trans_prod[1]: strange term \"%t\"\n", attrs);
  }
  if(res_attr)
  res_attr = ATmake("attrs(l(\"{\"),w(\"\"),<term>,w(\"\"),l(\"}\"))",
                    (ATerm) res_attr);
  else
  res_attr = ATparse("no-attrs");
  if(!id) {
  #if 0
    ATerror("trans_prod: id(<ModuleName>) required in attrs list\n");
  #else
    ATfprintf(stderr,"trans_prod: id(<ModuleName>) required in attrs list\n");
    id = ATparse("id(\"Unknown\")");
  #endif
  }
  result = ATmake("prod(<term>,w(\"\"),<term>,w(\"\"),"
                  "l(\"->\"),w(\"\"),<term>,w(\"\"),<term>)",
                  id, trans_prod_args(args), trans_cf_lex(res), res_attr);

  return result;
}

/*  char *trm_yield_aux_buf(int Mode, char c)  */

#define TYA_TMPCHUNK 64
#define TYA_INIT     0
#define TYA_INQUIRE  1
#define TYA_ADD      2

char *trm_yield_aux_buf(int Mode, char c)
{
  static char   *tmp = NULL;
  static size_t  tmpsize = 0;
  static int    index = 0;

  switch(Mode) {
    case TYA_INIT:
      if(tmp == NULL) {
        tmp = (char *) malloc(TYA_TMPCHUNK);
        if(tmp == NULL) {
          fprintf(stderr, "memory allocation error\n");
          exit(1);
        } else
          tmpsize = TYA_TMPCHUNK;
      }
      tmp[0] = index = 0;
      break;
    case TYA_INQUIRE:
      break;
    case TYA_ADD:
      if((index+2) > tmpsize) {
        tmp = (char *)realloc(tmp, tmpsize + TYA_TMPCHUNK);
        if(tmp == NULL) {
          fprintf(stderr, "memory reallocation error\n");
          exit(1);
        } else
          tmpsize += TYA_TMPCHUNK;
      }
      tmp[index++] = c;
      tmp[index] = 0;
      break;
  }
  return tmp;
}

/*  void trm_yield_aux(ATerm t)  */

void trm_yield_aux(ATerm t)
{
  ATermList args;

  if (ATisEmpty((ATermList) t))
    return;
  else if (ATgetType(t) == AT_INT) {
    trm_yield_aux_buf(TYA_ADD, ATgetInt((ATermInt) t));
  }
  else if (ATmatchTerm(t, asfix2_appl_term_list_pattern, NULL, &args)) {
    trm_yield_aux((ATerm) args);
  }
  else if (ATmatchTerm(t, asfix2_list_pattern, &args)) {
    trm_yield_aux(ATgetFirst(args));
    trm_yield_aux((ATerm) ATgetNext(args));
  }
  else {
    ATerror("trm_yield_aux: strange term: %t\n", t);
  }
}

/*  ATerm trm_yield(ATerm t)  */

ATerm trm_yield(ATerm t)
{
  trm_yield_aux_buf(TYA_INIT, 0);           /* Initialize (hidden) buffer */
  trm_yield_aux(t);                         /* Yield to (hidden) buffer   */
  return ATmake("<str>",                    /* Collect & return buffer    */
                trm_yield_aux_buf(TYA_INQUIRE, 0));
}

/*  ATerm internal_trans_top(ATerm t, ATbool standalone)  */

ATerm internal_trans_top(ATerm t, ATbool standalone, ATbool interpret_cons)
{
  ATerm  arg[3], result;
  ATermList args;

  /* Parse tree */
  if (ATmatchTerm(t, asfix2_parsetree_pattern, &t, NULL)) {
    return internal_trans_top(t, standalone, interpret_cons);
  }

  /* Top layout...     ...for SDF1 */
  else if (ATmatch(t, "appl(prod([cf(layout),<term>,cf(layout)],"
                   "sort(\"START\"),no-attrs),[<list>])",
                   NULL, &args)
           ||       /* ...for SDF2 */
           ATmatch(t, "appl(prod([cf(opt(layout)),<term>,cf(opt(layout))],"
                   "sort(\"<START>\"),no-attrs),[<list>])",
                   NULL, &args)) {
    arg[0] = ATgetFirst(args);
    arg[1] = ATelementAt(args,1);
    arg[2] = ATelementAt(args,2);
    result = ATmake("term(l(\"term\"),w(\" \"),l(\"X\"),w(\" \"),id(\"X\"),"
                    "w(<term>),<term>,w(<term>),no-abbreviations)",
                    trm_yield(arg[0]),
                    internal_trans(arg[1],interpret_cons), trm_yield(arg[2]));
    if (standalone == ATfalse)
      return ATmake("snd-value(<term>)", result);
    else
      return result;
  }
  /* Yawn -- not an interesting top-level case */
  else
    return internal_trans(t, interpret_cons);
}

/*   ATerm internal_trans(ATerm t)  */

ATerm internal_trans(ATerm t, ATbool interpret_cons)
{
  ATerm fun, sort, sort_or_iter, sep, asfix1_iter, asfix1_iter1;
  ATermList args;
  char *lit;

  if (ATmatchTerm(t, asfix2_amb_pattern, &args)) {
    return ATmakeTerm(asfix2_amb_pattern, trans_args(args, interpret_cons));
  }

  /* Literal */
  else if (ATmatchTerm(t, asfix2_appl_lit_pattern, NULL, &lit, NULL)) {
    return  ATmakeTerm(pattern_asfix_l, lit);
  }

  /* Layout..          ...for SDF1 */
  else if (ATmatchTerm(t, asfix2_appl_layout_pattern,
                       NULL, &args)
           ||       /* ...for SDF2 */
           ATmatchTerm(t, asfix2_appl_optlayout_pattern,
                       NULL, &args)) {
    return ATmakeTerm(pattern_asfix_ws_term, trm_yield((ATerm) args));
  }

  /* Lexical */
  else if (ATmatchTerm(t, asfix2_appl_lexical_pattern,
                       NULL, &sort, NULL, &args)) {
    return ATmakeTerm(pattern_asfix_lexterm, trm_yield((ATerm) args), sort);
  }

  /* Variable */
  else if (ATmatchTerm(t, asfix2_appl_var_pattern,
                       NULL, &sort_or_iter, NULL, &args)) {
    if (ATmatchTerm(sort_or_iter, asfix2_iter_pattern, &sort)) {
      asfix1_iter = ATmakeTerm(asfix1_iter_plus_pattern,sort);
      asfix1_iter1 = ATmakeTerm(asfix1_iter_star_pattern,sort);
      return ATmakeTerm(pattern_asfix_list,
                        asfix1_iter1, pattern_asfix_ews,
                        ATmakeList1(ATmakeTerm(pattern_asfix_varterm,
                                               trm_yield((ATerm) args),
                                               asfix1_iter)));
    } else if (ATmatchTerm(sort_or_iter, asfix2_iter_star_pattern, &sort)) {
      asfix1_iter = ATmakeTerm(asfix1_iter_star_pattern,sort);
      return ATmakeTerm(pattern_asfix_list,
                        asfix1_iter, pattern_asfix_ews,
                        ATmakeList1(ATmakeTerm(pattern_asfix_varterm,
                                               trm_yield((ATerm) args),
                                               asfix1_iter)));
    } else if(ATmatchTerm(sort_or_iter, asfix2_iter_sep_pattern, &sort, &sep)) {
      asfix1_iter = ATmakeTerm(asfix1_itersep_plus_pattern,sort,sep);
      asfix1_iter1 = ATmakeTerm(asfix1_itersep_star_pattern,sort,sep);
      return ATmakeTerm(pattern_asfix_list,
                        asfix1_iter1, pattern_asfix_ews,
                        ATmakeList1(ATmakeTerm(pattern_asfix_varterm,
                                               trm_yield((ATerm) args),
                                               asfix1_iter)));
    } else if (ATmatchTerm(sort_or_iter, asfix2_iter_star_sep_pattern,
                           &sort, &sep)) {
      asfix1_iter = ATmakeTerm(asfix1_itersep_star_pattern,sort,sep);
      return ATmakeTerm(pattern_asfix_list,
                        asfix1_iter, pattern_asfix_ews,
                        ATmakeList1(ATmakeTerm(pattern_asfix_varterm,
                                               trm_yield((ATerm) args),
                                               asfix1_iter)));
    } else
      return ATmakeTerm(pattern_asfix_varterm, trm_yield((ATerm) args),
                        sort_or_iter);
  }

  /* Star list with separator */
  else if (ATmatchTerm(t, asfix2_appl_starlist_sep_pattern,
                       NULL, &sort, &lit, NULL, &args)
           ||
           ATmatchTerm(t, asfix2_appl_pluslist_sep_pattern,
                       NULL, &sort, &lit, NULL, &args)) {
    /* ATfprintf(stderr, "normal application: %t\n", t); */
    ATerm itersep = ATmakeTerm(asfix1_itersep_pattern,sort, escape_str(lit));
    return  ATmakeTerm(pattern_asfix_list,
                       itersep, pattern_asfix_ews,
                       trans_sep_list(ATmakeList1(t), interpret_cons));
  }

  /* Star list without separator */
  else if (ATmatchTerm(t, asfix2_appl_starlist_pattern,
                       NULL, &sort, NULL, &args)
           ||
           ATmatchTerm(t, asfix2_appl_pluslist_pattern,
                       NULL, &sort, NULL, &args)) {
    /* ATfprintf(stderr, "normal application: %t\n", t); */
    ATerm iter = ATmakeTerm(asfix1_iter_pattern,sort);
    return  ATmakeTerm(pattern_asfix_list,
                       iter, pattern_asfix_ews,
                       trans_list(ATmakeList1(t), interpret_cons));
  }

  /* Default: application */
  else if (ATmatchTerm(t, asfix2_appl_term_list_pattern, &fun, &args)) {
    /* ATwarning("normal application: %t\n", t); */
    return  ATmakeTerm(pattern_asfix_appl,
                       trans_prod(fun, interpret_cons),
                       pattern_asfix_ews, trans_args(args, interpret_cons));
  }
  else {
    ATerror("trans: strange term: %t\n", t);
    return  t;
  }
}

ATerm a2toa1(ATerm t, ATbool interpret_cons)
{
  init_a2toa1_patterns();
  return internal_trans_top(t, ATtrue, interpret_cons);
}

/*   ATerm trans(int cid, ATerm t)  */

ATerm trans(int cid, ATerm t, ATerm interpret_cons)
{
  init_a2toa1_patterns();
  return internal_trans_top(t, ATfalse, (ATbool) interpret_cons);
}
