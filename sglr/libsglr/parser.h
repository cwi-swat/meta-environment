/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
/*  $Id$  */

#ifndef _PARSER_H_
#define _PARSER_H_  1

#include "stack.h"

forest SG_Parse(parse_table *pt, char *sort, int(*getchar)(void));

void   SG_ZeroStackHist(void);
void   SG_AddStackHist(stack *parent, stack *kid);
void   SG_PropagateReject(stack *st);
void   SG_PropagateUnreject(stack *st);

char  *SG_ProdSort(production t);


void SG_PrintStatusBar(char *subject, long part, long whole);

#ifdef DEBUG
void   SG_ShowStackOffspring(stack *);
void   SG_ShowStackAncestors(stack *);
void   SG_ShowStack(stack *st, int depth);
#endif

#endif  /* _PARSER_H_ */
