#include  "support.h"
static Symbol lf_AUX_Action_PCC1_1sym ;
static ATerm lf_AUX_Action_PCC1_1 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_Action_PCC1 ( ) {
lf_AUX_Action_PCC1_1sym = ATmakeSymbol ( "prod(id(\"Action-PCC\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CC-LA\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_PCC1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-PCC\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CC-LA\"),w(\"\"),no-attrs)" ) , lf_AUX_Action_PCC1_1 , lf_AUX_Action_PCC1_1sym ) ;
}
void resolve_AUX_Action_PCC1 ( ) {
}
void init_AUX_Action_PCC1 ( ) {
}
ATerm lf_AUX_Action_PCC1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Action_PCC1_1sym , ATmakeAppl ( lf_AUX_Action_PCC1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Action_PCC1_1sym , arg0 , arg1 ) ) ;
}

