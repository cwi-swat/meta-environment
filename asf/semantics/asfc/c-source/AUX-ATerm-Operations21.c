#include  "asc-support.h"
static Symbol lf_AUX_ATerm_Operations21_1sym ;
static ATerm lf_AUX_ATerm_Operations21_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef14sym ;
static funcptr ef14 ;
void register_AUX_ATerm_Operations21 ( ) {
lf_AUX_ATerm_Operations21_1sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"@\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations21_1sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"@\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations21_1 , lf_AUX_ATerm_Operations21_1sym ) ;
}
void resolve_AUX_ATerm_Operations21 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"ann\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"ann\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[sort(\"ATerms\"),w(\"\"),ql(\"++a\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[sort(\"ATerms\"),w(\"\"),ql(\"++a\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_ATerm_Operations21 ( ) {
}
ATerm lf_AUX_ATerm_Operations21_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_ATerm_Operations21_1sym , ATmakeAppl ( lf_AUX_ATerm_Operations21_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef2sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( term_equal ( atmp00 , atmp10 ) ) {
FUNC_EXIT ( atmp00 ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef4sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef6 ) ( atmp00 , ( * ef7 ) ( atmp10 ) ) ) ;
}
}
}
}
if ( check_sym ( arg0 , ef8sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef9 ) ( atmp00 , ( * ef7 ) ( atmp10 ) ) ) ;
}
}
}
}
if ( check_sym ( arg0 , ef10sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef11 ) ( atmp00 , ( * ef7 ) ( atmp10 ) ) ) ;
}
}
}
}
if ( check_sym ( arg0 , ef12sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( arg1 , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef13 ) ( atmp00 , atmp01 , ( * ef7 ) ( atmp10 ) ) ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef6sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef7sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( arg1 , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef6 ) ( atmp00 , ( * ef7 ) ( ( * ef14 ) ( atmp010 , atmp10 ) ) ) ) ;
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
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef7sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( arg1 , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef9 ) ( atmp00 , ( * ef7 ) ( ( * ef14 ) ( atmp010 , atmp10 ) ) ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef11sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef7sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( arg1 , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef11 ) ( atmp00 , ( * ef7 ) ( ( * ef14 ) ( atmp010 , atmp10 ) ) ) ) ;
}
}
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
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef7sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
if ( check_sym ( arg1 , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef13 ) ( atmp00 , atmp01 , ( * ef7 ) ( ( * ef14 ) ( atmp020 , atmp10 ) ) ) ) ;
}
}
}
}
}
}
}
}
if ( check_sym ( arg1 , ef3sym ) ) {
FUNC_EXIT ( arg0 ) ;
}
FUNC_EXIT ( make_nf2 ( lf_AUX_ATerm_Operations21_1sym , arg0 , arg1 ) ) ;
}

