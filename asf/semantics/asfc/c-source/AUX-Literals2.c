#include "support.h"
static Symbol lf_AUX_Literals2_1sym;
static ATerm lf_AUX_Literals2_1( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_Literals2( ) {
lf_AUX_Literals2_1sym= ATmakeSymbol( "prod(id(\"Literals\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Literals2_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"Literals\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))") , lf_AUX_Literals2_1 , lf_AUX_Literals2_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Literals2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_Literals2( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_Literals2_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[4];
PROF( prof_lf_AUX_Literals2_1);
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
if( not_empty_list( atmp000)) {
if( term_equal( list_head( atmp000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp000);
if( not_empty_list( tmp[ 0])) {
tmp[ 1]= list_prefix( tmp[ 0]);
if( term_equal( list_last( tmp[ 0]) , make_char( 34))) {
if( not_empty_list( atmp100)) {
if( term_equal( list_head( atmp100) , make_char( 34))) {
tmp[ 2]= list_tail( atmp100);
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= list_prefix( tmp[ 2]);
if( term_equal( list_last( tmp[ 2]) , make_char( 34))) {
return ( * ef1)( lf2( cons( ( constant0? constant0: ( constant0= make_list_char( 34))) , cons( make_list( tmp[ 1]) , cons( make_list( tmp[ 3]) , ( constant1? constant1: ( constant1= make_list( make_char( 34)))))))));
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
return make_nf2( lf_AUX_Literals2_1sym , arg0 , arg1);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

