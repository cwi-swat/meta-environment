/* $Id$ */

#include <assert.h>
#include <aterm2.h>
#include <logging.h>
#include "ksdf2table.h" 
#include "priorities.h" 
#include "flatten.h"
#include "first.h"
#include "pgenOptions.h"
#include "parseTable-data.h"
#include "parseTable-stats.h"

/*#include <unistd.h>
#include <ptable.h>
#include <rsrc-usage.h>
#include "characters.h"
#include "intset.h"
#include "pgen-symbol.h"
#include "follow.h"*/

typedef struct _GotoBucket {
  int nr_entries;
  int *entries;
} GotoBucket;

static PTBL_Labels labelsection;
static PTBL_Priorities priosection;

PTBL_Labels PGEN_getLabelSection() {
  return labelsection;
}

PTBL_Priorities PGEN_getPrioSection() {
  return priosection;
}

/* Group the production rule numbers with the same rhs symbol together. */
static void sort_on_rhs_symbol(PT_Production prod, int prodnr) {
  PT_Symbols args;
  PT_Symbol symbol;
  PT_Attributes attrs;

  if (PT_isValidProduction(prod)) {
    args   = PT_getProductionLhs(prod);
    symbol = PT_getProductionRhs(prod);
    attrs  = PT_getProductionAttributes(prod);

    PGEN_addProductionNumberOfRhsNonTerminal(symbol, prodnr);
  }
}

/* Assign production numbers, group productions on rhs symbol, save 
 * attributes and initialize first set attributes. */
static PTBL_Labels process_productions(SDF_ProductionList prods) {
  ATermIndexedSet unique_prods = ATindexedSetCreate(1024, 75);
  SDF_ProductionList localProds = prods;
  SDF_Production prod; 
  SDF_Production newProd;
  PTBL_Label labelentry;
  PTBL_Labels labelentries = PTBL_makeLabelsEmpty();
  PT_Production ptProd;
  PT_Symbols args;
  ATbool isnew;
  int cnt = 0;
  int idx; 
  int max_idx = 0;
  int arg; 
  int nr_args;
  int maxProdNumber;

  while (SDF_hasProductionListHead(localProds)) {
    prod = SDF_getProductionListHead(localProds);
    idx = ATindexedSetPut(unique_prods, (ATerm)prod, &isnew);
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

  maxProdNumber = cnt + MIN_PROD_NUM;
  PGEN_setMaxProductionNumber(maxProdNumber);
  PGEN_initProductionTables(maxProdNumber, MIN_PROD_NUM);
  PGEN_STATS_setCount(PGEN_STATS_kernelProductions, max_idx);

  for (idx=0; idx<=max_idx; idx++) {
    ATerm sdfflatprod = ATindexedSetGetElem(unique_prods, idx);
    assert(sdfflatprod);
    prod   = SDF_ProductionFromTerm(sdfflatprod);
    ptProd = SDFProductionToPtProduction(prod);

    PGEN_STATS_setMaxProductionLhsSymbols(PT_getSymbolsLength(PT_getProductionLhs(ptProd)));
    newProd = SDF_removeAttributes(prod);

    cnt = idx + MIN_PROD_NUM;
    PGEN_setProductionNumberOfProduction(cnt, newProd);
    PGEN_setProductionOfProductionNumber(ptProd, cnt);
    args = PT_getProductionLhs(ptProd);
    nr_args = PT_getSymbolsLength(args)+1;

    PGEN_allocateSymbolTable(cnt, nr_args);

    arg = 0;
    while (!PT_isSymbolsEmpty(args)) {
      PGEN_setLhsSymbolAtPositionXOfProductionNumber(PT_getSymbolsHead(args), arg++, cnt);
      args = PT_getSymbolsTail(args);
    }
    PGEN_setLhsSymbolAtPositionXOfProductionNumber(PT_makeSymbolEmpty(), arg++, cnt);

    if (SDF_hasRejectAttribute(prod)) {
      PGEN_setAttributeOfProductionNumber(1, cnt);
    }
    else if (SDF_hasPreferAttribute(prod)) {
      PGEN_setAttributeOfProductionNumber(2, cnt);
    }
    else if (SDF_hasAvoidAttribute(prod)) {
      PGEN_setAttributeOfProductionNumber(4, cnt);
    }
    else {
      PGEN_setAttributeOfProductionNumber(0, cnt);
    }

    sort_on_rhs_symbol(ptProd, cnt);
    init_prod_first(ptProd);

    labelentry = PTBL_makeLabelDefault((PTBL_Production)ptProd, cnt);
    labelentries = PTBL_makeLabelsMany(labelentry,labelentries);
  }

  ATindexedSetDestroy(unique_prods);

  return labelentries;
}

static int getProductionNumberForGroup(SDF_Group group) {
  int nr = 0;

  if (SDF_isGroupSimpleGroup(group)) {
    SDF_Production prod = SDF_getGroupProduction(group);
    nr = PGEN_getProductionNumberOfProduction(prod);
  }
  return nr;
}

static int getGroupArgument(SDF_Group group) {
  SDF_NatCon arg;
  char* value;
  SDF_ArgumentIndicator ai = SDF_getGroupArgumentIndicator(group);
  SDF_NatConArguments nats = SDF_getArgumentIndicatorArguments(ai);

  if (!SDF_isNatConArgumentsSingle(nats)) {
    ATerror("group argument had too many elements: %t\n", group);
  }

  arg = SDF_getNatConArgumentsHead(nats);
  value = PT_yieldTree((PT_Tree) arg);

  return atoi(value);
}

static PTBL_Priority processChainPriority(SDF_Priority prio, ATbool *nonTransitive) {
  int leftnr = 0, rightnr = 0;
  PTBL_Priority prioentry = NULL;

  SDF_GroupList groupList = SDF_getPriorityList(prio);
  SDF_Group leftGroup, rightGroup;

  if (SDF_isGroupListMany(groupList)) {
    leftGroup = SDF_getGroupListHead(groupList);
    groupList = SDF_getGroupListTail(groupList);

    if (SDF_isGroupListSingle(groupList)) {
      rightGroup = SDF_getGroupListHead(groupList);

      if (SDF_isGroupNonTransitive(leftGroup)) {
        *nonTransitive = ATtrue;
        leftGroup = SDF_getGroupGroup(leftGroup);
      }
      else {
        *nonTransitive = ATfalse;
      }

      if (SDF_isGroupSimpleGroup(leftGroup)) {
        leftnr = getProductionNumberForGroup(leftGroup);
      }
      else if (SDF_isGroupWithArguments(leftGroup)) {
        leftnr = getProductionNumberForGroup(SDF_getGroupGroup(leftGroup));
      }
      else {
        ATerror("illegal priority  group: %t\n", leftGroup);
      }

      if (SDF_isGroupSimpleGroup(rightGroup)) {
        rightnr = getProductionNumberForGroup(rightGroup);
      }
      else if (SDF_isGroupWithArguments(rightGroup)) {
        rightnr = getProductionNumberForGroup(SDF_getGroupGroup(rightGroup));
      }
      else {
        ATerror("illegal priority  group: %t\n", rightGroup);
      }

      if (leftnr != 0 && rightnr != 0) {
        if (SDF_isGroupWithArguments(leftGroup)) {
          int argNumber = getGroupArgument(leftGroup);
          prioentry = PTBL_makePriorityArgGreater(leftnr, argNumber, rightnr);
        }
        else {
          prioentry = PTBL_makePriorityGreater(leftnr, rightnr);
        }
      }
      else {
        prioentry = NULL;
      }
    }
    else {
      ATerror("priority group has too many arguments: %t\n", groupList);
    }
  }
  else {
    ATerror("priority group has too few arguments: %t\n", groupList);
  }
  return prioentry;
}

static PTBL_Priorities process_priorities(SDF_PriorityList prios) {
  PTBL_Priority prioentry = NULL;
  PTBL_Priorities prioentries = PTBL_makePrioritiesEmpty();
  PTBL_Priorities nonTransitivePrioEntries = PTBL_makePrioritiesEmpty();
  SDF_PriorityList localPrios = prios;
  PTBL_Priorities loop = NULL;
  ATbool isnew;
  int cnt = 0;
  int idx;
  int localIdx1; 
  int localIdx2;
  int max_idx; 

  /* Store the chain priorities */
  max_idx = -1;
  while (SDF_hasPriorityListHead(localPrios)) {
    ATbool nonTransitive;
    SDF_Priority prio = SDF_getPriorityListHead(localPrios);

    assert(!SDF_isPriorityAssoc(prio) && "assoc should be normalized to prio");

    if (SDF_isPriorityChain(prio)) {
      nonTransitive = ATfalse;
      prioentry = processChainPriority(prio, &nonTransitive);
    }
    else {
      ATwarning("process_priorities: illegal priority encountered: %t\n", prio);
      prioentry = NULL;
    }

    if (prioentry) {
      if (nonTransitive) {
        nonTransitivePrioEntries = PTBL_makePrioritiesMany(prioentry, nonTransitivePrioEntries);
      }
      else {
        idx = PGEN_putPriority(prioentry, &isnew);
        if (isnew) {
          if (idx > max_idx) {
            max_idx = idx;
          } 

          prioentries = PTBL_makePrioritiesMany(prioentry, prioentries);
        }
      }
      cnt++;
    }

    if (SDF_isPriorityListSingle(localPrios)) {
      break;
    }
    localPrios = SDF_getPriorityListTail(localPrios);
  }

  /* Calculate the transitive closure of the priorities */
  for (localIdx1=0; localIdx1<=max_idx; localIdx1++) {    
    PTBL_Priority prioentry1 = PGEN_getPriority(localIdx1);
    int rightnr1 = PTBL_getPriorityLabel2(prioentry1);

    for (localIdx2=0; localIdx2<=max_idx; localIdx2++) {    
      PTBL_Priority prioentry2 = PGEN_getPriority(localIdx2);
      int leftnr2 = PTBL_getPriorityLabel1(prioentry2);

      if (rightnr1 == leftnr2) {
        int rightnr2 = PTBL_getPriorityLabel2(prioentry2);

        prioentry = PTBL_setPriorityLabel2(prioentry1, rightnr2);
        idx = PGEN_putPriority(prioentry, &isnew);
        if (isnew) {
          if (idx > max_idx) {
            max_idx = idx;
          } 
          prioentries = PTBL_makePrioritiesMany(prioentry, prioentries);
          cnt++;
        }
      }
    }
  }

  /* Removed in merge.
     while (SDF_hasPriorityListHead(prios)) {
     SDF_Priority prio = SDF_getPriorityListHead(prios);
     
     if (SDF_isPriorityAssoc(prio)) {
     ATabort("Assoc priorities may not occur after normalization %t\n", prio);
     prioentry = NULL;
     }

     if (prioentry) {
     PGEN_putPriority(prioentry, &isnew);
     if (isnew) {
     prioentries = PTBL_makePrioritiesMany(prioentry, prioentries);
     cnt++;
     }
     }

     if (SDF_isPriorityListSingle(prios)) {
     break;
     }
     prios = SDF_getPriorityListTail(prios);
     }
  */
  
  loop = nonTransitivePrioEntries;
  while(!PTBL_isPrioritiesEmpty(loop)) {
    PTBL_Priority next = PTBL_getPrioritiesHead(loop);
    idx = PGEN_putPriority(next, &isnew);
    if (isnew) {
      cnt++;
    }
    loop = PTBL_getPrioritiesTail(loop);
  }


  PGEN_STATS_setCount(PGEN_STATS_priorities, cnt);

  /** \todo make sure that this concatenation is correct. */
  return PTBL_concatPriorities(prioentries, nonTransitivePrioEntries);
}

/* Process the grammar's follow restrictions and associate all defined 
 * lookaheads to the approapriate non-terminals. */
static void process_restrictions(SDF_RestrictionList restricts) {
  int cnt = 0;

  /* For each follow restriction defined... */
  while (SDF_hasRestrictionListHead(restricts)) {
    SDF_Restriction restrict = SDF_getRestrictionListHead(restricts);

    cnt++;
    if (SDF_isRestrictionFollow(restrict)) {
      SDF_Symbols symbols = SDF_getRestrictionSymbols(restrict);
      SDF_SymbolList symbolList = SDF_getSymbolsList(symbols);
      SDF_Lookaheads lookaheads = SDF_getRestrictionLookaheads(restrict);

      /* The lookaheads have already been normalized to LookaheadsList. */
      if (SDF_isLookaheadsList(lookaheads)) {
        SDF_LookaheadList lookaheadList = SDF_getLookaheadsList(lookaheads);
        PTBL_Restrictions restrictions = PTBL_makeRestrictionsEmpty();

        /* Process the new lookaheads defined in the current follow 
         * restriction. */
        while (SDF_hasLookaheadListHead(lookaheadList)) {
          SDF_Lookahead lookahead = SDF_getLookaheadListHead(lookaheadList);

          PTBL_Restriction restriction = implodeLookahead(lookahead);
          restrictions = PTBL_appendRestrictions(restrictions, restriction);

          if (SDF_isLookaheadListSingle(lookaheadList)) {
            break;
          }
          lookaheadList = SDF_getLookaheadListTail(lookaheadList);
        }

        /* Get any existing lookaheads for the symbols in the current follow 
         * restriction (other lookaheads may have been defined in previous 
         * follow restrictions) and add the new lookaheads to the symbol's 
         * follow restrictions. */
        while (SDF_hasSymbolListHead(symbolList)) {
          SDF_Symbol symbol = SDF_getSymbolListHead(symbolList);
          PT_Symbol symbolPT = SDFSymbolToPtSymbol(symbol);

          PTBL_Restrictions oldRestrictions = PGEN_getLookaheadsOfSymbol(symbolPT);
          if (oldRestrictions) {
            restrictions = PTBL_concatRestrictions(oldRestrictions, restrictions);
          }
          PGEN_setLookaheadsOfSymbol(restrictions, symbolPT);

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
    while (i % BITS_PER_LONG == (BITS_PER_LONG - 1) && set[i/BITS_PER_LONG] == 0) {
      i -= BITS_PER_LONG;
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

/* Process a grammar and extract the productions, follow restrictions and 
 * priorities. */
void PGEN_processGrammar(PT_Tree ptTree) {
  SDF_Grammar grammarTerm = SDF_GrammarFromTerm(PT_TreeToTerm(ptTree));

  if (SDF_isValidGrammar(grammarTerm)) {
    SDF_ProductionList  prods = SDF_getGrammarKernelProductions(grammarTerm);
    SDF_PriorityList    prios = SDF_getGrammarKernelPriorities(grammarTerm);
    SDF_RestrictionList restricts = SDF_getGrammarKernelRestrictions(grammarTerm);

    labelsection = process_productions(prods);
    priosection = process_priorities(prios);

    PTBL_protectLabels(&labelsection);
    PTBL_protectPriorities(&priosection); 

    process_restrictions(restricts);
  }
  else {
    ATwarning("parsetablegen: unexpected error in syntax definition!\n");
    ATwarning("\tdumped grammar to ./parsetablegen.bug\n");
    ATwriteToNamedTextFile((ATerm) grammarTerm, "./parsetablegen.bug");
  }
}
