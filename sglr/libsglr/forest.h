/*
 $Id$

 Parse forests

 The parser maintains a compact representation of a set of parse trees
 in the form of a parse forest. We use the generic terms to represent
 these.

 Parse forests are constructed using the functions |SG_Apply|, and
 |SG_Amb|. |SG_Apply| denotes the application of a function to a list
 of arguments.  The function |SG_Amb| actually constructs forests, by
 maintaining a lookup structure that maps terms onto sets of terms: an
 ambiguity cluster.
 */

#ifndef _FOREST_H_
#define _FOREST_H_  1

#include  "parser.h"

typedef   ATermTable      multiset;

#define SG_IS_MARKED(t)     IS_MARKED(t->header)
#define SG_MARK(t)          SET_MARK(t->header)
#define SG_UNMARK(t)        CLR_MARK(t->header)

enum SG_AmbTblKind { SG_AMBTBL_INIT, SG_AMBTBL_CLEAR, SG_AMBTBL_GET,
    SG_AMBTBL_ADD_INDEX, SG_AMBTBL_ADD_CLUSTER,
    SG_AMBTBL_UPDATE_INDEX, SG_AMBTBL_UPDATE_CLUSTER,
    SG_AMBTBL_LOOKUP_INDEX, SG_AMBTBL_LOOKUP_CLUSTER,
    SG_AMBTBL_REMOVE, SG_AMBTBL_DUMP };

ATerm      SG_AmbTable(int Mode, ATerm key, ATerm value);

int        SG_InjectionFilterSucceeded(int mode);
int        SG_MultiSetFilterSucceeded(int mode);
int        SG_InjectionCountCalls(int Mode);
int        SG_MultiSetGtrCalls(int Mode);
int        SG_AmbCalls(int Mode);

int        SG_MaxNrAmb(int Mode);

void       SG_Amb(parse_table *, tree, tree);

enum       SG_CYCLEMODE { SG_CYCLE_ENCOUNTERED, SG_CYCLE_RESET };
ATbool     SG_CycleEncountered(int Mode);
ATermList  SG_CyclicTerm(forest t);

forest     SG_ExpandApplNode(parse_table * pt, forest t, ATbool recurse,
                             ATbool doambs);
forest     SG_YieldPT(parse_table *pt, forest t);
tree       SG_Apply(parse_table *, label, ATermList, int attr, ATerm pi);
ATerm      SG_TreeType(ATerm);
label      SG_GetProdLabel(tree aprod);
label      SG_GetApplProdLabel(tree applprod);
label      SG_GetRejectProdLabel(tree rejectprod);

#endif  /* _FOREST_H_ */
