#include  "support.h"
static Symbol lf_AUX_Priority_Sdf_Normalization3_1sym ;
static ATerm lf_AUX_Priority_Sdf_Normalization3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Priority_Sdf_Normalization3 ( ) {
lf_AUX_Priority_Sdf_Normalization3_1sym = ATmakeSymbol ( "prod(id(\"Priority-Sdf-Normalization\"),w(\"\"),[ql(\"assoc\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Priority_Sdf_Normalization3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Priority-Sdf-Normalization\"),w(\"\"),[ql(\"assoc\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) , lf_AUX_Priority_Sdf_Normalization3_1 , lf_AUX_Priority_Sdf_Normalization3_1sym ) ;
}
void resolve_AUX_Priority_Sdf_Normalization3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Priority-Sdf-Normalization\"),w(\"\"),[ql(\"assoc\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Priority-Sdf-Normalization\"),w(\"\"),[ql(\"assoc\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Priorities\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Priority_Sdf_Normalization3 ( ) {
}
ATerm lf_AUX_Priority_Sdf_Normalization3_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Priority_Sdf_Normalization3_1sym , ATmakeAppl ( lf_AUX_Priority_Sdf_Normalization3_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( arg0 ) ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Priority_Sdf_Normalization3_1sym , arg0 ) ) ;
}

