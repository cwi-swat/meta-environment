#ifndef PT_utils_H
#define PT_utils_H

#include "PT.h"

ATbool PT_isListVar(PT_Tree arg);
ATbool PT_isStarVar(PT_Tree arg);
ATbool PT_isPlusVar(PT_Tree arg);
ATbool PT_isSymbolIter(PT_Symbol arg);

PT_Args PT_concatArgs(PT_Args args1, PT_Args args2);

#endif
