#include  "asc-support.h"
static Symbol lf_AUX_First_CFG5_1sym ;
static ATerm lf_AUX_First_CFG5_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_First_CFG5 ( ) {
lf_AUX_First_CFG5_1sym = ATmakeSymbol ( "prod(id(\"First-CFG\"),w(\"\"),[l(\"first-table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_First_CFG5_1sym ) ;
register_prod ( ATparse ( "prod(id(\"First-CFG\"),w(\"\"),[l(\"first-table\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_First_CFG5_1 , lf_AUX_First_CFG5_1sym ) ;
}
void resolve_AUX_First_CFG5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"First-CFG\"),w(\"\"),[l(\"first-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"First-CFG\"),w(\"\"),[l(\"first-table\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_First_CFG5 ( ) {
}
ATerm lf_AUX_First_CFG5_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_First_CFG5_1sym , ATmakeAppl ( lf_AUX_First_CFG5_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( arg0 ) ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_First_CFG5_1sym , arg0 ) ) ;
}

