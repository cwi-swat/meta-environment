#include  "asc-support.h"
static Symbol lf_AUX_Priority_Sdf_Projection5_1sym ;
static ATerm lf_AUX_Priority_Sdf_Projection5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef9sym ;
static funcptr ef9 ;
void register_AUX_Priority_Sdf_Projection5 ( ) {
lf_AUX_Priority_Sdf_Projection5_1sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[sort(\"Priority\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Projection5_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Group\"),ql(\">\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Priority\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Projection\"),w(\"\"),[sort(\"Priority\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"Priorities\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Projection5_1 , lf_AUX_Priority_Sdf_Projection5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Group\"),ql(\">\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Priority\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Priority_Sdf_Projection5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Group\"),w(\"\"),ql(\">\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Group\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Priority\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[sort(\"Production\"),w(\"\"),ql(\"~=\"),w(\"\"),sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[sort(\"Production\"),w(\"\"),ql(\"~=\"),w(\"\"),sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Syntax\"),w(\"\"),[sort(\"Group\"),w(\"\"),sort(\"Associativity\"),w(\"\"),sort(\"Group\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priority\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Priority_Sdf_Projection5 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Priority_Sdf_Projection5_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 13 ] ;
FUNC_ENTRY ( lf_AUX_Priority_Sdf_Projection5_1sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Projection5_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef3sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
tmp [ 0 ] = arg_0 ( atmp10 ) ;
{
ATerm atmp10010 ;
ATerm atmp1000 [ 2 ] ;
atmp1000 [ 0 ] = tmp [ 0 ] ;
atmp1000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp10010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 1 ] = list_head ( atmp000 ) ;
tmp [ 2 ] = list_tail ( atmp000 ) ;
if ( is_single_element ( tmp [ 2 ] ) ) {
tmp [ 3 ] = list_head ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef2sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( atmp10010 , ef1sym ) ) {
tmp [ 6 ] = arg_0 ( atmp10010 ) ;
if ( check_sym ( tmp [ 6 ] , lf2sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 7 ] ) ;
tmp [ 9 ] = list_tail ( tmp [ 7 ] ) ;
if ( is_single_element ( tmp [ 9 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef2sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 10 ] , ef2sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ;
if ( term_equal ( ( * ef5 ) ( tmp [ 4 ] , tmp [ 11 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) ) ) {
if ( term_equal ( ( * ef5 ) ( tmp [ 5 ] , tmp [ 12 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef4 ) ( ) ) ;
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
atmp1000 [ 1 ] = list_tail ( atmp1000 [ 1 ] ) ;
tmp [ 0 ] = atmp1000 [ 1 ] ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef6sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef2sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
if ( check_sym ( arg1 , ef3sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
tmp [ 0 ] = arg_0 ( atmp10 ) ;
{
ATerm atmp10010 ;
ATerm atmp1000 [ 2 ] ;
atmp1000 [ 0 ] = tmp [ 0 ] ;
atmp1000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp10010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( atmp10010 , ef6sym ) ) {
tmp [ 1 ] = arg_0 ( atmp10010 ) ;
tmp [ 2 ] = arg_1 ( atmp10010 ) ;
tmp [ 3 ] = arg_2 ( atmp10010 ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef2sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
if ( term_equal ( atmp01 , tmp [ 2 ] ) ) {
if ( term_equal ( ( * ef7 ) ( ( * ef8 ) ( ( * ef5 ) ( atmp000 , tmp [ 4 ] ) , ( * ef5 ) ( atmp020 , tmp [ 5 ] ) ) , ( * ef8 ) ( ( * ef5 ) ( atmp000 , tmp [ 5 ] ) , ( * ef5 ) ( atmp020 , tmp [ 4 ] ) ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef4 ) ( ) ) ;
}
}
}
}
}
atmp1000 [ 1 ] = list_tail ( atmp1000 [ 1 ] ) ;
tmp [ 0 ] = atmp1000 [ 1 ] ;
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
if ( check_sym ( arg1 , ef3sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT_CONST ( constant1 , ( * ef9 ) ( ) ) ;
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Priority_Sdf_Projection5_1sym , arg0 , arg1 ) ) ;
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

