#include  "asc-support.h"
static Symbol lf_AUX_Character_Class_Normalization3_1sym ;
static ATerm lf_AUX_Character_Class_Normalization3_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Character_Class_Normalization3 ( ) {
lf_AUX_Character_Class_Normalization3_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Normalization\"),w(\"\"),[l(\"head\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Normalization3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Normalization\"),w(\"\"),[l(\"head\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Normalization3_1 , lf_AUX_Character_Class_Normalization3_1sym ) ;
}
void resolve_AUX_Character_Class_Normalization3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\"),w(\"\"),sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\"),w(\"\"),sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Character_Class_Normalization3 ( ) {
}
ATerm lf_AUX_Character_Class_Normalization3_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Character_Class_Normalization3_1sym , ATmakeAppl ( lf_AUX_Character_Class_Normalization3_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
FUNC_EXIT ( atmp00 ) ;
}
}
if ( check_sym ( arg0 , ef2sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef1sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
FUNC_EXIT ( atmp000 ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Character_Class_Normalization3_1sym , arg0 ) ) ;
}

