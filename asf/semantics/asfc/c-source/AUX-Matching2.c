#include "support.h"
static Symbol lf_AUX_Matching2_1sym;
static ATerm lf_AUX_Matching2_1( ATerm arg1);
static Symbol lf_AUX_Matching2_2sym;
static ATerm lf_AUX_Matching2_2( );
void register_AUX_Matching2( ) {
lf_AUX_Matching2_1sym= ATmakeSymbol( "prod(id(\"Matching\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Matching2_1sym);
lf_AUX_Matching2_2sym= ATmakeSymbol( "prod(id(\"Matching\"),w(\"\"),[l(\"nomatch\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Matching2_2sym);
register_prod( ATparse( "prod(id(\"Matching\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)") , lf_AUX_Matching2_1 , lf_AUX_Matching2_1sym);
register_prod( ATparse( "prod(id(\"Matching\"),w(\"\"),[l(\"nomatch\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)") , lf_AUX_Matching2_2 , lf_AUX_Matching2_2sym);
}
void resolve_AUX_Matching2( ) {
}
void init_AUX_Matching2( ) {
}
ATerm lf_AUX_Matching2_2( ) {
PROF( prof_lf_AUX_Matching2_2);
return make_nf0( lf_AUX_Matching2_2sym);
}
ATerm lf_AUX_Matching2_1( ATerm arg0) {
PROF( prof_lf_AUX_Matching2_1);
return make_nf1( lf_AUX_Matching2_1sym , arg0);
}

