#include <stdio.h>
#include <assert.h>
#include <SDFME-utils.h>

#define TEST_GRAMMAR_FILE SRC_DIR "/Layout.pt"

int
testGrammars(void)
{
  ATerm      contents;
  SDF_Module module;
  SDF_ProductionList lexProds;

  contents = ATreadFromNamedFile(TEST_GRAMMAR_FILE);
  assert(contents != NULL);

  module = SDF_getStartTopModule((SDF_Start) contents);

  lexProds = SDF_getModuleLexicalProductions(module);

  assert(ATgetLength((ATermList)SDF_ProductionListToTerm(lexProds)) == 5);

  return 0;
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();

  return testGrammars();
}
