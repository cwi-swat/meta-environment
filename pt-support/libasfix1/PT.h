#ifndef _PT_H
#define _PT_H

/*{{{  includes */

#include <aterm1.h>
#include "PT_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm PT_String;
typedef ATerm PT_Symbols;
typedef ATerm PT_Attrs;

/*}}}  */
/*{{{  typedefs */

typedef struct _PT_ParseTree *PT_ParseTree;
typedef struct _PT_ModuleName *PT_ModuleName;
typedef struct _PT_Tree *PT_Tree;
typedef struct _PT_Var *PT_Var;
typedef struct _PT_Production *PT_Production;
typedef struct _PT_Symbol *PT_Symbol;
typedef struct _PT_Literal *PT_Literal;
typedef struct _PT_QLiteral *PT_QLiteral;
typedef struct _PT_Lexical *PT_Lexical;
typedef struct _PT_Separator *PT_Separator;
typedef struct _PT_Layout *PT_Layout;
typedef struct _PT_Args *PT_Args;

/*}}}  */

void PT_initPTApi(void);

PT_ParseTree PT_makeParseTreeFromTerm(ATerm t);
ATerm PT_makeTermFromParseTree(PT_ParseTree arg);
PT_ModuleName PT_makeModuleNameFromTerm(ATerm t);
ATerm PT_makeTermFromModuleName(PT_ModuleName arg);
PT_Tree PT_makeTreeFromTerm(ATerm t);
ATerm PT_makeTermFromTree(PT_Tree arg);
PT_Var PT_makeVarFromTerm(ATerm t);
ATerm PT_makeTermFromVar(PT_Var arg);
PT_Production PT_makeProductionFromTerm(ATerm t);
ATerm PT_makeTermFromProduction(PT_Production arg);
PT_Symbol PT_makeSymbolFromTerm(ATerm t);
ATerm PT_makeTermFromSymbol(PT_Symbol arg);
PT_Literal PT_makeLiteralFromTerm(ATerm t);
ATerm PT_makeTermFromLiteral(PT_Literal arg);
PT_QLiteral PT_makeQLiteralFromTerm(ATerm t);
ATerm PT_makeTermFromQLiteral(PT_QLiteral arg);
PT_Lexical PT_makeLexicalFromTerm(ATerm t);
ATerm PT_makeTermFromLexical(PT_Lexical arg);
PT_Separator PT_makeSeparatorFromTerm(ATerm t);
ATerm PT_makeTermFromSeparator(PT_Separator arg);
PT_Layout PT_makeLayoutFromTerm(ATerm t);
ATerm PT_makeTermFromLayout(PT_Layout arg);
PT_Args PT_makeArgsFromTerm(ATerm t);
ATerm PT_makeTermFromArgs(PT_Args arg);

PT_ParseTree PT_makeParseTreeTree(PT_Layout layoutBeforeTree, PT_Tree tree, PT_Layout layoutAfterTree);
PT_ModuleName PT_makeModuleNameDefault(PT_String id);
PT_Tree PT_makeTreeLayout(PT_Layout layout);
PT_Tree PT_makeTreeVar(PT_Var var);
PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args);
PT_Tree PT_makeTreeList(PT_Symbol iter, PT_Args args);
PT_Tree PT_makeTreeLexical(PT_Lexical lexical);
PT_Tree PT_makeTreeUnquotedLiteral(PT_Literal literal);
PT_Tree PT_makeTreeQuotedLiteral(PT_QLiteral qliteral);
PT_Tree PT_makeTreeSeparator(PT_Separator separator);
PT_Var PT_makeVarDefault(PT_String name, PT_Symbol symbol);
PT_Production PT_makeProductionDefault(PT_String moduleName, PT_Symbols lhs, PT_Symbol rhs, PT_Attrs attrs);
PT_Symbol PT_makeSymbolIterStar(PT_Symbol symbol);
PT_Symbol PT_makeSymbolIterPlus(PT_Symbol symbol);
PT_Symbol PT_makeSymbolIterStarSep(PT_Symbol symbol, PT_Separator separator);
PT_Symbol PT_makeSymbolIterPlusSep(PT_Symbol symbol, PT_Separator separator);
PT_Literal PT_makeLiteralDefault(PT_String chars);
PT_QLiteral PT_makeQLiteralDefault(PT_String chars);
PT_Lexical PT_makeLexicalDefault(PT_String chars, PT_Symbol symbol);
PT_Separator PT_makeSeparatorDefault(PT_String chars);
PT_Layout PT_makeLayoutDefault(PT_String chars);
PT_Args PT_makeArgsDefault(PT_Tree head, PT_Args tail);
PT_Args PT_makeArgsEmpty();

/*{{{  equality functions */

ATbool PT_isEqualParseTree(PT_ParseTree arg0, PT_ParseTree arg1);
ATbool PT_isEqualModuleName(PT_ModuleName arg0, PT_ModuleName arg1);
ATbool PT_isEqualTree(PT_Tree arg0, PT_Tree arg1);
ATbool PT_isEqualVar(PT_Var arg0, PT_Var arg1);
ATbool PT_isEqualProduction(PT_Production arg0, PT_Production arg1);
ATbool PT_isEqualSymbol(PT_Symbol arg0, PT_Symbol arg1);
ATbool PT_isEqualLiteral(PT_Literal arg0, PT_Literal arg1);
ATbool PT_isEqualQLiteral(PT_QLiteral arg0, PT_QLiteral arg1);
ATbool PT_isEqualLexical(PT_Lexical arg0, PT_Lexical arg1);
ATbool PT_isEqualSeparator(PT_Separator arg0, PT_Separator arg1);
ATbool PT_isEqualLayout(PT_Layout arg0, PT_Layout arg1);
ATbool PT_isEqualArgs(PT_Args arg0, PT_Args arg1);

/*}}}  */
/*{{{  PT_ParseTree accessor prototypes */

ATbool PT_isValidParseTree(PT_ParseTree arg);
ATbool PT_isParseTreeTree(PT_ParseTree arg);
ATbool PT_hasParseTreeLayoutBeforeTree(PT_ParseTree arg);
PT_Layout PT_getParseTreeLayoutBeforeTree(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree arg, PT_Layout layoutBeforeTree);
ATbool PT_hasParseTreeTree(PT_ParseTree arg);
PT_Tree PT_getParseTreeTree(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeTree(PT_ParseTree arg, PT_Tree tree);
ATbool PT_hasParseTreeLayoutAfterTree(PT_ParseTree arg);
PT_Layout PT_getParseTreeLayoutAfterTree(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeLayoutAfterTree(PT_ParseTree arg, PT_Layout layoutAfterTree);

/*}}}  */
/*{{{  PT_ModuleName accessor prototypes */

ATbool PT_isValidModuleName(PT_ModuleName arg);
ATbool PT_isModuleNameDefault(PT_ModuleName arg);
ATbool PT_hasModuleNameId(PT_ModuleName arg);
PT_String PT_getModuleNameId(PT_ModuleName arg);
PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, PT_String id);

/*}}}  */
/*{{{  PT_Tree accessor prototypes */

ATbool PT_isValidTree(PT_Tree arg);
ATbool PT_isTreeLayout(PT_Tree arg);
ATbool PT_isTreeVar(PT_Tree arg);
ATbool PT_isTreeAppl(PT_Tree arg);
ATbool PT_isTreeList(PT_Tree arg);
ATbool PT_isTreeLexical(PT_Tree arg);
ATbool PT_isTreeUnquotedLiteral(PT_Tree arg);
ATbool PT_isTreeQuotedLiteral(PT_Tree arg);
ATbool PT_isTreeSeparator(PT_Tree arg);
ATbool PT_hasTreeLexical(PT_Tree arg);
PT_Lexical PT_getTreeLexical(PT_Tree arg);
PT_Tree PT_setTreeLexical(PT_Tree arg, PT_Lexical lexical);
ATbool PT_hasTreeSeparator(PT_Tree arg);
PT_Separator PT_getTreeSeparator(PT_Tree arg);
PT_Tree PT_setTreeSeparator(PT_Tree arg, PT_Separator separator);
ATbool PT_hasTreeIter(PT_Tree arg);
PT_Symbol PT_getTreeIter(PT_Tree arg);
PT_Tree PT_setTreeIter(PT_Tree arg, PT_Symbol iter);
ATbool PT_hasTreeVar(PT_Tree arg);
PT_Var PT_getTreeVar(PT_Tree arg);
PT_Tree PT_setTreeVar(PT_Tree arg, PT_Var var);
ATbool PT_hasTreeArgs(PT_Tree arg);
PT_Args PT_getTreeArgs(PT_Tree arg);
PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args);
ATbool PT_hasTreeLayout(PT_Tree arg);
PT_Layout PT_getTreeLayout(PT_Tree arg);
PT_Tree PT_setTreeLayout(PT_Tree arg, PT_Layout layout);
ATbool PT_hasTreeLiteral(PT_Tree arg);
PT_Literal PT_getTreeLiteral(PT_Tree arg);
PT_Tree PT_setTreeLiteral(PT_Tree arg, PT_Literal literal);
ATbool PT_hasTreeQliteral(PT_Tree arg);
PT_QLiteral PT_getTreeQliteral(PT_Tree arg);
PT_Tree PT_setTreeQliteral(PT_Tree arg, PT_QLiteral qliteral);
ATbool PT_hasTreeProd(PT_Tree arg);
PT_Production PT_getTreeProd(PT_Tree arg);
PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod);

/*}}}  */
/*{{{  PT_Var accessor prototypes */

ATbool PT_isValidVar(PT_Var arg);
ATbool PT_isVarDefault(PT_Var arg);
ATbool PT_hasVarSymbol(PT_Var arg);
PT_Symbol PT_getVarSymbol(PT_Var arg);
PT_Var PT_setVarSymbol(PT_Var arg, PT_Symbol symbol);
ATbool PT_hasVarName(PT_Var arg);
PT_String PT_getVarName(PT_Var arg);
PT_Var PT_setVarName(PT_Var arg, PT_String name);

/*}}}  */
/*{{{  PT_Production accessor prototypes */

ATbool PT_isValidProduction(PT_Production arg);
ATbool PT_isProductionDefault(PT_Production arg);
ATbool PT_hasProductionRhs(PT_Production arg);
PT_Symbol PT_getProductionRhs(PT_Production arg);
PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs);
ATbool PT_hasProductionLhs(PT_Production arg);
PT_Symbols PT_getProductionLhs(PT_Production arg);
PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs);
ATbool PT_hasProductionAttrs(PT_Production arg);
PT_Attrs PT_getProductionAttrs(PT_Production arg);
PT_Production PT_setProductionAttrs(PT_Production arg, PT_Attrs attrs);
ATbool PT_hasProductionModuleName(PT_Production arg);
PT_String PT_getProductionModuleName(PT_Production arg);
PT_Production PT_setProductionModuleName(PT_Production arg, PT_String moduleName);

/*}}}  */
/*{{{  PT_Symbol accessor prototypes */

ATbool PT_isValidSymbol(PT_Symbol arg);
ATbool PT_isSymbolIterStar(PT_Symbol arg);
ATbool PT_isSymbolIterPlus(PT_Symbol arg);
ATbool PT_isSymbolIterStarSep(PT_Symbol arg);
ATbool PT_isSymbolIterPlusSep(PT_Symbol arg);
ATbool PT_hasSymbolSeparator(PT_Symbol arg);
PT_Separator PT_getSymbolSeparator(PT_Symbol arg);
PT_Symbol PT_setSymbolSeparator(PT_Symbol arg, PT_Separator separator);
ATbool PT_hasSymbolSymbol(PT_Symbol arg);
PT_Symbol PT_getSymbolSymbol(PT_Symbol arg);
PT_Symbol PT_setSymbolSymbol(PT_Symbol arg, PT_Symbol symbol);

/*}}}  */
/*{{{  PT_Literal accessor prototypes */

ATbool PT_isValidLiteral(PT_Literal arg);
ATbool PT_isLiteralDefault(PT_Literal arg);
ATbool PT_hasLiteralChars(PT_Literal arg);
PT_String PT_getLiteralChars(PT_Literal arg);
PT_Literal PT_setLiteralChars(PT_Literal arg, PT_String chars);

/*}}}  */
/*{{{  PT_QLiteral accessor prototypes */

ATbool PT_isValidQLiteral(PT_QLiteral arg);
ATbool PT_isQLiteralDefault(PT_QLiteral arg);
ATbool PT_hasQLiteralChars(PT_QLiteral arg);
PT_String PT_getQLiteralChars(PT_QLiteral arg);
PT_QLiteral PT_setQLiteralChars(PT_QLiteral arg, PT_String chars);

/*}}}  */
/*{{{  PT_Lexical accessor prototypes */

ATbool PT_isValidLexical(PT_Lexical arg);
ATbool PT_isLexicalDefault(PT_Lexical arg);
ATbool PT_hasLexicalSymbol(PT_Lexical arg);
PT_Symbol PT_getLexicalSymbol(PT_Lexical arg);
PT_Lexical PT_setLexicalSymbol(PT_Lexical arg, PT_Symbol symbol);
ATbool PT_hasLexicalChars(PT_Lexical arg);
PT_String PT_getLexicalChars(PT_Lexical arg);
PT_Lexical PT_setLexicalChars(PT_Lexical arg, PT_String chars);

/*}}}  */
/*{{{  PT_Separator accessor prototypes */

ATbool PT_isValidSeparator(PT_Separator arg);
ATbool PT_isSeparatorDefault(PT_Separator arg);
ATbool PT_hasSeparatorChars(PT_Separator arg);
PT_String PT_getSeparatorChars(PT_Separator arg);
PT_Separator PT_setSeparatorChars(PT_Separator arg, PT_String chars);

/*}}}  */
/*{{{  PT_Layout accessor prototypes */

ATbool PT_isValidLayout(PT_Layout arg);
ATbool PT_isLayoutDefault(PT_Layout arg);
ATbool PT_hasLayoutChars(PT_Layout arg);
PT_String PT_getLayoutChars(PT_Layout arg);
PT_Layout PT_setLayoutChars(PT_Layout arg, PT_String chars);

/*}}}  */
/*{{{  PT_Args accessor prototypes */

ATbool PT_isValidArgs(PT_Args arg);
ATbool PT_isArgsDefault(PT_Args arg);
ATbool PT_isArgsEmpty(PT_Args arg);
ATbool PT_hasArgsTail(PT_Args arg);
PT_Args PT_getArgsTail(PT_Args arg);
PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail);
ATbool PT_hasArgsHead(PT_Args arg);
PT_Tree PT_getArgsHead(PT_Args arg);
PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head);

/*}}}  */

#endif /* _PT_H */
