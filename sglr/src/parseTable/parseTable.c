/*$Id$*/

/** \file
 * \ingroup parseTable
 * Implementation of the internal representation of parse tables: creation, 
 * lookup, maintenance.
 *
 * \section tables Implementation of parse tables
 *
 * The action table contains the shift and reduce actions.
 * The goto table contains the goto actions that get queried after a reduce has 
 * been done. The standard goto table can be thought of a two-dimensional table
 * indexed by (state number, non-terminal). However, due to the priorities in
 * SDF2, pgen uses productions instead of non-terminals to index into the table.
 * The goto table tends to be quite sparse.
 *
 *
 * Parsing is done token by token (a token is a character in SGLR).  When 
 * looking up matching actions (or states), we have to return all actions 
 * (states) belonging to all character classes containing the token.
 *
 * This is fairly difficult when the lookup tables for actions and gotos
 * are represented in a straightforward manner, i.e. when the parse
 * table's character class terms are used as keys in an ATerm hash table:
 * in that approach, we'd have to find out first which character class
 * keys in the lookup table contain the token, which is cumbersome and costly.
 *
 * For that reason, character classes are `expanded' in representation:
 * whenever a charater range occurs in the parse table, the corresponding
 * action (state) is seperately incorporated in the lookup table for
 * all characters in the range; because of the Aterm Libary's maximal
 * sharing, this can be done at the cost of minimal overhead.  However,
 * a full (two-dimensional) expansion for action and goto table, both
 * of which are sparsely filled, imposes severe memory requirements.
 * For that reason, action and goto tables are represented as sparse
 * tables by means of dedicated hashing.
 *
 * \subsection actionTable The action table
 *
 * The data structure used to implement the action table is a one dimensional 
 * array of PTBL_Actions. The indexing function into the table is relatively 
 * straight forward. Because we only parse strings of ASCII characters, the 
 * maximum number of entries in a state is 257: 0-255 + the end-of-string 
 * character. The memory allocated for the action table is the 
 * (number of states * 257). The indexing function into the table is done by 
 * (state*MaxNumOfStates+inputSymbol). 
 *
 * \subsection gotoTable The goto table
 *
 * The goto table is used by the parser to find the state to move to after a 
 * reduction has been done. Each entry in the goto table consists of the 
 * source state, the production number and the target state and is indexed on
 * the source state and the production number.
 *
 * A hash table is used to implement the goto table. It is a two-dimensional
 * array. The size of the first dimension is dependant on the number of goto 
 * entries.
 *
 * The memory used for the goto table is allocated in 8MB chuncks. Once the 
 * first chunk is filled, a second chunck is allocated, and so on. The 
 * regression tests allocate at most 4 chuncks.
 */

#include "parseTable.h"
#include "tokens.h"
#include "mem-alloc.h"
#include "mainOptions.h" 
#include "ptable.h"
#include "parserStatistics.h"

#include <MEPT-utils.h>
#include <assert.h>

typedef PT_Production   *productiontable;
typedef ATermTable       injectiontable;
typedef ATermTable       prioritytable;
typedef ATermTable       argprioritytable;
typedef ATermIndexedSet  productionset;

typedef struct _gbucket {
  struct _gbucket *next;
  int              from;
  int              prodNum;
  int              to;
} gotobucket;

typedef struct _gototable {
  gotobucket **table;
  size_t     size;
  size_t     sizeclass;
} gototable;

struct _ParseTable {
  int              startState;
  size_t           numstates;
  size_t           numprods;
  PTBL_Actions    *actiontable; /**< Contains the shift and reduce actions. */
  gototable        gotos;
  productiontable  productions;
  injectiontable   injections;
  productionset    production_has_priorities;
  prioritytable    gtr_priorities;
  argprioritytable arg_gtr_priorities;
  prioritytable    associativities;
  ATbool           has_priorities;
  ATbool           has_rejects;
  ATbool           has_prefers;
  ATbool           has_avoids;
  ATerm            noInjection;
  ATerm            userDefinedInjection;
  ATerm            kernelInjection;
  int              maxProductionLength;
  char            *path;
};

/* The pool size of the free hash buckets in both action and goto tables. */
#define SGLR_PTBL_POOLCHUNK 8192 /**< The amount of memory to allocate for the 
                                      goto table. */
#define SGLR_PTBL_HASH_PRIME 677 /**< The prime number used to generate the 
                                      hash key. */

#define SGLR_PTBL_STATE_SIZE 257 /**< The columns in the action table. */
#define SGLR_PTBL_PROD_START 257

typedef unsigned int  hashkey;

static ERR_ErrorList ptErrorList = NULL;
static gotobucket *sg_goto_pool_free = NULL;

enum SGLR_PTBL_PRIORITIES { P_IGNORE, P_ARGGTR, P_GTR };

/* Parse table accessors. */

/** 
* Returns the start state of the parse table.
* 
* \param pt the parse table.
* 
* \return the start state of the parse table.
*/
int SGLR_PTBL_getStartState(ParseTable *pt) {         
  return pt->startState;
}
      
/** 
* Returns the number of states in the parse table.
* 
* \param pt the parse table.
* 
* \return the number of states in the parse table.
*/
size_t SGLR_PTBL_getNumberOfStates(ParseTable *pt) {
  return pt->numstates;
}

/** 
* Returns the number of productions in the parse table.
* 
* \param pt the parse table.
* 
* \return the number of productions in the parse table.
*/
size_t SGLR_PTBL_getNumberOfProductions(ParseTable *pt) {
  return pt->numprods;
}

/** 
* Returns the length of the longest production.
* 
* \return 
*/
int SGLR_PTBL_getMaxProductionLength(ParseTable *pt) {
  return pt->maxProductionLength;
}

/** 
* Returns the number of 
* 
* \param pt 
* 
* \return 
*/
gototable SGLR_PTBL_getNumberOfGotos(ParseTable *pt) {
  return pt->gotos;
}

/** 
* Returns the table containig the grammar's productions, which is indexed on 
* production numbers.
* 
* \param pt the parse table.
* 
* \return returns the table of productions.
*/
productiontable SGLR_PTBL_getProductions(ParseTable *pt) {
  return pt->productions;
}

/** 
* Returns the table containing whether or not the productions are injections.
* Again it is indexed on production numbers.
*
* \param pt the parse table.
* 
* \return returns the table of injections.
*/
injectiontable SGLR_PTBL_getInjections(ParseTable *pt) {
  return pt->injections;
}
 
productionset SGLR_PTBL_getPriorities(ParseTable *pt) {  
  return pt->production_has_priorities;
}
 
prioritytable SGLR_PTBL_getGreaterPriorities(ParseTable *pt) {
  return pt->gtr_priorities;
}
 
argprioritytable SGLR_PTBL_getArgumentGreaterPriorities(ParseTable *pt) {
 return pt->arg_gtr_priorities;
}
 
prioritytable SGLR_PTBL_getAssociativities(ParseTable *pt) {
  return pt->associativities;
}
 
ATbool SGLR_PTBL_hasPriorities(ParseTable *pt) {
  return pt->has_priorities;
}
 
ATbool SGLR_PTBL_hasRejects(ParseTable *pt) { 
  return pt->has_rejects; 
}

ATbool SGLR_PTBL_hasPrefers(ParseTable *pt) {
  return pt->has_prefers;
}

ATbool SGLR_PTBL_hasAvoids(ParseTable *pt) {
 return pt->has_avoids;
}
 
ATbool SGLR_PTBL_hasPreferences(ParseTable *pt) {
  return (SGLR_PTBL_hasRejects(pt)||SGLR_PTBL_hasPrefers(pt)||SGLR_PTBL_hasAvoids(pt));
}


/** 
* Returns a typedef enum that represents the type of action given. This is to 
* optimize the parser.
* 
* \param action the action.
* 
* \return an typedef enum representing the type of action given.
*/
ActionKind SGLR_PTBL_actionKind(PTBL_Action action) {

  if(PTBL_isActionReduce(action)) {
    return REDUCE;
  } else if(PTBL_isActionLookaheadReduce(action)) {
    return REDUCE_LA;
  } else if (PTBL_isActionShift(action)) {
    return SHIFT;
  } else if(PTBL_isActionAccept(action)) {
    return ACCEPT;
  }
  return ERROR;
}





/** 
* Computes the hash key used by the goto table. This is not a perfect hash.
* 
* \param pt the parse table.
* \param stateNum the source state number of the goto.
* \param prodNum the goto's production.
* 
* \return the hash key for the goto entry.
*/
static hashkey computeGotoHashKey(ParseTable *pt, int stateNum, int prodNum) {
  hashkey the_key;

  the_key =  (prodNum * pt->numstates) + stateNum;
  the_key *= SGLR_PTBL_HASH_PRIME;
  return the_key & (pt->gotos.size - 1);
}

/* Parse Table Lookup */
/** 
* Returns the index into the action table for the given state number and token.
* 
* \param s the state number to access
* \param c the token
* 
* \return Returns the index into the actions table for the given state number 
* and token.
*/
static int actionIndex(int s, Token c) {
  return s*SGLR_PTBL_STATE_SIZE + c;
}

/** 
* Returns the actions in the given parse table for the given state and token.
* 
* \param pt the parse table.
* \param s the state.
* \param c the token.
* 
* \return Returns the parse table actions in the given parse table.
*/
PTBL_Actions SGLR_PTBL_lookupAction(ParseTable *pt, int s, Token c) {
  return pt->actiontable[actionIndex(s,c)];
}

/** 
* Finds the goto state for the given state number and production number.
* 
* \param pt the parse table.
* \param stateNum the current state number.
* \param prodNum the production number the reduce was done for.
* 
* \return the state number 
*/
int SGLR_PTBL_lookupGoto(ParseTable *pt, int stateNum, int prodNum) {
  register gotobucket *b;
  hashkey h;

  h = computeGotoHashKey(pt, stateNum, prodNum);

  for(b = pt->gotos.table[h]; b; b=b->next) {
    if((b->from==stateNum) && (b->prodNum==prodNum)) {
      /* if (PARSER_getDebugFlag() == ATtrue) {
        fprintf(LOG_log(), "Goto(%d,%d) == %d\n", stateNum, prodNum, b->to);
      } */
      return b->to;
    }
  }
  
  assert("Error in SGLR_PTBL_lookupGoto() -- the goto state was not found!");
  return -1;
}


PT_Production SGLR_PTBL_lookupProduction(ParseTable *pt, int l) {
  int i = l;

  if (i >= (SGLR_PTBL_PROD_START+SGLR_PTBL_getNumberOfProductions(pt)) || i <= EOS_TOKEN) {
    return NULL;
  }
  else {
    return SGLR_PTBL_getProductions(pt)[i-SGLR_PTBL_PROD_START];
  }
}

PT_Production SGLR_PTBL_lookupBracketProd(ParseTable *pt, PT_Symbol symbol) {
  int i;
  int maxProd = SGLR_PTBL_getNumberOfProductions(pt);

  for (i = 0; i < maxProd; i++) {
    PT_Production p = SGLR_PTBL_getProductions(pt)[i];
    PT_Symbol rhs = PT_getProductionRhs(p);
    if (PT_isEqualSymbol(symbol, rhs) && PT_hasProductionBracketAttr(p)) {
      return p;
    }
  }
  return NULL;
}

static void registerProductionHasPriority(ParseTable *pt, PT_Production p) {
  ATindexedSetPut(SGLR_PTBL_getPriorities(pt), (ATerm)p, NULL);
}

ATbool SGLR_PTBL_hasProductionPriority(ParseTable *pt, PT_Production p) {
  if (ATindexedSetGetIndex(SGLR_PTBL_getPriorities(pt), (ATerm)p) < 0) {
    return ATfalse;
  }
  else {
    return ATtrue;
  } 
}

ATermList SGLR_PTBL_lookupGtrPriority(ParseTable *pt, PT_Production p) {
  return (ATermList)ATtableGet(SGLR_PTBL_getGreaterPriorities(pt), (ATerm)p);
}

static void addGtrPriority(ParseTable *pt, PT_Production p1, PT_Production p2) {
  ATermList value = SGLR_PTBL_lookupGtrPriority(pt, p1);

  if (value == NULL) {
    registerProductionHasPriority(pt, p1);
    ATtablePut(SGLR_PTBL_getGreaterPriorities(pt), (ATerm) p1,
               (ATerm) ATmakeList1((ATerm) p2));
  } else {
    ATtablePut(SGLR_PTBL_getGreaterPriorities(pt), (ATerm) p1,
               (ATerm) ATinsert(value, (ATerm) p2));
  }
}

ATermList lookupArgGtrPriority(ParseTable *pt, PT_Production p, ATermInt argNumber) {
  ATerm key = (ATerm)ATmakeList2((ATerm)p, (ATerm)argNumber);
  
  return (ATermList)ATtableGet(SGLR_PTBL_getArgumentGreaterPriorities(pt), key);
}

static void addArgGtrPriority(ParseTable *pt, PT_Production p1, ATermInt argNumber, PT_Production p2) {
  ATermList value = lookupArgGtrPriority(pt, p1, argNumber);
  ATerm key = (ATerm)ATmakeList2((ATerm)p1, (ATerm)argNumber);

  if (value == NULL) {
    registerProductionHasPriority(pt, p1);
    ATtablePut(SGLR_PTBL_getArgumentGreaterPriorities(pt), key, (ATerm) ATmakeList1((ATerm) p2));
  } else {
    ATtablePut(SGLR_PTBL_getArgumentGreaterPriorities(pt), key, (ATerm) ATinsert(value, (ATerm) p2));
  }
}

/** 
 * Determines which of the two given productions has a greater priority.
 *  
 * \param pt the parse table.
 * \param argNumber ?
 * \param p0 the first production to compare.
 * \param p1 the second production to compare.
 * 
 * \return \c true if the first production has a greater priority than the 
 * second.
 */
ATbool SGLR_PTBL_isPriorityGreater(ParseTable *pt, int argNumber, PT_Production p0, PT_Production p1) {
  ATermList prios = SGLR_PTBL_lookupGtrPriority(pt, p0);

  if (prios && ATindexOf(prios, (ATerm) p1, 0) != -1) {
    return ATtrue;
  }
  else {
    prios = lookupArgGtrPriority(pt, p0, ATmakeInt(argNumber));

    if (prios && ATindexOf(prios, (ATerm) p1, 0) != -1) {
      return ATtrue;
    }
  }
  return ATfalse;
}


/* Error handling. */
void SGLR_PTBL_initErrorList() {
  ERR_protectErrorList(&ptErrorList);

  /* test for NULL, or we throw away messages when init is called twice */
  if (ptErrorList == NULL) {
    ptErrorList = ERR_makeErrorListEmpty();
  }
}

ATbool SGLR_PTBL_isErrorListEmpty() {
  return ERR_isErrorListEmpty(ptErrorList);
}

void SGLR_PTBL_addErrorError(const char *path, const char *contentDescription) {
  if (ERR_isErrorListEmpty(ptErrorList)) {
    ERR_Subject subject;
    ERR_Error error;

    if (path != NULL) {
      ERR_Location posinfo = ERR_makeLocationFile(path);
      subject = ERR_makeSubjectLocalized(contentDescription, posinfo);
    }
    else {
      subject = ERR_makeSubjectSubject(contentDescription);
    }

    error = ERR_makeErrorError("Parse Table error",
			       ERR_makeSubjectListSingle(subject));
    ptErrorList = ERR_makeErrorListMany(error, ptErrorList);
  }
}

ERR_Error SGLR_PTBL_makeErrorError() {
  return ERR_getErrorListHead(ptErrorList);
}

ERR_Summary SGLR_PTBL_makeErrorSummary(const char *path) {
  return ERR_makeSummarySummary("sglr", path, ptErrorList);
}





ATbool SGLR_PTBL_prodIsInjection(ParseTable *pt, PT_Production p) {
  return ATtableGet(pt->injections, (ATerm) p) != pt->noInjection;
}

ATbool SGLR_PTBL_prodIsUserDefinedInjection(ParseTable *pt, PT_Production p) {
  return ATtableGet(pt->injections, (ATerm) p) == pt->userDefinedInjection;
}



/** 
 * Checks to see if the given actions contain preferece attributes and marks 
 * the parse table as containing preferences accordingly. 
 * 
 * \todo This should probably be removed and added directly from the parse 
 * table.
 * 
 * \param pt the parse table.
 * \param actions the actions to check.
 */
static void findPreferences(ParseTable *pt, PTBL_Actions actions) {
  PTBL_Action action;

  if(!pt->has_prefers || !pt->has_avoids) {
    for(; !PTBL_isActionsEmpty(actions); actions = PTBL_getActionsTail(actions)) {
      action = PTBL_getActionsHead(actions);
      if(PTBL_isActionReduce(action) || PTBL_isActionLookaheadReduce(action)) {
        PTBL_SpecialAttr attribute = PTBL_getActionSpecialAttr(action);

        if(PTBL_isSpecialAttrPrefer(attribute)) {
          pt->has_prefers = ATtrue;
        } else if(PTBL_isSpecialAttrAvoid(attribute)) {
          pt->has_avoids = ATtrue;
        }
      }
    }
  }
}

/** 
* Adds the given actions to the parse table for the given character and state.
* 
* \param pt the parse table.
* \param s the state to add the actions to.
* \param c the input symbol to add to the actions to.
* \param actions the actions.
*/
static void addActionsToActionTable(ParseTable *pt, int s, Token c, PTBL_Actions actions) {
  if (pt->actiontable[actionIndex(s,c)]) {
    pt->actiontable[actionIndex(s,c)] = (PTBL_Actions)ATconcat((ATermList)pt->actiontable[actionIndex(s,c)], (ATermList)actions);
  }
  else {
    pt->actiontable[actionIndex(s,c)] = actions;
  }
}

/** 
* Expands the character ranges extracted from the given actions and adds them 
* to the parse table. Because of the way the action table is implemented, 
* character classes have to be expanded and each action added for every 
* character in the given state.
*
* This function is effectively duplicated for the char ranges used in the goto
* table.
* 
* \param pt the parse table.
* \param s the state to add the actions to.
* \param ranges the character ranges to expand.
* \param actions the actions to add to the table.
*
* \see expandActionCharRanges()
*/
static void expandActionCharRanges(ParseTable *pt, int s, PT_CharRanges ranges, PTBL_Actions actions) {
  PT_CharRange firstTerm;

  for(; !PT_isCharRangesEmpty(ranges); ranges = PT_getCharRangesTail(ranges)) {
    firstTerm = PT_getCharRangesHead(ranges);
    if (PT_isCharRangeCharacter(firstTerm)) {
      addActionsToActionTable(pt, s, ATgetInt((ATermInt) firstTerm), actions);
    } else {
      if (PT_isCharRangeRange(firstTerm)) {
        int  first = PT_getCharRangeStart(firstTerm);
        int  last  = PT_getCharRangeEnd(firstTerm);

        for(; first <= last; first++) {
          addActionsToActionTable(pt, s, (Token)first, actions);
        }
      } else {
        ATerror("expandActionCharRanges: bad char-range %t\n", firstTerm);
      }
    }
  }
}

/** 
* Processes the choices extracted from the parse table for the given state.
* 
* \param pt the parse table.
* \param s the state.
* \param choices the choices.
*/
static void processChoices(ParseTable *pt, int s, PTBL_Choices choices) {
  PTBL_Choice choice;

  for (; !PTBL_isChoicesEmpty(choices); choices = PTBL_getChoicesTail(choices)) {
    choice = PTBL_getChoicesHead(choices);
    if(PTBL_isChoiceDefault(choice)) {
      PT_CharRanges classes = (PT_CharRanges) PTBL_getChoiceRanges(choice);
      PTBL_Actions t        = PTBL_getChoiceActions(choice);

      expandActionCharRanges(pt, s, classes, t);
      findPreferences(pt, t);

      for(; !pt->has_rejects && !PTBL_isActionsEmpty(t); t = PTBL_getActionsTail(t)) {
        PTBL_Action action = PTBL_getActionsHead(t);
        
        if (PTBL_hasActionSpecialAttr(action)) { 
          PTBL_SpecialAttr attr = PTBL_getActionSpecialAttr(action);

          if(PTBL_isSpecialAttrReject(attr)) {
            pt->has_rejects = ATtrue;
          }
        }
      }
    } else {
      ATerror("processChoices: bad action %t\n", choice);
    }
  }
}

/** 
* Adds a goto for the given source state, production number and target state.
* The parse table construction guarantees that only one goto exists for each 
* source state and production pair.
* 
* \param pt the parse table.
* \param from the source state number.
* \param prodNum the production number.
* \param to the target state number.
*/
void addGotoToGotoTable(ParseTable *pt, int from, int prodNum, int to) {
  gotobucket *gb;
  hashkey     h;

  if(sg_goto_pool_free == NULL) {
    /* If the goto pool is empty, allocate a new chunk of goto buckets */
    register size_t i;

    sg_goto_pool_free = malloc(SGLR_PTBL_POOLCHUNK * sizeof(gotobucket));
    if(!sg_goto_pool_free) {
      ATerror("failed to expand goto pool\n");
    }

    for(i=0, gb=sg_goto_pool_free; i < (SGLR_PTBL_POOLCHUNK-1); i++) {
      gb->next = (gotobucket *) ((size_t) gb + (size_t)sizeof(gotobucket));
      gb = gb->next;
    }
    gb->next = NULL;
  }
  gb = sg_goto_pool_free;
  sg_goto_pool_free = sg_goto_pool_free->next;

  h = computeGotoHashKey(pt, from, prodNum);
  if (pt->gotos.table[h] != 0) {
    /*ATwarning("pt->gotos.table[%d]: %d, %d, %d\n", h, (pt->gotos.table[h])->from, (pt->gotos.table[h])->to, (pt->gotos.table[h])->prodNum);*/
  }
  gb->next = pt->gotos.table[h];
  gb->from = from;
  gb->prodNum = prodNum;
  gb->to = to;
  pt->gotos.table[h] = gb;
}

/** 
* Expands the given character ranges and uses them when creating the goto table.
* In this instance the char ranges encode production numbers and not characters.
* Actually they do include characters as well, but I believe they can be 
* ignored. They shouldn't be necessary. 
*
* This function is effectively duplicated for the char ranges used in the action
* table.
* 
* \param pt the parse table.
* \param from 
* \param ranges 
* \param to 
*
* \see expandActionCharRanges()
*/
static void expandGotoCharRanges(ParseTable *pt, int from, PT_CharRanges ranges, int to) {
  PT_CharRange firstTerm;

  for(; !PT_isCharRangesEmpty(ranges); ranges = PT_getCharRangesTail(ranges)) {
    firstTerm = PT_getCharRangesHead(ranges);
    if (PT_isCharRangeCharacter(firstTerm)) {
      addGotoToGotoTable(pt, from, ATgetInt((ATermInt) firstTerm), to);
    } else {
      if (PT_isCharRangeRange(firstTerm)) {
 #if 1
        int  first = PT_getCharRangeStart(firstTerm);
        int  last  = PT_getCharRangeEnd(firstTerm);

        for(; first <= last; first++)
          addGotoToGotoTable(pt, from, first, to);
#endif
      } else {
        ATerror("expandGotoCharRanges: bad char-range %t\n", firstTerm);
      }
    }
  }
}

/** 
* Processes the gotos extracted from the parse table for the given state.
* 
* \param pt the parse table.
* \param s the state.
* \param gotos the gotos.
*/
static void processGotos(ParseTable *pt, int s, PTBL_Gotos gotos) {
  PTBL_Goto firstTerm;

  for (; !PTBL_isGotosEmpty(gotos); gotos = PTBL_getGotosTail(gotos)) {
    if (PTBL_isGotoDefault(firstTerm = PTBL_getGotosHead(gotos))) {
      /* Are the ranges here the production numbers for this goto? */
      PT_CharRanges ranges = (PT_CharRanges)PTBL_getGotoRanges(firstTerm);
      int s2 = PTBL_getGotoStateNumber(firstTerm);

      expandGotoCharRanges(pt, s, ranges, s2);
    } else {
      ATerror("processGotos: cannot parse goto entry %t\n", firstTerm);
    }
  }
}

/** 
* Fills the parse table's goto and action tables.
* 
* \param pt the parse table.
* \param states the states in the parse table.
*/
void SGLR_PTBL_fillParseTable(ParseTable *pt, PTBL_States states) {
  PTBL_State curstate;

  for(; !PTBL_isStatesEmpty(states); states = PTBL_getStatesTail(states)) {
    if(PTBL_isStateDefault(curstate = PTBL_getStatesHead(states))) {
      int s         = PTBL_getStateNumber(curstate);
      PTBL_Gotos gotos = PTBL_getStateGotos(curstate);
      PTBL_Choices choices = PTBL_getStateChoices(curstate);

      SGLR_STATS_addToCount(SGLR_STATS_gotos, PTBL_getGotosLength(gotos)); 
      SGLR_STATS_addToCount(SGLR_STATS_actions, PTBL_getChoicesLength(choices));

      processGotos(pt, s, gotos);
      processChoices(pt, s, choices);
    } else {
      ATerror("SGLR_PTBL_fillParseTable: bad state-rec %t\n", curstate);
    }
  }
}




static void addProduction(ParseTable *pt, int lbl, PT_Production prod) {
  productiontable tbl = pt->productions;

  tbl[lbl-SGLR_PTBL_PROD_START] = prod;
  ATprotect((ATerm *) &tbl[lbl-SGLR_PTBL_PROD_START]);

  if (PT_isProductionInjection(prod)) {
    if (!PT_isGeneratedKernelProduction(prod)) {
      ATtablePut(pt->injections, (ATerm) prod, pt->userDefinedInjection);
    }
    else {
      ATtablePut(pt->injections, (ATerm) prod, pt->kernelInjection);
    }
  }
  else {
      ATtablePut(pt->injections, (ATerm) prod, pt->noInjection);
  }
}

/** 
 * Add the literal ATerm for a production to the production table. The label 
 * is the pointer in the table. It is used in reduce actions to refer to the 
 * production.
 * 
 * \param pt the parse table. 
 * \param prods the list of production labels in the grammar.
 */
void SGLR_PTBL_processProductions(ParseTable *pt, PTBL_Labels prods) {
  PTBL_Label prodLabel;

  for (; !PTBL_isLabelsEmpty(prods); prods = PTBL_getLabelsTail(prods)) {
    prodLabel = PTBL_getLabelsHead(prods);
    if (PTBL_isLabelDefault(prodLabel)) {
      PT_Production prod  = (PT_Production)PTBL_getLabelProduction(prodLabel);
      int prodNum = PTBL_getLabelNumber(prodLabel);

      if (MAIN_getStatsFlag) {
        int lhsLength = PT_getArgsLength(PT_getProductionLhs(prod));
        if (pt->maxProductionLength < lhsLength) {
          pt->maxProductionLength = lhsLength;
        }
      }

      if (prodNum == EOS_TOKEN) {
        ATerror("error, obsolete parse table format\n");
      }
      if (prodNum <  SGLR_PTBL_PROD_START
         || prodNum >= SGLR_PTBL_PROD_START+SGLR_PTBL_getNumberOfProductions(pt)) {
        ATerror("SGLR_PTBL_processProductions: production %d out of range (%d..%d)\n",
                prodNum, SGLR_PTBL_PROD_START, SGLR_PTBL_PROD_START+SGLR_PTBL_getNumberOfProductions(pt)-1);
      }
      addProduction(pt, prodNum, prod);
    } 
    else {
      ATerror("SGLR_PTBL_processProductions: bad production %t\n", prodLabel);
    }
  }
}

/** 
* 
* 
* \param pt 
* \param prios 
*/
void SGLR_PTBL_processPriorities(ParseTable *pt, register PTBL_Priorities prios) {
  PTBL_Priority prio;
  ATermInt pr_num1, pr_num2, arg_num;
  PT_Production p1, p2;
  int ptype = P_IGNORE;

  for (; !PTBL_isPrioritiesEmpty(prios); prios = PTBL_getPrioritiesTail(prios)) {
    prio = PTBL_getPrioritiesHead(prios);
    if(PTBL_isPriorityGreater(prio)) {
      ptype = P_GTR;
    }
    else if (PTBL_isPriorityArgGreater(prio)) {
      ptype = P_ARGGTR;
    } else {
      ptype = P_IGNORE;
    }
    if(ptype != P_IGNORE) {

      pt->has_priorities = ATtrue;
      pr_num1 = ATmakeInt(PTBL_getPriorityLabel1(prio));
      p1 = SGLR_PTBL_lookupProduction(pt, ATgetInt(pr_num1));

      switch(ptype) {
        case P_GTR:
          pr_num2 = ATmakeInt(PTBL_getPriorityLabel2(prio));
          if (pr_num1 != pr_num2) {
            p2 = SGLR_PTBL_lookupProduction(pt, ATgetInt(pr_num2));
            addGtrPriority(pt, p1, p2);
          }
          break;
        case P_ARGGTR:
          arg_num = ATmakeInt(PTBL_getPriorityArgumentNumber(prio));
          pr_num2 = ATmakeInt(PTBL_getPriorityLabel2(prio));
          p2 = SGLR_PTBL_lookupProduction(pt, ATgetInt(pr_num2));
          addArgGtrPriority(pt, p1, arg_num, p2);
          break;
        default:
          break;
      }
    }
  }
}

/** 
* Allocates the memory required for the parse table.
*
* \param startState the start state of the parse table.
* \param numstates the number of states in the parse table.
* \param numprods the number of production in the normalised grammar (used as 
* the index into the goto table).
* \param action_entries the number of actions in the parse table.
* \param goto_entries the number of gotos in the parse table.
* \param path the path to the parse table file.
* 
* \return an empty parse table.
*/
ParseTable *SGLR_PTBL_initializeParseTable(int startState, size_t numstates, size_t numprods, size_t action_entries, size_t goto_entries, const char *path) {
  ParseTable *pt;
  size_t      tableclass, tablesize;

  SGLR_STATS_setCount(SGLR_STATS_states, numstates);
  SGLR_STATS_setCount(SGLR_STATS_prods, numprods);
  SGLR_STATS_setCount(SGLR_STATS_actionEntries, action_entries);
  SGLR_STATS_setCount(SGLR_STATS_gotoEntries, goto_entries);

  pt               = calloc(1, sizeof(struct _ParseTable));
  pt->startState   = startState;
  pt->numstates    = numstates;
  pt->numprods     = numprods;
  pt->path = (char *)path;  
  pt->noInjection = ATparse("no-injection");
  ATprotect(&(pt->noInjection));
  pt->userDefinedInjection = ATparse("user-defined-injection");
  ATprotect(&(pt->userDefinedInjection));
  pt->kernelInjection = ATparse("kernel-injection");
  ATprotect(&(pt->kernelInjection));


  pt->actiontable = calloc(numstates*SGLR_PTBL_STATE_SIZE, sizeof(PTBL_Actions));
  if(!pt->actiontable) {
    ATerror("could not allocate action table of size %d\n", numstates);
  }
  ATprotectArray((ATerm *)pt->actiontable, numstates*SGLR_PTBL_STATE_SIZE);

  /*  Goto table -- determine upper size/class bound, and initialize  */
  for(tableclass=4, tablesize=(1 << tableclass) ; tablesize < goto_entries;
      tablesize <<= 1) {
    tableclass++;
  }
  /*ATwarning("tableclass: %d, tablesize: %d, gotoentries: %d, sizeof(gotobucket *): %d\n", tableclass, tablesize, goto_entries, sizeof(gotobucket *));*/
  pt->gotos.sizeclass = tableclass;
  pt->gotos.size      = tablesize;
  pt->gotos.table     = calloc(tablesize, sizeof(gotobucket *));
  if(!pt->gotos.table) {
    ATerror("could not allocate goto table of size %d\n", tablesize);
  }

  pt->productions  = calloc(numprods, sizeof(PT_Production));
  if(!pt->productions) {
    ATerror("could not allocate %d productions\n", numprods);
  }
  pt->injections  = ATtableCreate(numprods, 75);
  if(!pt->injections) {
    ATerror("could not allocate %d booleans\n", numprods);
  }
  pt->production_has_priorities   = ATindexedSetCreate(numprods, 75);
  pt->gtr_priorities   = ATtableCreate(numprods, 75);
  pt->arg_gtr_priorities   = ATtableCreate(numprods, 75);
  pt->associativities   = ATtableCreate(numprods, 75);

  pt->has_priorities = pt->has_rejects  = ATfalse;
  pt->has_prefers = pt->has_avoids = ATfalse;

  return pt;
}






static size_t countClassesInActionTable(PT_CharRanges classes) {
  PT_CharRange firstTerm;
  size_t numactions = 0;

  for(; !PT_isCharRangesEmpty(classes); classes = PT_getCharRangesTail(classes)) {
    firstTerm = PT_getCharRangesHead(classes);
    if (PT_isCharRangeCharacter(firstTerm)) {
      numactions++;
    } else {
      if (PT_isCharRangeRange(firstTerm)) {
        int  first = PT_getCharRangeStart(firstTerm);
        int  last  = PT_getCharRangeEnd(firstTerm);

        numactions += (last - first) + 1;
      } else {
        ATerror("countClassesInActionTable: bad char-class %t\n", firstTerm);
      }
    }
  }
  return numactions;
}

size_t SGLR_PTBL_countChoices(register PTBL_Choices choices) {
  PTBL_Choice choice;
  size_t numchoices = 0;

  for (; !PTBL_isChoicesEmpty(choices); choices = PTBL_getChoicesTail(choices)) {
    choice = PTBL_getChoicesHead(choices);
    if(PTBL_isChoiceDefault(choice)) {
      PT_CharRanges classes = (PT_CharRanges)PTBL_getChoiceRanges(choice);
      numchoices += countClassesInActionTable(classes);
    } else {
      ATabort("SGLR_PTBL_countPTChoices: bad action %t\n", choice);
    }
  }
  return numchoices;
}

/** 
 * 
 *
 * \note This function is the same as countClassesInActionTable with different 
 * types.
 *
 * \param ranges 
 * 
 * \return 
 */
static size_t countElementsInRanges(register PT_CharRanges ranges) {
  PT_CharRange firstTerm;
  size_t numgotos = 0;

  for(; !PT_isCharRangesEmpty(ranges); ranges = PT_getCharRangesTail(ranges)) {
    firstTerm = PT_getCharRangesHead(ranges);
    if (PT_isCharRangeCharacter(firstTerm)) {
      numgotos++;
    } else {
      if (PT_isCharRangeRange(firstTerm)) {
#if 1
        /* These should be the redundant shift actions that are added to the
         * goto table. */
        int  first = PT_getCharRangeStart(firstTerm);
        int  last  = PT_getCharRangeEnd(firstTerm);

        numgotos += (last - first) + 1;
#endif
      }
    }
  }
  return numgotos;
}

/** 
* Counts the number of gotos in the given list. It is used to count the number 
* of gotos in the parse table to pick a good size for the goto hash table.
* 
* \param gotos a list of gotos.
* 
* \return the number of gotos in the given list.
*/
size_t SGLR_PTBL_countGotos(register PTBL_Gotos gotos) {
  PTBL_Goto firstTerm;
  size_t numgotos = 0;

  for (; !PTBL_isGotosEmpty(gotos); gotos = PTBL_getGotosTail(gotos)) {
    if (PTBL_isGotoDefault((firstTerm = PTBL_getGotosHead(gotos)))) {
      PT_CharRanges ranges = (PT_CharRanges)PTBL_getGotoRanges(firstTerm);
      numgotos += countElementsInRanges(ranges);
    }
  }
  return numgotos;
}





/* Parse Table Destruction */
static void discardActions(ParseTable *pt) {
  ATunprotectArray((ATerm *)pt->actiontable);
  free(pt->actiontable);
  pt->actiontable = NULL;
}

static void discardGotos(ParseTable *pt) {
  register size_t s;
  gotobucket *g, *next;

  for(s=0; s<pt->gotos.size; s++) {
    for(g = pt->gotos.table[s]; g; g=next) {
      next = g->next;
      g->next = sg_goto_pool_free;          /*  Feed pool for later perusal  */
      sg_goto_pool_free = g;
    }
  }
  free(pt->gotos.table);
}

static void discardProductions(ParseTable *pt) {
  register size_t p;

  for(p=0; p<SGLR_PTBL_getNumberOfProductions(pt); p++) {
    if(pt->productions[p] != NULL) {
      ATunprotect((ATerm *) &pt->productions[p]);
    }
  }
  free(pt->productions);
}

static void discardInjections(ParseTable *pt) {
  ATtableDestroy(pt->injections);
}

static void discardPriorities(ParseTable *pt) {
  ATindexedSetDestroy(pt->production_has_priorities);
  ATtableDestroy(pt->gtr_priorities);
  ATtableDestroy(pt->arg_gtr_priorities);
  ATtableDestroy(pt->associativities);
}

void SGLR_PTBL_discardParseTable(ParseTable *pt) {
  ATunprotect(&(pt->noInjection)); 
  ATunprotect(&(pt->userDefinedInjection)); 
  ATunprotect(&(pt->kernelInjection)); 

  discardActions(pt);
  discardGotos(pt);
  discardProductions(pt);
  discardInjections(pt);
  discardPriorities(pt);

  free(pt);
  pt = NULL;
}

