#include  "asc-support.h"
static Symbol lf_AUX_First_CFG1_1sym ;
static ATerm lf_AUX_First_CFG1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_First_CFG1_2sym ;
static ATerm lf_AUX_First_CFG1_2 ( ) ;
void register_AUX_First_CFG1 ( ) {
lf_AUX_First_CFG1_1sym = ATmakeSymbol ( "prod(id(\"First-CFG\"),w(\"\"),[l(\"non-terminal\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_First_CFG1_1sym ) ;
lf_AUX_First_CFG1_2sym = ATmakeSymbol ( "prod(id(\"First-CFG\"),w(\"\"),[ql(\"'e\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_First_CFG1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"First-CFG\"),w(\"\"),[l(\"non-terminal\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_First_CFG1_1 , lf_AUX_First_CFG1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"First-CFG\"),w(\"\"),[ql(\"'e\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) , lf_AUX_First_CFG1_2 , lf_AUX_First_CFG1_2sym ) ;
}
void resolve_AUX_First_CFG1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_First_CFG1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_First_CFG1_2 ( ) {
CONS_ENTRY ( lf_AUX_First_CFG1_2sym , ATmakeAppl0 ( lf_AUX_First_CFG1_2sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_First_CFG1_2sym ) ) ;
}
ATerm lf_AUX_First_CFG1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_First_CFG1_1sym , ATmakeAppl ( lf_AUX_First_CFG1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_First_CFG1_1sym , arg0 , arg1 ) ) ;
}

