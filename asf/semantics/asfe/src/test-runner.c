#include "evaluator.h"
#include "reduction.h"
#include "errors.h"
#include "pre-post.h"
#include "traversalfunctions.h"
#include "environment.h"
#include "matching.h"
#include <asc-builtins.h>
#include <ASFME-utils.h>
#include <MEPT-utils.h>
#include "equations.h"
#include "values.h"

/*{{{  static ATerm prettyTag(ASF_ASFTag tag) */

static ATerm prettyTag(ASF_ASFTag tag)
{
  if (!ASF_isASFTagEmpty(tag)) {
    ASF_ASFTagId id = ASF_getASFTagASFTagId(tag);
    AFun fun = ATmakeAFun(PT_yieldTree((PT_Tree) ASF_ASFTagIdToTerm(id)),
			  0, ATfalse);
    return (ATerm) ATmakeAppl0(fun);
  }
  else {
    return ATparse("unnamed-test");
  }
}

/*}}}  */

/*{{{  static ASF_ASFTag testOne(ASF_TestEquation test) */

static ASF_ASFTag testOne(ASF_ASFTestEquation test)
{
  ASF_ASFTag tag = ASF_getASFTestEquationASFTag(test);
  ASF_ASFCondition tobetested = ASF_getASFTestEquationASFCondition(test);
  ATerm environment = (ATerm) ATempty;
  PT_Tree lhs;
  PT_Tree rhs;
  ATbool equal = ATfalse;

  tobetested = prepareCondition(tobetested);

  if (ASF_hasASFTestEquationASFConditions(test)) {
    ASF_ASFConditions conditions;
    ASF_ASFConditionList condList;

    conditions = ASF_getASFTestEquationASFConditions(test);
    conditions = prepareConditions(conditions);
    
    condList = ASF_getASFConditionsList(conditions);
    environment = matchConditions(condList, environment, 0);

    if (is_fail_env(environment)) {
      return tag;
    }
  }

  lhs = rewriteInnermost((PT_Tree) ASF_getASFConditionLhs(tobetested),
			 environment, 0, NO_TRAVERSAL);
  rhs = rewriteInnermost((PT_Tree) ASF_getASFConditionRhs(tobetested),
			 environment, 0, NO_TRAVERSAL);
		
  equal = isAsFixEqual(lhs, rhs);

  if (ASF_isASFConditionNegative(tobetested)) {
    equal = !equal;
  }

  if (equal) {
    return NULL;
  }
  else {
    return tag;
  }
}

/*}}}  */
/*{{{  static ATermList testAll(ASF_ASFTestEquationTestList tests) */

static ATermList testAll(ASF_ASFTestEquationTestList tests)
{
  ATermList failed = ATempty;

  for (; !ASF_isASFTestEquationTestListEmpty(tests);
       tests = ASF_getASFTestEquationTestListTail(tests)) {
    ASF_ASFTestEquation test = ASF_getASFTestEquationTestListHead(tests);
    ASF_ASFTag result = testOne(test);

    if (result != NULL) {
      failed = ATinsert(failed, prettyTag(result));
    }

    if (!ASF_hasASFTestEquationTestListTail(tests)) {
      break;
    }
  }

  return failed;
}

/*}}}  */
/*{{{  ATermList runTests(ASF_ASFConditionalEquationList eqs, */

ATerm runTests(ASF_ASFConditionalEquationList eqs,
	       ASF_ASFTestEquationTestList tests)
{
   ASF_OptLayout e = ASF_makeOptLayoutAbsent();
   int numberOfTests = ASF_getTestEquationListLength(tests);
   ATermList failed = NULL;

   if (runVerbose) {
     ATwarning("initializing...\n");
   }

   ATprotect((ATerm*)&tagCurrentRule);
   useTide = ATfalse;
   eqs = RWprepareEquations(eqs, ATfalse);
   enter_equations(eqs);

   if (memo_table == NULL) {
     memo_table = MemoTableCreate();
   }

   tagCurrentRule = ASF_makeASFTagNotEmpty(e,
			   ASF_makeASFTagIdManyChars(
			     ASF_makeCHARLISTString("*undefined*")),e);
   rewrite_steps = 0;
   initBuiltins();

   if (runVerbose) {
     ATwarning("running tests...\n");
   }

   failed = testAll(tests);

   return ATmake("test-results(<int>,<int>,<term>)", 
		 numberOfTests, ATgetLength(failed), failed);

}

/*}}}  */
