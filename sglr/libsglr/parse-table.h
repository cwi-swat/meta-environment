/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

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
/*  $Id$  */

#ifndef _PARSE_TABLE_
#define _PARSE_TABLE_  1

#include <aterm2.h>
/*  Internal ATerm function: sglr happens to know to collect garbage.  */
void AT_collect(int size);
#define ATcollect()  AT_collect(2)

#include "sglr.h"

/*  Representation/data structures  */

#define HASH_PRIME    677;
typedef unsigned int  hashkey;

typedef struct _abucket {
  struct _abucket *next;
  state            s;
  token            c;
  actions          a;
} actionbucket;

typedef struct _actiontable {
  actionbucket **table;
  size_t         size;
  size_t         sizeclass;
} actiontable;

typedef struct _gbucket {
  struct _gbucket *next;
  state            from;
  label            l;
  state            to;
} gotobucket;

typedef struct _gototable {
  gotobucket **table;
  size_t     size;
  size_t     sizeclass;
} gototable;

typedef production *productiontable;
typedef ATbool     *injectiontable;
typedef ATermTable  prioritytable;

typedef struct _parse_table  {
  state            initial;
  size_t           numstates;
  size_t           numprods;
  actiontable      actions;
  gototable        gotos;
  productiontable  productions;
  injectiontable   injections;
  prioritytable    priorities;
} parse_table;

typedef enum ActionKind {ERROR, SHIFT, REDUCE, REDUCE_LA, ACCEPT}  actionkind;


/*  Some global variables/macros  */

#define SG_APPLLABEL    "#"
#define SG_REJECTLABEL  "X"
extern  token SG_EOF_Token;
extern  token SG_Zero_Token;

extern  AFun  SG_Regular_AFun, SG_Reject_AFun,
#ifndef NO_EAGERNESS
SG_Eager_AFun, SG_Uneager_AFun,
#endif
SG_Aprod_AFun, SG_Amb_AFun;

/*  Function prototypes  */

#define SG_Max(a,b)  ((a>b)?a:b)

state         SG_LookupGoto(parse_table *pt, state s, label l);
actions       SG_LookupAction(parse_table *pt, state s, token c);
production    SG_LookupProduction(parse_table *pt, label c);
ATbool        SG_ProdIsInjection(parse_table *pt, label l);
ATermList     SG_LookupPriority(parse_table *pt, label l);
ATermInt      SG_GetATint(int l, size_t numprods);

#ifdef HAVE_REJECTABILITY_DETERMINATION
ATbool SG_Rejectable(state s);
#else
#define SG_Rejectable(s)  ATtrue
#endif


actionkind    SG_ActionKind(action a);

#if 0
state         SG_A_STATE(action a);
int           SG_A_NR_ARGS(action a);
label         SG_A_PROD(action a);
int           SG_A_ATTRIBUTE(action a);
lookahead     SG_A_LOOKAHEAD(action a);

ATbool        SG_RegularAction(action a);
ATbool        SG_RejectAction(action a);
#ifndef NO_EAGERNESS
ATbool        SG_EagerAction(action a);
ATbool        SG_UneagerAction(action a);
#endif
#endif

parse_table  *SG_AddParseTable(char *prgname, char *L, char *FN);
void          SG_RemoveParseTable(char *L);
parse_table  *SG_BuildParseTable(ATermAppl t);
void          SG_SaveParseTable(char *L, parse_table *pt);
void          SG_ClearParseTable(char *L);
parse_table  *SG_LookupParseTable(char *L, ATbool may_fail);

/*  Constants in parse tables  */
#define       SG_PT_REGULAR         0
#define       SG_PT_REJECT          1    /*  Reject reduce in action table  */
#ifndef NO_EAGERNESS
#define       SG_PT_EAGER           2    /*  Preferred reduce  */
#define       SG_PT_UNEAGER         4    /*  Emergency-only reduction  */
#endif

#define       SG_PT_INITIAL(pt)     ((pt)->initial)
#define       SG_PT_NUMSTATES(pt)   ((pt)->numstates)
#define       SG_PT_NUMPRODS(pt)    ((pt)->numprods)
#define       SG_PT_ACTIONS(pt)     ((pt)->actions)
#define       SG_PT_GOTOS(pt)       ((pt)->gotos)
#define       SG_PT_PRODUCTIONS(pt) ((pt)->productions)
#define       SG_PT_INJECTIONS(pt)  ((pt)->injections)
#define       SG_PT_PRIORITIES(pt)  ((pt)->priorities)

#define       SG_A_STATE(a)         ATgetInt((ATermInt) ATgetArgument(a, 0))
#define       SG_A_NR_ARGS(a)       ATgetInt((ATermInt) ATgetArgument(a, 0))
#define       SG_A_PROD(a)          ATgetInt((ATermInt) ATgetArgument(a, 1))
#define       SG_A_ATTRIBUTE(a)     ATgetInt((ATermInt) ATgetArgument(a, 2))
#define       SG_A_LOOKAHEAD(a)     (lookahead) ATgetInt((ATermInt) ATgetArgument(a, 3))

#define       SG_RegularAction(a)   (SG_A_ATTRIBUTE(a) == SG_PT_REGULAR)
#define       SG_RejectAction(a)    (SG_A_ATTRIBUTE(a) == SG_PT_REJECT)

#ifndef NO_EAGERNESS
#define       SG_EagerAction(a)     (SG_A_ATTRIBUTE(a) == SG_PT_EAGER)
#define       SG_UneagerAction(a)   (SG_A_ATTRIBUTE(a) == SG_PT_UNEAGER)
#endif
#endif /*  _PARSE_TABLE_  */
