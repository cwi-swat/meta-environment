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

extern ATbool traversals_on;

typedef enum { UNDEFINED = 0, TRANSFORMER = 1, ANALYZER = 2 } TraversalType;
typedef struct Traversal_tag {
	TraversalType type;
	ATerm     prod;
	ATermList symbols;
	ATermList args;
} Traversal;

#define ACCUMULATED_POS (keep_layout ? 8 : 4)
#define TRAVERSED_POS (keep_layout ? 4 : 2)
#define TRAVERSED_SYMBOL_POS 4

/* operations  on Traversals */
Traversal create_traversal_pattern(ATerm term);
Traversal update_accumulator(Traversal trav, ATerm newarg);
ATerm     make_traversal_appl(ATerm trm, Traversal traversal);
ATerm     choose_normalform(ATerm term, Traversal trav);
ATerm     select_traversed_arg(ATermList args);


/* rewriting functionality */
ATerm rewrite_traversal(ATerm trm, ATerm env, int depth, Traversal *traversal);
ATermList rewrite_args_traversal(ATermList args, ATerm env, int depth, 
																 Traversal *traversal);
ATermList rewrite_elems_traversal(ATerm sym, ATermList elems, ATerm env, int depth, 
																	Traversal *traversal);

#endif
