/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.

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
/*
 $Id$

 This section contains the implementation of a \emph{generalized LR}
 parser. The main function |SG_Parse| takes a parsetable and an input
 streams as parameters and yields a term, which represents either the
 parse tree or an error message in case of a syntactic error in the
 input.
 */

#include <unistd.h>
#include <string.h>
#include <assert.h>

#include <aterm2.h>

#ifndef NO_A2TOA1
#include <a2toa1.h>
#endif
#include <tree-to-dot.h>
#include <sg_growbuf.h>

#include "parser.h"
#include "forest.h"
#include "mem-alloc.h"
#include "sglr.h"
#include "sglr-strings.h"
#include "rsrc-usage.h"


/*
 A shift pair is a pair of a state and a stack and is used to indicate
 a shift from the stack to a new state.
 */

typedef struct shift_pair {
  state   state;
  stack   *stack;
} shift_pair;

#define SG_SP_STATE(x)                  (x).state
#define SG_SP_STACK(x)                  (x).stack

/*
 A path is a pair of a stack and a list of terms.  A path represents the
 path from a certain point |p1| in a stack to another point |p2| in a
 stack such that |p2| is reachable from |p1| and the list of terms are
 the terms encountered in the links in reverse order.  Paths are used
 in reductions.
 */

typedef struct path {
  stack             *stack;
  ATermList         args;
  struct path       *next;
} path;

#define SG_P_STACK(x)                  (x)->stack
#define SG_P_ARGS(x)                   (x)->args
#define SG_P_NEXT(x)                   (x)->next

/*  The state of the parser is stored in the following global variables  */

parse_table *table;
token        current_token;
stack       *accepting_stack;
stacks      *active_stacks;
stacks      *for_actor;
stacks      *for_actor_delayed;

#define GC_CYCLE 200
stacks      *old_active_stacks[GC_CYCLE];

/* Prototypes for the auxiliary functions  */

void      SG_ParseToken(void);
void      SG_Actor(stack *);
ATbool    SG_CheckLookAhead(lookahead la);
void      SG_DoReductions(stack*, action);
#ifndef DEBUG
void    SG_Reducer(stack *st0, state s, label prodl, ATermList kids,
                   int attr);
#else
void    SG_Reducer(stack *st0, state s, label prodl, ATermList kids,
                   int attr, stack *stpt);
#endif
void      SG_DoLimitedReductions(stack*, action, st_link*);
void      SG_Shifter(void);
ATermList SG_CurrentPosInfo(void);
forest    SG_ParseError(ATermList cycle, int excess_ambs, ATerm ambtrak);
forest    SG_ParseResult(char *sort);

/*
 Some global vars, used for collecting statistics
 */

size_t num_reductions = 0;

/*
 The input for the parser is a list of tokens closed by an end of
 file symbol |SG_EOF|.  The list is accessed by means of a function that
 produces the next token in the list.  The function is a parameter of
 the |SG_NextToken| function and can be determined by the caller of the
 parser.

 For the purpose of error messages we keep track of the current line
 and column.
 */

size_t line;           /* current line */
size_t col;            /* current column */
size_t sg_tokens_read; /* number of tokens read */
size_t sg_total_tokens; /* total number of tokens */
/*  By definition the start of the input is at column zero of line one  */

void SG_ResetCoordinates(void)
{
  line           = 1;
  col            = 0;
}

void SG_InitInput(void)
{
  SG_ResetCoordinates();
  sg_tokens_read = 0;
}


#define     SG_SP_CHUNK 16
shift_pair  *sg_shift_pairs = NULL;
int         sg_sp_max = 0, sg_sp_maxidx, sg_sp_idx, sg_sp_maxtoken,
sg_sp_maxline, sg_sp_maxcol, sg_sp_maxoffset;

void SG_AddShiftPair(stack *st, state s)
{
  if(sg_shift_pairs == NULL) {
    sg_sp_max = SG_SP_CHUNK;
    sg_shift_pairs = SG_Malloc(SG_SP_CHUNK, sizeof(shift_pair));
  }
  if(sg_sp_idx >= sg_sp_max) {
    sg_sp_max += SG_SP_CHUNK;
    sg_shift_pairs = SG_Realloc(sg_shift_pairs, sg_sp_max, sizeof(shift_pair));
  }
  sg_shift_pairs[sg_sp_idx].stack = st;
  sg_shift_pairs[sg_sp_idx].state = s;
  sg_sp_idx++;
  IF_STATISTICS(
    if(sg_sp_idx > sg_sp_maxidx) {
      sg_sp_maxidx    = sg_sp_idx;
      sg_sp_maxtoken  = current_token;
      sg_sp_maxline   = line;
      sg_sp_maxcol    = col;
      sg_sp_maxoffset = sg_tokens_read;
    }
  );
}

void  SG_DiscardShiftPair(void)
{
  sg_sp_idx--;
}

void  SG_DiscardShiftPairs(void)
{
  sg_sp_idx = 0;
}

path *SG_NewPath(stack *st, ATermList sons, path *ps)
{
  path *p;

  if((p = SG_Malloc(1, sizeof(path)))) {
    p->stack = st;
    p->args  = sons;
    p->next  = ps;
    ATprotect((ATerm *) &(p->args));
  }
  return p;
}

void SG_ClearPath(register path *p)
{
  path *oldp;

  while(p) {
    oldp = p;
    p = p->next;
    ATunprotect((ATerm *) &(oldp->args));
    SG_Free(oldp);
  }
}

/*
 Function |SG_FindAllPaths| yields all paths from stack |st| with length
 |nrArgs|.
 */

static path *SG_FindAllPaths(stack *st, int nrArgs, ATermList sons, path *paths)
{
  register st_links  *ls = NULL;
  ATermList newsons = NULL;

  if (!st) {
    return paths;
  }

  if (nrArgs == 0) {
    paths = SG_NewPath(st, sons, paths);
  }
  else if (nrArgs > 0) {
    for (ls = SG_ST_LINKS(st); ls; ls = SG_TAIL(ls)) {
      st_link *l = SG_HEAD(ls);
      newsons = ATinsert(sons, (ATerm) SG_LK_TREE(l));
      paths = SG_FindAllPaths(SG_LK_STACK(l), nrArgs - 1, newsons, paths);
    }
  }
  return paths;
}

/*
 Function |SG_FindLinks| searches all paths from stack |st| with length
 |nrArgs|, until link |l0| is found.
 */

static ATbool SG_FindLink(stack *st, int nrArgs, st_link *l0)
{
  register st_links  *ls = NULL;
  st_link   *l1 = NULL;

  if (nrArgs > 0) {
    for (ls = SG_ST_LINKS(st); ls; ls = SG_TAIL(ls)) {
      l1 = SG_HEAD(ls);
      if (l0 == l1 || SG_FindLink(SG_LK_STACK(l1), nrArgs - 1, l0)) {
        return ATtrue;
      }
    }
  }
  return ATfalse;
}

/*
 Function |SG_FindPaths| yields all paths from stack |st| with length
 |nrArgs|, containing link |l0| if |link_seen| is |ATtrue|.
 */

static path *SG_FindPaths(stack *st, int nrArgs, st_link *l0, ATbool link_seen,
                   ATermList sons, path *paths)
{
  register st_links  *ls = NULL;
  st_link   *l1 = NULL;
  ATermList newsons = NULL;

  if (!st) {
    return paths;
  }

  if (nrArgs == 0 && link_seen) {
    paths = SG_NewPath(st, sons, paths);
  }
  else if (nrArgs > 0) {
    for (ls = SG_ST_LINKS(st); ls; ls = SG_TAIL(ls)) {
      l1 = SG_HEAD(ls);
      newsons = ATinsert(sons, (ATerm) SG_LK_TREE(l1));
      paths = SG_FindPaths(SG_LK_STACK(l1), nrArgs - 1, l0,
                           link_seen || (l0 == l1), newsons, paths);
    }
  }
  return paths;
}                        

/*
 Function |SG_FindLimitedPaths| first checks if the link |l0|
 is present in the stack, if so it finds the appropriate paths.
 */

path *SG_FindLimitedPaths(stack *st, int nrArgs, st_link *l0)
{
  if (SG_FindLink(st, nrArgs, l0)) {
    return SG_FindPaths(st, nrArgs, l0, ATfalse, ATempty, NULL);
  }
  else {
    return NULL;
  }
}

/*
 The function |SG_NextToken| reads the next token from the stream
 provided by the parameter function |get_next_token| and updates the
 line and column values taking account of newlines |\n|, tabs |\t| and
 end-of-file |SG_EOF|.
 */

token SG_NextToken(int(*get_next_token)(void))
{
  int c;

  c = get_next_token();
  sg_tokens_read++;
  switch(c) {
    case '\n' : line++; col = 0         ; break;
    case '\t' : col = (col / 8 + 1) * 8 ; break;
    case SG_EOF:
    case EOF  : return SG_EOF_Token     ;
    default   : col++                   ; break;
  }
  return SG_MAKETOKEN(c);
}

long   sg_major, sg_minor;
size_t sg_nr_rejects;

void  SG_ParserPreparation(void)
{
  SG_InitInput();
  SGsort(SG_UNSET, NULL);
  accepting_stack = NULL;
  num_reductions = sg_sp_idx = sg_sp_maxidx = 0;
  SG_MaxNrAmb(SG_NR_ZERO);
  SGnrAmb(SG_NR_ZERO);
#ifdef  MEMSTATS
  IF_STATISTICS(SG_ZeroAllocStats());
#endif
#ifndef DEBUG
  active_stacks = SG_NewStacks(SG_NewStack(SG_PT_INITIAL(table), ATfalse));
#else
  active_stacks = SG_NewStacks(SG_NewStack(SG_PT_INITIAL(table), NULL, ATfalse));
#endif
  SG_ERROR_OFF();
  IF_STATISTICS(
    SG_PageFlt(&sg_major, &sg_minor);
    SG_Timer();
  );
}

void SG_PostParse(void)
{
  IF_STATISTICS(
    double ptm;

    ptm = SG_Timer();

    fprintf(SG_log(), "Number of lines: %ld\n", (long) line);
    fprintf(SG_log(), "Maximum of %d parse branches reached at token ",
            sg_sp_maxidx);
    SG_PrintToken(SG_log(), sg_sp_maxtoken);
    fprintf(SG_log(), ", line %d, column %d (token #%d)\n",
            sg_sp_maxline, sg_sp_maxcol, sg_sp_maxoffset);

    fprintf(SG_log(), "Parse time: %.2fs\n", ptm);
    fprintf(SG_log(), "Characters/second: %.0f\n",
            ptm < 1.0e-4 ? 0 : sg_tokens_read/ptm);

    fprintf(SG_log(), "Number of rejects: %ld\n", (long) sg_nr_rejects);

    fprintf(SG_log(), "Number of reductions: %ld\n", (long) num_reductions);
    fprintf(SG_log(), "Number of reductions/sec: %.0f\n",
       ptm < 1.0e-04 ? 0 : (double) num_reductions/ptm);
    fprintf(SG_log(), "Number of reductions/token: %f\n",
            (double) num_reductions/(double)sg_tokens_read);
    fprintf(SG_log(), "Number of ambiguities: %d\n",
            SG_MaxNrAmb(SG_NR_ASK));
    fprintf(SG_log(), "Number of calls to Amb: %d\n",
            SG_AmbCalls(SG_NR_ASK));
  );
}

void SG_PostParseResult(void)
{
  IF_STATISTICS(    
    long allocated;

    if(SG_FILTER) {
      fprintf(SG_log(), "MultiSet Comparisons: total %d, successful %d\n",
              SG_MultiSetGtrCalls(SG_NR_ASK),
              SG_MultiSetFilterSucceeded(SG_NR_ASK));
      fprintf(SG_log(), "Number of Injection Counts: total %d, successful %d\n",
              SG_InjectionCountCalls(SG_NR_ASK),
              SG_InjectionFilterSucceeded(SG_NR_ASK));
    }

    fprintf(SG_log(), "Minor page faults: %ld\n", sg_minor);
    fprintf(SG_log(), "Major page faults: %ld\n", sg_major);

    if(sg_minor > 0)
    fprintf(SG_log(), "Characters/minor fault: %ld\n", sg_tokens_read/sg_minor);

    allocated = SG_Allocated();
    if(allocated > 0)
    fprintf(SG_log(), "[mem] extra ATerm memory allocated while parsing: %ld\n",
            allocated);
  );

  if(SG_SHOWSTACK) {
    SG_StacksToDotFile(SG_NewStacks(accepting_stack), sg_tokens_read);
    SG_StacksToDotFileFinalize(SG_StackDot());
  }
}

void  SG_ParserCleanup(void)
{
  long allocated;

  if (SG_GC) {
    SG_CollectOldStacks(old_active_stacks, sg_tokens_read % GC_CYCLE, 
			NULL, accepting_stack);
  }

#if !defined(HAVE_BOEHMGC)
  if(SG_GC)
    if(accepting_stack)
      SG_ClearStack(accepting_stack);
#endif

  active_stacks   = NULL;
  accepting_stack = NULL;
  SG_AmbTable(SG_AMBTBL_CLEAR, NULL, NULL);
#ifdef  MEMSTATS
  IF_STATISTICS(
    if(SG_GC)
    SG_PrintCurAllocStats();
    SG_PrintMaxAllocStats();
  );
#endif
    IF_STATISTICS(
      allocated = SG_Allocated();
      if(allocated > 0)
        fprintf(SG_log(), "[mem] extra ATerm memory allocated for parse tree: %ld\n",
                allocated);
    );
#if 0
    /*  Seems to trigger a bug related to ATerm gc if running as ToolBus tool  */
    ATcollect();
#endif
}

/*
 The parse function |SG_Parse| parses a text with a parse table
 |ptable|.  The text is accessed with the function argument
 |get_next_token|.

 For each token in the input and while there are still stacks alive,
 i.e., no error is encountered, the parser handles all actions for each
 active stack.  The shifts for each stack are stored and performed by
 |SG_Shifter| after all possible reductions have been performed.

 When the end of input is reached or no more stacks are alive, parsing
 is done.  The function |SG_ParseResult| returns a parse tree error
 message depending on the status.
 */

forest SG_Parse(parse_table *ptable, char *sort, int(*get_next_token)(void),
		size_t length)
{
  forest result;

  sg_total_tokens = length;
  table = ptable;

  SG_ParserPreparation();

  do {
    if(SG_SHOWSTACK) {
      SG_StacksToDotFile(active_stacks, sg_tokens_read);
    }

    IF_DEBUG(
             fprintf(SG_log(), "Current token (#%ld): ", (long) sg_tokens_read);
             SG_PrintToken(SG_log(), current_token);
             fprintf(SG_log(), "\n");
             )

    IF_VERBOSE(
      SG_PrintStatusBar("sglr: shifting", sg_tokens_read, sg_total_tokens) 
    )

    current_token = SG_NextToken(get_next_token);


    SG_ParseToken();


    SG_Shifter();

    if(SG_SHOWSTACK) {
      SG_StacksToDotFileFinalize(SG_StackDot());
    }

  } while (current_token != SG_EOF_Token && active_stacks);


  IF_VERBOSE( SG_PrintDotAndNewLine() );

  /*  Core parsing done!  */
  SG_PostParse();

  result = SG_ParseResult(sort);

  SG_PostParseResult();

  SG_ParserCleanup();

  return result;
}

/*
 For each stack on |active_stacks| handle the actions for the current
 token.
 */

void SG_ParseToken(void)
{
  stack   *st;
  stacks  *s;
  register stacks *actives = active_stacks;

  for_actor         = NULL;
  for_actor_delayed = NULL;

  while(actives || for_actor) {
    if(actives) {
      st      = SG_HEAD(actives);
      actives = SG_TAIL(actives);
    } else {
      st      = SG_HEAD(for_actor);
      s       = SG_TAIL(for_actor);
      SG_DeleteStacks(for_actor);
      for_actor = s;
    }
    if(!SG_Rejected(st))
      SG_Actor(st);

    if(SG_SHOWSTACK)
       SG_LinksToDot(SG_StackDot(), st); 

    if(!actives && !for_actor) {
      for_actor         = for_actor_delayed;
      for_actor_delayed = NULL;
    }
  }
}

/*
 Handle the actions for stack |st| and the current token.  A reduce
 action is immediately handled by |do_reductions|. Shift actions are
 saved for handling when no more reductions can be done. An accept
 action results in saving the current stack as the accepting stack.
 An error action is ignored because the current stack can be a wrong
 attempt while other stacks are still alive.  The entire parse fails
 if all stacks lead to error actions.  This will become apparent after
 shifting, because no more active stacks will be alive.
 */

void SG_Actor(stack *st)
{
  register actions as;
  action  a;

  as = SG_LookupAction(table, SG_ST_STATE(st), current_token);

  for(; as && !ATisEmpty(as); as = ATgetNext(as)) {
    a = ATgetFirst(as);
    switch(SG_ActionKind(a)) {
      case SHIFT:
        SG_AddShiftPair(st, SG_A_STATE(a));
        break;
      case REDUCE:
        SG_DoReductions(st, a);
        break;
      case REDUCE_LA:
        if(SG_CheckLookAhead(SG_A_LOOKAHEAD(a)))
          SG_DoReductions(st, a);
        else
          IF_DEBUG(ATfprintf(SG_log(),"Lookahead restriction prohibited %t\n",a));
        break;
      case ACCEPT:
        if(!SG_Rejected(st)) {
          IF_DEBUG(fprintf(SG_log(), "Reached the accept state\n"));
          accepting_stack = st;
        }
        break;
      default:
      case ERROR:
        break;
    }
  }
}

ATbool SG_CharInCharClass(int c, register ATermList cc)
{
  ATerm ccitem;

  for(; !ATisEmpty(cc); cc = ATgetNext(cc)) {
    ccitem = ATgetFirst(cc);

    switch(ATgetType(ccitem)) {
      case AT_INT:
        if(c == ATgetInt((ATermInt) ccitem))
          return ATtrue;
        break;
      case AT_APPL:
        if(c >= ATgetInt((ATermInt) ATgetArgument((ATermAppl) ccitem, 0))
           && c <= ATgetInt((ATermInt) ATgetArgument((ATermAppl) ccitem, 1)))
          return ATtrue;
        break;
      case AT_LIST:
      {
        register ATermList l = (ATermList) ccitem;

        for(; !ATisEmpty(l); l = ATgetNext(l))
          if(c == ATgetInt((ATermInt) ATgetFirst((ATermList) l)))
            return ATtrue;
      }
        break;
    }
  }
  return ATfalse;
}

ATbool SG_CheckLookAhead(lookahead las)
{
  int       c;
  ATbool    permitted = ATtrue;

  /*  Without further input no lookahead restrictions apply  */
  if((c = SG_GetChar()) == SG_EOF) {
    return ATtrue;
  }

  for(; permitted && !ATisEmpty(las); las = ATgetNext(las)) {
    ATermList cc;
    lookahead morelooks;
    ATerm la = ATgetFirst(las);

    if(ATmatch(la, "look(char-class(<term>),[<list>])", &cc, &morelooks)) {
      /*  is the current lookahead token in this char class?  */
      if(SG_CharInCharClass(c, cc)) {
        IF_DEBUG(ATfprintf(SG_log(), "Lookahead: character %d in %t\n", c, cc));
        permitted = ATisEmpty(morelooks)
        ? ATfalse                       /*  we have a match!  */
        : SG_CheckLookAhead(morelooks); /*  more to check     */
      }
    }
  }

  SG_UnGetChar();

  return permitted;
}

/*
 Function |SG_DoReductions| performs a reduction for stack |st| with
 production |r|, which has |nr_args| arguments.  For each path of length
 |p| from |st| a new tree is created with production |r| as label
 and the trees along the path as arguments.  The new tree is the link
 from a new stack to the stack at the end of the path.
 */

void SG_DoReductions(stack *st, action a)
{
  path  *fps;
  register path *ps;
  label prod;

  prod = SG_A_PROD(a);

  fps = SG_FindAllPaths(st, SG_A_NR_ARGS(a), ATempty, NULL);
  for(ps = fps; ps; ps = SG_P_NEXT(ps)) {
#ifndef DEBUG
    SG_Reducer(SG_P_STACK(ps),
               SG_LookupGoto(table, SG_ST_STATE(SG_P_STACK(ps)), prod),
               prod, SG_P_ARGS(ps), SG_A_ATTRIBUTE(a));
#else
    SG_Reducer(SG_P_STACK(ps),
               SG_LookupGoto(table, SG_ST_STATE(SG_P_STACK(ps)), prod),
               prod, SG_P_ARGS(ps), SG_A_ATTRIBUTE(a), st);
#endif
  }
  SG_ClearPath(fps);
}

/*
 For each path in |p|, |SG_Reducer| construct the parse tree with the
 list of descendants found and create a new stack.

 Stack |st0| is the stack at the end of path |p|. State |s| is the next
 state when reducing production |r| from the state of
 |st0|.  Look for a stack |st1| on |active_stacks| with state |s|.

 If no such stack is found, create a new stack with state |s| and a
 link to |st0|, which has tree |t| as child. The new stack is added
 to the list of active stacks and to the list of delayed stacks for
 |do_actions|.  The delay ensures (?) that all reductions to the same
 stack |st1| occur before any reductions from that state such that
 a rejection of stack |st1| will be detected before any further
 reductions.

 If such a stack exists and there is a direct link |l| from |st1| to
 |st0|, an ambiguity has been found.  The tree |t| is simply added to
 the |amb| node of the direct link |l|.

 If there is no direct link, create a new link from |st1| to
 |st0| with |t| as parse tree.
 */

#ifndef DEBUG
void SG_Reducer(stack *st0, state s, label prodl, ATermList kids, int attribute)
#else
void SG_Reducer(stack *st0, state s, label prodl, ATermList kids,
                int attribute, stack *stpt)
#endif
{
  tree      t;
  st_link   *nl;
  stack     *st1;

  IF_STATISTICS(num_reductions++);

  t = SG_Apply(table, prodl, kids, attribute,
               SG_POSINFO ? (ATerm) SG_CurrentPosInfo() : NULL);

  IF_DEBUG(
    fprintf(SG_log(), "Reducing; state %d, token: ", SG_GETSTATE(s));
    SG_PrintToken(SG_log(), current_token);
    fprintf(SG_log(), ", production: %d\n", SG_GETLABEL(prodl));
  );

  /*  A stack with state s already exists?  */
  if(!(st1 = SG_FindStack(s, active_stacks))) {
    /*  No existing stack for state s: new stack  */
#ifndef DEBUG
    st1 = SG_NewStack(s, ATfalse);
#else
    st1 = SG_NewStack(s, stpt, ATfalse);
#endif
    nl  = SG_AddLink(st1, st0, t);
    /*
     Add eventual reject stacks to the active stacks too;
     a stack might converge with it, later on
     */
    active_stacks = SG_AddStack(st1, active_stacks);
    if(SG_Rejectable(SG_ST_STATE(st1))) {
      for_actor_delayed = SG_AddStack(st1, for_actor_delayed);
    } else {
      for_actor         = SG_AddStack(st1, for_actor);
    }
    if (attribute == SG_PT_REJECT) {
      SG_MarkLinkRejected(nl);
      IF_DEBUG(fprintf(SG_log(), "Reject [new]\n"))
    }
    return;
  }

  /*  A stack with state s already exists.  Ambiguity?  */
  if ((nl = SG_FindDirectLink(st1, st0))) {
    IF_DEBUG(
      fprintf(SG_log(), "Ambiguity: direct link %d -> %d%s\n",
              SG_GETSTATE(SG_ST_STATE(st0)),
              SG_GETSTATE(SG_ST_STATE(st1)),
              (attribute == SG_PT_REJECT)?" {reject}":"")
    );
    if (attribute == SG_PT_REJECT) {
      /*  Reject?  */
      SG_MarkLinkRejected(nl);
    } else {
      /*  Don't add the rejects themselves to the amb cluster!  */
      SG_Amb(table, (tree) SG_LK_TREE(nl), (tree) t);
    }
  } else {
    /*
     No ambiguity; add new direct link from |st1| to |st0| and recheck
     all reductions for |st1|.
     */
    register stacks *sts;

    nl = SG_AddLink(st1, st0, t);
    /*  Reject?  */
    if (attribute == SG_PT_REJECT) {
      SG_MarkLinkRejected(nl);
      IF_DEBUG(
        fprintf(SG_log(), "Warning: stack with state %d rejected in "
                "presence of other links (linked to stack %d)\n",
                SG_GETSTATE(SG_ST_STATE(st0)), SG_GETSTATE(SG_ST_STATE(st1)));
      );
    }

    for(sts = active_stacks; sts; sts = SG_TAIL(sts)) {
      stack  *st2;

      st2 = SG_HEAD(sts);
      if(!SG_Rejected(st2)
         && !SG_InReduceStacks(st2, for_actor, ATfalse)
         && !SG_InReduceStacks(st2, for_actor_delayed, ATfalse)) {
        register actions as;

        for(as = SG_LookupAction(table, SG_ST_STATE(st2), current_token);
            as && !ATisEmpty(as); as = ATgetNext(as)) {
          action  a = ATgetFirst(as);


          if(SG_ActionKind(a) == REDUCE
          || (  SG_ActionKind(a) == REDUCE_LA
             && SG_CheckLookAhead(SG_A_LOOKAHEAD(a)))) {

            SG_DoLimitedReductions(st2, a, nl);
          }
        }
      }
    }
  }
}   /*  Reducer  */

/*  Limited: do only those reductions that have a path containing link |l|  */

void SG_DoLimitedReductions(stack *st, action a, st_link *l)
{
  path  *fps;
  register path *ps;
  label prod;

  prod = SG_A_PROD(a);

  fps = SG_FindLimitedPaths(st, SG_A_NR_ARGS(a), l);
  for(ps = fps; ps; ps = SG_P_NEXT(ps)) {
#ifndef DEBUG
    SG_Reducer(SG_P_STACK(ps),
               SG_LookupGoto(table, SG_ST_STATE(SG_P_STACK(ps)), prod),
               prod, SG_P_ARGS(ps), SG_A_ATTRIBUTE(a));
#else
    SG_Reducer(SG_P_STACK(ps),
               SG_LookupGoto(table, SG_ST_STATE(SG_P_STACK(ps)), prod),
               prod, SG_P_ARGS(ps), SG_A_ATTRIBUTE(a), st);
#endif
  }
  SG_ClearPath(fps);
}

/*
 Do all shifts. For each shift pair |(st1, s)|, a stack |st| is created
 that has a link to |st1| and has state |s|.  The tree corresponding
 to the current token is the parse tree for the link. If a stack with
 state |s| already existed on |active_stacks|, only a new link is added
 from |st| to |st1|.
 */

void SG_Shifter(void)
{
  production   t;
  stack        *st0, *st1;
  stacks       *new_active_stacks = NULL;
  state        s;
  st_link      *l;
  int          i;

  IF_DEBUG(
    fprintf(SG_log(), "#%ld: shifting %d parser(s) -- token ",
            (long) sg_tokens_read, sg_sp_idx);
    SG_PrintToken(SG_log(), current_token);
    fprintf(SG_log(), ", line %ld, column %ld\n", (long) line, (long) col);
  );

  t = SG_LookupProduction(table, current_token);

  for(i = 0; i < sg_sp_idx; i++) {
    s   = SG_SP_STATE(sg_shift_pairs[i]);
    st0 = SG_SP_STACK(sg_shift_pairs[i]);

    if(!SG_PT_HAS_REJECTS(table) || !SG_Rejected(st0)) {
      if(!(st1 = SG_FindStack(s, new_active_stacks))) {
#ifndef DEBUG
        st1 = SG_NewStack(s, ATtrue);
#else
        st1 = SG_NewStack(s, NULL, ATtrue);
#endif
        new_active_stacks = SG_AddStack(st1, new_active_stacks);
      }
      l = SG_AddLink(st1, st0, (tree) t);

      if(SG_SHOWSTACK) 
      	 SG_LinksToDot(SG_StackDot(), st1); 

    } else IF_DEBUG(
      fprintf(SG_log(), "Shifter: skipping rejected stack with state %d\n",
              SG_GETSTATE(SG_ST_STATE(st0)))
    );
  }
    SG_DiscardShiftPairs();

#if !defined(HAVE_BOEHMGC)
#ifdef  MEMSTATS
    IF_STATISTICS(SG_MaxAllocStats());
#endif
    if(SG_GC) {
      old_active_stacks[(sg_tokens_read-1) % GC_CYCLE] = active_stacks;
      if (((sg_tokens_read-1) % GC_CYCLE) == (GC_CYCLE-1)) {
	SG_CollectOldStacks(old_active_stacks, GC_CYCLE, new_active_stacks, accepting_stack);
      }
    }
#endif

  active_stacks = new_active_stacks;
} /*  Shifter  */

/*
 If all tokens have been read or if no more stacks are alive, parsing
 is done and the the result of parsing is returned.  If parsing
 succeeded, |accepting_stack| points to a stack that has a direct
 link to the initial state.  The tree on this link is the parse forest
 with all possible parse trees.  If parsing failed an error term is
 returned.  A distinction is made between an error at end of file an
 error in the middle of the file.
 */

char *SG_ProdSort(production t)
{
  char          *sort = NULL;

  if(ATmatch((ATerm) t, "prod(<term>,sort(\"<START>\"),<term>)", &t, NULL)) {
    ATermList list = (ATermList) t;
    ATerm elt, symbol;
    static sg_growbuf *gb = NULL;

    if(!gb) {
      gb = SG_Create_GrowBuf(32, 16, sizeof(char));
    } else {
      gb = SG_Reset_GrowBuf(gb);
    }

    for(;!sort && !ATisEmpty(list); list = ATgetNext(list)) {
      elt = ATgetFirst(list);

      if(!ATmatch(elt, "cf(opt(layout))",elt)
      &&  ATmatch(elt, "cf(<term>)", &symbol)) {
        char *symstr = SG_PrintSymbolToString(symbol, ATfalse);
        SG_AddStringToGrowBuf(gb, symstr);
        free(symstr);
      }
    }

    SG_AddToGrowBuf(gb,"\0",1); /* Don't forget null termination */
    sort = SG_GetGrowBufContent(gb);
  }

  return SG_SAFE_STRING(sort);
}

char *SG_ApplSort(tree t)
{
  production prod;

  if(ATmatch((ATerm) t, "appl(<term>,<list>)", &prod, NULL)) {
    return SG_ProdSort(prod);
  }

  if(ATisEqual(ATgetAFun((ATermAppl) t), SG_Amb_AFun))
    return("[multiple sorts]");

  return "[unknown sort]";
}

char *SGsort(int Mode, forest t)
{
  static char *sort = NULL;

  switch(Mode)
  {
    case SG_GET:
      break;
    case SG_UNSET:
      sort = NULL;
      break;
    case SG_SET:
      sort = SG_ApplSort((tree) t);
      break;
  }
  return SG_SAFE_STRING(sort);
}

ATermList SG_CurrentPosInfo(void)
{
  return
  ATmakeList4(
              (ATerm) ATmakeAppl1(SG_Character_AFun,
                                  (ATerm) SG_GetATint(current_token, 0)),
              (ATerm) ATmakeAppl1(SG_Line_AFun,
                                  (ATerm) SG_GetATint(line, 0)),
              (ATerm) ATmakeAppl1(SG_Col_AFun,
                                  (ATerm) SG_GetATint(col, 0)),
              (ATerm) ATmakeAppl1(SG_Offset_AFun,
                                  (ATerm) SG_GetATint(sg_tokens_read, 0))
              );

}

ATermList SG_GetFirstAmbiguityPosInfo(ATerm ambtrack)
{
   ATermList ambiguities;
   ATerm first;
   ATerm position;

   assert(ATgetType(ambtrack) == AT_APPL);
   
   ambiguities = (ATermList) ATgetArgument((ATermAppl) ambtrack, 1);
  
   assert(ATgetType(ambiguities) == AT_LIST);

   first = ATgetFirst(ambiguities);
   position = ATgetArgument((ATermAppl) first, 0);
   
   assert(ATgetType(position) == AT_APPL);

   return ATgetArguments((ATermAppl) position); 
}

forest SG_ParseError(ATermList cycle, int excess_ambs, ATerm ambtrak)
{
  ATermAppl  errcode;
  ATerm posinfo;

  SG_ERROR_ON();

  if(!ATisEmpty(cycle)) {
    errcode = ATmakeAppl1(SG_Cycle_Error_AFun, (ATerm) cycle);
  }
  else if(excess_ambs) {
    errcode = (ATermAppl) ambtrak; 
  }
  else if(current_token == SG_GETTOKEN(SG_EOF_Token)) {
    errcode = ATmakeAppl0(SG_EOF_Error_AFun);
  }
  else {
    errcode = ATmakeAppl0(SG_Plain_Error_AFun); 
  }

  posinfo = excess_ambs ? (ATerm) SG_GetFirstAmbiguityPosInfo(ambtrak) : 
                          (ATerm) SG_CurrentPosInfo();

  return (forest) ATmakeAppl2(SG_ParseError_AFun, posinfo, (ATerm) errcode);
}

tree SG_ConvertA2ToA1(tree t)
{
  int nr_ambs = SGnrAmb(SG_NR_ASK);

  if(nr_ambs > 0) {
    IF_DEBUG(
      ATwarning("error: cannot represent parse forest (%d ambiguit%s)"
                " in AsFix1\n",
                nr_ambs, nr_ambs > 1 ? "ies":"y")
    );

    return SG_ParseError(ATempty, nr_ambs, SG_AmbTracker(t));
  }

  IF_VERBOSE(ATwarning("converting AsFix2 parse tree to AsFix1\n"));

  IF_STATISTICS(SG_Timer());
  t = (tree) a2toa1((ATerm) t, ATfalse);
  IF_STATISTICS(fprintf(SG_log(),
                        "AsFix1 conversion took %.4fs\n", SG_Timer()));
  return t;
}

tree SG_ParseResult(char *sort)
{
  ATermList cycle;
  tree      t;

  if(!accepting_stack) {
    return SG_ParseError(ATempty, 0, NULL);
  } 
  else {
    /* During parsing no filtering is performed.
     * So, before printing the tree (forest) cycle detection,
     * and filtering is performed. 
     */
    
    t = (tree) SG_LK_TREE(SG_HEAD(SG_ST_LINKS(accepting_stack)));

    if (sort) {
      IF_STATISTICS(SG_Timer());
      t = SG_SelectOnTopSort(table, t, sort);
      IF_STATISTICS(fprintf(SG_log(), "Topsort selection took %.4fs\n",
                            SG_Timer()));
      if (!t) {
        /*  Flag this error at start, not end, of file  */
        SG_ResetCoordinates();
        return SG_ParseError(ATempty, 0, NULL);
      }
    }

    /*  Now detect, and report, cycles in the tree */
    if (SG_CYCLE) {
      if (SG_MaxNrAmb(SG_NR_ASK) > 0) {

        IF_STATISTICS(SG_Timer());
        cycle = SG_CyclicTerm(table, t);
        IF_STATISTICS(fprintf(SG_log(), "Cycle detection took %.4fs\n", SG_Timer()));
        if (!ATisEmpty(cycle)) {
          return SG_ParseError(cycle, 0, NULL);
        }
      }

      /* Now filtering starts, if SG_FILTER is false, it only
       * converts amb clusters to amb nodes
       */

      if (SGnrAmb(SG_NR_ASK) > 0) {
        IF_STATISTICS(SG_Timer());
        t = SG_FilterTree(table, t);
        IF_STATISTICS(fprintf(SG_log(), "Filtering took %.4fs\n", SG_Timer()));
      }
    }

    /* Finally, the parse tree (in AsFix format) is produced, if desired. */
    SGnrAmb(SG_NR_ZERO);
    IF_STATISTICS(SG_Timer());
    t = SG_YieldTree(table, t);
    IF_STATISTICS(fprintf(SG_log(),
                          "Aprod expansion took %.4fs\n", SG_Timer()));

    SGsort(SG_SET, t);     


    /*  Convert the forest in-line to AsFix1 upon request  */
    if(SG_ASFIX1) {
      return SG_ConvertA2ToA1(t);
    }


    /*
        If you'd want return ambiguity tracks instead of ambiguous
        AsFix2, that could be taken care of here...
     */
    if(SG_TOOLBUS) {
      ATerm ambtrak = SG_AmbTracker(t);

      if(ambtrak) {
        return SG_ParseError(ATempty, SGnrAmb(SG_NR_ASK), ambtrak);
      }
    }

    t = (tree) ATmakeAppl2(SG_ParseTree_AFun, (ATerm) t,
                           (ATerm) SG_GetATint(SGnrAmb(SG_NR_ASK), 0));

    return t;
  }
}

/* a function to print a status bar on a tty */
void SG_PrintStatusBar(char *subject, long part, long whole)
{
  static char bar[]  = "==============================";
  static char daisy[] = "|/-\\";
  long double factor;
  long freq = whole / 30;
 
  freq = (freq != 0) ? freq : 1; /* watching out for 0 divisions */

  if(!isatty(fileno(stderr))) {
    return;
  }

  factor = (long double) part / (long double) whole;

  if(whole == 0.0 || (part % freq && part != whole)) {
    return;
  }

  factor = (long double) part / (long double) whole;


  fprintf(stderr,"\r%-20s [%-30.*s] %c %ld/%ld (%3d%%)",
                 subject,
                 (int) ((double) 30 * factor),
                 bar,
		 part != whole ? daisy[(part / freq) % 4] : ' ',
                 part,
                 whole,
                 (int) (factor * 100)
         );

  return;
}

#ifdef DEBUG
/*  A few diagnostic routines (for debugging purposes)  */

void SG_ShowLinks(st_links *lks, int depth)
{
  for (; lks; lks = SG_TAIL(lks)) {
    fprintf(stderr, "%*.*s--%x-->\n", 2*depth, 2*depth, "", (int)SG_HEAD(lks));
    SG_ShowStack(SG_LK_STACK(SG_HEAD(lks)), depth+1);
  }
}

void SG_ShowStack(stack *st, int depth)
{
  if (!st)
    return;

  fprintf(stderr, "%*.*s%x %d\n", 2*depth, 2*depth, "", (int)st,
          SG_GETSTATE(SG_ST_STATE(st)));

  SG_ShowLinks(SG_ST_LINKS(st), depth+1);
}

void SG_ShowStacks(stacks *sts)
{
  if (!sts)
    return;

  while(sts) {
    SG_ShowStack(SG_HEAD(sts),0);
    sts = SG_TAIL(sts);
  }
}

void SG_ShowStackAncestors(stack *st)
{
  while(st && st->parent) {
    ATwarning("\t%d%s induced %d%s\n",
              SG_GETSTATE(SG_ST_STATE(st->parent)),
              SG_Rejected(st->parent)?"R":"",
              SG_GETSTATE(SG_ST_STATE(st)),
              SG_Rejected(st)?"R":"");
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
  while(astks) {
    stk   =  SG_HEAD(astks);
    astks =  SG_TAIL(astks);
    ATwarning("%d%s ", SG_GETSTATE(SG_ST_STATE(stk)),
              SG_Rejected(stk)?"r":"");
  }
  ATwarning("\n");
}

void SG_ShowStackRejects(stack *st, int depth)
{
  st_links *ls = SG_ST_LINKS(st);
  st_link *l;

  if(depth > 666) return;

  for (; ls; ls = SG_TAIL(ls)) {
    l = SG_HEAD(ls);

    ATwarning("%*.*s%s%x: state %d --> state %d\n", 2*depth, 2*depth,
              "", SG_LK_REJECTED(l)?"~":" ", (int) l,
              SG_GETSTATE(SG_ST_STATE(st)),
              SG_GETSTATE(SG_ST_STATE(SG_LK_STACK(l))));
    SG_ShowStackRejects(SG_LK_STACK(l), depth+1);
  }
}


void SG_ShowActiveStackLinks(stacks *astks)
{
  stack  *stk;

  while(astks) {
    stk   =  SG_HEAD(astks);
    astks =  SG_TAIL(astks);
    SG_ShowStackRejects(stk,2);
  }
}

void SG_ShowShiftPairs()
{
  int i;

  ATwarning("Shifters:\n");
  for(i = 0; i < sg_sp_idx; i++) {
    ATwarning("%d: ", SG_SP_STATE(sg_shift_pairs[i]));
    SG_ShowStackAncestors(SG_SP_STACK(sg_shift_pairs[i]));
  }
}
#endif  /* DEBUG */
