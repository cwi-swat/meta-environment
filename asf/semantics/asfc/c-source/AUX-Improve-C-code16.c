#include  "support.h"
static Symbol lf_AUX_Improve_C_code16_2sym ;
static ATerm lf_AUX_Improve_C_code16_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Improve_C_code16_1sym ;
static ATerm lf_AUX_Improve_C_code16_1 ( ATerm arg1 ) ;
void register_AUX_Improve_C_code16 ( ) {
lf_AUX_Improve_C_code16_2sym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"filter-exprs\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"given\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code16_2sym ) ;
lf_AUX_Improve_C_code16_1sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code16_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf_AUX_Improve_C_code16_1 , lf_AUX_Improve_C_code16_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"filter-exprs\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"given\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code16_2 , lf_AUX_Improve_C_code16_2sym ) ;
}
void resolve_AUX_Improve_C_code16 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"filter\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"given\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"filter\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"given\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[sort(\"Argument-expression-list\"),w(\"\"),ql(\"(+)\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[sort(\"Argument-expression-list\"),w(\"\"),ql(\"(+)\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Improve_C_code16 ( ) {
}
ATerm lf_AUX_Improve_C_code16_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 16 ] ;
FUNC_ENTRY ( lf_AUX_Improve_C_code16_2sym , ATmakeAppl ( lf_AUX_Improve_C_code16_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Improve_C_code16_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf_AUX_Improve_C_code16_1sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 0 ] , ( * ef1 ) ( lf_AUX_Improve_C_code16_1 ( make_list ( atmp100 ) ) ) ) ) ;
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] , ( * ef1 ) ( lf_AUX_Improve_C_code16_1 ( make_list ( atmp100 ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef1sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf_AUX_Improve_C_code16_1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef1sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf_AUX_Improve_C_code16_1sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = lf_AUX_Improve_C_code16_2 ( lf_AUX_Improve_C_code16_1 ( make_list ( tmp [ 1 ] ) ) , ( * ef1 ) ( lf_AUX_Improve_C_code16_1 ( make_list ( tmp [ 6 ] ) ) ) ) ;
if ( check_sym ( tmp [ 9 ] , ef3sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , ef1sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 12 ] , lf_AUX_Improve_C_code16_1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 11 ] , ef1sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 11 ] ) ;
if ( check_sym ( tmp [ 14 ] , lf_AUX_Improve_C_code16_1sym ) ) {
tmp [ 15 ] = arg_0 ( tmp [ 14 ] ) ;
FUNC_EXIT ( ( * ef3 ) ( ( * ef1 ) ( lf_AUX_Improve_C_code16_1 ( make_list ( tmp [ 13 ] ) ) ) , ( * ef4 ) ( ( * ef1 ) ( lf_AUX_Improve_C_code16_1 ( make_list ( tmp [ 8 ] ) ) ) , ( * ef1 ) ( lf_AUX_Improve_C_code16_1 ( make_list ( tmp [ 15 ] ) ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_Improve_C_code16_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Improve_C_code16_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Improve_C_code16_1sym , ATmakeAppl ( lf_AUX_Improve_C_code16_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Improve_C_code16_1sym , arg0 ) ) ;
}

