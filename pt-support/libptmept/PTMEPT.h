#ifndef _PTMEPT_H
#define _PTMEPT_H

/*{{{  includes */

#include <aterm1.h>
#include "PTMEPT_dict.h"

/*}}}  */

/*{{{  prologue */

typedef struct _PTPT_CHARLIST *PTPT_CHARLIST;

ATbool PTPT_isValidCHARLIST(PTPT_CHARLIST arg);
ATbool PTPT_isCHARLISTString(PTPT_CHARLIST arg);
char*  PTPT_getCHARLISTString(PTPT_CHARLIST arg);
PTPT_CHARLIST  PTPT_setCHARLISTString(PTPT_CHARLIST arg, char *str);
ATerm  PTPT_CHARLISTToTerm(PTPT_CHARLIST arg);
PTPT_CHARLIST PTPT_CHARLISTFromTerm(ATerm trm);
PTPT_CHARLIST PTPT_makeCHARLISTString(char *str);

/*}}}  */
/*{{{  typedefs */

typedef struct _PTPT_NatCon *PTPT_NatCon;
typedef struct _PTPT_IntCon *PTPT_IntCon;
typedef struct _PTPT_Tree *PTPT_Tree;
typedef struct _PTPT_Args *PTPT_Args;
typedef struct _PTPT_TreeList *PTPT_TreeList;
typedef struct _PTPT_Production *PTPT_Production;
typedef struct _PTPT_Symbol *PTPT_Symbol;
typedef struct _PTPT_Symbols *PTPT_Symbols;
typedef struct _PTPT_SymbolList *PTPT_SymbolList;
typedef struct _PTPT_CharRanges *PTPT_CharRanges;
typedef struct _PTPT_CharRangeList *PTPT_CharRangeList;
typedef struct _PTPT_CharRange *PTPT_CharRange;
typedef struct _PTPT_OptExp *PTPT_OptExp;
typedef struct _PTPT_RealCon *PTPT_RealCon;
typedef struct _PTPT_ATermList *PTPT_ATermList;
typedef struct _PTPT_ATermElems *PTPT_ATermElems;
typedef struct _PTPT_ACon *PTPT_ACon;
typedef struct _PTPT_AFun *PTPT_AFun;
typedef struct _PTPT_ATerm *PTPT_ATerm;
typedef struct _PTPT_ATermArgs *PTPT_ATermArgs;
typedef struct _PTPT_Ann *PTPT_Ann;
typedef struct _PTPT_ATermAnnos *PTPT_ATermAnnos;
typedef struct _PTPT_AlphaNumericalEscChar *PTPT_AlphaNumericalEscChar;
typedef struct _PTPT_DecimalEscChar *PTPT_DecimalEscChar;
typedef struct _PTPT_EscChar *PTPT_EscChar;
typedef struct _PTPT_LChar *PTPT_LChar;
typedef struct _PTPT_QLiteral *PTPT_QLiteral;
typedef struct _PTPT_UQLiteral *PTPT_UQLiteral;
typedef struct _PTPT_Literal *PTPT_Literal;
typedef struct _PTPT_Attributes *PTPT_Attributes;
typedef struct _PTPT_Attrs *PTPT_Attrs;
typedef struct _PTPT_AttrList *PTPT_AttrList;
typedef struct _PTPT_Attr *PTPT_Attr;
typedef struct _PTPT_Associativity *PTPT_Associativity;
typedef struct _PTPT_ParseTree *PTPT_ParseTree;
typedef struct _PTPT_Start *PTPT_Start;
typedef struct _PTPT_OptLayout *PTPT_OptLayout;

/*}}}  */

void PTPT_initPTMEPTApi(void);

/*{{{  term conversion functions */

PTPT_NatCon PTPT_NatConFromTerm(ATerm t);
ATerm PTPT_NatConToTerm(PTPT_NatCon arg);
PTPT_IntCon PTPT_IntConFromTerm(ATerm t);
ATerm PTPT_IntConToTerm(PTPT_IntCon arg);
PTPT_Tree PTPT_TreeFromTerm(ATerm t);
ATerm PTPT_TreeToTerm(PTPT_Tree arg);
PTPT_Args PTPT_ArgsFromTerm(ATerm t);
ATerm PTPT_ArgsToTerm(PTPT_Args arg);
PTPT_TreeList PTPT_TreeListFromTerm(ATerm t);
ATerm PTPT_TreeListToTerm(PTPT_TreeList arg);
PTPT_Production PTPT_ProductionFromTerm(ATerm t);
ATerm PTPT_ProductionToTerm(PTPT_Production arg);
PTPT_Symbol PTPT_SymbolFromTerm(ATerm t);
ATerm PTPT_SymbolToTerm(PTPT_Symbol arg);
PTPT_Symbols PTPT_SymbolsFromTerm(ATerm t);
ATerm PTPT_SymbolsToTerm(PTPT_Symbols arg);
PTPT_SymbolList PTPT_SymbolListFromTerm(ATerm t);
ATerm PTPT_SymbolListToTerm(PTPT_SymbolList arg);
PTPT_CharRanges PTPT_CharRangesFromTerm(ATerm t);
ATerm PTPT_CharRangesToTerm(PTPT_CharRanges arg);
PTPT_CharRangeList PTPT_CharRangeListFromTerm(ATerm t);
ATerm PTPT_CharRangeListToTerm(PTPT_CharRangeList arg);
PTPT_CharRange PTPT_CharRangeFromTerm(ATerm t);
ATerm PTPT_CharRangeToTerm(PTPT_CharRange arg);
PTPT_OptExp PTPT_OptExpFromTerm(ATerm t);
ATerm PTPT_OptExpToTerm(PTPT_OptExp arg);
PTPT_RealCon PTPT_RealConFromTerm(ATerm t);
ATerm PTPT_RealConToTerm(PTPT_RealCon arg);
PTPT_ATermList PTPT_ATermListFromTerm(ATerm t);
ATerm PTPT_ATermListToTerm(PTPT_ATermList arg);
PTPT_ATermElems PTPT_ATermElemsFromTerm(ATerm t);
ATerm PTPT_ATermElemsToTerm(PTPT_ATermElems arg);
PTPT_ACon PTPT_AConFromTerm(ATerm t);
ATerm PTPT_AConToTerm(PTPT_ACon arg);
PTPT_AFun PTPT_AFunFromTerm(ATerm t);
ATerm PTPT_AFunToTerm(PTPT_AFun arg);
PTPT_ATerm PTPT_ATermFromTerm(ATerm t);
ATerm PTPT_ATermToTerm(PTPT_ATerm arg);
PTPT_ATermArgs PTPT_ATermArgsFromTerm(ATerm t);
ATerm PTPT_ATermArgsToTerm(PTPT_ATermArgs arg);
PTPT_Ann PTPT_AnnFromTerm(ATerm t);
ATerm PTPT_AnnToTerm(PTPT_Ann arg);
PTPT_ATermAnnos PTPT_ATermAnnosFromTerm(ATerm t);
ATerm PTPT_ATermAnnosToTerm(PTPT_ATermAnnos arg);
PTPT_AlphaNumericalEscChar PTPT_AlphaNumericalEscCharFromTerm(ATerm t);
ATerm PTPT_AlphaNumericalEscCharToTerm(PTPT_AlphaNumericalEscChar arg);
PTPT_DecimalEscChar PTPT_DecimalEscCharFromTerm(ATerm t);
ATerm PTPT_DecimalEscCharToTerm(PTPT_DecimalEscChar arg);
PTPT_EscChar PTPT_EscCharFromTerm(ATerm t);
ATerm PTPT_EscCharToTerm(PTPT_EscChar arg);
PTPT_LChar PTPT_LCharFromTerm(ATerm t);
ATerm PTPT_LCharToTerm(PTPT_LChar arg);
PTPT_QLiteral PTPT_QLiteralFromTerm(ATerm t);
ATerm PTPT_QLiteralToTerm(PTPT_QLiteral arg);
PTPT_UQLiteral PTPT_UQLiteralFromTerm(ATerm t);
ATerm PTPT_UQLiteralToTerm(PTPT_UQLiteral arg);
PTPT_Literal PTPT_LiteralFromTerm(ATerm t);
ATerm PTPT_LiteralToTerm(PTPT_Literal arg);
PTPT_Attributes PTPT_AttributesFromTerm(ATerm t);
ATerm PTPT_AttributesToTerm(PTPT_Attributes arg);
PTPT_Attrs PTPT_AttrsFromTerm(ATerm t);
ATerm PTPT_AttrsToTerm(PTPT_Attrs arg);
PTPT_AttrList PTPT_AttrListFromTerm(ATerm t);
ATerm PTPT_AttrListToTerm(PTPT_AttrList arg);
PTPT_Attr PTPT_AttrFromTerm(ATerm t);
ATerm PTPT_AttrToTerm(PTPT_Attr arg);
PTPT_Associativity PTPT_AssociativityFromTerm(ATerm t);
ATerm PTPT_AssociativityToTerm(PTPT_Associativity arg);
PTPT_ParseTree PTPT_ParseTreeFromTerm(ATerm t);
ATerm PTPT_ParseTreeToTerm(PTPT_ParseTree arg);
PTPT_Start PTPT_StartFromTerm(ATerm t);
ATerm PTPT_StartToTerm(PTPT_Start arg);
PTPT_OptLayout PTPT_OptLayoutFromTerm(ATerm t);
ATerm PTPT_OptLayoutToTerm(PTPT_OptLayout arg);

/*}}}  */
/*{{{  constructors */

PTPT_NatCon PTPT_makeNatConDigits(PTPT_CHARLIST chars);
PTPT_IntCon PTPT_makeIntConNatural(PTPT_NatCon NatCon);
PTPT_IntCon PTPT_makeIntConPositive(PTPT_OptLayout wsAfterPos, PTPT_NatCon NatCon);
PTPT_IntCon PTPT_makeIntConNegative(PTPT_OptLayout wsAfterNeg, PTPT_NatCon NatCon);
PTPT_Tree PTPT_makeTreeAnnotated(PTPT_Tree Tree, PTPT_OptLayout wsAfterTree, PTPT_Ann Ann);
PTPT_Tree PTPT_makeTreeAppl(PTPT_OptLayout wsAfterAppl, PTPT_OptLayout wsAfterParenOpen, PTPT_Production prod, PTPT_OptLayout wsAfterProd, PTPT_OptLayout wsAfterComma, PTPT_Args args, PTPT_OptLayout wsAfterArgs);
PTPT_Tree PTPT_makeTreeChar(PTPT_NatCon character);
PTPT_Tree PTPT_makeTreeLit(PTPT_OptLayout wsAfterLit, PTPT_OptLayout wsAfterParenOpen, PTPT_QLiteral string, PTPT_OptLayout wsAfterString);
PTPT_Tree PTPT_makeTreeAmb(PTPT_OptLayout wsAfterAmb, PTPT_OptLayout wsAfterParenOpen, PTPT_Args args, PTPT_OptLayout wsAfterArgs);
PTPT_Args PTPT_makeArgsList(PTPT_OptLayout wsAfterBracketOpen, PTPT_TreeList list, PTPT_OptLayout wsAfterList);
PTPT_TreeList PTPT_makeTreeListEmpty();
PTPT_TreeList PTPT_makeTreeListSingle(PTPT_Tree head);
PTPT_TreeList PTPT_makeTreeListMany(PTPT_Tree head, PTPT_OptLayout wsAfterFirst, char * sep, PTPT_OptLayout wsAfterSep, PTPT_TreeList tail);
PTPT_Production PTPT_makeProductionDefault(PTPT_OptLayout wsAfterProd, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma1, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs, PTPT_OptLayout wsAfterComma2, PTPT_Attributes attributes, PTPT_OptLayout wsAfterAttributes);
PTPT_Production PTPT_makeProductionList(PTPT_OptLayout wsAfterList, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs);
PTPT_Symbol PTPT_makeSymbolEmpty();
PTPT_Symbol PTPT_makeSymbolLit(PTPT_OptLayout wsAfterLit, PTPT_OptLayout wsAfterParenOpen, PTPT_QLiteral string, PTPT_OptLayout wsAfterString);
PTPT_Symbol PTPT_makeSymbolCf(PTPT_OptLayout wsAfterCf, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolLex(PTPT_OptLayout wsAfterLex, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolOpt(PTPT_OptLayout wsAfterOpt, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolAlt(PTPT_OptLayout wsAfterAlt, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs);
PTPT_Symbol PTPT_makeSymbolSeq(PTPT_OptLayout wsAfterSeq, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs);
PTPT_Symbol PTPT_makeSymbolTuple(PTPT_OptLayout wsAfterTuple, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterComma, PTPT_Symbols rest, PTPT_OptLayout wsAfterRest);
PTPT_Symbol PTPT_makeSymbolSort(PTPT_OptLayout wsAfterSort, PTPT_OptLayout wsAfterParenOpen, PTPT_QLiteral string, PTPT_OptLayout wsAfterString);
PTPT_Symbol PTPT_makeSymbolIter(PTPT_OptLayout wsAfterIter, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolIterStar(PTPT_OptLayout wsAfterIterStar, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolIterSep(PTPT_OptLayout wsAfterIterSep, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator);
PTPT_Symbol PTPT_makeSymbolIterStarSep(PTPT_OptLayout wsAfterIterStarSep, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator);
PTPT_Symbol PTPT_makeSymbolIterN(PTPT_OptLayout wsAfterIterN, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_NatCon number, PTPT_OptLayout wsAfterNumber);
PTPT_Symbol PTPT_makeSymbolIterSepN(PTPT_OptLayout wsAfterIterSepN, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma1, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator, PTPT_OptLayout wsAfterComma2, PTPT_NatCon number, PTPT_OptLayout wsAfterNumber);
PTPT_Symbol PTPT_makeSymbolFunc(PTPT_OptLayout wsAfterFunc, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols symbols, PTPT_OptLayout wsAfterSymbols, PTPT_OptLayout wsAfterComma, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolVarsym(PTPT_OptLayout wsAfterVarsym, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolLayout();
PTPT_Symbol PTPT_makeSymbolCharClass(PTPT_OptLayout wsAfterCharClass, PTPT_OptLayout wsAfterParenOpen, PTPT_CharRanges CharRanges, PTPT_OptLayout wsAfterCharRanges);
PTPT_Symbol PTPT_makeSymbolStrategy(PTPT_OptLayout wsAfterStrategy, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs);
PTPT_Symbol PTPT_makeSymbolParametrizedSort(PTPT_OptLayout wsAfterParametrizedSort, PTPT_OptLayout wsAfterParenOpen, PTPT_QLiteral sort, PTPT_OptLayout wsAfterSort, PTPT_OptLayout wsAfterComma, PTPT_Symbols parameters, PTPT_OptLayout wsAfterParameters);
PTPT_Symbols PTPT_makeSymbolsList(PTPT_OptLayout wsAfterBracketOpen, PTPT_SymbolList list, PTPT_OptLayout wsAfterList);
PTPT_SymbolList PTPT_makeSymbolListEmpty();
PTPT_SymbolList PTPT_makeSymbolListSingle(PTPT_Symbol head);
PTPT_SymbolList PTPT_makeSymbolListMany(PTPT_Symbol head, PTPT_OptLayout wsAfterFirst, char * sep, PTPT_OptLayout wsAfterSep, PTPT_SymbolList tail);
PTPT_CharRanges PTPT_makeCharRangesList(PTPT_OptLayout wsAfterBracketOpen, PTPT_CharRangeList list, PTPT_OptLayout wsAfterList);
PTPT_CharRangeList PTPT_makeCharRangeListEmpty();
PTPT_CharRangeList PTPT_makeCharRangeListSingle(PTPT_CharRange head);
PTPT_CharRangeList PTPT_makeCharRangeListMany(PTPT_CharRange head, PTPT_OptLayout wsAfterFirst, char * sep, PTPT_OptLayout wsAfterSep, PTPT_CharRangeList tail);
PTPT_CharRange PTPT_makeCharRangeCharacter(PTPT_NatCon integer);
PTPT_CharRange PTPT_makeCharRangeRange(PTPT_OptLayout wsAfterRange, PTPT_OptLayout wsAfterParenOpen, PTPT_NatCon start, PTPT_OptLayout wsAfterStart, PTPT_OptLayout wsAfterComma, PTPT_NatCon end, PTPT_OptLayout wsAfterEnd);
PTPT_OptExp PTPT_makeOptExpPresent(PTPT_OptLayout wsAfterE, PTPT_IntCon IntCon);
PTPT_OptExp PTPT_makeOptExpAbsent();
PTPT_RealCon PTPT_makeRealConRealCon(PTPT_IntCon IntCon, PTPT_OptLayout wsAfterIntCon, PTPT_OptLayout wsAfterPeriod, PTPT_NatCon NatCon, PTPT_OptLayout wsAfterNatCon, PTPT_OptExp OptExp);
PTPT_ATermList PTPT_makeATermListNotEmpty(PTPT_OptLayout wsAfterBracketOpen, PTPT_ATermElems elems, PTPT_OptLayout wsAfterElems);
PTPT_ATermElems PTPT_makeATermElemsEmpty();
PTPT_ATermElems PTPT_makeATermElemsSingle(PTPT_ATerm head);
PTPT_ATermElems PTPT_makeATermElemsMany(PTPT_ATerm head, PTPT_OptLayout wsAfterFirst, char * sep, PTPT_OptLayout wsAfterSep, PTPT_ATermElems tail);
PTPT_ACon PTPT_makeAConInt(PTPT_IntCon IntCon);
PTPT_ACon PTPT_makeAConReal(PTPT_RealCon RealCon);
PTPT_AFun PTPT_makeAFunDefault(PTPT_Literal Literal);
PTPT_ATerm PTPT_makeATermConstant(PTPT_ACon ACon);
PTPT_ATerm PTPT_makeATermList(PTPT_ATermList list);
PTPT_ATerm PTPT_makeATermFun(PTPT_AFun fun);
PTPT_ATerm PTPT_makeATermAppl(PTPT_AFun fun, PTPT_OptLayout wsAfterFun, PTPT_OptLayout wsAfterParenOpen, PTPT_ATermArgs args, PTPT_OptLayout wsAfterArgs);
PTPT_ATerm PTPT_makeATermAnnotatedConstant(PTPT_ACon ACon, PTPT_OptLayout wsAfterACon, PTPT_Ann Ann);
PTPT_ATerm PTPT_makeATermAnnotatedList(PTPT_ATermList list, PTPT_OptLayout wsAfterList, PTPT_Ann Ann);
PTPT_ATerm PTPT_makeATermAnnotatedFun(PTPT_AFun fun, PTPT_OptLayout wsAfterFun, PTPT_Ann Ann);
PTPT_ATerm PTPT_makeATermAnnotatedAppl(PTPT_AFun fun, PTPT_OptLayout wsAfterFun, PTPT_OptLayout wsAfterParenOpen, PTPT_ATermArgs args, PTPT_OptLayout wsAfterArgs, PTPT_OptLayout wsAfterParenClose, PTPT_Ann Ann);
PTPT_ATermArgs PTPT_makeATermArgsSingle(PTPT_ATerm head);
PTPT_ATermArgs PTPT_makeATermArgsMany(PTPT_ATerm head, PTPT_OptLayout wsAfterFirst, char * sep, PTPT_OptLayout wsAfterSep, PTPT_ATermArgs tail);
PTPT_Ann PTPT_makeAnnAnnotation(PTPT_OptLayout wsAfterBraceOpen, PTPT_ATermAnnos annos, PTPT_OptLayout wsAfterAnnos);
PTPT_ATermAnnos PTPT_makeATermAnnosSingle(PTPT_ATerm head);
PTPT_ATermAnnos PTPT_makeATermAnnosMany(PTPT_ATerm head, PTPT_OptLayout wsAfterFirst, char * sep, PTPT_OptLayout wsAfterSep, PTPT_ATermAnnos tail);
PTPT_AlphaNumericalEscChar PTPT_makeAlphaNumericalEscCharDefault(PTPT_CHARLIST chars);
PTPT_DecimalEscChar PTPT_makeDecimalEscCharDec0Underscore199(PTPT_CHARLIST chars);
PTPT_DecimalEscChar PTPT_makeDecimalEscCharDec200Underscore249(PTPT_CHARLIST chars);
PTPT_DecimalEscChar PTPT_makeDecimalEscCharDec250Underscore255(PTPT_CHARLIST chars);
PTPT_EscChar PTPT_makeEscCharAlphaNumeric(PTPT_CHARLIST chars);
PTPT_EscChar PTPT_makeEscCharDecimal(PTPT_CHARLIST chars);
PTPT_LChar PTPT_makeLCharNormal(PTPT_CHARLIST chars);
PTPT_LChar PTPT_makeLCharEscaped(PTPT_CHARLIST chars);
PTPT_QLiteral PTPT_makeQLiteralQuoted(PTPT_CHARLIST chars);
PTPT_UQLiteral PTPT_makeUQLiteralOneChar(PTPT_CHARLIST chars);
PTPT_UQLiteral PTPT_makeUQLiteralMoreChars(PTPT_CHARLIST chars);
PTPT_Literal PTPT_makeLiteralQlit(PTPT_QLiteral QLiteral);
PTPT_Literal PTPT_makeLiteralUqlit(PTPT_UQLiteral UQLiteral);
PTPT_Attributes PTPT_makeAttributesNoAttrs();
PTPT_Attributes PTPT_makeAttributesAttrs(PTPT_OptLayout wsAfterAttrs, PTPT_OptLayout wsAfterParenOpen, PTPT_Attrs attributes, PTPT_OptLayout wsAfterAttributes);
PTPT_Attrs PTPT_makeAttrsMany(PTPT_OptLayout wsAfterBracketOpen, PTPT_AttrList list, PTPT_OptLayout wsAfterList);
PTPT_AttrList PTPT_makeAttrListSingle(PTPT_Attr head);
PTPT_AttrList PTPT_makeAttrListMany(PTPT_Attr head, PTPT_OptLayout wsAfterFirst, char * sep, PTPT_OptLayout wsAfterSep, PTPT_AttrList tail);
PTPT_Attr PTPT_makeAttrAssoc(PTPT_OptLayout wsAfterAssoc, PTPT_OptLayout wsAfterParenOpen, PTPT_Associativity associativity, PTPT_OptLayout wsAfterAssociativity);
PTPT_Attr PTPT_makeAttrTerm(PTPT_OptLayout wsAfterTerm, PTPT_OptLayout wsAfterParenOpen, PTPT_ATerm aterm, PTPT_OptLayout wsAfterAterm);
PTPT_Attr PTPT_makeAttrId(PTPT_OptLayout wsAfterId, PTPT_OptLayout wsAfterParenOpen, PTPT_QLiteral moduleName, PTPT_OptLayout wsAfterModuleName);
PTPT_Attr PTPT_makeAttrBracket();
PTPT_Attr PTPT_makeAttrReject();
PTPT_Attr PTPT_makeAttrPrefer();
PTPT_Attr PTPT_makeAttrAvoid();
PTPT_Associativity PTPT_makeAssociativityLeft();
PTPT_Associativity PTPT_makeAssociativityRight();
PTPT_Associativity PTPT_makeAssociativityAssoc();
PTPT_Associativity PTPT_makeAssociativityNonAssoc();
PTPT_ParseTree PTPT_makeParseTreeTop(PTPT_OptLayout wsAfterParsetree, PTPT_OptLayout wsAfterParenOpen, PTPT_Tree top, PTPT_OptLayout wsAfterTop, PTPT_OptLayout wsAfterComma, PTPT_NatCon ambCnt, PTPT_OptLayout wsAfterAmbCnt);
PTPT_Start PTPT_makeStartParseTree(PTPT_OptLayout wsBefore, PTPT_ParseTree topParseTree, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartAssociativity(PTPT_OptLayout wsBefore, PTPT_Associativity topAssociativity, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartAttr(PTPT_OptLayout wsBefore, PTPT_Attr topAttr, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartAttrs(PTPT_OptLayout wsBefore, PTPT_Attrs topAttrs, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartAttributes(PTPT_OptLayout wsBefore, PTPT_Attributes topAttributes, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartQLiteral(PTPT_OptLayout wsBefore, PTPT_QLiteral topQLiteral, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartUQLiteral(PTPT_OptLayout wsBefore, PTPT_UQLiteral topUQLiteral, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartLiteral(PTPT_OptLayout wsBefore, PTPT_Literal topLiteral, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartAnn(PTPT_OptLayout wsBefore, PTPT_Ann topAnn, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartATerm(PTPT_OptLayout wsBefore, PTPT_ATerm topATerm, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartAFun(PTPT_OptLayout wsBefore, PTPT_AFun topAFun, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartACon(PTPT_OptLayout wsBefore, PTPT_ACon topACon, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartATermList(PTPT_OptLayout wsBefore, PTPT_ATermList topATermList, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartRealCon(PTPT_OptLayout wsBefore, PTPT_RealCon topRealCon, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartOptExp(PTPT_OptLayout wsBefore, PTPT_OptExp topOptExp, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartCharRanges(PTPT_OptLayout wsBefore, PTPT_CharRanges topCharRanges, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartCharRange(PTPT_OptLayout wsBefore, PTPT_CharRange topCharRange, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartSymbols(PTPT_OptLayout wsBefore, PTPT_Symbols topSymbols, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartSymbol(PTPT_OptLayout wsBefore, PTPT_Symbol topSymbol, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartProduction(PTPT_OptLayout wsBefore, PTPT_Production topProduction, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartArgs(PTPT_OptLayout wsBefore, PTPT_Args topArgs, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartTree(PTPT_OptLayout wsBefore, PTPT_Tree topTree, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartIntCon(PTPT_OptLayout wsBefore, PTPT_IntCon topIntCon, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartNatCon(PTPT_OptLayout wsBefore, PTPT_NatCon topNatCon, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_OptLayout PTPT_makeOptLayoutAbsent();
PTPT_OptLayout PTPT_makeOptLayoutPresent(PTPT_CHARLIST chars);

/*}}}  */
/*{{{  equality functions */

ATbool PTPT_isEqualNatCon(PTPT_NatCon arg0, PTPT_NatCon arg1);
ATbool PTPT_isEqualIntCon(PTPT_IntCon arg0, PTPT_IntCon arg1);
ATbool PTPT_isEqualTree(PTPT_Tree arg0, PTPT_Tree arg1);
ATbool PTPT_isEqualArgs(PTPT_Args arg0, PTPT_Args arg1);
ATbool PTPT_isEqualTreeList(PTPT_TreeList arg0, PTPT_TreeList arg1);
ATbool PTPT_isEqualProduction(PTPT_Production arg0, PTPT_Production arg1);
ATbool PTPT_isEqualSymbol(PTPT_Symbol arg0, PTPT_Symbol arg1);
ATbool PTPT_isEqualSymbols(PTPT_Symbols arg0, PTPT_Symbols arg1);
ATbool PTPT_isEqualSymbolList(PTPT_SymbolList arg0, PTPT_SymbolList arg1);
ATbool PTPT_isEqualCharRanges(PTPT_CharRanges arg0, PTPT_CharRanges arg1);
ATbool PTPT_isEqualCharRangeList(PTPT_CharRangeList arg0, PTPT_CharRangeList arg1);
ATbool PTPT_isEqualCharRange(PTPT_CharRange arg0, PTPT_CharRange arg1);
ATbool PTPT_isEqualOptExp(PTPT_OptExp arg0, PTPT_OptExp arg1);
ATbool PTPT_isEqualRealCon(PTPT_RealCon arg0, PTPT_RealCon arg1);
ATbool PTPT_isEqualATermList(PTPT_ATermList arg0, PTPT_ATermList arg1);
ATbool PTPT_isEqualATermElems(PTPT_ATermElems arg0, PTPT_ATermElems arg1);
ATbool PTPT_isEqualACon(PTPT_ACon arg0, PTPT_ACon arg1);
ATbool PTPT_isEqualAFun(PTPT_AFun arg0, PTPT_AFun arg1);
ATbool PTPT_isEqualATerm(PTPT_ATerm arg0, PTPT_ATerm arg1);
ATbool PTPT_isEqualATermArgs(PTPT_ATermArgs arg0, PTPT_ATermArgs arg1);
ATbool PTPT_isEqualAnn(PTPT_Ann arg0, PTPT_Ann arg1);
ATbool PTPT_isEqualATermAnnos(PTPT_ATermAnnos arg0, PTPT_ATermAnnos arg1);
ATbool PTPT_isEqualAlphaNumericalEscChar(PTPT_AlphaNumericalEscChar arg0, PTPT_AlphaNumericalEscChar arg1);
ATbool PTPT_isEqualDecimalEscChar(PTPT_DecimalEscChar arg0, PTPT_DecimalEscChar arg1);
ATbool PTPT_isEqualEscChar(PTPT_EscChar arg0, PTPT_EscChar arg1);
ATbool PTPT_isEqualLChar(PTPT_LChar arg0, PTPT_LChar arg1);
ATbool PTPT_isEqualQLiteral(PTPT_QLiteral arg0, PTPT_QLiteral arg1);
ATbool PTPT_isEqualUQLiteral(PTPT_UQLiteral arg0, PTPT_UQLiteral arg1);
ATbool PTPT_isEqualLiteral(PTPT_Literal arg0, PTPT_Literal arg1);
ATbool PTPT_isEqualAttributes(PTPT_Attributes arg0, PTPT_Attributes arg1);
ATbool PTPT_isEqualAttrs(PTPT_Attrs arg0, PTPT_Attrs arg1);
ATbool PTPT_isEqualAttrList(PTPT_AttrList arg0, PTPT_AttrList arg1);
ATbool PTPT_isEqualAttr(PTPT_Attr arg0, PTPT_Attr arg1);
ATbool PTPT_isEqualAssociativity(PTPT_Associativity arg0, PTPT_Associativity arg1);
ATbool PTPT_isEqualParseTree(PTPT_ParseTree arg0, PTPT_ParseTree arg1);
ATbool PTPT_isEqualStart(PTPT_Start arg0, PTPT_Start arg1);
ATbool PTPT_isEqualOptLayout(PTPT_OptLayout arg0, PTPT_OptLayout arg1);

/*}}}  */
/*{{{  PTPT_NatCon accessors */

ATbool PTPT_isValidNatCon(PTPT_NatCon arg);
inline ATbool PTPT_isNatConDigits(PTPT_NatCon arg);
ATbool PTPT_hasNatConChars(PTPT_NatCon arg);
PTPT_CHARLIST PTPT_getNatConChars(PTPT_NatCon arg);
PTPT_NatCon PTPT_setNatConChars(PTPT_NatCon arg, PTPT_CHARLIST chars);

/*}}}  */
/*{{{  PTPT_IntCon accessors */

ATbool PTPT_isValidIntCon(PTPT_IntCon arg);
inline ATbool PTPT_isIntConNatural(PTPT_IntCon arg);
inline ATbool PTPT_isIntConPositive(PTPT_IntCon arg);
inline ATbool PTPT_isIntConNegative(PTPT_IntCon arg);
ATbool PTPT_hasIntConNatCon(PTPT_IntCon arg);
PTPT_NatCon PTPT_getIntConNatCon(PTPT_IntCon arg);
PTPT_IntCon PTPT_setIntConNatCon(PTPT_IntCon arg, PTPT_NatCon NatCon);
ATbool PTPT_hasIntConWsAfterPos(PTPT_IntCon arg);
PTPT_OptLayout PTPT_getIntConWsAfterPos(PTPT_IntCon arg);
PTPT_IntCon PTPT_setIntConWsAfterPos(PTPT_IntCon arg, PTPT_OptLayout wsAfterPos);
ATbool PTPT_hasIntConWsAfterNeg(PTPT_IntCon arg);
PTPT_OptLayout PTPT_getIntConWsAfterNeg(PTPT_IntCon arg);
PTPT_IntCon PTPT_setIntConWsAfterNeg(PTPT_IntCon arg, PTPT_OptLayout wsAfterNeg);

/*}}}  */
/*{{{  PTPT_Tree accessors */

ATbool PTPT_isValidTree(PTPT_Tree arg);
inline ATbool PTPT_isTreeAnnotated(PTPT_Tree arg);
inline ATbool PTPT_isTreeAppl(PTPT_Tree arg);
inline ATbool PTPT_isTreeChar(PTPT_Tree arg);
inline ATbool PTPT_isTreeLit(PTPT_Tree arg);
inline ATbool PTPT_isTreeAmb(PTPT_Tree arg);
ATbool PTPT_hasTreeTree(PTPT_Tree arg);
PTPT_Tree PTPT_getTreeTree(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeTree(PTPT_Tree arg, PTPT_Tree Tree);
ATbool PTPT_hasTreeWsAfterTree(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterTree(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterTree(PTPT_Tree arg, PTPT_OptLayout wsAfterTree);
ATbool PTPT_hasTreeAnn(PTPT_Tree arg);
PTPT_Ann PTPT_getTreeAnn(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeAnn(PTPT_Tree arg, PTPT_Ann Ann);
ATbool PTPT_hasTreeWsAfterAppl(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterAppl(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterAppl(PTPT_Tree arg, PTPT_OptLayout wsAfterAppl);
ATbool PTPT_hasTreeWsAfterParenOpen(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterParenOpen(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterParenOpen(PTPT_Tree arg, PTPT_OptLayout wsAfterParenOpen);
ATbool PTPT_hasTreeProd(PTPT_Tree arg);
PTPT_Production PTPT_getTreeProd(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeProd(PTPT_Tree arg, PTPT_Production prod);
ATbool PTPT_hasTreeWsAfterProd(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterProd(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterProd(PTPT_Tree arg, PTPT_OptLayout wsAfterProd);
ATbool PTPT_hasTreeWsAfterComma(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterComma(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterComma(PTPT_Tree arg, PTPT_OptLayout wsAfterComma);
ATbool PTPT_hasTreeArgs(PTPT_Tree arg);
PTPT_Args PTPT_getTreeArgs(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeArgs(PTPT_Tree arg, PTPT_Args args);
ATbool PTPT_hasTreeWsAfterArgs(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterArgs(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterArgs(PTPT_Tree arg, PTPT_OptLayout wsAfterArgs);
ATbool PTPT_hasTreeCharacter(PTPT_Tree arg);
PTPT_NatCon PTPT_getTreeCharacter(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeCharacter(PTPT_Tree arg, PTPT_NatCon character);
ATbool PTPT_hasTreeWsAfterLit(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterLit(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterLit(PTPT_Tree arg, PTPT_OptLayout wsAfterLit);
ATbool PTPT_hasTreeString(PTPT_Tree arg);
PTPT_QLiteral PTPT_getTreeString(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeString(PTPT_Tree arg, PTPT_QLiteral string);
ATbool PTPT_hasTreeWsAfterString(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterString(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterString(PTPT_Tree arg, PTPT_OptLayout wsAfterString);
ATbool PTPT_hasTreeWsAfterAmb(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterAmb(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeWsAfterAmb(PTPT_Tree arg, PTPT_OptLayout wsAfterAmb);

/*}}}  */
/*{{{  PTPT_Args accessors */

ATbool PTPT_isValidArgs(PTPT_Args arg);
inline ATbool PTPT_isArgsList(PTPT_Args arg);
ATbool PTPT_hasArgsWsAfterBracketOpen(PTPT_Args arg);
PTPT_OptLayout PTPT_getArgsWsAfterBracketOpen(PTPT_Args arg);
PTPT_Args PTPT_setArgsWsAfterBracketOpen(PTPT_Args arg, PTPT_OptLayout wsAfterBracketOpen);
ATbool PTPT_hasArgsList(PTPT_Args arg);
PTPT_TreeList PTPT_getArgsList(PTPT_Args arg);
PTPT_Args PTPT_setArgsList(PTPT_Args arg, PTPT_TreeList list);
ATbool PTPT_hasArgsWsAfterList(PTPT_Args arg);
PTPT_OptLayout PTPT_getArgsWsAfterList(PTPT_Args arg);
PTPT_Args PTPT_setArgsWsAfterList(PTPT_Args arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_TreeList accessors */

ATbool PTPT_isValidTreeList(PTPT_TreeList arg);
inline ATbool PTPT_isTreeListEmpty(PTPT_TreeList arg);
inline ATbool PTPT_isTreeListSingle(PTPT_TreeList arg);
inline ATbool PTPT_isTreeListMany(PTPT_TreeList arg);
ATbool PTPT_hasTreeListHead(PTPT_TreeList arg);
PTPT_Tree PTPT_getTreeListHead(PTPT_TreeList arg);
PTPT_TreeList PTPT_setTreeListHead(PTPT_TreeList arg, PTPT_Tree head);
ATbool PTPT_hasTreeListWsAfterFirst(PTPT_TreeList arg);
PTPT_OptLayout PTPT_getTreeListWsAfterFirst(PTPT_TreeList arg);
PTPT_TreeList PTPT_setTreeListWsAfterFirst(PTPT_TreeList arg, PTPT_OptLayout wsAfterFirst);
ATbool PTPT_hasTreeListSep(PTPT_TreeList arg);
char * PTPT_getTreeListSep(PTPT_TreeList arg);
PTPT_TreeList PTPT_setTreeListSep(PTPT_TreeList arg, char * sep);
ATbool PTPT_hasTreeListWsAfterSep(PTPT_TreeList arg);
PTPT_OptLayout PTPT_getTreeListWsAfterSep(PTPT_TreeList arg);
PTPT_TreeList PTPT_setTreeListWsAfterSep(PTPT_TreeList arg, PTPT_OptLayout wsAfterSep);
ATbool PTPT_hasTreeListTail(PTPT_TreeList arg);
PTPT_TreeList PTPT_getTreeListTail(PTPT_TreeList arg);
PTPT_TreeList PTPT_setTreeListTail(PTPT_TreeList arg, PTPT_TreeList tail);

/*}}}  */
/*{{{  PTPT_Production accessors */

ATbool PTPT_isValidProduction(PTPT_Production arg);
inline ATbool PTPT_isProductionDefault(PTPT_Production arg);
inline ATbool PTPT_isProductionList(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterProd(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterProd(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterProd(PTPT_Production arg, PTPT_OptLayout wsAfterProd);
ATbool PTPT_hasProductionWsAfterParenOpen(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterParenOpen(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterParenOpen(PTPT_Production arg, PTPT_OptLayout wsAfterParenOpen);
ATbool PTPT_hasProductionLhs(PTPT_Production arg);
PTPT_Symbols PTPT_getProductionLhs(PTPT_Production arg);
PTPT_Production PTPT_setProductionLhs(PTPT_Production arg, PTPT_Symbols lhs);
ATbool PTPT_hasProductionWsAfterLhs(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterLhs(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterLhs(PTPT_Production arg, PTPT_OptLayout wsAfterLhs);
ATbool PTPT_hasProductionWsAfterComma1(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterComma1(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterComma1(PTPT_Production arg, PTPT_OptLayout wsAfterComma1);
ATbool PTPT_hasProductionRhs(PTPT_Production arg);
PTPT_Symbol PTPT_getProductionRhs(PTPT_Production arg);
PTPT_Production PTPT_setProductionRhs(PTPT_Production arg, PTPT_Symbol rhs);
ATbool PTPT_hasProductionWsAfterRhs(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterRhs(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterRhs(PTPT_Production arg, PTPT_OptLayout wsAfterRhs);
ATbool PTPT_hasProductionWsAfterComma2(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterComma2(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterComma2(PTPT_Production arg, PTPT_OptLayout wsAfterComma2);
ATbool PTPT_hasProductionAttributes(PTPT_Production arg);
PTPT_Attributes PTPT_getProductionAttributes(PTPT_Production arg);
PTPT_Production PTPT_setProductionAttributes(PTPT_Production arg, PTPT_Attributes attributes);
ATbool PTPT_hasProductionWsAfterAttributes(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterAttributes(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterAttributes(PTPT_Production arg, PTPT_OptLayout wsAfterAttributes);
ATbool PTPT_hasProductionWsAfterList(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterList(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterList(PTPT_Production arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_Symbol accessors */

ATbool PTPT_isValidSymbol(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolEmpty(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolLit(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolCf(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolLex(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolOpt(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolAlt(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolSeq(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolTuple(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolSort(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolIter(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolIterStar(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolIterSep(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolIterStarSep(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolIterN(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolIterSepN(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolFunc(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolVarsym(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolLayout(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolCharClass(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolStrategy(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolParametrizedSort(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterLit(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterLit(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterLit(PTPT_Symbol arg, PTPT_OptLayout wsAfterLit);
ATbool PTPT_hasSymbolWsAfterParenOpen(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterParenOpen(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterParenOpen(PTPT_Symbol arg, PTPT_OptLayout wsAfterParenOpen);
ATbool PTPT_hasSymbolString(PTPT_Symbol arg);
PTPT_QLiteral PTPT_getSymbolString(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolString(PTPT_Symbol arg, PTPT_QLiteral string);
ATbool PTPT_hasSymbolWsAfterString(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterString(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterString(PTPT_Symbol arg, PTPT_OptLayout wsAfterString);
ATbool PTPT_hasSymbolWsAfterCf(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterCf(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterCf(PTPT_Symbol arg, PTPT_OptLayout wsAfterCf);
ATbool PTPT_hasSymbolSymbol(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolSymbol(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolSymbol(PTPT_Symbol arg, PTPT_Symbol symbol);
ATbool PTPT_hasSymbolWsAfterSymbol(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSymbol(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterSymbol(PTPT_Symbol arg, PTPT_OptLayout wsAfterSymbol);
ATbool PTPT_hasSymbolWsAfterLex(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterLex(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterLex(PTPT_Symbol arg, PTPT_OptLayout wsAfterLex);
ATbool PTPT_hasSymbolWsAfterOpt(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterOpt(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterOpt(PTPT_Symbol arg, PTPT_OptLayout wsAfterOpt);
ATbool PTPT_hasSymbolWsAfterAlt(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterAlt(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterAlt(PTPT_Symbol arg, PTPT_OptLayout wsAfterAlt);
ATbool PTPT_hasSymbolLhs(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolLhs(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolLhs(PTPT_Symbol arg, PTPT_Symbol lhs);
ATbool PTPT_hasSymbolWsAfterLhs(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterLhs(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterLhs(PTPT_Symbol arg, PTPT_OptLayout wsAfterLhs);
ATbool PTPT_hasSymbolWsAfterComma(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterComma(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterComma(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma);
ATbool PTPT_hasSymbolRhs(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolRhs(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolRhs(PTPT_Symbol arg, PTPT_Symbol rhs);
ATbool PTPT_hasSymbolWsAfterRhs(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterRhs(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterRhs(PTPT_Symbol arg, PTPT_OptLayout wsAfterRhs);
ATbool PTPT_hasSymbolWsAfterSeq(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSeq(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterSeq(PTPT_Symbol arg, PTPT_OptLayout wsAfterSeq);
ATbool PTPT_hasSymbolWsAfterTuple(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterTuple(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterTuple(PTPT_Symbol arg, PTPT_OptLayout wsAfterTuple);
ATbool PTPT_hasSymbolHead(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolHead(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolHead(PTPT_Symbol arg, PTPT_Symbol head);
ATbool PTPT_hasSymbolWsAfterHead(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterHead(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterHead(PTPT_Symbol arg, PTPT_OptLayout wsAfterHead);
ATbool PTPT_hasSymbolRest(PTPT_Symbol arg);
PTPT_Symbols PTPT_getSymbolRest(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolRest(PTPT_Symbol arg, PTPT_Symbols rest);
ATbool PTPT_hasSymbolWsAfterRest(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterRest(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterRest(PTPT_Symbol arg, PTPT_OptLayout wsAfterRest);
ATbool PTPT_hasSymbolWsAfterSort(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSort(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterSort(PTPT_Symbol arg, PTPT_OptLayout wsAfterSort);
ATbool PTPT_hasSymbolWsAfterIter(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIter(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterIter(PTPT_Symbol arg, PTPT_OptLayout wsAfterIter);
ATbool PTPT_hasSymbolWsAfterIterStar(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterStar(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterIterStar(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterStar);
ATbool PTPT_hasSymbolWsAfterIterSep(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterSep(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterIterSep(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterSep);
ATbool PTPT_hasSymbolSeparator(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolSeparator(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolSeparator(PTPT_Symbol arg, PTPT_Symbol separator);
ATbool PTPT_hasSymbolWsAfterSeparator(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSeparator(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterSeparator(PTPT_Symbol arg, PTPT_OptLayout wsAfterSeparator);
ATbool PTPT_hasSymbolWsAfterIterStarSep(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterStarSep(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterIterStarSep(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterStarSep);
ATbool PTPT_hasSymbolWsAfterIterN(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterN(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterIterN(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterN);
ATbool PTPT_hasSymbolNumber(PTPT_Symbol arg);
PTPT_NatCon PTPT_getSymbolNumber(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolNumber(PTPT_Symbol arg, PTPT_NatCon number);
ATbool PTPT_hasSymbolWsAfterNumber(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterNumber(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterNumber(PTPT_Symbol arg, PTPT_OptLayout wsAfterNumber);
ATbool PTPT_hasSymbolWsAfterIterSepN(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterSepN(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterIterSepN(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterSepN);
ATbool PTPT_hasSymbolWsAfterComma1(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterComma1(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterComma1(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma1);
ATbool PTPT_hasSymbolWsAfterComma2(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterComma2(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterComma2(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma2);
ATbool PTPT_hasSymbolWsAfterFunc(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterFunc(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterFunc(PTPT_Symbol arg, PTPT_OptLayout wsAfterFunc);
ATbool PTPT_hasSymbolSymbols(PTPT_Symbol arg);
PTPT_Symbols PTPT_getSymbolSymbols(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolSymbols(PTPT_Symbol arg, PTPT_Symbols symbols);
ATbool PTPT_hasSymbolWsAfterSymbols(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSymbols(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterSymbols(PTPT_Symbol arg, PTPT_OptLayout wsAfterSymbols);
ATbool PTPT_hasSymbolWsAfterVarsym(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterVarsym(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterVarsym(PTPT_Symbol arg, PTPT_OptLayout wsAfterVarsym);
ATbool PTPT_hasSymbolWsAfterCharClass(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterCharClass(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterCharClass(PTPT_Symbol arg, PTPT_OptLayout wsAfterCharClass);
ATbool PTPT_hasSymbolCharRanges(PTPT_Symbol arg);
PTPT_CharRanges PTPT_getSymbolCharRanges(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolCharRanges(PTPT_Symbol arg, PTPT_CharRanges CharRanges);
ATbool PTPT_hasSymbolWsAfterCharRanges(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterCharRanges(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterCharRanges(PTPT_Symbol arg, PTPT_OptLayout wsAfterCharRanges);
ATbool PTPT_hasSymbolWsAfterStrategy(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterStrategy(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterStrategy(PTPT_Symbol arg, PTPT_OptLayout wsAfterStrategy);
ATbool PTPT_hasSymbolWsAfterParametrizedSort(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterParametrizedSort(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterParametrizedSort(PTPT_Symbol arg, PTPT_OptLayout wsAfterParametrizedSort);
ATbool PTPT_hasSymbolSort(PTPT_Symbol arg);
PTPT_QLiteral PTPT_getSymbolSort(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolSort(PTPT_Symbol arg, PTPT_QLiteral sort);
ATbool PTPT_hasSymbolParameters(PTPT_Symbol arg);
PTPT_Symbols PTPT_getSymbolParameters(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolParameters(PTPT_Symbol arg, PTPT_Symbols parameters);
ATbool PTPT_hasSymbolWsAfterParameters(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterParameters(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterParameters(PTPT_Symbol arg, PTPT_OptLayout wsAfterParameters);

/*}}}  */
/*{{{  PTPT_Symbols accessors */

ATbool PTPT_isValidSymbols(PTPT_Symbols arg);
inline ATbool PTPT_isSymbolsList(PTPT_Symbols arg);
ATbool PTPT_hasSymbolsWsAfterBracketOpen(PTPT_Symbols arg);
PTPT_OptLayout PTPT_getSymbolsWsAfterBracketOpen(PTPT_Symbols arg);
PTPT_Symbols PTPT_setSymbolsWsAfterBracketOpen(PTPT_Symbols arg, PTPT_OptLayout wsAfterBracketOpen);
ATbool PTPT_hasSymbolsList(PTPT_Symbols arg);
PTPT_SymbolList PTPT_getSymbolsList(PTPT_Symbols arg);
PTPT_Symbols PTPT_setSymbolsList(PTPT_Symbols arg, PTPT_SymbolList list);
ATbool PTPT_hasSymbolsWsAfterList(PTPT_Symbols arg);
PTPT_OptLayout PTPT_getSymbolsWsAfterList(PTPT_Symbols arg);
PTPT_Symbols PTPT_setSymbolsWsAfterList(PTPT_Symbols arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_SymbolList accessors */

ATbool PTPT_isValidSymbolList(PTPT_SymbolList arg);
inline ATbool PTPT_isSymbolListEmpty(PTPT_SymbolList arg);
inline ATbool PTPT_isSymbolListSingle(PTPT_SymbolList arg);
inline ATbool PTPT_isSymbolListMany(PTPT_SymbolList arg);
ATbool PTPT_hasSymbolListHead(PTPT_SymbolList arg);
PTPT_Symbol PTPT_getSymbolListHead(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_setSymbolListHead(PTPT_SymbolList arg, PTPT_Symbol head);
ATbool PTPT_hasSymbolListWsAfterFirst(PTPT_SymbolList arg);
PTPT_OptLayout PTPT_getSymbolListWsAfterFirst(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_setSymbolListWsAfterFirst(PTPT_SymbolList arg, PTPT_OptLayout wsAfterFirst);
ATbool PTPT_hasSymbolListSep(PTPT_SymbolList arg);
char * PTPT_getSymbolListSep(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_setSymbolListSep(PTPT_SymbolList arg, char * sep);
ATbool PTPT_hasSymbolListWsAfterSep(PTPT_SymbolList arg);
PTPT_OptLayout PTPT_getSymbolListWsAfterSep(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_setSymbolListWsAfterSep(PTPT_SymbolList arg, PTPT_OptLayout wsAfterSep);
ATbool PTPT_hasSymbolListTail(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_getSymbolListTail(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_setSymbolListTail(PTPT_SymbolList arg, PTPT_SymbolList tail);

/*}}}  */
/*{{{  PTPT_CharRanges accessors */

ATbool PTPT_isValidCharRanges(PTPT_CharRanges arg);
inline ATbool PTPT_isCharRangesList(PTPT_CharRanges arg);
ATbool PTPT_hasCharRangesWsAfterBracketOpen(PTPT_CharRanges arg);
PTPT_OptLayout PTPT_getCharRangesWsAfterBracketOpen(PTPT_CharRanges arg);
PTPT_CharRanges PTPT_setCharRangesWsAfterBracketOpen(PTPT_CharRanges arg, PTPT_OptLayout wsAfterBracketOpen);
ATbool PTPT_hasCharRangesList(PTPT_CharRanges arg);
PTPT_CharRangeList PTPT_getCharRangesList(PTPT_CharRanges arg);
PTPT_CharRanges PTPT_setCharRangesList(PTPT_CharRanges arg, PTPT_CharRangeList list);
ATbool PTPT_hasCharRangesWsAfterList(PTPT_CharRanges arg);
PTPT_OptLayout PTPT_getCharRangesWsAfterList(PTPT_CharRanges arg);
PTPT_CharRanges PTPT_setCharRangesWsAfterList(PTPT_CharRanges arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_CharRangeList accessors */

ATbool PTPT_isValidCharRangeList(PTPT_CharRangeList arg);
inline ATbool PTPT_isCharRangeListEmpty(PTPT_CharRangeList arg);
inline ATbool PTPT_isCharRangeListSingle(PTPT_CharRangeList arg);
inline ATbool PTPT_isCharRangeListMany(PTPT_CharRangeList arg);
ATbool PTPT_hasCharRangeListHead(PTPT_CharRangeList arg);
PTPT_CharRange PTPT_getCharRangeListHead(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_setCharRangeListHead(PTPT_CharRangeList arg, PTPT_CharRange head);
ATbool PTPT_hasCharRangeListWsAfterFirst(PTPT_CharRangeList arg);
PTPT_OptLayout PTPT_getCharRangeListWsAfterFirst(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_setCharRangeListWsAfterFirst(PTPT_CharRangeList arg, PTPT_OptLayout wsAfterFirst);
ATbool PTPT_hasCharRangeListSep(PTPT_CharRangeList arg);
char * PTPT_getCharRangeListSep(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_setCharRangeListSep(PTPT_CharRangeList arg, char * sep);
ATbool PTPT_hasCharRangeListWsAfterSep(PTPT_CharRangeList arg);
PTPT_OptLayout PTPT_getCharRangeListWsAfterSep(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_setCharRangeListWsAfterSep(PTPT_CharRangeList arg, PTPT_OptLayout wsAfterSep);
ATbool PTPT_hasCharRangeListTail(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_getCharRangeListTail(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_setCharRangeListTail(PTPT_CharRangeList arg, PTPT_CharRangeList tail);

/*}}}  */
/*{{{  PTPT_CharRange accessors */

ATbool PTPT_isValidCharRange(PTPT_CharRange arg);
inline ATbool PTPT_isCharRangeCharacter(PTPT_CharRange arg);
inline ATbool PTPT_isCharRangeRange(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeInteger(PTPT_CharRange arg);
PTPT_NatCon PTPT_getCharRangeInteger(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeInteger(PTPT_CharRange arg, PTPT_NatCon integer);
ATbool PTPT_hasCharRangeWsAfterRange(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterRange(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeWsAfterRange(PTPT_CharRange arg, PTPT_OptLayout wsAfterRange);
ATbool PTPT_hasCharRangeWsAfterParenOpen(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterParenOpen(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeWsAfterParenOpen(PTPT_CharRange arg, PTPT_OptLayout wsAfterParenOpen);
ATbool PTPT_hasCharRangeStart(PTPT_CharRange arg);
PTPT_NatCon PTPT_getCharRangeStart(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeStart(PTPT_CharRange arg, PTPT_NatCon start);
ATbool PTPT_hasCharRangeWsAfterStart(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterStart(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeWsAfterStart(PTPT_CharRange arg, PTPT_OptLayout wsAfterStart);
ATbool PTPT_hasCharRangeWsAfterComma(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterComma(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeWsAfterComma(PTPT_CharRange arg, PTPT_OptLayout wsAfterComma);
ATbool PTPT_hasCharRangeEnd(PTPT_CharRange arg);
PTPT_NatCon PTPT_getCharRangeEnd(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeEnd(PTPT_CharRange arg, PTPT_NatCon end);
ATbool PTPT_hasCharRangeWsAfterEnd(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterEnd(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeWsAfterEnd(PTPT_CharRange arg, PTPT_OptLayout wsAfterEnd);

/*}}}  */
/*{{{  PTPT_OptExp accessors */

ATbool PTPT_isValidOptExp(PTPT_OptExp arg);
inline ATbool PTPT_isOptExpPresent(PTPT_OptExp arg);
inline ATbool PTPT_isOptExpAbsent(PTPT_OptExp arg);
ATbool PTPT_hasOptExpWsAfterE(PTPT_OptExp arg);
PTPT_OptLayout PTPT_getOptExpWsAfterE(PTPT_OptExp arg);
PTPT_OptExp PTPT_setOptExpWsAfterE(PTPT_OptExp arg, PTPT_OptLayout wsAfterE);
ATbool PTPT_hasOptExpIntCon(PTPT_OptExp arg);
PTPT_IntCon PTPT_getOptExpIntCon(PTPT_OptExp arg);
PTPT_OptExp PTPT_setOptExpIntCon(PTPT_OptExp arg, PTPT_IntCon IntCon);

/*}}}  */
/*{{{  PTPT_RealCon accessors */

ATbool PTPT_isValidRealCon(PTPT_RealCon arg);
inline ATbool PTPT_isRealConRealCon(PTPT_RealCon arg);
ATbool PTPT_hasRealConIntCon(PTPT_RealCon arg);
PTPT_IntCon PTPT_getRealConIntCon(PTPT_RealCon arg);
PTPT_RealCon PTPT_setRealConIntCon(PTPT_RealCon arg, PTPT_IntCon IntCon);
ATbool PTPT_hasRealConWsAfterIntCon(PTPT_RealCon arg);
PTPT_OptLayout PTPT_getRealConWsAfterIntCon(PTPT_RealCon arg);
PTPT_RealCon PTPT_setRealConWsAfterIntCon(PTPT_RealCon arg, PTPT_OptLayout wsAfterIntCon);
ATbool PTPT_hasRealConWsAfterPeriod(PTPT_RealCon arg);
PTPT_OptLayout PTPT_getRealConWsAfterPeriod(PTPT_RealCon arg);
PTPT_RealCon PTPT_setRealConWsAfterPeriod(PTPT_RealCon arg, PTPT_OptLayout wsAfterPeriod);
ATbool PTPT_hasRealConNatCon(PTPT_RealCon arg);
PTPT_NatCon PTPT_getRealConNatCon(PTPT_RealCon arg);
PTPT_RealCon PTPT_setRealConNatCon(PTPT_RealCon arg, PTPT_NatCon NatCon);
ATbool PTPT_hasRealConWsAfterNatCon(PTPT_RealCon arg);
PTPT_OptLayout PTPT_getRealConWsAfterNatCon(PTPT_RealCon arg);
PTPT_RealCon PTPT_setRealConWsAfterNatCon(PTPT_RealCon arg, PTPT_OptLayout wsAfterNatCon);
ATbool PTPT_hasRealConOptExp(PTPT_RealCon arg);
PTPT_OptExp PTPT_getRealConOptExp(PTPT_RealCon arg);
PTPT_RealCon PTPT_setRealConOptExp(PTPT_RealCon arg, PTPT_OptExp OptExp);

/*}}}  */
/*{{{  PTPT_ATermList accessors */

ATbool PTPT_isValidATermList(PTPT_ATermList arg);
inline ATbool PTPT_isATermListNotEmpty(PTPT_ATermList arg);
ATbool PTPT_hasATermListWsAfterBracketOpen(PTPT_ATermList arg);
PTPT_OptLayout PTPT_getATermListWsAfterBracketOpen(PTPT_ATermList arg);
PTPT_ATermList PTPT_setATermListWsAfterBracketOpen(PTPT_ATermList arg, PTPT_OptLayout wsAfterBracketOpen);
ATbool PTPT_hasATermListElems(PTPT_ATermList arg);
PTPT_ATermElems PTPT_getATermListElems(PTPT_ATermList arg);
PTPT_ATermList PTPT_setATermListElems(PTPT_ATermList arg, PTPT_ATermElems elems);
ATbool PTPT_hasATermListWsAfterElems(PTPT_ATermList arg);
PTPT_OptLayout PTPT_getATermListWsAfterElems(PTPT_ATermList arg);
PTPT_ATermList PTPT_setATermListWsAfterElems(PTPT_ATermList arg, PTPT_OptLayout wsAfterElems);

/*}}}  */
/*{{{  PTPT_ATermElems accessors */

ATbool PTPT_isValidATermElems(PTPT_ATermElems arg);
inline ATbool PTPT_isATermElemsEmpty(PTPT_ATermElems arg);
inline ATbool PTPT_isATermElemsSingle(PTPT_ATermElems arg);
inline ATbool PTPT_isATermElemsMany(PTPT_ATermElems arg);
ATbool PTPT_hasATermElemsHead(PTPT_ATermElems arg);
PTPT_ATerm PTPT_getATermElemsHead(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_setATermElemsHead(PTPT_ATermElems arg, PTPT_ATerm head);
ATbool PTPT_hasATermElemsWsAfterFirst(PTPT_ATermElems arg);
PTPT_OptLayout PTPT_getATermElemsWsAfterFirst(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_setATermElemsWsAfterFirst(PTPT_ATermElems arg, PTPT_OptLayout wsAfterFirst);
ATbool PTPT_hasATermElemsSep(PTPT_ATermElems arg);
char * PTPT_getATermElemsSep(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_setATermElemsSep(PTPT_ATermElems arg, char * sep);
ATbool PTPT_hasATermElemsWsAfterSep(PTPT_ATermElems arg);
PTPT_OptLayout PTPT_getATermElemsWsAfterSep(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_setATermElemsWsAfterSep(PTPT_ATermElems arg, PTPT_OptLayout wsAfterSep);
ATbool PTPT_hasATermElemsTail(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_getATermElemsTail(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_setATermElemsTail(PTPT_ATermElems arg, PTPT_ATermElems tail);

/*}}}  */
/*{{{  PTPT_ACon accessors */

ATbool PTPT_isValidACon(PTPT_ACon arg);
inline ATbool PTPT_isAConInt(PTPT_ACon arg);
inline ATbool PTPT_isAConReal(PTPT_ACon arg);
ATbool PTPT_hasAConIntCon(PTPT_ACon arg);
PTPT_IntCon PTPT_getAConIntCon(PTPT_ACon arg);
PTPT_ACon PTPT_setAConIntCon(PTPT_ACon arg, PTPT_IntCon IntCon);
ATbool PTPT_hasAConRealCon(PTPT_ACon arg);
PTPT_RealCon PTPT_getAConRealCon(PTPT_ACon arg);
PTPT_ACon PTPT_setAConRealCon(PTPT_ACon arg, PTPT_RealCon RealCon);

/*}}}  */
/*{{{  PTPT_AFun accessors */

ATbool PTPT_isValidAFun(PTPT_AFun arg);
inline ATbool PTPT_isAFunDefault(PTPT_AFun arg);
ATbool PTPT_hasAFunLiteral(PTPT_AFun arg);
PTPT_Literal PTPT_getAFunLiteral(PTPT_AFun arg);
PTPT_AFun PTPT_setAFunLiteral(PTPT_AFun arg, PTPT_Literal Literal);

/*}}}  */
/*{{{  PTPT_ATerm accessors */

ATbool PTPT_isValidATerm(PTPT_ATerm arg);
inline ATbool PTPT_isATermConstant(PTPT_ATerm arg);
inline ATbool PTPT_isATermList(PTPT_ATerm arg);
inline ATbool PTPT_isATermFun(PTPT_ATerm arg);
inline ATbool PTPT_isATermAppl(PTPT_ATerm arg);
inline ATbool PTPT_isATermAnnotatedConstant(PTPT_ATerm arg);
inline ATbool PTPT_isATermAnnotatedList(PTPT_ATerm arg);
inline ATbool PTPT_isATermAnnotatedFun(PTPT_ATerm arg);
inline ATbool PTPT_isATermAnnotatedAppl(PTPT_ATerm arg);
ATbool PTPT_hasATermACon(PTPT_ATerm arg);
PTPT_ACon PTPT_getATermACon(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermACon(PTPT_ATerm arg, PTPT_ACon ACon);
ATbool PTPT_hasATermList(PTPT_ATerm arg);
PTPT_ATermList PTPT_getATermList(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermList(PTPT_ATerm arg, PTPT_ATermList list);
ATbool PTPT_hasATermFun(PTPT_ATerm arg);
PTPT_AFun PTPT_getATermFun(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermFun(PTPT_ATerm arg, PTPT_AFun fun);
ATbool PTPT_hasATermWsAfterFun(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterFun(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermWsAfterFun(PTPT_ATerm arg, PTPT_OptLayout wsAfterFun);
ATbool PTPT_hasATermWsAfterParenOpen(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterParenOpen(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermWsAfterParenOpen(PTPT_ATerm arg, PTPT_OptLayout wsAfterParenOpen);
ATbool PTPT_hasATermArgs(PTPT_ATerm arg);
PTPT_ATermArgs PTPT_getATermArgs(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermArgs(PTPT_ATerm arg, PTPT_ATermArgs args);
ATbool PTPT_hasATermWsAfterArgs(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterArgs(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermWsAfterArgs(PTPT_ATerm arg, PTPT_OptLayout wsAfterArgs);
ATbool PTPT_hasATermWsAfterACon(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterACon(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermWsAfterACon(PTPT_ATerm arg, PTPT_OptLayout wsAfterACon);
ATbool PTPT_hasATermAnn(PTPT_ATerm arg);
PTPT_Ann PTPT_getATermAnn(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermAnn(PTPT_ATerm arg, PTPT_Ann Ann);
ATbool PTPT_hasATermWsAfterList(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterList(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermWsAfterList(PTPT_ATerm arg, PTPT_OptLayout wsAfterList);
ATbool PTPT_hasATermWsAfterParenClose(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterParenClose(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermWsAfterParenClose(PTPT_ATerm arg, PTPT_OptLayout wsAfterParenClose);

/*}}}  */
/*{{{  PTPT_ATermArgs accessors */

ATbool PTPT_isValidATermArgs(PTPT_ATermArgs arg);
inline ATbool PTPT_isATermArgsSingle(PTPT_ATermArgs arg);
inline ATbool PTPT_isATermArgsMany(PTPT_ATermArgs arg);
ATbool PTPT_hasATermArgsHead(PTPT_ATermArgs arg);
PTPT_ATerm PTPT_getATermArgsHead(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_setATermArgsHead(PTPT_ATermArgs arg, PTPT_ATerm head);
ATbool PTPT_hasATermArgsWsAfterFirst(PTPT_ATermArgs arg);
PTPT_OptLayout PTPT_getATermArgsWsAfterFirst(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_setATermArgsWsAfterFirst(PTPT_ATermArgs arg, PTPT_OptLayout wsAfterFirst);
ATbool PTPT_hasATermArgsSep(PTPT_ATermArgs arg);
char * PTPT_getATermArgsSep(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_setATermArgsSep(PTPT_ATermArgs arg, char * sep);
ATbool PTPT_hasATermArgsWsAfterSep(PTPT_ATermArgs arg);
PTPT_OptLayout PTPT_getATermArgsWsAfterSep(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_setATermArgsWsAfterSep(PTPT_ATermArgs arg, PTPT_OptLayout wsAfterSep);
ATbool PTPT_hasATermArgsTail(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_getATermArgsTail(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_setATermArgsTail(PTPT_ATermArgs arg, PTPT_ATermArgs tail);

/*}}}  */
/*{{{  PTPT_Ann accessors */

ATbool PTPT_isValidAnn(PTPT_Ann arg);
inline ATbool PTPT_isAnnAnnotation(PTPT_Ann arg);
ATbool PTPT_hasAnnWsAfterBraceOpen(PTPT_Ann arg);
PTPT_OptLayout PTPT_getAnnWsAfterBraceOpen(PTPT_Ann arg);
PTPT_Ann PTPT_setAnnWsAfterBraceOpen(PTPT_Ann arg, PTPT_OptLayout wsAfterBraceOpen);
ATbool PTPT_hasAnnAnnos(PTPT_Ann arg);
PTPT_ATermAnnos PTPT_getAnnAnnos(PTPT_Ann arg);
PTPT_Ann PTPT_setAnnAnnos(PTPT_Ann arg, PTPT_ATermAnnos annos);
ATbool PTPT_hasAnnWsAfterAnnos(PTPT_Ann arg);
PTPT_OptLayout PTPT_getAnnWsAfterAnnos(PTPT_Ann arg);
PTPT_Ann PTPT_setAnnWsAfterAnnos(PTPT_Ann arg, PTPT_OptLayout wsAfterAnnos);

/*}}}  */
/*{{{  PTPT_ATermAnnos accessors */

ATbool PTPT_isValidATermAnnos(PTPT_ATermAnnos arg);
inline ATbool PTPT_isATermAnnosSingle(PTPT_ATermAnnos arg);
inline ATbool PTPT_isATermAnnosMany(PTPT_ATermAnnos arg);
ATbool PTPT_hasATermAnnosHead(PTPT_ATermAnnos arg);
PTPT_ATerm PTPT_getATermAnnosHead(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_setATermAnnosHead(PTPT_ATermAnnos arg, PTPT_ATerm head);
ATbool PTPT_hasATermAnnosWsAfterFirst(PTPT_ATermAnnos arg);
PTPT_OptLayout PTPT_getATermAnnosWsAfterFirst(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_setATermAnnosWsAfterFirst(PTPT_ATermAnnos arg, PTPT_OptLayout wsAfterFirst);
ATbool PTPT_hasATermAnnosSep(PTPT_ATermAnnos arg);
char * PTPT_getATermAnnosSep(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_setATermAnnosSep(PTPT_ATermAnnos arg, char * sep);
ATbool PTPT_hasATermAnnosWsAfterSep(PTPT_ATermAnnos arg);
PTPT_OptLayout PTPT_getATermAnnosWsAfterSep(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_setATermAnnosWsAfterSep(PTPT_ATermAnnos arg, PTPT_OptLayout wsAfterSep);
ATbool PTPT_hasATermAnnosTail(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_getATermAnnosTail(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_setATermAnnosTail(PTPT_ATermAnnos arg, PTPT_ATermAnnos tail);

/*}}}  */
/*{{{  PTPT_AlphaNumericalEscChar accessors */

ATbool PTPT_isValidAlphaNumericalEscChar(PTPT_AlphaNumericalEscChar arg);
inline ATbool PTPT_isAlphaNumericalEscCharDefault(PTPT_AlphaNumericalEscChar arg);
ATbool PTPT_hasAlphaNumericalEscCharChars(PTPT_AlphaNumericalEscChar arg);
PTPT_CHARLIST PTPT_getAlphaNumericalEscCharChars(PTPT_AlphaNumericalEscChar arg);
PTPT_AlphaNumericalEscChar PTPT_setAlphaNumericalEscCharChars(PTPT_AlphaNumericalEscChar arg, PTPT_CHARLIST chars);

/*}}}  */
/*{{{  PTPT_DecimalEscChar accessors */

ATbool PTPT_isValidDecimalEscChar(PTPT_DecimalEscChar arg);
inline ATbool PTPT_isDecimalEscCharDec0Underscore199(PTPT_DecimalEscChar arg);
inline ATbool PTPT_isDecimalEscCharDec200Underscore249(PTPT_DecimalEscChar arg);
inline ATbool PTPT_isDecimalEscCharDec250Underscore255(PTPT_DecimalEscChar arg);
ATbool PTPT_hasDecimalEscCharChars(PTPT_DecimalEscChar arg);
PTPT_CHARLIST PTPT_getDecimalEscCharChars(PTPT_DecimalEscChar arg);
PTPT_DecimalEscChar PTPT_setDecimalEscCharChars(PTPT_DecimalEscChar arg, PTPT_CHARLIST chars);

/*}}}  */
/*{{{  PTPT_EscChar accessors */

ATbool PTPT_isValidEscChar(PTPT_EscChar arg);
inline ATbool PTPT_isEscCharAlphaNumeric(PTPT_EscChar arg);
inline ATbool PTPT_isEscCharDecimal(PTPT_EscChar arg);
ATbool PTPT_hasEscCharChars(PTPT_EscChar arg);
PTPT_CHARLIST PTPT_getEscCharChars(PTPT_EscChar arg);
PTPT_EscChar PTPT_setEscCharChars(PTPT_EscChar arg, PTPT_CHARLIST chars);

/*}}}  */
/*{{{  PTPT_LChar accessors */

ATbool PTPT_isValidLChar(PTPT_LChar arg);
inline ATbool PTPT_isLCharNormal(PTPT_LChar arg);
inline ATbool PTPT_isLCharEscaped(PTPT_LChar arg);
ATbool PTPT_hasLCharChars(PTPT_LChar arg);
PTPT_CHARLIST PTPT_getLCharChars(PTPT_LChar arg);
PTPT_LChar PTPT_setLCharChars(PTPT_LChar arg, PTPT_CHARLIST chars);

/*}}}  */
/*{{{  PTPT_QLiteral accessors */

ATbool PTPT_isValidQLiteral(PTPT_QLiteral arg);
inline ATbool PTPT_isQLiteralQuoted(PTPT_QLiteral arg);
ATbool PTPT_hasQLiteralChars(PTPT_QLiteral arg);
PTPT_CHARLIST PTPT_getQLiteralChars(PTPT_QLiteral arg);
PTPT_QLiteral PTPT_setQLiteralChars(PTPT_QLiteral arg, PTPT_CHARLIST chars);

/*}}}  */
/*{{{  PTPT_UQLiteral accessors */

ATbool PTPT_isValidUQLiteral(PTPT_UQLiteral arg);
inline ATbool PTPT_isUQLiteralOneChar(PTPT_UQLiteral arg);
inline ATbool PTPT_isUQLiteralMoreChars(PTPT_UQLiteral arg);
ATbool PTPT_hasUQLiteralChars(PTPT_UQLiteral arg);
PTPT_CHARLIST PTPT_getUQLiteralChars(PTPT_UQLiteral arg);
PTPT_UQLiteral PTPT_setUQLiteralChars(PTPT_UQLiteral arg, PTPT_CHARLIST chars);

/*}}}  */
/*{{{  PTPT_Literal accessors */

ATbool PTPT_isValidLiteral(PTPT_Literal arg);
inline ATbool PTPT_isLiteralQlit(PTPT_Literal arg);
inline ATbool PTPT_isLiteralUqlit(PTPT_Literal arg);
ATbool PTPT_hasLiteralQLiteral(PTPT_Literal arg);
PTPT_QLiteral PTPT_getLiteralQLiteral(PTPT_Literal arg);
PTPT_Literal PTPT_setLiteralQLiteral(PTPT_Literal arg, PTPT_QLiteral QLiteral);
ATbool PTPT_hasLiteralUQLiteral(PTPT_Literal arg);
PTPT_UQLiteral PTPT_getLiteralUQLiteral(PTPT_Literal arg);
PTPT_Literal PTPT_setLiteralUQLiteral(PTPT_Literal arg, PTPT_UQLiteral UQLiteral);

/*}}}  */
/*{{{  PTPT_Attributes accessors */

ATbool PTPT_isValidAttributes(PTPT_Attributes arg);
inline ATbool PTPT_isAttributesNoAttrs(PTPT_Attributes arg);
inline ATbool PTPT_isAttributesAttrs(PTPT_Attributes arg);
ATbool PTPT_hasAttributesWsAfterAttrs(PTPT_Attributes arg);
PTPT_OptLayout PTPT_getAttributesWsAfterAttrs(PTPT_Attributes arg);
PTPT_Attributes PTPT_setAttributesWsAfterAttrs(PTPT_Attributes arg, PTPT_OptLayout wsAfterAttrs);
ATbool PTPT_hasAttributesWsAfterParenOpen(PTPT_Attributes arg);
PTPT_OptLayout PTPT_getAttributesWsAfterParenOpen(PTPT_Attributes arg);
PTPT_Attributes PTPT_setAttributesWsAfterParenOpen(PTPT_Attributes arg, PTPT_OptLayout wsAfterParenOpen);
ATbool PTPT_hasAttributesAttributes(PTPT_Attributes arg);
PTPT_Attrs PTPT_getAttributesAttributes(PTPT_Attributes arg);
PTPT_Attributes PTPT_setAttributesAttributes(PTPT_Attributes arg, PTPT_Attrs attributes);
ATbool PTPT_hasAttributesWsAfterAttributes(PTPT_Attributes arg);
PTPT_OptLayout PTPT_getAttributesWsAfterAttributes(PTPT_Attributes arg);
PTPT_Attributes PTPT_setAttributesWsAfterAttributes(PTPT_Attributes arg, PTPT_OptLayout wsAfterAttributes);

/*}}}  */
/*{{{  PTPT_Attrs accessors */

ATbool PTPT_isValidAttrs(PTPT_Attrs arg);
inline ATbool PTPT_isAttrsMany(PTPT_Attrs arg);
ATbool PTPT_hasAttrsWsAfterBracketOpen(PTPT_Attrs arg);
PTPT_OptLayout PTPT_getAttrsWsAfterBracketOpen(PTPT_Attrs arg);
PTPT_Attrs PTPT_setAttrsWsAfterBracketOpen(PTPT_Attrs arg, PTPT_OptLayout wsAfterBracketOpen);
ATbool PTPT_hasAttrsList(PTPT_Attrs arg);
PTPT_AttrList PTPT_getAttrsList(PTPT_Attrs arg);
PTPT_Attrs PTPT_setAttrsList(PTPT_Attrs arg, PTPT_AttrList list);
ATbool PTPT_hasAttrsWsAfterList(PTPT_Attrs arg);
PTPT_OptLayout PTPT_getAttrsWsAfterList(PTPT_Attrs arg);
PTPT_Attrs PTPT_setAttrsWsAfterList(PTPT_Attrs arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_AttrList accessors */

ATbool PTPT_isValidAttrList(PTPT_AttrList arg);
inline ATbool PTPT_isAttrListSingle(PTPT_AttrList arg);
inline ATbool PTPT_isAttrListMany(PTPT_AttrList arg);
ATbool PTPT_hasAttrListHead(PTPT_AttrList arg);
PTPT_Attr PTPT_getAttrListHead(PTPT_AttrList arg);
PTPT_AttrList PTPT_setAttrListHead(PTPT_AttrList arg, PTPT_Attr head);
ATbool PTPT_hasAttrListWsAfterFirst(PTPT_AttrList arg);
PTPT_OptLayout PTPT_getAttrListWsAfterFirst(PTPT_AttrList arg);
PTPT_AttrList PTPT_setAttrListWsAfterFirst(PTPT_AttrList arg, PTPT_OptLayout wsAfterFirst);
ATbool PTPT_hasAttrListSep(PTPT_AttrList arg);
char * PTPT_getAttrListSep(PTPT_AttrList arg);
PTPT_AttrList PTPT_setAttrListSep(PTPT_AttrList arg, char * sep);
ATbool PTPT_hasAttrListWsAfterSep(PTPT_AttrList arg);
PTPT_OptLayout PTPT_getAttrListWsAfterSep(PTPT_AttrList arg);
PTPT_AttrList PTPT_setAttrListWsAfterSep(PTPT_AttrList arg, PTPT_OptLayout wsAfterSep);
ATbool PTPT_hasAttrListTail(PTPT_AttrList arg);
PTPT_AttrList PTPT_getAttrListTail(PTPT_AttrList arg);
PTPT_AttrList PTPT_setAttrListTail(PTPT_AttrList arg, PTPT_AttrList tail);

/*}}}  */
/*{{{  PTPT_Attr accessors */

ATbool PTPT_isValidAttr(PTPT_Attr arg);
inline ATbool PTPT_isAttrAssoc(PTPT_Attr arg);
inline ATbool PTPT_isAttrTerm(PTPT_Attr arg);
inline ATbool PTPT_isAttrId(PTPT_Attr arg);
inline ATbool PTPT_isAttrBracket(PTPT_Attr arg);
inline ATbool PTPT_isAttrReject(PTPT_Attr arg);
inline ATbool PTPT_isAttrPrefer(PTPT_Attr arg);
inline ATbool PTPT_isAttrAvoid(PTPT_Attr arg);
ATbool PTPT_hasAttrWsAfterAssoc(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterAssoc(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrWsAfterAssoc(PTPT_Attr arg, PTPT_OptLayout wsAfterAssoc);
ATbool PTPT_hasAttrWsAfterParenOpen(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterParenOpen(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrWsAfterParenOpen(PTPT_Attr arg, PTPT_OptLayout wsAfterParenOpen);
ATbool PTPT_hasAttrAssociativity(PTPT_Attr arg);
PTPT_Associativity PTPT_getAttrAssociativity(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrAssociativity(PTPT_Attr arg, PTPT_Associativity associativity);
ATbool PTPT_hasAttrWsAfterAssociativity(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterAssociativity(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrWsAfterAssociativity(PTPT_Attr arg, PTPT_OptLayout wsAfterAssociativity);
ATbool PTPT_hasAttrWsAfterTerm(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterTerm(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrWsAfterTerm(PTPT_Attr arg, PTPT_OptLayout wsAfterTerm);
ATbool PTPT_hasAttrAterm(PTPT_Attr arg);
PTPT_ATerm PTPT_getAttrAterm(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrAterm(PTPT_Attr arg, PTPT_ATerm aterm);
ATbool PTPT_hasAttrWsAfterAterm(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterAterm(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrWsAfterAterm(PTPT_Attr arg, PTPT_OptLayout wsAfterAterm);
ATbool PTPT_hasAttrWsAfterId(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterId(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrWsAfterId(PTPT_Attr arg, PTPT_OptLayout wsAfterId);
ATbool PTPT_hasAttrModuleName(PTPT_Attr arg);
PTPT_QLiteral PTPT_getAttrModuleName(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrModuleName(PTPT_Attr arg, PTPT_QLiteral moduleName);
ATbool PTPT_hasAttrWsAfterModuleName(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterModuleName(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrWsAfterModuleName(PTPT_Attr arg, PTPT_OptLayout wsAfterModuleName);

/*}}}  */
/*{{{  PTPT_Associativity accessors */

ATbool PTPT_isValidAssociativity(PTPT_Associativity arg);
inline ATbool PTPT_isAssociativityLeft(PTPT_Associativity arg);
inline ATbool PTPT_isAssociativityRight(PTPT_Associativity arg);
inline ATbool PTPT_isAssociativityAssoc(PTPT_Associativity arg);
inline ATbool PTPT_isAssociativityNonAssoc(PTPT_Associativity arg);

/*}}}  */
/*{{{  PTPT_ParseTree accessors */

ATbool PTPT_isValidParseTree(PTPT_ParseTree arg);
inline ATbool PTPT_isParseTreeTop(PTPT_ParseTree arg);
ATbool PTPT_hasParseTreeWsAfterParsetree(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterParsetree(PTPT_ParseTree arg);
PTPT_ParseTree PTPT_setParseTreeWsAfterParsetree(PTPT_ParseTree arg, PTPT_OptLayout wsAfterParsetree);
ATbool PTPT_hasParseTreeWsAfterParenOpen(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterParenOpen(PTPT_ParseTree arg);
PTPT_ParseTree PTPT_setParseTreeWsAfterParenOpen(PTPT_ParseTree arg, PTPT_OptLayout wsAfterParenOpen);
ATbool PTPT_hasParseTreeTop(PTPT_ParseTree arg);
PTPT_Tree PTPT_getParseTreeTop(PTPT_ParseTree arg);
PTPT_ParseTree PTPT_setParseTreeTop(PTPT_ParseTree arg, PTPT_Tree top);
ATbool PTPT_hasParseTreeWsAfterTop(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterTop(PTPT_ParseTree arg);
PTPT_ParseTree PTPT_setParseTreeWsAfterTop(PTPT_ParseTree arg, PTPT_OptLayout wsAfterTop);
ATbool PTPT_hasParseTreeWsAfterComma(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterComma(PTPT_ParseTree arg);
PTPT_ParseTree PTPT_setParseTreeWsAfterComma(PTPT_ParseTree arg, PTPT_OptLayout wsAfterComma);
ATbool PTPT_hasParseTreeAmbCnt(PTPT_ParseTree arg);
PTPT_NatCon PTPT_getParseTreeAmbCnt(PTPT_ParseTree arg);
PTPT_ParseTree PTPT_setParseTreeAmbCnt(PTPT_ParseTree arg, PTPT_NatCon ambCnt);
ATbool PTPT_hasParseTreeWsAfterAmbCnt(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterAmbCnt(PTPT_ParseTree arg);
PTPT_ParseTree PTPT_setParseTreeWsAfterAmbCnt(PTPT_ParseTree arg, PTPT_OptLayout wsAfterAmbCnt);

/*}}}  */
/*{{{  PTPT_Start accessors */

ATbool PTPT_isValidStart(PTPT_Start arg);
inline ATbool PTPT_isStartParseTree(PTPT_Start arg);
inline ATbool PTPT_isStartAssociativity(PTPT_Start arg);
inline ATbool PTPT_isStartAttr(PTPT_Start arg);
inline ATbool PTPT_isStartAttrs(PTPT_Start arg);
inline ATbool PTPT_isStartAttributes(PTPT_Start arg);
inline ATbool PTPT_isStartQLiteral(PTPT_Start arg);
inline ATbool PTPT_isStartUQLiteral(PTPT_Start arg);
inline ATbool PTPT_isStartLiteral(PTPT_Start arg);
inline ATbool PTPT_isStartAnn(PTPT_Start arg);
inline ATbool PTPT_isStartATerm(PTPT_Start arg);
inline ATbool PTPT_isStartAFun(PTPT_Start arg);
inline ATbool PTPT_isStartACon(PTPT_Start arg);
inline ATbool PTPT_isStartATermList(PTPT_Start arg);
inline ATbool PTPT_isStartRealCon(PTPT_Start arg);
inline ATbool PTPT_isStartOptExp(PTPT_Start arg);
inline ATbool PTPT_isStartCharRanges(PTPT_Start arg);
inline ATbool PTPT_isStartCharRange(PTPT_Start arg);
inline ATbool PTPT_isStartSymbols(PTPT_Start arg);
inline ATbool PTPT_isStartSymbol(PTPT_Start arg);
inline ATbool PTPT_isStartProduction(PTPT_Start arg);
inline ATbool PTPT_isStartArgs(PTPT_Start arg);
inline ATbool PTPT_isStartTree(PTPT_Start arg);
inline ATbool PTPT_isStartIntCon(PTPT_Start arg);
inline ATbool PTPT_isStartNatCon(PTPT_Start arg);
ATbool PTPT_hasStartWsBefore(PTPT_Start arg);
PTPT_OptLayout PTPT_getStartWsBefore(PTPT_Start arg);
PTPT_Start PTPT_setStartWsBefore(PTPT_Start arg, PTPT_OptLayout wsBefore);
ATbool PTPT_hasStartTopParseTree(PTPT_Start arg);
PTPT_ParseTree PTPT_getStartTopParseTree(PTPT_Start arg);
PTPT_Start PTPT_setStartTopParseTree(PTPT_Start arg, PTPT_ParseTree topParseTree);
ATbool PTPT_hasStartWsAfter(PTPT_Start arg);
PTPT_OptLayout PTPT_getStartWsAfter(PTPT_Start arg);
PTPT_Start PTPT_setStartWsAfter(PTPT_Start arg, PTPT_OptLayout wsAfter);
ATbool PTPT_hasStartAmbCnt(PTPT_Start arg);
int PTPT_getStartAmbCnt(PTPT_Start arg);
PTPT_Start PTPT_setStartAmbCnt(PTPT_Start arg, int ambCnt);
ATbool PTPT_hasStartTopAssociativity(PTPT_Start arg);
PTPT_Associativity PTPT_getStartTopAssociativity(PTPT_Start arg);
PTPT_Start PTPT_setStartTopAssociativity(PTPT_Start arg, PTPT_Associativity topAssociativity);
ATbool PTPT_hasStartTopAttr(PTPT_Start arg);
PTPT_Attr PTPT_getStartTopAttr(PTPT_Start arg);
PTPT_Start PTPT_setStartTopAttr(PTPT_Start arg, PTPT_Attr topAttr);
ATbool PTPT_hasStartTopAttrs(PTPT_Start arg);
PTPT_Attrs PTPT_getStartTopAttrs(PTPT_Start arg);
PTPT_Start PTPT_setStartTopAttrs(PTPT_Start arg, PTPT_Attrs topAttrs);
ATbool PTPT_hasStartTopAttributes(PTPT_Start arg);
PTPT_Attributes PTPT_getStartTopAttributes(PTPT_Start arg);
PTPT_Start PTPT_setStartTopAttributes(PTPT_Start arg, PTPT_Attributes topAttributes);
ATbool PTPT_hasStartTopQLiteral(PTPT_Start arg);
PTPT_QLiteral PTPT_getStartTopQLiteral(PTPT_Start arg);
PTPT_Start PTPT_setStartTopQLiteral(PTPT_Start arg, PTPT_QLiteral topQLiteral);
ATbool PTPT_hasStartTopUQLiteral(PTPT_Start arg);
PTPT_UQLiteral PTPT_getStartTopUQLiteral(PTPT_Start arg);
PTPT_Start PTPT_setStartTopUQLiteral(PTPT_Start arg, PTPT_UQLiteral topUQLiteral);
ATbool PTPT_hasStartTopLiteral(PTPT_Start arg);
PTPT_Literal PTPT_getStartTopLiteral(PTPT_Start arg);
PTPT_Start PTPT_setStartTopLiteral(PTPT_Start arg, PTPT_Literal topLiteral);
ATbool PTPT_hasStartTopAnn(PTPT_Start arg);
PTPT_Ann PTPT_getStartTopAnn(PTPT_Start arg);
PTPT_Start PTPT_setStartTopAnn(PTPT_Start arg, PTPT_Ann topAnn);
ATbool PTPT_hasStartTopATerm(PTPT_Start arg);
PTPT_ATerm PTPT_getStartTopATerm(PTPT_Start arg);
PTPT_Start PTPT_setStartTopATerm(PTPT_Start arg, PTPT_ATerm topATerm);
ATbool PTPT_hasStartTopAFun(PTPT_Start arg);
PTPT_AFun PTPT_getStartTopAFun(PTPT_Start arg);
PTPT_Start PTPT_setStartTopAFun(PTPT_Start arg, PTPT_AFun topAFun);
ATbool PTPT_hasStartTopACon(PTPT_Start arg);
PTPT_ACon PTPT_getStartTopACon(PTPT_Start arg);
PTPT_Start PTPT_setStartTopACon(PTPT_Start arg, PTPT_ACon topACon);
ATbool PTPT_hasStartTopATermList(PTPT_Start arg);
PTPT_ATermList PTPT_getStartTopATermList(PTPT_Start arg);
PTPT_Start PTPT_setStartTopATermList(PTPT_Start arg, PTPT_ATermList topATermList);
ATbool PTPT_hasStartTopRealCon(PTPT_Start arg);
PTPT_RealCon PTPT_getStartTopRealCon(PTPT_Start arg);
PTPT_Start PTPT_setStartTopRealCon(PTPT_Start arg, PTPT_RealCon topRealCon);
ATbool PTPT_hasStartTopOptExp(PTPT_Start arg);
PTPT_OptExp PTPT_getStartTopOptExp(PTPT_Start arg);
PTPT_Start PTPT_setStartTopOptExp(PTPT_Start arg, PTPT_OptExp topOptExp);
ATbool PTPT_hasStartTopCharRanges(PTPT_Start arg);
PTPT_CharRanges PTPT_getStartTopCharRanges(PTPT_Start arg);
PTPT_Start PTPT_setStartTopCharRanges(PTPT_Start arg, PTPT_CharRanges topCharRanges);
ATbool PTPT_hasStartTopCharRange(PTPT_Start arg);
PTPT_CharRange PTPT_getStartTopCharRange(PTPT_Start arg);
PTPT_Start PTPT_setStartTopCharRange(PTPT_Start arg, PTPT_CharRange topCharRange);
ATbool PTPT_hasStartTopSymbols(PTPT_Start arg);
PTPT_Symbols PTPT_getStartTopSymbols(PTPT_Start arg);
PTPT_Start PTPT_setStartTopSymbols(PTPT_Start arg, PTPT_Symbols topSymbols);
ATbool PTPT_hasStartTopSymbol(PTPT_Start arg);
PTPT_Symbol PTPT_getStartTopSymbol(PTPT_Start arg);
PTPT_Start PTPT_setStartTopSymbol(PTPT_Start arg, PTPT_Symbol topSymbol);
ATbool PTPT_hasStartTopProduction(PTPT_Start arg);
PTPT_Production PTPT_getStartTopProduction(PTPT_Start arg);
PTPT_Start PTPT_setStartTopProduction(PTPT_Start arg, PTPT_Production topProduction);
ATbool PTPT_hasStartTopArgs(PTPT_Start arg);
PTPT_Args PTPT_getStartTopArgs(PTPT_Start arg);
PTPT_Start PTPT_setStartTopArgs(PTPT_Start arg, PTPT_Args topArgs);
ATbool PTPT_hasStartTopTree(PTPT_Start arg);
PTPT_Tree PTPT_getStartTopTree(PTPT_Start arg);
PTPT_Start PTPT_setStartTopTree(PTPT_Start arg, PTPT_Tree topTree);
ATbool PTPT_hasStartTopIntCon(PTPT_Start arg);
PTPT_IntCon PTPT_getStartTopIntCon(PTPT_Start arg);
PTPT_Start PTPT_setStartTopIntCon(PTPT_Start arg, PTPT_IntCon topIntCon);
ATbool PTPT_hasStartTopNatCon(PTPT_Start arg);
PTPT_NatCon PTPT_getStartTopNatCon(PTPT_Start arg);
PTPT_Start PTPT_setStartTopNatCon(PTPT_Start arg, PTPT_NatCon topNatCon);

/*}}}  */
/*{{{  PTPT_OptLayout accessors */

ATbool PTPT_isValidOptLayout(PTPT_OptLayout arg);
inline ATbool PTPT_isOptLayoutAbsent(PTPT_OptLayout arg);
inline ATbool PTPT_isOptLayoutPresent(PTPT_OptLayout arg);
ATbool PTPT_hasOptLayoutChars(PTPT_OptLayout arg);
PTPT_CHARLIST PTPT_getOptLayoutChars(PTPT_OptLayout arg);
PTPT_OptLayout PTPT_setOptLayoutChars(PTPT_OptLayout arg, PTPT_CHARLIST chars);

/*}}}  */
/*{{{  sort visitors */

PTPT_NatCon PTPT_visitNatCon(PTPT_NatCon arg, PTPT_CHARLIST (*acceptChars)(PTPT_CHARLIST));
PTPT_IntCon PTPT_visitIntCon(PTPT_IntCon arg, PTPT_NatCon (*acceptNatCon)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterPos)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterNeg)(PTPT_OptLayout));
PTPT_Tree PTPT_visitTree(PTPT_Tree arg, PTPT_OptLayout (*acceptWsAfterTree)(PTPT_OptLayout), PTPT_Ann (*acceptAnn)(PTPT_Ann), PTPT_OptLayout (*acceptWsAfterAppl)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Production (*acceptProd)(PTPT_Production), PTPT_OptLayout (*acceptWsAfterProd)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_Args (*acceptArgs)(PTPT_Args), PTPT_OptLayout (*acceptWsAfterArgs)(PTPT_OptLayout), PTPT_NatCon (*acceptCharacter)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterLit)(PTPT_OptLayout), PTPT_QLiteral (*acceptString)(PTPT_QLiteral), PTPT_OptLayout (*acceptWsAfterString)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterAmb)(PTPT_OptLayout));
PTPT_Args PTPT_visitArgs(PTPT_Args arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_TreeList (*acceptList)(PTPT_TreeList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_TreeList PTPT_visitTreeList(PTPT_TreeList arg, PTPT_Tree (*acceptHead)(PTPT_Tree), PTPT_OptLayout (*acceptWsAfterFirst)(PTPT_OptLayout), char * (*acceptSep)(char *), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_Production PTPT_visitProduction(PTPT_Production arg, PTPT_OptLayout (*acceptWsAfterProd)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Symbols (*acceptLhs)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterLhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma1)(PTPT_OptLayout), PTPT_Symbol (*acceptRhs)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterRhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma2)(PTPT_OptLayout), PTPT_Attributes (*acceptAttributes)(PTPT_Attributes), PTPT_OptLayout (*acceptWsAfterAttributes)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_Symbol PTPT_visitSymbol(PTPT_Symbol arg, PTPT_OptLayout (*acceptWsAfterLit)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_QLiteral (*acceptString)(PTPT_QLiteral), PTPT_OptLayout (*acceptWsAfterString)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCf)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSymbol)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLex)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterOpt)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterAlt)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterRhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSeq)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTuple)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_Symbols (*acceptRest)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterRest)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSort)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIter)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterStar)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterSep)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSeparator)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterStarSep)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterN)(PTPT_OptLayout), PTPT_NatCon (*acceptNumber)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterNumber)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterSepN)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma1)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma2)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterFunc)(PTPT_OptLayout), PTPT_Symbols (*acceptSymbols)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterSymbols)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterVarsym)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCharClass)(PTPT_OptLayout), PTPT_CharRanges (*acceptCharRanges)(PTPT_CharRanges), PTPT_OptLayout (*acceptWsAfterCharRanges)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterStrategy)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParametrizedSort)(PTPT_OptLayout), PTPT_QLiteral (*acceptSort)(PTPT_QLiteral), PTPT_Symbols (*acceptParameters)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterParameters)(PTPT_OptLayout));
PTPT_Symbols PTPT_visitSymbols(PTPT_Symbols arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_SymbolList (*acceptList)(PTPT_SymbolList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_SymbolList PTPT_visitSymbolList(PTPT_SymbolList arg, PTPT_Symbol (*acceptHead)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterFirst)(PTPT_OptLayout), char * (*acceptSep)(char *), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_CharRanges PTPT_visitCharRanges(PTPT_CharRanges arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_CharRangeList (*acceptList)(PTPT_CharRangeList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_CharRangeList PTPT_visitCharRangeList(PTPT_CharRangeList arg, PTPT_CharRange (*acceptHead)(PTPT_CharRange), PTPT_OptLayout (*acceptWsAfterFirst)(PTPT_OptLayout), char * (*acceptSep)(char *), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_CharRange PTPT_visitCharRange(PTPT_CharRange arg, PTPT_NatCon (*acceptInteger)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterRange)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_NatCon (*acceptStart)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterStart)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_NatCon (*acceptEnd)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterEnd)(PTPT_OptLayout));
PTPT_OptExp PTPT_visitOptExp(PTPT_OptExp arg, PTPT_OptLayout (*acceptWsAfterE)(PTPT_OptLayout), PTPT_IntCon (*acceptIntCon)(PTPT_IntCon));
PTPT_RealCon PTPT_visitRealCon(PTPT_RealCon arg, PTPT_IntCon (*acceptIntCon)(PTPT_IntCon), PTPT_OptLayout (*acceptWsAfterIntCon)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterPeriod)(PTPT_OptLayout), PTPT_NatCon (*acceptNatCon)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterNatCon)(PTPT_OptLayout), PTPT_OptExp (*acceptOptExp)(PTPT_OptExp));
PTPT_ATermList PTPT_visitATermList(PTPT_ATermList arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_ATermElems (*acceptElems)(PTPT_ATermElems), PTPT_OptLayout (*acceptWsAfterElems)(PTPT_OptLayout));
PTPT_ATermElems PTPT_visitATermElems(PTPT_ATermElems arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterFirst)(PTPT_OptLayout), char * (*acceptSep)(char *), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_ACon PTPT_visitACon(PTPT_ACon arg, PTPT_IntCon (*acceptIntCon)(PTPT_IntCon), PTPT_RealCon (*acceptRealCon)(PTPT_RealCon));
PTPT_AFun PTPT_visitAFun(PTPT_AFun arg, PTPT_Literal (*acceptLiteral)(PTPT_Literal));
PTPT_ATerm PTPT_visitATerm(PTPT_ATerm arg, PTPT_ACon (*acceptACon)(PTPT_ACon), PTPT_ATermList (*acceptList)(PTPT_ATermList), PTPT_AFun (*acceptFun)(PTPT_AFun), PTPT_OptLayout (*acceptWsAfterFun)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_ATermArgs (*acceptArgs)(PTPT_ATermArgs), PTPT_OptLayout (*acceptWsAfterArgs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterACon)(PTPT_OptLayout), PTPT_Ann (*acceptAnn)(PTPT_Ann), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenClose)(PTPT_OptLayout));
PTPT_ATermArgs PTPT_visitATermArgs(PTPT_ATermArgs arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterFirst)(PTPT_OptLayout), char * (*acceptSep)(char *), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_Ann PTPT_visitAnn(PTPT_Ann arg, PTPT_OptLayout (*acceptWsAfterBraceOpen)(PTPT_OptLayout), PTPT_ATermAnnos (*acceptAnnos)(PTPT_ATermAnnos), PTPT_OptLayout (*acceptWsAfterAnnos)(PTPT_OptLayout));
PTPT_ATermAnnos PTPT_visitATermAnnos(PTPT_ATermAnnos arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterFirst)(PTPT_OptLayout), char * (*acceptSep)(char *), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_AlphaNumericalEscChar PTPT_visitAlphaNumericalEscChar(PTPT_AlphaNumericalEscChar arg, PTPT_CHARLIST (*acceptChars)(PTPT_CHARLIST));
PTPT_DecimalEscChar PTPT_visitDecimalEscChar(PTPT_DecimalEscChar arg, PTPT_CHARLIST (*acceptChars)(PTPT_CHARLIST));
PTPT_EscChar PTPT_visitEscChar(PTPT_EscChar arg, PTPT_CHARLIST (*acceptChars)(PTPT_CHARLIST));
PTPT_LChar PTPT_visitLChar(PTPT_LChar arg, PTPT_CHARLIST (*acceptChars)(PTPT_CHARLIST));
PTPT_QLiteral PTPT_visitQLiteral(PTPT_QLiteral arg, PTPT_CHARLIST (*acceptChars)(PTPT_CHARLIST));
PTPT_UQLiteral PTPT_visitUQLiteral(PTPT_UQLiteral arg, PTPT_CHARLIST (*acceptChars)(PTPT_CHARLIST));
PTPT_Literal PTPT_visitLiteral(PTPT_Literal arg, PTPT_QLiteral (*acceptQLiteral)(PTPT_QLiteral), PTPT_UQLiteral (*acceptUQLiteral)(PTPT_UQLiteral));
PTPT_Attributes PTPT_visitAttributes(PTPT_Attributes arg, PTPT_OptLayout (*acceptWsAfterAttrs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Attrs (*acceptAttributes)(PTPT_Attrs), PTPT_OptLayout (*acceptWsAfterAttributes)(PTPT_OptLayout));
PTPT_Attrs PTPT_visitAttrs(PTPT_Attrs arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_AttrList (*acceptList)(PTPT_AttrList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_AttrList PTPT_visitAttrList(PTPT_AttrList arg, PTPT_Attr (*acceptHead)(PTPT_Attr), PTPT_OptLayout (*acceptWsAfterFirst)(PTPT_OptLayout), char * (*acceptSep)(char *), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_Attr PTPT_visitAttr(PTPT_Attr arg, PTPT_OptLayout (*acceptWsAfterAssoc)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Associativity (*acceptAssociativity)(PTPT_Associativity), PTPT_OptLayout (*acceptWsAfterAssociativity)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTerm)(PTPT_OptLayout), PTPT_ATerm (*acceptAterm)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterAterm)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterId)(PTPT_OptLayout), PTPT_QLiteral (*acceptModuleName)(PTPT_QLiteral), PTPT_OptLayout (*acceptWsAfterModuleName)(PTPT_OptLayout));
PTPT_Associativity PTPT_visitAssociativity(PTPT_Associativity arg);
PTPT_ParseTree PTPT_visitParseTree(PTPT_ParseTree arg, PTPT_OptLayout (*acceptWsAfterParsetree)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Tree (*acceptTop)(PTPT_Tree), PTPT_OptLayout (*acceptWsAfterTop)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_NatCon (*acceptAmbCnt)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterAmbCnt)(PTPT_OptLayout));
PTPT_Start PTPT_visitStart(PTPT_Start arg, PTPT_OptLayout (*acceptWsBefore)(PTPT_OptLayout), PTPT_ParseTree (*acceptTopParseTree)(PTPT_ParseTree), PTPT_OptLayout (*acceptWsAfter)(PTPT_OptLayout), int (*acceptAmbCnt)(int), PTPT_Associativity (*acceptTopAssociativity)(PTPT_Associativity), PTPT_Attr (*acceptTopAttr)(PTPT_Attr), PTPT_Attrs (*acceptTopAttrs)(PTPT_Attrs), PTPT_Attributes (*acceptTopAttributes)(PTPT_Attributes), PTPT_QLiteral (*acceptTopQLiteral)(PTPT_QLiteral), PTPT_UQLiteral (*acceptTopUQLiteral)(PTPT_UQLiteral), PTPT_Literal (*acceptTopLiteral)(PTPT_Literal), PTPT_Ann (*acceptTopAnn)(PTPT_Ann), PTPT_ATerm (*acceptTopATerm)(PTPT_ATerm), PTPT_AFun (*acceptTopAFun)(PTPT_AFun), PTPT_ACon (*acceptTopACon)(PTPT_ACon), PTPT_ATermList (*acceptTopATermList)(PTPT_ATermList), PTPT_RealCon (*acceptTopRealCon)(PTPT_RealCon), PTPT_OptExp (*acceptTopOptExp)(PTPT_OptExp), PTPT_CharRanges (*acceptTopCharRanges)(PTPT_CharRanges), PTPT_CharRange (*acceptTopCharRange)(PTPT_CharRange), PTPT_Symbols (*acceptTopSymbols)(PTPT_Symbols), PTPT_Symbol (*acceptTopSymbol)(PTPT_Symbol), PTPT_Production (*acceptTopProduction)(PTPT_Production), PTPT_Args (*acceptTopArgs)(PTPT_Args), PTPT_Tree (*acceptTopTree)(PTPT_Tree), PTPT_IntCon (*acceptTopIntCon)(PTPT_IntCon), PTPT_NatCon (*acceptTopNatCon)(PTPT_NatCon));
PTPT_OptLayout PTPT_visitOptLayout(PTPT_OptLayout arg, PTPT_CHARLIST (*acceptChars)(PTPT_CHARLIST));

/*}}}  */

#endif /* _PTMEPT_H */
