/*  $Id$  */

#ifndef _PARSER_H_
#define _PARSER_H_  1

#include "stack.h"

forest SG_Parse(char *path,
                parse_table *pt, char *sort, int(*getchar)(void), 
		size_t length);

void   SG_ZeroStackHist(void);
void   SG_AddStackHist(stack *parent, stack *kid);
void   SG_PropagateReject(stack *st);
void   SG_PropagateUnreject(stack *st);
size_t SG_GetTokensRead(void);
char  *SG_ProdSort(production t);


void SG_PrintStatusBar(char *subject, long part, long whole);
#define SG_PrintDotAndNewLine() if (isatty(fileno(stderr))) { fprintf(stderr, ".\n"); } 

#ifdef DEBUG
void   SG_ShowStackOffspring(stack *);
void   SG_ShowStackAncestors(stack *);
void   SG_ShowStack(stack *st, int depth);
#endif

#endif  /* _PARSER_H_ */
