#include  "asc-support.h"
static Symbol lf_AUX_Character_Class_Syntax8_1sym ;
static ATerm lf_AUX_Character_Class_Syntax8_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_Character_Class_Syntax8 ( ) {
lf_AUX_Character_Class_Syntax8_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Syntax8_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Character_Class_Syntax8_1 , lf_AUX_Character_Class_Syntax8_1sym ) ;
}
void resolve_AUX_Character_Class_Syntax8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\"),w(\"\"),sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\"),w(\"\"),sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Character_Class_Syntax8 ( ) {
}
ATerm lf_AUX_Character_Class_Syntax8_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Character_Class_Syntax8_1sym , ATmakeAppl ( lf_AUX_Character_Class_Syntax8_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
FUNC_EXIT ( arg1 ) ;
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef3sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef3sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef3 ) ( ( * ef4 ) ( atmp000 , atmp100 ) ) ) ) ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
FUNC_EXIT ( arg0 ) ;
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Character_Class_Syntax8_1sym , arg0 , arg1 ) ) ;
}

