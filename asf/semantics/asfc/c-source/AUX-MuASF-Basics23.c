#include "support.h"
static Symbol lf_AUX_MuASF_Basics23_1sym;
static ATerm lf_AUX_MuASF_Basics23_1( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef3sym;
static funcptr ef3;
void register_AUX_MuASF_Basics23( ) {
lf_AUX_MuASF_Basics23_1sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-internal-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics23_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-internal-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics23_1 , lf_AUX_MuASF_Basics23_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Basics23( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-internal-funid-new\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-internal-funid-new\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_MuASF_Basics23( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_MuASF_Basics23_1( ATerm arg0) {
{
ATerm tmp[8];
PROF( prof_lf_AUX_MuASF_Basics23_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( not_empty_list( atmp000)) {
tmp[ 0]= list_head( atmp000);
if( term_equal( tmp[ 0] , make_char( 34))) {
tmp[ 1]= list_tail( atmp000);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 110))) {
tmp[ 2]= list_tail( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_head( tmp[ 2]) , make_char( 101))) {
tmp[ 3]= list_tail( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 119))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 95))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 95))) {
tmp[ 6]= list_tail( tmp[ 5]);
if( not_empty_list( tmp[ 6])) {
tmp[ 7]= list_prefix( tmp[ 6]);
if( term_equal( list_last( tmp[ 6]) , make_char( 34))) {
return ( * ef2)( ( * ef1)( lf2( make_list( tmp[ 7]))));
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
if( term_equal( tmp[ 0] , make_char( 110))) {
tmp[ 1]= list_tail( atmp000);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 101))) {
tmp[ 2]= list_tail( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_head( tmp[ 2]) , make_char( 119))) {
tmp[ 3]= list_tail( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 95))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 95))) {
tmp[ 5]= list_tail( tmp[ 4]);
return ( * ef2)( ( * ef1)( lf2( make_list( tmp[ 5]))));
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
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
ATerm atmp000= arg_0( atmp00);
return ( constant0? constant0: ( constant0= ( * ef3)( )));
}
}
}
}
return make_nf1( lf_AUX_MuASF_Basics23_1sym , arg0);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

