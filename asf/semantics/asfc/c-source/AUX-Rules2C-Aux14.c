#include  "support.h"
static Symbol lf_AUX_Rules2C_Aux14_2sym ;
static ATerm lf_AUX_Rules2C_Aux14_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Rules2C_Aux14_1sym ;
static ATerm lf_AUX_Rules2C_Aux14_1 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux14 ( ) {
lf_AUX_Rules2C_Aux14_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-same-list-pat\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux14_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf_AUX_Rules2C_Aux14_1sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux14_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_Rules2C_Aux14_1 , lf_AUX_Rules2C_Aux14_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-same-list-pat\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux14_2 , lf_AUX_Rules2C_Aux14_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Rules2C_Aux14 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Rules2C_Aux14 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Rules2C_Aux14_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 17 ] ;
PROF ( prof_lf_AUX_Rules2C_Aux14_2 ) ;
if ( check_sym ( arg1 , lf_AUX_Rules2C_Aux14_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
{
tmp [ 1 ] = list_tail ( atmp10 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef2sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ;
tmp [ 5 ] = arg_3 ( tmp [ 0 ] ) ;
tmp [ 6 ] = arg_4 ( tmp [ 0 ] ) ;
tmp [ 7 ] = arg_5 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 2 ] ) ;
{
if ( check_sym ( tmp [ 3 ] , lf4sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 3 ] ) ;
{
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 8 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 8 ] ) ;
tmp [ 12 ] = lf_AUX_Rules2C_Aux14_2 ( arg0 , lf_AUX_Rules2C_Aux14_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 12 ] , ef1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
tmp [ 14 ] = arg_1 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 13 ] , lf_AUX_Rules2C_Aux14_1sym ) ) {
tmp [ 15 ] = arg_0 ( tmp [ 13 ] ) ;
if ( check_sym ( tmp [ 14 ] , lf_AUX_Rules2C_Aux14_1sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 14 ] ) ;
return ( * ef1 ) ( lf_AUX_Rules2C_Aux14_1 ( make_list ( tmp [ 15 ] ) ) , lf_AUX_Rules2C_Aux14_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( tmp [ 10 ] ) , make_list ( tmp [ 11 ] ) ) ) , lf4 ( make_list ( tmp [ 9 ] ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 16 ] ) ) ) ) ;
}
}
}
if ( term_equal ( arg0 , tmp [ 10 ] ) ) {
tmp [ 12 ] = lf_AUX_Rules2C_Aux14_2 ( arg0 , lf_AUX_Rules2C_Aux14_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 12 ] , ef1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
tmp [ 14 ] = arg_1 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 13 ] , lf_AUX_Rules2C_Aux14_1sym ) ) {
tmp [ 15 ] = arg_0 ( tmp [ 13 ] ) ;
if ( check_sym ( tmp [ 14 ] , lf_AUX_Rules2C_Aux14_1sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 14 ] ) ;
return ( * ef1 ) ( lf_AUX_Rules2C_Aux14_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( arg0 ) , make_list ( tmp [ 11 ] ) ) ) , lf4 ( make_list ( tmp [ 9 ] ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 15 ] ) ) ) , lf_AUX_Rules2C_Aux14_1 ( make_list ( tmp [ 16 ] ) ) ) ;
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
return ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( lf_AUX_Rules2C_Aux14_1 ( make_list ( null ( ) ) ) , lf_AUX_Rules2C_Aux14_1 ( make_list ( null ( ) ) ) ) ) ) ;
}
}
}
return make_nf2 ( lf_AUX_Rules2C_Aux14_2sym , arg0 , arg1 ) ;
}
}
ATerm lf_AUX_Rules2C_Aux14_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux14_1 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux14_1sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}

