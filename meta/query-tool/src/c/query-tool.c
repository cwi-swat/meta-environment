/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>

#include <MEPT-utils.h>
#include <SDFME-utils.h>

#include "findSortDefinition.h"
#include "findProduction.h"

#include "query-tool.tif.h"

/*}}}  */

static char myversion[] = "1.0";

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
/*{{{  ATerm findSortDefinition(ATerm atModule, ATerm atTree) */

ATerm findProduction(ATerm atModule, ATerm atTree)
{
  SDF_Module sdfModule = SDF_getStartTopModule(SDF_StartFromTerm(atModule));
  PT_ParseTree parseTree = PT_ParseTreeFromTerm(atTree);

  if (queryProductionInModule(sdfModule, parseTree)) {
    return ATmake("snd-value(result(found))");
  }
  else {
    return ATmake("snd-value(result(not-found))");
  }
}

/*}}}  */

/*{{{  ATerm query(int cid, ATerm atModule, ATerm atTree) */

ATerm query(int cid, char *type, ATerm atModule, ATerm atTree)
{
  /*return findSortDefinition(atModule, atTree);*/
  return findProduction(atModule, atTree);
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

  cid = ATBconnect(NULL, NULL, -1, query_tool_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
