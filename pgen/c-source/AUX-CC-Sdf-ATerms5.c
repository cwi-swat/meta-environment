#include  "asc-support.h"
static Symbol lf_AUX_CC_Sdf_ATerms5_1sym ;
static ATerm lf_AUX_CC_Sdf_ATerms5_1 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_CC_Sdf_ATerms5 ( ) {
lf_AUX_CC_Sdf_ATerms5_1sym = ATmakeSymbol ( "prod(id(\"CC-Sdf-ATerms\"),w(\"\"),[l(\"range\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_CC_Sdf_ATerms5_1sym ) ;
register_prod ( ATparse ( "prod(id(\"CC-Sdf-ATerms\"),w(\"\"),[l(\"range\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) , lf_AUX_CC_Sdf_ATerms5_1 , lf_AUX_CC_Sdf_ATerms5_1sym ) ;
}
void resolve_AUX_CC_Sdf_ATerms5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ACon\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ACon\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"CC-Sdf-ATerms\"),w(\"\"),[l(\"character\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"CC-Sdf-ATerms\"),w(\"\"),[l(\"character\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"CC-Sdf-Tree-Constructors\"),w(\"\"),[ql(\"range\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"CC-Sdf-Tree-Constructors\"),w(\"\"),[ql(\"range\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\"),w(\"\"),ql(\"-\"),w(\"\"),sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_CC_Sdf_ATerms5 ( ) {
}
ATerm lf_AUX_CC_Sdf_ATerms5_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_CC_Sdf_ATerms5_1sym , ATmakeAppl ( lf_AUX_CC_Sdf_ATerms5_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
FUNC_EXIT ( ( * ef4 ) ( ( * ef5 ) ( arg0 ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( arg0 , ef6sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef7sym ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef8sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef1sym ) ) {
{
ATerm atmp0100 = arg_0 ( atmp010 ) ;
if ( check_sym ( atmp0100 , ef2sym ) ) {
{
ATerm atmp01000 = arg_0 ( atmp0100 ) ;
if ( check_sym ( atmp01000 , ef3sym ) ) {
{
ATerm atmp010000 = arg_0 ( atmp01000 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef9sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef1sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , ef2sym ) ) {
{
ATerm atmp011000 = arg_0 ( atmp01100 ) ;
if ( check_sym ( atmp011000 , ef3sym ) ) {
{
ATerm atmp0110000 = arg_0 ( atmp011000 ) ;
FUNC_EXIT ( ( * ef10 ) ( ( * ef5 ) ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( atmp010000 ) ) ) ) , ( * ef5 ) ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( atmp0110000 ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_CC_Sdf_ATerms5_1sym , arg0 ) ) ;
}

