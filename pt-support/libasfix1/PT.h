#ifndef _PT_H
#define _PT_H

/*{{{  includes */

#include <aterm1.h>
#include "PT_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm PT_String;

/*}}}  */
/*{{{  typedefs */

typedef struct _PT_ParseTree *PT_ParseTree;
typedef struct _PT_ModuleName *PT_ModuleName;
typedef struct _PT_Tree *PT_Tree;
typedef struct _PT_Var *PT_Var;
typedef struct _PT_Production *PT_Production;
typedef struct _PT_Attributes *PT_Attributes;
typedef struct _PT_Attrs *PT_Attrs;
typedef struct _PT_Attr *PT_Attr;
typedef struct _PT_Symbol *PT_Symbol;
typedef struct _PT_Literal *PT_Literal;
typedef struct _PT_QLiteral *PT_QLiteral;
typedef struct _PT_Lexical *PT_Lexical;
typedef struct _PT_Separator *PT_Separator;
typedef struct _PT_Layout *PT_Layout;
typedef struct _PT_Args *PT_Args;
typedef struct _PT_Symbols *PT_Symbols;

/*}}}  */

void PT_initPTApi(void);

/*{{{  term conversion functions */

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
PT_Attributes PT_makeAttributesFromTerm(ATerm t);
ATerm PT_makeTermFromAttributes(PT_Attributes arg);
PT_Attrs PT_makeAttrsFromTerm(ATerm t);
ATerm PT_makeTermFromAttrs(PT_Attrs arg);
PT_Attr PT_makeAttrFromTerm(ATerm t);
ATerm PT_makeTermFromAttr(PT_Attr arg);
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
PT_Symbols PT_makeSymbolsFromTerm(ATerm t);
ATerm PT_makeTermFromSymbols(PT_Symbols arg);

/*}}}  */
/*{{{  constructors */

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
PT_Production PT_makeProductionDefault(PT_String moduleName, PT_Symbols lhs, PT_Symbol rhs, PT_Attributes attrs);
PT_Attributes PT_makeAttributesNoAttrs();
PT_Attributes PT_makeAttributesAttrs(PT_Attrs attrs);
PT_Attrs PT_makeAttrsMany(PT_Attr head, PT_Attrs tail);
PT_Attrs PT_makeAttrsSingle(PT_Attr head);
PT_Attr PT_makeAttrCons(char * string);
PT_Attr PT_makeAttrBracket();
PT_Attr PT_makeAttrTraverse();
PT_Attr PT_makeAttrMemo();
PT_Symbol PT_makeSymbolIterStar(PT_Symbol symbol);
PT_Symbol PT_makeSymbolIterPlus(PT_Symbol symbol);
PT_Symbol PT_makeSymbolIterStarSep(PT_Symbol symbol, PT_Separator separator);
PT_Symbol PT_makeSymbolIterPlusSep(PT_Symbol symbol, PT_Separator separator);
PT_Symbol PT_makeSymbolEmptyLayout();
PT_Symbol PT_makeSymbolSort(PT_String string);
PT_Symbol PT_makeSymbolUnquotedLiteral(PT_Literal literal);
PT_Symbol PT_makeSymbolQuotedLiteral(PT_QLiteral qliteral);
PT_Literal PT_makeLiteralDefault(PT_String string);
PT_QLiteral PT_makeQLiteralDefault(PT_String string);
PT_Lexical PT_makeLexicalDefault(PT_String string, PT_Symbol symbol);
PT_Separator PT_makeSeparatorDefault(PT_String string);
PT_Layout PT_makeLayoutDefault(PT_String string);
PT_Args PT_makeArgsList(PT_Tree head, PT_Args tail);
PT_Args PT_makeArgsEmpty();
PT_Symbols PT_makeSymbolsList(PT_Symbol head, PT_Symbols tail);
PT_Symbols PT_makeSymbolsEmpty();

/*}}}  */
/*{{{  equality functions */

ATbool PT_isEqualParseTree(PT_ParseTree arg0, PT_ParseTree arg1);
ATbool PT_isEqualModuleName(PT_ModuleName arg0, PT_ModuleName arg1);
ATbool PT_isEqualTree(PT_Tree arg0, PT_Tree arg1);
ATbool PT_isEqualVar(PT_Var arg0, PT_Var arg1);
ATbool PT_isEqualProduction(PT_Production arg0, PT_Production arg1);
ATbool PT_isEqualAttributes(PT_Attributes arg0, PT_Attributes arg1);
ATbool PT_isEqualAttrs(PT_Attrs arg0, PT_Attrs arg1);
ATbool PT_isEqualAttr(PT_Attr arg0, PT_Attr arg1);
ATbool PT_isEqualSymbol(PT_Symbol arg0, PT_Symbol arg1);
ATbool PT_isEqualLiteral(PT_Literal arg0, PT_Literal arg1);
ATbool PT_isEqualQLiteral(PT_QLiteral arg0, PT_QLiteral arg1);
ATbool PT_isEqualLexical(PT_Lexical arg0, PT_Lexical arg1);
ATbool PT_isEqualSeparator(PT_Separator arg0, PT_Separator arg1);
ATbool PT_isEqualLayout(PT_Layout arg0, PT_Layout arg1);
ATbool PT_isEqualArgs(PT_Args arg0, PT_Args arg1);
ATbool PT_isEqualSymbols(PT_Symbols arg0, PT_Symbols arg1);

/*}}}  */
/*{{{  PT_ParseTree accessors */

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
/*{{{  PT_ModuleName accessors */

ATbool PT_isValidModuleName(PT_ModuleName arg);
ATbool PT_isModuleNameDefault(PT_ModuleName arg);
ATbool PT_hasModuleNameId(PT_ModuleName arg);
PT_String PT_getModuleNameId(PT_ModuleName arg);
PT_ModuleName PT_setModuleNameId(PT_ModuleName arg, PT_String id);

/*}}}  */
/*{{{  PT_Tree accessors */

ATbool PT_isValidTree(PT_Tree arg);
ATbool PT_isTreeLayout(PT_Tree arg);
ATbool PT_isTreeVar(PT_Tree arg);
ATbool PT_isTreeAppl(PT_Tree arg);
ATbool PT_isTreeList(PT_Tree arg);
ATbool PT_isTreeLexical(PT_Tree arg);
ATbool PT_isTreeUnquotedLiteral(PT_Tree arg);
ATbool PT_isTreeQuotedLiteral(PT_Tree arg);
ATbool PT_isTreeSeparator(PT_Tree arg);
ATbool PT_hasTreeLayout(PT_Tree arg);
PT_Layout PT_getTreeLayout(PT_Tree arg);
PT_Tree PT_setTreeLayout(PT_Tree arg, PT_Layout layout);
ATbool PT_hasTreeVar(PT_Tree arg);
PT_Var PT_getTreeVar(PT_Tree arg);
PT_Tree PT_setTreeVar(PT_Tree arg, PT_Var var);
ATbool PT_hasTreeProd(PT_Tree arg);
PT_Production PT_getTreeProd(PT_Tree arg);
PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod);
ATbool PT_hasTreeArgs(PT_Tree arg);
PT_Args PT_getTreeArgs(PT_Tree arg);
PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args);
ATbool PT_hasTreeIter(PT_Tree arg);
PT_Symbol PT_getTreeIter(PT_Tree arg);
PT_Tree PT_setTreeIter(PT_Tree arg, PT_Symbol iter);
ATbool PT_hasTreeLexical(PT_Tree arg);
PT_Lexical PT_getTreeLexical(PT_Tree arg);
PT_Tree PT_setTreeLexical(PT_Tree arg, PT_Lexical lexical);
ATbool PT_hasTreeLiteral(PT_Tree arg);
PT_Literal PT_getTreeLiteral(PT_Tree arg);
PT_Tree PT_setTreeLiteral(PT_Tree arg, PT_Literal literal);
ATbool PT_hasTreeQliteral(PT_Tree arg);
PT_QLiteral PT_getTreeQliteral(PT_Tree arg);
PT_Tree PT_setTreeQliteral(PT_Tree arg, PT_QLiteral qliteral);
ATbool PT_hasTreeSeparator(PT_Tree arg);
PT_Separator PT_getTreeSeparator(PT_Tree arg);
PT_Tree PT_setTreeSeparator(PT_Tree arg, PT_Separator separator);

/*}}}  */
/*{{{  PT_Var accessors */

ATbool PT_isValidVar(PT_Var arg);
ATbool PT_isVarDefault(PT_Var arg);
ATbool PT_hasVarName(PT_Var arg);
PT_String PT_getVarName(PT_Var arg);
PT_Var PT_setVarName(PT_Var arg, PT_String name);
ATbool PT_hasVarSymbol(PT_Var arg);
PT_Symbol PT_getVarSymbol(PT_Var arg);
PT_Var PT_setVarSymbol(PT_Var arg, PT_Symbol symbol);

/*}}}  */
/*{{{  PT_Production accessors */

ATbool PT_isValidProduction(PT_Production arg);
ATbool PT_isProductionDefault(PT_Production arg);
ATbool PT_hasProductionModuleName(PT_Production arg);
PT_String PT_getProductionModuleName(PT_Production arg);
PT_Production PT_setProductionModuleName(PT_Production arg, PT_String moduleName);
ATbool PT_hasProductionLhs(PT_Production arg);
PT_Symbols PT_getProductionLhs(PT_Production arg);
PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs);
ATbool PT_hasProductionRhs(PT_Production arg);
PT_Symbol PT_getProductionRhs(PT_Production arg);
PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs);
ATbool PT_hasProductionAttrs(PT_Production arg);
PT_Attributes PT_getProductionAttrs(PT_Production arg);
PT_Production PT_setProductionAttrs(PT_Production arg, PT_Attributes attrs);

/*}}}  */
/*{{{  PT_Attributes accessors */

ATbool PT_isValidAttributes(PT_Attributes arg);
ATbool PT_isAttributesNoAttrs(PT_Attributes arg);
ATbool PT_isAttributesAttrs(PT_Attributes arg);
ATbool PT_hasAttributesAttrs(PT_Attributes arg);
PT_Attrs PT_getAttributesAttrs(PT_Attributes arg);
PT_Attributes PT_setAttributesAttrs(PT_Attributes arg, PT_Attrs attrs);

/*}}}  */
/*{{{  PT_Attrs accessors */

ATbool PT_isValidAttrs(PT_Attrs arg);
ATbool PT_isAttrsMany(PT_Attrs arg);
ATbool PT_isAttrsSingle(PT_Attrs arg);
ATbool PT_hasAttrsHead(PT_Attrs arg);
PT_Attr PT_getAttrsHead(PT_Attrs arg);
PT_Attrs PT_setAttrsHead(PT_Attrs arg, PT_Attr head);
ATbool PT_hasAttrsTail(PT_Attrs arg);
PT_Attrs PT_getAttrsTail(PT_Attrs arg);
PT_Attrs PT_setAttrsTail(PT_Attrs arg, PT_Attrs tail);

/*}}}  */
/*{{{  PT_Attr accessors */

ATbool PT_isValidAttr(PT_Attr arg);
ATbool PT_isAttrCons(PT_Attr arg);
ATbool PT_isAttrBracket(PT_Attr arg);
ATbool PT_isAttrTraverse(PT_Attr arg);
ATbool PT_isAttrMemo(PT_Attr arg);
ATbool PT_hasAttrString(PT_Attr arg);
char * PT_getAttrString(PT_Attr arg);
PT_Attr PT_setAttrString(PT_Attr arg, char * string);

/*}}}  */
/*{{{  PT_Symbol accessors */

ATbool PT_isValidSymbol(PT_Symbol arg);
ATbool PT_isSymbolIterStar(PT_Symbol arg);
ATbool PT_isSymbolIterPlus(PT_Symbol arg);
ATbool PT_isSymbolIterStarSep(PT_Symbol arg);
ATbool PT_isSymbolIterPlusSep(PT_Symbol arg);
ATbool PT_isSymbolEmptyLayout(PT_Symbol arg);
ATbool PT_isSymbolSort(PT_Symbol arg);
ATbool PT_isSymbolUnquotedLiteral(PT_Symbol arg);
ATbool PT_isSymbolQuotedLiteral(PT_Symbol arg);
ATbool PT_hasSymbolSymbol(PT_Symbol arg);
PT_Symbol PT_getSymbolSymbol(PT_Symbol arg);
PT_Symbol PT_setSymbolSymbol(PT_Symbol arg, PT_Symbol symbol);
ATbool PT_hasSymbolSeparator(PT_Symbol arg);
PT_Separator PT_getSymbolSeparator(PT_Symbol arg);
PT_Symbol PT_setSymbolSeparator(PT_Symbol arg, PT_Separator separator);
ATbool PT_hasSymbolString(PT_Symbol arg);
PT_String PT_getSymbolString(PT_Symbol arg);
PT_Symbol PT_setSymbolString(PT_Symbol arg, PT_String string);
ATbool PT_hasSymbolLiteral(PT_Symbol arg);
PT_Literal PT_getSymbolLiteral(PT_Symbol arg);
PT_Symbol PT_setSymbolLiteral(PT_Symbol arg, PT_Literal literal);
ATbool PT_hasSymbolQliteral(PT_Symbol arg);
PT_QLiteral PT_getSymbolQliteral(PT_Symbol arg);
PT_Symbol PT_setSymbolQliteral(PT_Symbol arg, PT_QLiteral qliteral);

/*}}}  */
/*{{{  PT_Literal accessors */

ATbool PT_isValidLiteral(PT_Literal arg);
ATbool PT_isLiteralDefault(PT_Literal arg);
ATbool PT_hasLiteralString(PT_Literal arg);
PT_String PT_getLiteralString(PT_Literal arg);
PT_Literal PT_setLiteralString(PT_Literal arg, PT_String string);

/*}}}  */
/*{{{  PT_QLiteral accessors */

ATbool PT_isValidQLiteral(PT_QLiteral arg);
ATbool PT_isQLiteralDefault(PT_QLiteral arg);
ATbool PT_hasQLiteralString(PT_QLiteral arg);
PT_String PT_getQLiteralString(PT_QLiteral arg);
PT_QLiteral PT_setQLiteralString(PT_QLiteral arg, PT_String string);

/*}}}  */
/*{{{  PT_Lexical accessors */

ATbool PT_isValidLexical(PT_Lexical arg);
ATbool PT_isLexicalDefault(PT_Lexical arg);
ATbool PT_hasLexicalString(PT_Lexical arg);
PT_String PT_getLexicalString(PT_Lexical arg);
PT_Lexical PT_setLexicalString(PT_Lexical arg, PT_String string);
ATbool PT_hasLexicalSymbol(PT_Lexical arg);
PT_Symbol PT_getLexicalSymbol(PT_Lexical arg);
PT_Lexical PT_setLexicalSymbol(PT_Lexical arg, PT_Symbol symbol);

/*}}}  */
/*{{{  PT_Separator accessors */

ATbool PT_isValidSeparator(PT_Separator arg);
ATbool PT_isSeparatorDefault(PT_Separator arg);
ATbool PT_hasSeparatorString(PT_Separator arg);
PT_String PT_getSeparatorString(PT_Separator arg);
PT_Separator PT_setSeparatorString(PT_Separator arg, PT_String string);

/*}}}  */
/*{{{  PT_Layout accessors */

ATbool PT_isValidLayout(PT_Layout arg);
ATbool PT_isLayoutDefault(PT_Layout arg);
ATbool PT_hasLayoutString(PT_Layout arg);
PT_String PT_getLayoutString(PT_Layout arg);
PT_Layout PT_setLayoutString(PT_Layout arg, PT_String string);

/*}}}  */
/*{{{  PT_Args accessors */

ATbool PT_isValidArgs(PT_Args arg);
ATbool PT_isArgsList(PT_Args arg);
ATbool PT_isArgsEmpty(PT_Args arg);
ATbool PT_hasArgsHead(PT_Args arg);
PT_Tree PT_getArgsHead(PT_Args arg);
PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head);
ATbool PT_hasArgsTail(PT_Args arg);
PT_Args PT_getArgsTail(PT_Args arg);
PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail);

/*}}}  */
/*{{{  PT_Symbols accessors */

ATbool PT_isValidSymbols(PT_Symbols arg);
ATbool PT_isSymbolsList(PT_Symbols arg);
ATbool PT_isSymbolsEmpty(PT_Symbols arg);
ATbool PT_hasSymbolsHead(PT_Symbols arg);
PT_Symbol PT_getSymbolsHead(PT_Symbols arg);
PT_Symbols PT_setSymbolsHead(PT_Symbols arg, PT_Symbol head);
ATbool PT_hasSymbolsTail(PT_Symbols arg);
PT_Symbols PT_getSymbolsTail(PT_Symbols arg);
PT_Symbols PT_setSymbolsTail(PT_Symbols arg, PT_Symbols tail);

/*}}}  */
/*{{{  sort visitors */

PT_ParseTree visitParseTree(PT_ParseTree arg, PT_Layout (*acceptLayoutBeforeTree)(PT_Layout), PT_Tree (*acceptTree)(PT_Tree), PT_Layout (*acceptLayoutAfterTree)(PT_Layout));
PT_ModuleName visitModuleName(PT_ModuleName arg, PT_String (*acceptId)(PT_String));
PT_Tree visitTree(PT_Tree arg, PT_Layout (*acceptLayout)(PT_Layout), PT_Var (*acceptVar)(PT_Var), PT_Production (*acceptProd)(PT_Production), PT_Args (*acceptArgs)(PT_Args), PT_Symbol (*acceptIter)(PT_Symbol), PT_Lexical (*acceptLexical)(PT_Lexical), PT_Literal (*acceptLiteral)(PT_Literal), PT_QLiteral (*acceptQliteral)(PT_QLiteral), PT_Separator (*acceptSeparator)(PT_Separator));
PT_Var visitVar(PT_Var arg, PT_String (*acceptName)(PT_String), PT_Symbol (*acceptSymbol)(PT_Symbol));
PT_Production visitProduction(PT_Production arg, PT_String (*acceptModuleName)(PT_String), PT_Symbols (*acceptLhs)(PT_Symbols), PT_Symbol (*acceptRhs)(PT_Symbol), PT_Attributes (*acceptAttrs)(PT_Attributes));
PT_Attributes visitAttributes(PT_Attributes arg, PT_Attrs (*acceptAttrs)(PT_Attrs));
PT_Attrs visitAttrs(PT_Attrs arg, PT_Attr (*acceptHead)(PT_Attr));
PT_Attr visitAttr(PT_Attr arg, char * (*acceptString)(char *));
PT_Symbol visitSymbol(PT_Symbol arg, PT_Separator (*acceptSeparator)(PT_Separator), PT_String (*acceptString)(PT_String), PT_Literal (*acceptLiteral)(PT_Literal), PT_QLiteral (*acceptQliteral)(PT_QLiteral));
PT_Literal visitLiteral(PT_Literal arg, PT_String (*acceptString)(PT_String));
PT_QLiteral visitQLiteral(PT_QLiteral arg, PT_String (*acceptString)(PT_String));
PT_Lexical visitLexical(PT_Lexical arg, PT_String (*acceptString)(PT_String), PT_Symbol (*acceptSymbol)(PT_Symbol));
PT_Separator visitSeparator(PT_Separator arg, PT_String (*acceptString)(PT_String));
PT_Layout visitLayout(PT_Layout arg, PT_String (*acceptString)(PT_String));
PT_Args visitArgs(PT_Args arg, PT_Tree (*acceptHead)(PT_Tree));
PT_Symbols visitSymbols(PT_Symbols arg, PT_Symbol (*acceptHead)(PT_Symbol));

/*}}}  */

#endif /* _PT_H */
