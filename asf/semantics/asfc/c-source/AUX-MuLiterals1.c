#include "support.h"
static Symbol lf_AUX_MuLiterals1_2sym;
static ATerm lf_AUX_MuLiterals1_2( ATerm arg1);
static Symbol lf_AUX_MuLiterals1_3sym;
static ATerm lf_AUX_MuLiterals1_3( ATerm arg1);
static Symbol lf_AUX_MuLiterals1_4sym;
static ATerm lf_AUX_MuLiterals1_4( ATerm arg1);
static Symbol lf_AUX_MuLiterals1_1sym;
static ATerm lf_AUX_MuLiterals1_1( ATerm arg1);
static Symbol lf_AUX_MuLiterals1_5sym;
static ATerm lf_AUX_MuLiterals1_5( ATerm arg1);
void register_AUX_MuLiterals1( ) {
lf_AUX_MuLiterals1_2sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals1_2sym);
lf_AUX_MuLiterals1_3sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals1_3sym);
lf_AUX_MuLiterals1_4sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals1_4sym);
lf_AUX_MuLiterals1_1sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals1_1sym);
lf_AUX_MuLiterals1_5sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"propid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PropId\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals1_5sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf_AUX_MuLiterals1_1 , lf_AUX_MuLiterals1_1sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals1_2 , lf_AUX_MuLiterals1_2sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals1_3 , lf_AUX_MuLiterals1_3sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals1_4 , lf_AUX_MuLiterals1_4sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"propid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PropId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals1_5 , lf_AUX_MuLiterals1_5sym);
}
void resolve_AUX_MuLiterals1( ) {
}
void init_AUX_MuLiterals1( ) {
}
ATerm lf_AUX_MuLiterals1_5( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals1_5);
return make_nf1( lf_AUX_MuLiterals1_5sym , arg0);
}
ATerm lf_AUX_MuLiterals1_1( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals1_1);
return make_nf1( lf_AUX_MuLiterals1_1sym , arg0);
}
ATerm lf_AUX_MuLiterals1_4( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals1_4);
return make_nf1( lf_AUX_MuLiterals1_4sym , arg0);
}
ATerm lf_AUX_MuLiterals1_3( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals1_3);
return make_nf1( lf_AUX_MuLiterals1_3sym , arg0);
}
ATerm lf_AUX_MuLiterals1_2( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals1_2);
return make_nf1( lf_AUX_MuLiterals1_2sym , arg0);
}

