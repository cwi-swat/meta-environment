#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Basics29_1sym ;
static ATerm lf_AUX_MuASF_Basics29_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_MuASF_Basics29 ( ) {
lf_AUX_MuASF_Basics29_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Basics29_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Basics29_1 , lf_AUX_MuASF_Basics29_1sym ) ;
}
void resolve_AUX_MuASF_Basics29 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"deslashed-lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"deslashed-lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_MuASF_Basics29 ( ) {
}
ATerm lf_AUX_MuASF_Basics29_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_MuASF_Basics29_1sym , ATmakeAppl ( lf_AUX_MuASF_Basics29_1sym , arg0 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( arg0 ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_MuASF_Basics29_1sym , arg0 ) ) ;
}

