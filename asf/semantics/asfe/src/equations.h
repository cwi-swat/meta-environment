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
#include <MEPT-utils.h>
#include <ASFME.h>

typedef struct equation_entry
{
  struct equation_entry *hnext;
  unsigned hashnr;

  ASF_Tag tag;
  ASF_CondEquation equation;
  ASF_ConditionList conds;

  PT_Production top_ofs;
  PT_Production first_ofs;

  ATerm posinfo_equals;

  PT_Tree lhs;
  PT_Tree rhs;
} equation_entry;

extern equation_entry *currentRule;

typedef struct equation_table
{
  struct equation_table *next;
  ATerm module;
  unsigned size;
  equation_entry **table;
} equation_table;


equation_entry *find_equation(equation_entry *prev, PT_Production top_ofs, 
                              PT_Production first_ofs);
void enter_equations(char *module, ASF_CondEquationList eqs);
void delete_equations(char *module);
void select_equations(char *module);
void print_short_equation(int stack, const char *msg, equation_entry *entry);

extern equation_table *equations;


#endif
