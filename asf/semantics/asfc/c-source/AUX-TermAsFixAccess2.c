#include  "asc-support.h"
static Symbol lf_AUX_TermAsFixAccess2_1sym ;
static ATerm lf_AUX_TermAsFixAccess2_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_TermAsFixAccess2 ( ) {
lf_AUX_TermAsFixAccess2_1sym = ATmakeSymbol ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"remove-annotation\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFixAccess2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"remove-annotation\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFixAccess2_1 , lf_AUX_TermAsFixAccess2_1sym ) ;
}
void resolve_AUX_TermAsFixAccess2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_TermAsFixAccess2 ( ) {
}
ATerm lf_AUX_TermAsFixAccess2_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_TermAsFixAccess2_1sym , ATmakeAppl ( lf_AUX_TermAsFixAccess2_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( arg0 ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_TermAsFixAccess2_1sym , arg0 ) ) ;
}

