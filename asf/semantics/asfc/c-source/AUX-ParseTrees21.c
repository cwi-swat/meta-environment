#include  "support.h"
static Symbol lf_AUX_ParseTrees21_1sym ;
static ATerm lf_AUX_ParseTrees21_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef10sym ;
static funcptr ef10 ;
void register_AUX_ParseTrees21 ( ) {
lf_AUX_ParseTrees21_1sym = ATmakeSymbol ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"pp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ParseTrees21_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"pp\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) , lf_AUX_ParseTrees21_1 , lf_AUX_ParseTrees21_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_ParseTrees21 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Literals\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Literals\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_ParseTrees21 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_ParseTrees21_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_ParseTrees21_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
return atmp000 ;
}
}
}
}
if ( check_sym ( arg0 , ef3sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef4sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
return lf_AUX_ParseTrees21_1 ( atmp010 ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef5sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef6sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef7sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp0001 = arg_1 ( atmp000 ) ;
return ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( atmp0000 ) , lf_AUX_ParseTrees21_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp0001 ) ) ) ) ;
}
}
}
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef4sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
return lf_AUX_ParseTrees21_1 ( atmp0000 ) ;
}
}
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef9sym ) ) {
return ( constant0 ? constant0 : ( constant0 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ;
}
}
}
}
if ( check_sym ( arg0 , ef11sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef12sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
return ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( ( * ef13 ) ( atmp00 ) ) , ( * ef8 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 34 ] ) ) ) ) ) , ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp010 ) ) ) , ( constant2 ? constant2 : ( constant2 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef14sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef12sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
return ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( ( * ef1 ) ( atmp00 ) ) , ( * ef8 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 34 ] ) ) ) ) ) , ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp010 ) ) ) , ( constant2 ? constant2 : ( constant2 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ;
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
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef12sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
return ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( ( * ef3 ) ( atmp00 , atmp01 ) ) , ( * ef8 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 34 ] ) ) ) ) ) , ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp020 ) ) ) , ( constant2 ? constant2 : ( constant2 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ;
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
if ( check_sym ( atmp01 , ef12sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
return ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( ( * ef5 ) ( atmp00 ) ) , ( * ef8 ) ( ( constant1 ? constant1 : ( constant1 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 123 ] , char_table [ 34 ] ) ) ) ) ) , ( * ef8 ) ( lf_AUX_ParseTrees21_1 ( ( * ef5 ) ( ( * ef6 ) ( atmp010 ) ) ) , ( constant2 ? constant2 : ( constant2 = ( * ef10 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 125 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ;
}
}
}
}
}
return make_nf1 ( lf_AUX_ParseTrees21_1sym , arg0 ) ;
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}

