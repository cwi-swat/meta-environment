#include  "support.h"
static Symbol lf_AUX_IntCon3_1sym ;
static ATerm lf_AUX_IntCon3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_IntCon3 ( ) {
lf_AUX_IntCon3_1sym = ATmakeSymbol ( "prod(id(\"IntCon\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_IntCon3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"IntCon\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) , lf_AUX_IntCon3_1 , lf_AUX_IntCon3_1sym ) ;
}
void resolve_AUX_IntCon3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_IntCon3 ( ) {
}
ATerm lf_AUX_IntCon3_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_IntCon3_1sym , ATmakeAppl ( lf_AUX_IntCon3_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( arg0 ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_IntCon3_1sym , arg0 ) ) ;
}

