#include  "asc-support.h"
static Symbol lf_AUX_Integers_Extended3_1sym ;
static ATerm lf_AUX_Integers_Extended3_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_Integers_Extended3 ( ) {
lf_AUX_Integers_Extended3_1sym = ATmakeSymbol ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Integers_Extended3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Integers-Extended\"),w(\"\"),[l(\"gtr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) , lf_AUX_Integers_Extended3_1 , lf_AUX_Integers_Extended3_1sym ) ;
}
void resolve_AUX_Integers_Extended3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\">\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\">\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Integers_Extended3 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Integers_Extended3_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 1 ] ;
FUNC_ENTRY ( lf_AUX_Integers_Extended3_1sym , ATmakeAppl ( lf_AUX_Integers_Extended3_1sym , arg0 , arg1 ) ) ;
( tmp [ 0 ] = ( * ef1 ) ( ( * ef2 ) ( arg0 ) , ( * ef2 ) ( arg1 ) ) ) ;
if ( term_equal ( tmp [ 0 ] , ( constant0 ? constant0 : ( constant0 = ( * ef3 ) ( ) ) ) ) ) {
FUNC_EXIT ( arg0 ) ;
}
if ( term_equal ( tmp [ 0 ] , ( constant1 ? constant1 : ( constant1 = ( * ef4 ) ( ) ) ) ) ) {
FUNC_EXIT ( arg1 ) ;
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Integers_Extended3_1sym , arg0 , arg1 ) ) ;
}
}

