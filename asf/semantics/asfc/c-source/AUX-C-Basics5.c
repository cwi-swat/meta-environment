#include  "asc-support.h"
static Symbol lf_AUX_C_Basics5_1sym ;
static ATerm lf_AUX_C_Basics5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_C_Basics5 ( ) {
lf_AUX_C_Basics5_1sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++r\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics5_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Statement\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++r\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics5_1 , lf_AUX_C_Basics5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Statement\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_C_Basics5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_C_Basics5 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_C_Basics5_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 11 ] ;
FUNC_ENTRY ( lf_AUX_C_Basics5_1sym , ATmakeAppl ( lf_AUX_C_Basics5_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
FUNC_EXIT ( arg1 ) ;
}
if ( check_sym ( arg0 , ef2sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( is_single_element ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 3 ] = ( constant0 ? constant0 : ( constant0 = ( * ef6 ) ( ) ) ) ;
if ( term_equal ( tmp [ 1 ] , tmp [ 3 ] ) ) {
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
{
if ( check_sym ( tmp [ 4 ] , ef3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
{
if ( check_sym ( tmp [ 5 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
{
if ( not_empty_list ( tmp [ 6 ] ) ) {
tmp [ 7 ] = list_prefix ( tmp [ 6 ] ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
tmp [ 8 ] = list_last ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( ) , ( * ef2 ) ( ( * ef3 ) ( lf2 ( cons ( make_list ( tmp [ 7 ] ) , make_list ( ( * ef4 ) ( tmp [ 9 ] ) ) ) ) ) ) ) ) ) ) ) ) ;
}
}
}
if ( is_single_element ( tmp [ 6 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef4sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( make_list ( ( * ef5 ) ( ( * ef6 ) ( ) , ( * ef2 ) ( ( * ef3 ) ( lf2 ( make_list ( ( * ef4 ) ( tmp [ 8 ] ) ) ) ) ) ) ) ) ) ) ) ;
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
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( make_list ( ( * ef4 ) ( tmp [ 1 ] ) ) ) ) ) ) ;
}
}
{
if ( not_empty_list ( atmp0000 ) ) {
tmp [ 0 ] = list_prefix ( atmp0000 ) ;
{
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 1 ] = list_last ( atmp0000 ) ;
if ( check_sym ( tmp [ 1 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( ( * ef4 ) ( tmp [ 2 ] ) ) ) ) ) ) ) ;
}
if ( check_sym ( tmp [ 1 ] , ef5sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ;
tmp [ 4 ] = ( constant0 ? constant0 : ( constant0 = ( * ef6 ) ( ) ) ) ;
if ( term_equal ( tmp [ 2 ] , tmp [ 4 ] ) ) {
if ( check_sym ( tmp [ 3 ] , ef2sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
{
if ( check_sym ( tmp [ 5 ] , ef3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
{
if ( check_sym ( tmp [ 6 ] , lf2sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
{
if ( is_single_element ( tmp [ 7 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( ( * ef5 ) ( ( * ef6 ) ( ) , ( * ef2 ) ( ( * ef3 ) ( lf2 ( make_list ( ( * ef4 ) ( tmp [ 9 ] ) ) ) ) ) ) ) ) ) ) ) ) ;
}
}
if ( not_empty_list ( tmp [ 7 ] ) ) {
tmp [ 8 ] = list_prefix ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = list_last ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef4sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( ( * ef5 ) ( ( * ef6 ) ( ) , ( * ef2 ) ( ( * ef3 ) ( lf2 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( ( * ef4 ) ( tmp [ 10 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef2sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( not_empty_list ( atmp0000 ) ) {
FUNC_EXIT ( ( * ef7 ) ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( make_list ( atmp0000 ) ) ) ) , arg1 ) ) ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_C_Basics5_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

