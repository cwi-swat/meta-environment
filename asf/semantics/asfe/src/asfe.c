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
static ATermList apply_rule(PT_Tree trm, int depth, equation_entry **equ);
static PT_Tree selectAndRewrite(PT_Tree trm, int depth);
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

PT_Tree getVariableValue(ATerm env, PT_Tree var, PT_Symbol symbol)
{
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
/*      assert(ATgetAFun(tuple) == plain_var);*/
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

/* Matching functionality (and condition checking) */
/*{{{  static ATerm argMatching(env, arg1, arg2, conds, org1, org2, posinfo, depth) */

/* Function which tries to match two arguments.
   First it is checked whether one of the arguments is a variable
   and the other is not. If one is a variable it is checked
   whether it is a fresh one. If the variable is in the environment
   its value is retrieved and compared with the other argument.
   If they are equal the matching can proceed otherwise the matching
   must be aborted.  If the variable is a fresh one it is
   stored in the variable environment
   with the term of the other argument.

   If both arguments are ``appls'' their arguments should match.

   If both arguments are ``lists'' their elements shoudl match.

   Otherwise the arguments should be equal. If the do not
   match the matching should be aborted. */

static ATerm
argMatching(ATerm env, 
            PT_Tree arg1, PT_Tree arg2,
	    ASF_ConditionList conds,
	    PT_Args orgargs1, PT_Args orgargs2,
            ATerm lhs_posinfo, int depth)
{
  PT_Production prod1, prod2;
  PT_Args args1, args2;
  PT_Args elems1, elems2;
  ATerm newenv = env;

  if (runVerbose) {
    ATwarning("%t:matching: %t\nwith\n%t\n\n",
	      yieldTree((PT_Tree) tagCurrentRule), yieldTree(arg1), 
              yieldTree(arg2));
  }

  if (PT_isTreeAppl(arg1)) {
    pedantic_assert(PT_isTreeAppl(arg2));
    prod1 = PT_getTreeProd(arg1);

    if (PT_isOptLayoutProd(prod1)) {
      pedantic_assert(PT_isOptLayoutProd(PT_getTreeProd(arg2)));
      return argsMatching(newenv, conds, orgargs1, orgargs2,
			  lhs_posinfo, depth);
    }

    if (PT_isProductionList(prod1)) {
      pedantic_assert(PT_isProductionList(PT_getTreeProd(arg2)));

      elems1 = PT_getTreeArgs(arg1);
      elems2 = PT_getTreeArgs(arg2);

      return listMatching(newenv, prod1, elems1, elems2,
			  conds, orgargs1, orgargs2, 
			  lhs_posinfo, depth);
    }

    prod2 = PT_getTreeProd(arg2);
    if (PT_isEqualProduction(prod1, prod2)) {
      args1 = PT_getTreeArgs(arg1);
      args2 = PT_getTreeArgs(arg2);

      return (ATerm) argsMatching(newenv, conds, 
                                  PT_concatArgs(args1, orgargs1),
                                  PT_concatArgs(args2, orgargs2),
                                  lhs_posinfo, depth);
    }

    if (PT_isVarDefault(prod1)) {
      PT_Symbol rhs = PT_getProductionRhs(prod1);
      PT_Tree trm = getVariableValue(newenv, arg1, rhs);
      if (trm) {
	if (isAsFixEqual(arg2, trm)) {
	  return argsMatching(newenv, conds, orgargs1, orgargs2,
			      lhs_posinfo, depth);
	}
	else {
	  if (runVerbose) {
	    ATwarning("*** fail_env on line %d\n", __LINE__);
	  }
	  return fail_env;
	}
      }
      else {
	newenv = putVariableValue(newenv, arg1, arg2);
	return argsMatching(newenv, conds, orgargs1, orgargs2,
			    lhs_posinfo, depth);
      }
    }

    if (runVerbose) {
      ATwarning("*** fail_env on line %d\n", __LINE__);
    }
    return fail_env;
  }

  if (PT_isEqualTree(PT_removeTreeAnnotations(arg1),
		     PT_removeTreeAnnotations(arg2))) {
    return argsMatching(newenv, conds, orgargs1, orgargs2, lhs_posinfo, depth);
  }

  if (runVerbose) {
    ATwarning("*** fail_env on line %d\n", __LINE__);
  }
  return fail_env;
}


/*}}}  */
/*{{{  static ATerm argsMatching(env, conds, args1, args2, lhs_posinfo, depth) */

/* Two arguments lists are matched. As long as there are arguments
   to be matched this is performed if both argument lists are empty
   the conditions are inspected. 
*/
static ATerm
argsMatching(ATerm env, ASF_ConditionList conds,
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

  if (PT_hasArgsHead(args1)) {
    arg1 = PT_getArgsHead(args1);
    args1 = PT_getArgsTail(args1);

    if (PT_hasArgsHead(args2)) {
      arg2 = PT_getArgsHead(args2);
      args2 = PT_getArgsTail(args2);

      newenv = argMatching(newenv, arg1, arg2, conds, 
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
  else {
    if (PT_hasArgsHead(args2)) {
      newenv = fail_env;
      if (runVerbose) {
	ATwarning("*** fail_env on line %d\n", __LINE__);
      }
    }
    else {
      if (lhs_posinfo) {
	TIDE_STEP(lhs_posinfo, newenv, depth);
      }
      newenv = condsSatisfied(conds, newenv, depth);
    }
  }

  return newenv;
}


static ATbool
compareLists(Slice tuple, PT_Args list)
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
      
	newenv = argMatching(env, elem1, elem2, NULL,
			     PT_makeArgsEmpty(), PT_makeArgsEmpty(),
			     NULL, depth);
	if (newenv == fail_env) {
	  return fail_env;
	}

	return listMatching(newenv, listProd, elems1, elems2, conds,
			    args1, args2, lhs_posinfo, depth);

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
	newenv = argMatching(env, elem1, elem2, NULL,
			     PT_makeArgsEmpty(), PT_makeArgsEmpty(),
			     NULL, depth);
	if (newenv == fail_env) {
	  return fail_env;
	}

	return listMatching(newenv, listProd, elems1, elems2, conds,
			    args1, args2, lhs_posinfo, depth);
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
/*{{{  static ATerm condsSatisfied(ASF_ConditionList conds, ATerm env, int depth) */

/* Function ``condSatisfied'' check whether the conditions
   of an equation can be satisfied. 
   Remark access functions needed to retrieve the operator,
   lhs, and rhs. */

static ATerm condsSatisfied(ASF_ConditionList conds, ATerm env, int depth)
{
  ASF_Condition cond;
  PT_Tree lhs, rhs, lhstrm, rhstrm;
  ATerm newenv = env;


  if (conds == NULL) {
    return env;
  }

  if (ASF_hasConditionListHead(conds)) {
    cond = ASF_getConditionListHead(conds);
//ATwarning("cond: %t\nenv:%t\n", cond,env);
    if (ASF_hasConditionListTail(conds)) {
      conds = ASF_getConditionListTail(conds);
    }
    else {
      conds = NULL;
    }

    lhs = ASFtoPT(ASF_getConditionLhs(cond));
    rhs = ASFtoPT(ASF_getConditionRhs(cond));

    if (ASF_isConditionPositive(cond)) {
      if (no_new_vars(lhs, newenv)) {
	TIDE_STEP(PT_getTreeAnnotation(lhs, posinfo), newenv, depth);
	lhstrm = rewriteInnermost(lhs, newenv, depth + 1, NO_TRAVERSAL);
	if (!lhstrm) {
	  return fail_env;
	}

	TIDE_STEP(PT_getTreeAnnotation(rhs, posinfo), newenv, depth);
	if (no_new_vars(rhs, newenv)) {
	  rhstrm = rewriteInnermost(rhs, newenv, depth + 1 , NO_TRAVERSAL);
	  if (!rhstrm) {
	    return fail_env;
	  }

	  TIDE_STEP(ATgetAnnotation(ASF_makeTermFromCondition(cond), posinfo),
		    newenv, depth);
	  if (isAsFixEqual(lhstrm, rhstrm)) {
	    newenv = condsSatisfied(conds, newenv, depth);
	  }
	  else {
	    newenv = fail_env;
	    if (runVerbose) {
	      ATwarning("*** fail_env on line %d\n", __LINE__);
	    }
	  }
	}
	else {
	  TIDE_STEP(ATgetAnnotation(ASF_makeTermFromCondition(cond), posinfo),
		    newenv, depth);
	  newenv =
	    argMatching(newenv, rhs, lhstrm, conds,
			PT_makeArgsEmpty(), PT_makeArgsEmpty(), 
                        NULL, depth);
	}
      }
      else {
	TIDE_STEP(PT_getTreeAnnotation(lhs, posinfo), newenv, depth);
	TIDE_STEP(PT_getTreeAnnotation(rhs, posinfo), newenv, depth);
	if (no_new_vars(rhs, newenv)) {
	  rhstrm = rewriteInnermost(rhs, newenv, depth + 1 , NO_TRAVERSAL);
	  if (!rhstrm) {
	    return fail_env;
	  }

	  TIDE_STEP(ATgetAnnotation(ASF_makeTermFromCondition(cond), posinfo),
		    newenv, depth);
	  newenv =
	    argMatching(newenv, lhs, rhstrm, conds,
			PT_makeArgsEmpty(), PT_makeArgsEmpty(), 
                        NULL, depth);
	}
	else {
	  RWsetError
	    ("Both sides of condition introduce new variables.",
	     (ATerm) cond);
	  newenv = fail_env;
	  if (runVerbose) {
	    ATwarning("*** fail_env on line %d\n", __LINE__);
	  }
	}
      }
    }
    else {
      if (!no_new_vars(lhs, newenv) || !no_new_vars(rhs, newenv)) {
	RWsetError("Negative condition introduces new variables.",
		   (ATerm) cond);
	newenv = fail_env;
	if (runVerbose) {
	  ATwarning("*** fail_env on line %d\n", __LINE__);
	}
      }
      else {
	TIDE_STEP(PT_getTreeAnnotation(lhs, posinfo), newenv, depth);
	lhstrm = rewriteInnermost(lhs, newenv, depth + 1 , NO_TRAVERSAL);
	if (!lhstrm) {
	  return fail_env;
	}

	TIDE_STEP(PT_getTreeAnnotation(rhs, posinfo), newenv, depth);
	rhstrm = rewriteInnermost(rhs, newenv, depth + 1, NO_TRAVERSAL);
	if (!rhstrm) {
	  return fail_env;
	}

	TIDE_STEP(ATgetAnnotation(ASF_makeTermFromCondition(cond), posinfo),
		  newenv, depth);
	if (isAsFixEqual(lhstrm, rhstrm)) {
	  newenv = fail_env;
	  if (runVerbose) {
	    ATwarning("*** fail_env on line %d\n", __LINE__);
	  }
	}
	else {
	  newenv = condsSatisfied(conds, newenv, depth);
	}
      }
    }
  }

  return newenv;
}

/*}}}  */

/* Reduction functionality */
/*{{{  static ATermList apply_rule(PT_Tree trm, int depth) */

/* The function ``apply_rule'' tries to rewrite a term
   given a list of equations. As long as there is no
   success a new equation is tried. The arguments of
   the term and the arguments of the left hand side of
   the equation are matched.
*/

static ATermList apply_rule(PT_Tree trm, int depth, equation_entry **equation)
{
  PT_Production top_ofs, first_ofs;
  PT_Args termargs, equargs, tmpargs;
  ATerm env;
  ASF_ConditionList conds;
  equation_entry *entry = NULL;

  top_ofs = PT_getTreeProd(trm);
  termargs = PT_getTreeArgs(trm);

  tmpargs = termargs;
  while (PT_hasArgsHead(tmpargs) &&
	 (PT_isTreeLit(PT_getArgsHead(tmpargs)) ||
	  PT_isTreeLayout(PT_getArgsHead(tmpargs)))) {
    tmpargs = PT_getArgsTail(tmpargs);
  }

  if (PT_hasArgsHead(tmpargs)) {
    PT_Tree firstArg = PT_getArgsHead(tmpargs);
    if (PT_isTreeAppl(firstArg)) {
      first_ofs = PT_getTreeProd(PT_getArgsHead(tmpargs));

      while ((entry = find_equation(entry, top_ofs, first_ofs))) {
        if (runVerbose) {
	  ATwarning("Trying equation: %s\n", PT_yieldTree((PT_Tree)entry->tag));
        }

        tagCurrentRule = entry->tag;
	currentRule = entry;

        conds = entry->conds;
        equargs = PT_getTreeArgs(entry->lhs);
        if (PT_isProductionList(top_ofs)) {
          env = listMatching((ATerm) ATempty, top_ofs, equargs, termargs,
                             conds, PT_makeArgsEmpty(),  PT_makeArgsEmpty(), 
                             PT_getTreeAnnotation(entry->lhs, posinfo), 
			     depth); 
        }
        else {
          env = argsMatching((ATerm) ATempty, conds, equargs, termargs,
	   		     PT_getTreeAnnotation(entry->lhs, posinfo), 
			     depth);
        }

        tagCurrentRule = entry->tag;
	currentRule = entry;

        if (!is_fail_env(env)) {
	  TIDE_STEP(PT_getTreeAnnotation(entry->rhs, posinfo), env, depth);
	  if (runVerbose) {
	    ATwarning("Equation %s was successful.\n", 
                      PT_yieldTree((PT_Tree)entry->tag));
	  }

	  rewrite_steps++;
	  *equation = entry;
	  return make_cenv(entry->rhs, env);
        }
        else if (runVerbose) {
	  ATwarning("Equation %s failed.\n", PT_yieldTree((PT_Tree)entry->tag));
        }
      }
    }
  }

  while ((entry = find_equation(entry, top_ofs, (PT_Production) NULL))) {
    if (runVerbose) {
      ATwarning("Trying equation: %s.\n", PT_yieldTree((PT_Tree) entry->tag));
    }

    tagCurrentRule = entry->tag;
    currentRule = entry;

    conds = entry->conds;
    equargs = PT_getTreeArgs(entry->lhs);

    if (PT_isProductionList(top_ofs)) {
      env = listMatching((ATerm) ATempty, top_ofs, equargs, termargs,
			 conds, PT_makeArgsEmpty(),  PT_makeArgsEmpty(), 
			 PT_getTreeAnnotation(entry->lhs, posinfo), depth); 
    }
    else {
      env = argsMatching((ATerm) ATempty, conds, equargs, termargs,
			 PT_getTreeAnnotation(entry->lhs, posinfo), depth);
    }

    tagCurrentRule = entry->tag;
    currentRule = entry;

    if (!is_fail_env(env)) {
      TIDE_STEP(PT_getTreeAnnotation(entry->rhs, posinfo), env, depth);
      if (runVerbose) {
	ATwarning("Equation: %s was successful.\n", 
                  PT_yieldTree((PT_Tree)entry->tag));
      }

      rewrite_steps++;
      *equation = entry;
      return make_cenv(entry->rhs, env);
    }
    else if (runVerbose) {
      ATwarning("Equation %s failed.\n", PT_yieldTree((PT_Tree)entry->tag));
    }
  }

  *equation = NULL;
  return make_cenv(trm, fail_env);
}

/*}}}  */
/*{{{  static PT_Tree selectAndRewrite(PT_Tree trm, int depth) */

/* The function ``select_and_rewrite'' selects the
   the set of rewrite rules from the active rules and
   tries to rewrite the term via the function ``apply_rule''.
*/

static PT_Tree selectAndRewrite(PT_Tree trm, int depth)
{
  PT_Tree newtrm;
  ATermList complexenv;
  ATerm env;
  equation_entry *equation;
  ASF_Tag savedTag = tagCurrentRule;

  complexenv = apply_rule(trm, depth, &equation);
  env = get_env(complexenv);

  if (!is_fail_env(env)) {
    newtrm = get_term(complexenv);

    /* construct the right hand side */
    trm = rewriteRecursive(newtrm, env, depth + 1, NULL);

    assert(equation);
    tagCurrentRule = equation->tag;
    TIDE_STEP(equation->posinfo_equals, env, depth);
  }

  tagCurrentRule = savedTag;
  return trm;
}

/*}}}  */

/* Rewriting strategies  */
/*{{{  static PT_Tree rewrite(PT_Tree trm) */

static PT_Tree rewrite(PT_Tree trm)
{
  return rewriteRecursive(trm,(ATerm) ATempty, 0, NO_TRAVERSAL);
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
  PT_Tree reduct = trm;

  if (PT_isTreeVar(trm) || PT_isTreeVarList(trm)) {
    reduct = rewriteVariableAppl(trm, env, depth, extra);
  }
  else if (PT_hasTreeArgs(trm)) {
    /* first the kids */    
    trm = rewriteArgs(trm, env, depth, extra);

    if (trm) {
      /* Then the parent */
      reduct = rewriteTop(trm, env, depth, extra);
    }
  }

  return reduct;
}

/*}}}  */

/*{{{  static PT_Tree rewriteTraversal(PT_Tree trm, ATerm env, int depth, */

static PT_Tree rewriteTraversal(PT_Tree trm, ATerm env, int depth,
				Traversal* traversal)
{
  PT_Tree reduct = trm;

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

  assert(reduct);
  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteTraversalBottomUp(PT_Tree trm, ATerm env, int depth, */

static PT_Tree rewriteTraversalBottomUp(PT_Tree trm, ATerm env, int depth,
					Traversal* traversal)
{
  PT_Tree reduct = trm;

  if (PT_hasTreeArgs(trm)) {
    PT_Tree travtrm;
    trm = rewriteArgs(trm, env, depth, traversal);

    travtrm = makeTraversalAppl(trm, *traversal);

    reduct = rewriteTop(travtrm, env, depth, traversal);

    if (PT_isEqualTree(reduct, travtrm)) {
      reduct = trm;
    }
    else {
      reduct = makeTraversalReduct(trm, reduct, traversal);
    }
  }

  assert(reduct);
  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteTraversalTopDown(PT_Tree trm, ATerm env, int depth,  */

static PT_Tree rewriteTraversalTopDown(PT_Tree trm, ATerm env, int depth, 
				       Traversal* traversal)
{
  PT_Tree reduct = trm;

  if (PT_hasTreeArgs(trm)) {
    PT_Tree travtrm = makeTraversalAppl(trm, *traversal);

    reduct = rewriteTop(travtrm, env, depth, traversal);

    if (PT_isEqualTree(reduct, travtrm)) {
      trm = rewriteArgs(trm, env, depth, traversal);
      reduct = rewriteTop(trm, env, depth, traversal);
    }
    else { 
      reduct = makeTraversalReduct(trm, reduct, traversal);
    }
  }

  assert(reduct);
  return reduct;
}

/*}}}  */

/*{{{  static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra) */

static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra)
{
  PT_Tree reduct = trm;

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

  assert(reduct);
  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteArgs(PT_Tree trm, ATerm env, int depth, void* extra) */

static PT_Tree rewriteArgs(PT_Tree trm, ATerm env, int depth, void* extra)
{
  PT_Args args;
  PT_Tree arg, newarg;
  PT_Args newargs = PT_makeArgsEmpty();
  int len;

  assert(PT_hasTreeArgs(trm));

  args = PT_getTreeArgs(trm);
  len = PT_getArgsLength(args);
 
  if (len > 32) {
    while (PT_hasArgsHead(args)) {
      arg = PT_getArgsHead(args);
      newarg = rewriteRecursive(arg, env, depth /* + 1 */, extra);
      if (!newarg) {
	return NULL;
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
      if (!newarg_table[i]) {
	return NULL;
      }

      args = PT_getArgsTail(args);
      ++i;
    }
    assert(i == len);
    for (--i; i >= 0; i--) {
      newargs = PT_makeArgsList(newarg_table[i], newargs);
    }
  }

  return PT_setTreeArgs(trm, newargs);
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
  PT_Tree result = interpretAPICall(tree);

  return rewriteNormalAppl(result, env, depth, extra);
}

/*}}}  */
/*{{{  static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth,void *extra)  */

static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth,void *extra) 
{
  PT_Production prod = PT_getTreeProd(var);
  PT_Symbol rhs = PT_getProductionRhs(prod);
  PT_Tree value = getVariableValue(env, var, rhs);

  if (!value) {
    RWsetError("Uninitialized variable.",(ATerm) var);
    return var;
  }

  return value;
}

/*}}}  */
/*{{{  static PT_Tree rewriteListAppl(PT_Tree list, ATerm env, int depth, void *extra) */

static PT_Tree rewriteListAppl(PT_Tree list, ATerm env, int depth, void *extra)
{
  PT_Args elems;
  PT_Args newelems;
  PT_Production prod = PT_getTreeProd(list);
  
  elems = PT_getTreeArgs(list);
  newelems = rewriteElems(prod, elems, env, depth, extra);

  if (!newelems) {
    return list;
  }

  pedantic_assert(isValidList(newelems));
  return selectAndRewrite(PT_setTreeArgs(list, newelems), depth);
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

  reduct = selectAndRewrite(appl, depth);

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
  PT_Tree reduct;
  Traversal traversal;

  assert(extra == NULL && "Nested traversal should have been reduced.");

  traversal = createTraversalPattern(trm);

  if (traversal.type == UNDEFINED_TYPE) {
    return trm;
  }

  if (runVerbose) {
    ATwarning("Traversing...\n");
  }

  trm = selectTraversedArg(PT_getTreeArgs(trm));

  reduct = rewriteTraversal(trm, env, depth, &traversal);
  reduct = chooseNormalform(reduct, traversal);

  assert(reduct);
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
