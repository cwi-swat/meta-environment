#ifndef FOLLOW_H
#define FOLLOW_H

#include "characters.h"

extern CC_Class **follow_table;

void calc_follow_table();
void destroy_follow_table();

#endif
