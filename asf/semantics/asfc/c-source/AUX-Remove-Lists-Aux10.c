#include  "asc-support.h"
static Symbol lf_AUX_Remove_Lists_Aux10_2sym ;
static ATerm lf_AUX_Remove_Lists_Aux10_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Remove_Lists_Aux10_1sym ;
static ATerm lf_AUX_Remove_Lists_Aux10_1 ( ATerm arg1 ) ;
void register_AUX_Remove_Lists_Aux10 ( ) {
lf_AUX_Remove_Lists_Aux10_2sym = ATmakeSymbol ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-terms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_Aux10_2sym ) ;
lf_AUX_Remove_Lists_Aux10_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_Aux10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_Remove_Lists_Aux10_1 , lf_AUX_Remove_Lists_Aux10_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-terms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) , lf_AUX_Remove_Lists_Aux10_2 , lf_AUX_Remove_Lists_Aux10_2sym ) ;
}
void resolve_AUX_Remove_Lists_Aux10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Remove_Lists_Aux10 ( ) {
}
ATerm lf_AUX_Remove_Lists_Aux10_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Remove_Lists_Aux10_2sym , ATmakeAppl ( lf_AUX_Remove_Lists_Aux10_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , lf_AUX_Remove_Lists_Aux10_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( is_single_element ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Remove_Lists_Aux10_1 ( make_list ( ( * ef2 ) ( arg0 , tmp [ 0 ] ) ) ) ) ) ;
}
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
( tmp [ 1 ] = list_tail ( atmp10 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = ( * ef2 ) ( arg0 , tmp [ 0 ] ) ) ;
( tmp [ 3 ] = lf_AUX_Remove_Lists_Aux10_2 ( arg0 , lf_AUX_Remove_Lists_Aux10_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef1sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , lf_AUX_Remove_Lists_Aux10_1sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Remove_Lists_Aux10_1 ( cons ( make_list ( tmp [ 2 ] ) , make_list ( tmp [ 5 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Remove_Lists_Aux10_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Remove_Lists_Aux10_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Remove_Lists_Aux10_1sym , ATmakeAppl ( lf_AUX_Remove_Lists_Aux10_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Remove_Lists_Aux10_1sym , arg0 ) ) ;
}

