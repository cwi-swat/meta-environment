#include "support.h"
static Symbol lf_AUX_Numerals3_1sym;
static ATerm lf_AUX_Numerals3_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
void register_AUX_Numerals3( ) {
lf_AUX_Numerals3_1sym= ATmakeSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"incr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Numerals3_1sym);
register_prod( ATparse( "prod(id(\"Numerals\"),w(\"\"),[l(\"incr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals3_1 , lf_AUX_Numerals3_1sym);
}
void resolve_AUX_Numerals3( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
}
void init_AUX_Numerals3( ) {
}
ATerm lf_AUX_Numerals3_1( ATerm arg0) {
PROF( prof_lf_AUX_Numerals3_1);
return ( * ef1)( arg0);
}

