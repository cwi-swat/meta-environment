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
#include <unistd.h>
#include "ksdf2table.h"
#include "statistics.h"

/*{{{  global variables */

int MAX_PROD;
int nr_of_states;
int nr_of_actions;
int max_nr_actions;
int nr_of_gotos;
int max_nr_gotos;
int nr_of_lhs_members;
int max_nr_lhs_members;
extern int nr_of_items;
extern int max_nr_items;
ATerm empty_set;
ATerm eof_token;
ATerm all_chars;  
extern ATbool run_verbose;
extern ATbool statisticsMode;

/*}}}  */
/*{{{  external functions */

extern ATerm SDFflattenProd(ATerm prod);
extern ATerm SDFflattenSymbol(ATerm symbol);
extern ATerm SDFflattenLookAhead(ATerm prod, ATbool nested);
extern ATbool pgen_cnf(ATermInt prodnr1, int iptr, int len, ATermInt prodnr2);
extern ATbool has_reject_attr(ATerm prod);
extern ATbool has_prefer_attr(ATerm prod);
extern ATbool has_avoid_attr(ATerm prod);
extern ATermList SDFgetProductions(ATerm g);
extern ATermList SDFgetRestrictions(ATerm g);
extern ATermList SDFgetPriorities(ATerm g);
extern ATerm remove_attrs(ATerm prod);
extern int count_members_in_lhs(ATerm prod);
 
/*}}}  */
/*{{{  function declarations */

void init_first(ATerm prod);
void calc_first_table();
void calc_follow_table();
void calc_goto_graph();

/*}}}  */
/*{{{  AFuns */

AFun afun_action = 0;
AFun afun_char_class = 0;
AFun afun_goto = 0;
AFun afun_item = 0;
AFun afun_prod = 0;
AFun afun_range = 0;
AFun afun_shift = 0;
AFun afun_non_assoc_prio = 0;
AFun afun_gtr_prio = 0;
AFun afun_left_prio = 0;
AFun afun_right_prio = 0;
AFun afun_assoc_prio = 0;
AFun afun_actions = 0;
AFun afun_state_rec = 0;
AFun afun_label = 0;
AFun afun_lit = 0;

/*}}}  */
/*{{{  Declaration of tables used during generation process */

static ATermTable prod_nr_pairs;
ATermTable nr_flatprod_pairs;
ATermTable nr_spec_attr_pairs;
ATermTable symbol_lookaheads_table;
ATermTable priority_table;
ATermTable rhs_prods_pairs;
ATermTable first_table;
ATerm *nr_prod_table;

/* Datastructures to store the generated "parse table". 
 * The parse table is generated based on a LR automaton.
 * The LR automaton is a set of states.
 * A state is consists of a number, the corresponding itemset,
 * goto-set, action-set.
 */
ATerm initial_state;
ATermTable state_nr_pairs;
ATermTable nr_state_pairs;
ATermTable state_gotos_pairs;
ATermTable state_actions_pairs;
ATermSOS *state_sos;

/*}}}  */
/*{{{  void init_table_gen() */

void init_table_gen()
{
  prod_nr_pairs = ATtableCreate(1024,75);
  nr_spec_attr_pairs = ATtableCreate(1024,75);
  priority_table = ATtableCreate(1024,75);
  symbol_lookaheads_table = ATtableCreate(1024,75);
  rhs_prods_pairs = ATtableCreate(1024,75);
  first_table = ATtableCreate(1024,75);
  state_nr_pairs = ATtableCreate(1024,75);
  nr_state_pairs = ATtableCreate(1024,75);
  state_gotos_pairs = ATtableCreate(1024,75);
  state_actions_pairs = ATtableCreate(1024,75);
  state_sos = ATsosCreate(8501);
  
  empty_set = ATparse("epsilon");
  ATprotect(&empty_set);

  eof_token = ATmake("[<list>]",ATmakeList1((ATerm)ATmakeInt(SDF_EOF)));
  ATprotect(&eof_token);

  all_chars = ATmake("char-class([range(<term>,<term>)])",
                     (ATerm)ATmakeInt(0),(ATerm)ATmakeInt(255));
  ATprotect(&all_chars);

  afun_action = ATmakeAFun("action", 2, ATfalse);
  ATprotectAFun(afun_action);
  afun_char_class = ATmakeAFun("char-class", 1, ATfalse);
  ATprotectAFun(afun_char_class);
  afun_goto = ATmakeAFun("goto", 2, ATfalse);
  ATprotectAFun(afun_goto);
  afun_item = ATmakeAFun("item", 4, ATfalse);
  ATprotectAFun(afun_item);
  afun_prod = ATmakeAFun("prod", 3, ATfalse);
  ATprotectAFun(afun_prod);
  afun_range = ATmakeAFun("range", 2, ATfalse);
  ATprotectAFun(afun_range);
  afun_shift = ATmakeAFun("shift", 1, ATfalse);
  ATprotectAFun(afun_shift);
  afun_left_prio = ATmakeAFun("left-prio", 2, ATfalse);
  ATprotectAFun(afun_left_prio);
  afun_right_prio = ATmakeAFun("right-prio", 2, ATfalse);
  ATprotectAFun(afun_right_prio);
  afun_assoc_prio = ATmakeAFun("assoc-prio", 2, ATfalse);
  ATprotectAFun(afun_assoc_prio);
  afun_non_assoc_prio = ATmakeAFun("non-assoc-prio", 2, ATfalse);
  ATprotectAFun(afun_non_assoc_prio);
  afun_gtr_prio = ATmakeAFun("gtr-prio", 2, ATfalse);
  ATprotectAFun(afun_gtr_prio);
  afun_actions = ATmakeAFun("actions", 1, ATfalse);
  ATprotectAFun(afun_actions);
  afun_state_rec = ATmakeAFun("state-rec", 3, ATfalse);
  ATprotectAFun(afun_state_rec);
  afun_label = ATmakeAFun("label", 2, ATfalse);
  ATprotectAFun(afun_label);
  afun_lit = ATmakeAFun("lit", 1, ATfalse);
  ATprotectAFun(afun_lit);
}

/*}}}  */
/*{{{  void destroy_table_gen() */

void destroy_table_gen()
{
  ATtableDestroy(prod_nr_pairs);
  ATtableDestroy(nr_spec_attr_pairs);
  ATtableDestroy(priority_table);
  ATtableDestroy(symbol_lookaheads_table);
  ATtableDestroy(rhs_prods_pairs);
  ATtableDestroy(first_table);
  ATtableDestroy(state_nr_pairs);
  ATtableDestroy(nr_state_pairs);
  ATtableDestroy(state_gotos_pairs);
  ATtableDestroy(state_actions_pairs);
  ATsosDestroy(state_sos);
}      

/*}}}  */
/*{{{  void sort_on_rhs_symbol(ATerm prod,ATerm prodnr) */

/**
 * Group the production rules with the same rhs together.
 */

void sort_on_rhs_symbol(ATerm prod, ATerm prodnr)
{
  ATermList args;
  ATerm symbol, attrs, entry;

  if(IS_PROD(prod)) {
    args   = GET_LIST_ARG(prod,0);
    symbol = GET_ARG(prod, 1);
    attrs  = GET_ARG(prod, 2);

    entry = ATtableGet(rhs_prods_pairs,symbol);
    if(entry)
      entry = (ATerm)ATinsert((ATermList)entry,prodnr);
    else
      entry = (ATerm)ATmakeList1(prodnr);
    ATtablePut(rhs_prods_pairs,symbol,entry);
  }
}

/*}}}  */
/*{{{  ATerm process_productions(ATermList prods) */

ATerm process_productions(ATermList prods)
{
  ATerm prod, flatprod, aint, labelentry, newprod;
  ATermList localprods, labelentries = ATempty;
  int ip, cnt = MIN_PROD, nr_of_members, nr_of_kernel_prods;

  localprods = prods;
  while(!ATisEmpty(localprods)) {
    prod = ATgetFirst(localprods);
    localprods = ATgetNext(localprods);
    if(!AFTisWS(prod))
      cnt++;
  }
  MAX_PROD = cnt;

  nr_prod_table = (ATerm *)malloc(sizeof(ATerm)*MAX_PROD);

  if (!nr_prod_table) {
    ATerror("out of memory!\n");
  }

  for (ip=MIN_PROD; ip<MAX_PROD; ip++) {
    nr_prod_table[ip] = NULL;
  }

  ATprotectArray((ATerm *)nr_prod_table+MIN_PROD, MAX_PROD-MIN_PROD);

  cnt = MIN_PROD;
  while(!ATisEmpty(prods)) {
    prod = ATgetFirst(prods);
    prods = ATgetNext(prods);
    if (!AFTisWS(prod)) {

      flatprod = SDFflattenProd(prod);
      if (statisticsMode) {
        nr_of_members = count_members_in_lhs(flatprod);
        if (nr_of_members > max_nr_lhs_members) {
          max_nr_lhs_members = nr_of_members;
        }
        nr_of_lhs_members += nr_of_members;
      }
      newprod = remove_attrs(prod);

      aint = (ATerm)ATmakeInt(cnt);
      ATtablePut(prod_nr_pairs, newprod, aint);
      nr_prod_table[cnt] = flatprod;

      if (has_reject_attr(prod)) {
        ATtablePut(nr_spec_attr_pairs, aint, (ATerm)ATmakeInt(1));
      }
      else if (has_prefer_attr(prod)) {
        ATtablePut(nr_spec_attr_pairs, aint, (ATerm)ATmakeInt(2));
      }
      else if (has_avoid_attr(prod)) {
        ATtablePut(nr_spec_attr_pairs, aint, (ATerm)ATmakeInt(4));
      }
      else {
        ATtablePut(nr_spec_attr_pairs, aint, (ATerm)ATmakeInt(0));
      }

      sort_on_rhs_symbol(flatprod,aint);
      init_first(flatprod);

      labelentry = (ATerm)ATmakeAppl2(afun_label, flatprod, aint);
      labelentries = ATinsert(labelentries,labelentry);
      cnt++;
    }
  }
  nr_of_kernel_prods = cnt - MIN_PROD;

  IF_STATISTICS(fprintf(PT_log (), "Number of kernel productions is %d\n", cnt - MIN_PROD));
  IF_STATISTICS(fprintf(PT_log (), "Maximum number of members per left hand side is %d\n", max_nr_lhs_members));
  IF_STATISTICS(fprintf(PT_log (), "Average number of members per left hand side is %d\n", (nr_of_lhs_members/nr_of_kernel_prods)));

  return ATmake("[<list>]",labelentries);
}

/*}}}  */
/*{{{  ATerm process_priorities(ATermList prios) */

ATerm process_priorities(ATermList prios)
{
  ATerm leftgroup = NULL, rightgroup = NULL, 
        leftnr = NULL, rightnr = NULL, 
        newprod, leftprod, rightprod, priolist,
        prio, assoc, prioentry = NULL;
  ATermList prioelems, prioentries = ATempty;
  int cnt = 0;
  ATerm zero = (ATerm)ATmakeInt(0);

  while(!ATisEmpty(prios)) {
    prio = ATgetFirst(prios);
    prios = ATgetNext(prios);
    if(!AFTisWS(prio) && !AFTisSep(prio)) {
      cnt++;
      if(AFTisPriorityRule(prio)) {
        leftgroup = AFTgetPriorityRuleLeft(prio);
        if(AFTisGroupPriority(leftgroup)) {
          leftprod = AFTgetGroupPriorityProd(leftgroup);
          newprod = remove_attrs(leftprod);
          leftnr = ATtableGet(prod_nr_pairs, newprod);
          if(!leftnr) {
            newprod = SDFflattenProd(leftprod);
            if(run_verbose) ATwarning("No rule found for %t\n", newprod);
            leftnr = zero;
          }
        }
        rightgroup = AFTgetPriorityRuleRight(prio);
        if(AFTisGroupPriority(rightgroup)) {
          rightprod = AFTgetGroupPriorityProd(rightgroup);
          newprod = remove_attrs(rightprod);
          rightnr = ATtableGet(prod_nr_pairs, newprod);
          if(!rightnr) {
            newprod = SDFflattenProd(rightprod);
            if(run_verbose) ATwarning("No rule found for %t\n", newprod);
            rightnr = zero;
          }
        }
        if(!ATisEqual(leftnr,zero) && !ATisEqual(rightnr,zero)) {
          assoc = AFTgetPriorityRuleAssoc(prio);
          if(AFTisLeftAssoc(assoc))
            prioentry = (ATerm)ATmakeAppl2(afun_left_prio, 
                                           leftnr, rightnr);
          else if(AFTisRightAssoc(assoc))
            prioentry = (ATerm)ATmakeAppl2(afun_right_prio, 
                                           leftnr, rightnr);
          else if(AFTisAssocAssoc(assoc))
            prioentry = (ATerm)ATmakeAppl2(afun_assoc_prio, 
                                           leftnr, rightnr);
          else if(AFTisNonAssocAssoc(assoc))
            prioentry = (ATerm)ATmakeAppl2(afun_non_assoc_prio, 
                                           leftnr, rightnr);
          else
            ATerror("Left assoc expected, got %t\n", assoc);
	}
        else
          prioentry = NULL;
      }
      else if(AFTisPriorityGroupList(prio)) {
        priolist = AFTgetPriorityGroupListList(prio);

        if(!AFTisList(priolist))
          ATerror("not a list: %t\n", priolist);

        prioelems = AFTgetListElements(priolist);
  
        leftgroup = ATelementAt(prioelems,0);
        if(AFTisGroupPriority(leftgroup)) {
          leftprod = AFTgetGroupPriorityProd(leftgroup);
          newprod = remove_attrs(leftprod);
          leftnr = ATtableGet(prod_nr_pairs, newprod);
          if(!leftnr) {
            newprod = SDFflattenProd(leftprod);
            if(run_verbose) ATwarning("No rule found for %t\n", newprod);
            leftnr = zero;
          }
        }
        rightgroup = ATelementAt(prioelems,4);
        if(AFTisGroupPriority(rightgroup)) {
          rightprod = AFTgetGroupPriorityProd(rightgroup);
          newprod = remove_attrs(rightprod);
          rightnr = ATtableGet(prod_nr_pairs, newprod);
          if(!rightnr) {
            newprod = SDFflattenProd(rightprod);
            if(run_verbose) ATwarning("No rule found for %t\n", newprod);
            rightnr = zero;
          }
        }
        if(!ATisEqual(leftnr,zero) && !ATisEqual(rightnr,zero)) {
          assoc = ATelementAt(prioelems,2);
          if(ATisEqual(assoc,ATparse("sep(\">\")"))) {
            prioentry = (ATerm)ATmakeAppl2(afun_gtr_prio, 
                                         leftnr, rightnr);
          }
          else
            ATerror("Greater assoc expected, got %t\n", assoc);
        }
        else
          prioentry = NULL;
      }
      else
        ATerror("expected priority rule, got %t\n", prio);
      if(prioentry) {
        ATtablePut(priority_table, prioentry, (ATerm)ATmakeInt(cnt));
        prioentries = ATinsert(prioentries, prioentry);
      }
    }
  }

  IF_STATISTICS(fprintf(PT_log (), "Number of priorities is %d\n", cnt));

  return ATmake("[<list>]",prioentries);
}

/*}}} */
/*{{{ void process_restrictions(ATermList restricts) */


void process_restrictions(ATermList restricts)
{
  ATerm restrict, symbol, symbols, lookaheads, symbollist, newsymbol,
        lookaheadlist, newlookahead, lookahead;
  ATermList symbolelems, lookaheadelems, newlookaheads, oldlookaheads;
  int cnt = 0;

  while(!ATisEmpty(restricts)) {
    restrict = ATgetFirst(restricts);

    restricts = ATgetNext(restricts);
    if(!AFTisWS(restrict)) {
      cnt++;
      if(AFTisRestrictionRule(restrict)) {
        symbols = AFTgetRestrictionSymbols(restrict);
        lookaheads = AFTgetRestrictionLookaheads(restrict);

        if(!AFTisLookAheads(lookaheads))
          ATerror("expected lookaheads, got %t\n", lookaheads);

        lookaheadlist = AFTgetLookAheadsList(lookaheads);

        if(!AFTisList(lookaheadlist))
          ATerror("not a list: %t\n", lookaheadlist);

        lookaheadelems = AFTgetListElements(lookaheadlist);
        newlookaheads = ATempty;
        while(!ATisEmpty(lookaheadelems)) {
          lookahead = ATgetFirst(lookaheadelems);

          if(!AFTisWS(lookahead) && !AFTisSep(lookahead)) {
            newlookahead = SDFflattenLookAhead(lookahead, ATfalse);
            newlookaheads = ATappend(newlookaheads, newlookahead);
          }
          lookaheadelems = ATgetNext(lookaheadelems);
        }

        if(!AFTisSymbols(symbols))
          ATerror("expected symbols, got %t\n", symbols);

        symbollist = AFTgetSymbolsList(symbols);

        if(!AFTisList(symbollist))
          ATerror("not a list: %t\n", symbollist);

        symbolelems = AFTgetListElements(symbollist);

        while(!ATisEmpty(symbolelems)) {
          symbol = ATgetFirst(symbolelems);
          symbolelems = ATgetNext(symbolelems);

          if(!AFTisWS(symbol)) {
            newsymbol = SDFflattenSymbol(symbol);
            oldlookaheads = (ATermList)ATtableGet(symbol_lookaheads_table, newsymbol);
            if (oldlookaheads) {
              newlookaheads = ATconcat(oldlookaheads, newlookaheads);
            }
            ATtablePut(symbol_lookaheads_table, newsymbol, 
                       (ATerm)newlookaheads);
          }
        }
      }
    }
  }
}

/*}}}  */
/*{{{  ATerm generate_parse_table(ATerm t) */

ATerm generate_parse_table(ATerm g)
{
  int i, nr_actions, nr_gotos;
  ATerm trm, labelsection, priosection, vnr, vertex, state, newaction;
  ATermList prods, prios, statelist = ATempty, gotos, actions, restricts;

  trm = asfix_get_term(g);
  if(AFTisGrammars(trm)) {
    prods = SDFgetProductions(trm);
    prios = SDFgetPriorities(trm);
    restricts = SDFgetRestrictions(trm);
    labelsection = process_productions(prods);
    priosection = process_priorities(prios);
    process_restrictions(restricts);
    calc_first_table();
    calc_follow_table();
    calc_goto_graph();

    IF_STATISTICS(fprintf(PT_log (), "Number of states is %d\n", nr_of_states));
    IF_STATISTICS(fprintf(PT_log (), "Maximum number of items per state is %d\n", max_nr_items));
    IF_STATISTICS(fprintf(PT_log (), "Average number of items per state is %d\n", (nr_of_items/nr_of_states)));

    for (i=nr_of_states-1; i >= 0; i--) {
      vnr = (ATerm)ATmakeInt(i);
      vertex = ATtableGet(nr_state_pairs,vnr);

      gotos = (ATermList)ATtableGet(state_gotos_pairs,vertex);
      if (!gotos) {
        gotos = ATempty;
      } 
      else {
        IF_STATISTICS(nr_gotos = ATgetLength(gotos));
        IF_STATISTICS(nr_of_gotos += nr_gotos);
        IF_STATISTICS(if (nr_gotos > max_nr_gotos) { max_nr_gotos = nr_gotos;});
      }

      actions = (ATermList)ATtableGet(state_actions_pairs,vertex);
      if (!actions) {
        actions = ATempty;
      }
      else {
        IF_STATISTICS(nr_actions = ATgetLength(actions));
        IF_STATISTICS(nr_of_actions += nr_actions);
        IF_STATISTICS(if (nr_actions > max_nr_actions) { max_nr_actions = nr_actions;});
      }

      newaction = (ATerm)ATmakeAppl1(afun_actions, (ATerm)actions);
      state = (ATerm)ATmakeAppl3(afun_state_rec, vnr, (ATerm)gotos, newaction);

      statelist = ATinsert(statelist,state);
    }

    IF_STATISTICS(fprintf(PT_log (), "Maximum number of gotos per state is %d\n", max_nr_gotos));
    IF_STATISTICS(fprintf(PT_log (), "Average number of gotos per state is %d\n", (nr_of_gotos/nr_of_states)));
    IF_STATISTICS(fprintf(PT_log (), "Maximum number of actions per state is %d\n", max_nr_actions));
    IF_STATISTICS(fprintf(PT_log (), "Average number of actions per state is %d\n", (nr_of_actions/nr_of_states)));

    return ATmake("parse-table(<term>,<term>,states([<list>]),priorities(<term>))",
                  initial_state,labelsection,statelist,priosection);
  }
  else {
    ATerror("Expected grammars, got %t\n", trm);
    return NULL;
  }
}

/*}}}  */
