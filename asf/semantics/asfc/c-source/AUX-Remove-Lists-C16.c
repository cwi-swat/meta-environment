#include "support.h"
static asymbol * lf_AUX_Remove_Lists_C16_2sym;
static aterm * lf_AUX_Remove_Lists_C16_2( aterm * arg1 , aterm * arg2);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf_AUX_Remove_Lists_C16_1sym;
static aterm * lf_AUX_Remove_Lists_C16_1( aterm * arg1);
void register_AUX_Remove_Lists_C16( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_C16_2sym= TmkSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-list-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Remove_Lists_C16_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Remove_Lists_C16_1 , lf_AUX_Remove_Lists_C16_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-list-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C16_2 , lf_AUX_Remove_Lists_C16_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_Remove_Lists_C16( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-double-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-double-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-multiple-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-multiple-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-single-term\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-single-term\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_C16_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[17];
PROF( prof_lf_AUX_Remove_Lists_C16_2);
if( check_sym( arg0 , lf_AUX_Remove_Lists_C16_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
{
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
{
if( m_not_empty_list( tmp[ 4])) {
tmp[ 6]= m_list_head( tmp[ 4]);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 99))) {
tmp[ 7]= m_list_tail( tmp[ 4]);
{
if( m_not_empty_list( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 111))) {
tmp[ 9]= m_list_tail( tmp[ 7]);
{
if( m_not_empty_list( tmp[ 9])) {
tmp[ 10]= m_list_head( tmp[ 9]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 110))) {
tmp[ 11]= m_list_tail( tmp[ 9]);
{
if( m_is_single_element( tmp[ 11])) {
tmp[ 12]= m_list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 115))) {
if( m_not_empty_list( tmp[ 5])) {
tmp[ 13]= m_list_head( tmp[ 5]);
{
tmp[ 14]= m_list_tail( tmp[ 5]);
{
if( m_is_single_element( tmp[ 14])) {
tmp[ 15]= m_list_head( tmp[ 14]);
t_protect( tmp[ 15]);
tmp[ 16]= ( * ef4)( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , ( * ef5)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 16]);
return ( * ef3)( lf_AUX_Remove_Lists_C16_1( cons( make_list( tmp[ 13]) , make_list( tmp[ 15]))) , arg1);
}
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , ( * ef7)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 16]);
return ( * ef6)( lf_AUX_Remove_Lists_C16_1( make_list( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf_AUX_Remove_Lists_C16_1( cons( make_list( tmp[ 13]) , make_list( tmp[ 15])))))) , arg1);
}
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 15]);
}
}
t_unprotect( tmp[ 14]);
}
t_unprotect( tmp[ 13]);
}
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 8]);
}
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
}
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg0 , lf_AUX_Remove_Lists_C16_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_unprotect( arg0);
return ( * ef8)( lf_AUX_Remove_Lists_C16_1( make_list( tmp[ 0])) , arg1);
}
}
}
return make_nf2( lf_AUX_Remove_Lists_C16_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Remove_Lists_C16_1( aterm * arg0) {
PROF( prof_lf_AUX_Remove_Lists_C16_1);
return make_nf1( lf_AUX_Remove_Lists_C16_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

