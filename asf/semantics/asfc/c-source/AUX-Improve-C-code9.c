#include  "asc-support.h"
static Symbol lf_AUX_Improve_C_code9_1sym ;
static ATerm lf_AUX_Improve_C_code9_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef14sym ;
static funcptr ef14 ;
void register_AUX_Improve_C_code9 ( ) {
lf_AUX_Improve_C_code9_1sym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-stat\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code9_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Statement\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-stat\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code9_1 , lf_AUX_Improve_C_code9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Statement\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Improve_C_code9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-exps\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-exps\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-exp\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-exp\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"transform-arg-in-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Improve_C_code9 ( ) {
}
ATerm lf_AUX_Improve_C_code9_1 ( ATerm arg0 ) {
{
ATerm tmp [ 11 ] ;
FUNC_ENTRY ( lf_AUX_Improve_C_code9_1sym , ATmakeAppl ( lf_AUX_Improve_C_code9_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , ef4sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
if ( check_sym ( atmp00000 , ef5sym ) ) {
{
ATerm atmp000000 = arg_0 ( atmp00000 ) ;
if ( check_sym ( atmp000000 , ef6sym ) ) {
{
ATerm atmp0000000 = arg_0 ( atmp000000 ) ;
if ( check_sym ( atmp0000000 , lf2sym ) ) {
{
ATerm atmp00000000 = arg_0 ( atmp0000000 ) ;
{
ATerm atmp00001 = arg_1 ( atmp0000 ) ;
if ( check_sym ( atmp00001 , ef7sym ) ) {
{
ATerm atmp000010 = arg_0 ( atmp00001 ) ;
if ( check_sym ( atmp000010 , lf3sym ) ) {
{
ATerm atmp0000100 = arg_0 ( atmp000010 ) ;
if ( not_empty_list ( atmp00000000 ) ) {
if ( term_equal ( list_head ( atmp00000000 ) , make_char ( 70 ) ) ) {
( tmp [ 0 ] = list_tail ( atmp00000000 ) ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 85 ) ) ) {
( tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 78 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 67 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 95 ) ) ) {
( tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 69 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 88 ) ) ) {
( tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 73 ) ) ) {
( tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ) ;
if ( is_single_element ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 84 ) ) ) {
( tmp [ 8 ] = ( * ef8 ) ( ( * ef7 ) ( lf3 ( make_list ( atmp0000100 ) ) ) ) ) ;
if ( check_sym ( tmp [ 8 ] , ef7sym ) ) {
( tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , lf3sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ( * ef6 ) ( lf2 ( ( ATerm ) ATmakeList ( 9 , char_table [ 70 ] , char_table [ 85 ] , char_table [ 78 ] , char_table [ 67 ] , char_table [ 95 ] , char_table [ 69 ] , char_table [ 88 ] , char_table [ 73 ] , char_table [ 84 ] ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( tmp [ 10 ] ) ) ) ) ) ) ) ) ;
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
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef19sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
( tmp [ 0 ] = ( * ef14 ) ( atmp001 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef19 ) ( atmp000 , tmp [ 0 ] ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( arg0 , ef9sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef10sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef11sym ) ) {
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef12sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef13sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , lf4sym ) ) {
{
ATerm atmp011000 = arg_0 ( atmp01100 ) ;
if ( not_empty_list ( atmp011000 ) ) {
( tmp [ 0 ] = ( * ef14 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef15 ) ( ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( atmp011000 ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef12sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef13sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf4sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
FUNC_EXIT ( ( * ef9 ) ( tmp [ 0 ] , ( * ef10 ) ( ( * ef11 ) ( ) , ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( tmp [ 4 ] ) ) ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef16sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef10sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef11sym ) ) {
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef12sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef13sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , lf4sym ) ) {
{
ATerm atmp011000 = arg_0 ( atmp01100 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef10sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
if ( check_sym ( atmp020 , ef11sym ) ) {
{
ATerm atmp021 = arg_1 ( atmp02 ) ;
if ( check_sym ( atmp021 , ef12sym ) ) {
{
ATerm atmp0210 = arg_0 ( atmp021 ) ;
if ( check_sym ( atmp0210 , ef13sym ) ) {
{
ATerm atmp02100 = arg_0 ( atmp0210 ) ;
if ( check_sym ( atmp02100 , lf4sym ) ) {
{
ATerm atmp021000 = arg_0 ( atmp02100 ) ;
if ( not_empty_list ( atmp011000 ) ) {
if ( not_empty_list ( atmp021000 ) ) {
( tmp [ 0 ] = ( * ef14 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef15 ) ( ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( atmp011000 ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef12sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef13sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf4sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
( tmp [ 5 ] = ( * ef15 ) ( ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( atmp021000 ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 5 ] , ef12sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , ef13sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
FUNC_EXIT ( ( * ef16 ) ( tmp [ 0 ] , ( * ef10 ) ( ( * ef11 ) ( ) , ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( tmp [ 4 ] ) ) ) ) ) , ( * ef10 ) ( ( * ef11 ) ( ) , ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( tmp [ 8 ] ) ) ) ) ) ) ) ;
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
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef17sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef10sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef11sym ) ) {
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef12sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef13sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , lf4sym ) ) {
{
ATerm atmp011000 = arg_0 ( atmp01100 ) ;
if ( not_empty_list ( atmp011000 ) ) {
( tmp [ 0 ] = ( * ef14 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef15 ) ( ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( atmp011000 ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef12sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef13sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf4sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
FUNC_EXIT ( ( * ef17 ) ( tmp [ 0 ] , ( * ef10 ) ( ( * ef11 ) ( ) , ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( tmp [ 4 ] ) ) ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef10sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef12sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef13sym ) ) {
{
ATerm atmp0100 = arg_0 ( atmp010 ) ;
if ( check_sym ( atmp0100 , lf4sym ) ) {
{
ATerm atmp01000 = arg_0 ( atmp0100 ) ;
if ( not_empty_list ( atmp01000 ) ) {
( tmp [ 0 ] = ( * ef15 ) ( ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( atmp01000 ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef12sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , ef13sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
FUNC_EXIT ( ( * ef10 ) ( atmp00 , ( * ef12 ) ( ( * ef13 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef18sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
( tmp [ 0 ] = lf_AUX_Improve_C_code9_1 ( atmp01 ) ) ;
FUNC_EXIT ( ( * ef18 ) ( atmp00 , tmp [ 0 ] ) ) ;
}
}
}
FUNC_EXIT ( arg0 ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Improve_C_code9_1sym , arg0 ) ) ;
}
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

