#include "support.h"
static Symbol lf_AUX_C_Basics6_1sym;
static ATerm lf_AUX_C_Basics6_1( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef2sym;
static funcptr ef2;
void register_AUX_C_Basics6( ) {
lf_AUX_C_Basics6_1sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics6_1sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))") , lf_AUX_C_Basics6_1 , lf_AUX_C_Basics6_1sym);
}
void resolve_AUX_C_Basics6( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\"),w(\"\"),sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
}
void init_AUX_C_Basics6( ) {
}
ATerm lf_AUX_C_Basics6_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[2];
PROF( prof_lf_AUX_C_Basics6_1);
if( check_sym( arg0 , ef1sym)) {
return arg1;
}
if( check_sym( arg0 , ef2sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , ef2sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef3sym)) {
{
ATerm atmp100= arg_0( atmp10);
return ( * ef2)( ( * ef4)( atmp00 , atmp100));
}
}
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef4sym)) {
{
ATerm atmp100= arg_0( atmp10);
{
ATerm atmp101= arg_1( atmp10);
tmp[ 0]= lf_AUX_C_Basics6_1( arg0 , ( * ef2)( atmp100));
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
return ( * ef2)( ( * ef4)( tmp[ 1] , atmp101));
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
return arg0;
}
return make_nf2( lf_AUX_C_Basics6_1sym , arg0 , arg1);
}
}

