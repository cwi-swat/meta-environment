#include  "support.h"
static Symbol lf_AUX_CC_Sdf_ATerms3_1sym ;
static ATerm lf_AUX_CC_Sdf_ATerms3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_CC_Sdf_ATerms3 ( ) {
lf_AUX_CC_Sdf_ATerms3_1sym = ATmakeSymbol ( "prod(id(\"CC-Sdf-ATerms\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Character\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_CC_Sdf_ATerms3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"CC-Sdf-ATerms\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Character\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) , lf_AUX_CC_Sdf_ATerms3_1 , lf_AUX_CC_Sdf_ATerms3_1sym ) ;
}
void resolve_AUX_CC_Sdf_ATerms3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Arithmetic\"),w(\"\"),[l(\"int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Character\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Arithmetic\"),w(\"\"),[l(\"int\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Character\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_CC_Sdf_ATerms3 ( ) {
}
ATerm lf_AUX_CC_Sdf_ATerms3_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_CC_Sdf_ATerms3_1sym , ATmakeAppl ( lf_AUX_CC_Sdf_ATerms3_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( arg0 ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_CC_Sdf_ATerms3_1sym , arg0 ) ) ;
}

