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

#ifndef PREPARATION_H
#define PREPARATION_H

#include <aterm2.h>

typedef struct equation_entry
{
  struct equation_entry *hnext;
  unsigned hashnr;
  ATerm top_ofs;
  ATerm first_ofs;
  ATerm equation;
  ATerm tag;
  ATerm lhs;
  ATerm rhs;
  ATermList conds;
} equation_entry;

typedef struct equation_table
{
  struct equation_table *next;
  ATerm module;
  unsigned size;
  equation_entry **table;
} equation_table;


ATerm RWprepareTerm(ATerm t);
ATermList RWprepareEqs(ATermList eqs);
ATerm RWrestoreTerm(ATerm t);
void RWflushEquations();
ATermList AFfilterLayout(ATermList elems);
ATerm AFremoveTermLayout(ATerm t);

equation_entry *find_equation(equation_entry *prev, 
															ATerm top_ofs, ATerm first_ofs);
void select_equations(char *module);
void enter_equations(char *module, ATermList eqs);
ATbool find_module(char *module);
void delete_equations(char *module);

/* temp debug function */
ATerm text(ATerm asfix);

#endif
