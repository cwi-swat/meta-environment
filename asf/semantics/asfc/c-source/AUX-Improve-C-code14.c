#include  "support.h"
static Symbol lf_AUX_Improve_C_code14_2sym ;
static ATerm lf_AUX_Improve_C_code14_2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf_AUX_Improve_C_code14_1sym ;
static ATerm lf_AUX_Improve_C_code14_1 ( ATerm arg1 ) ;
void register_AUX_Improve_C_code14 ( ) {
lf_AUX_Improve_C_code14_2sym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"used-in-exprs\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code14_2sym ) ;
lf_AUX_Improve_C_code14_1sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code14_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf_AUX_Improve_C_code14_1 , lf_AUX_Improve_C_code14_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"used-in-exprs\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code14_2 , lf_AUX_Improve_C_code14_2sym ) ;
}
void resolve_AUX_Improve_C_code14 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"used-in-expr\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"used-in-expr\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[sort(\"Argument-expression-list\"),w(\"\"),ql(\"(+)\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[sort(\"Argument-expression-list\"),w(\"\"),ql(\"(+)\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Improve_C_code14 ( ) {
}
ATerm lf_AUX_Improve_C_code14_2 ( ATerm arg0 ) {
{
ATerm tmp [ 8 ] ;
FUNC_ENTRY ( lf_AUX_Improve_C_code14_2sym , ATmakeAppl ( lf_AUX_Improve_C_code14_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Improve_C_code14_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
FUNC_EXIT ( ( * ef1 ) ( tmp [ 0 ] ) ) ;
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef1 ) ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_Improve_C_code14_1sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = lf_AUX_Improve_C_code14_2 ( lf_AUX_Improve_C_code14_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 5 ] , ef3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf_AUX_Improve_C_code14_1sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf_AUX_Improve_C_code14_1 ( make_list ( tmp [ 4 ] ) ) ) , ( * ef3 ) ( lf_AUX_Improve_C_code14_1 ( make_list ( tmp [ 7 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Improve_C_code14_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Improve_C_code14_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Improve_C_code14_1sym , ATmakeAppl ( lf_AUX_Improve_C_code14_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Improve_C_code14_1sym , arg0 ) ) ;
}

