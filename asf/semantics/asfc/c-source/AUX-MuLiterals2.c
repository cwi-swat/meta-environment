#include "support.h"
static Symbol lf_AUX_MuLiterals2_2sym;
static ATerm lf_AUX_MuLiterals2_2( ATerm arg1);
static Symbol lf_AUX_MuLiterals2_3sym;
static ATerm lf_AUX_MuLiterals2_3( ATerm arg1);
static Symbol lf_AUX_MuLiterals2_4sym;
static ATerm lf_AUX_MuLiterals2_4( ATerm arg1);
static Symbol lf_AUX_MuLiterals2_5sym;
static ATerm lf_AUX_MuLiterals2_5( ATerm arg1);
static Symbol lf_AUX_MuLiterals2_6sym;
static ATerm lf_AUX_MuLiterals2_6( ATerm arg1);
static Symbol lf_AUX_MuLiterals2_1sym;
static ATerm lf_AUX_MuLiterals2_1( ATerm arg1);
static Symbol lf_AUX_MuLiterals2_7sym;
static ATerm lf_AUX_MuLiterals2_7( ATerm arg1);
void register_AUX_MuLiterals2( ) {
lf_AUX_MuLiterals2_2sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"escchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EscChar\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals2_2sym);
lf_AUX_MuLiterals2_3sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"qchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"QChar\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals2_3sym);
lf_AUX_MuLiterals2_4sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals2_4sym);
lf_AUX_MuLiterals2_5sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals2_5sym);
lf_AUX_MuLiterals2_6sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals2_6sym);
lf_AUX_MuLiterals2_1sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals2_1sym);
lf_AUX_MuLiterals2_7sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"propid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PropId\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuLiterals2_7sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf_AUX_MuLiterals2_1 , lf_AUX_MuLiterals2_1sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"escchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EscChar\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_2 , lf_AUX_MuLiterals2_2sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"qchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"QChar\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_3 , lf_AUX_MuLiterals2_3sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_4 , lf_AUX_MuLiterals2_4sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"varid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_5 , lf_AUX_MuLiterals2_5sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"modid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_6 , lf_AUX_MuLiterals2_6sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"propid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PropId\"),w(\"\"),no-attrs)") , lf_AUX_MuLiterals2_7 , lf_AUX_MuLiterals2_7sym);
}
void resolve_AUX_MuLiterals2( ) {
}
void init_AUX_MuLiterals2( ) {
}
ATerm lf_AUX_MuLiterals2_7( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals2_7);
return make_nf1( lf_AUX_MuLiterals2_7sym , arg0);
}
ATerm lf_AUX_MuLiterals2_1( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals2_1);
return make_nf1( lf_AUX_MuLiterals2_1sym , arg0);
}
ATerm lf_AUX_MuLiterals2_6( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals2_6);
return make_nf1( lf_AUX_MuLiterals2_6sym , arg0);
}
ATerm lf_AUX_MuLiterals2_5( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals2_5);
return make_nf1( lf_AUX_MuLiterals2_5sym , arg0);
}
ATerm lf_AUX_MuLiterals2_4( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals2_4);
return make_nf1( lf_AUX_MuLiterals2_4sym , arg0);
}
ATerm lf_AUX_MuLiterals2_3( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals2_3);
return make_nf1( lf_AUX_MuLiterals2_3sym , arg0);
}
ATerm lf_AUX_MuLiterals2_2( ATerm arg0) {
PROF( prof_lf_AUX_MuLiterals2_2);
return make_nf1( lf_AUX_MuLiterals2_2sym , arg0);
}

