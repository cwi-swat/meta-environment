#include "support.h"
static asymbol * lf_AUX_Integers14_1sym;
static aterm * lf_AUX_Integers14_1( aterm * arg1 , aterm * arg2);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Integers14( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers14_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\">-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\">-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)") , lf_AUX_Integers14_1 , lf_AUX_Integers14_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Integers14( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Integers14_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[20];
PROF( prof_lf_AUX_Integers14_1);
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
t_protect( atmp0000);
if( is_single_element( atmp0000)) {
t_protect( atmp0000);
tmp[ 0]= list_head( atmp0000);
t_protect( atmp1000);
if( is_single_element( atmp1000)) {
t_protect( atmp1000);
tmp[ 1]= list_head( atmp1000);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef3)( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 0])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 1])))));
}
t_unprotect( tmp[ 0]);
}
t_protect( atmp0000);
if( not_empty_list( atmp0000)) {
t_protect( atmp0000);
tmp[ 0]= list_prefix( atmp0000);
t_protect( tmp[ 0]);
if( not_empty_list( tmp[ 0])) {
t_protect( atmp0000);
tmp[ 1]= list_last( atmp0000);
t_protect( atmp1000);
if( not_empty_list( atmp1000)) {
t_protect( atmp1000);
tmp[ 2]= list_prefix( atmp1000);
{
t_protect( atmp1000);
tmp[ 3]= list_last( atmp1000);
{
t_protect( tmp[ 1]);
t_protect( tmp[ 3]);
tmp[ 4]= ( * ef3)( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 1])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 3])))));
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , ef2sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 7]);
if( is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
tmp[ 8]= list_head( tmp[ 7]);
t_protect( tmp[ 0]);
t_protect( tmp[ 2]);
tmp[ 9]= lf_AUX_Integers14_1( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 0])))) , ( * ef1)( ( * ef2)( lf2( cons( make_list( make_char( 48)) , make_list( tmp[ 2]))))));
if( check_sym( tmp[ 9] , ef1sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 10] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf2sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
t_protect( tmp[ 12]);
if( not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 9]);
return ( * ef1)( ( * ef2)( lf2( cons( make_list( tmp[ 12]) , make_list( tmp[ 8])))));
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
t_unprotect( tmp[ 4]);
t_protect( tmp[ 3]);
t_protect( tmp[ 1]);
tmp[ 4]= ( * ef3)( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 3])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 1])))));
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , ef2sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 7]);
if( is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
tmp[ 8]= list_head( tmp[ 7]);
t_protect( tmp[ 8]);
tmp[ 9]= ( * ef3)( ( * ef1)( ( * ef2)( lf2( cons( make_list( make_char( 49)) , make_list( make_char( 48)))))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 8])))));
if( check_sym( tmp[ 9] , ef1sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 10] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf2sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
t_protect( tmp[ 12]);
if( is_single_element( tmp[ 12])) {
t_protect( tmp[ 12]);
tmp[ 13]= list_head( tmp[ 12]);
t_protect( tmp[ 2]);
tmp[ 14]= ( * ef4)( ( * ef5)( ( * ef1)( ( * ef2)( lf2( cons( make_list( make_char( 48)) , make_list( tmp[ 2])))))) , ( * ef5)( ( * ef1)( ( * ef2)( lf2( make_list( make_char( 49)))))));
if( check_sym( tmp[ 14] , ef5sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
t_protect( tmp[ 0]);
t_protect( tmp[ 15]);
tmp[ 16]= lf_AUX_Integers14_1( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 0])))) , tmp[ 15]);
if( check_sym( tmp[ 16] , ef1sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
if( check_sym( tmp[ 17] , ef2sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
if( check_sym( tmp[ 18] , lf2sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
t_protect( tmp[ 19]);
if( not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 16]);
return ( * ef1)( ( * ef2)( lf2( cons( make_list( tmp[ 19]) , make_list( tmp[ 13])))));
}
}
}
}
t_unprotect( tmp[ 16]);
}
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 13]);
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
t_unprotect( tmp[ 4]);
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
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
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , lf2sym)) {
{
aterm * atmp1000= arg_0( atmp100);
t_protect( atmp1000);
if( is_single_element( atmp1000)) {
t_protect( atmp1000);
if( term_equal( list_head( atmp1000) , make_char( 48))) {
t_unprotect( arg1);
return arg0;
}
}
}
}
}
}
}
}
return make_nf2( lf_AUX_Integers14_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

