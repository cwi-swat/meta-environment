#include "support.h"
static asymbol * lf_AUX_Integers12_1sym;
static aterm * lf_AUX_Integers12_1( aterm * arg1 , aterm * arg2);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
void register_AUX_Integers12( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers12_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Integers12_1 , lf_AUX_Integers12_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Integers12( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Integers12_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[7];
PROF( prof_lf_AUX_Integers12_1);
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
if( m_is_single_element( atmp1000)) {
tmp[ 1]= m_list_head( atmp1000);
t_protect( tmp[ 0]);
t_protect( tmp[ 1]);
tmp[ 2]= ( * ef4)( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 0])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 1])))));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , ef2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( m_is_single_element( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_protect( tmp[ 6]);
if( ! term_equal( ( * ef2)( lf2( make_list( tmp[ 6]))) , ( * ef2)( lf2( make_list( make_char( 48)))))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 6]);
return ( * ef3)( );
}
t_unprotect( tmp[ 6]);
}
}
}
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
{
if( m_not_empty_list( atmp0000)) {
t_protect( atmp0000);
tmp[ 0]= list_prefix( atmp0000);
{
if( m_not_empty_list( tmp[ 0])) {
t_protect( atmp0000);
tmp[ 1]= list_last( atmp0000);
{
if( m_not_empty_list( atmp1000)) {
t_protect( atmp1000);
tmp[ 2]= list_prefix( atmp1000);
{
if( m_not_empty_list( tmp[ 2])) {
t_protect( atmp1000);
tmp[ 3]= list_last( atmp1000);
t_protect( tmp[ 0]);
t_protect( tmp[ 2]);
if( term_equal( lf_AUX_Integers12_1( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 0])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 2]))))) , ( * ef3)( ))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef3)( );
}
if( m_term_equal( tmp[ 0] , tmp[ 2])) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
return lf_AUX_Integers12_1( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 1])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 3])))));
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 2]);
}
if( m_is_single_element( atmp1000)) {
tmp[ 2]= m_list_head( atmp1000);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef3)( );
}
}
t_unprotect( tmp[ 1]);
}
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
return make_nf2( lf_AUX_Integers12_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

