/*
  $Id$
 */

#include <stdlib.h>
#include <aterm2.h>
#include <atb-tool.h>

#include <SDFME-utils.h>
#include "sdf-tool.tif.h"

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
    ATwarning("sdf-tool: an interface to the sdf-support library.\n"
	      "This tool can only be executed on the ToolBus platform.\n");
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

#define RESULT_TERM(t) (ATmake("snd-value(result(<term>))",t))

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

  ATBinit(argc, argv, &bottomOfStack);
  SDF_initSDFMEApi();


  cid = ATBconnect(NULL, NULL, -1, sdf_tool_handler);

  ATBeventloop();

  return 0;
}

/*}}}  */
