#ifndef _MEPT_H
#define _MEPT_H

/*{{{  includes */

#include <aterm1.h>
#include "MEPT_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _PT_ParseTree *PT_ParseTree;
typedef struct _PT_Tree *PT_Tree;
typedef struct _PT_Production *PT_Production;
typedef struct _PT_Attributes *PT_Attributes;
typedef struct _PT_Attrs *PT_Attrs;
typedef struct _PT_Attr *PT_Attr;
typedef struct _PT_Args *PT_Args;
typedef struct _PT_Symbol *PT_Symbol;
typedef struct _PT_Symbols *PT_Symbols;

/*}}}  */

void PT_initMEPTApi(void);

/*{{{  term conversion functions */

PT_ParseTree PT_makeParseTreeFromTerm(ATerm t);
ATerm PT_makeTermFromParseTree(PT_ParseTree arg);
PT_Tree PT_makeTreeFromTerm(ATerm t);
ATerm PT_makeTermFromTree(PT_Tree arg);
PT_Production PT_makeProductionFromTerm(ATerm t);
ATerm PT_makeTermFromProduction(PT_Production arg);
PT_Attributes PT_makeAttributesFromTerm(ATerm t);
ATerm PT_makeTermFromAttributes(PT_Attributes arg);
PT_Attrs PT_makeAttrsFromTerm(ATerm t);
ATerm PT_makeTermFromAttrs(PT_Attrs arg);
PT_Attr PT_makeAttrFromTerm(ATerm t);
ATerm PT_makeTermFromAttr(PT_Attr arg);
PT_Args PT_makeArgsFromTerm(ATerm t);
ATerm PT_makeTermFromArgs(PT_Args arg);
PT_Symbol PT_makeSymbolFromTerm(ATerm t);
ATerm PT_makeTermFromSymbol(PT_Symbol arg);
PT_Symbols PT_makeSymbolsFromTerm(ATerm t);
ATerm PT_makeTermFromSymbols(PT_Symbols arg);

/*}}}  */
/*{{{  constructors */

PT_ParseTree PT_makeParseTreeTree(PT_Symbols lhs, PT_Tree layoutBeforeTree, PT_Tree tree, PT_Tree layoutAfterTree, int ambCnt);
PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args);
PT_Tree PT_makeTreeList(PT_Args args);
PT_Tree PT_makeTreeChar(int character);
PT_Tree PT_makeTreeLit(char * string);
PT_Tree PT_makeTreeFlatLayout(char * string);
PT_Tree PT_makeTreeFlatLexical(char * string);
PT_Tree PT_makeTreeAmb(PT_Args args);
PT_Production PT_makeProductionDefault(PT_Symbols lhs, PT_Symbol rhs, PT_Attributes attributes);
PT_Attributes PT_makeAttributesNoAttrs();
PT_Attributes PT_makeAttributesAttrs(PT_Attrs attrs);
PT_Attrs PT_makeAttrsMany(PT_Attr head, PT_Attrs tail);
PT_Attrs PT_makeAttrsSingle(PT_Attr head);
PT_Attr PT_makeAttrCons(char * string);
PT_Attr PT_makeAttrBracket();
PT_Args PT_makeArgsList(PT_Tree head, PT_Args tail);
PT_Args PT_makeArgsEmpty();
PT_Symbol PT_makeSymbolLit(char * string);
PT_Symbol PT_makeSymbolCf(PT_Symbol symbol);
PT_Symbol PT_makeSymbolLex(PT_Symbol symbol);
PT_Symbol PT_makeSymbolOpt(PT_Symbol symbol);
PT_Symbol PT_makeSymbolAlt(PT_Symbol left, PT_Symbol right);
PT_Symbol PT_makeSymbolSort(char * string);
PT_Symbol PT_makeSymbolIterPlus(PT_Symbol symbol);
PT_Symbol PT_makeSymbolIterStar(PT_Symbol symbol);
PT_Symbol PT_makeSymbolIterPlusSep(PT_Symbol symbol, PT_Symbol separator);
PT_Symbol PT_makeSymbolIterStarSep(PT_Symbol symbol, PT_Symbol separator);
PT_Symbol PT_makeSymbolVarSym(PT_Symbol symbol);
PT_Symbol PT_makeSymbolLayout();
PT_Symbols PT_makeSymbolsList(PT_Symbol head, PT_Symbols tail);
PT_Symbols PT_makeSymbolsEmpty();

/*}}}  */
/*{{{  equality functions */

ATbool PT_isEqualParseTree(PT_ParseTree arg0, PT_ParseTree arg1);
ATbool PT_isEqualTree(PT_Tree arg0, PT_Tree arg1);
ATbool PT_isEqualProduction(PT_Production arg0, PT_Production arg1);
ATbool PT_isEqualAttributes(PT_Attributes arg0, PT_Attributes arg1);
ATbool PT_isEqualAttrs(PT_Attrs arg0, PT_Attrs arg1);
ATbool PT_isEqualAttr(PT_Attr arg0, PT_Attr arg1);
ATbool PT_isEqualArgs(PT_Args arg0, PT_Args arg1);
ATbool PT_isEqualSymbol(PT_Symbol arg0, PT_Symbol arg1);
ATbool PT_isEqualSymbols(PT_Symbols arg0, PT_Symbols arg1);

/*}}}  */
/*{{{  PT_ParseTree accessors */

ATbool PT_isValidParseTree(PT_ParseTree arg);
ATbool PT_isParseTreeTree(PT_ParseTree arg);
ATbool PT_hasParseTreeLhs(PT_ParseTree arg);
PT_Symbols PT_getParseTreeLhs(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeLhs(PT_ParseTree arg, PT_Symbols lhs);
ATbool PT_hasParseTreeLayoutBeforeTree(PT_ParseTree arg);
PT_Tree PT_getParseTreeLayoutBeforeTree(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree arg, PT_Tree layoutBeforeTree);
ATbool PT_hasParseTreeTree(PT_ParseTree arg);
PT_Tree PT_getParseTreeTree(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeTree(PT_ParseTree arg, PT_Tree tree);
ATbool PT_hasParseTreeLayoutAfterTree(PT_ParseTree arg);
PT_Tree PT_getParseTreeLayoutAfterTree(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeLayoutAfterTree(PT_ParseTree arg, PT_Tree layoutAfterTree);
ATbool PT_hasParseTreeAmbCnt(PT_ParseTree arg);
int PT_getParseTreeAmbCnt(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeAmbCnt(PT_ParseTree arg, int ambCnt);

/*}}}  */
/*{{{  PT_Tree accessors */

ATbool PT_isValidTree(PT_Tree arg);
ATbool PT_isTreeAppl(PT_Tree arg);
ATbool PT_isTreeList(PT_Tree arg);
ATbool PT_isTreeChar(PT_Tree arg);
ATbool PT_isTreeLit(PT_Tree arg);
ATbool PT_isTreeFlatLayout(PT_Tree arg);
ATbool PT_isTreeFlatLexical(PT_Tree arg);
ATbool PT_isTreeAmb(PT_Tree arg);
ATbool PT_hasTreeProd(PT_Tree arg);
PT_Production PT_getTreeProd(PT_Tree arg);
PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod);
ATbool PT_hasTreeArgs(PT_Tree arg);
PT_Args PT_getTreeArgs(PT_Tree arg);
PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args);
ATbool PT_hasTreeCharacter(PT_Tree arg);
int PT_getTreeCharacter(PT_Tree arg);
PT_Tree PT_setTreeCharacter(PT_Tree arg, int character);
ATbool PT_hasTreeString(PT_Tree arg);
char * PT_getTreeString(PT_Tree arg);
PT_Tree PT_setTreeString(PT_Tree arg, char * string);

/*}}}  */
/*{{{  PT_Production accessors */

ATbool PT_isValidProduction(PT_Production arg);
ATbool PT_isProductionDefault(PT_Production arg);
ATbool PT_hasProductionLhs(PT_Production arg);
PT_Symbols PT_getProductionLhs(PT_Production arg);
PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs);
ATbool PT_hasProductionRhs(PT_Production arg);
PT_Symbol PT_getProductionRhs(PT_Production arg);
PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs);
ATbool PT_hasProductionAttributes(PT_Production arg);
PT_Attributes PT_getProductionAttributes(PT_Production arg);
PT_Production PT_setProductionAttributes(PT_Production arg, PT_Attributes attributes);

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
ATbool PT_hasAttrString(PT_Attr arg);
char * PT_getAttrString(PT_Attr arg);
PT_Attr PT_setAttrString(PT_Attr arg, char * string);

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
/*{{{  PT_Symbol accessors */

ATbool PT_isValidSymbol(PT_Symbol arg);
ATbool PT_isSymbolLit(PT_Symbol arg);
ATbool PT_isSymbolCf(PT_Symbol arg);
ATbool PT_isSymbolLex(PT_Symbol arg);
ATbool PT_isSymbolOpt(PT_Symbol arg);
ATbool PT_isSymbolAlt(PT_Symbol arg);
ATbool PT_isSymbolSort(PT_Symbol arg);
ATbool PT_isSymbolIterPlus(PT_Symbol arg);
ATbool PT_isSymbolIterStar(PT_Symbol arg);
ATbool PT_isSymbolIterPlusSep(PT_Symbol arg);
ATbool PT_isSymbolIterStarSep(PT_Symbol arg);
ATbool PT_isSymbolVarSym(PT_Symbol arg);
ATbool PT_isSymbolLayout(PT_Symbol arg);
ATbool PT_hasSymbolString(PT_Symbol arg);
char * PT_getSymbolString(PT_Symbol arg);
PT_Symbol PT_setSymbolString(PT_Symbol arg, char * string);
ATbool PT_hasSymbolSymbol(PT_Symbol arg);
PT_Symbol PT_getSymbolSymbol(PT_Symbol arg);
PT_Symbol PT_setSymbolSymbol(PT_Symbol arg, PT_Symbol symbol);
ATbool PT_hasSymbolLeft(PT_Symbol arg);
PT_Symbol PT_getSymbolLeft(PT_Symbol arg);
PT_Symbol PT_setSymbolLeft(PT_Symbol arg, PT_Symbol left);
ATbool PT_hasSymbolRight(PT_Symbol arg);
PT_Symbol PT_getSymbolRight(PT_Symbol arg);
PT_Symbol PT_setSymbolRight(PT_Symbol arg, PT_Symbol right);
ATbool PT_hasSymbolSeparator(PT_Symbol arg);
PT_Symbol PT_getSymbolSeparator(PT_Symbol arg);
PT_Symbol PT_setSymbolSeparator(PT_Symbol arg, PT_Symbol separator);

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

PT_ParseTree PT_visitParseTree(PT_ParseTree arg, PT_Symbols (*acceptLhs)(PT_Symbols), PT_Tree (*acceptLayoutBeforeTree)(PT_Tree), PT_Tree (*acceptTree)(PT_Tree), PT_Tree (*acceptLayoutAfterTree)(PT_Tree), int (*acceptAmbCnt)(int));
PT_Tree PT_visitTree(PT_Tree arg, PT_Production (*acceptProd)(PT_Production), PT_Args (*acceptArgs)(PT_Args), int (*acceptCharacter)(int), char * (*acceptString)(char *));
PT_Production PT_visitProduction(PT_Production arg, PT_Symbols (*acceptLhs)(PT_Symbols), PT_Symbol (*acceptRhs)(PT_Symbol), PT_Attributes (*acceptAttributes)(PT_Attributes));
PT_Attributes PT_visitAttributes(PT_Attributes arg, PT_Attrs (*acceptAttrs)(PT_Attrs));
PT_Attrs PT_visitAttrs(PT_Attrs arg, PT_Attr (*acceptHead)(PT_Attr));
PT_Attr PT_visitAttr(PT_Attr arg, char * (*acceptString)(char *));
PT_Args PT_visitArgs(PT_Args arg, PT_Tree (*acceptHead)(PT_Tree));
PT_Symbol PT_visitSymbol(PT_Symbol arg, char * (*acceptString)(char *));
PT_Symbols PT_visitSymbols(PT_Symbols arg, PT_Symbol (*acceptHead)(PT_Symbol));

/*}}}  */

#endif /* _MEPT_H */
