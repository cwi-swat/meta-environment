#include "support.h"
static asymbol * lf_AUX_Integers6_1sym;
static aterm * lf_AUX_Integers6_1( aterm * arg1 , aterm * arg2);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef1sym;
static funcptr ef1;
void register_AUX_Integers6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers6_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"*\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"*\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers6_1 , lf_AUX_Integers6_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Integers6( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Integers6_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[7];
PROF( prof_lf_AUX_Integers6_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , lf2sym)) {
{
aterm * atmp00000= arg_0( atmp0000);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , lf2sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( m_not_empty_list( atmp00000)) {
if( m_not_empty_list( atmp10000)) {
t_protect( atmp10000);
tmp[ 0]= list_prefix( atmp10000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( atmp10000);
tmp[ 1]= list_last( atmp10000);
t_protect( atmp00000);
t_protect( tmp[ 0]);
tmp[ 2]= lf_AUX_Integers6_1( ( * ef1)( ( * ef2)( ( * ef3)( lf2( make_list( atmp00000))))) , ( * ef1)( ( * ef2)( ( * ef3)( lf2( make_list( tmp[ 0]))))));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , ef2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf2sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
t_protect( atmp00000);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
return ( * ef4)( ( * ef1)( ( * ef2)( ( * ef3)( lf2( cons( make_list( tmp[ 6]) , make_list( make_char( 48))))))) , lf_AUX_Integers6_1( ( * ef1)( ( * ef2)( ( * ef3)( lf2( make_list( atmp00000))))) , ( * ef1)( ( * ef2)( ( * ef3)( lf2( make_list( tmp[ 1])))))));
}
}
}
}
}
t_unprotect( tmp[ 2]);
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
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , lf2sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( m_is_single_element( atmp10000)) {
tmp[ 0]= m_list_head( atmp10000);
t_protect( tmp[ 0]);
if( term_equal( ( * ef6)( ( * ef2)( ( * ef3)( lf2( make_list( tmp[ 0])))) , ( * ef2)( ( * ef3)( lf2( make_list( make_char( 49)))))) , ( * ef7)( ))) {
t_protect( arg0);
t_unprotect( arg1);
return ( * ef4)( arg0 , lf_AUX_Integers6_1( arg0 , ( * ef5)( ( * ef1)( ( * ef2)( ( * ef3)( lf2( make_list( tmp[ 0]))))) , ( * ef1)( ( * ef2)( ( * ef3)( lf2( make_list( make_char( 49)))))))));
}
t_unprotect( tmp[ 0]);
tmp[ 0]= m_list_head( atmp10000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 48))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef1)( ( * ef2)( ( * ef3)( lf2( make_list( make_char( 48))))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 49))) {
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return arg0;
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
if( check_sym( arg1 , ef8sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( arg0);
t_protect( atmp10);
tmp[ 0]= lf_AUX_Integers6_1( arg0 , ( * ef1)( atmp10));
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef8)( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg0 , ef8sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp00);
t_protect( arg1);
tmp[ 0]= lf_AUX_Integers6_1( ( * ef1)( atmp00) , arg1);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef8)( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
if( check_sym( arg1 , ef8sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp00);
t_protect( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return lf_AUX_Integers6_1( ( * ef1)( atmp00) , ( * ef1)( atmp10));
}
}
}
}
return make_nf2( lf_AUX_Integers6_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

