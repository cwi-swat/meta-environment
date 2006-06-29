/* $Id$ */

/** 
 * \mainpage 
 *
 * pt-support contains data-structures for parse tree and parse forest
 * manipulations. 
 *
 * \section Usage Usage
 *
 * SGLR produces parse trees using \ref MEPT.h "MEPT.h". You can use the 
 * API to traverse these trees. The API can also be used to produce trees
 * that look exactly like they have been constructed by SGLR. Tools that
 * use this API are rewriters, structure editors, parse tree visualizers,
 * fact extractors, etc.
 *
 * The parse tree format is constructed from:
 * 1. An abstract representation of SDF productions.
 * 2. Tree and forest construction nodes (with productions in each node).
 * 3. ASCII character values as leafs.
 *
 * \section Files Important files
 * \ref MEPT.h 
 *
 * \ref MEPT-utils.h 
 *
 * \ref PTMEPT.h 
 *
 * \ref PTMEPT-utils.h 
 *
 * \section Tools Tools
 *
 * A number of important ToolBus and commandline tools are located in
 * \ref utils:
 *
 * unparsePT: yields the characters of a parse tree
 *
 * liftPT: lifts a parse tree to a parse tree of a parse tree, or vice versa
 *
 * implodePT: maps a parse tree to a more abstract ATerm (abstract syntax tree)
 *
 * addPosInfo: add position annotations to each sub-tree
 *
 * ambtracker: prints a report of all ambiguities in a parse forest
 *
 * unparseProd: maps the AsFix representation of a production to the SDF presentation.
 */

#ifndef _ME_PT_H
#define _ME_PT_H

/**
 * \file 
 * Contains all reusable high level operations on parse trees and forests.
 * The mostly used function is PT_yieldTree() for yielding the characters
 * of a parse tree to a string.
 *
 */

#include <aterm2.h>
#include <deprecated.h>
#include "MEPT.h"
#include <Location.h>

int PT_compareTree(PT_Tree tree1, PT_Tree tree2, ATbool modAmbOrdering, ATbool modLayout);

PT_Tree PT_removeTreeAllLayoutAndAnnotations(PT_Tree tree);
PT_Tree PT_applyFunctionToArgs(const char *function, const char *sort,
			       PT_Args args);
PT_ParseTree PT_applyFunctionToArgsParseTree(const char *function,
					     const char *sort, PT_Args args);
PT_Tree PT_applyFunctionToTree(const char *function, const char *sort,
			       int nArgs, ...);
PT_Tree PT_applyFunction(const char* function, PT_Symbol rhs, PT_Args args,
			 PT_Attributes attributes);

PT_ParseTree PT_makeValidParseTreeFromTree(PT_Tree tree);
PT_ParseTree PT_makeParseTreeTree(PT_Symbols lhs, PT_Tree wsBefore,
				  PT_Tree tree, PT_Tree wsAfter, int ambs);
PT_Tree PT_getParseTreeTree(PT_ParseTree parsetree);
PT_Tree PT_getParseTreeLayoutBeforeTree(PT_ParseTree parsetree);
PT_Tree PT_getParseTreeLayoutAfterTree(PT_ParseTree parsetree);
PT_ParseTree PT_setParseTreeTree(PT_ParseTree parsetree, PT_Tree tree);
PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree parsetree,
					     PT_Tree tree);
PT_ParseTree PT_setParseTreeLayoutAfterTree(PT_ParseTree parsetree,
					    PT_Tree tree);

ATbool PT_prodHasLitAsRhs(PT_Production arg);
ATbool PT_isLexicalProd(PT_Production arg);
ATbool PT_prodHasLexLayoutAsRhs(PT_Production arg);
ATbool PT_prodHasCfLayoutAsRhs(PT_Production arg);
ATbool PT_isOptLayoutProd(PT_Production arg);
ATbool PT_prodHasVarSymAsRhs(PT_Production arg);
ATbool PT_isLexicalInjectionProd(PT_Production prod);
ATbool PT_isProductionVariable(PT_Production arg);
ATbool PT_isProductionInjection(PT_Production prod);
ATbool PT_prodHasIterSepAsRhs(PT_Production prod);
ATbool PT_prodHasIterAsRhs(PT_Production prod);

ATbool PT_isTreeApplList(PT_Tree tree);
ATbool PT_isTreeAlt(PT_Tree tree);
ATbool PT_isTreeLit(PT_Tree tree);
ATbool PT_isTreeCilit(PT_Tree tree);
ATbool PT_isTreeSeq(PT_Tree tree);
ATbool PT_isTreeOpt(PT_Tree tree);
ATbool PT_isIterSepSymbol(PT_Symbol sym);
ATbool PT_isIterSymbol(PT_Symbol sym);
ATbool PT_prodHasSTARTAsRhs(PT_Production prod);
ATbool PT_isOptLayoutSymbol(PT_Symbol arg);
PT_Symbol PT_makeOptLayoutSymbol();

PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr);
PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr);
PT_Args PT_makeArgsSingle(PT_Tree arg);

PT_Args PT_removeArgsLiterals(PT_Args args);

char *PT_yieldProduction(PT_Production prod);
char *PT_yieldSymbol(PT_Symbol symbol);
char *PT_yieldSymbolVisualVariables(PT_Symbol symbol);

ATerm PT_reportTreeAmbiguities(const char *path, PT_Tree tree);
ATerm PT_reportParseTreeAmbiguities(const char *path, PT_ParseTree parsetree);

PT_Tree PT_findTopAmbiguity(PT_Tree tree);

void PT_initAsFix2Api();
PT_ParseTree flattenPT(PT_ParseTree tree);
PT_Tree flattenTree(PT_Tree tree);

ATerm PT_implodeParseTree(PT_ParseTree tree,
			  ATbool _interpret_cons,
			  ATbool _remove_layout,
			  ATbool _remove_literals,
			  ATbool _remove_injections,
			  ATbool _remove_parsetree,
			  ATbool _implode_lexicals,
			  ATbool _keep_annotations,
			  ATbool _interpret_alt,
			  ATbool _interpret_seq,
			  ATbool _interpret_opt,
			  ATbool _interpret_layout_place_holder);

typedef void *PT_TreeVisitorData;
typedef PT_Tree(*PT_TreeVisitor) (PT_Tree tree, PT_TreeVisitorData data);
PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor,
			     PT_TreeVisitorData data);

typedef void *PT_SymbolVisitorData;
typedef PT_Symbol(*PT_SymbolVisitor) (PT_Symbol symbol,
				      PT_SymbolVisitorData data);
PT_Symbols PT_foreachSymbolInSymbols(PT_Symbols symbols,
				     PT_SymbolVisitor visitor,
				     PT_SymbolVisitorData data);

PT_ParseTree PT_addParseTreePosInfoSome(const char *path,
					PT_ParseTree parsetree, int depth,
					ATbool layout, ATbool literals);
PT_ParseTree PT_addParseTreePosInfo(const char *pathInfo, PT_ParseTree tree);
PT_ParseTree PT_addParseTreePosInfoToDepth(const char *pathInfo,
					   PT_ParseTree tree, int maxDepth);
PT_Tree PT_addTreePosInfoToDepth(const char *pathInfo, PT_Tree tree,
				 int maxDepth, int start_line, int start_col);
PT_Tree PT_addTreePosInfoSome(const char *path, PT_Tree tree, int depth,
			      ATbool layout, ATbool literals, int start_line,
			      int start_col);
ATbool PT_hasTreeLocation(PT_Tree tree);
LOC_Location PT_getTreeLocation(PT_Tree tree);
PT_Tree PT_removeTreeLocation(PT_Tree tree);
ATbool PT_getTreePosInfo(PT_Tree tree, char **path, int *start_line,
			 int *start_col, int *end_line, int *end_col);


ATerm PT_getTreeAnnotations(PT_Tree tree);
PT_Tree PT_setTreeAnnotations(PT_Tree tree, ATerm annos);
ATerm PT_getParseTreeAnnotations(PT_ParseTree tree);
ATerm PT_getTreeAnnotation(PT_Tree tree, ATerm key);
PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value);
PT_Tree PT_annotateTreeWithLength(PT_Tree tree);
PT_ParseTree PT_annotateParseTreeWithLength(PT_ParseTree parse_tree);
int PT_getParseTreeLengthAnno(PT_ParseTree parse_tree);
int PT_getTreeLengthAnno(PT_Tree tree);
PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length);
PT_ParseTree PT_setParseTreeLengthAnno(PT_ParseTree parse_tree, int length);

ATbool PT_isTreeLexical(PT_Tree tree);
ATbool PT_isTreeLexicalInjection(PT_Tree tree);

PT_Tree PT_makeTreeLayoutEmpty();
ATbool PT_isTreeLayout(PT_Tree tree);
PT_Tree PT_makeTreeLayoutNonEmpty(PT_Args args);
PT_Tree PT_makeTreeLayoutFromString(const char *str);

PT_Tree PT_makeTreeLexToCf(PT_Symbol sym, PT_Tree tree);
PT_Tree PT_makeTreeLit(const char* string);
PT_Tree PT_makeTreeCilit(const char* string);

PT_Tree PT_removeTreeAnnotations(PT_Tree arg);

ATbool PT_isTreeVar(PT_Tree tree);
ATbool PT_isTreeVarList(PT_Tree tree);
ATbool PT_isTreeVarListStar(PT_Tree tree);
ATbool PT_isTreeVarListPlus(PT_Tree tree);

typedef void *PT_AttrVisitorData;
typedef PT_Attr(*PT_AttrVisitor) (PT_Attr attr, PT_AttrVisitorData data);
PT_Attrs PT_foreachAttrInAttrs(PT_Attrs attrs, PT_AttrVisitor visitor,
			       PT_AttrVisitorData data);


ATbool PT_hasProductionCertainAttr(PT_Production prod, PT_Attr attr);
ATbool PT_hasProductionBracketAttr(PT_Production prod);
ATbool PT_hasProductionMemoAttr(PT_Production prod);
ATbool PT_hasProductionLexicalConstructorAttr(PT_Production prod);
ATbool PT_hasProductionConstructorAttr(PT_Production prod);
ATbool PT_hasProductionTraversalAttribute(PT_Production prod);

PT_Symbol makeSymbolAllChars();
PT_Tree PT_makeTreeFlatLexical(PT_Args charList);
PT_Tree PT_makeTreeFlatLexicalFromString(const char *str);
ATbool PT_isTreeFlatLexical(PT_Tree tree);
PT_Symbol PT_getIterSepSeparator(PT_Symbol symbol);

PT_Tree PT_getParseTreeTop(PT_ParseTree parseTree);
PT_ParseTree PT_setParseTreeTop(PT_ParseTree parseTree, PT_Tree top);
ATbool PT_isTreeBracket(PT_Tree tree);
PT_Tree PT_getTreeBracketTree(PT_Tree tree);

PT_Tree PT_renameInTree(PT_Tree tree, PT_Symbol formalParam,
			PT_Symbol actualParam);
PT_ParseTree PT_renameInParseTree(PT_ParseTree parsetree,
				  PT_Symbol formalParam,
				  PT_Symbol actualParam);

PT_Tree PT_findTreeAtOffset(PT_Tree tree, int offset);
PT_Tree PT_findTreeAtLineColumn(PT_Tree tree, int line, int column);

PT_Args PT_findArgsWithLocation(PT_Args args);
PT_Tree PT_findTreeParent(PT_Tree needle, PT_Tree haystack);

PT_Tree PT_promotePosInfoToOrigin(PT_Tree tree);
LOC_Location PT_getTreeOrigin(PT_Tree tree);

unsigned long PT_getTreeLength(PT_Tree tree);

char *PT_yieldTree(PT_Tree tree);
char *PT_yieldTreeToString(PT_Tree tree, ATbool yieldAllAmbiguities);
char *PT_yieldArgsToString(PT_Args args, ATbool yieldAllAmbiguities);
char *PT_yieldParseTreeToString(PT_ParseTree pt, ATbool yieldAllAmbiguities);
char *PT_yieldAnyToString(ATerm t, ATbool yieldAllAmbiguities);

void PT_yieldTreeToFile(PT_Tree tree, FILE *f, ATbool yieldAllAmbiguities);
void PT_yieldArgsToFile(PT_Args args, FILE *f, ATbool yieldAllAmbiguities);
void PT_yieldParseTreeToFile(PT_ParseTree pt, FILE *f, ATbool yieldAllAmbiguities);
void PT_yieldAnyToFile(ATerm t, FILE *f, ATbool yieldAllAmbiguities);

PT_ParseTree PT_replaceParseTreeLayout(PT_ParseTree tree, PT_Tree layout);
PT_Tree PT_replaceTreeLayout(PT_Tree tree, PT_Tree layout);

ATbool PT_subsetOfCharClass(PT_Symbol smaller, PT_Symbol larger);
ATbool PT_elementOfCharClass(PT_Tree character, PT_Symbol charClass);

#endif /* _ME_PT_H */
