/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
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
#define SG_PROD_TO_NR(l)    (l-257)
#define SG_NR_TO_PROD(l)    (ATmakeInt(ATgetInt((ATermInt)l)+257))

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
ATermList  SG_CyclicTerm(parse_table *pt, forest t);

tree       SG_FilterTree(parse_table *pt, tree t);
tree       SG_SelectOnTopSort(parse_table *pt, tree t, char *sort); 
forest     SG_YieldTree(parse_table *pt, tree t);
ATerm      SG_AmbTracker(forest t);
tree       SG_Apply(parse_table *, label, ATermList, int attr);
ATerm      SG_TreeType(ATerm);
label      SG_GetProdLabel(tree aprod);
label      SG_GetApplProdLabel(tree applprod);
label      SG_GetRejectProdLabel(tree rejectprod);

#endif  /* _FOREST_H_ */
