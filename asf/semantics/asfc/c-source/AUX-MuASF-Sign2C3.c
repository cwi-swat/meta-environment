#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Sign2C3_2sym ;
static ATerm lf_AUX_MuASF_Sign2C3_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf_AUX_MuASF_Sign2C3_1sym ;
static ATerm lf_AUX_MuASF_Sign2C3_1 ( ATerm arg1 ) ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_MuASF_Sign2C3 ( ) {
lf_AUX_MuASF_Sign2C3_2sym = ATmakeSymbol ( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Sign2C3_2sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Type-specifier\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf_AUX_MuASF_Sign2C3_1sym = ATmakeSymbol ( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Sign2C3_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"SigArg\"),ql(\",\"))" ) , lf_AUX_MuASF_Sign2C3_1 , lf_AUX_MuASF_Sign2C3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2cargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Sign2C3_2 , lf_AUX_MuASF_Sign2C3_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Type-specifier\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_MuASF_Sign2C3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Parameter-declaration\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Parameter-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Parameter-declaration\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Parameter-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_MuASF_Sign2C3 ( ) {
}
ATerm lf_AUX_MuASF_Sign2C3_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Sign2C3_2sym , ATmakeAppl ( lf_AUX_MuASF_Sign2C3_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , lf_AUX_MuASF_Sign2C3_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf3sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( is_single_element ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
FUNC_EXIT ( ( * ef3 ) ( lf4 ( make_list ( ( * ef4 ) ( ( * ef5 ) ( lf5 ( make_list ( ( * ef6 ) ( ( * ef7 ) ( lf3 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) , ( * ef8 ) ( ( * ef7 ) ( lf3 ( cons ( make_list_char ( 97 ) , cons ( make_list_char ( 114 ) , cons ( make_list_char ( 103 ) , make_list ( atmp1000 ) ) ) ) ) ) ) ) ) ) ) ) ;
}
}
}
}
}
}
}
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = lf_AUX_MuASF_Sign2C3_2 ( lf_AUX_MuASF_Sign2C3_1 ( make_list ( tmp [ 1 ] ) ) , ( * ef10 ) ( arg1 ) ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
( tmp [ 3 ] = arg_0 ( arg1 ) ) ;
if ( check_sym ( tmp [ 3 ] , ef2sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
FUNC_EXIT ( ( * ef9 ) ( ( * ef4 ) ( ( * ef5 ) ( lf5 ( make_list ( ( * ef6 ) ( ( * ef7 ) ( lf3 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) , ( * ef8 ) ( ( * ef7 ) ( lf3 ( cons ( make_list_char ( 97 ) , cons ( make_list_char ( 114 ) , cons ( make_list_char ( 103 ) , make_list ( tmp [ 5 ] ) ) ) ) ) ) ) ) , tmp [ 2 ] ) ) ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_MuASF_Sign2C3_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf_AUX_MuASF_Sign2C3_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Sign2C3_1sym , ATmakeAppl ( lf_AUX_MuASF_Sign2C3_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Sign2C3_1sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}

