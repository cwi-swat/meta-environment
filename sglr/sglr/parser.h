/*
  %% $Id$
*/

#ifndef _PARSER
#define _PARSER

#include <TB.h>
#include "parse-table.h"

term *parse(parse_table *lr, int(*getchar)(void));

void zero_stack_hist(void);
void add_stack_hist(stack *parent, stack *kid);
void show_stack_hist(void);
void propagate_reject(stack *st);

typedef int label;

#endif
