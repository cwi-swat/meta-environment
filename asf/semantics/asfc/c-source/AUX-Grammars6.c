#include "support.h"
static Symbol lf_AUX_Grammars6_1sym;
static ATerm lf_AUX_Grammars6_1( );
static Symbol lf_AUX_Grammars6_2sym;
static ATerm lf_AUX_Grammars6_2( );
static Symbol lf_AUX_Grammars6_3sym;
static ATerm lf_AUX_Grammars6_3( );
static Symbol lf_AUX_Grammars6_4sym;
static ATerm lf_AUX_Grammars6_4( ATerm arg1);
static Symbol lf_AUX_Grammars6_5sym;
static ATerm lf_AUX_Grammars6_5( ATerm arg1);
static Symbol lf_AUX_Grammars6_6sym;
static ATerm lf_AUX_Grammars6_6( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Grammars6_7sym;
static ATerm lf_AUX_Grammars6_7( ATerm arg1);
static Symbol lf_AUX_Grammars6_8sym;
static ATerm lf_AUX_Grammars6_8( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Grammars6_9sym;
static ATerm lf_AUX_Grammars6_9( ATerm arg1);
static Symbol lf_AUX_Grammars6_10sym;
static ATerm lf_AUX_Grammars6_10( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Grammars6_12sym;
static ATerm lf_AUX_Grammars6_12( ATerm arg1);
static Symbol lf_AUX_Grammars6_11sym;
static ATerm lf_AUX_Grammars6_11( ATerm arg1);
static Symbol lf_AUX_Grammars6_13sym;
static ATerm lf_AUX_Grammars6_13( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Grammars6_15sym;
static ATerm lf_AUX_Grammars6_15( ATerm arg1);
static Symbol lf_AUX_Grammars6_14sym;
static ATerm lf_AUX_Grammars6_14( ATerm arg1);
static Symbol lf_AUX_Grammars6_16sym;
static ATerm lf_AUX_Grammars6_16( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Grammars6_17sym;
static ATerm lf_AUX_Grammars6_17( );
static Symbol lf_AUX_Grammars6_19sym;
static ATerm lf_AUX_Grammars6_19( ATerm arg1);
static Symbol lf_AUX_Grammars6_18sym;
static ATerm lf_AUX_Grammars6_18( ATerm arg1);
void register_AUX_Grammars6( ) {
lf_AUX_Grammars6_1sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_1sym);
lf_AUX_Grammars6_2sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Text\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_2sym);
lf_AUX_Grammars6_3sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_3sym);
lf_AUX_Grammars6_4sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_4sym);
lf_AUX_Grammars6_5sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_5sym);
lf_AUX_Grammars6_6sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_6sym);
lf_AUX_Grammars6_7sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_7sym);
lf_AUX_Grammars6_8sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_8sym);
lf_AUX_Grammars6_9sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_9sym);
lf_AUX_Grammars6_10sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_10sym);
lf_AUX_Grammars6_12sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_12sym);
lf_AUX_Grammars6_11sym= ATmakeSymbol( "listtype(sort(\"Symbol\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_11sym);
lf_AUX_Grammars6_13sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_13sym);
lf_AUX_Grammars6_15sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_15sym);
lf_AUX_Grammars6_14sym= ATmakeSymbol( "listtype(sort(\"Production\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_14sym);
lf_AUX_Grammars6_16sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"lexical syntax\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"context-free syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_16sym);
lf_AUX_Grammars6_17sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_17sym);
lf_AUX_Grammars6_19sym= ATmakeSymbol( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_19sym);
lf_AUX_Grammars6_18sym= ATmakeSymbol( "listtype(sort(\"ATerm\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Grammars6_18sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Layout\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_1 , lf_AUX_Grammars6_1sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[ql(\"Text\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_2 , lf_AUX_Grammars6_2sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[ql(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_3 , lf_AUX_Grammars6_3sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_4 , lf_AUX_Grammars6_4sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_5 , lf_AUX_Grammars6_5sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_6 , lf_AUX_Grammars6_6sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_7 , lf_AUX_Grammars6_7sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"*\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_8 , lf_AUX_Grammars6_8sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_9 , lf_AUX_Grammars6_9sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"}\"),w(\"\"),ql(\"+\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_10 , lf_AUX_Grammars6_10sym);
register_prod( ATparse( "listtype(sort(\"Symbol\"))") , lf_AUX_Grammars6_11 , lf_AUX_Grammars6_11sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_12 , lf_AUX_Grammars6_12sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_13 , lf_AUX_Grammars6_13sym);
register_prod( ATparse( "listtype(sort(\"Production\"))") , lf_AUX_Grammars6_14 , lf_AUX_Grammars6_14sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_15 , lf_AUX_Grammars6_15sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[ql(\"lexical syntax\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\"context-free syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_16 , lf_AUX_Grammars6_16sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_17 , lf_AUX_Grammars6_17sym);
register_prod( ATparse( "listtype(sort(\"ATerm\"),ql(\",\"))") , lf_AUX_Grammars6_18 , lf_AUX_Grammars6_18sym);
register_prod( ATparse( "prod(id(\"Grammars\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)") , lf_AUX_Grammars6_19 , lf_AUX_Grammars6_19sym);
}
void resolve_AUX_Grammars6( ) {
}
void init_AUX_Grammars6( ) {
}
ATerm lf_AUX_Grammars6_18( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_18);
return make_nf1( lf_AUX_Grammars6_18sym , arg0);
}
ATerm lf_AUX_Grammars6_19( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_19);
return make_nf1( lf_AUX_Grammars6_19sym , arg0);
}
ATerm lf_AUX_Grammars6_17( ) {
PROF( prof_lf_AUX_Grammars6_17);
return make_nf0( lf_AUX_Grammars6_17sym);
}
ATerm lf_AUX_Grammars6_16( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Grammars6_16);
return make_nf2( lf_AUX_Grammars6_16sym , arg0 , arg1);
}
ATerm lf_AUX_Grammars6_14( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_14);
return make_nf1( lf_AUX_Grammars6_14sym , arg0);
}
ATerm lf_AUX_Grammars6_15( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_15);
return make_nf1( lf_AUX_Grammars6_15sym , arg0);
}
ATerm lf_AUX_Grammars6_13( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Grammars6_13);
return make_nf3( lf_AUX_Grammars6_13sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_Grammars6_11( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_11);
return make_nf1( lf_AUX_Grammars6_11sym , arg0);
}
ATerm lf_AUX_Grammars6_12( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_12);
return make_nf1( lf_AUX_Grammars6_12sym , arg0);
}
ATerm lf_AUX_Grammars6_10( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Grammars6_10);
return make_nf2( lf_AUX_Grammars6_10sym , arg0 , arg1);
}
ATerm lf_AUX_Grammars6_9( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_9);
return make_nf1( lf_AUX_Grammars6_9sym , arg0);
}
ATerm lf_AUX_Grammars6_8( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Grammars6_8);
return make_nf2( lf_AUX_Grammars6_8sym , arg0 , arg1);
}
ATerm lf_AUX_Grammars6_7( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_7);
return make_nf1( lf_AUX_Grammars6_7sym , arg0);
}
ATerm lf_AUX_Grammars6_6( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Grammars6_6);
return make_nf2( lf_AUX_Grammars6_6sym , arg0 , arg1);
}
ATerm lf_AUX_Grammars6_5( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_5);
return make_nf1( lf_AUX_Grammars6_5sym , arg0);
}
ATerm lf_AUX_Grammars6_4( ATerm arg0) {
PROF( prof_lf_AUX_Grammars6_4);
return make_nf1( lf_AUX_Grammars6_4sym , arg0);
}
ATerm lf_AUX_Grammars6_3( ) {
PROF( prof_lf_AUX_Grammars6_3);
return make_nf0( lf_AUX_Grammars6_3sym);
}
ATerm lf_AUX_Grammars6_2( ) {
PROF( prof_lf_AUX_Grammars6_2);
return make_nf0( lf_AUX_Grammars6_2sym);
}
ATerm lf_AUX_Grammars6_1( ) {
PROF( prof_lf_AUX_Grammars6_1);
return make_nf0( lf_AUX_Grammars6_1sym);
}

