#include "support.h"
static asymbol * lf_AUX_MuASF_Conds2C6_3sym;
static aterm * lf_AUX_MuASF_Conds2C6_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * lf8sym;
static aterm * lf8( aterm * arg1);
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * lf_AUX_MuASF_Conds2C6_1sym;
static aterm * lf_AUX_MuASF_Conds2C6_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * lf_AUX_MuASF_Conds2C6_2sym;
static aterm * lf_AUX_MuASF_Conds2C6_2( aterm * arg1);
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef19sym;
static funcptr ef19;
void register_AUX_MuASF_Conds2C6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Conds2C6_3sym= TmkSymbol( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"listconds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf8sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Conds2C6_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_MuASF_Conds2C6_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Conds2C6_1 , lf_AUX_MuASF_Conds2C6_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Conds2C6_2 , lf_AUX_MuASF_Conds2C6_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"listconds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Conds2C6_3 , lf_AUX_MuASF_Conds2C6_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf7 , lf7sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf8 , lf8sym);
}
void resolve_AUX_MuASF_Conds2C6( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"listcondspatterns2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"listcondspatterns2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_MuASF_Conds2C6_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
{
aterm * tmp[23];
PROF( prof_lf_AUX_MuASF_Conds2C6_3);
if( check_sym( arg0 , lf_AUX_MuASF_Conds2C6_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , lf_AUX_MuASF_Conds2C6_2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
if( m_not_empty_list( tmp[ 8])) {
tmp[ 9]= m_list_head( tmp[ 8]);
tmp[ 10]= m_list_tail( tmp[ 8]);
if( check_sym( tmp[ 9] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 12] , ef3sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
tmp[ 14]= arg_1( tmp[ 12]);
if( check_sym( tmp[ 14] , lf6sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 13]);
t_protect( arg4);
t_protect( atmp20);
tmp[ 16]= ( * ef5)( tmp[ 13] , arg4 , lf_AUX_MuASF_Conds2C6_2( make_list( atmp20)));
t_protect( arg3);
tmp[ 17]= ( * ef6)( ( * ef7)( arg3));
t_protect( tmp[ 17]);
t_protect( arg4);
tmp[ 18]= ( * ef8)( ( * ef9)( ( * ef10)( ( * ef11)( tmp[ 17] , ( * ef6)( ( * ef12)( ( * ef13)( ( * ef14)( lf7( cons( make_list( make_char( 97)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 103)) , cons( make_list( make_char( 95)) , make_list( make_char( 48))))))))) , ( * ef15)( lf8( make_list( arg4)))))))));
t_protect( tmp[ 7]);
t_protect( tmp[ 11]);
t_protect( tmp[ 13]);
t_protect( tmp[ 15]);
t_protect( tmp[ 10]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( arg1);
t_protect( atmp20);
t_protect( arg3);
tmp[ 19]= ( * ef16)( lf_AUX_MuASF_Conds2C6_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( tmp[ 11] , ( * ef3)( tmp[ 13] , lf6( make_list( tmp[ 15]))))) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , tmp[ 17] , arg1 , lf_AUX_MuASF_Conds2C6_2( make_list( atmp20)) , ( * ef17)( arg3));
if( check_sym( tmp[ 19] , ef4sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
tmp[ 21]= arg_1( tmp[ 19]);
t_protect( tmp[ 16]);
t_protect( tmp[ 18]);
t_protect( tmp[ 20]);
tmp[ 22]= ( * ef18)( tmp[ 16] , ( * ef19)( tmp[ 18] , tmp[ 20]));
t_protect( tmp[ 21]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( arg4);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
return ( * ef4)( tmp[ 22] , tmp[ 21]);
}
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 16]);
}
}
}
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf5( lf_AUX_MuASF_Conds2C6_3sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
}
aterm * lf_AUX_MuASF_Conds2C6_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C6_2);
return make_nf1( lf_AUX_MuASF_Conds2C6_2sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_MuASF_Conds2C6_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C6_1);
return make_nf1( lf_AUX_MuASF_Conds2C6_1sym , arg0);
}
aterm * lf8( aterm * arg0) {
PROF( prof_lf8);
return make_nf1( lf8sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}

