#include  "support.h"
static Symbol lf_AUX_VarEnv16_1sym ;
static ATerm lf_AUX_VarEnv16_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_VarEnv16 ( ) {
lf_AUX_VarEnv16_1sym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv16_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv16_1 , lf_AUX_VarEnv16_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_VarEnv16 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_VarEnv16 ( ) {
}
ATerm lf_AUX_VarEnv16_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 14 ] ;
PROF ( prof_lf_AUX_VarEnv16_1 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef2sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
{
ATerm atmp21 = arg_1 ( arg2 ) ;
if ( check_sym ( atmp21 , ef3sym ) ) {
{
ATerm atmp210 = arg_0 ( atmp21 ) ;
if ( check_sym ( atmp210 , lf4sym ) ) {
{
ATerm atmp2100 = arg_0 ( atmp210 ) ;
{
ATerm atmp22 = arg_2 ( arg2 ) ;
{
ATerm atmp23 = arg_3 ( arg2 ) ;
if ( ! not_empty_list ( atmp200 ) ) {
if ( check_sym ( atmp22 , ef7sym ) ) {
tmp [ 0 ] = arg_0 ( atmp22 ) ;
if ( check_sym ( tmp [ 0 ] , ef8sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , lf4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
return ( * ef4 ) ( ( * ef3 ) ( lf4 ( cons ( make_list ( atmp2100 ) , make_list ( tmp [ 2 ] ) ) ) ) , ( * ef2 ) ( lf3 ( make_list ( ( * ef5 ) ( arg0 , ( * ef3 ) ( lf4 ( cons ( make_list ( atmp2100 ) , make_list ( tmp [ 2 ] ) ) ) ) , lf2 ( make_list ( atmp100 ) ) ) ) ) , ( * ef3 ) ( lf4 ( make_list ( atmp2100 ) ) ) , ( * ef6 ) ( atmp22 ) , atmp23 ) ) ;
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
{
ATerm atmp21 = arg_1 ( arg2 ) ;
{
ATerm atmp22 = arg_2 ( arg2 ) ;
{
ATerm atmp23 = arg_3 ( arg2 ) ;
if ( not_empty_list ( atmp200 ) ) {
tmp [ 0 ] = list_head ( atmp200 ) ;
{
tmp [ 1 ] = list_tail ( atmp200 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 4 ] , lf2sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( ! term_equal ( arg0 , tmp [ 2 ] ) ) {
tmp [ 6 ] = lf_AUX_VarEnv16_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( atmp100 ) ) ) , ( * ef2 ) ( lf3 ( make_list ( tmp [ 1 ] ) ) , atmp21 , atmp22 , atmp23 ) ) ;
if ( check_sym ( tmp [ 6 ] , ef4sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
tmp [ 8 ] = arg_1 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef2sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ;
tmp [ 11 ] = arg_2 ( tmp [ 8 ] ) ;
tmp [ 12 ] = arg_3 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf3sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 9 ] ) ;
return ( * ef4 ) ( tmp [ 7 ] , ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef5 ) ( tmp [ 2 ] , tmp [ 3 ] , lf2 ( make_list ( tmp [ 5 ] ) ) ) ) , make_list ( tmp [ 13 ] ) ) ) , tmp [ 10 ] , tmp [ 11 ] , tmp [ 12 ] ) ) ;
}
}
}
}
else {
return ( * ef4 ) ( tmp [ 3 ] , ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef5 ) ( arg0 , tmp [ 3 ] , lf2 ( make_list ( tmp [ 5 ] ) ) ) ) , make_list ( tmp [ 1 ] ) ) ) , atmp21 , atmp22 , atmp23 ) ) ;
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
return make_nf3 ( lf_AUX_VarEnv16_1sym , arg0 , arg1 , arg2 ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}

