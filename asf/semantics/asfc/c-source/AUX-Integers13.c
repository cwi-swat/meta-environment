#include "support.h"
static asymbol * lf_AUX_Integers13_1sym;
static aterm * lf_AUX_Integers13_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_Integers13( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers13_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)") , lf_AUX_Integers13_1 , lf_AUX_Integers13_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Integers13( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Integers13_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[10];
PROF( prof_lf_AUX_Integers13_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , lf2sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( m_is_single_element( atmp0000)) {
tmp[ 0]= m_list_head( atmp0000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 50))) {
if( m_is_single_element( atmp1000)) {
t_protect( atmp1000);
if( term_equal( list_head( atmp1000) , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
}
}
tmp[ 1]= make_char( 51);
if( m_term_equal( tmp[ 0] , tmp[ 1])) {
if( m_is_single_element( atmp1000)) {
tmp[ 2]= m_list_head( atmp1000);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 50)))));
}
t_unprotect( tmp[ 2]);
}
}
tmp[ 2]= make_char( 52);
if( m_term_equal( tmp[ 0] , tmp[ 2])) {
if( m_is_single_element( atmp1000)) {
tmp[ 3]= m_list_head( atmp1000);
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 51)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 50)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 51))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
t_unprotect( tmp[ 3]);
}
}
tmp[ 3]= make_char( 53);
if( m_term_equal( tmp[ 0] , tmp[ 3])) {
if( m_is_single_element( atmp1000)) {
tmp[ 4]= m_list_head( atmp1000);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 52))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 52)))));
}
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 51)))));
}
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 51))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 50)))));
}
t_unprotect( tmp[ 4]);
}
}
tmp[ 4]= make_char( 54);
if( m_term_equal( tmp[ 0] , tmp[ 4])) {
if( m_is_single_element( atmp1000)) {
tmp[ 5]= m_list_head( atmp1000);
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , make_char( 52))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 50)))));
}
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , make_char( 53))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 53)))));
}
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 52)))));
}
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , make_char( 51))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 51)))));
}
t_unprotect( tmp[ 5]);
}
}
tmp[ 5]= make_char( 55);
if( m_term_equal( tmp[ 0] , tmp[ 5])) {
if( m_is_single_element( atmp1000)) {
tmp[ 6]= m_list_head( atmp1000);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 52))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 51)))));
}
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 53))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 50)))));
}
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 54))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 54)))));
}
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 53)))));
}
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 51))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 52)))));
}
t_unprotect( tmp[ 6]);
}
}
tmp[ 6]= make_char( 56);
if( m_term_equal( tmp[ 0] , tmp[ 6])) {
if( m_is_single_element( atmp1000)) {
tmp[ 7]= m_list_head( atmp1000);
t_protect( tmp[ 7]);
if( term_equal( tmp[ 7] , make_char( 52))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 52)))));
}
t_protect( tmp[ 7]);
if( term_equal( tmp[ 7] , make_char( 53))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 51)))));
}
t_protect( tmp[ 7]);
if( term_equal( tmp[ 7] , make_char( 54))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 50)))));
}
t_protect( tmp[ 7]);
if( term_equal( tmp[ 7] , make_char( 55))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
t_protect( tmp[ 7]);
if( term_equal( tmp[ 7] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 55)))));
}
t_protect( tmp[ 7]);
if( term_equal( tmp[ 7] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 54)))));
}
t_protect( tmp[ 7]);
if( term_equal( tmp[ 7] , make_char( 51))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 53)))));
}
t_unprotect( tmp[ 7]);
}
}
tmp[ 7]= make_char( 57);
if( m_term_equal( tmp[ 0] , tmp[ 7])) {
if( m_is_single_element( atmp1000)) {
tmp[ 8]= m_list_head( atmp1000);
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 52))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 53)))));
}
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 53))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 52)))));
}
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 54))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 51)))));
}
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 55))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 50)))));
}
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 56))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 56)))));
}
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 55)))));
}
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 51))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 54)))));
}
t_unprotect( tmp[ 8]);
}
}
{
tmp[ 8]= m_list_head( atmp0000);
{
if( m_is_single_element( atmp1000)) {
tmp[ 9]= m_list_head( atmp1000);
if( m_term_equal( tmp[ 8] , tmp[ 9])) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 48)))));
}
t_unprotect( tmp[ 9]);
t_protect( atmp1000);
if( term_equal( list_head( atmp1000) , make_char( 48))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 8]))));
}
}
}
t_unprotect( tmp[ 8]);
}
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
{
if( m_not_empty_list( atmp0000)) {
tmp[ 0]= m_list_head( atmp0000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 49))) {
tmp[ 1]= m_list_tail( atmp0000);
{
if( m_is_single_element( tmp[ 1])) {
tmp[ 2]= m_list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 48))) {
if( m_is_single_element( atmp1000)) {
tmp[ 3]= m_list_head( atmp1000);
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 50))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 56)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 51))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 55)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 52))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 54)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 53))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 53)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 54))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 52)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 55))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 51)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 56))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 50)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 57))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))));
}
t_protect( tmp[ 3]);
if( term_equal( tmp[ 3] , make_char( 49))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef1)( ( * ef2)( lf2( make_list( make_char( 57)))));
}
t_unprotect( tmp[ 3]);
}
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
}
}
}
}
return make_nf2( lf_AUX_Integers13_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

