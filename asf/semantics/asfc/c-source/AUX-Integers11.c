#include "support.h"
static Symbol lf_AUX_Integers11_1sym;
static ATerm lf_AUX_Integers11_1( ATerm arg1 , ATerm arg2);
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
void register_AUX_Integers11( ) {
lf_AUX_Integers11_1sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NatCon\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NatCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Integers11_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NatCon\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NatCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Integers11_1 , lf_AUX_Integers11_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Integers11( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NatCon\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NatCon\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_Integers11( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_Integers11_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[6];
PROF( prof_lf_AUX_Integers11_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( is_single_element( atmp000)) {
tmp[ 0]= list_head( atmp000);
if( is_single_element( atmp100)) {
tmp[ 1]= list_head( atmp100);
tmp[ 2]= ( * ef3)( ( * ef1)( lf2( make_list( tmp[ 0]))) , ( * ef1)( lf2( make_list( tmp[ 1]))));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( is_single_element( tmp[ 4])) {
tmp[ 5]= list_head( tmp[ 4]);
if( ! term_equal( ( * ef1)( lf2( make_list( tmp[ 5]))) , ( * ef1)( lf2( make_list( make_char( 48)))))) {
return ( constant0? constant0: ( constant0= ( * ef2)( )));
}
}
}
}
}
}
{
if( not_empty_list( atmp000)) {
tmp[ 0]= list_prefix( atmp000);
{
if( not_empty_list( tmp[ 0])) {
tmp[ 1]= list_last( atmp000);
{
if( not_empty_list( atmp100)) {
tmp[ 2]= list_prefix( atmp100);
{
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= list_last( atmp100);
if( term_equal( lf_AUX_Integers11_1( ( * ef1)( lf2( make_list( tmp[ 0]))) , ( * ef1)( lf2( make_list( tmp[ 2])))) , ( constant0? constant0: ( constant0= ( * ef2)( ))))) {
return ( constant0? constant0: ( constant0= ( * ef2)( )));
}
if( term_equal( tmp[ 0] , tmp[ 2])) {
return lf_AUX_Integers11_1( ( * ef1)( lf2( make_list( tmp[ 1]))) , ( * ef1)( lf2( make_list( tmp[ 3]))));
}
}
}
}
if( is_single_element( atmp100)) {
tmp[ 2]= list_head( atmp100);
return ( constant0? constant0: ( constant0= ( * ef2)( )));
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
return make_nf2( lf_AUX_Integers11_1sym , arg0 , arg1);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

