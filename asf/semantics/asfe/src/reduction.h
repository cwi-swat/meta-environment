#ifndef REDUCTION_H
#define REDUCTION_H
#include <MEPT.h>
#include <aterm2.h>

PT_Tree rewrite(PT_Tree trm);
PT_Tree rewriteRecursive(PT_Tree trm, ATerm env, int depth, void* extra);
PT_Tree rewriteInnermost(PT_Tree trm, ATerm env, int depth, void *extra);

#endif
