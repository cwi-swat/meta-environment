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

  if (IS_PROD(prod)) {
    args   = GET_LIST_ARG(prod,0);
    symbol = GET_ARG(prod, 1);
    attrs  = GET_ARG(prod, 2);

    entry = ATtableGet(rhs_prods_pairs,symbol);
    if (entry)
      entry = (ATerm)ATinsert((ATermList)entry,prodnr);
    else
      entry = (ATerm)ATmakeList1(prodnr);
    ATtablePut(rhs_prods_pairs,symbol,entry);
  }
}

/*}}}  */
/*{{{  ATerm process_productions(ATermList prods) */

ATerm process_productions(SDF_ProductionList prods)
{
  ATerm flatprod, aint, labelentry;
  ATermList labelentries = ATempty;
  int ip, cnt = MIN_PROD, nr_of_members, nr_of_kernel_prods;
  SDF_Production prod, newProd;

  SDF_ProductionList localProds = prods;
  while (SDF_hasProductionListHead(localProds)) {
    prod = SDF_getProductionListHead(localProds);
    cnt++;

    if (SDF_isProductionListSingle(localProds)) {
      break;
    }
    localProds = SDF_getProductionListTail(localProds);
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
  while (SDF_hasProductionListHead(prods)) {
    prod = SDF_getProductionListHead(prods);

    flatprod = SDFflattenProd(SDF_makeTermFromProduction(prod));
    if (statisticsMode) {
      nr_of_members = count_members_in_lhs(flatprod);
      if (nr_of_members > max_nr_lhs_members) {
        max_nr_lhs_members = nr_of_members;
      }
      nr_of_lhs_members += nr_of_members;
    }
    newProd = SDF_removeAttributes(prod);

    aint = (ATerm)ATmakeInt(cnt);
    ATtablePut(prod_nr_pairs, SDF_makeTermFromProduction(newProd), aint);
    nr_prod_table[cnt] = flatprod;

    if (SDF_hasRejectAttribute(prod)) {
      ATtablePut(nr_spec_attr_pairs, aint, (ATerm)ATmakeInt(1));
    }
    else if (SDF_hasPreferAttribute(prod)) {
      ATtablePut(nr_spec_attr_pairs, aint, (ATerm)ATmakeInt(2));
    }
    else if (SDF_hasAvoidAttribute(prod)) {
      ATtablePut(nr_spec_attr_pairs, aint, (ATerm)ATmakeInt(4));
    }
    else {
      ATtablePut(nr_spec_attr_pairs, aint, (ATerm)ATmakeInt(0));
    }

    sort_on_rhs_symbol(flatprod, aint);
    init_first(flatprod);

    labelentry = (ATerm)ATmakeAppl2(afun_label, flatprod, aint);
    labelentries = ATinsert(labelentries,labelentry);
    cnt++;

    if (SDF_isProductionListSingle(prods)) {
      break;
    }                                             
    prods = SDF_getProductionListTail(prods);
  }
  nr_of_kernel_prods = cnt - MIN_PROD;

  IF_STATISTICS(fprintf(PT_log (), "Number of kernel productions is %d\n", cnt - MIN_PROD));
  IF_STATISTICS(fprintf(PT_log (), "Maximum number of members per left hand side is %d\n", max_nr_lhs_members));
  IF_STATISTICS(fprintf(PT_log (), "Average number of members per left hand side is %d\n", (nr_of_lhs_members/nr_of_kernel_prods)));

  return ATmake("[<list>]", labelentries);
}

/*}}}  */
/*{{{  ATerm process_priorities(SDF_PriorityList prios) */

ATerm processAssocPriority(SDF_Priority prio)
{
  ATerm leftnr = NULL, rightnr = NULL;
  ATerm prioentry = NULL;
  ATerm newprod;
  ATerm zero = (ATerm)ATmakeInt(0);

  SDF_Group leftGroup = SDF_getPriorityLeft(prio);
  SDF_Group rightGroup = SDF_getPriorityRight(prio);

  if (SDF_isGroupSimpleGroup(leftGroup)) {
    SDF_Production leftProd = SDF_getGroupProduction(leftGroup);
    SDF_Production newProd = SDF_removeAttributes(leftProd);
    leftnr = ATtableGet(prod_nr_pairs,
                        SDF_makeTermFromProduction(newProd));
    if (!leftnr) {
      newprod = SDFflattenProd(SDF_makeTermFromProduction(leftProd));
      if (run_verbose) {
        ATwarning("No rule found for %t\n", newprod);
      }
      leftnr = zero;
    }
  }
  if (SDF_isGroupSimpleGroup(rightGroup)) {
    SDF_Production rightProd = SDF_getGroupProduction(rightGroup);
    SDF_Production newProd = SDF_removeAttributes(rightProd);
    rightnr = ATtableGet(prod_nr_pairs,
                         SDF_makeTermFromProduction(newProd));
    if (!rightnr) {
      newprod = SDFflattenProd(SDF_makeTermFromProduction(rightProd));
      if (run_verbose) {
        ATwarning("No rule found for %t\n", newprod);
      }
      rightnr = zero;
    }
  }
  if (!ATisEqual(leftnr, zero) && !ATisEqual(rightnr, zero)) {
    SDF_Associativity assoc = SDF_getPriorityAssociativity(prio);
    if (SDF_isAssociativityLeft(assoc)) {
      prioentry = (ATerm)ATmakeAppl2(afun_left_prio, 
                                     leftnr, rightnr);
    }
    else if (SDF_isAssociativityRight(assoc)) {
      prioentry = (ATerm)ATmakeAppl2(afun_right_prio, 
                                     leftnr, rightnr);
    }
    else if (SDF_isAssociativityAssoc(assoc)) {
      prioentry = (ATerm)ATmakeAppl2(afun_assoc_prio, 
                                     leftnr, rightnr);
    }
    else if (SDF_isAssociativityNonAssoc(assoc)) {
      prioentry = (ATerm)ATmakeAppl2(afun_non_assoc_prio, 
                                     leftnr, rightnr);
    }
    else {
      ATerror("Associativity expected, got %t\n", assoc);
    }
  }
  else {
    prioentry = NULL;
  }
  return prioentry;
}

ATerm processChainPriority(SDF_Priority prio)
{
  ATerm leftnr = NULL, rightnr = NULL;
  ATerm prioentry = NULL;
  ATerm newprod;
  ATerm zero = (ATerm)ATmakeInt(0);

  SDF_GroupList groupList = SDF_getPriorityList(prio);
  SDF_Group leftGroup, rightGroup;

  if (SDF_isGroupListMany(groupList)) {
    leftGroup = SDF_getGroupListHead(groupList);
    groupList = SDF_getGroupListTail(groupList);
    if (SDF_isGroupListSingle(groupList)) {
      rightGroup = SDF_getGroupListHead(groupList);

      if (SDF_isGroupSimpleGroup(leftGroup)) {
        SDF_Production leftProd = SDF_getGroupProduction(leftGroup);
        SDF_Production newProd = SDF_removeAttributes(leftProd);
        leftnr = ATtableGet(prod_nr_pairs,
                            SDF_makeTermFromProduction(newProd));
        if (!leftnr) {
          newprod = SDFflattenProd(SDF_makeTermFromProduction(leftProd));
          if (run_verbose) {
            ATwarning("No rule found for %t\n", newprod);
          }
          leftnr = zero;
        }
      }
      if (SDF_isGroupSimpleGroup(rightGroup)) {
        SDF_Production rightProd = SDF_getGroupProduction(rightGroup);
        SDF_Production newProd = SDF_removeAttributes(rightProd);
        rightnr = ATtableGet(prod_nr_pairs,
                             SDF_makeTermFromProduction(newProd));
        if (!rightnr) {
          newprod = SDFflattenProd(SDF_makeTermFromProduction(rightProd));
          if (run_verbose) {
            ATwarning("No rule found for %t\n", newprod);
          }
          rightnr = zero;
        }
      }
      if (!ATisEqual(leftnr, zero) && !ATisEqual(rightnr, zero)) {
        prioentry = (ATerm)ATmakeAppl2(afun_gtr_prio, 
                                       leftnr, rightnr);
      }
      else {
        prioentry = NULL;
      }
    }
    else {
      ATerror("priority group has too many arguments: %t\n",
              groupList);
    }
  }
  else {
    ATerror("priority group has too few arguments: %t\n",
            groupList);
  }
  return prioentry;
}

ATerm process_priorities(SDF_PriorityList prios)
{
  ATerm prioentry = NULL;
  ATermList prioentries = ATempty;
  int cnt = 0;

  while (SDF_hasPriorityListHead(prios)) {
    SDF_Priority prio = SDF_getPriorityListHead(prios);
    
    cnt++;
    if (SDF_isPriorityAssoc(prio)) {
      prioentry = processAssocPriority(prio);
    }
    else if (SDF_isPriorityChain(prio)) {
      prioentry = processChainPriority(prio);
    }
    else {
      ATerror("expected priority rule, got %t\n", prio);
    }

    if (prioentry) {
      ATtablePut(priority_table, prioentry, (ATerm)ATmakeInt(cnt));
      prioentries = ATinsert(prioentries, prioentry);
    }
  
    if (SDF_isPriorityListSingle(prios)) {
      break;
    }
    prios = SDF_getPriorityListTail(prios);
  }

  IF_STATISTICS(fprintf(PT_log (), "Number of priorities is %d\n", cnt));

  return ATmake("[<list>]",prioentries);
}

/*}}} */
/*{{{ void process_restrictions(SDF_RestrictionList restricts) */

void process_restrictions(SDF_RestrictionList restricts)
{
  int cnt = 0;

  while (SDF_hasRestrictionListHead(restricts)) {
    SDF_Restriction restrict = SDF_getRestrictionListHead(restricts);

    cnt++;
    if (SDF_isRestrictionFollow(restrict)) {
      SDF_Symbols symbols = SDF_getRestrictionSymbols(restrict);
      SDF_SymbolList symbolList = SDF_getSymbolsList(symbols);
      SDF_Lookaheads lookaheads = SDF_getRestrictionLookaheads(restrict);

      if (SDF_isLookaheadsList(lookaheads)) {
        SDF_LookaheadList lookaheadList = SDF_getLookaheadsList(lookaheads);
        ATermList newLookaheads = ATempty;

        while (SDF_hasLookaheadListHead(lookaheadList)) {
          SDF_Lookahead lookahead = SDF_getLookaheadListHead(lookaheadList);

          ATerm newLookahead = SDFflattenLookAhead(
                                 SDF_makeTermFromLookahead(lookahead),
                                 ATfalse);
          newLookaheads = ATappend(newLookaheads, newLookahead);
          
          if (SDF_isLookaheadListSingle(lookaheadList)) {
            break;
          }
          lookaheadList = SDF_getLookaheadListTail(lookaheadList);
        }
 
        while (SDF_hasSymbolListHead(symbolList)) {
          SDF_Symbol symbol = SDF_getSymbolListHead(symbolList);
          ATerm newsymbol = SDFflattenSymbol(SDF_makeTermFromSymbol(symbol));
  
          ATermList oldLookaheads = 
                      (ATermList)ATtableGet(symbol_lookaheads_table, newsymbol);
          if (oldLookaheads) {
            newLookaheads = ATconcat(oldLookaheads, newLookaheads);
          }
          ATtablePut(symbol_lookaheads_table, newsymbol, 
                     (ATerm)newLookaheads);
  
          if (SDF_isSymbolListSingle(symbolList)) {
            break;
          }
          symbolList = SDF_getSymbolListTail(symbolList);
        }
      }
      else {
        ATerror("expected lookaheads, got %t\n", lookaheads);
      }

    }

    if (SDF_isRestrictionListSingle(restricts)) {
      break;
    }
    restricts = SDF_getRestrictionListTail(restricts);
  }
}

/*}}}  */
/*{{{  ATerm generate_parse_table(ATerm t) */

ATerm generate_parse_table(PT_ParseTree g)
{
  int i, nr_actions, nr_gotos;
  ATerm labelsection, priosection, vnr, vertex, state, newaction;
  ATermList statelist = ATempty, gotos, actions;

  PT_Tree ptTree = PT_getParseTreeTree(g);
  
  SDF_Grammar grammarTerm = SDF_makeGrammarFromTerm(
                              PT_makeTermFromTree(ptTree));
  if (SDF_isValidGrammar(grammarTerm)) {
    SDF_ProductionList  prods = SDF_getGrammarKernelProductions(grammarTerm);
    SDF_PriorityList    prios = SDF_getGrammarKernelPriorities(grammarTerm);
    SDF_RestrictionList restricts =
                          SDF_getGrammarKernelRestrictions(grammarTerm);
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
    ATerror("Expected grammars, got %t\n", grammarTerm);
    return NULL;
  }
}

/*}}}  */
