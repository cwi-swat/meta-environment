/*
  %% $Id$
  %% Parse forests

   The parser maintains a compact representation of a set of parse
   trees in the form of a parse forest. We use the generic terms to
   represent these.

   Parse forests are constructed using the functions |apply|, |NULL|,
   |cons| and |amb|. |apply| denotes the application of a function to
   a list of arguments. |NULL| denotes the empty list of
   arguments.|cons| adds a term in front of a list. The function |amb|
   actually constructs forests. It takes two trees and creates an
   ambiguous node \emph{at the same address as the first tree}. This
   means that all trees with a pointer to the first tree will share
   the newly created ambiguous node.

*/

#ifndef _FOREST_H_
#define _FOREST_H_  1

#include  "parser.h"

/*
    The following #defines are TEMPORARY, until there's a true
    interface (sort of) to access the internal `mark' bit in aterms
    we're abusing here
*/

/* Taken from @ATERMDIST@/aterm/encoding.h
#define MASK_MARK         (1<<1)
#define IS_MARKED(h)      ((h) &   MASK_MARK)
#define SET_MARK(h)       ((h) |=  MASK_MARK)
#define CLR_MARK(h)       ((h) &= ~MASK_MARK)
 */
#define SG_IS_MARKED(t)     IS_MARKED(t->header)
#define SG_MARK(t)   	    SET_MARK(t->header)
#define SG_UNMARK(t)        CLR_MARK(t->header)
/*   End of TEMPORARY hack */



#define SG_APPLLABEL    "#"
#define SG_REJECTLABEL  "X"

enum SG_AmbTblKind { SG_AMBTBL_INIT, SG_AMBTBL_CLEAR, SG_AMBTBL_GET,
                     SG_AMBTBL_ADD_INDEX, SG_AMBTBL_ADD_CLUSTER,
                     SG_AMBTBL_UPDATE_INDEX, SG_AMBTBL_UPDATE_CLUSTER,
                     SG_AMBTBL_LOOKUP_INDEX, SG_AMBTBL_LOOKUP_CLUSTER,
                     SG_AMBTBL_REMOVE, SG_AMBTBL_DUMP};

ATerm      SG_AmbTable(int Mode, ATerm key, ATerm value);
int        SG_MaxNrAmb(int Mode);
AFun       SG_ApplAFun(void);
AFun       SG_AprodAFun(void);
AFun       SG_AmbAFun(void);

void       SG_Amb(parse_table *, ATermAppl, ATermAppl);

enum  SG_CYCLEMODE { SG_CYCLE_ENCOUNTERED, SG_CYCLE_RESET } ;
ATbool     SG_CycleEncountered(int Mode);
ATermList  SG_CyclicTerm(ATerm t);

ATermAppl  SG_ExpandApplNode(parse_table * pt, ATermAppl t,
                             ATbool recurse, ATbool doambs);
ATerm      SG_YieldPT(parse_table *pt, ATerm t);
ATerm      SG_ApplLabel(void);
ATerm      SG_AprodlLabel(void);
ATerm      SG_RejectLabel(void);
ATerm      SG_Apply(parse_table *, label, ATermList, ATbool);
ATerm      SG_TreeType(ATerm);
ATermInt   SG_GetApplProdLabel(ATermAppl applprod);
ATermInt   SG_GetProdLabel(ATermAppl aprod);

ATerm      SG_TermYield(ATerm);
ATerm      SG_DotTermYield(ATerm);

#endif  /* _FOREST_H_ */
