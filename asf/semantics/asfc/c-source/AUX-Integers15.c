#include "support.h"
static Symbol lf_AUX_Integers15_1sym;
static ATerm lf_AUX_Integers15_1( ATerm arg1);
static Symbol lf_AUX_Integers15_2sym;
static ATerm lf_AUX_Integers15_2( ATerm arg1);
static Symbol lf_AUX_Integers15_3sym;
static ATerm lf_AUX_Integers15_3( ATerm arg1);
static Symbol lf_AUX_Integers15_4sym;
static ATerm lf_AUX_Integers15_4( ATerm arg1);
void register_AUX_Integers15( ) {
lf_AUX_Integers15_1sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers15_1sym);
lf_AUX_Integers15_2sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers15_2sym);
lf_AUX_Integers15_3sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers15_3sym);
lf_AUX_Integers15_4sym= ATmakeSymbol( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"INT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Integers15_4sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),no-attrs)") , lf_AUX_Integers15_1 , lf_AUX_Integers15_1sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"NAT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NAT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers15_2 , lf_AUX_Integers15_2sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)") , lf_AUX_Integers15_3 , lf_AUX_Integers15_3sym);
register_prod( ATparse( "prod(id(\"Integers\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"INT\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_Integers15_4 , lf_AUX_Integers15_4sym);
}
void resolve_AUX_Integers15( ) {
}
void init_AUX_Integers15( ) {
}
ATerm lf_AUX_Integers15_4( ATerm arg0) {
PROF( prof_lf_AUX_Integers15_4);
return make_nf1( lf_AUX_Integers15_4sym , arg0);
}
ATerm lf_AUX_Integers15_3( ATerm arg0) {
PROF( prof_lf_AUX_Integers15_3);
return make_nf1( lf_AUX_Integers15_3sym , arg0);
}
ATerm lf_AUX_Integers15_2( ATerm arg0) {
PROF( prof_lf_AUX_Integers15_2);
return make_nf1( lf_AUX_Integers15_2sym , arg0);
}
ATerm lf_AUX_Integers15_1( ATerm arg0) {
PROF( prof_lf_AUX_Integers15_1);
return make_nf1( lf_AUX_Integers15_1sym , arg0);
}

