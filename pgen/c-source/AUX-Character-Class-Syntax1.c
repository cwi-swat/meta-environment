#include  "asc-support.h"
static Symbol lf_AUX_Character_Class_Syntax1_1sym ;
static ATerm lf_AUX_Character_Class_Syntax1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Character_Class_Syntax1_2sym ;
static ATerm lf_AUX_Character_Class_Syntax1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Character_Class_Syntax1_3sym ;
static ATerm lf_AUX_Character_Class_Syntax1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Character_Class_Syntax1_4sym ;
static ATerm lf_AUX_Character_Class_Syntax1_4 ( ) ;
static Symbol lf_AUX_Character_Class_Syntax1_5sym ;
static ATerm lf_AUX_Character_Class_Syntax1_5 ( ATerm arg1 ) ;
static Symbol lf_AUX_Character_Class_Syntax1_6sym ;
static ATerm lf_AUX_Character_Class_Syntax1_6 ( ATerm arg1 ) ;
void register_AUX_Character_Class_Syntax1 ( ) {
lf_AUX_Character_Class_Syntax1_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Syntax1_1sym ) ;
lf_AUX_Character_Class_Syntax1_2sym = ATmakeSymbol ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Syntax1_2sym ) ;
lf_AUX_Character_Class_Syntax1_3sym = ATmakeSymbol ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Syntax1_3sym ) ;
lf_AUX_Character_Class_Syntax1_4sym = ATmakeSymbol ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Syntax1_4sym ) ;
lf_AUX_Character_Class_Syntax1_5sym = ATmakeSymbol ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Syntax1_5sym ) ;
lf_AUX_Character_Class_Syntax1_6sym = ATmakeSymbol ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Syntax1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"Character\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRange\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Syntax1_1 , lf_AUX_Character_Class_Syntax1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRange\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Syntax1_2 , lf_AUX_Character_Class_Syntax1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharRanges\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Character_Class_Syntax1_3 , lf_AUX_Character_Class_Syntax1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Syntax1_4 , lf_AUX_Character_Class_Syntax1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharRanges\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Syntax1_5 , lf_AUX_Character_Class_Syntax1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Character_Class_Syntax1_6 , lf_AUX_Character_Class_Syntax1_6sym ) ;
}
void resolve_AUX_Character_Class_Syntax1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_Character_Class_Syntax1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Character_Class_Syntax1_6 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Character_Class_Syntax1_6sym , ATmakeAppl ( lf_AUX_Character_Class_Syntax1_6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Character_Class_Syntax1_6sym , arg0 ) ) ;
}
ATerm lf_AUX_Character_Class_Syntax1_5 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Character_Class_Syntax1_5sym , ATmakeAppl ( lf_AUX_Character_Class_Syntax1_5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Character_Class_Syntax1_5sym , arg0 ) ) ;
}
ATerm lf_AUX_Character_Class_Syntax1_4 ( ) {
CONS_ENTRY ( lf_AUX_Character_Class_Syntax1_4sym , ATmakeAppl0 ( lf_AUX_Character_Class_Syntax1_4sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Character_Class_Syntax1_4sym ) ) ;
}
ATerm lf_AUX_Character_Class_Syntax1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Character_Class_Syntax1_3sym , ATmakeAppl ( lf_AUX_Character_Class_Syntax1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Character_Class_Syntax1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Character_Class_Syntax1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Character_Class_Syntax1_2sym , ATmakeAppl ( lf_AUX_Character_Class_Syntax1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Character_Class_Syntax1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Character_Class_Syntax1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Character_Class_Syntax1_1sym , ATmakeAppl ( lf_AUX_Character_Class_Syntax1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Character_Class_Syntax1_1sym , arg0 ) ) ;
}

