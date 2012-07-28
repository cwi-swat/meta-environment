#include <SDFME-utils.h>
#include <SDF2PT.h>
#include <MEPT-utils.h>
#include <assert.h>
#include <string.h>

#define MAX_LAYOUT_LENGTH 10000
#define DEFAULT_LAYOUT_CHARACTER ' '

ATermTable mapping = NULL;
static char layout_buffer[MAX_LAYOUT_LENGTH] = { '\0' };

static PT_Tree pTree(PT_Tree tree, int *i);
static PT_Args pArgs(PT_Args args, int *i);

/*{{{  static PT_Production normalizeProduction(PT_Production prod) */

static PT_Production normalizeProduction(PT_Production prod)
{
  PT_Symbol layout = PT_makeOptLayoutSymbol();

  if (!PT_isProductionList(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Symbols newLhs = PT_makeSymbolsEmpty();
    PT_Symbol rhs = PT_getProductionRhs(prod);

    for(; !PT_isSymbolsEmpty(lhs); lhs = PT_getSymbolsTail(lhs)) {
      PT_Symbol head = PT_getSymbolsHead(lhs);
      PT_Symbol newHead;

      if (!PT_isSymbolLit(head)) {
	newHead = PT_makeSymbolCf(head);
      }
      else {
	newHead = head;
      }

      newLhs = PT_makeSymbolsList(newHead, newLhs);

      if (PT_hasSymbolsTail(PT_getSymbolsTail(lhs))) {
	newLhs = PT_makeSymbolsList(layout, newLhs);
      }
    }

    prod = PT_setProductionRhs(prod, PT_makeSymbolCf(rhs));
    prod = PT_setProductionLhs(prod, PT_reverseSymbols(newLhs));

    return prod;
  }
  else {
    return prod;
  }
}

/*}}}  */
/*{{{  static SDF_ProductionList collectProductions(SDF_SDF syntax) */

static SDF_ProductionList collectProductions(SDF_SDF syntax)
{
  SDF_Definition def = SDF_getSDFDefinition(syntax);
  SDF_ModuleList modules = SDF_getDefinitionList(def);
  SDF_ProductionList productions = SDF_makeProductionListEmpty();

  while (SDF_hasModuleListHead(modules) ) {
    SDF_Module module = SDF_getModuleListHead(modules);
    productions = SDF_concatProductionList(productions, 
					   SDF_getModuleContextFreeProductions(module));

    if (!SDF_hasModuleListTail(modules)) {
      break;
    }
    else {
      modules = SDF_getModuleListTail(modules);
    }
  }

  return productions;
}

/*}}}  */
/*{{{  static void createMappingToPT(SDF_ProductionList productions) */

static void createMappingToPT(SDF_ProductionList productions)
{
  mapping = ATtableCreate(1024, 75);

  while (SDF_hasProductionListHead(productions)) {
    SDF_Production prod = SDF_getProductionListHead(productions);

    if (SDF_isProductionProd(prod)) {
      PT_Production ptprod = SDFProductionToPtProduction(prod);

      if (ptprod) {
	ATtablePut(mapping, (ATerm) normalizeProduction(ptprod), (ATerm) prod);
      }
    }

    if (!SDF_hasProductionListTail(productions)) {
      break;
    }
    else {
      productions = SDF_getProductionListTail(productions);
    }
  }
}

/*}}}  */

/*{{{  static int calcIndentationLevel(int *i, PT_Tree layout) */

static int calcIndentationLevel(int indent, PT_Tree layout)
{
  int i;
  int len = PT_getTreeLength(layout);
  char *str = PT_yieldTree(layout);

  for (i=len; i >= 0 && str[i] != '\n'; i--);

  return indent + (len - i) - 1;
}

/*}}}  */
/*{{{  static PT_Tree createLayoutTree(int *indent, PT_Tree layout) */

static PT_Tree createLayoutTree(int indent, PT_Tree layout)
{
  int i,j,k;
  int len = PT_getTreeLength(layout);
  char *str = PT_yieldTree(layout);
  PT_Tree result = NULL;


  /* after every new line a amount of 'indent' spaces should be inserted */
  for (i=0, j=0; i < len; i++, j++) {
    assert(j < MAX_LAYOUT_LENGTH && "Maximum length of layout exceeded");
    layout_buffer[j] = str[i];

    if (str[i] == '\n') {
      for(k=0; k < indent; k++) {
	layout_buffer[++j] = DEFAULT_LAYOUT_CHARACTER;
      }
    }
  }
  layout_buffer[j] = '\0';

  result = PT_makeTreeLayoutFromString(layout_buffer);

  return result;
}

/*}}}  */

/*{{{  static PT_Tree pList(PT_Tree tree, SDF_Symbol ssym) */

static PT_Tree pList(PT_Tree tree, int *i, SDF_Symbol ssym)
{
  PT_Tree layout;
  PT_Args elems;
  PT_Args newElems;
  ATbool  isLayout;
  int indent = *i;


  assert(PT_isTreeApplList(tree) && "This tool only supports AsFix2ME");
  assert(SDF_isSymbolIterStar(ssym) || SDF_isSymbolIter(ssym));

  layout = (PT_Tree) SDF_getSymbolWsAfterSymbol(ssym);
  elems  = PT_getTreeArgs(tree);
  newElems = PT_makeArgsEmpty();

  isLayout = ATfalse;
  for (; !PT_isArgsEmpty(elems); elems = PT_getArgsTail(elems)) {
    PT_Tree head = PT_getArgsHead(elems);

    if (isLayout) {
      newElems = PT_makeArgsList(createLayoutTree(*i, layout), newElems);
      *i = calcIndentationLevel(*i, layout);
    }
    else {
      newElems = PT_makeArgsList(pTree(head, i), newElems);
    }

    isLayout = !isLayout;
    *i = indent;
  }

  return PT_setTreeArgs(tree, PT_reverseArgs(newElems));
}

/*}}}  */
/*{{{  static PT_Tree pSepList(PT_Tree tree, SDF_Symbol ssym) */

static PT_Tree pSepList(PT_Tree tree, int *i, SDF_Symbol ssym)
{
  PT_Tree layout;
  PT_Tree layout2;
  PT_Args elems;
  PT_Args newElems;
  ATbool  isFirstLayout;
  ATbool  isLayout;
  int indent = *i;

  assert(PT_isTreeApplList(tree) && 
	 (SDF_isSymbolIterStarSep(ssym) || SDF_isSymbolIterSep(ssym)));

  layout = (PT_Tree) SDF_getSymbolWsAfterSymbol(ssym);
  layout2 = (PT_Tree) SDF_getSymbolWsAfterSep(ssym);

  elems  = PT_getTreeArgs(tree);
  newElems = PT_makeArgsEmpty();

  isLayout  = ATfalse;
  isFirstLayout = ATtrue;

  for (; !PT_isArgsEmpty(elems); elems = PT_getArgsTail(elems)) {
    PT_Tree head = PT_getArgsHead(elems);

    if (isLayout) {
      if (isFirstLayout) {
	newElems = PT_makeArgsList(createLayoutTree(*i,layout), newElems);
	*i = calcIndentationLevel(*i, layout);
      }
      else {
	newElems = PT_makeArgsList(createLayoutTree(*i,layout2), newElems);
	*i = calcIndentationLevel(*i, layout2);
      }
    }
    else {
      newElems = PT_makeArgsList(pTree(head, i), newElems);
    }

    if (isLayout) {
      isFirstLayout = !isFirstLayout;
    }
    isLayout = !isLayout;
    *i = indent;
  }

  return PT_setTreeArgs(tree, PT_reverseArgs(newElems));
}

/*}}}  */
/*{{{  static PT_Tree pTreeWithSymbol(PT_Tree tree, PT_Symbol sym, SDF_Symbol ssym) */

static PT_Tree pTreeWithSymbol(PT_Tree tree, int *i, PT_Symbol sym, SDF_Symbol ssym)
{
  if (PT_isSymbolSort(sym)) {
    return pTree(tree, i);
  }
  else if (PT_isSymbolLit(sym)) {
    return tree;
  }
  else if (PT_isSymbolIterStar(sym) || PT_isSymbolIterPlus(sym)) {
    return pList(tree, i, ssym);
  }
  else if (PT_isSymbolIterStarSep(sym) || PT_isSymbolIterPlusSep(sym)) {
    return pSepList(tree, i, ssym);
  }

  /* the rest is handled by doing nothing */
  if (PT_hasTreeArgs(tree)) {
    return PT_setTreeArgs(tree, pArgs(PT_getTreeArgs(tree), i));
  }
  else {
    return tree;
  }
}

/*}}}  */

/*{{{  static PT_Args pArgs(PT_Args args) */

static PT_Args pArgs(PT_Args args, int *i)
{
  int indent = *i;
  PT_Args newArgs = PT_makeArgsEmpty();

  for(; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree head = PT_getArgsHead(args);
    newArgs = PT_makeArgsList(pTree(head, i), newArgs);
    *i = indent;
  }

  return PT_reverseArgs(newArgs);
}

/*}}}  */
/*{{{  static PT_Tree pAppl(PT_Tree tree) */

static PT_Tree pAppl(PT_Tree tree, int *i)
{
  int indent = *i;
  PT_Args args = PT_getTreeArgs(tree);
  PT_Production prod = PT_getTreeProd(tree);
  SDF_Production sprod = (SDF_Production) ATtableGet(mapping, (ATerm) prod);

  if (sprod != NULL) {
    PT_Args newArgs = PT_makeArgsEmpty();
    SDF_SymbolList slhs = SDF_getSymbolsList(SDF_getProductionSymbols(sprod));
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Tree nextLayout = NULL;

    for (; !PT_isArgsEmpty(args); args = PT_getArgsTail(args), lhs = PT_getSymbolsTail(lhs)) {
      PT_Tree head = PT_getArgsHead(args);
      PT_Symbol sym = PT_getSymbolsHead(lhs);

      // here we put in the layout that's in between the symbols on the lhs
      if (PT_isOptLayoutSymbol(sym)) {
	assert(nextLayout != NULL);
	newArgs = PT_makeArgsList(createLayoutTree(indent, nextLayout), newArgs);
	*i = calcIndentationLevel(indent, nextLayout);
	nextLayout = NULL;
      }
      else {
	SDF_Symbol ssym = SDF_getSymbolListHead(slhs);
	PT_Symbol real = PT_getSymbolSymbol(sym);

	newArgs = PT_makeArgsList(pTreeWithSymbol(head, i, real, ssym), newArgs);

	if (SDF_hasSymbolListTail(slhs)) {
	  nextLayout = (PT_Tree) SDF_getSymbolListWsAfterFirst(slhs);
	  slhs = SDF_getSymbolListTail(slhs);
	}
      }
    }

    tree = PT_setTreeArgs(tree, PT_reverseArgs(newArgs));
  }
  else {
    tree = PT_setTreeArgs(tree, pArgs(args, i));
  }

  return tree;
}

/*}}}  */
/*{{{  static PT_Tree pAmb(PT_Tree tree)  */

static PT_Tree pAmb(PT_Tree tree, int *i) 
{
  PT_Args args = PT_getTreeArgs(tree);
  return PT_setTreeArgs(tree, pArgs(args, i));
}

/*}}}  */
/*{{{  static PT_Tree pTree(PT_Tree tree) */

static PT_Tree pTree(PT_Tree tree, int *i)
{
  if (PT_isTreeAmb(tree)) {
    return pAmb(tree, i);
  }
  else if (PT_isTreeAppl(tree)) {
    return pAppl(tree, i);
  }
  else {
    return tree;
  }
}

/*}}}  */
/*{{{  static PT_ParseTree pParseTree(PT_ParseTree parsetree) */

static PT_ParseTree pParseTree(PT_ParseTree parsetree)
{
  int indent = 0;
  PT_Tree tree = PT_getParseTreeTree(parsetree);
  return PT_setParseTreeTree(parsetree, pTree(tree, &indent));
}

/*}}}  */

/*{{{  PT_ParseTree pretty(SDF_SDF syntax, PT_ParseTree parsetree) */

PT_ParseTree pretty(SDF_SDF syntax, PT_ParseTree parsetree)
{
  SDF_ProductionList productions = collectProductions(syntax);
  createMappingToPT(productions);

  return pParseTree(parsetree);
}

/*}}}  */
