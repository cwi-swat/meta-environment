
#ifndef PTMEPT_UTILS_H
#define PTMEPT_UTILS_H

#include <PTMEPT.h>
#include <MEPT.h>


PTPT_TreeList PTPT_reverseTreeList(PTPT_TreeList args);
PTPT_SymbolList PTPT_reverseSymbolList(PTPT_SymbolList args);
PTPT_AttrList PTPT_reverseAttrList(PTPT_AttrList args);
PTPT_CharRangeList PTPT_reverseCharRangeList(PTPT_CharRangeList args);
PTPT_ATermElems PTPT_reverseATermElems(PTPT_ATermElems args);

PTPT_ParseTree PTPT_liftParseTree(PT_ParseTree pt);
PTPT_Tree      PTPT_liftTree(PT_Tree pt);
PTPT_ATerm     PTPT_liftATerm(ATerm trm);

PT_ParseTree PTPT_lowerParseTree(PTPT_ParseTree pt);
PT_Tree      PTPT_lowerTree(PTPT_Tree pt);
ATerm     PTPT_lowerATerm(PTPT_ATerm trm);
#endif
