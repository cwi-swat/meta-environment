#include  "asc-support.h"
static Symbol lf_AUX_RenameVars10_3sym ;
static ATerm lf_AUX_RenameVars10_3 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf_AUX_RenameVars10_2sym ;
static ATerm lf_AUX_RenameVars10_2 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_RenameVars10_1sym ;
static ATerm lf_AUX_RenameVars10_1 ( ATerm arg1 ) ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
void register_AUX_RenameVars10 ( ) {
lf_AUX_RenameVars10_3sym = ATmakeSymbol ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"move-cons-terms-in-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TsCE\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars10_3sym ) ;
lf_AUX_RenameVars10_2sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars10_2sym ) ;
lf_AUX_RenameVars10_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars10_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_RenameVars10_1 , lf_AUX_RenameVars10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_RenameVars10_2 , lf_AUX_RenameVars10_2sym ) ;
register_prod ( ATparse ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"move-cons-terms-in-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TsCE\"),w(\"\"),no-attrs)" ) , lf_AUX_RenameVars10_3 , lf_AUX_RenameVars10_3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_RenameVars10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TsCE\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TsCE\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"move-cons-terms-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TCE\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"move-cons-terms-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TCE\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TCE\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TCE\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_RenameVars10 ( ) {
}
ATerm lf_AUX_RenameVars10_3 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 13 ] ;
FUNC_ENTRY ( lf_AUX_RenameVars10_3sym , ATmakeAppl ( lf_AUX_RenameVars10_3sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , lf_AUX_RenameVars10_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_RenameVars10_2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = ( * ef2 ) ( tmp [ 0 ] , lf_AUX_RenameVars10_2 ( make_list ( atmp10 ) ) , arg2 ) ;
if ( check_sym ( tmp [ 1 ] , ef3sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf4sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_RenameVars10_1 ( make_list ( tmp [ 2 ] ) ) , lf4 ( make_list ( tmp [ 5 ] ) ) , tmp [ 4 ] ) ) ;
}
}
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] , lf_AUX_RenameVars10_2 ( make_list ( atmp10 ) ) , arg2 ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 4 ] ) ;
tmp [ 7 ] = lf_AUX_RenameVars10_3 ( lf_AUX_RenameVars10_1 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_RenameVars10_2 ( make_list ( atmp10 ) ) , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef1sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ;
tmp [ 10 ] = arg_2 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , lf_AUX_RenameVars10_1sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf4sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_RenameVars10_1 ( cons ( make_list ( tmp [ 3 ] ) , make_list ( tmp [ 11 ] ) ) ) , lf4 ( cons ( make_list ( tmp [ 6 ] ) , make_list ( tmp [ 12 ] ) ) ) , tmp [ 10 ] ) ) ;
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
FUNC_EXIT ( make_nf3 ( lf_AUX_RenameVars10_3sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf_AUX_RenameVars10_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_RenameVars10_1sym , ATmakeAppl ( lf_AUX_RenameVars10_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_RenameVars10_1sym , arg0 ) ) ;
}
ATerm lf_AUX_RenameVars10_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_RenameVars10_2sym , ATmakeAppl ( lf_AUX_RenameVars10_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_RenameVars10_2sym , arg0 ) ) ;
}

