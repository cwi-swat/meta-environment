#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <aterm2.h>

#include <parse-table.h>
#include <sglr.h>
#include <atb-tool.h>
#include "restorebrackets.tif.h"
#include <MEPT-utils.h>

static char myname[] = "restorebrackets";
static char myversion[] = "0.1";

static char myarguments[] = "bhi:o:p:atvV";

ATbool run_verbose;
ATbool add_all;

void rec_terminate(int cid, ATerm t) {
  exit(0);
}

static PT_Tree RestoreBracketsInTree(PT_Tree tree, parse_table *pt);
static PT_Args RestoreBracketsInArgs(PT_Args args, parse_table *pt)
{
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

static PT_Tree AddBracketsToTreeIfNeeded(int label, 
                                         PT_Tree tree, 
                                         int argNr,
                                         parse_table *pt);
static PT_Args AddBracketsToArgsIfNeeded(int label, 
                                         PT_Args args, 
                                         int argNr,
                                         parse_table *pt) 
{
  PT_Tree head, newHead;
  PT_Args tail, newTail;

  if (PT_isArgsEmpty(args)) {
    return args;
  }

  head = PT_getArgsHead(args);
  tail = PT_getArgsTail(args);
  newHead = AddBracketsToTreeIfNeeded(label, head, argNr, pt);
  newTail = AddBracketsToArgsIfNeeded(label, tail, ++argNr, pt);

  if (!PT_isEqualTree(head, newHead) ||
      !PT_isEqualArgs(tail, newTail)) {
    return PT_makeArgsMany(newHead, newTail);
  }
  else {
    return args;
  }
}

static PT_Tree AddBrackets(PT_Tree tree, parse_table *pt)
{
  PT_Production prod = PT_getTreeProd(tree);
  PT_Symbol rhs = PT_getProductionRhs(prod);
  PT_Production bracketProd;
  ATerm atBracketProd;

  bracketProd = (PT_Production) SG_LookupBracketProd(pt, rhs);
  atBracketProd = PT_ProductionToTerm(bracketProd);

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

static PT_Tree AddBracketsToTreeIfNeeded(int fatherLabel, 
                                         PT_Tree tree, 
                                         int argNr,
                                         parse_table *pt) 
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isProductionDefault(prod)) {
      int sonLabel = SG_LookupLabel(pt, (ATermAppl)PT_ProductionToTerm(prod));
      if (add_all || SGGtrPriority(pt, argNr, fatherLabel, sonLabel)) {
        return AddBrackets(tree, pt);
      }
    }
  }
  return tree;
}

static PT_Tree RestoreBracketsInTree(PT_Tree tree, parse_table *pt)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args args = PT_getTreeArgs(tree);
    PT_Args newArgs = RestoreBracketsInArgs(args, pt);
    if (PT_isProductionDefault(prod)) {
      int label = SG_LookupLabel(pt, (ATermAppl)PT_ProductionToTerm(prod));
      newArgs = AddBracketsToArgsIfNeeded(label, newArgs, 0, pt);
    }
    if (!PT_isEqualArgs(args, newArgs)) {
      return PT_setTreeArgs(tree, newArgs);
    }
  }
  return tree;
}

static PT_ParseTree RestoreBracketsInPT(PT_ParseTree pttree, parse_table *pt)
{
  PT_Tree tree = PT_getParseTreeTop(pttree);

  PT_Tree newTree = RestoreBracketsInTree(tree, pt);

  return PT_setParseTreeTop(pttree, newTree);
}

ATerm add_brackets(int cid, ATerm packedTerm, ATerm packedTable)
{
	add_all = ATtrue;
	return restore_brackets(cid, packedTerm, packedTable);
}

ATerm restore_brackets(int cid, ATerm packedTerm, ATerm packedTable)
{
  parse_table *pt = NULL;
  ATerm restoredTerm;

  ATerm table = ATBunpack(packedTable);
  ATerm term = ATBunpack(packedTerm);

  pt = SG_BuildParseTable((ATermAppl) table, NULL);

  restoredTerm
    = PT_ParseTreeToTerm(RestoreBracketsInPT(PT_ParseTreeFromTerm(term), pt));

  SG_DiscardParseTable(pt);

  return ATmake("snd-value(brackets-restored(<term>))", ATBpack(restoredTerm));
}

static void usage(void)
{
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

static void version(void)
{
  ATwarning("%s v%s\n", myname, myversion);
}
  

int main(int argc, char *argv[])
{
  FILE *iofile;

  int cid;
  ATerm bottomOfStack;
  PT_ParseTree tree, restoredTree;
  char *input = "-";
  char *output = "-";
  char *parse_table_file = NULL;
  language lang_name;
  parse_table *pt;
  int bafMode = 1;
  int proceed = 1;
  
  ATbool need_closing;

  int c, toolbus_mode = 0;
  run_verbose = ATfalse;

  for (c=1; !toolbus_mode && c<argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi(); 
  initErrorApi();

  if (toolbus_mode) {
    ATBinit(argc, argv, &bottomOfStack);
    cid = ATBconnect(NULL, NULL, -1, restorebrackets_handler);
    ATBeventloop();
  }

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'a': add_all = ATtrue;	 break;	    	
      case 'b': bafMode =1;              break;
      case 'i': input=optarg;            break;
      case 'o': output=optarg;           break;
      case 'p': parse_table_file=optarg; break;
      case 't': bafMode = 0;             break;
      case 'v': run_verbose = ATtrue;    break;
      case 'V': version(); proceed = 0;  break;
    
      case 'h':
      default:  usage(); proceed = 0;   break;
    }
  }

  argc -= optind;
  argv += optind;

  if (parse_table_file == NULL) {
	  ATwarning("Please provide a parse table using the -p option\n");
	  usage();
	  return 1;
  }

  if (proceed) {
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
    
    lang_name = ATmake("<str>", parse_table_file);
    if (!SGopenLanguage(lang_name, parse_table_file, input)) {
      ATerror("could not open language!\n");
      return 1;
    }
    
    pt = SG_LookupParseTable(lang_name, input);
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
