#include  "asc-support.h"
static Symbol lf_AUX_Rules2C_Aux3_1sym ;
static ATerm lf_AUX_Rules2C_Aux3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol lf7sym ;
static ATerm lf7 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux3 ( ) {
lf_AUX_Rules2C_Aux3_1sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux3_1sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"IntCon\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf7sym = ATmakeSymbol ( "listtype(sort(\"TE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf7sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"make-c-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux3_1 , lf_AUX_Rules2C_Aux3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"IntCon\"),ql(\",\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf6 , lf6sym ) ;
register_prod ( ATparse ( "listtype(sort(\"TE-pair\"),ql(\",\"))" ) , lf7 , lf7sym ) ;
}
void resolve_AUX_Rules2C_Aux3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"code-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"code-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"funargs2cexp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"funargs2cexp\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Rules2C_Aux3 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Rules2C_Aux3_1 ( ATerm arg0 ) {
{
ATerm tmp [ 10 ] ;
FUNC_ENTRY ( lf_AUX_Rules2C_Aux3_1sym , ATmakeAppl ( lf_AUX_Rules2C_Aux3_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
( tmp [ 0 ] = ( * ef3 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef4 ) ( atmp00 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef5sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
( tmp [ 4 ] = ( * ef6 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) , lf5 ( make_list ( ( * ef7 ) ( ( * ef8 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef9sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , ef10sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf2sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = ( * ef11 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) , ( * ef7 ) ( ( * ef8 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 8 ] ) ) , lf3 ( make_list ( null ( ) ) ) , atmp01 , tmp [ 6 ] , tmp [ 9 ] , tmp [ 0 ] ) ) ;
}
}
}
}
}
}
if ( term_equal ( ( * ef4 ) ( atmp00 ) , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( lf4 ( make_list ( null ( ) ) ) ) ) ) ) ) {
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) , lf3 ( make_list ( null ( ) ) ) , atmp01 , ( * ef12 ) ( lf7 ( make_list ( null ( ) ) ) ) , ( * ef12 ) ( lf7 ( make_list ( null ( ) ) ) ) , tmp [ 0 ] ) ) ;
}
}
}
}
if ( check_sym ( arg0 , ef13sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef14sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
( tmp [ 0 ] = ( * ef3 ) ( atmp01 ) ) ;
( tmp [ 1 ] = ( * ef4 ) ( atmp01 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef5sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
( tmp [ 4 ] = ( * ef6 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) , lf5 ( make_list ( ( * ef7 ) ( ( * ef8 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef9sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , ef10sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf2sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = ( * ef11 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) , ( * ef7 ) ( ( * ef8 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 8 ] ) ) , lf3 ( make_list ( atmp0000 ) ) , atmp02 , tmp [ 6 ] , tmp [ 9 ] , tmp [ 0 ] ) ) ;
}
}
}
}
}
}
if ( term_equal ( ( * ef4 ) ( atmp01 ) , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( lf4 ( make_list ( null ( ) ) ) ) ) ) ) ) {
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) , lf3 ( make_list ( atmp0000 ) ) , atmp02 , ( * ef12 ) ( lf7 ( make_list ( null ( ) ) ) ) , ( * ef12 ) ( lf7 ( make_list ( null ( ) ) ) ) , tmp [ 0 ] ) ) ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef15sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
( tmp [ 0 ] = ( * ef3 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef4 ) ( atmp00 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef5sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
( tmp [ 4 ] = ( * ef6 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) , lf5 ( make_list ( ( * ef7 ) ( ( * ef8 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef9sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , ef10sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf2sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = ( * ef11 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) , ( * ef7 ) ( ( * ef8 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 8 ] ) ) , lf3 ( make_list ( null ( ) ) ) , atmp01 , tmp [ 6 ] , tmp [ 9 ] , tmp [ 0 ] ) ) ;
}
}
}
}
}
}
if ( term_equal ( ( * ef4 ) ( atmp00 ) , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( lf4 ( make_list ( null ( ) ) ) ) ) ) ) ) {
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) , lf3 ( make_list ( null ( ) ) ) , atmp01 , ( * ef12 ) ( lf7 ( make_list ( null ( ) ) ) ) , ( * ef12 ) ( lf7 ( make_list ( null ( ) ) ) ) , tmp [ 0 ] ) ) ;
}
}
}
}
if ( check_sym ( arg0 , ef16sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef14sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
( tmp [ 0 ] = ( * ef3 ) ( atmp01 ) ) ;
( tmp [ 1 ] = ( * ef4 ) ( atmp01 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef5sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
( tmp [ 4 ] = ( * ef6 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) , lf5 ( make_list ( ( * ef7 ) ( ( * ef8 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef9sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ) ;
if ( check_sym ( tmp [ 5 ] , ef10sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf2sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = ( * ef11 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) , ( * ef7 ) ( ( * ef8 ) ( lf6 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 8 ] ) ) , lf3 ( make_list ( atmp0000 ) ) , atmp02 , tmp [ 6 ] , tmp [ 9 ] , tmp [ 0 ] ) ) ;
}
}
}
}
}
}
if ( term_equal ( ( * ef4 ) ( atmp01 ) , ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( lf4 ( make_list ( null ( ) ) ) ) ) ) ) ) {
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) , lf3 ( make_list ( atmp0000 ) ) , atmp02 , ( * ef12 ) ( lf7 ( make_list ( null ( ) ) ) ) , ( * ef12 ) ( lf7 ( make_list ( null ( ) ) ) ) , tmp [ 0 ] ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Rules2C_Aux3_1sym , arg0 ) ) ;
}
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf7 ( ATerm arg0 ) {
CONS_ENTRY ( lf7sym , ATmakeAppl ( lf7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf7sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf6 ( ATerm arg0 ) {
CONS_ENTRY ( lf6sym , ATmakeAppl ( lf6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf6sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}

