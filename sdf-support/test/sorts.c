#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <SDFME-utils.h>
#include <MEPT-utils.h>

#define TEST_GRAMMAR_FILE SRC_DIR "/Booleans.pt"

/*{{{  int testSorts(void) */

int testSorts(void)
{
  ATerm       contents;
  SDF_Start start;
  SDF_SymbolList   sorts;
  SDF_Module  module;
  SDF_Symbol  symbol;
  SDF_Sort    sort;
  char       *str;

  contents = ATreadFromNamedFile(TEST_GRAMMAR_FILE);
  assert(contents != NULL);

  start = SDF_StartFromTerm(contents);
  module = SDF_getStartTopModule(start);

  sorts = SDF_getModuleSorts(module);

  assert(ATgetLength((ATermList)SDF_SymbolListToTerm(sorts)) == 1);

  symbol = SDF_getSymbolListHead(sorts);

  assert(SDF_hasSymbolSort(symbol));

  sort   = SDF_getSymbolSort(symbol);

  str    = PT_yieldTree((PT_Tree) sort);

  assert(strcmp(str, "PICO-BOOL") == 0);

  return 0;
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();
  PT_initMEPTApi();

  return testSorts();
}

/*}}}  */
