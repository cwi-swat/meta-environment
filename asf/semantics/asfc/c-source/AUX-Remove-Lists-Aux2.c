#include "support.h"
static asymbol * lf_AUX_Remove_Lists_Aux2_1sym;
static aterm * lf_AUX_Remove_Lists_Aux2_1( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef5sym;
static funcptr ef5;
void register_AUX_Remove_Lists_Aux2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_Aux2_1sym= TmkSymbol( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"get-prefix-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"get-prefix-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_Aux2_1 , lf_AUX_Remove_Lists_Aux2_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_Remove_Lists_Aux2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_Aux2_1( aterm * arg0) {
{
aterm * tmp[12];
PROF( prof_lf_AUX_Remove_Lists_Aux2_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf3sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( m_not_empty_list( atmp0000)) {
tmp[ 0]= m_list_head( atmp0000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 99))) {
tmp[ 1]= m_list_tail( atmp0000);
{
if( m_not_empty_list( tmp[ 1])) {
tmp[ 2]= m_list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 111))) {
tmp[ 3]= m_list_tail( tmp[ 1]);
{
if( m_not_empty_list( tmp[ 3])) {
tmp[ 4]= m_list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 110))) {
tmp[ 5]= m_list_tail( tmp[ 3]);
{
if( m_is_single_element( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 115))) {
if( m_not_empty_list( atmp010)) {
tmp[ 7]= m_list_head( atmp010);
{
tmp[ 8]= m_list_tail( atmp010);
{
if( m_is_single_element( tmp[ 8])) {
tmp[ 9]= m_list_head( tmp[ 8]);
t_protect( tmp[ 9]);
tmp[ 10]= ( * ef3)( tmp[ 9]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , ( * ef4)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
return tmp[ 7];
}
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , ( * ef5)( ))) {
t_protect( tmp[ 9]);
tmp[ 11]= lf_AUX_Remove_Lists_Aux2_1( tmp[ 9]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
return ( * ef1)( ( * ef2)( lf2( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf3( cons( make_list( tmp[ 7]) , make_list( tmp[ 11]))));
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
t_unprotect( tmp[ 8]);
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
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
return make_nf1( lf_AUX_Remove_Lists_Aux2_1sym , arg0);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

