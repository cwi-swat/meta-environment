/* $Id$ */

/** \file
 *
 */ 

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <aterm2.h>
#include <ptable.h>
#include <sglrInterface.h>
#include <atb-tool.h>
#include <MEPT-utils.h>

#include "parseTable.h"
#include "parseTableDB.h"
#include "restorebrackets.h"

static char myname[] = "restorebrackets";
static char myversion[] = "0.1";
static char myarguments[] = "abhi:o:p:tvV";
static const char PARSETABLE_ID[] = "RestoreBracketsParseTable";

ATbool run_verbose;
ATbool add_all;

void rec_terminate(int cid, ATerm t) {
  exit(0);
}

static PT_Tree RestoreBracketsInTree(PT_Tree tree, ParseTable *pt);
static PT_Args RestoreBracketsInArgs(PT_Args args, ParseTable *pt) {
  PT_Tree head, newHead;
  PT_Args tail, newTail;

  if (PT_isArgsEmpty(args)) {
    return args;
  }

  head = PT_getArgsHead(args);
  tail = PT_getArgsTail(args);
  newHead = RestoreBracketsInTree(head, pt);
  newTail = RestoreBracketsInArgs(tail, pt);

  if (!PT_isEqualTree(head, newHead) ||
      !PT_isEqualArgs(tail, newTail)) {
    return PT_makeArgsMany(newHead, newTail);
  }
  else {
    return args;
  }
}

static PT_Tree AddBracketsToTreeIfNeeded(PT_Production prod, PT_Tree tree, int argNr, ParseTable *pt);
static PT_Args AddBracketsToArgsIfNeeded(PT_Production prod, PT_Args args, int argNr, ParseTable *pt) {
  PT_Tree head, newHead;
  PT_Args tail, newTail;

  if (PT_isArgsEmpty(args)) {
    return args;
  }

  head = PT_getArgsHead(args);
  tail = PT_getArgsTail(args);
  newHead = AddBracketsToTreeIfNeeded(prod, head, argNr, pt);
  newTail = AddBracketsToArgsIfNeeded(prod, tail, ++argNr, pt);

  if (!PT_isEqualTree(head, newHead) ||
      !PT_isEqualArgs(tail, newTail)) {
    return PT_makeArgsMany(newHead, newTail);
  }
  else {
    return args;
  }
}

static PT_Tree AddBrackets(PT_Tree tree, ParseTable *pt) {
  PT_Production prod = PT_getTreeProd(tree);
  PT_Symbol rhs = PT_getProductionRhs(prod);
  PT_Production bracketProd = SGLR_PTBL_lookupBracketProd(pt, rhs);
  ATerm atBracketProd = PT_ProductionToTerm(bracketProd);
  
  if (atBracketProd && !PT_isEqualProduction(prod, bracketProd)) {
    PT_Production bracketProd = PT_ProductionFromTerm(atBracketProd);
    PT_Symbols bracketSymbols = PT_getProductionLhs(bracketProd);
    PT_Symbol openBracketSym = PT_getSymbolsHead(bracketSymbols);
    PT_Symbol closeBracketSym = PT_getSymbolsSymbolAt(bracketSymbols, 4);
    PT_Tree openBracket = PT_makeTreeLit(PT_getSymbolString(openBracketSym));
    PT_Tree closeBracket = PT_makeTreeLit(PT_getSymbolString(closeBracketSym));
    PT_Args newArgs = PT_makeArgsSingle(closeBracket);
    newArgs = PT_makeArgsMany(PT_makeTreeLayoutEmpty(), newArgs);
    newArgs = PT_makeArgsMany(tree, newArgs);
    newArgs = PT_makeArgsMany(PT_makeTreeLayoutEmpty(), newArgs);
    newArgs = PT_makeArgsMany(openBracket, newArgs);
    return PT_makeTreeAppl(bracketProd, newArgs);
  }
  else {
    if (!add_all) {
      ATwarning("No brackets defined for symbol %s\n", PT_yieldSymbol(rhs));
    }
    return tree;
  }
}

static PT_Tree AddBracketsToTreeIfNeeded(PT_Production fatherProd, PT_Tree tree, int argNr, ParseTable *pt) {
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isProductionDefault(prod)) {
      if (add_all || SGLR_PTBL_isPriorityGreater(pt, argNr, fatherProd, prod)) {
        return AddBrackets(tree, pt);
      }
    }
  }
  return tree;
}

static PT_Tree RestoreBracketsInTree(PT_Tree tree, ParseTable *pt) {
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args args = PT_getTreeArgs(tree);
    PT_Args newArgs = RestoreBracketsInArgs(args, pt);
    if (PT_isProductionDefault(prod)) {
      newArgs = AddBracketsToArgsIfNeeded(prod, newArgs, 0, pt);
    }
    if (!PT_isEqualArgs(args, newArgs)) {
      return PT_setTreeArgs(tree, newArgs);
    }
  }
  return tree;
}

static PT_ParseTree RestoreBracketsInPT(PT_ParseTree pttree, ParseTable *pt) {
  PT_Tree tree = PT_getParseTreeTop(pttree);

  PT_Tree newTree = RestoreBracketsInTree(tree, pt);

  return PT_setParseTreeTop(pttree, newTree);
}

/* Interface to toolbus. */
ATerm add_brackets(int cid, ATerm packedTerm, ATerm packedTable) {
  add_all = ATtrue;
  return restore_brackets(cid, packedTerm, packedTable);
}

ATerm restore_brackets(int cid, ATerm packedTerm, ATerm packedTable) {
  ParseTable *pt = NULL;
  ATerm restoredTerm;
  PTBL_ParseTable parseTable;
  PT_ParseTree parseTree;
  
  parseTable = PTBL_ParseTableFromTerm(ATBunpack(packedTable));
  if (!SGLR_loadParseTable(PARSETABLE_ID, parseTable)) {
    ATerror("could not open language!\n");
  }

  pt = SG_LookupParseTable(PARSETABLE_ID);
  if (!pt) {
    ATerror("failed to find parse table for language %s\n", PARSETABLE_ID);
  }

  parseTree = PT_ParseTreeFromTerm(ATBunpack(packedTerm));
  restoredTerm = PT_ParseTreeToTerm(RestoreBracketsInPT(parseTree, pt));

  SGLR_PTBL_discardParseTable(pt);
  return ATmake("snd-value(brackets-restored(<term>))", ATBpack(restoredTerm));
}

static void usage(void) {
  ATwarning("Usage: %s [options]\n"
            "Options:\n"
            "\t-a              put all possible brackets (one level)\n"
            "\t-b              output terms in BAF format (default)\n"
            "\t-i filename     input from file (default stdin)\n"
            "\t-o filename     output to file (default stdout)\n"
            "\t-p file         use parse table (required)\n"
            "\t-t              output terms in plain text format\n"
            "\t-v              verbose mode\n"
            "\t-V              reveal program version (i.e. %s)\n",
            myname, myversion);
}

static void version(void) {
  ATwarning("%s v%s\n", myname, myversion);
}

int main(int argc, char *argv[]) {
  FILE *iofile;

  int cid;
  ATerm bottomOfStack;
  PT_ParseTree tree, restoredTree;
  char *input = "-";
  char *output = "-";
  char *parse_table_file = NULL;
  PTBL_ParseTable parseTable;
  ATerm packedParseTable;
  ParseTable *pt;
  int bafMode = 1;
  
  ATbool need_closing;

  int c, toolbus_mode = 0;
  run_verbose = ATfalse;

  for (c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi(); 
  initErrorApi();
  SGLR_initialize();

  if (toolbus_mode) {
    ATBinit(argc, argv, &bottomOfStack);
    cid = ATBconnect(NULL, NULL, -1, restorebrackets_handler);
    ATBeventloop();
  }
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'a': add_all = ATtrue;        break;
        case 'b': bafMode =1;              break;
        case 'i': input=optarg;            break;
        case 'o': output=optarg;           break;
        case 'p': parse_table_file=optarg; break;
        case 't': bafMode = 0;             break;
        case 'v': run_verbose = ATtrue;    break;
        case 'V': version(); exit(0);      break;
        case 'h':
        default:  usage(); exit(0);        break;
      }
    }

    if (parse_table_file == NULL) {
      ATwarning("Please provide a parse table using the -p option\n");
      usage();
      return 1;
    }

    if (!strcmp(input, "") || !strcmp(input, "-")) {
      iofile = stdin;
    }
    else {
      if (!(iofile = fopen(input, "rb"))) {
        ATerror("%s: cannot open %s\n", myname, input);
      }
    }

    if (run_verbose) {
      ATwarning("restoring brackets for %s\n", input);
    }

    tree = PT_ParseTreeFromTerm(ATreadFromFile(iofile));
    assert(tree);

    packedParseTable = ATreadFromNamedFile(parse_table_file); 
    parseTable = PTBL_ParseTableFromTerm(ATBunpack(packedParseTable));

    if (!SGLR_loadParseTable(PARSETABLE_ID, parseTable)) {
      ATerror("could not open language!\n");
      return 1;
    }

    pt = SG_LookupParseTable(PARSETABLE_ID);
    if (!pt) {
      ATerror("failed to find parse table for language %s\n", parse_table_file);
      return 1;
    }

    restoredTree = RestoreBracketsInPT(tree, pt);

    if (!strcmp(output, "") || !strcmp(output, "-")) {
      iofile = stdout;
      need_closing = ATfalse;
    }
    else {
      iofile = fopen(output, "wb");
      if (iofile == NULL) {
        ATerror("%s: cannot open %s\n", myname, output);
      }
      need_closing = ATtrue;
    }

    if (bafMode) {
      ATwriteToBinaryFile(PT_ParseTreeToTerm(restoredTree), iofile);
    }
    else {
      ATwriteToTextFile(PT_ParseTreeToTerm(restoredTree), iofile);
    }
    if (need_closing && iofile != NULL) {
      fclose(iofile);
    }
  }
  return 0;
}
