#include "support.h"
static asymbol * lf_AUX_MuASF_Conds2C1_3sym;
static aterm * lf_AUX_MuASF_Conds2C1_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * lf_AUX_MuASF_Conds2C1_1sym;
static aterm * lf_AUX_MuASF_Conds2C1_1( aterm * arg1);
static asymbol * lf_AUX_MuASF_Conds2C1_2sym;
static aterm * lf_AUX_MuASF_Conds2C1_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
void register_AUX_MuASF_Conds2C1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Conds2C1_3sym= TmkSymbol( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_MuASF_Conds2C1_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_MuASF_Conds2C1_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Conds2C1_1 , lf_AUX_MuASF_Conds2C1_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Conds2C1_2 , lf_AUX_MuASF_Conds2C1_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"conds2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Conds2C1_3 , lf_AUX_MuASF_Conds2C1_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf7 , lf7sym);
}
void resolve_AUX_MuASF_Conds2C1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2cstats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-lhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-lhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Conds2C1_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3) {
{
aterm * tmp[30];
PROF( prof_lf_AUX_MuASF_Conds2C1_3);
if( check_sym( arg0 , lf_AUX_MuASF_Conds2C1_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , lf_AUX_MuASF_Conds2C1_2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
tmp[ 4]= arg_3( tmp[ 0]);
tmp[ 5]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 6]= arg_0( tmp[ 1]);
{
if( check_sym( tmp[ 2] , lf5sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
{
t_protect( tmp[ 7]);
if( ! not_empty_list( tmp[ 7])) {
t_protect( atmp00);
tmp[ 8]= list_tail( atmp00);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( arg1);
t_protect( atmp20);
t_protect( arg3);
tmp[ 9]= ( * ef4)( ( * ef5)( ) , tmp[ 3] , tmp[ 4] , tmp[ 5] , arg1 , lf_AUX_MuASF_Conds2C1_2( make_list( atmp20)) , arg3);
if( check_sym( tmp[ 9] , ef1sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
t_protect( tmp[ 10]);
t_protect( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
return ( * ef1)( tmp[ 10] , tmp[ 11]);
}
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 8]);
}
else {
t_protect( tmp[ 7]);
tmp[ 8]= list_head( tmp[ 7]);
if( check_sym( tmp[ 8] , ef6sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
if( check_sym( tmp[ 9] , ef7sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 11] , ef8sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
if( check_sym( tmp[ 13] , lf6sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 12] , lf7sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
t_protect( tmp[ 14]);
if( not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 116))) {
t_protect( tmp[ 14]);
tmp[ 16]= list_tail( tmp[ 14]);
t_protect( tmp[ 16]);
if( not_empty_list( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 101))) {
t_protect( tmp[ 16]);
tmp[ 17]= list_tail( tmp[ 16]);
t_protect( tmp[ 17]);
if( not_empty_list( tmp[ 17])) {
t_protect( tmp[ 17]);
if( term_equal( list_head( tmp[ 17]) , make_char( 114))) {
t_protect( tmp[ 17]);
tmp[ 18]= list_tail( tmp[ 17]);
t_protect( tmp[ 18]);
if( not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 109))) {
t_protect( tmp[ 18]);
tmp[ 19]= list_tail( tmp[ 18]);
t_protect( tmp[ 19]);
if( not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 45))) {
t_protect( tmp[ 19]);
tmp[ 20]= list_tail( tmp[ 19]);
t_protect( tmp[ 20]);
if( not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 101))) {
t_protect( tmp[ 20]);
tmp[ 21]= list_tail( tmp[ 20]);
t_protect( tmp[ 21]);
if( not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 113))) {
t_protect( tmp[ 21]);
tmp[ 22]= list_tail( tmp[ 21]);
t_protect( tmp[ 22]);
if( not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 117))) {
t_protect( tmp[ 22]);
tmp[ 23]= list_tail( tmp[ 22]);
t_protect( tmp[ 23]);
if( not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 97))) {
t_protect( tmp[ 23]);
tmp[ 24]= list_tail( tmp[ 23]);
t_protect( tmp[ 24]);
if( is_single_element( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 108))) {
t_protect( tmp[ 15]);
if( not_empty_list( tmp[ 15])) {
t_protect( tmp[ 7]);
tmp[ 25]= list_tail( tmp[ 7]);
t_protect( atmp00);
tmp[ 26]= list_tail( atmp00);
t_protect( tmp[ 26]);
if( not_empty_list( tmp[ 26])) {
t_protect( tmp[ 6]);
t_protect( tmp[ 15]);
t_protect( tmp[ 10]);
t_protect( tmp[ 25]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 26]);
t_protect( arg1);
t_protect( atmp20);
t_protect( arg3);
tmp[ 27]= ( * ef9)( lf_AUX_MuASF_Conds2C1_1( cons( make_list( ( * ef3)( lf4( make_list( tmp[ 6])) , lf5( cons( make_list( ( * ef6)( ( * ef7)( ( * ef8)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))) , lf7( make_list( tmp[ 15]))) , tmp[ 10])) , make_list( tmp[ 25]))) , tmp[ 3] , tmp[ 4] , tmp[ 5])) , make_list( tmp[ 26]))) , arg1 , lf_AUX_MuASF_Conds2C1_2( make_list( atmp20)) , arg3);
if( check_sym( tmp[ 27] , ef1sym)) {
tmp[ 28]= arg_0( tmp[ 27]);
tmp[ 29]= arg_1( tmp[ 27]);
t_protect( tmp[ 28]);
t_protect( tmp[ 29]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
return ( * ef1)( tmp[ 28] , tmp[ 29]);
}
t_unprotect( tmp[ 27]);
}
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 25]);
}
}
}
t_unprotect( tmp[ 24]);
}
}
t_unprotect( tmp[ 23]);
}
}
t_unprotect( tmp[ 22]);
}
}
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
}
}
t_unprotect( tmp[ 18]);
}
}
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 16]);
}
}
}
}
}
}
}
t_unprotect( tmp[ 8]);
}
}
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef1)( ( * ef2)( ) , arg3);
}
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
tmp[ 4]= arg_3( tmp[ 0]);
tmp[ 5]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 6]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf5sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 6]);
t_protect( tmp[ 7]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( arg1);
t_protect( atmp20);
t_protect( arg3);
tmp[ 8]= ( * ef9)( lf_AUX_MuASF_Conds2C1_1( make_list( ( * ef3)( lf4( make_list( tmp[ 6])) , lf5( make_list( tmp[ 7])) , tmp[ 3] , tmp[ 4] , tmp[ 5]))) , arg1 , lf_AUX_MuASF_Conds2C1_2( make_list( atmp20)) , arg3);
if( check_sym( tmp[ 8] , ef1sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
t_protect( tmp[ 9]);
t_protect( tmp[ 10]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
return ( * ef1)( tmp[ 9] , tmp[ 10]);
}
t_unprotect( tmp[ 8]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg0 , lf_AUX_MuASF_Conds2C1_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , lf_AUX_MuASF_Conds2C1_2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
tmp[ 4]= arg_3( tmp[ 0]);
tmp[ 5]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 1] , lf4sym)) {
tmp[ 6]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf5sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( atmp00);
tmp[ 8]= list_tail( atmp00);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 6]);
t_protect( tmp[ 7]);
t_protect( tmp[ 3]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 8]);
tmp[ 9]= ( * ef10)( ( * ef3)( lf4( make_list( tmp[ 6])) , lf5( make_list( tmp[ 7])) , tmp[ 3] , tmp[ 4] , tmp[ 5]) , lf_AUX_MuASF_Conds2C1_1( make_list( tmp[ 8])));
if( check_sym( tmp[ 9] , ef11sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 10] , lf_AUX_MuASF_Conds2C1_1sym)) {
tmp[ 12]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf_AUX_MuASF_Conds2C1_1sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
t_protect( tmp[ 12]);
t_protect( arg1);
t_protect( atmp20);
t_protect( arg3);
tmp[ 14]= ( * ef9)( lf_AUX_MuASF_Conds2C1_1( make_list( tmp[ 12])) , arg1 , lf_AUX_MuASF_Conds2C1_2( make_list( atmp20)) , arg3);
if( check_sym( tmp[ 14] , ef1sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
tmp[ 16]= arg_1( tmp[ 14]);
t_protect( tmp[ 13]);
t_protect( arg1);
t_protect( atmp20);
t_protect( arg3);
tmp[ 17]= lf_AUX_MuASF_Conds2C1_3( lf_AUX_MuASF_Conds2C1_1( make_list( tmp[ 13])) , arg1 , lf_AUX_MuASF_Conds2C1_2( make_list( atmp20)) , arg3);
if( check_sym( tmp[ 17] , ef1sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
tmp[ 19]= arg_1( tmp[ 17]);
t_protect( tmp[ 15]);
t_protect( tmp[ 18]);
tmp[ 20]= ( * ef12)( tmp[ 15] , tmp[ 18]);
t_protect( tmp[ 16]);
t_protect( tmp[ 19]);
tmp[ 21]= ( * ef13)( tmp[ 16] , tmp[ 19]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 17]);
return ( * ef1)( tmp[ 20] , tmp[ 21]);
}
t_unprotect( tmp[ 17]);
}
t_unprotect( tmp[ 14]);
}
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 8]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf4( lf_AUX_MuASF_Conds2C1_3sym , arg0 , arg1 , arg2 , arg3);
}
}
aterm * lf_AUX_MuASF_Conds2C1_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C1_2);
return make_nf1( lf_AUX_MuASF_Conds2C1_2sym , arg0);
}
aterm * lf_AUX_MuASF_Conds2C1_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C1_1);
return make_nf1( lf_AUX_MuASF_Conds2C1_1sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}

