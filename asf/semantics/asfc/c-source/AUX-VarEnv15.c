#include "support.h"
static Symbol lf_AUX_VarEnv15_1sym;
static ATerm lf_AUX_VarEnv15_1( ATerm arg1 , ATerm arg2);
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef6sym;
static funcptr ef6;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_VarEnv15( ) {
lf_AUX_VarEnv15_1sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[l(\"ntl-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv15_1sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[l(\"ntl-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv15_1 , lf_AUX_VarEnv15_1sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_VarEnv15( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_VarEnv15( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_VarEnv15_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[12];
PROF( prof_lf_AUX_VarEnv15_1);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
ATerm atmp100= arg_0( atmp10);
{
ATerm atmp11= arg_1( arg1);
{
ATerm atmp12= arg_2( arg1);
{
ATerm atmp13= arg_3( arg1);
if( not_empty_list( atmp100)) {
tmp[ 0]= list_head( atmp100);
{
tmp[ 1]= list_tail( atmp100);
{
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
if( ! term_equal( arg0 , tmp[ 2])) {
tmp[ 4]= lf_AUX_VarEnv15_1( arg0 , ( * ef1)( lf2( make_list( tmp[ 1])) , atmp11 , atmp12 , atmp13));
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 6] , ef1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= arg_1( tmp[ 6]);
tmp[ 9]= arg_2( tmp[ 6]);
tmp[ 10]= arg_3( tmp[ 6]);
if( check_sym( tmp[ 7] , lf2sym)) {
tmp[ 11]= arg_0( tmp[ 7]);
return ( * ef2)( tmp[ 5] , ( * ef1)( lf2( cons( make_list( ( * ef4)( tmp[ 2] , tmp[ 3])) , make_list( tmp[ 11]))) , tmp[ 8] , tmp[ 9] , tmp[ 10]));
}
}
}
}
else {
return ( * ef2)( tmp[ 3] , ( * ef1)( lf2( cons( make_list( ( * ef4)( arg0 , tmp[ 3])) , make_list( tmp[ 1]))) , atmp11 , atmp12 , atmp13));
}
}
}
}
}
else {
if( check_sym( atmp13 , ef6sym)) {
tmp[ 0]= arg_0( atmp13);
if( check_sym( tmp[ 0] , lf3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
return ( * ef2)( ( * ef3)( lf3( cons( ( constant0? constant0: ( constant0= make_list_char( 108))) , cons( ( constant1? constant1: ( constant1= make_list_char( 102))) , make_list( tmp[ 1]))))) , ( * ef1)( lf2( make_list( ( * ef4)( arg0 , ( * ef3)( lf3( cons( ( constant0? constant0: ( constant0= make_list_char( 108))) , cons( ( constant1? constant1: ( constant1= make_list_char( 102))) , make_list( tmp[ 1])))))))) , atmp11 , atmp12 , ( * ef5)( atmp13)));
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
return make_nf2( lf_AUX_VarEnv15_1sym , arg0 , arg1);
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

