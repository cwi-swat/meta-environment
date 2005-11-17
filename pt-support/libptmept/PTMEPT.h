#ifndef _PTMEPT_H
#define _PTMEPT_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "PTMEPT_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _PTPT_OptLayout *PTPT_OptLayout;
typedef struct _PTPT_Layout *PTPT_Layout;
typedef struct _PTPT_LexLayoutList *PTPT_LexLayoutList;
typedef struct _PTPT_Tree *PTPT_Tree;
typedef struct _PTPT_Attributes *PTPT_Attributes;
typedef struct _PTPT_Attrs *PTPT_Attrs;
typedef struct _PTPT_Attr *PTPT_Attr;
typedef struct _PTPT_Associativity *PTPT_Associativity;
typedef struct _PTPT_AttrList *PTPT_AttrList;
typedef struct _PTPT_ParseTree *PTPT_ParseTree;
typedef struct _PTPT_Symbol *PTPT_Symbol;
typedef struct _PTPT_Symbols *PTPT_Symbols;
typedef struct _PTPT_CharRanges *PTPT_CharRanges;
typedef struct _PTPT_CharRange *PTPT_CharRange;
typedef struct _PTPT_Start *PTPT_Start;
typedef struct _PTPT_SymbolList *PTPT_SymbolList;
typedef struct _PTPT_CharRangeList *PTPT_CharRangeList;
typedef struct _PTPT_Args *PTPT_Args;
typedef struct _PTPT_Production *PTPT_Production;
typedef struct _PTPT_TreeList *PTPT_TreeList;
typedef struct _PTPT_AFun *PTPT_AFun;
typedef struct _PTPT_ATerm *PTPT_ATerm;
typedef struct _PTPT_Annotation *PTPT_Annotation;
typedef struct _PTPT_ATermArgs *PTPT_ATermArgs;
typedef struct _PTPT_ATermElems *PTPT_ATermElems;
typedef struct _PTPT_ATermAnnos *PTPT_ATermAnnos;
typedef struct _PTPT_IntCon *PTPT_IntCon;
typedef struct _PTPT_OptExp *PTPT_OptExp;
typedef struct _PTPT_RealCon *PTPT_RealCon;
typedef struct _PTPT_LexStrChar *PTPT_LexStrChar;
typedef struct _PTPT_StrChar *PTPT_StrChar;
typedef struct _PTPT_LexStrCon *PTPT_LexStrCon;
typedef struct _PTPT_StrCon *PTPT_StrCon;
typedef struct _PTPT_LexStrCharChars *PTPT_LexStrCharChars;
typedef struct _PTPT_LexNatCon *PTPT_LexNatCon;
typedef struct _PTPT_NatCon *PTPT_NatCon;
typedef struct _PTPT_LexIdCon *PTPT_LexIdCon;
typedef struct _PTPT_IdCon *PTPT_IdCon;
typedef struct _PTPT_LexLayout *PTPT_LexLayout;

/*}}}  */

void PTPT_initPTMEPTApi(void);

/*{{{  protect functions */

void PTPT_protectOptLayout(PTPT_OptLayout *arg);
void PTPT_protectLayout(PTPT_Layout *arg);
void PTPT_protectLexLayoutList(PTPT_LexLayoutList *arg);
void PTPT_protectTree(PTPT_Tree *arg);
void PTPT_protectAttributes(PTPT_Attributes *arg);
void PTPT_protectAttrs(PTPT_Attrs *arg);
void PTPT_protectAttr(PTPT_Attr *arg);
void PTPT_protectAssociativity(PTPT_Associativity *arg);
void PTPT_protectAttrList(PTPT_AttrList *arg);
void PTPT_protectParseTree(PTPT_ParseTree *arg);
void PTPT_protectSymbol(PTPT_Symbol *arg);
void PTPT_protectSymbols(PTPT_Symbols *arg);
void PTPT_protectCharRanges(PTPT_CharRanges *arg);
void PTPT_protectCharRange(PTPT_CharRange *arg);
void PTPT_protectStart(PTPT_Start *arg);
void PTPT_protectSymbolList(PTPT_SymbolList *arg);
void PTPT_protectCharRangeList(PTPT_CharRangeList *arg);
void PTPT_protectArgs(PTPT_Args *arg);
void PTPT_protectProduction(PTPT_Production *arg);
void PTPT_protectTreeList(PTPT_TreeList *arg);
void PTPT_protectAFun(PTPT_AFun *arg);
void PTPT_protectATerm(PTPT_ATerm *arg);
void PTPT_protectAnnotation(PTPT_Annotation *arg);
void PTPT_protectATermArgs(PTPT_ATermArgs *arg);
void PTPT_protectATermElems(PTPT_ATermElems *arg);
void PTPT_protectATermAnnos(PTPT_ATermAnnos *arg);
void PTPT_protectIntCon(PTPT_IntCon *arg);
void PTPT_protectOptExp(PTPT_OptExp *arg);
void PTPT_protectRealCon(PTPT_RealCon *arg);
void PTPT_protectLexStrChar(PTPT_LexStrChar *arg);
void PTPT_protectStrChar(PTPT_StrChar *arg);
void PTPT_protectLexStrCon(PTPT_LexStrCon *arg);
void PTPT_protectStrCon(PTPT_StrCon *arg);
void PTPT_protectLexStrCharChars(PTPT_LexStrCharChars *arg);
void PTPT_protectLexNatCon(PTPT_LexNatCon *arg);
void PTPT_protectNatCon(PTPT_NatCon *arg);
void PTPT_protectLexIdCon(PTPT_LexIdCon *arg);
void PTPT_protectIdCon(PTPT_IdCon *arg);
void PTPT_protectLexLayout(PTPT_LexLayout *arg);

/*}}}  */
/*{{{  term conversion functions */

PTPT_OptLayout PTPT_OptLayoutFromTerm(ATerm t);
ATerm PTPT_OptLayoutToTerm(PTPT_OptLayout arg);
PTPT_Layout PTPT_LayoutFromTerm(ATerm t);
ATerm PTPT_LayoutToTerm(PTPT_Layout arg);
PTPT_LexLayoutList PTPT_LexLayoutListFromTerm(ATerm t);
ATerm PTPT_LexLayoutListToTerm(PTPT_LexLayoutList arg);
PTPT_Tree PTPT_TreeFromTerm(ATerm t);
ATerm PTPT_TreeToTerm(PTPT_Tree arg);
PTPT_Attributes PTPT_AttributesFromTerm(ATerm t);
ATerm PTPT_AttributesToTerm(PTPT_Attributes arg);
PTPT_Attrs PTPT_AttrsFromTerm(ATerm t);
ATerm PTPT_AttrsToTerm(PTPT_Attrs arg);
PTPT_Attr PTPT_AttrFromTerm(ATerm t);
ATerm PTPT_AttrToTerm(PTPT_Attr arg);
PTPT_Associativity PTPT_AssociativityFromTerm(ATerm t);
ATerm PTPT_AssociativityToTerm(PTPT_Associativity arg);
PTPT_AttrList PTPT_AttrListFromTerm(ATerm t);
ATerm PTPT_AttrListToTerm(PTPT_AttrList arg);
PTPT_ParseTree PTPT_ParseTreeFromTerm(ATerm t);
ATerm PTPT_ParseTreeToTerm(PTPT_ParseTree arg);
PTPT_Symbol PTPT_SymbolFromTerm(ATerm t);
ATerm PTPT_SymbolToTerm(PTPT_Symbol arg);
PTPT_Symbols PTPT_SymbolsFromTerm(ATerm t);
ATerm PTPT_SymbolsToTerm(PTPT_Symbols arg);
PTPT_CharRanges PTPT_CharRangesFromTerm(ATerm t);
ATerm PTPT_CharRangesToTerm(PTPT_CharRanges arg);
PTPT_CharRange PTPT_CharRangeFromTerm(ATerm t);
ATerm PTPT_CharRangeToTerm(PTPT_CharRange arg);
PTPT_Start PTPT_StartFromTerm(ATerm t);
ATerm PTPT_StartToTerm(PTPT_Start arg);
PTPT_SymbolList PTPT_SymbolListFromTerm(ATerm t);
ATerm PTPT_SymbolListToTerm(PTPT_SymbolList arg);
PTPT_CharRangeList PTPT_CharRangeListFromTerm(ATerm t);
ATerm PTPT_CharRangeListToTerm(PTPT_CharRangeList arg);
PTPT_Args PTPT_ArgsFromTerm(ATerm t);
ATerm PTPT_ArgsToTerm(PTPT_Args arg);
PTPT_Production PTPT_ProductionFromTerm(ATerm t);
ATerm PTPT_ProductionToTerm(PTPT_Production arg);
PTPT_TreeList PTPT_TreeListFromTerm(ATerm t);
ATerm PTPT_TreeListToTerm(PTPT_TreeList arg);
PTPT_AFun PTPT_AFunFromTerm(ATerm t);
ATerm PTPT_AFunToTerm(PTPT_AFun arg);
PTPT_ATerm PTPT_ATermFromTerm(ATerm t);
ATerm PTPT_ATermToTerm(PTPT_ATerm arg);
PTPT_Annotation PTPT_AnnotationFromTerm(ATerm t);
ATerm PTPT_AnnotationToTerm(PTPT_Annotation arg);
PTPT_ATermArgs PTPT_ATermArgsFromTerm(ATerm t);
ATerm PTPT_ATermArgsToTerm(PTPT_ATermArgs arg);
PTPT_ATermElems PTPT_ATermElemsFromTerm(ATerm t);
ATerm PTPT_ATermElemsToTerm(PTPT_ATermElems arg);
PTPT_ATermAnnos PTPT_ATermAnnosFromTerm(ATerm t);
ATerm PTPT_ATermAnnosToTerm(PTPT_ATermAnnos arg);
PTPT_IntCon PTPT_IntConFromTerm(ATerm t);
ATerm PTPT_IntConToTerm(PTPT_IntCon arg);
PTPT_OptExp PTPT_OptExpFromTerm(ATerm t);
ATerm PTPT_OptExpToTerm(PTPT_OptExp arg);
PTPT_RealCon PTPT_RealConFromTerm(ATerm t);
ATerm PTPT_RealConToTerm(PTPT_RealCon arg);
PTPT_LexStrChar PTPT_LexStrCharFromTerm(ATerm t);
ATerm PTPT_LexStrCharToTerm(PTPT_LexStrChar arg);
PTPT_StrChar PTPT_StrCharFromTerm(ATerm t);
ATerm PTPT_StrCharToTerm(PTPT_StrChar arg);
PTPT_LexStrCon PTPT_LexStrConFromTerm(ATerm t);
ATerm PTPT_LexStrConToTerm(PTPT_LexStrCon arg);
PTPT_StrCon PTPT_StrConFromTerm(ATerm t);
ATerm PTPT_StrConToTerm(PTPT_StrCon arg);
PTPT_LexStrCharChars PTPT_LexStrCharCharsFromTerm(ATerm t);
ATerm PTPT_LexStrCharCharsToTerm(PTPT_LexStrCharChars arg);
PTPT_LexNatCon PTPT_LexNatConFromTerm(ATerm t);
ATerm PTPT_LexNatConToTerm(PTPT_LexNatCon arg);
PTPT_NatCon PTPT_NatConFromTerm(ATerm t);
ATerm PTPT_NatConToTerm(PTPT_NatCon arg);
PTPT_LexIdCon PTPT_LexIdConFromTerm(ATerm t);
ATerm PTPT_LexIdConToTerm(PTPT_LexIdCon arg);
PTPT_IdCon PTPT_IdConFromTerm(ATerm t);
ATerm PTPT_IdConToTerm(PTPT_IdCon arg);
PTPT_LexLayout PTPT_LexLayoutFromTerm(ATerm t);
ATerm PTPT_LexLayoutToTerm(PTPT_LexLayout arg);

/*}}}  */
/*{{{  list functions */

int PTPT_getLexLayoutListLength (PTPT_LexLayoutList arg);
PTPT_LexLayoutList PTPT_reverseLexLayoutList(PTPT_LexLayoutList arg);
PTPT_LexLayoutList PTPT_appendLexLayoutList(PTPT_LexLayoutList arg, PTPT_LexLayout elem);
PTPT_LexLayoutList PTPT_concatLexLayoutList(PTPT_LexLayoutList arg0, PTPT_LexLayoutList arg1);
PTPT_LexLayoutList PTPT_sliceLexLayoutList(PTPT_LexLayoutList arg, int start, int end);
PTPT_LexLayout PTPT_getLexLayoutListLexLayoutAt(PTPT_LexLayoutList arg, int index);
PTPT_LexLayoutList PTPT_replaceLexLayoutListLexLayoutAt(PTPT_LexLayoutList arg, PTPT_LexLayout elem, int index);
PTPT_LexLayoutList PTPT_makeLexLayoutList2(PTPT_LexLayout elem1, PTPT_LexLayout elem2);
PTPT_LexLayoutList PTPT_makeLexLayoutList3(PTPT_LexLayout elem1, PTPT_LexLayout elem2, PTPT_LexLayout elem3);
PTPT_LexLayoutList PTPT_makeLexLayoutList4(PTPT_LexLayout elem1, PTPT_LexLayout elem2, PTPT_LexLayout elem3, PTPT_LexLayout elem4);
PTPT_LexLayoutList PTPT_makeLexLayoutList5(PTPT_LexLayout elem1, PTPT_LexLayout elem2, PTPT_LexLayout elem3, PTPT_LexLayout elem4, PTPT_LexLayout elem5);
PTPT_LexLayoutList PTPT_makeLexLayoutList6(PTPT_LexLayout elem1, PTPT_LexLayout elem2, PTPT_LexLayout elem3, PTPT_LexLayout elem4, PTPT_LexLayout elem5, PTPT_LexLayout elem6);
int PTPT_getAttrListLength (PTPT_AttrList arg);
PTPT_AttrList PTPT_reverseAttrList(PTPT_AttrList arg);
PTPT_AttrList PTPT_appendAttrList(PTPT_AttrList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr arg1);
PTPT_AttrList PTPT_concatAttrList(PTPT_AttrList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_AttrList arg1);
PTPT_AttrList PTPT_sliceAttrList(PTPT_AttrList arg, int start, int end);
PTPT_Attr PTPT_getAttrListAttrAt(PTPT_AttrList arg, int index);
PTPT_AttrList PTPT_replaceAttrListAttrAt(PTPT_AttrList arg, PTPT_Attr elem, int index);
PTPT_AttrList PTPT_makeAttrList2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2);
PTPT_AttrList PTPT_makeAttrList3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2, PTPT_Attr elem3);
PTPT_AttrList PTPT_makeAttrList4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2, PTPT_Attr elem3, PTPT_Attr elem4);
PTPT_AttrList PTPT_makeAttrList5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2, PTPT_Attr elem3, PTPT_Attr elem4, PTPT_Attr elem5);
PTPT_AttrList PTPT_makeAttrList6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2, PTPT_Attr elem3, PTPT_Attr elem4, PTPT_Attr elem5, PTPT_Attr elem6);
int PTPT_getSymbolListLength (PTPT_SymbolList arg);
PTPT_SymbolList PTPT_reverseSymbolList(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_appendSymbolList(PTPT_SymbolList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol arg1);
PTPT_SymbolList PTPT_concatSymbolList(PTPT_SymbolList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_SymbolList arg1);
PTPT_SymbolList PTPT_sliceSymbolList(PTPT_SymbolList arg, int start, int end);
PTPT_Symbol PTPT_getSymbolListSymbolAt(PTPT_SymbolList arg, int index);
PTPT_SymbolList PTPT_replaceSymbolListSymbolAt(PTPT_SymbolList arg, PTPT_Symbol elem, int index);
PTPT_SymbolList PTPT_makeSymbolList2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2);
PTPT_SymbolList PTPT_makeSymbolList3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2, PTPT_Symbol elem3);
PTPT_SymbolList PTPT_makeSymbolList4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2, PTPT_Symbol elem3, PTPT_Symbol elem4);
PTPT_SymbolList PTPT_makeSymbolList5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2, PTPT_Symbol elem3, PTPT_Symbol elem4, PTPT_Symbol elem5);
PTPT_SymbolList PTPT_makeSymbolList6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2, PTPT_Symbol elem3, PTPT_Symbol elem4, PTPT_Symbol elem5, PTPT_Symbol elem6);
int PTPT_getCharRangeListLength (PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_reverseCharRangeList(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_appendCharRangeList(PTPT_CharRangeList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange arg1);
PTPT_CharRangeList PTPT_concatCharRangeList(PTPT_CharRangeList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRangeList arg1);
PTPT_CharRangeList PTPT_sliceCharRangeList(PTPT_CharRangeList arg, int start, int end);
PTPT_CharRange PTPT_getCharRangeListCharRangeAt(PTPT_CharRangeList arg, int index);
PTPT_CharRangeList PTPT_replaceCharRangeListCharRangeAt(PTPT_CharRangeList arg, PTPT_CharRange elem, int index);
PTPT_CharRangeList PTPT_makeCharRangeList2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2);
PTPT_CharRangeList PTPT_makeCharRangeList3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2, PTPT_CharRange elem3);
PTPT_CharRangeList PTPT_makeCharRangeList4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2, PTPT_CharRange elem3, PTPT_CharRange elem4);
PTPT_CharRangeList PTPT_makeCharRangeList5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2, PTPT_CharRange elem3, PTPT_CharRange elem4, PTPT_CharRange elem5);
PTPT_CharRangeList PTPT_makeCharRangeList6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2, PTPT_CharRange elem3, PTPT_CharRange elem4, PTPT_CharRange elem5, PTPT_CharRange elem6);
int PTPT_getTreeListLength (PTPT_TreeList arg);
PTPT_TreeList PTPT_reverseTreeList(PTPT_TreeList arg);
PTPT_TreeList PTPT_appendTreeList(PTPT_TreeList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree arg1);
PTPT_TreeList PTPT_concatTreeList(PTPT_TreeList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_TreeList arg1);
PTPT_TreeList PTPT_sliceTreeList(PTPT_TreeList arg, int start, int end);
PTPT_Tree PTPT_getTreeListTreeAt(PTPT_TreeList arg, int index);
PTPT_TreeList PTPT_replaceTreeListTreeAt(PTPT_TreeList arg, PTPT_Tree elem, int index);
PTPT_TreeList PTPT_makeTreeList2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2);
PTPT_TreeList PTPT_makeTreeList3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2, PTPT_Tree elem3);
PTPT_TreeList PTPT_makeTreeList4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2, PTPT_Tree elem3, PTPT_Tree elem4);
PTPT_TreeList PTPT_makeTreeList5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2, PTPT_Tree elem3, PTPT_Tree elem4, PTPT_Tree elem5);
PTPT_TreeList PTPT_makeTreeList6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2, PTPT_Tree elem3, PTPT_Tree elem4, PTPT_Tree elem5, PTPT_Tree elem6);
int PTPT_getATermArgsLength (PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_reverseATermArgs(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_appendATermArgs(PTPT_ATermArgs arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm arg1);
PTPT_ATermArgs PTPT_concatATermArgs(PTPT_ATermArgs arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermArgs arg1);
PTPT_ATermArgs PTPT_sliceATermArgs(PTPT_ATermArgs arg, int start, int end);
PTPT_ATerm PTPT_getATermArgsATermAt(PTPT_ATermArgs arg, int index);
PTPT_ATermArgs PTPT_replaceATermArgsATermAt(PTPT_ATermArgs arg, PTPT_ATerm elem, int index);
PTPT_ATermArgs PTPT_makeATermArgs2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2);
PTPT_ATermArgs PTPT_makeATermArgs3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3);
PTPT_ATermArgs PTPT_makeATermArgs4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4);
PTPT_ATermArgs PTPT_makeATermArgs5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5);
PTPT_ATermArgs PTPT_makeATermArgs6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5, PTPT_ATerm elem6);
int PTPT_getATermElemsLength (PTPT_ATermElems arg);
PTPT_ATermElems PTPT_reverseATermElems(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_appendATermElems(PTPT_ATermElems arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm arg1);
PTPT_ATermElems PTPT_concatATermElems(PTPT_ATermElems arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermElems arg1);
PTPT_ATermElems PTPT_sliceATermElems(PTPT_ATermElems arg, int start, int end);
PTPT_ATerm PTPT_getATermElemsATermAt(PTPT_ATermElems arg, int index);
PTPT_ATermElems PTPT_replaceATermElemsATermAt(PTPT_ATermElems arg, PTPT_ATerm elem, int index);
PTPT_ATermElems PTPT_makeATermElems2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2);
PTPT_ATermElems PTPT_makeATermElems3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3);
PTPT_ATermElems PTPT_makeATermElems4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4);
PTPT_ATermElems PTPT_makeATermElems5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5);
PTPT_ATermElems PTPT_makeATermElems6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5, PTPT_ATerm elem6);
int PTPT_getATermAnnosLength (PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_reverseATermAnnos(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_appendATermAnnos(PTPT_ATermAnnos arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm arg1);
PTPT_ATermAnnos PTPT_concatATermAnnos(PTPT_ATermAnnos arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermAnnos arg1);
PTPT_ATermAnnos PTPT_sliceATermAnnos(PTPT_ATermAnnos arg, int start, int end);
PTPT_ATerm PTPT_getATermAnnosATermAt(PTPT_ATermAnnos arg, int index);
PTPT_ATermAnnos PTPT_replaceATermAnnosATermAt(PTPT_ATermAnnos arg, PTPT_ATerm elem, int index);
PTPT_ATermAnnos PTPT_makeATermAnnos2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2);
PTPT_ATermAnnos PTPT_makeATermAnnos3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3);
PTPT_ATermAnnos PTPT_makeATermAnnos4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4);
PTPT_ATermAnnos PTPT_makeATermAnnos5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5);
PTPT_ATermAnnos PTPT_makeATermAnnos6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5, PTPT_ATerm elem6);
int PTPT_getLexStrCharCharsLength (PTPT_LexStrCharChars arg);
PTPT_LexStrCharChars PTPT_reverseLexStrCharChars(PTPT_LexStrCharChars arg);
PTPT_LexStrCharChars PTPT_appendLexStrCharChars(PTPT_LexStrCharChars arg, PTPT_LexStrChar elem);
PTPT_LexStrCharChars PTPT_concatLexStrCharChars(PTPT_LexStrCharChars arg0, PTPT_LexStrCharChars arg1);
PTPT_LexStrCharChars PTPT_sliceLexStrCharChars(PTPT_LexStrCharChars arg, int start, int end);
PTPT_LexStrChar PTPT_getLexStrCharCharsLexStrCharAt(PTPT_LexStrCharChars arg, int index);
PTPT_LexStrCharChars PTPT_replaceLexStrCharCharsLexStrCharAt(PTPT_LexStrCharChars arg, PTPT_LexStrChar elem, int index);
PTPT_LexStrCharChars PTPT_makeLexStrCharChars2(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2);
PTPT_LexStrCharChars PTPT_makeLexStrCharChars3(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2, PTPT_LexStrChar elem3);
PTPT_LexStrCharChars PTPT_makeLexStrCharChars4(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2, PTPT_LexStrChar elem3, PTPT_LexStrChar elem4);
PTPT_LexStrCharChars PTPT_makeLexStrCharChars5(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2, PTPT_LexStrChar elem3, PTPT_LexStrChar elem4, PTPT_LexStrChar elem5);
PTPT_LexStrCharChars PTPT_makeLexStrCharChars6(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2, PTPT_LexStrChar elem3, PTPT_LexStrChar elem4, PTPT_LexStrChar elem5, PTPT_LexStrChar elem6);

/*}}}  */
/*{{{  constructors */

PTPT_OptLayout PTPT_makeOptLayoutAbsent(void);
PTPT_OptLayout PTPT_makeOptLayoutPresent(PTPT_Layout layout);
PTPT_Layout PTPT_makeLayoutLexToCf(PTPT_LexLayoutList list);
PTPT_LexLayoutList PTPT_makeLexLayoutListEmpty(void);
PTPT_LexLayoutList PTPT_makeLexLayoutListSingle(PTPT_LexLayout head);
PTPT_LexLayoutList PTPT_makeLexLayoutListMany(PTPT_LexLayout head, PTPT_LexLayoutList tail);
PTPT_Tree PTPT_makeTreeAnnotated(PTPT_Tree Tree, PTPT_OptLayout wsAfterTree, PTPT_Annotation Annotation);
PTPT_Tree PTPT_makeTreeAppl(PTPT_OptLayout wsAfterAppl, PTPT_OptLayout wsAfterParenOpen, PTPT_Production prod, PTPT_OptLayout wsAfterProd, PTPT_OptLayout wsAfterComma, PTPT_Args args, PTPT_OptLayout wsAfterArgs);
PTPT_Tree PTPT_makeTreeCycle(PTPT_OptLayout wsAfterCycle, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_NatCon cycleLength, PTPT_OptLayout wsAfterCycleLength);
PTPT_Tree PTPT_makeTreeAmb(PTPT_OptLayout wsAfterAmb, PTPT_OptLayout wsAfterParenOpen, PTPT_Args args, PTPT_OptLayout wsAfterArgs);
PTPT_Tree PTPT_makeTreeChar(PTPT_NatCon character);
PTPT_Attributes PTPT_makeAttributesNoAttrs(void);
PTPT_Attributes PTPT_makeAttributesAttrs(PTPT_OptLayout wsAfterAttrs, PTPT_OptLayout wsAfterParenOpen, PTPT_Attrs attributes, PTPT_OptLayout wsAfterAttributes);
PTPT_Attrs PTPT_makeAttrsMany(PTPT_OptLayout wsAfterBracketOpen, PTPT_AttrList list, PTPT_OptLayout wsAfterList);
PTPT_Attr PTPT_makeAttrAssoc(PTPT_OptLayout wsAfterAssoc, PTPT_OptLayout wsAfterParenOpen, PTPT_Associativity associativity, PTPT_OptLayout wsAfterAssociativity);
PTPT_Attr PTPT_makeAttrTerm(PTPT_OptLayout wsAfterTerm, PTPT_OptLayout wsAfterParenOpen, PTPT_ATerm aterm, PTPT_OptLayout wsAfterAterm);
PTPT_Attr PTPT_makeAttrId(PTPT_OptLayout wsAfterId, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon moduleName, PTPT_OptLayout wsAfterModuleName);
PTPT_Attr PTPT_makeAttrBracket(void);
PTPT_Attr PTPT_makeAttrReject(void);
PTPT_Attr PTPT_makeAttrPrefer(void);
PTPT_Attr PTPT_makeAttrAvoid(void);
PTPT_Associativity PTPT_makeAssociativityLeft(void);
PTPT_Associativity PTPT_makeAssociativityRight(void);
PTPT_Associativity PTPT_makeAssociativityAssoc(void);
PTPT_Associativity PTPT_makeAssociativityNonAssoc(void);
PTPT_AttrList PTPT_makeAttrListEmpty(void);
PTPT_AttrList PTPT_makeAttrListSingle(PTPT_Attr head);
PTPT_AttrList PTPT_makeAttrListMany(PTPT_Attr head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_AttrList tail);
PTPT_ParseTree PTPT_makeParseTreeTop(PTPT_OptLayout wsAfterParsetree, PTPT_OptLayout wsAfterParenOpen, PTPT_Tree top, PTPT_OptLayout wsAfterTop, PTPT_OptLayout wsAfterComma, PTPT_NatCon ambCnt, PTPT_OptLayout wsAfterAmbCnt);
PTPT_Symbol PTPT_makeSymbolEmpty(void);
PTPT_Symbol PTPT_makeSymbolLit(PTPT_OptLayout wsAfterLit, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString);
PTPT_Symbol PTPT_makeSymbolCilit(PTPT_OptLayout wsAfterCilit, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString);
PTPT_Symbol PTPT_makeSymbolCf(PTPT_OptLayout wsAfterCf, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolLex(PTPT_OptLayout wsAfterLex, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolOpt(PTPT_OptLayout wsAfterOpt, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolAlt(PTPT_OptLayout wsAfterAlt, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs);
PTPT_Symbol PTPT_makeSymbolSeq(PTPT_OptLayout wsAfterSeq, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols symbols, PTPT_OptLayout wsAfterSymbols);
PTPT_Symbol PTPT_makeSymbolTuple(PTPT_OptLayout wsAfterTuple, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterComma, PTPT_Symbols rest, PTPT_OptLayout wsAfterRest);
PTPT_Symbol PTPT_makeSymbolSort(PTPT_OptLayout wsAfterSort, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString);
PTPT_Symbol PTPT_makeSymbolIter(PTPT_OptLayout wsAfterIter, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolIterStar(PTPT_OptLayout wsAfterIterStar, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolIterSep(PTPT_OptLayout wsAfterIterSep, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator);
PTPT_Symbol PTPT_makeSymbolIterStarSep(PTPT_OptLayout wsAfterIterStarSep, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator);
PTPT_Symbol PTPT_makeSymbolIterN(PTPT_OptLayout wsAfterIterN, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_NatCon number, PTPT_OptLayout wsAfterNumber);
PTPT_Symbol PTPT_makeSymbolIterSepN(PTPT_OptLayout wsAfterIterSepN, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma1, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator, PTPT_OptLayout wsAfterComma2, PTPT_NatCon number, PTPT_OptLayout wsAfterNumber);
PTPT_Symbol PTPT_makeSymbolFunc(PTPT_OptLayout wsAfterFunc, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols symbols, PTPT_OptLayout wsAfterSymbols, PTPT_OptLayout wsAfterComma, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolVarsym(PTPT_OptLayout wsAfterVarsym, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_makeSymbolLayout(void);
PTPT_Symbol PTPT_makeSymbolCharClass(PTPT_OptLayout wsAfterCharClass, PTPT_OptLayout wsAfterParenOpen, PTPT_CharRanges CharRanges, PTPT_OptLayout wsAfterCharRanges);
PTPT_Symbol PTPT_makeSymbolStrategy(PTPT_OptLayout wsAfterStrategy, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs);
PTPT_Symbol PTPT_makeSymbolParameterizedSort(PTPT_OptLayout wsAfterParameterizedSort, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon sort, PTPT_OptLayout wsAfterSort, PTPT_OptLayout wsAfterComma, PTPT_Symbols parameters, PTPT_OptLayout wsAfterParameters);
PTPT_Symbols PTPT_makeSymbolsList(PTPT_OptLayout wsAfterBracketOpen, PTPT_SymbolList list, PTPT_OptLayout wsAfterList);
PTPT_CharRanges PTPT_makeCharRangesList(PTPT_OptLayout wsAfterBracketOpen, PTPT_CharRangeList list, PTPT_OptLayout wsAfterList);
PTPT_CharRange PTPT_makeCharRangeCharacter(PTPT_NatCon integer);
PTPT_CharRange PTPT_makeCharRangeRange(PTPT_OptLayout wsAfterRange, PTPT_OptLayout wsAfterParenOpen, PTPT_NatCon start, PTPT_OptLayout wsAfterStart, PTPT_OptLayout wsAfterComma, PTPT_NatCon end, PTPT_OptLayout wsAfterEnd);
PTPT_Start PTPT_makeStartSymbol(PTPT_OptLayout wsBefore, PTPT_Symbol topSymbol, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartTree(PTPT_OptLayout wsBefore, PTPT_Tree topTree, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartATerm(PTPT_OptLayout wsBefore, PTPT_ATerm topATerm, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartIntCon(PTPT_OptLayout wsBefore, PTPT_IntCon topIntCon, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_Start PTPT_makeStartRealCon(PTPT_OptLayout wsBefore, PTPT_RealCon topRealCon, PTPT_OptLayout wsAfter, int ambCnt);
PTPT_SymbolList PTPT_makeSymbolListEmpty(void);
PTPT_SymbolList PTPT_makeSymbolListSingle(PTPT_Symbol head);
PTPT_SymbolList PTPT_makeSymbolListMany(PTPT_Symbol head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_SymbolList tail);
PTPT_CharRangeList PTPT_makeCharRangeListEmpty(void);
PTPT_CharRangeList PTPT_makeCharRangeListSingle(PTPT_CharRange head);
PTPT_CharRangeList PTPT_makeCharRangeListMany(PTPT_CharRange head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRangeList tail);
PTPT_Args PTPT_makeArgsList(PTPT_OptLayout wsAfterBracketOpen, PTPT_TreeList list, PTPT_OptLayout wsAfterList);
PTPT_Production PTPT_makeProductionDefault(PTPT_OptLayout wsAfterProd, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma1, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs, PTPT_OptLayout wsAfterComma2, PTPT_Attributes attributes, PTPT_OptLayout wsAfterAttributes);
PTPT_Production PTPT_makeProductionList(PTPT_OptLayout wsAfterList, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs);
PTPT_TreeList PTPT_makeTreeListEmpty(void);
PTPT_TreeList PTPT_makeTreeListSingle(PTPT_Tree head);
PTPT_TreeList PTPT_makeTreeListMany(PTPT_Tree head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_TreeList tail);
PTPT_AFun PTPT_makeAFunQuoted(PTPT_StrCon StrCon);
PTPT_AFun PTPT_makeAFunUnquoted(PTPT_IdCon IdCon);
PTPT_ATerm PTPT_makeATermInt(PTPT_IntCon IntCon);
PTPT_ATerm PTPT_makeATermReal(PTPT_RealCon RealCon);
PTPT_ATerm PTPT_makeATermFun(PTPT_AFun fun);
PTPT_ATerm PTPT_makeATermAppl(PTPT_AFun fun, PTPT_OptLayout wsAfterFun, PTPT_OptLayout wsAfterParenOpen, PTPT_ATermArgs args, PTPT_OptLayout wsAfterArgs);
PTPT_ATerm PTPT_makeATermPlaceholder(PTPT_OptLayout wsAfterLessThan, PTPT_ATerm type, PTPT_OptLayout wsAfterType);
PTPT_ATerm PTPT_makeATermList(PTPT_OptLayout wsAfterBracketOpen, PTPT_ATermElems elems, PTPT_OptLayout wsAfterElems);
PTPT_ATerm PTPT_makeATermAnnotated(PTPT_ATerm trm, PTPT_OptLayout wsAfterTrm, PTPT_Annotation Annotation);
PTPT_Annotation PTPT_makeAnnotationDefault(PTPT_OptLayout wsAfterBraceOpen, PTPT_ATermAnnos annos, PTPT_OptLayout wsAfterAnnos);
PTPT_ATermArgs PTPT_makeATermArgsEmpty(void);
PTPT_ATermArgs PTPT_makeATermArgsSingle(PTPT_ATerm head);
PTPT_ATermArgs PTPT_makeATermArgsMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermArgs tail);
PTPT_ATermElems PTPT_makeATermElemsEmpty(void);
PTPT_ATermElems PTPT_makeATermElemsSingle(PTPT_ATerm head);
PTPT_ATermElems PTPT_makeATermElemsMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermElems tail);
PTPT_ATermAnnos PTPT_makeATermAnnosEmpty(void);
PTPT_ATermAnnos PTPT_makeATermAnnosSingle(PTPT_ATerm head);
PTPT_ATermAnnos PTPT_makeATermAnnosMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermAnnos tail);
PTPT_IntCon PTPT_makeIntConNatural(PTPT_NatCon NatCon);
PTPT_IntCon PTPT_makeIntConPositive(PTPT_OptLayout wsAfterPos, PTPT_NatCon NatCon);
PTPT_IntCon PTPT_makeIntConNegative(PTPT_OptLayout wsAfterNeg, PTPT_NatCon NatCon);
PTPT_OptExp PTPT_makeOptExpPresent(PTPT_OptLayout wsAfterE, PTPT_IntCon IntCon);
PTPT_OptExp PTPT_makeOptExpAbsent(void);
PTPT_RealCon PTPT_makeRealConRealCon(PTPT_IntCon base, PTPT_OptLayout wsAfterBase, PTPT_OptLayout wsAfterPeriod, PTPT_NatCon decimal, PTPT_OptLayout wsAfterDecimal, PTPT_OptExp exp);
PTPT_LexStrChar PTPT_makeLexStrCharNewline(void);
PTPT_LexStrChar PTPT_makeLexStrCharTab(void);
PTPT_LexStrChar PTPT_makeLexStrCharQuote(void);
PTPT_LexStrChar PTPT_makeLexStrCharBackslash(void);
PTPT_LexStrChar PTPT_makeLexStrCharDecimal(char a, char b, char c);
PTPT_LexStrChar PTPT_makeLexStrCharNormal(char ch);
PTPT_StrChar PTPT_makeStrCharLexToCf(PTPT_LexStrChar StrChar);
PTPT_LexStrCon PTPT_makeLexStrConDefault(PTPT_LexStrCharChars chars);
PTPT_StrCon PTPT_makeStrConLexToCf(PTPT_LexStrCon StrCon);
PTPT_LexStrCharChars PTPT_makeLexStrCharCharsEmpty(void);
PTPT_LexStrCharChars PTPT_makeLexStrCharCharsSingle(PTPT_LexStrChar head);
PTPT_LexStrCharChars PTPT_makeLexStrCharCharsMany(PTPT_LexStrChar head, PTPT_LexStrCharChars tail);
PTPT_LexNatCon PTPT_makeLexNatConDigits(const char* list);
PTPT_NatCon PTPT_makeNatConLexToCf(PTPT_LexNatCon NatCon);
PTPT_LexIdCon PTPT_makeLexIdConDefault(char head, const char* tail);
PTPT_IdCon PTPT_makeIdConLexToCf(PTPT_LexIdCon IdCon);
PTPT_LexLayout PTPT_makeLexLayoutWhitespace(char ch);

/*}}}  */
/*{{{  equality functions */

ATbool PTPT_isEqualOptLayout(PTPT_OptLayout arg0, PTPT_OptLayout arg1);
ATbool PTPT_isEqualLayout(PTPT_Layout arg0, PTPT_Layout arg1);
ATbool PTPT_isEqualLexLayoutList(PTPT_LexLayoutList arg0, PTPT_LexLayoutList arg1);
ATbool PTPT_isEqualTree(PTPT_Tree arg0, PTPT_Tree arg1);
ATbool PTPT_isEqualAttributes(PTPT_Attributes arg0, PTPT_Attributes arg1);
ATbool PTPT_isEqualAttrs(PTPT_Attrs arg0, PTPT_Attrs arg1);
ATbool PTPT_isEqualAttr(PTPT_Attr arg0, PTPT_Attr arg1);
ATbool PTPT_isEqualAssociativity(PTPT_Associativity arg0, PTPT_Associativity arg1);
ATbool PTPT_isEqualAttrList(PTPT_AttrList arg0, PTPT_AttrList arg1);
ATbool PTPT_isEqualParseTree(PTPT_ParseTree arg0, PTPT_ParseTree arg1);
ATbool PTPT_isEqualSymbol(PTPT_Symbol arg0, PTPT_Symbol arg1);
ATbool PTPT_isEqualSymbols(PTPT_Symbols arg0, PTPT_Symbols arg1);
ATbool PTPT_isEqualCharRanges(PTPT_CharRanges arg0, PTPT_CharRanges arg1);
ATbool PTPT_isEqualCharRange(PTPT_CharRange arg0, PTPT_CharRange arg1);
ATbool PTPT_isEqualStart(PTPT_Start arg0, PTPT_Start arg1);
ATbool PTPT_isEqualSymbolList(PTPT_SymbolList arg0, PTPT_SymbolList arg1);
ATbool PTPT_isEqualCharRangeList(PTPT_CharRangeList arg0, PTPT_CharRangeList arg1);
ATbool PTPT_isEqualArgs(PTPT_Args arg0, PTPT_Args arg1);
ATbool PTPT_isEqualProduction(PTPT_Production arg0, PTPT_Production arg1);
ATbool PTPT_isEqualTreeList(PTPT_TreeList arg0, PTPT_TreeList arg1);
ATbool PTPT_isEqualAFun(PTPT_AFun arg0, PTPT_AFun arg1);
ATbool PTPT_isEqualATerm(PTPT_ATerm arg0, PTPT_ATerm arg1);
ATbool PTPT_isEqualAnnotation(PTPT_Annotation arg0, PTPT_Annotation arg1);
ATbool PTPT_isEqualATermArgs(PTPT_ATermArgs arg0, PTPT_ATermArgs arg1);
ATbool PTPT_isEqualATermElems(PTPT_ATermElems arg0, PTPT_ATermElems arg1);
ATbool PTPT_isEqualATermAnnos(PTPT_ATermAnnos arg0, PTPT_ATermAnnos arg1);
ATbool PTPT_isEqualIntCon(PTPT_IntCon arg0, PTPT_IntCon arg1);
ATbool PTPT_isEqualOptExp(PTPT_OptExp arg0, PTPT_OptExp arg1);
ATbool PTPT_isEqualRealCon(PTPT_RealCon arg0, PTPT_RealCon arg1);
ATbool PTPT_isEqualLexStrChar(PTPT_LexStrChar arg0, PTPT_LexStrChar arg1);
ATbool PTPT_isEqualStrChar(PTPT_StrChar arg0, PTPT_StrChar arg1);
ATbool PTPT_isEqualLexStrCon(PTPT_LexStrCon arg0, PTPT_LexStrCon arg1);
ATbool PTPT_isEqualStrCon(PTPT_StrCon arg0, PTPT_StrCon arg1);
ATbool PTPT_isEqualLexStrCharChars(PTPT_LexStrCharChars arg0, PTPT_LexStrCharChars arg1);
ATbool PTPT_isEqualLexNatCon(PTPT_LexNatCon arg0, PTPT_LexNatCon arg1);
ATbool PTPT_isEqualNatCon(PTPT_NatCon arg0, PTPT_NatCon arg1);
ATbool PTPT_isEqualLexIdCon(PTPT_LexIdCon arg0, PTPT_LexIdCon arg1);
ATbool PTPT_isEqualIdCon(PTPT_IdCon arg0, PTPT_IdCon arg1);
ATbool PTPT_isEqualLexLayout(PTPT_LexLayout arg0, PTPT_LexLayout arg1);

/*}}}  */
/*{{{  PTPT_OptLayout accessors */

ATbool PTPT_isValidOptLayout(PTPT_OptLayout arg);
inline ATbool PTPT_isOptLayoutAbsent(PTPT_OptLayout arg);
inline ATbool PTPT_isOptLayoutPresent(PTPT_OptLayout arg);
ATbool PTPT_hasOptLayoutLayout(PTPT_OptLayout arg);
PTPT_Layout PTPT_getOptLayoutLayout(PTPT_OptLayout arg);
PTPT_OptLayout PTPT_setOptLayoutLayout(PTPT_OptLayout arg, PTPT_Layout layout);

/*}}}  */
/*{{{  PTPT_Layout accessors */

ATbool PTPT_isValidLayout(PTPT_Layout arg);
inline ATbool PTPT_isLayoutLexToCf(PTPT_Layout arg);
ATbool PTPT_hasLayoutList(PTPT_Layout arg);
PTPT_LexLayoutList PTPT_getLayoutList(PTPT_Layout arg);
PTPT_Layout PTPT_setLayoutList(PTPT_Layout arg, PTPT_LexLayoutList list);

/*}}}  */
/*{{{  PTPT_LexLayoutList accessors */

ATbool PTPT_isValidLexLayoutList(PTPT_LexLayoutList arg);
inline ATbool PTPT_isLexLayoutListEmpty(PTPT_LexLayoutList arg);
inline ATbool PTPT_isLexLayoutListSingle(PTPT_LexLayoutList arg);
inline ATbool PTPT_isLexLayoutListMany(PTPT_LexLayoutList arg);
ATbool PTPT_hasLexLayoutListHead(PTPT_LexLayoutList arg);
ATbool PTPT_hasLexLayoutListTail(PTPT_LexLayoutList arg);
PTPT_LexLayout PTPT_getLexLayoutListHead(PTPT_LexLayoutList arg);
PTPT_LexLayoutList PTPT_getLexLayoutListTail(PTPT_LexLayoutList arg);
PTPT_LexLayoutList PTPT_setLexLayoutListHead(PTPT_LexLayoutList arg, PTPT_LexLayout head);
PTPT_LexLayoutList PTPT_setLexLayoutListTail(PTPT_LexLayoutList arg, PTPT_LexLayoutList tail);

/*}}}  */
/*{{{  PTPT_Tree accessors */

ATbool PTPT_isValidTree(PTPT_Tree arg);
inline ATbool PTPT_isTreeAnnotated(PTPT_Tree arg);
inline ATbool PTPT_isTreeAppl(PTPT_Tree arg);
inline ATbool PTPT_isTreeCycle(PTPT_Tree arg);
inline ATbool PTPT_isTreeAmb(PTPT_Tree arg);
inline ATbool PTPT_isTreeChar(PTPT_Tree arg);
ATbool PTPT_hasTreeTree(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterTree(PTPT_Tree arg);
ATbool PTPT_hasTreeAnnotation(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterAppl(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterParenOpen(PTPT_Tree arg);
ATbool PTPT_hasTreeProd(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterProd(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterComma(PTPT_Tree arg);
ATbool PTPT_hasTreeArgs(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterArgs(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterCycle(PTPT_Tree arg);
ATbool PTPT_hasTreeSymbol(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterSymbol(PTPT_Tree arg);
ATbool PTPT_hasTreeCycleLength(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterCycleLength(PTPT_Tree arg);
ATbool PTPT_hasTreeWsAfterAmb(PTPT_Tree arg);
ATbool PTPT_hasTreeCharacter(PTPT_Tree arg);
PTPT_Tree PTPT_getTreeTree(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterTree(PTPT_Tree arg);
PTPT_Annotation PTPT_getTreeAnnotation(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterAppl(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterParenOpen(PTPT_Tree arg);
PTPT_Production PTPT_getTreeProd(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterProd(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterComma(PTPT_Tree arg);
PTPT_Args PTPT_getTreeArgs(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterArgs(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterCycle(PTPT_Tree arg);
PTPT_Symbol PTPT_getTreeSymbol(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterSymbol(PTPT_Tree arg);
PTPT_NatCon PTPT_getTreeCycleLength(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterCycleLength(PTPT_Tree arg);
PTPT_OptLayout PTPT_getTreeWsAfterAmb(PTPT_Tree arg);
PTPT_NatCon PTPT_getTreeCharacter(PTPT_Tree arg);
PTPT_Tree PTPT_setTreeTree(PTPT_Tree arg, PTPT_Tree Tree);
PTPT_Tree PTPT_setTreeWsAfterTree(PTPT_Tree arg, PTPT_OptLayout wsAfterTree);
PTPT_Tree PTPT_setTreeAnnotation(PTPT_Tree arg, PTPT_Annotation Annotation);
PTPT_Tree PTPT_setTreeWsAfterAppl(PTPT_Tree arg, PTPT_OptLayout wsAfterAppl);
PTPT_Tree PTPT_setTreeWsAfterParenOpen(PTPT_Tree arg, PTPT_OptLayout wsAfterParenOpen);
PTPT_Tree PTPT_setTreeProd(PTPT_Tree arg, PTPT_Production prod);
PTPT_Tree PTPT_setTreeWsAfterProd(PTPT_Tree arg, PTPT_OptLayout wsAfterProd);
PTPT_Tree PTPT_setTreeWsAfterComma(PTPT_Tree arg, PTPT_OptLayout wsAfterComma);
PTPT_Tree PTPT_setTreeArgs(PTPT_Tree arg, PTPT_Args args);
PTPT_Tree PTPT_setTreeWsAfterArgs(PTPT_Tree arg, PTPT_OptLayout wsAfterArgs);
PTPT_Tree PTPT_setTreeWsAfterCycle(PTPT_Tree arg, PTPT_OptLayout wsAfterCycle);
PTPT_Tree PTPT_setTreeSymbol(PTPT_Tree arg, PTPT_Symbol symbol);
PTPT_Tree PTPT_setTreeWsAfterSymbol(PTPT_Tree arg, PTPT_OptLayout wsAfterSymbol);
PTPT_Tree PTPT_setTreeCycleLength(PTPT_Tree arg, PTPT_NatCon cycleLength);
PTPT_Tree PTPT_setTreeWsAfterCycleLength(PTPT_Tree arg, PTPT_OptLayout wsAfterCycleLength);
PTPT_Tree PTPT_setTreeWsAfterAmb(PTPT_Tree arg, PTPT_OptLayout wsAfterAmb);
PTPT_Tree PTPT_setTreeCharacter(PTPT_Tree arg, PTPT_NatCon character);

/*}}}  */
/*{{{  PTPT_Attributes accessors */

ATbool PTPT_isValidAttributes(PTPT_Attributes arg);
inline ATbool PTPT_isAttributesNoAttrs(PTPT_Attributes arg);
inline ATbool PTPT_isAttributesAttrs(PTPT_Attributes arg);
ATbool PTPT_hasAttributesWsAfterAttrs(PTPT_Attributes arg);
ATbool PTPT_hasAttributesWsAfterParenOpen(PTPT_Attributes arg);
ATbool PTPT_hasAttributesAttributes(PTPT_Attributes arg);
ATbool PTPT_hasAttributesWsAfterAttributes(PTPT_Attributes arg);
PTPT_OptLayout PTPT_getAttributesWsAfterAttrs(PTPT_Attributes arg);
PTPT_OptLayout PTPT_getAttributesWsAfterParenOpen(PTPT_Attributes arg);
PTPT_Attrs PTPT_getAttributesAttributes(PTPT_Attributes arg);
PTPT_OptLayout PTPT_getAttributesWsAfterAttributes(PTPT_Attributes arg);
PTPT_Attributes PTPT_setAttributesWsAfterAttrs(PTPT_Attributes arg, PTPT_OptLayout wsAfterAttrs);
PTPT_Attributes PTPT_setAttributesWsAfterParenOpen(PTPT_Attributes arg, PTPT_OptLayout wsAfterParenOpen);
PTPT_Attributes PTPT_setAttributesAttributes(PTPT_Attributes arg, PTPT_Attrs attributes);
PTPT_Attributes PTPT_setAttributesWsAfterAttributes(PTPT_Attributes arg, PTPT_OptLayout wsAfterAttributes);

/*}}}  */
/*{{{  PTPT_Attrs accessors */

ATbool PTPT_isValidAttrs(PTPT_Attrs arg);
inline ATbool PTPT_isAttrsMany(PTPT_Attrs arg);
ATbool PTPT_hasAttrsWsAfterBracketOpen(PTPT_Attrs arg);
ATbool PTPT_hasAttrsList(PTPT_Attrs arg);
ATbool PTPT_hasAttrsWsAfterList(PTPT_Attrs arg);
PTPT_OptLayout PTPT_getAttrsWsAfterBracketOpen(PTPT_Attrs arg);
PTPT_AttrList PTPT_getAttrsList(PTPT_Attrs arg);
PTPT_OptLayout PTPT_getAttrsWsAfterList(PTPT_Attrs arg);
PTPT_Attrs PTPT_setAttrsWsAfterBracketOpen(PTPT_Attrs arg, PTPT_OptLayout wsAfterBracketOpen);
PTPT_Attrs PTPT_setAttrsList(PTPT_Attrs arg, PTPT_AttrList list);
PTPT_Attrs PTPT_setAttrsWsAfterList(PTPT_Attrs arg, PTPT_OptLayout wsAfterList);

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
ATbool PTPT_hasAttrWsAfterParenOpen(PTPT_Attr arg);
ATbool PTPT_hasAttrAssociativity(PTPT_Attr arg);
ATbool PTPT_hasAttrWsAfterAssociativity(PTPT_Attr arg);
ATbool PTPT_hasAttrWsAfterTerm(PTPT_Attr arg);
ATbool PTPT_hasAttrAterm(PTPT_Attr arg);
ATbool PTPT_hasAttrWsAfterAterm(PTPT_Attr arg);
ATbool PTPT_hasAttrWsAfterId(PTPT_Attr arg);
ATbool PTPT_hasAttrModuleName(PTPT_Attr arg);
ATbool PTPT_hasAttrWsAfterModuleName(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterAssoc(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterParenOpen(PTPT_Attr arg);
PTPT_Associativity PTPT_getAttrAssociativity(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterAssociativity(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterTerm(PTPT_Attr arg);
PTPT_ATerm PTPT_getAttrAterm(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterAterm(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterId(PTPT_Attr arg);
PTPT_StrCon PTPT_getAttrModuleName(PTPT_Attr arg);
PTPT_OptLayout PTPT_getAttrWsAfterModuleName(PTPT_Attr arg);
PTPT_Attr PTPT_setAttrWsAfterAssoc(PTPT_Attr arg, PTPT_OptLayout wsAfterAssoc);
PTPT_Attr PTPT_setAttrWsAfterParenOpen(PTPT_Attr arg, PTPT_OptLayout wsAfterParenOpen);
PTPT_Attr PTPT_setAttrAssociativity(PTPT_Attr arg, PTPT_Associativity associativity);
PTPT_Attr PTPT_setAttrWsAfterAssociativity(PTPT_Attr arg, PTPT_OptLayout wsAfterAssociativity);
PTPT_Attr PTPT_setAttrWsAfterTerm(PTPT_Attr arg, PTPT_OptLayout wsAfterTerm);
PTPT_Attr PTPT_setAttrAterm(PTPT_Attr arg, PTPT_ATerm aterm);
PTPT_Attr PTPT_setAttrWsAfterAterm(PTPT_Attr arg, PTPT_OptLayout wsAfterAterm);
PTPT_Attr PTPT_setAttrWsAfterId(PTPT_Attr arg, PTPT_OptLayout wsAfterId);
PTPT_Attr PTPT_setAttrModuleName(PTPT_Attr arg, PTPT_StrCon moduleName);
PTPT_Attr PTPT_setAttrWsAfterModuleName(PTPT_Attr arg, PTPT_OptLayout wsAfterModuleName);

/*}}}  */
/*{{{  PTPT_Associativity accessors */

ATbool PTPT_isValidAssociativity(PTPT_Associativity arg);
inline ATbool PTPT_isAssociativityLeft(PTPT_Associativity arg);
inline ATbool PTPT_isAssociativityRight(PTPT_Associativity arg);
inline ATbool PTPT_isAssociativityAssoc(PTPT_Associativity arg);
inline ATbool PTPT_isAssociativityNonAssoc(PTPT_Associativity arg);

/*}}}  */
/*{{{  PTPT_AttrList accessors */

ATbool PTPT_isValidAttrList(PTPT_AttrList arg);
inline ATbool PTPT_isAttrListEmpty(PTPT_AttrList arg);
inline ATbool PTPT_isAttrListSingle(PTPT_AttrList arg);
inline ATbool PTPT_isAttrListMany(PTPT_AttrList arg);
ATbool PTPT_hasAttrListHead(PTPT_AttrList arg);
ATbool PTPT_hasAttrListWsAfterHead(PTPT_AttrList arg);
ATbool PTPT_hasAttrListWsAfterSep(PTPT_AttrList arg);
ATbool PTPT_hasAttrListTail(PTPT_AttrList arg);
PTPT_AttrList PTPT_getAttrListTail(PTPT_AttrList arg);
PTPT_Attr PTPT_getAttrListHead(PTPT_AttrList arg);
PTPT_OptLayout PTPT_getAttrListWsAfterHead(PTPT_AttrList arg);
PTPT_OptLayout PTPT_getAttrListWsAfterSep(PTPT_AttrList arg);
PTPT_AttrList PTPT_setAttrListHead(PTPT_AttrList arg, PTPT_Attr head);
PTPT_AttrList PTPT_setAttrListWsAfterHead(PTPT_AttrList arg, PTPT_OptLayout wsAfterHead);
PTPT_AttrList PTPT_setAttrListWsAfterSep(PTPT_AttrList arg, PTPT_OptLayout wsAfterSep);
PTPT_AttrList PTPT_setAttrListTail(PTPT_AttrList arg, PTPT_AttrList tail);

/*}}}  */
/*{{{  PTPT_ParseTree accessors */

ATbool PTPT_isValidParseTree(PTPT_ParseTree arg);
inline ATbool PTPT_isParseTreeTop(PTPT_ParseTree arg);
ATbool PTPT_hasParseTreeWsAfterParsetree(PTPT_ParseTree arg);
ATbool PTPT_hasParseTreeWsAfterParenOpen(PTPT_ParseTree arg);
ATbool PTPT_hasParseTreeTop(PTPT_ParseTree arg);
ATbool PTPT_hasParseTreeWsAfterTop(PTPT_ParseTree arg);
ATbool PTPT_hasParseTreeWsAfterComma(PTPT_ParseTree arg);
ATbool PTPT_hasParseTreeAmbCnt(PTPT_ParseTree arg);
ATbool PTPT_hasParseTreeWsAfterAmbCnt(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterParsetree(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterParenOpen(PTPT_ParseTree arg);
PTPT_Tree PTPT_getParseTreeTop(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterTop(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterComma(PTPT_ParseTree arg);
PTPT_NatCon PTPT_getParseTreeAmbCnt(PTPT_ParseTree arg);
PTPT_OptLayout PTPT_getParseTreeWsAfterAmbCnt(PTPT_ParseTree arg);
PTPT_ParseTree PTPT_setParseTreeWsAfterParsetree(PTPT_ParseTree arg, PTPT_OptLayout wsAfterParsetree);
PTPT_ParseTree PTPT_setParseTreeWsAfterParenOpen(PTPT_ParseTree arg, PTPT_OptLayout wsAfterParenOpen);
PTPT_ParseTree PTPT_setParseTreeTop(PTPT_ParseTree arg, PTPT_Tree top);
PTPT_ParseTree PTPT_setParseTreeWsAfterTop(PTPT_ParseTree arg, PTPT_OptLayout wsAfterTop);
PTPT_ParseTree PTPT_setParseTreeWsAfterComma(PTPT_ParseTree arg, PTPT_OptLayout wsAfterComma);
PTPT_ParseTree PTPT_setParseTreeAmbCnt(PTPT_ParseTree arg, PTPT_NatCon ambCnt);
PTPT_ParseTree PTPT_setParseTreeWsAfterAmbCnt(PTPT_ParseTree arg, PTPT_OptLayout wsAfterAmbCnt);

/*}}}  */
/*{{{  PTPT_Symbol accessors */

ATbool PTPT_isValidSymbol(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolEmpty(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolLit(PTPT_Symbol arg);
inline ATbool PTPT_isSymbolCilit(PTPT_Symbol arg);
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
inline ATbool PTPT_isSymbolParameterizedSort(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterLit(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterParenOpen(PTPT_Symbol arg);
ATbool PTPT_hasSymbolString(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterString(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterCilit(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterCf(PTPT_Symbol arg);
ATbool PTPT_hasSymbolSymbol(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterSymbol(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterLex(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterOpt(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterAlt(PTPT_Symbol arg);
ATbool PTPT_hasSymbolLhs(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterLhs(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterComma(PTPT_Symbol arg);
ATbool PTPT_hasSymbolRhs(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterRhs(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterSeq(PTPT_Symbol arg);
ATbool PTPT_hasSymbolSymbols(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterSymbols(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterTuple(PTPT_Symbol arg);
ATbool PTPT_hasSymbolHead(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterHead(PTPT_Symbol arg);
ATbool PTPT_hasSymbolRest(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterRest(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterSort(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterIter(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterIterStar(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterIterSep(PTPT_Symbol arg);
ATbool PTPT_hasSymbolSeparator(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterSeparator(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterIterStarSep(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterIterN(PTPT_Symbol arg);
ATbool PTPT_hasSymbolNumber(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterNumber(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterIterSepN(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterComma1(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterComma2(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterFunc(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterVarsym(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterCharClass(PTPT_Symbol arg);
ATbool PTPT_hasSymbolCharRanges(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterCharRanges(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterStrategy(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterParameterizedSort(PTPT_Symbol arg);
ATbool PTPT_hasSymbolSort(PTPT_Symbol arg);
ATbool PTPT_hasSymbolParameters(PTPT_Symbol arg);
ATbool PTPT_hasSymbolWsAfterParameters(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterLit(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterParenOpen(PTPT_Symbol arg);
PTPT_StrCon PTPT_getSymbolString(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterString(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterCilit(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterCf(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolSymbol(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSymbol(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterLex(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterOpt(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterAlt(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolLhs(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterLhs(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterComma(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolRhs(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterRhs(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSeq(PTPT_Symbol arg);
PTPT_Symbols PTPT_getSymbolSymbols(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSymbols(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterTuple(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolHead(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterHead(PTPT_Symbol arg);
PTPT_Symbols PTPT_getSymbolRest(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterRest(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSort(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIter(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterStar(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterSep(PTPT_Symbol arg);
PTPT_Symbol PTPT_getSymbolSeparator(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterSeparator(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterStarSep(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterN(PTPT_Symbol arg);
PTPT_NatCon PTPT_getSymbolNumber(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterNumber(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterIterSepN(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterComma1(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterComma2(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterFunc(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterVarsym(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterCharClass(PTPT_Symbol arg);
PTPT_CharRanges PTPT_getSymbolCharRanges(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterCharRanges(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterStrategy(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterParameterizedSort(PTPT_Symbol arg);
PTPT_StrCon PTPT_getSymbolSort(PTPT_Symbol arg);
PTPT_Symbols PTPT_getSymbolParameters(PTPT_Symbol arg);
PTPT_OptLayout PTPT_getSymbolWsAfterParameters(PTPT_Symbol arg);
PTPT_Symbol PTPT_setSymbolWsAfterLit(PTPT_Symbol arg, PTPT_OptLayout wsAfterLit);
PTPT_Symbol PTPT_setSymbolWsAfterParenOpen(PTPT_Symbol arg, PTPT_OptLayout wsAfterParenOpen);
PTPT_Symbol PTPT_setSymbolString(PTPT_Symbol arg, PTPT_StrCon string);
PTPT_Symbol PTPT_setSymbolWsAfterString(PTPT_Symbol arg, PTPT_OptLayout wsAfterString);
PTPT_Symbol PTPT_setSymbolWsAfterCilit(PTPT_Symbol arg, PTPT_OptLayout wsAfterCilit);
PTPT_Symbol PTPT_setSymbolWsAfterCf(PTPT_Symbol arg, PTPT_OptLayout wsAfterCf);
PTPT_Symbol PTPT_setSymbolSymbol(PTPT_Symbol arg, PTPT_Symbol symbol);
PTPT_Symbol PTPT_setSymbolWsAfterSymbol(PTPT_Symbol arg, PTPT_OptLayout wsAfterSymbol);
PTPT_Symbol PTPT_setSymbolWsAfterLex(PTPT_Symbol arg, PTPT_OptLayout wsAfterLex);
PTPT_Symbol PTPT_setSymbolWsAfterOpt(PTPT_Symbol arg, PTPT_OptLayout wsAfterOpt);
PTPT_Symbol PTPT_setSymbolWsAfterAlt(PTPT_Symbol arg, PTPT_OptLayout wsAfterAlt);
PTPT_Symbol PTPT_setSymbolLhs(PTPT_Symbol arg, PTPT_Symbol lhs);
PTPT_Symbol PTPT_setSymbolWsAfterLhs(PTPT_Symbol arg, PTPT_OptLayout wsAfterLhs);
PTPT_Symbol PTPT_setSymbolWsAfterComma(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma);
PTPT_Symbol PTPT_setSymbolRhs(PTPT_Symbol arg, PTPT_Symbol rhs);
PTPT_Symbol PTPT_setSymbolWsAfterRhs(PTPT_Symbol arg, PTPT_OptLayout wsAfterRhs);
PTPT_Symbol PTPT_setSymbolWsAfterSeq(PTPT_Symbol arg, PTPT_OptLayout wsAfterSeq);
PTPT_Symbol PTPT_setSymbolSymbols(PTPT_Symbol arg, PTPT_Symbols symbols);
PTPT_Symbol PTPT_setSymbolWsAfterSymbols(PTPT_Symbol arg, PTPT_OptLayout wsAfterSymbols);
PTPT_Symbol PTPT_setSymbolWsAfterTuple(PTPT_Symbol arg, PTPT_OptLayout wsAfterTuple);
PTPT_Symbol PTPT_setSymbolHead(PTPT_Symbol arg, PTPT_Symbol head);
PTPT_Symbol PTPT_setSymbolWsAfterHead(PTPT_Symbol arg, PTPT_OptLayout wsAfterHead);
PTPT_Symbol PTPT_setSymbolRest(PTPT_Symbol arg, PTPT_Symbols rest);
PTPT_Symbol PTPT_setSymbolWsAfterRest(PTPT_Symbol arg, PTPT_OptLayout wsAfterRest);
PTPT_Symbol PTPT_setSymbolWsAfterSort(PTPT_Symbol arg, PTPT_OptLayout wsAfterSort);
PTPT_Symbol PTPT_setSymbolWsAfterIter(PTPT_Symbol arg, PTPT_OptLayout wsAfterIter);
PTPT_Symbol PTPT_setSymbolWsAfterIterStar(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterStar);
PTPT_Symbol PTPT_setSymbolWsAfterIterSep(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterSep);
PTPT_Symbol PTPT_setSymbolSeparator(PTPT_Symbol arg, PTPT_Symbol separator);
PTPT_Symbol PTPT_setSymbolWsAfterSeparator(PTPT_Symbol arg, PTPT_OptLayout wsAfterSeparator);
PTPT_Symbol PTPT_setSymbolWsAfterIterStarSep(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterStarSep);
PTPT_Symbol PTPT_setSymbolWsAfterIterN(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterN);
PTPT_Symbol PTPT_setSymbolNumber(PTPT_Symbol arg, PTPT_NatCon number);
PTPT_Symbol PTPT_setSymbolWsAfterNumber(PTPT_Symbol arg, PTPT_OptLayout wsAfterNumber);
PTPT_Symbol PTPT_setSymbolWsAfterIterSepN(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterSepN);
PTPT_Symbol PTPT_setSymbolWsAfterComma1(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma1);
PTPT_Symbol PTPT_setSymbolWsAfterComma2(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma2);
PTPT_Symbol PTPT_setSymbolWsAfterFunc(PTPT_Symbol arg, PTPT_OptLayout wsAfterFunc);
PTPT_Symbol PTPT_setSymbolWsAfterVarsym(PTPT_Symbol arg, PTPT_OptLayout wsAfterVarsym);
PTPT_Symbol PTPT_setSymbolWsAfterCharClass(PTPT_Symbol arg, PTPT_OptLayout wsAfterCharClass);
PTPT_Symbol PTPT_setSymbolCharRanges(PTPT_Symbol arg, PTPT_CharRanges CharRanges);
PTPT_Symbol PTPT_setSymbolWsAfterCharRanges(PTPT_Symbol arg, PTPT_OptLayout wsAfterCharRanges);
PTPT_Symbol PTPT_setSymbolWsAfterStrategy(PTPT_Symbol arg, PTPT_OptLayout wsAfterStrategy);
PTPT_Symbol PTPT_setSymbolWsAfterParameterizedSort(PTPT_Symbol arg, PTPT_OptLayout wsAfterParameterizedSort);
PTPT_Symbol PTPT_setSymbolSort(PTPT_Symbol arg, PTPT_StrCon sort);
PTPT_Symbol PTPT_setSymbolParameters(PTPT_Symbol arg, PTPT_Symbols parameters);
PTPT_Symbol PTPT_setSymbolWsAfterParameters(PTPT_Symbol arg, PTPT_OptLayout wsAfterParameters);

/*}}}  */
/*{{{  PTPT_Symbols accessors */

ATbool PTPT_isValidSymbols(PTPT_Symbols arg);
inline ATbool PTPT_isSymbolsList(PTPT_Symbols arg);
ATbool PTPT_hasSymbolsWsAfterBracketOpen(PTPT_Symbols arg);
ATbool PTPT_hasSymbolsList(PTPT_Symbols arg);
ATbool PTPT_hasSymbolsWsAfterList(PTPT_Symbols arg);
PTPT_OptLayout PTPT_getSymbolsWsAfterBracketOpen(PTPT_Symbols arg);
PTPT_SymbolList PTPT_getSymbolsList(PTPT_Symbols arg);
PTPT_OptLayout PTPT_getSymbolsWsAfterList(PTPT_Symbols arg);
PTPT_Symbols PTPT_setSymbolsWsAfterBracketOpen(PTPT_Symbols arg, PTPT_OptLayout wsAfterBracketOpen);
PTPT_Symbols PTPT_setSymbolsList(PTPT_Symbols arg, PTPT_SymbolList list);
PTPT_Symbols PTPT_setSymbolsWsAfterList(PTPT_Symbols arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_CharRanges accessors */

ATbool PTPT_isValidCharRanges(PTPT_CharRanges arg);
inline ATbool PTPT_isCharRangesList(PTPT_CharRanges arg);
ATbool PTPT_hasCharRangesWsAfterBracketOpen(PTPT_CharRanges arg);
ATbool PTPT_hasCharRangesList(PTPT_CharRanges arg);
ATbool PTPT_hasCharRangesWsAfterList(PTPT_CharRanges arg);
PTPT_OptLayout PTPT_getCharRangesWsAfterBracketOpen(PTPT_CharRanges arg);
PTPT_CharRangeList PTPT_getCharRangesList(PTPT_CharRanges arg);
PTPT_OptLayout PTPT_getCharRangesWsAfterList(PTPT_CharRanges arg);
PTPT_CharRanges PTPT_setCharRangesWsAfterBracketOpen(PTPT_CharRanges arg, PTPT_OptLayout wsAfterBracketOpen);
PTPT_CharRanges PTPT_setCharRangesList(PTPT_CharRanges arg, PTPT_CharRangeList list);
PTPT_CharRanges PTPT_setCharRangesWsAfterList(PTPT_CharRanges arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_CharRange accessors */

ATbool PTPT_isValidCharRange(PTPT_CharRange arg);
inline ATbool PTPT_isCharRangeCharacter(PTPT_CharRange arg);
inline ATbool PTPT_isCharRangeRange(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeInteger(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeWsAfterRange(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeWsAfterParenOpen(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeStart(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeWsAfterStart(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeWsAfterComma(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeEnd(PTPT_CharRange arg);
ATbool PTPT_hasCharRangeWsAfterEnd(PTPT_CharRange arg);
PTPT_NatCon PTPT_getCharRangeInteger(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterRange(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterParenOpen(PTPT_CharRange arg);
PTPT_NatCon PTPT_getCharRangeStart(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterStart(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterComma(PTPT_CharRange arg);
PTPT_NatCon PTPT_getCharRangeEnd(PTPT_CharRange arg);
PTPT_OptLayout PTPT_getCharRangeWsAfterEnd(PTPT_CharRange arg);
PTPT_CharRange PTPT_setCharRangeInteger(PTPT_CharRange arg, PTPT_NatCon integer);
PTPT_CharRange PTPT_setCharRangeWsAfterRange(PTPT_CharRange arg, PTPT_OptLayout wsAfterRange);
PTPT_CharRange PTPT_setCharRangeWsAfterParenOpen(PTPT_CharRange arg, PTPT_OptLayout wsAfterParenOpen);
PTPT_CharRange PTPT_setCharRangeStart(PTPT_CharRange arg, PTPT_NatCon start);
PTPT_CharRange PTPT_setCharRangeWsAfterStart(PTPT_CharRange arg, PTPT_OptLayout wsAfterStart);
PTPT_CharRange PTPT_setCharRangeWsAfterComma(PTPT_CharRange arg, PTPT_OptLayout wsAfterComma);
PTPT_CharRange PTPT_setCharRangeEnd(PTPT_CharRange arg, PTPT_NatCon end);
PTPT_CharRange PTPT_setCharRangeWsAfterEnd(PTPT_CharRange arg, PTPT_OptLayout wsAfterEnd);

/*}}}  */
/*{{{  PTPT_Start accessors */

ATbool PTPT_isValidStart(PTPT_Start arg);
inline ATbool PTPT_isStartSymbol(PTPT_Start arg);
inline ATbool PTPT_isStartTree(PTPT_Start arg);
inline ATbool PTPT_isStartATerm(PTPT_Start arg);
inline ATbool PTPT_isStartIntCon(PTPT_Start arg);
inline ATbool PTPT_isStartRealCon(PTPT_Start arg);
ATbool PTPT_hasStartWsBefore(PTPT_Start arg);
ATbool PTPT_hasStartTopSymbol(PTPT_Start arg);
ATbool PTPT_hasStartWsAfter(PTPT_Start arg);
ATbool PTPT_hasStartAmbCnt(PTPT_Start arg);
ATbool PTPT_hasStartTopTree(PTPT_Start arg);
ATbool PTPT_hasStartTopATerm(PTPT_Start arg);
ATbool PTPT_hasStartTopIntCon(PTPT_Start arg);
ATbool PTPT_hasStartTopRealCon(PTPT_Start arg);
PTPT_OptLayout PTPT_getStartWsBefore(PTPT_Start arg);
PTPT_Symbol PTPT_getStartTopSymbol(PTPT_Start arg);
PTPT_OptLayout PTPT_getStartWsAfter(PTPT_Start arg);
int PTPT_getStartAmbCnt(PTPT_Start arg);
PTPT_Tree PTPT_getStartTopTree(PTPT_Start arg);
PTPT_ATerm PTPT_getStartTopATerm(PTPT_Start arg);
PTPT_IntCon PTPT_getStartTopIntCon(PTPT_Start arg);
PTPT_RealCon PTPT_getStartTopRealCon(PTPT_Start arg);
PTPT_Start PTPT_setStartWsBefore(PTPT_Start arg, PTPT_OptLayout wsBefore);
PTPT_Start PTPT_setStartTopSymbol(PTPT_Start arg, PTPT_Symbol topSymbol);
PTPT_Start PTPT_setStartWsAfter(PTPT_Start arg, PTPT_OptLayout wsAfter);
PTPT_Start PTPT_setStartAmbCnt(PTPT_Start arg, int ambCnt);
PTPT_Start PTPT_setStartTopTree(PTPT_Start arg, PTPT_Tree topTree);
PTPT_Start PTPT_setStartTopATerm(PTPT_Start arg, PTPT_ATerm topATerm);
PTPT_Start PTPT_setStartTopIntCon(PTPT_Start arg, PTPT_IntCon topIntCon);
PTPT_Start PTPT_setStartTopRealCon(PTPT_Start arg, PTPT_RealCon topRealCon);

/*}}}  */
/*{{{  PTPT_SymbolList accessors */

ATbool PTPT_isValidSymbolList(PTPT_SymbolList arg);
inline ATbool PTPT_isSymbolListEmpty(PTPT_SymbolList arg);
inline ATbool PTPT_isSymbolListSingle(PTPT_SymbolList arg);
inline ATbool PTPT_isSymbolListMany(PTPT_SymbolList arg);
ATbool PTPT_hasSymbolListHead(PTPT_SymbolList arg);
ATbool PTPT_hasSymbolListWsAfterHead(PTPT_SymbolList arg);
ATbool PTPT_hasSymbolListWsAfterSep(PTPT_SymbolList arg);
ATbool PTPT_hasSymbolListTail(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_getSymbolListTail(PTPT_SymbolList arg);
PTPT_Symbol PTPT_getSymbolListHead(PTPT_SymbolList arg);
PTPT_OptLayout PTPT_getSymbolListWsAfterHead(PTPT_SymbolList arg);
PTPT_OptLayout PTPT_getSymbolListWsAfterSep(PTPT_SymbolList arg);
PTPT_SymbolList PTPT_setSymbolListHead(PTPT_SymbolList arg, PTPT_Symbol head);
PTPT_SymbolList PTPT_setSymbolListWsAfterHead(PTPT_SymbolList arg, PTPT_OptLayout wsAfterHead);
PTPT_SymbolList PTPT_setSymbolListWsAfterSep(PTPT_SymbolList arg, PTPT_OptLayout wsAfterSep);
PTPT_SymbolList PTPT_setSymbolListTail(PTPT_SymbolList arg, PTPT_SymbolList tail);

/*}}}  */
/*{{{  PTPT_CharRangeList accessors */

ATbool PTPT_isValidCharRangeList(PTPT_CharRangeList arg);
inline ATbool PTPT_isCharRangeListEmpty(PTPT_CharRangeList arg);
inline ATbool PTPT_isCharRangeListSingle(PTPT_CharRangeList arg);
inline ATbool PTPT_isCharRangeListMany(PTPT_CharRangeList arg);
ATbool PTPT_hasCharRangeListHead(PTPT_CharRangeList arg);
ATbool PTPT_hasCharRangeListWsAfterHead(PTPT_CharRangeList arg);
ATbool PTPT_hasCharRangeListWsAfterSep(PTPT_CharRangeList arg);
ATbool PTPT_hasCharRangeListTail(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_getCharRangeListTail(PTPT_CharRangeList arg);
PTPT_CharRange PTPT_getCharRangeListHead(PTPT_CharRangeList arg);
PTPT_OptLayout PTPT_getCharRangeListWsAfterHead(PTPT_CharRangeList arg);
PTPT_OptLayout PTPT_getCharRangeListWsAfterSep(PTPT_CharRangeList arg);
PTPT_CharRangeList PTPT_setCharRangeListHead(PTPT_CharRangeList arg, PTPT_CharRange head);
PTPT_CharRangeList PTPT_setCharRangeListWsAfterHead(PTPT_CharRangeList arg, PTPT_OptLayout wsAfterHead);
PTPT_CharRangeList PTPT_setCharRangeListWsAfterSep(PTPT_CharRangeList arg, PTPT_OptLayout wsAfterSep);
PTPT_CharRangeList PTPT_setCharRangeListTail(PTPT_CharRangeList arg, PTPT_CharRangeList tail);

/*}}}  */
/*{{{  PTPT_Args accessors */

ATbool PTPT_isValidArgs(PTPT_Args arg);
inline ATbool PTPT_isArgsList(PTPT_Args arg);
ATbool PTPT_hasArgsWsAfterBracketOpen(PTPT_Args arg);
ATbool PTPT_hasArgsList(PTPT_Args arg);
ATbool PTPT_hasArgsWsAfterList(PTPT_Args arg);
PTPT_OptLayout PTPT_getArgsWsAfterBracketOpen(PTPT_Args arg);
PTPT_TreeList PTPT_getArgsList(PTPT_Args arg);
PTPT_OptLayout PTPT_getArgsWsAfterList(PTPT_Args arg);
PTPT_Args PTPT_setArgsWsAfterBracketOpen(PTPT_Args arg, PTPT_OptLayout wsAfterBracketOpen);
PTPT_Args PTPT_setArgsList(PTPT_Args arg, PTPT_TreeList list);
PTPT_Args PTPT_setArgsWsAfterList(PTPT_Args arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_Production accessors */

ATbool PTPT_isValidProduction(PTPT_Production arg);
inline ATbool PTPT_isProductionDefault(PTPT_Production arg);
inline ATbool PTPT_isProductionList(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterProd(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterParenOpen(PTPT_Production arg);
ATbool PTPT_hasProductionLhs(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterLhs(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterComma1(PTPT_Production arg);
ATbool PTPT_hasProductionRhs(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterRhs(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterComma2(PTPT_Production arg);
ATbool PTPT_hasProductionAttributes(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterAttributes(PTPT_Production arg);
ATbool PTPT_hasProductionWsAfterList(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterProd(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterParenOpen(PTPT_Production arg);
PTPT_Symbols PTPT_getProductionLhs(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterLhs(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterComma1(PTPT_Production arg);
PTPT_Symbol PTPT_getProductionRhs(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterRhs(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterComma2(PTPT_Production arg);
PTPT_Attributes PTPT_getProductionAttributes(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterAttributes(PTPT_Production arg);
PTPT_OptLayout PTPT_getProductionWsAfterList(PTPT_Production arg);
PTPT_Production PTPT_setProductionWsAfterProd(PTPT_Production arg, PTPT_OptLayout wsAfterProd);
PTPT_Production PTPT_setProductionWsAfterParenOpen(PTPT_Production arg, PTPT_OptLayout wsAfterParenOpen);
PTPT_Production PTPT_setProductionLhs(PTPT_Production arg, PTPT_Symbols lhs);
PTPT_Production PTPT_setProductionWsAfterLhs(PTPT_Production arg, PTPT_OptLayout wsAfterLhs);
PTPT_Production PTPT_setProductionWsAfterComma1(PTPT_Production arg, PTPT_OptLayout wsAfterComma1);
PTPT_Production PTPT_setProductionRhs(PTPT_Production arg, PTPT_Symbol rhs);
PTPT_Production PTPT_setProductionWsAfterRhs(PTPT_Production arg, PTPT_OptLayout wsAfterRhs);
PTPT_Production PTPT_setProductionWsAfterComma2(PTPT_Production arg, PTPT_OptLayout wsAfterComma2);
PTPT_Production PTPT_setProductionAttributes(PTPT_Production arg, PTPT_Attributes attributes);
PTPT_Production PTPT_setProductionWsAfterAttributes(PTPT_Production arg, PTPT_OptLayout wsAfterAttributes);
PTPT_Production PTPT_setProductionWsAfterList(PTPT_Production arg, PTPT_OptLayout wsAfterList);

/*}}}  */
/*{{{  PTPT_TreeList accessors */

ATbool PTPT_isValidTreeList(PTPT_TreeList arg);
inline ATbool PTPT_isTreeListEmpty(PTPT_TreeList arg);
inline ATbool PTPT_isTreeListSingle(PTPT_TreeList arg);
inline ATbool PTPT_isTreeListMany(PTPT_TreeList arg);
ATbool PTPT_hasTreeListHead(PTPT_TreeList arg);
ATbool PTPT_hasTreeListWsAfterHead(PTPT_TreeList arg);
ATbool PTPT_hasTreeListWsAfterSep(PTPT_TreeList arg);
ATbool PTPT_hasTreeListTail(PTPT_TreeList arg);
PTPT_TreeList PTPT_getTreeListTail(PTPT_TreeList arg);
PTPT_Tree PTPT_getTreeListHead(PTPT_TreeList arg);
PTPT_OptLayout PTPT_getTreeListWsAfterHead(PTPT_TreeList arg);
PTPT_OptLayout PTPT_getTreeListWsAfterSep(PTPT_TreeList arg);
PTPT_TreeList PTPT_setTreeListHead(PTPT_TreeList arg, PTPT_Tree head);
PTPT_TreeList PTPT_setTreeListWsAfterHead(PTPT_TreeList arg, PTPT_OptLayout wsAfterHead);
PTPT_TreeList PTPT_setTreeListWsAfterSep(PTPT_TreeList arg, PTPT_OptLayout wsAfterSep);
PTPT_TreeList PTPT_setTreeListTail(PTPT_TreeList arg, PTPT_TreeList tail);

/*}}}  */
/*{{{  PTPT_AFun accessors */

ATbool PTPT_isValidAFun(PTPT_AFun arg);
inline ATbool PTPT_isAFunQuoted(PTPT_AFun arg);
inline ATbool PTPT_isAFunUnquoted(PTPT_AFun arg);
ATbool PTPT_hasAFunStrCon(PTPT_AFun arg);
ATbool PTPT_hasAFunIdCon(PTPT_AFun arg);
PTPT_StrCon PTPT_getAFunStrCon(PTPT_AFun arg);
PTPT_IdCon PTPT_getAFunIdCon(PTPT_AFun arg);
PTPT_AFun PTPT_setAFunStrCon(PTPT_AFun arg, PTPT_StrCon StrCon);
PTPT_AFun PTPT_setAFunIdCon(PTPT_AFun arg, PTPT_IdCon IdCon);

/*}}}  */
/*{{{  PTPT_ATerm accessors */

ATbool PTPT_isValidATerm(PTPT_ATerm arg);
inline ATbool PTPT_isATermInt(PTPT_ATerm arg);
inline ATbool PTPT_isATermReal(PTPT_ATerm arg);
inline ATbool PTPT_isATermFun(PTPT_ATerm arg);
inline ATbool PTPT_isATermAppl(PTPT_ATerm arg);
inline ATbool PTPT_isATermPlaceholder(PTPT_ATerm arg);
inline ATbool PTPT_isATermList(PTPT_ATerm arg);
inline ATbool PTPT_isATermAnnotated(PTPT_ATerm arg);
ATbool PTPT_hasATermIntCon(PTPT_ATerm arg);
ATbool PTPT_hasATermRealCon(PTPT_ATerm arg);
ATbool PTPT_hasATermFun(PTPT_ATerm arg);
ATbool PTPT_hasATermWsAfterFun(PTPT_ATerm arg);
ATbool PTPT_hasATermWsAfterParenOpen(PTPT_ATerm arg);
ATbool PTPT_hasATermArgs(PTPT_ATerm arg);
ATbool PTPT_hasATermWsAfterArgs(PTPT_ATerm arg);
ATbool PTPT_hasATermWsAfterLessThan(PTPT_ATerm arg);
ATbool PTPT_hasATermType(PTPT_ATerm arg);
ATbool PTPT_hasATermWsAfterType(PTPT_ATerm arg);
ATbool PTPT_hasATermWsAfterBracketOpen(PTPT_ATerm arg);
ATbool PTPT_hasATermElems(PTPT_ATerm arg);
ATbool PTPT_hasATermWsAfterElems(PTPT_ATerm arg);
ATbool PTPT_hasATermTrm(PTPT_ATerm arg);
ATbool PTPT_hasATermWsAfterTrm(PTPT_ATerm arg);
ATbool PTPT_hasATermAnnotation(PTPT_ATerm arg);
PTPT_IntCon PTPT_getATermIntCon(PTPT_ATerm arg);
PTPT_RealCon PTPT_getATermRealCon(PTPT_ATerm arg);
PTPT_AFun PTPT_getATermFun(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterFun(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterParenOpen(PTPT_ATerm arg);
PTPT_ATermArgs PTPT_getATermArgs(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterArgs(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterLessThan(PTPT_ATerm arg);
PTPT_ATerm PTPT_getATermType(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterType(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterBracketOpen(PTPT_ATerm arg);
PTPT_ATermElems PTPT_getATermElems(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterElems(PTPT_ATerm arg);
PTPT_ATerm PTPT_getATermTrm(PTPT_ATerm arg);
PTPT_OptLayout PTPT_getATermWsAfterTrm(PTPT_ATerm arg);
PTPT_Annotation PTPT_getATermAnnotation(PTPT_ATerm arg);
PTPT_ATerm PTPT_setATermIntCon(PTPT_ATerm arg, PTPT_IntCon IntCon);
PTPT_ATerm PTPT_setATermRealCon(PTPT_ATerm arg, PTPT_RealCon RealCon);
PTPT_ATerm PTPT_setATermFun(PTPT_ATerm arg, PTPT_AFun fun);
PTPT_ATerm PTPT_setATermWsAfterFun(PTPT_ATerm arg, PTPT_OptLayout wsAfterFun);
PTPT_ATerm PTPT_setATermWsAfterParenOpen(PTPT_ATerm arg, PTPT_OptLayout wsAfterParenOpen);
PTPT_ATerm PTPT_setATermArgs(PTPT_ATerm arg, PTPT_ATermArgs args);
PTPT_ATerm PTPT_setATermWsAfterArgs(PTPT_ATerm arg, PTPT_OptLayout wsAfterArgs);
PTPT_ATerm PTPT_setATermWsAfterLessThan(PTPT_ATerm arg, PTPT_OptLayout wsAfterLessThan);
PTPT_ATerm PTPT_setATermType(PTPT_ATerm arg, PTPT_ATerm type);
PTPT_ATerm PTPT_setATermWsAfterType(PTPT_ATerm arg, PTPT_OptLayout wsAfterType);
PTPT_ATerm PTPT_setATermWsAfterBracketOpen(PTPT_ATerm arg, PTPT_OptLayout wsAfterBracketOpen);
PTPT_ATerm PTPT_setATermElems(PTPT_ATerm arg, PTPT_ATermElems elems);
PTPT_ATerm PTPT_setATermWsAfterElems(PTPT_ATerm arg, PTPT_OptLayout wsAfterElems);
PTPT_ATerm PTPT_setATermTrm(PTPT_ATerm arg, PTPT_ATerm trm);
PTPT_ATerm PTPT_setATermWsAfterTrm(PTPT_ATerm arg, PTPT_OptLayout wsAfterTrm);
PTPT_ATerm PTPT_setATermAnnotation(PTPT_ATerm arg, PTPT_Annotation Annotation);

/*}}}  */
/*{{{  PTPT_Annotation accessors */

ATbool PTPT_isValidAnnotation(PTPT_Annotation arg);
inline ATbool PTPT_isAnnotationDefault(PTPT_Annotation arg);
ATbool PTPT_hasAnnotationWsAfterBraceOpen(PTPT_Annotation arg);
ATbool PTPT_hasAnnotationAnnos(PTPT_Annotation arg);
ATbool PTPT_hasAnnotationWsAfterAnnos(PTPT_Annotation arg);
PTPT_OptLayout PTPT_getAnnotationWsAfterBraceOpen(PTPT_Annotation arg);
PTPT_ATermAnnos PTPT_getAnnotationAnnos(PTPT_Annotation arg);
PTPT_OptLayout PTPT_getAnnotationWsAfterAnnos(PTPT_Annotation arg);
PTPT_Annotation PTPT_setAnnotationWsAfterBraceOpen(PTPT_Annotation arg, PTPT_OptLayout wsAfterBraceOpen);
PTPT_Annotation PTPT_setAnnotationAnnos(PTPT_Annotation arg, PTPT_ATermAnnos annos);
PTPT_Annotation PTPT_setAnnotationWsAfterAnnos(PTPT_Annotation arg, PTPT_OptLayout wsAfterAnnos);

/*}}}  */
/*{{{  PTPT_ATermArgs accessors */

ATbool PTPT_isValidATermArgs(PTPT_ATermArgs arg);
inline ATbool PTPT_isATermArgsEmpty(PTPT_ATermArgs arg);
inline ATbool PTPT_isATermArgsSingle(PTPT_ATermArgs arg);
inline ATbool PTPT_isATermArgsMany(PTPT_ATermArgs arg);
ATbool PTPT_hasATermArgsHead(PTPT_ATermArgs arg);
ATbool PTPT_hasATermArgsWsAfterHead(PTPT_ATermArgs arg);
ATbool PTPT_hasATermArgsWsAfterSep(PTPT_ATermArgs arg);
ATbool PTPT_hasATermArgsTail(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_getATermArgsTail(PTPT_ATermArgs arg);
PTPT_ATerm PTPT_getATermArgsHead(PTPT_ATermArgs arg);
PTPT_OptLayout PTPT_getATermArgsWsAfterHead(PTPT_ATermArgs arg);
PTPT_OptLayout PTPT_getATermArgsWsAfterSep(PTPT_ATermArgs arg);
PTPT_ATermArgs PTPT_setATermArgsHead(PTPT_ATermArgs arg, PTPT_ATerm head);
PTPT_ATermArgs PTPT_setATermArgsWsAfterHead(PTPT_ATermArgs arg, PTPT_OptLayout wsAfterHead);
PTPT_ATermArgs PTPT_setATermArgsWsAfterSep(PTPT_ATermArgs arg, PTPT_OptLayout wsAfterSep);
PTPT_ATermArgs PTPT_setATermArgsTail(PTPT_ATermArgs arg, PTPT_ATermArgs tail);

/*}}}  */
/*{{{  PTPT_ATermElems accessors */

ATbool PTPT_isValidATermElems(PTPT_ATermElems arg);
inline ATbool PTPT_isATermElemsEmpty(PTPT_ATermElems arg);
inline ATbool PTPT_isATermElemsSingle(PTPT_ATermElems arg);
inline ATbool PTPT_isATermElemsMany(PTPT_ATermElems arg);
ATbool PTPT_hasATermElemsHead(PTPT_ATermElems arg);
ATbool PTPT_hasATermElemsWsAfterHead(PTPT_ATermElems arg);
ATbool PTPT_hasATermElemsWsAfterSep(PTPT_ATermElems arg);
ATbool PTPT_hasATermElemsTail(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_getATermElemsTail(PTPT_ATermElems arg);
PTPT_ATerm PTPT_getATermElemsHead(PTPT_ATermElems arg);
PTPT_OptLayout PTPT_getATermElemsWsAfterHead(PTPT_ATermElems arg);
PTPT_OptLayout PTPT_getATermElemsWsAfterSep(PTPT_ATermElems arg);
PTPT_ATermElems PTPT_setATermElemsHead(PTPT_ATermElems arg, PTPT_ATerm head);
PTPT_ATermElems PTPT_setATermElemsWsAfterHead(PTPT_ATermElems arg, PTPT_OptLayout wsAfterHead);
PTPT_ATermElems PTPT_setATermElemsWsAfterSep(PTPT_ATermElems arg, PTPT_OptLayout wsAfterSep);
PTPT_ATermElems PTPT_setATermElemsTail(PTPT_ATermElems arg, PTPT_ATermElems tail);

/*}}}  */
/*{{{  PTPT_ATermAnnos accessors */

ATbool PTPT_isValidATermAnnos(PTPT_ATermAnnos arg);
inline ATbool PTPT_isATermAnnosEmpty(PTPT_ATermAnnos arg);
inline ATbool PTPT_isATermAnnosSingle(PTPT_ATermAnnos arg);
inline ATbool PTPT_isATermAnnosMany(PTPT_ATermAnnos arg);
ATbool PTPT_hasATermAnnosHead(PTPT_ATermAnnos arg);
ATbool PTPT_hasATermAnnosWsAfterHead(PTPT_ATermAnnos arg);
ATbool PTPT_hasATermAnnosWsAfterSep(PTPT_ATermAnnos arg);
ATbool PTPT_hasATermAnnosTail(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_getATermAnnosTail(PTPT_ATermAnnos arg);
PTPT_ATerm PTPT_getATermAnnosHead(PTPT_ATermAnnos arg);
PTPT_OptLayout PTPT_getATermAnnosWsAfterHead(PTPT_ATermAnnos arg);
PTPT_OptLayout PTPT_getATermAnnosWsAfterSep(PTPT_ATermAnnos arg);
PTPT_ATermAnnos PTPT_setATermAnnosHead(PTPT_ATermAnnos arg, PTPT_ATerm head);
PTPT_ATermAnnos PTPT_setATermAnnosWsAfterHead(PTPT_ATermAnnos arg, PTPT_OptLayout wsAfterHead);
PTPT_ATermAnnos PTPT_setATermAnnosWsAfterSep(PTPT_ATermAnnos arg, PTPT_OptLayout wsAfterSep);
PTPT_ATermAnnos PTPT_setATermAnnosTail(PTPT_ATermAnnos arg, PTPT_ATermAnnos tail);

/*}}}  */
/*{{{  PTPT_IntCon accessors */

ATbool PTPT_isValidIntCon(PTPT_IntCon arg);
inline ATbool PTPT_isIntConNatural(PTPT_IntCon arg);
inline ATbool PTPT_isIntConPositive(PTPT_IntCon arg);
inline ATbool PTPT_isIntConNegative(PTPT_IntCon arg);
ATbool PTPT_hasIntConNatCon(PTPT_IntCon arg);
ATbool PTPT_hasIntConWsAfterPos(PTPT_IntCon arg);
ATbool PTPT_hasIntConWsAfterNeg(PTPT_IntCon arg);
PTPT_NatCon PTPT_getIntConNatCon(PTPT_IntCon arg);
PTPT_OptLayout PTPT_getIntConWsAfterPos(PTPT_IntCon arg);
PTPT_OptLayout PTPT_getIntConWsAfterNeg(PTPT_IntCon arg);
PTPT_IntCon PTPT_setIntConNatCon(PTPT_IntCon arg, PTPT_NatCon NatCon);
PTPT_IntCon PTPT_setIntConWsAfterPos(PTPT_IntCon arg, PTPT_OptLayout wsAfterPos);
PTPT_IntCon PTPT_setIntConWsAfterNeg(PTPT_IntCon arg, PTPT_OptLayout wsAfterNeg);

/*}}}  */
/*{{{  PTPT_OptExp accessors */

ATbool PTPT_isValidOptExp(PTPT_OptExp arg);
inline ATbool PTPT_isOptExpPresent(PTPT_OptExp arg);
inline ATbool PTPT_isOptExpAbsent(PTPT_OptExp arg);
ATbool PTPT_hasOptExpWsAfterE(PTPT_OptExp arg);
ATbool PTPT_hasOptExpIntCon(PTPT_OptExp arg);
PTPT_OptLayout PTPT_getOptExpWsAfterE(PTPT_OptExp arg);
PTPT_IntCon PTPT_getOptExpIntCon(PTPT_OptExp arg);
PTPT_OptExp PTPT_setOptExpWsAfterE(PTPT_OptExp arg, PTPT_OptLayout wsAfterE);
PTPT_OptExp PTPT_setOptExpIntCon(PTPT_OptExp arg, PTPT_IntCon IntCon);

/*}}}  */
/*{{{  PTPT_RealCon accessors */

ATbool PTPT_isValidRealCon(PTPT_RealCon arg);
inline ATbool PTPT_isRealConRealCon(PTPT_RealCon arg);
ATbool PTPT_hasRealConBase(PTPT_RealCon arg);
ATbool PTPT_hasRealConWsAfterBase(PTPT_RealCon arg);
ATbool PTPT_hasRealConWsAfterPeriod(PTPT_RealCon arg);
ATbool PTPT_hasRealConDecimal(PTPT_RealCon arg);
ATbool PTPT_hasRealConWsAfterDecimal(PTPT_RealCon arg);
ATbool PTPT_hasRealConExp(PTPT_RealCon arg);
PTPT_IntCon PTPT_getRealConBase(PTPT_RealCon arg);
PTPT_OptLayout PTPT_getRealConWsAfterBase(PTPT_RealCon arg);
PTPT_OptLayout PTPT_getRealConWsAfterPeriod(PTPT_RealCon arg);
PTPT_NatCon PTPT_getRealConDecimal(PTPT_RealCon arg);
PTPT_OptLayout PTPT_getRealConWsAfterDecimal(PTPT_RealCon arg);
PTPT_OptExp PTPT_getRealConExp(PTPT_RealCon arg);
PTPT_RealCon PTPT_setRealConBase(PTPT_RealCon arg, PTPT_IntCon base);
PTPT_RealCon PTPT_setRealConWsAfterBase(PTPT_RealCon arg, PTPT_OptLayout wsAfterBase);
PTPT_RealCon PTPT_setRealConWsAfterPeriod(PTPT_RealCon arg, PTPT_OptLayout wsAfterPeriod);
PTPT_RealCon PTPT_setRealConDecimal(PTPT_RealCon arg, PTPT_NatCon decimal);
PTPT_RealCon PTPT_setRealConWsAfterDecimal(PTPT_RealCon arg, PTPT_OptLayout wsAfterDecimal);
PTPT_RealCon PTPT_setRealConExp(PTPT_RealCon arg, PTPT_OptExp exp);

/*}}}  */
/*{{{  PTPT_LexStrChar accessors */

ATbool PTPT_isValidLexStrChar(PTPT_LexStrChar arg);
inline ATbool PTPT_isLexStrCharNewline(PTPT_LexStrChar arg);
inline ATbool PTPT_isLexStrCharTab(PTPT_LexStrChar arg);
inline ATbool PTPT_isLexStrCharQuote(PTPT_LexStrChar arg);
inline ATbool PTPT_isLexStrCharBackslash(PTPT_LexStrChar arg);
inline ATbool PTPT_isLexStrCharDecimal(PTPT_LexStrChar arg);
inline ATbool PTPT_isLexStrCharNormal(PTPT_LexStrChar arg);
ATbool PTPT_hasLexStrCharA(PTPT_LexStrChar arg);
ATbool PTPT_hasLexStrCharB(PTPT_LexStrChar arg);
ATbool PTPT_hasLexStrCharC(PTPT_LexStrChar arg);
ATbool PTPT_hasLexStrCharCh(PTPT_LexStrChar arg);
char PTPT_getLexStrCharA(PTPT_LexStrChar arg);
char PTPT_getLexStrCharB(PTPT_LexStrChar arg);
char PTPT_getLexStrCharC(PTPT_LexStrChar arg);
char PTPT_getLexStrCharCh(PTPT_LexStrChar arg);
PTPT_LexStrChar PTPT_setLexStrCharA(PTPT_LexStrChar arg, char a);
PTPT_LexStrChar PTPT_setLexStrCharB(PTPT_LexStrChar arg, char b);
PTPT_LexStrChar PTPT_setLexStrCharC(PTPT_LexStrChar arg, char c);
PTPT_LexStrChar PTPT_setLexStrCharCh(PTPT_LexStrChar arg, char ch);

/*}}}  */
/*{{{  PTPT_StrChar accessors */

ATbool PTPT_isValidStrChar(PTPT_StrChar arg);
inline ATbool PTPT_isStrCharLexToCf(PTPT_StrChar arg);
ATbool PTPT_hasStrCharStrChar(PTPT_StrChar arg);
PTPT_LexStrChar PTPT_getStrCharStrChar(PTPT_StrChar arg);
PTPT_StrChar PTPT_setStrCharStrChar(PTPT_StrChar arg, PTPT_LexStrChar StrChar);

/*}}}  */
/*{{{  PTPT_LexStrCon accessors */

ATbool PTPT_isValidLexStrCon(PTPT_LexStrCon arg);
inline ATbool PTPT_isLexStrConDefault(PTPT_LexStrCon arg);
ATbool PTPT_hasLexStrConChars(PTPT_LexStrCon arg);
PTPT_LexStrCharChars PTPT_getLexStrConChars(PTPT_LexStrCon arg);
PTPT_LexStrCon PTPT_setLexStrConChars(PTPT_LexStrCon arg, PTPT_LexStrCharChars chars);

/*}}}  */
/*{{{  PTPT_StrCon accessors */

ATbool PTPT_isValidStrCon(PTPT_StrCon arg);
inline ATbool PTPT_isStrConLexToCf(PTPT_StrCon arg);
ATbool PTPT_hasStrConStrCon(PTPT_StrCon arg);
PTPT_LexStrCon PTPT_getStrConStrCon(PTPT_StrCon arg);
PTPT_StrCon PTPT_setStrConStrCon(PTPT_StrCon arg, PTPT_LexStrCon StrCon);

/*}}}  */
/*{{{  PTPT_LexStrCharChars accessors */

ATbool PTPT_isValidLexStrCharChars(PTPT_LexStrCharChars arg);
inline ATbool PTPT_isLexStrCharCharsEmpty(PTPT_LexStrCharChars arg);
inline ATbool PTPT_isLexStrCharCharsSingle(PTPT_LexStrCharChars arg);
inline ATbool PTPT_isLexStrCharCharsMany(PTPT_LexStrCharChars arg);
ATbool PTPT_hasLexStrCharCharsHead(PTPT_LexStrCharChars arg);
ATbool PTPT_hasLexStrCharCharsTail(PTPT_LexStrCharChars arg);
PTPT_LexStrChar PTPT_getLexStrCharCharsHead(PTPT_LexStrCharChars arg);
PTPT_LexStrCharChars PTPT_getLexStrCharCharsTail(PTPT_LexStrCharChars arg);
PTPT_LexStrCharChars PTPT_setLexStrCharCharsHead(PTPT_LexStrCharChars arg, PTPT_LexStrChar head);
PTPT_LexStrCharChars PTPT_setLexStrCharCharsTail(PTPT_LexStrCharChars arg, PTPT_LexStrCharChars tail);

/*}}}  */
/*{{{  PTPT_LexNatCon accessors */

ATbool PTPT_isValidLexNatCon(PTPT_LexNatCon arg);
inline ATbool PTPT_isLexNatConDigits(PTPT_LexNatCon arg);
ATbool PTPT_hasLexNatConList(PTPT_LexNatCon arg);
char* PTPT_getLexNatConList(PTPT_LexNatCon arg);
PTPT_LexNatCon PTPT_setLexNatConList(PTPT_LexNatCon arg, const char* list);

/*}}}  */
/*{{{  PTPT_NatCon accessors */

ATbool PTPT_isValidNatCon(PTPT_NatCon arg);
inline ATbool PTPT_isNatConLexToCf(PTPT_NatCon arg);
ATbool PTPT_hasNatConNatCon(PTPT_NatCon arg);
PTPT_LexNatCon PTPT_getNatConNatCon(PTPT_NatCon arg);
PTPT_NatCon PTPT_setNatConNatCon(PTPT_NatCon arg, PTPT_LexNatCon NatCon);

/*}}}  */
/*{{{  PTPT_LexIdCon accessors */

ATbool PTPT_isValidLexIdCon(PTPT_LexIdCon arg);
inline ATbool PTPT_isLexIdConDefault(PTPT_LexIdCon arg);
ATbool PTPT_hasLexIdConHead(PTPT_LexIdCon arg);
ATbool PTPT_hasLexIdConTail(PTPT_LexIdCon arg);
char PTPT_getLexIdConHead(PTPT_LexIdCon arg);
char* PTPT_getLexIdConTail(PTPT_LexIdCon arg);
PTPT_LexIdCon PTPT_setLexIdConHead(PTPT_LexIdCon arg, char head);
PTPT_LexIdCon PTPT_setLexIdConTail(PTPT_LexIdCon arg, const char* tail);

/*}}}  */
/*{{{  PTPT_IdCon accessors */

ATbool PTPT_isValidIdCon(PTPT_IdCon arg);
inline ATbool PTPT_isIdConLexToCf(PTPT_IdCon arg);
ATbool PTPT_hasIdConIdCon(PTPT_IdCon arg);
PTPT_LexIdCon PTPT_getIdConIdCon(PTPT_IdCon arg);
PTPT_IdCon PTPT_setIdConIdCon(PTPT_IdCon arg, PTPT_LexIdCon IdCon);

/*}}}  */
/*{{{  PTPT_LexLayout accessors */

ATbool PTPT_isValidLexLayout(PTPT_LexLayout arg);
inline ATbool PTPT_isLexLayoutWhitespace(PTPT_LexLayout arg);
ATbool PTPT_hasLexLayoutCh(PTPT_LexLayout arg);
char PTPT_getLexLayoutCh(PTPT_LexLayout arg);
PTPT_LexLayout PTPT_setLexLayoutCh(PTPT_LexLayout arg, char ch);

/*}}}  */
/*{{{  sort visitors */

PTPT_OptLayout PTPT_visitOptLayout(PTPT_OptLayout arg, PTPT_Layout (*acceptLayout)(PTPT_Layout));
PTPT_Layout PTPT_visitLayout(PTPT_Layout arg, PTPT_LexLayoutList (*acceptList)(PTPT_LexLayoutList));
PTPT_LexLayoutList PTPT_visitLexLayoutList(PTPT_LexLayoutList arg, PTPT_LexLayout (*acceptHead)(PTPT_LexLayout));
PTPT_Tree PTPT_visitTree(PTPT_Tree arg, PTPT_OptLayout (*acceptWsAfterTree)(PTPT_OptLayout), PTPT_Annotation (*acceptAnnotation)(PTPT_Annotation), PTPT_OptLayout (*acceptWsAfterAppl)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Production (*acceptProd)(PTPT_Production), PTPT_OptLayout (*acceptWsAfterProd)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_Args (*acceptArgs)(PTPT_Args), PTPT_OptLayout (*acceptWsAfterArgs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCycle)(PTPT_OptLayout), PTPT_Symbol (*acceptSymbol)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterSymbol)(PTPT_OptLayout), PTPT_NatCon (*acceptCycleLength)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterCycleLength)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterAmb)(PTPT_OptLayout), PTPT_NatCon (*acceptCharacter)(PTPT_NatCon));
PTPT_Attributes PTPT_visitAttributes(PTPT_Attributes arg, PTPT_OptLayout (*acceptWsAfterAttrs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Attrs (*acceptAttributes)(PTPT_Attrs), PTPT_OptLayout (*acceptWsAfterAttributes)(PTPT_OptLayout));
PTPT_Attrs PTPT_visitAttrs(PTPT_Attrs arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_AttrList (*acceptList)(PTPT_AttrList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_Attr PTPT_visitAttr(PTPT_Attr arg, PTPT_OptLayout (*acceptWsAfterAssoc)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Associativity (*acceptAssociativity)(PTPT_Associativity), PTPT_OptLayout (*acceptWsAfterAssociativity)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTerm)(PTPT_OptLayout), PTPT_ATerm (*acceptAterm)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterAterm)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterId)(PTPT_OptLayout), PTPT_StrCon (*acceptModuleName)(PTPT_StrCon), PTPT_OptLayout (*acceptWsAfterModuleName)(PTPT_OptLayout));
PTPT_Associativity PTPT_visitAssociativity(PTPT_Associativity arg);
PTPT_AttrList PTPT_visitAttrList(PTPT_AttrList arg, PTPT_Attr (*acceptHead)(PTPT_Attr), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_ParseTree PTPT_visitParseTree(PTPT_ParseTree arg, PTPT_OptLayout (*acceptWsAfterParsetree)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Tree (*acceptTop)(PTPT_Tree), PTPT_OptLayout (*acceptWsAfterTop)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_NatCon (*acceptAmbCnt)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterAmbCnt)(PTPT_OptLayout));
PTPT_Symbol PTPT_visitSymbol(PTPT_Symbol arg, PTPT_OptLayout (*acceptWsAfterLit)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_StrCon (*acceptString)(PTPT_StrCon), PTPT_OptLayout (*acceptWsAfterString)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCilit)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCf)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSymbol)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLex)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterOpt)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterAlt)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterRhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSeq)(PTPT_OptLayout), PTPT_Symbols (*acceptSymbols)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterSymbols)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTuple)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_Symbols (*acceptRest)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterRest)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSort)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIter)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterStar)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterSep)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSeparator)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterStarSep)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterN)(PTPT_OptLayout), PTPT_NatCon (*acceptNumber)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterNumber)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterSepN)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma1)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma2)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterFunc)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterVarsym)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCharClass)(PTPT_OptLayout), PTPT_CharRanges (*acceptCharRanges)(PTPT_CharRanges), PTPT_OptLayout (*acceptWsAfterCharRanges)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterStrategy)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParameterizedSort)(PTPT_OptLayout), PTPT_StrCon (*acceptSort)(PTPT_StrCon), PTPT_Symbols (*acceptParameters)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterParameters)(PTPT_OptLayout));
PTPT_Symbols PTPT_visitSymbols(PTPT_Symbols arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_SymbolList (*acceptList)(PTPT_SymbolList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_CharRanges PTPT_visitCharRanges(PTPT_CharRanges arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_CharRangeList (*acceptList)(PTPT_CharRangeList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_CharRange PTPT_visitCharRange(PTPT_CharRange arg, PTPT_NatCon (*acceptInteger)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterRange)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_NatCon (*acceptStart)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterStart)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_NatCon (*acceptEnd)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterEnd)(PTPT_OptLayout));
PTPT_Start PTPT_visitStart(PTPT_Start arg, PTPT_OptLayout (*acceptWsBefore)(PTPT_OptLayout), PTPT_Symbol (*acceptTopSymbol)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfter)(PTPT_OptLayout), int (*acceptAmbCnt)(int), PTPT_Tree (*acceptTopTree)(PTPT_Tree), PTPT_ATerm (*acceptTopATerm)(PTPT_ATerm), PTPT_IntCon (*acceptTopIntCon)(PTPT_IntCon), PTPT_RealCon (*acceptTopRealCon)(PTPT_RealCon));
PTPT_SymbolList PTPT_visitSymbolList(PTPT_SymbolList arg, PTPT_Symbol (*acceptHead)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_CharRangeList PTPT_visitCharRangeList(PTPT_CharRangeList arg, PTPT_CharRange (*acceptHead)(PTPT_CharRange), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_Args PTPT_visitArgs(PTPT_Args arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_TreeList (*acceptList)(PTPT_TreeList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_Production PTPT_visitProduction(PTPT_Production arg, PTPT_OptLayout (*acceptWsAfterProd)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Symbols (*acceptLhs)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterLhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma1)(PTPT_OptLayout), PTPT_Symbol (*acceptRhs)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterRhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma2)(PTPT_OptLayout), PTPT_Attributes (*acceptAttributes)(PTPT_Attributes), PTPT_OptLayout (*acceptWsAfterAttributes)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout));
PTPT_TreeList PTPT_visitTreeList(PTPT_TreeList arg, PTPT_Tree (*acceptHead)(PTPT_Tree), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_AFun PTPT_visitAFun(PTPT_AFun arg, PTPT_StrCon (*acceptStrCon)(PTPT_StrCon), PTPT_IdCon (*acceptIdCon)(PTPT_IdCon));
PTPT_ATerm PTPT_visitATerm(PTPT_ATerm arg, PTPT_IntCon (*acceptIntCon)(PTPT_IntCon), PTPT_RealCon (*acceptRealCon)(PTPT_RealCon), PTPT_AFun (*acceptFun)(PTPT_AFun), PTPT_OptLayout (*acceptWsAfterFun)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_ATermArgs (*acceptArgs)(PTPT_ATermArgs), PTPT_OptLayout (*acceptWsAfterArgs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLessThan)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterType)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_ATermElems (*acceptElems)(PTPT_ATermElems), PTPT_OptLayout (*acceptWsAfterElems)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTrm)(PTPT_OptLayout), PTPT_Annotation (*acceptAnnotation)(PTPT_Annotation));
PTPT_Annotation PTPT_visitAnnotation(PTPT_Annotation arg, PTPT_OptLayout (*acceptWsAfterBraceOpen)(PTPT_OptLayout), PTPT_ATermAnnos (*acceptAnnos)(PTPT_ATermAnnos), PTPT_OptLayout (*acceptWsAfterAnnos)(PTPT_OptLayout));
PTPT_ATermArgs PTPT_visitATermArgs(PTPT_ATermArgs arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_ATermElems PTPT_visitATermElems(PTPT_ATermElems arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_ATermAnnos PTPT_visitATermAnnos(PTPT_ATermAnnos arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout));
PTPT_IntCon PTPT_visitIntCon(PTPT_IntCon arg, PTPT_NatCon (*acceptNatCon)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterPos)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterNeg)(PTPT_OptLayout));
PTPT_OptExp PTPT_visitOptExp(PTPT_OptExp arg, PTPT_OptLayout (*acceptWsAfterE)(PTPT_OptLayout), PTPT_IntCon (*acceptIntCon)(PTPT_IntCon));
PTPT_RealCon PTPT_visitRealCon(PTPT_RealCon arg, PTPT_IntCon (*acceptBase)(PTPT_IntCon), PTPT_OptLayout (*acceptWsAfterBase)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterPeriod)(PTPT_OptLayout), PTPT_NatCon (*acceptDecimal)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterDecimal)(PTPT_OptLayout), PTPT_OptExp (*acceptExp)(PTPT_OptExp));
PTPT_LexStrChar PTPT_visitLexStrChar(PTPT_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char));
PTPT_StrChar PTPT_visitStrChar(PTPT_StrChar arg, PTPT_LexStrChar (*acceptStrChar)(PTPT_LexStrChar));
PTPT_LexStrCon PTPT_visitLexStrCon(PTPT_LexStrCon arg, PTPT_LexStrCharChars (*acceptChars)(PTPT_LexStrCharChars));
PTPT_StrCon PTPT_visitStrCon(PTPT_StrCon arg, PTPT_LexStrCon (*acceptStrCon)(PTPT_LexStrCon));
PTPT_LexStrCharChars PTPT_visitLexStrCharChars(PTPT_LexStrCharChars arg, PTPT_LexStrChar (*acceptHead)(PTPT_LexStrChar));
PTPT_LexNatCon PTPT_visitLexNatCon(PTPT_LexNatCon arg, char* (*acceptList)(char*));
PTPT_NatCon PTPT_visitNatCon(PTPT_NatCon arg, PTPT_LexNatCon (*acceptNatCon)(PTPT_LexNatCon));
PTPT_LexIdCon PTPT_visitLexIdCon(PTPT_LexIdCon arg, char (*acceptHead)(char), char* (*acceptTail)(char*));
PTPT_IdCon PTPT_visitIdCon(PTPT_IdCon arg, PTPT_LexIdCon (*acceptIdCon)(PTPT_LexIdCon));
PTPT_LexLayout PTPT_visitLexLayout(PTPT_LexLayout arg, char (*acceptCh)(char));

/*}}}  */

#endif /* _PTMEPT_H */
