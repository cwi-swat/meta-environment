#include "evaluator.h"
#include "reduction.h"
#include "errors.h"
#include "pre-post.h"
#include <asc-builtins.h>
#include <ASFME.h>
#include <MEPT-utils.h>
#include "equations.h"
#include "values.h"

/*{{{  static ASF_ASFTag testOne(ASF_TestEquation test) */

static ASF_ASFTag testOne(ASF_ASFTestEquation test)
{
  ASF_ASFTag tag = ASF_getASFTestEquationASFTag(test);
  ASF_ASFCondition condition = ASF_getASFTestEquationASFCondition(test);
  ATbool equals = ATfalse;
   
  PT_Tree lhs = (PT_Tree) ASF_getASFConditionLhs(condition);
  PT_Tree rhs = (PT_Tree) ASF_getASFConditionRhs(condition);

  lhs = RWprepareTerm(lhs, ATfalse);
  rhs = RWprepareTerm(rhs, ATfalse);
 
  lhs = rewrite(lhs);
  rhs = rewrite(rhs);

  if (isAsFixEqual(lhs, rhs)) {
    equals = ATtrue;
  }  

  if (ASF_isASFConditionNegative(condition)) {
    equals = !equals;
  }

  if (equals) {
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
      failed = ATinsert(failed, 
			ATmake("<str>", 
			       PT_yieldTree((PT_Tree) 
					    ASF_ASFTagToTerm(result))));
    }

    if (!ASF_hasASFTestEquationTestListTail(tests)) {
      break;
    }
  }

  return failed;
}

/*}}}  */
/*{{{  ATermList runTests(ASF_ASFConditionalEquationList eqs, */

ATermList runTests(ASF_ASFConditionalEquationList eqs,
		   ASF_ASFTestEquationTestList tests)
{
   ASF_OptLayout e = ASF_makeOptLayoutAbsent();

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

   return testAll(tests);
}

/*}}}  */
