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

  if (ASF_isValidASFEquation((ASF_ASFEquation) eqOrCond)) { 
    lhs = (PT_Tree) ASF_getASFEquationLhs((ASF_ASFEquation) eqOrCond);
  }
  else if (ASF_isValidASFCondition((ASF_ASFCondition) eqOrCond)) { 
    lhs = (PT_Tree) ASF_getASFConditionLhs((ASF_ASFCondition) eqOrCond);
  }
  else {
    return DEPTH_UNDEFINED;
  }

  return countTreeInjections(lhs);
}

/*}}}  */

/*{{{  static ASF_ASFEquation filterASFEquationOrCondition(PT_Tree eqOrCond) */

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

static ASF_ASFConditions filterConditions(ASF_ASFConditions conds)
{
  ASF_ASFConditionList condlist;
  int count;
  ASF_ASFCondition* buffer = NULL;
  ASF_ASFConditionList new;
  int i;

  CHECK_AMB(conds);
  
  condlist = ASF_getASFConditionsList(conds);
  count = ASF_getConditionListLength(condlist);

  buffer = (ASF_ASFCondition*) calloc(count, sizeof(ASF_ASFCondition));

  if (buffer == NULL) {
    ATerror("filterConditions: not enough memory\n");
    return NULL;
  }

  ATprotectArray((ATerm*) buffer, count);

  for(i = 0;ASF_hasASFConditionListHead(condlist);
      condlist = ASF_getASFConditionListTail(condlist)) {
    ASF_ASFCondition cond = ASF_getASFConditionListHead(condlist);
    buffer[i++] = (ASF_ASFCondition) filterEquationOrCondition((PT_Tree) cond); 

    if (!ASF_hasASFConditionListTail(condlist)) {
      break;
    }
  }

  new = NULL;

  while (--i >= 0) {
    if (new == NULL) {
      new = ASF_makeASFConditionListSingle(buffer[i]);
      assert(new);
    }
    else {
      new = ASF_makeASFConditionListMany(buffer[i],space,",",space,new);
    }
  }

  ATunprotectArray((ATerm*) buffer);
  free(buffer);
  buffer = NULL;

  return ASF_makeASFConditionsDefault(new);
}

/*}}}  */
/*{{{  static ASF_CondEquation filterCondEquation(ASF_CondEquation condeq) */

static ASF_ASFConditionalEquation filterCondEquation(ASF_ASFConditionalEquation condeq)
{
  ASF_ASFEquation eq;

  CHECK_AMB(condeq);

  eq = ASF_getASFConditionalEquationASFEquation(condeq);
  assert(eq);

  eq = (ASF_ASFEquation) filterEquationOrCondition((PT_Tree) eq);
  condeq = ASF_setASFConditionalEquationASFEquation(condeq, eq);

  if (ASF_hasASFConditionalEquationASFConditions(condeq)) {
    ASF_ASFConditions conds = ASF_getASFConditionalEquationASFConditions(condeq);
    conds = filterConditions(conds);
    condeq = ASF_setASFConditionalEquationASFConditions(condeq, conds);
  }

  return condeq; 
}

/*}}}  */
/*{{{  static CondEquationsList filterCondEquationList(ASF_CondEquationList ... */

static ASF_ASFConditionalEquationList 
filterCondEquationList(ASF_ASFConditionalEquationList condeqslist)
{
  int count;
  ASF_ASFConditionalEquation* buffer = NULL;
  ASF_ASFConditionalEquationList new;
  int i;

  CHECK_AMB(condeqslist);
  
  count = ASF_getASFConditionalEquationListLength(condeqslist);

  if (ASF_isASFConditionalEquationListEmpty(condeqslist)) {
    return condeqslist;
  }

  buffer = (ASF_ASFConditionalEquation*) calloc(count, sizeof(ASF_ASFConditionalEquation));

  if (buffer == NULL) {
    ATerror("filterCondEquationList: not enough memory\n");
    return NULL;
  }

  ATprotectArray((ATerm*) buffer, count);

  for(i = 0;ASF_hasASFConditionalEquationListHead(condeqslist);
      condeqslist = ASF_getASFConditionalEquationListTail(condeqslist)) {
    ASF_ASFConditionalEquation condeq = ASF_getASFConditionalEquationListHead(condeqslist);
    buffer[i++] = filterCondEquation(condeq); 

    if (!ASF_hasASFConditionalEquationListTail(condeqslist)) {
      break;
    }
  }

  new = NULL;

  while (--i >= 0) {
    if (new == NULL) {
      new = ASF_makeASFConditionalEquationListSingle(buffer[i]);
      assert(new);
    }
    else {
      new = ASF_makeASFConditionalEquationListMany(buffer[i],space,new);
    }
  }

  ATunprotectArray((ATerm*) buffer);
  free(buffer);
  buffer = NULL;

  return new;
}

/*}}}  */
/*{{{  static ASF_Equations filterEquations(ASF_Equations equations) */

static ASF_ASFEquations filterEquations(ASF_ASFEquations equations)
{
  CHECK_AMB(equations);

  if (ASF_isASFEquationsPresent(equations)) {
    ASF_ASFConditionalEquationList condeqslist = ASF_getASFEquationsList(equations);

    condeqslist = filterCondEquationList(condeqslist);

    return ASF_setASFEquationsList(equations, condeqslist);
  }
  else {
    return equations;
  }
}

/*}}}  */

/*{{{  ASF_Equations filterEquationSyntax(ASF_Equations equations) */

ASF_ASFEquations filterEquationSyntax(ASF_ASFEquations equations)
{
  /* initialize some globals */
  space = ASF_makeOptLayoutPresent(ASF_makeCHARLISTString(" "));
  ATprotect((ATerm*) &space);

  if (ASF_isValidASFEquations(equations)) {
    equations = filterEquations(equations);
  }

  ATunprotect((ATerm*) &space);

  return equations;
}

/*}}}  */
