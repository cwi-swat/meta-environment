/*
   $Id$
*/         

#ifndef _ME_PT_H
#define _ME_PT_H

#include <aterm2.h>
#include <deprecated.h>
#include "MEPT.h" 

PT_Tree PT_applyFunctionToArgs(char *function, char* sort, PT_Args args);
PT_ParseTree PT_applyFunctionToArgsParseTree(char *function, char *sort, 
					     PT_Args args);
PT_Tree PT_applyFunctionToTree(char *function, char* sort, int nArgs, ...);

ATbool PT_prodHasLitAsRhs(PT_Production arg);
ATbool PT_isLexicalProd(PT_Production arg);
ATbool PT_prodHasLexLayoutAsRhs(PT_Production arg);
ATbool PT_prodHasCfLayoutAsRhs(PT_Production arg);
ATbool PT_isOptLayoutProd(PT_Production arg);
ATbool PT_prodHasVarSymAsRhs(PT_Production arg);
ATbool PT_isVarDefault(PT_Production arg);
ATbool PT_isLexicalInjectionProd(PT_Production prod);
ATbool PT_isProductionInjection(PT_Production prod);
ATbool PT_prodHasIterSepAsRhs(PT_Production prod);
ATbool PT_prodHasIterAsRhs(PT_Production prod);

ATbool PT_isTreeListInjection(PT_Tree tree);
ATbool PT_isTreeApplList(PT_Tree tree);
ATbool PT_isTreeAlt(PT_Tree tree);
ATbool PT_isTreeSeq(PT_Tree tree);
ATbool PT_isIterSepSymbol(PT_Symbol sym);
ATbool PT_isIterSymbol(PT_Symbol sym);
ATbool PT_prodHasSTARTAsRhs(PT_Production prod);
ATbool PT_isOptLayoutSymbol(PT_Symbol arg);
PT_Symbol PT_makeOptLayoutSymbol();

PT_Args PT_concatArgs(PT_Args args1, PT_Args args2);
PT_Args PT_appendArgs(PT_Args args, PT_Tree arg);
PT_Args PT_reverseArgs(PT_Args args);
int PT_getArgsLength(PT_Args args);
PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr);
PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr);
PT_Args PT_sliceArgs(PT_Args args, int start, int end);

char *PT_yieldAny(ATerm t);
char *PT_yieldParseTree(PT_ParseTree tree);
char *PT_yieldTree(PT_Tree tree);
char *PT_yieldArgs(PT_Args tree);
int   PT_getTreeLength(PT_Tree tree);

char *PT_yieldAnyVisualAmbs(ATerm t, ATbool visualAmbs);
char *PT_yieldParseTreeVisualAmbs(PT_ParseTree tree, ATbool visualAmbs);
char *PT_yieldTreeVisualAmbs(PT_Tree tree, ATbool visualAmbs);                 
char *PT_yieldArgsVisualAmbs(PT_Args tree, ATbool visualAmbs);

char *PT_yieldProduction(PT_Production prod);
char *PT_yieldSymbol(PT_Symbol symbol);
char *PT_yieldSymbolVisualVariables(PT_Symbol symbol, ATbool showVars);

ATerm PT_reportTreeAmbiguities(PT_Tree tree);
ATerm PT_reportParseTreeAmbiguities(PT_ParseTree parsetree);

char* PT_printTreeToDot(PT_Tree tree, ATbool sharing, ATbool characters, 
			ATbool characters_sharing, ATbool productions, 
			ATbool layout, ATbool literals);
char* PT_printParseTreeToDot(PT_ParseTree parsetree, ATbool sharing, 
			     ATbool characters_sharing, ATbool characters, 
			     ATbool productions, ATbool layout, 
			     ATbool literals);

ATerm implodeParseTree(PT_ParseTree tree);

typedef void* PT_TreeVisitorData;
typedef PT_Tree (*PT_TreeVisitor)(PT_Tree tree, PT_TreeVisitorData data);
PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor,                                           PT_TreeVisitorData data);

PT_Symbols PT_appendSymbols(PT_Symbols symbols, PT_Symbol symbol);
int PT_getSymbolsLength(PT_Symbols symbols);
PT_Symbol PT_getSymbolsSymbolAt(PT_Symbols symbols, int index);

typedef void* PT_SymbolVisitorData;
typedef PT_Symbol (*PT_SymbolVisitor)(PT_Symbol symbol,
                                      PT_SymbolVisitorData data);
PT_Symbols PT_foreachSymbolInSymbols(PT_Symbols symbols,
                                     PT_SymbolVisitor visitor,
                                     PT_SymbolVisitorData data); 

PT_ParseTree PT_addParseTreePosInfo(char *pathInfo, PT_ParseTree tree);
PT_ParseTree PT_addParseTreePosInfoToDepth(char *pathInfo, PT_ParseTree tree,
                                           int maxDepth);
PT_Tree PT_addTreePosInfoToDepth(char *pathInfo, PT_Tree tree, int maxDepth,
				 int start_line, int start_col);
PT_Tree PT_setTreePosInfo(PT_Tree tree, const char *path,
			  int from_line, int from_col, int to_line, int to_col);
void PT_calcTreePosInfo(PT_Tree tree, int *lines, int *cols);
ATbool PT_getTreePosInfo(PT_Tree tree, char **path,  int *start_line, int *start_col,
		       int *end_line, int *end_col);


ATerm   PT_getTreeAnnotation(PT_Tree tree, ATerm key);
PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value);
PT_Tree PT_annotateTreeWithLength(PT_Tree tree);
PT_ParseTree PT_annotateParseTreeWithLength(PT_ParseTree parse_tree);
int     PT_getParseTreeLengthAnno(PT_ParseTree parse_tree);
int     PT_getTreeLengthAnno(PT_Tree tree);
PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length);
PT_ParseTree PT_setParseTreeLengthAnno(PT_ParseTree parse_tree, int length);  

ATbool PT_isTreeLexical(PT_Tree tree);

PT_Tree PT_makeTreeLayoutEmpty();
ATbool  PT_isTreeLayout(PT_Tree tree);
PT_Tree PT_makeTreeLayoutNonEmpty(PT_Args args);
PT_Tree PT_makeTreeLayoutFromString(const char *str);

PT_Tree PT_makeTreeLexToCf(PT_Symbol sym, PT_Tree tree);

PT_Tree PT_removeTreeAnnotations(PT_Tree arg);  

ATbool PT_isTreeVar(PT_Tree tree);
ATbool PT_isTreeVarList(PT_Tree tree);
ATbool PT_isTreeVarListStar(PT_Tree tree);
ATbool PT_isTreeVarListPlus(PT_Tree tree);

typedef void* PT_AttrVisitorData;
typedef PT_Attr (*PT_AttrVisitor)(PT_Attr attr, PT_AttrVisitorData data);
PT_Attrs PT_foreachAttrInAttrs(PT_Attrs attrs, PT_AttrVisitor visitor,
                               PT_AttrVisitorData data);

                                                          
ATbool PT_hasProductionCertainAttr(PT_Production prod, PT_Attr attr);
ATbool PT_hasProductionBracketAttr(PT_Production prod);
ATbool PT_hasProductionMemoAttr(PT_Production prod);
ATbool PT_hasProductionTraverseAttr(PT_Production prod); 

PT_Symbols PT_concatSymbols(PT_Symbols symbols1, PT_Symbols symbols2);
PT_Symbol makeSymbolAllChars();
PT_Tree PT_makeTreeFlatLexical(PT_Args charList);
PT_Tree PT_makeTreeFlatLexicalFromString(const char *str);
ATbool PT_isTreeFlatLexical(PT_Tree tree);
PT_Symbol PT_getIterSepSeparator(PT_Symbol symbol);

PT_Tree PT_getParseTreeTop(PT_ParseTree parseTree);
PT_ParseTree PT_setParseTreeTop(PT_ParseTree parseTree, PT_Tree top);
ATbool PT_isTreeBracket(PT_Tree tree);
PT_Tree PT_getTreeBracketTree(PT_Tree tree);

PT_Attrs PT_reverseAttrs(PT_Attrs attrs);

PT_CharRanges PT_concatCharRanges(PT_CharRanges ranges1, PT_CharRanges ranges2);

#endif /* _ME_PT_H */ 
