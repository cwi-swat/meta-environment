#include  "asc-support.h"
static Symbol lf_AUX_Check_List_Pats22_2sym ;
static ATerm lf_AUX_Check_List_Pats22_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Check_List_Pats22_1sym ;
static ATerm lf_AUX_Check_List_Pats22_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Check_List_Pats22 ( ) {
lf_AUX_Check_List_Pats22_2sym = ATmakeSymbol ( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"are-rhs-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Check_List_Pats22_2sym ) ;
lf_AUX_Check_List_Pats22_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Check_List_Pats22_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_Check_List_Pats22_1 , lf_AUX_Check_List_Pats22_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"are-rhs-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Check_List_Pats22_2 , lf_AUX_Check_List_Pats22_2sym ) ;
}
void resolve_AUX_Check_List_Pats22 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-rhs-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-rhs-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Check_List_Pats22 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Check_List_Pats22_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 3 ] ;
FUNC_ENTRY ( lf_AUX_Check_List_Pats22_2sym , ATmakeAppl ( lf_AUX_Check_List_Pats22_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , lf_AUX_Check_List_Pats22_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
{
( tmp [ 1 ] = list_tail ( atmp10 ) ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = ( * ef2 ) ( arg0 , tmp [ 0 ] ) ) ;
if ( term_equal ( tmp [ 2 ] , ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( ) ) ) ) ) {
if ( term_equal ( lf_AUX_Check_List_Pats22_2 ( arg0 , lf_AUX_Check_List_Pats22_1 ( make_list ( tmp [ 1 ] ) ) ) , ( constant1 ? constant1 : ( constant1 = ( * ef3 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ) ) ;
}
}
if ( term_equal ( tmp [ 2 ] , ( constant1 ? constant1 : ( constant1 = ( * ef3 ) ( ) ) ) ) ) {
if ( term_equal ( lf_AUX_Check_List_Pats22_2 ( arg0 , lf_AUX_Check_List_Pats22_1 ( make_list ( tmp [ 1 ] ) ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ) ) ;
}
}
}
}
}
}
if ( is_single_element ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
FUNC_EXIT ( ( * ef2 ) ( arg0 , tmp [ 0 ] ) ) ;
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Check_List_Pats22_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Check_List_Pats22_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Check_List_Pats22_1sym , ATmakeAppl ( lf_AUX_Check_List_Pats22_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Check_List_Pats22_1sym , arg0 ) ) ;
}

