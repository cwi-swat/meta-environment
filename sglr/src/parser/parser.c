/* $Id$ */

/** \file
 * \ingroup parser
 *  Implementation of a Scannerless Generalized LR (SGLR) parser.
 *  
 * All reject filtering described in Eelco Visser's thesis has been removed 
 * from the parser and is performed during a post parse traversal of the parse 
 * forest.
 *
 * If all tokens have been read or if no more GSS nodes are alive, parsing
 * is done and the the result of parsing is returned.  If parsing
 * succeeded, #acceptingStack points to a GSS node that has a direct
 * link to the initial state.  The tree on this link is the parse forest
 * with all possible parse trees.  If parsing failed an error summary is
 * returned.  A distinction is made between an error at end of file an
 * error in the middle of the file.
 */

#include <assert.h>

#include <MEPT-utils.h>
#include <Error.h>
#include <aterm2.h>
#include <Error-manager.h>
#include <logging.h>
#include <rsrc-usage.h>
#include <filterOptions.h>

#include "parser.h"
#include "reductionPath.h"
#include "shiftQueue.h"
#include "gss.h"
#include "gssGarbageCollector.h"
#include "filters.h" /** \todo Remove dependency on filters.h */
#include "filterStats.h"
#include "ambi-tables.h" 
#include "inputString-api.h"
#include "parserOptions.h"
#include "mainOptions.h"
#include "tokens.h"
#include "statusBar.h"

#define GC_CYCLE 200

static ParseTable *parseTable;
static InputString inputString;

/** The GSS node that has a direct link (edge) to a GSS node labelled by the 
 * accepting state. */
static GSSNode     acceptingStack;
static GSSNodeList forActor;
static GSSNodeList forActorDelayed;

static GSSNodeList oldActiveStacks[GC_CYCLE];

static void parseToken(void);
static void actor(GSSNode gssNode);
static void doReductions(GSSNode gssNode, PTBL_Action a);
static void reducer(GSSNode st0, int s, int prodl, PT_Args kids, 
		    size_t length, PTBL_SpecialAttr attr);
static void doLimitedReductions(GSSNode gssNode, PTBL_Action a, 
				GSSEdge links);
static void shifter(void);

static void postParse(void);
static void postParseResult(void);
static void parserCleanup(void);
static void parseError();

/* Some global vars, used for collecting statistics.
 * TO-DO Should move these in to a statistics file.
 */

static size_t numberOfReductions = 0;
static size_t fullReductionEdgeVisits = 0; 
static size_t limitedReductionEdgeVisits = 0;

static long majorPageFaults; 
static long minorPageFaults;

enum  SG_SORTOPS { SG_SET, SG_UNSET, SG_GET };



//------------------------PARSING ALGORITHM-----------------------------------

static void initialiseParser(void) {
  assert(inputString != NULL && parseTable != NULL);
 
  SG_CreateInputAmbiMap(IS_getLength(inputString));

  acceptingStack = NULL;
  numberOfReductions = 0;

  FLT_resetTotalAmbCount();
  FLT_resetAmbCount();

  /** \todo Use GSS_addToCurrentLevel() instead. */
  GSS_createStartNode(GSSNode_createNode(SGLR_PTBL_getStartState(parseTable), 
					 ATfalse));
  
  if (PARSER_getStatsFlag() == ATtrue) {
    STATS_PageFlt(&majorPageFaults, &minorPageFaults);
    STATS_Timer();
  }
}

/** 
 * Parse an input string \a string using a parse table \a ptable.  
 * 
 * For each token in the input and while there are still GSS nodes alive
 * (i.e. no error is encountered) the parser handles all actions for each
 * active GSS node.  The shifts for each GSS node are stored and performed by
 * shifter() after all possible reductions have been performed. Parsing is 
 * done when the end of input is reached or no more GSS nodes are alive.
 *
 * \param[in] table The parse table.
 * \param[in] string The input string.
 * \return The parse forest.
 */
PT_Tree SG_parse(ParseTable *table, InputString string) {
  PT_Tree result = NULL;
  parseTable = table;
  inputString = string;

  initialiseParser();
  do {    
    IS_readNextToken(inputString);
    parseToken();
    /* If the shift queue is empty and the current level does not contain 
     * an accepting state then an error has occured.*/
    shifter();

    if (PARSER_getVerboseFlag()) {
      /* Added 1 to length of input string to show progress during parsing of 
       * the EOS symbol. */
      SG_printStatusBar("sglr: parsing", 
			IS_getNumberOfTokensRead(inputString), 
			IS_getLength(inputString)+1);
    }
  } while (!IS_isEndOfString(inputString) && GSS_getCurrentLevel() != NULL);

  if (PARSER_getVerboseFlag() == ATtrue) {
    SG_printDotAndNewLine();
  }

  postParse();

  /** \todo verify that the parser will not report success if the accept state 
   * is reached and all the string is not parsed. */
  if (acceptingStack && PARSER_getOutputFlag()) {
    result = GSSEdge_getTree(GSS_getEdgeListHead(GSSNode_getEdgeList(acceptingStack)));
  }

  parseError();
  postParseResult();

  parserCleanup();

  return result;
}

/** 
 * For each GSS node in the current level handle the actions for the current 
 * token.
 */
static void parseToken(void) {
  GSSNode st;
  GSSNodeList s;
  register GSSNodeList actives = GSS_getCurrentLevel();

  forActor        = NULL;
  forActorDelayed = NULL;
  
  while (actives || forActor) {
    if(actives != NULL) {
      st      = GSS_getNodeListHead(actives);
      actives = GSS_getNodeListTail(actives);
    } 
    else {
      st      = GSS_getNodeListHead(forActor);
      s       = GSS_getNodeListTail(forActor);
      GSS_deleteNodeList(forActor);
      forActor = s;
    }

    if (!GSSNode_isRejected(st)) {
      actor(st);
    }
    
    if (actives == NULL && forActor == NULL) {
      forActor        = forActorDelayed;
      forActorDelayed = NULL;
    }
  }
}


/** 
 * Handle the actions for GSS node \a st and the current token.  A reduce
 * action is immediately handled by doReductions(). Shift actions are
 * saved for handling when no more reductions can be done. An accept
 * action results in saving the current GSSNode as the accepting GSS node.
 * An error action is ignored because the current GSS node can be a wrong
 * attempt while other GSS nodes are still alive.  The entire parse fails
 * if all GSS nodes lead to error actions.  This will become apparent after
 * shifting, because no more active GSS nodes will be alive.
 */
static void actor(GSSNode st) {
  register PTBL_Actions as;
  PTBL_Action  a;

  as = SGLR_PTBL_lookupAction(parseTable, GSSNode_getStateNumber(st), IS_getCurrentToken(inputString));

  for (; as != NULL && !PTBL_isActionsEmpty(as); as = PTBL_getActionsTail(as)) {
    a = PTBL_getActionsHead(as);
    switch(SGLR_PTBL_actionKind(a)) {
      case SHIFT:
        GSS_addShiftQueueElement(PTBL_getActionStateNumber(a), st);
        break;
      case REDUCE:
        doReductions(st, a);
        break;
      case REDUCE_LA:
        if (IS_checkLookahead(inputString, PTBL_getActionRestrictions(a) /*SG_A_LOOKAHEAD(a)*/)) {
          doReductions(st, a);
        }
        break;
      case ACCEPT:
        if (!GSSNode_isRejected(st)) {
          acceptingStack = st;
        }
        break;
      default:
      case ERROR:
        break;
    }
  }
}

/** 
 * Perform a reduction for GSS node \a st with production \a r, which has 
 * \a nr_args number of arguments. For each path of length \a p from \a st a 
 * new tree is created with production \a r as its label and the trees 
 * along the path as its arguments. The new tree is the link from a new GSS 
 * node to the GSS node at the end of the path.
 */
static void doReductions(GSSNode st, PTBL_Action a) {
  ReductionPath head;
  register ReductionPath ps;
  int prod;

  prod = PTBL_getActionLabel(a);

  ps = GSS_findAllPaths(st, PTBL_getActionLength(a)); 

  while(ps != NULL){
    reducer(GSS_getReductionPathTargetGSSNode(ps),
        SGLR_PTBL_lookupGoto(parseTable, GSSNode_getStateNumber(GSS_getReductionPathTargetGSSNode(ps)), prod),
        prod, 
        GSS_getReductionPathTreeNodes(ps), 
        GSS_getReductionPathLength(ps), 
        PTBL_getActionSpecialAttr(a));

    head = ps;
    ps = GSS_getNextReductionPath(ps);
    GSS_clearReductionPath(head);
  }
}

/** 
 * For each path in \a p, construct the parse tree with the list of descendants 
 * found and create a new GSSNode.
 *
 * Look for a GSS node \a st1 in the current level labelled by state \a s.
 * If no such GSS node is found, create a new GSS node, labelled \a s, and a
 * link (edge) to \a st0, which is labelled with tree \a t. Add the new GSS 
 * node to the current level and to the #forActorDelayed list. 
 *
 * The #forActorDelayed list is an attempt to ensure that all reductions that 
 * have a goto to a GSS node \a st1 occur before any reductions from \a st1 
 * occur. This is to avoid having to undo any reduction performed from \a st1 
 * in the case that \a st1 is rejected.
 *
 * If such a GSS node exists and there is a direct link \a l from \a st1 to
 * \a st0, an ambiguity has been found.  The tree \a t is simply added to
 * the \a amb node of the direct link \a l.
 *
 * If there is no direct link, create a new link from \a st1 to \a st0 with 
 * \a t as parse tree.
 *
 * \param[in] st0 The GSSNode at the end of the reduction path. 
 * \param[in] s The goto state of the reduction.
 * \param[in] prodl The reduction's production number.
 * \param[in] kids The SPPF nodes that label the edges traversed for the 
 * reduction 
 * \param[in] length The length of the reduction.
 * \param[in] attribute The special attribute associated with the reduction.
 */
static void reducer(GSSNode st0, int s, int prodl, PT_Args kids, size_t length, PTBL_SpecialAttr attribute) {
  PT_Tree t;
  PT_Production prod;
  GSSEdge nl;
  GSSNode st1;

  if (PARSER_getStatsFlag() == ATtrue) {
    numberOfReductions++;
  }

  prod = SGLR_PTBL_lookupProduction(parseTable, prodl);
  t = PT_makeTreeAppl(prod, kids);

  st1 = GSS_findNodeInCurrentLevel(s);

  if (st1 == NULL) {
    /* State |s| is not in the current level. */
    st1 = GSSNode_createNode(s, ATfalse);
    nl  = GSSNode_addEdge(st1, st0, t, length);
    GSS_addToCurrentLevel(st1);

    forActorDelayed = GSS_addNodeListElement(st1, forActorDelayed);
    
    if (PTBL_isSpecialAttrReject(attribute)) {
      GSSEdge_setRejected(nl);
    }
  }
  else {
    /* State |s| exists in the current level. */
    nl = GSS_findDirectEdge(st1, st0);
    if (nl != NULL) {
      /* The edge already exists. */
      if (PTBL_isSpecialAttrReject(attribute)) {
        GSSEdge_setRejected(nl); //A non-rejected edge is changed to rejected 
	                         //(if not already rejected)!
      }

      SG_CreateAmbCluster(GSSEdge_getTree(nl), t,
                          IS_getNumberOfTokensRead(inputString) - 
			  GSSEdge_getNumberOfLeavesInTree(nl) - 1);
    }
    else {
      /* The edge does not exist. */
      register GSSNodeList sts;

      nl = GSSNode_addEdge(st1, st0, t, length);

      if (PTBL_isSpecialAttrReject(attribute)) {
        GSSEdge_setRejected(nl);
      }

      for (sts = GSS_getCurrentLevel(); 
	   sts != NULL; 
	   sts = GSS_getNodeListTail(sts)) {
        
	GSSNode st2 = GSS_getNodeListHead(sts);
	
        if (!GSSNode_isRejected(st2) &&
        GSS_findElementInNodeList(st2, forActor) == NULL && 
	    GSS_findElementInNodeList(st2, forActorDelayed) == NULL) {
          register PTBL_Actions as;

          for (as = SGLR_PTBL_lookupAction(parseTable, GSSNode_getStateNumber(st2), 
				    IS_getCurrentToken(inputString));
               as != NULL && !PTBL_isActionsEmpty(as); 
	       as = PTBL_getActionsTail(as)) {

            PTBL_Action a = PTBL_getActionsHead(as);

            if (SGLR_PTBL_actionKind(a) == REDUCE
                || (SGLR_PTBL_actionKind(a) == REDUCE_LA
                    && IS_checkLookahead(inputString, PTBL_getActionRestrictions(a)))) {
              doLimitedReductions(st2, a, nl);
            }
          }
        }
      }
    }
  }
}

/** 
 * Find the reduction paths for a reduction from \a st that traverse \a edge. 
 * For each such path call reducer().
 */
static void doLimitedReductions(GSSNode st, PTBL_Action a, GSSEdge edge) {
  ReductionPath  head;
  register ReductionPath ps;
  int prod;

  prod = PTBL_getActionLabel(a);

  ps = GSS_findLimitedPaths(st, PTBL_getActionStateNumber(a), edge);

  while(ps) {
    reducer(GSS_getReductionPathTargetGSSNode(ps),
	    SGLR_PTBL_lookupGoto(parseTable, GSSNode_getStateNumber(GSS_getReductionPathTargetGSSNode(ps)), prod),
	    prod, 
        GSS_getReductionPathTreeNodes(ps), 
        GSS_getReductionPathLength(ps), 
	    PTBL_getActionSpecialAttr(a));

    head = ps;
    ps = GSS_getNextReductionPath(ps);
    GSS_clearReductionPath(head);
  }
}

/** 
 * Perform all shifts. For each shift pair (\a st1, \a s), a GSS node \a st is 
 * created that has a link to \a st1 and is labelled \a s. The tree 
 * corresponding to the current token is the parse tree for the link. If a GSS 
 * node with state \a s already existed in the current level, only a new link 
 * is added from \a st to \a st1.
 */
static void shifter(void) {
  PT_Tree t;
  GSSNode st0;
  GSSNode st1;
  GSSNodeList newActiveStacks = NULL;
  int s;
  GSSEdge l;

  t = PT_makeTreeChar(IS_getCurrentToken(inputString));

  while (!GSS_isShiftQueueEmpty()) {
    s   = GSS_getShiftQueueStateNumber();
    st0 = GSS_getShiftQueueGSSNode();  
   
    if (/*PTBL_hasRejects(table) ||*/ !GSSNode_isRejected(st0)) { 
      st1 = GSS_findStateInNodeList(s, newActiveStacks);

      if(st1 == NULL) {
        st1 = GSSNode_createNode(s, ATtrue);
        newActiveStacks = GSS_addNodeListElement(st1, newActiveStacks);
      }

      l = GSSNode_addEdge(st1, st0, t, 1);
    }
    GSS_removeShiftQueueElement();
  }
  GSS_deleteShiftQueue();

  oldActiveStacks[(IS_getNumberOfTokensRead(inputString)-1) % GC_CYCLE] = GSS_getCurrentLevel();
  if (((IS_getNumberOfTokensRead(inputString)-1) % GC_CYCLE) == (GC_CYCLE-1)) {
    GC_gssBranches(oldActiveStacks, GC_CYCLE, newActiveStacks, 
		   acceptingStack);
  }

  GSS_setCurrentLevel(newActiveStacks);
}

/*-----------------------POST PARSE STUFF------------------------------------*/

static void postParse(void) {
  if (PARSER_getStatsFlag() == ATtrue) {
    double ptm;

    ptm = STATS_Timer();
    
    ATwarning("Logging statistics\n");

    fprintf(LOG_log(), "Number of linesParseds parsed: %ld\n", 
	    (long) IS_getLinesRead(inputString));
    
    fprintf(LOG_log(), "Parse time: %.6fs\n", ptm);
    fprintf(LOG_log(), "Characters/second: %.0f\n",
            ptm < 1.0e-4 ? 0 : IS_getNumberOfTokensRead(inputString)/ptm);

    fprintf(LOG_log(), "Number of reductions: %ld\n", (long) numberOfReductions);
    
    fprintf(LOG_log(), "Number of reductions/token: %f\n",
            (double) numberOfReductions/(double)IS_getNumberOfTokensRead(inputString));

    fprintf(LOG_log(), "Number of edge visits for full reductions: %ld\n",
            (long) fullReductionEdgeVisits);

    fprintf(LOG_log(), "Number of edge visits for limited reductions: %ld\n",
            (long) limitedReductionEdgeVisits);

    fprintf(LOG_log(), "Number of ambiguities: %d\n",
            FLT_getTotalAmbCount());
    fprintf(LOG_log(), "Number of calls to Amb: %d\n",
            FLT_getAmbCallsCount());
  }
}

static void postParseResult(void) {

  if (PARSER_getStatsFlag() == ATtrue) {  
    long allocated;

    if (FLT_getFilterFlag() == ATtrue) {
      fprintf(LOG_log(), "Count Eagerness Comparisons: total %d, successful %d\n", FLT_getNumPreferenceCountCalls(), FLT_getNumPreferenceCount());
      
      fprintf(LOG_log(), "Number of Injection Counts: total %d, successful %d\n", FLT_getNumInjectionCountCalls(), FLT_getNumInjectionCount());
    }

    fprintf(LOG_log(), "Minor page faults: %ld\n", minorPageFaults);
    fprintf(LOG_log(), "Major page faults: %ld\n", majorPageFaults);

    if(minorPageFaults > 0)
    fprintf(LOG_log(), "Characters/minor fault: %ld\n", IS_getNumberOfTokensRead(inputString)/minorPageFaults);

    allocated = STATS_Allocated();
    if(allocated > 0)
    fprintf(LOG_log(), "[mem] extra ATerm memory allocated while parsing: %ld\n", allocated);
  }
}

static void parserCleanup(void) {
  long allocated;
  
  GC_gssBranches(oldActiveStacks, 
		 IS_getNumberOfTokensRead(inputString) % GC_CYCLE,
		 NULL, 
		 acceptingStack);

  if (acceptingStack) {
    GC_gssBranch(acceptingStack);
  }

  GSS_clearCurrentLevel();
  acceptingStack = NULL;

  if (PARSER_getStatsFlag() == ATtrue) {
    allocated = STATS_Allocated();
    if(allocated > 0)
      fprintf(LOG_log(), "[mem] extra ATerm memory allocated for parse tree: %ld\n",
              allocated);
  }
}

/*-----------------------------ERROR HANDLING--------------------------------*/

static void parseError() {
  ERR_Subject subject;
  ERR_Location posinfo;
  static char subjectDescription[1024];
  static char errorDescription[1024];

  if (!acceptingStack) {
    if (IS_getCurrentToken(inputString) == EOS_TOKEN) {
      sprintf(errorDescription, "parse error, eof unexpected");
    }
    else {
      sprintf(errorDescription, "parse error, '%c' unexpected", 
          IS_getCurrentToken(inputString));
    }

    sprintf(subjectDescription, "input string");

    posinfo = IS_currentPosInfo(inputString);
    subject = ERR_makeSubjectLocalized(subjectDescription, posinfo);

    ERR_managerStoreError(errorDescription, ERR_makeSubjectListSingle(subject));
  }
}


