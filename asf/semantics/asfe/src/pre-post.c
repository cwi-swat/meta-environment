#include <assert.h>
#include <ASFME-utils.h>
#include <MEPT-utils.h>
#include <aterm2.h>

#include "pre-post.h"
#include "values.h"
#include "evaluator.h"
#include "asf-api.h"
#include "errors.h"

/* New layout is marked by a layout tree that exists, but is empty.
 * This can never be the result of parsing, but it is still valid AsFix.
 */
#define DIRTY_LAYOUT_MARKER "layout-place-holder"

static ATbool mark_new_layout;
static ATbool in_equations;

static PT_Tree prepareTerm(PT_Tree tree, PT_TreeVisitorData data);
static PT_Tree restoreTerm(PT_Tree tree, PT_TreeVisitorData data);


/*{{{  ASF_Condition prepare_cond(ASF_Condition cond) */

ASF_Condition prepare_cond(ASF_Condition cond)
{
  PT_Tree lhs, rhs;
  
  lhs = ASFtoPT(ASF_getConditionLhs(cond));
  cond = ASF_setConditionLhs(cond, PTtoASF(RWprepareTerm(lhs, ATfalse)));
    
  rhs = ASFtoPT(ASF_getConditionRhs(cond));
  cond = ASF_setConditionRhs(cond, PTtoASF(RWprepareTerm(rhs, ATfalse)));

  return cond;
}

/*}}}  */
/*{{{  ASF_Conditions prepareConditions(ASF_Conditions conds) */

ASF_Conditions prepareConditions(ASF_Conditions conds)
{
  ASF_ConditionList  condList = ASF_getConditionsList(conds);
  
  condList = ASF_visitConditionList(condList, prepare_cond, NULL, NULL, NULL);

  return ASF_setConditionsList(conds, condList);
}

/*}}}  */
/*{{{  ASF_CondEquation prepareEquation(ASF_CondEquation equ) */

/*
Prepare an equation for rewriting. This includes removing the layout,
and translating lexicals into lists.
*/

ASF_CondEquation prepareEquation(ASF_CondEquation equ)
{
  ASF_Equation equation;


  if (ASF_isCondEquationWhen(equ) || ASF_isCondEquationImplies(equ)) {
    equ = ASF_setCondEquationConditions(equ,
            prepareConditions(ASF_getCondEquationConditions(equ)));
  }

  equation = ASF_getCondEquationEquation(equ);

  equation = ASF_setEquationLhs(equation, 
          PTtoASF(RWprepareTerm(ASFtoPT(ASF_getEquationLhs(equation)),
				ATfalse)));

  equation = ASF_setEquationRhs(equation,
          PTtoASF(RWprepareTerm(ASFtoPT(ASF_getEquationRhs(equation)),
				ATfalse)));

  return ASF_setCondEquationEquation(equ, equation); 
}

/*}}}  */
/*{{{  static PT_Tree ambToAmbConstructor(PT_Tree tree) */

static PT_Tree ambToAmbConstructor(PT_Tree tree, PT_TreeVisitorData data)
{
  PT_Args ambs;
  PT_Args listargs = PT_makeArgsEmpty();
  PT_Symbol symbol;
  PT_Tree first;
  PT_Tree l = PT_makeTreeLayoutEmpty();
  PT_Tree s = PT_makeTreeLit(",");

  assert(PT_isTreeAmb(tree));
  ambs = PT_getTreeArgs(tree);

  assert(PT_hasArgsHead(ambs));

  first = PT_getArgsHead(ambs);

  symbol = PT_getProductionRhs(PT_getTreeProd(first)); 

  if (PT_isSymbolCf(symbol) || PT_isSymbolLex(symbol)) {
    symbol = PT_getSymbolSymbol(symbol);
  }

  ambs = PT_foreachTreeInArgs(ambs, prepareTerm, data);

  for (; PT_hasArgsHead(ambs); ambs = PT_getArgsTail(ambs)) {
    PT_Tree amb = PT_getArgsHead(ambs);
    listargs = PT_makeArgsList(amb, listargs);

    if (PT_hasArgsHead(PT_getArgsTail(ambs))) {
      listargs = PT_makeArgsList(l,listargs);
      listargs = PT_makeArgsList(s,listargs);
      listargs = PT_makeArgsList(l,listargs);
    }
  }

  return (PT_Tree) 
    ASF_makeTreeAmbConstructor((ASF_Symbol) symbol,
			       (ASF_Symbol) symbol,
			       (ASF_Layout) l,
			       (ASF_Layout) l,
			       (ASF_Symbol) symbol,
			       (ASF_TreeAmbs) listargs,
			       (ASF_Layout) l);
}

/*}}}  */
/*{{{  static PT_Tree APICallToNormalCall(PT_Tree tree) */

static PT_Tree APICallToNormalCall(PT_Tree tree, PT_TreeVisitorData data)
{
  AA_Calls calls = getTreeAPICalls(tree);
  AA_Call call = AA_getCallsHead(calls);
  PT_Tree result;

  if (AA_isCallConstructor(call)) {
    result = interpretConstructorCall(tree, calls);
    return prepareTerm(result, data); 
  }

  /* other API calls are interpreted at run-time */
  return tree;
}

/*}}}  */
/*{{{  static PT_Tree prepareTerm(PT_Tree tree, PT_TreeVisitorData data) */

static PT_Tree prepareTerm(PT_Tree tree, PT_TreeVisitorData data)
{
  PT_Tree result;
  PT_Args args, newargs;
  ATerm annos = AT_getAnnotations(PT_makeTermFromTree(tree));

  if (ASF_isTreeLexicalConstructorFunction((ASF_Tree) tree)) { 
    result = (PT_Tree) 
               ASF_LexicalConstructorTreeToLexicalTree((ASF_Tree) tree);
  }
  else if (isTreeAPIFunction(tree)) {
    result = APICallToNormalCall(tree, data);
  } 
  else if (PT_isTreeBracket(tree)) {
    result = prepareTerm(PT_getTreeBracketTree(tree), data);
  }
  else if (mark_new_layout && in_equations && PT_isTreeLayout(tree)) {
    result = tree;
    /* add a special annotation */
    annos = (ATerm) ATinsert((ATermList) (annos ? annos : (ATerm) ATempty),
		     ATparse("["DIRTY_LAYOUT_MARKER","DIRTY_LAYOUT_MARKER"]"));
  }
  else if (PT_isTreeAppl(tree)) {
    args = PT_getTreeArgs(tree);
    newargs = PT_foreachTreeInArgs(args, prepareTerm, data);
    result = PT_setTreeArgs(tree, newargs);
  }
  else if (PT_isTreeAmb(tree)) {
    if (*((ATbool*) data) == ATtrue) {
      result = ambToAmbConstructor(tree,data);
    }
    else {
      RWsetError("Illegal ambiguity", (ATerm) PT_makeTreeLit(""));
      result = tree;
    }
  }
  else {
    result = tree;
  }

  if (annos != NULL) {
    result = PT_makeTreeFromTerm(
               AT_setAnnotations(PT_makeTermFromTree(result), annos));
  }

  return result;
}

/*}}}  */

/*{{{  PT_Tree RWprepareTerm(PT_Tree tree) */

PT_Tree RWprepareTerm(PT_Tree tree, ATbool allow_ambs)
{
  return  prepareTerm(tree, &allow_ambs);
}

/*}}}  */
/*{{{  ASF_CondEquationList RWprepareEquations(ASF_CondEquationList eqsList) */
/*
Prepare a list of equations for rewriting.
*/


ASF_CondEquationList RWprepareEquations(ASF_CondEquationList eqsList, 
					ATbool mark_layout)
{
  ASF_CondEquationList new;
  mark_new_layout = mark_layout;
  in_equations = ATtrue;
  new = ASF_visitCondEquationList(eqsList, prepareEquation, NULL);
  in_equations = ATfalse;
  return new;
}

/*}}}  */
/*{{{  static PT_Tree ambConstructorToAmb(PT_Tree tree, PT_TreeVisitorData data) */

static PT_Tree ambConstructorToAmb(PT_Tree tree, PT_TreeVisitorData data)
{
  ASF_Tree asfTree = PTtoASF(tree);
  PT_Args args = (PT_Args) ASF_getTreeAmbs(asfTree);
  PT_Args ambs;

  ambs = PT_makeArgsEmpty();

  if (ATisEmpty(args)) {
    RWsetError("Empty ambiguity cluster encountered", (ATerm) PT_makeTreeLit(""));
    return tree;
  }

  while (PT_hasArgsHead(args)) {
    PT_Tree arg;
    PT_Tree amb;

    arg = PT_getArgsHead(args);
    args = PT_getArgsTail(args);
    amb = restoreTerm(arg, data);
    ambs = PT_makeArgsList(amb,ambs);

    
    if (!PT_isArgsEmpty(args)) {
      args = PT_getArgsTail(args); 
      args = PT_getArgsTail(args); 
      args = PT_getArgsTail(args); 
    }
  }

  return PT_makeTreeAmb(ambs);
}

/*}}}  */

/*{{{  static PT_Tree restoreTerm(PT_Tree tree, PT_TreeVisitorData data) */

static PT_Tree restoreTerm(PT_Tree tree, PT_TreeVisitorData data)
{
  PT_Args args;

  if (PT_isTreeAppl(tree)) {
    if (ASF_isTreeAmbConstructorFunction(PTtoASF(tree))) {
      return ambConstructorToAmb(tree, data);
    }
    else if ( *((ATbool*) data) == ATtrue && PT_isTreeLayout(tree)) {
      return PT_makeTreeLayoutFromString(" ");
    }

    args = PT_getTreeArgs(tree);
    args = PT_foreachTreeInArgs(args, restoreTerm, data);
    return PT_setTreeArgs(tree, args);
  }

  return tree;
}


/*}}}  */
/*{{{  PT_Tree RWrestoreTerm(PT_Tree tree) */

PT_Tree RWrestoreTerm(PT_Tree tree, ATbool remove_layout)
{
  return restoreTerm(tree, &remove_layout);
}

/*}}}  */
/*{{{  PT_Args RWrestoreArgs(PT_Args args) */

PT_Args RWrestoreArgs(PT_Args args, ATbool remove_layout)
{
  return PT_foreachTreeInArgs(args, restoreTerm, &remove_layout);
}

/*}}}  */
