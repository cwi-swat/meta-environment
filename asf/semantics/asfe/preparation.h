
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
void select_equations(ATerm module);
void enter_equations(ATerm module, ATermList eqs);

#endif
