#include  "support.h"
static Symbol lf_AUX_Rules2C_Aux27_2sym ;
static ATerm lf_AUX_Rules2C_Aux27_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Rules2C_Aux27_1sym ;
static ATerm lf_AUX_Rules2C_Aux27_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux27 ( ) {
lf_AUX_Rules2C_Aux27_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"get-first-vf-path\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux27_2sym ) ;
lf_AUX_Rules2C_Aux27_1sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux27_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"IntCon\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_Rules2C_Aux27_1 , lf_AUX_Rules2C_Aux27_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"get-first-vf-path\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux27_2 , lf_AUX_Rules2C_Aux27_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"IntCon\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_Rules2C_Aux27 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Rules2C_Aux27 ( ) {
}
ATerm lf_AUX_Rules2C_Aux27_2 ( ATerm arg0 ) {
{
ATerm tmp [ 19 ] ;
PROF ( prof_lf_AUX_Rules2C_Aux27_2 ) ;
if ( check_sym ( arg0 , lf_AUX_Rules2C_Aux27_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
{
tmp [ 1 ] = list_tail ( atmp00 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
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
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 3 ] ) ;
{
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 8 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 10 ] , ef3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 12 ] , lf3sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
tmp [ 14 ] = list_head ( tmp [ 13 ] ) ;
tmp [ 15 ] = list_tail ( tmp [ 13 ] ) ;
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( check_sym ( tmp [ 14 ] , ef2sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 14 ] ) ;
tmp [ 17 ] = arg_1 ( tmp [ 14 ] ) ;
if ( check_sym ( tmp [ 17 ] , lf4sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ;
return ( * ef2 ) ( tmp [ 16 ] , lf4 ( make_list ( tmp [ 18 ] ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( tmp [ 10 ] , ef2sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 13 ] , lf4sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
return ( * ef2 ) ( tmp [ 12 ] , lf4 ( make_list ( tmp [ 14 ] ) ) ) ;
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
return make_nf1 ( lf_AUX_Rules2C_Aux27_2sym , arg0 ) ;
}
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}
ATerm lf5 ( ATerm arg0 ) {
PROF ( prof_lf5 ) ;
return make_nf1 ( lf5sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}
ATerm lf_AUX_Rules2C_Aux27_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux27_1 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux27_1sym , arg0 ) ;
}

