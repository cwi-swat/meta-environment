#include  "asc-support.h"
static Symbol lf_AUX_Action_Earley6_1sym ;
static ATerm lf_AUX_Action_Earley6_1 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_Action_Earley6 ( ) {
lf_AUX_Action_Earley6_1sym = ATmakeSymbol ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter-follow\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_Earley6_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter-follow\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Action_Earley6_1 , lf_AUX_Action_Earley6_1sym ) ;
}
void resolve_AUX_Action_Earley6 ( ) {
}
void init_AUX_Action_Earley6 ( ) {
}
ATerm lf_AUX_Action_Earley6_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Action_Earley6_1sym , ATmakeAppl ( lf_AUX_Action_Earley6_1sym , arg0 , arg1 ) ) ;
FUNC_EXIT ( arg1 ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_Action_Earley6_1sym , arg0 , arg1 ) ) ;
}

