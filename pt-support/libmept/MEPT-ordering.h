#ifndef MEPT_ORDERING
#define MEPT_ORDERING
#include <MEPT.h>
#include <aterm2.h>

int PT_compareTree(PT_Tree tree1, PT_Tree tree2, ATbool modLayout);
PT_Tree PT_orderAmbiguities(PT_Tree input);

#endif
