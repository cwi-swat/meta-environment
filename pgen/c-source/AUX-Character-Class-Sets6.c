#include  "asc-support.h"
static Symbol lf_AUX_Character_Class_Sets6_1sym ;
static ATerm lf_AUX_Character_Class_Sets6_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Character_Class_Sets6 ( ) {
lf_AUX_Character_Class_Sets6_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Sets6_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CharClass\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Class_Sets6_1 , lf_AUX_Character_Class_Sets6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CharClass\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Character_Class_Sets6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"CharClass\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"CharClass\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"/\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"/\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Character_Class_Sets6 ( ) {
}
ATerm lf_AUX_Character_Class_Sets6_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Character_Class_Sets6_1sym , ATmakeAppl ( lf_AUX_Character_Class_Sets6_1sym , arg0 , arg1 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef1 ) ( ( * ef2 ) ( arg0 , ( * ef3 ) ( lf2 ( make_list ( arg1 ) ) ) ) , ( * ef4 ) ( arg0 , ( * ef3 ) ( lf2 ( make_list ( arg1 ) ) ) ) ) , ( * ef4 ) ( ( * ef3 ) ( lf2 ( make_list ( arg1 ) ) ) , arg0 ) ) ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_Character_Class_Sets6_1sym , arg0 , arg1 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

