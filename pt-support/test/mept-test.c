
/* $Id$
 *
 * In this file we test some features of the pt-support library
 */

#include <MEPT-utils.h>
#include <assert.h>
#include <terms_dict.h>

#define test_assert(msg,exp) (assert(exp && msg))

/*{{{  void testCompare() */

void testCompare()
{
  test_assert("true > false", 
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(True)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(False)))
	      > 0);

  test_assert("false < true", 
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(False)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(True)))
	      < 0);

  test_assert("whitespace difference",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(
		             TrueAndFalse)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(
			     OtherTrueAndFalse)))
	      == 0);

  test_assert("annotations difference",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(
			     TrueAndFalse)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(
			     AnnotatedTrueAndFalse)))
	      == 0);


  test_assert("begin declare a : natural end < begin declare b : natural end",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(DeclareA)
						),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(DeclareB)
						))
	      < 0);

  test_assert("2 > 10",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(Two)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(Ten)))
	      > 0);

  test_assert("20 > 10",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(Twenty)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(Ten)))
	      > 0);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  init_terms_dict();

  testCompare();

  return 0;
}

/*}}}  */

