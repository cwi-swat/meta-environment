#include  "support.h"
static Symbol lf_AUX_Modular_Sdf_ATerms1_1sym ;
static ATerm lf_AUX_Modular_Sdf_ATerms1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_ATerms1_2sym ;
static ATerm lf_AUX_Modular_Sdf_ATerms1_2 ( ATerm arg1 ) ;
void register_AUX_Modular_Sdf_ATerms1 ( ) {
lf_AUX_Modular_Sdf_ATerms1_1sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-ATerms\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_ATerms1_1sym ) ;
lf_AUX_Modular_Sdf_ATerms1_2sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-ATerms\"),w(\"\"),[l(\"atermlist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Sections\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_ATerms1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-ATerms\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_ATerms1_1 , lf_AUX_Modular_Sdf_ATerms1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-ATerms\"),w(\"\"),[l(\"atermlist\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Sections\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_ATerms1_2 , lf_AUX_Modular_Sdf_ATerms1_2sym ) ;
}
void resolve_AUX_Modular_Sdf_ATerms1 ( ) {
}
void init_AUX_Modular_Sdf_ATerms1 ( ) {
}
ATerm lf_AUX_Modular_Sdf_ATerms1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_ATerms1_2sym , ATmakeAppl ( lf_AUX_Modular_Sdf_ATerms1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_ATerms1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_ATerms1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_ATerms1_1sym , ATmakeAppl ( lf_AUX_Modular_Sdf_ATerms1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_ATerms1_1sym , arg0 ) ) ;
}

