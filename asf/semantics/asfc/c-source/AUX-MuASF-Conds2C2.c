#include "support.h"
static Symbol lf_AUX_MuASF_Conds2C2_3sym;
static ATerm lf_AUX_MuASF_Conds2C2_3( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf7sym;
static ATerm lf7( ATerm arg1);
static Symbol ef10sym;
static funcptr ef10;
static Symbol lf6sym;
static ATerm lf6( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef13sym;
static funcptr ef13;
static Symbol lf_AUX_MuASF_Conds2C2_1sym;
static ATerm lf_AUX_MuASF_Conds2C2_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_MuASF_Conds2C2_2sym;
static ATerm lf_AUX_MuASF_Conds2C2_2( ATerm arg1);
void register_AUX_MuASF_Conds2C2( ) {
lf_AUX_MuASF_Conds2C2_3sym= ATmakeSymbol( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Conds2C2_3sym);
lf7sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf7sym);
lf6sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf6sym);
lf_AUX_MuASF_Conds2C2_1sym= ATmakeSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Conds2C2_1sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
lf_AUX_MuASF_Conds2C2_2sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Conds2C2_2sym);
register_prod( ATparse( "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Conds2C2_1 , lf_AUX_MuASF_Conds2C2_1sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Conds2C2_2 , lf_AUX_MuASF_Conds2C2_2sym);
register_prod( ATparse( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Conds2C2_3 , lf_AUX_MuASF_Conds2C2_3sym);
register_prod( ATparse( "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf7 , lf7sym);
}
void resolve_AUX_MuASF_Conds2C2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef7= lookup_func( ATreadFromString( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"find-common-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"find-common-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"test-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"test-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-boolean-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-boolean-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_MuASF_Conds2C2( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_MuASF_Conds2C2_3( ATerm arg0 , ATerm arg1 , ATerm arg2) {
{
ATerm tmp[69];
PROF( prof_lf_AUX_MuASF_Conds2C2_3);
if( check_sym( arg0 , lf_AUX_MuASF_Conds2C2_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_MuASF_Conds2C2_2sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
{
tmp[ 1]= list_tail( atmp00);
{
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
{
if( check_sym( tmp[ 3] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
{
if( not_empty_list( tmp[ 8])) {
tmp[ 9]= list_head( tmp[ 8]);
{
tmp[ 10]= list_tail( tmp[ 8]);
{
if( check_sym( tmp[ 9] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
{
if( check_sym( tmp[ 11] , ef3sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
tmp[ 14]= arg_1( tmp[ 11]);
if( check_sym( tmp[ 13] , ef4sym)) {
tmp[ 15]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 15] , lf6sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( check_sym( tmp[ 14] , lf7sym)) {
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
tmp[ 30]= ( * ef7)( lf_AUX_MuASF_Conds2C2_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( constant0? constant0: ( constant0= ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))) , lf7( cons( make_list( tmp[ 27]) , make_list( tmp[ 29])))) , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , lf_AUX_MuASF_Conds2C2_2( make_list( atmp10)) , arg2);
if( check_sym( tmp[ 30] , ef8sym)) {
tmp[ 31]= arg_0( tmp[ 30]);
tmp[ 32]= arg_1( tmp[ 30]);
tmp[ 33]= arg_2( tmp[ 30]);
tmp[ 34]= arg_3( tmp[ 30]);
if( check_sym( tmp[ 33] , lf_AUX_MuASF_Conds2C2_1sym)) {
tmp[ 35]= arg_0( tmp[ 33]);
if( not_empty_list( tmp[ 35])) {
tmp[ 36]= list_head( tmp[ 35]);
tmp[ 37]= list_tail( tmp[ 35]);
if( check_sym( tmp[ 36] , ef1sym)) {
tmp[ 38]= arg_0( tmp[ 36]);
tmp[ 39]= arg_1( tmp[ 36]);
tmp[ 40]= arg_2( tmp[ 36]);
tmp[ 41]= arg_3( tmp[ 36]);
tmp[ 42]= arg_4( tmp[ 36]);
if( check_sym( tmp[ 38] , lf4sym)) {
tmp[ 43]= arg_0( tmp[ 38]);
if( check_sym( tmp[ 39] , lf5sym)) {
tmp[ 44]= arg_0( tmp[ 39]);
if( not_empty_list( tmp[ 44])) {
tmp[ 45]= list_head( tmp[ 44]);
tmp[ 46]= list_tail( tmp[ 44]);
if( check_sym( tmp[ 45] , ef2sym)) {
tmp[ 47]= arg_0( tmp[ 45]);
tmp[ 48]= arg_1( tmp[ 45]);
if( check_sym( tmp[ 47] , ef3sym)) {
tmp[ 49]= arg_0( tmp[ 47]);
tmp[ 50]= arg_1( tmp[ 47]);
if( check_sym( tmp[ 49] , ef4sym)) {
tmp[ 51]= arg_0( tmp[ 49]);
if( check_sym( tmp[ 51] , lf6sym)) {
tmp[ 52]= arg_0( tmp[ 51]);
if( check_sym( tmp[ 50] , lf7sym)) {
tmp[ 53]= arg_0( tmp[ 50]);
if( not_empty_list( tmp[ 52])) {
if( term_equal( list_head( tmp[ 52]) , make_char( 116))) {
tmp[ 54]= list_tail( tmp[ 52]);
if( not_empty_list( tmp[ 54])) {
if( term_equal( list_head( tmp[ 54]) , make_char( 101))) {
tmp[ 55]= list_tail( tmp[ 54]);
if( not_empty_list( tmp[ 55])) {
if( term_equal( list_head( tmp[ 55]) , make_char( 114))) {
tmp[ 56]= list_tail( tmp[ 55]);
if( not_empty_list( tmp[ 56])) {
if( term_equal( list_head( tmp[ 56]) , make_char( 109))) {
tmp[ 57]= list_tail( tmp[ 56]);
if( not_empty_list( tmp[ 57])) {
if( term_equal( list_head( tmp[ 57]) , make_char( 45))) {
tmp[ 58]= list_tail( tmp[ 57]);
if( not_empty_list( tmp[ 58])) {
if( term_equal( list_head( tmp[ 58]) , make_char( 101))) {
tmp[ 59]= list_tail( tmp[ 58]);
if( not_empty_list( tmp[ 59])) {
if( term_equal( list_head( tmp[ 59]) , make_char( 113))) {
tmp[ 60]= list_tail( tmp[ 59]);
if( not_empty_list( tmp[ 60])) {
if( term_equal( list_head( tmp[ 60]) , make_char( 117))) {
tmp[ 61]= list_tail( tmp[ 60]);
if( not_empty_list( tmp[ 61])) {
if( term_equal( list_head( tmp[ 61]) , make_char( 97))) {
tmp[ 62]= list_tail( tmp[ 61]);
if( is_single_element( tmp[ 62])) {
if( term_equal( list_head( tmp[ 62]) , make_char( 108))) {
if( not_empty_list( tmp[ 53])) {
tmp[ 63]= list_head( tmp[ 53]);
tmp[ 64]= list_tail( tmp[ 53]);
if( is_single_element( tmp[ 64])) {
tmp[ 65]= list_head( tmp[ 64]);
tmp[ 66]= ( * ef9)( lf_AUX_MuASF_Conds2C2_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 43])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( constant0? constant0: ( constant0= ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))) , lf7( cons( make_list( tmp[ 63]) , make_list( tmp[ 65])))) , tmp[ 48])) , make_list( tmp[ 46]))) , tmp[ 40] , tmp[ 41] , tmp[ 42])) , make_list( tmp[ 37]))) , lf_AUX_MuASF_Conds2C2_2( make_list( atmp10)) , tmp[ 34]);
if( check_sym( tmp[ 66] , ef5sym)) {
tmp[ 67]= arg_0( tmp[ 66]);
tmp[ 68]= arg_1( tmp[ 66]);
return ( * ef5)( ( * ef6)( ( * ef6)( tmp[ 31] , tmp[ 67]) , tmp[ 32]) , tmp[ 68]);
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
tmp[ 13]= ( * ef10)( tmp[ 11]);
if( ! term_equal( tmp[ 13] , ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))) {
if( term_equal( ( * ef11)( tmp[ 12]) , ( constant1? constant1: ( constant1= ( * ef12)( ))))) {
tmp[ 14]= ( * ef9)( lf_AUX_MuASF_Conds2C2_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( tmp[ 11] , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , lf_AUX_MuASF_Conds2C2_2( make_list( atmp10)) , arg2);
if( check_sym( tmp[ 14] , ef5sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
tmp[ 16]= arg_1( tmp[ 14]);
return ( * ef5)( tmp[ 15] , tmp[ 16]);
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
if( check_sym( arg0 , lf_AUX_MuASF_Conds2C2_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_MuASF_Conds2C2_2sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
tmp[ 1]= list_tail( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
if( not_empty_list( tmp[ 8])) {
tmp[ 9]= list_head( tmp[ 8]);
tmp[ 10]= list_tail( tmp[ 8]);
if( check_sym( tmp[ 9] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
return ( * ef13)( lf_AUX_MuASF_Conds2C2_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( tmp[ 11] , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , lf_AUX_MuASF_Conds2C2_2( make_list( atmp10)) , arg2);
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
return make_nf3( lf_AUX_MuASF_Conds2C2_3sym , arg0 , arg1 , arg2);
}
}
ATerm lf_AUX_MuASF_Conds2C2_2( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C2_2);
return make_nf1( lf_AUX_MuASF_Conds2C2_2sym , arg0);
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf_AUX_MuASF_Conds2C2_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C2_1);
return make_nf1( lf_AUX_MuASF_Conds2C2_1sym , arg0);
}
ATerm lf6( ATerm arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
ATerm lf7( ATerm arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}

