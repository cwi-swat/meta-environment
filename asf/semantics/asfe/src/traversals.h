/*

    Meta-Environment - An environment for language prototyping.
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
/*
  $Id$
 */

#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <aterm2.h>
#include <MEPT-utils.h>

extern ATbool traversals_on;

typedef enum { UNDEFINED = 0, TRANSFORMER = 1, ANALYZER = 2 } TraversalType;
typedef struct Traversal_tag {
	TraversalType  type;
	PT_Production  prod;
	PT_Symbols     symbols;
	PT_Args        args;
} Traversal;

#define ACCUMULATED_ARG_POS  8
#define TRAVERSED_ARG_POS    4 
#define TRAVERSED_SYMBOL_POS 4

#define NO_TRAVERSAL NULL

#define selectTraversedArg(args) (selectTree(args, TRAVERSED_ARG_POS))
#define selectAccumulatedArg(args) (selectTree(args, ACCUMULATED_ARG_POS))

/* operations  on Traversals */
Traversal createTraversalPattern(PT_Tree term);
Traversal updateAccumulator(Traversal trav, PT_Tree newarg);
PT_Tree   makeTraversalAppl(PT_Tree trm, Traversal traversal);
PT_Tree   chooseNormalform(PT_Tree term, Traversal trav);
PT_Tree   selectTree(PT_Args args, int pos);

#endif
