/*{{{  includes */

#include "evaluator.h"
#include "reduction.h"
#include "errors.h"
#include "traversalfunctions.h"
#include "environment.h"
#include "matching.h"
#include <asc-builtins.h>
#include <ASFME-utils.h>
#include <MEPT-utils.h>
#include <Error.h>
#include "equations.h"
#include "values.h"
#include "debug.h"

/*}}}  */

/*{{{  defines */

#define BUFFER_SIZE 10240

/*}}}  */

static PT_Tree leftSubject;
static PT_Tree rightSubject;


/*{{{  static ERR_Subject makeSubject(PT_Tree trm) */

static ERR_Subject makeSubject(PT_Tree trm, LOC_Location loc)
{
  if (loc != NULL) {
    return ERR_makeSubjectLocalized(term_prefix(trm), (ERR_Location) loc);
  }
  else {
    return ERR_makeSubjectSubject(term_prefix(trm));
  }
}

/*}}}  */

/*{{{  static ATbool testOne(ASF_ASFTestEquation test) */

static ERR_Error testOne(ASF_ASFTestEquation test)
{
  ASF_ASFTag tag = ASF_getASFTestEquationASFTag(test);
  ASF_ASFCondition tobetested = ASF_getASFTestEquationASFCondition(test);
  ATerm environment = (ATerm) ATempty;
  PT_Tree lhs = (PT_Tree) ASF_getASFConditionLhs(tobetested);
  PT_Tree rhs = (PT_Tree) ASF_getASFConditionRhs(tobetested);
  PT_Tree lhsResult;
  PT_Tree rhsResult;
  LOC_Location lhsLocation = NULL;
  LOC_Location rhsLocation = NULL;
  ATbool equal = ATfalse;

  if (PT_hasTreeLocation(lhs)) {
    lhsLocation = PT_getTreeLocation(lhs);
  }
  if (PT_hasTreeLocation(rhs)) {
    rhsLocation = PT_getTreeLocation(rhs);
  }

  tagCurrentRule = testRunnerTag;
  TIDE_STEP(tobetested, environment, 0);

  tagCurrentRule = tag;
  if (ASF_hasASFTestEquationASFConditions(test)) {
    ASF_ASFConditions conditions;
    ASF_ASFConditionList condList;

    conditions = ASF_getASFTestEquationASFConditions(test);
    
    condList = ASF_getASFConditionsList(conditions);
    environment = matchConditions(condList, environment, 1);

    if (is_fail_env(environment)) {
      ERR_Subject lhsSubject = makeSubject(lhs, lhsLocation); 

      return ERR_makeErrorError("condition of test failed", 
				ERR_makeSubjectListSingle(lhsSubject));
    }
  }



   lhsResult = rewriteInnermost(lhs, environment, 1, NO_TRAVERSAL);
   rhsResult = rewriteInnermost(rhs, environment, 1, NO_TRAVERSAL); 


 

  if (!no_new_vars(lhsResult, environment)) {
    RWaddError("Left side of test introduces a variable", 
	       PT_yieldTreeToString((PT_Tree) tag, ATfalse));
    return NULL;
  }
  if (!no_new_vars(rhsResult, environment)) {
    RWaddError("Right side of test introduces a variable", 
	       PT_yieldTreeToString((PT_Tree) tag, ATfalse));
    return NULL;
  }

  equal = isAsFixEqual(lhsResult, rhsResult);

  environment = putVariableValue(environment, leftSubject, lhsResult);
  environment = putVariableValue(environment, rightSubject, rhsResult);

  tagCurrentRule = testRunnerTag;
  TIDE_STEP(tobetested, environment, 0);

  if (ASF_isASFConditionNegative(tobetested)) {
    equal = !equal;
  }

  if (equal) {
    return NULL;
  }
  else {
    /* this subject is the subject of the error message, not
     * the currently rewritten term
     */
    ERR_Subject lhsSubject = makeSubject(lhsResult, lhsLocation);
    ERR_Subject rhsSubject = makeSubject(rhsResult, rhsLocation); 

    return ERR_makeErrorError("test failed", ERR_makeSubjectListMany(lhsSubject,
								     ERR_makeSubjectListSingle(rhsSubject)));
  }
}

/*}}}  */
/*{{{  static ERR_ErrorList testAll(ASF_ASFTestEquationTestList tests,  */

static ERR_ErrorList testAll(ASF_ASFTestEquationTestList tests, 
			     ERR_ErrorList failed)
{
  while (!ASF_isASFTestEquationTestListEmpty(tests)) {
    ASF_ASFTestEquation test = ASF_getASFTestEquationTestListHead(tests);
    ERR_Error result = testOne(test);

    if (result != NULL) {
      failed = ERR_makeErrorListMany(result, failed);
    }

    if (!ASF_hasASFTestEquationTestListTail(tests)) {
      break;
    }
    tests = ASF_getASFTestEquationTestListTail(tests);
  }

  return failed;
}

/*}}}  */
/*{{{  ATermList runTests(ASF_ASFConditionalEquationList eqs, */

ATerm runTests(ASF_ASFConditionalEquationList eqs,
	       ASF_ASFTestEquationTestList tests, ATbool debug)
{
   ASF_OptLayout e = ASF_makeOptLayoutAbsent();
   ERR_ErrorList failed = ERR_makeErrorListEmpty();

   if (runVerbose) {
     ATwarning("initializing...\n");
   }

   ASF_protectASFTag(&tagCurrentRule);
   PT_protectTree(&innermostSubject);
   PT_protectTree(&leftSubject);
   PT_protectTree(&rightSubject);
   ASF_protectASFTag(&innermostTag);
   ASF_protectASFTag(&testRunnerTag);

   useTide = debug;

   enter_equations(eqs);

   if (memo_table == NULL) {
     memo_table = MemoTableCreate();
   }

   tagCurrentRule = ASF_makeASFTagNotEmpty(e,
				   ASF_makeTagId("*undefined*"),e);
   innermostTag = ASF_makeASFTagNotEmpty(e,
				 ASF_makeTagId("*innermost*"),e);
   testRunnerTag = ASF_makeASFTagNotEmpty(e,
				  ASF_makeTagId("*test-runner*"),e);
   innermostSubject = PT_makeTreeLit("*subject*");
   leftSubject = PT_makeTreeLit("*lhs*");
   rightSubject = PT_makeTreeLit("*rhs*");
   asfe_rewrite_steps = 0;
   initBuiltins();

   if (runVerbose) {
     ATwarning("running tests...\n");
   }

   failed = testAll(tests, failed);

   return ATmake("test-results(<term>)", failed);
}

/*}}}  */
