#include "support.h"
static Symbol lf_AUX_MuASF_Basics21_1sym;
static ATerm lf_AUX_MuASF_Basics21_1( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_MuASF_Basics21( ) {
lf_AUX_MuASF_Basics21_1sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"prefix-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics21_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"prefix-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics21_1 , lf_AUX_MuASF_Basics21_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Basics21( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
void init_AUX_MuASF_Basics21( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
}
ATerm lf_AUX_MuASF_Basics21_1( ATerm arg0 , ATerm arg1 , ATerm arg2) {
{
ATerm tmp[4];
PROF( prof_lf_AUX_MuASF_Basics21_1);
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
if( check_sym( arg2 , ef2sym)) {
{
ATerm atmp20= arg_0( arg2);
if( check_sym( atmp20 , lf2sym)) {
{
ATerm atmp200= arg_0( atmp20);
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
return ( * ef1)( lf2( cons( ( constant0? constant0: ( constant0= make_list_char( 34))) , cons( make_list( tmp[ 1]) , cons( make_list( atmp200) , cons( ( constant1? constant1: ( constant1= make_list_char( 95))) , cons( ( constant1? constant1: ( constant1= make_list_char( 95))) , cons( make_list( tmp[ 3]) , ( constant2? constant2: ( constant2= make_list( make_char( 34))))))))))));
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
if( check_sym( arg2 , ef2sym)) {
{
ATerm atmp20= arg_0( arg2);
if( check_sym( atmp20 , lf2sym)) {
{
ATerm atmp200= arg_0( atmp20);
if( not_empty_list( atmp000)) {
if( term_equal( list_head( atmp000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp000);
if( not_empty_list( tmp[ 0])) {
tmp[ 1]= list_prefix( tmp[ 0]);
if( term_equal( list_last( tmp[ 0]) , make_char( 34))) {
return ( * ef1)( lf2( cons( make_list( tmp[ 1]) , cons( make_list( atmp200) , cons( ( constant1? constant1: ( constant1= make_list_char( 95))) , cons( ( constant1? constant1: ( constant1= make_list_char( 95))) , make_list( atmp100)))))));
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
return make_nf3( lf_AUX_MuASF_Basics21_1sym , arg0 , arg1 , arg2);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

