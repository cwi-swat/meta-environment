#include "support.h"
static Symbol lf_AUX_ParseTrees1_1sym;
static ATerm lf_AUX_ParseTrees1_1( );
static Symbol lf_AUX_ParseTrees1_2sym;
static ATerm lf_AUX_ParseTrees1_2( );
static Symbol lf_AUX_ParseTrees1_3sym;
static ATerm lf_AUX_ParseTrees1_3( ATerm arg1);
static Symbol lf_AUX_ParseTrees1_4sym;
static ATerm lf_AUX_ParseTrees1_4( ATerm arg1);
void register_AUX_ParseTrees1( ) {
lf_AUX_ParseTrees1_1sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"fun-wmap\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_1sym);
lf_AUX_ParseTrees1_2sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"wid\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_2sym);
lf_AUX_ParseTrees1_3sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_3sym);
lf_AUX_ParseTrees1_4sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_4sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"fun-wmap\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_1 , lf_AUX_ParseTrees1_1sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"wid\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_2 , lf_AUX_ParseTrees1_2sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_3 , lf_AUX_ParseTrees1_3sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_4 , lf_AUX_ParseTrees1_4sym);
}
void resolve_AUX_ParseTrees1( ) {
}
void init_AUX_ParseTrees1( ) {
}
ATerm lf_AUX_ParseTrees1_4( ATerm arg0) {
PROF( prof_lf_AUX_ParseTrees1_4);
return make_nf1( lf_AUX_ParseTrees1_4sym , arg0);
}
ATerm lf_AUX_ParseTrees1_3( ATerm arg0) {
PROF( prof_lf_AUX_ParseTrees1_3);
return make_nf1( lf_AUX_ParseTrees1_3sym , arg0);
}
ATerm lf_AUX_ParseTrees1_2( ) {
PROF( prof_lf_AUX_ParseTrees1_2);
return make_nf0( lf_AUX_ParseTrees1_2sym);
}
ATerm lf_AUX_ParseTrees1_1( ) {
PROF( prof_lf_AUX_ParseTrees1_1);
return make_nf0( lf_AUX_ParseTrees1_1sym);
}

