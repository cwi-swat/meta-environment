#include  "asc-support.h"
static Symbol lf_AUX_Character_Class_Syntax4_1sym ;
static ATerm lf_AUX_Character_Class_Syntax4_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_Character_Class_Syntax4 ( ) {
lf_AUX_Character_Class_Syntax4_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Syntax4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Syntax4_1 , lf_AUX_Character_Class_Syntax4_1sym ) ;
}
void resolve_AUX_Character_Class_Syntax4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Normalization\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Normalization\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Character_Class_Syntax4 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Character_Class_Syntax4_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Character_Class_Syntax4_1sym , ATmakeAppl ( lf_AUX_Character_Class_Syntax4_1sym , arg0 ) ) ;
{
ATerm ltmp [ 1 ] ;
lbl_lf_AUX_Character_Class_Syntax4_1 : ltmp [ 0 ] = arg0 ;
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
arg0 = ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) ;
goto lbl_lf_AUX_Character_Class_Syntax4_1 ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Character_Class_Syntax4_1sym , ltmp [ 0 ] ) ) ;
}
}

