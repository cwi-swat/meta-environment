#include "support.h"
static Symbol lf_AUX_Numerals2_1sym;
static ATerm lf_AUX_Numerals2_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
void register_AUX_Numerals2( ) {
lf_AUX_Numerals2_1sym= ATmakeSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"decr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Numerals2_1sym);
register_prod( ATparse( "prod(id(\"Numerals\"),w(\"\"),[l(\"decr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals2_1 , lf_AUX_Numerals2_1sym);
}
void resolve_AUX_Numerals2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
}
void init_AUX_Numerals2( ) {
}
ATerm lf_AUX_Numerals2_1( ATerm arg0) {
PROF( prof_lf_AUX_Numerals2_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
return atmp00;
}
}
if( check_sym( arg0 , ef2sym)) {
return arg0;
}
return make_nf1( lf_AUX_Numerals2_1sym , arg0);
}

