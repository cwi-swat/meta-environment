#include "support.h"
static Symbol lf_AUX_Integers5_1sym;
static ATerm lf_AUX_Integers5_1( ATerm arg1 , ATerm arg2);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef1sym;
static funcptr ef1;
void register_AUX_Integers5( ) {
lf_AUX_Integers5_1sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Integers5_1sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers5_1 , lf_AUX_Integers5_1sym);
}
void resolve_AUX_Integers5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\">-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\">-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[ql(\"-\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
static ATerm constant0= NULL;
void init_AUX_Integers5( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_Integers5_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[2];
PROF( prof_lf_AUX_Integers5_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
tmp[ 0]= ( * ef3)( atmp00 , atmp10);
if( term_equal( tmp[ 0] , ( constant0? constant0: ( constant0= ( * ef4)( ))))) {
return ( * ef1)( ( * ef2)( atmp00 , atmp10));
}
else {
return ( * ef5)( ( * ef2)( atmp10 , atmp00));
}
}
}
if( check_sym( arg1 , ef5sym)) {
{
ATerm atmp10= arg_0( arg1);
return ( * ef6)( arg0 , ( * ef1)( atmp10));
}
}
}
}
if( check_sym( arg0 , ef5sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
tmp[ 0]= ( * ef6)( ( * ef1)( atmp00) , arg1);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
return ( * ef5)( tmp[ 1]);
}
}
}
if( check_sym( arg1 , ef5sym)) {
{
ATerm atmp10= arg_0( arg1);
return lf_AUX_Integers5_1( ( * ef1)( atmp10) , ( * ef1)( atmp00));
}
}
}
}
return make_nf2( lf_AUX_Integers5_1sym , arg0 , arg1);
}
}

