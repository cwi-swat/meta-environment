/*
  %% $Id$
*/

#ifndef _PARSER_H_
#define _PARSER_H_  1

#include "stack.h"

ATerm SG_Parse(parse_table *pt, char *sort, int(*getchar)(void));

void SG_ZeroStackHist(void);
void SG_AddStackHist(stack *parent, stack *kid);
void SG_ShowStackOffspring(stack *);
void SG_ShowStackAncestors(stack *);
void SG_PropagateReject(stack *st);
void SG_PropagateUnreject(stack *st);

typedef int label;

extern size_t  sg_numtokens;

#endif  /* _PARSER_H_ */
