#include  "asc-support.h"
static Symbol lf_AUX_Action_Earley5_1sym ;
static ATerm lf_AUX_Action_Earley5_1 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_Action_Earley5 ( ) {
lf_AUX_Action_Earley5_1sym = ATmakeSymbol ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_Earley5_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Action_Earley5_1 , lf_AUX_Action_Earley5_1sym ) ;
}
void resolve_AUX_Action_Earley5 ( ) {
}
void init_AUX_Action_Earley5 ( ) {
}
ATerm lf_AUX_Action_Earley5_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Action_Earley5_1sym , ATmakeAppl ( lf_AUX_Action_Earley5_1sym , arg0 , arg1 ) ) ;
FUNC_EXIT ( arg1 ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_Action_Earley5_1sym , arg0 , arg1 ) ) ;
}

