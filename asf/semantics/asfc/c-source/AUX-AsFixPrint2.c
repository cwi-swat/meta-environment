#include  "asc-support.h"
static Symbol lf_AUX_AsFixPrint2_1sym ;
static ATerm lf_AUX_AsFixPrint2_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_AsFixPrint2 ( ) {
lf_AUX_AsFixPrint2_1sym = ATmakeSymbol ( "prod(id(\"AsFixPrint\"),w(\"\"),[l(\"nws-print\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFixPrint2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFixPrint\"),w(\"\"),[l(\"nws-print\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFixPrint2_1 , lf_AUX_AsFixPrint2_1sym ) ;
}
void resolve_AUX_AsFixPrint2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATermPrint\"),w(\"\"),[l(\"print\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATermPrint\"),w(\"\"),[l(\"print\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"RemAsFixWspace\"),w(\"\"),[l(\"change-all-ws\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"RemAsFixWspace\"),w(\"\"),[l(\"change-all-ws\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_AsFixPrint2 ( ) {
}
ATerm lf_AUX_AsFixPrint2_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_AsFixPrint2_1sym , ATmakeAppl ( lf_AUX_AsFixPrint2_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( arg0 ) ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_AsFixPrint2_1sym , arg0 ) ) ;
}

