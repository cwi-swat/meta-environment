#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Conds2C4_3sym ;
static ATerm lf_AUX_MuASF_Conds2C4_3 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf_AUX_MuASF_Conds2C4_1sym ;
static ATerm lf_AUX_MuASF_Conds2C4_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_MuASF_Conds2C4_2sym ;
static ATerm lf_AUX_MuASF_Conds2C4_2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol lf7sym ;
static ATerm lf7 ( ATerm arg1 ) ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef17sym ;
static funcptr ef17 ;
void register_AUX_MuASF_Conds2C4 ( ) {
lf_AUX_MuASF_Conds2C4_3sym = ATmakeSymbol ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Conds2C4_3sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf_AUX_MuASF_Conds2C4_1sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Conds2C4_1sym ) ;
lf_AUX_MuASF_Conds2C4_2sym = ATmakeSymbol ( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Conds2C4_2sym ) ;
lf7sym = ATmakeSymbol ( "listtype(sort(\"Statement\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf7sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_MuASF_Conds2C4_1 , lf_AUX_MuASF_Conds2C4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"NamePair\"),ql(\",\"))" ) , lf_AUX_MuASF_Conds2C4_2 , lf_AUX_MuASF_Conds2C4_2sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Conds2C4_3 , lf_AUX_MuASF_Conds2C4_3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf6 , lf6sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Statement\"))" ) , lf7 , lf7sym ) ;
}
void resolve_AUX_MuASF_Conds2C4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"celookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"celookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"assign-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"assign-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"make-c-temp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"term2carg\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_MuASF_Conds2C4 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_MuASF_Conds2C4_3 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 28 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Conds2C4_3sym , ATmakeAppl ( lf_AUX_MuASF_Conds2C4_3sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , lf_AUX_MuASF_Conds2C4_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , lf_AUX_MuASF_Conds2C4_2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
{
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
{
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 0 ] ) ) ;
( tmp [ 5 ] = arg_3 ( tmp [ 0 ] ) ) ;
( tmp [ 6 ] = arg_4 ( tmp [ 0 ] ) ) ;
( tmp [ 7 ] = arg_5 ( tmp [ 0 ] ) ) ;
{
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 2 ] ) ) ;
{
if ( check_sym ( tmp [ 3 ] , lf5sym ) ) {
( tmp [ 9 ] = arg_0 ( tmp [ 3 ] ) ) ;
{
if ( not_empty_list ( tmp [ 9 ] ) ) {
( tmp [ 10 ] = list_head ( tmp [ 9 ] ) ) ;
{
( tmp [ 11 ] = list_tail ( tmp [ 9 ] ) ) ;
{
if ( check_sym ( tmp [ 10 ] , ef2sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 10 ] ) ) ;
( tmp [ 13 ] = arg_1 ( tmp [ 10 ] ) ) ;
( tmp [ 14 ] = ( * ef4 ) ( tmp [ 12 ] ) ) ;
if ( term_equal ( tmp [ 14 ] , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ) ) ) ) ) {
( tmp [ 15 ] = ( * ef6 ) ( tmp [ 12 ] , tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 15 ] , ef7sym ) ) {
( tmp [ 16 ] = arg_0 ( tmp [ 15 ] ) ) ;
( tmp [ 17 ] = ( * ef8 ) ( lf_AUX_MuASF_Conds2C4_1 ( cons ( make_list ( ( * ef1 ) ( lf4 ( make_list ( tmp [ 8 ] ) ) , lf5 ( cons ( make_list ( ( * ef2 ) ( tmp [ 12 ] , tmp [ 13 ] ) ) , make_list ( tmp [ 11 ] ) ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 1 ] ) ) ) , lf_AUX_MuASF_Conds2C4_1 ( make_list ( null ( ) ) ) , lf_AUX_MuASF_Conds2C4_2 ( make_list ( atmp10 ) ) , arg2 , tmp [ 16 ] ) ) ;
if ( check_sym ( tmp [ 17 ] , ef3sym ) ) {
( tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ) ;
( tmp [ 19 ] = arg_1 ( tmp [ 17 ] ) ) ;
FUNC_EXIT ( ( * ef3 ) ( tmp [ 18 ] , tmp [ 19 ] ) ) ;
}
}
}
if ( term_equal ( tmp [ 14 ] , ( constant1 ? constant1 : ( constant1 = ( * ef9 ) ( ) ) ) ) ) {
( tmp [ 15 ] = ( * ef10 ) ( ( * ef11 ) ( ( * ef12 ) ( arg2 ) ) ) ) ;
( tmp [ 16 ] = ( * ef13 ) ( ( * ef9 ) ( ) , tmp [ 12 ] , tmp [ 5 ] , tmp [ 6 ] , ( * ef14 ) ( arg2 ) , tmp [ 15 ] , tmp [ 7 ] , lf_AUX_MuASF_Conds2C4_2 ( make_list ( atmp10 ) ) ) ) ;
if ( check_sym ( tmp [ 16 ] , ef15sym ) ) {
( tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ) ;
( tmp [ 18 ] = arg_1 ( tmp [ 16 ] ) ) ;
( tmp [ 19 ] = arg_2 ( tmp [ 16 ] ) ) ;
if ( check_sym ( tmp [ 17 ] , ef16sym ) ) {
( tmp [ 20 ] = arg_0 ( tmp [ 17 ] ) ) ;
if ( check_sym ( tmp [ 20 ] , lf6sym ) ) {
( tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ) ;
if ( is_single_element ( tmp [ 21 ] ) ) {
( tmp [ 22 ] = list_head ( tmp [ 21 ] ) ) ;
( tmp [ 23 ] = ( * ef8 ) ( lf_AUX_MuASF_Conds2C4_1 ( cons ( make_list ( ( * ef1 ) ( lf4 ( make_list ( tmp [ 8 ] ) ) , lf5 ( cons ( make_list ( ( * ef2 ) ( tmp [ 12 ] , tmp [ 13 ] ) ) , make_list ( tmp [ 11 ] ) ) ) , tmp [ 4 ] , tmp [ 5 ] , tmp [ 6 ] , tmp [ 7 ] ) ) , make_list ( tmp [ 1 ] ) ) ) , lf_AUX_MuASF_Conds2C4_1 ( make_list ( null ( ) ) ) , lf_AUX_MuASF_Conds2C4_2 ( make_list ( atmp10 ) ) , tmp [ 19 ] , tmp [ 15 ] ) ) ;
if ( check_sym ( tmp [ 23 ] , ef3sym ) ) {
( tmp [ 24 ] = arg_0 ( tmp [ 23 ] ) ) ;
( tmp [ 25 ] = arg_1 ( tmp [ 23 ] ) ) ;
( tmp [ 26 ] = ( * ef17 ) ( tmp [ 18 ] , ( * ef18 ) ( ( * ef19 ) ( lf7 ( make_list ( ( * ef20 ) ( ( * ef21 ) ( tmp [ 15 ] , tmp [ 22 ] ) ) ) ) ) ) ) ) ;
( tmp [ 27 ] = ( * ef17 ) ( tmp [ 26 ] , tmp [ 24 ] ) ) ;
FUNC_EXIT ( ( * ef3 ) ( tmp [ 27 ] , tmp [ 25 ] ) ) ;
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
FUNC_EXIT ( make_nf3 ( lf_AUX_MuASF_Conds2C4_3sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf7 ( ATerm arg0 ) {
CONS_ENTRY ( lf7sym , ATmakeAppl ( lf7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf7sym , arg0 ) ) ;
}
ATerm lf_AUX_MuASF_Conds2C4_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Conds2C4_2sym , ATmakeAppl ( lf_AUX_MuASF_Conds2C4_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Conds2C4_2sym , arg0 ) ) ;
}
ATerm lf_AUX_MuASF_Conds2C4_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Conds2C4_1sym , ATmakeAppl ( lf_AUX_MuASF_Conds2C4_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Conds2C4_1sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf6 ( ATerm arg0 ) {
CONS_ENTRY ( lf6sym , ATmakeAppl ( lf6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf6sym , arg0 ) ) ;
}

