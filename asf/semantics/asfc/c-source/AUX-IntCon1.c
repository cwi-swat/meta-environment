#include  "support.h"
static Symbol lf_AUX_IntCon1_1sym ;
static ATerm lf_AUX_IntCon1_1 ( ATerm arg1 ) ;
void register_AUX_IntCon1 ( ) {
lf_AUX_IntCon1_1sym = ATmakeSymbol ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_IntCon1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) , lf_AUX_IntCon1_1 , lf_AUX_IntCon1_1sym ) ;
}
void resolve_AUX_IntCon1 ( ) {
}
void init_AUX_IntCon1 ( ) {
}
ATerm lf_AUX_IntCon1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_IntCon1_1sym , ATmakeAppl ( lf_AUX_IntCon1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_IntCon1_1sym , arg0 ) ) ;
}

