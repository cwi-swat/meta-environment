#include  "support.h"
static Symbol lf_AUX_VarEnv25_2sym ;
static ATerm lf_AUX_VarEnv25_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf_AUX_VarEnv25_1sym ;
static ATerm lf_AUX_VarEnv25_1 ( ATerm arg1 ) ;
void register_AUX_VarEnv25 ( ) {
lf_AUX_VarEnv25_2sym = ATmakeSymbol ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"get-delaying-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv25_2sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_VarEnv25_1sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_VarEnv25_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_VarEnv25_1 , lf_AUX_VarEnv25_1sym ) ;
register_prod ( ATparse ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"get-delaying-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) , lf_AUX_VarEnv25_2 , lf_AUX_VarEnv25_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_VarEnv25 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_VarEnv25 ( ) {
}
ATerm lf_AUX_VarEnv25_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 46 ] ;
PROF ( prof_lf_AUX_VarEnv25_2 ) ;
if ( check_sym ( arg1 , lf_AUX_VarEnv25_1sym ) ) {
tmp [ 0 ] = arg_0 ( arg1 ) ;
{
ATerm atmp100 ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
atmp100 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( atmp100 , ef1sym ) ) {
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
if ( check_sym ( tmp [ 7 ] , ef2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef3sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf4sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 12 ] = list_head ( tmp [ 11 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 11 ] ) ;
if ( is_char ( tmp [ 12 ] , 100 ) ) {
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 13 ] = list_head ( tmp [ 11 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 11 ] ) ;
if ( is_char ( tmp [ 13 ] , 101 ) ) {
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 14 ] = list_head ( tmp [ 11 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 11 ] ) ;
if ( is_char ( tmp [ 14 ] , 108 ) ) {
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 15 ] = list_head ( tmp [ 11 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 11 ] ) ;
if ( is_char ( tmp [ 15 ] , 97 ) ) {
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 16 ] = list_head ( tmp [ 11 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 11 ] ) ;
if ( is_char ( tmp [ 16 ] , 121 ) ) {
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 17 ] = list_head ( tmp [ 11 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 11 ] ) ;
if ( is_char ( tmp [ 17 ] , 105 ) ) {
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 18 ] = list_head ( tmp [ 11 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 11 ] ) ;
if ( is_char ( tmp [ 18 ] , 110 ) ) {
if ( is_single_element ( tmp [ 11 ] ) ) {
tmp [ 19 ] = list_head ( tmp [ 11 ] ) ;
if ( is_char ( tmp [ 19 ] , 103 ) ) {
if ( check_sym ( tmp [ 9 ] , lf3sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 9 ] ) ;
if ( not_empty_list ( tmp [ 20 ] ) ) {
if ( term_equal ( arg0 , tmp [ 2 ] ) ) {
return ( * ef4 ) ( lf3 ( tmp [ 20 ] ) ) ;
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
if ( check_sym ( atmp100 , ef1sym ) ) {
tmp [ 21 ] = arg_0 ( atmp100 ) ;
tmp [ 22 ] = arg_1 ( atmp100 ) ;
tmp [ 23 ] = arg_2 ( atmp100 ) ;
if ( check_sym ( tmp [ 23 ] , lf3sym ) ) {
tmp [ 24 ] = arg_0 ( tmp [ 23 ] ) ;
tmp [ 25 ] = tmp [ 24 ] ;
tmp [ 26 ] = tmp [ 24 ] ;
while ( not_empty_list ( tmp [ 24 ] ) ) {
tmp [ 27 ] = list_head ( tmp [ 24 ] ) ;
tmp [ 24 ] = list_tail ( tmp [ 24 ] ) ;
if ( check_sym ( tmp [ 27 ] , ef2sym ) ) {
tmp [ 28 ] = arg_0 ( tmp [ 27 ] ) ;
tmp [ 29 ] = arg_1 ( tmp [ 27 ] ) ;
if ( check_sym ( tmp [ 28 ] , ef3sym ) ) {
tmp [ 30 ] = arg_0 ( tmp [ 28 ] ) ;
if ( check_sym ( tmp [ 30 ] , lf4sym ) ) {
tmp [ 31 ] = arg_0 ( tmp [ 30 ] ) ;
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 32 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 32 ] , 100 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 33 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 33 ] , 101 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 34 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 34 ] , 108 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 35 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 35 ] , 97 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 36 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 36 ] , 121 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 37 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 37 ] , 105 ) ) {
if ( not_empty_list ( tmp [ 31 ] ) ) {
tmp [ 38 ] = list_head ( tmp [ 31 ] ) ;
tmp [ 31 ] = list_tail ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 38 ] , 110 ) ) {
if ( is_single_element ( tmp [ 31 ] ) ) {
tmp [ 39 ] = list_head ( tmp [ 31 ] ) ;
if ( is_char ( tmp [ 39 ] , 103 ) ) {
if ( check_sym ( tmp [ 29 ] , lf3sym ) ) {
tmp [ 40 ] = arg_0 ( tmp [ 29 ] ) ;
if ( not_empty_list ( tmp [ 40 ] ) ) {
if ( check_sym ( arg0 , ef3sym ) ) {
tmp [ 41 ] = arg_0 ( arg0 ) ;
if ( check_sym ( tmp [ 41 ] , lf4sym ) ) {
tmp [ 42 ] = arg_0 ( tmp [ 41 ] ) ;
if ( check_sym ( tmp [ 22 ] , ef3sym ) ) {
tmp [ 43 ] = arg_0 ( tmp [ 22 ] ) ;
if ( check_sym ( tmp [ 43 ] , lf4sym ) ) {
tmp [ 44 ] = arg_0 ( tmp [ 43 ] ) ;
if ( not_empty_list ( tmp [ 44 ] ) ) {
tmp [ 45 ] = list_head ( tmp [ 44 ] ) ;
tmp [ 44 ] = list_tail ( tmp [ 44 ] ) ;
if ( is_char ( tmp [ 45 ] , 95 ) ) {
if ( term_equal ( ( * ef3 ) ( lf4 ( tmp [ 42 ] ) ) , ( * ef3 ) ( lf4 ( tmp [ 44 ] ) ) ) ) {
return ( * ef4 ) ( lf3 ( tmp [ 40 ] ) ) ;
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
tmp [ 26 ] = list_tail ( tmp [ 26 ] ) ;
tmp [ 24 ] = tmp [ 26 ] ;
}
}
}
}
}
}
if ( check_sym ( arg1 , lf_AUX_VarEnv25_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
tmp [ 1 ] = list_tail ( atmp10 ) ;
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
return lf_AUX_VarEnv25_2 ( arg0 , lf_AUX_VarEnv25_1 ( make_list ( tmp [ 1 ] ) ) ) ;
}
}
}
}
}
return make_nf2 ( lf_AUX_VarEnv25_2sym , arg0 , arg1 ) ;
}
}
ATerm lf_AUX_VarEnv25_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_VarEnv25_1 ) ;
return make_nf1 ( lf_AUX_VarEnv25_1sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}

