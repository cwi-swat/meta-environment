#include "support.h"
static Symbol lf_AUX_Literals5_2sym;
static ATerm lf_AUX_Literals5_2( ATerm arg1);
static Symbol lf_AUX_Literals5_3sym;
static ATerm lf_AUX_Literals5_3( ATerm arg1);
static Symbol lf_AUX_Literals5_1sym;
static ATerm lf_AUX_Literals5_1( ATerm arg1);
static Symbol lf_AUX_Literals5_4sym;
static ATerm lf_AUX_Literals5_4( ATerm arg1);
void register_AUX_Literals5( ) {
lf_AUX_Literals5_2sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"escchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EscChar\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Literals5_2sym);
lf_AUX_Literals5_3sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"l-char\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"L-Char\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Literals5_3sym);
lf_AUX_Literals5_1sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Literals5_1sym);
lf_AUX_Literals5_4sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Literals5_4sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf_AUX_Literals5_1 , lf_AUX_Literals5_1sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"escchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EscChar\"),w(\"\"),no-attrs)") , lf_AUX_Literals5_2 , lf_AUX_Literals5_2sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"l-char\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"L-Char\"),w(\"\"),no-attrs)") , lf_AUX_Literals5_3 , lf_AUX_Literals5_3sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_Literals5_4 , lf_AUX_Literals5_4sym);
}
void resolve_AUX_Literals5( ) {
}
void init_AUX_Literals5( ) {
}
ATerm lf_AUX_Literals5_4( ATerm arg0) {
PROF( prof_lf_AUX_Literals5_4);
return make_nf1( lf_AUX_Literals5_4sym , arg0);
}
ATerm lf_AUX_Literals5_1( ATerm arg0) {
PROF( prof_lf_AUX_Literals5_1);
return make_nf1( lf_AUX_Literals5_1sym , arg0);
}
ATerm lf_AUX_Literals5_3( ATerm arg0) {
PROF( prof_lf_AUX_Literals5_3);
return make_nf1( lf_AUX_Literals5_3sym , arg0);
}
ATerm lf_AUX_Literals5_2( ATerm arg0) {
PROF( prof_lf_AUX_Literals5_2);
return make_nf1( lf_AUX_Literals5_2sym , arg0);
}

