#ifndef PT_utils_H
#define PT_utils_H

#include "PT.h"

ATbool PT_isListVar(PT_Tree arg);
ATbool PT_isStarVar(PT_Tree arg);
ATbool PT_isPlusVar(PT_Tree arg);
ATbool PT_isSymbolIter(PT_Symbol arg);


PT_Args PT_concatArgs(PT_Args args1, PT_Args args2);
PT_Args PT_appendArgs(PT_Args args, PT_Tree arg);

typedef PT_Tree (*PT_TreeVisitor)(PT_Tree tree);
PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor);

typedef void* PT_SymbolVisitorData;
typedef PT_Symbol (*PT_SymbolVisitor)(PT_Symbol symbol, 
                                      PT_SymbolVisitorData data);

PT_Tree PT_removeTreeAnnotations(PT_Tree arg);
ATerm   PT_getTreeAnnotation(PT_Tree arg, ATerm label);
int     PT_getArgsLength(PT_Args args);

char      *PT_getStringChars(PT_String ptStr);
PT_String PT_setStringChars(const char* str);


#endif
