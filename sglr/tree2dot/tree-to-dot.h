/* %% $Id$ */

#ifndef _TREE_TO_DOT_H_
#define _TREE_TO_DOT_H_ 1

#include <stack.h>

void SG_StacksToDotFile(stacks *, int);
void SG_LinksToDot(FILE *, stack *);

FILE  *SG_StackDot(void);

#endif  /* _TREE_TO_DOT_H_ */
