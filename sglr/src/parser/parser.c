/* $Id$ */

/** \file
 * \ingroup parser
 *  Implementation of a Scannerless Generalized LR (SGLR) parser.
 *  
 * If all tokens have been read or if no more GSS nodes are alive, parsing
 * is done and the the result of parsing is returned.  If parsing
 * succeeded, there is a node (the accept node) in the GSS that has a direct
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
#include <rsrc-usage.h>
#include <filterOptions.h>

#include "parser.h"
#include "reductionPath.h"
#include "shiftQueue.h"
#include "gss.h"
#include "gssGarbageCollector.h"
#include "filters.h" /** \todo Remove dependency on filters.h */
#include "ambi-tables.h" 
#include "inputString-api.h"
#include "parserOptions.h"
#include "mainOptions.h"
#include "tokens.h"
#include "statusBar.h"
#include "parserStatistics.h"

static ParseTable *parseTable;
static InputString inputString;

/** The GSS node that has a direct link (edge) to a GSS node labelled by the 
 * accepting state. */
static GSSNodeList forActor;
static GSSNodeList forActorDelayed;

static void parseToken(void);
static void actor(GSSNode gssNode);
static void doReductions(GSSNode gssNode, PTBL_Action a);
static void reducer(GSSNode st0, int s, int prodl, PT_Args kids, 
		    size_t length, PTBL_SpecialAttr attr);
static void doLimitedReductions(GSSNode gssNode, PTBL_Action a, 
				GSSEdge links);
static void shifter(void);

static void parseError();

/* Some global vars, used for collecting statistics.
 * TO-DO Should move these in to a statistics file.
 */

enum  SG_SORTOPS { SG_SET, SG_UNSET, SG_GET };



//------------------------PARSING ALGORITHM-----------------------------------

static void initialiseParser(void) {
  assert(inputString != NULL && parseTable != NULL);
 
  SG_CreateInputAmbiMap(IS_getLength(inputString));

  /** \todo Use GSS_addToCurrentLevel() instead. */
  GSS_createStartNode(GSSNode_createNode(SGLR_PTBL_getStartState(parseTable), 
					 ATfalse));
  
 if (MAIN_getStatsFlag) {
    STATS_PageFlt(&SGLR_STATS_majorPageFaults, &SGLR_STATS_minorPageFaults);
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
  GSSNode acceptNode;
  PT_Tree result = NULL;
  parseTable = table;
  inputString = string;

  initialiseParser();
  do {    
    IS_readNextToken(inputString);
    parseToken();
    /* If the shift queue is empty and the current level does not contain 
     * an accepting state then an error has occured.*/
    if (!IS_isEndOfString(inputString)) {
      shifter();

      if (PARSER_getVerboseFlag) {
        SG_printStatusBar("sglr: parsing", IS_getNumberOfTokensRead(inputString), IS_getLength(inputString));
      }
    }
  } while (!IS_isEndOfString(inputString) && GSS_getCurrentLevel() != NULL);

  if (PARSER_getVerboseFlag == ATtrue) {
    SG_printDotAndNewLine();
  }

  acceptNode = GSS_getAcceptNode();

  /** \todo verify that the parser will not report success if the accept state 
   * is reached and all the string is not parsed. */
  if (acceptNode && PARSER_getParserFlag()) {
    result = GSSEdge_getTree(GSS_getEdgeListHead(GSSNode_getEdgeList(acceptNode)));
  }

  parseError();

  SGLR_STATS_setCount(SGLR_STATS_parsingMemAllocated, STATS_Allocated());

  GSS_freeGSS();

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

    if (!FLT_getRejectFlag() || !GSSNode_isRejected(st)) {
      actor(st);
    }
    
    if (actives == NULL && forActor == NULL && forActorDelayed != NULL) {
      /*forActor        = forActorDelayed;
      forActorDelayed = NULL;*/
      forActor = GSS_addNodeListElement(GSS_getNodeListHead(forActorDelayed), forActor);
      forActorDelayed = GSS_getNodeListTail(forActorDelayed);
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
        if (IS_checkLookahead(inputString, PTBL_getActionRestrictions(a))) {
          SGLR_STATS_incrementCount(SGLR_STATS_reductionsLADone);
          doReductions(st, a);
        }
        break;
      case ACCEPT:
        if (!FLT_getRejectFlag() || !GSSNode_isRejected(st)) {
          GSS_setAcceptNode(st);
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

  SGLR_STATS_addReductionLength(PTBL_getActionLength(a));
  ps = GSS_findAllPaths(st, PTBL_getActionLength(a), IS_getNumberOfTokensRead(inputString)); 

  while(ps != NULL){
    SGLR_STATS_incrementCount(SGLR_STATS_reductionsDone);

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

  prod = SGLR_PTBL_lookupProduction(parseTable, prodl);
  t = PT_makeTreeAppl(prod, kids);
  SGLR_STATS_incrementCountConditionally(SGLR_STATS_rejectedTreesCreated, PTBL_isSpecialAttrReject(attribute));
  SGLR_STATS_incrementCount(SGLR_STATS_prodTreeNodesCreated);

  st1 = GSS_findNodeInCurrentLevel(s);

  if (st1 == NULL) {
    /* State |s| is not in the current level. */
    st1 = GSSNode_createNode(s, ATfalse);
    nl  = GSSNode_addEdge(st1, st0, t, length, PTBL_isSpecialAttrReject(attribute));
    GSS_addToCurrentLevel(st1);

    /*forActorDelayed = GSS_addNodeListElement(st1, forActorDelayed);*/
    
    if (PTBL_isSpecialAttrReject(attribute)) {
      forActorDelayed = GSS_addNodeListElement(st1, forActorDelayed);
      SGLR_STATS_incrementCount(SGLR_STATS_nodesRejected);
    }
    else {
      forActor= GSS_addNodeListElement(st1, forActor);
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

      nl = GSSNode_addEdge(st1, st0, t, length, PTBL_isSpecialAttrReject(attribute));

      for (sts = GSS_getCurrentLevel(); sts != NULL; sts = GSS_getNodeListTail(sts)) {
        GSSNode st2 = GSS_getNodeListHead(sts);
	
        if ((!FLT_getRejectFlag() || !GSSNode_isRejected(st2)) &&
        GSS_findElementInNodeList(st2, forActor) == NULL && 
	    GSS_findElementInNodeList(st2, forActorDelayed) == NULL) {
          register PTBL_Actions as;

          for (as = SGLR_PTBL_lookupAction(parseTable, GSSNode_getStateNumber(st2), IS_getCurrentToken(inputString));
               as != NULL && !PTBL_isActionsEmpty(as); 
    	       as = PTBL_getActionsTail(as)) {

            PTBL_Action a = PTBL_getActionsHead(as);

            if (SGLR_PTBL_actionKind(a) == REDUCE
                || (SGLR_PTBL_actionKind(a) == REDUCE_LA
                    && IS_checkLookahead(inputString, PTBL_getActionRestrictions(a)))) {
              SGLR_STATS_incrementCountConditionally(SGLR_STATS_limitedLAReductionsDone, (SGLR_PTBL_actionKind(a) == REDUCE_LA && IS_checkLookahead(inputString, PTBL_getActionRestrictions(a))));
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

  SGLR_STATS_addReductionLength(PTBL_getActionLength(a));
  ps = GSS_findLimitedPaths(st, PTBL_getActionLength(a), edge, IS_getNumberOfTokensRead(inputString));

  while(ps) {
    SGLR_STATS_incrementCount(SGLR_STATS_limitedReductionsDone);
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

  SGLR_STATS_incrementCount(SGLR_STATS_shiftsDone);

  t = PT_makeTreeChar(IS_getCurrentToken(inputString));
  SGLR_STATS_incrementCount(SGLR_STATS_symbolTreeNodesCreated);

  while (!GSS_isShiftQueueEmpty()) {
    s   = GSS_getShiftQueueStateNumber();
    st0 = GSS_getShiftQueueGSSNode();  
   
    if (!FLT_getRejectFlag() || !GSSNode_isRejected(st0)) { 
      st1 = GSS_findStateInNodeList(s, newActiveStacks);

      if(st1 == NULL) {
        st1 = GSSNode_createNode(s, ATtrue);
        newActiveStacks = GSS_addNodeListElement(st1, newActiveStacks);
      }

      l = GSSNode_addEdge(st1, st0, t, 1, ATfalse);
    }
    GSS_removeShiftQueueElement();
  }
  GSS_resetShiftQueue();

  GSS_addNewLevel(newActiveStacks);
}

/*-----------------------------ERROR HANDLING--------------------------------*/

static void parseError() {
  ERR_Subject subject;
  ERR_Location posinfo;
  static char subjectDescription[1024];
  static char errorDescription[1024];

  if (!GSS_getAcceptNode()) {
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


