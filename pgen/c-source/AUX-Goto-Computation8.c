#include  "asc-support.h"
static Symbol lf_AUX_Goto_Computation8_1sym ;
static ATerm lf_AUX_Goto_Computation8_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_Goto_Computation8 ( ) {
lf_AUX_Goto_Computation8_1sym = ATmakeSymbol ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"outgoing\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_Computation8_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"outgoing\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Goto_Computation8_1 , lf_AUX_Goto_Computation8_1sym ) ;
}
void resolve_AUX_Goto_Computation8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"trans-labels\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"trans-labels\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"predicted\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"predicted\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Goto_Computation8 ( ) {
}
ATerm lf_AUX_Goto_Computation8_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Goto_Computation8_1sym , ATmakeAppl ( lf_AUX_Goto_Computation8_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef2 ) ( arg0 , ( * ef3 ) ( arg0 , atmp10 ) ) ) ;
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Goto_Computation8_1sym , arg0 , arg1 ) ) ;
}

