#ifndef MATCHING_H
#define MATCHING_H

#include <aterm2.h>
#include <MEPT.h>
#include <ASFME.h>
#include "equations.h"

ATerm matchEquation(equation_entry *entry, PT_Tree trm, int depth);
ATerm matchConditions(ASF_ASFConditionList conds, ATerm env, int depth);
#endif
