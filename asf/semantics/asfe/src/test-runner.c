/*{{{  includes */

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
#include <Error.h>
#include "equations.h"
#include "values.h"

/*}}}  */

/*{{{  defines */

#define BUFFER_SIZE 10240

/*}}}  */

/*{{{  static ATerm prettyTag(ASF_ASFTag tag) */

static ERR_Error prettyTag(ASF_ASFTag tag)
{
  char *description;
  LOC_Location location = PT_getTreeLocation((PT_Tree) tag);
  ERR_Subject subject;

  if (!ASF_isASFTagEmpty(tag)) {
    ASF_ASFTagId id = ASF_getASFTagASFTagId(tag);
    description = PT_yieldTreeToString((PT_Tree) id, ATfalse);
  }
  else {
    description = "unnamed test";
  }

  if (location == NULL) {
    subject = ERR_makeSubjectSubject(description);
  } else {
    subject = ERR_makeSubjectLocalized(description, (ERR_Location) location);
  }

  return ERR_makeErrorError("failed test", ERR_makeSubjectListSingle(subject));
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

  lhs = (PT_Tree) ASF_getASFConditionLhs(tobetested);
  rhs = (PT_Tree) ASF_getASFConditionRhs(tobetested);

  lhs = rewriteInnermost(lhs, environment, 0, NO_TRAVERSAL);
  rhs = rewriteInnermost(rhs, environment, 0, NO_TRAVERSAL); 

  tagCurrentRule = tag;

  if (!no_new_vars(lhs, environment)) {
    RWaddError("Left side of test introduces a variable", 
	       PT_yieldTreeToString((PT_Tree) tag, ATfalse));
    return tag;
  }
  if (!no_new_vars(rhs, environment)) {
    RWaddError("Right side of test introduces a variable", 
	       PT_yieldTreeToString((PT_Tree) tag, ATfalse));
    return tag;
  }

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
/*{{{  static ERR_ErrorList testAll(ASF_ASFTestEquationTestList tests,  */

static ERR_ErrorList testAll(ASF_ASFTestEquationTestList tests, 
			     ERR_ErrorList failed)
{
  while (!ASF_isASFTestEquationTestListEmpty(tests)) {
    ASF_ASFTestEquation test = ASF_getASFTestEquationTestListHead(tests);
    ASF_ASFTag result = testOne(test);

    if (result != NULL) {
      failed = ERR_makeErrorListMany(prettyTag(result), failed);
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
	       ASF_ASFTestEquationTestList tests)
{
   ASF_OptLayout e = ASF_makeOptLayoutAbsent();
   ERR_ErrorList failed = ERR_makeErrorListEmpty();

   if (runVerbose) {
     ATwarning("initializing...\n");
   }

   ASF_protectASFTag(&tagCurrentRule);
   useTide = ATfalse;

   eqs = RWprepareEquations(eqs, ATfalse);
   enter_equations(eqs);

   if (memo_table == NULL) {
     memo_table = MemoTableCreate();
   }

   tagCurrentRule = ASF_makeASFTagNotEmpty(e,
			   ASF_makeASFTagIdManyChars("*undefined*"),e);
   rewrite_steps = 0;
   initBuiltins();

   if (runVerbose) {
     ATwarning("running tests...\n");
   }

   failed = testAll(tests, failed);

   return ATmake("test-results(<term>)", failed);
}

/*}}}  */
