#include "support.h"
static asymbol * lf_AUX_Remove_Lists_C17_2sym;
static aterm * lf_AUX_Remove_Lists_C17_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_Remove_Lists_C17_1sym;
static aterm * lf_AUX_Remove_Lists_C17_1( aterm * arg1);
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
void register_AUX_Remove_Lists_C17( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_C17_2sym= TmkSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-rhs-list-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Remove_Lists_C17_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Remove_Lists_C17_1 , lf_AUX_Remove_Lists_C17_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-rhs-list-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C17_2 , lf_AUX_Remove_Lists_C17_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
}
void resolve_AUX_Remove_Lists_C17( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-rhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-rhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-rhs-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-rhs-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_C17_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[15];
PROF( prof_lf_AUX_Remove_Lists_C17_2);
if( check_sym( arg0 , lf_AUX_Remove_Lists_C17_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_protect( tmp[ 0]);
if( ! term_equal( tmp[ 0] , ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 108)))))))))) {
t_protect( tmp[ 0]);
if( term_equal( ( * ef5)( tmp[ 0]) , ( * ef6)( ))) {
t_unprotect( arg0);
return ( * ef4)( tmp[ 0] , arg1);
}
}
t_protect( tmp[ 0]);
if( term_equal( ( * ef5)( tmp[ 0]) , ( * ef8)( ))) {
t_unprotect( arg0);
return ( * ef7)( tmp[ 0] , arg1);
}
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 110))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 117))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 108))) {
tmp[ 6]= m_list_tail( tmp[ 5]);
if( m_is_single_element( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 108))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef3)( lf_AUX_Remove_Lists_C17_1( make_list( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 108)))))))))) , lf4( make_list( null( ))) , arg1);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
{
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
{
tmp[ 1]= m_list_tail( atmp00);
{
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
if( ! term_equal( tmp[ 0] , ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 108)))))))))) {
t_protect( tmp[ 0]);
if( term_equal( ( * ef5)( tmp[ 0]) , ( * ef6)( ))) {
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 2]= ( * ef4)( tmp[ 0] , arg1);
if( check_sym( tmp[ 2] , ef3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_Remove_Lists_C17_1sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 4]);
if( m_is_single_element( tmp[ 6])) {
tmp[ 8]= m_list_head( tmp[ 6]);
t_protect( tmp[ 1]);
t_protect( tmp[ 5]);
tmp[ 9]= lf_AUX_Remove_Lists_C17_2( lf_AUX_Remove_Lists_C17_1( make_list( tmp[ 1])) , tmp[ 5]);
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
tmp[ 12]= arg_2( tmp[ 9]);
if( check_sym( tmp[ 10] , lf_AUX_Remove_Lists_C17_1sym)) {
tmp[ 13]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf4sym)) {
tmp[ 14]= arg_0( tmp[ 11]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
t_protect( tmp[ 7]);
t_protect( tmp[ 14]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 9]);
return ( * ef3)( lf_AUX_Remove_Lists_C17_1( cons( make_list( tmp[ 8]) , make_list( tmp[ 13]))) , lf4( cons( make_list( tmp[ 7]) , make_list( tmp[ 14]))) , tmp[ 12]);
}
}
}
}
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 8]);
}
}
}
}
t_unprotect( tmp[ 2]);
}
}
t_protect( tmp[ 0]);
if( term_equal( ( * ef5)( tmp[ 0]) , ( * ef8)( ))) {
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 2]= ( * ef7)( tmp[ 0] , arg1);
if( check_sym( tmp[ 2] , ef3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_Remove_Lists_C17_1sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 4]);
if( m_is_single_element( tmp[ 6])) {
tmp[ 8]= m_list_head( tmp[ 6]);
t_protect( tmp[ 1]);
t_protect( tmp[ 5]);
tmp[ 9]= lf_AUX_Remove_Lists_C17_2( lf_AUX_Remove_Lists_C17_1( make_list( tmp[ 1])) , tmp[ 5]);
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
tmp[ 12]= arg_2( tmp[ 9]);
if( check_sym( tmp[ 10] , lf_AUX_Remove_Lists_C17_1sym)) {
tmp[ 13]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf4sym)) {
tmp[ 14]= arg_0( tmp[ 11]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
t_protect( tmp[ 7]);
t_protect( tmp[ 14]);
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 9]);
return ( * ef3)( lf_AUX_Remove_Lists_C17_1( cons( make_list( tmp[ 8]) , make_list( tmp[ 13]))) , lf4( cons( make_list( tmp[ 7]) , make_list( tmp[ 14]))) , tmp[ 12]);
}
}
}
}
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 8]);
}
}
}
}
t_unprotect( tmp[ 2]);
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
}
return make_nf2( lf_AUX_Remove_Lists_C17_2sym , arg0 , arg1);
}
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_Remove_Lists_C17_1( aterm * arg0) {
PROF( prof_lf_AUX_Remove_Lists_C17_1);
return make_nf1( lf_AUX_Remove_Lists_C17_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

