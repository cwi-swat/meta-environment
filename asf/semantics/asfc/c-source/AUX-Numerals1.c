#include "support.h"
static Symbol lf_AUX_Numerals1_1sym;
static ATerm lf_AUX_Numerals1_1( );
static Symbol lf_AUX_Numerals1_2sym;
static ATerm lf_AUX_Numerals1_2( ATerm arg1);
void register_AUX_Numerals1( ) {
lf_AUX_Numerals1_1sym= ATmakeSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Numerals1_1sym);
lf_AUX_Numerals1_2sym= ATmakeSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Numerals1_2sym);
register_prod( ATparse( "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals1_1 , lf_AUX_Numerals1_1sym);
register_prod( ATparse( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals1_2 , lf_AUX_Numerals1_2sym);
}
void resolve_AUX_Numerals1( ) {
}
void init_AUX_Numerals1( ) {
}
ATerm lf_AUX_Numerals1_2( ATerm arg0) {
PROF( prof_lf_AUX_Numerals1_2);
return make_nf1( lf_AUX_Numerals1_2sym , arg0);
}
ATerm lf_AUX_Numerals1_1( ) {
PROF( prof_lf_AUX_Numerals1_1);
return make_nf0( lf_AUX_Numerals1_1sym);
}

