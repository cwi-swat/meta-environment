#include  "asc-support.h"
static Symbol lf_AUX_Locate_Constants21_2sym ;
static ATerm lf_AUX_Locate_Constants21_2 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Locate_Constants21_1sym ;
static ATerm lf_AUX_Locate_Constants21_1 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
void register_AUX_Locate_Constants21 ( ) {
lf_AUX_Locate_Constants21_2sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"add-to-ce-pairs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants21_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_Locate_Constants21_1sym = ATmakeSymbol ( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants21_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CE-pair\"),ql(\",\"))" ) , lf_AUX_Locate_Constants21_1 , lf_AUX_Locate_Constants21_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"add-to-ce-pairs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants21_2 , lf_AUX_Locate_Constants21_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Locate_Constants21 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Locate_Constants21 ( ) {
}
ATerm lf_AUX_Locate_Constants21_2 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 15 ] ;
FUNC_ENTRY ( lf_AUX_Locate_Constants21_2sym , ATmakeAppl ( lf_AUX_Locate_Constants21_2sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg1 , lf_AUX_Locate_Constants21_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
( tmp [ 0 ] = list_head ( atmp10 ) ) ;
{
( tmp [ 1 ] = list_tail ( atmp10 ) ) ;
{
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
{
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ) ;
{
if ( check_sym ( tmp [ 4 ] , ef4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
{
if ( check_sym ( tmp [ 5 ] , ef5sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( ! term_equal ( arg0 , tmp [ 3 ] ) ) {
( tmp [ 7 ] = lf_AUX_Locate_Constants21_2 ( arg0 , lf_AUX_Locate_Constants21_1 ( make_list ( tmp [ 1 ] ) ) , arg2 ) ) ;
if ( check_sym ( tmp [ 7 ] , ef1sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ) ;
( tmp [ 10 ] = arg_2 ( tmp [ 7 ] ) ) ;
if ( check_sym ( tmp [ 8 ] , lf_AUX_Locate_Constants21_1sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 8 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , ef3sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ) ;
if ( check_sym ( tmp [ 12 ] , ef4sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ) ;
if ( check_sym ( tmp [ 13 ] , ef5sym ) ) {
( tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Locate_Constants21_1 ( cons ( make_list ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 6 ] ) ) ) , tmp [ 3 ] ) ) , make_list ( tmp [ 11 ] ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 14 ] ) ) ) , tmp [ 10 ] ) ) ;
}
}
}
}
}
}
else {
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Locate_Constants21_1 ( cons ( make_list ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 6 ] ) ) ) , arg0 ) ) , make_list ( tmp [ 1 ] ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 6 ] ) ) ) , arg2 ) ) ;
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
else {
if ( check_sym ( arg2 , ef6sym ) ) {
( tmp [ 0 ] = arg_0 ( arg2 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef7sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = ( * ef8 ) ( arg2 ) ) ;
( tmp [ 4 ] = ( * ef9 ) ( lf3 ( cons ( make_list_char ( 99 ) , cons ( make_list_char ( 111 ) , cons ( make_list_char ( 110 ) , cons ( make_list_char ( 115 ) , cons ( make_list_char ( 116 ) , cons ( make_list_char ( 97 ) , cons ( make_list_char ( 110 ) , cons ( make_list_char ( 116 ) , make_list ( tmp [ 2 ] ) ) ) ) ) ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Locate_Constants21_1 ( make_list ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 4 ] ) ) ) , arg0 ) ) ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 4 ] ) ) ) , tmp [ 3 ] ) ) ;
}
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Locate_Constants21_2sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf_AUX_Locate_Constants21_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants21_1sym , ATmakeAppl ( lf_AUX_Locate_Constants21_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Locate_Constants21_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

