#include "support.h"
static Symbol lf_AUX_AsFix_Basics6_1sym;
static ATerm lf_AUX_AsFix_Basics6_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef6sym;
static funcptr ef6;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
void register_AUX_AsFix_Basics6( ) {
lf_AUX_AsFix_Basics6_1sym= ATmakeSymbol( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-default\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix_Basics6_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-default\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_AsFix_Basics6_1 , lf_AUX_AsFix_Basics6_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_AsFix_Basics6( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_AsFix_Basics6( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_AsFix_Basics6_1( ATerm arg0) {
{
ATerm tmp[11];
PROF( prof_lf_AUX_AsFix_Basics6_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef3sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef4sym)) {
{
ATerm atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef5sym)) {
{
ATerm atmp01000= arg_0( atmp0100);
if( check_sym( atmp01000 , ef6sym)) {
{
ATerm atmp010000= arg_0( atmp01000);
if( check_sym( atmp010000 , lf2sym)) {
{
ATerm atmp0100000= arg_0( atmp010000);
if( not_empty_list( atmp0100000)) {
if( term_equal( list_head( atmp0100000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp0100000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 91))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 100))) {
tmp[ 2]= list_tail( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_head( tmp[ 2]) , make_char( 101))) {
tmp[ 3]= list_tail( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 102))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 97))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 117))) {
tmp[ 6]= list_tail( tmp[ 5]);
if( not_empty_list( tmp[ 6])) {
if( term_equal( list_head( tmp[ 6]) , make_char( 108))) {
tmp[ 7]= list_tail( tmp[ 6]);
if( not_empty_list( tmp[ 7])) {
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
tmp[ 8]= list_tail( tmp[ 7]);
if( not_empty_list( tmp[ 8])) {
if( term_equal( list_head( tmp[ 8]) , make_char( 45))) {
tmp[ 9]= list_tail( tmp[ 8]);
if( not_empty_list( tmp[ 9])) {
tmp[ 10]= list_prefix( tmp[ 9]);
if( term_equal( list_last( tmp[ 9]) , make_char( 34))) {
return ( constant0? constant0: ( constant0= ( * ef7)( )));
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
return ( constant1? constant1: ( constant1= ( * ef8)( )));
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

