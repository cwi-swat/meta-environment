#include "support.h"
static asymbol * lf_AUX_Remove_Lists_C19_2sym;
static aterm * lf_AUX_Remove_Lists_C19_2( aterm * arg1 , aterm * arg2);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Remove_Lists_C19_1sym;
static aterm * lf_AUX_Remove_Lists_C19_1( aterm * arg1);
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef14sym;
static funcptr ef14;
void register_AUX_Remove_Lists_C19( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_C19_2sym= TmkSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-double-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Remove_Lists_C19_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Remove_Lists_C19_1 , lf_AUX_Remove_Lists_C19_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-double-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C19_2 , lf_AUX_Remove_Lists_C19_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
}
void resolve_AUX_Remove_Lists_C19( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"make-new-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"make-new-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"get-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"get-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newlistvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newlistvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"put-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"put-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_C19_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[23];
PROF( prof_lf_AUX_Remove_Lists_C19_2);
if( check_sym( arg0 , lf_AUX_Remove_Lists_C19_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
{
t_protect( atmp00);
tmp[ 1]= list_tail( atmp00);
t_protect( tmp[ 1]);
if( is_single_element( tmp[ 1])) {
t_protect( tmp[ 1]);
tmp[ 2]= list_head( tmp[ 1]);
t_protect( tmp[ 0]);
tmp[ 3]= ( * ef9)( tmp[ 0]);
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , ( * ef10)( ))) {
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 4]= ( * ef11)( tmp[ 0] , arg1);
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
tmp[ 7]= arg_2( tmp[ 4]);
{
if( check_sym( tmp[ 5] , lf_AUX_Remove_Lists_C19_1sym)) {
tmp[ 8]= arg_0( tmp[ 5]);
{
if( check_sym( tmp[ 6] , lf3sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
t_protect( tmp[ 8]);
if( is_single_element( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 10]= list_head( tmp[ 8]);
t_protect( tmp[ 2]);
tmp[ 11]= ( * ef9)( tmp[ 2]);
t_protect( tmp[ 11]);
if( term_equal( tmp[ 11] , ( * ef10)( ))) {
t_protect( tmp[ 2]);
t_protect( tmp[ 7]);
tmp[ 12]= ( * ef11)( tmp[ 2] , tmp[ 7]);
if( check_sym( tmp[ 12] , ef1sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
tmp[ 14]= arg_1( tmp[ 12]);
tmp[ 15]= arg_2( tmp[ 12]);
if( check_sym( tmp[ 13] , lf_AUX_Remove_Lists_C19_1sym)) {
tmp[ 16]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 14] , lf3sym)) {
tmp[ 17]= arg_0( tmp[ 14]);
t_protect( tmp[ 16]);
if( is_single_element( tmp[ 16])) {
t_protect( tmp[ 16]);
tmp[ 18]= list_head( tmp[ 16]);
t_protect( tmp[ 15]);
tmp[ 19]= ( * ef12)( tmp[ 15]);
t_protect( tmp[ 19]);
tmp[ 20]= ( * ef13)( tmp[ 19]);
t_protect( tmp[ 19]);
tmp[ 21]= ( * ef13)( ( * ef14)( tmp[ 19]));
t_protect( tmp[ 19]);
t_protect( tmp[ 15]);
tmp[ 22]= ( * ef15)( ( * ef14)( ( * ef14)( tmp[ 19])) , tmp[ 15]);
t_protect( tmp[ 20]);
t_protect( tmp[ 20]);
t_protect( tmp[ 20]);
t_protect( tmp[ 9]);
t_protect( tmp[ 21]);
t_protect( tmp[ 21]);
t_protect( tmp[ 17]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 19]);
return ( * ef1)( lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 20])))) , lf3( cons( make_list( ( * ef4)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 20]))))) , ( * ef7)( ( * ef6)( lf4( make_list( make_char( 116))))))) , cons( make_list( ( * ef8)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100)))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 20]))))) , tmp[ 10])) , cons( make_list( tmp[ 9]) , cons( make_list( ( * ef4)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108)))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 20]))))) , ( * ef2)( ( * ef3)( tmp[ 21])))) , cons( make_list( ( * ef4)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 103)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 116)))))))))))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 21]))))) , ( * ef7)( ( * ef6)( lf4( make_list( make_char( 116))))))) , cons( make_list( ( * ef8)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100)))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 21]))))) , tmp[ 18])) , make_list( tmp[ 17])))))))) , tmp[ 22]);
}
}
}
}
t_unprotect( tmp[ 12]);
}
t_protect( tmp[ 11]);
if( term_equal( tmp[ 11] , ( * ef16)( ))) {
t_protect( tmp[ 2]);
t_protect( tmp[ 7]);
tmp[ 12]= ( * ef17)( tmp[ 2] , tmp[ 7]);
if( check_sym( tmp[ 12] , ef1sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
tmp[ 14]= arg_1( tmp[ 12]);
tmp[ 15]= arg_2( tmp[ 12]);
if( check_sym( tmp[ 13] , lf_AUX_Remove_Lists_C19_1sym)) {
tmp[ 16]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 14] , lf3sym)) {
tmp[ 17]= arg_0( tmp[ 14]);
t_protect( tmp[ 16]);
if( is_single_element( tmp[ 16])) {
t_protect( tmp[ 16]);
tmp[ 18]= list_head( tmp[ 16]);
t_protect( tmp[ 15]);
tmp[ 19]= ( * ef12)( tmp[ 15]);
t_protect( tmp[ 19]);
tmp[ 20]= ( * ef13)( tmp[ 19]);
t_protect( tmp[ 19]);
t_protect( tmp[ 15]);
tmp[ 21]= ( * ef15)( ( * ef14)( tmp[ 19]) , tmp[ 15]);
t_protect( tmp[ 20]);
t_protect( tmp[ 20]);
t_protect( tmp[ 20]);
t_protect( tmp[ 9]);
t_protect( tmp[ 17]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 19]);
return ( * ef1)( lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 20])))) , lf3( cons( make_list( ( * ef4)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 20]))))) , ( * ef7)( ( * ef6)( lf4( make_list( make_char( 116))))))) , cons( make_list( ( * ef8)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100)))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 20]))))) , tmp[ 10])) , cons( make_list( tmp[ 9]) , cons( make_list( ( * ef4)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108)))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 20]))))) , tmp[ 18])) , make_list( tmp[ 17])))))) , tmp[ 21]);
}
}
}
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 10]);
}
}
}
}
}
}
t_unprotect( tmp[ 4]);
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , ( * ef16)( ))) {
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 4]= ( * ef17)( tmp[ 0] , arg1);
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
tmp[ 7]= arg_2( tmp[ 4]);
if( check_sym( tmp[ 5] , lf_AUX_Remove_Lists_C19_1sym)) {
tmp[ 8]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf3sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
t_protect( tmp[ 8]);
if( is_single_element( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 10]= list_head( tmp[ 8]);
t_protect( tmp[ 2]);
if( term_equal( ( * ef9)( tmp[ 2]) , ( * ef10)( ))) {
t_protect( tmp[ 2]);
t_protect( tmp[ 7]);
tmp[ 11]= ( * ef11)( tmp[ 2] , tmp[ 7]);
if( check_sym( tmp[ 11] , ef1sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
tmp[ 13]= arg_1( tmp[ 11]);
tmp[ 14]= arg_2( tmp[ 11]);
if( check_sym( tmp[ 12] , lf_AUX_Remove_Lists_C19_1sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 13] , lf3sym)) {
tmp[ 16]= arg_0( tmp[ 13]);
t_protect( tmp[ 15]);
if( is_single_element( tmp[ 15])) {
t_protect( tmp[ 15]);
tmp[ 17]= list_head( tmp[ 15]);
t_protect( tmp[ 14]);
tmp[ 18]= ( * ef12)( tmp[ 14]);
t_protect( tmp[ 18]);
tmp[ 19]= ( * ef13)( tmp[ 18]);
t_protect( tmp[ 18]);
t_protect( tmp[ 14]);
tmp[ 20]= ( * ef15)( ( * ef14)( tmp[ 18]) , tmp[ 14]);
t_protect( tmp[ 19]);
t_protect( tmp[ 19]);
t_protect( tmp[ 19]);
t_protect( tmp[ 9]);
t_protect( tmp[ 16]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 18]);
return ( * ef1)( lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 19])))) , lf3( cons( make_list( ( * ef4)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 19]))))) , ( * ef7)( ( * ef6)( lf4( make_list( make_char( 116))))))) , cons( make_list( ( * ef4)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 102)) , cons( make_list( make_char( 105)) , make_list( make_char( 120)))))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 19]))))) , tmp[ 10])) , cons( make_list( tmp[ 9]) , cons( make_list( ( * ef8)( ( * ef5)( ( * ef6)( lf4( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))) , lf_AUX_Remove_Lists_C19_1( make_list( ( * ef2)( ( * ef3)( tmp[ 19]))))) , tmp[ 17])) , make_list( tmp[ 16])))))) , tmp[ 20]);
}
}
}
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
}
}
t_unprotect( tmp[ 4]);
}
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_Remove_Lists_C19_2sym , arg0 , arg1);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf_AUX_Remove_Lists_C19_1( aterm * arg0) {
PROF( prof_lf_AUX_Remove_Lists_C19_1);
return make_nf1( lf_AUX_Remove_Lists_C19_1sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

