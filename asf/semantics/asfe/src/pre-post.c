#include <assert.h>
#include <ASFME-utils.h>
#include <MEPT-utils.h>
#include <aterm2.h>

#include "pre-post.h"
#include "values.h"
#include "evaluator.h"
#include "errors.h"

/* New layout is marked by a layout tree that exists, but is empty.
 * This can never be the result of parsing, but it is still valid AsFix.
 */
#define DIRTY_LAYOUT_MARKER "layout-place-holder"

static ATbool mark_new_layout;
static ATbool in_equations;

static PT_Tree prepareTerm(PT_Tree tree, PT_TreeVisitorData data);
static PT_Tree restoreTerm(PT_Tree tree, PT_TreeVisitorData data);


/*{{{  ASF_ASFCondition prepare_cond(ASF_ASFCondition cond) */

ASF_ASFCondition prepareCondition(ASF_ASFCondition cond)
{
  PT_Tree lhs, rhs;
  
  lhs = ASFtoPT(ASF_getASFConditionLhs(cond));
  cond = ASF_setASFConditionLhs(cond, PTtoASF(RWprepareTerm(lhs, ATfalse)));

  rhs = ASFtoPT(ASF_getASFConditionRhs(cond));
  cond = ASF_setASFConditionRhs(cond, PTtoASF(RWprepareTerm(rhs, ATfalse)));

  return cond;
}

/*}}}  */
/*{{{  ASF_ASFConditions prepareConditions(ASF_ASFConditions conds) */

ASF_ASFConditions prepareConditions(ASF_ASFConditions conds)
{
  ASF_ASFConditionList  condList = ASF_getASFConditionsList(conds);
  
  condList = ASF_visitASFConditionList(condList, prepareCondition, NULL, NULL, NULL);

  return ASF_setASFConditionsList(conds, condList);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation prepareEquation(ASF_ASFConditionalEquation equ) */

/*
Prepare an equation for rewriting. This includes removing the layout,
and translating lexicals into lists.
*/

ASF_ASFConditionalEquation prepareEquation(ASF_ASFConditionalEquation equ)
{
  ASF_ASFEquation equation;


  if (ASF_isASFConditionalEquationWhen(equ) || ASF_isASFConditionalEquationImplies(equ)) {
    equ = ASF_setASFConditionalEquationASFConditions(equ,
            prepareConditions(ASF_getASFConditionalEquationASFConditions(equ)));
  }

  equation = ASF_getASFConditionalEquationASFEquation(equ);

  equation = ASF_setASFEquationLhs(equation, 
          PTtoASF(RWprepareTerm(ASFtoPT(ASF_getASFEquationLhs(equation)),
				ATfalse)));

  equation = ASF_setASFEquationRhs(equation,
          PTtoASF(RWprepareTerm(ASFtoPT(ASF_getASFEquationRhs(equation)),
				ATfalse)));

  return ASF_setASFConditionalEquationASFEquation(equ, equation); 
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
    ASF_makeTreeAmbiguityConstructor((ASF_Symbol) symbol,
			             (ASF_Symbol) symbol,
			             (ASF_OptLayout) l,
			             (ASF_OptLayout) l,
			             (ASF_Symbol) symbol,
			             (ASF_TreeAmbs) listargs,
			             (ASF_OptLayout) l);
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
      RWaddError("Illegal ambiguity", PT_yieldTree(tree));
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
/*{{{  ASF_ASFConditionalEquationList RWprepareEquations(ASF_ASFConditionalEquationList eqsList) */
/*
Prepare a list of equations for rewriting.
*/


ASF_ASFConditionalEquationList RWprepareEquations(ASF_ASFConditionalEquationList eqsList, 
					ATbool mark_layout)
{
  ASF_ASFConditionalEquationList new;
  mark_new_layout = mark_layout;
  in_equations = ATtrue;
  new = ASF_visitASFConditionalEquationList(eqsList, prepareEquation, NULL);
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
    RWaddError("Empty ambiguity cluster encountered", "");
    return tree;
  }

  while (PT_hasArgsHead(args)) {
    PT_Tree arg;
    PT_Tree amb;
    int len;

    arg = PT_getArgsHead(args);
    args = PT_getArgsTail(args);
    amb = restoreTerm(arg, data);
    ambs = PT_makeArgsList(amb,ambs);

   
    len = PT_getArgsLength(args);
    assert((len == 0 || len > 3) && "ill formed amb cluster");

    if (len > 3) {
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
