
#ifndef PTMEPT_UTILS_H
#define PTMEPT_UTILS_H

#include <PTMEPT.h>
#include <MEPT.h>

PTPT_ParseTree PTPT_explodeParseTree(PT_ParseTree pt);
PTPT_Tree      PTPT_explodeTree(PT_Tree pt);
PTPT_ATerm     PTPT_explodeATerm(ATerm trm);

#endif
