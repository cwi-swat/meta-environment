#include  "support.h"
static Symbol lf_AUX_Restrictions_Sdf_Normalization1_1sym ;
static ATerm lf_AUX_Restrictions_Sdf_Normalization1_1 ( ATerm arg1 ) ;
void register_AUX_Restrictions_Sdf_Normalization1 ( ) {
lf_AUX_Restrictions_Sdf_Normalization1_1sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Normalization\"),w(\"\"),[l(\"head\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Normalization1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Normalization\"),w(\"\"),[l(\"head\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Normalization1_1 , lf_AUX_Restrictions_Sdf_Normalization1_1sym ) ;
}
void resolve_AUX_Restrictions_Sdf_Normalization1 ( ) {
}
void init_AUX_Restrictions_Sdf_Normalization1 ( ) {
}
ATerm lf_AUX_Restrictions_Sdf_Normalization1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Normalization1_1sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Normalization1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Normalization1_1sym , arg0 ) ) ;
}

