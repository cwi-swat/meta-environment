/*
  %% $Id$

*/

#ifndef _PARSE_TABLE_
#define _PARSE_TABLE_  1

#include <aterm2.h>

/*
   states, actions, character ranges and parse tables
*/
typedef ATermList aterms;
typedef int state;
typedef struct _parse_table parse_table;


typedef ATerm     action;
typedef ATermList actions;
typedef ATerm     production;

enum ActionKind {ERROR, SHIFT, REDUCE, ACCEPT, REDUCE_CONST};

/*
   Functions
*/

#define SG_Max(a,b)  ((a>b)?a:b)

state      SG_LookupGoto(parse_table *pt, state s, int c);
actions    SG_LookupAction(parse_table *pt, state s, int c);
production SG_LookupProduction(parse_table *pt, int token);
ATermList  SG_LookupPriority(parse_table *pt, ATermInt prodlabel);

#define    SG_INIT(ptable)    ((ptable)->init)

int       SG_ActionKind(action a);
#ifdef A_FUNCS
  state   SG_A_STATE(action a);
  int     SG_A_NR_ARGS(action a);
  int     SG_A_PROD(action a);
  ATbool  SG_A_REJECT(action a);
#else
  #define SG_A_STATE(a)    ATgetInt((ATermInt) ATgetArgument(a, 0))
  #define SG_A_NR_ARGS(a)  ATgetInt((ATermInt) ATgetArgument(a, 0))
  #define SG_A_PROD(a)     ATgetInt((ATermInt) ATgetArgument(a, 1))
  #define SG_A_REJECT(a)   (ATgetInt((ATermInt)ATgetArgument(a, 2))?ATtrue:ATfalse)
#endif

parse_table   *SG_BuildParseTable(ATerm t);
void          SG_SaveParseTable(char *L, parse_table *pt);
parse_table   *SG_LookupParseTable(char *L, ATbool may_fail);

/*
  Representation
*/

struct _parse_table  {
  state      init;
  ATermTable actions;
  ATermTable gotos;
  ATermTable productions;
  ATermTable priorities;
};

#endif	/*  _PARSE_TABLE_  */
