#include <aterm2.h>
#include <deprecated.h>
#include "PT.h"

/*{{{  typedefs */

typedef struct ATerm _PT_ParseTree;
typedef struct ATerm _PT_ModuleName;
typedef struct ATerm _PT_Tree;
typedef struct ATerm _PT_Production;
typedef struct ATerm _PT_Attributes;
typedef struct ATerm _PT_Attrs;
typedef struct ATerm _PT_Attr;
typedef struct ATerm _PT_Symbol;
typedef struct ATerm _PT_Args;
typedef struct ATerm _PT_Symbols;

/*}}}  */

/*{{{  void PT_initPTApi(void) */

void PT_initPTApi(void)
{
  init_PT_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  PT_ParseTree PT_makeParseTreeFromTerm(ATerm t) */

PT_ParseTree PT_makeParseTreeFromTerm(ATerm t)
{
  return (PT_ParseTree)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromParseTree(PT_ParseTree arg) */

ATerm PT_makeTermFromParseTree(PT_ParseTree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_ModuleName PT_makeModuleNameFromTerm(ATerm t) */

PT_ModuleName PT_makeModuleNameFromTerm(ATerm t)
{
  return (PT_ModuleName)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromModuleName(PT_ModuleName arg) */

ATerm PT_makeTermFromModuleName(PT_ModuleName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeFromTerm(ATerm t) */

PT_Tree PT_makeTreeFromTerm(ATerm t)
{
  return (PT_Tree)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromTree(PT_Tree arg) */

ATerm PT_makeTermFromTree(PT_Tree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Production PT_makeProductionFromTerm(ATerm t) */

PT_Production PT_makeProductionFromTerm(ATerm t)
{
  return (PT_Production)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromProduction(PT_Production arg) */

ATerm PT_makeTermFromProduction(PT_Production arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Attributes PT_makeAttributesFromTerm(ATerm t) */

PT_Attributes PT_makeAttributesFromTerm(ATerm t)
{
  return (PT_Attributes)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromAttributes(PT_Attributes arg) */

ATerm PT_makeTermFromAttributes(PT_Attributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Attrs PT_makeAttrsFromTerm(ATerm t) */

PT_Attrs PT_makeAttrsFromTerm(ATerm t)
{
  return (PT_Attrs)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromAttrs(PT_Attrs arg) */

ATerm PT_makeTermFromAttrs(PT_Attrs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrFromTerm(ATerm t) */

PT_Attr PT_makeAttrFromTerm(ATerm t)
{
  return (PT_Attr)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromAttr(PT_Attr arg) */

ATerm PT_makeTermFromAttr(PT_Attr arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolFromTerm(ATerm t) */

PT_Symbol PT_makeSymbolFromTerm(ATerm t)
{
  return (PT_Symbol)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromSymbol(PT_Symbol arg) */

ATerm PT_makeTermFromSymbol(PT_Symbol arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Args PT_makeArgsFromTerm(ATerm t) */

PT_Args PT_makeArgsFromTerm(ATerm t)
{
  return (PT_Args)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromArgs(PT_Args arg) */

ATerm PT_makeTermFromArgs(PT_Args arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Symbols PT_makeSymbolsFromTerm(ATerm t) */

PT_Symbols PT_makeSymbolsFromTerm(ATerm t)
{
  return (PT_Symbols)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromSymbols(PT_Symbols arg) */

ATerm PT_makeTermFromSymbols(PT_Symbols arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  PT_ParseTree PT_makeParseTreeTree(char * layoutBeforeTree, PT_Tree tree, char * layoutAfterTree) */

PT_ParseTree PT_makeParseTreeTree(char * layoutBeforeTree, PT_Tree tree, char * layoutAfterTree)
{
  return (PT_ParseTree)ATmakeTerm(PT_patternParseTreeTree, layoutBeforeTree, tree, layoutAfterTree);
}

/*}}}  */
/*{{{  PT_ModuleName PT_makeModuleNameDefault(char * id) */

PT_ModuleName PT_makeModuleNameDefault(char * id)
{
  return (PT_ModuleName)ATmakeTerm(PT_patternModuleNameDefault, id);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args) */

PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeAppl, prod, args);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeList(PT_Symbol iter, PT_Args args) */

PT_Tree PT_makeTreeList(PT_Symbol iter, PT_Args args)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeList, iter, args);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLexical(char * string, PT_Symbol symbol) */

PT_Tree PT_makeTreeLexical(char * string, PT_Symbol symbol)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeLexical, string, symbol);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeUnquotedLiteral(char * string) */

PT_Tree PT_makeTreeUnquotedLiteral(char * string)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeUnquotedLiteral, string);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeQuotedLiteral(char * string) */

PT_Tree PT_makeTreeQuotedLiteral(char * string)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeQuotedLiteral, string);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeSeparator(char * string) */

PT_Tree PT_makeTreeSeparator(char * string)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeSeparator, string);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLayout(char * string) */

PT_Tree PT_makeTreeLayout(char * string)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeLayout, string);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeVar(char * string, PT_Symbol symbol) */

PT_Tree PT_makeTreeVar(char * string, PT_Symbol symbol)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeVar, string, symbol);
}

/*}}}  */
/*{{{  PT_Production PT_makeProductionDefault(char * moduleName, PT_Symbols lhs, PT_Symbol rhs, PT_Attributes attributes) */

PT_Production PT_makeProductionDefault(char * moduleName, PT_Symbols lhs, PT_Symbol rhs, PT_Attributes attributes)
{
  return (PT_Production)ATmakeTerm(PT_patternProductionDefault, moduleName, lhs, rhs, attributes);
}

/*}}}  */
/*{{{  PT_Attributes PT_makeAttributesNoAttrs() */

PT_Attributes PT_makeAttributesNoAttrs()
{
  return (PT_Attributes)ATmakeTerm(PT_patternAttributesNoAttrs);
}

/*}}}  */
/*{{{  PT_Attributes PT_makeAttributesAttrs(PT_Attrs attrs) */

PT_Attributes PT_makeAttributesAttrs(PT_Attrs attrs)
{
  return (PT_Attributes)ATmakeTerm(PT_patternAttributesAttrs, attrs);
}

/*}}}  */
/*{{{  PT_Attrs PT_makeAttrsMany(PT_Attr head, PT_Attrs tail) */

PT_Attrs PT_makeAttrsMany(PT_Attr head, PT_Attrs tail)
{
  return (PT_Attrs)ATmakeTerm(PT_patternAttrsMany, head, tail);
}

/*}}}  */
/*{{{  PT_Attrs PT_makeAttrsSingle(PT_Attr head) */

PT_Attrs PT_makeAttrsSingle(PT_Attr head)
{
  return (PT_Attrs)ATmakeTerm(PT_patternAttrsSingle, head);
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrCons(char * string) */

PT_Attr PT_makeAttrCons(char * string)
{
  return (PT_Attr)ATmakeTerm(PT_patternAttrCons, string);
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrBracket() */

PT_Attr PT_makeAttrBracket()
{
  return (PT_Attr)ATmakeTerm(PT_patternAttrBracket);
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrTraverse() */

PT_Attr PT_makeAttrTraverse()
{
  return (PT_Attr)ATmakeTerm(PT_patternAttrTraverse);
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrMemo() */

PT_Attr PT_makeAttrMemo()
{
  return (PT_Attr)ATmakeTerm(PT_patternAttrMemo);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterStar(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolIterStar(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterStar, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterPlus(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolIterPlus(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterPlus, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterStarSep(PT_Symbol symbol, char * separator) */

PT_Symbol PT_makeSymbolIterStarSep(PT_Symbol symbol, char * separator)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterStarSep, symbol, separator);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterPlusSep(PT_Symbol symbol, char * separator) */

PT_Symbol PT_makeSymbolIterPlusSep(PT_Symbol symbol, char * separator)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterPlusSep, symbol, separator);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolEmptyLayout() */

PT_Symbol PT_makeSymbolEmptyLayout()
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolEmptyLayout);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolSort(char * string) */

PT_Symbol PT_makeSymbolSort(char * string)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolSort, string);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolUnquotedLiteral(char * string) */

PT_Symbol PT_makeSymbolUnquotedLiteral(char * string)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolUnquotedLiteral, string);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolQuotedLiteral(char * string) */

PT_Symbol PT_makeSymbolQuotedLiteral(char * string)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolQuotedLiteral, string);
}

/*}}}  */
/*{{{  PT_Args PT_makeArgsList(PT_Tree head, PT_Args tail) */

PT_Args PT_makeArgsList(PT_Tree head, PT_Args tail)
{
  return (PT_Args)ATmakeTerm(PT_patternArgsList, head, tail);
}

/*}}}  */
/*{{{  PT_Args PT_makeArgsEmpty() */

PT_Args PT_makeArgsEmpty()
{
  return (PT_Args)ATmakeTerm(PT_patternArgsEmpty);
}

/*}}}  */
/*{{{  PT_Symbols PT_makeSymbolsList(PT_Symbol head, PT_Symbols tail) */

PT_Symbols PT_makeSymbolsList(PT_Symbol head, PT_Symbols tail)
{
  return (PT_Symbols)ATmakeTerm(PT_patternSymbolsList, head, tail);
}

/*}}}  */
/*{{{  PT_Symbols PT_makeSymbolsEmpty() */

PT_Symbols PT_makeSymbolsEmpty()
{
  return (PT_Symbols)ATmakeTerm(PT_patternSymbolsEmpty);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PT_isEqualParseTree(PT_ParseTree arg0, PT_ParseTree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualModuleName(PT_ModuleName arg0, PT_ModuleName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualTree(PT_Tree arg0, PT_Tree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualProduction(PT_Production arg0, PT_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualAttributes(PT_Attributes arg0, PT_Attributes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualAttrs(PT_Attrs arg0, PT_Attrs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualAttr(PT_Attr arg0, PT_Attr arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualSymbol(PT_Symbol arg0, PT_Symbol arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualArgs(PT_Args arg0, PT_Args arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualSymbols(PT_Symbols arg0, PT_Symbols arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PT_ParseTree accessors */

/*{{{  ATbool PT_isValidParseTree(PT_ParseTree arg) */

ATbool PT_isValidParseTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isParseTreeTree(PT_ParseTree arg) */

ATbool PT_isParseTreeTree(PT_ParseTree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternParseTreeTree, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeLayoutBeforeTree(PT_ParseTree arg) */

ATbool PT_hasParseTreeLayoutBeforeTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getParseTreeLayoutBeforeTree(PT_ParseTree arg) */

char * PT_getParseTreeLayoutBeforeTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 5), 0)));
  }

  ATabort("ParseTree has no LayoutBeforeTree: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree arg, char * layoutBeforeTree) */

PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree arg, char * layoutBeforeTree)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 5), (ATerm)ATmakeAppl0(ATmakeAFun(layoutBeforeTree, 0, ATtrue)), 0), 5);
  }

  ATabort("ParseTree has no LayoutBeforeTree: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeTree(PT_ParseTree arg) */

ATbool PT_hasParseTreeTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getParseTreeTree(PT_ParseTree arg) */

PT_Tree PT_getParseTreeTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Tree)ATgetArgument((ATermAppl)arg, 6);
  }

  ATabort("ParseTree has no Tree: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeTree(PT_ParseTree arg, PT_Tree tree) */

PT_ParseTree PT_setParseTreeTree(PT_ParseTree arg, PT_Tree tree)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)tree, 6);
  }

  ATabort("ParseTree has no Tree: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeLayoutAfterTree(PT_ParseTree arg) */

ATbool PT_hasParseTreeLayoutAfterTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getParseTreeLayoutAfterTree(PT_ParseTree arg) */

char * PT_getParseTreeLayoutAfterTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 7), 0)));
  }

  ATabort("ParseTree has no LayoutAfterTree: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeLayoutAfterTree(PT_ParseTree arg, char * layoutAfterTree) */

PT_ParseTree PT_setParseTreeLayoutAfterTree(PT_ParseTree arg, char * layoutAfterTree)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 7), (ATerm)ATmakeAppl0(ATmakeAFun(layoutAfterTree, 0, ATtrue)), 0), 7);
  }

  ATabort("ParseTree has no LayoutAfterTree: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_ModuleName accessors */

/*{{{  ATbool PT_isValidModuleName(PT_ModuleName arg) */

ATbool PT_isValidModuleName(PT_ModuleName arg)
{
  if (PT_isModuleNameDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isModuleNameDefault(PT_ModuleName arg) */

ATbool PT_isModuleNameDefault(PT_ModuleName arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternModuleNameDefault, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasModuleNameId(PT_ModuleName arg) */

ATbool PT_hasModuleNameId(PT_ModuleName arg)
{
  if (PT_isModuleNameDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getModuleNameId(PT_ModuleName arg) */

char * PT_getModuleNameId(PT_ModuleName arg)
{
  if (PT_isModuleNameDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("ModuleName has no Id: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, char * id) */

PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, char * id)
{
  if (PT_isModuleNameDefault(arg)) {
    return (PT_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), 0);
  }

  ATabort("ModuleName has no Id: %t\n", arg);
  return (PT_ModuleName)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Tree accessors */

/*{{{  ATbool PT_isValidTree(PT_Tree arg) */

ATbool PT_isValidTree(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeList(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeLexical(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeUnquotedLiteral(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeQuotedLiteral(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeSeparator(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeLayout(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeVar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeAppl(PT_Tree arg) */

ATbool PT_isTreeAppl(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeAppl, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeList(PT_Tree arg) */

ATbool PT_isTreeList(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeList, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeLexical(PT_Tree arg) */

ATbool PT_isTreeLexical(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeLexical, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeUnquotedLiteral(PT_Tree arg) */

ATbool PT_isTreeUnquotedLiteral(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeUnquotedLiteral, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeQuotedLiteral(PT_Tree arg) */

ATbool PT_isTreeQuotedLiteral(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeQuotedLiteral, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeSeparator(PT_Tree arg) */

ATbool PT_isTreeSeparator(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeSeparator, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeLayout(PT_Tree arg) */

ATbool PT_isTreeLayout(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeLayout, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeVar(PT_Tree arg) */

ATbool PT_isTreeVar(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeVar, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasTreeProd(PT_Tree arg) */

ATbool PT_hasTreeProd(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Production PT_getTreeProd(PT_Tree arg) */

PT_Production PT_getTreeProd(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Production)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Tree has no Prod: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod) */

PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)prod, 0);
  }

  ATabort("Tree has no Prod: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeArgs(PT_Tree arg) */

ATbool PT_hasTreeArgs(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Args PT_getTreeArgs(PT_Tree arg) */

PT_Args PT_getTreeArgs(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Args)ATgetArgument((ATermAppl)arg, 2);
  }
  else if (PT_isTreeList(arg)) {
    return (PT_Args)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Tree has no Args: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args) */

PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)args, 2);
  }
  else if (PT_isTreeList(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)args, 2);
  }

  ATabort("Tree has no Args: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeIter(PT_Tree arg) */

ATbool PT_hasTreeIter(PT_Tree arg)
{
  if (PT_isTreeList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getTreeIter(PT_Tree arg) */

PT_Symbol PT_getTreeIter(PT_Tree arg)
{
  if (PT_isTreeList(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Tree has no Iter: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeIter(PT_Tree arg, PT_Symbol iter) */

PT_Tree PT_setTreeIter(PT_Tree arg, PT_Symbol iter)
{
  if (PT_isTreeList(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)iter, 0);
  }

  ATabort("Tree has no Iter: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeString(PT_Tree arg) */

ATbool PT_hasTreeString(PT_Tree arg)
{
  if (PT_isTreeLexical(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeUnquotedLiteral(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeQuotedLiteral(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeSeparator(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeLayout(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeVar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getTreeString(PT_Tree arg) */

char * PT_getTreeString(PT_Tree arg)
{
  if (PT_isTreeLexical(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isTreeUnquotedLiteral(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isTreeQuotedLiteral(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isTreeSeparator(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isTreeLayout(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isTreeVar(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Tree has no String: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeString(PT_Tree arg, char * string) */

PT_Tree PT_setTreeString(PT_Tree arg, char * string)
{
  if (PT_isTreeLexical(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isTreeUnquotedLiteral(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isTreeQuotedLiteral(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isTreeSeparator(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isTreeLayout(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isTreeVar(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }

  ATabort("Tree has no String: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeSymbol(PT_Tree arg) */

ATbool PT_hasTreeSymbol(PT_Tree arg)
{
  if (PT_isTreeLexical(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeVar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getTreeSymbol(PT_Tree arg) */

PT_Symbol PT_getTreeSymbol(PT_Tree arg)
{
  if (PT_isTreeLexical(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (PT_isTreeVar(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }

  ATabort("Tree has no Symbol: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeSymbol(PT_Tree arg, PT_Symbol symbol) */

PT_Tree PT_setTreeSymbol(PT_Tree arg, PT_Symbol symbol)
{
  if (PT_isTreeLexical(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 1);
  }
  else if (PT_isTreeVar(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 1);
  }

  ATabort("Tree has no Symbol: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Production accessors */

/*{{{  ATbool PT_isValidProduction(PT_Production arg) */

ATbool PT_isValidProduction(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isProductionDefault(PT_Production arg) */

ATbool PT_isProductionDefault(PT_Production arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternProductionDefault, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasProductionModuleName(PT_Production arg) */

ATbool PT_hasProductionModuleName(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getProductionModuleName(PT_Production arg) */

char * PT_getProductionModuleName(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0)));
  }

  ATabort("Production has no ModuleName: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionModuleName(PT_Production arg, char * moduleName) */

PT_Production PT_setProductionModuleName(PT_Production arg, char * moduleName)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATmakeAppl0(ATmakeAFun(moduleName, 0, ATtrue)), 0), 0);
  }

  ATabort("Production has no ModuleName: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionLhs(PT_Production arg) */

ATbool PT_hasProductionLhs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbols PT_getProductionLhs(PT_Production arg) */

PT_Symbols PT_getProductionLhs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Symbols)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Production has no Lhs: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs) */

PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)lhs, 2);
  }

  ATabort("Production has no Lhs: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionRhs(PT_Production arg) */

ATbool PT_hasProductionRhs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getProductionRhs(PT_Production arg) */

PT_Symbol PT_getProductionRhs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 6);
  }

  ATabort("Production has no Rhs: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs) */

PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)rhs, 6);
  }

  ATabort("Production has no Rhs: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionAttributes(PT_Production arg) */

ATbool PT_hasProductionAttributes(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attributes PT_getProductionAttributes(PT_Production arg) */

PT_Attributes PT_getProductionAttributes(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Attributes)ATgetArgument((ATermAppl)arg, 8);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return (PT_Attributes)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionAttributes(PT_Production arg, PT_Attributes attributes) */

PT_Production PT_setProductionAttributes(PT_Production arg, PT_Attributes attributes)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)attributes, 8);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Attributes accessors */

/*{{{  ATbool PT_isValidAttributes(PT_Attributes arg) */

ATbool PT_isValidAttributes(PT_Attributes arg)
{
  if (PT_isAttributesNoAttrs(arg)) {
    return ATtrue;
  }
  else if (PT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isAttributesNoAttrs(PT_Attributes arg) */

ATbool PT_isAttributesNoAttrs(PT_Attributes arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttributesNoAttrs);
}

/*}}}  */
/*{{{  ATbool PT_isAttributesAttrs(PT_Attributes arg) */

ATbool PT_isAttributesAttrs(PT_Attributes arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttributesAttrs, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasAttributesAttrs(PT_Attributes arg) */

ATbool PT_hasAttributesAttrs(PT_Attributes arg)
{
  if (PT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attrs PT_getAttributesAttrs(PT_Attributes arg) */

PT_Attrs PT_getAttributesAttrs(PT_Attributes arg)
{
  if (PT_isAttributesAttrs(arg)) {
    return (PT_Attrs)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Attributes has no Attrs: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */
/*{{{  PT_Attributes PT_setAttributesAttrs(PT_Attributes arg, PT_Attrs attrs) */

PT_Attributes PT_setAttributesAttrs(PT_Attributes arg, PT_Attrs attrs)
{
  if (PT_isAttributesAttrs(arg)) {
    return (PT_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)attrs, 2);
  }

  ATabort("Attributes has no Attrs: %t\n", arg);
  return (PT_Attributes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Attrs accessors */

/*{{{  ATbool PT_isValidAttrs(PT_Attrs arg) */

ATbool PT_isValidAttrs(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrsSingle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isAttrsMany(PT_Attrs arg) */

ATbool PT_isAttrsMany(PT_Attrs arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrsMany, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isAttrsSingle(PT_Attrs arg) */

ATbool PT_isAttrsSingle(PT_Attrs arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasAttrsHead(PT_Attrs arg) */

ATbool PT_hasAttrsHead(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrsSingle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attr PT_getAttrsHead(PT_Attrs arg) */

PT_Attr PT_getAttrsHead(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return (PT_Attr)ATelementAt((ATermList)arg, 0);
  }
  else if (PT_isAttrsSingle(arg)) {
    return (PT_Attr)ATelementAt((ATermList)arg, 0);
  }

  ATabort("Attrs has no Head: %t\n", arg);
  return (PT_Attr)NULL;
}

/*}}}  */
/*{{{  PT_Attrs PT_setAttrsHead(PT_Attrs arg, PT_Attr head) */

PT_Attrs PT_setAttrsHead(PT_Attrs arg, PT_Attr head)
{
  if (PT_isAttrsMany(arg)) {
    return (PT_Attrs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (PT_isAttrsSingle(arg)) {
    return (PT_Attrs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Attrs has no Head: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAttrsTail(PT_Attrs arg) */

ATbool PT_hasAttrsTail(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attrs PT_getAttrsTail(PT_Attrs arg) */

PT_Attrs PT_getAttrsTail(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return (PT_Attrs)ATgetTail((ATermList)arg, 4);
  }

  ATabort("Attrs has no Tail: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */
/*{{{  PT_Attrs PT_setAttrsTail(PT_Attrs arg, PT_Attrs tail) */

PT_Attrs PT_setAttrsTail(PT_Attrs arg, PT_Attrs tail)
{
  if (PT_isAttrsMany(arg)) {
    return (PT_Attrs)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("Attrs has no Tail: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Attr accessors */

/*{{{  ATbool PT_isValidAttr(PT_Attr arg) */

ATbool PT_isValidAttr(PT_Attr arg)
{
  if (PT_isAttrCons(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrBracket(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrTraverse(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrMemo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isAttrCons(PT_Attr arg) */

ATbool PT_isAttrCons(PT_Attr arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrCons, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isAttrBracket(PT_Attr arg) */

ATbool PT_isAttrBracket(PT_Attr arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrBracket);
}

/*}}}  */
/*{{{  ATbool PT_isAttrTraverse(PT_Attr arg) */

ATbool PT_isAttrTraverse(PT_Attr arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrTraverse);
}

/*}}}  */
/*{{{  ATbool PT_isAttrMemo(PT_Attr arg) */

ATbool PT_isAttrMemo(PT_Attr arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrMemo);
}

/*}}}  */
/*{{{  ATbool PT_hasAttrString(PT_Attr arg) */

ATbool PT_hasAttrString(PT_Attr arg)
{
  if (PT_isAttrCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getAttrString(PT_Attr arg) */

char * PT_getAttrString(PT_Attr arg)
{
  if (PT_isAttrCons(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Attr has no String: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Attr PT_setAttrString(PT_Attr arg, char * string) */

PT_Attr PT_setAttrString(PT_Attr arg, char * string)
{
  if (PT_isAttrCons(arg)) {
    return (PT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }

  ATabort("Attr has no String: %t\n", arg);
  return (PT_Attr)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Symbol accessors */

/*{{{  ATbool PT_isValidSymbol(PT_Symbol arg) */

ATbool PT_isValidSymbol(PT_Symbol arg)
{
  if (PT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlus(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolEmptyLayout(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolUnquotedLiteral(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolQuotedLiteral(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterStar(PT_Symbol arg) */

ATbool PT_isSymbolIterStar(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterStar, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterPlus(PT_Symbol arg) */

ATbool PT_isSymbolIterPlus(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterPlus, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterStarSep(PT_Symbol arg) */

ATbool PT_isSymbolIterStarSep(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterStarSep, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterPlusSep(PT_Symbol arg) */

ATbool PT_isSymbolIterPlusSep(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterPlusSep, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolEmptyLayout(PT_Symbol arg) */

ATbool PT_isSymbolEmptyLayout(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolEmptyLayout);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolSort(PT_Symbol arg) */

ATbool PT_isSymbolSort(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolSort, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolUnquotedLiteral(PT_Symbol arg) */

ATbool PT_isSymbolUnquotedLiteral(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolUnquotedLiteral, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolQuotedLiteral(PT_Symbol arg) */

ATbool PT_isSymbolQuotedLiteral(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolQuotedLiteral, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolSymbol(PT_Symbol arg) */

ATbool PT_hasSymbolSymbol(PT_Symbol arg)
{
  if (PT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlus(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getSymbolSymbol(PT_Symbol arg) */

PT_Symbol PT_getSymbolSymbol(PT_Symbol arg)
{
  if (PT_isSymbolIterStar(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolIterPlus(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 2);
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolSymbol(PT_Symbol arg, PT_Symbol symbol) */

PT_Symbol PT_setSymbolSymbol(PT_Symbol arg, PT_Symbol symbol)
{
  if (PT_isSymbolIterStar(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolIterPlus(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 2);
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 2);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolSeparator(PT_Symbol arg) */

ATbool PT_hasSymbolSeparator(PT_Symbol arg)
{
  if (PT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getSymbolSeparator(PT_Symbol arg) */

char * PT_getSymbolSeparator(PT_Symbol arg)
{
  if (PT_isSymbolIterStarSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), 0)));
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), 0)));
  }

  ATabort("Symbol has no Separator: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolSeparator(PT_Symbol arg, char * separator) */

PT_Symbol PT_setSymbolSeparator(PT_Symbol arg, char * separator)
{
  if (PT_isSymbolIterStarSep(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), (ATerm)ATmakeAppl0(ATmakeAFun(separator, 0, ATtrue)), 0), 4);
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 4), (ATerm)ATmakeAppl0(ATmakeAFun(separator, 0, ATtrue)), 0), 4);
  }

  ATabort("Symbol has no Separator: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolString(PT_Symbol arg) */

ATbool PT_hasSymbolString(PT_Symbol arg)
{
  if (PT_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolUnquotedLiteral(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolQuotedLiteral(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getSymbolString(PT_Symbol arg) */

char * PT_getSymbolString(PT_Symbol arg)
{
  if (PT_isSymbolSort(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isSymbolUnquotedLiteral(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isSymbolQuotedLiteral(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Symbol has no String: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolString(PT_Symbol arg, char * string) */

PT_Symbol PT_setSymbolString(PT_Symbol arg, char * string)
{
  if (PT_isSymbolSort(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isSymbolUnquotedLiteral(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isSymbolQuotedLiteral(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }

  ATabort("Symbol has no String: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Args accessors */

/*{{{  ATbool PT_isValidArgs(PT_Args arg) */

ATbool PT_isValidArgs(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return ATtrue;
  }
  else if (PT_isArgsEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isArgsList(PT_Args arg) */

ATbool PT_isArgsList(PT_Args arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternArgsList, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isArgsEmpty(PT_Args arg) */

ATbool PT_isArgsEmpty(PT_Args arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternArgsEmpty);
}

/*}}}  */
/*{{{  ATbool PT_hasArgsHead(PT_Args arg) */

ATbool PT_hasArgsHead(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getArgsHead(PT_Args arg) */

PT_Tree PT_getArgsHead(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return (PT_Tree)ATelementAt((ATermList)arg, 0);
  }

  ATabort("Args has no Head: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head) */

PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head)
{
  if (PT_isArgsList(arg)) {
    return (PT_Args)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Args has no Head: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasArgsTail(PT_Args arg) */

ATbool PT_hasArgsTail(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Args PT_getArgsTail(PT_Args arg) */

PT_Args PT_getArgsTail(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return (PT_Args)ATgetTail((ATermList)arg, 1);
  }

  ATabort("Args has no Tail: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */
/*{{{  PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail) */

PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail)
{
  if (PT_isArgsList(arg)) {
    return (PT_Args)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Args has no Tail: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Symbols accessors */

/*{{{  ATbool PT_isValidSymbols(PT_Symbols arg) */

ATbool PT_isValidSymbols(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolsEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isSymbolsList(PT_Symbols arg) */

ATbool PT_isSymbolsList(PT_Symbols arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolsList, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolsEmpty(PT_Symbols arg) */

ATbool PT_isSymbolsEmpty(PT_Symbols arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolsEmpty);
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolsHead(PT_Symbols arg) */

ATbool PT_hasSymbolsHead(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getSymbolsHead(PT_Symbols arg) */

PT_Symbol PT_getSymbolsHead(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return (PT_Symbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("Symbols has no Head: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Symbols PT_setSymbolsHead(PT_Symbols arg, PT_Symbol head) */

PT_Symbols PT_setSymbolsHead(PT_Symbols arg, PT_Symbol head)
{
  if (PT_isSymbolsList(arg)) {
    return (PT_Symbols)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Symbols has no Head: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolsTail(PT_Symbols arg) */

ATbool PT_hasSymbolsTail(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbols PT_getSymbolsTail(PT_Symbols arg) */

PT_Symbols PT_getSymbolsTail(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return (PT_Symbols)ATgetTail((ATermList)arg, 1);
  }

  ATabort("Symbols has no Tail: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  PT_Symbols PT_setSymbolsTail(PT_Symbols arg, PT_Symbols tail) */

PT_Symbols PT_setSymbolsTail(PT_Symbols arg, PT_Symbols tail)
{
  if (PT_isSymbolsList(arg)) {
    return (PT_Symbols)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Symbols has no Tail: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  PT_ParseTree PT_visitParseTree(PT_ParseTree arg, char * (*acceptLayoutBeforeTree)(char *), PT_Tree (*acceptTree)(PT_Tree), char * (*acceptLayoutAfterTree)(char *)) */

PT_ParseTree PT_visitParseTree(PT_ParseTree arg, char * (*acceptLayoutBeforeTree)(char *), PT_Tree (*acceptTree)(PT_Tree), char * (*acceptLayoutAfterTree)(char *))
{
  if (PT_isParseTreeTree(arg)) {
    return PT_makeParseTreeTree(
        acceptLayoutBeforeTree ? acceptLayoutBeforeTree(PT_getParseTreeLayoutBeforeTree(arg)) : PT_getParseTreeLayoutBeforeTree(arg),
        acceptTree ? acceptTree(PT_getParseTreeTree(arg)) : PT_getParseTreeTree(arg),
        acceptLayoutAfterTree ? acceptLayoutAfterTree(PT_getParseTreeLayoutAfterTree(arg)) : PT_getParseTreeLayoutAfterTree(arg));
  }
  ATabort("not a ParseTree: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PT_ModuleName PT_visitModuleName(PT_ModuleName arg, char * (*acceptId)(char *)) */

PT_ModuleName PT_visitModuleName(PT_ModuleName arg, char * (*acceptId)(char *))
{
  if (PT_isModuleNameDefault(arg)) {
    return PT_makeModuleNameDefault(
        acceptId ? acceptId(PT_getModuleNameId(arg)) : PT_getModuleNameId(arg));
  }
  ATabort("not a ModuleName: %t\n", arg);
  return (PT_ModuleName)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_visitTree(PT_Tree arg, PT_Production (*acceptProd)(PT_Production), PT_Args (*acceptArgs)(PT_Args), PT_Symbol (*acceptIter)(PT_Symbol), char * (*acceptString)(char *), PT_Symbol (*acceptSymbol)(PT_Symbol)) */

PT_Tree PT_visitTree(PT_Tree arg, PT_Production (*acceptProd)(PT_Production), PT_Args (*acceptArgs)(PT_Args), PT_Symbol (*acceptIter)(PT_Symbol), char * (*acceptString)(char *), PT_Symbol (*acceptSymbol)(PT_Symbol))
{
  if (PT_isTreeAppl(arg)) {
    return PT_makeTreeAppl(
        acceptProd ? acceptProd(PT_getTreeProd(arg)) : PT_getTreeProd(arg),
        acceptArgs ? acceptArgs(PT_getTreeArgs(arg)) : PT_getTreeArgs(arg));
  }
  if (PT_isTreeList(arg)) {
    return PT_makeTreeList(
        acceptIter ? acceptIter(PT_getTreeIter(arg)) : PT_getTreeIter(arg),
        acceptArgs ? acceptArgs(PT_getTreeArgs(arg)) : PT_getTreeArgs(arg));
  }
  if (PT_isTreeLexical(arg)) {
    return PT_makeTreeLexical(
        acceptString ? acceptString(PT_getTreeString(arg)) : PT_getTreeString(arg),
        acceptSymbol ? acceptSymbol(PT_getTreeSymbol(arg)) : PT_getTreeSymbol(arg));
  }
  if (PT_isTreeUnquotedLiteral(arg)) {
    return PT_makeTreeUnquotedLiteral(
        acceptString ? acceptString(PT_getTreeString(arg)) : PT_getTreeString(arg));
  }
  if (PT_isTreeQuotedLiteral(arg)) {
    return PT_makeTreeQuotedLiteral(
        acceptString ? acceptString(PT_getTreeString(arg)) : PT_getTreeString(arg));
  }
  if (PT_isTreeSeparator(arg)) {
    return PT_makeTreeSeparator(
        acceptString ? acceptString(PT_getTreeString(arg)) : PT_getTreeString(arg));
  }
  if (PT_isTreeLayout(arg)) {
    return PT_makeTreeLayout(
        acceptString ? acceptString(PT_getTreeString(arg)) : PT_getTreeString(arg));
  }
  if (PT_isTreeVar(arg)) {
    return PT_makeTreeVar(
        acceptString ? acceptString(PT_getTreeString(arg)) : PT_getTreeString(arg),
        acceptSymbol ? acceptSymbol(PT_getTreeSymbol(arg)) : PT_getTreeSymbol(arg));
  }
  ATabort("not a Tree: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_visitProduction(PT_Production arg, char * (*acceptModuleName)(char *), PT_Symbols (*acceptLhs)(PT_Symbols), PT_Symbol (*acceptRhs)(PT_Symbol), PT_Attributes (*acceptAttributes)(PT_Attributes)) */

PT_Production PT_visitProduction(PT_Production arg, char * (*acceptModuleName)(char *), PT_Symbols (*acceptLhs)(PT_Symbols), PT_Symbol (*acceptRhs)(PT_Symbol), PT_Attributes (*acceptAttributes)(PT_Attributes))
{
  if (PT_isProductionDefault(arg)) {
    return PT_makeProductionDefault(
        acceptModuleName ? acceptModuleName(PT_getProductionModuleName(arg)) : PT_getProductionModuleName(arg),
        acceptLhs ? acceptLhs(PT_getProductionLhs(arg)) : PT_getProductionLhs(arg),
        acceptRhs ? acceptRhs(PT_getProductionRhs(arg)) : PT_getProductionRhs(arg),
        acceptAttributes ? acceptAttributes(PT_getProductionAttributes(arg)) : PT_getProductionAttributes(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  PT_Attributes PT_visitAttributes(PT_Attributes arg, PT_Attrs (*acceptAttrs)(PT_Attrs)) */

PT_Attributes PT_visitAttributes(PT_Attributes arg, PT_Attrs (*acceptAttrs)(PT_Attrs))
{
  if (PT_isAttributesNoAttrs(arg)) {
    return PT_makeAttributesNoAttrs();
  }
  if (PT_isAttributesAttrs(arg)) {
    return PT_makeAttributesAttrs(
        acceptAttrs ? acceptAttrs(PT_getAttributesAttrs(arg)) : PT_getAttributesAttrs(arg));
  }
  ATabort("not a Attributes: %t\n", arg);
  return (PT_Attributes)NULL;
}

/*}}}  */
/*{{{  PT_Attrs PT_visitAttrs(PT_Attrs arg, PT_Attr (*acceptHead)(PT_Attr)) */

PT_Attrs PT_visitAttrs(PT_Attrs arg, PT_Attr (*acceptHead)(PT_Attr))
{
  if (PT_isAttrsMany(arg)) {
    return PT_makeAttrsMany(
        acceptHead ? acceptHead(PT_getAttrsHead(arg)) : PT_getAttrsHead(arg),
        PT_visitAttrs(PT_getAttrsTail(arg), acceptHead));
  }
  if (PT_isAttrsSingle(arg)) {
    return PT_makeAttrsSingle(
        acceptHead ? acceptHead(PT_getAttrsHead(arg)) : PT_getAttrsHead(arg));
  }
  ATabort("not a Attrs: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */
/*{{{  PT_Attr PT_visitAttr(PT_Attr arg, char * (*acceptString)(char *)) */

PT_Attr PT_visitAttr(PT_Attr arg, char * (*acceptString)(char *))
{
  if (PT_isAttrCons(arg)) {
    return PT_makeAttrCons(
        acceptString ? acceptString(PT_getAttrString(arg)) : PT_getAttrString(arg));
  }
  if (PT_isAttrBracket(arg)) {
    return PT_makeAttrBracket();
  }
  if (PT_isAttrTraverse(arg)) {
    return PT_makeAttrTraverse();
  }
  if (PT_isAttrMemo(arg)) {
    return PT_makeAttrMemo();
  }
  ATabort("not a Attr: %t\n", arg);
  return (PT_Attr)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_visitSymbol(PT_Symbol arg, char * (*acceptSeparator)(char *), char * (*acceptString)(char *)) */

PT_Symbol PT_visitSymbol(PT_Symbol arg, char * (*acceptSeparator)(char *), char * (*acceptString)(char *))
{
  if (PT_isSymbolIterStar(arg)) {
    return PT_makeSymbolIterStar(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptSeparator, acceptString));
  }
  if (PT_isSymbolIterPlus(arg)) {
    return PT_makeSymbolIterPlus(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptSeparator, acceptString));
  }
  if (PT_isSymbolIterStarSep(arg)) {
    return PT_makeSymbolIterStarSep(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptSeparator, acceptString),
        acceptSeparator ? acceptSeparator(PT_getSymbolSeparator(arg)) : PT_getSymbolSeparator(arg));
  }
  if (PT_isSymbolIterPlusSep(arg)) {
    return PT_makeSymbolIterPlusSep(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptSeparator, acceptString),
        acceptSeparator ? acceptSeparator(PT_getSymbolSeparator(arg)) : PT_getSymbolSeparator(arg));
  }
  if (PT_isSymbolEmptyLayout(arg)) {
    return PT_makeSymbolEmptyLayout();
  }
  if (PT_isSymbolSort(arg)) {
    return PT_makeSymbolSort(
        acceptString ? acceptString(PT_getSymbolString(arg)) : PT_getSymbolString(arg));
  }
  if (PT_isSymbolUnquotedLiteral(arg)) {
    return PT_makeSymbolUnquotedLiteral(
        acceptString ? acceptString(PT_getSymbolString(arg)) : PT_getSymbolString(arg));
  }
  if (PT_isSymbolQuotedLiteral(arg)) {
    return PT_makeSymbolQuotedLiteral(
        acceptString ? acceptString(PT_getSymbolString(arg)) : PT_getSymbolString(arg));
  }
  ATabort("not a Symbol: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Args PT_visitArgs(PT_Args arg, PT_Tree (*acceptHead)(PT_Tree)) */

PT_Args PT_visitArgs(PT_Args arg, PT_Tree (*acceptHead)(PT_Tree))
{
  if (PT_isArgsList(arg)) {
    return PT_makeArgsList(
        acceptHead ? acceptHead(PT_getArgsHead(arg)) : PT_getArgsHead(arg),
        PT_visitArgs(PT_getArgsTail(arg), acceptHead));
  }
  if (PT_isArgsEmpty(arg)) {
    return PT_makeArgsEmpty();
  }
  ATabort("not a Args: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */
/*{{{  PT_Symbols PT_visitSymbols(PT_Symbols arg, PT_Symbol (*acceptHead)(PT_Symbol)) */

PT_Symbols PT_visitSymbols(PT_Symbols arg, PT_Symbol (*acceptHead)(PT_Symbol))
{
  if (PT_isSymbolsList(arg)) {
    return PT_makeSymbolsList(
        acceptHead ? acceptHead(PT_getSymbolsHead(arg)) : PT_getSymbolsHead(arg),
        PT_visitSymbols(PT_getSymbolsTail(arg), acceptHead));
  }
  if (PT_isSymbolsEmpty(arg)) {
    return PT_makeSymbolsEmpty();
  }
  ATabort("not a Symbols: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */

/*}}}  */
