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

#include <aterm2.h>

ATerm make_traversal_appl(ATerm trm, ATerm traversal);
ATerm create_traversal_pattern(ATerm prod);
ATerm change_traversal_appl(ATerm analyzer, ATerm newarg);
ATerm choose_normalform(ATerm term, ATerm traversal);
ATerm select_traversed_arg(ATermList args);

#define is_analyzer(t) ATmatch(t,"analyzer(<term>)", NULL)
#define is_traversal(t) ATmatch(t,"traversal(<term>)", NULL)
#define is_combination(t) ATmatch(t,"combination(<term>,tuple(<term>))",NULL,NULL)
ATbool is_traversal_prod(ATerm prod);

ATerm get_first(ATerm tuple, ATerm combination);
ATerm get_second(ATerm tuple, ATerm combination);

ATerm rewrite_traversal(ATerm trm, ATerm env, int depth, ATerm *traversal);
ATermList rewrite_args_traversal(ATermList args, ATerm env, int depth, 
																 ATerm *traversal);
ATermList rewrite_elems_traversal(ATerm sym, ATermList elems, ATerm env, int depth, 
																	ATerm *traversal);


