/* 
   %% $Id$
   %% Graph Structured Stack

   The parser maintains a graph structured stack to keep track
   of all possible parses in parallel. If there is more than
   one possible continuation for a stack, a new stack is created
   for each possibility. All these stacks share the common prefix
   of the stack. If later on different stacks reach the same state,
   they can be joined again. This leads to a graph structure.

   Stacks are defined by means of |term|s. 
   
*/

extern FILE *stack_dot;
extern int show_stack;

typedef term stack; 
typedef term stacks;
typedef term st_link;
typedef term st_links;

#define new_stack(s, ls)    mk_appl(s, ls)
#define new_link(t, st)     TBmake("link(%t,%t)", t, st)

#define new_stacks(st, sts) mk_list(st, sts)
#define new_links(l, ls)    mk_list(l, ls)

#define STATE(s)          fun_sym(s)   /* state of a stack */
#define LINKS(s)          fun_args(s)  /* list of links of a stack */

#define TREE(l)           elm1(fun_args(l))  /* tree of a link */
#define STACK(l)          elm2(fun_args(l))  /* stack of a link */


#define add_link(st1, t, st0, l) \
        LINKS(st1) = new_links(l = new_link(t, st0), LINKS(st1))

#define add_link2(st1, t, st0) \
        LINKS(st1) = new_links(new_link(t, st0), LINKS(st1)) 

#define add_stack(st, sts) \
        sts = new_stacks(st, sts)

#define REJECTED(t)       (t)->trm_has_conds
/*
  The macro |pop(hd, lst)| indicates whether a list |lst| is empty. If
  it is not, the head of the list is assigned to the variable |hd| and
  the list is reduced to its tail.  The macro can be used to loop over
  the elements of a list as follows:
\begin{verbatim}
  term *hd; term_list *lst;
  while(pop(hd, lst)) {
    do something with hd
  }
\end{verbatim} 
*/
#define pop(hd, lst) ((lst)? (hd) = first(lst), \
		      (lst) = next(lst), TRUE : FALSE)

/*
   Check whether a stack is contained in a list of stacks.
*/

stack *find_stack(state , stacks *);
st_link *find_direct_link(stack *, stack *);
void mark_stack_rejected(stack *, st_link *);
void mark_link_rejected1(stack *, st_link *);
void mark_link_rejected2(stack *, st_link *);
bool  rejected(stack *);
