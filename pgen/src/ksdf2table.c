/*{{{  includes */

#include <unistd.h>
#include <assert.h>

#include <aterm2.h>

#include "ksdf2table.h" 
#include "flatten.h"
#include "statistics.h"
#include "characters.h"
#include "intset.h"
#include "first.h"
#include "pgen-symbol.h"
#include "follow.h"

/*}}}  */

/*{{{  types */

typedef struct _GotoBucket
{
  int nr_entries;
  int *entries;
} GotoBucket;

/*}}}  */
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
ATerm eof_token;
ATerm all_chars;   
extern ATbool run_verbose;
extern ATbool statisticsMode;

/*}}}  */
/*{{{  function declarations */

void calc_goto_graph();

/*}}}  */
/*{{{  AFuns */

AFun afun_action = 0;
AFun afun_char_class = 0;
AFun afun_goto = 0;
AFun afun_prod = 0;
AFun afun_range = 0;
AFun afun_shift = 0;
AFun afun_non_assoc_prio = 0;
AFun afun_gtr_prio = 0;
AFun afun_left_prio = 0;
AFun afun_right_prio = 0;
AFun afun_assoc_prio = 0;
AFun afun_state_rec = 0;
AFun afun_label = 0;
AFun afun_lit = 0;

/*}}}  */
/*{{{  Declaration of tables used during generation process */

static ATermTable prod_nr_pairs;
ATermTable nr_flatprod_pairs;
ATermTable nr_spec_attr_pairs;
ATermTable symbol_lookaheads_table;
ATermIndexedSet priority_table;
ATermTable rhs_prods_pairs;
ATerm *nr_prod_table;
ATerm **symbol_table;

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
  priority_table = ATindexedSetCreate(1024,75);
  symbol_lookaheads_table = ATtableCreate(1024,75);
  rhs_prods_pairs = ATtableCreate(1024,75);
  state_nr_pairs = ATtableCreate(1024,75);
  nr_state_pairs = ATtableCreate(1024,75);
  state_gotos_pairs = ATtableCreate(1024,75);
  state_actions_pairs = ATtableCreate(1024,75);
  state_sos = ATsosCreate(8501);
  
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
  afun_state_rec = ATmakeAFun("state-rec", 3, ATfalse);
  ATprotectAFun(afun_state_rec);
  afun_label = ATmakeAFun("label", 2, ATfalse);
  ATprotectAFun(afun_label);
  afun_lit = ATmakeAFun("lit", 1, ATfalse);
  ATprotectAFun(afun_lit);

  initSymbols();
  CC_init();
  init_first();
}

/*}}}  */
/*{{{  void destroy_table_gen() */

void destroy_table_gen()
{
  int i;

  destroy_first();
  destroy_follow_table();
  CC_cleanup();
  destroySymbols();

  ATunprotectArray((ATerm *)nr_prod_table+MIN_PROD);
  free(nr_prod_table);

  for (i=0; i<MAX_PROD; i++) {
    if (symbol_table[i]) {
      free(symbol_table[i]);
    }
  }
  free(symbol_table);

  ATtableDestroy(prod_nr_pairs);
  ATtableDestroy(nr_spec_attr_pairs);
  ATindexedSetDestroy(priority_table);
  ATtableDestroy(symbol_lookaheads_table);
  ATtableDestroy(rhs_prods_pairs);
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
  int cnt, nr_of_members, nr_of_kernel_prods;
  SDF_Production prod, newProd;
  PT_Production ptProd;
  ATbool isnew;
  int idx, max_idx;
  ATermIndexedSet unique_prods;
  int arg, nr_args;
  ATermList args;

  SDF_ProductionList localProds = prods;
  unique_prods = ATindexedSetCreate(1024, 75);
  cnt = 0;
  max_idx = 0;
  while (SDF_hasProductionListHead(localProds)) {
    prod = SDF_getProductionListHead(localProds);
    flatprod = SDF_ProductionToTerm(prod);
    idx = ATindexedSetPut(unique_prods, flatprod, &isnew);
    if (isnew) {
      if (idx > max_idx) {
	max_idx = idx;
      }
      assert(cnt == max_idx);
      cnt++;
    }

    if (SDF_isProductionListSingle(localProds)) {
      break;
    }
    localProds = SDF_getProductionListTail(localProds);
  }
  cnt += MIN_PROD;
  MAX_PROD = cnt;
  assert(cnt-MIN_PROD == (max_idx+1));

  nr_prod_table = (ATerm *)calloc(MAX_PROD, sizeof(ATerm));
  symbol_table  = (ATerm **)calloc(MAX_PROD, sizeof(ATerm *));

  if (!nr_prod_table || !symbol_table) {
    ATerror("out of memory!\n");
  }

  ATprotectArray((ATerm *)nr_prod_table+MIN_PROD, MAX_PROD-MIN_PROD);

  for (idx=0; idx<=max_idx; idx++) {
    ATerm sdfflatprod = ATindexedSetGetElem(unique_prods, idx);
    assert(sdfflatprod);
    prod   = SDF_ProductionFromTerm(sdfflatprod);
    ptProd = SDFProductionToPtProduction(prod);
    flatprod = PT_makeTermFromProduction(ptProd);
                 
    if (statisticsMode) {
      nr_of_members = PT_getSymbolsLength(PT_getProductionLhs(ptProd));
      if (nr_of_members > max_nr_lhs_members) {
        max_nr_lhs_members = nr_of_members;
      }
      nr_of_lhs_members += nr_of_members;
    }
    newProd = SDF_removeAttributes(prod);

    cnt = idx + MIN_PROD;
    aint = (ATerm)ATmakeInt(cnt);
    ATtablePut(prod_nr_pairs, SDF_makeTermFromProduction(newProd), aint);
    nr_prod_table[cnt] = flatprod;
    args = (ATermList)ATgetArgument((ATermAppl)flatprod, 0);
    nr_args = ATgetLength(args)+1;
    symbol_table[cnt] = (ATerm *)malloc(nr_args*sizeof(ATerm));
    if (symbol_table[cnt] == NULL) {
      ATerror("cannot allocate symboltable (%d)\n", nr_args);
    }
    arg = 0;
    while (!ATisEmpty(args)) {
      symbol_table[cnt][arg++] = ATgetFirst(args);
      args = ATgetNext(args);
    }
    symbol_table[cnt][arg++] = empty_set;

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
    init_prod_first(flatprod);

    labelentry = (ATerm)ATmakeAppl2(afun_label, flatprod, aint);
    labelentries = ATinsert(labelentries,labelentry);
  }
  nr_of_kernel_prods = max_idx;

  IF_STATISTICS(fprintf(PT_log (), "Number of kernel productions is %d\n", max_idx));
  IF_STATISTICS(fprintf(PT_log (), "Maximum number of members per left hand side is %d\n", max_nr_lhs_members));
  IF_STATISTICS(fprintf(PT_log (), "Average number of members per left hand side is %d\n", (nr_of_lhs_members/nr_of_kernel_prods)));

  ATindexedSetDestroy(unique_prods);

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
      newprod = PT_ProductionToTerm(SDFProductionToPtProduction(leftProd));
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
      newprod = PT_ProductionToTerm(SDFProductionToPtProduction(rightProd));
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
          newprod = PT_ProductionToTerm(SDFProductionToPtProduction(leftProd));
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
          newprod = PT_ProductionToTerm(SDFProductionToPtProduction(rightProd));
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
  ATbool isnew;
  int idx, localIdx1, localIdx2, max_idx; 
  SDF_PriorityList localPrios = prios;

/* Store the chain priorities */
  max_idx = -1;
  while (SDF_hasPriorityListHead(localPrios)) {
    SDF_Priority prio = SDF_getPriorityListHead(localPrios);
    
    if (SDF_isPriorityChain(prio)) {
      prioentry = processChainPriority(prio);
    }

    if (prioentry) {
      idx = ATindexedSetPut(priority_table, prioentry, &isnew);
      if (isnew) {
        if (idx > max_idx) {
          max_idx = idx;
        } 
	prioentries = ATinsert(prioentries, prioentry);
	cnt++;
      }
    }
  
    if (SDF_isPriorityListSingle(localPrios)) {
      break;
    }
    localPrios = SDF_getPriorityListTail(localPrios);
  }

/* Calculate the transitive closure of the chain priorities */
  for (localIdx1=0; localIdx1<=max_idx; localIdx1++) {    
    ATermAppl prioentry1 = 
      (ATermAppl)ATindexedSetGetElem(priority_table, localIdx1);
    ATerm rightnr1 = ATgetArgument(prioentry1, 1);

    for (localIdx2=0; localIdx2<=max_idx; localIdx2++) {    
      ATermAppl prioentry2 = 
                  (ATermAppl)ATindexedSetGetElem(priority_table, localIdx2);
      ATerm leftnr2 = ATgetArgument(prioentry2, 0);

      if (ATisEqual(rightnr1, leftnr2)) {
        ATerm leftnr1 = ATgetArgument(prioentry1, 0);
        ATerm rightnr2 = ATgetArgument(prioentry2, 1);
        prioentry = (ATerm)ATmakeAppl2(afun_gtr_prio, 
                                       leftnr1, rightnr2);
        idx = ATindexedSetPut(priority_table, prioentry, &isnew);
        if (isnew) {
          if (idx > max_idx) {
            max_idx = idx;
          } 
	  prioentries = ATinsert(prioentries, prioentry);
	  cnt++;
        }
      }
    }
  }

/* Store the associativity priorities */
  while (SDF_hasPriorityListHead(prios)) {
    SDF_Priority prio = SDF_getPriorityListHead(prios);
    
    if (SDF_isPriorityAssoc(prio)) {
      prioentry = processAssocPriority(prio);
    }

    if (prioentry) {
      ATindexedSetPut(priority_table, prioentry, &isnew);
      if (isnew) {
	prioentries = ATinsert(prioentries, prioentry);
	cnt++;
      }
    }
  
    if (SDF_isPriorityListSingle(prios)) {
      break;
    }
    prios = SDF_getPriorityListTail(prios);
  }

  IF_STATISTICS(fprintf(PT_log (), "Number of priorities is %d\n", cnt));

  return ATmake("[<list>]", prioentries);
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

          ATerm newLookahead = SDFflattenLookAhead(lookahead, ATfalse);
          newLookaheads = ATappend(newLookaheads, newLookahead);
          
          if (SDF_isLookaheadListSingle(lookaheadList)) {
            break;
          }
          lookaheadList = SDF_getLookaheadListTail(lookaheadList);
        }
 
        while (SDF_hasSymbolListHead(symbolList)) {
          SDF_Symbol symbol = SDF_getSymbolListHead(symbolList);
          ATerm newsymbol = PT_SymbolToTerm(SDFSymbolToPtSymbol(symbol));
  
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

#if 0
/*{{{  static ATerm intset_to_term(IS_IntSet set) */

static ATerm intset_to_term(IS_IntSet set)
{
  ATermList range_set = ATempty;
  ATerm elem;
  int i, start, end;

  assert(afun_range >= 0);

  for (i=MAX_PROD; i>=0; i--) {
    while (i % 32 == 31 && set[i/32] == 0) {
      i -= 32;
      if (i == -1) {
	return (ATerm)range_set;
      }
    }
    if (IS_contains(set, i)) {
      end   = i;
      start = end-1;

      while (start>=0 && IS_contains(set, start)) {
	start--;
      }

      if (start < (end-1)) {
	/* Add a range */
	elem = (ATerm)ATmakeAppl2(afun_range, (ATerm)ATmakeInt(start+1),
				  (ATerm)ATmakeInt(end));
      } else {
	elem = (ATerm)ATmakeInt(end);
      }

      range_set = ATinsert(range_set, elem);

      i = start;
    }
  }

  return (ATerm)range_set;
}

/*}}}  */
/*{{{  static ATermList compress_gotos(ATermList goto_list) */

static ATermList compress_gotos(ATermList goto_list)
{
  static IS_IntSet *prodsets = NULL;
  static int *occupied_sets = NULL;
  static int prev_nr_of_states = -1;
  int nr_occupied_sets = 0, prod, state, idx;
  ATermAppl gt;
  ATermList result, list;
  ATerm elem;
  IS_IntSet set;

  if (prev_nr_of_states != nr_of_states) {
    int size = nr_of_states*sizeof(IS_IntSet);
    prodsets = (IS_IntSet *)realloc(prodsets, size);
    if (prodsets == NULL) {
      ATerror("out of memory in compress_gotos(%d)\n", size);
    }
    memset(prodsets, 0, size);

    size = nr_of_states*sizeof(int);
    occupied_sets = (int *)realloc(occupied_sets, size);
    if (occupied_sets == NULL) {
      ATerror("out of memory in compress_gotos(%d) 2\n", size);
    }
    memset(occupied_sets, 0, size);
  }

  result = ATempty;
  while (!ATisEmpty(goto_list)) {
    gt    = (ATermAppl)ATgetFirst(goto_list);
    list  = (ATermList)ATgetArgument(gt, 0);
    assert(ATgetLength(list) > 0);
    elem = ATgetFirst(list);
    if (ATgetLength(list) == 1 && ATgetType(elem) == AT_INT) {
      prod  = ATgetInt((ATermInt)elem);
      state = ATgetInt((ATermInt)ATgetArgument(gt, 1));

      set = prodsets[state];
      if (set == NULL) {
	set = IS_create(MAX_PROD);
	prodsets[state] = set;
	occupied_sets[nr_occupied_sets++] = state;
      }
      IS_add(set, prod);
    } else {
      result = ATinsert(result, (ATerm)gt);
    }

    goto_list = ATgetNext(goto_list);
  }

  for (idx=0; idx<nr_occupied_sets; idx++) {
    state = occupied_sets[idx];
    set   = prodsets[state];
    assert(set);
    gt = ATmakeAppl2(afun_goto, intset_to_term(set), (ATerm)ATmakeInt(state));
    result = ATinsert(result, (ATerm)gt);
    IS_destroy(prodsets[state]);
    prodsets[state] = NULL;
  }

  return result;
}

/*}}}  */
#endif

/*{{{  ATerm generate_parse_table(int version_nr, ATerm t) */

ATerm generate_parse_table(int version_nr, PT_ParseTree g)
{
  int i, nr_actions = 0, nr_gotos = 0;
  ATerm labelsection, priosection, vnr, vertex, state;
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

      /*ATwarning("actions before compression (vnr=%t) = %t\n", vnr, actions);*/
      /*gotos   = compress_gotos(gotos);*/

      state = (ATerm)ATmakeAppl3(afun_state_rec, vnr, (ATerm)gotos, (ATerm)actions);

      statelist = ATinsert(statelist,state);
    }
 
    IF_STATISTICS(fprintf(PT_log (), "Maximum number of gotos per state is %d\n", max_nr_gotos));
    IF_STATISTICS(fprintf(PT_log (), "Average number of gotos per state is %d\n", (nr_of_gotos/nr_of_states)));
    IF_STATISTICS(fprintf(PT_log (), "Maximum number of actions per state is %d\n", max_nr_actions));
    IF_STATISTICS(fprintf(PT_log (), "Average number of actions per state is %d\n", (nr_of_actions/nr_of_states)));

    return ATmake("parse-table(<term>,<term>,<term>,states([<list>]),priorities(<term>))",
                  ATmakeInt(version_nr),
                  initial_state,labelsection,statelist,priosection);
  }
  else {
    ATwarning("parsetablegen: unexpected error in syntax definition!\n");
    ATwarning("\tgrammar is: %s\n", PT_yieldTree((PT_Tree) grammarTerm));
    return NULL;
  }
}

/*}}}  */
