#include "support.h"
static Symbol lf_AUX_ParseTrees1_1sym;
static ATerm lf_AUX_ParseTrees1_1( );
static Symbol lf_AUX_ParseTrees1_2sym;
static ATerm lf_AUX_ParseTrees1_2( );
static Symbol lf_AUX_ParseTrees1_3sym;
static ATerm lf_AUX_ParseTrees1_3( );
static Symbol lf_AUX_ParseTrees1_4sym;
static ATerm lf_AUX_ParseTrees1_4( );
static Symbol lf_AUX_ParseTrees1_5sym;
static ATerm lf_AUX_ParseTrees1_5( );
static Symbol lf_AUX_ParseTrees1_6sym;
static ATerm lf_AUX_ParseTrees1_6( );
static Symbol lf_AUX_ParseTrees1_7sym;
static ATerm lf_AUX_ParseTrees1_7( );
static Symbol lf_AUX_ParseTrees1_8sym;
static ATerm lf_AUX_ParseTrees1_8( ATerm arg1);
static Symbol lf_AUX_ParseTrees1_9sym;
static ATerm lf_AUX_ParseTrees1_9( ATerm arg1);
void register_AUX_ParseTrees1( ) {
lf_AUX_ParseTrees1_1sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_1sym);
lf_AUX_ParseTrees1_2sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_2sym);
lf_AUX_ParseTrees1_3sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_3sym);
lf_AUX_ParseTrees1_4sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_4sym);
lf_AUX_ParseTrees1_5sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_5sym);
lf_AUX_ParseTrees1_6sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_6sym);
lf_AUX_ParseTrees1_7sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_7sym);
lf_AUX_ParseTrees1_8sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_8sym);
lf_AUX_ParseTrees1_9sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees1_9sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_1 , lf_AUX_ParseTrees1_1sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_2 , lf_AUX_ParseTrees1_2sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_3 , lf_AUX_ParseTrees1_3sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_4 , lf_AUX_ParseTrees1_4sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_5 , lf_AUX_ParseTrees1_5sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_6 , lf_AUX_ParseTrees1_6sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_7 , lf_AUX_ParseTrees1_7sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_8 , lf_AUX_ParseTrees1_8sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees1_9 , lf_AUX_ParseTrees1_9sym);
}
void resolve_AUX_ParseTrees1( ) {
}
void init_AUX_ParseTrees1( ) {
}
ATerm lf_AUX_ParseTrees1_9( ATerm arg0) {
PROF( prof_lf_AUX_ParseTrees1_9);
return make_nf1( lf_AUX_ParseTrees1_9sym , arg0);
}
ATerm lf_AUX_ParseTrees1_8( ATerm arg0) {
PROF( prof_lf_AUX_ParseTrees1_8);
return make_nf1( lf_AUX_ParseTrees1_8sym , arg0);
}
ATerm lf_AUX_ParseTrees1_7( ) {
PROF( prof_lf_AUX_ParseTrees1_7);
return make_nf0( lf_AUX_ParseTrees1_7sym);
}
ATerm lf_AUX_ParseTrees1_6( ) {
PROF( prof_lf_AUX_ParseTrees1_6);
return make_nf0( lf_AUX_ParseTrees1_6sym);
}
ATerm lf_AUX_ParseTrees1_5( ) {
PROF( prof_lf_AUX_ParseTrees1_5);
return make_nf0( lf_AUX_ParseTrees1_5sym);
}
ATerm lf_AUX_ParseTrees1_4( ) {
PROF( prof_lf_AUX_ParseTrees1_4);
return make_nf0( lf_AUX_ParseTrees1_4sym);
}
ATerm lf_AUX_ParseTrees1_3( ) {
PROF( prof_lf_AUX_ParseTrees1_3);
return make_nf0( lf_AUX_ParseTrees1_3sym);
}
ATerm lf_AUX_ParseTrees1_2( ) {
PROF( prof_lf_AUX_ParseTrees1_2);
return make_nf0( lf_AUX_ParseTrees1_2sym);
}
ATerm lf_AUX_ParseTrees1_1( ) {
PROF( prof_lf_AUX_ParseTrees1_1);
return make_nf0( lf_AUX_ParseTrees1_1sym);
}

