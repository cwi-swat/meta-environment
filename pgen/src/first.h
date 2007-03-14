#ifndef FIRST_H
#define FIRST_H

#include <MEPT.h>
#include "characters.h"

extern ATermTable first_table;

ATbool contains_epsilon(ATermList set);
ATermList remove_epsilon(ATermList set);
CC_Class *first_no_epsilon(PT_Symbols symbols);
void init_prod_first(PT_Production prod);
void calc_first_table();

CC_Class *get_first_set(PT_Symbol symbol, ATbool create);

void init_first();
void destroy_first();

#endif
