/*

    MEPT -- The Meta-Environment Parse Tree library

    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

   $Id$
*/         

#ifndef _ME_PT_H
#define _ME_PT_H

#include <aterm2.h>
#include <deprecated.h>
#include "MEPT.h" 

ATbool PT_prodHasLitAsRhs(PT_Production arg);
ATbool PT_isLexicalProd(PT_Production arg);
ATbool PT_prodHasLexLayoutAsRhs(PT_Production arg);
ATbool PT_prodHasCfLayoutAsRhs(PT_Production arg);
ATbool PT_isOptLayoutProd(PT_Production arg);
ATbool PT_prodHasVarSymAsRhs(PT_Production arg);
ATbool PT_isVarDefault(PT_Production arg);
ATbool PT_isLexicalInjectionProd(PT_Production prod);
ATbool PT_prodHasIterSepAsRhs(PT_Production prod);
ATbool PT_prodHasIterAsRhs(PT_Production prod);
/*
ATbool PT_isProductionList(PT_Production prod);
*/
ATbool PT_isTreeApplList(PT_Tree tree);
ATbool PT_isIterSepSymbol(PT_Symbol sym);
ATbool PT_isIterSymbol(PT_Symbol sym);
ATbool PT_prodHasSTARTAsRhs(PT_Production prod);
ATbool PT_isOptLayoutSymbol(PT_Symbol arg);

PT_Args PT_concatArgs(PT_Args args1, PT_Args args2);
PT_Args PT_appendArgs(PT_Args args, PT_Tree arg);
PT_Args PT_reverseArgs(PT_Args args);
int PT_getArgsLength(PT_Args args);
PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr);
PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr);
PT_Args PT_sliceArgs(PT_Args args, int start, int end);

char *PT_yieldParseTree(PT_ParseTree tree);
char *PT_yieldTree(PT_Tree tree);
char *PT_yieldProduction(PT_Production prod);
char *PT_yieldSymbol(PT_Symbol symbol);

PT_ParseTree implodeParseTree(PT_ParseTree tree);

typedef void* PT_TreeVisitorData;
typedef PT_Tree (*PT_TreeVisitor)(PT_Tree tree, PT_TreeVisitorData data);
PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor,                                           PT_TreeVisitorData data);

typedef void* PT_SymbolVisitorData;
typedef PT_Symbol (*PT_SymbolVisitor)(PT_Symbol symbol,
                                      PT_SymbolVisitorData data);
PT_Symbols PT_foreachSymbolInSymbols(PT_Symbols symbols,
                                     PT_SymbolVisitor visitor,
                                     PT_SymbolVisitorData data); 

PT_ParseTree PT_addParseTreePosInfo(char *pathInfo, PT_ParseTree tree);

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
PT_Symbol PT_getIterSepSeparator(PT_Symbol symbol);

PT_Tree PT_getParseTreeTop(PT_ParseTree parseTree);
PT_ParseTree PT_setParseTreeTop(PT_ParseTree parseTree, PT_Tree top);

#endif /* _ME_PT_H */ 
