#include  "support.h"
static Symbol lf_AUX_Remove_Lists_Aux10_2sym ;
static ATerm lf_AUX_Remove_Lists_Aux10_2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Remove_Lists_Aux10_1sym ;
static ATerm lf_AUX_Remove_Lists_Aux10_1 ( ATerm arg1 ) ;
void register_AUX_Remove_Lists_Aux10 ( ) {
lf_AUX_Remove_Lists_Aux10_2sym = ATmakeSymbol ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_Aux10_2sym ) ;
lf_AUX_Remove_Lists_Aux10_1sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_Aux10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf_AUX_Remove_Lists_Aux10_1 , lf_AUX_Remove_Lists_Aux10_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) , lf_AUX_Remove_Lists_Aux10_2 , lf_AUX_Remove_Lists_Aux10_2sym ) ;
}
void resolve_AUX_Remove_Lists_Aux10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Remove_Lists_Aux10 ( ) {
}
ATerm lf_AUX_Remove_Lists_Aux10_2 ( ATerm arg0 ) {
{
ATerm tmp [ 6 ] ;
PROF ( prof_lf_AUX_Remove_Lists_Aux10_2 ) ;
if ( check_sym ( arg0 , lf_AUX_Remove_Lists_Aux10_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
return ( * ef1 ) ( lf_AUX_Remove_Lists_Aux10_1 ( make_list ( ( * ef2 ) ( tmp [ 0 ] ) ) ) ) ;
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] ) ;
tmp [ 3 ] = lf_AUX_Remove_Lists_Aux10_2 ( lf_AUX_Remove_Lists_Aux10_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef1sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf_AUX_Remove_Lists_Aux10_1sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
return ( * ef1 ) ( lf_AUX_Remove_Lists_Aux10_1 ( cons ( make_list ( tmp [ 2 ] ) , make_list ( tmp [ 5 ] ) ) ) ) ;
}
}
}
}
}
}
}
return make_nf1 ( lf_AUX_Remove_Lists_Aux10_2sym , arg0 ) ;
}
}
ATerm lf_AUX_Remove_Lists_Aux10_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Remove_Lists_Aux10_1 ) ;
return make_nf1 ( lf_AUX_Remove_Lists_Aux10_1sym , arg0 ) ;
}

