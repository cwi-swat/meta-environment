#include  "asc-support.h"
static Symbol lf_AUX_Locate_Constants3_1sym ;
static ATerm lf_AUX_Locate_Constants3_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Locate_Constants3 ( ) {
lf_AUX_Locate_Constants3_1sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decllist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Declaration\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decllist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants3_1 , lf_AUX_Locate_Constants3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Declaration\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CE-pair\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Locate_Constants3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Declaration\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Declaration\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decl\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decl\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Locate_Constants3 ( ) {
}
ATerm lf_AUX_Locate_Constants3_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 14 ] ;
FUNC_ENTRY ( lf_AUX_Locate_Constants3_1sym , ATmakeAppl ( lf_AUX_Locate_Constants3_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( is_single_element ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = ( * ef4 ) ( tmp [ 0 ] , ( * ef2 ) ( lf3 ( make_list ( atmp100 ) ) , atmp11 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef5sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ;
FUNC_EXIT ( ( * ef3 ) ( lf3 ( make_list ( tmp [ 5 ] ) ) , ( * ef1 ) ( lf2 ( make_list ( tmp [ 3 ] ) ) ) , tmp [ 4 ] ) ) ;
}
}
}
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_prefix ( atmp000 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 1 ] = list_last ( atmp000 ) ;
tmp [ 2 ] = lf_AUX_Locate_Constants3_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) , ( * ef2 ) ( lf3 ( make_list ( atmp100 ) ) , atmp11 ) ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef1sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = ( * ef4 ) ( tmp [ 1 ] , ( * ef2 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) , tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , ef5sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf3sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ;
FUNC_EXIT ( ( * ef3 ) ( lf3 ( make_list ( tmp [ 13 ] ) ) , ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 11 ] ) ) ) ) , tmp [ 12 ] ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_Locate_Constants3_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

