#include  "support.h"
static Symbol lf_AUX_Character_Class_Normalization2_1sym ;
static ATerm lf_AUX_Character_Class_Normalization2_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Character_Class_Normalization2 ( ) {
lf_AUX_Character_Class_Normalization2_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Normalization\"),w(\"\"),[l(\"if\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"delaying2\"),w(\"\"),sep(\",\"),w(\"\"),l(\"delaying3\")],w(\"\"),l(\"}\")))"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Normalization2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Normalization\"),w(\"\"),[l(\"if\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"delaying2\"),w(\"\"),sep(\",\"),w(\"\"),l(\"delaying3\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Character_Class_Normalization2_1 , lf_AUX_Character_Class_Normalization2_1sym ) ;
}
void resolve_AUX_Character_Class_Normalization2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Character_Class_Normalization2 ( ) {
}
ATerm lf_AUX_Character_Class_Normalization2_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
FUNC_ENTRY ( lf_AUX_Character_Class_Normalization2_1sym , ATmakeAppl ( lf_AUX_Character_Class_Normalization2_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
FUNC_EXIT ( unquote ( arg1 ) ) ;
}
if ( check_sym ( arg0 , ef2sym ) ) {
FUNC_EXIT ( unquote ( arg2 ) ) ;
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Character_Class_Normalization2_1sym , arg0 , arg1 , arg2 ) ) ;
}

