#include  "asc-support.h"
static Symbol lf_AUX_Rules2C_Aux10_2sym ;
static ATerm lf_AUX_Rules2C_Aux10_2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Rules2C_Aux10_1sym ;
static ATerm lf_AUX_Rules2C_Aux10_1 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux10 ( ) {
lf_AUX_Rules2C_Aux10_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-defaults\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux10_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_Rules2C_Aux10_1sym = ATmakeSymbol ( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Rule\"),ql(\";\"))" ) , lf_AUX_Rules2C_Aux10_1 , lf_AUX_Rules2C_Aux10_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-defaults\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux10_2 , lf_AUX_Rules2C_Aux10_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Rules2C_Aux10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Rules2C_Aux10 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Rules2C_Aux10_2 ( ATerm arg0 ) {
{
ATerm tmp [ 12 ] ;
FUNC_ENTRY ( lf_AUX_Rules2C_Aux10_2sym , ATmakeAppl ( lf_AUX_Rules2C_Aux10_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Rules2C_Aux10_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef5sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , lf3sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
( tmp [ 7 ] = lf_AUX_Rules2C_Aux10_2 ( lf_AUX_Rules2C_Aux10_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 7 ] , ef1sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ) ;
if ( check_sym ( tmp [ 8 ] , lf_AUX_Rules2C_Aux10_1sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 8 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , lf_AUX_Rules2C_Aux10_1sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 9 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux10_1 ( make_list ( tmp [ 10 ] ) ) , lf_AUX_Rules2C_Aux10_1 ( cons ( make_list ( ( * ef4 ) ( ( * ef5 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) ) , tmp [ 3 ] , tmp [ 4 ] ) ) , make_list ( tmp [ 11 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef6sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef5sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , lf3sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
( tmp [ 7 ] = lf_AUX_Rules2C_Aux10_2 ( lf_AUX_Rules2C_Aux10_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 7 ] , ef1sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ) ;
if ( check_sym ( tmp [ 8 ] , lf_AUX_Rules2C_Aux10_1sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 8 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , lf_AUX_Rules2C_Aux10_1sym ) ) {
( tmp [ 11 ] = arg_0 ( tmp [ 9 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux10_1 ( cons ( make_list ( ( * ef6 ) ( ( * ef5 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) ) , tmp [ 3 ] , tmp [ 4 ] ) ) , make_list ( tmp [ 10 ] ) ) ) , lf_AUX_Rules2C_Aux10_1 ( make_list ( tmp [ 11 ] ) ) ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = lf_AUX_Rules2C_Aux10_2 ( lf_AUX_Rules2C_Aux10_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef1sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , lf_AUX_Rules2C_Aux10_1sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , lf_AUX_Rules2C_Aux10_1sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 6 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux10_1 ( make_list ( tmp [ 7 ] ) ) , lf_AUX_Rules2C_Aux10_1 ( cons ( make_list ( ( * ef2 ) ( tmp [ 2 ] , tmp [ 3 ] ) ) , make_list ( tmp [ 8 ] ) ) ) ) ) ;
}
}
}
}
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = lf_AUX_Rules2C_Aux10_2 ( lf_AUX_Rules2C_Aux10_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef1sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , lf_AUX_Rules2C_Aux10_1sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , lf_AUX_Rules2C_Aux10_1sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 6 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux10_1 ( cons ( make_list ( ( * ef3 ) ( tmp [ 2 ] , tmp [ 3 ] ) ) , make_list ( tmp [ 7 ] ) ) ) , lf_AUX_Rules2C_Aux10_1 ( make_list ( tmp [ 8 ] ) ) ) ) ;
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf_AUX_Rules2C_Aux10_1 ( make_list ( null ( ) ) ) , lf_AUX_Rules2C_Aux10_1 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Rules2C_Aux10_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Rules2C_Aux10_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Rules2C_Aux10_1sym , ATmakeAppl ( lf_AUX_Rules2C_Aux10_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Rules2C_Aux10_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

