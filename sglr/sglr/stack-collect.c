#include "mem-alloc.h"
#include "stack.h"

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
