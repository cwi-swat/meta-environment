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
  unsigned size;
  equation_entry **table;
} equation_table;


equation_entry *find_equation(equation_entry *prev, PT_Production top_ofs, 
                              PT_Production first_ofs);
void enter_equations(ASF_CondEquationList eqs);
void print_short_equation(int stack, const char *msg, equation_entry *entry);
void destroy_equation_table();

extern equation_table *equations;


#endif
