#ifndef FIRST_H
#define FIRST_H

extern ATermTable first_table;

ATbool contains_epsilon(ATermList set);
ATermList remove_epsilon(ATermList set);
CC_Class *first_no_epsilon(ATermList symbols);
void init_prod_first(ATerm prod);
void calc_first_table();

CC_Class *get_first_set(ATerm symbol, ATbool create);

void init_first();
void destroy_first();

#endif
