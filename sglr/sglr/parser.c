/*
  %% $Id$

  \section{Parser}
  \label{parser.c}

  This section contains the implementation of a \emph{generalized LR}
  parser. The main function |parse| takes a parsetable and an input
  streams as parameters and yields a term, which represents either the
  parse tree or an error message in case of a syntactic error in the
  input.

  All data structures are represented by means of ToolBus terms.

  \subsection{parser.h}

  \input{parser.htx}

  \noindent\rule{3cm}{0.5pt} end parser.h
*/

#include  <ctype.h>

#include <aterm2.h>
#include <a2toa1.h>

#include "parse-table.h"
#include "stack.h"
#include "parser.h"
#include "forest.h"
#include "tree-to-dot.h"
#include "mem-alloc.h"
#include "sglr.h"


/*
   \subsection{Text Input}

   The input for the parser is a list of characters closed by an end
   of file symbol |EOF|. The list is accessed by means of a function
   that produces the next character in the list. The function is a
   parameter of the |SG_NexToken| function and can be determined by the
   caller of the parser.

   For the purpose of error messages we keep track of the current line
   and column.
*/
int line;        /* current line */
int col;         /* current column */
int text_length; /* number of tokens read */
#define eof 0

/*
   By definition we say that the start of the input is at
   column zero of line one,and there are 0 ambiguities
*/
void SG_InitInput(void)
{
  line        = 1;
  col         = 0;
  text_length = 0;
  SGnrAmb(SG_NRAMB_ZERO);
}

/*
  The function |SG_NexToken| reads the next token from the
  stream provided by the parameter function |get_next_char| and
  updates the line and column values taking account of
  newlines |\n|, tabs |\t| and end of file |EOF|.
*/
int SG_NexToken(int(*get_next_char)(void))
{
  int c;
  c = get_next_char();
  text_length++;
  switch(c) {
    case '\n' : line++; col = 0         ; break;
    case '\t' : col = (col / 8 + 1) * 8 ; break;
    case EOF  : c = eof                 ; break;
    default  : col++                   ; break;
  }
  return c;
}

/*
   \subsection{Shift Pairs}

   A shift pair is a pair of a state and a stack and is used to
   indicate a shift from the stack to a new state.
*/

typedef struct shift_pair {
  state   state;
  stack   *stack;
  struct shift_pair *tail;
} shift_pair;

shift_pair *SG_NewShiftPair(stack *st, state s, shift_pair *sp0)
{
  shift_pair *sp1;

  if((sp1 = SG_Malloc(sizeof(shift_pair))) != NULL) {
    sp1->state = s;
    sp1->stack = st;
    sp1->tail  = sp0;
  }
  return sp1;
}

#define SG_SP_STATE(x)                  (x)->state
#define SG_SP_STACK(x)                  (x)->stack
#define SG_SP_NEXT(x)                   (x)->tail

#define SG_AddShiftPair(st, a, next)    (next = SG_NewShiftPair(st, a, next))


/*
   \subsection{Paths}

   A path is a pair of a stack and a list of terms. A path represents
   the path from a certain point |p1| in a stack to another point |p2|
   in a stack such that |p2| is reachable from |p1| and the list of
   terms are the terms encountered in the links in reverse order.
   Paths are used in reductions.

*/

typedef struct path {
  stack             *stack;
  ATermList         args;
  struct path       *next;
} path;

//#define paths path;

#define SG_P_STACK(x)                  (x)->stack
#define SG_P_ARGS(x)                   (x)->args
#define SG_P_NEXT(x)                   (x)->next

path *SG_NewPath(stack *st, ATermList sons, path *ps)
{
  path *p;

  if((p = SG_Malloc(sizeof(path))) != NULL) {
    p->stack = st;
    p->args  = sons;
    p->next  = ps;
  }
  return p;
}


/*
  The concatenation of two paths
*/
path *SG_ConcPaths(path *ps1, path *ps2)
{
  path *ps;
  if (ps1 == NULL) return ps2;
  if (ps2 == NULL) return ps1;
  for (ps = ps1; SG_P_NEXT(ps) != NULL; ps = SG_P_NEXT(ps)) ;
  SG_P_NEXT(ps) = ps2;
  return ps1;
}

/*
   \paragraph{Find Paths}

   Function |SG_FindPaths| yields all paths from stack |st| with length
   |i|, containing link |l| if |link_seen| is |ATtrue|.

*/
path *SG_FindPaths(stack *st, int i, st_link *l0, ATbool link_seen,
                   ATermList sons)
{
  st_links  *ls = NULL;
  st_link   *l1 = NULL;
  path      *paths = NULL;
  ATermList newsons = NULL;

  if (SG_DEBUG)
    ATfprintf(SGlog(), "SG_FindPaths(%d, %d, x, %d, %d)\n",
              SG_ST_STATE(st), i, link_seen, (int) sons);

  if (st == NULL) {
    paths = NULL;
  } else if (i == 0 && link_seen) {
    paths = SG_NewPath(st, sons, NULL);
  } else if (i > 0) {
    for (ls = SG_ST_LINKS(st); ls != NULL; ls = tail(ls)) {
      l1 = head(ls);
      newsons = ATinsert(sons?sons:ATempty, SG_LK_TREE(l1));
      paths = SG_ConcPaths(SG_FindPaths(SG_LK_STACK(l1), i - 1, l0,
                                        link_seen || (l0 == l1), newsons),
                           paths);
    }
  }
  return paths;
}


/*
   \subsection{The Interpreter}

   The state of the parser is stored in the following global variables.

*/
parse_table *table;
int         current_token;
stack       *accepting_stack;
stacks      *active_stacks;
stacks      *for_actor;
stacks      *for_actor_delayed;
shift_pair  *for_shifter;

/*
   Predeclaration of the auxiliary functions.
*/
void  SG_ParseChar(void);
void  SG_Actor(stack *);
void  SG_DoReductions(stack*, action);
void  SG_Reducer(stack *, state, label, ATermList, ATbool, stack *);
void  SG_DoLimitedReductions(stack*, action, st_link*);
void  SG_Shifter(void);
ATerm SG_Result(void);

/*
   \paragraph{Parse}

   The parse function |SG_Parse| parses a text with a parse table |ptable|.
   The text is accessed with the function argument |get_next_char|.

   For each token in the input and while there are still stacks alive,
   i.e., no error is encountered, the parser handles all actions for
   each active stack. The shifts for each stack are stored and
   performed by |do_shifts| after all possible reductions have been
   performed.

   When the end of input is reached or no more stacks are alive,
   parsing is done. The function |SG_Result| returns a parse tree error
   message depending on the status.

*/
ATerm SG_Parse(parse_table *ptable, int(*get_next_char)(void))
{
  SG_InitInput();
  table = ptable;

  accepting_stack = NULL;
  active_stacks = SG_NewStacks(SG_NewStack(SG_INIT(table), NULL));

  do {
    if(SG_SHOWSTACK) SG_StacksToDotFile(active_stacks, text_length);
    current_token = SG_NexToken(get_next_char);
    if(SG_DEBUG) {
      if(isgraph(current_token))
        ATfprintf(SGlog(), "Current token:  %c\n", current_token);
      else
        ATfprintf(SGlog(), "Current token:  \\%o\n", current_token);
    }
    SG_ParseChar();
    SG_Shifter();
  } while (current_token != eof && active_stacks != NULL);

  if(SG_SHOWSTACK)
    SG_StacksToDotFile(SG_NewStacks(accepting_stack), text_length);

  return SG_Result();
}

/*
  \paragraph{Termination}

  If all tokens have been read or if no more stacks are alive,
  parsing is done and the the result of parsing is returned.  If
  parsing succeeded, |accepting_stack| points to a stack that has a
  direct link to the initial state. The tree on this link is the parse
  forest with all possible parse trees.  If parsing failed an error
  term is returned. A distinction is made between an error at end of
  file an error in the middle of the file.
*/
ATerm SG_Result(void)
{
  if (accepting_stack != NULL) {
    ATerm t;

//    active_stacks = SG_AddStacks(accepting_stack, active_stacks);
    active_stacks = NULL;

    t = SG_YieldPT(SG_LK_TREE(head(SG_ST_LINKS(accepting_stack))));

    if(SG_ASFIX1)
      return a2toa1(t);
    else
      return ATmake("parsetree(<term>,<int>)", t, SGnrAmb(SG_NRAMB_ASK));
  } else
    return ATmake("parse-error([character(<int>), line(<int>),"
                  "col(<int>), char(<int>)])",
                  current_token, line, col, text_length);

}
/*
   \paragraph{Parse Character}

   For each stack on |active_stacks| handle the actions for the
   current token.
*/

void SG_ParseChar(void)
{
  stack *st;

  for_actor = active_stacks;
  for_actor_delayed = NULL;
  for_shifter = NULL;

//ATfprintf(stderr, "p_c: %d\n", current_token);

  while(for_actor != NULL  || for_actor_delayed != NULL) {
   if(for_actor != NULL)
      shift(st, for_actor);
    else
      shift(st, for_actor_delayed);
    SG_Actor(st);
    if(SG_SHOWSTACK) SG_LinksToDot(SG_StackDot(), st);
  }
}

/*
   \paragraph{Actor}

   Handle the actions for stack |st| and the current token.  A reduce
   action is immediately handled by |do_reductions|. Shift actions are
   saved on |for_shifter| for handling if no more reductions can be
   done. An accept action results in saving the current stack as the
   accepting stack. An error action is ignored because the current
   stack can be a wrong attempt while other stacks are still
   alive. The entire parse fails if all stacks lead to error
   actions. This will become apparent after shifting because no more
   active stacks will be alive.
*/

void SG_Actor(stack *st)
{
  actions as;
  action  a;

#ifdef DEBUG
  ATbool sr, ar;

  sr = SG_SomeRejected(st); ar = SG_Rejected(st);
  if(sr != ar) {
    ATfprintf(stderr, "\nRA: state %d, SR (%d) != AR (%d)\n", STATE(st),sr,ar);
    show_stack_rejects(st, 0);
  }
#endif

  if(SG_Rejected(st)) {
#ifdef DEBUG
    ATfprintf(stderr, "RA: Rejected state %d: %t\n", STATE(st), TREE(st));
#endif
    return;
  }

  as = SG_LookupAction(table, SG_ST_STATE(st), current_token);
//ATfprintf(stderr, "SG_Actor: actions[%d,%d] = %t\n", SG_ST_STATE(st), current_token, as);
  for(; as != NULL && !ATisEmpty(as); as = ATgetNext(as)) {
    a = ATgetFirst(as);
    switch(SG_A_KIND(a)) {
      case SHIFT:
        SG_AddShiftPair(st, SG_A_STATE(a), for_shifter);
        break;
      case REDUCE:
        SG_DoReductions(st, a);
        break;
      case ACCEPT:
         if(!SG_Rejected(st))
           accepting_stack = st;
         break;
      case ERROR:
        break;
    }
  }
}

/*
  \paragraph{Reductions}

  Function |do_reductions| performs a reduction for stack |st| with
  production |r|, which has |nr_args| arguments. For each path of length
  |p| from |st| a new tree is created with production |r| as label
  and the trees along the path as arguments. The new tree is the link
  from a new stack to the stack at the end of the path.
*/
void SG_DoReductions(stack *st, action a)
{
  path  *ps;
  label prod;

  prod = SG_A_PROD(a);

  for(ps = SG_FindPaths(st, SG_A_NR_ARGS(a), NULL, ATtrue, ATempty);
      ps != NULL; ps = SG_P_NEXT(ps)) {

    SG_Reducer(SG_P_STACK(ps),
               SG_LookupGoto(table, SG_ST_STATE(SG_P_STACK(ps)), prod),
               prod, SG_P_ARGS(ps), SG_A_REJECT(a), st);
  }
}

/*
  \paragraph{Reducer}

  For each path in |p| construct the parse tree with the list of
  descendants found and create a new stack.

  Stack |st0| is the stack at the end of path |p|. State |s| is
  the next state when reducing production |r| from the state of
  |st0|. Look for a stack |st1| on |active_stacks| with state |s|.

  If no such stack is found, create a new stack with state |s|
  and a link to |st0|, which has tree |t| as child. The new
  stack is added to the list of active stacks and to the list of
  delayed stacks for |do_actions|. The delay ensures (?) that all
  reductions to the same stack |st1| occur before any reductions
  from that state such that a rejection of stack |st1| will be
  detected before any further reductions.

  If such a stack exists and there is a direct link |l| from |st1|
  to |st0|, an ambiguity has been found. The tree |t| is simply
  added to the |amb| node of the direct link |l|.

  If there is no direct link, create a new link from |st1| to
  |st0| with |t| as parse tree.
*/

void SG_Reducer(stack *st0, state s, label prodl, ATermList kids,
             ATbool reject, stack *stpt)
{
  ATerm t;
  st_link *nl;
  stack *st1;

  if(SG_Rejected(stpt)) return;

  t = SG_Apply(table, prodl, kids);

  if(SG_DEBUG) ATfprintf(SGlog(), "Reducing %t\n", SG_DotTermYield(t));

  if((st1 = SG_FindStack(s, active_stacks)) != NULL) {
    if((nl = SG_FindDirectLink(st1, st0)) != NULL) {
      /* ambiguity */
      if(SG_DEBUG)  ATfprintf(SGlog(), "Direct link found\n");
      if (!reject)      /* Don't bother to represent rejects prods -- J$ */
        SG_Amb(SG_LK_TREE(nl), t);
      else {
        SG_PropagateReject(st1);
//        SG_MarkLinkRejected(st1, nl);
#ifdef DEBUG
        SG_ShowStackOffspring(st1);
#endif
      }
    } else {
      /* add new direct link from |st1| to |st0| and
         recheck all reductions for |st1|. */
      stacks *sts = NULL;
      stack  *st2 = NULL;

      /* First check if one of the children of |st1| was not rejected already */
      nl = SG_AddLink(st1, st0, t);
      if (reject) {
        SG_MarkLinkRejected2(st1, nl);
      }
      sts = active_stacks;
      while(shift(st2, sts)) {
        actions as;
        action a;
        if(!SG_Rejected(st2) && !SG_InStacks(st2, for_actor)
           && !SG_InStacks(st2, for_actor_delayed)) {
          as = SG_LookupAction(table, SG_ST_STATE(st2), current_token);
          for(; as && !ATisEmpty(as); as = ATgetNext(as)) {
            a = ATgetFirst(as);
            if(SG_A_KIND(a) == REDUCE)
              SG_DoLimitedReductions(st2, a, nl);
          }
        }
      }
    }
  } else {  /* new stack */
    st1 = SG_NewStack(s, stpt);
    nl = SG_AddLink(st1, st0, t);
    SG_AddStackHist(stpt, st1);
//    SG_AddStackHist(stpt, st1);
    active_stacks = SG_AddStacks(st1, active_stacks);
    for_actor_delayed = SG_AddStacks(st1, for_actor_delayed);
    if (reject) {
      if(SG_DEBUG)  ATfprintf(SGlog(), "Rejected [new]\n");
      SG_MarkStackRejected(st1, nl);
    }
  }
} /* reducer */

/*
  \paragraph{Do Limited Reductions}

  Only those reductions that have a path containing link |l|
*/
void SG_DoLimitedReductions(stack *st, action a, st_link *l)
{
  path  *ps;
  label prod;

  prod = SG_A_PROD(a);

  for(ps = SG_FindPaths(st, SG_A_NR_ARGS(a), l, ATfalse, ATempty);
      ps != NULL; ps = SG_P_NEXT(ps)) {
    SG_Reducer(SG_P_STACK(ps),
               SG_LookupGoto(table, SG_ST_STATE(SG_P_STACK(ps)), prod),
               prod, SG_P_ARGS(ps), SG_A_REJECT(a), st);
  }
}

/*
   \paragraph{Shifter}

   Do all shifts in |for_shifter|. For each shift pair |(st1, s)|, a
   stack |st| is created that has a link to |st1| and has state |s|.
   The tree corresponding to the current token is the parse tree for
   the link. If a stack with state |s| already existed on
   |active_stacks|, only a new link is added from |st| to |st1|.
*/
void SG_Shifter(void)
{
  ATerm t;
  stack *st0, *st1;
  shift_pair *shift_pair;
  state s;
  st_link *l;

  active_stacks = NULL;
  t = SG_LookupProduction(table, current_token);

//  if(for_shifter == NULL) return;
  for(shift_pair = for_shifter; shift_pair != NULL;
      shift_pair = SG_SP_NEXT(shift_pair)) {
    s = SG_SP_STATE(shift_pair);
    st0 = SG_SP_STACK(shift_pair);
    if(!SG_Rejected(st0)) {
      if((st1 = SG_FindStack(s, active_stacks)) == NULL) {
        st1 = SG_NewStack(s, NULL);
        active_stacks = SG_AddStacks(st1, active_stacks);
      }
      l = SG_AddLink(st1, st0, t);
      if(SG_SHOWSTACK) SG_LinksToDot(SG_StackDot(), st1);
    }
//  else ATfprintf(stderr,"Shifter: rejected stack %d\n", STATE(st0));
  }
} /* shifter */


/*
 * A few quirks surround the reject mechanism:
 *
 * - Stacks that have already been accepted may be rejected (either
 *   directly or indirectly) in a reduce action that occurs (sequentially)
 *   later in the process.  Stacks that are rejected might also already
 *   have been scheduled for shifting.
 *
 * - Stacks that are rejected may have instantiated other stacks, that
 *   in their turn might get accepted.  To detect this offspring,
 *   and reject the `indirectly' rejected stacks properly, we must
 *   maintain a list containing the relation between originating
 *   stacks and their descendants.
 */

void SG_AddStackHist(stack *parent, stack *kid)
{
  parent->kid = kid;
}

void SG_PropagateReject(stack *st)
{
  while(st != NULL) {
    if(st == accepting_stack) accepting_stack = NULL;
    SG_MarkLinkRejected(st, head(SG_ST_LINKS(st)));
    st = st->kid;
  }
}


#ifdef DEBUG
/*
 *  A few diagnostic routines (for debugging purposes)
 */

void SG_ShowStackOffspring(stack *st)
{
  while(st != NULL && st->kid != NULL) {
    ATfprintf(stderr, "%d%s created %d%s\n",
                     STATE(st), SG_Rejected(st)?"r":"",
                     STATE(st->kid), SG_Rejected(st->kid)?"r":"");
    st = st->kid;
  }
}

void SG_ShowStackAncestors(stack *st)
{
  while(st != NULL && st->parent != NULL) {
    ATfprintf(stderr, "%d%s induced %d%s\n",
                     STATE(st->parent), SG_Rejected(st->parent)?"r":"",
                     STATE(st), SG_Rejected(st)?"r":"");
    st = st->parent;
  }
}

void SG_ShowActiveStackStates(signed int c)
{
  stacks *astks = active_stacks;
  stack  *stk;
  static int level = 0;

  level = (level>1)?(level+c):0;
  ATfprintf(stderr, "%*.*s%cActive states: ", level, level, "", c>0?'+':'-');
  while(astks != NULL) {
    stk   =  astks->head;
    astks =  astks->tail;
    ATfprintf(stderr, "%d%s ", STATE(stk), SG_Rejected(stk)?"r":"");
  }
  ATfprintf(stderr, "\n");
}

void SG_ShowStackRejects(stack *st, int depth)
{
  st_links *ls = LINKS(st);
  st_link *l;

//  if(depth > 666) return;

  for (; ls != NULL; ls = next(ls)) {
    l = first(ls);
    ATfprintf(stderr, "%*.*s%s state %d ==> state %d\n", 2*depth, 2*depth,
                      "", REJECTED(l)?"+":"-", STATE(st), STATE(STACK(l)));
    show_stack_rejects(STACK(l), depth+1);
  }
}


void SG_ShowActiveStackLinks()
{
  stacks *astks = active_stacks;
  stack  *stk;

  while(astks != NULL) {
    stk   =  astks->head;
    astks =  astks->tail;
    show_stack_rejects(stk,2);
  }
}

#endif /* DEBUG */
