#include  "support.h"
static Symbol lf_AUX_Integers10_1sym ;
static ATerm lf_AUX_Integers10_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Integers10 ( ) {
lf_AUX_Integers10_1sym = ATmakeSymbol ( "prod(id(\"Integers\"),w(\"\"),[sort(\"NatCon\"),w(\"\"),ql(\">-\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Integers10_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Integers\"),w(\"\"),[sort(\"NatCon\"),w(\"\"),ql(\">-\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) , lf_AUX_Integers10_1 , lf_AUX_Integers10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Integers10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"NatCon\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"NatCon\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_Integers10 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_Integers10_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 18 ] ;
PROF ( prof_lf_AUX_Integers10_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( is_single_element ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( is_single_element ( atmp100 ) ) {
tmp [ 1 ] = list_head ( atmp100 ) ;
return ( * ef2 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
}
{
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_prefix ( atmp000 ) ;
{
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 1 ] = list_last ( atmp000 ) ;
{
if ( not_empty_list ( atmp100 ) ) {
tmp [ 2 ] = list_prefix ( atmp100 ) ;
tmp [ 3 ] = list_last ( atmp100 ) ;
tmp [ 4 ] = ( * ef2 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , ( * ef1 ) ( lf2 ( make_list ( tmp [ 3 ] ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef1sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 6 ] ) ;
tmp [ 8 ] = lf_AUX_Integers10_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) , ( * ef1 ) ( lf2 ( cons ( ( constant0 ? constant0 : ( constant0 = make_list ( make_char ( 48 ) ) ) ) , make_list ( tmp [ 2 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 8 ] , ef1sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf2sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
return ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 10 ] ) , make_list ( tmp [ 7 ] ) ) ) ) ;
}
}
}
}
}
}
tmp [ 4 ] = ( * ef2 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 3 ] ) ) ) , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef1sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 6 ] ) ;
tmp [ 8 ] = ( * ef2 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef1 ) ( lf2 ( cons ( make_list ( make_char ( 49 ) ) , make_list ( make_char ( 48 ) ) ) ) ) ) ) , ( * ef1 ) ( lf2 ( make_list ( tmp [ 7 ] ) ) ) ) ;
if ( check_sym ( tmp [ 8 ] , ef1sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf2sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( is_single_element ( tmp [ 10 ] ) ) {
tmp [ 11 ] = list_head ( tmp [ 10 ] ) ;
tmp [ 12 ] = ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ( * ef1 ) ( lf2 ( cons ( ( constant0 ? constant0 : ( constant0 = make_list ( make_char ( 48 ) ) ) ) , make_list ( tmp [ 2 ] ) ) ) ) ) ) , ( constant2 ? constant2 : ( constant2 = ( * ef4 ) ( ( * ef5 ) ( ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 12 ] , ef4sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 13 ] , ef5sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
tmp [ 15 ] = lf_AUX_Integers10_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) , tmp [ 14 ] ) ;
if ( check_sym ( tmp [ 15 ] , ef1sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 15 ] ) ;
if ( check_sym ( tmp [ 16 ] , lf2sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ;
if ( not_empty_list ( tmp [ 17 ] ) ) {
return ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 17 ] ) , make_list ( tmp [ 11 ] ) ) ) ) ;
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
}
}
}
}
}
}
}
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( is_single_element ( atmp100 ) ) {
if ( term_equal ( list_head ( atmp100 ) , make_char ( 48 ) ) ) {
return arg0 ;
}
}
}
}
}
}
return make_nf2 ( lf_AUX_Integers10_1sym , arg0 , arg1 ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}

