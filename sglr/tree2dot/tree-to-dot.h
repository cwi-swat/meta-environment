/* %% $Id$ */

#ifndef _TREE_TO_DOT_H_
#define _TREE_TO_DOT_H_ 1

#include <stack.h>

void SGtreeToDotFile(char *prg, char *fnam, ATerm t, ATbool suppress);
void SG_StacksToDotFile(stacks *, int);
void SG_LinksToDot(FILE *, stack *);

FILE  *SG_StackDot(void);

ATerm      SG_TermYield(ATerm);
ATerm      SG_DotTermYield(ATerm);

#endif  /* _TREE_TO_DOT_H_ */
