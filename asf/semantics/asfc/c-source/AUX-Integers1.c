#include "support.h"
static Symbol lf_AUX_Integers1_1sym;
static ATerm lf_AUX_Integers1_1( ATerm arg1);
static Symbol lf_AUX_Integers1_2sym;
static ATerm lf_AUX_Integers1_2( ATerm arg1);
static Symbol lf_AUX_Integers1_3sym;
static ATerm lf_AUX_Integers1_3( ATerm arg1);
static Symbol lf_AUX_Integers1_4sym;
static ATerm lf_AUX_Integers1_4( ATerm arg1);
void register_AUX_Integers1( ) {
lf_AUX_Integers1_1sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers1_1sym);
lf_AUX_Integers1_2sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers1_2sym);
lf_AUX_Integers1_3sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers1_3sym);
lf_AUX_Integers1_4sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"INT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers1_4sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)") , lf_AUX_Integers1_1 , lf_AUX_Integers1_1sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers1_2 , lf_AUX_Integers1_2sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)") , lf_AUX_Integers1_3 , lf_AUX_Integers1_3sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"INT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers1_4 , lf_AUX_Integers1_4sym);
}
void resolve_AUX_Integers1( ) {
}
void init_AUX_Integers1( ) {
}
ATerm lf_AUX_Integers1_4( ATerm arg0) {
PROF( prof_lf_AUX_Integers1_4);
return make_nf1( lf_AUX_Integers1_4sym , arg0);
}
ATerm lf_AUX_Integers1_3( ATerm arg0) {
PROF( prof_lf_AUX_Integers1_3);
return make_nf1( lf_AUX_Integers1_3sym , arg0);
}
ATerm lf_AUX_Integers1_2( ATerm arg0) {
PROF( prof_lf_AUX_Integers1_2);
return make_nf1( lf_AUX_Integers1_2sym , arg0);
}
ATerm lf_AUX_Integers1_1( ATerm arg0) {
PROF( prof_lf_AUX_Integers1_1);
return make_nf1( lf_AUX_Integers1_1sym , arg0);
}

