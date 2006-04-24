#include <assert.h>

#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <asc-builtins.h>
#include <asc-ambiguity.h>

#include "reduction.h"
#include "memotable.h"
#include "equations.h"
#include "environment.h"
#include "evaluator.h"
#include "matching.h"
#include "traversalfunctions.h"
#include "errors.h"
#include "debug.h"
#include "builtins.h"
#include <string.h>

#define FAIL NULL
#define TERM_PREFIX_LENGTH 50

/*{{{  local function declarations */

static ATerm try(PT_Tree trm, equation_entry *entry, int depth);
static PT_Tree reduce(PT_Tree trm, int depth);
static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Tree rewriteArgs(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Tree rewriteAmb(PT_Tree trm, ATerm env, int depth, void *extra);
static PT_Args rewriteElems(PT_Production listProd, PT_Args elems, ATerm env, 
			    int depth, void *extra);
static PT_Tree rewriteVariableAppl(PT_Tree var, ATerm env, int depth, 
				   void *extra);
static PT_Tree rewriteListAppl(PT_Tree list, ATerm env, int depth, 
			       void *extra);
static PT_Tree rewriteNormalAppl(PT_Tree appl, ATerm env, int depth, 
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
static PT_Tree rewriteBuiltinAppl(ATerm builtin, PT_Tree trm, ATerm env, 
				  int depth, void* extra);
/*}}}  */

/* Printing a term for verbose messages */
/*{{{  static char* term_prefix(PT_Tree trm) */

static char* term_prefix(PT_Tree trm)
{
  static const char abbreviated[] = " ... (etc.)";
  char *tmp;

  tmp = PT_yieldTreeToString(trm, ATfalse);

  if (strlen(tmp) > TERM_PREFIX_LENGTH - strlen(abbreviated)) {
    sprintf(tmp+TERM_PREFIX_LENGTH-strlen(abbreviated),abbreviated);
  }

  return tmp;
}

/*}}}  */

/* Reduction functionality */
/*{{{  static ATerm try(PT_Tree trm, equation_entry *entry, int depth) */

static ATerm try(PT_Tree trm, equation_entry *entry, int depth)
{
  ATerm env = fail_env;
  ASF_ASFTag savedTag = tagCurrentRule;

  tagCurrentRule = entry->tag;
  currentRule = entry;

  print_short_equation(depth, "try", entry);

  env = matchEquation(entry, trm, depth);

  tagCurrentRule = entry->tag;
  currentRule = entry;

  if (!is_fail_env(env)) {
    print_short_equation(depth, "success", entry);

    TIDE_STEP(entry->rhs, env, depth);

    asfe_rewrite_steps++;
  }
  else {
    print_short_equation(depth, "fail", entry);
  }

  tagCurrentRule = savedTag;

  return env;
}

/*}}}  */
/*{{{  static ATbool hasProductionCompleteAttribute(PT_Production prod) */

static ATbool hasProductionCompleteAttribute(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrTerm(ATparse("complete")));;
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

  if (hasProductionCompleteAttribute(top_ofs)) {
    RWaddError("complete function not reduced:", PT_yieldProduction(top_ofs));
    return FAIL;
  }
  return trm;
}

/*}}}  */

/* Rewriting strategies  */

/*{{{  static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra) */

static PT_Tree rewriteTop(PT_Tree trm, ATerm env, int depth, void *extra)
{
  PT_Tree reduct = FAIL;
  ATerm builtin = NULL;

  if (runVerbose) {
    ATwarning("rewriting: %s\n", term_prefix(trm));
  }


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
  else if ((builtin = getTreeBuiltin(trm)) != NULL) {
    reduct = rewriteBuiltinAppl(builtin, trm, env, depth, extra);
  }
  else if (PT_isTreeLit(trm)) {
    reduct = trm;
  }
  else if (PT_isTreeAppl(trm)) {
    reduct = rewriteNormalAppl(trm, env, depth, extra);
  }
  else if (PT_isTreeAmb(trm)) {
    reduct = rewriteAmb(trm, env, depth, extra);
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
  PT_Production prod;
  PT_Tree arg, newarg, reduct = FAIL;
  PT_Args newargs = PT_makeArgsEmpty();
  int len;
  ATbool fail = ATtrue;

  assert(PT_hasTreeArgs(trm));

  prod = PT_getTreeProd(trm);
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
      newargs = PT_makeArgsMany(newarg_table[i], newargs);
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

/*{{{  static PT_Tree rewriteAmb(PT_Tree amb, ATerm env, int depth, void* extra) */

static PT_Tree rewriteAmb(PT_Tree amb, ATerm env, int depth, void* extra)
{
  PT_Tree trm = NULL;
  PT_Tree reduct = FAIL;
  PT_Tree memo = MemoTableLookup(memo_table, amb);

  /* Memoization is needed here to prevent exponential 
   * behavior in case of nested ambiguity.
   */ 
  if (memo == (PT_Tree) ATempty) {
    return FAIL;
  }
  else if (memo != NULL) {
    return memo;
  }

  if (runVerbose) {
    ATwarning("Lifting ambiguity to constructor\n");
  }

  trm = ASC_ambToConstructor(amb);

  assert(trm != NULL);

  if (runVerbose) {
    ATwarning("Rewriting ambiguity\n");
  }

  reduct = rewriteNormalAppl(trm, env, depth, extra);

  if (runVerbose) {
    ATwarning("Done rewriting ambiguity\n");
  }


  memo_table = MemoTableAdd(memo_table, amb, reduct ? reduct : (PT_Tree) ATempty);



  return reduct;
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

  /* retrieve possible memoized reduct, ambiguity constructors are
   * memoized by default to try and prevent exponential behavior
   * in the context of nested ambiguity. See also rewriteAmb, which
   * also has to memoize its output.
  */
  if (PT_hasProductionMemoAttr(prod) ||
      PT_hasProductionCertainAttr(prod, 
				  PT_makeAttrTerm(ATparse("cons(\"ambiguity-constructor\")")))) {
    PT_Tree memo = MemoTableLookup(memo_table, appl);
    isMemoFunction = ATtrue;

    if (memo == (PT_Tree) ATempty) {
      return FAIL;
    }
    else if (memo != NULL) {
      return memo;
    }
  }

  reduct = reduce(appl, depth);

  if (PT_isEqualTree(appl, reduct)) {
    reduct = FAIL;
  }

  if (isMemoFunction) {
    memo_table = MemoTableAdd(memo_table, appl, reduct ? reduct : (PT_Tree) ATempty);
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
/*{{{  static PT_Tree rewriteBuiltinAppl(PT_Tree trm, ATerm env, int depth,  */

static PT_Tree rewriteBuiltinAppl(ATerm builtin, PT_Tree trm, ATerm env, 
				  int depth, void* extra)
{
  return rewriteInnermost(forwardBuiltin(builtin, trm), env, depth+1, 
			  NO_TRAVERSAL);
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

      if (travtrm != NULL) {
	reduct = rewriteTop(travtrm, env, depth, traversal);
      }
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
    RWaddError(tmp, PT_yieldTreeToString((PT_Tree) tagCurrentRule, ATfalse));
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
  PT_Tree save = trm;

  if (depth == 0) {
    PT_Tree memo = MemoTableLookup(memo_table, trm);
    if (memo != NULL) {
      return memo;
    }
  }

  ASF_ASFTag tag = tagCurrentRule;

  if (PT_isTreeVar(trm) || PT_isTreeVarList(trm)) {
    /* Note that depth is not the depth of the tree, but the depth
     * of the ASF call stack.
     */
    reduct = rewriteVariableAppl(trm, env, depth, extra);
    tagCurrentRule = innermostTag;
    TIDE_STEP(save, putVariableValue(env, innermostSubject, reduct), depth);
    tagCurrentRule = tag;
  }
  else if (PT_hasTreeArgs(trm)) {
    /* first the kids */    
    reduct = rewriteArgs(trm, env, depth, extra);

    if (reduct != FAIL) {
      trm = reduct;
    }

    if (trm) {
      /* Then the parent */

      tagCurrentRule = innermostTag;
      TIDE_STEP(save, putVariableValue(env, innermostSubject, trm), depth);
      tagCurrentRule = tag;

      reduct = rewriteTop(trm, env, depth, extra);

      if (reduct == FAIL) {
	reduct = trm;
	if (depth == 0) {
	  /* we cache rewriting of constants on level 0 */
	  memo_table = MemoTableAdd(memo_table, trm, reduct);
	}
      }
    }
  }

  if (reduct != FAIL && ASC_isAmbiguityConstructor(reduct)) {
    if (runVerbose) {
      ATwarning("Lowering ambiguity to constructor\n");
    }
    reduct = ASC_constructorToAmb(reduct);

    if (PT_isArgsEmpty(PT_getTreeArgs(reduct))) {
      LOC_Location loc = PT_getTreeLocation(reduct);

      if (loc == NULL) {
	RWaddError("Rewriting failed: empty ambiguity cluster returned", "");
      }
      else {
	RWaddLocatedError("Rewriting failed: empty ambiguity cluster returned", "pattern", loc);
      }
      reduct = FAIL;
    }
  }
 
  return reduct;
}

/*}}}  */
