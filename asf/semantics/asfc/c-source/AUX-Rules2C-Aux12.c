#include  "support.h"
static Symbol lf_AUX_Rules2C_Aux12_2sym ;
static ATerm lf_AUX_Rules2C_Aux12_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Rules2C_Aux12_1sym ;
static ATerm lf_AUX_Rules2C_Aux12_1 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux12 ( ) {
lf_AUX_Rules2C_Aux12_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-ofs-first-arg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux12_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"IntCon\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf_AUX_Rules2C_Aux12_1sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux12_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_Rules2C_Aux12_1 , lf_AUX_Rules2C_Aux12_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-ofs-first-arg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux12_2 , lf_AUX_Rules2C_Aux12_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"IntCon\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_Rules2C_Aux12 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_Rules2C_Aux12 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_Rules2C_Aux12_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 27 ] ;
PROF ( prof_lf_AUX_Rules2C_Aux12_2 ) ;
if ( check_sym ( arg1 , lf_AUX_Rules2C_Aux12_1sym ) ) {
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
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 3 ] ) ;
{
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 8 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 10 ] , ef8sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ;
{
if ( check_sym ( tmp [ 12 ] , lf3sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
{
if ( not_empty_list ( tmp [ 13 ] ) ) {
tmp [ 14 ] = list_head ( tmp [ 13 ] ) ;
{
tmp [ 15 ] = list_tail ( tmp [ 13 ] ) ;
{
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( check_sym ( tmp [ 14 ] , ef3sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 14 ] ) ;
tmp [ 17 ] = arg_1 ( tmp [ 14 ] ) ;
{
if ( check_sym ( tmp [ 17 ] , lf4sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ;
tmp [ 19 ] = ( * ef7 ) ( tmp [ 16 ] ) ;
if ( ! term_equal ( arg0 , tmp [ 19 ] ) ) {
tmp [ 20 ] = lf_AUX_Rules2C_Aux12_2 ( arg0 , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 20 ] , ef1sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ;
tmp [ 22 ] = arg_1 ( tmp [ 20 ] ) ;
tmp [ 23 ] = arg_2 ( tmp [ 20 ] ) ;
if ( check_sym ( tmp [ 21 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 24 ] = arg_0 ( tmp [ 21 ] ) ;
if ( check_sym ( tmp [ 22 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 25 ] = arg_0 ( tmp [ 22 ] ) ;
if ( check_sym ( tmp [ 23 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 26 ] = arg_0 ( tmp [ 23 ] ) ;
return ( * ef1 ) ( lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 24 ] ) ) , lf_AUX_Rules2C_Aux12_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef8 ) ( lf3 ( cons ( make_list ( ( * ef3 ) ( tmp [ 16 ] , lf4 ( make_list ( tmp [ 18 ] ) ) ) ) , make_list ( tmp [ 15 ] ) ) ) ) ) , make_list ( tmp [ 11 ] ) ) ) , lf5 ( make_list ( tmp [ 9 ] ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 25 ] ) ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 26 ] ) ) ) ;
}
}
}
}
}
if ( term_equal ( ( * ef7 ) ( tmp [ 16 ] ) , arg0 ) ) {
tmp [ 19 ] = lf_AUX_Rules2C_Aux12_2 ( arg0 , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 19 ] , ef1sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ;
tmp [ 21 ] = arg_1 ( tmp [ 19 ] ) ;
tmp [ 22 ] = arg_2 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 23 ] = arg_0 ( tmp [ 20 ] ) ;
if ( check_sym ( tmp [ 21 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 24 ] = arg_0 ( tmp [ 21 ] ) ;
if ( check_sym ( tmp [ 22 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 25 ] = arg_0 ( tmp [ 22 ] ) ;
return ( * ef1 ) ( lf_AUX_Rules2C_Aux12_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef8 ) ( lf3 ( cons ( make_list ( ( * ef3 ) ( tmp [ 16 ] , lf4 ( make_list ( tmp [ 18 ] ) ) ) ) , make_list ( tmp [ 15 ] ) ) ) ) ) , make_list ( tmp [ 11 ] ) ) ) , lf5 ( make_list ( tmp [ 9 ] ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 23 ] ) ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 24 ] ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 25 ] ) ) ) ;
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
if ( check_sym ( tmp [ 10 ] , ef3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 10 ] ) ;
{
if ( check_sym ( tmp [ 13 ] , lf4sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
tmp [ 15 ] = ( * ef4 ) ( tmp [ 12 ] ) ;
if ( term_equal ( tmp [ 15 ] , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ) ) {
tmp [ 16 ] = lf_AUX_Rules2C_Aux12_2 ( arg0 , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 16 ] , ef1sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ;
tmp [ 18 ] = arg_1 ( tmp [ 16 ] ) ;
tmp [ 19 ] = arg_2 ( tmp [ 16 ] ) ;
if ( check_sym ( tmp [ 17 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 17 ] ) ;
if ( check_sym ( tmp [ 18 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 18 ] ) ;
if ( check_sym ( tmp [ 19 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 19 ] ) ;
return ( * ef1 ) ( lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 20 ] ) ) , lf_AUX_Rules2C_Aux12_1 ( cons ( make_list ( tmp [ 21 ] ) , make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef3 ) ( tmp [ 12 ] , lf4 ( make_list ( tmp [ 14 ] ) ) ) ) , make_list ( tmp [ 11 ] ) ) ) , lf5 ( make_list ( tmp [ 9 ] ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 22 ] ) ) ) ;
}
}
}
}
}
tmp [ 16 ] = ( constant1 ? constant1 : ( constant1 = ( * ef6 ) ( ) ) ) ;
if ( term_equal ( tmp [ 15 ] , tmp [ 16 ] ) ) {
tmp [ 17 ] = ( * ef7 ) ( tmp [ 12 ] ) ;
if ( ! term_equal ( arg0 , tmp [ 17 ] ) ) {
tmp [ 18 ] = lf_AUX_Rules2C_Aux12_2 ( arg0 , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 18 ] , ef1sym ) ) {
tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ;
tmp [ 20 ] = arg_1 ( tmp [ 18 ] ) ;
tmp [ 21 ] = arg_2 ( tmp [ 18 ] ) ;
if ( check_sym ( tmp [ 19 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 23 ] = arg_0 ( tmp [ 20 ] ) ;
if ( check_sym ( tmp [ 21 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 24 ] = arg_0 ( tmp [ 21 ] ) ;
return ( * ef1 ) ( lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 22 ] ) ) , lf_AUX_Rules2C_Aux12_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef3 ) ( tmp [ 12 ] , lf4 ( make_list ( tmp [ 14 ] ) ) ) ) , make_list ( tmp [ 11 ] ) ) ) , lf5 ( make_list ( tmp [ 9 ] ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 23 ] ) ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 24 ] ) ) ) ;
}
}
}
}
}
if ( term_equal ( ( * ef7 ) ( tmp [ 12 ] ) , arg0 ) ) {
tmp [ 17 ] = lf_AUX_Rules2C_Aux12_2 ( arg0 , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 17 ] , ef1sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ;
tmp [ 19 ] = arg_1 ( tmp [ 17 ] ) ;
tmp [ 20 ] = arg_2 ( tmp [ 17 ] ) ;
if ( check_sym ( tmp [ 18 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 18 ] ) ;
if ( check_sym ( tmp [ 19 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf_AUX_Rules2C_Aux12_1sym ) ) {
tmp [ 23 ] = arg_0 ( tmp [ 20 ] ) ;
return ( * ef1 ) ( lf_AUX_Rules2C_Aux12_1 ( cons ( make_list ( ( * ef2 ) ( lf3 ( cons ( make_list ( ( * ef3 ) ( tmp [ 12 ] , lf4 ( make_list ( tmp [ 14 ] ) ) ) ) , make_list ( tmp [ 11 ] ) ) ) , lf5 ( make_list ( tmp [ 9 ] ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 21 ] ) ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 22 ] ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( tmp [ 23 ] ) ) ) ;
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
return ( constant2 ? constant2 : ( constant2 = ( * ef1 ) ( lf_AUX_Rules2C_Aux12_1 ( make_list ( null ( ) ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( null ( ) ) ) , lf_AUX_Rules2C_Aux12_1 ( make_list ( null ( ) ) ) ) ) ) ;
}
}
}
return make_nf2 ( lf_AUX_Rules2C_Aux12_2sym , arg0 , arg1 ) ;
}
}
ATerm lf_AUX_Rules2C_Aux12_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux12_1 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux12_1sym , arg0 ) ;
}
ATerm lf5 ( ATerm arg0 ) {
PROF ( prof_lf5 ) ;
return make_nf1 ( lf5sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}

