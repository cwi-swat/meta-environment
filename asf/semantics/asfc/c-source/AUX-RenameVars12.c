#include  "asc-support.h"
static Symbol lf_AUX_RenameVars12_3sym ;
static ATerm lf_AUX_RenameVars12_3 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_RenameVars12_1sym ;
static ATerm lf_AUX_RenameVars12_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_RenameVars12_2sym ;
static ATerm lf_AUX_RenameVars12_2 ( ATerm arg1 ) ;
void register_AUX_RenameVars12 ( ) {
lf_AUX_RenameVars12_3sym = ATmakeSymbol ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"are-constructor-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars12_3sym ) ;
lf_AUX_RenameVars12_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars12_1sym ) ;
lf_AUX_RenameVars12_2sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars12_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_RenameVars12_1 , lf_AUX_RenameVars12_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_RenameVars12_2 , lf_AUX_RenameVars12_2sym ) ;
register_prod ( ATparse ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"are-constructor-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_RenameVars12_3 , lf_AUX_RenameVars12_3sym ) ;
}
void resolve_AUX_RenameVars12 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"is-constructor-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"is-constructor-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_RenameVars12 ( ) {
}
ATerm lf_AUX_RenameVars12_3 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_RenameVars12_3sym , ATmakeAppl ( lf_AUX_RenameVars12_3sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , lf_AUX_RenameVars12_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_RenameVars12_2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
FUNC_EXIT ( ( * ef1 ) ( tmp [ 0 ] , lf_AUX_RenameVars12_2 ( make_list ( atmp10 ) ) ) ) ;
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef1 ) ( tmp [ 0 ] , lf_AUX_RenameVars12_2 ( make_list ( atmp10 ) ) ) ;
tmp [ 3 ] = lf_AUX_RenameVars12_3 ( lf_AUX_RenameVars12_1 ( make_list ( tmp [ 1 ] ) ) , lf_AUX_RenameVars12_2 ( make_list ( atmp10 ) ) ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 2 ] , tmp [ 3 ] ) ) ;
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_RenameVars12_3sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_RenameVars12_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_RenameVars12_2sym , ATmakeAppl ( lf_AUX_RenameVars12_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_RenameVars12_2sym , arg0 ) ) ;
}
ATerm lf_AUX_RenameVars12_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_RenameVars12_1sym , ATmakeAppl ( lf_AUX_RenameVars12_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_RenameVars12_1sym , arg0 ) ) ;
}

