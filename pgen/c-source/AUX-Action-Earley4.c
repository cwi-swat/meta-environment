#include  "asc-support.h"
static Symbol lf_AUX_Action_Earley4_1sym ;
static ATerm lf_AUX_Action_Earley4_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
void register_AUX_Action_Earley4 ( ) {
lf_AUX_Action_Earley4_1sym = ATmakeSymbol ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"init-labels\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Action_Earley4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Action-Earley\"),w(\"\"),[l(\"init-labels\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Action_Earley4_1 , lf_AUX_Action_Earley4_1sym ) ;
}
void resolve_AUX_Action_Earley4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"init-labels\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Action-PCC\"),w(\"\"),[l(\"init-labels\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Arithmetic\"),w(\"\"),[l(\"int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Character\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Arithmetic\"),w(\"\"),[l(\"int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Character\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Syntax\"),w(\"\"),[ql(\"\\\\\\\\LABEL_START\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Syntax\"),w(\"\"),[ql(\"\\\\\\\\LABEL_START\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Action_Earley4 ( ) {
}
ATerm lf_AUX_Action_Earley4_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Action_Earley4_1sym , ATmakeAppl ( lf_AUX_Action_Earley4_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( arg0 ) , ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ( * ef6 ) ( ) ) ) ) ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Action_Earley4_1sym , arg0 ) ) ;
}

