#ifndef PT_utils_H
#define PT_utils_H

#include "PT.h"

ATbool PT_isListVar(PT_Tree arg);
ATbool PT_isStarVar(PT_Tree arg);
ATbool PT_isPlusVar(PT_Tree arg);
ATbool PT_isSymbolIter(PT_Symbol arg);


PT_Args PT_concatArgs(PT_Args args1, PT_Args args2);
PT_Args PT_appendArgs(PT_Args args, PT_Tree arg);
int     PT_getArgsLength(PT_Args args);

typedef void* PT_TreeVisitorData;
typedef PT_Tree (*PT_TreeVisitor)(PT_Tree tree, PT_TreeVisitorData data);
PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor,
                             PT_TreeVisitorData data);

typedef void* PT_SymbolVisitorData;
typedef PT_Symbol (*PT_SymbolVisitor)(PT_Symbol symbol, 
                                      PT_SymbolVisitorData data);
PT_Symbols PT_foreachSymbolInSymbols(PT_Symbols symbols, 
                                     PT_SymbolVisitor visitor, 
                                     PT_SymbolVisitorData data);

typedef void* PT_AttrVisitorData;
typedef PT_Attr (*PT_AttrVisitor)(PT_Attr attr, PT_AttrVisitorData data);
PT_Attrs PT_foreachAttrInAttrs(PT_Attrs attrs, PT_AttrVisitor visitor,
                               PT_AttrVisitorData data);

ATbool PT_hasProductionCertainAttr(PT_Production prod, PT_Attr attr);
ATbool PT_hasProductionBracketAttr(PT_Production prod);
ATbool PT_hasProductionMemoAttr(PT_Production prod);
ATbool PT_hasProductionTraverseAttr(PT_Production prod);

PT_Tree PT_removeTreeAnnotations(PT_Tree arg);
ATerm   PT_getTreeAnnotation(PT_Tree arg, ATerm label);

char *PT_yieldParseTree(PT_ParseTree tree);
char *PT_yieldTree(PT_Tree tree);

#endif
