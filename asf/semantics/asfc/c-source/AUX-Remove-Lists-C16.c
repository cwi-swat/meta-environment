#include "support.h"
static asymbol * lf_AUX_Remove_Lists_C16_2sym;
static aterm * lf_AUX_Remove_Lists_C16_2( aterm * arg1 , aterm * arg2);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_Remove_Lists_C16_1sym;
static aterm * lf_AUX_Remove_Lists_C16_1( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
void register_AUX_Remove_Lists_C16( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_C16_2sym= TmkSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-no-list-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Remove_Lists_C16_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Remove_Lists_C16_1 , lf_AUX_Remove_Lists_C16_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-no-list-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C16_2 , lf_AUX_Remove_Lists_C16_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
}
void resolve_AUX_Remove_Lists_C16( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"make-new-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"make-new-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"get-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"get-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newlistvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newlistvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"put-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"put-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"get-last-element\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"get-last-element\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"get-prefix-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"get-prefix-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_C16_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[38];
PROF( prof_lf_AUX_Remove_Lists_C16_2);
if( check_sym( arg0 , lf_AUX_Remove_Lists_C16_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 1]);
{
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
{
if( check_sym( tmp[ 2] , lf_AUX_Remove_Lists_C16_1sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
t_protect( tmp[ 4]);
if( not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
tmp[ 6]= list_head( tmp[ 4]);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 99))) {
t_protect( tmp[ 4]);
tmp[ 7]= list_tail( tmp[ 4]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
tmp[ 8]= list_head( tmp[ 7]);
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 111))) {
t_protect( tmp[ 7]);
tmp[ 9]= list_tail( tmp[ 7]);
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
tmp[ 10]= list_head( tmp[ 9]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 110))) {
t_protect( tmp[ 9]);
tmp[ 11]= list_tail( tmp[ 9]);
t_protect( tmp[ 11]);
if( is_single_element( tmp[ 11])) {
t_protect( tmp[ 11]);
tmp[ 12]= list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 115))) {
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
tmp[ 13]= list_head( tmp[ 5]);
{
t_protect( tmp[ 5]);
tmp[ 14]= list_tail( tmp[ 5]);
t_protect( tmp[ 14]);
if( is_single_element( tmp[ 14])) {
t_protect( tmp[ 14]);
tmp[ 15]= list_head( tmp[ 14]);
t_protect( tmp[ 15]);
tmp[ 16]= ( * ef9)( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , ( * ef10)( ))) {
t_protect( tmp[ 13]);
t_protect( arg1);
tmp[ 17]= ( * ef11)( tmp[ 13] , arg1);
if( check_sym( tmp[ 17] , ef3sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
tmp[ 19]= arg_1( tmp[ 17]);
tmp[ 20]= arg_2( tmp[ 17]);
if( check_sym( tmp[ 18] , lf_AUX_Remove_Lists_C16_1sym)) {
tmp[ 21]= arg_0( tmp[ 18]);
if( check_sym( tmp[ 19] , lf4sym)) {
tmp[ 22]= arg_0( tmp[ 19]);
t_protect( tmp[ 21]);
if( is_single_element( tmp[ 21])) {
t_protect( tmp[ 21]);
tmp[ 23]= list_head( tmp[ 21]);
t_protect( tmp[ 15]);
t_protect( tmp[ 20]);
tmp[ 24]= ( * ef12)( tmp[ 15] , tmp[ 20]);
if( check_sym( tmp[ 24] , ef3sym)) {
tmp[ 25]= arg_0( tmp[ 24]);
tmp[ 26]= arg_1( tmp[ 24]);
tmp[ 27]= arg_2( tmp[ 24]);
if( check_sym( tmp[ 25] , lf_AUX_Remove_Lists_C16_1sym)) {
tmp[ 28]= arg_0( tmp[ 25]);
if( check_sym( tmp[ 26] , lf4sym)) {
tmp[ 29]= arg_0( tmp[ 26]);
t_protect( tmp[ 28]);
if( is_single_element( tmp[ 28])) {
t_protect( tmp[ 28]);
tmp[ 30]= list_head( tmp[ 28]);
t_protect( tmp[ 27]);
tmp[ 31]= ( * ef13)( tmp[ 27]);
t_protect( tmp[ 31]);
tmp[ 32]= ( * ef14)( tmp[ 31]);
t_protect( tmp[ 31]);
t_protect( tmp[ 27]);
tmp[ 33]= ( * ef15)( ( * ef16)( tmp[ 31]) , tmp[ 27]);
t_protect( tmp[ 32]);
t_protect( tmp[ 32]);
t_protect( tmp[ 22]);
t_protect( tmp[ 32]);
t_protect( tmp[ 29]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 31]);
return ( * ef3)( lf_AUX_Remove_Lists_C16_1( make_list( ( * ef4)( ( * ef5)( tmp[ 32])))) , lf4( cons( make_list( ( * ef6)( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 102)) , cons( make_list( make_char( 105)) , make_list( make_char( 120)))))))))))))) , lf_AUX_Remove_Lists_C16_1( make_list( ( * ef4)( ( * ef5)( tmp[ 32]))))) , tmp[ 23])) , cons( make_list( tmp[ 22]) , cons( make_list( ( * ef6)( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))))))))) , lf_AUX_Remove_Lists_C16_1( make_list( ( * ef4)( ( * ef5)( tmp[ 32]))))) , ( * ef7)( ( * ef2)( lf3( make_list( make_char( 116))))))) , cons( make_list( ( * ef8)( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))) , lf_AUX_Remove_Lists_C16_1( make_list( ( * ef4)( ( * ef5)( tmp[ 32]))))) , tmp[ 30])) , make_list( tmp[ 29])))))) , tmp[ 33]);
}
}
}
}
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 23]);
}
}
}
}
t_unprotect( tmp[ 17]);
}
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , ( * ef17)( ))) {
t_protect( tmp[ 15]);
tmp[ 17]= ( * ef18)( tmp[ 15]);
t_protect( tmp[ 17]);
t_protect( arg1);
tmp[ 18]= ( * ef12)( tmp[ 17] , arg1);
if( check_sym( tmp[ 18] , ef3sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
tmp[ 20]= arg_1( tmp[ 18]);
tmp[ 21]= arg_2( tmp[ 18]);
if( check_sym( tmp[ 19] , lf_AUX_Remove_Lists_C16_1sym)) {
tmp[ 22]= arg_0( tmp[ 19]);
if( check_sym( tmp[ 20] , lf4sym)) {
tmp[ 23]= arg_0( tmp[ 20]);
t_protect( tmp[ 22]);
if( is_single_element( tmp[ 22])) {
t_protect( tmp[ 22]);
tmp[ 24]= list_head( tmp[ 22]);
t_protect( tmp[ 21]);
tmp[ 25]= ( * ef13)( tmp[ 21]);
t_protect( tmp[ 25]);
tmp[ 26]= ( * ef14)( tmp[ 25]);
t_protect( tmp[ 25]);
t_protect( tmp[ 21]);
tmp[ 27]= ( * ef15)( ( * ef16)( tmp[ 25]) , tmp[ 21]);
t_protect( tmp[ 15]);
tmp[ 28]= ( * ef19)( tmp[ 15]);
t_protect( tmp[ 13]);
t_protect( tmp[ 28]);
t_protect( tmp[ 27]);
tmp[ 29]= lf_AUX_Remove_Lists_C16_2( lf_AUX_Remove_Lists_C16_1( make_list( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf_AUX_Remove_Lists_C16_1( cons( make_list( tmp[ 13]) , make_list( tmp[ 28])))))) , tmp[ 27]);
if( check_sym( tmp[ 29] , ef3sym)) {
tmp[ 30]= arg_0( tmp[ 29]);
tmp[ 31]= arg_1( tmp[ 29]);
tmp[ 32]= arg_2( tmp[ 29]);
if( check_sym( tmp[ 30] , lf_AUX_Remove_Lists_C16_1sym)) {
tmp[ 33]= arg_0( tmp[ 30]);
if( check_sym( tmp[ 31] , lf4sym)) {
tmp[ 34]= arg_0( tmp[ 31]);
t_protect( tmp[ 33]);
if( is_single_element( tmp[ 33])) {
t_protect( tmp[ 33]);
tmp[ 35]= list_head( tmp[ 33]);
if( check_sym( tmp[ 35] , ef4sym)) {
tmp[ 36]= arg_0( tmp[ 35]);
if( check_sym( tmp[ 36] , ef5sym)) {
tmp[ 37]= arg_0( tmp[ 36]);
t_protect( tmp[ 26]);
t_protect( tmp[ 26]);
t_protect( tmp[ 37]);
t_protect( tmp[ 26]);
t_protect( tmp[ 23]);
t_protect( tmp[ 34]);
t_protect( tmp[ 32]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 35]);
return ( * ef3)( lf_AUX_Remove_Lists_C16_1( make_list( ( * ef4)( ( * ef5)( tmp[ 26])))) , lf4( cons( make_list( ( * ef6)( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 102)) , cons( make_list( make_char( 105)) , make_list( make_char( 120)))))))))))))) , lf_AUX_Remove_Lists_C16_1( make_list( ( * ef4)( ( * ef5)( tmp[ 26]))))) , ( * ef4)( ( * ef5)( tmp[ 37])))) , cons( make_list( ( * ef6)( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))))))))) , lf_AUX_Remove_Lists_C16_1( make_list( ( * ef4)( ( * ef5)( tmp[ 26]))))) , ( * ef7)( ( * ef2)( lf3( make_list( make_char( 116))))))) , cons( make_list( ( * ef8)( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))) , lf_AUX_Remove_Lists_C16_1( make_list( ( * ef4)( ( * ef5)( tmp[ 26]))))) , tmp[ 24])) , cons( make_list( tmp[ 23]) , make_list( tmp[ 34])))))) , tmp[ 32]);
}
}
t_unprotect( tmp[ 35]);
}
}
}
}
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 24]);
}
}
}
}
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 17]);
}
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 15]);
}
t_unprotect( tmp[ 14]);
}
t_unprotect( tmp[ 13]);
}
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 8]);
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
}
}
}
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_Remove_Lists_C16_2sym , arg0 , arg1);
}
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_Remove_Lists_C16_1( aterm * arg0) {
PROF( prof_lf_AUX_Remove_Lists_C16_1);
return make_nf1( lf_AUX_Remove_Lists_C16_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

