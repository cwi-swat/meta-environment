#include  "asc-support.h"
static Symbol lf_AUX_Remove_Lists_Aux9_1sym ;
static ATerm lf_AUX_Remove_Lists_Aux9_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Remove_Lists_Aux9 ( ) {
lf_AUX_Remove_Lists_Aux9_1sym = ATmakeSymbol ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_Aux9_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) , lf_AUX_Remove_Lists_Aux9_1 , lf_AUX_Remove_Lists_Aux9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Remove_Lists_Aux9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"is-trans-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"is-trans-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-terms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-terms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Remove_Lists_Aux9 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Remove_Lists_Aux9_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 5 ] ;
FUNC_ENTRY ( lf_AUX_Remove_Lists_Aux9_1sym , ATmakeAppl ( lf_AUX_Remove_Lists_Aux9_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , lf2sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
if ( not_empty_list ( atmp110 ) ) {
( tmp [ 0 ] = ( * ef3 ) ( atmp10 ) ) ;
if ( term_equal ( tmp [ 0 ] , arg0 ) ) {
( tmp [ 1 ] = ( * ef4 ) ( ( * ef5 ) ( ) , lf2 ( make_list ( atmp110 ) ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf2sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
( tmp [ 4 ] = list_head ( tmp [ 3 ] ) ) ;
FUNC_EXIT ( tmp [ 4 ] ) ;
}
}
}
}
if ( term_equal ( tmp [ 0 ] , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ) ) {
( tmp [ 1 ] = ( * ef4 ) ( arg0 , lf2 ( make_list ( atmp110 ) ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf2sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
FUNC_EXIT ( ( * ef2 ) ( atmp10 , lf2 ( make_list ( tmp [ 3 ] ) ) ) ) ;
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
if ( check_sym ( arg0 , ef5sym ) ) {
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , lf2sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
if ( not_empty_list ( atmp110 ) ) {
( tmp [ 0 ] = ( * ef4 ) ( arg0 , lf2 ( make_list ( atmp110 ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef6sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf2sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
FUNC_EXIT ( ( * ef2 ) ( atmp10 , lf2 ( make_list ( tmp [ 2 ] ) ) ) ) ;
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
FUNC_EXIT ( arg1 ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_Remove_Lists_Aux9_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

