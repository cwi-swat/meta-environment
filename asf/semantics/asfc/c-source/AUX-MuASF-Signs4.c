#include "support.h"
static Symbol lf_AUX_MuASF_Signs4_1sym;
static ATerm lf_AUX_MuASF_Signs4_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef6sym;
static funcptr ef6;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef7sym;
static funcptr ef7;
void register_AUX_MuASF_Signs4( ) {
lf_AUX_MuASF_Signs4_1sym= ATmakeSymbol( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"is-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Signs4_1sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
register_prod( ATparse( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"is-external-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Signs4_1 , lf_AUX_MuASF_Signs4_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"SigArg\"),ql(\",\"))") , lf4 , lf4sym);
}
void resolve_AUX_MuASF_Signs4( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_MuASF_Signs4( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_MuASF_Signs4_1( ATerm arg0) {
{
ATerm tmp[11];
PROF( prof_lf_AUX_MuASF_Signs4_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef2sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( atmp010 , lf2sym)) {
{
ATerm atmp0100= arg_0( atmp010);
if( is_single_element( atmp0100)) {
tmp[ 0]= list_head( atmp0100);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 120))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 116))) {
tmp[ 6]= list_tail( tmp[ 5]);
if( not_empty_list( tmp[ 6])) {
if( term_equal( list_head( tmp[ 6]) , make_char( 101))) {
tmp[ 7]= list_tail( tmp[ 6]);
if( not_empty_list( tmp[ 7])) {
if( term_equal( list_head( tmp[ 7]) , make_char( 114))) {
tmp[ 8]= list_tail( tmp[ 7]);
if( not_empty_list( tmp[ 8])) {
if( term_equal( list_head( tmp[ 8]) , make_char( 110))) {
tmp[ 9]= list_tail( tmp[ 8]);
if( not_empty_list( tmp[ 9])) {
if( term_equal( list_head( tmp[ 9]) , make_char( 97))) {
tmp[ 10]= list_tail( tmp[ 9]);
if( is_single_element( tmp[ 10])) {
if( term_equal( list_head( tmp[ 10]) , make_char( 108))) {
return ( constant0? constant0: ( constant0= ( * ef5)( )));
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
if( check_sym( arg0 , ef6sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf4sym)) {
{
ATerm atmp010= arg_0( atmp01);
{
ATerm atmp02= arg_2( arg0);
if( check_sym( atmp02 , ef2sym)) {
{
ATerm atmp020= arg_0( atmp02);
if( check_sym( atmp020 , lf2sym)) {
{
ATerm atmp0200= arg_0( atmp020);
if( not_empty_list( atmp010)) {
if( is_single_element( atmp0200)) {
tmp[ 0]= list_head( atmp0200);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 101))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 120))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 116))) {
tmp[ 6]= list_tail( tmp[ 5]);
if( not_empty_list( tmp[ 6])) {
if( term_equal( list_head( tmp[ 6]) , make_char( 101))) {
tmp[ 7]= list_tail( tmp[ 6]);
if( not_empty_list( tmp[ 7])) {
if( term_equal( list_head( tmp[ 7]) , make_char( 114))) {
tmp[ 8]= list_tail( tmp[ 7]);
if( not_empty_list( tmp[ 8])) {
if( term_equal( list_head( tmp[ 8]) , make_char( 110))) {
tmp[ 9]= list_tail( tmp[ 8]);
if( not_empty_list( tmp[ 9])) {
if( term_equal( list_head( tmp[ 9]) , make_char( 97))) {
tmp[ 10]= list_tail( tmp[ 9]);
if( is_single_element( tmp[ 10])) {
if( term_equal( list_head( tmp[ 10]) , make_char( 108))) {
return ( constant0? constant0: ( constant0= ( * ef5)( )));
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
return ( constant1? constant1: ( constant1= ( * ef7)( )));
}
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

