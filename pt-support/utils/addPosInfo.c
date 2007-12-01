/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <MEPT-utils.h>
#include <Error-utils.h>

#include "position-annotator.h"

/*}}}  */

static char version[] = "1.3";

#ifndef streq
#define streq(str1, str2) (!strcmp(str1, str2))
#endif

/*{{{  ATerm add_posinfo(int cid, const char* path, ATerm t) */

ATerm add_posinfo(int cid, const char* path, ATerm t)
{
  PT_ParseTree result = PT_addParseTreePosInfoSome(path, 
						   (PT_ParseTree) ATBunpack(t), 
						   -1, ATfalse, ATfalse);

  return ATmake("snd-value(tree-with-pos-info(<term>))", (ATerm) result);
}

/*}}}  */
/*{{{  ATerm add_posinfo_packed(int cid, const char* path, ATerm t) */

ATerm add_posinfo_packed(int cid, const char* path, ATerm t)
{
  PT_ParseTree result 
    = PT_addParseTreePosInfoSome(path, 
				 (PT_ParseTree) ATBunpack(t), 
				 -1, ATfalse, ATfalse);

  return ATmake("snd-value(tree-with-pos-info(<term>))", ATBpack((ATerm) result));
}

/*}}}  */
/*{{{  ATerm add_posinfo_to_depth(int cid, const char* path, ATerm t, int depth) */

ATerm add_posinfo_to_depth(int cid, const char* path, ATerm t, int depth)
{
  PT_ParseTree result = PT_addParseTreePosInfoSome(path, 
						   (PT_ParseTree) ATBunpack(t), 
						   depth, ATfalse, ATfalse);

  return ATmake("snd-value(tree-with-pos-info(<term>))", ATBpack((ATerm) result));
}

/*}}}  */
/*{{{  ATerm promote_posinfo_to_origin(int cid, ATerm t) */

ATerm promote_posinfo_to_origin(int cid, ATerm t)
{
  PT_ParseTree parseTree = PT_ParseTreeFromTerm(ATBunpack(t));
  PT_Tree tree = PT_getParseTreeTop(parseTree);
  tree = PT_promotePosInfoToOrigin(tree);
  parseTree = PT_setParseTreeTop(parseTree, tree);

  return ATmake("snd-value(tree(<term>))", ATBpack((ATerm)parseTree));
}

/*}}}  */
/*{{{  ATerm get_origin(int cid, ATerm t) */

ATerm get_origin(int cid, ATerm t)
{
  PT_Tree tree = PT_TreeFromTerm(ATBunpack(t));
  ERR_Location origin = PT_getTreeOrigin(tree);

  if (origin == NULL) {
    return ATmake("snd-value(no-origin)");
  }
  else {
    return ATmake("snd-value(origin(<term>))", ERR_LocationToTerm(origin));
  }
}

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
    exit(0);
} 

/*}}}  */

/*{{{  static void usage(const char *myname, const char* myversion) */

static void usage(const char *myname, const char* myversion)
{
   fprintf (stderr,
        "Usage: %s [<options>]\n"
        "Options:\n"
        "\t-d <int>       Maximum tree depth to traverse"
        "\t(Default: unlimited)\n"
	"\t-f             Make offset instead of area"
	"\t(Default: off)\n"
        "\t-h             Display help information (usage)\n"
        "\t-i <input>     Read input from file <input>"
        "\t(Default: stdin)\n"
	"\t-l             label layout too"
	"\t\t\t(Default: off)\n"
	"\t-m             label literals too"
	"\t\t(Default: off)\n"
        "\t-o <output>    Write output to file <output>"
        "\t(Default: stdout)\n"
        "\t-p <path>      Path of file (obligatory)\n"
	"\t-t             Write textual ATerm format\n"
        "\t-V             Print version information (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

/*{{{  static void requireArgument(int argc, char *argv[], int arg) */

static void requireArgument(int argc, char *argv[], int arg)
{
   if (arg > argc) {
     fprintf(stderr,
             "%s: %s option requires an argument.\n", argv[0], argv[arg]);
     exit(1);
   }
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm     bottomOfStack;
  ATerm     contents;
  char   *input  = "-";
  char   *output = "-";
  ATbool label_layout = ATfalse;
  ATbool label_literals = ATfalse;
  ATbool text = ATfalse;
  ATbool offset = ATfalse;
  char   *path = NULL;
  int depth = -1;
  PT_ParseTree parseTree;
  int lcv;
#ifndef WITHOUT_TOOLBUS
  ATbool use_toolbus = ATfalse;
  int i;

  for (i=1; !use_toolbus && i < argc; i++) {
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (use_toolbus) {
    int cid;
    ATBinit(argc, argv, &bottomOfStack);
    PT_initMEPTApi();
    ERR_initErrorApi();

    cid = ATBconnect(NULL, NULL, -1, position_annotator_handler);
    ATBeventloop();
  }
  else 
#endif
  {
    ATinit(argc, argv, &bottomOfStack);
    PT_initMEPTApi();
    ERR_initErrorApi();

    if (argc == 1) {
      /* no arguments */
      usage(argv[0], version);
      exit(1);
    }

    /*{{{  Parse commandline arguments */

    for (lcv = 1; lcv < argc; lcv++) {
      if (streq(argv[lcv], "-d")) {
	requireArgument(argc, argv, lcv);
	depth = atoi(argv[++lcv]);
      }
      else if (streq(argv[lcv], "-f")) {
	offset = ATtrue;
      }
      else if (streq(argv[lcv], "-h")) {
	usage(argv[0],version);
	exit(0);
      }
      else if (streq(argv[lcv], "-i")) {
	requireArgument(argc, argv, lcv);
	input = argv[++lcv];
      }
      else if (streq(argv[lcv], "-l")) {
	label_layout = ATtrue;
      }
      else if (streq(argv[lcv], "-m")) {
	label_literals = ATtrue;
      }
      else if (streq(argv[lcv], "-o")) {
	requireArgument(argc, argv, lcv);
	output = argv[++lcv];
      }
      else if (streq(argv[lcv], "-p")) {
	requireArgument(argc, argv, lcv);
	path = strdup(argv[++lcv]);
	if(path == NULL) {
	  ATerror("%s: not enough memory.\n", argv[0]);
	  exit(1);
	}
      }
      else if (streq(argv[lcv], "-t")) {
	text = ATtrue;
      }
      else if (streq(argv[lcv], "-V")) {
	fprintf(stderr, "%s v%s\n", argv[0], version);
	exit(0);
      }
    }

    if (path == NULL) {
      ATwarning("Error: -p option is obligatory\n\n");
      usage(argv[0], version);
      return 1;
    }

    /*}}}  */

    contents = ATreadFromNamedFile(input);
    assert(contents != NULL);

    parseTree =  PT_ParseTreeFromTerm(contents);

    if (!offset) {
      parseTree = PT_addParseTreePosInfoSome(path, parseTree, depth, 
					     label_layout, label_literals);
    }

    if (text) {
      ATwriteToNamedTextFile(PT_ParseTreeToTerm(parseTree), output);
    }
    else {
      ATwriteToNamedBinaryFile(PT_ParseTreeToTerm(parseTree), output);
    }

  }

  return 0;
}

/*}}}  */
