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
#include <TB.h>
#include "parse-table.h"
#include "bool.h"

#ifndef DONT_USE_BOEHMGC
  #include <gc.h>
  #define malloc(n)  GC_malloc(n)
  #define free(n)    ;
#endif


extern int   verboseflag;
extern int   debugflag;
extern int   show_statistics;
extern FILE *log;

/*
  \paragraph{Actions}

  The function |A_KIND| analyses an action and returns its
  kind.
*/
int A_KIND(action *a)
{
  int i, j, k;
  if (TBmatch(a, "shift(%d)", &i))
    return SHIFT;
  else if (TBmatch(a, "reduce(%d,%d,%d)", &i, &j, &k))
    return REDUCE;
  else if (TBmatch(a, "accept"))
    return ACCEPT;
  else
    return ERROR;
}

/*
  \subsection{Binary Search Trees}

  The goto and action tables consist of an array with an entry for
  each state.  The entries are binary search trees based on character
  ranges that contain as value a term, either a state or a list of
  actions. The nodes of the search trees are of the form |node(first,
  left, last, right, val)|, with |first-last| the range for which
  |val| is the value and |left| and |right| search trees for keys
  smaller than |first| and larger than |last| respectively. The
  function |bst_find| looks up the value for a key in a search
  tree. If the key does not fit in any of the ranges |NULL| is
  returned.
*/
term *bst_find(term *tree, int key)
{
  term *left, *right, *val;
  int first, last;
  if (debugflag)
    TBprintf(log, "looking for %d in %t\n", key, tree);
  while (tree != NULL)
    if (TBmatch(tree, "node(%d,%t,%d,%t,%t)",
                 &first, &left, &last, &right, &val)) {
      if (key < first) {
          tree = left;
          continue;
      }
      if (key > last) {
          tree = right;
          continue;
      }
      if (debugflag)
        TBprintf(log, " = %t\n", val);
      return val;
    }
  return NULL;
}

/*
  A new node can be added to a search tree by means of the function
  |bst_add|.  It is assumed that the range added does not overlap with
  any of the ranges already in the tree. It is an error if this is not
  the case. The address of the root pointer of the tree should be
  supplied. It is overwritten if the tree was empty. Note that the
  functions use iteration instead of recursion.
*/
void bst_add(term **tree, int first, int last, term *val)
{
  term *left2, *right2, *val2;
  int first2, last2;
  while (TRUE) {
     if (*tree == NULL) {
       *tree = TBmake("node(%d,%t,%d,%t,%t)", first, NULL, last, NULL, val);
       if (debugflag) {
         fprintf(log, "\nAdded : ");
         TBprintf(log, "%t", *tree);
       }
       return;
     } else if (!TBmatch(*tree, "node(%d,%t,%d,%t,%t)",
                  &first2, &left2, &last2, &right2, &val2)) {
       fprintf(stderr, "malformed bst\n");
       exit(1);
    } else if (last < first2) {
      tree = &(elm2(fun_args(*tree)));
      continue;
    } else if (first > last2) {
      tree = &(elm4(fun_args(*tree)));
       continue;
    } else {
      fprintf(stderr, "\noverlapping character range %d-%d\n", first, last);
      TBprintf(stderr, "value = %t\n", val);
      exit(1);
    }
  }
}

/*
   \subsection{Parse Table Lookup}
*/
state GOTO(parse_table *pt, state s, int c)
{
  state s2; term *val;

  val = bst_find(pt->goto_table[s], c);
  if (val == NULL)
    s2 = -1;
  else
    s2 = int_val(val);
  if (debugflag)
    fprintf(log, "GOTO(%d,%d) = %d\n", s, c, s2);
  return s2;
}

actions *ACTIONS(parse_table *pt, state s, int c)
{
  actions *as;
/*
  if(debugflag) TBprintf(log, "state %d = %t\n\n", s, pt->vertices[s]);
*/
  as = bst_find(pt->action_table[s], c);
  if (debugflag) {
      fprintf(log, "ACTION(%d,%d) = ", s, c);
      TBprintf(log, "%t\n\n", as);
  }
  return as;
}

/*
   \subsection{Parse Table Creation}
*/
parse_table *new_parse_table(int states, int productions)
{
  parse_table *pt;
  int i;

  pt               = malloc(sizeof(struct _parse_table));
  pt->init         = -1;
  pt->action_table = malloc(sizeof(term *) * states);
  pt->goto_table   = malloc(sizeof(term *) * states);
  pt->productions  = malloc(sizeof(struct _production) * (productions + 256));
  pt->vertices     = malloc(sizeof(term *) * states);
  pt->org_table    = NULL;

  for (i = 0; i <= states; i++) {
    pt->action_table[i] = NULL;
    pt->goto_table[i]   = NULL;
  }

  for (i = 0; i <= productions; i++) {
    pt->productions[i].aterm = NULL;
    pt->productions[i].cons = NULL;
  }
  return pt;
}

void add_goto(parse_table *pt, state s1, int first, int last, state s2)
{
  bst_add(&(pt->goto_table[s1]), first, last, mk_int(s2));
}

void add_actions(parse_table *pt, state s, int first, int last, actions *as)
{
  bst_add(&(pt->action_table[s]), first, last, as);
}


/*
   \subsection{Printing Parse Tables}
*/


/*
  \subsection{Parse Table Term to Parse Table}
*/

state nr_of_states;

void max_state(state s)
{
  if (s > nr_of_states)
    nr_of_states = s;
}

void bst_add_classes(term ** entry, term *classes, actions *as)
{
  int first, last;
  while(classes != NULL) {
    if (TBmatch(first(classes), "%d", &first))
      last = first;
    else if (!TBmatch(first(classes), "range(%d,%d)", &first, &last)) {
      fprintf(stderr, "bst_add_classes: cannot parse character class\n");
      TBprintf(stderr, "%t", classes);
      fprintf(stderr, "\n");
      exit(1);
    }
    bst_add(entry, first, last, as);
    classes = next(classes);
  }
}

void PT_actions(term *action_table, parse_table *pt, state s)
{
  term *classes, *as, *action;

  while (action_table != NULL) {
    action = first(action_table);
    if (TBmatch(action, "action(char-class(%t),%t)",
                &classes, &as)) {
      bst_add_classes(&(pt->action_table[s]), classes, as);
    } else {
      TBprintf(stderr, "PT_actions: cannot match action %t\n", action);
      exit(1);
    }
    action_table = next(action_table);
  }
}

void PT_gotos(term *goto_table, parse_table *pt, state s1)
{
  term *classes;
  state s2;

  while (goto_table != NULL) {
    if (TBmatch(first(goto_table), "goto(char-class(%t), %d)",
                 &classes, &s2)) {
      bst_add_classes(&(pt->goto_table[s1]), classes, mk_int(s2));
    } else {
      fprintf(stderr, "PT_gotos: cannot parse goto entry\n");
      exit(1);
    }
    goto_table = next(goto_table);
  }
}

/*
  Adds the ATerm encodings of the itemssets to the parse table
*/
void PT_items(term *vertices, parse_table *pt)
{
  term *vertex, *itemset;
  int pr_num;

  for ( ; vertices != NULL; vertices = next(vertices)) {
    vertex = first(vertices);
    if (!TBmatch(vertex, "vertex(%d, %t)", &pr_num, &itemset)) {
        fprintf(stderr, "PT_actions: cannot parse vertex\n");
        exit(1);
    }
    pt->vertices[pr_num] = itemset;
    TBprotect(&(pt->vertices[pr_num]));
  }
}

/*
  states
*/
void PT_states(term *states, parse_table *pt)
{
  term *state, *gotos, *actions;
  int s;

  nr_of_states = 0;

  while (states != NULL) {
    state = first(states);
    if (TBmatch(state, "state-rec(%d, %t, actions(%t))",
                &s, &gotos, &actions)) {
      if(debugflag)
        TBprintf(log, "\nstate %d = %t\n\n", s, state);
      max_state(s);
      PT_gotos(gotos, pt, s);
      PT_actions(actions, pt, s);
    } else {
      TBprintf(stderr, "PT_states: cannot parse state: %t\n", first(states));
      exit(1);
    }
    states = next(states);
  }
  if (debugflag || show_statistics)
    fprintf(log, "%d states\n", nr_of_states);
  for (s = 0; s <= nr_of_states; s++) {
    TBprotect(&(pt->goto_table[s]));
    TBprotect(&(pt->action_table[s]));
  }
}

/*
  Adds the literal ATerm for a production to the production table.
  The label is the pointer in the table. It is used in reduce actions
  to refer to the production.
*/
void PT_grammar(term *grammar, parse_table *pt)
{
  term *production;
  int pr_num;
  int c;
  char str[2];
  int nr_of_productions;

  while (grammar != NULL) {
    production = first(grammar);
    grammar = next(grammar);
    if (!TBmatch(production, "label(%t, %d)", &production, &pr_num)) {
      fprintf(stderr, "PT_actions: cannot parse production\n");
      exit(1);
    }
    PROD(pt, pr_num) = production;
    TBprotect(&(PROD(pt, pr_num)));
    if (pr_num > nr_of_productions)
      nr_of_productions = pr_num;
  }
  if (debugflag || show_statistics)
    fprintf(log, "%d productions\n", nr_of_productions - 256);
  str[1] = '\0';
  for (c = 0; c <= 255; c++) {
    str[0] = c;
     PROD(pt, c) = TBmake("%d", c);
    TBprotect(&(PROD(pt, c)));
  }
}

/*

  \paragraph{Build Parse Table}

  Interpret term as parse table.

  Translating parse tree representation of parse table into parse
  table data structure.

*/
parse_table *build_parse_table(term *t)
{
  term *prods, *sts;
  parse_table *pt;

  pt = new_parse_table(3000, 2000);
  pt->org_table = t;
  TBprotect(&(pt->org_table));

  if(!TBmatch(t, "parse-table(%d,%t,states(%t))",
              &(pt->init), &prods, &sts)) {
    fprintf(stderr, "error: Cannot parse parse table\n");
    return NULL;
  }
  PT_states(sts, pt);
  PT_grammar(prods, pt);
  return pt;
}

/*
  \subsection{A Parse Table Database}

*/
#define MAX_TABLES 100

typedef struct _ptdb {
  char *name;
  parse_table *table;
} PTDB;
static PTDB tables[MAX_TABLES];
int last_table = 0;

void save_parse_table(char *L, parse_table *pt)
{
  int i;
  for (i = 0; i < last_table && strcmp(L, tables[i].name); i++) ;
  if (i > MAX_TABLES) {
    fprintf(stderr, "maximum number (%d) of languages exceeded\n", MAX_TABLES);
    exit(1);
  }
  if (i == last_table)
    last_table++;
  else
    ; /* free tables[i].table */
  tables[i].name = strdup(L);
  tables[i].table = pt;
  if (debugflag)
    fprintf(log, "language %s has index %d\n", L, i);
  return;
}

parse_table *lookup_parse_table(char *L)
{
  int i;

  if (debugflag)
    fprintf(log, "request for language %s\n", L);

  for (i = 0; i < last_table; i++)
    if (!strcmp(L, tables[i].name)) {
      if (debugflag)
        fprintf(log, "table for language %s found at index %d\n", L, i);
      return tables[i].table;
    } else if (debugflag)
      fprintf(log, "language %s not at index %d (%s)\n", L, i, tables[i].name);

  if (i > MAX_TABLES) {
    fprintf(stderr, "maximum number (%d) of languages exceeded\n", MAX_TABLES);
    exit(1);
  } else {
    fprintf(stderr, "no language %s open\n", L);
    exit(1);
  }
}
