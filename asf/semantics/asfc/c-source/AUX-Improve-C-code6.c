#include  "support.h"
static Symbol lf_AUX_Improve_C_code6_1sym ;
static ATerm lf_AUX_Improve_C_code6_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef25sym ;
static funcptr ef25 ;
static Symbol ef26sym ;
static funcptr ef26 ;
static Symbol ef27sym ;
static funcptr ef27 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef28sym ;
static funcptr ef28 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Improve_C_code6 ( ) {
lf_AUX_Improve_C_code6_1sym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"improve-stat\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SE-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code6_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Statement\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"improve-stat\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SE-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code6_1 , lf_AUX_Improve_C_code6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Statement\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Improve_C_code6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SE-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SE-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"filter\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"given\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"filter\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\"given\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expressions-pair\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"new-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SE-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"new-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SE-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"improve-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"improve-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"improve-while-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"improve-while-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[sort(\"Argument-expression-list\"),w(\"\"),ql(\"(+)\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[sort(\"Argument-expression-list\"),w(\"\"),ql(\"(+)\"),w(\"\"),sort(\"Argument-expression-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"used-in-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"used-in-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"improve-decls\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DE-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"improve-decls\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DE-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DE-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DE-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef28 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef28sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_Improve_C_code6 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_Improve_C_code6_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 41 ] ;
FUNC_ENTRY ( lf_AUX_Improve_C_code6_1sym , ATmakeAppl ( lf_AUX_Improve_C_code6_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , ef4sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
if ( check_sym ( atmp00000 , ef5sym ) ) {
{
ATerm atmp000000 = arg_0 ( atmp00000 ) ;
if ( check_sym ( atmp000000 , ef6sym ) ) {
{
ATerm atmp0000000 = arg_0 ( atmp000000 ) ;
if ( check_sym ( atmp0000000 , lf2sym ) ) {
{
ATerm atmp00000000 = arg_0 ( atmp0000000 ) ;
{
ATerm atmp00001 = arg_1 ( atmp0000 ) ;
if ( check_sym ( atmp00001 , ef7sym ) ) {
{
ATerm atmp000010 = arg_0 ( atmp00001 ) ;
if ( check_sym ( atmp000010 , lf3sym ) ) {
{
ATerm atmp0000100 = arg_0 ( atmp000010 ) ;
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp00000000 ) ) {
tmp [ 0 ] = list_head ( atmp00000000 ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 70 ) ) ) {
tmp [ 1 ] = list_tail ( atmp00000000 ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = list_head ( tmp [ 1 ] ) ;
if ( term_equal ( tmp [ 2 ] , make_char ( 85 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 1 ] ) ;
{
if ( not_empty_list ( tmp [ 3 ] ) ) {
tmp [ 4 ] = list_head ( tmp [ 3 ] ) ;
if ( term_equal ( tmp [ 4 ] , make_char ( 78 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 3 ] ) ;
{
if ( not_empty_list ( tmp [ 5 ] ) ) {
tmp [ 6 ] = list_head ( tmp [ 5 ] ) ;
if ( term_equal ( tmp [ 6 ] , make_char ( 67 ) ) ) {
tmp [ 7 ] = list_tail ( tmp [ 5 ] ) ;
{
if ( not_empty_list ( tmp [ 7 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 7 ] ) ;
if ( term_equal ( tmp [ 8 ] , make_char ( 95 ) ) ) {
tmp [ 9 ] = list_tail ( tmp [ 7 ] ) ;
{
if ( not_empty_list ( tmp [ 9 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 9 ] ) ;
if ( term_equal ( tmp [ 10 ] , make_char ( 69 ) ) ) {
tmp [ 11 ] = list_tail ( tmp [ 9 ] ) ;
{
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 12 ] = list_head ( tmp [ 11 ] ) ;
if ( term_equal ( tmp [ 12 ] , make_char ( 88 ) ) ) {
tmp [ 13 ] = list_tail ( tmp [ 11 ] ) ;
{
if ( not_empty_list ( tmp [ 13 ] ) ) {
tmp [ 14 ] = list_head ( tmp [ 13 ] ) ;
if ( term_equal ( tmp [ 14 ] , make_char ( 73 ) ) ) {
tmp [ 15 ] = list_tail ( tmp [ 13 ] ) ;
{
if ( is_single_element ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 84 ) ) ) {
if ( is_single_element ( atmp0000100 ) ) {
tmp [ 16 ] = list_head ( atmp0000100 ) ;
tmp [ 17 ] = ( * ef11 ) ( tmp [ 16 ] , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ;
if ( check_sym ( tmp [ 17 ] , ef12sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ;
tmp [ 19 ] = arg_1 ( tmp [ 17 ] ) ;
if ( check_sym ( tmp [ 18 ] , ef7sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 18 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf3sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ;
if ( check_sym ( tmp [ 19 ] , ef7sym ) ) {
tmp [ 22 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 22 ] , lf3sym ) ) {
tmp [ 23 ] = arg_0 ( tmp [ 22 ] ) ;
tmp [ 24 ] = ( * ef13 ) ( ( * ef7 ) ( lf3 ( make_list ( tmp [ 21 ] ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp100 ) ) ) ) ;
if ( check_sym ( tmp [ 24 ] , ef8sym ) ) {
tmp [ 25 ] = arg_0 ( tmp [ 24 ] ) ;
tmp [ 26 ] = arg_1 ( tmp [ 24 ] ) ;
if ( check_sym ( tmp [ 26 ] , ef7sym ) ) {
tmp [ 27 ] = arg_0 ( tmp [ 26 ] ) ;
if ( check_sym ( tmp [ 27 ] , lf3sym ) ) {
tmp [ 28 ] = arg_0 ( tmp [ 27 ] ) ;
tmp [ 29 ] = ( * ef14 ) ( tmp [ 25 ] , ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef5 ) ( ( * ef6 ) ( lf2 ( cons ( make_list ( make_char ( 70 ) ) , cons ( make_list ( make_char ( 85 ) ) , cons ( make_list ( make_char ( 78 ) ) , cons ( make_list ( make_char ( 67 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 69 ) ) , cons ( make_list ( make_char ( 88 ) ) , cons ( make_list ( make_char ( 73 ) ) , make_list ( make_char ( 84 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( tmp [ 16 ] ) ) ) ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 29 ] , ef9sym ) ) {
tmp [ 30 ] = arg_0 ( tmp [ 29 ] ) ;
if ( check_sym ( tmp [ 30 ] , ef10sym ) ) {
tmp [ 31 ] = arg_0 ( tmp [ 30 ] ) ;
if ( check_sym ( tmp [ 31 ] , lf4sym ) ) {
tmp [ 32 ] = arg_0 ( tmp [ 31 ] ) ;
if ( not_empty_list ( tmp [ 32 ] ) ) {
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 32 ] ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ) ;
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
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 84 ) ) ) {
tmp [ 16 ] = list_tail ( tmp [ 15 ] ) ;
if ( not_empty_list ( tmp [ 16 ] ) ) {
if ( term_equal ( list_head ( tmp [ 16 ] ) , make_char ( 95 ) ) ) {
tmp [ 17 ] = list_tail ( tmp [ 16 ] ) ;
if ( not_empty_list ( tmp [ 17 ] ) ) {
if ( term_equal ( list_head ( tmp [ 17 ] ) , make_char ( 67 ) ) ) {
tmp [ 18 ] = list_tail ( tmp [ 17 ] ) ;
if ( not_empty_list ( tmp [ 18 ] ) ) {
if ( term_equal ( list_head ( tmp [ 18 ] ) , make_char ( 79 ) ) ) {
tmp [ 19 ] = list_tail ( tmp [ 18 ] ) ;
if ( not_empty_list ( tmp [ 19 ] ) ) {
if ( term_equal ( list_head ( tmp [ 19 ] ) , make_char ( 78 ) ) ) {
tmp [ 20 ] = list_tail ( tmp [ 19 ] ) ;
if ( not_empty_list ( tmp [ 20 ] ) ) {
if ( term_equal ( list_head ( tmp [ 20 ] ) , make_char ( 83 ) ) ) {
tmp [ 21 ] = list_tail ( tmp [ 20 ] ) ;
if ( is_single_element ( tmp [ 21 ] ) ) {
if ( term_equal ( list_head ( tmp [ 21 ] ) , make_char ( 84 ) ) ) {
if ( not_empty_list ( atmp0000100 ) ) {
tmp [ 22 ] = list_head ( atmp0000100 ) ;
tmp [ 23 ] = list_tail ( atmp0000100 ) ;
if ( is_single_element ( tmp [ 23 ] ) ) {
tmp [ 24 ] = list_head ( tmp [ 23 ] ) ;
tmp [ 25 ] = ( * ef11 ) ( tmp [ 24 ] , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ;
if ( check_sym ( tmp [ 25 ] , ef12sym ) ) {
tmp [ 26 ] = arg_0 ( tmp [ 25 ] ) ;
tmp [ 27 ] = arg_1 ( tmp [ 25 ] ) ;
if ( check_sym ( tmp [ 26 ] , ef7sym ) ) {
tmp [ 28 ] = arg_0 ( tmp [ 26 ] ) ;
if ( check_sym ( tmp [ 28 ] , lf3sym ) ) {
tmp [ 29 ] = arg_0 ( tmp [ 28 ] ) ;
if ( check_sym ( tmp [ 27 ] , ef7sym ) ) {
tmp [ 30 ] = arg_0 ( tmp [ 27 ] ) ;
if ( check_sym ( tmp [ 30 ] , lf3sym ) ) {
tmp [ 31 ] = arg_0 ( tmp [ 30 ] ) ;
tmp [ 32 ] = ( * ef13 ) ( ( * ef7 ) ( lf3 ( make_list ( tmp [ 29 ] ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp100 ) ) ) ) ;
if ( check_sym ( tmp [ 32 ] , ef8sym ) ) {
tmp [ 33 ] = arg_0 ( tmp [ 32 ] ) ;
tmp [ 34 ] = arg_1 ( tmp [ 32 ] ) ;
if ( check_sym ( tmp [ 34 ] , ef7sym ) ) {
tmp [ 35 ] = arg_0 ( tmp [ 34 ] ) ;
if ( check_sym ( tmp [ 35 ] , lf3sym ) ) {
tmp [ 36 ] = arg_0 ( tmp [ 35 ] ) ;
tmp [ 37 ] = ( * ef14 ) ( tmp [ 33 ] , ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef5 ) ( ( * ef6 ) ( lf2 ( cons ( make_list ( make_char ( 70 ) ) , cons ( make_list ( make_char ( 85 ) ) , cons ( make_list ( make_char ( 78 ) ) , cons ( make_list ( make_char ( 67 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 69 ) ) , cons ( make_list ( make_char ( 88 ) ) , cons ( make_list ( make_char ( 73 ) ) , cons ( make_list ( make_char ( 84 ) ) , cons ( make_list ( make_char ( 95 ) ) , cons ( make_list ( make_char ( 67 ) ) , cons ( make_list ( make_char ( 79 ) ) , cons ( make_list ( make_char ( 78 ) ) , cons ( make_list ( make_char ( 83 ) ) , make_list ( make_char ( 84 ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) , ( * ef7 ) ( lf3 ( cons ( make_list ( tmp [ 22 ] ) , make_list ( tmp [ 24 ] ) ) ) ) ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 37 ] , ef9sym ) ) {
tmp [ 38 ] = arg_0 ( tmp [ 37 ] ) ;
if ( check_sym ( tmp [ 38 ] , ef10sym ) ) {
tmp [ 39 ] = arg_0 ( tmp [ 38 ] ) ;
if ( check_sym ( tmp [ 39 ] , lf4sym ) ) {
tmp [ 40 ] = arg_0 ( tmp [ 39 ] ) ;
if ( not_empty_list ( tmp [ 40 ] ) ) {
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 40 ] ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ) ;
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
}
}
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef22sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
tmp [ 0 ] = arg_0 ( atmp10 ) ;
{
ATerm atmp10010 ;
ATerm atmp1000 [ 2 ] ;
atmp1000 [ 0 ] = tmp [ 0 ] ;
atmp1000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp10010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( term_equal ( atmp000 , atmp10010 ) ) {
tmp [ 1 ] = ( * ef10 ) ( lf4 ( make_list ( arg0 ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef10sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) ) ) , ( * ef23 ) ( ( * ef7 ) ( lf3 ( make_list ( atmp000 ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
atmp1000 [ 1 ] = list_tail ( atmp1000 [ 1 ] ) ;
tmp [ 0 ] = atmp1000 [ 1 ] ;
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
if ( check_sym ( arg0 , ef15sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef16sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef17sym ) ) {
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef9sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef10sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , lf4sym ) ) {
{
ATerm atmp011000 = arg_0 ( atmp01100 ) ;
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp011000 ) ) {
tmp [ 0 ] = ( * ef18 ) ( ( * ef10 ) ( lf4 ( make_list ( atmp011000 ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef9sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef10sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
tmp [ 4 ] = ( * ef10 ) ( lf4 ( make_list ( ( * ef15 ) ( atmp00 , ( * ef16 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef17 ) ( ) ) ) , ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef10sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 6 ] ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef19sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef16sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef17sym ) ) {
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef9sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef10sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , lf4sym ) ) {
{
ATerm atmp011000 = arg_0 ( atmp01100 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef16sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
if ( check_sym ( atmp020 , ef17sym ) ) {
{
ATerm atmp021 = arg_1 ( atmp02 ) ;
if ( check_sym ( atmp021 , ef9sym ) ) {
{
ATerm atmp0210 = arg_0 ( atmp021 ) ;
if ( check_sym ( atmp0210 , ef10sym ) ) {
{
ATerm atmp02100 = arg_0 ( atmp0210 ) ;
if ( check_sym ( atmp02100 , lf4sym ) ) {
{
ATerm atmp021000 = arg_0 ( atmp02100 ) ;
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp011000 ) ) {
if ( not_empty_list ( atmp021000 ) ) {
tmp [ 0 ] = ( * ef18 ) ( ( * ef10 ) ( lf4 ( make_list ( atmp011000 ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef9sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef10sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
tmp [ 4 ] = ( * ef18 ) ( ( * ef10 ) ( lf4 ( make_list ( atmp021000 ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef9sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef10sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf4sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
tmp [ 8 ] = ( * ef10 ) ( lf4 ( make_list ( ( * ef19 ) ( atmp00 , ( * ef16 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef17 ) ( ) ) ) , ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) ) ) ) , ( * ef16 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef17 ) ( ) ) ) , ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 7 ] ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 8 ] , ef10sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf4sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 10 ] ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ) ;
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
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef20sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef16sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef17sym ) ) {
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef9sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef10sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , lf4sym ) ) {
{
ATerm atmp011000 = arg_0 ( atmp01100 ) ;
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp011000 ) ) {
tmp [ 0 ] = ( * ef21 ) ( ( * ef10 ) ( lf4 ( make_list ( atmp011000 ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp100 ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef9sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef10sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
tmp [ 4 ] = ( * ef10 ) ( lf4 ( make_list ( ( * ef20 ) ( atmp00 , ( * ef16 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef17 ) ( ) ) ) , ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 3 ] ) ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 4 ] , ef10sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf4sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 6 ] ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef16sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef9sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef10sym ) ) {
{
ATerm atmp0100 = arg_0 ( atmp010 ) ;
if ( check_sym ( atmp0100 , lf4sym ) ) {
{
ATerm atmp01000 = arg_0 ( atmp0100 ) ;
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp01000 ) ) {
tmp [ 0 ] = ( * ef25 ) ( ( * ef10 ) ( lf4 ( make_list ( atmp01000 ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef7sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , lf3sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 3 ] = ( * ef26 ) ( atmp00 , ( * ef7 ) ( lf3 ( make_list ( tmp [ 2 ] ) ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef27sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef7sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf3sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
tmp [ 8 ] = ( * ef18 ) ( ( * ef10 ) ( lf4 ( make_list ( atmp01000 ) ) ) , ( * ef23 ) ( ( * ef23 ) ( ( * ef7 ) ( lf3 ( make_list ( atmp100 ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( tmp [ 7 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 8 ] , ef9sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , ef10sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf4sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
tmp [ 12 ] = ( * ef10 ) ( lf4 ( make_list ( ( * ef16 ) ( tmp [ 4 ] , ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 11 ] ) ) ) ) ) ) ) ) ;
if ( check_sym ( tmp [ 12 ] , ef10sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 13 ] , lf4sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
if ( not_empty_list ( tmp [ 14 ] ) ) {
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( tmp [ 14 ] ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef28sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
tmp [ 0 ] = lf_AUX_Improve_C_code6_1 ( atmp01 , ( * ef7 ) ( lf3 ( make_list ( atmp100 ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef8sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef9sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef10sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf4sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef7sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf3sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( is_single_element ( tmp [ 5 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 5 ] ) ;
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( ( * ef28 ) ( atmp00 , tmp [ 8 ] ) ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( tmp [ 7 ] ) ) ) ) ) ;
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
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
FUNC_EXIT ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf4 ( make_list ( arg0 ) ) ) ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ) ;
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef22sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( check_sym ( arg1 , ef7sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef7sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
FUNC_EXIT ( ( * ef8 ) ( ( * ef24 ) ( ) , ( * ef7 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf3 ( lf_AUX_Improve_C_code6_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

