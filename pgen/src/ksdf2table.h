#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <aterm2.h>
#include <MEPT-utils.h>
#include <SDFME-utils.h>

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
