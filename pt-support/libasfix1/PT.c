#include <aterm2.h>
#include <deprecated.h>
#include "PT.h"

/*{{{  typedefs */

typedef struct ATerm _PT_ParseTree;
typedef struct ATerm _PT_ModuleName;
typedef struct ATerm _PT_Tree;
typedef struct ATerm _PT_Var;
typedef struct ATerm _PT_Production;
typedef struct ATerm _PT_Iter;
typedef struct ATerm _PT_Literal;
typedef struct ATerm _PT_QLiteral;
typedef struct ATerm _PT_Lexical;
typedef struct ATerm _PT_Separator;
typedef struct ATerm _PT_Layout;
typedef struct ATerm _PT_Args;

/*}}}  */

/*{{{  void PT_initPTApi(void) */

void PT_initPTApi(void)
{
  init_PT_dict();
}

/*}}}  */

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
/*{{{  PT_Var PT_makeVarFromTerm(ATerm t) */

PT_Var PT_makeVarFromTerm(ATerm t)
{
  return (PT_Var)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromVar(PT_Var arg) */

ATerm PT_makeTermFromVar(PT_Var arg)
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
/*{{{  PT_Iter PT_makeIterFromTerm(ATerm t) */

PT_Iter PT_makeIterFromTerm(ATerm t)
{
  return (PT_Iter)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromIter(PT_Iter arg) */

ATerm PT_makeTermFromIter(PT_Iter arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Literal PT_makeLiteralFromTerm(ATerm t) */

PT_Literal PT_makeLiteralFromTerm(ATerm t)
{
  return (PT_Literal)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromLiteral(PT_Literal arg) */

ATerm PT_makeTermFromLiteral(PT_Literal arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_QLiteral PT_makeQLiteralFromTerm(ATerm t) */

PT_QLiteral PT_makeQLiteralFromTerm(ATerm t)
{
  return (PT_QLiteral)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromQLiteral(PT_QLiteral arg) */

ATerm PT_makeTermFromQLiteral(PT_QLiteral arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Lexical PT_makeLexicalFromTerm(ATerm t) */

PT_Lexical PT_makeLexicalFromTerm(ATerm t)
{
  return (PT_Lexical)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromLexical(PT_Lexical arg) */

ATerm PT_makeTermFromLexical(PT_Lexical arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Separator PT_makeSeparatorFromTerm(ATerm t) */

PT_Separator PT_makeSeparatorFromTerm(ATerm t)
{
  return (PT_Separator)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromSeparator(PT_Separator arg) */

ATerm PT_makeTermFromSeparator(PT_Separator arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Layout PT_makeLayoutFromTerm(ATerm t) */

PT_Layout PT_makeLayoutFromTerm(ATerm t)
{
  return (PT_Layout)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromLayout(PT_Layout arg) */

ATerm PT_makeTermFromLayout(PT_Layout arg)
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

/*{{{  PT_ParseTree PT_makeParseTreeTree(PT_Layout wsAfterTerm, PT_Layout wsAfterPath, PT_ModuleName moduleName, PT_Layout wsAfterModuleName, PT_Tree tree, PT_Layout wsAfterTree) */

PT_ParseTree PT_makeParseTreeTree(PT_Layout wsAfterTerm, PT_Layout wsAfterPath, PT_ModuleName moduleName, PT_Layout wsAfterModuleName, PT_Tree tree, PT_Layout wsAfterTree)
{
  return (PT_ParseTree)ATmakeTerm(PT_patternParseTreeTree, wsAfterTerm, wsAfterPath, moduleName, wsAfterModuleName, tree, wsAfterTree);
}

/*}}}  */
/*{{{  PT_ModuleName PT_makeModuleNameDefault(PT_String id) */

PT_ModuleName PT_makeModuleNameDefault(PT_String id)
{
  return (PT_ModuleName)ATmakeTerm(PT_patternModuleNameDefault, id);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLayout(PT_Layout layout) */

PT_Tree PT_makeTreeLayout(PT_Layout layout)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeLayout, layout);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeVar(PT_Var var) */

PT_Tree PT_makeTreeVar(PT_Var var)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeVar, var);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args) */

PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeAppl, prod, args);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeList(PT_Iter iter, PT_Args elems) */

PT_Tree PT_makeTreeList(PT_Iter iter, PT_Args elems)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeList, iter, elems);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLexical(PT_Lexical lexical) */

PT_Tree PT_makeTreeLexical(PT_Lexical lexical)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeLexical, lexical);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLiteral(PT_Literal literal) */

PT_Tree PT_makeTreeLiteral(PT_Literal literal)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeLiteral, literal);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeQLiteral(PT_QLiteral qliteral) */

PT_Tree PT_makeTreeQLiteral(PT_QLiteral qliteral)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeQLiteral, qliteral);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeSeparator(PT_Separator separator) */

PT_Tree PT_makeTreeSeparator(PT_Separator separator)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeSeparator, separator);
}

/*}}}  */
/*{{{  PT_Var PT_makeVarDefault(PT_String name, PT_Symbol sort) */

PT_Var PT_makeVarDefault(PT_String name, PT_Symbol sort)
{
  return (PT_Var)ATmakeTerm(PT_patternVarDefault, name, sort);
}

/*}}}  */
/*{{{  PT_Production PT_makeProductionDefault(PT_String moduleName, PT_Symbols lhs, PT_Symbol rhs, PT_Attrs attrs) */

PT_Production PT_makeProductionDefault(PT_String moduleName, PT_Symbols lhs, PT_Symbol rhs, PT_Attrs attrs)
{
  return (PT_Production)ATmakeTerm(PT_patternProductionDefault, moduleName, lhs, rhs, attrs);
}

/*}}}  */
/*{{{  PT_Iter PT_makeIterStar(PT_Symbol sort) */

PT_Iter PT_makeIterStar(PT_Symbol sort)
{
  return (PT_Iter)ATmakeTerm(PT_patternIterStar, sort);
}

/*}}}  */
/*{{{  PT_Iter PT_makeIterPlus(PT_Symbol sort) */

PT_Iter PT_makeIterPlus(PT_Symbol sort)
{
  return (PT_Iter)ATmakeTerm(PT_patternIterPlus, sort);
}

/*}}}  */
/*{{{  PT_Iter PT_makeIterSepStar(PT_Symbol sort, PT_Separator separator) */

PT_Iter PT_makeIterSepStar(PT_Symbol sort, PT_Separator separator)
{
  return (PT_Iter)ATmakeTerm(PT_patternIterSepStar, sort, separator);
}

/*}}}  */
/*{{{  PT_Iter PT_makeIterSepPlus(PT_Symbol sort, PT_Separator separator) */

PT_Iter PT_makeIterSepPlus(PT_Symbol sort, PT_Separator separator)
{
  return (PT_Iter)ATmakeTerm(PT_patternIterSepPlus, sort, separator);
}

/*}}}  */
/*{{{  PT_Literal PT_makeLiteralDefault(PT_String chars) */

PT_Literal PT_makeLiteralDefault(PT_String chars)
{
  return (PT_Literal)ATmakeTerm(PT_patternLiteralDefault, chars);
}

/*}}}  */
/*{{{  PT_QLiteral PT_makeQLiteralDefault(PT_String chars) */

PT_QLiteral PT_makeQLiteralDefault(PT_String chars)
{
  return (PT_QLiteral)ATmakeTerm(PT_patternQLiteralDefault, chars);
}

/*}}}  */
/*{{{  PT_Lexical PT_makeLexicalDefault(PT_String chars, PT_Symbol sort) */

PT_Lexical PT_makeLexicalDefault(PT_String chars, PT_Symbol sort)
{
  return (PT_Lexical)ATmakeTerm(PT_patternLexicalDefault, chars, sort);
}

/*}}}  */
/*{{{  PT_Separator PT_makeSeparatorDefault(PT_String chars) */

PT_Separator PT_makeSeparatorDefault(PT_String chars)
{
  return (PT_Separator)ATmakeTerm(PT_patternSeparatorDefault, chars);
}

/*}}}  */
/*{{{  PT_Layout PT_makeLayoutDefault(PT_String chars) */

PT_Layout PT_makeLayoutDefault(PT_String chars)
{
  return (PT_Layout)ATmakeTerm(PT_patternLayoutDefault, chars);
}

/*}}}  */
/*{{{  PT_Args PT_makeArgsDefault(PT_Tree head, PT_Args tail) */

PT_Args PT_makeArgsDefault(PT_Tree head, PT_Args tail)
{
  return (PT_Args)ATmakeTerm(PT_patternArgsDefault, head, tail);
}

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

ATbool PT_isEqualVar(PT_Var arg0, PT_Var arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualProduction(PT_Production arg0, PT_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualIter(PT_Iter arg0, PT_Iter arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualLiteral(PT_Literal arg0, PT_Literal arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualQLiteral(PT_QLiteral arg0, PT_QLiteral arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualLexical(PT_Lexical arg0, PT_Lexical arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualSeparator(PT_Separator arg0, PT_Separator arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualLayout(PT_Layout arg0, PT_Layout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualArgs(PT_Args arg0, PT_Args arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PT_ParseTree accessor implementations */

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
  return ATmatchTerm((ATerm)arg, PT_patternParseTreeTree, NULL, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeWsAfterPath(PT_ParseTree arg) */

ATbool PT_hasParseTreeWsAfterPath(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getParseTreeWsAfterPath(PT_ParseTree arg) */

PT_Layout PT_getParseTreeWsAfterPath(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Layout)ATgetArgument((ATermAppl)arg, 3);
  }

  ATabort("ParseTree has no WsAfterPath: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeWsAfterPath(PT_ParseTree arg, PT_Layout wsAfterPath) */

PT_ParseTree PT_setParseTreeWsAfterPath(PT_ParseTree arg, PT_Layout wsAfterPath)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)wsAfterPath, 3);
  }

  ATabort("ParseTree has no WsAfterPath: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeWsAfterTree(PT_ParseTree arg) */

ATbool PT_hasParseTreeWsAfterTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getParseTreeWsAfterTree(PT_ParseTree arg) */

PT_Layout PT_getParseTreeWsAfterTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Layout)ATgetArgument((ATermAppl)arg, 7);
  }

  ATabort("ParseTree has no WsAfterTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeWsAfterTree(PT_ParseTree arg, PT_Layout wsAfterTree) */

PT_ParseTree PT_setParseTreeWsAfterTree(PT_ParseTree arg, PT_Layout wsAfterTree)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)wsAfterTree, 7);
  }

  ATabort("ParseTree has no WsAfterTree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeWsAfterTerm(PT_ParseTree arg) */

ATbool PT_hasParseTreeWsAfterTerm(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getParseTreeWsAfterTerm(PT_ParseTree arg) */

PT_Layout PT_getParseTreeWsAfterTerm(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Layout)ATgetArgument((ATermAppl)arg, 1);
  }

  ATabort("ParseTree has no WsAfterTerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeWsAfterTerm(PT_ParseTree arg, PT_Layout wsAfterTerm) */

PT_ParseTree PT_setParseTreeWsAfterTerm(PT_ParseTree arg, PT_Layout wsAfterTerm)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)wsAfterTerm, 1);
  }

  ATabort("ParseTree has no WsAfterTerm: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeModuleName(PT_ParseTree arg) */

ATbool PT_hasParseTreeModuleName(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_ModuleName PT_getParseTreeModuleName(PT_ParseTree arg) */

PT_ModuleName PT_getParseTreeModuleName(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ModuleName)ATgetArgument((ATermAppl)arg, 4);
  }

  ATabort("ParseTree has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeModuleName(PT_ParseTree arg, PT_ModuleName moduleName) */

PT_ParseTree PT_setParseTreeModuleName(PT_ParseTree arg, PT_ModuleName moduleName)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)moduleName, 4);
  }

  ATabort("ParseTree has no ModuleName: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeTree(PT_ParseTree arg, PT_Tree tree) */

PT_ParseTree PT_setParseTreeTree(PT_ParseTree arg, PT_Tree tree)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)tree, 6);
  }

  ATabort("ParseTree has no Tree: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeWsAfterModuleName(PT_ParseTree arg) */

ATbool PT_hasParseTreeWsAfterModuleName(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getParseTreeWsAfterModuleName(PT_ParseTree arg) */

PT_Layout PT_getParseTreeWsAfterModuleName(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Layout)ATgetArgument((ATermAppl)arg, 5);
  }

  ATabort("ParseTree has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeWsAfterModuleName(PT_ParseTree arg, PT_Layout wsAfterModuleName) */

PT_ParseTree PT_setParseTreeWsAfterModuleName(PT_ParseTree arg, PT_Layout wsAfterModuleName)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)wsAfterModuleName, 5);
  }

  ATabort("ParseTree has no WsAfterModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_ModuleName accessor implementations */

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
/*{{{  PT_String PT_getModuleNameId(PT_ModuleName arg) */

PT_String PT_getModuleNameId(PT_ModuleName arg)
{
  if (PT_isModuleNameDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("ModuleName has no Id: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, PT_String id) */

PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, PT_String id)
{
  if (PT_isModuleNameDefault(arg)) {
    return (PT_ModuleName)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("ModuleName has no Id: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Tree accessor implementations */

/*{{{  ATbool PT_isValidTree(PT_Tree arg) */

ATbool PT_isValidTree(PT_Tree arg)
{
  if (PT_isTreeLayout(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeVar(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeList(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeLexical(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeLiteral(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeQLiteral(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeSeparator(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
  return ATmatchTerm((ATerm)arg, PT_patternTreeVar, NULL);
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
  return ATmatchTerm((ATerm)arg, PT_patternTreeLexical, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeLiteral(PT_Tree arg) */

ATbool PT_isTreeLiteral(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeLiteral, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeQLiteral(PT_Tree arg) */

ATbool PT_isTreeQLiteral(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeQLiteral, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeSeparator(PT_Tree arg) */

ATbool PT_isTreeSeparator(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeSeparator, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasTreeLexical(PT_Tree arg) */

ATbool PT_hasTreeLexical(PT_Tree arg)
{
  if (PT_isTreeLexical(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Lexical PT_getTreeLexical(PT_Tree arg) */

PT_Lexical PT_getTreeLexical(PT_Tree arg)
{
  if (PT_isTreeLexical(arg)) {
    return (PT_Lexical)arg;
  }

  ATabort("Tree has no Lexical: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeLexical(PT_Tree arg, PT_Lexical lexical) */

PT_Tree PT_setTreeLexical(PT_Tree arg, PT_Lexical lexical)
{
  if (PT_isTreeLexical(arg)) {
    return (PT_Tree)lexical;
  }

  ATabort("Tree has no Lexical: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeSeparator(PT_Tree arg) */

ATbool PT_hasTreeSeparator(PT_Tree arg)
{
  if (PT_isTreeSeparator(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Separator PT_getTreeSeparator(PT_Tree arg) */

PT_Separator PT_getTreeSeparator(PT_Tree arg)
{
  if (PT_isTreeSeparator(arg)) {
    return (PT_Separator)arg;
  }

  ATabort("Tree has no Separator: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeSeparator(PT_Tree arg, PT_Separator separator) */

PT_Tree PT_setTreeSeparator(PT_Tree arg, PT_Separator separator)
{
  if (PT_isTreeSeparator(arg)) {
    return (PT_Tree)separator;
  }

  ATabort("Tree has no Separator: %t\n", arg);
  return NULL;
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
/*{{{  PT_Iter PT_getTreeIter(PT_Tree arg) */

PT_Iter PT_getTreeIter(PT_Tree arg)
{
  if (PT_isTreeList(arg)) {
    return (PT_Iter)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Tree has no Iter: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeIter(PT_Tree arg, PT_Iter iter) */

PT_Tree PT_setTreeIter(PT_Tree arg, PT_Iter iter)
{
  if (PT_isTreeList(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)iter, 0);
  }

  ATabort("Tree has no Iter: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeVar(PT_Tree arg) */

ATbool PT_hasTreeVar(PT_Tree arg)
{
  if (PT_isTreeVar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Var PT_getTreeVar(PT_Tree arg) */

PT_Var PT_getTreeVar(PT_Tree arg)
{
  if (PT_isTreeVar(arg)) {
    return (PT_Var)arg;
  }

  ATabort("Tree has no Var: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeVar(PT_Tree arg, PT_Var var) */

PT_Tree PT_setTreeVar(PT_Tree arg, PT_Var var)
{
  if (PT_isTreeVar(arg)) {
    return (PT_Tree)var;
  }

  ATabort("Tree has no Var: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeArgs(PT_Tree arg) */

ATbool PT_hasTreeArgs(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
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

  ATabort("Tree has no Args: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args) */

PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)args, 2);
  }

  ATabort("Tree has no Args: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeLayout(PT_Tree arg) */

ATbool PT_hasTreeLayout(PT_Tree arg)
{
  if (PT_isTreeLayout(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Layout PT_getTreeLayout(PT_Tree arg) */

PT_Layout PT_getTreeLayout(PT_Tree arg)
{
  if (PT_isTreeLayout(arg)) {
    return (PT_Layout)arg;
  }

  ATabort("Tree has no Layout: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeLayout(PT_Tree arg, PT_Layout layout) */

PT_Tree PT_setTreeLayout(PT_Tree arg, PT_Layout layout)
{
  if (PT_isTreeLayout(arg)) {
    return (PT_Tree)layout;
  }

  ATabort("Tree has no Layout: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeLiteral(PT_Tree arg) */

ATbool PT_hasTreeLiteral(PT_Tree arg)
{
  if (PT_isTreeLiteral(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Literal PT_getTreeLiteral(PT_Tree arg) */

PT_Literal PT_getTreeLiteral(PT_Tree arg)
{
  if (PT_isTreeLiteral(arg)) {
    return (PT_Literal)arg;
  }

  ATabort("Tree has no Literal: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeLiteral(PT_Tree arg, PT_Literal literal) */

PT_Tree PT_setTreeLiteral(PT_Tree arg, PT_Literal literal)
{
  if (PT_isTreeLiteral(arg)) {
    return (PT_Tree)literal;
  }

  ATabort("Tree has no Literal: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeQliteral(PT_Tree arg) */

ATbool PT_hasTreeQliteral(PT_Tree arg)
{
  if (PT_isTreeQLiteral(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_QLiteral PT_getTreeQliteral(PT_Tree arg) */

PT_QLiteral PT_getTreeQliteral(PT_Tree arg)
{
  if (PT_isTreeQLiteral(arg)) {
    return (PT_QLiteral)arg;
  }

  ATabort("Tree has no Qliteral: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeQliteral(PT_Tree arg, PT_QLiteral qliteral) */

PT_Tree PT_setTreeQliteral(PT_Tree arg, PT_QLiteral qliteral)
{
  if (PT_isTreeQLiteral(arg)) {
    return (PT_Tree)qliteral;
  }

  ATabort("Tree has no Qliteral: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeElems(PT_Tree arg) */

ATbool PT_hasTreeElems(PT_Tree arg)
{
  if (PT_isTreeList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Args PT_getTreeElems(PT_Tree arg) */

PT_Args PT_getTreeElems(PT_Tree arg)
{
  if (PT_isTreeList(arg)) {
    return (PT_Args)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Tree has no Elems: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeElems(PT_Tree arg, PT_Args elems) */

PT_Tree PT_setTreeElems(PT_Tree arg, PT_Args elems)
{
  if (PT_isTreeList(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)elems, 2);
  }

  ATabort("Tree has no Elems: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod) */

PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)prod, 0);
  }

  ATabort("Tree has no Prod: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Var accessor implementations */

/*{{{  ATbool PT_isValidVar(PT_Var arg) */

ATbool PT_isValidVar(PT_Var arg)
{
  if (PT_isVarDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isVarDefault(PT_Var arg) */

ATbool PT_isVarDefault(PT_Var arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternVarDefault, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasVarSort(PT_Var arg) */

ATbool PT_hasVarSort(PT_Var arg)
{
  if (PT_isVarDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getVarSort(PT_Var arg) */

PT_Symbol PT_getVarSort(PT_Var arg)
{
  if (PT_isVarDefault(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }

  ATabort("Var has no Sort: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Var PT_setVarSort(PT_Var arg, PT_Symbol sort) */

PT_Var PT_setVarSort(PT_Var arg, PT_Symbol sort)
{
  if (PT_isVarDefault(arg)) {
    return (PT_Var)ATsetArgument((ATermAppl)arg, (ATerm)sort, 1);
  }

  ATabort("Var has no Sort: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasVarName(PT_Var arg) */

ATbool PT_hasVarName(PT_Var arg)
{
  if (PT_isVarDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_String PT_getVarName(PT_Var arg) */

PT_String PT_getVarName(PT_Var arg)
{
  if (PT_isVarDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Var has no Name: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Var PT_setVarName(PT_Var arg, PT_String name) */

PT_Var PT_setVarName(PT_Var arg, PT_String name)
{
  if (PT_isVarDefault(arg)) {
    return (PT_Var)ATsetArgument((ATermAppl)arg, (ATerm)name, 0);
  }

  ATabort("Var has no Name: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Production accessor implementations */

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
  return NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs) */

PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)rhs, 6);
  }

  ATabort("Production has no Rhs: %t\n", arg);
  return NULL;
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
  return NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs) */

PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)lhs, 2);
  }

  ATabort("Production has no Lhs: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionAttrs(PT_Production arg) */

ATbool PT_hasProductionAttrs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attrs PT_getProductionAttrs(PT_Production arg) */

PT_Attrs PT_getProductionAttrs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Attrs)ATgetArgument((ATermAppl)arg, 8);
  }

  ATabort("Production has no Attrs: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionAttrs(PT_Production arg, PT_Attrs attrs) */

PT_Production PT_setProductionAttrs(PT_Production arg, PT_Attrs attrs)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)attrs, 8);
  }

  ATabort("Production has no Attrs: %t\n", arg);
  return NULL;
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
/*{{{  PT_String PT_getProductionModuleName(PT_Production arg) */

PT_String PT_getProductionModuleName(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0);
  }

  ATabort("Production has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionModuleName(PT_Production arg, PT_String moduleName) */

PT_Production PT_setProductionModuleName(PT_Production arg, PT_String moduleName)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)moduleName, 0), 0);
  }

  ATabort("Production has no ModuleName: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Iter accessor implementations */

/*{{{  ATbool PT_isValidIter(PT_Iter arg) */

ATbool PT_isValidIter(PT_Iter arg)
{
  if (PT_isIterStar(arg)) {
    return ATtrue;
  }
  else if (PT_isIterPlus(arg)) {
    return ATtrue;
  }
  else if (PT_isIterSepStar(arg)) {
    return ATtrue;
  }
  else if (PT_isIterSepPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isIterStar(PT_Iter arg) */

ATbool PT_isIterStar(PT_Iter arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternIterStar, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isIterPlus(PT_Iter arg) */

ATbool PT_isIterPlus(PT_Iter arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternIterPlus, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isIterSepStar(PT_Iter arg) */

ATbool PT_isIterSepStar(PT_Iter arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternIterSepStar, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isIterSepPlus(PT_Iter arg) */

ATbool PT_isIterSepPlus(PT_Iter arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternIterSepPlus, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasIterSeparator(PT_Iter arg) */

ATbool PT_hasIterSeparator(PT_Iter arg)
{
  if (PT_isIterSepStar(arg)) {
    return ATtrue;
  }
  else if (PT_isIterSepPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Separator PT_getIterSeparator(PT_Iter arg) */

PT_Separator PT_getIterSeparator(PT_Iter arg)
{
  if (PT_isIterSepStar(arg)) {
    return (PT_Separator)ATgetArgument((ATermAppl)arg, 4);
  }
  else if (PT_isIterSepPlus(arg)) {
    return (PT_Separator)ATgetArgument((ATermAppl)arg, 4);
  }

  ATabort("Iter has no Separator: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Iter PT_setIterSeparator(PT_Iter arg, PT_Separator separator) */

PT_Iter PT_setIterSeparator(PT_Iter arg, PT_Separator separator)
{
  if (PT_isIterSepStar(arg)) {
    return (PT_Iter)ATsetArgument((ATermAppl)arg, (ATerm)separator, 4);
  }
  else if (PT_isIterSepPlus(arg)) {
    return (PT_Iter)ATsetArgument((ATermAppl)arg, (ATerm)separator, 4);
  }

  ATabort("Iter has no Separator: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasIterSort(PT_Iter arg) */

ATbool PT_hasIterSort(PT_Iter arg)
{
  if (PT_isIterStar(arg)) {
    return ATtrue;
  }
  else if (PT_isIterPlus(arg)) {
    return ATtrue;
  }
  else if (PT_isIterSepStar(arg)) {
    return ATtrue;
  }
  else if (PT_isIterSepPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getIterSort(PT_Iter arg) */

PT_Symbol PT_getIterSort(PT_Iter arg)
{
  if (PT_isIterStar(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isIterPlus(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isIterSepStar(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 2);
  }
  else if (PT_isIterSepPlus(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Iter has no Sort: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Iter PT_setIterSort(PT_Iter arg, PT_Symbol sort) */

PT_Iter PT_setIterSort(PT_Iter arg, PT_Symbol sort)
{
  if (PT_isIterStar(arg)) {
    return (PT_Iter)ATsetArgument((ATermAppl)arg, (ATerm)sort, 0);
  }
  else if (PT_isIterPlus(arg)) {
    return (PT_Iter)ATsetArgument((ATermAppl)arg, (ATerm)sort, 0);
  }
  else if (PT_isIterSepStar(arg)) {
    return (PT_Iter)ATsetArgument((ATermAppl)arg, (ATerm)sort, 2);
  }
  else if (PT_isIterSepPlus(arg)) {
    return (PT_Iter)ATsetArgument((ATermAppl)arg, (ATerm)sort, 2);
  }

  ATabort("Iter has no Sort: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Literal accessor implementations */

/*{{{  ATbool PT_isValidLiteral(PT_Literal arg) */

ATbool PT_isValidLiteral(PT_Literal arg)
{
  if (PT_isLiteralDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isLiteralDefault(PT_Literal arg) */

ATbool PT_isLiteralDefault(PT_Literal arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternLiteralDefault, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasLiteralChars(PT_Literal arg) */

ATbool PT_hasLiteralChars(PT_Literal arg)
{
  if (PT_isLiteralDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_String PT_getLiteralChars(PT_Literal arg) */

PT_String PT_getLiteralChars(PT_Literal arg)
{
  if (PT_isLiteralDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Literal has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Literal PT_setLiteralChars(PT_Literal arg, PT_String chars) */

PT_Literal PT_setLiteralChars(PT_Literal arg, PT_String chars)
{
  if (PT_isLiteralDefault(arg)) {
    return (PT_Literal)ATsetArgument((ATermAppl)arg, (ATerm)chars, 0);
  }

  ATabort("Literal has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_QLiteral accessor implementations */

/*{{{  ATbool PT_isValidQLiteral(PT_QLiteral arg) */

ATbool PT_isValidQLiteral(PT_QLiteral arg)
{
  if (PT_isQLiteralDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isQLiteralDefault(PT_QLiteral arg) */

ATbool PT_isQLiteralDefault(PT_QLiteral arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternQLiteralDefault, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasQLiteralChars(PT_QLiteral arg) */

ATbool PT_hasQLiteralChars(PT_QLiteral arg)
{
  if (PT_isQLiteralDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_String PT_getQLiteralChars(PT_QLiteral arg) */

PT_String PT_getQLiteralChars(PT_QLiteral arg)
{
  if (PT_isQLiteralDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("QLiteral has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_QLiteral PT_setQLiteralChars(PT_QLiteral arg, PT_String chars) */

PT_QLiteral PT_setQLiteralChars(PT_QLiteral arg, PT_String chars)
{
  if (PT_isQLiteralDefault(arg)) {
    return (PT_QLiteral)ATsetArgument((ATermAppl)arg, (ATerm)chars, 0);
  }

  ATabort("QLiteral has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Lexical accessor implementations */

/*{{{  ATbool PT_isValidLexical(PT_Lexical arg) */

ATbool PT_isValidLexical(PT_Lexical arg)
{
  if (PT_isLexicalDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isLexicalDefault(PT_Lexical arg) */

ATbool PT_isLexicalDefault(PT_Lexical arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternLexicalDefault, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasLexicalSort(PT_Lexical arg) */

ATbool PT_hasLexicalSort(PT_Lexical arg)
{
  if (PT_isLexicalDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getLexicalSort(PT_Lexical arg) */

PT_Symbol PT_getLexicalSort(PT_Lexical arg)
{
  if (PT_isLexicalDefault(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }

  ATabort("Lexical has no Sort: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Lexical PT_setLexicalSort(PT_Lexical arg, PT_Symbol sort) */

PT_Lexical PT_setLexicalSort(PT_Lexical arg, PT_Symbol sort)
{
  if (PT_isLexicalDefault(arg)) {
    return (PT_Lexical)ATsetArgument((ATermAppl)arg, (ATerm)sort, 1);
  }

  ATabort("Lexical has no Sort: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasLexicalChars(PT_Lexical arg) */

ATbool PT_hasLexicalChars(PT_Lexical arg)
{
  if (PT_isLexicalDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_String PT_getLexicalChars(PT_Lexical arg) */

PT_String PT_getLexicalChars(PT_Lexical arg)
{
  if (PT_isLexicalDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Lexical has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Lexical PT_setLexicalChars(PT_Lexical arg, PT_String chars) */

PT_Lexical PT_setLexicalChars(PT_Lexical arg, PT_String chars)
{
  if (PT_isLexicalDefault(arg)) {
    return (PT_Lexical)ATsetArgument((ATermAppl)arg, (ATerm)chars, 0);
  }

  ATabort("Lexical has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Separator accessor implementations */

/*{{{  ATbool PT_isValidSeparator(PT_Separator arg) */

ATbool PT_isValidSeparator(PT_Separator arg)
{
  if (PT_isSeparatorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isSeparatorDefault(PT_Separator arg) */

ATbool PT_isSeparatorDefault(PT_Separator arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSeparatorDefault, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasSeparatorChars(PT_Separator arg) */

ATbool PT_hasSeparatorChars(PT_Separator arg)
{
  if (PT_isSeparatorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_String PT_getSeparatorChars(PT_Separator arg) */

PT_String PT_getSeparatorChars(PT_Separator arg)
{
  if (PT_isSeparatorDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Separator has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Separator PT_setSeparatorChars(PT_Separator arg, PT_String chars) */

PT_Separator PT_setSeparatorChars(PT_Separator arg, PT_String chars)
{
  if (PT_isSeparatorDefault(arg)) {
    return (PT_Separator)ATsetArgument((ATermAppl)arg, (ATerm)chars, 0);
  }

  ATabort("Separator has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Layout accessor implementations */

/*{{{  ATbool PT_isValidLayout(PT_Layout arg) */

ATbool PT_isValidLayout(PT_Layout arg)
{
  if (PT_isLayoutDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isLayoutDefault(PT_Layout arg) */

ATbool PT_isLayoutDefault(PT_Layout arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternLayoutDefault, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasLayoutChars(PT_Layout arg) */

ATbool PT_hasLayoutChars(PT_Layout arg)
{
  if (PT_isLayoutDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_String PT_getLayoutChars(PT_Layout arg) */

PT_String PT_getLayoutChars(PT_Layout arg)
{
  if (PT_isLayoutDefault(arg)) {
    return (PT_String)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Layout has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Layout PT_setLayoutChars(PT_Layout arg, PT_String chars) */

PT_Layout PT_setLayoutChars(PT_Layout arg, PT_String chars)
{
  if (PT_isLayoutDefault(arg)) {
    return (PT_Layout)ATsetArgument((ATermAppl)arg, (ATerm)chars, 0);
  }

  ATabort("Layout has no Chars: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Args accessor implementations */

/*{{{  ATbool PT_isValidArgs(PT_Args arg) */

ATbool PT_isValidArgs(PT_Args arg)
{
  if (PT_isArgsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isArgsDefault(PT_Args arg) */

ATbool PT_isArgsDefault(PT_Args arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternArgsDefault, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasArgsTail(PT_Args arg) */

ATbool PT_hasArgsTail(PT_Args arg)
{
  if (PT_isArgsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Args PT_getArgsTail(PT_Args arg) */

PT_Args PT_getArgsTail(PT_Args arg)
{
  if (PT_isArgsDefault(arg)) {
    return (PT_Args)ATelementAt((ATermList)ATelementAt((ATermList)arg, 1), 0);
  }

  ATabort("Args has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail) */

PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail)
{
  if (PT_isArgsDefault(arg)) {
    return (PT_Args)ATreplace((ATermList)arg, (ATerm)ATreplace((ATermList)ATelementAt((ATermList)arg, 1), (ATerm)tail, 0), 1);
  }

  ATabort("Args has no Tail: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasArgsHead(PT_Args arg) */

ATbool PT_hasArgsHead(PT_Args arg)
{
  if (PT_isArgsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getArgsHead(PT_Args arg) */

PT_Tree PT_getArgsHead(PT_Args arg)
{
  if (PT_isArgsDefault(arg)) {
    return (PT_Tree)ATelementAt((ATermList)arg, 0);
  }

  ATabort("Args has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */
/*{{{  PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head) */

PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head)
{
  if (PT_isArgsDefault(arg)) {
    return (PT_Args)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Args has no Head: %t\n", arg);
  return NULL;
}

/*}}}  */

/*}}}  */
