/*

    PGEN - the SDF2 parse table generator.
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
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <aterm2.h>
#include <AsFix.h>
#include <AsFix2src.h>
#include <AsFix-access.h>
#include <AsFix-expand.h>
#include <AsFix-init-patterns.h> 
#include <PT-utils.h>
#include <SDF-utils.h>

#include "atsets.h"
#include "statistics.h"

#ifdef WIN32
     #include <string.h>
     #include <fcntl.h>
     #include <io.h>
     #define streq(a,b) (!strcmp((a),(b)))
#else
     #include <atb-tool.h>
     #include "parsetablegen.tif.h"
#endif

#define SDF_EOF  256
#define MIN_PROD (SDF_EOF+1)

/*{{{  external patterns */

extern ATerm pattern_asfix_lex;
extern ATerm pattern_asfix_lit;
extern ATerm pattern_asfix_l;
extern ATerm pattern_asfix_appl;
extern ATerm pattern_asfix_str;
extern ATerm pattern_asfix_id;

/*}}}  */
/*{{{  external functions */

extern char *unquote_str(char *s);

/*}}}  */
/*{{{  AFuns */

extern AFun afun_range;
extern AFun afun_char_class;
extern AFun afun_item;
extern AFun afun_action;
extern AFun afun_prod;
extern AFun afun_goto;
extern AFun afun_shift;
extern AFun afun_left_prio;
extern AFun afun_right_prio;
extern AFun afun_assoc_prio;
extern AFun afun_non_assoc_prio;
extern AFun afun_gtr_prio;
extern AFun afun_lit;

extern ATerm empty_set;
extern ATerm eof_token;
extern ATerm all_chars;

#define GET_ARG(t,n)      (ATgetArgument((ATermAppl)(t), n))
#define GET_INT_ARG(t,n)  ((ATermInt)GET_ARG(t,n))
#define GET_LIST_ARG(t,n) ((ATermList)GET_ARG(t,n))
#define IS_ACTION(t)      (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_action)
#define IS_CHARCLASS(t)   (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_char_class)
#define IS_GOTO(t)        (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_goto)
#define IS_ITEM(t)        (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_item)
#define IS_PROD(t)        (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_prod)
#define IS_RANGE(t)       (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_range)
#define IS_SHIFT(t)       (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_shift)

/*}}}  */
/*{{{  variables */

extern ATermSOS *state_sos;

/*}}}  */
ATerm generate_parse_table(PT_ParseTree g);
void init_table_gen();
void destroy_table_gen();
