#include  "support.h"
static Symbol lf_AUX_RealCon1_1sym ;
static ATerm lf_AUX_RealCon1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_RealCon1_2sym ;
static ATerm lf_AUX_RealCon1_2 ( ) ;
static Symbol lf_AUX_RealCon1_3sym ;
static ATerm lf_AUX_RealCon1_3 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
void register_AUX_RealCon1 ( ) {
lf_AUX_RealCon1_1sym = ATmakeSymbol ( "prod(id(\"RealCon\"),w(\"\"),[ql(\"e\"),w(\"\"),sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptExp\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RealCon1_1sym ) ;
lf_AUX_RealCon1_2sym = ATmakeSymbol ( "prod(id(\"RealCon\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptExp\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RealCon1_2sym ) ;
lf_AUX_RealCon1_3sym = ATmakeSymbol ( "prod(id(\"RealCon\"),w(\"\"),[sort(\"IntCon\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"NatCon\"),w(\"\"),sort(\"OptExp\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RealCon\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RealCon1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"RealCon\"),w(\"\"),[ql(\"e\"),w(\"\"),sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptExp\"),w(\"\"),no-attrs)" ) , lf_AUX_RealCon1_1 , lf_AUX_RealCon1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"RealCon\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptExp\"),w(\"\"),no-attrs)" ) , lf_AUX_RealCon1_2 , lf_AUX_RealCon1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"RealCon\"),w(\"\"),[sort(\"IntCon\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"NatCon\"),w(\"\"),sort(\"OptExp\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RealCon\"),w(\"\"),no-attrs)" ) , lf_AUX_RealCon1_3 , lf_AUX_RealCon1_3sym ) ;
}
void resolve_AUX_RealCon1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_RealCon1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_RealCon1_3 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_RealCon1_3sym , ATmakeAppl ( lf_AUX_RealCon1_3sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_RealCon1_3sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_RealCon1_2 ( ) {
CONS_ENTRY ( lf_AUX_RealCon1_2sym , ATmakeAppl0 ( lf_AUX_RealCon1_2sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_RealCon1_2sym ) ) ;
}
ATerm lf_AUX_RealCon1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_RealCon1_1sym , ATmakeAppl ( lf_AUX_RealCon1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_RealCon1_1sym , arg0 ) ) ;
}

