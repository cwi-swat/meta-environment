/*
  %% $Id$

  \section{Graph Structured Stack}
  \label{stack.c}

  \subsection{stack.h}

  \input{stack.htx}

  \subsection{stack.c}

*/

#include <stdlib.h>

#include "parse-table.h"
#include "stack.h"
#include "parser.h"

#include "mem-alloc.h"  /* Note: BOEHM GC caused weird things at one point */


enum STATOP {CLR, DEC, INC, NOP};

#ifdef DEBUG
long SG_AllocStats(int op)
{
  static long count = 0;

  switch(op) {
    case CLR:   count=0L; break;
    case DEC:   count--;  break;
    case INC:   count++;  break;
    case NOP:
    default:              break;
  }
  return count;
}
#else
  #define SG_AllocStats(i)
#endif

stack *SG_NewStack(state s, stack *ancestor) {
  stack *res;

  if((res = SG_Malloc(sizeof(stack))) != NULL) {
SG_AllocStats(INC);
    res->state = s;
    res->parent = ancestor;
    res->kid    = NULL;
    res->links  = NULL;
    res->rejected  = ATfalse;
    res->protected = ATtrue;
  }
  return res;
}

stacks *SG_AddStack(stack *st, stacks *sts) {
  stacks *res;

  if((res = SG_Malloc(sizeof(stacks *))) != NULL) {
    res->head = st;
    res->tail = sts;
  }
  return res;
}

st_link *SG_NewLink(tree t, stack *st) {
  st_link *res;

  if((res = SG_Malloc(sizeof(st_link))) != NULL) {
    res->tree = t;
    ATprotect(&(res->tree));
    res->stack = st;
    res->rejected = ATfalse;
  }
  return res;
}

st_link *SG_AddLink(stack *frm, stack *to, tree t)
{
  st_link *link;

  if((link = SG_NewLink(t, to)) != NULL) {
    frm->links = SG_AddLinks(link, frm->links);
  }
  return link;
}

st_links *SG_AddLinks(st_link *l, st_links *ls)
{
  st_links *res;

  if((res = SG_Malloc(sizeof(st_links))) != NULL) {
    res->head = l;
    res->tail = ls;
  }
  return res;
}


/*
  Using the related stack- and link data structures, a suitable
  method of garbage collection must be performed.

  The parser consists of a number of parallel parsers, which are
  `thrown away' on each shift (and accept).

  When shifting, a new set of parsers is derived; whatever lived
  in the old set of parsers, but not in either the new one or in
  the accepting stack, must be disposed.

  Stacks can be substacks of one another; a simple traversal
  will not do, because it may stumble upon the same (sub)stacks
  multiple times.  For that reason, garbage collection uses the
  classic two `mark' and `sweep' passes.
 */

stacks *SG_PurgeOldStacks(stacks *old, stacks *new, stack *accept)
{
/*
  ATfprintf(stderr,"stack allocs before: %d\n", SG_AllocStats(NOP));
  ATfprintf(stderr,"GC..");
*/
  SG_UnprotectUnusedStacks(old, new, accept);
/*
  ATfprintf(stderr,"..");
*/
  SG_DisposeUnusedStacks(old);
/*
  ATfprintf(stderr,"..\n");
  ATfprintf(stderr,"stack allocs after:  %d\n", SG_AllocStats(NOP));
*/
  return new;
}

/*
  Garbage collection: unprotect (mark) phase
 */

void SG_UnprotectUnusedStacks(stacks *old, stacks *new, stack *accept)
{
  stack *st;

  if(accept != NULL)
    new = SG_AddStack(accept, new);
  while(shift(st, old))
    SG_UnprotectUnusedStack(st, NULL, new);
}

void SG_UnprotectUnusedStack(stack *st, st_link *unprotector, stacks *sts)
{
    if(st->protected                    /*  Done if already unprotected */
    && !SG_InStacks(st, sts, ATtrue)) { /*  as are the living stacks    */
      st_links *lks = SG_ST_LINKS(st);

        st->protected = ATfalse;
        st->unprotector = unprotector;

      /*  The stacks descendants might also have been obsoleted         */
      for (; lks != NULL; lks = tail(lks)) {
        st_link *lk = head(lks);

        SG_UnprotectUnusedStack(SG_LK_STACK(lk), lk, sts);
      }
    }
}


/*
  Garbage collection: disposal (sweep) phase
 */

void SG_DisposeUnusedStacks(stacks *sts)
{
  stack *st;

  while(shift(st, sts)) {
    SG_DisposeUnusedStack(st, NULL);
  }
}

void SG_DisposeUnusedStack(stack *st, st_link *unprotector)
{
    if(!st->protected && (st->unprotector == unprotector)) {
      st_links *lks = SG_ST_LINKS(st);

      for (; lks != NULL; lks = tail(lks)) {
        st_link *lk = head(lks);

        SG_DisposeUnusedStack(SG_LK_STACK(lk), lk);
      }
/*
      ATfprintf(stderr, "Deleting stack %xd, unprotected by %xd\n", st, unprotector);
*/
      SG_DeleteStack(st);
    }
}

stacks *SG_DeleteStacks(stacks *sts)
{
  stack *st;

  while(shift(st, sts))
    SG_DeleteStack(st);
  return NULL;
}

void SG_DeleteStack(stack *st)
{
SG_AllocStats(DEC);
  SG_DeleteLinks(SG_ST_LINKS(st));
  SG_free(st);
}

st_links *SG_DeleteLinks(st_links *lks)
{
  for (; lks != NULL; lks = tail(lks))
    SG_DeleteLink(head(lks));

  return NULL;
}

void SG_DeleteLink(st_link *lk)
{
  ATunprotect(&(lk->tree));
  SG_free(lk);
}


ATbool SG_InStacks(stack *st1, stacks *sts, ATbool deep)
{
  stack *st2;

  while(sts) {
    st2 = head(sts);
    sts = tail(sts);
    if(st1 == st2) return ATtrue;
    if(deep && SG_SubStack(st1, st2)) {
      return ATtrue;
    }
  }
  return ATfalse;
}

ATbool SG_SubStack(stack *st1, stack *st0)
{
  st_link *l;
  st_links *ls;

  if(st0 == NULL || st1 == NULL) return ATfalse;
  if(st1 == st0) {
    return ATtrue;
  }

  ls = SG_ST_LINKS(st0);
  for (; ls != NULL; ls = tail(ls)) {
    l = head(ls);
    if (SG_SubStack(st1, SG_LK_STACK(l))) {
      return ATtrue;
    }
  }
  return ATfalse;
}


/*
   Find a stack with a state |s| in a list of stacks.
*/

stack *SG_FindStack(state s, stacks *sts)
{
  for (; sts != NULL; sts = tail(sts))
    if(SG_ST_STATE(head(sts)) == s) return head(sts);
  return NULL;
}

/*
   Find a direct link from |st0| to |st1|
*/
st_link *SG_FindDirectLink(stack *st0, stack *st1)
{
  st_links *ls = NULL;

  for (ls = SG_ST_LINKS(st0); ls != NULL; ls = tail(ls))
    if(SG_LK_STACK(head(ls)) == st1) return head(ls);
  return NULL;
}


/*
  Mark link of a stack as rejected. (By setting its |has_conds| field
  to |ATtrue|. This is a hack to save space by not declaring another
  node for the representation of stacks!)
*/

void SG_MarkStackRejected(stack *st, st_link *l)
{
  SG_LK_REJECTED(l) = ATtrue;
}

void SG_MarkLinkRejected(stack *st, st_link *l)
{
  SG_LK_REJECTED(l) = ATtrue;
/*
  ATfprintf(stderr, "Link state %d ==> state %d rejected\n",
           SG_ST_STATE(st), SG_ST_STATE(SG_LK_STACK(l)));
*/
}

void SG_MarkLinkRejected2(stack *st, st_link *l)
{
  ATfprintf(stderr, "Warning: link state %d ==> state %d rejected in "
                   "presence of other links\n",
           SG_ST_STATE(st), SG_ST_STATE(SG_LK_STACK(l)));
  SG_MarkLinkRejected(st, l);
}


#ifdef DEBUG
/*
    Is one of the stacks links rejected?
 */
ATbool SG_SomeRejected(stack *st)
{
  st_links *ls = SG_ST_LINKS(st);
  stack *kid;
  st_link *l;
  int count = 0;

  for (; ls != NULL; ls = tail(ls)) {
    l = head(ls);
    if(SG_LK_REJECTED(l)) {
       return ATtrue;
    }
    kid = SG_LK_STACK(l);
    count++;
    if (SG_SomeRejected(kid))
      return ATtrue;
  }
  return ATfalse;
}
#endif /* DEBUG */

/*
  A stack is rejected if all its links are.
*/
ATbool SG_Rejected(stack *st)
{
  st_links *ls;

  if (!(ls = SG_ST_LINKS(st))) return ATfalse;
  for (; ls != NULL; ls = tail(ls)) {
    if(SG_LK_REJECTED(head(ls))) {
      return ATtrue;
    }
  }
  return ATfalse;
}
