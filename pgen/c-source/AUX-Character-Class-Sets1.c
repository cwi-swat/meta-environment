#include  "asc-support.h"
static Symbol lf_AUX_Character_Class_Sets1_1sym ;
static ATerm lf_AUX_Character_Class_Sets1_1 ( ATerm arg1 ) ;
void register_AUX_Character_Class_Sets1 ( ) {
lf_AUX_Character_Class_Sets1_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Sets1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Character_Class_Sets1_1 , lf_AUX_Character_Class_Sets1_1sym ) ;
}
void resolve_AUX_Character_Class_Sets1 ( ) {
}
void init_AUX_Character_Class_Sets1 ( ) {
}
ATerm lf_AUX_Character_Class_Sets1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Character_Class_Sets1_1sym , ATmakeAppl ( lf_AUX_Character_Class_Sets1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Character_Class_Sets1_1sym , arg0 ) ) ;
}

