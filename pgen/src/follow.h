/* $Id$ */

#ifndef FOLLOW_H
#define FOLLOW_H

#include "characters.h"

void calc_follow_table();
CC_Class *PGEN_getFollowSet(int prodNumber);
void destroy_follow_table();

#endif
