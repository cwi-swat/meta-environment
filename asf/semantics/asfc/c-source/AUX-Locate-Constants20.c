#include  "asc-support.h"
static Symbol lf_AUX_Locate_Constants20_2sym ;
static ATerm lf_AUX_Locate_Constants20_2 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol lf8sym ;
static ATerm lf8 ( ATerm arg1 ) ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf_AUX_Locate_Constants20_1sym ;
static ATerm lf_AUX_Locate_Constants20_1 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol lf7sym ;
static ATerm lf7 ( ATerm arg1 ) ;
void register_AUX_Locate_Constants20 ( ) {
lf_AUX_Locate_Constants20_2sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"make-stats-function\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants20_2sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Type-specifier\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf8sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf8sym ) ;
lf_AUX_Locate_Constants20_1sym = ATmakeSymbol ( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants20_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Declaration\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf7sym = ATmakeSymbol ( "listtype(sort(\"Statement\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf7sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CE-pair\"),ql(\",\"))" ) , lf_AUX_Locate_Constants20_1 , lf_AUX_Locate_Constants20_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"make-stats-function\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants20_2 , lf_AUX_Locate_Constants20_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Declaration\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Type-specifier\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf6 , lf6sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Statement\"))" ) , lf7 , lf7sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf8 , lf8sym ) ;
}
void resolve_AUX_Locate_Constants20 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Declaration\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Declaration\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"static\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Unary-operator\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[ql(\"&\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[ql(\"&\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Unary-operator\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Locate_Constants20 ( ) {
}
ATerm lf_AUX_Locate_Constants20_2 ( ATerm arg0 ) {
{
ATerm tmp [ 25 ] ;
FUNC_ENTRY ( lf_AUX_Locate_Constants20_2sym , ATmakeAppl ( lf_AUX_Locate_Constants20_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Locate_Constants20_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , ef4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , ef12sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , lf6sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 116 ) ) ) {
( tmp [ 8 ] = list_tail ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 97 ) ) ) {
( tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ) ;
if ( not_empty_list ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 98 ) ) ) {
( tmp [ 10 ] = list_tail ( tmp [ 9 ] ) ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
if ( term_equal ( list_head ( tmp [ 10 ] ) , make_char ( 108 ) ) ) {
( tmp [ 11 ] = list_tail ( tmp [ 10 ] ) ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
if ( term_equal ( list_head ( tmp [ 11 ] ) , make_char ( 101 ) ) ) {
( tmp [ 12 ] = list_tail ( tmp [ 11 ] ) ) ;
FUNC_EXIT ( ( * ef5 ) ( lf3 ( make_list ( null ( ) ) ) , ( * ef6 ) ( ( * ef7 ) ( lf4 ( make_list ( ( * ef8 ) ( ( * ef9 ) ( lf5 ( cons ( make_list ( ( * ef10 ) ( ) ) , make_list ( ( * ef11 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 10 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] , char_table [ 84 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) ) ) ) ) , ( * ef13 ) ( tmp [ 5 ] ) ) ) ) ) ) , ( * ef14 ) ( ( * ef15 ) ( lf7 ( make_list ( ( * ef16 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef17 ) ( ( * ef4 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 12 , char_table [ 99 ] , char_table [ 114 ] , char_table [ 101 ] , char_table [ 97 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 95 ] , char_table [ 116 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) , ( * ef18 ) ( lf8 ( cons ( make_list ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( tmp [ 5 ] ) ) ) ) , make_list ( ( * ef2 ) ( ( * ef3 ) ( ( * ef19 ) ( ( * ef20 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
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
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_prefix ( atmp00 ) ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
( tmp [ 1 ] = list_last ( atmp00 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef1sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , ef3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , ef4sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , ef12sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf6sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 116 ) ) ) {
( tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ) ;
if ( not_empty_list ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 97 ) ) ) {
( tmp [ 10 ] = list_tail ( tmp [ 9 ] ) ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
if ( term_equal ( list_head ( tmp [ 10 ] ) , make_char ( 98 ) ) ) {
( tmp [ 11 ] = list_tail ( tmp [ 10 ] ) ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
if ( term_equal ( list_head ( tmp [ 11 ] ) , make_char ( 108 ) ) ) {
( tmp [ 12 ] = list_tail ( tmp [ 11 ] ) ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 101 ) ) ) {
( tmp [ 13 ] = list_tail ( tmp [ 12 ] ) ) ;
( tmp [ 14 ] = lf_AUX_Locate_Constants20_2 ( lf_AUX_Locate_Constants20_1 ( make_list ( tmp [ 0 ] ) ) ) ) ;
if ( check_sym ( tmp [ 14 ] , ef5sym ) ) {
( tmp [ 15 ] = arg_0 ( tmp [ 14 ] ) ) ;
( tmp [ 16 ] = arg_1 ( tmp [ 14 ] ) ) ;
( tmp [ 17 ] = arg_2 ( tmp [ 14 ] ) ) ;
if ( check_sym ( tmp [ 15 ] , lf3sym ) ) {
( tmp [ 18 ] = arg_0 ( tmp [ 15 ] ) ) ;
if ( check_sym ( tmp [ 16 ] , ef6sym ) ) {
( tmp [ 19 ] = arg_0 ( tmp [ 16 ] ) ) ;
if ( check_sym ( tmp [ 19 ] , ef7sym ) ) {
( tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ) ;
if ( check_sym ( tmp [ 20 ] , lf4sym ) ) {
( tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ) ;
if ( check_sym ( tmp [ 17 ] , ef14sym ) ) {
( tmp [ 22 ] = arg_0 ( tmp [ 17 ] ) ) ;
if ( check_sym ( tmp [ 22 ] , ef15sym ) ) {
( tmp [ 23 ] = arg_0 ( tmp [ 22 ] ) ) ;
if ( check_sym ( tmp [ 23 ] , lf7sym ) ) {
( tmp [ 24 ] = arg_0 ( tmp [ 23 ] ) ) ;
if ( ! not_empty_list ( tmp [ 18 ] ) ) {
if ( not_empty_list ( tmp [ 21 ] ) ) {
if ( not_empty_list ( tmp [ 24 ] ) ) {
FUNC_EXIT ( ( * ef5 ) ( lf3 ( make_list ( null ( ) ) ) , ( * ef6 ) ( ( * ef7 ) ( lf4 ( cons ( make_list ( tmp [ 21 ] ) , make_list ( ( * ef8 ) ( ( * ef9 ) ( lf5 ( make_list ( ( * ef11 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 10 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] , char_table [ 84 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) ) ) ) , ( * ef13 ) ( tmp [ 6 ] ) ) ) ) ) ) ) , ( * ef14 ) ( ( * ef15 ) ( lf7 ( cons ( make_list ( tmp [ 24 ] ) , make_list ( ( * ef16 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef17 ) ( ( * ef4 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 12 , char_table [ 99 ] , char_table [ 114 ] , char_table [ 101 ] , char_table [ 97 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 95 ] , char_table [ 116 ] , char_table [ 97 ] , char_table [ 98 ] , char_table [ 108 ] , char_table [ 101 ] ) ) ) ) , ( * ef18 ) ( lf8 ( cons ( make_list ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( tmp [ 6 ] ) ) ) ) , make_list ( ( * ef2 ) ( ( * ef3 ) ( ( * ef19 ) ( ( * ef20 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
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
if ( check_sym ( arg0 , lf_AUX_Locate_Constants20_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , ef4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
FUNC_EXIT ( ( * ef5 ) ( lf3 ( make_list ( null ( ) ) ) , ( * ef6 ) ( ( * ef7 ) ( lf4 ( make_list ( ( * ef21 ) ( ( * ef9 ) ( lf5 ( cons ( make_list ( ( * ef10 ) ( ) ) , make_list ( ( * ef11 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) , ( * ef13 ) ( tmp [ 5 ] ) , ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 4 , char_table [ 78 ] , char_table [ 85 ] , char_table [ 76 ] , char_table [ 76 ] ) ) ) ) ) ) ) ) ) ) ) , ( * ef14 ) ( ( * ef15 ) ( lf7 ( make_list ( ( * ef16 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef17 ) ( ( * ef4 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 9 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 112 ] , char_table [ 114 ] , char_table [ 111 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 99 ] , char_table [ 116 ] ) ) ) ) , ( * ef18 ) ( lf8 ( make_list ( ( * ef22 ) ( ( * ef23 ) ( ) , ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( tmp [ 5 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
}
}
}
}
}
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_prefix ( atmp00 ) ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
( tmp [ 1 ] = list_last ( atmp00 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef1sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , ef3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , ef4sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
( tmp [ 7 ] = lf_AUX_Locate_Constants20_2 ( lf_AUX_Locate_Constants20_1 ( make_list ( tmp [ 0 ] ) ) ) ) ;
if ( check_sym ( tmp [ 7 ] , ef5sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ) ;
( tmp [ 10 ] = arg_2 ( tmp [ 7 ] ) ) ;
if ( check_sym ( tmp [ 8 ] , lf3sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 8 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , ef6sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ) ;
if ( check_sym ( tmp [ 12 ] , ef7sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ) ;
if ( check_sym ( tmp [ 13 ] , lf4sym ) ) {
( tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ) ;
if ( check_sym ( tmp [ 10 ] , ef14sym ) ) {
( tmp [ 15 ] = arg_0 ( tmp [ 10 ] ) ) ;
if ( check_sym ( tmp [ 15 ] , ef15sym ) ) {
( tmp [ 16 ] = arg_0 ( tmp [ 15 ] ) ) ;
if ( check_sym ( tmp [ 16 ] , lf7sym ) ) {
( tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ) ;
if ( ! not_empty_list ( tmp [ 11 ] ) ) {
if ( not_empty_list ( tmp [ 14 ] ) ) {
if ( not_empty_list ( tmp [ 17 ] ) ) {
FUNC_EXIT ( ( * ef5 ) ( lf3 ( make_list ( null ( ) ) ) , ( * ef6 ) ( ( * ef7 ) ( lf4 ( cons ( make_list ( tmp [ 14 ] ) , make_list ( ( * ef21 ) ( ( * ef9 ) ( lf5 ( cons ( make_list ( ( * ef10 ) ( ) ) , make_list ( ( * ef11 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) , ( * ef13 ) ( tmp [ 6 ] ) , ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 4 , char_table [ 78 ] , char_table [ 85 ] , char_table [ 76 ] , char_table [ 76 ] ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef14 ) ( ( * ef15 ) ( lf7 ( cons ( make_list ( tmp [ 17 ] ) , make_list ( ( * ef16 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef17 ) ( ( * ef4 ) ( ( * ef12 ) ( lf6 ( ( ATerm ) ATmakeList ( 9 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 112 ] , char_table [ 114 ] , char_table [ 111 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 99 ] , char_table [ 116 ] ) ) ) ) , ( * ef18 ) ( lf8 ( make_list ( ( * ef22 ) ( ( * ef23 ) ( ) , ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( tmp [ 6 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf1 ( lf_AUX_Locate_Constants20_2sym , arg0 ) ) ;
}
}
ATerm lf7 ( ATerm arg0 ) {
CONS_ENTRY ( lf7sym , ATmakeAppl ( lf7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf7sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf_AUX_Locate_Constants20_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants20_1sym , ATmakeAppl ( lf_AUX_Locate_Constants20_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Locate_Constants20_1sym , arg0 ) ) ;
}
ATerm lf8 ( ATerm arg0 ) {
CONS_ENTRY ( lf8sym , ATmakeAppl ( lf8sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf8sym , arg0 ) ) ;
}
ATerm lf6 ( ATerm arg0 ) {
CONS_ENTRY ( lf6sym , ATmakeAppl ( lf6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf6sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}

