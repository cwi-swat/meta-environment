#include  "support.h"
static Symbol lf_AUX_Improve_C_code8_1sym ;
static ATerm lf_AUX_Improve_C_code8_1 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Improve_C_code8 ( ) {
lf_AUX_Improve_C_code8_1sym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code8_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Statement\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code8_1 , lf_AUX_Improve_C_code8_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Statement\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Improve_C_code8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-stat\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-stat\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Improve_C_code8 ( ) {
}
ATerm lf_AUX_Improve_C_code8_1 ( ATerm arg0 ) {
{
ATerm tmp [ 7 ] ;
FUNC_ENTRY ( lf_AUX_Improve_C_code8_1sym , ATmakeAppl ( lf_AUX_Improve_C_code8_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( is_single_element ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( ( * ef3 ) ( tmp [ 0 ] ) ) ) ) ) ) ;
}
if ( not_empty_list ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
tmp [ 1 ] = list_tail ( atmp0000 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef3 ) ( tmp [ 0 ] ) ;
tmp [ 3 ] = lf_AUX_Improve_C_code8_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef1sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef2sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( cons ( make_list ( tmp [ 2 ] ) , make_list ( tmp [ 6 ] ) ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf1 ( lf_AUX_Improve_C_code8_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

