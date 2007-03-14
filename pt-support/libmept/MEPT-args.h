#ifndef MEPT_ARGS
#define MEPT_ARGS
#include <MEPT.h>

PT_Args PT_removeArgsLiterals(PT_Args args);
PT_Args PT_removeArgsTree(PT_Args args, PT_Tree tree);
int PT_indexOfTreeInArgs(PT_Args args, PT_Tree tree);

#endif
