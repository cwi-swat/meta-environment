#include "support.h"
static Symbol lf_AUX_Integers12_1sym;
static ATerm lf_AUX_Integers12_1( ATerm arg1 , ATerm arg2);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef3sym;
static funcptr ef3;
void register_AUX_Integers12( ) {
lf_AUX_Integers12_1sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Integers12_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[l(\"gt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Integers12_1 , lf_AUX_Integers12_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Integers12( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_Integers12( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_Integers12_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[7];
PROF( prof_lf_AUX_Integers12_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( check_sym( atmp100 , lf2sym)) {
{
ATerm atmp1000= arg_0( atmp100);
if( is_single_element( atmp0000)) {
tmp[ 0]= list_head( atmp0000);
if( is_single_element( atmp1000)) {
tmp[ 1]= list_head( atmp1000);
tmp[ 2]= ( * ef4)( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 0])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 1])))));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , ef2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( is_single_element( tmp[ 5])) {
tmp[ 6]= list_head( tmp[ 5]);
if( ! term_equal( ( * ef2)( lf2( make_list( tmp[ 6]))) , ( * ef2)( lf2( make_list( make_char( 48)))))) {
return ( constant0? constant0: ( constant0= ( * ef3)( )));
}
}
}
}
}
}
}
{
if( not_empty_list( atmp0000)) {
tmp[ 0]= list_prefix( atmp0000);
{
if( not_empty_list( tmp[ 0])) {
tmp[ 1]= list_last( atmp0000);
{
if( not_empty_list( atmp1000)) {
tmp[ 2]= list_prefix( atmp1000);
{
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= list_last( atmp1000);
if( term_equal( lf_AUX_Integers12_1( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 0])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 2]))))) , ( constant0? constant0: ( constant0= ( * ef3)( ))))) {
return ( constant0? constant0: ( constant0= ( * ef3)( )));
}
if( term_equal( tmp[ 0] , tmp[ 2])) {
return lf_AUX_Integers12_1( ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 1])))) , ( * ef1)( ( * ef2)( lf2( make_list( tmp[ 3])))));
}
}
}
}
if( is_single_element( atmp1000)) {
tmp[ 2]= list_head( atmp1000);
return ( constant0? constant0: ( constant0= ( * ef3)( )));
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
}
}
return make_nf2( lf_AUX_Integers12_1sym , arg0 , arg1);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

