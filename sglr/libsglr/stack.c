/*
 $Id$
 */

#include <stdlib.h>

#include "mem-alloc.h"
#include "forest.h"
#include "stack.h"
#include "sglr.h"


#ifdef  MEMSTATS
/*
 For keeping score of memory allocation...
 */

size_t  sg_maxnum_stacks, sg_maxnum_stack, sg_maxnum_link, sg_maxnum_links;
size_t  sg_num_stacks, sg_num_stack, sg_num_links, sg_num_link;


void SG_ZeroAllocStats(void)
{
  sg_maxnum_stacks = sg_maxnum_stack = sg_maxnum_link = sg_maxnum_links =
  sg_num_stacks = sg_num_stack = sg_num_link = sg_num_links = 0;
}

void SG_MaxAllocStats(void)
{
  IF_STATISTICS(
    sg_maxnum_stacks = SG_MAX(sg_num_stacks, sg_maxnum_stacks);
    sg_maxnum_stack  = SG_MAX(sg_num_stack,  sg_maxnum_stack);
    sg_maxnum_links  = SG_MAX(sg_num_links,  sg_maxnum_links);
    sg_maxnum_link   = SG_MAX(sg_num_link,   sg_maxnum_link);
  );
}

void SG_PrintCurAllocStats(void)
{
  size_t total = 0, this;

  IF_STATISTICS(
    fprintf(SGlog(), "Current memory items used:\n\t"
            "datatype      number    sizeof()   subtotal\n");

    this = sg_num_stacks * sizeof(stacks); total += this;
    fprintf(SGlog(), "\tstack lists  %8.8ld * %6.6ld  == %8.8ld\n",
            (long) sg_num_stacks, (long) sizeof(stacks), (long) this);

    this = sg_num_stack * sizeof(stack); total += this;
    fprintf(SGlog(), "\tstacks       %8.8ld * %6.6ld  == %8.8ld\n",
            (long) sg_num_stack, (long) sizeof(stack), (long) this);

    this = sg_num_links * sizeof(st_links); total += this;
    fprintf(SGlog(), "\tlink lists   %8.8ld * %6.6ld  == %8.8ld\n",
            (long) sg_num_links, (long) sizeof(st_links), (long) this);

    this = sg_num_link * sizeof(st_link); total += this;
    fprintf(SGlog(), "\tlinks        %8.8ld * %6.6ld  == %8.8ld\n",
            (long) sg_num_link, (long) sizeof(st_link), (long) this);

    fprintf(SGlog(), "\ttotal                              %8.8ld\n", (long) total);
  );
}

void SG_PrintMaxAllocStats(void)
{
  size_t total = 0, this;

  IF_STATISTICS(
    fprintf(SGlog(), "Maximum %smemory items used:\n\t"
            "datatype      number    sizeof()   subtotal\n",
            SG_GC?"":"(and current; gc is disabled) ");

    this = sg_maxnum_stacks * sizeof(stacks); total += this;
    fprintf(SGlog(), "\tstack lists  %8.8ld * %6.6ld  == %8.8ld\n",
            (long) sg_maxnum_stacks, (long) sizeof(stacks), (long) this);

    this = sg_maxnum_stack * sizeof(stack); total += this;
    fprintf(SGlog(), "\tstacks       %8.8ld * %6.6ld  == %8.8ld\n",
            (long) sg_maxnum_stack, (long) sizeof(stack), (long) this);

    this = sg_maxnum_links * sizeof(st_links); total += this;
    fprintf(SGlog(), "\tlink lists   %8.8ld * %6.6ld  == %8.8ld\n",
            (long) sg_maxnum_links, (long) sizeof(st_links), (long) this);

    this = sg_maxnum_link * sizeof(st_link); total += this;
    fprintf(SGlog(), "\tlinks        %8.8ld * %6.6ld  == %8.8ld\n",
            (long) sg_maxnum_link, (long) sizeof(st_link), (long) this);

    fprintf(SGlog(), "\ttotal                              %8.8ld\n", (long) total);
  );
}
#endif /*  MEMSTATS  */


#define SG_POOL_ALLOC

#ifdef SG_POOL_ALLOC

#define SG_MEMCHUNK       64
#define SG_STACKMEMCHUNK  (4*SG_MEMCHUNK)
#define SG_STACKSMEMCHUNK (1*SG_MEMCHUNK)
#define SG_LINKMEMCHUNK   (8*SG_MEMCHUNK)
#define SG_LINKSMEMCHUNK  (8*SG_MEMCHUNK)

stack    *sg_stack_pool_free = NULL;
stacks   *sg_stacks_pool_free = NULL;
st_link  *sg_link_pool_free = NULL;
st_links *sg_links_pool_free = NULL;

void SG_FreeStack(stack *st)
{
  st->links = (st_links *) sg_stack_pool_free;
  sg_stack_pool_free = st;
}

void SG_FreeStacks(stacks *sts)
{
  sts->tail = sg_stacks_pool_free;
  sg_stacks_pool_free = sts;
}

void SG_FreeLink(st_link *lk)
{
  lk->stack = (stack *) sg_link_pool_free;
  sg_link_pool_free = lk;
}

void SG_FreeLinks(st_links *lks)
{
  lks->tail = sg_links_pool_free;
  sg_links_pool_free = lks;
}

#ifdef SG_GENERIC_POOL_ALLOC
list *SG_MallocPool(list **free_list, size_t dtsize, size_t chunksize)
{
  list *lst;

  if(*free_list == NULL) {
    /*  When out of free items, allocate a new chunk of 'em  */
    list **pool;
    register int i;
    pool = SG_Malloc(chunksize, dtsize);
    pool[0] = (list *) pool;
    for(i=1; i<chunksize; i++) {
      pool[i] = pool[i-1]->tail = (list *) ((size_t)pool[i-1] + (size_t)dtsize);
    }
    pool[chunksize-1]->tail = NULL;
    *free_list = *pool;
  }
  lst = *free_list;
  *free_list = (*free_list)->tail;

  return lst;
}

#define SG_MallocStack()  (stack *)    SG_MallocPool((list **)&sg_stack_pool_free, sizeof(stack),    SG_STACKMEMCHUNK)
#define SG_MallocStacks() (stacks *)   SG_MallocPool((list **)&sg_stacks_pool_free, sizeof(stacks),   SG_STACKSMEMCHUNK)
#define SG_MallocLink()   (st_link *)  SG_MallocPool((list **)&sg_link_pool_free, sizeof(st_link),  SG_LINKMEMCHUNK)
#define SG_MallocLinks()  (st_links *) SG_MallocPool((list **)&sg_links_pool_free, sizeof(st_links), SG_LINKSMEMCHUNK)
#else
stack *SG_MallocStack(void)
{
  stack *st;

  if(sg_stack_pool_free == NULL) {
    /*  When out of free items, allocate a new chunk of 'em  */
    stack **pool;
    register int i;
    pool = SG_Malloc(SG_STACKMEMCHUNK, sizeof(stack));
    pool[0] = (stack *) pool;
    for(i=1; i< SG_STACKMEMCHUNK; i++) {
      pool[i]
      = (stack *) pool[i-1]->links
      = (st_link *) ((size_t)pool[i-1] + (size_t)sizeof(stack));
    }
    pool[SG_STACKMEMCHUNK-1]->links = NULL;
    sg_stack_pool_free = *pool;
  }
  st = sg_stack_pool_free;
  sg_stack_pool_free = (stack *) sg_stack_pool_free->links;

  return st;
}

stacks *SG_MallocStacks(void)
{
  stacks *sts;

  if(sg_stacks_pool_free == NULL) {
    /*  When out of free items, allocate a new chunk of 'em  */
    stacks **pool;
    register int i;
    pool = SG_Malloc(SG_STACKMEMCHUNK, sizeof(stacks));
    pool[0] = (stacks *) pool;
    for(i=1; i< SG_STACKSMEMCHUNK; i++) {
      pool[i]
      = pool[i-1]->tail
      = (stacks *) ((size_t)pool[i-1] + (size_t)sizeof(stacks));
    }
    pool[SG_STACKSMEMCHUNK-1]->tail = NULL;
    sg_stacks_pool_free = *pool;
  }
  sts = sg_stacks_pool_free;
  sg_stacks_pool_free = sg_stacks_pool_free->tail;

  return sts;
}

st_link *SG_MallocLink(void)
{
  st_link *lk;

  if(sg_link_pool_free == NULL) {
    /*  When out of free items, allocate a new chunk of 'em  */
    st_link **pool;
    register int i;
    pool = SG_Malloc(SG_LINKMEMCHUNK, sizeof(st_link));
    pool[0] = (st_link *) pool;
    for(i=1; i< SG_LINKMEMCHUNK; i++) {
      pool[i]
      = (st_link *) pool[i-1]->stack
      = (stack *) ((size_t)pool[i-1] + (size_t)sizeof(st_link));
    }
    pool[SG_LINKMEMCHUNK-1]->stack = NULL;
    sg_link_pool_free = *pool;
  }
  lk = sg_link_pool_free;
  sg_link_pool_free = (st_link *) sg_link_pool_free->stack;

  return lk;
}

st_links *SG_MallocLinks(void)
{
  st_links *lks;

  if(sg_links_pool_free == NULL) {
    /*  When out of free items, allocate a new chunk of 'em  */
    st_links **pool;
    register int i;
    pool = SG_Malloc(SG_LINKSMEMCHUNK, sizeof(st_link));
    pool[0] = (st_links *) pool;
    for(i=1; i< SG_LINKSMEMCHUNK; i++) {
      pool[i]
      = pool[i-1]->tail
      = (st_links *) ((size_t)pool[i-1] + (size_t)sizeof(st_links));
    }
    pool[SG_LINKSMEMCHUNK-1]->tail = NULL;
    sg_links_pool_free = *pool;
  }
  lks = sg_links_pool_free;
  sg_links_pool_free = sg_links_pool_free->tail;

  return lks;
}
#endif  /*  SG_GENERIC_POOL_ALLOC  */
#endif  /*  SG_POOL_ALLOC  */

#ifndef DEBUG
stack *SG_NewStack(state s, ATbool isshift)
#else
stack *SG_NewStack(state s, stack *ancestor, ATbool isshift)
#endif
{
  stack *st;

  if((st = SG_MallocStack())) {
    st->state     = s;
    st->links     = NULL;
    st->refcount  = 0;
    st->isshift   = isshift;
#ifdef DEBUG
    st->parent = ancestor;
#endif
#ifdef  MEMSTATS
    IF_STATISTICS(sg_num_stack++);
#endif
  }
#ifdef DEBUG
  if(SG_DEBUG)
    ATwarning("%xd stack created [%d]\n", st, sg_num_stack);
#endif
  return st;
}

void SG_DeleteStack(stack *st)
{
  if(!st) {
    ATwarning("NULL stack not deleted!\n");
    return;
  }
  SG_FreeStack(st);
#ifdef  MEMSTATS
  IF_STATISTICS(sg_num_stack--);
#endif
#ifdef DEBUG
  if(SG_DEBUG)
    ATwarning("%xd stack deleted [%d]\n", st, sg_num_stack);
#endif
}

stacks *SG_AddStack(stack *st, stacks *osts) {
  stacks *nsts;

  if((nsts = SG_MallocStacks())) {
    nsts->head = st;
    nsts->tail = osts;
#ifdef  MEMSTATS
    IF_STATISTICS(sg_num_stacks++);
#endif
  }
#ifdef DEBUG
  if(SG_DEBUG)
    ATwarning("%xd stack list created [%d]\n", nsts, sg_num_stacks);
#endif
  return nsts;
}

void SG_DeleteStacks(stacks *sts)
{
  SG_FreeStacks(sts);
#ifdef  MEMSTATS
  IF_STATISTICS(sg_num_stacks--);
#endif
#ifdef DEBUG
  if(SG_DEBUG)
    ATwarning("%xd stack list deleted [%d]\n", sts, sg_num_stacks);
#endif
}

st_link *SG_NewLink(tree t, stack *st) {
  st_link *lk;

  if((lk = SG_MallocLink())) {
    lk->tree = t;
    ATprotect((ATerm *) &(lk->tree));
    lk->stack = st;
    lk->rejected = ATfalse;
#ifdef  MEMSTATS
    IF_STATISTICS(sg_num_link++);
#endif
  }
#ifdef DEBUG
  if(SG_DEBUG)
    ATwarning("%xd link created [%d]\n", lk, sg_num_link);
#endif
  return lk;
}

void SG_DeleteLink(st_link *lk)
{
  ATunprotect((ATerm *)&SG_LK_TREE(lk));
  SG_FreeLink(lk);
#ifdef  MEMSTATS
  IF_STATISTICS(sg_num_link--);
#endif
#ifdef DEBUG
  if(SG_DEBUG)
    ATwarning("%xd link deleted [%d]\n", lk, sg_num_link);
#endif
}

st_link *SG_AddLink(stack *frm, stack *to, tree t)
{
  st_link *link;

  if((link = SG_NewLink(t, to))) {
    frm->links = SG_AddLinks(link, frm->links);
  }
  return link;
}

  st_links *SG_AddLinks(st_link *l, st_links *ls)
  {
    st_links *lks;

  if((lks = SG_MallocLinks())) {
    lks->head = l;
    lks->tail = ls;
#ifdef  MEMSTATS
    IF_STATISTICS(sg_num_links++);
#endif
  }
#ifdef DEBUG
  if(SG_DEBUG)
    ATwarning("%xd link list created [%d]\n", lks, sg_num_links);
#endif
  return lks;
}

void SG_DeleteLinks(st_links *lks)
{
  SG_FreeLinks(lks);
#ifdef  MEMSTATS
  IF_STATISTICS(sg_num_links--);
#endif
#ifdef DEBUG
  if(SG_DEBUG)
    ATwarning("%xd link list deleted [%d]\n", lks, sg_num_links);
#endif
}

ATbool SG_InStacks(stack *st1, stacks *sts, ATbool deep)
{
  stack *st0;

  while(sts) {
    st0 = SG_HEAD(sts);
    sts = SG_TAIL(sts);
    if(st1 == st0) return ATtrue;
    if(deep && SG_SubStack(st1, st0)) {
      return ATtrue;
    }
  }
  return ATfalse;
}

ATbool SG_SubStack(stack *st1, stack *st0)
{
  stack    *s;
  st_links *ls;

  if(st1 == st0)
    return ATtrue;
  if(!st0 || !st1)
    return ATfalse;

  ls = SG_ST_LINKS(st0);
  for (; ls; ls = SG_TAIL(ls)) {
    s = SG_LK_STACK(SG_HEAD(ls));
    if (SG_SubStack(st1, s)) {
      return ATtrue;
    }
  }
  return ATfalse;
}

ATbool SG_InReduceStacks(stack *st1, stacks *sts, ATbool deep)
{
  stack *st0;

  for(; sts; sts = SG_TAIL(sts)) {
    st0 = SG_HEAD(sts);
    if(st1 == st0) return ATtrue;
    if(deep && SG_ReduceSubStack(st1, st0)) {
      return ATtrue;
    }
  }
  return ATfalse;
}

ATbool SG_ReduceSubStack(stack *st1, stack *st0)
{
  stack    *s;
  st_links *ls;

  if(st1 == st0)
    return ATtrue;
  if(!st0 || !st1)
    return ATfalse;

  if(SG_ST_ISSHIFT(st0))
    return ATfalse;

  ls = SG_ST_LINKS(st0);
  for (; ls; ls = SG_TAIL(ls)) {
    s = SG_LK_STACK(SG_HEAD(ls));
    if (SG_SubStack(st1, s)) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/*  Find a stack with a state |s| in a list of stacks.  */

stack *SG_FindStack(state s, stacks *sts)
{
  for (; sts; sts = SG_TAIL(sts))
    if(SG_ST_STATE(SG_HEAD(sts)) == s)
      return SG_HEAD(sts);
  return NULL;
}

/*  Find a direct link from |st0| to |st1|  */

st_link *SG_FindDirectLink(stack *st0, stack *st1)
{
  st_links *ls = NULL;

  for (ls = SG_ST_LINKS(st0); ls; ls = SG_TAIL(ls))
    if(SG_LK_STACK(SG_HEAD(ls)) == st1)
      return SG_HEAD(ls);
  return NULL;
}


/*  Mark link of a stack as rejected.  */

void SG_MarkLinkRejected(st_link *l)
{
  SG_LK_REJECTED(l) = ATtrue;
  /*
   ATwarning("Link state %d --> state %d rejected\n",
             SG_GETSTATE(SG_ST_STATE(st)),
             SG_GETSTATE(SG_ST_STATE(SG_LK_STACK(l))));
   */
}

/*
 A stack is rejected if both the following conditions are met:
 (1)  it has rejected links
 (2)  is has no unrejected links
 */

ATbool SG_Rejected(stack *st)
{
  st_links *ls;

  if (!(ls = SG_ST_LINKS(st)))
    /* No links, no reject */
    return ATfalse;

  for (; ls; ls = SG_TAIL(ls)) {
    if(!SG_LK_REJECTED(SG_HEAD(ls))) {
      /*  A link is not rejected  */
      return ATfalse;
    }
  }
  /*  All links are rejected  */
  return ATtrue;
}
