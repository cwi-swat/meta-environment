#include  "support.h"
static Symbol lf_AUX_Basic_Integers1_1sym ;
static ATerm lf_AUX_Basic_Integers1_1 ( ATerm arg1 ) ;
void register_AUX_Basic_Integers1 ( ) {
lf_AUX_Basic_Integers1_1sym = ATmakeSymbol ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Basic_Integers1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) , lf_AUX_Basic_Integers1_1 , lf_AUX_Basic_Integers1_1sym ) ;
}
void resolve_AUX_Basic_Integers1 ( ) {
}
void init_AUX_Basic_Integers1 ( ) {
}
ATerm lf_AUX_Basic_Integers1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Basic_Integers1_1sym , ATmakeAppl ( lf_AUX_Basic_Integers1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Basic_Integers1_1sym , arg0 ) ) ;
}

