#include  "support.h"
static Symbol lf_AUX_Goto_Earley2_1sym ;
static ATerm lf_AUX_Goto_Earley2_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Goto_Earley2 ( ) {
lf_AUX_Goto_Earley2_1sym = ATmakeSymbol ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"top-sort\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_Earley2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"top-sort\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Goto_Earley2_1 , lf_AUX_Goto_Earley2_1sym ) ;
}
void resolve_AUX_Goto_Earley2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<Start>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-Syntax\"),w(\"\"),[ql(\"<Start>\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Goto_Earley2 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Goto_Earley2_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Goto_Earley2_1sym , ATmakeAppl ( lf_AUX_Goto_Earley2_1sym , arg0 ) ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Goto_Earley2_1sym , arg0 ) ) ;
}

