#include "support.h"
static Symbol lf_AUX_Trans_Set_Pats3_2sym;
static ATerm lf_AUX_Trans_Set_Pats3_2( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4);
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
static Symbol lf6sym;
static ATerm lf6( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol lf_AUX_Trans_Set_Pats3_1sym;
static ATerm lf_AUX_Trans_Set_Pats3_1( ATerm arg1);
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef10sym;
static funcptr ef10;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
void register_AUX_Trans_Set_Pats3( ) {
lf_AUX_Trans_Set_Pats3_2sym= ATmakeSymbol( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[l(\"transform-set-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"
 , 4 , ATtrue);
ATprotectSymbol( lf_AUX_Trans_Set_Pats3_2sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
lf6sym= ATmakeSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf6sym);
lf_AUX_Trans_Set_Pats3_1sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Trans_Set_Pats3_1sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Trans_Set_Pats3_1 , lf_AUX_Trans_Set_Pats3_1sym);
register_prod( ATparse( "prod(id(\"Trans-Set-Pats\"),w(\"\"),[l(\"transform-set-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Set_Pats3_2 , lf_AUX_Trans_Set_Pats3_2sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf5 , lf5sym);
register_prod( ATparse( "listtype(sort(\"Rule\"),ql(\";\"))") , lf6 , lf6sym);
}
void resolve_AUX_Trans_Set_Pats3( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-new-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-new-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
void init_AUX_Trans_Set_Pats3( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
}
ATerm lf_AUX_Trans_Set_Pats3_2( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3) {
{
ATerm tmp[59];
PROF( prof_lf_AUX_Trans_Set_Pats3_2);
if( check_sym( arg1 , lf_AUX_Trans_Set_Pats3_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( arg2 , ef1sym)) {
{
ATerm atmp20= arg_0( arg2);
{
ATerm atmp21= arg_1( arg2);
if( check_sym( atmp21 , lf3sym)) {
{
ATerm atmp210= arg_0( atmp21);
if( not_empty_list( atmp10)) {
if( is_single_element( atmp210)) {
tmp[ 0]= list_head( atmp210);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( is_single_element( tmp[ 3])) {
tmp[ 4]= list_head( tmp[ 3]);
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 5] , ef2sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 7] , lf4sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( check_sym( tmp[ 6] , lf3sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
if( not_empty_list( tmp[ 8])) {
if( term_equal( list_head( tmp[ 8]) , make_char( 99))) {
tmp[ 10]= list_tail( tmp[ 8]);
if( not_empty_list( tmp[ 10])) {
if( term_equal( list_head( tmp[ 10]) , make_char( 111))) {
tmp[ 11]= list_tail( tmp[ 10]);
if( not_empty_list( tmp[ 11])) {
if( term_equal( list_head( tmp[ 11]) , make_char( 110))) {
tmp[ 12]= list_tail( tmp[ 11]);
if( is_single_element( tmp[ 12])) {
if( term_equal( list_head( tmp[ 12]) , make_char( 115))) {
if( not_empty_list( tmp[ 9])) {
tmp[ 13]= list_head( tmp[ 9]);
tmp[ 14]= list_tail( tmp[ 9]);
if( is_single_element( tmp[ 14])) {
tmp[ 15]= list_head( tmp[ 14]);
if( check_sym( tmp[ 15] , ef1sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
tmp[ 17]= arg_1( tmp[ 15]);
if( check_sym( tmp[ 16] , ef2sym)) {
tmp[ 18]= arg_0( tmp[ 16]);
if( check_sym( tmp[ 18] , lf4sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
if( check_sym( tmp[ 17] , lf3sym)) {
tmp[ 20]= arg_0( tmp[ 17]);
if( not_empty_list( tmp[ 19])) {
if( term_equal( list_head( tmp[ 19]) , make_char( 99))) {
tmp[ 21]= list_tail( tmp[ 19]);
if( not_empty_list( tmp[ 21])) {
if( term_equal( list_head( tmp[ 21]) , make_char( 111))) {
tmp[ 22]= list_tail( tmp[ 21]);
if( not_empty_list( tmp[ 22])) {
if( term_equal( list_head( tmp[ 22]) , make_char( 110))) {
tmp[ 23]= list_tail( tmp[ 22]);
if( is_single_element( tmp[ 23])) {
if( term_equal( list_head( tmp[ 23]) , make_char( 115))) {
if( not_empty_list( tmp[ 20])) {
tmp[ 24]= list_head( tmp[ 20]);
tmp[ 25]= list_tail( tmp[ 20]);
if( is_single_element( tmp[ 25])) {
tmp[ 26]= list_head( tmp[ 25]);
if( check_sym( tmp[ 26] , ef1sym)) {
tmp[ 27]= arg_0( tmp[ 26]);
tmp[ 28]= arg_1( tmp[ 26]);
if( check_sym( tmp[ 27] , ef2sym)) {
tmp[ 29]= arg_0( tmp[ 27]);
if( check_sym( tmp[ 29] , lf4sym)) {
tmp[ 30]= arg_0( tmp[ 29]);
if( check_sym( tmp[ 28] , lf3sym)) {
tmp[ 31]= arg_0( tmp[ 28]);
if( not_empty_list( tmp[ 30])) {
if( term_equal( list_head( tmp[ 30]) , make_char( 99))) {
tmp[ 32]= list_tail( tmp[ 30]);
if( not_empty_list( tmp[ 32])) {
if( term_equal( list_head( tmp[ 32]) , make_char( 111))) {
tmp[ 33]= list_tail( tmp[ 32]);
if( not_empty_list( tmp[ 33])) {
if( term_equal( list_head( tmp[ 33]) , make_char( 110))) {
tmp[ 34]= list_tail( tmp[ 33]);
if( is_single_element( tmp[ 34])) {
if( term_equal( list_head( tmp[ 34]) , make_char( 115))) {
if( not_empty_list( tmp[ 31])) {
tmp[ 35]= list_head( tmp[ 31]);
tmp[ 36]= list_tail( tmp[ 31]);
if( is_single_element( tmp[ 36])) {
tmp[ 37]= list_head( tmp[ 36]);
if( check_sym( tmp[ 37] , ef1sym)) {
tmp[ 38]= arg_0( tmp[ 37]);
tmp[ 39]= arg_1( tmp[ 37]);
if( check_sym( tmp[ 38] , ef2sym)) {
tmp[ 40]= arg_0( tmp[ 38]);
if( check_sym( tmp[ 40] , lf4sym)) {
tmp[ 41]= arg_0( tmp[ 40]);
if( check_sym( tmp[ 39] , lf3sym)) {
tmp[ 42]= arg_0( tmp[ 39]);
if( not_empty_list( tmp[ 41])) {
if( term_equal( list_head( tmp[ 41]) , make_char( 99))) {
tmp[ 43]= list_tail( tmp[ 41]);
if( not_empty_list( tmp[ 43])) {
if( term_equal( list_head( tmp[ 43]) , make_char( 111))) {
tmp[ 44]= list_tail( tmp[ 43]);
if( not_empty_list( tmp[ 44])) {
if( term_equal( list_head( tmp[ 44]) , make_char( 110))) {
tmp[ 45]= list_tail( tmp[ 44]);
if( is_single_element( tmp[ 45])) {
if( term_equal( list_head( tmp[ 45]) , make_char( 115))) {
if( not_empty_list( tmp[ 42])) {
tmp[ 46]= list_head( tmp[ 42]);
tmp[ 47]= list_tail( tmp[ 42]);
if( is_single_element( tmp[ 47])) {
tmp[ 48]= list_head( tmp[ 47]);
tmp[ 49]= ( * ef11)( arg3 , ( constant0? constant0: ( constant0= ( * ef7)( ( * ef8)( ( * ef12)( lf4( cons( make_list( make_char( 78)) , cons( make_list( make_char( 101)) , make_list( make_char( 119)))))))))));
if( check_sym( tmp[ 49] , ef7sym)) {
tmp[ 50]= arg_0( tmp[ 49]);
if( check_sym( tmp[ 50] , ef8sym)) {
tmp[ 51]= arg_0( tmp[ 50]);
tmp[ 52]= ( * ef11)( arg3 , ( constant1? constant1: ( constant1= ( * ef7)( ( * ef8)( ( * ef12)( lf4( cons( make_list( make_char( 76)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116))))))))))));
if( check_sym( tmp[ 52] , ef7sym)) {
tmp[ 53]= arg_0( tmp[ 52]);
if( check_sym( tmp[ 53] , ef8sym)) {
tmp[ 54]= arg_0( tmp[ 53]);
tmp[ 55]= ( * ef11)( ( * ef10)( arg3) , ( constant0? constant0: ( constant0= ( * ef7)( ( * ef8)( ( * ef12)( lf4( cons( make_list( make_char( 78)) , cons( make_list( make_char( 101)) , make_list( make_char( 119)))))))))));
if( check_sym( tmp[ 55] , ef7sym)) {
tmp[ 56]= arg_0( tmp[ 55]);
if( check_sym( tmp[ 56] , ef8sym)) {
tmp[ 57]= arg_0( tmp[ 56]);
tmp[ 58]= ( * ef13)( ( * ef1)( atmp20 , lf3( make_list( ( * ef7)( ( * ef8)( tmp[ 51]))))) , arg0);
return ( * ef3)( lf5( make_list( tmp[ 58])) , lf6( cons( make_list( ( * ef4)( ( * ef5)( lf_AUX_Trans_Set_Pats3_1( cons( make_list( atmp10) , make_list( ( * ef6)( ( * ef1)( atmp20 , lf3( make_list( ( * ef1)( tmp[ 1] , lf3( make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 24]) , make_list( tmp[ 48])))))))))) , ( * ef1)( atmp20 , lf3( make_list( ( * ef1)( tmp[ 1] , lf3( cons( make_list( ( * ef7)( ( * ef8)( tmp[ 51]))) , make_list( ( * ef7)( ( * ef9)( tmp[ 54])))))))))))))) , ( * ef1)( atmp20 , lf3( make_list( ( * ef1)( tmp[ 1] , lf3( make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 13]) , make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 24]) , make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 35]) , make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 46]) , make_list( tmp[ 48])))))))))))))))))))))) , ( * ef1)( atmp20 , lf3( make_list( ( * ef1)( tmp[ 1] , lf3( make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( ( * ef7)( ( * ef8)( tmp[ 51]))) , make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 13]) , make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 35]) , make_list( ( * ef7)( ( * ef9)( tmp[ 54])))))))))))))))))))))) , make_list( ( * ef4)( ( * ef5)( lf_AUX_Trans_Set_Pats3_1( cons( make_list( atmp10) , cons( make_list( ( * ef6)( ( * ef1)( arg0 , lf3( make_list( ( * ef1)( tmp[ 1] , lf3( make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 24]) , make_list( tmp[ 48])))))))))) , ( * ef1)( arg0 , lf3( make_list( ( * ef1)( tmp[ 1] , lf3( cons( make_list( ( * ef7)( ( * ef8)( tmp[ 51]))) , make_list( ( * ef7)( ( * ef9)( tmp[ 54]))))))))))) , make_list( ( * ef6)( ( * ef1)( atmp20 , lf3( make_list( ( * ef1)( tmp[ 1] , lf3( make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 24]) , make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 35]) , make_list( ( * ef7)( ( * ef9)( tmp[ 54])))))))))))))))) , ( * ef7)( ( * ef8)( tmp[ 57])))))))) , ( * ef1)( atmp20 , lf3( make_list( ( * ef1)( tmp[ 1] , lf3( make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 24]) , make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 35]) , make_list( ( * ef1)( ( constant2? constant2: ( constant2= ( * ef2)( lf4( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( tmp[ 46]) , make_list( tmp[ 48])))))))))))))))))) , ( * ef7)( ( * ef8)( tmp[ 57])))))) , ( * ef10)( arg3));
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
return make_nf4( lf_AUX_Trans_Set_Pats3_2sym , arg0 , arg1 , arg2 , arg3);
}
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
ATerm lf_AUX_Trans_Set_Pats3_1( ATerm arg0) {
PROF( prof_lf_AUX_Trans_Set_Pats3_1);
return make_nf1( lf_AUX_Trans_Set_Pats3_1sym , arg0);
}
ATerm lf6( ATerm arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

