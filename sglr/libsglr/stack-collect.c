/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands.

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
 * $Id$
 */

#include "mem-alloc.h"
#include "stack.h"

/*
 Using the related stack- and link data structures, a suitable
 method of garbage collection must be performed.

 The parser consists of a number of parallel parsers that may be
 discarded on shift (and accept), or merge on reduce.

 When shifting, a new set of parsers is derived; whatever lived
 in the old set of parsers, but not in either the new one or in
 the accepting stack, can (and hence must) be disposed.

 Stacks can be substacks of one another; a simple traversal will not
 do, because shared (sub)stacks will be visited multiple times.  For
 that reason, garbage collection uses the classic two `mark' and
 `sweep' passes.
 */


/*
 *  Mark phase:  traverse stacks, increment counters of visited nodes
 */

void SG_MarkStack(stack *st)
{
  if(st) {
    SG_ST_INCCOUNT(st);
    if(SG_ST_COUNT(st) == 1) {
      register st_links *lks;

      for(lks = SG_ST_LINKS(st); lks; lks = SG_TAIL(lks))
        SG_MarkStack(SG_LK_STACK(SG_HEAD(lks)));
    }
  }
}

void SG_MarkStacks(stacks *sts)
{
  for(; sts; sts = SG_TAIL(sts))
    SG_MarkStack(SG_HEAD(sts));
}

/*
 *  Sweep phase: traverse, decrement counters while doing so,
 *               free a node when in delete mode, and the counter hits 0
 */

void SG_SweepStack(stack *st, ATbool delete)
{
  if(st) {
    SG_ST_DECCOUNT(st);
    if(SG_ST_COUNT(st) <= 0) {
      register st_links *lks, *lks2;

      for(lks = SG_ST_LINKS(st); lks;) {
        st_link  *lk = SG_HEAD(lks);

        lks2 = lks;
        lks = SG_TAIL(lks);
        SG_SweepStack(SG_LK_STACK(lk), delete);
        if(delete) {
          SG_DeleteLink(lk);
          SG_DeleteLinks(lks2);
        }
      }
      if(delete)
        SG_DeleteStack(st);
    }
  }
}

void SG_SweepStacks(stacks *sts, ATbool delete)
{
  while(sts) {
    stacks *osts;

    SG_SweepStack(SG_HEAD(sts), delete);
    osts = sts;
    sts = SG_TAIL(sts);
    if(delete)
      SG_DeleteStacks(osts);
  }
}

stacks *SG_CollectOldStacks(stacks *old, stacks *new, stack *accept)
{
#ifdef MEMSTATS
  if(SG_DEBUG) {
    fprintf(SGlog(), "[Before GC] ");
    SG_PrintCurAllocStats();
  }
#endif

  /*  Count references: mark...  */
  if(accept)
    SG_MarkStack(accept);
  if(new)
    SG_MarkStacks(new);
  SG_MarkStacks(old);

  /*  Remove unreferenced items: sweep... */
  SG_SweepStacks(old, ATtrue);
  if(accept)
    SG_SweepStack(accept, ATfalse);
  if(new)
    SG_SweepStacks(new, ATfalse);

#ifdef MEMSTATS
  if(SG_DEBUG) {
    fprintf(SGlog(), "[After  GC] ");
    SG_PrintCurAllocStats();
  }
#endif

  return new;
}
