#include "support.h"
static Symbol lf_AUX_Remove_Lists_C21_2sym;
static ATerm lf_AUX_Remove_Lists_C21_2( ATerm arg1 , ATerm arg2);
static Symbol ef17sym;
static funcptr ef17;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef15sym;
static funcptr ef15;
static Symbol ef14sym;
static funcptr ef14;
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef11sym;
static funcptr ef11;
static Symbol lf_AUX_Remove_Lists_C21_1sym;
static ATerm lf_AUX_Remove_Lists_C21_1( ATerm arg1);
static Symbol ef18sym;
static funcptr ef18;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef16sym;
static funcptr ef16;
void register_AUX_Remove_Lists_C21( ) {
lf_AUX_Remove_Lists_C21_2sym= ATmakeSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-single-term\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Remove_Lists_C21_2sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf_AUX_Remove_Lists_C21_1sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Remove_Lists_C21_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Remove_Lists_C21_1 , lf_AUX_Remove_Lists_C21_1sym);
register_prod( ATparse( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-single-term\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C21_2 , lf_AUX_Remove_Lists_C21_2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
}
void resolve_AUX_Remove_Lists_C21( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"get-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"get-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newlistvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newlistvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"put-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"put-int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"make-new-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"make-new-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef15= lookup_func( ATreadFromString( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( ATreadFromString( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef17= lookup_func( ATreadFromString( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( ATreadFromString( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef18= lookup_func( ATreadFromString( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( ATreadFromString( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-lhs-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
static ATerm constant4= NULL;
static ATerm constant5= NULL;
static ATerm constant6= NULL;
static ATerm constant7= NULL;
void init_AUX_Remove_Lists_C21( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
ATprotect( & constant4);
ATprotect( & constant5);
ATprotect( & constant6);
ATprotect( & constant7);
}
ATerm lf_AUX_Remove_Lists_C21_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[14];
PROF( prof_lf_AUX_Remove_Lists_C21_2);
if( check_sym( arg0 , lf_AUX_Remove_Lists_C21_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
{
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_head( tmp[ 3]) , make_char( 110))) {
tmp[ 4]= list_tail( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 117))) {
tmp[ 5]= list_tail( tmp[ 4]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 108))) {
tmp[ 6]= list_tail( tmp[ 5]);
if( is_single_element( tmp[ 6])) {
if( term_equal( list_head( tmp[ 6]) , make_char( 108))) {
tmp[ 7]= ( * ef8)( arg1);
tmp[ 8]= ( * ef9)( tmp[ 7]);
tmp[ 9]= ( * ef10)( ( * ef11)( tmp[ 7]) , arg1);
return ( * ef3)( lf_AUX_Remove_Lists_C21_1( make_list( ( * ef4)( ( * ef5)( tmp[ 8])))) , lf4( make_list( ( * ef6)( ( * ef7)( ( constant0? constant0: ( constant0= ( * ef2)( lf3( (ATerm) ATmakeList( 14 , char_table[ 110] , char_table[ 111] , char_table[ 116] , char_table[ 45] , char_table[ 101] , char_table[ 109] , char_table[ 112] , char_table[ 116] , char_table[ 121] , char_table[ 45] , char_table[ 108] , char_table[ 105] , char_table[ 115] , char_table[ 116]))))) , lf_AUX_Remove_Lists_C21_1( make_list( ( * ef4)( ( * ef5)( tmp[ 8]))))) , ( constant1? constant1: ( constant1= ( * ef1)( ( * ef2)( lf3( make_list( make_char( 102)))))))))) , tmp[ 9]);
}
}
}
}
}
}
}
}
}
}
}
tmp[ 1]= ( constant2? constant2: ( constant2= ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 108))))))))));
if( ! term_equal( tmp[ 0] , tmp[ 1])) {
tmp[ 2]= ( * ef13)( tmp[ 0]);
if( term_equal( tmp[ 2] , ( constant3? constant3: ( constant3= ( * ef14)( ))))) {
tmp[ 3]= ( * ef15)( tmp[ 0]);
if( term_equal( tmp[ 3] , ( constant4? constant4: ( constant4= ( * ef16)( ))))) {
tmp[ 4]= ( * ef17)( tmp[ 0] , arg1);
if( check_sym( tmp[ 4] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
tmp[ 7]= arg_2( tmp[ 4]);
if( check_sym( tmp[ 5] , lf_AUX_Remove_Lists_C21_1sym)) {
tmp[ 8]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf4sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
if( is_single_element( tmp[ 8])) {
tmp[ 10]= list_head( tmp[ 8]);
tmp[ 11]= ( * ef8)( tmp[ 7]);
tmp[ 12]= ( * ef9)( tmp[ 11]);
tmp[ 13]= ( * ef10)( ( * ef11)( tmp[ 11]) , tmp[ 7]);
return ( * ef3)( lf_AUX_Remove_Lists_C21_1( make_list( ( * ef4)( ( * ef5)( tmp[ 12])))) , lf4( cons( make_list( ( * ef6)( ( * ef7)( ( constant5? constant5: ( constant5= ( * ef2)( lf3( (ATerm) ATmakeList( 17 , char_table[ 105] , char_table[ 115] , char_table[ 45] , char_table[ 115] , char_table[ 105] , char_table[ 110] , char_table[ 103] , char_table[ 108] , char_table[ 101] , char_table[ 45] , char_table[ 101] , char_table[ 108] , char_table[ 101] , char_table[ 109] , char_table[ 101] , char_table[ 110] , char_table[ 116]))))) , lf_AUX_Remove_Lists_C21_1( make_list( ( * ef4)( ( * ef5)( tmp[ 12]))))) , ( constant6? constant6: ( constant6= ( * ef1)( ( * ef2)( lf3( make_list( make_char( 116))))))))) , cons( make_list( ( * ef12)( ( * ef7)( ( constant7? constant7: ( constant7= ( * ef2)( lf3( (ATerm) ATmakeList( 9 , char_table[ 108] , char_table[ 105] , char_table[ 115] , char_table[ 116] , char_table[ 45] , char_table[ 104] , char_table[ 101] , char_table[ 97] , char_table[ 100]))))) , lf_AUX_Remove_Lists_C21_1( make_list( ( * ef4)( ( * ef5)( tmp[ 12]))))) , tmp[ 10])) , make_list( tmp[ 9])))) , tmp[ 13]);
}
}
}
}
}
if( term_equal( tmp[ 3] , ( constant3? constant3: ( constant3= ( * ef14)( ))))) {
tmp[ 4]= ( * ef8)( arg1);
tmp[ 5]= ( * ef9)( tmp[ 4]);
tmp[ 6]= ( * ef10)( ( * ef11)( tmp[ 4]) , arg1);
return ( * ef3)( lf_AUX_Remove_Lists_C21_1( make_list( ( * ef4)( ( * ef5)( tmp[ 5])))) , lf4( cons( make_list( ( * ef6)( ( * ef7)( ( constant5? constant5: ( constant5= ( * ef2)( lf3( (ATerm) ATmakeList( 17 , char_table[ 105] , char_table[ 115] , char_table[ 45] , char_table[ 115] , char_table[ 105] , char_table[ 110] , char_table[ 103] , char_table[ 108] , char_table[ 101] , char_table[ 45] , char_table[ 101] , char_table[ 108] , char_table[ 101] , char_table[ 109] , char_table[ 101] , char_table[ 110] , char_table[ 116]))))) , lf_AUX_Remove_Lists_C21_1( make_list( ( * ef4)( ( * ef5)( tmp[ 5]))))) , ( constant6? constant6: ( constant6= ( * ef1)( ( * ef2)( lf3( make_list( make_char( 116))))))))) , make_list( ( * ef12)( ( * ef7)( ( constant7? constant7: ( constant7= ( * ef2)( lf3( (ATerm) ATmakeList( 9 , char_table[ 108] , char_table[ 105] , char_table[ 115] , char_table[ 116] , char_table[ 45] , char_table[ 104] , char_table[ 101] , char_table[ 97] , char_table[ 100]))))) , lf_AUX_Remove_Lists_C21_1( make_list( ( * ef4)( ( * ef5)( tmp[ 5]))))) , tmp[ 0])))) , tmp[ 6]);
}
}
}
if( term_equal( ( * ef13)( tmp[ 0]) , ( constant4? constant4: ( constant4= ( * ef16)( ))))) {
return ( * ef18)( tmp[ 0] , arg1);
}
}
}
}
}
return make_nf2( lf_AUX_Remove_Lists_C21_2sym , arg0 , arg1);
}
}
ATerm lf_AUX_Remove_Lists_C21_1( ATerm arg0) {
PROF( prof_lf_AUX_Remove_Lists_C21_1);
return make_nf1( lf_AUX_Remove_Lists_C21_1sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

