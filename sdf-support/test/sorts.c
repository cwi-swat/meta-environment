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
  SDF_SymbolList   sorts;
  SDF_Module  module;
  SDF_Symbol  symbol;
  SDF_Sort    sort;
  SDF_Lexical lex;
  char       *str;

  contents = ATreadFromNamedFile(TEST_GRAMMAR_FILE);
  assert(contents != NULL);

  module = SDF_ModuleFromTerm(
             PT_TreeToTerm(
               PT_getParseTreeTree(PT_ParseTreeFromTerm(contents))));

  sorts = SDF_getModuleSorts(module);

  assert(ATgetLength((ATermList)SDF_makeTermFromSymbolList(sorts)) == 1);

  symbol = SDF_getSymbolListHead(sorts);
  sort   = SDF_getSymbolSort(symbol);
  lex    = SDF_getSortLex(sort);
  str    = PT_yieldTree((PT_Tree)lex);

  assert(strcmp(str, "PICO-BOOL") == 0);

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

  return testSorts();
}

/*}}}  */
