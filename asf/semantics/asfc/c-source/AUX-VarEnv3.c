#include  "support.h"
static Symbol lf_AUX_VarEnv3_1sym ;
static ATerm lf_AUX_VarEnv3_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_VarEnv3 ( ) {
lf_AUX_VarEnv3_1sym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"vv-enter\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"VV-Pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"vv-enter\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv3_1 , lf_AUX_VarEnv3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"VV-Pair\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_VarEnv3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_VarEnv3 ( ) {
}
ATerm lf_AUX_VarEnv3_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 10 ] ;
FUNC_ENTRY ( lf_AUX_VarEnv3_1sym , ATmakeAppl ( lf_AUX_VarEnv3_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , lf2sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
if ( not_empty_list ( atmp110 ) ) {
tmp [ 0 ] = list_head ( atmp110 ) ;
{
tmp [ 1 ] = list_tail ( atmp110 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
if ( ! term_equal ( arg0 , tmp [ 2 ] ) ) {
tmp [ 4 ] = lf_AUX_VarEnv3_1 ( arg0 , ( * ef1 ) ( atmp10 , lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef2sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 6 ] , ef1sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
tmp [ 8 ] = arg_1 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 8 ] , lf2sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 5 ] , ( * ef1 ) ( tmp [ 7 ] , lf2 ( cons ( make_list ( ( * ef4 ) ( tmp [ 2 ] , tmp [ 3 ] ) ) , make_list ( tmp [ 9 ] ) ) ) ) ) ) ;
}
}
}
}
else {
FUNC_EXIT ( ( * ef2 ) ( tmp [ 3 ] , ( * ef1 ) ( atmp10 , lf2 ( cons ( make_list ( ( * ef4 ) ( arg0 , tmp [ 3 ] ) ) , make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
}
}
}
}
else {
tmp [ 0 ] = ( * ef5 ) ( atmp10 ) ;
if ( check_sym ( tmp [ 0 ] , ef6sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef7sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 2 ] , ( * ef1 ) ( ( * ef3 ) ( atmp10 ) , lf2 ( make_list ( ( * ef4 ) ( arg0 , tmp [ 2 ] ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_VarEnv3_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

