#include  "asc-support.h"
static Symbol lf_AUX_Substitution5_1sym ;
static ATerm lf_AUX_Substitution5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
void register_AUX_Substitution5 ( ) {
lf_AUX_Substitution5_1sym = ATmakeSymbol ( "prod(id(\"Substitution\"),w(\"\"),[l(\"substitute\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Substitution5_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Substitution\"),w(\"\"),[l(\"substitute\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_Substitution5_1 , lf_AUX_Substitution5_1sym ) ;
}
void resolve_AUX_Substitution5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Substitution\"),w(\"\"),[l(\"value\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Substitution\"),w(\"\"),[l(\"value\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"aterms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"aterms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"atermlist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"atermlist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Substitution5 ( ) {
}
ATerm lf_AUX_Substitution5_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_Substitution5_1sym , ATmakeAppl ( lf_AUX_Substitution5_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
FUNC_EXIT ( ( * ef2 ) ( atmp00 , arg1 ) ) ;
}
}
if ( check_sym ( arg0 , ef3sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
FUNC_EXIT ( ( * ef3 ) ( atmp00 , ( * ef4 ) ( lf_AUX_Substitution5_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp01 ) ) , arg1 ) ) ) ) ;
}
}
}
if ( check_sym ( arg0 , ef5sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef7sym ) ) {
FUNC_EXIT ( arg0 ) ;
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef6sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
FUNC_EXIT ( ( * ef5 ) ( ( * ef8 ) ( ( * ef6 ) ( ( * ef9 ) ( lf_AUX_Substitution5_1 ( ( * ef10 ) ( ( * ef6 ) ( atmp000 ) ) , arg1 ) ) ) , ( * ef11 ) ( lf_AUX_Substitution5_1 ( ( * ef5 ) ( ( * ef12 ) ( ( * ef6 ) ( atmp000 ) ) ) , arg1 ) ) ) ) ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef13sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef14sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
( tmp [ 0 ] = lf_AUX_Substitution5_1 ( ( * ef15 ) ( atmp00 ) , arg1 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef15sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = ( * ef4 ) ( lf_AUX_Substitution5_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp010 ) ) , arg1 ) ) ) ;
FUNC_EXIT ( ( * ef13 ) ( tmp [ 1 ] , ( * ef14 ) ( tmp [ 2 ] ) ) ) ;
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
if ( check_sym ( atmp01 , ef14sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
( tmp [ 0 ] = lf_AUX_Substitution5_1 ( ( * ef17 ) ( atmp00 ) , arg1 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef17sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = ( * ef4 ) ( lf_AUX_Substitution5_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp010 ) ) , arg1 ) ) ) ;
FUNC_EXIT ( ( * ef16 ) ( tmp [ 1 ] , ( * ef14 ) ( tmp [ 2 ] ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( arg0 , ef18sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef14sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
( tmp [ 0 ] = lf_AUX_Substitution5_1 ( ( * ef3 ) ( atmp00 , atmp01 ) , arg1 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = ( * ef4 ) ( lf_AUX_Substitution5_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp020 ) ) , arg1 ) ) ) ;
FUNC_EXIT ( ( * ef18 ) ( tmp [ 1 ] , tmp [ 2 ] , ( * ef14 ) ( tmp [ 3 ] ) ) ) ;
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
if ( check_sym ( atmp01 , ef14sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
( tmp [ 0 ] = lf_AUX_Substitution5_1 ( ( * ef5 ) ( atmp00 ) , arg1 ) ) ;
if ( check_sym ( tmp [ 0 ] , ef5sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = ( * ef4 ) ( lf_AUX_Substitution5_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp010 ) ) , arg1 ) ) ) ;
FUNC_EXIT ( ( * ef19 ) ( tmp [ 1 ] , ( * ef14 ) ( tmp [ 2 ] ) ) ) ;
}
}
}
}
}
}
FUNC_EXIT ( arg0 ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_Substitution5_1sym , arg0 , arg1 ) ) ;
}
}

