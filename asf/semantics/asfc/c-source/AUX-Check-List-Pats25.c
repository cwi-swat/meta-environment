#include "support.h"
static Symbol lf_AUX_Check_List_Pats25_1sym;
static ATerm lf_AUX_Check_List_Pats25_1( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef6sym;
static funcptr ef6;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef9sym;
static funcptr ef9;
void register_AUX_Check_List_Pats25( ) {
lf_AUX_Check_List_Pats25_1sym= ATmakeSymbol( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Check_List_Pats25_1sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Check_List_Pats25_1 , lf_AUX_Check_List_Pats25_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_Check_List_Pats25( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-no-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-no-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_Check_List_Pats25( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_Check_List_Pats25_1( ATerm arg0) {
{
ATerm tmp[11];
PROF( prof_lf_AUX_Check_List_Pats25_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef6sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf3sym)) {
{
ATerm atmp0000= arg_0( atmp000);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf2sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( not_empty_list( atmp0000)) {
tmp[ 0]= list_head( atmp0000);
if( term_equal( tmp[ 0] , make_char( 99))) {
tmp[ 1]= list_tail( atmp0000);
{
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= list_head( tmp[ 1]);
if( term_equal( tmp[ 2] , make_char( 111))) {
tmp[ 3]= list_tail( tmp[ 1]);
{
if( not_empty_list( tmp[ 3])) {
tmp[ 4]= list_head( tmp[ 3]);
if( term_equal( tmp[ 4] , make_char( 110))) {
tmp[ 5]= list_tail( tmp[ 3]);
{
if( is_single_element( tmp[ 5])) {
tmp[ 6]= list_head( tmp[ 5]);
if( term_equal( tmp[ 6] , make_char( 115))) {
if( not_empty_list( atmp010)) {
tmp[ 7]= list_head( atmp010);
{
tmp[ 8]= list_tail( atmp010);
{
if( is_single_element( tmp[ 8])) {
tmp[ 9]= list_head( tmp[ 8]);
tmp[ 10]= ( * ef8)( tmp[ 7]);
if( term_equal( tmp[ 10] , ( constant0? constant0: ( constant0= ( * ef9)( ))))) {
return ( * ef7)( tmp[ 9]);
}
if( term_equal( tmp[ 10] , ( constant1? constant1: ( constant1= ( * ef5)( ))))) {
return lf_AUX_Check_List_Pats25_1( tmp[ 9]);
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
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf2sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( not_empty_list( atmp010)) {
if( term_equal( ( * ef3)( ( * ef4)( atmp00)) , ( constant1? constant1: ( constant1= ( * ef5)( ))))) {
return ( * ef2)( lf2( make_list( atmp010)));
}
}
}
}
}
}
}
}
return ( constant0? constant0: ( constant0= ( * ef9)( )));
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

