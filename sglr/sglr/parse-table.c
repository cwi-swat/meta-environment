/*
  %% $Id$

  \section{Parse Table}
  \label{parse-table.c}

  This section defines the implementation of parse tables.

  \subsection{parse-table.h}

  \input{parse-table.htx}

  \noindent \rule{3cm}{0.5pt} end parse-table.h
*/

/*
  \paragraph{Includes}
*/
#include <stdio.h>
#include <string.h>

#include  "mem-alloc.h"
#include  "parse-table.h"
#include  "sglr.h"

/*
  \paragraph{Actions}

  The function |SG_ActionKind| analyses an action and returns its
  kind.
*/
int     SG_ActionKind(action a)
{
  if(!a) {
    ATfprintf(stderr, "SG_ActionKind error!\n");ATerror(NULL);
    return ERROR;
  }
  if (ATmatch(a, "shift(<int>)", NULL))
    return SHIFT;
  if (ATmatch(a, "reduce(<int>,<int>,<int>)", NULL, NULL, NULL))
    return REDUCE;
  if (ATmatch(a, "accept"))
    return ACCEPT;

  return ERROR;
}

#ifdef SG_A_FUNCS
state   SG_A_STATE(action a)
{
  return ATgetInt((ATermInt) ATgetArgument(a, 0));
}

int     SG_A_NR_ARGS(action a)
{
  return ATgetInt((ATermInt) ATgetArgument(a, 0));
}

int     SG_A_PROD(action a)
{
  return ATgetInt((ATermInt) ATgetArgument(a, 1));
}

ATbool  SG_A_REJECT(action a)
{
  ATbool r;

  r = ATgetInt((ATermInt) ATgetArgument(a, 2));
  return r ? ATtrue : ATfalse;
}
#endif

/*
   \subsection{Parse Table Lookup}
*/

state SG_LookupGoto(parse_table *pt, state s, int token)
{
  state retstate;
  ATerm val;

  val = ATtableGet(pt->gotos, (ATerm) ATmakeList2((ATerm) ATmakeInt(s),
                                                  (ATerm) ATmakeInt(token)));
  retstate = (val == NULL)?-1:ATgetInt((ATermInt) val);

  if (SG_DEBUG) ATfprintf(SGlog(), "Goto(%d,%d) == %d\n", s, token, retstate);

  return retstate;
}

actions SG_LookupAction(parse_table *pt, state s, int token)
{
  actions as;

  as = (actions) ATtableGet(pt->actions,
                            (ATerm) ATmakeList2((ATerm) ATmakeInt(s),
                                                (ATerm) ATmakeInt(token)));
  as = as ? as : ATempty;

  if (SG_DEBUG) ATfprintf(SGlog(), "Action(%d,%d) = %t\n", s, token, as);

  return as;
}

ATermList SG_LookupPriority(parse_table *pt, ATermInt prodlabel)
{
  return (ATermList) ATtableGet(pt->priorities, (ATerm) prodlabel);
}

/*
   \subsection{Parse Table Creation}
*/

parse_table *SG_NewParseTable(int states, int productions)
{
  parse_table *pt;

  pt               = SG_Malloc(sizeof(struct _parse_table));
  pt->init         = -1;
  pt->actions      = ATtableCreate(states*1.4, 75);
  pt->gotos        = ATtableCreate(states*1.4, 75);
  pt->productions  = ATtableCreate((productions + 256)*1.4, 75);
  pt->priorities   = ATtableCreate( productions >> 2, 75);

  return pt;
}


/*
   \subsection{Printing Parse Tables}
*/


/*
  \subsection{Parse Table Term to Parse Table}
*/

/*
  Storing and accessing character classes

  Parsing is done token bij token.  When looking up matching
  actions (or states), we have to return all actions (states)
  belonging to all character classes containing the token.

  This is fairly difficult when the lookup tables for actions and
  gotos are represented in a straightforward manner, i.e. when the
  parse table's character class terms are used as keys in an ATerm
  hash table: in that approach, we'd have to find out first which
  character class keys in the lookup table contain the token,
  which is quite cumbersome (and could be costly).

  For that reason, character classes are `expanded' in
  representation: whenever a charater range occurs in the
  parse table, the corresponding action (state) is seperately
  incorporated in the lookup table for all characters in the
  range; because of the Aterm Libary's maximal sharing, this can
  be done at the cost of minimal overhead.

  As an advantage, lookups are speeded up: no searching, other
  than hash key driven access provided by the high-performance
  Aterm Library, has to be performed, making lookups `immediate'.

 */

void SG_AddToTable(ATermTable tbl, state s, int c, ATermList as, ATbool make_list)
{
  ATerm key;
  ATermList prev;

  key = (ATerm) ATmakeList2((ATerm) ATmakeInt(s), (ATerm) ATmakeInt(c));
  prev = (ATermList) ATtableGet(tbl, key);

  if(!prev) {             /* New key, add a new list */
    if(ATgetType(as) == AT_LIST)
      ATtablePut(tbl, key, (ATerm) as);
    else
      if(make_list)
        ATtablePut(tbl, key, (ATerm) ATmakeList1((ATerm) as));
      else
        ATtablePut(tbl, key, (ATerm) as);
  } else {                /* Existing key, insert into existing list */
    if(!make_list)
        ATerror("SG_AddToTable: attempt to add value to non-list table\n");
    switch(ATgetType(prev)) {
      case  AT_LIST:
        if(ATgetType(as) == AT_LIST)
          ATtablePut(tbl, key, (ATerm) ATconcat(prev, as));
        else
          ATtablePut(tbl, key, (ATerm) ATinsert(prev, (ATerm) as));
        break;
      default:
        ATerror("SG_AddToTable: bad value in table (must be list): %t\n",(ATerm)prev);
        break;
    }
  }
}

void SG_AddClassesToTable(ATermTable tbl, state s, ATermList classes, ATermList as, ATbool make_list)
{
  int       first, last;
  ATermList currClass;
  ATerm     firstTerm;

  for(; !ATisEmpty(classes); classes = ATgetNext(classes)) {
    currClass = (ATermList) ATgetFirst(classes);
    for(; !ATisEmpty(currClass); currClass = ATgetNext(currClass)) {
      firstTerm = ATgetFirst(currClass);
      if (ATmatch(firstTerm, "<int>", &first)) {
        SG_AddToTable(tbl, s, first, as, make_list);
      } else {
        if (ATmatch(firstTerm, "range(<int>,<int>)", &first, &last))
          for(; first <= last; first++) {
            SG_AddToTable(tbl, s, first, as, make_list);
        } else {
          ATerror("SG_AddClassesToTable: bad character class\n%t\n", firstTerm);
        }
      }
    }
  }
}

void SG_AddPTActions(ATermList acts, parse_table *pt, state s)
{
  ATerm     action;
  ATermList classes, actions;

  for (; !ATisEmpty(acts); acts = ATgetNext(acts)) {
    action = ATgetFirst(acts);
    if (ATmatch(action, "action(char-class(<list>),<term>)",
                &classes, &actions))
      SG_AddClassesToTable(pt->actions, s, classes, actions, ATtrue);
    else
      ATerror("SG_AddPTActions: cannot match action %t\n", action);
  }
}

void SG_AddPTGotos(ATermList goto_lst, parse_table *pt, state s)
{
  ATermList classes;
  ATerm     curTerm;
  state     s2;

  for (; !ATisEmpty(goto_lst); goto_lst = ATgetNext(goto_lst)) {
    curTerm = ATgetFirst(goto_lst);
    if (ATmatch(curTerm, "goto(char-class(<list>),<int>)", &classes, &s2))
      SG_AddClassesToTable(pt->gotos, s, classes,
                           (ATermList)ATmakeInt(s2), ATfalse);
    else
      ATerror("SG_AddPTGotos: cannot parse goto entry %t\n", curTerm);
  }
}


/*
  States
*/
void SG_AddPTStates(ATermList states, parse_table *pt)
{
  ATerm     curstate;
  ATermList gotos, actions;
  int       s, nr_of_states = 0;

  for (; !ATisEmpty(states); states=ATgetNext(states)) {
    curstate=ATgetFirst(states);
    if (ATmatch(curstate, "state-rec(<int>,[<list>],actions([<list>]))",
                &s, &gotos, &actions)) {
/*
      if(SG_DEBUG)
        ATfprintf(SGlog(), "State %d: %t\n", s, curstate);
 */
      nr_of_states = SG_Max(nr_of_states, s);
      SG_AddPTGotos(gotos, pt, s);
      SG_AddPTActions(actions, pt, s);
    } else
      ATerror("SG_AddPTStates: cannot parse %t\n", curstate);
  }
  if (SG_DEBUG || SG_SHOWSTAT)
    ATfprintf(SGlog(), "No. of states: %d\n", nr_of_states);
}

production SG_LookupProduction(parse_table *pt, int token)
{
  return(ATtableGet(pt->productions, (ATerm) ATmakeInt(token)));
}

void SG_AddProduction(ATermTable tbl, int pr_num, production prod)
{
  ATerm key, prev;

  key = (ATerm) ATmakeInt(pr_num);

  if((prev = ATtableGet(tbl, key)))
    ATerror("SG_AddProduction: production %d (%t) already present, previous: %t\n",
            pr_num, prod, prev);

  ATtablePut(tbl, (ATerm) ATmakeInt(pr_num), prod);
}

/*
  Adds the literal ATerm for a production to the production table.
  The label is the pointer in the table. It is used in reduce actions
  to refer to the production.
*/
void SG_AddPTGrammar(ATermList grammar, parse_table *pt)
{
  production prod;
  int pr_num;
  int c;
  int nr_of_prods = 0;

  for (; !ATisEmpty(grammar); grammar = ATgetNext(grammar)) {
    prod = ATgetFirst(grammar);
    if (!ATmatch(prod, "label(<term>,<int>)", &prod, &pr_num))
      ATerror("SG_AddPTGrammar: cannot parse production %t\n", prod);
    SG_AddProduction(pt->productions, pr_num, prod);
    nr_of_prods = SG_Max(pr_num, nr_of_prods);
  }
  if (SG_DEBUG || SG_SHOWSTAT)
    ATfprintf(SGlog(), "No. of productions: %d\n", nr_of_prods + 256);
  for (c = 0; c <= 255; c++) {
    SG_AddProduction(pt->productions, c, (production) ATmakeInt(c));
  }
}

AFun  SG_GtrPrioAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(fun == (AFun) NULL) {
    fun = ATmakeAFun("gtr-prio", 2, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}

AFun  SG_LeftPrioAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(fun == (AFun) NULL) {
    fun = ATmakeAFun("left-prio", 2, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}

AFun  SG_RightPrioAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(fun == (AFun) NULL) {
    fun = ATmakeAFun("right-prio", 2, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}

enum SG_PRIORITIES { P_IGNORE, P_GTR, P_LEFT, P_RIGHT };

void SG_AddPTPriorities(ATermList prios, parse_table *pt)
{
  ATerm prio;
  AFun  fun;
  ATermList args;
  ATermInt  pr_num1, pr_num2;
  int   ptype = P_IGNORE;

  for (; !ATisEmpty(prios); prios = ATgetNext(prios)) {
    prio = ATgetFirst(prios);
    fun = ATgetAFun(prio);
    if(fun == SG_GtrPrioAFun()) {
      ptype = P_GTR;
    } else if(fun == SG_LeftPrioAFun()) {
      ptype = P_LEFT;
    } else if(fun == SG_RightPrioAFun()) {
      ptype = P_RIGHT;
    } else {
      ptype = P_IGNORE;
    }
    if(ptype != P_IGNORE) {
      ATermList prev;

      args = ATgetArguments((ATermAppl) prio);
      pr_num1 = (ATermInt) ATelementAt(args, 0);
      pr_num2 = (ATermInt) ATelementAt(args, 1);
      switch(ptype) {
        case P_GTR:
          if(pr_num1 == pr_num2)
            break;
          if(!(prev = (ATermList)ATtableGet(pt->priorities, (ATerm)pr_num1))) {
            ATtablePut(pt->priorities, (ATerm) pr_num1,
                       (ATerm) ATmakeList1((ATerm) pr_num2));
          } else {
            ATtablePut(pt->priorities, (ATerm) pr_num1,
                       (ATerm) ATinsert(prev, (ATerm) pr_num2));
          }
          break;
        default:
          break;
      }
    }
  }
}

/*

  \paragraph{Build Parse Table}

  Interpret term as parse table.

  Translating parse tree representation of parse table into parse
  table data structure.

*/
parse_table *SG_BuildParseTable(ATerm t)
{
#define SG_OLDPTFORMAT	"<int>,[<list>],states([<list>])"
#define	SG_PTFORMAT	SG_OLDPTFORMAT",priorities([<list>])"

  ATermList   prods, prios, sts;
  parse_table *pt;

  pt = SG_NewParseTable(8192, 2048);

  if(!ATmatch(t, "parse-table("SG_PTFORMAT")",
              &(pt->init), &prods, &sts, &prios)) {
    if(!ATmatch(t, "parse-table("SG_OLDPTFORMAT")",
                &(pt->init), &prods, &sts)) {
      ATfprintf(stderr, "error: Cannot parse parse table\n");
      return NULL;
    }
    if(SG_VERBOSE)
      ATfprintf(stderr, "warning: no priority information in parse table\n");
  } else {	/*  Successful match, priorities included  */
    SG_AddPTPriorities(prios, pt);
  }
  SG_AddPTStates(sts, pt);
  SG_AddPTGrammar(prods, pt);
  return pt;
}

/*
  \subsection{A Parse Table Database}

*/
#define MAX_TABLES 32

typedef struct _ptdb {
  char *name;
  parse_table *table;
} PTDB;
static PTDB tables[MAX_TABLES];
int last_table = 0;

void SG_SaveParseTable(char *L, parse_table *pt)
{
  int i;
  for (i = 0; i < last_table && strcmp(L, tables[i].name); i++) ;
  if (i > MAX_TABLES)
    ATerror("maximum number (%d) of languages exceeded\n", MAX_TABLES);

  if (i == last_table)
    last_table++;

  tables[i].name = strdup(L);
  tables[i].table = pt;
  if (SG_DEBUG)
    ATfprintf(SGlog(), "Language %s has index %d\n", L, i);
}

parse_table *SG_LookupParseTable(char *L, ATbool may_fail)
{
  int i;

  if (SG_DEBUG)
    ATfprintf(SGlog(), "Request for language %s\n", L);

  for (i = 0; i < last_table; i++)
    if (!strcmp(L, tables[i].name)) {
      if (SG_DEBUG)
        ATfprintf(SGlog(), "Table for language %s available with index %d\n", L, i);
      return tables[i].table;
    } else if (SG_DEBUG)
      ATfprintf(SGlog(), "Language %s not at index %d (%s)\n",
                L, i, tables[i].name);

  if (i > MAX_TABLES)
    ATerror("maximum number (%d) of languages exceeded\n", MAX_TABLES);
  else {
    if (SG_DEBUG)
      ATfprintf(SGlog(), "Language %s not available\n", L);
    if(!may_fail) ATerror("No language %s open\n", L);
  }
  return NULL;
}
