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
#ifdef HAVE_A2TOA1
  #include <a2toa1.h>
#endif

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
size_t line;           /* current line */
size_t col;            /* current column */
size_t sg_tokens_read; /* number of tokens read */
size_t sg_numtokens;   /* number of tokens in input file */
#define eof 0

/*
   By definition we say that the start of the input is at
   column zero of line one,and there are 0 ambiguities
*/
void SG_InitInput(void)
{
  line        = 1;
  col         = 0;
  sg_tokens_read = 0;
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
  sg_tokens_read++;
/*
  if(SG_VERBOSE && (sg_numtokens != -1)) {
    if(sg_tokens_read > sg_numtokens)
      ATfprintf(stderr, "\nall %d tokens read\n", sg_tokens_read-1);
    else if (!((sg_tokens_read % sg_numtokens/78)))
      ATfprintf(stderr, ".");
  }
 */
  switch(c) {
    case '\n' : line++; col = 0         ; break;
    case '\t' : col = (col / 8 + 1) * 8 ; break;
    case EOF  : c = eof                 ; break;
    default   : col++                   ; break;
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
    ATprotect((ATerm *) &(p->args));
  }
  return p;
}

void SG_ClearPath(path *p)
{
  path *oldp;

  while(p) {
    oldp = p;
    p = p->next;
    ATunprotect((ATerm *) &(oldp->args));
    SG_free(oldp);
  }
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

/*
  if (SG_DEBUG)
    ATfprintf(SGlog(), "SG_FindPaths(%d, %d, x, %d, %x)\n",
              SG_ST_STATE(st), i, link_seen, (int) sons);
*/
  if (st == NULL) {
    paths = NULL;
  } else if (i == 0 && link_seen) {
    paths = SG_NewPath(st, sons, NULL);
  } else if (i > 0) {
    for (ls = SG_ST_LINKS(st); ls != NULL; ls = SG_TAIL(ls)) {
      l1 = SG_HEAD(ls);
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
ATerm SG_Prune(ATerm t, char *sort);
ATerm SG_Result(char *sort);

void  SG_ParserPreparation(void)
{
  SG_InitInput();
  accepting_stack = NULL;
  SG_MaxNrAmb(SG_NRAMB_ZERO);
  SGnrAmb(SG_NRAMB_ZERO);
  active_stacks = SG_NewStacks(SG_NewStack(SG_INIT(table), NULL));
}

void  SG_ParserCleanup(void)
{
  if(SG_GC)
    SG_PurgeOldStacks(SG_AddStack(accepting_stack, active_stacks), NULL, NULL);
  active_stacks   = NULL;
  accepting_stack = NULL;
  SG_AmbTable(SG_AMBTBL_CLEAR, NULL, NULL);
}

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
ATerm SG_Parse(parse_table *ptable, char *sort, int(*get_next_char)(void))
{
  ATerm result;

  table = ptable;

  SG_ParserPreparation();

  do {
    if(SG_SHOWSTACK) SG_StacksToDotFile(active_stacks, sg_tokens_read);
    current_token = SG_NexToken(get_next_char);
    if(SG_DEBUG) {
      if(isprint(current_token))
        ATfprintf(SGlog(), "Token: '%c'\n", current_token);
      else
        ATfprintf(SGlog(), "Token: '\\%d'\n", current_token);
    }
    SG_ParseChar();
    SG_Shifter();
  } while (current_token != eof && active_stacks != NULL);

  if(SG_VERBOSE)
    ATfprintf(stderr, "parsing finished, read %d tokens\n", sg_tokens_read-1);

  if(SG_SHOWSTACK)
    SG_StacksToDotFile(SG_NewStacks(accepting_stack), sg_tokens_read);

  result = SG_Result(sort);
  SG_ParserCleanup();

  return result;
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

char *SG_ApplSort(ATerm t)
{
  char *sort;

  if(ATmatch(t, "appl(prod([<term>,cf(sort(<str>)),<term>],<term>,<term>),"
                "<list>)",
         NULL, &sort, NULL, NULL, NULL, NULL)) {
    return sort;
  }
  if(ATgetAFun((ATermAppl) t) == SG_AmbAFun())
    return("[multiple sorts]"); 

  return NULL;
}

ATerm SG_Prune(ATerm forest, char *desiredsort)
{
  /*  Prune the forest  */
  ATermList trees, bonsai = ATempty;
  ATerm     tree;
  char      *sort;
  ATbool    AmbStart;

  /*  Is the top node an ambiguity node?  If so, all trees in it must be done.  */
  if(!(AmbStart = ATmatch(forest, "amb([<list>])", &trees))) {
    trees = ATmakeList1(forest);
  }

  for(; !ATisEmpty(trees); trees=ATgetNext(trees)) {
    tree = ATgetFirst(trees);
    sort = SG_ApplSort(tree);
    if(sort != NULL) {
      if(!strcmp(desiredsort, sort)) {
        bonsai = ATinsert(bonsai, tree);
      }
    }
  }
  if(!ATisEmpty(bonsai)) {
    if(AmbStart) {
      if(ATgetLength(bonsai) > 1) {
        return ATmake("amb([<list>])", bonsai);
      } else {
        SGnrAmb(SG_NRAMB_DEC);
        return ATgetFirst(bonsai);
      }
    } else {
       return ATgetFirst(bonsai);
    }
  } else {    /*  Nothing left  */
    SGnrAmb(SG_NRAMB_ZERO);
    return NULL;
  }
}

char *SGsort(int Mode, ATerm t)
{
  static char *sort = NULL;

  switch(Mode)
  {
    case SG_GET:
      break;
    case SG_SET:
      sort = SG_ApplSort(t);
      break;
  }
  return sort;
}

ATerm SG_Result(char *sort)
{
  ATbool    was_abbrev;
  ATermList cycle;

  if (accepting_stack != NULL) {
    ATerm forest;

    forest = SG_LK_TREE(SG_HEAD(SG_ST_LINKS(accepting_stack)));

   if(!ATisEmpty(cycle = SG_CyclicTerm(forest)))
     return ATmake("parse-error([character(<int>), line(<int>),"
                   "col(<int>), char(<int>)],cycle(<term>))",
                   current_token, line, col, sg_tokens_read, cycle);


// ATfprintf(stderr, "Unexpanded Forest: %t\n", forest);

    /*  We _must_ expand at least the top node to get the top sort  */
    was_abbrev = SG_ABBREV;
    SG_ABBREV_OFF();
    forest = (ATerm) SG_ExpandApplNode(table, (ATermAppl) forest, ATfalse);
    if(was_abbrev) SG_ABBREV_ON();

    /*  Select only the desired start symbols when so requested  */
    if (sort!=NULL && !SG_ABBREV && (forest = SG_Prune(forest, sort))==NULL)
        return ATmake("parse-error([character(<int>), line(<int>),"
                      "col(<int>), char(<int>)])",
                      current_token, line, col, sg_tokens_read);

    SGsort(SG_SET, forest);

    if(!SG_OUTPUT)  /*  Ambiguity count > 0 is an upper limit in this case  */
      forest = ATmake("parsetree(suppressed,<int>)", SG_MaxNrAmb(SG_NRAMB_ASK));
    else {          /*  An exact ambiguity count can be given  */
      forest = SG_YieldPT(table, forest);
      forest = ATmake("parsetree(<term>,<int>)", forest, SGnrAmb(SG_NRAMB_ASK));
      SGsort(SG_SET, ATgetArgument((ATermAppl) forest, 0));
#ifdef HAVE_A2TOA1
      if(SG_ASFIX1) {
        if(SGnrAmb(SG_NRAMB_ASK) > 0) {
          ATfprintf(stderr, "error: cannot represent parse forest "
                            "(%d ambiguit%s) in AsFix1\n",
                    SGnrAmb(SG_NRAMB_ASK), SGnrAmb(SG_NRAMB_ASK)==1?"y":"ies");
          return ATmake("parse-error([character(<int>), line(<int>),"
                        "col(<int>), char(<int>)])",
                        current_token, line, col, sg_tokens_read);
        }
        if (SG_VERBOSE)
          ATfprintf(stderr, "converting AsFix2 parse tree to AsFix1\n");
        forest = a2toa1(forest);
      }
#endif
    }

    return forest;
  } else
    return ATmake("parse-error([character(<int>), line(<int>),"
                  "col(<int>), char(<int>)])",
                  current_token, line, col, sg_tokens_read);
}

/*
   \paragraph{Parse Character}

   For each stack on |active_stacks| handle the actions for the
   current token.
*/

void SG_ParseChar(void)
{
  stack   *st;

  for_actor = active_stacks;
  for_actor_delayed = NULL;
  for_shifter = NULL;

/*
  ATfprintf(stderr, "p_c: %d\n", current_token);
*/

  while(for_actor != NULL  || for_actor_delayed != NULL) {
    if(for_actor != NULL) {
      st = SG_HEAD(for_actor);
      for_actor = SG_TAIL(for_actor);
    } else {
      st = SG_HEAD(for_actor_delayed);
      for_actor_delayed = SG_TAIL(for_actor_delayed);
    }
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

  if(SG_Rejected(st))
    return;

  as = SG_LookupAction(table, SG_ST_STATE(st), current_token);
/*
  ATfprintf(stderr, "SG_Actor: actions[%d,%d] = %t\n", SG_ST_STATE(st), current_token, as);
*/
  for(; as != NULL && !ATisEmpty(as); as = ATgetNext(as)) {
    a = ATgetFirst(as);
    switch(SG_ActionKind(a)) {
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
      default:
      case ERROR:
        ATfprintf(stderr, "SG_Actor: deleting hopeless stack\n");
        SG_DeleteStack(st);
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
  path  *fps, *ps;
  label prod;

  prod = SG_A_PROD(a);

  for(ps = fps = SG_FindPaths(st, SG_A_NR_ARGS(a), NULL, ATtrue, ATempty);
      ps != NULL; ps = SG_P_NEXT(ps)) {
    SG_Reducer(SG_P_STACK(ps),
               SG_LookupGoto(table, SG_ST_STATE(SG_P_STACK(ps)), prod),
               prod, SG_P_ARGS(ps), SG_A_REJECT(a), st);
  }
  SG_ClearPath(fps);
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

  t = SG_Apply(table, prodl, kids, reject);

  if(SG_DEBUG) ATfprintf(SGlog(), "Reducing %t\n", SG_TermYield(t));

  /*  A stack with state s already exists?  */
  if((st1 = SG_FindStack(s, active_stacks)) == NULL) {
    /*  No existing stack for state s: new stack  */
    st1 = SG_NewStack(s, stpt);
    nl  = SG_AddLink(st1, st0, t);
    SG_AddStackHist(stpt, st1);
    active_stacks = SG_AddStack(st1, active_stacks);
    for_actor_delayed = SG_AddStack(st1, for_actor_delayed);
    if (reject) {
      if(SG_DEBUG)  ATfprintf(SGlog(), "Rejected [new]\n");
      SG_MarkStackRejected(st1);
    }
    return;
  }

  /*  A stack with state s already exists.  */
  /*  Ambiguity?  */
  if((nl = SG_FindDirectLink(st1, st0)) != NULL) {
    if(SG_DEBUG)
      ATfprintf(SGlog(), "Ambiguity: Direct link %d -> %d%s\n",
                          SG_ST_STATE(st0), SG_ST_STATE(st1),
                          reject?" {reject}":"");
    /*  Reject?  */
    if (reject) {     /*  J$: Don't bother representing rejects  */
      if (SG_DEBUG)
        ATfprintf(SGlog(), "Rejecting %t\n", t);
      SG_PropagateReject(st1);
      return;
    }
    /*  No reject.  */
    /*
      The existing stack may already be rejected; in this case, no
      amb-node should be created (and the existing stack may have to
      be "unrejected"?).  However, if this stack was directly created
      by a reject production, it has to remain rejected.
     */
    /*  No reject, but in an ambiguity cluster with a rejected stack?  */
    if(SG_Rejected(st1)) {
/*
      ATfprintf(stderr, "Warning: zombie stack (%d)?\n", SG_ST_STATE(st0));
 */
      SG_MarkStackRejected(st0);
      return;
    }
    /* No reject, and not sharing ambiguity with a reject  */
    SG_Amb(table, (ATermAppl) SG_LK_TREE(nl), (ATermAppl) t);
#ifdef DEBUG
    SG_ShowStackOffspring(st1);
#endif
    return;
  } else {
    /*  No ambiguity.  */
    /*  Add new direct link from |st1| to |st0| and
        recheck all reductions for |st1|. */
    stacks *sts = active_stacks;
    stack  *st2 = NULL;

    /* First check if one of the children of |st1| was not rejected already */
    nl = SG_AddLink(st1, st0, t);
    if(SG_DEBUG && SG_Rejected(st1)) {
      ATfprintf(SGlog(),"Stack %x (state %d) was already rejected\n",
                st1, SG_ST_STATE(st1));
    }
    /*  Reject?  */
    if (reject) {
      if(SG_DEBUG)
        ATfprintf(SGlog(), "Warning: stack %d rejected in presence of "
                           "other links (linked to stack %d)\n",
                  SG_ST_STATE(st0), SG_ST_STATE(st1));
      SG_MarkStackRejected(st0);
#ifdef DEBUG
      ATfprintf(stderr, "Stack 0 (%x):\n", st0); SG_ShowStack(st0, 1);
      ATfprintf(stderr, "Stack 1 (%x):\n", st1); SG_ShowStack(st1, 1);
#endif
    }
    while(sts != NULL) {
      actions as;
      action a;

      st2 = SG_HEAD(sts);
      sts = SG_TAIL(sts);
#ifdef	DEBUG
      if(SG_Rejected(st2)) {
        if(SG_DeeplyRejected(st2))
          ATfprintf(stderr,"Active Stack %x (state %d) is deeply rejected\n",
                    st2, SG_ST_STATE(st2));
        else
          ATfprintf(stderr,"Active Stack %x (state %d) is shallowly rejected\n",
                    st2, SG_ST_STATE(st2));
	ATfprintf(stderr, "Stack 2 (%x):\n", st2); SG_ShowStack(st2, 1);
      }
#endif
      if(!SG_DeeplyRejected(st2)) {
        if(!SG_InStacks(st2, for_actor, ATfalse)
         && !SG_InStacks(st2, for_actor_delayed, ATfalse)) {
          as = SG_LookupAction(table, SG_ST_STATE(st2), current_token);
          for(; as && !ATisEmpty(as); as = ATgetNext(as)) {
            a = ATgetFirst(as);
            if(SG_ActionKind(a) == REDUCE)
              SG_DoLimitedReductions(st2, a, nl);
          }
        }
      }
    }
    return;
  }
  ATfprintf(stderr, "Warning: flow error in Reducer\n");
}   /*  Reducer  */

/*
  \paragraph{Do Limited Reductions}

  Only those reductions that have a path containing link |l|
*/
void SG_DoLimitedReductions(stack *st, action a, st_link *l)
{
  path  *fps, *ps;
  label prod;

  prod = SG_A_PROD(a);

  for(ps = fps = SG_FindPaths(st, SG_A_NR_ARGS(a), l, ATfalse, ATempty);
      ps != NULL; ps = SG_P_NEXT(ps)) {
    SG_Reducer(SG_P_STACK(ps),
               SG_LookupGoto(table, SG_ST_STATE(SG_P_STACK(ps)), prod),
               prod, SG_P_ARGS(ps), SG_A_REJECT(a), st);
  }
  SG_ClearPath(fps);
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
  ATerm  t;
  stack  *st0, *st1;
  stacks *new_active_stacks = NULL;
  shift_pair *shift_pair;
  state s;
  st_link *l;

  t = SG_LookupProduction(table, current_token);

  for(shift_pair = for_shifter; shift_pair != NULL;
      shift_pair = SG_SP_NEXT(shift_pair)) {
    s = SG_SP_STATE(shift_pair);
    st0 = SG_SP_STACK(shift_pair);
    if(!SG_Rejected(st0)) {
      if((st1 = SG_FindStack(s, new_active_stacks)) == NULL) {
        st1 = SG_NewStack(s, NULL);
        new_active_stacks = SG_AddStack(st1, new_active_stacks);
      }
      l = SG_AddLink(st1, st0, t);
      if(SG_SHOWSTACK) SG_LinksToDot(SG_StackDot(), st1);
    } else if (SG_DEBUG)
      ATfprintf(SGlog(), "Shifter: skipping rejected stack %d\n",
                SG_ST_STATE(st0));
  }

  if(SG_GC)
    SG_PurgeOldStacks(active_stacks, new_active_stacks, accepting_stack);

  if((active_stacks = new_active_stacks) == NULL && SG_DEBUG)
      ATfprintf(SGlog(), "Shifter: no more stacks left\n");
} /*  Shifter  */


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
  parent->kidcount++;
  if(parent->kidcount == 1)    /*  First kid  */
    parent->kids = SG_Malloc(sizeof(stack *));
  else                         /*  Consecutive kids  */
    parent->kids = SG_Realloc(parent->kids, parent->kidcount * sizeof(stack *));
  parent->kids[parent->kidcount - 1] = kid;
}

void SG_PropagateReject(stack *st)
{
  ATermList amb, trms, idxs, oldidxs, newtrms = ATempty;
  ATerm     compost, t, i;
  ATermInt  cmpstid;
  int       oldlen, newlen;

  if(st == NULL)
    return;

  compost = SG_LK_TREE(SG_HEAD(SG_ST_LINKS(st)));
  cmpstid = (ATermInt) ATgetAnnotation(compost, SG_ApplLabel()),
  amb = SG_AmbTable(SG_AMBTBL_LOOKUP, cmpstid, NULL);
  if(!ATisEmpty(amb)) {             /*  Ambiguity encountered  */
    if (SG_DEBUG)
      ATfprintf(SGlog(), "Reject: resolving an ambiguity cluster...\n");
    compost = ATremoveAnnotation(compost, SG_ApplLabel());
    trms = (ATermList) ATgetFirst(amb);
    oldlen = ATgetLength(trms);
    idxs = oldidxs = (ATermList) ATelementAt(amb, 1);
    while(trms && !ATisEmpty(trms)) {
      t = ATgetFirst(trms); trms = ATgetNext(trms);
      i = ATgetFirst(idxs); idxs = ATgetNext(idxs);
      if(ATisEqual(compost, t)) {  /*  Ditch term from ambiguity  */
        if (SG_DEBUG)
          ATfprintf(SGlog(), "Removed from ambiguity cluster: %t\n", t);
       } else {
        if (SG_DEBUG)
          ATfprintf(SGlog(), "Keeping in ambiguity cluster: %t\n", t);
        newtrms = ATinsert(newtrms, t);
      }
    }
    /*  Update the full ambiguity cluster  */
    amb = ATmakeList2((ATerm) newtrms, (ATerm) oldidxs);
    for(; !ATisEmpty(oldidxs); oldidxs=ATgetNext(oldidxs)) {
      SG_AmbTable(SG_AMBTBL_UPDATE, (ATermInt)ATgetFirst(oldidxs), amb);
    }
    newlen = ATgetLength(newtrms);
/*
  An ambiguity resolved -- nice, but when yielding (which is driven
  by the maximum of possible ambs -- we might need to substitute
  a rejected term by its non-rejected counterpart in the ambiguity
  cluster
*/
    if(newlen > 0) {
      /*  Don't reject this link/propagate if part of this amb-cluster
          is still valid
       */
      return;
    } /*  If no terms were left in the amb-cluster: reject & propagate  */
  }

  /*  If we get here, either
         - the stack's term wasn't part of an ambiguity cluster
         - the stack's term was in an ambiguity cluster which is
           wiped spotlessly clean by the removal of this term
      In both cases, the reject needs to propagate, and this stack
      must be marked rejected.
   */
  SG_MarkStackRejected(st);

  /*  Propagate for all this stack's kids  */
  if(st->kidcount > 0) {
    int  kididx;

    for(kididx = 0; kididx < st->kidcount; kididx++) {
      if (SG_DEBUG)
        ATfprintf(SGlog(), "Reject: propagating (%d->%d)\n",
                  SG_ST_STATE(st), SG_ST_STATE(st->kids[kididx]));
#if 0
      SG_MarkLinkRejected(SG_HEAD(SG_ST_LINKS(st)));
#endif
      SG_PropagateReject(st->kids[kididx]);
    }
  }
}

#ifdef DOWENEEDTHIS
void SG_PropagateUnreject(stack *st)
{
  ATermList l;
  ATermInt  annot;

ATfprintf(stderr, "unrejecting %x\n", st);
  while(st != NULL) {
    annot = (ATermInt) ATgetAnnotation(SG_LK_TREE(SG_HEAD(SG_ST_LINKS(st))),
                                       SG_ApplLabel());
    l = SG_AmbTable(SG_AMBTBL_LOOKUP, annot, NULL);
    if(!ATisEmpty(l)) {
ATfprintf(stderr, "unreject: %x contains an amb link: %t\n", st, l);
    }
    SG_MarkLinkUnrejected(SG_HEAD(SG_ST_LINKS(st)));
/*
    SG_MarkStackUnrejected(st);
 */
    st = st->kid;
  }
}
#endif

#ifdef DEBUG
/*
 *  A few diagnostic routines (for debugging purposes)
 */

void SG_ShowLinks(st_links *lks, int depth)
{
  for (; lks != NULL; lks = SG_TAIL(lks)) {
    fprintf(stderr, "%*.*s--%x-->\n", 2*depth, 2*depth, "", (int)SG_HEAD(lks));
    SG_ShowStack(SG_LK_STACK(HEAD(lks)), depth+1);
  }
}

void SG_ShowStack(stack *st, int depth)
{
  if (st == NULL) return;
  fprintf(stderr, "%*.*s%x%s %d\n", 2*depth, 2*depth, "", (int)st,
          SG_ST_REJECTED(st)?"R":"", SG_ST_STATE(st));
  SG_ShowLinks(SG_ST_LINKS(st), depth+1);
}

void SG_ShowStacks(stacks *sts)
{
  if(sts == NULL) return;
  while(sts != NULL) {
    SG_ShowStack(SG_HEAD(sts),0);
    sts = SG_TAIL(sts);
  }
}

void SG_ShowStackOffspring(stack *st)
{
  int  kididx;

  if(st == NULL || st->kidcount == 0)
    return;

  ATfprintf(stderr, "State %d%s created...\n",
            SG_ST_STATE(st), SG_Rejected(st)?"R":"");
  for(kididx = 0; kididx < st->kidcount; kididx++) {
    ATfprintf(stderr, "\t... %d%s\n",
              SG_ST_STATE(st->kids[kididx]),
              SG_Rejected(st->kids[kididx])?"R":"");
  }
  for(kididx = 0; kididx < st->kidcount; kididx++)
    SG_ShowStackOffspring(st->kids[kididx]);
}

void SG_ShowStackAncestors(stack *st)
{
  while(st != NULL && st->parent != NULL) {
    ATfprintf(stderr, "\t%d%s induced %d%s\n",
                     SG_ST_STATE(st->parent), SG_Rejected(st->parent)?"R":"",
                     SG_ST_STATE(st), SG_Rejected(st)?"R":"");
    st = st->parent;
  }
}

void SG_ShowActiveStackStates(signed int c)
{
  stacks *astks = active_stacks;
  stack  *stk;
  static int level = 0;

  level = (level>1)?(level+c):0;
  fprintf(stderr, "%*.*s%cActive states: ", level, level, "", c>0?'+':'-');
  while(astks != NULL) {
    stk   =  SG_HEAD(astks);
    astks =  SG_TAIL(astks);
    ATfprintf(stderr, "%x%s ", SG_ST_STATE(stk), SG_Rejected(stk)?"r":"");
  }
  ATfprintf(stderr, "\n");
}

void SG_ShowStackRejects(stack *st, int depth)
{
  st_links *ls = SG_ST_LINKS(st);
  st_link *l;

  if(depth > 666) return;

  for (; ls != NULL; ls = SG_TAIL(ls)) {
    l = SG_HEAD(ls);
/*
    ATfprintf(stderr, "%*.*s%s%x: state %d ==> state %d\n", 2*depth, 2*depth,
              "", SG_LK_REJECTED(l)?"~":" ", (int) l, SG_ST_STATE(st),
              SG_ST_STATE(SG_LK_STACK(l)));
 */
    ATfprintf(stderr, "%*.*s%x: state %d ==> state %d\n", 2*depth, 2*depth,
              "", (int) l, SG_ST_STATE(st), SG_ST_STATE(SG_LK_STACK(l)));
    SG_ShowStackRejects(SG_LK_STACK(l), depth+1);
  }
}


void SG_ShowActiveStackLinks(stacks *astks)
{
  stack  *stk;

  while(astks != NULL) {
    stk   =  SG_HEAD(astks);
    astks =  SG_TAIL(astks);
    SG_ShowStackRejects(stk,2);
  }
}

void SG_ShowShiftPairs()
{
  shift_pair *sp;
  stack *st;

  ATfprintf(stderr, "Shifters:\n");
  for(sp = for_shifter; sp != NULL;
      sp = SG_SP_NEXT(sp)) {
    ATfprintf(stderr, "%d: ", SG_SP_STATE(sp));
    st = SG_SP_STACK(sp);
    SG_ShowStackAncestors(st);
    SG_ShowStackOffspring(st);
  }
}

#endif /* DEBUG */
