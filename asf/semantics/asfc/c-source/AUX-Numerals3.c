#include "support.h"
static Symbol lf_AUX_Numerals3_1sym;
static ATerm lf_AUX_Numerals3_1( );
static Symbol lf_AUX_Numerals3_2sym;
static ATerm lf_AUX_Numerals3_2( ATerm arg1);
void register_AUX_Numerals3( ) {
lf_AUX_Numerals3_1sym= ATmakeSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Numerals3_1sym);
lf_AUX_Numerals3_2sym= ATmakeSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Numerals3_2sym);
register_prod( ATparse( "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals3_1 , lf_AUX_Numerals3_1sym);
register_prod( ATparse( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals3_2 , lf_AUX_Numerals3_2sym);
}
void resolve_AUX_Numerals3( ) {
}
void init_AUX_Numerals3( ) {
}
ATerm lf_AUX_Numerals3_2( ATerm arg0) {
PROF( prof_lf_AUX_Numerals3_2);
return make_nf1( lf_AUX_Numerals3_2sym , arg0);
}
ATerm lf_AUX_Numerals3_1( ) {
PROF( prof_lf_AUX_Numerals3_1);
return make_nf0( lf_AUX_Numerals3_1sym);
}

