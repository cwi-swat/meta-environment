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

#include <TB.h>
#include "bool.h"
#include "parse-table.h"
#include "stack.h"
#include "parser.h"
#include "forest.h"
#include "tree-to-dot.h"

/*
   The following flags determine how much progress information is
   provided.
*/
extern int debugflag;
extern int verbose_flag;
extern FILE *log;
extern int abbreviation_flag;
extern int show_stack;
extern int gc;

/*
   \subsection{Text Input}

   The input for the parser is a list of characters closed by an end
   of file symbol |EOF|. The list is accessed by means of a function
   that produces the next character in the list. The function is a
   parameter of the |next_token| function and can be determined by the
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
   column zero of line one.
*/
void init_input(void)
{
  line        = 1;
  col         = 0;
  text_length = 0;
}
/*
  The function |next_token| reads the next token from the
  stream provided by the parameter function |get_next_char| and
  updates the line and column values taking account of
  newlines |\n|, tabs |\t| and end of file |EOF|.
*/
int next_token(int(*get_next_char)(void))
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
  if(debugflag) fprintf(log, "next_token = %c\n", c);
  return c;
}

/*
   \subsection{Shift Pairs}

   A shift pair is a pair of a state and a stack and is used to
   indicate a shift from the stack to a new state.
*/

typedef term shift_pair;

#define new_shift_pair(st, s, next)  TBmake("[shift(%d,%t),%l]", s, st, next)
#define SP_STATE(x)                  int_val(elm1(fun_args(x)))
#define SP_STACK(x)                  elm2(fun_args(x))
#define SP_NEXT(x)                   next(x)

#define add_shift_pair(st, a, next) next = new_shift_pair(st, a, next)

/*
   \subsection{Paths}

   A path is a pair of a stack and a list of terms. A path represents
   the path from a certain point |p1| in a stack to another point |p2|
   in a stack such that |p2| is reachable from |p1| and the list of
   terms are the terms encountered in the links in reverse order.
   Paths are used in reductions.

*/
typedef term path;
typedef term paths;

#define new_path(st, sons, ps) TBmake("[path(%t,%t),%l]", st, sons, ps)
#define P_STACK(p)             elm1(fun_args(p))
#define P_ARGS(p)              elm2(fun_args(p))
#define P_NEXT(ps)             next(ps)

/*
  The concatenation of two paths
*/
path *conc_paths(paths *ps1, paths *ps2)
{
  path *ps;
  if (ps1 == NULL) return ps2;
  if (ps2 == NULL) return ps1;
  for (ps = ps1; P_NEXT(ps) != NULL; ps = P_NEXT(ps)) ;
  P_NEXT(ps) = ps2;
  return ps1;
}
/*
   \paragraph{Find Paths}

   Function |find_paths| yields all paths from stack |st| with length
   |i|, containing link |l| if |link_seen| is |TRUE|.

*/
path *find_paths(stack *st, int i, st_link *l0, bool link_seen, term *sons)
{
  st_links *ls = NULL;
  st_link  *l1 = NULL;
  term *paths = NULL;
  term *newsons = NULL;

  if (debugflag)  fprintf(log, "find_paths(%d, %d, x, %d, %d)\n",
                          STATE(st), i, link_seen, (int) sons);
  if (st == NULL)
    paths = NULL;
  else if (i == 0 && link_seen)
    paths = new_path(st, sons, NULL);
  else if (i > 0)
    for (ls = LINKS(st); ls != NULL; ls = next(ls)) {
      l1 = first(ls);
      newsons = cons(TREE(l1), sons);
      paths = conc_paths(find_paths(STACK(l1), i - 1, l0,
                                    link_seen || (l0 == l1),
                                    newsons),
                         paths);
    }
  return paths;
}

/*
   \subsection{The Interpreter}

   The state of the parser is stored in the following global variables.

*/
parse_table *table;
int        current_token;
stack       *accepting_stack;
stacks      *active_stacks;
stacks      *for_actor;
stacks      *for_actor_delayed;
shift_pair  *for_shifter;

/*
   Predeclaration of the auxiliary functions.
*/
void parse_character(void);
void actor(stack *);
void do_reductions(stack*, action*);
void reducer(stack *, state, label, term_list *, bool, stack *);
void do_limited_reductions(stack*, action*, st_link*);
void shifter(void);
term *result(void);

/*
   \paragraph{Parse}

   The parse function |parse| parses a text with a parse table |ptable|.
   The text is accesed with the function argument |get_next_char|.

   For each token in the input and while there are still stacks alive,
   i.e., no error is encountered, the parser handles all actions for
   each active stack. The shifts for each stack are stored and
   performed by |do_shifts| after all possible reductions have been
   performed.

   When the end of input is reached or no more stacks are alive,
   parsing is done. The function |result| returns a parse tree error
   message depending on the status.

*/
term *parse(parse_table *ptable, int(*get_next_char)(void))
{
  init_input();
  table = ptable;

  accepting_stack = NULL;
  active_stacks = new_stacks(new_stack(INIT(table), NULL), NULL);
  TBprotect(&active_stacks);
  TBprotect(&accepting_stack);

  do {
    if(show_stack) stacks_to_dotfile(active_stacks);
    current_token = next_token(get_next_char);
    parse_character();
    shifter();
    if(gc) TBcollect();
  } while (current_token != eof && active_stacks != NULL);

  if(show_stack) stacks_to_dotfile(mk_list(accepting_stack, NULL));

  TBunprotect(&active_stacks);
  TBunprotect(&accepting_stack);
  return result();
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
term *result(void)
{
  if (accepting_stack != NULL) {
     term *t;

   add_stack(accepting_stack, active_stacks);
   active_stacks = NULL;

       t = TREE(first(LINKS(accepting_stack)));
      return TBmake("parsetree(%t,%d)", t, nr_ambiguities);
  } else
    return TBmake("parse-error([character(%d), line(%d),"
                  "col(%d), char(%d)])",
                  current_token, line, col, text_length);

}
/*
   \paragraph{Parse Character}

   For each stack on |active_stacks| handle the actions for the
   current token.
*/

void parse_character(void)
{
  stack *st;

  for_actor = active_stacks;
  for_actor_delayed = NULL;
  for_shifter = NULL;

  zero_stack_hist();
  while(for_actor != NULL  || for_actor_delayed != NULL) {
   if(for_actor != NULL)
      pop(st, for_actor);
    else
      pop(st, for_actor_delayed);
    actor(st);
    if(show_stack) links_to_dot(stack_dot, st);
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

void actor(stack *st)
{
  actions *as;
  action *a;

#ifdef DEBUG
  bool sr, ar;
  sr = some_rejected(st); ar = rejected(st);
  if(sr != ar) {
    TBprintf(stderr, "\n(RA) state %d: SR (%d) != AR (%d)\n", STATE(st), sr, ar);
    show_stack_rejects(st, 0);
  }
#endif

  if(rejected(st)) {
#ifdef DEBUG
    TBprintf(stderr, "(RA) Rejected state %d: %t\n", STATE(st), TREE(st));
#endif
    return;
  }

  as = ACTIONS(table, STATE(st), current_token);
  while(pop(a, as))
    switch(A_KIND(a)) {
    case SHIFT:
      add_shift_pair(st, A_STATE(a), for_shifter);
      break;
    case REDUCE:
      do_reductions(st, a);
      break;
    case ACCEPT:
       if(!rejected(st))
         accepting_stack = st;
       break;
    case ERROR:
      break;
  }
}

/*
  \paragraph{Reductions}

  Function |do_reductions| performs a reduction for stack |st| with
  production |r|, which has |nr_args| arguments. For each path of length
  |pop| from |st| a new tree is created with production |r| as label
  and the trees along the path as arguments. The new tree is the link
  from a new stack to the stack at the end of the path.
*/
void do_reductions(stack *st, action *a)
{
  path  *p;
  paths *ps;
  label prod;
  prod = A_PROD(a);

  ps = find_paths(st, A_NR_ARGS(a), NULL, TRUE, NULL);
  while(pop(p, ps)) {
    reducer(P_STACK(p), GOTO(table, STATE(P_STACK(p)), prod),
            prod, P_ARGS(p), A_REJECT(a), st);
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

void reducer(stack *st0, state s, label prod, term_list *kids, bool reject, stack *stpt)
{
  term* t;
  st_link *nl;
  stack *st1;

  if(rejected(stpt)) return;

  t = apply(table, prod, kids);

  if(debugflag)
    TBprintf(log, "reducing %t\n", dot_term_yield(t));

  if((st1 = find_stack(s, active_stacks)) != NULL) {
    if((nl = find_direct_link(st1, st0)) != NULL) {
      /* ambiguity */
      if(debugflag)  TBprintf(log, "direct link found\n");
      if (!reject)      /* Don't bother to represent rejects prods -- J$ */
        amb(TREE(nl), t);
      else {
        mark_link_rejected1(st1, nl);
/*
        TBprintf(stderr,"  Rejects: st0 (state %d): %d/%d, st1 (state %d): %d/%d\n",
                        STATE(st0), some_rejected(st0), rejected(st0),
                        STATE(st1), some_rejected(st1), rejected(st1));
*/
        propagate_reject(st1);
      }
    } else {
      /* add new direct link from |st1| to |st0| and
         recheck all reductions for |st1|. */
      stacks *sts = NULL;
      stack  *st2 = NULL;

      /* First check if one of the children of |st1| was not rejected already */
      add_link(st1, t, st0, nl);
      if (reject) {
        if(debugflag)  TBprintf(log, "rejected [amb]\n");
        mark_link_rejected2(st1, nl);
      }
      sts = active_stacks;
      while(pop(st2, sts)) {
        actions *as;
        action *a;
        if(!rejected(st2) && !in_stacks(st2, for_actor)
           && !in_stacks(st2, for_actor_delayed)) {
          as = ACTIONS(table, STATE(st2), current_token);
          while(pop(a, as))
            if(A_KIND(a) == REDUCE)
              do_limited_reductions(st2, a, nl);
        }
      }
    }
  } else {  /* new stack */
    st1 = new_stack(s, NULL);
    add_link(st1, t, st0, nl);
    add_stack_hist(stpt, st1);
    add_stack(st1, active_stacks);
    add_stack(st1, for_actor_delayed);
    if (reject) {
      if(debugflag)  TBprintf(log, "rejected [new]\n");
      mark_stack_rejected(st1, nl);
    }
  }
} /* reducer */

/*
  \paragraph{Do Limited Reductions}

  Only those reductions that have a path containing link |l|
*/
void do_limited_reductions(stack *st, action *a, st_link *l)
{
  path  *p;
  paths *ps;
  label prod;
  prod = A_PROD(a);

  ps = find_paths(st, A_NR_ARGS(a), l, FALSE, NULL);
  while(pop(p, ps)) {
    reducer(P_STACK(p), GOTO(table, STATE(P_STACK(p)), prod),
            prod, P_ARGS(p), A_REJECT(a), st);
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
void shifter(void)
{
  term *t;
  stack *st0, *st1;
  term *shift_pair;
  state s;
  st_link *l;

  active_stacks = NULL;
  t = PROD(table, current_token);

  while(pop(shift_pair, for_shifter)) {
    s = SP_STATE(shift_pair);
    st0 = SP_STACK(shift_pair);
    if(!rejected(st0)) {
      if((st1 = find_stack(s, active_stacks)) == NULL) {
        st1 = new_stack(s, NULL);
        add_stack(st1, active_stacks);
      }
      add_link(st1, t, st0, l);
      if(show_stack) links_to_dot(stack_dot, st1);
    }
//  else TBprintf(stderr,"Shifter: rejected stack %d\n", STATE(st0));
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

typedef struct stackpair {
        stack   *parent;
        stack   *kid;
        struct stackpair *next;
} stack_pair;

stack_pair    *stack_hist = NULL;

void zero_stack_hist()
{
  stack_pair *sp;

  while(stack_hist != NULL) {
    sp = stack_hist;
    stack_hist = sp->next;
    free(sp);
  }
}

void add_stack_hist(stack *parent, stack *kid)
{
  stack_pair *sp;

  if((sp = malloc(sizeof(stack_pair))) == 0) {
    fprintf(stderr, "add_stack_hist: fatal error\n");
    exit(1);
  } else {
    sp->parent = parent;
    sp->kid    = kid;
    sp->next   = stack_hist;
    stack_hist = sp;
  }
}

void show_stack_hist()
{
  stack_pair *sp = stack_hist;

  while(sp != NULL) {
    TBprintf(stderr, "%d%s induced %d%s\n",
                     STATE(sp->parent), rejected(sp->parent)?"r":"",
                     STATE(sp->kid), rejected(sp->kid)?"r":"");
    sp = sp->next;
  }
}

void propagate_reject(stack *st)
{
  stack_pair *sp = stack_hist;

  while(sp != NULL) {
    if(sp->parent == st) {
      st_links *ls = LINKS(sp->kid);

      if(accepting_stack == sp->kid) accepting_stack = NULL;
      mark_stack_rejected(sp->kid, first(ls));
      propagate_reject(sp->kid);
    }
    sp = sp->next;
  }
}


/*
 *  A few diagnostic routines
 */

#ifdef DEBUG

void show_active_stack_states(signed int c)
{
  stacks *astks = active_stacks;
  stack  *stk;
  static int level = 0;

  level = (level>1)?(level+c):0;
  fprintf(stderr, "%*.*s%cActive states: ", level, level, "", c>0?'+':'-');
  while(astks != NULL) {
    pop(stk, astks);
    TBprintf(stderr, "%d%s ", STATE(stk), rejected(stk)?"r":"");
  }
  TBprintf(stderr, "\n");
}

void show_stack_rejects(stack *st, int depth)
{
  st_links *ls = LINKS(st);
  st_link *l;

//  if(depth > 666) return;

  for (; ls != NULL; ls = next(ls)) {
    l = first(ls);
    fprintf(stderr, "%*.*s%s state %d ==> state %d\n", 2*depth, 2*depth,
                    "", REJECTED(l)?"+":"-", STATE(st), STATE(STACK(l)));
    show_stack_rejects(STACK(l), depth+1);
  }
}


void show_active_stack_links()
{
  stacks *astks = active_stacks;
  stack  *stk;

  while(astks != NULL) {
    pop(stk, astks);
    show_stack_rejects(stk,2);
  }
}

#endif /* DEBUG */
