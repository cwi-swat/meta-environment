#include  "support.h"
static Symbol lf_AUX_AsFix_Basics8_1sym ;
static ATerm lf_AUX_AsFix_Basics8_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
void register_AUX_AsFix_Basics8 ( ) {
lf_AUX_AsFix_Basics8_1sym = ATmakeSymbol ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-attribute\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix_Basics8_1sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"is-attribute\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix_Basics8_1 , lf_AUX_AsFix_Basics8_1sym ) ;
}
void resolve_AUX_AsFix_Basics8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"get-itersep-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"get-itersep-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_AsFix_Basics8 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_AsFix_Basics8_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 3 ] ;
FUNC_ENTRY ( lf_AUX_AsFix_Basics8_1sym , ATmakeAppl ( lf_AUX_AsFix_Basics8_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( ) ) ;
}
tmp [ 0 ] = ( constant1 ? constant1 : ( constant1 = ( * ef1 ) ( ) ) ) ;
if ( ! term_equal ( arg0 , tmp [ 0 ] ) ) {
tmp [ 1 ] = ( * ef4 ) ( arg0 ) ;
if ( term_equal ( tmp [ 1 ] , arg1 ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef3 ) ( ) ) ;
}
else {
tmp [ 2 ] = ( * ef5 ) ( arg0 ) ;
FUNC_EXIT ( lf_AUX_AsFix_Basics8_1 ( tmp [ 2 ] , arg1 ) ) ;
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_AsFix_Basics8_1sym , arg0 , arg1 ) ) ;
}
}

