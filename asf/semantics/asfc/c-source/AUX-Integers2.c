#include "support.h"
static Symbol lf_AUX_Integers2_1sym;
static ATerm lf_AUX_Integers2_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
void register_AUX_Integers2( ) {
lf_AUX_Integers2_1sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers2_1sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)") , lf_AUX_Integers2_1 , lf_AUX_Integers2_1sym);
}
void resolve_AUX_Integers2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
}
void init_AUX_Integers2( ) {
}
ATerm lf_AUX_Integers2_1( ATerm arg0) {
PROF( prof_lf_AUX_Integers2_1);
return ( * ef1)( arg0);
}

