#include "support.h"
static Symbol lf_AUX_Booleans1_1sym;
static ATerm lf_AUX_Booleans1_1( );
static Symbol lf_AUX_Booleans1_2sym;
static ATerm lf_AUX_Booleans1_2( );
static Symbol lf_AUX_Booleans1_3sym;
static ATerm lf_AUX_Booleans1_3( ATerm arg1);
void register_AUX_Booleans1( ) {
lf_AUX_Booleans1_1sym= ATmakeSymbol( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Booleans1_1sym);
lf_AUX_Booleans1_2sym= ATmakeSymbol( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Booleans1_2sym);
lf_AUX_Booleans1_3sym= ATmakeSymbol( "prod(id(\"Booleans\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Booleans1_3sym);
register_prod( ATparse( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Booleans1_1 , lf_AUX_Booleans1_1sym);
register_prod( ATparse( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Booleans1_2 , lf_AUX_Booleans1_2sym);
register_prod( ATparse( "prod(id(\"Booleans\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_Booleans1_3 , lf_AUX_Booleans1_3sym);
}
void resolve_AUX_Booleans1( ) {
}
void init_AUX_Booleans1( ) {
}
ATerm lf_AUX_Booleans1_3( ATerm arg0) {
PROF( prof_lf_AUX_Booleans1_3);
return make_nf1( lf_AUX_Booleans1_3sym , arg0);
}
ATerm lf_AUX_Booleans1_2( ) {
PROF( prof_lf_AUX_Booleans1_2);
return make_nf0( lf_AUX_Booleans1_2sym);
}
ATerm lf_AUX_Booleans1_1( ) {
PROF( prof_lf_AUX_Booleans1_1);
return make_nf0( lf_AUX_Booleans1_1sym);
}

