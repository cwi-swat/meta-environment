/*
   %% $Id$
   %% Graph Structured Stack

   The parser maintains a graph structured stack to keep track
   of all possible parses in parallel. If there is more than
   one possible continuation for a stack, a new stack is created
   for each possibility. All these stacks share the common prefix
   of the stack. If later on different stacks reach the same state,
   they can be joined again. This leads to a graph structure.

   Stacks are defined by means of dedicated data structures.

*/

extern FILE *stack_dot;
extern int show_stack;

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


/**** Stack/link datastructures ****/

typedef term *tree;
// typedef int  state;

typedef struct link {
  tree          tree;
  struct stack  *stack;
  bool          rejected;
} st_link;

typedef struct links {
  st_link       *head;
  struct links  *tail;
} st_links;

typedef struct stack {
  state         state;
  struct stack  *parent;
  struct stack  *kid;
  st_links      *links;
  bool          rejected;
} stack;

typedef struct stacks {
  stack         *head;
  struct stacks *tail;
} stacks;


#define STATE(s)          ((s)->state)     /* state of a stack * */
#define LINKS(s)          ((s)->links)     /* list of links of a stack * */
#define PARENT(s)         ((s)->parent     /* parent stack of a stack * */
#define KID(s)            ((s)->kid        /* kid stack of a stack * */

#define TREE(l)           ((l)->tree)      /* tree of a link * */
#define STACK(l)          ((l)->stack)     /* stack of a link * */

#define REJECTED(x)       (x)->rejected

/*
 The macro |shift(h, l)| indicates whether a list |l| is empty. If
 it is not, the head of the list is assigned to the variable |h| and
 the list is reduced to its tail.  The macro can be used to loop over
 the elements of a list as follows:
\begin{verbatim}
  term *hd; term_list *lst;
  while(pop(hd, lst)) {
    do something with hd
  }
\end{verbatim}
 */
#define head(l)    ((l)->head)
#define tail(l)    ((l)->tail)
#define shift(h,l) ((l) ? (h)=head(l), (l)=tail(l), TRUE : FALSE)

stack  *new_stack(state s, stack *st);
stacks *add_stacks(stack *st, stacks *sts);
st_link *add_link(stack *st0, stack *st1,  tree t);

#define new_stacks(s)   add_stacks(s, NULL)


stack *find_stack(state , stacks *);
st_link *find_direct_link(stack *, stack *);
void mark_stack_rejected(stack *, st_link *);
void mark_link_rejected1(stack *, st_link *);
void mark_link_rejected2(stack *, st_link *);
bool  rejected(stack *);
bool in_stacks(stack *, stacks *);
