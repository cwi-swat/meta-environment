#include <stdio.h>
#include <assert.h>
#include <SDF-utils.h>

#define TEST_GRAMMAR_FILE "Layout.pt"

int
testGrammars(void)
{
  ATerm      contents;
  SDF_Module module;
  ATermList  lexProds;

  contents = ATreadFromNamedFile(TEST_GRAMMAR_FILE);
  assert(contents != NULL);

  module = SDF_makeModuleFromTerm(contents);

  lexProds = SDFgetLexicalProductions(module);

  assert(ATgetLength(lexProds) == 3);

  return 0;
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFApi();

  return testGrammars();
}
