#include  "support.h"
static Symbol lf_AUX_ParseTrees5_1sym ;
static ATerm lf_AUX_ParseTrees5_1 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef9sym ;
static funcptr ef9 ;
void register_AUX_ParseTrees5 ( ) {
lf_AUX_ParseTrees5_1sym = ATmakeSymbol ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTrees5_1sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTrees5_1 , lf_AUX_ParseTrees5_1sym ) ;
}
void resolve_AUX_ParseTrees5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_ParseTrees5 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_ParseTrees5_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_ParseTrees5_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( check_sym ( atmp001 , ef2sym ) ) {
{
ATerm atmp0010 = arg_0 ( atmp001 ) ;
if ( check_sym ( atmp0010 , ef3sym ) ) {
{
ATerm atmp00100 = arg_0 ( atmp0010 ) ;
if ( check_sym ( atmp00100 , ef4sym ) ) {
{
ATerm atmp00101 = arg_1 ( atmp0010 ) ;
if ( check_sym ( atmp00101 , ef5sym ) ) {
{
ATerm atmp001010 = arg_0 ( atmp00101 ) ;
if ( check_sym ( atmp001010 , ef6sym ) ) {
{
ATerm atmp0010100 = arg_0 ( atmp001010 ) ;
if ( check_sym ( atmp0010100 , ef7sym ) ) {
{
ATerm atmp00101000 = arg_0 ( atmp0010100 ) ;
{
ATerm atmp0011 = arg_1 ( atmp001 ) ;
if ( check_sym ( atmp0011 , ef2sym ) ) {
{
ATerm atmp00110 = arg_0 ( atmp0011 ) ;
if ( check_sym ( atmp00110 , ef3sym ) ) {
{
ATerm atmp001100 = arg_0 ( atmp00110 ) ;
if ( check_sym ( atmp001100 , ef8sym ) ) {
{
ATerm atmp001101 = arg_1 ( atmp00110 ) ;
if ( check_sym ( atmp001101 , ef5sym ) ) {
{
ATerm atmp0011010 = arg_0 ( atmp001101 ) ;
if ( check_sym ( atmp0011010 , ef6sym ) ) {
{
ATerm atmp00110100 = arg_0 ( atmp0011010 ) ;
if ( check_sym ( atmp00110100 , ef7sym ) ) {
{
ATerm atmp001101000 = arg_0 ( atmp00110100 ) ;
{
ATerm atmp00111 = arg_1 ( atmp0011 ) ;
if ( check_sym ( atmp00111 , ef2sym ) ) {
{
ATerm atmp001110 = arg_0 ( atmp00111 ) ;
if ( check_sym ( atmp001110 , ef3sym ) ) {
{
ATerm atmp0011100 = arg_0 ( atmp001110 ) ;
if ( check_sym ( atmp0011100 , ef4sym ) ) {
{
ATerm atmp0011101 = arg_1 ( atmp001110 ) ;
if ( check_sym ( atmp0011101 , ef5sym ) ) {
{
ATerm atmp00111010 = arg_0 ( atmp0011101 ) ;
if ( check_sym ( atmp00111010 , ef6sym ) ) {
{
ATerm atmp001110100 = arg_0 ( atmp00111010 ) ;
if ( check_sym ( atmp001110100 , ef7sym ) ) {
{
ATerm atmp0011101000 = arg_0 ( atmp001110100 ) ;
{
ATerm atmp001111 = arg_1 ( atmp00111 ) ;
return ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) , ( * ef5 ) ( ( * ef6 ) ( ( * ef7 ) ( atmp00101000 ) ) ) ) , ( * ef2 ) ( ( * ef3 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef8 ) ( ) ) ) , ( * ef5 ) ( ( * ef6 ) ( ( * ef7 ) ( atmp001101000 ) ) ) ) , ( * ef2 ) ( ( * ef3 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) , ( * ef5 ) ( ( * ef6 ) ( ( * ef7 ) ( atmp0011101000 ) ) ) ) , atmp001111 ) ) ) ) ;
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
if ( check_sym ( atmp00 , ef5sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
return ( constant2 ? constant2 : ( constant2 = ( * ef9 ) ( ) ) ) ;
}
}
}
}
}
return make_nf1 ( lf_AUX_ParseTrees5_1sym , arg0 ) ;
}

