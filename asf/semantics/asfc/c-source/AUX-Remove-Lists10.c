#include  "asc-support.h"
static Symbol lf_AUX_Remove_Lists10_1sym ;
static ATerm lf_AUX_Remove_Lists10_1 ( ATerm arg1 ) ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Remove_Lists10 ( ) {
lf_AUX_Remove_Lists10_1sym = ATmakeSymbol ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"remove-simple-lists\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Remove_Lists10_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"remove-simple-lists\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) , lf_AUX_Remove_Lists10_1 , lf_AUX_Remove_Lists10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Remove_Lists10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"rem-lists-from-lhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"rem-lists-from-rhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"rem-lists-from-rhs-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-conditional-rule\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-conditional-rule\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"rem-lists-from-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Remove-Lists\"),w(\"\"),[l(\"rem-lists-from-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Remove_Lists10 ( ) {
}
ATerm lf_AUX_Remove_Lists10_1 ( ATerm arg0 ) {
{
ATerm tmp [ 19 ] ;
FUNC_ENTRY ( lf_AUX_Remove_Lists10_1sym , ATmakeAppl ( lf_AUX_Remove_Lists10_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
( tmp [ 0 ] = ( * ef2 ) ( atmp00 , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) , lf3 ( make_list ( null ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef6sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( is_single_element ( tmp [ 4 ] ) ) {
( tmp [ 6 ] = list_head ( tmp [ 4 ] ) ) ;
( tmp [ 7 ] = ( * ef7 ) ( atmp01 , tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , ef6sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ) ;
( tmp [ 10 ] = arg_2 ( tmp [ 7 ] ) ) ;
if ( check_sym ( tmp [ 8 ] , lf3sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 8 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , lf4sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ) ;
if ( is_single_element ( tmp [ 11 ] ) ) {
( tmp [ 13 ] = list_head ( tmp [ 11 ] ) ) ;
( tmp [ 14 ] = ( * ef8 ) ( lf4 ( cons ( make_list ( tmp [ 5 ] ) , make_list ( tmp [ 12 ] ) ) ) , ( * ef1 ) ( tmp [ 6 ] , tmp [ 13 ] ) ) ) ;
FUNC_EXIT ( tmp [ 14 ] ) ;
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
if ( check_sym ( arg0 , ef9sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef10sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf4sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( not_empty_list ( atmp0000 ) ) {
( tmp [ 0 ] = ( * ef2 ) ( atmp01 , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) , lf3 ( make_list ( null ( ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef6sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( is_single_element ( tmp [ 4 ] ) ) {
( tmp [ 6 ] = list_head ( tmp [ 4 ] ) ) ;
( tmp [ 7 ] = ( * ef11 ) ( lf4 ( make_list ( atmp0000 ) ) , tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , ef12sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ) ;
if ( check_sym ( tmp [ 8 ] , lf4sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 8 ] ) ) ;
( tmp [ 11 ] = ( * ef7 ) ( atmp02 , tmp [ 9 ] ) ) ;
if ( check_sym ( tmp [ 11 ] , ef6sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ) ;
( tmp [ 13 ] = arg_1 ( tmp [ 11 ] ) ) ;
( tmp [ 14 ] = arg_2 ( tmp [ 11 ] ) ) ;
if ( check_sym ( tmp [ 12 ] , lf3sym ) ) {
( tmp [ 15 ] = arg_0 ( tmp [ 12 ] ) ) ;
if ( check_sym ( tmp [ 13 ] , lf4sym ) ) {
( tmp [ 16 ] = arg_0 ( tmp [ 13 ] ) ) ;
if ( is_single_element ( tmp [ 15 ] ) ) {
( tmp [ 17 ] = list_head ( tmp [ 15 ] ) ) ;
( tmp [ 18 ] = ( * ef8 ) ( lf4 ( cons ( make_list ( tmp [ 5 ] ) , cons ( make_list ( tmp [ 10 ] ) , make_list ( tmp [ 16 ] ) ) ) ) , ( * ef1 ) ( tmp [ 6 ] , tmp [ 17 ] ) ) ) ;
FUNC_EXIT ( tmp [ 18 ] ) ;
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
FUNC_EXIT ( make_nf1 ( lf_AUX_Remove_Lists10_1sym , arg0 ) ) ;
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

