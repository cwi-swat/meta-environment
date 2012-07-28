#include <assert.h>

#include "findSortDefinition.h"

#define SDF_MODULE (SRC_DIR "/terms/Bool.sdf.pt")
#define TEST_TREE (SRC_DIR "/terms/boollist.pt")

void testSortDefinition()
{
  ATerm input;
  SDF_Module sdfModule;
  SDF_Start sdfStart;
  PT_ParseTree parseTree;

  input = ATreadFromNamedFile(SDF_MODULE);
  assert(input != NULL);

  sdfStart = SDF_StartFromTerm(input);
  assert(SDF_isValidStart(sdfStart));

  sdfModule = SDF_getStartTopModule(sdfStart);
  assert(SDF_isValidModule(sdfModule));

  input = ATreadFromNamedFile(TEST_TREE);
  assert(input != NULL);

  parseTree = PT_ParseTreeFromTerm(input);
  assert(PT_isValidParseTree(parseTree));

  assert(querySortInModule(sdfModule, parseTree) == ATtrue);
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();
  PT_initMEPTApi();

  testSortDefinition();

  return 0;
}
