#include "support.h"
static Symbol lf_AUX_Rules2C_Aux16_2sym;
static ATerm lf_AUX_Rules2C_Aux16_2( ATerm arg1 , ATerm arg2);
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
static Symbol ef5sym;
static funcptr ef5;
static Symbol lf6sym;
static ATerm lf6( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf_AUX_Rules2C_Aux16_1sym;
static ATerm lf_AUX_Rules2C_Aux16_1( ATerm arg1);
void register_AUX_Rules2C_Aux16( ) {
lf_AUX_Rules2C_Aux16_2sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-conds-on-first-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux16_2sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
lf6sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf6sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf_AUX_Rules2C_Aux16_1sym= ATmakeSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux16_1sym);
register_prod( ATparse( "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux16_1 , lf_AUX_Rules2C_Aux16_1sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-conds-on-first-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux16_2 , lf_AUX_Rules2C_Aux16_2sym);
register_prod( ATparse( "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf5 , lf5sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf6 , lf6sym);
}
void resolve_AUX_Rules2C_Aux16( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_Rules2C_Aux16( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_Rules2C_Aux16_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[35];
PROF( prof_lf_AUX_Rules2C_Aux16_2);
if( check_sym( arg1 , lf_AUX_Rules2C_Aux16_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp10)) {
tmp[ 0]= list_head( atmp10);
tmp[ 1]= list_tail( atmp10);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf4sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
if( not_empty_list( tmp[ 8])) {
tmp[ 9]= list_head( tmp[ 8]);
tmp[ 10]= list_tail( tmp[ 8]);
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 11] , ef4sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
tmp[ 14]= arg_1( tmp[ 11]);
if( check_sym( tmp[ 13] , ef5sym)) {
tmp[ 15]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 15] , lf5sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( check_sym( tmp[ 14] , lf6sym)) {
tmp[ 17]= arg_0( tmp[ 14]);
if( not_empty_list( tmp[ 16])) {
if( term_equal( list_head( tmp[ 16]) , make_char( 116))) {
tmp[ 18]= list_tail( tmp[ 16]);
if( not_empty_list( tmp[ 18])) {
if( term_equal( list_head( tmp[ 18]) , make_char( 101))) {
tmp[ 19]= list_tail( tmp[ 18]);
if( not_empty_list( tmp[ 19])) {
if( term_equal( list_head( tmp[ 19]) , make_char( 114))) {
tmp[ 20]= list_tail( tmp[ 19]);
if( not_empty_list( tmp[ 20])) {
if( term_equal( list_head( tmp[ 20]) , make_char( 109))) {
tmp[ 21]= list_tail( tmp[ 20]);
if( not_empty_list( tmp[ 21])) {
if( term_equal( list_head( tmp[ 21]) , make_char( 45))) {
tmp[ 22]= list_tail( tmp[ 21]);
if( not_empty_list( tmp[ 22])) {
if( term_equal( list_head( tmp[ 22]) , make_char( 101))) {
tmp[ 23]= list_tail( tmp[ 22]);
if( not_empty_list( tmp[ 23])) {
if( term_equal( list_head( tmp[ 23]) , make_char( 113))) {
tmp[ 24]= list_tail( tmp[ 23]);
if( not_empty_list( tmp[ 24])) {
if( term_equal( list_head( tmp[ 24]) , make_char( 117))) {
tmp[ 25]= list_tail( tmp[ 24]);
if( not_empty_list( tmp[ 25])) {
if( term_equal( list_head( tmp[ 25]) , make_char( 97))) {
tmp[ 26]= list_tail( tmp[ 25]);
if( is_single_element( tmp[ 26])) {
if( term_equal( list_head( tmp[ 26]) , make_char( 108))) {
if( not_empty_list( tmp[ 17])) {
tmp[ 27]= list_head( tmp[ 17]);
tmp[ 28]= list_tail( tmp[ 17]);
if( is_single_element( tmp[ 28])) {
tmp[ 29]= list_head( tmp[ 28]);
if( term_equal( arg0 , tmp[ 27])) {
tmp[ 30]= lf_AUX_Rules2C_Aux16_2( arg0 , lf_AUX_Rules2C_Aux16_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 30] , ef1sym)) {
tmp[ 31]= arg_0( tmp[ 30]);
tmp[ 32]= arg_1( tmp[ 30]);
if( check_sym( tmp[ 31] , lf_AUX_Rules2C_Aux16_1sym)) {
tmp[ 33]= arg_0( tmp[ 31]);
if( check_sym( tmp[ 32] , lf_AUX_Rules2C_Aux16_1sym)) {
tmp[ 34]= arg_0( tmp[ 32]);
return ( * ef1)( lf_AUX_Rules2C_Aux16_1( cons( make_list( ( * ef2)( lf3( make_list( tmp[ 7])) , lf4( cons( make_list( ( * ef3)( ( * ef4)( ( constant0? constant0: ( constant0= ( * ef5)( lf5( (ATerm) ATmakeList( 10 , char_table[ 116] , char_table[ 101] , char_table[ 114] , char_table[ 109] , char_table[ 45] , char_table[ 101] , char_table[ 113] , char_table[ 117] , char_table[ 97] , char_table[ 108]))))) , lf6( cons( make_list( arg0) , make_list( tmp[ 29])))) , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 33]))) , lf_AUX_Rules2C_Aux16_1( make_list( tmp[ 34])));
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
else {
return ( constant1? constant1: ( constant1= ( * ef1)( lf_AUX_Rules2C_Aux16_1( make_list( null( ))) , lf_AUX_Rules2C_Aux16_1( make_list( null( ))))));
}
}
}
if( check_sym( arg1 , lf_AUX_Rules2C_Aux16_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp10)) {
tmp[ 0]= list_head( atmp10);
tmp[ 1]= list_tail( atmp10);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf4sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
tmp[ 9]= lf_AUX_Rules2C_Aux16_2( arg0 , lf_AUX_Rules2C_Aux16_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 9] , ef1sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 10] , lf_AUX_Rules2C_Aux16_1sym)) {
tmp[ 12]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf_AUX_Rules2C_Aux16_1sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
return ( * ef1)( lf_AUX_Rules2C_Aux16_1( make_list( tmp[ 12])) , lf_AUX_Rules2C_Aux16_1( cons( make_list( ( * ef2)( lf3( make_list( tmp[ 7])) , lf4( make_list( tmp[ 8])) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 13]))));
}
}
}
}
}
}
}
}
}
return make_nf2( lf_AUX_Rules2C_Aux16_2sym , arg0 , arg1);
}
}
ATerm lf_AUX_Rules2C_Aux16_1( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux16_1);
return make_nf1( lf_AUX_Rules2C_Aux16_1sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf6( ATerm arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

