#include "support.h"
static Symbol lf_AUX_ATerms3_1sym;
static ATerm lf_AUX_ATerms3_1( ATerm arg1 , ATerm arg2);
void register_AUX_ATerms3( ) {
lf_AUX_ATerms3_1sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms3_1sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))") , lf_AUX_ATerms3_1 , lf_AUX_ATerms3_1sym);
}
void resolve_AUX_ATerms3( ) {
}
void init_AUX_ATerms3( ) {
}
ATerm lf_AUX_ATerms3_1( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_ATerms3_1);
if( check_sym( arg0 , lf_AUX_ATerms3_1sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
return lf_AUX_ATerms3_1( atmp00 , lf_AUX_ATerms3_1( atmp01 , arg1));
}
}
}
return make_nf2( lf_AUX_ATerms3_1sym , arg0 , arg1);
}

