#include  "support.h"
static Symbol lf_AUX_Rules2C_Aux19_2sym ;
static ATerm lf_AUX_Rules2C_Aux19_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Rules2C_Aux19_1sym ;
static ATerm lf_AUX_Rules2C_Aux19_1 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux19 ( ) {
lf_AUX_Rules2C_Aux19_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-conds-on-second-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux19_2sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf_AUX_Rules2C_Aux19_1sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux19_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_Rules2C_Aux19_1 , lf_AUX_Rules2C_Aux19_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-conds-on-second-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux19_2 , lf_AUX_Rules2C_Aux19_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf6 , lf6sym ) ;
}
void resolve_AUX_Rules2C_Aux19 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Rules2C_Aux19 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Rules2C_Aux19_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 36 ] ;
FUNC_ENTRY ( lf_AUX_Rules2C_Aux19_2sym , ATmakeAppl ( lf_AUX_Rules2C_Aux19_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , lf_AUX_Rules2C_Aux19_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
tmp [ 1 ] = list_tail ( atmp10 ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
tmp [ 5 ] = arg_3 ( tmp [ 0 ] ) ;
tmp [ 6 ] = arg_4 ( tmp [ 0 ] ) ;
tmp [ 7 ] = arg_5 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 9 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 9 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , ef3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 12 ] , ef4sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 12 ] ) ;
tmp [ 15 ] = arg_1 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 14 ] , ef5sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 14 ] ) ;
if ( check_sym ( tmp [ 16 ] , lf5sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ;
if ( check_sym ( tmp [ 15 ] , lf6sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 15 ] ) ;
if ( not_empty_list ( tmp [ 17 ] ) ) {
if ( term_equal ( list_head ( tmp [ 17 ] ) , make_char ( 116 ) ) ) {
tmp [ 19 ] = list_tail ( tmp [ 17 ] ) ;
if ( not_empty_list ( tmp [ 19 ] ) ) {
if ( term_equal ( list_head ( tmp [ 19 ] ) , make_char ( 101 ) ) ) {
tmp [ 20 ] = list_tail ( tmp [ 19 ] ) ;
if ( not_empty_list ( tmp [ 20 ] ) ) {
if ( term_equal ( list_head ( tmp [ 20 ] ) , make_char ( 114 ) ) ) {
tmp [ 21 ] = list_tail ( tmp [ 20 ] ) ;
if ( not_empty_list ( tmp [ 21 ] ) ) {
if ( term_equal ( list_head ( tmp [ 21 ] ) , make_char ( 109 ) ) ) {
tmp [ 22 ] = list_tail ( tmp [ 21 ] ) ;
if ( not_empty_list ( tmp [ 22 ] ) ) {
if ( term_equal ( list_head ( tmp [ 22 ] ) , make_char ( 45 ) ) ) {
tmp [ 23 ] = list_tail ( tmp [ 22 ] ) ;
if ( not_empty_list ( tmp [ 23 ] ) ) {
if ( term_equal ( list_head ( tmp [ 23 ] ) , make_char ( 101 ) ) ) {
tmp [ 24 ] = list_tail ( tmp [ 23 ] ) ;
if ( not_empty_list ( tmp [ 24 ] ) ) {
if ( term_equal ( list_head ( tmp [ 24 ] ) , make_char ( 113 ) ) ) {
tmp [ 25 ] = list_tail ( tmp [ 24 ] ) ;
if ( not_empty_list ( tmp [ 25 ] ) ) {
if ( term_equal ( list_head ( tmp [ 25 ] ) , make_char ( 117 ) ) ) {
tmp [ 26 ] = list_tail ( tmp [ 25 ] ) ;
if ( not_empty_list ( tmp [ 26 ] ) ) {
if ( term_equal ( list_head ( tmp [ 26 ] ) , make_char ( 97 ) ) ) {
tmp [ 27 ] = list_tail ( tmp [ 26 ] ) ;
if ( is_single_element ( tmp [ 27 ] ) ) {
if ( term_equal ( list_head ( tmp [ 27 ] ) , make_char ( 108 ) ) ) {
if ( not_empty_list ( tmp [ 18 ] ) ) {
tmp [ 28 ] = list_head ( tmp [ 18 ] ) ;
tmp [ 29 ] = list_tail ( tmp [ 18 ] ) ;
if ( is_single_element ( tmp [ 29 ] ) ) {
tmp [ 30 ] = list_head ( tmp [ 29 ] ) ;
if ( term_equal ( arg0 , tmp [ 30 ] ) ) {
tmp [ 31 ] = lf_AUX_Rules2C_Aux19_2 ( arg0 , lf_AUX_Rules2C_Aux19_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 31 ] , ef1sym ) ) {
tmp [ 32 ] = arg_0 ( tmp [ 31 ] ) ;
tmp [ 33 ] = arg_1 ( tmp [ 31 ] ) ;
if ( check_sym ( tmp [ 32 ] , lf_AUX_Rules2C_Aux19_1sym ) ) {
tmp [ 34 ] = arg_0 ( tmp [ 32 ] ) ;
if ( check_sym ( tmp [ 33 ] , lf_AUX_Rules2C_Aux19_1sym ) ) {
tmp [ 35 ] = arg_0 ( tmp [ 33 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux19_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( make_list ( tmp [ 8 ] ) ) , lf4 ( cons ( make_list ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf5 ( ( ATerm ) ATmakeList ( 10 , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] , char_table [ 45 ] , char_table [ 101 ] , char_table [ 113 ] , char_table [ 117 ] , char_table [ 97 ] , char_table [ 108 ] ) ) ) , lf6 ( cons ( make_list ( tmp [ 28 ] ) , make_list ( arg0 ) ) ) ) , tmp [ 13 ] ) ) , make_list ( tmp [ 11 ] ) ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 34 ] ) ) ) , lf_AUX_Rules2C_Aux19_1 ( make_list ( tmp [ 35 ] ) ) ) ) ;
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
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf_AUX_Rules2C_Aux19_1 ( make_list ( null ( ) ) ) , lf_AUX_Rules2C_Aux19_1 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
if ( check_sym ( arg1 , lf_AUX_Rules2C_Aux19_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
tmp [ 1 ] = list_tail ( atmp10 ) ;
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
tmp [ 5 ] = arg_3 ( tmp [ 0 ] ) ;
tmp [ 6 ] = arg_4 ( tmp [ 0 ] ) ;
tmp [ 7 ] = arg_5 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 10 ] = lf_AUX_Rules2C_Aux19_2 ( arg0 , lf_AUX_Rules2C_Aux19_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 10 ] , ef1sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
tmp [ 12 ] = arg_1 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf_AUX_Rules2C_Aux19_1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 11 ] ) ;
if ( check_sym ( tmp [ 12 ] , lf_AUX_Rules2C_Aux19_1sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 12 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux19_1 ( make_list ( tmp [ 13 ] ) ) , lf_AUX_Rules2C_Aux19_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( make_list ( tmp [ 8 ] ) ) , lf4 ( make_list ( tmp [ 9 ] ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 14 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Rules2C_Aux19_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Rules2C_Aux19_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Rules2C_Aux19_1sym , ATmakeAppl ( lf_AUX_Rules2C_Aux19_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Rules2C_Aux19_1sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf6 ( ATerm arg0 ) {
CONS_ENTRY ( lf6sym , ATmakeAppl ( lf6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf6sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}

