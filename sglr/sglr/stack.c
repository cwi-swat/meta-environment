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


stack *new_stack(state s, stack *ancestor) {
  stack *res;

  if((res = malloc(sizeof(stack))) != NULL) {
    res->state = s;
    res->parent = ancestor;
    res->kid = NULL;
    res->links = NULL;
    res->rejected = FALSE;
  }
  return res;
}

st_link *new_link(tree t, stack *st) {
  st_link *res;

  if((res = malloc(sizeof(st_link))) != NULL) {
    res->tree = t;
    res->stack = st;
    res->rejected = FALSE;
  }
  return res;
}

st_links *add_links(st_link *l, st_links *ls) {
  st_links *res;

  if((res = malloc(sizeof(st_links))) != NULL) {
    res->head = l;
    res->tail = ls;
  }
  return res;
}

stacks *add_stacks(stack *st, stacks *sts) {
  stacks *res;

  if((res = malloc(sizeof(stacks *))) != NULL) {
    res->head = st;
    res->tail = sts;
  }
  return res;
}

st_link *add_link(stack *frm, stack *to, tree t)
{
  st_link *link;

  if((link = new_link(t, to)) != NULL) {
    frm->links = add_links(link, frm->links);
  }
  return link;
}


bool in_stacks(stack *st1, stacks *sts)
{
  stack *st2;
  while(shift(st2, sts))
    if(st2 == st1) return TRUE;
  return FALSE;
}

/*
   Find a stack with a state |s| in a list of stacks.
*/
stack *find_stack(state s, stacks *sts)
{
  for (; sts != NULL; sts = tail(sts))
    if(STATE(head(sts)) == s) return head(sts);
  return NULL;
}

/*
   Find a direct link from |st0| to |st1|
*/
st_link *find_direct_link(stack *st0, stack *st1)
{
  st_links *ls = NULL;

  for (ls = LINKS(st0); ls != NULL; ls = tail(ls))
    if(STACK(head(ls)) == st1) return head(ls);
  return NULL;
}


/*
  Mark link of a stack as rejected. (By setting its |has_conds| field
  to |TRUE|. This is a hack to save space by not declaring another
  node for the representation of stacks!)
*/

void mark_stack_rejected(stack *st, st_link *l)
{
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


#ifdef DEBUG
/*
    Is one of the stacks links rejected?
 */
bool some_rejected(stack *st)
{
  register st_links *ls = LINKS(st);
  stack *kid;
  st_link *l;
  int count = 0;

  for (; ls != NULL; ls = tail(ls)) {
    l = head(ls);
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
#endif /* DEBUG */

/*
  A stack is rejected if all its links are.
*/
bool rejected(stack *st)
{
  register st_links *ls = LINKS(st);

  if (!ls) return FALSE;
  for (; ls != NULL; ls = tail(ls))
    if(REJECTED(head(ls))) {
//      TBprintf(stderr, "A stack link with state %d unrejected\n", STATE(st));
      return TRUE;
    }
  return FALSE;
}
