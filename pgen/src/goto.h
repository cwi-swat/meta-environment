#ifndef GOTO_H
#define GOTO_H

#include "item.h"

void action_insert(CC_Class *cc2, ATermList elems2);
ATermList insert_item(ATermList items, Item item);

extern int max_gotos;

#endif
