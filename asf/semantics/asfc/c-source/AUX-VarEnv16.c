#include "support.h"
static Symbol lf_AUX_VarEnv16_1sym;
static ATerm lf_AUX_VarEnv16_1( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_VarEnv16( ) {
lf_AUX_VarEnv16_1sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-add\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv16_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-add\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv16_1 , lf_AUX_VarEnv16_1sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf2 , lf2sym);
}
void resolve_AUX_VarEnv16( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
}
void init_AUX_VarEnv16( ) {
}
ATerm lf_AUX_VarEnv16_1( ATerm arg0 , ATerm arg1 , ATerm arg2) {
{
ATerm tmp[10];
PROF( prof_lf_AUX_VarEnv16_1);
if( check_sym( arg2 , ef1sym)) {
{
ATerm atmp20= arg_0( arg2);
if( check_sym( atmp20 , lf2sym)) {
{
ATerm atmp200= arg_0( atmp20);
{
ATerm atmp21= arg_1( arg2);
{
ATerm atmp22= arg_2( arg2);
{
ATerm atmp23= arg_3( arg2);
if( not_empty_list( atmp200)) {
tmp[ 0]= list_head( atmp200);
{
tmp[ 1]= list_tail( atmp200);
{
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
if( ! term_equal( arg0 , tmp[ 2])) {
tmp[ 4]= lf_AUX_VarEnv16_1( arg0 , arg1 , ( * ef1)( lf2( make_list( tmp[ 1])) , atmp21 , atmp22 , atmp23));
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
tmp[ 7]= arg_2( tmp[ 4]);
tmp[ 8]= arg_3( tmp[ 4]);
if( check_sym( tmp[ 5] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 5]);
return ( * ef1)( lf2( cons( make_list( ( * ef2)( tmp[ 2] , tmp[ 3])) , make_list( tmp[ 9]))) , tmp[ 6] , tmp[ 7] , tmp[ 8]);
}
}
}
else {
if( term_equal( arg1 , tmp[ 3])) {
return ( * ef1)( lf2( cons( make_list( ( * ef2)( arg0 , arg1)) , make_list( tmp[ 1]))) , atmp21 , atmp22 , atmp23);
}
}
}
}
}
}
else {
return ( * ef1)( lf2( make_list( ( * ef2)( arg0 , arg1))) , atmp21 , atmp22 , atmp23);
}
}
}
}
}
}
}
}
return make_nf3( lf_AUX_VarEnv16_1sym , arg0 , arg1 , arg2);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

