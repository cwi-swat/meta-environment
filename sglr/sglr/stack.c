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
#include "parse-table.h"
#include "stack.h"
#include "parser.h"

bool in_stacks(stack *st1, stacks *sts)
{
  stack *st2;
  while(pop(st2, sts))
    if(st2 == st1) return TRUE;
  return FALSE;
}

/*
   Find a stack with a state |s| in a list of stacks.
*/
stack *find_stack(state s, stacks *sts)
{
  for (; sts != NULL; sts = next(sts))
    if(STATE(first(sts)) == s) return first(sts);
  return NULL;
}

/*
   Find a direct link from |st0| to |st1|
*/
st_link *find_direct_link(stack *st0, stack *st1)
{
  st_links *ls = NULL;
  for (ls = LINKS(st0); ls != NULL; ls = next(ls))
    if(STACK(first(ls)) == st1) return first(ls);
  return NULL;
}


/*
  Mark link of a stack as rejected. (By setting its |has_conds| field
  to |TRUE|. This is a hack to save space by not declaring another
  node for the representation of stacks!)
*/

void mark_stack_rejected(stack *st, st_link *l)
{
  st_links *ls = LINKS(st);

  for (; ls != NULL; ls = next(ls)) {
/*
    TBprintf(stderr, "Rejecting state %d ==> state %d\n",
                     STATE(st), STATE(STACK(first(ls))));
*/
    REJECTED(first(ls)) = TRUE;
  }

  REJECTED(l) = TRUE;
}

void mark_link_rejected1(stack *st, st_link *l)
{
  REJECTED(l) = TRUE;
/*
  TBprintf(stderr, "Link state %d ==> state %d rejected\n",
           STATE(st), STATE(STACK(l)));
*/
}

void mark_link_rejected2(stack *st, st_link *l)
{
  REJECTED(l) = TRUE;
  TBprintf(stderr, "Warning: link state %d ==> state %d rejected in presence of other links\n",
           STATE(st), STATE(STACK(l)));
}



/*
    Is one of the stacks links rejected?
 */
bool some_rejected(stack *st)
{
  register st_links *ls = LINKS(st);
  stack *kid;
  st_link *l;
  int count = 0;

  for (; ls != NULL; ls = next(ls)) {
    l = first(ls);
    if(REJECTED(l)) {
//       TBprintf(stderr, "A stack link with state %d rejected\n", STATE(st));
       return TRUE;
    }
    kid = STACK(l);
    count++;
    if (some_rejected(kid))
      return TRUE;
  }
  return FALSE;
}

/*
  A stack is rejected if all its links are.
*/
bool rejected(stack *st)
{
  register st_links *ls = LINKS(st);

  if (!ls) return FALSE;
  for (; ls != NULL; ls = next(ls))
    if(REJECTED(first(ls))) {
//      TBprintf(stderr, "A stack link with state %d unrejected\n", STATE(st));
      return TRUE;
    }
  return FALSE;
}
