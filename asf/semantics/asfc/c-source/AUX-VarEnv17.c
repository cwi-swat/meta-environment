#include "support.h"
static Symbol lf_AUX_VarEnv17_2sym;
static ATerm lf_AUX_VarEnv17_2( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_VarEnv17_1sym;
static ATerm lf_AUX_VarEnv17_1( ATerm arg1);
void register_AUX_VarEnv17( ) {
lf_AUX_VarEnv17_2sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[l(\"np-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv17_2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf_AUX_VarEnv17_1sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv17_1sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_VarEnv17_1 , lf_AUX_VarEnv17_1sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[l(\"np-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv17_2 , lf_AUX_VarEnv17_2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_VarEnv17( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_VarEnv17( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_VarEnv17_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[4];
PROF( prof_lf_AUX_VarEnv17_2);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf3sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( arg1 , lf_AUX_VarEnv17_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( ! not_empty_list( atmp10)) {
return ( * ef1)( lf3( cons( ( constant0? constant0: ( constant0= make_list_char( 34))) , cons( make_list( atmp000) , ( constant1? constant1: ( constant1= make_list( make_char( 34))))))));
}
}
}
}
}
}
}
if( check_sym( arg1 , lf_AUX_VarEnv17_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp10)) {
tmp[ 0]= list_head( atmp10);
{
tmp[ 1]= list_tail( atmp10);
{
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
if( ! term_equal( arg0 , tmp[ 3])) {
return lf_AUX_VarEnv17_2( arg0 , lf_AUX_VarEnv17_1( make_list( tmp[ 1])));
}
else {
return tmp[ 2];
}
}
}
}
}
}
}
return make_nf2( lf_AUX_VarEnv17_2sym , arg0 , arg1);
}
}
ATerm lf_AUX_VarEnv17_1( ATerm arg0) {
PROF( prof_lf_AUX_VarEnv17_1);
return make_nf1( lf_AUX_VarEnv17_1sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

