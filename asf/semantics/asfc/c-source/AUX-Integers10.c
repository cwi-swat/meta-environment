#include "support.h"
static Symbol lf_AUX_Integers10_1sym;
static ATerm lf_AUX_Integers10_1( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
void register_AUX_Integers10( ) {
lf_AUX_Integers10_1sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"<\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Integers10_1sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"<\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Integers10_1 , lf_AUX_Integers10_1sym);
}
void resolve_AUX_Integers10( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"~\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"~\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\">=\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\">=\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
void init_AUX_Integers10( ) {
}
ATerm lf_AUX_Integers10_1( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Integers10_1);
return ( * ef1)( ( * ef2)( arg0 , arg1));
}

