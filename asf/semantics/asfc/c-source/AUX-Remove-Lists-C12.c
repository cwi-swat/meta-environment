#include  "support.h"
static Symbol lf_AUX_Remove_Lists_C12_2sym ;
static ATerm lf_AUX_Remove_Lists_C12_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf_AUX_Remove_Lists_C12_1sym ;
static ATerm lf_AUX_Remove_Lists_C12_1 ( ATerm arg1 ) ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Remove_Lists_C12 ( ) {
lf_AUX_Remove_Lists_C12_2sym = ATmakeSymbol ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_C12_2sym ) ;
lf_AUX_Remove_Lists_C12_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_C12_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_Remove_Lists_C12_1 , lf_AUX_Remove_Lists_C12_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) , lf_AUX_Remove_Lists_C12_2 , lf_AUX_Remove_Lists_C12_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Remove_Lists_C12 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Remove_Lists_C12 ( ) {
}
ATerm lf_AUX_Remove_Lists_C12_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 15 ] ;
PROF ( prof_lf_AUX_Remove_Lists_C12_2 ) ;
if ( check_sym ( arg0 , lf_AUX_Remove_Lists_C12_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
return ( * ef1 ) ( tmp [ 0 ] , arg1 ) ;
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef1 ) ( tmp [ 0 ] , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_Remove_Lists_C12_1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 6 ] ) ;
tmp [ 9 ] = lf_AUX_Remove_Lists_C12_2 ( lf_AUX_Remove_Lists_C12_1 ( make_list ( tmp [ 1 ] ) ) , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef2sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf_AUX_Remove_Lists_C12_1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf3sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 11 ] ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
return ( * ef2 ) ( lf_AUX_Remove_Lists_C12_1 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 13 ] ) ) ) , lf3 ( cons ( make_list ( tmp [ 7 ] ) , make_list ( tmp [ 14 ] ) ) ) , tmp [ 12 ] ) ;
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
return make_nf2 ( lf_AUX_Remove_Lists_C12_2sym , arg0 , arg1 ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}
ATerm lf_AUX_Remove_Lists_C12_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Remove_Lists_C12_1 ) ;
return make_nf1 ( lf_AUX_Remove_Lists_C12_1sym , arg0 ) ;
}

