#include  "support.h"
static Symbol lf_AUX_Remove_Lists_C18_2sym ;
static ATerm lf_AUX_Remove_Lists_C18_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf_AUX_Remove_Lists_C18_1sym ;
static ATerm lf_AUX_Remove_Lists_C18_1 ( ATerm arg1 ) ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
void register_AUX_Remove_Lists_C18 ( ) {
lf_AUX_Remove_Lists_C18_2sym = ATmakeSymbol ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-rhs-list-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_C18_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_Remove_Lists_C18_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists_C18_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_Remove_Lists_C18_1 , lf_AUX_Remove_Lists_C18_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-rhs-list-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) , lf_AUX_Remove_Lists_C18_2 , lf_AUX_Remove_Lists_C18_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Remove_Lists_C18 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-rhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-rhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-rhs-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"transform-rhs-list-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Remove_Lists_C18 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Remove_Lists_C18_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 15 ] ;
FUNC_ENTRY ( lf_AUX_Remove_Lists_C18_2sym , ATmakeAppl ( lf_AUX_Remove_Lists_C18_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Remove_Lists_C18_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
if ( ! term_equal ( tmp [ 0 ] , ( * ef1 ) ( ( * ef2 ) ( lf3 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 117 ) ) , cons ( make_list ( make_char ( 108 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) {
if ( term_equal ( ( * ef5 ) ( tmp [ 0 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef6 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef4 ) ( tmp [ 0 ] , arg1 ) ) ;
}
}
if ( term_equal ( ( * ef5 ) ( tmp [ 0 ] ) , ( constant1 ? constant1 : ( constant1 = ( * ef8 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef7 ) ( tmp [ 0 ] , arg1 ) ) ;
}
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 110 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 117 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 108 ) ) ) {
tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 108 ) ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf_AUX_Remove_Lists_C18_1 ( make_list ( ( * ef1 ) ( ( * ef2 ) ( lf3 ( ( ATerm ) ATmakeList ( 4 , char_table [ 110 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 108 ] ) ) ) ) ) ) , lf4 ( make_list ( null ( ) ) ) , arg1 ) ) ;
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
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
{
tmp [ 1 ] = list_tail ( atmp00 ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( ! term_equal ( tmp [ 0 ] , ( * ef1 ) ( ( * ef2 ) ( lf3 ( cons ( make_list ( make_char ( 110 ) ) , cons ( make_list ( make_char ( 117 ) ) , cons ( make_list ( make_char ( 108 ) ) , make_list ( make_char ( 108 ) ) ) ) ) ) ) ) ) ) {
if ( term_equal ( ( * ef5 ) ( tmp [ 0 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef6 ) ( ) ) ) ) ) {
tmp [ 2 ] = ( * ef4 ) ( tmp [ 0 ] , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_Remove_Lists_C18_1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf4sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 6 ] ) ;
tmp [ 9 ] = lf_AUX_Remove_Lists_C18_2 ( lf_AUX_Remove_Lists_C18_1 ( make_list ( tmp [ 1 ] ) ) , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef3sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf_AUX_Remove_Lists_C18_1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf4sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 11 ] ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf_AUX_Remove_Lists_C18_1 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 13 ] ) ) ) , lf4 ( cons ( make_list ( tmp [ 7 ] ) , make_list ( tmp [ 14 ] ) ) ) , tmp [ 12 ] ) ) ;
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
if ( term_equal ( ( * ef5 ) ( tmp [ 0 ] ) , ( constant1 ? constant1 : ( constant1 = ( * ef8 ) ( ) ) ) ) ) {
tmp [ 2 ] = ( * ef7 ) ( tmp [ 0 ] , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_Remove_Lists_C18_1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf4sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 6 ] ) ;
tmp [ 9 ] = lf_AUX_Remove_Lists_C18_2 ( lf_AUX_Remove_Lists_C18_1 ( make_list ( tmp [ 1 ] ) ) , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef3sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ;
tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf_AUX_Remove_Lists_C18_1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf4sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 11 ] ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf_AUX_Remove_Lists_C18_1 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 13 ] ) ) ) , lf4 ( cons ( make_list ( tmp [ 7 ] ) , make_list ( tmp [ 14 ] ) ) ) , tmp [ 12 ] ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_Remove_Lists_C18_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf_AUX_Remove_Lists_C18_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Remove_Lists_C18_1sym , ATmakeAppl ( lf_AUX_Remove_Lists_C18_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Remove_Lists_C18_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

