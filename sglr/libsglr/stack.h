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
/*  $Id$  */

/*
 Graph Structured Stack

 The parser maintains a graph structured stack to keep track
 of all possible parses in parallel. If there is more than
 one possible continuation for a stack, a new stack is created
 for each possibility. All these stacks share the common prefix
 of the stack. If later on different stacks reach the same state,
 they can be joined again. This leads to a graph structure.

 Stacks are defined by means of dedicated data structures.
 */

#ifndef _STACK_H_
#define _STACK_H_ 1

#include "parse-table.h"


#define SG_HEAD(l)    ((l)->head)
#define SG_TAIL(l)    ((l)->tail)


typedef struct list {
  struct list   *tail;
  void          *head;
} list;


/*  Stack/link datastructures  */

typedef list stacks;
typedef list st_links;

typedef struct link {
  struct stack   *stack;
  tree           tree;
  ATbool         rejected;
} st_link;

typedef struct stack {
  st_links       *links;
  state          state;
  short          refcount;
  ATbool         isshift;
#ifdef DEBUG
  struct stack   *parent;
#endif
} stack;


#define SG_ST_STATE(s)          (((stack *)s)->state)     /* State of a stack */
#define SG_ST_LINKS(s)          (((stack *)s)->links)     /* List of links of a stack */
#define SG_ST_PARENT(s)         (((stack *)s)->parent     /* Parent stack of a stack */
#define SG_ST_INCCOUNT(s)       (((stack *)s)->refcount++)
#define SG_ST_DECCOUNT(s)       (((stack *)s)->refcount--)
#define SG_ST_COUNT(s)          (((stack *)s)->refcount)
#define SG_ST_ISSHIFT(s)        (((stack *)s)->isshift)

#define SG_LK_TREE(l)           (((st_link *)l)->tree)      /* Tree of a link */
#define SG_LK_STACK(l)          (((st_link *)l)->stack)     /* Stack of a link */
#define SG_LK_REJECTED(l)       (((st_link *)l)->rejected)  /* Rejected attr. of link */

#ifdef  MEMSTATS
void      SG_ZeroAllocStats(void);
void      SG_PrintCurAllocStats(void);
void      SG_PrintMaxAllocStats(void);
void      SG_MaxAllocStats(void);
#endif

#ifndef DEBUG
stack    *SG_NewStack(state s, ATbool isshift);
#else
stack    *SG_NewStack(state s, stack *st, ATbool isshift);
#endif
#define   SG_NewStacks(s)  SG_AddStack(s, NULL)
stacks   *SG_AddStack(stack *st, stacks *sts);
st_link  *SG_AddLink(stack *st0, stack *st1,  tree t);
st_links *SG_AddLinks(st_link *l, st_links *ls);

stacks   *SG_CollectOldStacks(stacks *old, stacks *new, stack *accept);

void      SG_DeleteStacks(stacks *sts);
void      SG_DeleteStack(stack *st);
void      SG_DeleteLinks(st_links *lks);
void      SG_DeleteLink(st_link *lk);

void      SG_SweepStack(stack *accept, ATbool delete);
#define   SG_ClearStack(st)  SG_SweepStack(st, ATtrue)

stack    *SG_FindStack(state, stacks *);
st_link  *SG_FindDirectLink(stack *, stack *);

void      SG_MarkStackRejected(stack *);
void      SG_MarkLinkRejected(st_link *);
ATbool    SG_Rejected(stack *);
ATbool    SG_DeeplyRejected(stack *);
ATbool    SG_InStacks(stack *, stacks *, ATbool);
ATbool    SG_SubStack(stack *, stack *);
ATbool    SG_InReduceStacks(stack *, stacks *, ATbool);
ATbool    SG_ReduceSubStack(stack *, stack *);

#endif  /* _STACK_H_ */
