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
ATerm tmp [ 43 ] ;
FUNC_ENTRY ( lf_AUX_VarEnv24_2sym , ATmakeAppl ( lf_AUX_VarEnv24_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , lf_AUX_VarEnv24_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
{
tmp [ 1 ] = list_tail ( atmp10 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
tmp [ 27 ] = tmp [ 5 ] ;
tmp [ 28 ] = tmp [ 5 ] ;
while ( not_empty_list ( tmp [ 5 ] ) ) {
tmp [ 29 ] = list_head ( tmp [ 5 ] ) ;
tmp [ 5 ] = list_tail ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 29 ] , ef3sym ) ) {
tmp [ 30 ] = arg_0 ( tmp [ 29 ] ) ;
if ( check_sym ( tmp [ 30 ] , ef4sym ) ) {
tmp [ 31 ] = arg_0 ( tmp [ 30 ] ) ;
if ( check_sym ( tmp [ 31 ] , lf4sym ) ) {
tmp [ 32 ] = arg_0 ( tmp [ 31 ] ) ;
if ( not_empty_list ( tmp [ 32 ] ) ) {
if ( term_equal ( list_head ( tmp [ 32 ] ) , make_char ( 99 ) ) ) {
tmp [ 33 ] = list_tail ( tmp [ 32 ] ) ;
if ( not_empty_list ( tmp [ 33 ] ) ) {
if ( term_equal ( list_head ( tmp [ 33 ] ) , make_char ( 111 ) ) ) {
tmp [ 34 ] = list_tail ( tmp [ 33 ] ) ;
if ( not_empty_list ( tmp [ 34 ] ) ) {
if ( term_equal ( list_head ( tmp [ 34 ] ) , make_char ( 110 ) ) ) {
tmp [ 35 ] = list_tail ( tmp [ 34 ] ) ;
if ( not_empty_list ( tmp [ 35 ] ) ) {
if ( term_equal ( list_head ( tmp [ 35 ] ) , make_char ( 115 ) ) ) {
tmp [ 36 ] = list_tail ( tmp [ 35 ] ) ;
if ( not_empty_list ( tmp [ 36 ] ) ) {
if ( term_equal ( list_head ( tmp [ 36 ] ) , make_char ( 116 ) ) ) {
tmp [ 37 ] = list_tail ( tmp [ 36 ] ) ;
if ( not_empty_list ( tmp [ 37 ] ) ) {
if ( term_equal ( list_head ( tmp [ 37 ] ) , make_char ( 114 ) ) ) {
tmp [ 38 ] = list_tail ( tmp [ 37 ] ) ;
if ( not_empty_list ( tmp [ 38 ] ) ) {
if ( term_equal ( list_head ( tmp [ 38 ] ) , make_char ( 117 ) ) ) {
tmp [ 39 ] = list_tail ( tmp [ 38 ] ) ;
if ( not_empty_list ( tmp [ 39 ] ) ) {
if ( term_equal ( list_head ( tmp [ 39 ] ) , make_char ( 99 ) ) ) {
tmp [ 40 ] = list_tail ( tmp [ 39 ] ) ;
if ( not_empty_list ( tmp [ 40 ] ) ) {
if ( term_equal ( list_head ( tmp [ 40 ] ) , make_char ( 116 ) ) ) {
tmp [ 41 ] = list_tail ( tmp [ 40 ] ) ;
if ( not_empty_list ( tmp [ 41 ] ) ) {
if ( term_equal ( list_head ( tmp [ 41 ] ) , make_char ( 111 ) ) ) {
tmp [ 42 ] = list_tail ( tmp [ 41 ] ) ;
if ( is_single_element ( tmp [ 42 ] ) ) {
if ( term_equal ( list_head ( tmp [ 42 ] ) , make_char ( 114 ) ) ) {
if ( term_equal ( arg0 , tmp [ 3 ] ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef5 ) ( ) ) ;
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
tmp [ 28 ] = list_tail ( tmp [ 28 ] ) ;
tmp [ 5 ] = tmp [ 28 ] ;
}
tmp [ 6 ] = tmp [ 5 ] ;
tmp [ 7 ] = tmp [ 5 ] ;
while ( not_empty_list ( tmp [ 5 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 5 ] ) ;
tmp [ 5 ] = list_tail ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef3sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef4sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf4sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
if ( term_equal ( list_head ( tmp [ 11 ] ) , make_char ( 99 ) ) ) {
tmp [ 12 ] = list_tail ( tmp [ 11 ] ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 111 ) ) ) {
tmp [ 13 ] = list_tail ( tmp [ 12 ] ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
if ( term_equal ( list_head ( tmp [ 13 ] ) , make_char ( 110 ) ) ) {
tmp [ 14 ] = list_tail ( tmp [ 13 ] ) ;
if ( not_empty_list ( tmp [ 14 ] ) ) {
if ( term_equal ( list_head ( tmp [ 14 ] ) , make_char ( 115 ) ) ) {
tmp [ 15 ] = list_tail ( tmp [ 14 ] ) ;
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 116 ) ) ) {
tmp [ 16 ] = list_tail ( tmp [ 15 ] ) ;
if ( not_empty_list ( tmp [ 16 ] ) ) {
if ( term_equal ( list_head ( tmp [ 16 ] ) , make_char ( 114 ) ) ) {
tmp [ 17 ] = list_tail ( tmp [ 16 ] ) ;
if ( not_empty_list ( tmp [ 17 ] ) ) {
if ( term_equal ( list_head ( tmp [ 17 ] ) , make_char ( 117 ) ) ) {
tmp [ 18 ] = list_tail ( tmp [ 17 ] ) ;
if ( not_empty_list ( tmp [ 18 ] ) ) {
if ( term_equal ( list_head ( tmp [ 18 ] ) , make_char ( 99 ) ) ) {
tmp [ 19 ] = list_tail ( tmp [ 18 ] ) ;
if ( not_empty_list ( tmp [ 19 ] ) ) {
if ( term_equal ( list_head ( tmp [ 19 ] ) , make_char ( 116 ) ) ) {
tmp [ 20 ] = list_tail ( tmp [ 19 ] ) ;
if ( not_empty_list ( tmp [ 20 ] ) ) {
if ( term_equal ( list_head ( tmp [ 20 ] ) , make_char ( 111 ) ) ) {
tmp [ 21 ] = list_tail ( tmp [ 20 ] ) ;
if ( is_single_element ( tmp [ 21 ] ) ) {
if ( term_equal ( list_head ( tmp [ 21 ] ) , make_char ( 114 ) ) ) {
if ( check_sym ( arg0 , ef4sym ) ) {
tmp [ 22 ] = arg_0 ( arg0 ) ;
if ( check_sym ( tmp [ 22 ] , lf4sym ) ) {
tmp [ 23 ] = arg_0 ( tmp [ 22 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef4sym ) ) {
tmp [ 24 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 24 ] , lf4sym ) ) {
tmp [ 25 ] = arg_0 ( tmp [ 24 ] ) ;
if ( not_empty_list ( tmp [ 25 ] ) ) {
if ( term_equal ( list_head ( tmp [ 25 ] ) , make_char ( 95 ) ) ) {
tmp [ 26 ] = list_tail ( tmp [ 25 ] ) ;
if ( term_equal ( ( * ef4 ) ( lf4 ( make_list ( tmp [ 23 ] ) ) ) , ( * ef4 ) ( lf4 ( make_list ( tmp [ 26 ] ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef5 ) ( ) ) ;
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
tmp [ 7 ] = list_tail ( tmp [ 7 ] ) ;
tmp [ 5 ] = tmp [ 7 ] ;
}
}
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( ) ) ;
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
FUNC_EXIT ( lf_AUX_VarEnv24_2 ( arg0 , lf_AUX_VarEnv24_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_VarEnv24_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_VarEnv24_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_VarEnv24_1sym , ATmakeAppl ( lf_AUX_VarEnv24_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_VarEnv24_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}

