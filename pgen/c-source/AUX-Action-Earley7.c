#include  "asc-support.h"
static Symbol lf_AUX_Action_Earley7_1sym ;
static ATerm lf_AUX_Action_Earley7_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Action_Earley7 ( ) {
lf_AUX_Action_Earley7_1sym = ATmakeSymbol ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter-follow\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_Earley7_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter-follow\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Action_Earley7_1 , lf_AUX_Action_Earley7_1sym ) ;
}
void resolve_AUX_Action_Earley7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter-follow\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"filter-follow\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"follow-table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Follow-Earley\"),w(\"\"),[l(\"follow-table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Action_Earley7 ( ) {
}
ATerm lf_AUX_Action_Earley7_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Action_Earley7_1sym , ATmakeAppl ( lf_AUX_Action_Earley7_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( arg0 , ( * ef2 ) ( arg0 ) ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Action_Earley7_1sym , arg0 ) ) ;
}

