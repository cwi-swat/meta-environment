#include "support.h"
static Symbol lf_AUX_Booleans5_1sym;
static ATerm lf_AUX_Booleans5_1( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
void register_AUX_Booleans5( ) {
lf_AUX_Booleans5_1sym= ATmakeSymbol( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Booleans5_1sym);
register_prod( ATparse( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))") , lf_AUX_Booleans5_1 , lf_AUX_Booleans5_1sym);
}
void resolve_AUX_Booleans5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
void init_AUX_Booleans5( ) {
}
ATerm lf_AUX_Booleans5_1( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Booleans5_1);
if( check_sym( arg0 , ef1sym)) {
return arg0;
}
if( check_sym( arg0 , ef2sym)) {
return arg1;
}
return make_nf2( lf_AUX_Booleans5_1sym , arg0 , arg1);
}

