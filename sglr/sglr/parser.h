/*
  %% $Id$
*/

#ifndef _PARSER
#define _PARSER

#include "parse-table.h"

ATerm SG_Parse(parse_table *pt, char *sort, int(*getchar)(void));

void SG_ZeroStackHist(void);
void SG_AddStackHist(stack *parent, stack *kid);
void SG_ShowStackOffspring(stack *);
void SG_ShowStackAncestors(stack *);
void SG_PropagateReject(stack *st);

typedef int label;

#endif
