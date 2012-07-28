/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <assert.h>

#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <PT2SDF.h>

/*}}}  */
/*{{{  defines */

#define TEST_PT2SDF_FILE SRC_DIR "/BoolTerm.pt"

/*}}}  */

/*{{{  static int testPT2SDF(void) */

static int testPT2SDF(void)
{
  ATerm contents;
  PT_ParseTree parseTree;
  PT_Tree tree;
  PT_Production ptProduction;
  SDF_Production sdfProduction;

  contents = ATreadFromNamedFile(TEST_PT2SDF_FILE);
  assert(contents != NULL);

  parseTree = PT_ParseTreeFromTerm(contents);
  tree = PT_getParseTreeTree(parseTree);
  assert(PT_isValidTree(tree));

  assert(PT_isTreeAppl(tree));
  ptProduction = PT_getTreeProd(tree);
  assert(PT_isValidProduction(ptProduction));
  /*ATwarning("ptProduction: %t\n", ptProduction);*/

  sdfProduction = PTProductionToSDFProduction(ptProduction);
  /*ATwarning("%t\n", sdfProduction);*/
  assert(SDF_isValidProduction(sdfProduction));
  /*ATwarning("sdfProduction: %t\n", sdfProduction);*/

  return 0;
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();
  SDF_initSDFMEApi();

  return testPT2SDF();
}

/*}}}  */
