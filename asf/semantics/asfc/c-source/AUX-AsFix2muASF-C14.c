#include "support.h"
static Symbol lf_AUX_AsFix2muASF_C14_2sym;
static ATerm lf_AUX_AsFix2muASF_C14_2( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_AsFix2muASF_C14_1sym;
static ATerm lf_AUX_AsFix2muASF_C14_1( ATerm arg1);
void register_AUX_AsFix2muASF_C14( ) {
lf_AUX_AsFix2muASF_C14_2sym= ATmakeSymbol( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-c-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix2muASF_C14_2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf_AUX_AsFix2muASF_C14_1sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix2muASF_C14_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_AsFix2muASF_C14_1 , lf_AUX_AsFix2muASF_C14_1sym);
register_prod( ATparse( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-c-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASF_C14_2 , lf_AUX_AsFix2muASF_C14_2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_AsFix2muASF_C14( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_AsFix2muASF_C14( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_AsFix2muASF_C14_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[13];
PROF( prof_lf_AUX_AsFix2muASF_C14_2);
if( check_sym( arg0 , lf_AUX_AsFix2muASF_C14_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_AsFix2muASF_C14_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
{
if( ! not_empty_list( atmp10)) {
return tmp[ 0];
}
if( is_single_element( atmp10)) {
tmp[ 1]= list_head( atmp10);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 4] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 3] , lf_AUX_AsFix2muASF_C14_1sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 99))) {
tmp[ 7]= list_tail( tmp[ 5]);
if( not_empty_list( tmp[ 7])) {
if( term_equal( list_head( tmp[ 7]) , make_char( 111))) {
tmp[ 8]= list_tail( tmp[ 7]);
if( not_empty_list( tmp[ 8])) {
if( term_equal( list_head( tmp[ 8]) , make_char( 110))) {
tmp[ 9]= list_tail( tmp[ 8]);
if( is_single_element( tmp[ 9])) {
if( term_equal( list_head( tmp[ 9]) , make_char( 115))) {
if( not_empty_list( tmp[ 6])) {
tmp[ 10]= list_head( tmp[ 6]);
tmp[ 11]= list_tail( tmp[ 6]);
if( is_single_element( tmp[ 11])) {
tmp[ 12]= list_head( tmp[ 11]);
return lf_AUX_AsFix2muASF_C14_2( lf_AUX_AsFix2muASF_C14_1( make_list( tmp[ 10])) , lf_AUX_AsFix2muASF_C14_1( make_list( ( * ef1)( ( constant0? constant0: ( constant0= ( * ef2)( lf3( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf_AUX_AsFix2muASF_C14_1( cons( make_list( tmp[ 12]) , make_list( tmp[ 1])))))));
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
if( ! not_empty_list( atmp00)) {
if( is_single_element( atmp10)) {
tmp[ 0]= list_head( atmp10);
return tmp[ 0];
}
}
}
}
}
}
if( check_sym( arg0 , lf_AUX_AsFix2muASF_C14_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_AsFix2muASF_C14_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
if( is_single_element( atmp10)) {
tmp[ 1]= list_head( atmp10);
return ( * ef1)( ( constant0? constant0: ( constant0= ( * ef2)( lf3( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf_AUX_AsFix2muASF_C14_1( cons( make_list( tmp[ 0]) , make_list( tmp[ 1]))));
}
}
}
}
}
}
return make_nf2( lf_AUX_AsFix2muASF_C14_2sym , arg0 , arg1);
}
}
ATerm lf_AUX_AsFix2muASF_C14_1( ATerm arg0) {
PROF( prof_lf_AUX_AsFix2muASF_C14_1);
return make_nf1( lf_AUX_AsFix2muASF_C14_1sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

