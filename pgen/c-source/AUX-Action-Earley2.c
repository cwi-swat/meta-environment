#include  "support.h"
static Symbol lf_AUX_Action_Earley2_1sym ;
static ATerm lf_AUX_Action_Earley2_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Action_Earley2 ( ) {
lf_AUX_Action_Earley2_1sym = ATmakeSymbol ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"shifts\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_Earley2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"shifts\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Action_Earley2_1 , lf_AUX_Action_Earley2_1sym ) ;
}
void resolve_AUX_Action_Earley2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"nm-shifts\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"nm-shifts\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Action_Earley2 ( ) {
}
ATerm lf_AUX_Action_Earley2_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Action_Earley2_1sym , ATmakeAppl ( lf_AUX_Action_Earley2_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( arg0 ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Action_Earley2_1sym , arg0 ) ) ;
}

