#include "support.h"
static Symbol lf_AUX_ParseTrees17_1sym;
static ATerm lf_AUX_ParseTrees17_1( );
static Symbol lf_AUX_ParseTrees17_2sym;
static ATerm lf_AUX_ParseTrees17_2( );
static Symbol lf_AUX_ParseTrees17_3sym;
static ATerm lf_AUX_ParseTrees17_3( );
static Symbol lf_AUX_ParseTrees17_4sym;
static ATerm lf_AUX_ParseTrees17_4( );
static Symbol lf_AUX_ParseTrees17_5sym;
static ATerm lf_AUX_ParseTrees17_5( );
static Symbol lf_AUX_ParseTrees17_6sym;
static ATerm lf_AUX_ParseTrees17_6( );
static Symbol lf_AUX_ParseTrees17_7sym;
static ATerm lf_AUX_ParseTrees17_7( );
static Symbol lf_AUX_ParseTrees17_8sym;
static ATerm lf_AUX_ParseTrees17_8( ATerm arg1);
static Symbol lf_AUX_ParseTrees17_9sym;
static ATerm lf_AUX_ParseTrees17_9( ATerm arg1);
void register_AUX_ParseTrees17( ) {
lf_AUX_ParseTrees17_1sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_1sym);
lf_AUX_ParseTrees17_2sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_2sym);
lf_AUX_ParseTrees17_3sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_3sym);
lf_AUX_ParseTrees17_4sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_4sym);
lf_AUX_ParseTrees17_5sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_5sym);
lf_AUX_ParseTrees17_6sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_6sym);
lf_AUX_ParseTrees17_7sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_7sym);
lf_AUX_ParseTrees17_8sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_8sym);
lf_AUX_ParseTrees17_9sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees17_9sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_1 , lf_AUX_ParseTrees17_1sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_2 , lf_AUX_ParseTrees17_2sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_3 , lf_AUX_ParseTrees17_3sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"meta-var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_4 , lf_AUX_ParseTrees17_4sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_5 , lf_AUX_ParseTrees17_5sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_6 , lf_AUX_ParseTrees17_6sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_7 , lf_AUX_ParseTrees17_7sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"is\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_8 , lf_AUX_ParseTrees17_8sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"cons2lit\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees17_9 , lf_AUX_ParseTrees17_9sym);
}
void resolve_AUX_ParseTrees17( ) {
}
void init_AUX_ParseTrees17( ) {
}
ATerm lf_AUX_ParseTrees17_9( ATerm arg0) {
PROF( prof_lf_AUX_ParseTrees17_9);
return make_nf1( lf_AUX_ParseTrees17_9sym , arg0);
}
ATerm lf_AUX_ParseTrees17_8( ATerm arg0) {
PROF( prof_lf_AUX_ParseTrees17_8);
return make_nf1( lf_AUX_ParseTrees17_8sym , arg0);
}
ATerm lf_AUX_ParseTrees17_7( ) {
PROF( prof_lf_AUX_ParseTrees17_7);
return make_nf0( lf_AUX_ParseTrees17_7sym);
}
ATerm lf_AUX_ParseTrees17_6( ) {
PROF( prof_lf_AUX_ParseTrees17_6);
return make_nf0( lf_AUX_ParseTrees17_6sym);
}
ATerm lf_AUX_ParseTrees17_5( ) {
PROF( prof_lf_AUX_ParseTrees17_5);
return make_nf0( lf_AUX_ParseTrees17_5sym);
}
ATerm lf_AUX_ParseTrees17_4( ) {
PROF( prof_lf_AUX_ParseTrees17_4);
return make_nf0( lf_AUX_ParseTrees17_4sym);
}
ATerm lf_AUX_ParseTrees17_3( ) {
PROF( prof_lf_AUX_ParseTrees17_3);
return make_nf0( lf_AUX_ParseTrees17_3sym);
}
ATerm lf_AUX_ParseTrees17_2( ) {
PROF( prof_lf_AUX_ParseTrees17_2);
return make_nf0( lf_AUX_ParseTrees17_2sym);
}
ATerm lf_AUX_ParseTrees17_1( ) {
PROF( prof_lf_AUX_ParseTrees17_1);
return make_nf0( lf_AUX_ParseTrees17_1sym);
}

