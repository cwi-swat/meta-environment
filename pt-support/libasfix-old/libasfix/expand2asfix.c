/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

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

   $Id$
*/

/*{{{  includes */

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "AsFix.h"
#include "AsFix-abbrevs.h"
#include "aterm2.h"
#include "deprecated.h"
#include "AsFix-expand.h"
#include "AsFix-access.h"

/*}}}  */
/*{{{  defines */

#define TABLE_SIZE 2048
#define DB {fprintf(stderr, "%s-%d\n", __FILE__, __LINE__ );}

#define NEW_ASFIX
#undef CONSTRUCTOR_FUNCTIONS

#define CONSTRUCTOR \
   ATparse( "attrs(l(\"{\"), w(\"\"), [l(\"constructor\")],w(\"\"),l(\"}\"))")

/*}}}  */
/*{{{  types */

typedef struct prodbucket
{
  struct prodbucket *next;
  ATerm prod;
  ATerm result;
} prodbucket;

/*}}}  */
/*{{{  variables */

static prodbucket *table[TABLE_SIZE] = { NULL };

/*}}}  */
/*{{{  external patterns */

extern ATerm pattern_asfix_ws;
extern ATerm pattern_asfix_sort;
extern ATerm pattern_asfix_lex;
extern ATerm pattern_asfix_var;
extern ATerm pattern_asfix_charclass;
extern ATerm pattern_asfix_neg;
extern ATerm pattern_asfix_itersep;
extern ATerm pattern_asfix_iter;
extern ATerm pattern_asfix_ql;
extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_attrs;
extern ATerm pattern_asfix_noattrs;
extern ATerm pattern_asfix_id;
extern ATerm pattern_asfix_ws_pattern;
extern ATerm pattern_asfix_sep;
extern ATerm pattern_asfix_simplelist;
extern ATerm pattern_asfix_hiddens;
extern ATerm pattern_asfix_exports;
extern ATerm pattern_asfix_contextfreesyntax;
extern ATerm pattern_asfix_prod;
extern ATerm pattern_asfix_appl;
extern ATerm pattern_asfix_list;
extern ATerm pattern_asfix_module;
extern ATerm pattern_asfix_equations;
extern ATerm pattern_asfix_noequations;
extern ATerm pattern_asfix_modulename;
extern ATerm pattern_asfix_ceqwhen;
extern ATerm pattern_asfix_ceqimpl;
extern ATerm pattern_asfix_ceqequ;
extern ATerm pattern_asfix_condition;
extern ATerm pattern_asfix_imports;
extern ATerm pattern_asfix_priorities;
extern ATerm pattern_asfix_sorts;
extern ATerm pattern_asfix_variables;
extern ATerm pattern_asfix_lexicalsyntax;
extern ATerm pattern_asfix_decrchain;
extern ATerm pattern_asfix_incrchain;
extern ATerm pattern_asfix_agroup;
extern ATerm pattern_asfix_group;
extern ATerm pattern_asfix_prodskel;
extern ATerm pattern_asfix_term;

/*}}}  */
/*{{{  internal terms */

static ATerm term_ws = NULL;
static ATerm term_comma = NULL;
static ATerm term_open = NULL;
static ATerm term_close = NULL;
static ATerm term_square_open = NULL;
static ATerm term_square_close = NULL;
static ATerm term_curly_open = NULL;
static ATerm term_curly_close = NULL;
static ATerm term_sort_literal = NULL;
static ATerm term_w_appl = NULL;
static ATerm term_l_appl = NULL;
static ATerm term_ql_appl = NULL;
static ATerm term_sep_appl = NULL;
static ATerm term_id_appl = NULL;
static ATerm term_exports_appl = NULL;
static ATerm term_imports_appl = NULL;
static ATerm term_hiddens_appl = NULL;
static ATerm term_sorts_appl = NULL;
static ATerm term_sort_appl = NULL;
static ATerm term_lexicalsyntax_appl = NULL;
static ATerm term_contextfreesyntax_appl = NULL;
static ATerm term_variables_appl = NULL;
static ATerm term_priorities_appl = NULL;
static ATerm term_incrchain_appl = NULL;
static ATerm term_decrchain_appl = NULL;
static ATerm term_prodskel_appl = NULL;
static ATerm term_agroup_appl = NULL;
static ATerm term_group_appl = NULL;
static ATerm term_noequations_appl = NULL;
static ATerm term_modulename_appl = NULL;
static ATerm term_equations_appl = NULL;
static ATerm term_ceqequ_appl = NULL;
static ATerm term_ceqimpl_appl = NULL;
static ATerm term_ceqwhen_appl = NULL;
static ATerm term_condition_appl = NULL;
static ATerm term_appl_appl = NULL;
static ATerm term_list_appl = NULL;
static ATerm term_var_appl = NULL;
static ATerm term_lex_appl = NULL;
static ATerm term_prod_appl = NULL;
static ATerm term_iter_appl = NULL;
static ATerm term_itersep_appl = NULL;
static ATerm term_neg_appl = NULL;
static ATerm term_charclass_appl = NULL;
static ATerm term_noattrs_appl = NULL;
static ATerm term_attrs_appl = NULL;
static ATerm term_module_appl = NULL;
static ATerm term_term_appl = NULL;
static ATerm term_abbreviations_appl = NULL;
static ATerm term_literal_to_afun_prod = NULL;
static ATerm term_afun_to_aterm_prod = NULL;
static ATerm term_aterm_to_aterms_prod = NULL;
static ATerm term_afun_aterms_to_aterm_prod = NULL;
static ATerm term_afun_aterms_ann_to_aterm_prod = NULL;
static ATerm term_aterm_aterms_to_aterms_prod = NULL;
static ATerm term_atermlist_to_aterm_prod = NULL;
static ATerm term_aterms_to_atermlist_prod = NULL;
static ATerm term_ann_prod = NULL;
static ATerm term_empty_to_atermlist_appl = NULL;

/*}}}  */
/*{{{  void AFinitExpansionTerms() */

void AFinitExpansionTerms()
{
  ATerm tmp;

  ATprotect(&term_ws);
  ATprotect(&term_comma);
  ATprotect(&term_open);
  ATprotect(&term_close);
  ATprotect(&term_square_open);
  ATprotect(&term_square_close);
  ATprotect(&term_curly_open);
  ATprotect(&term_curly_close);
  ATprotect(&term_sort_literal);
  ATprotect(&term_w_appl);
  ATprotect(&term_l_appl);
  ATprotect(&term_ql_appl);
  ATprotect(&term_sep_appl);
  ATprotect(&term_id_appl);
  ATprotect(&term_exports_appl);
  ATprotect(&term_imports_appl);
  ATprotect(&term_hiddens_appl);
  ATprotect(&term_sorts_appl);
  ATprotect(&term_sort_appl);
  ATprotect(&term_lexicalsyntax_appl);
  ATprotect(&term_contextfreesyntax_appl);
  ATprotect(&term_term_appl);
  ATprotect(&term_variables_appl);
  ATprotect(&term_priorities_appl);
  ATprotect(&term_decrchain_appl);
  ATprotect(&term_incrchain_appl);
  ATprotect(&term_prodskel_appl);
  ATprotect(&term_agroup_appl);
  ATprotect(&term_group_appl);
  ATprotect(&term_noequations_appl);
  ATprotect(&term_modulename_appl);
  ATprotect(&term_equations_appl);
  ATprotect(&term_ceqequ_appl);
  ATprotect(&term_ceqwhen_appl);
  ATprotect(&term_ceqimpl_appl);
  ATprotect(&term_condition_appl);
  ATprotect(&term_appl_appl);
  ATprotect(&term_list_appl);
  ATprotect(&term_var_appl);
  ATprotect(&term_lex_appl);
  ATprotect(&term_prod_appl);
  ATprotect(&term_iter_appl);
  ATprotect(&term_itersep_appl);
  ATprotect(&term_neg_appl);
  ATprotect(&term_charclass_appl);
  ATprotect(&term_noattrs_appl);
  ATprotect(&term_attrs_appl);
  ATprotect(&term_module_appl);
  ATprotect(&term_abbreviations_appl);
  ATprotect(&term_literal_to_afun_prod);
  ATprotect(&term_afun_to_aterm_prod);
  ATprotect(&term_aterm_to_aterms_prod);
  ATprotect(&term_afun_aterms_to_aterm_prod);
  ATprotect(&term_afun_aterms_ann_to_aterm_prod);
  ATprotect(&term_aterm_aterms_to_aterms_prod);
  ATprotect(&term_atermlist_to_aterm_prod);
  ATprotect(&term_aterms_to_atermlist_prod);
  ATprotect(&term_ann_prod);
  ATprotect(&term_empty_to_atermlist_appl);

  /* Building a white-space */
  term_ws = ATparse("w(\"\")");

  /* Building a comma */
  term_comma = ATparse("l(\",\")");

  /* Building an open */
  term_open = ATparse("l(\"(\")");

  /* Building a close */
  term_close = ATparse("l(\")\")");

  /* Building a square open */
  term_square_open = ATparse("l(\"[\")");

  /* Building a square close */
  term_square_close = ATparse("l(\"]\")");

  /* Building a curly open */
  term_curly_open = ATparse("l(\"{\")");

  /* Building a curly close */
  term_curly_close = ATparse("l(\"}\")");

  /* Building a sort Literal */
  term_sort_literal = ATparse("sort(\"Literal\")");

  /* Building a white-space appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"ParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"ParseTree-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"w\")")), 
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_w_appl = AFmakeAppl(tmp, 
                           ATmakeList1(ATparse("l(\"w\")")));
 
  /* Building a literal appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"ParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"ParseTree-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"l\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_l_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"l\")")));

  /* Building a qliteral appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"ql\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_ql_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"ql\")")));

  /* Building a separator appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"ParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"ParseTree-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"sep\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);

  term_sep_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"sep\")")));

  /* Building an identifier appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"id\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_id_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"id\")")));

  /* Building an exports appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"exports\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);

  term_exports_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"exports\")")));

  /* Building an imports appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"imports\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_imports_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"imports\")")));

  /* Building a hiddens appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"hiddens\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_hiddens_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"hiddens\")")));

  /* Building a sorts appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"sorts\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_sorts_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"sorts\")")));

  /* Building a sort appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"ParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"ParseTree-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"sort\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_sort_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"sort\")")));

  /* Building a lexical-syntax appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"lexical-syntax\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_lexicalsyntax_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"lexical-syntax\")")));

  /* Building a context-free syntax appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"context-free-syntax\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_contextfreesyntax_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"context-free-syntax\")")));

  /* Building a variables appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"variables\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_variables_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"variables\")")));

  /* Building a priorities appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"priorities\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_priorities_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"priorities\")")));
  
  /* Building an incrchain appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"incr-chain\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_incrchain_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"incr-chain\")")));
  
  /* Building a decrchain appl */ 
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"decr-chain\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_decrchain_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"decr-chain\")")));
  
  /* Building a prodskel appl */ 
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"prod-skel\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_prodskel_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"prod-skel\")")));
  
  /* Building an agroup appl */ 
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"agroup\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_agroup_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"agroup\")")));
  
  /* Building a group appl */ 
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"group\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
);
  term_group_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"group\")")));
  
  /* Building a noequations appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"no-equations\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_noequations_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"no-equations\")")));
  
  /* Building an equations appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"equations\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_equations_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"equations\")")));
  
  /* Building a ceqequ appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"ceq-equ\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_ceqequ_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"ceq-equ\")")));
  
  /* Building a ceqimpl appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"ceq-impl\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_ceqimpl_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"ceq-impl\")")));
  
  /* Building a ceqwhen appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"ceq-when\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_ceqwhen_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"ceq-when\")")));
  
  /* Building a condition appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"condition\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_condition_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"condition\")")));

  /* Building an appl appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"appl\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_appl_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"appl\")")));

  /* Building a list appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"ATypes\")"),
                           ATmakeList1(ATparse("l(\"list\")")),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
                            ATmakeList1(ATparse("ql(\"list\")")),
#endif
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_list_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"list\")")));

  /* Building a var appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"var\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_var_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"var\")")));

  /* Building a lex appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"lex\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_lex_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"lex\")")));

  /* Building a prod appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"prod\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_prod_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"prod\")")));

  /* Building an iter appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"ParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"ParseTree-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"iter\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_iter_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"iter\")")));

  /* Building an itersep appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"ParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"ParseTree-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"iter-sep\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_itersep_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"iter-sep\")")));

  /* Building a neg appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"neg\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_neg_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"neg\")")));

  /* Building a charclass appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"char-class\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_charclass_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"char-class\")")));

  /* Building a noattrs appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"no-attrs\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_noattrs_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"no-attrs\")")));

  /* Building an attrs appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"attrs\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_attrs_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"attrs\")")));

  /* Building a module appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"module\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR );
#else
                           ATparse("no-attrs"));
#endif
  term_module_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"module\")")));
  
  /* Building a modulename appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
   tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"module-name\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_modulename_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"module-name\")")));

   /* Building a term appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
  tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"term\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
   
   term_term_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"term\")")));

  /* Building an abbreviations appl */
#ifndef NEW_ASFIX
  tmp = AFmakeProd(ATparse("id(\"AsFixParseTrees\")"),
#else
  tmp = AFmakeProd(ATparse("id(\"AsFix-Constructors\")"),
#endif
                           ATmakeList1(ATparse("ql(\"abbreviations\")")),
                           ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                           ATparse("no-attrs")
#endif
                           );
  term_abbreviations_appl = AFmakeAppl(tmp,
                           ATmakeList1(ATparse("l(\"abbreviations\")")));

  /* Building a literal_to_afun prod */
  term_literal_to_afun_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                        ATmakeList(1,ATparse("sort(\"Literal\")")),
                        ATparse("sort(\"AFun\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                        ATparse("no-attrs")
#endif
                        );

  /* Building an afun_to_aterm prod */
  term_afun_to_aterm_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                        ATmakeList(1,ATparse("sort(\"AFun\")")),
                        ATparse("sort(\"ATerm\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                        ATparse("no-attrs")
#endif
                        );

  /* Building an aterm_to_aterms prod */
  term_aterm_to_aterms_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                        ATmakeList(1,ATparse("sort(\"ATerm\")")),
                        ATparse("sort(\"ATerms\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                        ATparse("no-attrs")
#endif
                        );

  /* Building an afun_aterms_to_aterm prod */
  term_afun_aterms_to_aterm_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                    ATmakeList(7,ATparse("sort(\"AFun\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("ql(\"(\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("sort(\"ATerms\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("ql(\")\")")),
                    ATparse("sort(\"ATerm\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                    ATparse("no-attrs")
#endif
                    );

  /* Building an afun_aterms_to_aterm prod */
  term_afun_aterms_ann_to_aterm_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                    ATmakeList(9,ATparse("sort(\"AFun\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("ql(\"(\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("sort(\"ATerms\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("ql(\")\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("sort(\"Ann\")")),
                    ATparse("sort(\"ATerm\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                    ATparse("no-attrs")
#endif
                    );

  /* Building an aterm_aterms_to_aterms prod */
  term_aterm_aterms_to_aterms_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                    ATmakeList(5,ATparse("sort(\"ATerm\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("ql(\",\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("sort(\"ATerms\")")),
                    ATparse("sort(\"ATerms\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                    ATparse("no-attrs")
#endif
                    );
                    

  /* Building an atermlist_to_aterm prod */
  term_atermlist_to_aterm_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                    ATmakeList1(ATparse("sort(\"ATermList\")")),
                    ATparse("sort(\"ATerm\")"),
#ifdef CONSTRUCTOR_FUNCTIONS  
CONSTRUCTOR
#else
                    ATparse("no-attrs")
#endif
                    );

  /* Building an aterms_to_atermlist prod */
  term_aterms_to_atermlist_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                    ATmakeList(5,ATparse("ql(\"[\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("sort(\"ATerms\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("ql(\"]\")")),
                    ATparse("sort(\"ATermList\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                    ATparse("no-attrs")
#endif
                    );

  /* Building an empty_to_atermlist appl */
  tmp = AFmakeProd(ATparse("id(\"ATerms\")"),
                   ATmakeList(3,ATparse("ql(\"[\")"),
                                ATparse("w(\"\")"),
                                ATparse("ql(\"]\")")),
                   ATparse("sort(\"ATermList\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                   ATparse("no-attrs")
#endif
                   );

  term_empty_to_atermlist_appl = 
         AFmakeAppl(tmp,
                    ATmakeList(3,ATparse("l(\"[\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("l(\"]\"))"))); 

  /* Building an aterms_to_atermlist prod */
  term_ann_prod = 
         AFmakeProd(ATparse("id(\"ATerms\")"),
                    ATmakeList(5,ATparse("ql(\"{\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("sort(\"ATerms\")"),
                                 ATparse("w(\"\")"),
                                 ATparse("ql(\"}\")")),
                    ATparse("sort(\"Ann\")"),
#ifdef CONSTRUCTOR_FUNCTIONS
CONSTRUCTOR
#else
                    ATparse("no-attrs")
#endif
                    );
}

/*}}}  */

/*{{{  static prodbucket *find_bucket(ATerm prod) */

static prodbucket *find_bucket(ATerm prod)
{
  /*int idx = prod->hnr % TABLE_SIZE;*/
  prodbucket *cur;
  unsigned int idx = (((int) &prod)>>2);
  idx %= TABLE_SIZE;
  
  cur = table[idx];
  while(cur && !ATisEqual(cur->prod, prod))
    cur = cur->next;

  return cur;
}

/*}}}  */
/*{{{  static void enter_prod(ATerm prod, ATerm result) */

static void enter_prod(ATerm prod, ATerm result)
{
  /*int idx = prod->hnr % TABLE_SIZE;*/
  prodbucket *b;
  unsigned int idx = (((int) &prod)>>2);
  idx %= TABLE_SIZE;

  b = malloc(sizeof(prodbucket));
  if(!b)
    ATerror("out of memory in enter_prod");
  b->next = table[idx];
  table[idx] = b;
  b->prod = prod;
  b->result = result;

  ATprotect(&b->prod);
  ATprotect(&b->result);
}

/*}}}  */
/*{{{  int is_sep(ATerm sep) */

int is_sep(ATerm sep)
{
  char *text;
  return ATmatchTerm(sep,pattern_asfix_sep,&text);
}

/*}}}  */
/*{{{  ATerm make_ann_appl(ATerm arg) */

ATerm make_ann_appl(ATerm arg)
{
  return AFmakeAppl(term_ann_prod,
                    ATmakeList(5,
                               term_curly_open,
                               term_ws,
                               arg,
                               term_ws,
                               term_curly_close));
}
/*}}}  */
/*{{{  ATerm make_literal_to_afun_appl(ATerm arg) */

ATerm make_literal_to_afun_appl(ATerm arg)
{
  return AFmakeAppl(term_literal_to_afun_prod,
                    ATmakeList(1,arg));
}

/*}}}  */
/*{{{  ATerm make_afun_to_aterm_appl(ATerm arg) */

ATerm make_afun_to_aterm_appl(ATerm arg)
{
  return AFmakeAppl(term_afun_to_aterm_prod,
                    ATmakeList(1,arg));
}

/*}}}  */
/*{{{  ATerm make_aterm_to_aterms_appl(ATerm arg) */

ATerm make_aterm_to_aterms_appl(ATerm arg)
{
  return AFmakeAppl(term_aterm_to_aterms_prod,
                    ATmakeList(1,arg));
}

/*}}}  */
/*{{{  ATerm make_afun_aterms_to_aterm_appl(ATerm fun,ATerm arg) */

ATerm make_afun_aterms_to_aterm_appl(ATerm fun,ATerm arg)
{
  return AFmakeAppl(term_afun_aterms_to_aterm_prod,
                    ATmakeList(7,
                              fun,
                              term_ws,
                              term_open,
                              term_ws,
                              arg,
                              term_ws,
                              term_close));
}

/*}}}  */
/*{{{  ATerm make_afun_aterms_ann_to_aterm_appl(ATerm fun,
                                                ATerm arg,
                                                ATerm ann) */

ATerm make_afun_aterms_ann_to_aterm_appl(ATerm fun,ATerm arg,ATerm anno)
{
  return AFmakeAppl(term_afun_aterms_ann_to_aterm_prod,
                    ATmakeList(9,
                              fun,
                              term_ws,
                              term_open,
                              term_ws,
                              arg,
                              term_ws,
                              term_close,
                              term_ws,
                              anno));
}

/*}}}  */
/*{{{  ATerm make_aterm_aterms_to_aterms_appl(ATerm term, ATerm terms) */

ATerm make_aterm_aterms_to_aterms_appl(ATerm term, ATerm terms)
{
  return AFmakeAppl(term_aterm_aterms_to_aterms_prod,
                    ATmakeList(5,
                              term,
                              term_ws,
                              term_comma,
                              term_ws,
                              terms));
}

/*}}}  */
/*{{{  ATerm make_atermlist_to_aterm_appl(ATerm arg) */

ATerm make_atermlist_to_aterm_appl(ATerm arg)
{
  return AFmakeAppl(term_atermlist_to_aterm_prod,
                    ATmakeList(1,arg));
}

/*}}}  */
/*{{{  ATerm make_aterms_to_atermlist_appl(ATerm args) */

ATerm make_aterms_to_atermlist_appl(ATerm args)
{
  return AFmakeAppl(term_aterms_to_atermlist_prod,
                    ATmakeList(5,
                              term_square_open,
                              term_ws,
                              args,
                              term_ws,
                              term_square_close));
}

/*}}}  */
/*{{{  ATerm make_empty_abbreviations() */

ATerm make_empty_abbreviations()
{
  return make_afun_aterms_to_aterm_appl(
           term_abbreviations_appl,
           make_aterm_to_aterms_appl(
             make_atermlist_to_aterm_appl(
               term_empty_to_atermlist_appl)));
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixWs(ATerm ws) */

ATerm AFexpandAsFixWs(ATerm ws)
{
  char *text;
  ATerm appl;

  if(ATmatchTerm(ws,pattern_asfix_ws_pattern,&text)) {
    appl = make_afun_to_aterm_appl(make_literal_to_afun_appl(AFmakeLex(text, term_sort_literal)));
    return make_afun_aterms_to_aterm_appl(term_w_appl,
                                        make_aterm_to_aterms_appl(appl));
  }
  else {
    ATerror("AFexpandAsFixWs entered with %t\n", ws);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixLiteral(ATerm l) */

ATerm AFexpandAsFixLiteral(ATerm l)
{
  char *text;
  ATerm appl;

  if(ATmatchTerm(l,pattern_asfix_l,&text)){ 
    appl = make_afun_to_aterm_appl(make_literal_to_afun_appl(AFmakeLex(text,
                                                                     term_sort_literal)));
    return make_afun_aterms_to_aterm_appl(term_l_appl,
                                          make_aterm_to_aterms_appl(appl));
  }
  else {
    ATprintf("AFexpandAsFixLiteral entered with %t\n",l);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixQLiteral(ATerm ql) */

ATerm AFexpandAsFixQLiteral(ATerm ql)
{
  char *text;
  ATerm appl;

  if(ATmatchTerm(ql,pattern_asfix_ql,&text)) {
    appl = make_afun_to_aterm_appl(
              make_literal_to_afun_appl(AFmakeLex(text, term_sort_literal)));
    return make_afun_aterms_to_aterm_appl(term_ql_appl,
                                          make_aterm_to_aterms_appl(appl));
  }
  else {
    ATprintf("AFexpandAsFixQLiteral entered with %t\n",ql);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSep(ATerm s) */

ATerm AFexpandAsFixSep(ATerm s)
{
  char *text;
  ATerm appl;

  if(ATmatchTerm(s,pattern_asfix_sep,&text)) {
    appl = make_afun_to_aterm_appl(
             make_literal_to_afun_appl(AFmakeLex(text,term_sort_literal)));
    return make_afun_aterms_to_aterm_appl(term_sep_appl,
                                          make_aterm_to_aterms_appl(appl));
  }
  else {
    ATprintf("AFexpandAsFixSep entered with %t\n",s);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixIter(ATerm iter) */

ATerm AFexpandAsFixTerm(ATerm term);
ATerm AFexpandAsFixSort(ATerm sort);

ATerm AFexpandAsFixIter(ATerm iter)
{
  ATerm term, w, l;
  ATerm args;

  if(ATmatchTerm(iter,pattern_asfix_iter,
                 &term,&w,&l)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixTerm(term),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w),
               make_aterm_to_aterms_appl(
               AFexpandAsFixLiteral(l))));
    return make_afun_aterms_to_aterm_appl(term_iter_appl,
                                          args);
  }
  else {
    ATprintf("AFexpandAsFixIter entered with %t\n",iter);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixIterSep(ATerm itersep) */

ATerm AFexpandAsFixIterSep(ATerm itersep)
{
  ATerm term, w[4], l[3], ql;
  ATerm args;

  if(ATmatchTerm(itersep,pattern_asfix_itersep,
                 &l[0],&w[0],&term,&w[1],&ql,&w[2],&l[1],&w[3],&l[2])) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixLiteral(l[0]),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixTerm(term),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixWs(w[1]),
                   make_aterm_aterms_to_aterms_appl(
                     AFexpandAsFixQLiteral(ql),
                     make_aterm_aterms_to_aterms_appl(
                       AFexpandAsFixWs(w[2]),
                       make_aterm_aterms_to_aterms_appl(
                         AFexpandAsFixLiteral(l[1]),
                         make_aterm_aterms_to_aterms_appl(
                           AFexpandAsFixWs(w[3]),
                           make_aterm_to_aterms_appl(
                             AFexpandAsFixLiteral(l[2]))))))))));
    return make_afun_aterms_to_aterm_appl(term_itersep_appl,
                                          args);
  }
  else {
    ATprintf("AFexpandAsFixIterSep entered with %t\n",itersep);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixNeg(ATerm neg) */

ATerm AFexpandAsFixNeg(ATerm neg)
{
  ATerm term, w, l;
  ATerm args;

  if(ATmatchTerm(neg,pattern_asfix_neg,
                 &l,&w,&term)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixLiteral(l),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w),
               make_aterm_to_aterms_appl(
                 AFexpandAsFixTerm(term))));
    return make_afun_aterms_to_aterm_appl(term_neg_appl,
                                          args);
  }
  else {
    ATprintf("AFexpandAsFixNeg entered with %t\n",neg);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixCharclass(ATerm cc) */

ATerm AFexpandAsFixCharclass(ATerm cc)
{
  char *text;
  ATerm appl;

  if(ATmatchTerm(cc,pattern_asfix_charclass,&text)) {
    appl = make_afun_to_aterm_appl(
             make_literal_to_afun_appl(AFmakeLex(text,term_sort_literal)));
    return make_afun_aterms_to_aterm_appl(term_charclass_appl,
                                          make_aterm_to_aterms_appl(appl));
  }
  else {
    ATprintf("AFexpandAsFixCharClass entered with %t\n",cc);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAnno(ATerm anno) */

ATerm AFexpandAsFixId(ATerm id);
ATerm AFexpandAnno(ATermList annos)
{
  ATerm anno1, anno2;
  ATerm newannos, newanno = NULL, newannolist;

  anno1 = ATgetFirst(annos);
  if(ATmatchTerm(anno1,pattern_asfix_modulename))
    newanno = make_afun_to_aterm_appl(term_modulename_appl);

  anno2 = ATgetFirst(ATgetNext(annos));

  newannos = make_aterm_aterms_to_aterms_appl(
               newanno,
               make_aterm_to_aterms_appl(
                 AFexpandAsFixId(anno2)));
  newannolist = make_atermlist_to_aterm_appl(
                  make_aterms_to_atermlist_appl(newannos));
  return make_ann_appl(make_aterm_to_aterms_appl(newannolist));
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixId(ATerm id) */

ATerm AFexpandAsFixId(ATerm id)
{
  char *text;
  ATerm appl, anno, newid;
 
  anno = AT_getAnnotations(id);

  if(anno != NULL) {
    anno = ATgetFirst((ATermList)anno); 

    if(ATmatchTerm(id,pattern_asfix_id,&text)) {
      appl = make_afun_to_aterm_appl(
               make_literal_to_afun_appl(AFmakeLex(text,term_sort_literal)));
      newid = make_afun_aterms_ann_to_aterm_appl(
               term_id_appl,
               make_aterm_to_aterms_appl(appl),
               AFexpandAnno((ATermList)anno)); 
      return newid;
    }
    else {
      ATprintf("AFexpandAsFixId entered with %t\n",id);
      return NULL;
    }
  }
  else {
    if(ATmatchTerm(id,pattern_asfix_id,&text)) {
      appl = make_afun_to_aterm_appl(
               make_literal_to_afun_appl(AFmakeLex(text,term_sort_literal)));
      return make_afun_aterms_to_aterm_appl(
               term_id_appl,
               make_aterm_to_aterms_appl(appl));
    }
    else {
      ATprintf("AFexpandAsFixId entered with %t\n",id);
      return NULL;
    }
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixIds(ATermList ids) */

ATerm AFexpandAsFixIds(ATermList ids)
{
  ATerm id;
  ATerm expid;
  ATerm expids = NULL;

  if(!ATisEmpty(ids)) {
    id = ATgetFirst(ids);
    ids = ATgetNext(ids);
    if(AFisLayout(id))
      expid = AFexpandAsFixWs(id);
    else
      expid = AFexpandAsFixId(id);
    if(!ATisEmpty(ids)) {
      expids = make_aterm_aterms_to_aterms_appl(
                         expid,
                         AFexpandAsFixIds(ids));
    }
    else
      expids = make_aterm_to_aterms_appl(expid);
  }
  return expids;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixIdlist(ATerm idlist) */

ATerm AFexpandAsFixIdlist(ATerm idlist)
{
  ATermList ids;

  if(ATmatchTerm(idlist,pattern_asfix_simplelist,&ids)) {
    if(ATisEmpty(ids))
      return  make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixIds(ids)));
  }
  else {
    ATprintf("AFexpandAsFixIdList entered with %t\n",idlist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixAttrss(ATermList attrs) */

ATerm AFexpandAsFixAttrss(ATermList attrs)
{
  ATerm attr;
  ATerm expattr;
  ATerm expattrs = NULL;
  char *text;

  if(!ATisEmpty(attrs)) {
    attr = ATgetFirst(attrs);
    attrs = ATgetNext(attrs);
    if(AFisLayout(attr))
      expattr = AFexpandAsFixWs(attr);
    else if(is_sep(attr))
      expattr = AFexpandAsFixSep(attr);
    else if(ATmatchTerm(attr,pattern_asfix_ql,&text)) {
      expattr = AFexpandAsFixQLiteral(attr);
    } else {
      expattr = AFexpandAsFixLiteral(attr);
    }
    if(!ATisEmpty(attrs)) {
      expattrs = make_aterm_aterms_to_aterms_appl(expattr,
                                                  AFexpandAsFixAttrss(attrs));
    }
    else
      expattrs = make_aterm_to_aterms_appl(expattr);
  }
  return expattrs;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixAttributes(ATerm attrlist) */

ATerm AFexpandAsFixAttributes(ATerm attrlist)
{
  ATermList attrs;
  ATerm w[2],l[2],args;

  if(ATmatchTerm(attrlist,pattern_asfix_noattrs)) {
    return make_afun_to_aterm_appl(term_noattrs_appl);
  }
  else {
    if(ATmatchTerm(attrlist,pattern_asfix_attrs,
		   &l[0],&w[0],&attrs,&w[1],&l[1])) {
      args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(l[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w[0]),
                 make_aterm_aterms_to_aterms_appl(
                   make_atermlist_to_aterm_appl(
                   make_aterms_to_atermlist_appl(
                   AFexpandAsFixAttrss(attrs))),
                     make_aterm_aterms_to_aterms_appl(
                     AFexpandAsFixWs(w[1]),
                       make_aterm_to_aterms_appl(
                       AFexpandAsFixLiteral(l[1]))))));
      return make_afun_aterms_to_aterm_appl(term_attrs_appl,args);
    }
    else {
      ATprintf("AFexpandAsFixAttributes entered with %t\n",attrlist);
      return NULL;
    }
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixAppl(ATerm appl) */

ATerm AFexpandAsFixArgslist(ATerm arglist);
ATerm AFexpandAsFixProd(ATerm prod);

ATerm AFexpandAsFixAppl(ATerm appl)
{
  ATerm prod, w, applargs;
  ATerm args, result;

  if(ATmatchTerm(appl,pattern_asfix_appl,
		 &prod,&w,&applargs)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixProd(prod),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixArgslist(applargs))));
    result = make_afun_aterms_to_aterm_appl(term_appl_appl,
                                            args);
    return result;
  }
  else {
    ATprintf("AFexpandAsFixAppl entered with %t\n",appl);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixList(ATerm list) */

ATerm AFexpandAsFixList(ATerm list)
{
  ATerm term,w,listargs;
  ATerm args;

  if(ATmatchTerm(list,pattern_asfix_list,
		 &term,&w,&listargs)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixTerm(term),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w),
               make_aterm_to_aterms_appl(
                 AFexpandAsFixArgslist(listargs))));
    return make_afun_aterms_to_aterm_appl(term_list_appl,args);
  }
  else {
    ATprintf("AFexpandAsFixList entered with %t\n",list);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixVar(ATerm var) */

ATerm AFexpandAsFixVar(ATerm var)
{
  char *text;
  ATerm t;
  ATerm args;
  
  if(ATmatchTerm(var, pattern_asfix_var, &text,&t)) {
    args = make_aterm_aterms_to_aterms_appl(
             make_afun_to_aterm_appl(
             make_literal_to_afun_appl(
             AFmakeLex(text,term_sort_literal))),
               make_aterm_to_aterms_appl(
                 AFexpandAsFixTerm(t)));
    return make_afun_aterms_to_aterm_appl(term_var_appl,args);
  }
  else {
    ATprintf("AFexpandAsFixVar entered with %t\n",var);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixLex(ATerm lex) */

ATerm AFexpandAsFixLex(ATerm lex)
{
  char *text;
  ATerm t[1];
  ATerm args;

  if(ATmatchTerm(lex,pattern_asfix_lex,&text,&t[0])) {
    args = make_aterm_aterms_to_aterms_appl(
             make_afun_to_aterm_appl(
             make_literal_to_afun_appl(
             AFmakeLex(text,term_sort_literal))),
               make_aterm_to_aterms_appl(
                 AFexpandAsFixTerm(t[0])));
    return make_afun_aterms_to_aterm_appl(term_lex_appl,args);
  }
  else {
    ATprintf("AFexpandAsFixLex entered with %t\n",lex);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixTerm(ATerm term) */

ATerm AFexpandAsFixTerm(ATerm term)
{
  char *text;
  ATerm t[9], result;

  if(ATmatchTerm(term,pattern_asfix_sort,&text))
    result = AFexpandAsFixSort(term);
  else if(ATmatchTerm(term,pattern_asfix_l,&text))
    result = AFexpandAsFixLiteral(term);
  else if(ATmatchTerm(term,pattern_asfix_ql,&text))
    result = AFexpandAsFixQLiteral(term);
  else if(ATmatchTerm(term,pattern_asfix_iter,
                 &t[0],&t[1],&t[2]))
    result = AFexpandAsFixIter(term);
  else if(ATmatchTerm(term,pattern_asfix_itersep,
                 &t[0],&t[1],&t[2],&t[3],&t[4],&t[5],&t[6],&t[7],&t[8]))
    result = AFexpandAsFixIterSep(term);
  else if(ATmatchTerm(term,pattern_asfix_neg,
                 &t[0],&t[1],&t[2]))
    result = AFexpandAsFixNeg(term);
  else if(ATmatchTerm(term,pattern_asfix_charclass,&text))
    result = AFexpandAsFixCharclass(term);
  else if(ATmatchTerm(term,pattern_asfix_appl,
                 &t[0],&t[1],&t[2]))
    result = AFexpandAsFixAppl(term);
  else if(ATmatchTerm(term,pattern_asfix_var,
                 &text,&t[0]))
    result = AFexpandAsFixVar(term);
  else if(ATmatchTerm(term,pattern_asfix_list,
                 &t[0],&t[1],&t[2]))
    result = AFexpandAsFixList(term);
  else if(ATmatchTerm(term,pattern_asfix_lex,
                 &text,&t[0]))
    result = AFexpandAsFixLex(term);
  else if(ATmatchTerm(term,pattern_asfix_ws,
                 &text,&t[0]))
    result = AFexpandAsFixWs(term);
  
  else {
    ATerror("\n\nUnknown term type: %t\n", term);
	return NULL;
  }

  return result;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixArgs(ATermList args) */

ATerm AFexpandAsFixArgs(ATermList args)
{
  ATerm arg;
  ATerm exparg;
  ATerm expargs = NULL;

  if(!ATisEmpty(args)) {
    arg = ATgetFirst(args);
    args = ATgetNext(args);
    if(AFisLayout(arg))
      exparg = AFexpandAsFixWs(arg);
    else if(is_sep(arg))
      exparg = AFexpandAsFixSep(arg);
    else
      exparg = AFexpandAsFixTerm(arg);
    if(!ATisEmpty(args)) {
      expargs = make_aterm_aterms_to_aterms_appl(
                         exparg,
                         AFexpandAsFixArgs(args));
    }
    else
      expargs = make_aterm_to_aterms_appl(exparg);
  }
  return expargs;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixArgslist(ATerm arglist) */

ATerm AFexpandAsFixArgslist(ATerm arglist)
{
  ATermList args;

  if(ATmatchTerm(arglist,pattern_asfix_simplelist,&args)) {
    if(ATisEmpty(args))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixArgs(args)));
  }
  else {
    ATprintf("AFexpandAsFixArgslist entered with %t\n",arglist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixProdskel(ATerm prodskel) */

ATerm AFexpandAsFixProdskel(ATerm prodskel)
{
  ATerm args,w,prod;
  if(ATmatchTerm(prodskel,pattern_asfix_prodskel,
		 &args,&w,&prod)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixArgslist(args),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w),
               make_aterm_to_aterms_appl(
                 AFexpandAsFixProd(prod))));
    return make_afun_aterms_to_aterm_appl(term_prodskel_appl,
                                        args);
  }
  else {
    ATprintf("AFexpandAsFixProdskel entered with %t\n",prodskel);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixProdskels(ATermList prodskels) */

ATerm AFexpandAsFixProdskels(ATermList prodskels)
{
  ATerm prodskel;
  ATerm expprodskel;
  ATerm expprodskels = NULL;

  if(!ATisEmpty(prodskels)) {
    prodskel = ATgetFirst(prodskels);
    prodskels = ATgetNext(prodskels);
    if(AFisLayout(prodskel))
      expprodskel = AFexpandAsFixWs(prodskel);
    else if(is_sep(prodskel))
      expprodskel = AFexpandAsFixSep(prodskel);
    else
      expprodskel = AFexpandAsFixProdskel(prodskel);
    if(!ATisEmpty(prodskels)) {
      expprodskels = make_aterm_aterms_to_aterms_appl(
                         expprodskel,
                         AFexpandAsFixProdskels(prodskels));
    }
    else
      expprodskels = make_aterm_to_aterms_appl(expprodskel);
  }
  return expprodskels;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixProdskellist(ATerm prodskellist) */

ATerm AFexpandAsFixProdskellist(ATerm prodskellist)
{
  ATermList prodskels;

  if(ATmatchTerm(prodskellist,pattern_asfix_simplelist,&prodskels)) {
    if(ATisEmpty(prodskels))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixProdskels(prodskels)));
  }
  else {
    ATprintf("AFexpandAsFixProdskellist entered with %t\n",prodskellist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixChain(ATerm chain) */

ATerm AFexpandAsFixChain(ATerm chain)
{
  ATerm args,w[4],prod,l[4],prods;
  if(ATmatchTerm(chain,pattern_asfix_prodskel,
                  &args,&w[0],&prod)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixArgslist(args),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_to_aterms_appl(
                 AFexpandAsFixProd(prod))));
    return make_afun_aterms_to_aterm_appl(
                                          term_prodskel_appl,
                                          args);
  }
  else if(ATmatchTerm(chain,pattern_asfix_group,
                 &l[0],&w[0],&prods,&w[1],&l[1])) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixLiteral(l[0]),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl( 
                 AFexpandAsFixProdskellist(prods),
                 make_aterm_aterms_to_aterms_appl( 
                   AFexpandAsFixWs(w[1]),
                   make_aterm_to_aterms_appl( 
                     AFexpandAsFixLiteral(l[1]))))));
    return make_afun_aterms_to_aterm_appl(
                                          term_group_appl,
                                          args);
  }
  else {
    if(ATmatchTerm(chain,pattern_asfix_agroup,
                   &l[0],&w[0],&l[1],&w[1],&l[2],&w[2],&prods,&w[3],&l[3])) {
      args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(l[0]),
               make_aterm_aterms_to_aterms_appl( 
                 AFexpandAsFixWs(w[0]),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixLiteral(l[1]),
                   make_aterm_aterms_to_aterms_appl(
                     AFexpandAsFixWs(w[1]),
                     make_aterm_aterms_to_aterms_appl(
                       AFexpandAsFixLiteral(l[2]),
                       make_aterm_aterms_to_aterms_appl(
                         AFexpandAsFixWs(w[2]),
                         make_aterm_aterms_to_aterms_appl(
                           AFexpandAsFixProdskellist(prods),
                           make_aterm_aterms_to_aterms_appl(
                             AFexpandAsFixWs(w[3]),
                             make_aterm_to_aterms_appl(
                               AFexpandAsFixLiteral(l[3]))))))))));
      return make_afun_aterms_to_aterm_appl(term_agroup_appl,
                                            args);
    }
    else {
      ATprintf("AFexpandAsFixChain entered with %t\n",chain);
      return NULL;
    }
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixChains(ATermList chains) */

ATerm AFexpandAsFixChains(ATermList chains)
{
  ATerm chain;
  ATerm expchain;
  ATerm expchains = NULL;

  if(!ATisEmpty(chains)) {
    chain = ATgetFirst(chains);
    chains = ATgetNext(chains);
    if(AFisLayout(chain))
      expchain = AFexpandAsFixWs(chain);
    else if(is_sep(chain))
      expchain = AFexpandAsFixSep(chain);
    else
      expchain = AFexpandAsFixChain(chain);
    if(!ATisEmpty(chains)) {
      expchains = make_aterm_aterms_to_aterms_appl(
                         expchain,
                         AFexpandAsFixChains(chains));
    }
    else
      expchains = make_aterm_to_aterms_appl(expchain);
  }
  return expchains;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixChainlist(ATerm chainlist) */

ATerm AFexpandAsFixChainlist(ATerm chainlist)
{
  ATermList chains;

  if(ATmatchTerm(chainlist,pattern_asfix_simplelist,&chains)) {
    if(ATisEmpty(chains))
      return make_aterm_to_aterms_appl(
               make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl));
    else
      return make_aterm_to_aterms_appl(
               make_atermlist_to_aterm_appl(
                 make_aterms_to_atermlist_appl(
                   AFexpandAsFixChains(chains))));
  }
  else {
    ATprintf("AFexpandAsFixChainlist entered with %t\n",chainlist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixPrio(ATerm prio) */

ATerm AFexpandAsFixPrio(ATerm prio)
{
  ATerm chainlist;

  if(ATmatchTerm(prio,pattern_asfix_incrchain,&chainlist)) {
    return make_afun_aterms_to_aterm_appl(
               term_incrchain_appl,
               AFexpandAsFixChainlist(chainlist));
  }
  else {
    if(ATmatchTerm(prio,pattern_asfix_decrchain,&chainlist)) 
      return make_afun_aterms_to_aterm_appl(
                 term_decrchain_appl,
                 AFexpandAsFixChainlist(chainlist));
    else {
      ATprintf("AFexpandAsFixPrio entered with %t\n",chainlist);
     return NULL;
    }
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixPrios(ATermList prios) */

ATerm AFexpandAsFixPrios(ATermList prios)
{
  ATerm prio;
  ATerm expprio;
  ATerm expprios = NULL;

  if(!ATisEmpty(prios)) {
    prio = ATgetFirst(prios);
    prios = ATgetNext(prios);
    if(AFisLayout(prio))
      expprio = AFexpandAsFixWs(prio);
    else if(is_sep(prio))
      expprio = AFexpandAsFixSep(prio);
    else
      expprio = AFexpandAsFixPrio(prio);
    if(!ATisEmpty(prios)) {
      expprios = make_aterm_aterms_to_aterms_appl(
                         expprio,
                         AFexpandAsFixPrios(prios));
    }
    else
      expprios = make_aterm_to_aterms_appl(expprio);
  }
  return expprios;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixPrioslist(ATerm priolist) */

ATerm AFexpandAsFixPrioslist(ATerm priolist)
{
  ATermList prios;

  if(ATmatchTerm(priolist,pattern_asfix_simplelist,&prios)) {
    if(ATisEmpty(prios))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixPrios(prios)));
  }
  else {
    ATprintf("AFexpandAsFixPrioslist entered with %t\n",priolist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSort(ATerm sort) */

ATerm AFexpandAsFixSort(ATerm sort)
{
  char *text;
  ATerm appl;

  if(ATmatchTerm(sort,pattern_asfix_sort,&text)) {
    appl = make_afun_to_aterm_appl(
               make_literal_to_afun_appl(AFmakeLex(text,term_sort_literal)));
    return make_afun_aterms_to_aterm_appl(
               term_sort_appl,make_aterm_to_aterms_appl(appl));
  }
  else {
    ATprintf("AFexpandAsFixSort entered with %t\n",sort);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSorts(ATermList sorts) */

ATerm AFexpandAsFixSorts(ATermList sorts)
{
  ATerm sort;
  ATerm expsort;
  ATerm expsorts = NULL;

  if(!ATisEmpty(sorts)) {
    sort = ATgetFirst(sorts);
    sorts = ATgetNext(sorts);
    if(AFisLayout(sort))
      expsort = AFexpandAsFixWs(sort);
    else
      expsort = AFexpandAsFixSort(sort);
    if(!ATisEmpty(sorts)) {
      expsorts = make_aterm_aterms_to_aterms_appl(
                         expsort,
                         AFexpandAsFixSorts(sorts));
    }
    else
      expsorts = make_aterm_to_aterms_appl(expsort);
  }
  return expsorts;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSortlist(ATerm sortlist) */

ATerm AFexpandAsFixSortlist(ATerm sortlist)
{
  ATermList sorts;

  if(ATmatchTerm(sortlist,pattern_asfix_simplelist,&sorts)) {
    if(ATisEmpty(sorts))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixSorts(sorts)));
  }
  else {
    ATprintf("AFexpandAsFixSortlist entered with %t\n",sortlist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixProd(ATerm prod) */

ATerm AFexpandAsFixProd(ATerm prod)
{
  ATerm w[4],id,prodargs,lit,term,attrs;
  ATerm args,result = NULL;

  prodbucket *b = find_bucket(prod);
  if(b)
    return b->result;

  if(ATmatchTerm(prod,pattern_asfix_prod,
                 &id,&w[0],&prodargs,&w[1],&lit,&w[2],&term,&w[3],&attrs)) { 
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixId(id),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixArgslist(prodargs),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixWs(w[1]),
                   make_aterm_aterms_to_aterms_appl(
                     AFexpandAsFixLiteral(lit),
                     make_aterm_aterms_to_aterms_appl(
                       AFexpandAsFixWs(w[2]),
                       make_aterm_aterms_to_aterms_appl(
                         AFexpandAsFixTerm(term),
                         make_aterm_aterms_to_aterms_appl(
                           AFexpandAsFixWs(w[3]),
                             make_aterm_to_aterms_appl(
                               AFexpandAsFixAttributes(attrs))))))))));
    result = make_afun_aterms_to_aterm_appl( term_prod_appl, args);
    enter_prod(prod, result);
  }
  else { 
    if(AFTisProd(prod)) { 
      result = AFexpandAsFixAppl(prod);
      enter_prod(prod, result);
    }
    else if(AFTisPrefixProd(prod)) { 
      result = AFexpandAsFixAppl(prod);
      enter_prod(prod, result);
    }
    else {
      ATerror("AFexpandAsFixProd entered with %t\n", prod);
    }
  }
  return result;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixProds(ATermList prods) */

ATerm AFexpandAsFixProds(ATermList prods)
{
  ATerm prod;
  ATerm expprod;
  ATerm expprods = NULL;

  if(!ATisEmpty(prods)) {
    prod = ATgetFirst(prods);
    prods = ATgetNext(prods);
    if(AFisLayout(prod))
      expprod = AFexpandAsFixWs(prod);
    else
      expprod = AFexpandAsFixProd(prod);
    if(!ATisEmpty(prods)) {
      expprods = make_aterm_aterms_to_aterms_appl(
                         expprod,
                         AFexpandAsFixProds(prods));
    }
    else
      expprods = make_aterm_to_aterms_appl(expprod);
  }
  return expprods;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixProdlist(ATerm prodlist) */

ATerm AFexpandAsFixProdlist(ATerm prodlist)
{
  ATermList prods;

  if(ATmatchTerm(prodlist,pattern_asfix_simplelist,&prods)) {
    if(ATisEmpty(prods))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixProds(prods)));
  }
  else {
    ATprintf("AFexpandAsFixProdlist entered with %t\n",prodlist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSubsection(ATerm subsection) */

ATerm AFexpandAsFixSubsection(ATerm subsection)
{
  ATerm lit, w, prods, sorts, prios;
  ATerm args;

  if(ATmatchTerm(subsection,  pattern_asfix_lexicalsyntax,
            &lit,&w,&prods)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(lit),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixProdlist(prods))));
    return make_afun_aterms_to_aterm_appl(
                                          term_lexicalsyntax_appl,
                                          args);
  }
  else if(ATmatchTerm(subsection, pattern_asfix_contextfreesyntax,
            &lit,&w,&prods)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(lit),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixProdlist(prods))));
    return make_afun_aterms_to_aterm_appl(
                                          term_contextfreesyntax_appl,
                                          args);
  }
  else if(ATmatchTerm(subsection, pattern_asfix_variables,
            &lit,&w,&prods)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(lit),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixProdlist(prods))));
    return make_afun_aterms_to_aterm_appl(term_variables_appl,
                                          args);
  }
  else if(ATmatchTerm(subsection, pattern_asfix_sorts,
            &lit,&w,&sorts)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(lit),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixSortlist(sorts))));
    return make_afun_aterms_to_aterm_appl(term_sorts_appl,
                                          args);
  }
  else if(ATmatchTerm(subsection, pattern_asfix_priorities,
		      &lit,&w,&prios)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(lit),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixPrioslist(prios))));
    return make_afun_aterms_to_aterm_appl(
                                          term_priorities_appl,
                                          args);
  }
  else {
    ATprintf("AFexpandAsFixSubsection entered with %t\n",subsection);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSubsections(ATermList subsections) */

ATerm AFexpandAsFixSubsections(ATermList subsections)
{
  ATerm subsection;
  ATerm expsubsection;
  ATerm expsubsections = NULL;

  if(!ATisEmpty(subsections)) {
    subsection = ATgetFirst(subsections);
    subsections = ATgetNext(subsections);
    if(AFisLayout(subsection))
      expsubsection = AFexpandAsFixWs(subsection);
    else
      expsubsection = AFexpandAsFixSubsection(subsection);
    if(!ATisEmpty(subsections)) {
      expsubsections = make_aterm_aterms_to_aterms_appl(
                           expsubsection,
                           AFexpandAsFixSubsections(subsections));
    }
    else
      expsubsections = make_aterm_to_aterms_appl(expsubsection);
  }
  return expsubsections;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSubsectionlist(ATerm subsectionlist) */

ATerm AFexpandAsFixSubsectionlist(ATerm subsectionlist)
{
  ATermList subsections;

  if(ATmatchTerm(subsectionlist,pattern_asfix_simplelist,&subsections)) {
    if(ATisEmpty(subsections))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else 
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                  AFexpandAsFixSubsections(subsections)));
  }
  else {
    ATprintf("AFexpandAsFixSubsectionlist entered with %t\n",subsectionlist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSection(ATerm section) */

ATerm AFexpandAsFixSection(ATerm section)
{
  ATerm lit, w, args;
  ATerm subsections, ids;

  if(ATmatchTerm(section, pattern_asfix_exports,
            &lit,&w,&subsections)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(lit),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixSubsectionlist(subsections))));
    return make_afun_aterms_to_aterm_appl(
                                          term_exports_appl,
                                          args);
  }
  else if(ATmatchTerm(section, pattern_asfix_imports,
            &lit,&w,&ids)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(lit),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixIdlist(ids))));
    return make_afun_aterms_to_aterm_appl(
                                          term_imports_appl,
                                          args);
  }
  else if(ATmatchTerm(section, pattern_asfix_hiddens,
		      &lit,&w,&subsections)) {
    args = make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixLiteral(lit),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixWs(w),
                 make_aterm_to_aterms_appl(
                   AFexpandAsFixSubsectionlist(subsections))));
    return make_afun_aterms_to_aterm_appl(term_hiddens_appl,
                                          args);
  }
  else {
    ATprintf("AFexpandAsFixSection entered with %t\n",section);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSections(ATermList sections) */

ATerm AFexpandAsFixSections(ATermList sections)
{
  ATerm section;
  ATerm expsection;
  ATerm expsections = NULL;

  if(!ATisEmpty(sections)) {
    section = ATgetFirst(sections);
    sections = ATgetNext(sections);
    if(AFisLayout(section))
      expsection = AFexpandAsFixWs(section);
    else
      expsection = AFexpandAsFixSection(section);
    if(!ATisEmpty(sections)) {
      expsections = make_aterm_aterms_to_aterms_appl(
                         expsection,
                         AFexpandAsFixSections(sections));
    }
    else
      expsections = make_aterm_to_aterms_appl(expsection);
  }
  return expsections;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixSectionlist(ATerm sectionlist) */

ATerm AFexpandAsFixSectionlist(ATerm sectionlist)
{
  ATermList sections;

  if(ATmatchTerm(sectionlist,pattern_asfix_simplelist,&sections)) {
    if(ATisEmpty(sections))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else 
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixSections(sections)));
  }
  else {
    ATprintf("AFexpandAsFixSectionlist entered with %t\n",sectionlist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixCond(ATerm cond) */

ATerm AFexpandAsFixCond(ATerm cond)
{
  ATerm lhs,rhs,w[2],l;
  ATerm args;

  if(ATmatchTerm(cond,pattern_asfix_condition,
                 &lhs,&w[0],&l,&w[1],&rhs)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixTerm(lhs),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixLiteral(l),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixWs(w[1]),
                   make_aterm_to_aterms_appl(
                     AFexpandAsFixTerm(rhs)))))); 
    return make_afun_aterms_to_aterm_appl(term_condition_appl,
                                          args);
  }
  else {
    ATprintf("AFexpandAsFixCond entered with %t\n",cond);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixConds(ATermList conds) */

ATerm AFexpandAsFixConds(ATermList conds)
{
  ATerm cond;
  ATerm expcond;
  ATerm expconds = NULL;

  if(!ATisEmpty(conds)) {
    cond = ATgetFirst(conds);
    conds = ATgetNext(conds);
    if(AFisLayout(cond))
      expcond = AFexpandAsFixWs(cond);
    else if(is_sep(cond))
      expcond = AFexpandAsFixSep(cond);
    else
      expcond = AFexpandAsFixCond(cond);
    if(!ATisEmpty(conds)) {
      expconds = make_aterm_aterms_to_aterms_appl(
                         expcond,
                         AFexpandAsFixConds(conds));
    }
    else
      expconds = make_aterm_to_aterms_appl(expcond);
  }
  return expconds;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixCondslist(ATerm condslist) */

ATerm AFexpandAsFixCondslist(ATerm condslist)
{
  ATermList conds;

  if(ATmatchTerm(condslist,pattern_asfix_simplelist,&conds)) {
    if(ATisEmpty(conds))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixConds(conds)));
  }
  else {
    ATprintf("AFexpandAsFixCondslist entered with %t\n",condslist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixEquation(ATerm equation) */

ATerm AFexpandAsFixEquation(ATerm equation)
{
  ATerm id,l[3],w[6],lhs,rhs,conds;
  ATerm args,res; 

  if(ATmatchTerm(equation, pattern_asfix_ceqequ,
            &id,&w[0],&l[0],&w[1],&lhs,&w[2],&l[1],&w[3],&rhs)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixId(id),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixLiteral(l[0]),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixWs(w[1]),
                   make_aterm_aterms_to_aterms_appl(
                     AFexpandAsFixTerm(lhs),
                     make_aterm_aterms_to_aterms_appl(
                       AFexpandAsFixWs(w[2]),
                       make_aterm_aterms_to_aterms_appl(
                         AFexpandAsFixLiteral(l[1]),
                         make_aterm_aterms_to_aterms_appl(
                           AFexpandAsFixWs(w[3]),
                           make_aterm_to_aterms_appl(
                             AFexpandAsFixTerm(rhs))))))))));
    res = make_afun_aterms_to_aterm_appl(
                                         term_ceqequ_appl,
                                         args);
  }
  else if(ATmatchTerm(equation,pattern_asfix_ceqimpl,
                 &id,&w[0],&l[0],&w[1],&conds,
                 &w[2],&l[1],&w[3],&lhs,&w[4],
                 &l[2],&w[5],&rhs)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixId(id),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixLiteral(l[0]),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixWs(w[1]),
                   make_aterm_aterms_to_aterms_appl(
                     AFexpandAsFixCondslist(conds),
                     make_aterm_aterms_to_aterms_appl(
                       AFexpandAsFixWs(w[2]),
                       make_aterm_aterms_to_aterms_appl(
                         AFexpandAsFixLiteral(l[1]),
                         make_aterm_aterms_to_aterms_appl(
                           AFexpandAsFixWs(w[3]),
                           make_aterm_aterms_to_aterms_appl(
                             AFexpandAsFixTerm(lhs),
                             make_aterm_aterms_to_aterms_appl(
                               AFexpandAsFixWs(w[4]),
                               make_aterm_aterms_to_aterms_appl(
                                 AFexpandAsFixLiteral(l[2]),
                                 make_aterm_aterms_to_aterms_appl(
                                   AFexpandAsFixWs(w[5]),
                                   make_aterm_to_aterms_appl(
                                     AFexpandAsFixTerm(rhs))))))))))))));
    res = make_afun_aterms_to_aterm_appl(
                                         term_ceqimpl_appl,
                                         args);
  }
  else if(ATmatchTerm(equation,pattern_asfix_ceqwhen,
                 &id,&w[0],&l[0],&w[1],&lhs,
                 &w[2],&l[1],&w[3],&rhs,&w[4],
		      &l[2],&w[5],&conds)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixId(id),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixLiteral(l[0]),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixWs(w[1]),
                   make_aterm_aterms_to_aterms_appl(
                    AFexpandAsFixTerm(lhs),
                     make_aterm_aterms_to_aterms_appl(
                       AFexpandAsFixWs(w[2]),
                       make_aterm_aterms_to_aterms_appl(
                         AFexpandAsFixLiteral(l[1]),
                         make_aterm_aterms_to_aterms_appl(
                           AFexpandAsFixWs(w[3]),
                           make_aterm_aterms_to_aterms_appl(
                             AFexpandAsFixTerm(rhs),
                             make_aterm_aterms_to_aterms_appl(
                               AFexpandAsFixWs(w[4]),
                               make_aterm_aterms_to_aterms_appl(
                                 AFexpandAsFixLiteral(l[2]),
                                 make_aterm_aterms_to_aterms_appl(
                                   AFexpandAsFixWs(w[5]),
                                   make_aterm_to_aterms_appl(
                                     AFexpandAsFixCondslist(conds))))))))))))));
    res = make_afun_aterms_to_aterm_appl(
                                         term_ceqwhen_appl,
                                         args);
  }
  else {
    if(AFTisSimpleCondEqu(equation) || 
       AFTisImpliesCondEqu(equation) ||
       AFTisWhenCondEqu(equation)) {
      res = AFexpandAsFixAppl(equation);
    }
    else {
      ATerror("AFexpandAsFixEquation entered with %t\n",equation);
      res = NULL;
    }
  }
  return res;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixEquations(ATermList equations) */

ATerm AFexpandAsFixEquations(ATermList equations)
{
  ATerm equation;
  ATerm expequation;
  ATerm expequations = NULL;

  if(!ATisEmpty(equations)) {
    equation = ATgetFirst(equations);
    equations = ATgetNext(equations);
    if(AFisLayout(equation))
      expequation = AFexpandAsFixWs(equation);
    else
      expequation = AFexpandAsFixEquation(equation);
    if(!ATisEmpty(equations)) {
      expequations = make_aterm_aterms_to_aterms_appl(
                         expequation,
                         AFexpandAsFixEquations(equations));
    }
    else
      expequations = make_aterm_to_aterms_appl(expequation);
  }
  return expequations;
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixEquationlist(ATerm equationlist) */

ATerm AFexpandAsFixEquationlist(ATerm equationlist)
{
  ATermList equations;

  if(ATmatchTerm(equationlist,pattern_asfix_simplelist,&equations)) {
    if(ATisEmpty(equations))
      return make_atermlist_to_aterm_appl(term_empty_to_atermlist_appl);
    else
      return make_atermlist_to_aterm_appl(
               make_aterms_to_atermlist_appl(
                 AFexpandAsFixEquations(equations)));
  }
  else {
    ATprintf("AFexpandAsFixEquationlist entered with %t\n",equationlist);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixEquationsection(ATerm equations) */

ATerm AFexpandAsFixEquationsection(ATerm equations)
{
  ATerm l,w,eqs;
  ATerm args;

  if(ATmatchTerm(equations,pattern_asfix_noequations))
    return make_afun_to_aterm_appl(term_noequations_appl);
  else if(ATmatchTerm(equations,pattern_asfix_equations,
		      &l,&w,&eqs)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixLiteral(l),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w),
               make_aterm_to_aterms_appl(
                 AFexpandAsFixEquationlist(eqs))));
    return make_afun_aterms_to_aterm_appl(
                                          term_equations_appl,
                                          args);
  }
  else {
    ATprintf("AFexpandAsFixEquationsection entered with %t\n",equations);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixTopTerm(ATerm term) */

ATerm AFexpandAsFixTopTerm(ATerm term)
{
  ATerm lit[2],w[4],id,t;
  ATerm args;

  if(ATmatchTerm(term,pattern_asfix_term,
		 &lit[0],&w[0],&lit[1],&w[1],&id,&w[2],&t,&w[3],NULL)) {

    /* term can contain an application or list */
    if( strcmp( ATgetName( ATgetSymbol( t ) ), "appl" ) == 0 )
       t = AFexpandAsFixAppl( t );
    else
       t = AFexpandAsFixList( t );
      
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixLiteral(lit[0]),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixLiteral(lit[1]),
                 make_aterm_aterms_to_aterms_appl(
                  AFexpandAsFixWs(w[1]),
                  make_aterm_aterms_to_aterms_appl(
                    AFexpandAsFixId(id),
                    make_aterm_aterms_to_aterms_appl(
                      AFexpandAsFixWs(w[2]),
                      make_aterm_aterms_to_aterms_appl(
                        t,
                        make_aterm_aterms_to_aterms_appl(
                          AFexpandAsFixWs(w[3]),
                            make_aterm_to_aterms_appl(
                              make_empty_abbreviations())))))))));
    return make_afun_aterms_to_aterm_appl(term_term_appl, args);
  }
  else {
    ATprintf("AFexpandAsFixTopTerm entered with %t\n",term);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm AFexpandAsFixModule(ATerm mod) */

ATerm AFexpandAsFixModule(ATerm mod)
{
  ATerm lit, w[4], id, equations, sections;
  ATerm lexfuncs, cffuncs, eqs;
  ATerm args;

  if (ATmatchTerm(mod,pattern_asfix_module,
                 &lit,&w[0],&id,&w[1],&sections,&w[2],&equations,&w[3],NULL)) {
    args = make_aterm_aterms_to_aterms_appl(
             AFexpandAsFixLiteral(lit),
             make_aterm_aterms_to_aterms_appl(
               AFexpandAsFixWs(w[0]),
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixId(id),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixWs(w[1]),
                   make_aterm_aterms_to_aterms_appl(
                     AFexpandAsFixSectionlist(sections),
                     make_aterm_aterms_to_aterms_appl(
                       AFexpandAsFixWs(w[2]),
                       make_aterm_aterms_to_aterms_appl(
                         AFexpandAsFixEquationsection(equations),
                         make_aterm_aterms_to_aterms_appl(
                           AFexpandAsFixWs(w[3]),
                             make_aterm_to_aterms_appl(
                               make_empty_abbreviations())))))))));
    return make_afun_aterms_to_aterm_appl(term_module_appl, args);
  }
  else if (ATmatch(mod, "[<term>,<term>,<term>,<term>]", 
                          &id, &lexfuncs, &cffuncs, &eqs)) {
    return make_atermlist_to_aterm_appl(
             make_aterms_to_atermlist_appl(
               make_aterm_aterms_to_aterms_appl(
                 AFexpandAsFixId(id),
                 make_aterm_aterms_to_aterms_appl(
                   AFexpandAsFixProdlist(lexfuncs),
                   make_aterm_aterms_to_aterms_appl(
                     AFexpandAsFixProdlist(cffuncs),
                     make_aterm_to_aterms_appl(
                       AFexpandAsFixEquationlist(eqs)))))));
  }
  else {
    ATprintf("AFexpandAsFixModule entered with %t\n",mod);
    return NULL;
  }
}

/*}}}  */
/*{{{  ATerm make_term(char *name, char* module_name, ATerm term) */

ATerm make_term(char *name, char* module_name, ATerm term)
{
  ATerm t_name;
  ATerm t_module_name;
  ATerm abbrevs;
  
  t_name = ATmake( "id(<str>)", name );
  t_module_name = ATmake( "l(<str>)", module_name );
  abbrevs = ATparse( "abbreviations([])" );

   return ATmake("term(<term>,<term>,<term>,<term>,<term>,<term>," \
                        "<term>,<term>,<term>)",
                        ATparse( "l(\"term\")" ),
                        term_ws,
                        t_module_name,
                        term_ws,
                        t_name,
                        term_ws,
                        term,
                        term_ws,
                        abbrevs );
                        
}

/*}}}  */
/*{{{  ATerm AFexpandModuleToAsFix(ATerm mod, char *name, char* module_name) */

ATerm AFexpandModuleToAsFix(ATerm mod, char *name, char* module_name)
{
  ATerm args;
  ATerm result;

  args = AFexpandAsFixModule(mod);

  result = make_term(name,module_name, args);
  return result;

}

/*}}}  */
/*{{{  ATerm AFexpandTermToAsFix(ATerm term, char *name, char* module_name) */

ATerm AFexpandTermToAsFix(ATerm term, char *name, char* module_name)
{
  ATerm args;
  ATerm result;

  args = AFexpandAsFixTopTerm(term);
  result = make_term(name, module_name, args);

  return result;
}

/*}}}  */
