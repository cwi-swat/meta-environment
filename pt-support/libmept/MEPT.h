#ifndef _MEPT_H
#define _MEPT_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "MEPT_dict.h"

typedef struct _PT_ParseTree *PT_ParseTree;
typedef struct _PT_Tree *PT_Tree;
typedef struct _PT_Args *PT_Args;
typedef struct _PT_Production *PT_Production;
typedef struct _PT_Attributes *PT_Attributes;
typedef struct _PT_Attrs *PT_Attrs;
typedef struct _PT_Attr *PT_Attr;
typedef struct _PT_Associativity *PT_Associativity;
typedef struct _PT_Symbol *PT_Symbol;
typedef struct _PT_Symbols *PT_Symbols;
typedef struct _PT_CharRange *PT_CharRange;
typedef struct _PT_CharRanges *PT_CharRanges;

#ifdef FAST_API
#define PT_initMEPTApi() (init_MEPT_dict())
#else
void _PT_initMEPTApi(void);
#define PT_initMEPTApi() (_PT_initMEPTApi())
#endif

#ifdef FAST_API
#define PT_protectParseTree(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectParseTree(PT_ParseTree *arg);
#define PT_protectParseTree(arg) (_PT_protectParseTree(arg))
#endif
#ifdef FAST_API
#define PT_unprotectParseTree(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectParseTree(PT_ParseTree *arg);
#define PT_unprotectParseTree(arg) (_PT_unprotectParseTree(arg))
#endif
#ifdef FAST_API
#define PT_protectTree(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectTree(PT_Tree *arg);
#define PT_protectTree(arg) (_PT_protectTree(arg))
#endif
#ifdef FAST_API
#define PT_unprotectTree(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectTree(PT_Tree *arg);
#define PT_unprotectTree(arg) (_PT_unprotectTree(arg))
#endif
#ifdef FAST_API
#define PT_protectArgs(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectArgs(PT_Args *arg);
#define PT_protectArgs(arg) (_PT_protectArgs(arg))
#endif
#ifdef FAST_API
#define PT_unprotectArgs(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectArgs(PT_Args *arg);
#define PT_unprotectArgs(arg) (_PT_unprotectArgs(arg))
#endif
#ifdef FAST_API
#define PT_protectProduction(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectProduction(PT_Production *arg);
#define PT_protectProduction(arg) (_PT_protectProduction(arg))
#endif
#ifdef FAST_API
#define PT_unprotectProduction(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectProduction(PT_Production *arg);
#define PT_unprotectProduction(arg) (_PT_unprotectProduction(arg))
#endif
#ifdef FAST_API
#define PT_protectAttributes(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectAttributes(PT_Attributes *arg);
#define PT_protectAttributes(arg) (_PT_protectAttributes(arg))
#endif
#ifdef FAST_API
#define PT_unprotectAttributes(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectAttributes(PT_Attributes *arg);
#define PT_unprotectAttributes(arg) (_PT_unprotectAttributes(arg))
#endif
#ifdef FAST_API
#define PT_protectAttrs(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectAttrs(PT_Attrs *arg);
#define PT_protectAttrs(arg) (_PT_protectAttrs(arg))
#endif
#ifdef FAST_API
#define PT_unprotectAttrs(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectAttrs(PT_Attrs *arg);
#define PT_unprotectAttrs(arg) (_PT_unprotectAttrs(arg))
#endif
#ifdef FAST_API
#define PT_protectAttr(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectAttr(PT_Attr *arg);
#define PT_protectAttr(arg) (_PT_protectAttr(arg))
#endif
#ifdef FAST_API
#define PT_unprotectAttr(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectAttr(PT_Attr *arg);
#define PT_unprotectAttr(arg) (_PT_unprotectAttr(arg))
#endif
#ifdef FAST_API
#define PT_protectAssociativity(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectAssociativity(PT_Associativity *arg);
#define PT_protectAssociativity(arg) (_PT_protectAssociativity(arg))
#endif
#ifdef FAST_API
#define PT_unprotectAssociativity(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectAssociativity(PT_Associativity *arg);
#define PT_unprotectAssociativity(arg) (_PT_unprotectAssociativity(arg))
#endif
#ifdef FAST_API
#define PT_protectSymbol(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectSymbol(PT_Symbol *arg);
#define PT_protectSymbol(arg) (_PT_protectSymbol(arg))
#endif
#ifdef FAST_API
#define PT_unprotectSymbol(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectSymbol(PT_Symbol *arg);
#define PT_unprotectSymbol(arg) (_PT_unprotectSymbol(arg))
#endif
#ifdef FAST_API
#define PT_protectSymbols(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectSymbols(PT_Symbols *arg);
#define PT_protectSymbols(arg) (_PT_protectSymbols(arg))
#endif
#ifdef FAST_API
#define PT_unprotectSymbols(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectSymbols(PT_Symbols *arg);
#define PT_unprotectSymbols(arg) (_PT_unprotectSymbols(arg))
#endif
#ifdef FAST_API
#define PT_protectCharRange(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectCharRange(PT_CharRange *arg);
#define PT_protectCharRange(arg) (_PT_protectCharRange(arg))
#endif
#ifdef FAST_API
#define PT_unprotectCharRange(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectCharRange(PT_CharRange *arg);
#define PT_unprotectCharRange(arg) (_PT_unprotectCharRange(arg))
#endif
#ifdef FAST_API
#define PT_protectCharRanges(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _PT_protectCharRanges(PT_CharRanges *arg);
#define PT_protectCharRanges(arg) (_PT_protectCharRanges(arg))
#endif
#ifdef FAST_API
#define PT_unprotectCharRanges(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _PT_unprotectCharRanges(PT_CharRanges *arg);
#define PT_unprotectCharRanges(arg) (_PT_unprotectCharRanges(arg))
#endif
#ifdef FAST_API
#define PT_ParseTreeFromTerm(t) ((((union {PT_ParseTree target; ATerm source; })(t)).target))
#else
PT_ParseTree _PT_ParseTreeFromTerm(ATerm t);
#define PT_ParseTreeFromTerm(t) (_PT_ParseTreeFromTerm(t))
#endif
#ifdef FAST_API
#define PT_ParseTreeToTerm(arg) ((((union {PT_ParseTree source; ATerm target; })(arg)).target))
#else
ATerm _PT_ParseTreeToTerm(PT_ParseTree arg);
#define PT_ParseTreeToTerm(arg) (_PT_ParseTreeToTerm(arg))
#endif
#ifdef FAST_API
#define PT_TreeFromTerm(t) ((((union {PT_Tree target; ATerm source; })(t)).target))
#else
PT_Tree _PT_TreeFromTerm(ATerm t);
#define PT_TreeFromTerm(t) (_PT_TreeFromTerm(t))
#endif
#ifdef FAST_API
#define PT_TreeToTerm(arg) ((((union {PT_Tree source; ATerm target; })(arg)).target))
#else
ATerm _PT_TreeToTerm(PT_Tree arg);
#define PT_TreeToTerm(arg) (_PT_TreeToTerm(arg))
#endif
#ifdef FAST_API
#define PT_ArgsFromTerm(t) ((((union {PT_Args target; ATerm source; })(t)).target))
#else
PT_Args _PT_ArgsFromTerm(ATerm t);
#define PT_ArgsFromTerm(t) (_PT_ArgsFromTerm(t))
#endif
#ifdef FAST_API
#define PT_ArgsToTerm(arg) ((((union {PT_Args source; ATerm target; })(arg)).target))
#else
ATerm _PT_ArgsToTerm(PT_Args arg);
#define PT_ArgsToTerm(arg) (_PT_ArgsToTerm(arg))
#endif
#ifdef FAST_API
#define PT_ProductionFromTerm(t) ((((union {PT_Production target; ATerm source; })(t)).target))
#else
PT_Production _PT_ProductionFromTerm(ATerm t);
#define PT_ProductionFromTerm(t) (_PT_ProductionFromTerm(t))
#endif
#ifdef FAST_API
#define PT_ProductionToTerm(arg) ((((union {PT_Production source; ATerm target; })(arg)).target))
#else
ATerm _PT_ProductionToTerm(PT_Production arg);
#define PT_ProductionToTerm(arg) (_PT_ProductionToTerm(arg))
#endif
#ifdef FAST_API
#define PT_AttributesFromTerm(t) ((((union {PT_Attributes target; ATerm source; })(t)).target))
#else
PT_Attributes _PT_AttributesFromTerm(ATerm t);
#define PT_AttributesFromTerm(t) (_PT_AttributesFromTerm(t))
#endif
#ifdef FAST_API
#define PT_AttributesToTerm(arg) ((((union {PT_Attributes source; ATerm target; })(arg)).target))
#else
ATerm _PT_AttributesToTerm(PT_Attributes arg);
#define PT_AttributesToTerm(arg) (_PT_AttributesToTerm(arg))
#endif
#ifdef FAST_API
#define PT_AttrsFromTerm(t) ((((union {PT_Attrs target; ATerm source; })(t)).target))
#else
PT_Attrs _PT_AttrsFromTerm(ATerm t);
#define PT_AttrsFromTerm(t) (_PT_AttrsFromTerm(t))
#endif
#ifdef FAST_API
#define PT_AttrsToTerm(arg) ((((union {PT_Attrs source; ATerm target; })(arg)).target))
#else
ATerm _PT_AttrsToTerm(PT_Attrs arg);
#define PT_AttrsToTerm(arg) (_PT_AttrsToTerm(arg))
#endif
#ifdef FAST_API
#define PT_AttrFromTerm(t) ((((union {PT_Attr target; ATerm source; })(t)).target))
#else
PT_Attr _PT_AttrFromTerm(ATerm t);
#define PT_AttrFromTerm(t) (_PT_AttrFromTerm(t))
#endif
#ifdef FAST_API
#define PT_AttrToTerm(arg) ((((union {PT_Attr source; ATerm target; })(arg)).target))
#else
ATerm _PT_AttrToTerm(PT_Attr arg);
#define PT_AttrToTerm(arg) (_PT_AttrToTerm(arg))
#endif
#ifdef FAST_API
#define PT_AssociativityFromTerm(t) ((((union {PT_Associativity target; ATerm source; })(t)).target))
#else
PT_Associativity _PT_AssociativityFromTerm(ATerm t);
#define PT_AssociativityFromTerm(t) (_PT_AssociativityFromTerm(t))
#endif
#ifdef FAST_API
#define PT_AssociativityToTerm(arg) ((((union {PT_Associativity source; ATerm target; })(arg)).target))
#else
ATerm _PT_AssociativityToTerm(PT_Associativity arg);
#define PT_AssociativityToTerm(arg) (_PT_AssociativityToTerm(arg))
#endif
#ifdef FAST_API
#define PT_SymbolFromTerm(t) ((((union {PT_Symbol target; ATerm source; })(t)).target))
#else
PT_Symbol _PT_SymbolFromTerm(ATerm t);
#define PT_SymbolFromTerm(t) (_PT_SymbolFromTerm(t))
#endif
#ifdef FAST_API
#define PT_SymbolToTerm(arg) ((((union {PT_Symbol source; ATerm target; })(arg)).target))
#else
ATerm _PT_SymbolToTerm(PT_Symbol arg);
#define PT_SymbolToTerm(arg) (_PT_SymbolToTerm(arg))
#endif
#ifdef FAST_API
#define PT_SymbolsFromTerm(t) ((((union {PT_Symbols target; ATerm source; })(t)).target))
#else
PT_Symbols _PT_SymbolsFromTerm(ATerm t);
#define PT_SymbolsFromTerm(t) (_PT_SymbolsFromTerm(t))
#endif
#ifdef FAST_API
#define PT_SymbolsToTerm(arg) ((((union {PT_Symbols source; ATerm target; })(arg)).target))
#else
ATerm _PT_SymbolsToTerm(PT_Symbols arg);
#define PT_SymbolsToTerm(arg) (_PT_SymbolsToTerm(arg))
#endif
#ifdef FAST_API
#define PT_CharRangeFromTerm(t) ((((union {PT_CharRange target; ATerm source; })(t)).target))
#else
PT_CharRange _PT_CharRangeFromTerm(ATerm t);
#define PT_CharRangeFromTerm(t) (_PT_CharRangeFromTerm(t))
#endif
#ifdef FAST_API
#define PT_CharRangeToTerm(arg) ((((union {PT_CharRange source; ATerm target; })(arg)).target))
#else
ATerm _PT_CharRangeToTerm(PT_CharRange arg);
#define PT_CharRangeToTerm(arg) (_PT_CharRangeToTerm(arg))
#endif
#ifdef FAST_API
#define PT_CharRangesFromTerm(t) ((((union {PT_CharRanges target; ATerm source; })(t)).target))
#else
PT_CharRanges _PT_CharRangesFromTerm(ATerm t);
#define PT_CharRangesFromTerm(t) (_PT_CharRangesFromTerm(t))
#endif
#ifdef FAST_API
#define PT_CharRangesToTerm(arg) ((((union {PT_CharRanges source; ATerm target; })(arg)).target))
#else
ATerm _PT_CharRangesToTerm(PT_CharRanges arg);
#define PT_CharRangesToTerm(arg) (_PT_CharRangesToTerm(arg))
#endif
#ifdef FAST_API
#define PT_getArgsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PT_getArgsLength(PT_Args arg);
#define PT_getArgsLength(arg) (_PT_getArgsLength(arg))
#endif
#ifdef FAST_API
#define PT_reverseArgs(arg) ((PT_Args) ATreverse((ATermList) (arg)))
#else
PT_Args _PT_reverseArgs(PT_Args arg);
#define PT_reverseArgs(arg) (_PT_reverseArgs(arg))
#endif
#ifdef FAST_API
#define PT_appendArgs(arg, elem) ((PT_Args) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PT_Args _PT_appendArgs(PT_Args arg, PT_Tree elem);
#define PT_appendArgs(arg, elem) (_PT_appendArgs(arg, elem))
#endif
#ifdef FAST_API
#define PT_concatArgs(arg0, arg1) ((PT_Args) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PT_Args _PT_concatArgs(PT_Args arg0, PT_Args arg1);
#define PT_concatArgs(arg0, arg1) (_PT_concatArgs(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_sliceArgs(arg, start, end) ((PT_Args) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PT_Args _PT_sliceArgs(PT_Args arg, int start, int end);
#define PT_sliceArgs(arg, start, end) (_PT_sliceArgs(arg, start, end))
#endif
#ifdef FAST_API
#define PT_getArgsTreeAt(arg, index) ((PT_Tree) (ATelementAt((ATermList) arg,index)))
#else
PT_Tree _PT_getArgsTreeAt(PT_Args arg, int index);
#define PT_getArgsTreeAt(arg, index) (_PT_getArgsTreeAt(arg, index))
#endif
#ifdef FAST_API
#define PT_replaceArgsTreeAt(arg, elem, index) ((PT_Args) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PT_Args _PT_replaceArgsTreeAt(PT_Args arg, PT_Tree elem, int index);
#define PT_replaceArgsTreeAt(arg, elem, index) (_PT_replaceArgsTreeAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PT_makeArgs2(elem1,  elem2) ((PT_Args) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PT_Args _PT_makeArgs2(PT_Tree elem1, PT_Tree elem2);
#define PT_makeArgs2(elem1,  elem2) (_PT_makeArgs2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PT_makeArgs3(elem1, elem2,  elem3) ((PT_Args) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PT_Args _PT_makeArgs3(PT_Tree elem1, PT_Tree elem2, PT_Tree elem3);
#define PT_makeArgs3(elem1, elem2,  elem3) (_PT_makeArgs3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PT_makeArgs4(elem1, elem2, elem3,  elem4) ((PT_Args) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PT_Args _PT_makeArgs4(PT_Tree elem1, PT_Tree elem2, PT_Tree elem3, PT_Tree elem4);
#define PT_makeArgs4(elem1, elem2, elem3,  elem4) (_PT_makeArgs4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PT_makeArgs5(elem1, elem2, elem3, elem4,  elem5) ((PT_Args) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PT_Args _PT_makeArgs5(PT_Tree elem1, PT_Tree elem2, PT_Tree elem3, PT_Tree elem4, PT_Tree elem5);
#define PT_makeArgs5(elem1, elem2, elem3, elem4,  elem5) (_PT_makeArgs5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PT_makeArgs6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PT_Args) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PT_Args _PT_makeArgs6(PT_Tree elem1, PT_Tree elem2, PT_Tree elem3, PT_Tree elem4, PT_Tree elem5, PT_Tree elem6);
#define PT_makeArgs6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PT_makeArgs6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PT_getAttrsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PT_getAttrsLength(PT_Attrs arg);
#define PT_getAttrsLength(arg) (_PT_getAttrsLength(arg))
#endif
#ifdef FAST_API
#define PT_reverseAttrs(arg) ((PT_Attrs) ATreverse((ATermList) (arg)))
#else
PT_Attrs _PT_reverseAttrs(PT_Attrs arg);
#define PT_reverseAttrs(arg) (_PT_reverseAttrs(arg))
#endif
#ifdef FAST_API
#define PT_appendAttrs(arg, elem) ((PT_Attrs) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PT_Attrs _PT_appendAttrs(PT_Attrs arg, PT_Attr elem);
#define PT_appendAttrs(arg, elem) (_PT_appendAttrs(arg, elem))
#endif
#ifdef FAST_API
#define PT_concatAttrs(arg0, arg1) ((PT_Attrs) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PT_Attrs _PT_concatAttrs(PT_Attrs arg0, PT_Attrs arg1);
#define PT_concatAttrs(arg0, arg1) (_PT_concatAttrs(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_sliceAttrs(arg, start, end) ((PT_Attrs) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PT_Attrs _PT_sliceAttrs(PT_Attrs arg, int start, int end);
#define PT_sliceAttrs(arg, start, end) (_PT_sliceAttrs(arg, start, end))
#endif
#ifdef FAST_API
#define PT_getAttrsAttrAt(arg, index) ((PT_Attr) (ATelementAt((ATermList) arg,index)))
#else
PT_Attr _PT_getAttrsAttrAt(PT_Attrs arg, int index);
#define PT_getAttrsAttrAt(arg, index) (_PT_getAttrsAttrAt(arg, index))
#endif
#ifdef FAST_API
#define PT_replaceAttrsAttrAt(arg, elem, index) ((PT_Attrs) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PT_Attrs _PT_replaceAttrsAttrAt(PT_Attrs arg, PT_Attr elem, int index);
#define PT_replaceAttrsAttrAt(arg, elem, index) (_PT_replaceAttrsAttrAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PT_makeAttrs2(elem1,  elem2) ((PT_Attrs) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PT_Attrs _PT_makeAttrs2(PT_Attr elem1, PT_Attr elem2);
#define PT_makeAttrs2(elem1,  elem2) (_PT_makeAttrs2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PT_makeAttrs3(elem1, elem2,  elem3) ((PT_Attrs) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PT_Attrs _PT_makeAttrs3(PT_Attr elem1, PT_Attr elem2, PT_Attr elem3);
#define PT_makeAttrs3(elem1, elem2,  elem3) (_PT_makeAttrs3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PT_makeAttrs4(elem1, elem2, elem3,  elem4) ((PT_Attrs) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PT_Attrs _PT_makeAttrs4(PT_Attr elem1, PT_Attr elem2, PT_Attr elem3, PT_Attr elem4);
#define PT_makeAttrs4(elem1, elem2, elem3,  elem4) (_PT_makeAttrs4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PT_makeAttrs5(elem1, elem2, elem3, elem4,  elem5) ((PT_Attrs) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PT_Attrs _PT_makeAttrs5(PT_Attr elem1, PT_Attr elem2, PT_Attr elem3, PT_Attr elem4, PT_Attr elem5);
#define PT_makeAttrs5(elem1, elem2, elem3, elem4,  elem5) (_PT_makeAttrs5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PT_makeAttrs6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PT_Attrs) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PT_Attrs _PT_makeAttrs6(PT_Attr elem1, PT_Attr elem2, PT_Attr elem3, PT_Attr elem4, PT_Attr elem5, PT_Attr elem6);
#define PT_makeAttrs6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PT_makeAttrs6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PT_getSymbolsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PT_getSymbolsLength(PT_Symbols arg);
#define PT_getSymbolsLength(arg) (_PT_getSymbolsLength(arg))
#endif
#ifdef FAST_API
#define PT_reverseSymbols(arg) ((PT_Symbols) ATreverse((ATermList) (arg)))
#else
PT_Symbols _PT_reverseSymbols(PT_Symbols arg);
#define PT_reverseSymbols(arg) (_PT_reverseSymbols(arg))
#endif
#ifdef FAST_API
#define PT_appendSymbols(arg, elem) ((PT_Symbols) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PT_Symbols _PT_appendSymbols(PT_Symbols arg, PT_Symbol elem);
#define PT_appendSymbols(arg, elem) (_PT_appendSymbols(arg, elem))
#endif
#ifdef FAST_API
#define PT_concatSymbols(arg0, arg1) ((PT_Symbols) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PT_Symbols _PT_concatSymbols(PT_Symbols arg0, PT_Symbols arg1);
#define PT_concatSymbols(arg0, arg1) (_PT_concatSymbols(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_sliceSymbols(arg, start, end) ((PT_Symbols) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PT_Symbols _PT_sliceSymbols(PT_Symbols arg, int start, int end);
#define PT_sliceSymbols(arg, start, end) (_PT_sliceSymbols(arg, start, end))
#endif
#ifdef FAST_API
#define PT_getSymbolsSymbolAt(arg, index) ((PT_Symbol) (ATelementAt((ATermList) arg,index)))
#else
PT_Symbol _PT_getSymbolsSymbolAt(PT_Symbols arg, int index);
#define PT_getSymbolsSymbolAt(arg, index) (_PT_getSymbolsSymbolAt(arg, index))
#endif
#ifdef FAST_API
#define PT_replaceSymbolsSymbolAt(arg, elem, index) ((PT_Symbols) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PT_Symbols _PT_replaceSymbolsSymbolAt(PT_Symbols arg, PT_Symbol elem, int index);
#define PT_replaceSymbolsSymbolAt(arg, elem, index) (_PT_replaceSymbolsSymbolAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PT_makeSymbols2(elem1,  elem2) ((PT_Symbols) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PT_Symbols _PT_makeSymbols2(PT_Symbol elem1, PT_Symbol elem2);
#define PT_makeSymbols2(elem1,  elem2) (_PT_makeSymbols2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PT_makeSymbols3(elem1, elem2,  elem3) ((PT_Symbols) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PT_Symbols _PT_makeSymbols3(PT_Symbol elem1, PT_Symbol elem2, PT_Symbol elem3);
#define PT_makeSymbols3(elem1, elem2,  elem3) (_PT_makeSymbols3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PT_makeSymbols4(elem1, elem2, elem3,  elem4) ((PT_Symbols) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PT_Symbols _PT_makeSymbols4(PT_Symbol elem1, PT_Symbol elem2, PT_Symbol elem3, PT_Symbol elem4);
#define PT_makeSymbols4(elem1, elem2, elem3,  elem4) (_PT_makeSymbols4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PT_makeSymbols5(elem1, elem2, elem3, elem4,  elem5) ((PT_Symbols) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PT_Symbols _PT_makeSymbols5(PT_Symbol elem1, PT_Symbol elem2, PT_Symbol elem3, PT_Symbol elem4, PT_Symbol elem5);
#define PT_makeSymbols5(elem1, elem2, elem3, elem4,  elem5) (_PT_makeSymbols5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PT_makeSymbols6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PT_Symbols) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PT_Symbols _PT_makeSymbols6(PT_Symbol elem1, PT_Symbol elem2, PT_Symbol elem3, PT_Symbol elem4, PT_Symbol elem5, PT_Symbol elem6);
#define PT_makeSymbols6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PT_makeSymbols6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define PT_getCharRangesLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _PT_getCharRangesLength(PT_CharRanges arg);
#define PT_getCharRangesLength(arg) (_PT_getCharRangesLength(arg))
#endif
#ifdef FAST_API
#define PT_reverseCharRanges(arg) ((PT_CharRanges) ATreverse((ATermList) (arg)))
#else
PT_CharRanges _PT_reverseCharRanges(PT_CharRanges arg);
#define PT_reverseCharRanges(arg) (_PT_reverseCharRanges(arg))
#endif
#ifdef FAST_API
#define PT_appendCharRanges(arg, elem) ((PT_CharRanges) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
PT_CharRanges _PT_appendCharRanges(PT_CharRanges arg, PT_CharRange elem);
#define PT_appendCharRanges(arg, elem) (_PT_appendCharRanges(arg, elem))
#endif
#ifdef FAST_API
#define PT_concatCharRanges(arg0, arg1) ((PT_CharRanges) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
PT_CharRanges _PT_concatCharRanges(PT_CharRanges arg0, PT_CharRanges arg1);
#define PT_concatCharRanges(arg0, arg1) (_PT_concatCharRanges(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_sliceCharRanges(arg, start, end) ((PT_CharRanges) ATgetSlice((ATermList) (arg), (start), (end)))
#else
PT_CharRanges _PT_sliceCharRanges(PT_CharRanges arg, int start, int end);
#define PT_sliceCharRanges(arg, start, end) (_PT_sliceCharRanges(arg, start, end))
#endif
#ifdef FAST_API
#define PT_getCharRangesCharRangeAt(arg, index) ((PT_CharRange) (ATelementAt((ATermList) arg,index)))
#else
PT_CharRange _PT_getCharRangesCharRangeAt(PT_CharRanges arg, int index);
#define PT_getCharRangesCharRangeAt(arg, index) (_PT_getCharRangesCharRangeAt(arg, index))
#endif
#ifdef FAST_API
#define PT_replaceCharRangesCharRangeAt(arg, elem, index) ((PT_CharRanges) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
PT_CharRanges _PT_replaceCharRangesCharRangeAt(PT_CharRanges arg, PT_CharRange elem, int index);
#define PT_replaceCharRangesCharRangeAt(arg, elem, index) (_PT_replaceCharRangesCharRangeAt(arg, elem, index))
#endif
#ifdef FAST_API
#define PT_makeCharRanges2(elem1,  elem2) ((PT_CharRanges) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
PT_CharRanges _PT_makeCharRanges2(PT_CharRange elem1, PT_CharRange elem2);
#define PT_makeCharRanges2(elem1,  elem2) (_PT_makeCharRanges2(elem1,  elem2))
#endif
#ifdef FAST_API
#define PT_makeCharRanges3(elem1, elem2,  elem3) ((PT_CharRanges) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
PT_CharRanges _PT_makeCharRanges3(PT_CharRange elem1, PT_CharRange elem2, PT_CharRange elem3);
#define PT_makeCharRanges3(elem1, elem2,  elem3) (_PT_makeCharRanges3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define PT_makeCharRanges4(elem1, elem2, elem3,  elem4) ((PT_CharRanges) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
PT_CharRanges _PT_makeCharRanges4(PT_CharRange elem1, PT_CharRange elem2, PT_CharRange elem3, PT_CharRange elem4);
#define PT_makeCharRanges4(elem1, elem2, elem3,  elem4) (_PT_makeCharRanges4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define PT_makeCharRanges5(elem1, elem2, elem3, elem4,  elem5) ((PT_CharRanges) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
PT_CharRanges _PT_makeCharRanges5(PT_CharRange elem1, PT_CharRange elem2, PT_CharRange elem3, PT_CharRange elem4, PT_CharRange elem5);
#define PT_makeCharRanges5(elem1, elem2, elem3, elem4,  elem5) (_PT_makeCharRanges5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define PT_makeCharRanges6(elem1, elem2, elem3, elem4, elem5,  elem6) ((PT_CharRanges) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
PT_CharRanges _PT_makeCharRanges6(PT_CharRange elem1, PT_CharRange elem2, PT_CharRange elem3, PT_CharRange elem4, PT_CharRange elem5, PT_CharRange elem6);
#define PT_makeCharRanges6(elem1, elem2, elem3, elem4, elem5,  elem6) (_PT_makeCharRanges6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
PT_ParseTree PT_makeParseTreeTop(PT_Tree top, int ambCnt);
PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args);
PT_Tree PT_makeTreeCycle(PT_Symbol symbol, int cycleLength);
PT_Tree PT_makeTreeAmb(PT_Args args);
PT_Tree PT_makeTreeChar(int character);
PT_Args PT_makeArgsEmpty(void);
PT_Args PT_makeArgsSingle(PT_Tree head);
PT_Args PT_makeArgsMany(PT_Tree head, PT_Args tail);
PT_Production PT_makeProductionDefault(PT_Symbols lhs, PT_Symbol rhs, PT_Attributes attributes);
PT_Production PT_makeProductionList(PT_Symbol rhs);
PT_Attributes PT_makeAttributesNoAttrs(void);
PT_Attributes PT_makeAttributesAttrs(PT_Attrs attrs);
PT_Attrs PT_makeAttrsEmpty(void);
PT_Attrs PT_makeAttrsSingle(PT_Attr head);
PT_Attrs PT_makeAttrsMany(PT_Attr head, PT_Attrs tail);
PT_Attr PT_makeAttrAssoc(PT_Associativity assoc);
PT_Attr PT_makeAttrTerm(ATerm value);
PT_Attr PT_makeAttrId(const char* moduleName);
PT_Attr PT_makeAttrBracket(void);
PT_Attr PT_makeAttrReject(void);
PT_Attr PT_makeAttrPrefer(void);
PT_Attr PT_makeAttrAvoid(void);
PT_Associativity PT_makeAssociativityLeft(void);
PT_Associativity PT_makeAssociativityRight(void);
PT_Associativity PT_makeAssociativityAssoc(void);
PT_Associativity PT_makeAssociativityNonAssoc(void);
PT_Symbol PT_makeSymbolLit(const char* string);
PT_Symbol PT_makeSymbolCilit(const char* string);
PT_Symbol PT_makeSymbolCf(PT_Symbol symbol);
PT_Symbol PT_makeSymbolLex(PT_Symbol symbol);
PT_Symbol PT_makeSymbolEmpty(void);
PT_Symbol PT_makeSymbolSeq(PT_Symbols symbols);
PT_Symbol PT_makeSymbolOpt(PT_Symbol symbol);
PT_Symbol PT_makeSymbolAlt(PT_Symbol lhs, PT_Symbol rhs);
PT_Symbol PT_makeSymbolTuple(PT_Symbol head, PT_Symbols rest);
PT_Symbol PT_makeSymbolSort(const char* string);
PT_Symbol PT_makeSymbolIterPlus(PT_Symbol symbol);
PT_Symbol PT_makeSymbolIterStar(PT_Symbol symbol);
PT_Symbol PT_makeSymbolIterPlusSep(PT_Symbol symbol, PT_Symbol separator);
PT_Symbol PT_makeSymbolIterStarSep(PT_Symbol symbol, PT_Symbol separator);
PT_Symbol PT_makeSymbolIterN(PT_Symbol symbol, int number);
PT_Symbol PT_makeSymbolIterSepN(PT_Symbol symbol, PT_Symbol separator, int number);
PT_Symbol PT_makeSymbolFunc(PT_Symbols symbols, PT_Symbol symbol);
PT_Symbol PT_makeSymbolParameterizedSort(const char* sort, PT_Symbols parameters);
PT_Symbol PT_makeSymbolStrategy(PT_Symbol lhs, PT_Symbol rhs);
PT_Symbol PT_makeSymbolVarSym(PT_Symbol symbol);
PT_Symbol PT_makeSymbolLayout(void);
PT_Symbol PT_makeSymbolCharClass(PT_CharRanges ranges);
PT_Symbols PT_makeSymbolsEmpty(void);
PT_Symbols PT_makeSymbolsSingle(PT_Symbol head);
PT_Symbols PT_makeSymbolsMany(PT_Symbol head, PT_Symbols tail);
PT_CharRange PT_makeCharRangeCharacter(int start);
PT_CharRange PT_makeCharRangeRange(int start, int end);
PT_CharRanges PT_makeCharRangesEmpty(void);
PT_CharRanges PT_makeCharRangesSingle(PT_CharRange head);
PT_CharRanges PT_makeCharRangesMany(PT_CharRange head, PT_CharRanges tail);
#ifdef FAST_API
#define PT_isEqualParseTree(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualParseTree(PT_ParseTree arg0, PT_ParseTree arg1);
#define PT_isEqualParseTree(arg0, arg1) (_PT_isEqualParseTree(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualTree(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualTree(PT_Tree arg0, PT_Tree arg1);
#define PT_isEqualTree(arg0, arg1) (_PT_isEqualTree(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualArgs(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualArgs(PT_Args arg0, PT_Args arg1);
#define PT_isEqualArgs(arg0, arg1) (_PT_isEqualArgs(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualProduction(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualProduction(PT_Production arg0, PT_Production arg1);
#define PT_isEqualProduction(arg0, arg1) (_PT_isEqualProduction(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualAttributes(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualAttributes(PT_Attributes arg0, PT_Attributes arg1);
#define PT_isEqualAttributes(arg0, arg1) (_PT_isEqualAttributes(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualAttrs(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualAttrs(PT_Attrs arg0, PT_Attrs arg1);
#define PT_isEqualAttrs(arg0, arg1) (_PT_isEqualAttrs(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualAttr(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualAttr(PT_Attr arg0, PT_Attr arg1);
#define PT_isEqualAttr(arg0, arg1) (_PT_isEqualAttr(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualAssociativity(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualAssociativity(PT_Associativity arg0, PT_Associativity arg1);
#define PT_isEqualAssociativity(arg0, arg1) (_PT_isEqualAssociativity(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualSymbol(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualSymbol(PT_Symbol arg0, PT_Symbol arg1);
#define PT_isEqualSymbol(arg0, arg1) (_PT_isEqualSymbol(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualSymbols(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualSymbols(PT_Symbols arg0, PT_Symbols arg1);
#define PT_isEqualSymbols(arg0, arg1) (_PT_isEqualSymbols(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualCharRange(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualCharRange(PT_CharRange arg0, PT_CharRange arg1);
#define PT_isEqualCharRange(arg0, arg1) (_PT_isEqualCharRange(arg0, arg1))
#endif
#ifdef FAST_API
#define PT_isEqualCharRanges(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _PT_isEqualCharRanges(PT_CharRanges arg0, PT_CharRanges arg1);
#define PT_isEqualCharRanges(arg0, arg1) (_PT_isEqualCharRanges(arg0, arg1))
#endif
ATbool PT_isValidParseTree(PT_ParseTree arg);
inline ATbool PT_isParseTreeTop(PT_ParseTree arg);
ATbool PT_hasParseTreeTop(PT_ParseTree arg);
ATbool PT_hasParseTreeAmbCnt(PT_ParseTree arg);
PT_Tree PT_getParseTreeTop(PT_ParseTree arg);
int PT_getParseTreeAmbCnt(PT_ParseTree arg);
PT_ParseTree PT_setParseTreeTop(PT_ParseTree arg, PT_Tree top);
PT_ParseTree PT_setParseTreeAmbCnt(PT_ParseTree arg, int ambCnt);
ATbool PT_isValidTree(PT_Tree arg);
inline ATbool PT_isTreeAppl(PT_Tree arg);
inline ATbool PT_isTreeCycle(PT_Tree arg);
inline ATbool PT_isTreeAmb(PT_Tree arg);
inline ATbool PT_isTreeChar(PT_Tree arg);
ATbool PT_hasTreeProd(PT_Tree arg);
ATbool PT_hasTreeArgs(PT_Tree arg);
ATbool PT_hasTreeSymbol(PT_Tree arg);
ATbool PT_hasTreeCycleLength(PT_Tree arg);
ATbool PT_hasTreeCharacter(PT_Tree arg);
PT_Production PT_getTreeProd(PT_Tree arg);
PT_Args PT_getTreeArgs(PT_Tree arg);
PT_Symbol PT_getTreeSymbol(PT_Tree arg);
int PT_getTreeCycleLength(PT_Tree arg);
int PT_getTreeCharacter(PT_Tree arg);
PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod);
PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args);
PT_Tree PT_setTreeSymbol(PT_Tree arg, PT_Symbol symbol);
PT_Tree PT_setTreeCycleLength(PT_Tree arg, int cycleLength);
PT_Tree PT_setTreeCharacter(PT_Tree arg, int character);
ATbool PT_isValidArgs(PT_Args arg);
inline ATbool PT_isArgsEmpty(PT_Args arg);
inline ATbool PT_isArgsSingle(PT_Args arg);
inline ATbool PT_isArgsMany(PT_Args arg);
ATbool PT_hasArgsHead(PT_Args arg);
ATbool PT_hasArgsTail(PT_Args arg);
PT_Tree PT_getArgsHead(PT_Args arg);
PT_Args PT_getArgsTail(PT_Args arg);
PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head);
PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail);
ATbool PT_isValidProduction(PT_Production arg);
inline ATbool PT_isProductionDefault(PT_Production arg);
inline ATbool PT_isProductionList(PT_Production arg);
ATbool PT_hasProductionLhs(PT_Production arg);
ATbool PT_hasProductionRhs(PT_Production arg);
ATbool PT_hasProductionAttributes(PT_Production arg);
PT_Symbols PT_getProductionLhs(PT_Production arg);
PT_Symbol PT_getProductionRhs(PT_Production arg);
PT_Attributes PT_getProductionAttributes(PT_Production arg);
PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs);
PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs);
PT_Production PT_setProductionAttributes(PT_Production arg, PT_Attributes attributes);
ATbool PT_isValidAttributes(PT_Attributes arg);
inline ATbool PT_isAttributesNoAttrs(PT_Attributes arg);
inline ATbool PT_isAttributesAttrs(PT_Attributes arg);
ATbool PT_hasAttributesAttrs(PT_Attributes arg);
PT_Attrs PT_getAttributesAttrs(PT_Attributes arg);
PT_Attributes PT_setAttributesAttrs(PT_Attributes arg, PT_Attrs attrs);
ATbool PT_isValidAttrs(PT_Attrs arg);
inline ATbool PT_isAttrsEmpty(PT_Attrs arg);
inline ATbool PT_isAttrsSingle(PT_Attrs arg);
inline ATbool PT_isAttrsMany(PT_Attrs arg);
ATbool PT_hasAttrsHead(PT_Attrs arg);
ATbool PT_hasAttrsTail(PT_Attrs arg);
PT_Attr PT_getAttrsHead(PT_Attrs arg);
PT_Attrs PT_getAttrsTail(PT_Attrs arg);
PT_Attrs PT_setAttrsHead(PT_Attrs arg, PT_Attr head);
PT_Attrs PT_setAttrsTail(PT_Attrs arg, PT_Attrs tail);
ATbool PT_isValidAttr(PT_Attr arg);
inline ATbool PT_isAttrAssoc(PT_Attr arg);
inline ATbool PT_isAttrTerm(PT_Attr arg);
inline ATbool PT_isAttrId(PT_Attr arg);
inline ATbool PT_isAttrBracket(PT_Attr arg);
inline ATbool PT_isAttrReject(PT_Attr arg);
inline ATbool PT_isAttrPrefer(PT_Attr arg);
inline ATbool PT_isAttrAvoid(PT_Attr arg);
ATbool PT_hasAttrAssoc(PT_Attr arg);
ATbool PT_hasAttrValue(PT_Attr arg);
ATbool PT_hasAttrModuleName(PT_Attr arg);
PT_Associativity PT_getAttrAssoc(PT_Attr arg);
ATerm PT_getAttrValue(PT_Attr arg);
char* PT_getAttrModuleName(PT_Attr arg);
PT_Attr PT_setAttrAssoc(PT_Attr arg, PT_Associativity assoc);
PT_Attr PT_setAttrValue(PT_Attr arg, ATerm value);
PT_Attr PT_setAttrModuleName(PT_Attr arg, const char* moduleName);
ATbool PT_isValidAssociativity(PT_Associativity arg);
inline ATbool PT_isAssociativityLeft(PT_Associativity arg);
inline ATbool PT_isAssociativityRight(PT_Associativity arg);
inline ATbool PT_isAssociativityAssoc(PT_Associativity arg);
inline ATbool PT_isAssociativityNonAssoc(PT_Associativity arg);
ATbool PT_isValidSymbol(PT_Symbol arg);
inline ATbool PT_isSymbolLit(PT_Symbol arg);
inline ATbool PT_isSymbolCilit(PT_Symbol arg);
inline ATbool PT_isSymbolCf(PT_Symbol arg);
inline ATbool PT_isSymbolLex(PT_Symbol arg);
inline ATbool PT_isSymbolEmpty(PT_Symbol arg);
inline ATbool PT_isSymbolSeq(PT_Symbol arg);
inline ATbool PT_isSymbolOpt(PT_Symbol arg);
inline ATbool PT_isSymbolAlt(PT_Symbol arg);
inline ATbool PT_isSymbolTuple(PT_Symbol arg);
inline ATbool PT_isSymbolSort(PT_Symbol arg);
inline ATbool PT_isSymbolIterPlus(PT_Symbol arg);
inline ATbool PT_isSymbolIterStar(PT_Symbol arg);
inline ATbool PT_isSymbolIterPlusSep(PT_Symbol arg);
inline ATbool PT_isSymbolIterStarSep(PT_Symbol arg);
inline ATbool PT_isSymbolIterN(PT_Symbol arg);
inline ATbool PT_isSymbolIterSepN(PT_Symbol arg);
inline ATbool PT_isSymbolFunc(PT_Symbol arg);
inline ATbool PT_isSymbolParameterizedSort(PT_Symbol arg);
inline ATbool PT_isSymbolStrategy(PT_Symbol arg);
inline ATbool PT_isSymbolVarSym(PT_Symbol arg);
inline ATbool PT_isSymbolLayout(PT_Symbol arg);
inline ATbool PT_isSymbolCharClass(PT_Symbol arg);
ATbool PT_hasSymbolString(PT_Symbol arg);
ATbool PT_hasSymbolSymbol(PT_Symbol arg);
ATbool PT_hasSymbolSymbols(PT_Symbol arg);
ATbool PT_hasSymbolLhs(PT_Symbol arg);
ATbool PT_hasSymbolRhs(PT_Symbol arg);
ATbool PT_hasSymbolHead(PT_Symbol arg);
ATbool PT_hasSymbolRest(PT_Symbol arg);
ATbool PT_hasSymbolSeparator(PT_Symbol arg);
ATbool PT_hasSymbolNumber(PT_Symbol arg);
ATbool PT_hasSymbolSort(PT_Symbol arg);
ATbool PT_hasSymbolParameters(PT_Symbol arg);
ATbool PT_hasSymbolRanges(PT_Symbol arg);
char* PT_getSymbolString(PT_Symbol arg);
PT_Symbol PT_getSymbolSymbol(PT_Symbol arg);
PT_Symbols PT_getSymbolSymbols(PT_Symbol arg);
PT_Symbol PT_getSymbolLhs(PT_Symbol arg);
PT_Symbol PT_getSymbolRhs(PT_Symbol arg);
PT_Symbol PT_getSymbolHead(PT_Symbol arg);
PT_Symbols PT_getSymbolRest(PT_Symbol arg);
PT_Symbol PT_getSymbolSeparator(PT_Symbol arg);
int PT_getSymbolNumber(PT_Symbol arg);
char* PT_getSymbolSort(PT_Symbol arg);
PT_Symbols PT_getSymbolParameters(PT_Symbol arg);
PT_CharRanges PT_getSymbolRanges(PT_Symbol arg);
PT_Symbol PT_setSymbolString(PT_Symbol arg, const char* string);
PT_Symbol PT_setSymbolSymbol(PT_Symbol arg, PT_Symbol symbol);
PT_Symbol PT_setSymbolSymbols(PT_Symbol arg, PT_Symbols symbols);
PT_Symbol PT_setSymbolLhs(PT_Symbol arg, PT_Symbol lhs);
PT_Symbol PT_setSymbolRhs(PT_Symbol arg, PT_Symbol rhs);
PT_Symbol PT_setSymbolHead(PT_Symbol arg, PT_Symbol head);
PT_Symbol PT_setSymbolRest(PT_Symbol arg, PT_Symbols rest);
PT_Symbol PT_setSymbolSeparator(PT_Symbol arg, PT_Symbol separator);
PT_Symbol PT_setSymbolNumber(PT_Symbol arg, int number);
PT_Symbol PT_setSymbolSort(PT_Symbol arg, const char* sort);
PT_Symbol PT_setSymbolParameters(PT_Symbol arg, PT_Symbols parameters);
PT_Symbol PT_setSymbolRanges(PT_Symbol arg, PT_CharRanges ranges);
ATbool PT_isValidSymbols(PT_Symbols arg);
inline ATbool PT_isSymbolsEmpty(PT_Symbols arg);
inline ATbool PT_isSymbolsSingle(PT_Symbols arg);
inline ATbool PT_isSymbolsMany(PT_Symbols arg);
ATbool PT_hasSymbolsHead(PT_Symbols arg);
ATbool PT_hasSymbolsTail(PT_Symbols arg);
PT_Symbol PT_getSymbolsHead(PT_Symbols arg);
PT_Symbols PT_getSymbolsTail(PT_Symbols arg);
PT_Symbols PT_setSymbolsHead(PT_Symbols arg, PT_Symbol head);
PT_Symbols PT_setSymbolsTail(PT_Symbols arg, PT_Symbols tail);
ATbool PT_isValidCharRange(PT_CharRange arg);
inline ATbool PT_isCharRangeCharacter(PT_CharRange arg);
inline ATbool PT_isCharRangeRange(PT_CharRange arg);
ATbool PT_hasCharRangeStart(PT_CharRange arg);
ATbool PT_hasCharRangeEnd(PT_CharRange arg);
int PT_getCharRangeStart(PT_CharRange arg);
int PT_getCharRangeEnd(PT_CharRange arg);
PT_CharRange PT_setCharRangeStart(PT_CharRange arg, int start);
PT_CharRange PT_setCharRangeEnd(PT_CharRange arg, int end);
ATbool PT_isValidCharRanges(PT_CharRanges arg);
inline ATbool PT_isCharRangesEmpty(PT_CharRanges arg);
inline ATbool PT_isCharRangesSingle(PT_CharRanges arg);
inline ATbool PT_isCharRangesMany(PT_CharRanges arg);
ATbool PT_hasCharRangesHead(PT_CharRanges arg);
ATbool PT_hasCharRangesTail(PT_CharRanges arg);
PT_CharRange PT_getCharRangesHead(PT_CharRanges arg);
PT_CharRanges PT_getCharRangesTail(PT_CharRanges arg);
PT_CharRanges PT_setCharRangesHead(PT_CharRanges arg, PT_CharRange head);
PT_CharRanges PT_setCharRangesTail(PT_CharRanges arg, PT_CharRanges tail);
PT_ParseTree PT_visitParseTree(PT_ParseTree arg, PT_Tree (*acceptTop)(PT_Tree), int (*acceptAmbCnt)(int));
PT_Tree PT_visitTree(PT_Tree arg, PT_Production (*acceptProd)(PT_Production), PT_Args (*acceptArgs)(PT_Args), PT_Symbol (*acceptSymbol)(PT_Symbol), int (*acceptCycleLength)(int), int (*acceptCharacter)(int));
PT_Args PT_visitArgs(PT_Args arg, PT_Tree (*acceptHead)(PT_Tree));
PT_Production PT_visitProduction(PT_Production arg, PT_Symbols (*acceptLhs)(PT_Symbols), PT_Symbol (*acceptRhs)(PT_Symbol), PT_Attributes (*acceptAttributes)(PT_Attributes));
PT_Attributes PT_visitAttributes(PT_Attributes arg, PT_Attrs (*acceptAttrs)(PT_Attrs));
PT_Attrs PT_visitAttrs(PT_Attrs arg, PT_Attr (*acceptHead)(PT_Attr));
PT_Attr PT_visitAttr(PT_Attr arg, PT_Associativity (*acceptAssoc)(PT_Associativity), ATerm (*acceptValue)(ATerm), char* (*acceptModuleName)(char*));
PT_Associativity PT_visitAssociativity(PT_Associativity arg);
PT_Symbol PT_visitSymbol(PT_Symbol arg, char* (*acceptString)(char*), PT_Symbols (*acceptSymbols)(PT_Symbols), PT_Symbols (*acceptRest)(PT_Symbols), int (*acceptNumber)(int), char* (*acceptSort)(char*), PT_Symbols (*acceptParameters)(PT_Symbols), PT_CharRanges (*acceptRanges)(PT_CharRanges));
PT_Symbols PT_visitSymbols(PT_Symbols arg, PT_Symbol (*acceptHead)(PT_Symbol));
PT_CharRange PT_visitCharRange(PT_CharRange arg, int (*acceptStart)(int), int (*acceptEnd)(int));
PT_CharRanges PT_visitCharRanges(PT_CharRanges arg, PT_CharRange (*acceptHead)(PT_CharRange));

#endif /* _MEPT_H */
