/*
  %% $Id$

  \section{Graph Structured Stack}
  \label{stack.c}

  \subsection{stack.h}

  \input{stack.htx}

  \subsection{stack.c}

*/

#include <TB.h>
#include "bool.h"
#include "parser.h"
#include "parse-table.h"
#include "stack.h"

bool
in_stacks(stack *st1, stacks *sts)
{
  stack *st2;
  while(pop(st2, sts))
    if(st2 == st1) return TRUE;
  return FALSE;
}
/*
   Find a stack with a state |s| in a list of stacks.
*/
stack *
find_stack(state s, stacks *sts)
{
  for (; sts != NULL; sts = next(sts))
    if(STATE(first(sts)) == s) return first(sts);
  return NULL;
}
/*
   Find a direct link from |st1| to |st2|
*/
st_link *
find_direct_link(stack *st1, stack *st2)
{
  st_links *ls = NULL;
  for (ls = LINKS(st1); ls != NULL; ls = next(ls))
    if(STACK(first(ls)) == st2) return first(ls);
  return NULL;
}
/*
  Mark link of a stack as rejected. (By setting its |has_conds| field
  to |TRUE|. This is a hack to save space and not declaring another
  node for the representation of stacks!)
*/
void
mark_stack_rejected(stack *st, st_link *l)
{
  REJECTED(l) = TRUE;
}
void
mark_link_rejected1(stack *st, st_link *l)
{
  REJECTED(l) = TRUE;
}
void
mark_link_rejected2(stack *st, st_link *l)
{
  REJECTED(l) = TRUE;
  TBprintf(stderr, "warning: link rejected in presence of other links\n",
	   "from state %d to state %d\n", STATE(STACK(l)), STATE(st));
}
/*
  A stack is rejected if all its links are.
*/
bool
rejected(stack *st)
{
  register st_links *ls;
  ls = LINKS(st);
  if (!ls) return FALSE;
  while(ls)
    {
      if (REJECTED(first(ls)))
	{
	  return TRUE;
	}
      ls = next(ls);
    }
  /* TBprintf(stderr, "Stack with state %d rejected\n", STATE(st)); */
  return FALSE;
}
