#include  "support.h"
static Symbol lf_AUX_VarEnv24_2sym ;
static ATerm lf_AUX_VarEnv24_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf_AUX_VarEnv24_1sym ;
static ATerm lf_AUX_VarEnv24_1 ( ATerm arg1 ) ;
void register_AUX_VarEnv24 ( ) {
lf_AUX_VarEnv24_2sym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"is-constructor\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv24_2sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_VarEnv24_1sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv24_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_VarEnv24_1 , lf_AUX_VarEnv24_1sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"is-constructor\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv24_2 , lf_AUX_VarEnv24_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_VarEnv24 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_VarEnv24 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_VarEnv24_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 48 ] ;
PROF ( prof_lf_AUX_VarEnv24_2 ) ;
if ( check_sym ( arg1 , lf_AUX_VarEnv24_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( ! not_empty_list ( atmp10 ) ) {
return ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( ) ) ) ;
}
}
}
if ( check_sym ( arg1 , lf_AUX_VarEnv24_1sym ) ) {
tmp [ 0 ] = arg_0 ( arg1 ) ;
{
ATerm atmp100 ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
atmp100 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( atmp100 , ef2sym ) ) {
tmp [ 1 ] = arg_0 ( atmp100 ) ;
tmp [ 2 ] = arg_1 ( atmp100 ) ;
tmp [ 3 ] = arg_2 ( atmp100 ) ;
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = tmp [ 4 ] ;
tmp [ 6 ] = tmp [ 4 ] ;
while ( not_empty_list ( tmp [ 4 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 4 ] ) ;
tmp [ 4 ] = list_tail ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef3sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf4sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 11 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 11 ] , 99 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 12 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 12 ] , 111 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 13 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 13 ] , 110 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 14 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 14 ] , 115 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 15 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 15 ] , 116 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 16 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 16 ] , 114 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 17 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 17 ] , 117 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 18 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 18 ] , 99 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 19 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 19 ] , 116 ) ) {
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 20 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 20 ] , 111 ) ) {
if ( is_single_element ( tmp [ 10 ] ) ) {
tmp [ 21 ] = list_head ( tmp [ 10 ] ) ;
if ( is_char ( tmp [ 21 ] , 114 ) ) {
if ( term_equal ( arg0 , tmp [ 2 ] ) ) {
return ( constant1 ? constant1 : ( constant1 = ( * ef5 ) ( ) ) ) ;
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
tmp [ 6 ] = list_tail ( tmp [ 6 ] ) ;
tmp [ 4 ] = tmp [ 6 ] ;
}
}
}
}
}
tmp [ 0 ] = arg_0 ( arg1 ) ;
{
ATerm atmp100 ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
atmp100 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( atmp100 , ef2sym ) ) {
tmp [ 22 ] = arg_0 ( atmp100 ) ;
tmp [ 23 ] = arg_1 ( atmp100 ) ;
tmp [ 24 ] = arg_2 ( atmp100 ) ;
if ( check_sym ( tmp [ 24 ] , lf3sym ) ) {
tmp [ 25 ] = arg_0 ( tmp [ 24 ] ) ;
tmp [ 26 ] = tmp [ 25 ] ;
tmp [ 27 ] = tmp [ 25 ] ;
while ( not_empty_list ( tmp [ 25 ] ) ) {
tmp [ 28 ] = list_head ( tmp [ 25 ] ) ;
tmp [ 25 ] = list_tail ( tmp [ 25 ] ) ;
if ( check_sym ( tmp [ 28 ] , ef3sym ) ) {
tmp [ 29 ] = arg_0 ( tmp [ 28 ] ) ;
if ( check_sym ( tmp [ 29 ] , ef4sym ) ) {
tmp [ 30 ] = arg_0 ( tmp [ 29 ] ) ;
if ( check_sym ( tmp [ 30 ] , lf4sym ) ) {
tmp [ 31 ] = arg_0 ( tmp [ 30 ] ) ;
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 32 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 32 ] , 99 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 33 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 33 ] , 111 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 34 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 34 ] , 110 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 35 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 35 ] , 115 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 36 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 36 ] , 116 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 37 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 37 ] , 114 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 38 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 38 ] , 117 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 39 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 39 ] , 99 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 40 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 40 ] , 116 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 41 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 41 ] , 111 ) ) {
if ( is_single_element ( tmp [ 31 ] ) ) {
tmp [ 42 ] = list_head ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 42 ] , 114 ) ) {
if ( check_sym ( arg0 , ef4sym ) ) {
tmp [ 43 ] = arg_0 ( arg0 ) ;
if ( check_sym ( tmp [ 43 ] , lf4sym ) ) {
tmp [ 44 ] = arg_0 ( tmp [ 43 ] ) ;
if ( check_sym ( tmp [ 23 ] , ef4sym ) ) {
tmp [ 45 ] = arg_0 ( tmp [ 23 ] ) ;
if ( check_sym ( tmp [ 45 ] , lf4sym ) ) {
tmp [ 46 ] = arg_0 ( tmp [ 45 ] ) ;
if ( not_empty_list ( tmp [ 46 ] ) ) {
tmp [ 47 ] = list_head ( tmp [ 46 ] ) ;
tmp [ 46 ] = list_tail ( tmp [ 46 ] ) ;
if ( is_char ( tmp [ 47 ] , 95 ) ) {
if ( term_equal ( ( * ef4 ) ( lf4 ( tmp [ 44 ] ) ) , ( * ef4 ) ( lf4 ( tmp [ 46 ] ) ) ) ) {
return ( constant1 ? constant1 : ( constant1 = ( * ef5 ) ( ) ) ) ;
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
tmp [ 27 ] = list_tail ( tmp [ 27 ] ) ;
tmp [ 25 ] = tmp [ 27 ] ;
}
}
}
}
}
}
if ( check_sym ( arg1 , lf_AUX_VarEnv24_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
tmp [ 1 ] = list_tail ( atmp10 ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
return lf_AUX_VarEnv24_2 ( arg0 , lf_AUX_VarEnv24_1 ( make_list ( tmp [ 1 ] ) ) ) ;
}
}
}
}
}
return make_nf2 ( lf_AUX_VarEnv24_2sym , arg0 , arg1 ) ;
}
}
ATerm lf_AUX_VarEnv24_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_VarEnv24_1 ) ;
return make_nf1 ( lf_AUX_VarEnv24_1sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}

