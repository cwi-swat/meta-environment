#include  "asc-support.h"
static Symbol lf_AUX_ATerm_Operations18_1sym ;
static ATerm lf_AUX_ATerm_Operations18_1 ( ATerm arg1 ) ;
void register_AUX_ATerm_Operations18 ( ) {
lf_AUX_ATerm_Operations18_1sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"identity\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations18_1sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"identity\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations18_1 , lf_AUX_ATerm_Operations18_1sym ) ;
}
void resolve_AUX_ATerm_Operations18 ( ) {
}
void init_AUX_ATerm_Operations18 ( ) {
}
ATerm lf_AUX_ATerm_Operations18_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_ATerm_Operations18_1sym , ATmakeAppl ( lf_AUX_ATerm_Operations18_1sym , arg0 ) ) ;
FUNC_EXIT ( arg0 ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_ATerm_Operations18_1sym , arg0 ) ) ;
}

