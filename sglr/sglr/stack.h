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

/*
 The macro |shift(h, l)| indicates whether a list-type data
 structure (containing head and tail pointers) |l| is empty. If it
 is not, the head of the list is assigned to the variable |h| and
 the list is reduced to its tail.  The macro can be used to loop
 over the structure as follows:
\begin{verbatim}
  listElt hd; listPtr lst;
  while(pop(hd, lst)) {
    [do something with hd and/or lst]
  }
\end{verbatim}
 */

#define head(l)    ((l)->head)
#define tail(l)    ((l)->tail)
#define shift(h,l) ((l) ? (h)=head(l), (l)=tail(l), ATtrue : ATfalse)

/*
  The macro |pop(hd, lst)| indicates whether an AtermList |lst| is empty. If
  it is not, the head of the list is assigned to the variable |hd| and
  the list is reduced to its tail.  The macro can be used to loop over
  the elements of a list as follows:
\begin{verbatim}
  ATerm hd;  ATermList lst;
  while(pop(hd, lst)) {
    [do something with hd and/or lst]
  }
\end{verbatim}
*/

/*
#define pop(hd, lst) (((lst) && !ATisEmpty(lst)) ?                         \
                        (hd)=ATgetFirst(lst),(lst)=ATgetNext(lst),ATtrue : \
                        ATfalse)
*/



/**** Stack/link datastructures ****/

typedef ATerm tree;

typedef struct link {
  tree          tree;
  struct stack  *stack;
  ATbool        rejected;
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
  ATbool        rejected;
  ATbool        protected;
} stack;

typedef struct stacks {
  stack         *head;
  struct stacks *tail;
} stacks;


#define SG_ST_STATE(s)          ((s)->state)     /* State of a stack * */
#define SG_ST_LINKS(s)          ((s)->links)     /* List of links of a stack * */
#define SG_ST_PARENT(s)         ((s)->parent     /* Parent stack of a stack * */
#define SG_ST_KID(s)            ((s)->kid        /* Kid stack of a stack * */

#define SG_LK_TREE(l)           ((l)->tree)      /* Tree of a link * */
#define SG_LK_STACK(l)          ((l)->stack)     /* Stack of a link * */

#define SG_LK_REJECTED(x)       (x)->rejected
#define SG_LK_PROTECTED(x)      (x)->protected


stack    *SG_NewStack(state s, stack *st);
#define   SG_NewStacks(s)	SG_AddStack(s, NULL)
stacks   *SG_AddStack(stack *st, stacks *sts);
st_link  *SG_AddLink(stack *st0, stack *st1,  tree t);
st_links *SG_AddLinks(st_link *l, st_links *ls);

stacks *SG_PurgeOldStacks(stacks *old, stacks *new, stack *accept);
void    SG_UnprotectUnusedStacks(stacks *old, stacks *new, stack *accept);
void    SG_UnprotectUnusedStack(stack *st, stacks *new, stack *accept);
void    SG_DisposeUnusedStacks(stacks *sts);
void    SG_DisposeUnusedStack(stack *st);

/*
stacks   *SG_DeleteOldStacks(stacks *old, stacks *new);
void      SG_DeleteOldStack(stack *st, stacks *new);
*/
stacks   *SG_DeleteStacks(stacks *sts);
void      SG_DeleteStack(stack *st);
st_links *SG_DeleteLinks(st_links *lks);
void      SG_DeleteLink(st_link *lk);


stack *   SG_FindStack(state , stacks *);
st_link  *SG_FindDirectLink(stack *, stack *);

void     SG_MarkStackRejected(stack *, st_link *);
void     SG_MarkLinkRejected(stack *, st_link *);
void     SG_MarkLinkRejected2(stack *, st_link *);
ATbool   SG_Rejected(stack *);
ATbool   SG_InStacks(stack *, stacks *, ATbool);
ATbool   SG_SubStack(stack *, stack *);
