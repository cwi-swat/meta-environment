/*
  %% $Id$

  \section{Graph Structured Stack}
  \label{stack.c}

  \subsection{stack.h}

  \input{stack.htx}

  \subsection{stack.c}

*/

#include <stdlib.h>

#include "mem-alloc.h"
#include "forest.h"
#include "stack.h"
#include "sglr.h"


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

  if((res = SG_Malloc(sizeof(stack)))) {
    SG_AllocStats(INC);
    res->state = s;
#ifdef DEBUG
    res->parent = ancestor;
#endif
    res->kids      = NULL;
    res->kidcount  = 0;
    res->links     = NULL;
    res->rejected = ATfalse;
    res->protected = ATtrue;
  }
  return res;
}

stacks *SG_AddStack(stack *st, stacks *sts) {
  stacks *res;

  if((res = SG_Malloc(sizeof(stacks)))) {
    res->head = st;
    res->tail = sts;
  }
  return res;
}

st_link *SG_NewLink(tree t, stack *st) {
  st_link *res;

  if((res = SG_Malloc(sizeof(st_link)))) {
    res->tree = t;
    ATprotect(&(res->tree));
    res->stack = st;
/*
    res->rejected = ATfalse;
 */
  }
  return res;
}

st_link *SG_AddLink(stack *frm, stack *to, tree t)
{
  st_link *link;

  if(SG_SubStack(frm, to)) {
    SG_CycleEncountered(SG_CYCLE_ENCOUNTERED);
    if(SG_DEBUG)
      ATfprintf(SGlog(),"Refusing cyclic parse stack creation "
                        "(%d is already a substack of %d)\n",
                frm, to);
    return NULL;
  }

  if((link = SG_NewLink(t, to))) {
    frm->links = SG_AddLinks(link, frm->links);
  }
  return link;
}

st_links *SG_AddLinks(st_link *l, st_links *ls)
{
  st_links *res;

  if((res = SG_Malloc(sizeof(st_links)))) {
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

enum SG_GC_OPS {SG_GC_ADD, SG_GC_CLR};
#define SG_GC_Sweep()   SG_StackCleanupList(SG_GC_CLR, NULL);

stacks *SG_PurgeOldStacks(stacks *old, stacks *new, stack *accept)
{
  SG_MarkStacks(old, new, accept);
  SG_GC_Sweep();
  return new;
}

/*
  Garbage collection: unprotect (mark) phase.

  The old list of stacks is traversed, stacks not reoccurring in
  either the new list of stacks or the accepting stack are marked
  for deletion.

  Also, the old list of stacks itself (which is obsoleted here)
  is deallocated.
 */

void SG_MarkStacks(stacks *old, stacks *new, stack *accept)
{
  stacks *sts;

  if(accept )                    /*  Add the sacred accepting stack  */
    new = SG_AddStack(accept, new);

  while(old) {
    sts = old;
    SG_MarkStack(SG_HEAD(sts), NULL, new);
    old = SG_TAIL(old);
    SG_free(sts);
  }
  if(accept)                    /*  Free this fragment too  */
    SG_free(new);
}

void SG_MarkStack(stack *st, st_link *unprotector, stacks *sts)
{
  if(st && SG_ST_PROTECTED(st)         /*  Done if already unprotected */
   && !SG_InStacks(st, sts, ATtrue)) { /*  or in a living stack        */
     st_links *lks = SG_ST_LINKS(st);

      SG_StackCleanupList(SG_GC_ADD, st);
      st->protected   = ATfalse;

     /*  The stacks descendants might also have been obsoleted         */
     for (; lks; lks = SG_TAIL(lks)) {
       st_link *lk = SG_HEAD(lks);

       SG_MarkStack(SG_LK_STACK(lk), lk, sts);
     }
   }
}


/*  Garbage collection: deallocation (sweep) phase  */

#define SG_GC_CHUNK   64          /*  Stays typically below +- 32  */

void SG_StackCleanupList(int Mode, stack *st)
{
  static size_t size  = 0;
  static size_t count = 0;
  static stack  **gcstacks= NULL;

  switch(Mode) {
    case SG_GC_CLR:
      while(count) {
          count--;
        SG_DeleteStack(gcstacks[count]);
      }
/*
      SG_Free(gcstacks);
      gcstacks = NULL;
      size = 0;
*/
      break;
    case SG_GC_ADD:
      if(!gcstacks) {
        size += SG_GC_CHUNK;
        gcstacks = SG_Malloc(size * sizeof(stack *));
      } else if(count >= size) {
        size += SG_GC_CHUNK;
        gcstacks = SG_Realloc(gcstacks, size * sizeof(stack *));
      }
#ifdef DEBUG
      if(!gcstacks) {
        ATfprintf(stderr, "SG_GC: memory (re)allocation error\n");
        exit(1);
      }
#endif
      gcstacks[count++] = st;
      break;
  }
}

void SG_DeleteStacks(stacks *sts)
{
  stacks *osts;

  while(sts) {
    osts = sts;
    sts = SG_TAIL(sts);
    SG_free(osts);
  }
}

void SG_DeleteStack(stack *st)
{
  st_links *lks = SG_ST_LINKS(st), *curlks;
  st_link  *lk;

  while(lks) {
    lk = SG_HEAD(lks);
    ATunprotect(&(lk->tree));
    curlks = lks;
    lks = SG_TAIL(lks);
    SG_free(curlks);
    SG_free(lk);
  }
  SG_free(st->kids);
  SG_free(st);
}


ATbool SG_InStacks(stack *st1, stacks *sts, ATbool deep)
{
  stack *st0;

  while(sts) {
    st0 = SG_HEAD(sts);
    sts = SG_TAIL(sts);
    if(st1 == st0) return ATtrue;
#if !defined(DETECT_CYCLIC_STACKS)
    if(deep && SG_SubStack(st1, st0)) {
#else
    if(deep && SG_SubStack(st1, st0, ATempty)) {
#endif
      return ATtrue;
    }
  }
  return ATfalse;
}

#if !defined(DETECT_CYCLIC_STACKS)
ATbool SG_SubStack(stack *st1, stack *st0)
{
  st_link *l;
  st_links *ls;

  if(st1 == st0)
    return ATtrue;
  if(!st0 || !st1)
    return ATfalse;

  ls = SG_ST_LINKS(st0);
  for (; ls; ls = SG_TAIL(ls)) {
    l = SG_HEAD(ls);
    if (SG_SubStack(st1, SG_LK_STACK(l))) {
      return ATtrue;
    }
  }
  return ATfalse;
}
#else  /*   Catching cyclic stacks...  */
ATbool SG_SubStack(stack *st1, stack *st0, ATermList visited)
{
  st_link *l;
  st_links *ls;
  ATerm    st0trm;

  if(!st0 || !st1)
    return ATfalse;
  if(st1 == st0)
    return ATtrue;

  st0trm = (ATerm) ATmakeInt((int) st0);
  if(ATindexOf(visited, st0trm, 0) != -1) {
/*
    ATfprintf(stderr, "Cyclic stack!\n", st0trm, st0);
 */
    return ATfalse;
  }
  visited = ATinsert(visited, st0trm);

  ls = SG_ST_LINKS(st0);
  for (; ls; ls = SG_TAIL(ls)) {
    l = SG_HEAD(ls);
    if (SG_SubStack(st1, SG_LK_STACK(l), visited)) {
      return ATtrue;
    }
  }
  return ATfalse;
}
#endif

/*
   Find a stack with a state |s| in a list of stacks.
*/

stack *SG_FindStack(state s, stacks *sts)
{
  for (; sts; sts = SG_TAIL(sts))
    if(SG_ST_STATE(SG_HEAD(sts)) == s)
      return SG_HEAD(sts);
  return NULL;
}

/*
   Find a direct link from |st0| to |st1|
*/
st_link *SG_FindDirectLink(stack *st0, stack *st1)
{
  st_links *ls = NULL;

  for (ls = SG_ST_LINKS(st0); ls; ls = SG_TAIL(ls))
    if(SG_LK_STACK(SG_HEAD(ls)) == st1)
      return SG_HEAD(ls);
  return NULL;
}


/*
  Mark link of a stack as rejected. (By setting its |has_conds| field
  to |ATtrue|. This is a hack to save space by not declaring another
  node for the representation of stacks!)
*/

void SG_MarkStackRejected(stack *st)
{
  if(SG_DEBUG)
    ATfprintf(SGlog(), "Marking stack with state %d as rejected\n", SG_ST_STATE(st));
  st->rejected = ATtrue;
}

#if 0
void SG_MarkStackUnrejected(stack *st)
{
/*
  SG_LK_REJECTED(l) = ATfalse;
 */
  st->rejected = ATfalse;
}

void SG_MarkLinkUnrejected(st_link *l)
{
  SG_LK_REJECTED(l) = ATfalse;
/*
  ATfprintf(stderr, "Link state %d --> state %d rejected\n",
           SG_ST_STATE(st), SG_ST_STATE(SG_LK_STACK(l)));
*/
}

void SG_MarkLinkRejected(st_link *l)
{
  SG_LK_REJECTED(l) = ATtrue;
/*
  ATfprintf(stderr, "Link state %d --> state %d rejected\n",
           SG_ST_STATE(st), SG_ST_STATE(SG_LK_STACK(l)));
*/
}
#endif

#if 0
/*
    Is one of the stacks links rejected?
 */
ATbool SG_SomeRejected(stack *st)
{
  st_links *ls = SG_ST_LINKS(st);
  stack *kid;
  st_link *l;
  int count = 0;

  for (; ls; ls = SG_TAIL(ls)) {
    l = SG_HEAD(ls);
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
#endif

ATbool SG_Rejected(stack *st)
{
  return SG_ST_REJECTED(st);
/*
  st_links *ls;

  if (!(ls = SG_ST_LINKS(st))) return ATfalse;
  for (; ls; ls = SG_TAIL(ls)) {
    if(SG_LK_REJECTED(SG_HEAD(ls))) {
      return ATtrue;
    }
  }
  return ATfalse;
 */
}

/*
  Is the stack, and are all of the stacks a stack links to, rejected?
*/
ATbool SG_DeeplyRejected(stack *st)
{
  st_links *ls;

  if(!SG_ST_REJECTED(st))
    return ATfalse;

  if (!(ls = SG_ST_LINKS(st)))	/*  No links, so no unrejected ones too  */
    return ATtrue;

  for (; ls; ls = SG_TAIL(ls)) {
    if(!SG_ST_REJECTED(SG_LK_STACK(SG_HEAD(ls)))) {
      return ATfalse;		/*  Found an unrejected direct substack  */
    }
  }
  return ATtrue;
}
