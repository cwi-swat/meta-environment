/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <ASFME-utils.h>

#include "findSortDefinition.h"
#include "findProduction.h"
#include "findProdUse.h"

#include "query-tool.tif.h"

/*}}}  */

static char myversion[] = "1.1";

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */

/*{{{  static void usage(char *prg, ATbool is_err) */

static void usage(char *prg, ATbool is_err)
{
  ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
  ATwarning("use '%s -at-help' to get more options.\n", prg);
  ATwarning("This program can only be used as a ToolBus tool!\n");
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  static void version(const char *msg) */

static void version(const char *msg)
{
  ATwarning("%s v%s\n", msg, myversion);
  exit(1);
}

/*}}}  */

/*{{{  ATerm findSortDefinition(ATerm atModule, ATerm atTree) */

ATerm findSortDefinition(ATerm atModule, ATerm atTree)
{
  SDF_Module sdfModule = SDF_getStartTopModule(SDF_StartFromTerm(atModule));
  PT_ParseTree parseTree = PT_ParseTreeFromTerm(atTree);

  if (querySortInModule(sdfModule, parseTree)) {
    return ATmake("snd-value(result(found))");
  }
  else {
    return ATmake("snd-value(result(not-found))");
  }
}

/*}}}  */
/*{{{  ATerm findProduction(ATerm atModule, ATerm atTree) */

ATerm findProduction(ATerm atModule, ATerm atTree)
{
  SDF_Module sdfModule = SDF_getStartTopModule(SDF_StartFromTerm(atModule));
  PT_ParseTree parseTree = PT_ParseTreeFromTerm(atTree);
  ATerm posInfo = queryProductionInModule(sdfModule, parseTree);

  if (posInfo) {
    /*ATwarning("found %t\n", posInfo);*/
    return ATmake("snd-value(result(found(<term>)))", posInfo);
  }
  else {
    /*ATwarning("not found\n");*/
    return ATmake("snd-value(result(not-found))");
  }
}

/*}}}  */
/*{{{  ATerm findProdUse(ATerm atEquations, ATerm atProduction) */

ATerm findProdUse(ATerm atEquations, ATerm atProduction)
{
  ATerm posInfo;
  ASF_Start asfStart;
  ASF_Equations asfEquations;
  SDF_Production sdfProduction;
  PT_ParseTree parseTree;
  PT_Tree tree;

  asfStart = ASF_StartFromTerm(atEquations);
  assert(ASF_isValidStart(asfStart));

  asfEquations = ASF_getStartTopEquations(asfStart);

  parseTree = PT_ParseTreeFromTerm(atProduction);
  tree = PT_getParseTreeTree(parseTree);

  sdfProduction = SDF_ProductionFromTerm(PT_TreeToTerm(tree));
  assert(SDF_isValidProduction(sdfProduction));

  posInfo = queryProdUse(asfEquations, sdfProduction);

  if (posInfo) {
    ATwarning("found %t\n", posInfo);
    return ATmake("snd-value(result(found(<term>)))", posInfo);
  }
  else {
    ATwarning("not found\n");
    return ATmake("snd-value(result(not-found))");
  }
}

/*}}}  */

/*{{{  ATerm query(int cid, char *type, ATerm atModule, ATerm atTree) */

ATerm query(int cid, char *type, ATerm atModule, ATerm atTree)
{
  /*ATwarning("query: %s\n", type);*/
  if (strcmp(type, "symbol") == 0) {
    return findSortDefinition(atModule, atTree);
  }
  
  if (strcmp(type, "production") == 0) {
    return findProduction(atModule, atTree);
  }

  if (strcmp(type, "produse") == 0) {
    return findProdUse(atModule, atTree);
  }

  ATabort("query-tool.c: unknown query: %s\n", type);
  return NULL;
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;

  for (i=1; i<argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      usage(argv[0], ATfalse);
    } else if (strcmp(argv[i], "-V") == 0) {
      version(argv[0]);
    }
  }

  ATBinit(argc, argv,&bottomOfStack);
  PT_initMEPTApi();
  SDF_initSDFMEApi();
  ASF_initASFMEApi();

  cid = ATBconnect(NULL, NULL, -1, query_tool_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
