#include <assert.h>

#include "findProduction.h"

#define SDF_MODULE (SRC_DIR "/terms/Bool.sdf.pt")
#define LIST_TREE (SRC_DIR "/terms/boollist.pt")
#define SEP_LIST_TREE (SRC_DIR "/terms/boolseplist.pt")
#define AND_TREE (SRC_DIR "/terms/booland.pt")
#define OR_TREE (SRC_DIR "/terms/boolor.pt")
#define ID_TREE (SRC_DIR "/terms/id.pt")

static void testFrame(const char *termName, ATerm expectedArea)
{
  ATerm input;
  SDF_Module sdfModule;
  SDF_Start sdfStart;
  PT_ParseTree parseTree;
  ATerm resultArea;

  input = ATreadFromNamedFile(SDF_MODULE);
  assert(input != NULL);
 
  sdfStart = SDF_StartFromTerm(input);
  assert(SDF_isValidStart(sdfStart));
 
  sdfModule = SDF_getStartTopModule(sdfStart);
  assert(SDF_isValidModule(sdfModule));
 
  input = ATreadFromNamedFile(termName);
  assert(input != NULL);
 
  parseTree = PT_ParseTreeFromTerm(input);
  assert(PT_isValidParseTree(parseTree));
 
  resultArea = queryProductionInModule(sdfModule, parseTree);
  assert(resultArea != NULL);
/*
ATwarning("area = %t\n", resultArea);
*/
  assert(ATisEqual(resultArea, expectedArea));
}

static void testProduction()
{
  testFrame(LIST_TREE, ATparse("area(\"Test\",11,4,12,4)"));
  testFrame(SEP_LIST_TREE, ATparse("area(\"Test\",12,4,14,0)"));
  testFrame(OR_TREE, ATparse("area(\"Test\",9,4,9,34)"));
  testFrame(AND_TREE, ATparse("area(\"Test\",10,4,10,34)"));
  testFrame(ID_TREE, ATparse("area(\"Test\",17,4,18,0)"));
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();
  PT_initMEPTApi();

  testProduction();

  return 0;
}
