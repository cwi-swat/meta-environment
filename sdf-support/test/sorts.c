#include <stdio.h>
#include <assert.h>
#include <SDF-utils.h>

#define TEST_GRAMMAR_FILE "Booleans.pt"

int
testSorts(void)
{
  ATerm       contents;
  SDF_SymbolList   sorts;
  SDF_Module  module;
  SDF_Symbol  symbol;
  SDF_Sort    sort;
  char       *lex;

  contents = ATreadFromNamedFile(TEST_GRAMMAR_FILE);
  assert(contents != NULL);

  module = SDF_makeModuleFromTerm(contents);

  sorts = SDF_getModuleSorts(module);

  assert(ATgetLength((ATermList)SDF_makeTermFromSymbolList(sorts)) == 1);

  symbol = SDF_getSymbolListHead(sorts);
  sort   = SDF_getSymbolSort(symbol);
  lex    = SDF_getSortLex(sort);

  assert(strcmp(lex, "PICO-BOOL") == 0);

  return 0;
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFApi();

  return testSorts();
}
