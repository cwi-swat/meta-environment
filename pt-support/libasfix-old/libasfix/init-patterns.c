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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#include "AsFix.h"
#include "AsFix-abbrevs.h"
#include "AsFix-init-patterns.h"
#include "aterm1.h"
#include "aterm2.h"
#include "deprecated.h"

ATerm pattern_asfix_cbo_symbol = NULL;
ATerm pattern_asfix_cbc_symbol = NULL;
ATerm pattern_asfix_plus_symbol = NULL;
ATerm pattern_asfix_star_symbol = NULL;
ATerm pattern_asfix_comma_symbol = NULL;
ATerm pattern_asfix_arrow_symbol = NULL;
ATerm pattern_asfix_assign_symbol = NULL;
ATerm pattern_asfix_equal_symbol = NULL;
ATerm pattern_asfix_notequal_symbol = NULL;
ATerm pattern_asfix_ws = NULL;
ATerm pattern_asfix_ews = NULL;
ATerm pattern_asfix_nlws = NULL;
ATerm pattern_asfix_ws_pattern = NULL;
ATerm pattern_asfix_ws_term = NULL;
ATerm pattern_asfix_prod = NULL;
ATerm pattern_asfix_prodskel = NULL;
ATerm pattern_asfix_group = NULL;
ATerm pattern_asfix_agroup = NULL;
ATerm pattern_asfix_incrchain = NULL;
ATerm pattern_asfix_decrchain = NULL;
ATerm pattern_asfix_appl = NULL;
ATerm pattern_asfix_list = NULL;
ATerm pattern_asfix_simplelist = NULL;
ATerm pattern_asfix_iter = NULL;
ATerm pattern_asfix_itersep = NULL;
ATerm pattern_asfix_iter_star = NULL;
ATerm pattern_asfix_itersep_star = NULL;
ATerm pattern_asfix_iter_plus = NULL;
ATerm pattern_asfix_itersep_plus = NULL;
ATerm pattern_asfix_neg = NULL;
ATerm pattern_asfix_lex = NULL;
ATerm pattern_asfix_lexterm = NULL;
ATerm pattern_asfix_var = NULL;
ATerm pattern_asfix_varterm = NULL;
ATerm pattern_asfix_term = NULL;
ATerm pattern_asfix_asfcons = NULL;
ATerm pattern_asfix_cat = NULL;
ATerm pattern_asfix_cat2 = NULL;
ATerm pattern_asfix_str = NULL;
ATerm pattern_asfix_int = NULL;
ATerm pattern_asfix_sort = NULL;
ATerm pattern_asfix_l = NULL;
ATerm pattern_asfix_ql = NULL;
ATerm pattern_asfix_lit = NULL;
ATerm pattern_asfix_charclass = NULL;
ATerm pattern_asfix_sep = NULL;
ATerm pattern_asfix_noattrs = NULL;
ATerm pattern_asfix_attrs = NULL;
ATerm pattern_asfix_contextfreesyntax = NULL;
ATerm pattern_asfix_lexicalsyntax = NULL;
ATerm pattern_asfix_variables = NULL;
ATerm pattern_asfix_sorts = NULL;
ATerm pattern_asfix_priorities = NULL;
ATerm pattern_asfix_imports = NULL;
ATerm pattern_asfix_exports = NULL;
ATerm pattern_asfix_hiddens = NULL;
ATerm pattern_asfix_id = NULL;
ATerm pattern_asfix_CHAR = NULL;
ATerm pattern_asfix_ceqequ = NULL;
ATerm pattern_asfix_ceqimpl = NULL;
ATerm pattern_asfix_ceqwhen = NULL;
ATerm pattern_asfix_noequations = NULL;
ATerm pattern_asfix_modulename = NULL;
ATerm pattern_asfix_equations = NULL;
ATerm pattern_asfix_condition = NULL;
ATerm pattern_asfix_module = NULL;
ATerm pattern_asfix_lexcaller = NULL;
ATerm pattern_asfix_lex_cons = NULL;

/* Well-known symbols */
AFun af_symbol_list;

/* Well-known prods */
ATerm af_prod_empty_equ_section = NULL;
ATerm af_prod_equ_section = NULL;
ATerm af_prod_simple_cond_equ = NULL;
ATerm af_prod_implies_cond_equ = NULL;
ATerm af_prod_when_cond_equ = NULL;
ATerm af_prod_conds = NULL;
ATerm af_prod_tag = NULL;
ATerm af_prod_module = NULL;
ATerm af_prod_module_attr = NULL;
ATerm af_prod_reject_attr = NULL;
ATerm af_prod_prefer_attr = NULL;
ATerm af_prod_uneager_attr = NULL;
ATerm af_prod_cons_attr = NULL;
ATerm af_prod_simple_module_id = NULL;
ATerm af_prod_complex_module_id = NULL;
ATerm af_prod_sections = NULL;
ATerm af_prod_exports_section = NULL;
ATerm af_prod_hiddens_section = NULL;
ATerm af_prod_grammars = NULL;
ATerm af_prod_sorts_grammar = NULL;
ATerm af_prod_symbols = NULL;
ATerm af_prod_lookaheads = NULL;
ATerm af_prod_lexfuncs_grammar = NULL;
ATerm af_prod_cffuncs_grammar = NULL;
ATerm af_prod_numchar = NULL;
ATerm af_prod_single_character = NULL;
ATerm af_prod_character_range = NULL;
ATerm af_prod_single_charrange = NULL;
ATerm af_prod_charrange_list = NULL;
ATerm af_prod_charranges_optcharranges = NULL;
ATerm af_prod_optcharranges = NULL;
ATerm af_prod_charclass_symbol = NULL;
ATerm af_prod_var_symbol = NULL;
ATerm af_prod_opt_symbol = NULL;
ATerm af_prod_alt_symbol = NULL;
ATerm af_prod_nonemptyseq_symbol = NULL;
ATerm af_prod_LAYOUT_symbol = NULL;
ATerm af_prod_START_symbol = NULL;
ATerm af_prod_Start_symbol = NULL;
ATerm af_prod_LEX_symbol = NULL;
ATerm af_prod_CF_symbol = NULL;
ATerm af_prod_kernel_syntax_grammar = NULL;
ATerm af_prod_restriction_grammar = NULL;
ATerm af_prod_prios = NULL;
ATerm af_prod_prods = NULL;
ATerm af_prod_restricts = NULL;
ATerm af_prod_prod = NULL;
ATerm af_prod_lookahead = NULL;
ATerm af_prod_complexlookahead = NULL;
ATerm af_prefix_prod_prod = NULL;
ATerm af_prod_sort_symbol = NULL;
ATerm af_prod_literal_symbol = NULL;
ATerm af_prod_uqliteral_symbol = NULL;
ATerm af_prod_star_list_symbol = NULL;
ATerm af_prod_star_sep_list_symbol = NULL;
ATerm af_prod_plus_list_symbol = NULL;
ATerm af_prod_plus_sep_list_symbol = NULL;
ATerm af_prod_empty_attrs = NULL;
ATerm af_prod_attrs = NULL;
ATerm af_priorities_grammar = NULL;
ATerm af_priority_rule = NULL;
ATerm af_restrictions_rule = NULL;
ATerm af_priorities_list = NULL;
ATerm af_prio_group_list = NULL;
ATerm af_group_priority = NULL;
ATerm af_prod_assoc_attr = NULL;
ATerm af_prod_left_assoc = NULL;
ATerm af_prod_right_assoc = NULL;
ATerm af_prod_assoc_assoc = NULL;
ATerm af_prod_nonassoc_assoc = NULL;
ATerm af_prod_bracket_assoc = NULL;
ATerm af_prod_constructor_assoc = NULL;
ATerm af_prod_memo_assoc = NULL;

ATerm af_prod_afun2aterm = NULL;
ATerm af_prod_literal2afun = NULL;

/* Some other useful terms */
ATerm af_iter_eqlist = NULL;

void AFinitAsFixPatterns()
{
  ATprotect(&pattern_asfix_cbo_symbol);
  ATprotect(&pattern_asfix_cbc_symbol);
  ATprotect(&pattern_asfix_plus_symbol);
  ATprotect(&pattern_asfix_star_symbol);
  ATprotect(&pattern_asfix_comma_symbol);
  ATprotect(&pattern_asfix_arrow_symbol);
  ATprotect(&pattern_asfix_assign_symbol);
  ATprotect(&pattern_asfix_equal_symbol);
  ATprotect(&pattern_asfix_notequal_symbol);
  ATprotect(&pattern_asfix_ws);
  ATprotect(&pattern_asfix_ews);
  ATprotect(&pattern_asfix_nlws);
  ATprotect(&pattern_asfix_ws_pattern);
  ATprotect(&pattern_asfix_ws_term);
  ATprotect(&pattern_asfix_prod);
  ATprotect(&pattern_asfix_prodskel);
  ATprotect(&pattern_asfix_group);
  ATprotect(&pattern_asfix_agroup);
  ATprotect(&pattern_asfix_incrchain);
  ATprotect(&pattern_asfix_decrchain);
  ATprotect(&pattern_asfix_appl);
  ATprotect(&pattern_asfix_list);
  ATprotect(&pattern_asfix_simplelist);
  ATprotect(&pattern_asfix_iter);
  ATprotect(&pattern_asfix_itersep);
  ATprotect(&pattern_asfix_iter_star);
  ATprotect(&pattern_asfix_itersep_star);
  ATprotect(&pattern_asfix_iter_plus);
  ATprotect(&pattern_asfix_itersep_plus);
  ATprotect(&pattern_asfix_neg);
  ATprotect(&pattern_asfix_lex);
  ATprotect(&pattern_asfix_lexterm);
  ATprotect(&pattern_asfix_var);
  ATprotect(&pattern_asfix_varterm);
  ATprotect(&pattern_asfix_term);
  ATprotect(&pattern_asfix_asfcons);
  ATprotect(&pattern_asfix_cat);
  ATprotect(&pattern_asfix_cat2);
  ATprotect(&pattern_asfix_str);
  ATprotect(&pattern_asfix_int);
  ATprotect(&pattern_asfix_sort);
  ATprotect(&pattern_asfix_l);
  ATprotect(&pattern_asfix_ql);
  ATprotect(&pattern_asfix_lit);
  ATprotect(&pattern_asfix_charclass);
  ATprotect(&pattern_asfix_sep);
  ATprotect(&pattern_asfix_noattrs);
  ATprotect(&pattern_asfix_attrs);
  ATprotect(&pattern_asfix_contextfreesyntax);
  ATprotect(&pattern_asfix_lexicalsyntax);
  ATprotect(&pattern_asfix_variables);
  ATprotect(&pattern_asfix_sorts);
  ATprotect(&pattern_asfix_priorities);
  ATprotect(&pattern_asfix_imports);
  ATprotect(&pattern_asfix_exports);
  ATprotect(&pattern_asfix_hiddens);
  ATprotect(&pattern_asfix_id);
  ATprotect(&pattern_asfix_CHAR);
  ATprotect(&pattern_asfix_condition);
  ATprotect(&pattern_asfix_ceqequ);
  ATprotect(&pattern_asfix_ceqimpl);
  ATprotect(&pattern_asfix_ceqwhen);
  ATprotect(&pattern_asfix_noequations);
  ATprotect(&pattern_asfix_modulename);
  ATprotect(&pattern_asfix_equations);
  ATprotect(&pattern_asfix_module);
  ATprotect(&pattern_asfix_lexcaller);
  ATprotect(&pattern_asfix_lex_cons);

  pattern_asfix_cbo_symbol = ATparse("l(\"{\")");
  pattern_asfix_cbc_symbol = ATparse("l(\"}\")");
  pattern_asfix_plus_symbol = ATparse("l(\"+\")");
  pattern_asfix_star_symbol = ATparse("l(\"*\")");
  pattern_asfix_comma_symbol = ATparse("l(\",\")");
  pattern_asfix_arrow_symbol = ATparse("l(\"->\")");
  pattern_asfix_assign_symbol = ATparse("l(\"=:\")");
  pattern_asfix_equal_symbol = ATparse("l(\"=\")");
  pattern_asfix_notequal_symbol = ATparse("l(\"!=\")");
  pattern_asfix_ws = ATparse("w(\" \")");
  pattern_asfix_ews = ATparse("w(\"\")");
  pattern_asfix_nlws = ATparse("w(\"\\n\")");
  pattern_asfix_ws_pattern = ATparse("w(<str>)");
  pattern_asfix_ws_term = ATparse("w(<term>)");
  pattern_asfix_prod = ATparse("prod(<term>,<term>,[<list>],<term>,<term>," \
                                   "<term>,<term>,<term>,<term>)");
  pattern_asfix_prodskel = ATparse("prod-skel(<term>,<term>,<term>)");
  pattern_asfix_group = ATparse("group(<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_agroup = ATparse("agroup(<term>,<term>,<term>,<term>,<term>," \
                                "<term>,<term>,<term>,<term>)");
  pattern_asfix_incrchain = ATparse("incr-chain(<term>)");
  pattern_asfix_decrchain = ATparse("decr-chain(<term>)");
  pattern_asfix_appl = ATparse("appl(<term>,<term>,[<list>])");
  pattern_asfix_list = ATparse("list(<term>,<term>,[<list>])");
  pattern_asfix_simplelist = ATparse("[<list>]");
  pattern_asfix_iter = ATparse("iter(<term>,<term>,<term>)");
  pattern_asfix_itersep = ATparse("iter-sep(<term>,<term>,<term>,<term>," \
                                 "<term>,<term>,<term>,<term>,<term>)");
  pattern_asfix_iter_star = ATparse("iter(<term>,w(\"\"),l(\"*\"))");
  pattern_asfix_itersep_star = ATparse("iter-sep(l(\"{\"),w(\"\"),<term>," \
                                       "w(\"\"),<term>,w(\"\"),l(\"}\")," \
                                       "w(\"\"),l(\"*\"))");
  pattern_asfix_iter_plus = ATparse("iter(<term>,w(\"\"),l(\"+\"))");
  pattern_asfix_itersep_plus = ATparse("iter-sep(l(\"{\"),w(\"\"),<term>," \
                                       "w(\"\"),<term>,w(\"\"),l(\"}\")," \
                                       "w(\"\"),l(\"+\"))");
  pattern_asfix_neg = ATparse("neg(<term>,<term>,<term>)");
  pattern_asfix_lex = ATparse("lex(<str>,<term>)");
  pattern_asfix_lexterm = ATparse("lex(<term>,<term>)");
  pattern_asfix_var = ATparse("var(<str>,<term>)");
  pattern_asfix_varterm = ATparse("var(<term>,<term>)");
  pattern_asfix_term = ATparse("term(<term>,<term>,<term>," \
                                "<term>,<term>,<term>," \
                                "<term>,<term>,<term>)");
  pattern_asfix_asfcons = ATparse("asf-cons(<term>,<term>)");
  pattern_asfix_cat = ATparse("cat(<int>,<term>)");
  pattern_asfix_cat2 = ATparse("cat(<term>,<term>)");
  pattern_asfix_str = ATparse("<str>");
  pattern_asfix_int = ATparse("<int>");
  pattern_asfix_sort = ATparse("sort(<str>)");
  pattern_asfix_l = ATparse("l(<str>)");
  pattern_asfix_ql = ATparse("ql(<str>)");
  pattern_asfix_lit = ATparse("lit(<str>)");
  pattern_asfix_charclass = ATparse("char-class(<str>)");
  pattern_asfix_sep = ATparse("sep(<str>)");
  pattern_asfix_noattrs = ATparse("no-attrs");
  pattern_asfix_attrs = ATparse("attrs(<term>,<term>,[<list>],<term>,<term>)");
  pattern_asfix_contextfreesyntax = ATparse("context-free-syntax(<term>," \
                                           "<term>,[<list>])");
  pattern_asfix_lexicalsyntax = ATparse("lexical-syntax(<term>,<term>,[<list>])");
  pattern_asfix_variables = ATparse("variables(<term>,<term>,[<list>])");
  pattern_asfix_sorts = ATparse("sorts(<term>,<term>,[<list>])");
  pattern_asfix_priorities = ATparse("priorities(<term>,<term>,[<list>])");
  pattern_asfix_imports = ATparse("imports(<term>,<term>,[<list>])");
  pattern_asfix_exports = ATparse("exports(<term>,<term>,[<list>])");
  pattern_asfix_hiddens = ATparse("hiddens(<term>,<term>,[<list>])");
  pattern_asfix_id = ATparse("id(<str>)");
  pattern_asfix_CHAR = ATparse("\"{CHAR}\"(<term>)");
  pattern_asfix_ceqequ = ATparse("ceq-equ(<term>,<term>,<term>," \
                                "<term>,<term>,<term>," \
                                "<term>,<term>,<term>)");
  pattern_asfix_ceqimpl = ATparse("ceq-impl(<term>,<term>,<term>," \
                                 "<term>,<term>,<term>," \
                                 "<term>,<term>,<term>,<term>," \
                                 "<term>,<term>,<term>)");
  pattern_asfix_ceqwhen = ATparse("ceq-when(<term>,<term>,<term>," \
                                 "<term>,<term>,<term>," \
                                 "<term>,<term>,<term>,<term>," \
                                 "<term>,<term>,<term>)");
  pattern_asfix_noequations = ATparse("no-equations");
  pattern_asfix_modulename = ATparse("module-name");
  pattern_asfix_equations = ATparse("equations(<term>,<term>,<term>)");
  pattern_asfix_condition = ATparse("condition(<term>,<term>,<term>," \
                                   "<term>,<term>)");
  pattern_asfix_module = ATparse("module(<term>,<term>,<term>," \
                                "<term>,<term>,<term>," \
                                "<term>,<term>,<term>)");
  pattern_asfix_lexcaller =
    ATparse("prod(id(\"caller\"),w(\"\")," \
                             "[<term>,w(\"\"),ql(\"(\"),w(\"\")," \
                              "iter(sort(\"CHAR\"),w(\"\"),l(\"+\"))," \
                              "w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\")," \
                             "<term>,w(\"\"),no-attrs)");
  pattern_asfix_lex_cons =
    ATparse("prod(id(\"GEN-LexConsFuncs\"),w(\"\")," \
            "[<term>,w(\"\"),ql(\"(\"),w(\"\")," \
            "iter(sort(\"CHAR\"),w(\"\"),l(\"*\"))," \
            "w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\")," \
            "<term>,w(\"\"),no-attrs)");


    /* Well-known symbols */
    af_symbol_list = ATmakeSymbol("list", 3, ATfalse);
    ATprotectSymbol(af_symbol_list);

    /* Well-known prods */
    ATprotect(&af_prod_empty_equ_section);
    ATprotect(&af_prod_equ_section);
    ATprotect(&af_prod_simple_cond_equ);
    ATprotect(&af_prod_implies_cond_equ);
    ATprotect(&af_prod_when_cond_equ);
    ATprotect(&af_prod_conds);
    ATprotect(&af_prod_tag);
    ATprotect(&af_prod_module);
    ATprotect(&af_prod_module_attr);
    ATprotect(&af_prod_reject_attr);
    ATprotect(&af_prod_prefer_attr);
    ATprotect(&af_prod_uneager_attr);
    ATprotect(&af_prod_cons_attr);
    ATprotect(&af_prod_simple_module_id);
    ATprotect(&af_prod_complex_module_id);
    ATprotect(&af_prod_sections);
    ATprotect(&af_prod_exports_section);
    ATprotect(&af_prod_hiddens_section);
    ATprotect(&af_prod_grammars);
    ATprotect(&af_prod_sorts_grammar); 
    ATprotect(&af_prod_symbols);
    ATprotect(&af_prod_lookaheads);
    ATprotect(&af_prod_lexfuncs_grammar); 
    ATprotect(&af_prod_cffuncs_grammar); 
    ATprotect(&af_prod_numchar); 
    ATprotect(&af_prod_single_character); 
    ATprotect(&af_prod_character_range); 
    ATprotect(&af_prod_single_charrange); 
    ATprotect(&af_prod_charrange_list); 
    ATprotect(&af_prod_charranges_optcharranges); 
    ATprotect(&af_prod_optcharranges); 
    ATprotect(&af_prod_charclass_symbol); 
    ATprotect(&af_prod_var_symbol); 
    ATprotect(&af_prod_opt_symbol); 
    ATprotect(&af_prod_alt_symbol); 
    ATprotect(&af_prod_nonemptyseq_symbol); 
    ATprotect(&af_prod_LAYOUT_symbol); 
    ATprotect(&af_prod_START_symbol); 
    ATprotect(&af_prod_Start_symbol); 
    ATprotect(&af_prod_LEX_symbol); 
    ATprotect(&af_prod_CF_symbol); 
    ATprotect(&af_prod_kernel_syntax_grammar); 
    ATprotect(&af_prod_restriction_grammar); 
    ATprotect(&af_prod_prios);
    ATprotect(&af_prod_prods);
    ATprotect(&af_prod_restricts);
    ATprotect(&af_prod_prod);
    ATprotect(&af_prod_lookahead);
    ATprotect(&af_prod_complexlookahead);
    ATprotect(&af_prefix_prod_prod);
    ATprotect(&af_prod_sort_symbol);
    ATprotect(&af_prod_literal_symbol);
    ATprotect(&af_prod_uqliteral_symbol);
    ATprotect(&af_prod_star_list_symbol);
    ATprotect(&af_prod_star_sep_list_symbol);
    ATprotect(&af_prod_plus_list_symbol);
    ATprotect(&af_prod_plus_sep_list_symbol);
    ATprotect(&af_prod_empty_attrs);
    ATprotect(&af_prod_attrs);
    ATprotect(&af_priorities_grammar);
    ATprotect(&af_priority_rule);
    ATprotect(&af_restrictions_rule);
    ATprotect(&af_priorities_list);
    ATprotect(&af_prio_group_list);
    ATprotect(&af_group_priority);
    ATprotect(&af_prod_assoc_attr);
    ATprotect(&af_prod_left_assoc);
    ATprotect(&af_prod_right_assoc);
    ATprotect(&af_prod_assoc_assoc);
    ATprotect(&af_prod_nonassoc_assoc);
    ATprotect(&af_prod_bracket_assoc);
    ATprotect(&af_prod_constructor_assoc);
    ATprotect(&af_prod_memo_assoc);
    ATprotect(&af_iter_eqlist);
    ATprotect(&af_prod_afun2aterm);
    ATprotect(&af_prod_literal2afun);

    af_prod_empty_equ_section = 
      ATparse("prod(id(\"Equations\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Equations\"),w(\"\"),no-attrs)");
    af_prod_equ_section = 
      ATparse("prod(id(\"Equations\"),w(\"\"),[ql(\"equations\"),w(\"\"),"
	      "iter(sort(\"CondEquation\"),w(\"\"),l(\"*\"))],w(\"\"),"
	      "l(\"->\"),w(\"\"),sort(\"Equations\"),w(\"\"),no-attrs)");

    af_prod_simple_cond_equ = 
      ATparse("prod(id(\"Equations\"),w(\"\"),[sort(\"Tag\"),w(\"\"),"
	      "sort(\"Equation\")],w(\"\"),l(\"->\"),w(\"\"),"
	      "sort(\"CondEquation\"),w(\"\"),no-attrs))");

    af_prod_implies_cond_equ = 
      ATparse("prod(id(\"Equations\"),w(\"\"),[sort(\"Tag\"),w(\"\"),"
	      "sort(\"Conditions\"),w(\"\"),sort(\"Implies\"),w(\"\"),"
	      "sort(\"Equation\")],w(\"\"),l(\"->\"),w(\"\"),"
	      "sort(\"CondEquation\"),w(\"\"),no-attrs)");

    af_prod_when_cond_equ = 
      ATparse("prod(id(\"Equations\"),w(\"\"),[sort(\"Tag\"),w(\"\"),"
	      "sort(\"Equation\"),w(\"\"),ql(\"when\"),w(\"\"),"
	      "sort(\"Conditions\")],w(\"\"),l(\"->\"),w(\"\"),"
	      "sort(\"CondEquation\"),w(\"\"),no-attrs)");

    af_prod_conds = 
      ATparse("prod(id(\"Equations\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),"
	      "sort(\"Condition\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),"
	      "l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Conditions\"),"
	      "w(\"\"),no-attrs)");

    af_prod_tag =
      ATparse("prod(id(\"Equations\"),w(\"\"),[ql(\"[\"),w(\"\"),"
	      "sort(\"TagId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),"
	      "w(\"\"),sort(\"Tag\"),w(\"\"),no-attrs)");

    af_prod_module =
      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"module\"),"
              "w(\"\"),sort(\"ModuleName\"),w(\"\"),iter(sort(\"ImpSection\"),"
              "w(\"\"),l(\"*\")),w(\"\"),sort(\"Sections\")],w(\"\"),"
              "l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)");

    af_prod_module_attr =
      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"id\"),"
              "w(\"\"),ql(\"(\"),w(\"\"),sort(\"ModuleName\"),"
              "w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Attribute\"),w(\"\"),no-attrs)");

    af_prod_reject_attr =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"reject\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),"
              "w(\"\"),no-attrs)");

    af_prod_prefer_attr =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"prefer\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),"
              "w(\"\"),no-attrs)");

    af_prod_uneager_attr =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"avoid\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),"
              "w(\"\"),no-attrs)");

    af_prod_cons_attr =
      ATparse("prod(id(\"Label-Sdf-Syntax\"),w(\"\"),[ql(\"cons\"),"
              "w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),"
              "w(\"\"),no-attrs)");

    af_prod_simple_module_id =
      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),["
              "sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"ModuleName\"),w(\"\"),no-attrs)");

    af_prod_complex_module_id =
      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\"),"
              "w(\"\"),ql(\"[\"),w(\"\"),sort(\"Symbols\"),"
              "w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),"
              "w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)");

    af_prod_sections =
      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),"
              "[iter(sort(\"Section\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),"
              "w(\"\"),sort(\"Sections\"),w(\"\"),no-attrs)");

    af_prod_exports_section =
      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"exports\"),"
              "w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Section\"),w(\"\"),no-attrs)");
    
    af_prod_hiddens_section =
      ATparse("prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"hiddens\"),"
              "w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Section\"),w(\"\"),no-attrs)");
    
    af_prod_grammars =
      ATparse("prod(id(\"Grammar-Syntax\"),w(\"\"),[sort(\"Grammar\"),"
              "w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),"
              "[l(\"assoc\")],w(\"\"),l(\"}\")))");
    
    af_prod_sorts_grammar =
      ATparse("prod(id(\"Sorts-Sdf-Syntax\"),w(\"\"),[ql(\"sorts\"),"
              "w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Grammar\"),w(\"\"),no-attrs)");
    
    af_prod_symbols =
      ATparse("prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),"
              "w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Symbols\"),w(\"\"),no-attrs)");
    
    af_prod_lookaheads =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"[[\"),"
              "w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Lookahead\"),"
              "w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),"
              "w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),"
              "w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)");
    
    af_prod_lexfuncs_grammar =
      ATparse("prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"lexical\"),"
              "w(\"\"),ql(\"syntax\"),w(\"\"),sort(\"Productions\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)");
    
    af_prod_cffuncs_grammar =
      ATparse("prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"context-free\"),"
              "w(\"\"),ql(\"syntax\"),w(\"\"),sort(\"Productions\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)");

    af_prod_numchar =
      ATparse("prod(id(\"Character-Syntax\"),w(\"\"),[sort(\"NumChar\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),"
              "no-attrs)");

    af_prod_single_character =
      ATparse("prod(id(\"Character-Class-Syntax\"),w(\"\"),["
              "sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"CharRange\"),w(\"\"),no-attrs)");

    af_prod_character_range =
      ATparse("prod(id(\"Character-Class-Syntax\"),w(\"\"),["
              "sort(\"Character\"),w(\"\"),ql(\"-\"),w(\"\"),"
              "sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"CharRange\"),w(\"\"),no-attrs)");

    af_prod_single_charrange =
      ATparse("prod(id(\"Character-Class-Syntax\"),"
              "w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"CharRanges\"),w(\"\"),no-attrs)");

    af_prod_charrange_list =
      ATparse("prod(id(\"Character-Class-Syntax\"),"
              "w(\"\"),[sort(\"CharRanges\"),w(\"\"),sort(\"CharRanges\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),"
              "attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),"
              "w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))");

    af_prod_charranges_optcharranges =
      ATparse("prod(id(\"Character-Class-Syntax\"),w(\"\"),["
              "sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"OptCharRanges\"),w(\"\"),no-attrs)");

    af_prod_optcharranges =
      ATparse("prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),"
              "w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),"
              "w(\"\"),no-attrs)");

    af_prod_charclass_symbol =
      ATparse("prod(id(\"CC-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_var_symbol =
      ATparse("prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),"
              "w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"-VAR\"),"
              "w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),"
              "w(\"\"),no-attrs)");

    af_prod_opt_symbol =
      ATparse("prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),"
              "w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),"
              "w(\"\"),no-attrs)");

    af_prod_alt_symbol =
      ATparse("prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),"
              "w(\"\"),ql(\"|\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),"
              "w(\"\"),sort(\"Symbol\"),w(\"\"),attrs(l(\"{\"),"
              "w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))");

    af_prod_nonemptyseq_symbol =
      ATparse("prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),iter(sort(\"Symbol\"),w(\"\"),"
              "l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_LAYOUT_symbol =
      ATparse("prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"LAYOUT\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_START_symbol =
      ATparse("prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<START>\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_Start_symbol =
      ATparse("prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<Start>\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_LEX_symbol =
      ATparse("prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),ql(\"-LEX\"),w(\"\"),ql(\">\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_CF_symbol =
      ATparse("prod(id(\"Basic-Sdf-Syntax\"),w(\"\"),[ql(\"<\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),ql(\"-CF\"),w(\"\"),ql(\">\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_kernel_syntax_grammar =
      ATparse("prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"syntax\"),"
              "w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Grammar\"),w(\"\"),no-attrs)");

    af_prod_restriction_grammar =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),"
              "[ql(\"restrictions\"),w(\"\"),sort(\"Restrictions\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)");

    af_prod_prios =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),["
              "iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),"
              "ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),"
              "l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)");

    af_prod_prods =
      ATparse("prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),"
              "[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),"
              "l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)");

    af_prod_restricts =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),"
              "[iter(sort(\"Restriction\"),w(\"\"),l(\"*\"))],w(\"\"),"
              "l(\"->\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),no-attrs)");
    
    af_prod_prod =
      ATparse("prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),"
              "[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),"
              "l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)");
    
    af_prod_lookahead =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),["
              "sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Lookahead\"),w(\"\"),no-attrs)");
    
    af_prod_complexlookahead =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),["
              "sort(\"CharClass\"),w(\"\"),ql(\".\"),w(\"\"),"
              "sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Lookahead\"),w(\"\"),no-attrs)");

    af_prefix_prod_prod =
      ATparse("prod(id(\"Literals-Sdf-Syntax\"),w(\"\"),[sort(\"Literal\"),"
              "w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),"
              "l(\"*\")),w(\"\"),ql(\")\"),w(\"\"),ql(\"->\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),"
              "l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)");

    af_prod_sort_symbol =
      ATparse("prod(id(\"Sorts-Sdf-Syntax\"),w(\"\"),[sort(\"Sort\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_literal_symbol =
      ATparse("prod(id(\"Literals-Sdf-Syntax\"),w(\"\"),[sort(\"Literal\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)");

    af_prod_uqliteral_symbol =
      ATparse("prod(id(\"Literals-Sdf-Syntax\"),w(\"\"),[sort(\"UQLiteral\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)");

    af_prod_star_list_symbol =
      ATparse("prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),"
              "w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),"
              "w(\"\"),no-attrs)");

    af_prod_star_sep_list_symbol =
      ATparse("prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),"
              "w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),"
              "w(\"\"),no-attrs)");

    af_prod_plus_list_symbol =
      ATparse("prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),"
              "w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),"
              "w(\"\"),no-attrs)");

    af_prod_plus_sep_list_symbol =
      ATparse("prod(id(\"Regular-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),"
              "sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),"
              "w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),"
              "w(\"\"),no-attrs)");

    af_prod_empty_attrs =
      ATparse("prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),"
              "w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)");

    af_prod_attrs =
      ATparse("prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),"
              "iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),"
              "ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),"
              "ql(\"}\")],w(\"\"),l(\"->\"),"
              "w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)");

    af_priorities_grammar =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),["
              "ql(\"priorities\"),w(\"\"),sort(\"Priorities\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)");

    af_priority_rule =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),"
              "w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),"
              "w(\"\"),no-attrs)");

    af_restrictions_rule =
      ATparse("prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),["
              "sort(\"Symbols\"),w(\"\"),ql(\"-/-\"),w(\"\"),"
              "sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Restriction\"),w(\"\"),no-attrs)");

    af_priorities_list =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),["
              "iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),"
              "ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),"
              "l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)");

    af_prio_group_list =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),["
              "iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),"
              "ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),"
              "l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)");

    af_group_priority =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),["
              "sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Group\"),w(\"\"),no-attrs)");

    af_prod_assoc_attr =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),["
              "sort(\"Associativity\")],w(\"\"),l(\"->\"),w(\"\"),"
              "sort(\"Attribute\"),w(\"\"),no-attrs)");

    af_prod_left_assoc =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"left\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),"
              "w(\"\"),no-attrs)");

    af_prod_right_assoc =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"right\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),"
              "w(\"\"),no-attrs)");

    af_prod_assoc_assoc =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"assoc\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),"
              "w(\"\"),no-attrs)");

    af_prod_nonassoc_assoc =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"non-assoc\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Associativity\"),"
              "w(\"\"),no-attrs)");

    af_prod_bracket_assoc =
      ATparse("prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[ql(\"bracket\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),"
              "w(\"\"),no-attrs)");

    af_prod_constructor_assoc =
      ATparse("prod(id(\"Label-Sdf-Syntax\"),w(\"\"),[ql(\"constructor\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),"
              "w(\"\"),no-attrs)");

    af_prod_memo_assoc =
      ATparse("prod(id(\"Label-Sdf-Syntax\"),w(\"\"),[ql(\"memo\")],"
              "w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),"
              "w(\"\"),no-attrs)");

    af_prod_afun2aterm =
       ATparse("prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],"
               "w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)");

    af_prod_literal2afun =
       ATparse("prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],"
               "w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)");

	/* Some other useful terms */
    af_iter_eqlist = ATparse("iter(sort(\"CondEquation\"),w(\"\"),l(\"*\"))");

}

ATerm make_caller_prod(ATerm sort)
{
  ATerm prod, name;
  char *text;
  int i;

  if(!ATmatchTerm(sort, pattern_asfix_sort, &text))
		ATerror("make_caller_prod: not an asfix sort: %t\n", sort);

  text = strdup(text);
  if(!text) {
    ATerror("Not enough memory\n");
  }
  for(i=0; text[i]; i++)
    text[i] = tolower(text[i]);
  name = ATmakeTerm(pattern_asfix_l, text);
  free(text);
  prod = ATmakeTerm(pattern_asfix_lexcaller, name, sort);
  return prod;
}


ATerm make_term_caller_prod(ATerm sort)
{
  ATerm prod, name;
  char *text;
  int i;

  if(!ATmatchTerm(sort, pattern_asfix_sort, &text))
    ATerror("make_term_caller_prod: not an asfix sort: %t\n", sort);

  text = strdup(text);
  if(!text) {
    ATerror("Not enough memory\n");
  }
  for(i=0; text[i]; i++)
    text[i] = tolower(text[i]);
  name = ATmakeTerm(pattern_asfix_ql, text);
  free(text);
  prod = ATmakeTerm(pattern_asfix_lex_cons, name, sort);
  return prod;
}

