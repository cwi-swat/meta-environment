#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <aterm2.h>
#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <SDF2PT.h>

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

#ifdef DMALLOC
#include <dmalloc.h>
#endif

#define SDF_EOF  256
#define MIN_PROD (SDF_EOF+1)
#define MAX_STATES  130000

/*{{{  external functions */

extern char *unquote_str(char *s);

/*}}}  */
/*{{{  AFuns */

extern AFun afun_action;
extern AFun afun_prod;
extern AFun afun_goto;
extern AFun afun_shift;
extern AFun afun_gtr_prio;
extern AFun afun_arg_gtr_prio;
extern AFun afun_lit;

extern ATerm eof_token;
extern ATerm all_chars;  

#define GET_ARG(t,n)      (ATgetArgument((ATermAppl)(t), n))
#define GET_INT_ARG(t,n)  ((ATermInt)GET_ARG(t,n))
#define GET_LIST_ARG(t,n) ((ATermList)GET_ARG(t,n))
#define IS_ACTION(t)      (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_action)
#define IS_CHARCLASS(t)   (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == get_afun_char_class())
#define IS_GOTO(t)        (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_goto)
#define IS_PROD(t)        (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_prod)
#define IS_RANGE(t)       (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_range)
#define IS_SHIFT(t)       (ATgetType(t) == AT_APPL && ATgetAFun((ATermAppl)(t)) == afun_shift)

/*}}}  */
/*{{{  variables */

extern ATermSOS *state_sos;
extern ATermIndexedSet priority_table;
extern ATermTable rhs_prods_pairs;
extern ATerm *nr_prod_table;
extern ATerm **symbol_table;
extern int max_nr_lhs_members;
extern int MAX_PROD;

/*}}}  */
ATerm generate_parse_table(int version_nr, SDF_Grammar g);
void init_table_gen();
void destroy_table_gen();
AFun get_afun_char_class();
