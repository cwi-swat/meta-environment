#ifndef PTMEPT_UTILS_H
#define PTMEPT_UTILS_H

#include <PTMEPT.h>
#include <MEPT.h>

PTPT_ParseTree PTPT_liftParseTree(PT_ParseTree pt);
PTPT_Tree PTPT_liftTree(PT_Tree pt);
PTPT_ATerm PTPT_liftATerm(ATerm trm);

PT_ParseTree PTPT_lowerParseTree(PTPT_ParseTree pt);
PT_Tree PTPT_lowerTree(PTPT_Tree pt);
ATerm PTPT_lowerATerm(PTPT_ATerm trm);

#endif
