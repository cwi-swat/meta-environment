#include <stdio.h>
#include <assert.h>
#include <SDF-utils.h>

#define TEST_GRAMMAR_FILE "Booleans.pt"

int
testSorts(void)
{
  ATerm      contents;
  SDF_Module module;
  ATermList  sorts;

  contents = ATreadFromNamedFile(TEST_GRAMMAR_FILE);
  assert(contents != NULL);

  module = SDF_makeModuleFromTerm(contents);

  sorts = SDFgetSorts(module);

  assert(ATgetLength(sorts) == 1);

  return 0;
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFApi();

  return testSorts();
}
