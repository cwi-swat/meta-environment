/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <MEPT-utils.h>
#include <ASFME-utils.h>

#include "filtereqssyntax.h"

/*}}}  */

/*{{{  globals */

static ASF_OptLayout space;

#define DEPTH_UNDEFINED -1
#define CHECK_AMB(tree)  if (PT_isTreeAmb((PT_Tree) (tree))) return (tree)

/*}}}  */

/*{{{  static int countTreeInjections(PT_Tree tree) */

static int countTreeInjections(PT_Tree tree)
{
  PT_Production prod;

  if(PT_isTreeAppl(tree)) {
    prod = PT_getTreeProd(tree);

    if (PT_isProductionInjection(prod)) {
      return 1 + countTreeInjections(PT_getArgsHead(PT_getTreeArgs(tree)));
    }
  } 

  return 0;
}

/*}}}  */
/*{{{  static int getInjectionDepth(PT_Tree eqOrCond) */

static int getInjectionDepth(PT_Tree eqOrCond)
{
  PT_Tree lhs;

  if (ASF_isValidEquation((ASF_Equation) eqOrCond)) { 
    lhs = (PT_Tree) ASF_getEquationLhs((ASF_Equation) eqOrCond);
  }
  else if (ASF_isValidCondition((ASF_Condition) eqOrCond)) { 
    lhs = (PT_Tree) ASF_getConditionLhs((ASF_Condition) eqOrCond);
  }
  else {
    return DEPTH_UNDEFINED;
  }

  return countTreeInjections(lhs);
}

/*}}}  */

/*{{{  static ASF_Equation filterEquationOrCondition(PT_Tree eqOrCond) */

static PT_Tree filterEquationOrCondition(PT_Tree eqOrCond)
{
  if (PT_isTreeAmb(eqOrCond)) {
    PT_Args ambs = PT_getTreeArgs(eqOrCond);
    int count = PT_getArgsLength(ambs);
    PT_Tree *buffer = NULL;
    int     *depth = NULL;
    int i,j;

    buffer = (PT_Tree*) calloc(count, sizeof(PT_Tree));
    depth = (int*) calloc(count, sizeof(int));

    if (buffer == NULL || depth == NULL) {
      ATerror("filterEquation: not enough memory\n");
      return NULL;
    }
  
    ATprotectArray((ATerm*) buffer, count);

    for(i = 0; PT_hasArgsHead(ambs); ambs = PT_getArgsTail(ambs), i++) {
      buffer[i] = PT_getArgsHead(ambs);
      depth[i] = getInjectionDepth(buffer[i]);
    }

    /* Compare the depth of each tree to the depth of the others.
     * Trees with bigger depths are replaced by NULL.
     */

    for (i = 0; i < count; i++) {
      if (depth[i] != DEPTH_UNDEFINED) {
	for (j = i + 1; j < count; j++) {
	  if (buffer[j] != NULL && depth[j] != DEPTH_UNDEFINED) {
	    if (depth[i] > depth[j]) {
	      buffer[i] = NULL;
	      break;
	    } 
	    else if (depth[i] < depth[j]) {
	      buffer[j] = NULL;
	    }
	  }
	}
      }
    }

    ambs = PT_makeArgsEmpty();

    /* remaining trees back in the cluster */
    for(i = 0; i < count; i++) {
      if (buffer[i] != NULL) {
	ambs = PT_makeArgsList((PT_Tree) buffer[i], ambs);
      }
    }

    assert(!PT_isArgsEmpty(ambs));

    if (PT_getArgsLength(ambs) == 1) { /* ambiguity resolved */
      eqOrCond = PT_getArgsHead(ambs);
    }
    else {
      eqOrCond = PT_makeTreeAmb(ambs);
    }
    
    ATunprotectArray((ATerm*) buffer);
    free(buffer);
    buffer = NULL;
    free(depth);
    depth = NULL;
  }
  
  return eqOrCond;
}

/*}}}  */
/*{{{  static ASF_Conditions filterConditions(ASF_Conditions conds) */

static ASF_Conditions filterConditions(ASF_Conditions conds)
{
  ASF_ConditionList condlist;
  int count;
  ASF_Condition* buffer = NULL;
  ASF_ConditionList new;
  int i;

  CHECK_AMB(conds);
  
  condlist = ASF_getConditionsList(conds);
  count = ASF_getConditionListLength(condlist);

  buffer = (ASF_Condition*) calloc(count, sizeof(ASF_Condition));

  if (buffer == NULL) {
    ATerror("filterConditions: not enough memory\n");
    return NULL;
  }

  ATprotectArray((ATerm*) buffer, count);

  for(i = 0;ASF_hasConditionListHead(condlist);
      condlist = ASF_getConditionListTail(condlist)) {
    ASF_Condition cond = ASF_getConditionListHead(condlist);
    buffer[i++] = (ASF_Condition) filterEquationOrCondition((PT_Tree) cond); 

    if (!ASF_hasConditionListTail(condlist)) {
      break;
    }
  }

  new = NULL;

  while (--i >= 0) {
    if (new == NULL) {
      new = ASF_makeConditionListSingle(buffer[i]);
      assert(new);
    }
    else {
      new = ASF_makeConditionListMany(buffer[i],space,",",space,new);
    }
  }

  ATunprotectArray((ATerm*) buffer);
  free(buffer);
  buffer = NULL;

  return ASF_makeConditionsDefault(new);
}

/*}}}  */
/*{{{  static ASF_CondEquation filterCondEquation(ASF_CondEquation condeq) */

static ASF_CondEquation filterCondEquation(ASF_CondEquation condeq)
{
  ASF_Equation eq;

  CHECK_AMB(condeq);

  eq = ASF_getCondEquationEquation(condeq);
  assert(eq);

  eq = (ASF_Equation) filterEquationOrCondition((PT_Tree) eq);
  condeq = ASF_setCondEquationEquation(condeq, eq);

  if (ASF_hasCondEquationConditions(condeq)) {
    ASF_Conditions conds = ASF_getCondEquationConditions(condeq);
    conds = filterConditions(conds);
    condeq = ASF_setCondEquationConditions(condeq, conds);
  }

  return condeq; 
}

/*}}}  */
/*{{{  static CondEquationsList filterCondEquationList(ASF_CondEquationList ... */

static ASF_CondEquationList 
filterCondEquationList(ASF_CondEquationList condeqslist)
{
  int count;
  ASF_CondEquation* buffer = NULL;
  ASF_CondEquationList new;
  int i;

  CHECK_AMB(condeqslist);
  
  count = ASF_getCondEquationListLength(condeqslist);

  if (ASF_isCondEquationListEmpty(condeqslist)) {
    return condeqslist;
  }

  buffer = (ASF_CondEquation*) calloc(count, sizeof(ASF_CondEquation));

  if (buffer == NULL) {
    ATerror("filterCondEquationList: not enough memory\n");
    return NULL;
  }

  ATprotectArray((ATerm*) buffer, count);

  for(i = 0;ASF_hasCondEquationListHead(condeqslist);
      condeqslist = ASF_getCondEquationListTail(condeqslist)) {
    ASF_CondEquation condeq = ASF_getCondEquationListHead(condeqslist);
    buffer[i++] = filterCondEquation(condeq); 

    if (!ASF_hasCondEquationListTail(condeqslist)) {
      break;
    }
  }

  new = NULL;

  while (--i >= 0) {
    if (new == NULL) {
      new = ASF_makeCondEquationListSingle(buffer[i]);
      assert(new);
    }
    else {
      new = ASF_makeCondEquationListMany(buffer[i],space,new);
    }
  }

  ATunprotectArray((ATerm*) buffer);
  free(buffer);
  buffer = NULL;

  return new;
}

/*}}}  */
/*{{{  static ASF_Equations filterEquations(ASF_Equations equations) */

static ASF_Equations filterEquations(ASF_Equations equations)
{
  CHECK_AMB(equations);

  if (ASF_isEquationsPresent(equations)) {
    ASF_CondEquationList condeqslist = ASF_getEquationsList(equations);

    condeqslist = filterCondEquationList(condeqslist);

    return ASF_setEquationsList(equations, condeqslist);
  }
  else {
    return equations;
  }
}

/*}}}  */

/*{{{  ASF_Equations filterEquationSyntax(ASF_Equations equations) */

ASF_Equations filterEquationSyntax(ASF_Equations equations)
{
  /* initialize some globals */
  space = ASF_makeOptLayoutPresent(ASF_makeCHARLISTString(" "));
  ATprotect((ATerm*) &space);

  if (ASF_isValidEquations(equations)) {
    equations = filterEquations(equations);
  }

  ATunprotect((ATerm*) &space);

  return equations;
}

/*}}}  */
