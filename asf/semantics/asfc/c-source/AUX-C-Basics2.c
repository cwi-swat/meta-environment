#include "support.h"
static Symbol lf_AUX_C_Basics2_2sym;
static ATerm lf_AUX_C_Basics2_2( ATerm arg1 , ATerm arg2);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf_AUX_C_Basics2_1sym;
static ATerm lf_AUX_C_Basics2_1( ATerm arg1);
void register_AUX_C_Basics2( ) {
lf_AUX_C_Basics2_2sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[l(\"remove-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics2_2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf_AUX_C_Basics2_1sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics2_1sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_C_Basics2_1 , lf_AUX_C_Basics2_1sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[l(\"remove-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics2_2 , lf_AUX_C_Basics2_2sym);
register_prod( ATparse( "listtype(sort(\"SigArg\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_C_Basics2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_C_Basics2( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_C_Basics2_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[8];
PROF( prof_lf_AUX_C_Basics2_2);
if( check_sym( arg1 , lf_AUX_C_Basics2_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp10)) {
tmp[ 0]= list_head( atmp10);
tmp[ 1]= list_tail( atmp10);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
if( term_equal( arg0 , tmp[ 2])) {
return ( * ef1)( lf_AUX_C_Basics2_1( make_list( tmp[ 1])));
}
else {
tmp[ 3]= lf_AUX_C_Basics2_2( arg0 , lf_AUX_C_Basics2_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 3] , ef1sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_C_Basics2_1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
return ( * ef1)( lf_AUX_C_Basics2_1( cons( make_list( ( * ef2)( tmp[ 2])) , make_list( tmp[ 5]))));
}
}
}
}
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
{
if( not_empty_list( tmp[ 4])) {
if( term_equal( arg0 , tmp[ 2])) {
return ( * ef1)( lf_AUX_C_Basics2_1( make_list( tmp[ 1])));
}
else {
tmp[ 5]= lf_AUX_C_Basics2_2( arg0 , lf_AUX_C_Basics2_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 5] , ef1sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf_AUX_C_Basics2_1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
return ( * ef1)( lf_AUX_C_Basics2_1( cons( make_list( ( * ef3)( tmp[ 2] , lf3( make_list( tmp[ 4])))) , make_list( tmp[ 7]))));
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
return ( constant0? constant0: ( constant0= ( * ef1)( lf_AUX_C_Basics2_1( make_list( null( ))))));
}
}
}
return make_nf2( lf_AUX_C_Basics2_2sym , arg0 , arg1);
}
}
ATerm lf_AUX_C_Basics2_1( ATerm arg0) {
PROF( prof_lf_AUX_C_Basics2_1);
return make_nf1( lf_AUX_C_Basics2_1sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

