#include <assert.h>

#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <asf-builtins.h>

#include "reduction.h"
#include "memotable.h"
#include "equations.h"
#include "environment.h"
#include "evaluator.h"
#include "matching.h"
#include "traversalfunctions.h"
#include "errors.h"
#include "asf-api.h"
#include "debug.h"

/*
#ifdef USE_TIDE
#include "debug.h"
#endif
*/


#define FAIL NULL

/*{{{  local function declarations */

static ATerm try(PT_Tree trm, equation_entry *entry, int depth);
static PT_Tree reduce(PT_Tree trm, int depth);
static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Tree rewriteArgs(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Args rewriteElems(PT_Production listProd, PT_Args elems, ATerm env, 
			    int depth, void *extra);
static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth, 
				   void *extra);
static PT_Tree rewriteListAppl(PT_Tree list, ATerm env, int depth, 
			       void *extra);
static PT_Tree rewriteNormalAppl(PT_Tree appl, ATerm env, int depth, 
				 void *extra);
static PT_Tree rewriteAPIAppl(PT_Tree tree, ATerm env, int depth, 
			      void *extra);
static PT_Tree rewriteTraversalAppl(PT_Tree trm, ATerm env, int depth, 
				    void *extra);
static PT_Tree rewriteBracketAppl(PT_Tree trm, ATerm env, int depth, 
				  void *extra);
static PT_Tree rewriteTraversal(PT_Tree trm, ATerm env, int depth, 
				Traversal *traversal);
static PT_Tree rewriteTraversalBottomUp(PT_Tree trm, ATerm env, int depth, 
					Traversal *traversal);
static PT_Tree rewriteTraversalTopDown(PT_Tree trm, ATerm env, int depth, 
				       Traversal *traversal);
static PT_Tree rewriteRecursive(PT_Tree trm, ATerm env, int depth, void* extra);
/*}}}  */


/* Reduction functionality */
/*{{{  static ATerm try(PT_Tree trm, equation_entry *entry, int depth) */

static ATerm try(PT_Tree trm, equation_entry *entry, int depth)
{
  ATerm env = fail_env;


  tagCurrentRule = entry->tag;
  currentRule = entry;

  print_short_equation("try", entry);

  env = matchEquation(entry, trm, depth);

  tagCurrentRule = entry->tag;
  currentRule = entry;

  if (!is_fail_env(env)) {
    print_short_equation("success", entry);

    TIDE_STEP(entry->rhs, env, depth);
    rewrite_steps++;
  }
  else {
    print_short_equation("fail", entry);
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

  if (!PT_hasTreeProd(trm)) {
    return trm;
  }

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

  while (PT_hasArgsHead(elems)) {
    elem = PT_getArgsHead(elems);

    if (PT_isTreeApplList(elem)) {
      PT_Args elemArgs = PT_getTreeArgs(elem);
      newelems = concatElems(listProd, newelems, elemArgs);
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

  return newelems;
}


/*}}}  */

/*{{{  static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth,void *extra)  */

static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth,void *extra) 
{
  PT_Tree value = getVariableValue(env, var);

  if (value == NULL) {
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
  PT_Tree reduct = FAIL;

  elems = PT_getTreeArgs(list);
  newelems = rewriteElems(prod, elems, env, depth, extra);

  if (!newelems) {
    return FAIL;
  }

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
/*{{{  static PT_Tree rewriteAPIAppl(PT_Tree tree) */

static PT_Tree rewriteAPIAppl(PT_Tree tree, ATerm env, int depth, void*extra)
{
  PT_Tree apiresult = FAIL, result = FAIL;

  apiresult = interpretAPICall(tree);

  if (apiresult == FAIL) {
    apiresult = tree; 
  }
  
  result = rewriteInnermost(apiresult, env, depth, extra);

  if (result == FAIL && apiresult != FAIL) {
    result = apiresult;
  }

  return result;
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

/*{{{  PT_Tree rewrite(PT_Tree trm) */

PT_Tree rewrite(PT_Tree trm)
{
  PT_Tree reduct;
 
  reduct = rewriteRecursive(trm,(ATerm) ATempty, 0, NO_TRAVERSAL);

  return reduct;
}

/*}}}  */
/*{{{  static PT_Tree rewriteRecursive(PT_Tree trm, ATerm env, int depth, void* extra) */

static PT_Tree rewriteRecursive(PT_Tree trm, ATerm env, int depth, void* extra)
{
  PT_Tree reduct;
  equation_entry *entry = currentRule;

  if (depth > MAX_DEPTH) {
    char tmp[256];
    sprintf(tmp, "maximum stack depth (%d) exceeded.", MAX_DEPTH);
    RWsetError(tmp, (ATerm) ATempty);
    reduct = trm;
  }

  if (aborted) {
    return trm;
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
/*{{{  PT_Tree rewriteInnermost(PT_Tree trm, ATerm env, int depth, void *extra) */

PT_Tree rewriteInnermost(PT_Tree trm, ATerm env, int depth, void *extra)
{
  PT_Tree reduct = FAIL;

  if (PT_isTreeLayout(trm)) {
    reduct = trm;
  }
  else if (PT_isTreeVar(trm) || PT_isTreeVarList(trm)) {
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
