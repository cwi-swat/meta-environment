/*
  $Id$
 */

/*{{{  includes */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <string.h>
#include <sys/times.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <deprecated.h>

#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <asf-builtins.h>

#include "preparation.h"
#include "asfe.tif.h"
#include "asfix_utils.h"
#include "asfe.h"
#include "memotable.h"
#include "traversals.h"

#include "traversals.h"
#include "asf-api.h"

#ifdef USE_TIDE
#include "eval-tide.h"
#endif


/*}}}  */
/*{{{  defines */

#define MAX_DEPTH 2000

#ifdef USE_TIDE
#define TIDE_STEP(posinfo, env, depth) Tide_step(posinfo, env, depth)
#else
#define TIDE_STEP(posinfo, env, depth)
#endif

#define FAIL NULL
/*}}}  */
/*{{{  variables */


static unsigned rewrite_steps = 0;
ASF_Tag tagCurrentRule = NULL;

ATbool runVerbose = ATfalse;
ATbool useTide = ATfalse;

/* rewrite_error contains the first error encountered during evaluation.
 * this error is later sent to the ToolBus (or dumped to stderr in case of 
 * standalone evaluator)
 */
ATerm rewriteError = NULL;

/*
 *  The argument vector: list of option letters, colons denote option
 *  arguments.  See Usage function, immediately below, for option
 *  explanation.
 */

ATerm fail_env;
ATerm posinfo;

AFun list_var, plain_var;
AFun traversal_afun, analyzer_afun, combination_afun, index_afun, tuple_afun;

ATerm equations_db = NULL;
static MemoTable memo_table = NULL;
static char error_buf[BUFSIZ];
static ATbool aborted = ATfalse;

/*}}}  */
/*{{{  static declarations */

/* Used "cproto -S -I<include-dir>" to collect all static functions */

static Slice getListVariableValue(ATerm env, PT_Tree var);
static ATerm putVariableValue(ATerm env, PT_Tree var, PT_Tree value);
static ATerm putListVariableValue(ATerm env, PT_Tree var, PT_Args start, PT_Args end);
static PT_Args getSliceFirst(Slice slice);
static PT_Args getSliceLast(Slice slice);
static ATbool isBoundVariable(ATerm env, PT_Tree var);
static PT_Args prepend(PT_Args first, PT_Args last, PT_Args list);
static PT_Args prependSlice(Slice slice, PT_Args list);
static PT_Args concatElems(PT_Production listProd, PT_Args elems, PT_Args newElems);
static PT_Args appendElem(PT_Production listProd, PT_Args elems, PT_Tree elem);
static ATbool no_new_vars(PT_Tree trm, ATerm env);
static ATerm argMatching(ATerm env, PT_Tree arg1, PT_Tree arg2, ASF_ConditionList conds, PT_Args orgargs1, PT_Args orgargs2, ATerm lhs_posinfo, int depth);
static ATerm argsMatching(ATerm env, ASF_ConditionList conds, PT_Args args1, PT_Args args2, ATerm lhs_posinfo, int depth);
static ATbool compareLists(Slice tuple, PT_Args list);
static PT_Args compareSubLists(Slice slice, PT_Args elems2, 
			       PT_Production listProd);
static ATerm subListMatching(ATerm env, PT_Tree elem, PT_Production listProd, PT_Args elems1, PT_Args elems2, ASF_ConditionList conds, PT_Args args1, PT_Args args2, ATerm lhs_posinfo, int depth);
static ATerm lastListElementMatching(ATerm env, PT_Tree elem1, PT_Args elems2, 
				     PT_Production listProd, 
				     ASF_ConditionList conds, PT_Args args1, PT_Args args2, ATerm lhs_posinfo, int depth);
static ATerm nextListElementMatching(ATerm env, PT_Tree elem1, PT_Production listProd, PT_Args elems1, PT_Args elems2, ASF_ConditionList conds, PT_Args args1, PT_Args args2, ATerm lhs_posinfo, int depth);
static ATerm listMatching(ATerm env, PT_Production listProd, PT_Args elems1, PT_Args elems2, ASF_ConditionList conds, PT_Args args1, PT_Args args2, ATerm lhs_posinfo, int depth);
static ATerm condsSatisfied(ASF_ConditionList conds, ATerm env, int depth);
static PT_Tree reduce(PT_Tree trm, int depth);
static PT_Tree rewrite(PT_Tree trm);
static PT_Tree rewriteRecursive(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Tree rewriteInnermost(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Tree rewriteTraversal(PT_Tree trm, ATerm env, int depth, Traversal *traversal);
static PT_Tree rewriteTraversalBottomUp(PT_Tree trm, ATerm env, int depth, Traversal *traversal);
static PT_Tree rewriteTraversalTopDown(PT_Tree trm, ATerm env, int depth, Traversal *traversal);
static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Tree rewriteArgs(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Args rewriteElems(PT_Production listProd, PT_Args elems, ATerm env, int depth, void *extra);
static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth, void *extra);
static PT_Tree rewriteAPIAppl(PT_Tree tree, ATerm env, int depth, void *extra);
static PT_Tree rewriteListAppl(PT_Tree list, ATerm env, int depth, void *extra);
static PT_Tree rewriteNormalAppl(PT_Tree appl, ATerm env, int depth, void *extra);
static PT_Tree rewriteTraversalAppl(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Tree rewriteBracketAppl(PT_Tree trm, ATerm env, int depth, void *extra);
/*}}}  */

/* ToolBus interfacing */
/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  void debugging(int conn, ATerm on) */

/*
 * Switch debugging on/off
 */

void debugging(ATerm on)
{
  if (ATmatch(on, "on")) {
#ifdef USE_TIDE
    Tide_connect();
    useTide = ATtrue;
#else
    ATwarning("*** SORRY, NO DEBUGGING SUPPORT AVAILABLE "
	      "(you might want to try to configure the asf module --with-tide)\n");
#endif
  }
  else {
    useTide = ATfalse;
  }
}

/*}}}  */
/*{{{  ATerm interpret(int cid, char *modname, ATerm trm) */

ATerm interpret(int cid, char *modname, ATerm eqs, ATerm trm, ATerm tide)
{
  PT_ParseTree parseTree;
  ASF_CondEquationList eqsList;
  ATerm result;

  eqsList = ASF_makeCondEquationListFromTerm(eqs);
  parseTree = PT_makeParseTreeFromTerm(trm);

  result = evaluator(modname, parseTree, eqsList, tide, ATfalse,
		     ATfalse, ATfalse);
  if (RWgetError() == NULL) {
    return ATmake("snd-value(rewrite-result(<term>))", ATBpack(result));
  }
  else {
    return ATmake("snd-value(rewrite-errors([<term>]))", RWgetError());
  }
}

/*}}}  */

/* Error registration */
/*{{{  void RWclearError() */

void RWclearError()
{
  static ATbool is_protected = ATfalse;

  if (!is_protected) {
    is_protected = ATtrue;
    rewriteError = NULL;
    ATprotect(&rewriteError);
  }

  rewriteError = NULL;
}

/*}}}  */
/*{{{  void RWsetError(const char *message, ATerm subject) */

void RWsetError(const char *message, ATerm subject)
{
  if (rewriteError == NULL) {
    RWclearError();		/* Protect rewrite_error if necessary */
    rewriteError = ATmake("[<str>,<term>,<term>])",
			   message, tagCurrentRule,
			   subject);
  }
  aborted = ATtrue;
}

/*}}}  */
/*{{{  ATerm RWgetError() */

ATerm RWgetError()
{
  return rewriteError;
}

/*}}}  */

/* Top level entry point*/
/*{{{  ATerm evaluator(char *name, ATerm term) */

ATerm evaluator(char *name, PT_ParseTree parseTree, ASF_CondEquationList eqs,
                ATerm debug, ATbool remove_layout, ATbool mark_new_layout,
		ATbool allow_ambs)
{
  PT_Tree result;
  PT_Tree tree;

  eqs = RWprepareEquations(eqs, mark_new_layout);
  enter_equations(name, eqs);
  select_equations(name);

  debugging(debug);
  tagCurrentRule = (ASF_Tag) PT_makeTreeLit("*undefined*");
  rewrite_steps = 0;
  memo_table = MemoTableCreate();
  aborted = ATfalse;
  initBuiltins();

  tree = PT_getParseTreeTree(parseTree);
  tree = RWprepareTerm(tree, allow_ambs);

  select_equations(name);

  if (runVerbose) {
    ATwarning("rewriting...\n");
  }

  result = rewrite(tree);

  result = RWrestoreTerm(result, remove_layout);
  parseTree = PT_setParseTreeTree(parseTree, result);

  if (remove_layout) { /* compatible with asc-support */
    parseTree = PT_setParseTreeLayoutBeforeTree(parseTree,
						PT_makeTreeLayoutEmpty());
    parseTree = PT_setParseTreeLayoutAfterTree(parseTree,
					       PT_makeTreeLayoutEmpty());
  }

  MemoTableDestroy(memo_table);

  return PT_makeTermFromParseTree(parseTree);
}

/*}}}  */

/* (List)variable functions and slicing functions */
/*{{{  static PT_Tree getVariableValue(ATerm env, PT_Tree var, PT_Symbol symbol) */

/*
 * Retrieve the value of a variable
 */

PT_Tree getVariableValue(ATerm env, PT_Tree var)
{
  PT_Production prod = PT_getTreeProd(var);
  PT_Symbol symbol = PT_getProductionRhs(prod);

  if (PT_isIterSepSymbol(symbol) || 
      PT_isIterSymbol(symbol)) {
    Slice slice = getListVariableValue(env, var);
    PT_Args newelems;
    
    if (slice) {
      newelems = appendSlice(PT_makeArgsEmpty(), slice);

      return PT_makeTreeAppl(PT_makeProductionList(symbol), newelems);
    }
  }
  else {
    ATermList list = (ATermList) env;
    ATerm atVar = ATmake("<str>", PT_yieldTree(var));

    while (!ATisEmpty(list)) {
      ATermAppl tuple = (ATermAppl) ATgetFirst(list);
      if (ATisEqual(ATgetArgument(tuple, 0), atVar)) {
        return PT_makeTreeFromTerm(ATgetArgument(tuple, 1));
      }

      list = ATgetNext(list);
    }
  }

  return NULL;
}

/*}}}  */
/*{{{  static Slice getListVariableValue(ATerm env, PT_Tree var) */

/*
 * Retrieve the value of a list variable
 */

static Slice getListVariableValue(ATerm env, PT_Tree var)
{
  ATermList list = (ATermList) env;
  /*ATerm atVar = PT_makeTermFromTree(var);*/
  ATerm atVar = ATmake("<str>", PT_yieldTree(var));

  while (!ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl) ATgetFirst(list);
    if (ATisEqual(ATgetArgument(tuple, 0), atVar)) {
      assert(ATgetAFun(tuple) == list_var);
      return (Slice) tuple;
    }

    list = ATgetNext(list);
  }

  return NULL;
}

/*}}}  */
/*{{{  static ATerm putVariableValue(ATerm env, PT_Tree var, PT_Tree value) */

/* 
 * Store the value of a variable in the value environment
 */

static ATerm putVariableValue(ATerm env, PT_Tree var, PT_Tree value)
{
  ATerm atVar = ATmake("<str>", PT_yieldTree(var));
  ATerm atValue = PT_makeTermFromTree(value);

  return (ATerm) ATinsert((ATermList) env,
			  (ATerm) ATmakeAppl2(plain_var, atVar, atValue));
}

/*}}}  */
/*{{{  static ATerm putListVariableValue(ATerm env, PT_Tree var, PT_Args start, PT_Args end) */

static ATerm putListVariableValue(ATerm env, PT_Tree var, PT_Args start, PT_Args end)
{
  ATerm atVar = ATmake("<str>", PT_yieldTree(var));
  ATerm atStart = PT_makeTermFromArgs(start);
  ATerm atEnd = PT_makeTermFromArgs(end);

  return (ATerm) ATinsert((ATermList) env,
			  (ATerm) ATmakeAppl3(list_var, atVar,
					      atStart, atEnd));
}

/*}}}  */
/*{{{  static PT_Args getSliceFirst(Slice slice) */

static PT_Args getSliceFirst(Slice slice)
{
  return PT_makeArgsFromTerm(ATgetArgument((ATermAppl) slice, 1));
}

/*}}}  */
/*{{{  static PT_Args getSliceLast(Slice slice) */

static PT_Args getSliceLast(Slice slice)
{
  return PT_makeArgsFromTerm(ATgetArgument((ATermAppl) slice, 2));
}

/*}}}  */
/*{{{  static ATbool isBoundVariable(ATerm env, PT_Tree var) */

/*
  * See if a variable is bound.
  */

static ATbool isBoundVariable(ATerm env, PT_Tree var)
{
  ATermList list = (ATermList) env;
  ATerm atVar = ATmake("<str>", PT_yieldTree(var));

  while (!ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl) ATgetFirst(list);
    if (ATisEqual(ATgetArgument(tuple, 0), atVar)) {
      return ATtrue;
    }
    list = ATgetNext(list);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  static PT_Args prepend(PT_Args first, PT_Args last, PT_Args list) */

/*
 * Prepend a slice to the front of a list
 */

static PT_Args prepend(PT_Args first, PT_Args last, PT_Args list)
{
  PT_Args temp;
  PT_Tree elem;

  if (PT_isEqualArgs(first, last)) {
    return list;
  }

  elem = PT_getArgsHead(first);
  temp = prepend(PT_getArgsTail(first), last, list);

  if (PT_isArgsEmpty(temp) && PT_isTreeLayout(elem)) {
    return PT_makeArgsEmpty();
  }

  return PT_makeArgsList(elem, temp);
}

/*}}}  */
/*{{{  static PT_Args prependSlice(Slice slice, PT_Args list) */

static PT_Args prependSlice(Slice slice, PT_Args list)
{
  PT_Args first = getSliceFirst(slice);
  PT_Args last = getSliceLast(slice);

  return prepend(first, last, list);
}

/*}}}  */
/*{{{  PT_Args appendSlice(PT_Args list, Slice slice) */

/*
 * Append a slice to a list
 */

PT_Args appendSlice(PT_Args list, Slice slice)
{
  return PT_concatArgs(list, prependSlice(slice, PT_makeArgsEmpty()));
}

/*}}}  */
/*{{{  static PT_Args concatElems(listProd, PT_Args elems, PT_Args newElems) */

/* The list of elements is rewritten and a new elementlist
   is constructed. */


static PT_Args 
concatElems(PT_Production listProd, PT_Args elems, PT_Args newElems)
{
  PT_Args newList;
  PT_Symbol sym = PT_getProductionRhs(listProd);
  int seplen = 0;

  if (PT_isSymbolLex(sym)) {
    if (PT_isIterSepSymbol(sym)) {
      seplen = 1;
    }
    else {
      seplen = 0;
    }
  }
  else if (PT_isSymbolCf(sym)) {
    if (PT_isIterSepSymbol(sym)) {
      seplen = 3;
    }
    else {
      seplen = 1;
    }
  }

  if (PT_isArgsEmpty(elems)) {
    newList = newElems;
  }
  else {
    if (!PT_isArgsEmpty(newElems)) {
      newList = PT_concatArgs(elems, newElems);
    }
    else {
      int length = PT_getArgsLength(elems);
      if (length > seplen) {
	newList = PT_sliceArgs(elems, 0, length-seplen);
      }
      else {
	newList = PT_makeArgsEmpty();
      }
    }
  }

  pedantic_assert(isValidList(newList));
  return newList;
}

/*}}}  */
/*{{{  static PT_Args appendElem(PT_Production listProd, PT_Args elems, PT_Tree elem) */

static PT_Args appendElem(PT_Production listProd, PT_Args elems, PT_Tree elem)
{
  if (PT_isArgsEmpty(elems)) {
    if (PT_isTreeLayout(elem)) {
      return elems;
    }
    else if (isListSeparator(elem, listProd)) {
      return elems; 
    }
  }
  return PT_appendArgs(elems, elem);
}

/*}}}  */
/*{{{  static PT_Args addElemsToArgs(PT_Production listProd, PT_Args elems, PT_Args args)  */

static PT_Args addElemsToArgs(PT_Production listProd, PT_Args elems, 
			      PT_Args args) 
{
  PT_Tree listArg = PT_makeTreeAppl(listProd, elems);
  return PT_makeArgsList(listArg, args);
}

/*}}}  */
/*{{{  static ATerm getFirstArgument(PT_Tree trm) */

static PT_Tree getFirstArgument(PT_Tree trm)
{
  PT_Args args;

  if (!PT_hasTreeArgs(trm)) {
    return NULL;
  }

  args = PT_getTreeArgs(trm);

  while (PT_hasArgsHead(args) &&
	 (PT_isTreeLit(PT_getArgsHead(args)) ||
	  PT_isTreeLayout(PT_getArgsHead(args)))) {
    args = PT_getArgsTail(args);
  }

  if (PT_hasArgsHead(args)) {
    return PT_getArgsHead(args);
  }

  return NULL;
}

/*}}}  */

/* Other utilities */
/*{{{  static ATbool no_new_vars(PT_Tree trm, ATerm env) */
/* A predicate which checks whether a term introduces new
   variables. This functions is used when dealing with the
   conditions of equations. */

static ATbool no_new_vars(PT_Tree trm, ATerm env)
{
  PT_Tree arg;
  PT_Args args;
  ATbool existing;

  if (PT_isTreeVar(trm)) {
    if (isBoundVariable(env, trm))
      return ATtrue;
    else
      return ATfalse;
  }
  else if (PT_isTreeAppl(trm)) {
    existing = ATtrue;
    args = PT_getTreeArgs(trm);
    while (existing && PT_hasArgsHead(args)) {
      arg = PT_getArgsHead(args);
      existing = no_new_vars(arg, env);
      args = PT_getArgsTail(args);
    };
    return existing;
  }
  else {
    return ATtrue;
  }
}

/*}}}  */

/* Matching functionality */
/*{{{  static ATerm varMatching(ATerm env, */

static ATerm varMatching(ATerm env,
			 PT_Tree var,
			 PT_Tree arg2,
			 ASF_ConditionList conds,
			 PT_Args orgargs1, PT_Args orgargs2,
			 ATerm lhs_posinfo, int depth)
{
  PT_Tree trm = getVariableValue(env, var);
  ATerm newenv = fail_env;

  if (trm != NULL) {
    if (isAsFixEqual(arg2, trm)) {
      newenv = argsMatching(env, conds, orgargs1, orgargs2,
			  lhs_posinfo, depth);
    }
    else {
      newenv = fail_env;
    }
  }
  else {
    newenv = putVariableValue(env, var, arg2);
    newenv = argsMatching(newenv, conds, orgargs1, orgargs2, lhs_posinfo, 
			  depth);
  }

  return newenv;
}

/*}}}  */
/*{{{  static ATerm applMatching(ATerm env, */

static ATerm applMatching(ATerm env,
			 PT_Tree arg1,
			 PT_Tree arg2,
			 ASF_ConditionList conds,
			 PT_Args orgargs1, PT_Args orgargs2,
			 ATerm lhs_posinfo, int depth)
{
  PT_Production prod1 = PT_getTreeProd(arg1);
  PT_Production prod2 = PT_getTreeProd(arg2);
  ATerm newenv;

  if (PT_isEqualProduction(prod1, prod2)) {
    PT_Args args1 = PT_getTreeArgs(arg1);
    PT_Args args2 = PT_getTreeArgs(arg2);

    newenv = argsMatching(env, conds, 
			  PT_concatArgs(args1, orgargs1),
			  PT_concatArgs(args2, orgargs2),
			  lhs_posinfo, depth);
  }
  else {
    newenv = fail_env;
  }

  return newenv;
}

/*}}}  */
/*{{{  static ATerm argMatching(env, arg1, arg2, conds, org1, org2, posinfo, depth) */

static ATerm argMatching(ATerm env, 
			 PT_Tree arg1, PT_Tree arg2,
			 ASF_ConditionList conds,
			 PT_Args orgargs1, PT_Args orgargs2,
			 ATerm lhs_posinfo, int depth)
{
  ATerm newenv = fail_env;

  if (runVerbose) {
    ATwarning("%t:matching: %t\nwith\n%t\n\n",
	      yieldTree((PT_Tree) tagCurrentRule), yieldTree(arg1), 
              yieldTree(arg2));
  }

  /* equality check is cheap, so try this first */
  if (PT_isEqualTree(PT_removeTreeAnnotations(arg1),
		     PT_removeTreeAnnotations(arg2))) {
    newenv = argsMatching(env, conds, orgargs1, orgargs2, lhs_posinfo, depth);
  }
  else if (PT_isTreeLayout(arg1)) {
    newenv = argsMatching(env, conds, orgargs1, orgargs2, lhs_posinfo, depth);
  }
  else if (PT_isTreeApplList(arg1)) {
    PT_Args elems1 = PT_getTreeArgs(arg1);
    PT_Args elems2 = PT_getTreeArgs(arg2);
    PT_Production prod1 = PT_getTreeProd(arg1);

    newenv = listMatching(env, prod1, elems1, elems2,
			conds, orgargs1, orgargs2, 
			lhs_posinfo, depth);
  }
  else if (PT_isTreeVar(arg1)) {
    newenv = varMatching(env, arg1, arg2, conds, orgargs1, orgargs2,
		       lhs_posinfo, depth);
  }
  else if (PT_isTreeAppl(arg1)) {
    newenv = applMatching(env, arg1, arg2, conds, orgargs1, orgargs2,
			lhs_posinfo, depth);
  }

  return newenv;
}


/*}}}  */
/*{{{  static ATerm argsMatching(ATerm env, ASF_ConditionList conds, */

static ATerm argsMatching(ATerm env, ASF_ConditionList conds,
			  PT_Args args1, PT_Args args2, 
			  ATerm lhs_posinfo, int depth)
{
  PT_Tree arg1, arg2;
  ATerm newenv = env;

  if (runVerbose) {
    ATwarning("args %t matched against %t\n", 
        yieldArgs(args1),
        yieldArgs(args2));
  }

  assert(PT_getArgsLength(args1) == PT_getArgsLength(args2) &&
	 "if prods are equal, then the number of arguments should be too");

  if (PT_hasArgsHead(args1)) {
    arg1 = PT_getArgsHead(args1);
    args1 = PT_getArgsTail(args1);
    arg2 = PT_getArgsHead(args2);
    args2 = PT_getArgsTail(args2);

    newenv = argMatching(newenv, arg1, arg2, conds, args1, args2, 
			 lhs_posinfo, depth);
  }
  else {
    if (lhs_posinfo) {
      TIDE_STEP(lhs_posinfo, newenv, depth);
    }

    newenv = condsSatisfied(conds, newenv, depth);
  }

  return newenv;
}

/*}}}  */

/* List Matching functionality */
/*{{{  static ATbool compareLists(Slice tuple, PT_Args list) */

static ATbool compareLists(Slice tuple, PT_Args list)
{
  PT_Args first, last;

  assert(ATgetAFun(tuple) == list_var);
  first = getSliceFirst(tuple);
  last = getSliceLast(tuple);

  while (!PT_isEqualArgs(first, last)) {
    PT_Tree elem1, elem2;

    if (PT_isArgsEmpty(list)) {
      return ATfalse;
    }

    elem1 = PT_getArgsHead(first);
    elem2 = PT_getArgsHead(list);

    if (!isAsFixEqual(elem1, elem2)) {
      return ATfalse;
    }

    first = PT_getArgsTail(first);
    list = PT_getArgsTail(list);
  }

  return PT_isArgsEmpty(list);
}

/*}}}  */
/*{{{  static PT_Args compareSubLists(Slice slice, PT_Args elems2, 
 * PT_Production listProd) */

static PT_Args compareSubLists(Slice slice, PT_Args elems2, 
			       PT_Production listProd)
{
  PT_Tree elem1, elem2;
  PT_Args first, last;
  ATbool match = ATtrue;

  assert(ATgetAFun(slice) == list_var);
  first = getSliceFirst(slice);
  last = getSliceLast(slice);

    first = skipWhitespaceAndSeparator(first,listProd);
    elems2 = skipWhitespaceAndSeparator(elems2,listProd);

    pedantic_assert(isValidSlice(first, last));
    pedantic_assert(isValidList(elems2));

  while (!PT_isEqualArgs(first, last) && match) {
      first = skipWhitespaceAndSeparator(first,listProd);
      assert(isValidSlice(first, last));

    elem1 = PT_getArgsHead(first);
    if (PT_hasArgsHead(elems2)) {
      elem2 = PT_getArgsHead(elems2);
      match = isAsFixEqual(elem1, elem2);

	elems2 = skipWhitespaceAndSeparator(PT_getArgsTail(elems2),listProd);
	assert(isValidList(elems2));
    }
    else {
      match = ATfalse;
    }

    first = PT_getArgsTail(first);
  }

  if (match) {
    pedantic_assert(isValidList(elems2));
    return elems2;
  }
  else {
    return NULL;
  }
}

/*}}}  */
/*{{{  static ATerm subListMatching(env, el, listProd, e1, e2, cnds, a1, a2, pos, d) */


/* subListMatching
 *
 * Tries different sizes for a single list variable.
 */

static ATerm
subListMatching(ATerm env, PT_Tree elem,
		PT_Production listProd, PT_Args elems1, PT_Args elems2,
		ASF_ConditionList conds,
		PT_Args args1, PT_Args args2,
                ATerm lhs_posinfo, int depth)
{
  ATerm subenv, newenv;
  PT_Args last;
 
/* 
ATwarning("subListMatching entered for %t with %t\n",
          yieldTree(elem),
          yieldArgs(elems2)); 
*/

  if (PT_isTreeVarListStar(elem)) {
    /* try to match with zero elements for star variable */
    newenv = putListVariableValue(env, elem, PT_makeArgsEmpty(),
				  PT_makeArgsEmpty());

    subenv =
      listMatching(newenv, listProd, elems1, elems2, conds, 
                   args1, args2,
                   lhs_posinfo, depth);
  }
  else {
    /* if plus variable, do not try to match with zero elements */
    subenv = fail_env;
    if (runVerbose) {
      ATwarning("*** fail_env on line %d\n", __LINE__);
    }
  }

  /* Make sure we begin at a regular element */
  elems2 = skipWhitespaceAndSeparator(elems2, listProd);
  pedantic_assert(isValidList(elems2));

  /* If the star variable didn't match or we have a plus variable
   * we continue matching with increasing length while possible.
   */

  if (PT_hasArgsHead(elems2)) {
    for (last = PT_getArgsTail(elems2);	/* create a singleton */
	 is_fail_env(subenv);
	 /* add an element to the slice */
	 last = PT_getArgsTail(skipWhitespaceAndSeparator(last, listProd))) {
      pedantic_assert(isValidSlice(elems2, last));
      newenv = putListVariableValue(env, elem, elems2, last);
      subenv =
	listMatching(newenv, listProd, elems1, last,
                     conds, args1, args2,
		     lhs_posinfo, depth);

      if (!PT_hasArgsHead(last)) {
	/* the entire list has been tried now */
	break;
      }
    }
  }

  return subenv;
}


/*}}}  */
/*{{{  static ATerm lastListElementMatching(env, el1, els2, conds, a1, a2, pos, d) */

static ATerm
lastListElementMatching(ATerm env, PT_Tree elem1, 
                        PT_Args elems2,
			PT_Production listProd,
                        ASF_ConditionList conds, 
                        PT_Args args1, PT_Args args2,
                        ATerm lhs_posinfo, int depth) 
{
  PT_Tree elem2;
  ATerm newenv;

  if (runVerbose) {
    ATwarning("lastListElementMatching: %t matched with %t\n",
              yieldTree(elem1),
              yieldArgs(elems2));
  }

  if (PT_isTreeVarList(elem1)) {
    Slice trms = getListVariableValue(env, elem1);
    if (trms) {
      if (compareLists(trms, elems2)) {
        newenv = argsMatching(env, conds, args1, args2,
    			      lhs_posinfo, depth);
      }
      else {
        newenv = fail_env;
        if (runVerbose) {
          ATwarning("*** fail_env on line %d\n", __LINE__);
        }
      }
    }
    else {			/* TdictGet(env,elem1) == Tfalse */
      if (PT_isTreeVarListPlus(elem1) && PT_isArgsEmpty(elems2)) {
        newenv = fail_env;
        if (runVerbose) {
          ATwarning("*** fail_env on line %d\n", __LINE__);
        }
      }
      else {
        elems2 = skipWhitespaceAndSeparator(elems2, listProd);
        pedantic_assert(isValidList(elems2));

        if (PT_hasArgsHead(elems2)) {
          elem2 = PT_getArgsHead(elems2);
        }
    
        pedantic_assert(isValidSlice(elems2, PT_makeArgsEmpty()));
        newenv =
          putListVariableValue(env, elem1, elems2, PT_makeArgsEmpty());
        newenv =
          argsMatching(newenv, conds, args1, args2, 
                       lhs_posinfo, depth);
      }
    }
  }
  else {			/*is_list_var(elem1) == Tfalse */
    if (!PT_isArgsEmpty(elems2)) {
      elem2 = PT_getArgsHead(elems2);
      elems2 = PT_getArgsTail(elems2);
      if (PT_isArgsEmpty(elems2)) {	/* is singleton */
        newenv =
          argMatching(env, elem1, elem2,
                      conds, args1, args2,
                      lhs_posinfo, depth);
      }
      else {
        newenv = fail_env;
        if (runVerbose) {
          ATwarning("*** fail_env on line %d\n", __LINE__);
        }
      }
    }
    else {
      newenv = fail_env;
      if (runVerbose) {
        ATwarning("*** fail_env on line %d\n", __LINE__);
      }
    }
  }
  return newenv;
}


/*}}}  */
/*{{{  static ATerm nextListElementMatching(env, elem1, listProd, ...) */

static ATerm
nextListElementMatching(ATerm env, PT_Tree elem1, 
                        PT_Production listProd, 
                        PT_Args elems1, PT_Args elems2,
                        ASF_ConditionList conds, 
                        PT_Args args1, PT_Args args2,
                        ATerm lhs_posinfo, int depth) 
{
  PT_Tree elem2 = NULL;
  ATerm newenv;

  if (runVerbose) {
    ATwarning("%t:matching next element: %t\ngiven %t\n and %s\n\n\n",
	      yieldTree((PT_Tree) tagCurrentRule), 
              yieldTree(elem1), 
              yieldArgs(elems2), 
              PT_yieldProduction(listProd));
  }

  if (PT_isTreeVarList(elem1)) {
    Slice trms = getListVariableValue(env, elem1);
    if (trms) {
      elems2 = compareSubLists(trms, elems2, listProd);
      if (elems2) {
        newenv = listMatching(env, listProd, elems1, elems2, conds,
                              args1, args2,
                              lhs_posinfo, depth);
      }
      else {
        newenv = fail_env;
        if (runVerbose) {
          ATwarning("*** fail_env on line %d\n", __LINE__);
        }
      }
    }
    else {      /* list variable elem1 does not occur in value env. */
      newenv = subListMatching(env, elem1, 
                               listProd, elems1, elems2,
                               conds, args1, args2, 
                               lhs_posinfo, depth);
    }
  }
  else if (isListSeparator(elem1, listProd)) {
    if (PT_hasArgsHead(elems2)) {
      elem2 = PT_getArgsHead(elems2);

      if (isListSeparator(elem2, listProd)) {

        elems2 = skipWhitespace(PT_getArgsTail(elems2));

        pedantic_assert(isValidList(elems2));
      
	newenv = argMatching(env, elem1, elem2, conds,
                             addElemsToArgs(listProd, elems1, args1),
                             addElemsToArgs(listProd, elems2, args2),
			     lhs_posinfo, depth);
      }
      else {
        elems1 = skipWhitespace(PT_getArgsTail(elems1)); 
        newenv = listMatching(env, listProd, elems1, elems2, conds,
                              args1, args2,
                              lhs_posinfo, depth);
      }
    }
    else {
      elems1 = skipWhitespace(PT_getArgsTail(elems1)); 
      newenv = listMatching(env, listProd, elems1, elems2, conds,
                            args1, args2,
                            lhs_posinfo, depth);
    }
  }
  else {  /* elem1 is not a list variable and not a separator */
    if (PT_hasArgsHead(elems2)) {
      elem2 = PT_getArgsHead(elems2);

      elems2 = skipWhitespace(PT_getArgsTail(elems2)); 
      pedantic_assert(isValidList(elems2));

      if (isListSeparator(elem2, listProd)) {
        newenv = listMatching(env, listProd, elems1, elems2, conds,
                              args1, args2,
                              lhs_posinfo, depth);
      }
      else {
	newenv=  argMatching(env, elem1, elem2, conds,
                             addElemsToArgs(listProd, elems1, args1),
                             addElemsToArgs(listProd, elems2, args2),
			     lhs_posinfo, depth);
      }
    }
    else {
      newenv = fail_env;
      if (runVerbose) {
        ATwarning("*** fail_env on line %d\n", __LINE__);
      }
    }
  }
  return newenv;
}


/*}}}  */
/*{{{  static ATerm listMatching(env, listProd, elems1, elems2, conds, args1, ...) */

static ATerm
listMatching(ATerm env, PT_Production listProd,
             PT_Args elems1, PT_Args elems2,
	     ASF_ConditionList conds, 
             PT_Args args1, PT_Args args2,
	     ATerm lhs_posinfo, int depth)
{
  PT_Tree elem1;
  ATerm newenv;

  elems1 = skipWhitespaceAndSeparator(elems1,listProd);
  pedantic_assert(isValidList(elems1));
  elems2 = skipWhitespaceAndSeparator(elems2,listProd);
  pedantic_assert(isValidList(elems2));

  if (runVerbose) {
    ATwarning("%t:matching elements: %t\nwith\n%t given %s\n\n\n",
	      yieldTree((PT_Tree) tagCurrentRule), 
              yieldArgs(elems1), 
              yieldArgs(elems2), 
              PT_yieldProduction(listProd));
  }


  if (PT_hasArgsHead(elems1)) {
    elem1 = PT_getArgsHead(elems1);
    elems1 = PT_getArgsTail(elems1);

    if (PT_isArgsEmpty(elems1)) { /* elems1 was a single element list */
      newenv = lastListElementMatching(env, elem1, elems2, listProd, conds, 
                                       args1, args2, lhs_posinfo, depth);
    }
    else { /* elems1 contained more than one element in its pattern */
      newenv = nextListElementMatching(env, elem1, 
                                       listProd, elems1, elems2,
                                       conds, 
                                       args1, args2,
                                       lhs_posinfo, depth);
    }
  }
  else { /* elems1 is empty, so we are successful if elems2 are empty
          * as well
          */
    if (!PT_isArgsEmpty(elems2)) {
      newenv = fail_env;
      if (runVerbose) {
	ATwarning("*** fail_env on line %d\n", __LINE__);
      }
    }
    else {
      newenv = argsMatching(env, conds, args1, args2, 
                            lhs_posinfo, depth);
    }
  }

  return newenv;
}


/*}}}  */

/* condition checking */
/*{{{  static ATerm negativeCondSatisfied(PT_Tree lhs, PT_Tree rhs,  */

static ATerm negativeCondSatisfied(PT_Tree lhs, PT_Tree rhs, 
				   ASF_ConditionList conds,
				   ATerm env, 
				   int depth)
{
  PT_Tree lhstrm, rhstrm;

  /* assuming that none of the sides introduce new variables */

  TIDE_STEP(PT_getTreeAnnotation(lhs, posinfo), env, depth);
  lhstrm = rewriteInnermost(lhs, env, depth + 1 , NO_TRAVERSAL);

  if (!lhstrm) {
    return fail_env;
  }

  TIDE_STEP(PT_getTreeAnnotation(rhs, posinfo), env, depth);
  rhstrm = rewriteInnermost(rhs, env, depth + 1, NO_TRAVERSAL);

  if (!rhstrm) {
    return fail_env;
  }

  if (isAsFixEqual(lhstrm, rhstrm)) {
    if (runVerbose) {
      ATwarning("*** fail_env on line %d\n", __LINE__);
    }

    return fail_env;
  }

  return condsSatisfied(conds, env, depth);
}

/*}}}  */
/*{{{  static ATerm positiveCondSatisfied(PT_Tree lhs, PT_Tree rhs,  */

static ATerm positiveCondSatisfied(PT_Tree lhs, PT_Tree rhs, 
				   ASF_ConditionList conds,
				   ATerm env, int depth)
{
  PT_Tree lhstrm = lhs;
  PT_Tree rhstrm = rhs;

  /* assuming that not both sides have new vars */

  if (!no_new_vars(rhs,env)) { /* a matching condition */
    TIDE_STEP(PT_getTreeAnnotation(lhs, posinfo), env, depth);
    lhstrm = rewriteInnermost(lhs, env, depth + 1, NO_TRAVERSAL);
    if (!lhstrm) {
      return fail_env;
    }
    TIDE_STEP(PT_getTreeAnnotation(rhs, posinfo), env, depth);
    return argMatching(env, rhs, lhstrm, conds, 
		       PT_makeArgsEmpty(), PT_makeArgsEmpty(), 
		       NULL, depth);
  }
  else if (!no_new_vars(lhs, env)) { /* flip the sides */
    return positiveCondSatisfied(rhs, lhs, conds, env, depth);
  }
  else { /* an equality condition */
    TIDE_STEP(PT_getTreeAnnotation(lhs, posinfo), env, depth);
    lhstrm = rewriteInnermost(lhs, env, depth + 1, NO_TRAVERSAL);
    if (!lhstrm) {
      return fail_env;
    }

    TIDE_STEP(PT_getTreeAnnotation(rhs, posinfo), env, depth);
    rhstrm = rewriteInnermost(rhs, env, depth + 1, NO_TRAVERSAL);
    if (!rhstrm) {
      return fail_env;
    }

    if (isAsFixEqual(lhstrm, rhstrm)) {
      return condsSatisfied(conds, env, depth);
    }
    else {
      return fail_env;
    }
  }
}

/*}}}  */
/*{{{  static ATerm condSatisfied(ASF_Condition cond, ASF_ConditionList conds, */

static ATerm condSatisfied(ASF_Condition cond, ASF_ConditionList conds,
			   ATerm env, int depth)
{
  PT_Tree lhs = ASFtoPT(ASF_getConditionLhs(cond));
  PT_Tree rhs = ASFtoPT(ASF_getConditionRhs(cond));


  if (ASF_isConditionPositive(cond)) {
    return positiveCondSatisfied(lhs, rhs, conds, env, depth);
  }
  else {
    return negativeCondSatisfied(lhs, rhs, conds, env, depth);
  }
}

/*}}}  */
/*{{{  static ATerm condsSatisfied(ASF_ConditionList conds, ATerm env, int depth) */
static ATerm condsSatisfied(ASF_ConditionList conds, ATerm env, int depth)
{
  ASF_Condition cond;
  ATerm newenv = env;

  if (conds == NULL) {
    return env;
  }

  if (ASF_hasConditionListHead(conds)) {
    cond = ASF_getConditionListHead(conds);

    if (ASF_hasConditionListTail(conds)) {
      conds = ASF_getConditionListTail(conds);
    }
    else {
      conds = NULL;
    }
 
    newenv = condSatisfied(cond, conds, env, depth);

  }

  return newenv;
}
/*}}}  */

/* Reduction functionality */
/*{{{  static ATerm try(PT_Tree trm, equation_entry *entry, int depth) */

static ATerm try(PT_Tree trm, equation_entry *entry, int depth)
{
  ATerm env = fail_env;

  if (runVerbose) {
    ATwarning("Trying equation: %s\n", PT_yieldTree((PT_Tree)entry->tag));
  }

  tagCurrentRule = entry->tag;
  currentRule = entry;

  env = argMatching((ATerm) ATempty, entry->lhs, trm, entry->conds,
		    PT_makeArgsEmpty(), PT_makeArgsEmpty(),
		    PT_getTreeAnnotation(entry->lhs, posinfo), depth);


  tagCurrentRule = entry->tag;
  currentRule = entry;


  if (!is_fail_env(env)) {
    if (runVerbose) {
      ATwarning("Equation %s was successful.\n", 
		PT_yieldTree((PT_Tree)entry->tag));
    }

    TIDE_STEP(PT_getTreeAnnotation(entry->rhs, posinfo), env, depth);
    rewrite_steps++;
  }
  else {
    if (runVerbose) {
      ATwarning("Equation %s failed.\n", PT_yieldTree((PT_Tree)entry->tag));
    }
  }

  return env;
}

/*}}}  */
/*{{{  static ATermList reduce(PT_Tree trm, int depth) */

static PT_Tree reduce(PT_Tree trm, int depth)
{
  PT_Tree first_arg;
  PT_Production top_ofs = NULL;
  PT_Production first_ofs = NULL;
  ATerm env = (ATerm) ATempty;
  equation_entry *entry = NULL;
  int i, tries;

  top_ofs = PT_getTreeProd(trm);
  first_arg = getFirstArgument(trm);

  tries = 1;
  if (first_arg != NULL) {
    first_ofs = PT_getTreeProd(first_arg);
    tries++;
  }

  /* We try to find equations, first with a (guarded) first argument,
   * then once more without a guarded first argument.
   */
  for(i = 0; i < tries; i++) {
    while ((entry = find_equation(entry, top_ofs, first_ofs))) {
      env = try(trm, entry, depth);

      if (!is_fail_env(env)) {
	/* This should not happen here! Only substition should take
	 * place here and in rewriteInnermost the recursive call should
	 * be made.
	 */
	return rewriteRecursive(entry->rhs, env, depth + 1, NULL);
      }
    }

    first_ofs = NULL; /* next loop without the first argument */
  }

  /* this should be 'return FAIL' */
  return trm;
}

/*}}}  */

/* Rewriting strategies  */
/*{{{  static PT_Tree rewrite(PT_Tree trm) */

static PT_Tree rewrite(PT_Tree trm)
{
  PT_Tree reduct = rewriteRecursive(trm,(ATerm) ATempty, 0, NO_TRAVERSAL);

  return reduct == FAIL ? trm : reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteRecursive(PT_Tree trm, ATerm env, int depth, void* extra) */

static PT_Tree rewriteRecursive(PT_Tree trm, ATerm env, int depth, void* extra)
{
  PT_Tree reduct;
  equation_entry *entry = currentRule;

  if (aborted) {
    reduct = trm;
  }

  if (depth > MAX_DEPTH) {
    sprintf(error_buf, "maximum stack depth (%d) exceeded.", MAX_DEPTH);
    RWsetError(error_buf, (ATerm) ATempty);
    reduct = trm;
  }

  /* select the appriopriate rewriting strategy */
  if (extra != NULL) {
    reduct = rewriteTraversal(trm, env, depth, extra);
  }
  else {
    reduct = rewriteInnermost(trm, env, depth, NO_TRAVERSAL);
  }

  currentRule = entry;

  return reduct;
}

/*}}}  */

/*{{{  static PT_Tree rewriteInnermost(PT_Tree trm, ATerm env, int depth, void *extra) */

static PT_Tree rewriteInnermost(PT_Tree trm, ATerm env, int depth, void *extra)
{
  PT_Tree reduct = FAIL;

  if (PT_isTreeVar(trm) || PT_isTreeVarList(trm)) {
    reduct = rewriteVariableAppl(trm, env, depth, extra);
  }
  else if (PT_hasTreeArgs(trm)) {

    /* first the kids */    
    reduct = rewriteArgs(trm, env, depth, extra);

    if (reduct != FAIL) {
      trm = reduct;
    }

    if (trm) {
      /* Then the parent */
      reduct = rewriteTop(trm, env, depth, extra);

      if (reduct == FAIL) {
	reduct = trm;
      }
    }
  }

  return reduct;
}

/*}}}  */

/*{{{  static PT_Tree rewriteTraversal(PT_Tree trm, ATerm env, int depth, */

static PT_Tree rewriteTraversal(PT_Tree trm, ATerm env, int depth,
				Traversal* traversal)
{
  PT_Tree reduct = FAIL;

  if (PT_isTreeVar(trm)) {
    reduct = rewriteVariableAppl(trm, env, depth, traversal);
  }
  else if (traversal->strategy == TOPDOWN) {
    reduct = rewriteTraversalTopDown(trm,env,depth,traversal);
  }
  else if (traversal->strategy == BOTTOMUP) {
    reduct = rewriteTraversalBottomUp(trm,env,depth,traversal);
  }
  else {
    ATerror("rewriteTraversal: unknown traversal type");
  }

  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteTraversalBottomUp(PT_Tree trm, ATerm env, int depth, */

static PT_Tree rewriteTraversalBottomUp(PT_Tree trm, ATerm env, int depth,
					Traversal* traversal)
{
  PT_Tree reduct = FAIL;

  if (PT_hasTreeArgs(trm)) {
    PT_Tree travtrm, reduct_args, reduct_args_tmp;
    reduct_args = rewriteArgs(trm, env, depth, traversal);

    if (reduct_args != FAIL) {
      reduct_args_tmp = rewriteTop(reduct_args, env, depth, NO_TRAVERSAL);

      if (reduct_args_tmp != FAIL) {
	reduct_args = reduct_args_tmp;
      }
    }

    if ((traversal->continuation == BREAK && reduct_args == FAIL) ||
	traversal->continuation == CONTINUE) {
      travtrm = makeTraversalAppl(reduct_args == FAIL ?
				  trm : reduct_args, *traversal);

      reduct = rewriteTop(travtrm, env, depth, traversal);
    }

    if (reduct == FAIL) {
      reduct = reduct_args;
    }
  }

  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteTraversalTopDown(PT_Tree trm, ATerm env, int depth,  */

static PT_Tree rewriteTraversalTopDown(PT_Tree trm, ATerm env, int depth, 
				       Traversal* traversal)
{
  PT_Tree reduct = FAIL;

  if (PT_hasTreeArgs(trm)) {
    PT_Tree travtrm, reduct_top, reduct_args;

    travtrm = makeTraversalAppl(trm, *traversal);
    reduct_top = rewriteTop(travtrm, env, depth, traversal);

    if ((traversal->continuation == BREAK && reduct_top == FAIL) ||
	traversal->continuation == CONTINUE) {
      reduct_args = rewriteArgs(reduct_top == FAIL ?
				trm : reduct_top, env, depth, traversal);

      if (reduct_args != FAIL) {
	reduct = rewriteTop(reduct_args, env, depth, NO_TRAVERSAL);

	if (reduct == FAIL) {
	  reduct = reduct_args;
	}
      } 
      else {
	reduct = reduct_top;
      }
    }
    else {
      reduct = reduct_top;
    }
  }

  return reduct;
}

/*}}}  */

/*{{{  static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra) */

static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra)
{
  PT_Tree reduct = FAIL;

  /* The order of this if-then-else is important because the conditions
   * are not mutually exclusive.
   */
 
  /* the function called below should not do any recursion in the current
   * strategy, because this function only rewrites the top.
   */ 
  if (PT_isTreeApplList(trm)) {
    reduct = rewriteListAppl(trm, env, depth, extra);
  }
  else if (PT_isTreeBracket(trm)) {
    reduct = rewriteBracketAppl(trm, env, depth, extra);
  }
  else if (extra == NULL && ASF_isTreeTraversalFunction((ASF_Tree) trm)) { 
    /* only do this if we are not in a traversal already */
    reduct = rewriteTraversalAppl(trm, env, depth, extra);
  }
  else if (isTreeAPIFunction(trm)) {
    reduct = rewriteAPIAppl(trm, env, depth, extra);
  }
  else if (PT_isTreeAppl(trm)) {
    reduct = rewriteNormalAppl(trm, env, depth, extra);
  }

  if (PT_isEqualTree(reduct,trm)) {
    reduct = FAIL;
  }

  if (reduct != FAIL && extra != NULL) {
    reduct = makeTraversalReduct(trm, reduct, extra);
  }

  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteArgs(PT_Tree trm, ATerm env, int depth, void* extra) */

static PT_Tree rewriteArgs(PT_Tree trm, ATerm env, int depth, void* extra)
{
  PT_Args args;
  PT_Tree arg, newarg, reduct = FAIL;
  PT_Args newargs = PT_makeArgsEmpty();
  int len;
  ATbool fail = ATtrue;

  assert(PT_hasTreeArgs(trm));

  args = PT_getTreeArgs(trm);
  len = PT_getArgsLength(args);
 
  if (len > 32) {
    while (PT_hasArgsHead(args)) {
      arg = PT_getArgsHead(args);
      newarg = rewriteRecursive(arg, env, depth /* + 1 */, extra);
      if (newarg == FAIL) {
	newarg = arg;
      } 
      else {
	fail = ATfalse;
      }
      newargs = PT_appendArgs(newargs, newarg);
      args = PT_getArgsTail(args);
    }
  }
  else {
    PT_Tree newarg_table[32];
    int i = 0;
    while (PT_hasArgsHead(args)) {
      arg = PT_getArgsHead(args);
      newarg_table[i] = rewriteRecursive(arg, env, depth /* + 1 */, extra);
      if (newarg_table[i] == FAIL) {
	newarg_table[i] = arg;
      }
      else {
	fail = ATfalse;
      }
      args = PT_getArgsTail(args);
      ++i;
    }
    assert(i == len);
    for (--i; i >= 0; i--) {
      newargs = PT_makeArgsList(newarg_table[i], newargs);
    }
  }

  if (fail) {
    reduct = FAIL;
  }
  else {
    reduct = PT_setTreeArgs(trm, newargs);
  }

  return reduct;
}

/*}}}  */
/*{{{  static PT_Args rewriteElems(listProd, elems, env, depth, traversal) */

static PT_Args
rewriteElems(PT_Production listProd, PT_Args elems, ATerm env, int depth, 
             void *extra)
{
  PT_Tree elem;
  PT_Args newelems = PT_makeArgsEmpty();

  pedantic_assert(isValidList(elems));

  while (PT_hasArgsHead(elems)) {
    elem = PT_getArgsHead(elems);

    if (PT_isTreeApplList(elem)) {
      PT_Args elemArgs = PT_getTreeArgs(elem);
      newelems = concatElems(listProd, newelems, elemArgs);

      pedantic_assert(isValidList(newelems));
    }
    else {
      newelems = appendElem(listProd, newelems, elem);
    }

    if(PT_isTreeVar(elem)) { /* uninitalized variable */
      return elems;
    }
    
    elems = PT_getArgsTail(elems);
  }

  newelems = skipWhitespaceAndSeparator(newelems,listProd);
  pedantic_assert(isValidList(newelems));

  return newelems;
}


/*}}}  */

/*{{{  static PT_Tree rewriteAPIAppl(PT_Tree tree) */

static PT_Tree rewriteAPIAppl(PT_Tree tree, ATerm env, int depth, void*extra)
{
  PT_Tree apiresult = FAIL, result = FAIL;

  apiresult = interpretAPICall(tree);

  if (apiresult == FAIL) {
    apiresult = tree; 
  }
  
  result = rewriteNormalAppl(apiresult, env, depth, extra);

  if (result == FAIL && apiresult != FAIL) {
    result = apiresult;
  }

  return result;
}

/*}}}  */
/*{{{  static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth,void *extra)  */

static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth,void *extra) 
{
  PT_Tree value = getVariableValue(env, var);

  assert(value != NULL && "uninitialized variable");

  return value;
}

/*}}}  */
/*{{{  static PT_Tree rewriteListAppl(PT_Tree list, ATerm env, int depth, void *extra) */

static PT_Tree rewriteListAppl(PT_Tree list, ATerm env, int depth, void *extra)
{
  PT_Args elems;
  PT_Args newelems;
  PT_Production prod = PT_getTreeProd(list);
  PT_Tree reduct = FAIL;

  elems = PT_getTreeArgs(list);
  newelems = rewriteElems(prod, elems, env, depth, extra);

  if (!newelems) {
    return FAIL;
  }

  pedantic_assert(isValidList(newelems));
  reduct = reduce(PT_setTreeArgs(list, newelems), depth);

  if (PT_isEqualTree(reduct,list)) {
    reduct = FAIL;
  }

  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteNormalAppl(PT_Tree appl, ATerm env, int depth,  */

static PT_Tree rewriteNormalAppl(PT_Tree appl, ATerm env, int depth, 
				 void *extra)
{
  PT_Production prod = PT_getTreeProd(appl);
  PT_Tree reduct;
  ATbool isMemoFunction = ATfalse;

  /* retrieve possible memoized reduct */
  if (PT_hasProductionMemoAttr(prod)) {
    PT_Tree memo = MemoTableLookup(memo_table, appl);
    isMemoFunction = ATtrue;
 
    if (memo != NULL) {
      return memo;
    }
  }

  reduct = reduce(appl, depth);

  if (PT_isEqualTree(appl, reduct)) {
    reduct = FAIL;
  }

  if (isMemoFunction) {
    memo_table = MemoTableAdd(memo_table, appl, reduct);
  }

  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteTraversalAppl(PT_Tree trm, ATerm env, int depth,  */

static PT_Tree rewriteTraversalAppl(PT_Tree trm, ATerm env, int depth, 
				    void *extra)
{
  PT_Tree reduct = FAIL;
  Traversal traversal;
ATsetChecking(ATtrue);
  assert(extra == NULL && "Nested traversal should have been reduced.");

  traversal = createTraversalPattern(trm);

  if (traversal.type == UNDEFINED_TYPE) {
    ATerror("unknown traversal type %d\n", traversal.type);
    return reduct;
  }

  if (runVerbose) {
    ATwarning("Traversing...\n");
  }

  trm = selectTraversedArg(PT_getTreeArgs(trm));

  reduct = rewriteTraversal(trm, env, depth, &traversal);
  /* a traversal function never fails */ 
  reduct = chooseNormalform(reduct == FAIL ? trm : reduct, traversal);

  return reduct; 
}

/*}}}  */
/*{{{  static PT_Tree rewriteBracketAppl(PT_Tree trm, ATerm env, int depth,  */

static PT_Tree rewriteBracketAppl(PT_Tree trm, ATerm env, int depth, 
				  void* extra)
{
  PT_Args args = PT_getTreeArgs(trm);

  /* just remove the brackets */
  return PT_getArgsHead(skipWhitespace(PT_getArgsTail(args)));
}

/*}}}  */
