/*
  %% $Id$

*/

#ifndef _PARSE_TABLE
#define _PARSE_TABLE

#include <TB.h>

/*
   states, actions, character ranges and parse tables
*/
typedef term terms;
typedef int state;
typedef term action;
typedef term actions;
typedef struct _parse_table parse_table;

enum ActionKind {ERROR, SHIFT, REDUCE, ACCEPT, REDUCE_CONST};

/*
   Functions
*/

state   GOTO(parse_table *pt, state s, int c);
actions *ACTIONS(parse_table *pt, state s, int c);

#define INIT(ptable)       ((ptable)->init)
#define PROD(ptable, n)    ((ptable)->productions[n].aterm)
#define PCONS(ptable, n)   ((ptable)->productions[n].cons)

#define NEXT_ACTION(as) next(as)
#define A_NR_ARGS(a)    int_val(first(fun_args(a)))
#define A_PROD(a)       int_val(elm2(fun_args(a)))
#define A_REJECT(a)     int_val(elm3(fun_args(a)))
#define A_STATE(a)      int_val(first(fun_args(a)))

int A_KIND(action *a);

parse_table *build_parse_table(term *t);

void save_parse_table(char *L, parse_table *pt);
parse_table *lookup_parse_table(char *L);

/*
  representation
*/

struct _production {
  term *aterm;
  term *(*cons)(term*);
};

typedef struct _production production;

struct _parse_table  {
  state       init;
  term      **action_table;
  term      **goto_table;
  production *productions;
  term      **vertices;
  term       *org_table;
};

#endif
