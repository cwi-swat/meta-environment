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

#ifndef _TREE_TO_DOT_H_
#define _TREE_TO_DOT_H_ 1

#include "stack.h"

void SGtreeToDotFile(char *prg, char *fnam, ATerm t, ATbool suppress, 
										 ATbool print_prods);
void SG_StacksToDotFile(stacks *, int);
void SG_StacksToDotFileFinalize(FILE *);
void SG_LinksToDot(FILE *, stack *);

FILE  *SG_StackDot(void);

ATerm      SG_TermYield(ATermAppl);
ATerm      SG_DotTermYield(ATerm);

char      *SG_PrintSymbolToString(ATerm t, ATbool escaped);

#endif  /* _TREE_TO_DOT_H_ */
