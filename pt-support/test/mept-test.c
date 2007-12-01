
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
  ATbool modLayout = ATtrue;

  test_assert("true > false", 
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(True)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(False)),
                             modLayout)
	      > 0);

  test_assert("false < true", 
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(False)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(True)),
                             modLayout)
	      < 0);

  test_assert("whitespace difference",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(
		             TrueAndFalse)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(
			     OtherTrueAndFalse)),
                             modLayout)
	      == 0);

  test_assert("annotations difference",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(
			     TrueAndFalse)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(
			     AnnotatedTrueAndFalse)),
                             modLayout)
	      == 0);


  test_assert("begin declare a : natural end < begin declare b : natural end",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(DeclareA)
						),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(DeclareB)
						),
                             modLayout)
	      < 0);

  test_assert("2 > 10",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(Two)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(Ten)),
                             modLayout)
	      > 0);

  test_assert("20 > 10",
	      PT_compareTree(PT_getParseTreeTree(PT_ParseTreeFromTerm(Twenty)),
			     PT_getParseTreeTree(PT_ParseTreeFromTerm(Ten)),
                             modLayout)
	      > 0);

  test_assert("compare modulo amb ordering is true",
      PT_compareTree(PT_orderAmbiguities(PT_getParseTreeTop(PT_ParseTreeFromTerm(amb1))),
        PT_orderAmbiguities(PT_getParseTreeTop(PT_ParseTreeFromTerm(amb2))),
        ATfalse)
      == 0);

  test_assert("compare modulo amb ordering is false",
	      PT_compareTree(PT_getParseTreeTop(PT_ParseTreeFromTerm(amb1)),
			     PT_getParseTreeTop(PT_ParseTreeFromTerm(amb2)),
                             ATfalse)
	      != 0);
}

/*}}}  */

void testPosInfo() {
  PT_ParseTree parseTree = PT_addParseTreePosInfo("-", PT_ParseTreeFromTerm(Integers));
  PT_Tree tree = PT_getParseTreeTree(parseTree);
  ERR_Location location;
  ERR_Area area;
  int beginLine;
  int endLine;
  int beginColumn;
  int endColumn;
  int offset;
  int length;

  assert(PT_hasTreeLocation(tree));

  location = PT_getTreeLocation(tree);
  area = ERR_getLocationArea(location);
  beginLine = ERR_getAreaBeginLine(area);
  endLine = ERR_getAreaEndLine(area);
  beginColumn = ERR_getAreaBeginColumn(area);
  endColumn = ERR_getAreaEndColumn(area);
  offset = ERR_getAreaOffset(area);
  length = ERR_getAreaLength(area);

  test_assert("beginline", beginLine == 1);
  test_assert("endline", endLine == 2);
  test_assert("begincolumn", beginColumn == 2);
  test_assert("endcolumn", endColumn == 5);
  test_assert("offset", offset == 2);
  test_assert("length", length == 7);
}

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  ERR_initErrorApi();
  init_terms_dict();

  testCompare();
  testPosInfo();

  return 0;
}

/*}}}  */


