#include "support.h"
static Symbol lf_AUX_Rules2C_Aux29_2sym;
static ATerm lf_AUX_Rules2C_Aux29_2( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_Rules2C_Aux29_1sym;
static ATerm lf_AUX_Rules2C_Aux29_1( ATerm arg1);
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
void register_AUX_Rules2C_Aux29( ) {
lf_AUX_Rules2C_Aux29_2sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux29_2sym);
lf_AUX_Rules2C_Aux29_1sym= ATmakeSymbol( "listtype(sort(\"IntCon\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux29_1sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
register_prod( ATparse( "listtype(sort(\"IntCon\"),ql(\",\"))") , lf_AUX_Rules2C_Aux29_1 , lf_AUX_Rules2C_Aux29_1sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-atmp2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux29_2 , lf_AUX_Rules2C_Aux29_2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_Rules2C_Aux29( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
void init_AUX_Rules2C_Aux29( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
}
ATerm lf_AUX_Rules2C_Aux29_2( ATerm arg0) {
{
ATerm tmp[8];
PROF( prof_lf_AUX_Rules2C_Aux29_2);
if( check_sym( arg0 , lf_AUX_Rules2C_Aux29_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
return ( * ef3)( lf3( cons( ( constant0? constant0: ( constant0= make_list_char( 97))) , cons( ( constant1? constant1: ( constant1= make_list_char( 116))) , cons( ( constant2? constant2: ( constant2= make_list_char( 109))) , cons( ( constant3? constant3: ( constant3= make_list_char( 112))) , make_list( tmp[ 3])))))));
}
}
}
}
}
if( not_empty_list( atmp00)) {
tmp[ 0]= list_prefix( atmp00);
if( not_empty_list( tmp[ 0])) {
tmp[ 1]= list_last( atmp00);
if( check_sym( tmp[ 1] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
tmp[ 5]= lf_AUX_Rules2C_Aux29_2( lf_AUX_Rules2C_Aux29_1( make_list( tmp[ 0])));
if( check_sym( tmp[ 5] , ef3sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf3sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( not_empty_list( tmp[ 7])) {
return ( * ef3)( lf3( cons( make_list( tmp[ 7]) , make_list( tmp[ 4]))));
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
return make_nf1( lf_AUX_Rules2C_Aux29_2sym , arg0);
}
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf_AUX_Rules2C_Aux29_1( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux29_1);
return make_nf1( lf_AUX_Rules2C_Aux29_1sym , arg0);
}

