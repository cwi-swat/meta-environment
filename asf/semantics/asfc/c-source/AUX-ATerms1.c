#include "support.h"
static Symbol lf_AUX_ATerms1_1sym;
static ATerm lf_AUX_ATerms1_1( ATerm arg1);
static Symbol lf_AUX_ATerms1_2sym;
static ATerm lf_AUX_ATerms1_2( ATerm arg1);
static Symbol lf_AUX_ATerms1_3sym;
static ATerm lf_AUX_ATerms1_3( ATerm arg1);
static Symbol lf_AUX_ATerms1_4sym;
static ATerm lf_AUX_ATerms1_4( ATerm arg1);
static Symbol lf_AUX_ATerms1_5sym;
static ATerm lf_AUX_ATerms1_5( ATerm arg1);
static Symbol lf_AUX_ATerms1_6sym;
static ATerm lf_AUX_ATerms1_6( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_ATerms1_7sym;
static ATerm lf_AUX_ATerms1_7( ATerm arg1);
static Symbol lf_AUX_ATerms1_8sym;
static ATerm lf_AUX_ATerms1_8( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_ATerms1_9sym;
static ATerm lf_AUX_ATerms1_9( ATerm arg1);
static Symbol lf_AUX_ATerms1_10sym;
static ATerm lf_AUX_ATerms1_10( ATerm arg1);
static Symbol lf_AUX_ATerms1_11sym;
static ATerm lf_AUX_ATerms1_11( );
static Symbol lf_AUX_ATerms1_12sym;
static ATerm lf_AUX_ATerms1_12( ATerm arg1);
static Symbol lf_AUX_ATerms1_13sym;
static ATerm lf_AUX_ATerms1_13( ATerm arg1);
static Symbol lf_AUX_ATerms1_14sym;
static ATerm lf_AUX_ATerms1_14( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_ATerms1_15sym;
static ATerm lf_AUX_ATerms1_15( ATerm arg1);
static Symbol lf_AUX_ATerms1_16sym;
static ATerm lf_AUX_ATerms1_16( ATerm arg1);
static Symbol lf_AUX_ATerms1_17sym;
static ATerm lf_AUX_ATerms1_17( ATerm arg1);
void register_AUX_ATerms1( ) {
lf_AUX_ATerms1_1sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_1sym);
lf_AUX_ATerms1_2sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_2sym);
lf_AUX_ATerms1_3sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_3sym);
lf_AUX_ATerms1_4sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_4sym);
lf_AUX_ATerms1_5sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_5sym);
lf_AUX_ATerms1_6sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_6sym);
lf_AUX_ATerms1_7sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_7sym);
lf_AUX_ATerms1_8sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_8sym);
lf_AUX_ATerms1_9sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_9sym);
lf_AUX_ATerms1_10sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_10sym);
lf_AUX_ATerms1_11sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_11sym);
lf_AUX_ATerms1_12sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_12sym);
lf_AUX_ATerms1_13sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_13sym);
lf_AUX_ATerms1_14sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_14sym);
lf_AUX_ATerms1_15sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_15sym);
lf_AUX_ATerms1_16sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_16sym);
lf_AUX_ATerms1_17sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms1_17sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf_AUX_ATerms1_1 , lf_AUX_ATerms1_1sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_2 , lf_AUX_ATerms1_2sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_3 , lf_AUX_ATerms1_3sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_4 , lf_AUX_ATerms1_4sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_5 , lf_AUX_ATerms1_5sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_6 , lf_AUX_ATerms1_6sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_7 , lf_AUX_ATerms1_7sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_8 , lf_AUX_ATerms1_8sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_9 , lf_AUX_ATerms1_9sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_10 , lf_AUX_ATerms1_10sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_11 , lf_AUX_ATerms1_11sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_12 , lf_AUX_ATerms1_12sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_13 , lf_AUX_ATerms1_13sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_14 , lf_AUX_ATerms1_14sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_ATerms1_15 , lf_AUX_ATerms1_15sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms1_16 , lf_AUX_ATerms1_16sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_ATerms1_17 , lf_AUX_ATerms1_17sym);
}
void resolve_AUX_ATerms1( ) {
}
void init_AUX_ATerms1( ) {
}
ATerm lf_AUX_ATerms1_17( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_17);
return make_nf1( lf_AUX_ATerms1_17sym , arg0);
}
ATerm lf_AUX_ATerms1_16( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_16);
return make_nf1( lf_AUX_ATerms1_16sym , arg0);
}
ATerm lf_AUX_ATerms1_15( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_15);
return make_nf1( lf_AUX_ATerms1_15sym , arg0);
}
ATerm lf_AUX_ATerms1_14( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_ATerms1_14);
return make_nf2( lf_AUX_ATerms1_14sym , arg0 , arg1);
}
ATerm lf_AUX_ATerms1_13( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_13);
return make_nf1( lf_AUX_ATerms1_13sym , arg0);
}
ATerm lf_AUX_ATerms1_12( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_12);
return make_nf1( lf_AUX_ATerms1_12sym , arg0);
}
ATerm lf_AUX_ATerms1_11( ) {
PROF( prof_lf_AUX_ATerms1_11);
return make_nf0( lf_AUX_ATerms1_11sym);
}
ATerm lf_AUX_ATerms1_10( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_10);
return make_nf1( lf_AUX_ATerms1_10sym , arg0);
}
ATerm lf_AUX_ATerms1_9( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_9);
return make_nf1( lf_AUX_ATerms1_9sym , arg0);
}
ATerm lf_AUX_ATerms1_8( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_ATerms1_8);
return make_nf2( lf_AUX_ATerms1_8sym , arg0 , arg1);
}
ATerm lf_AUX_ATerms1_7( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_7);
return make_nf1( lf_AUX_ATerms1_7sym , arg0);
}
ATerm lf_AUX_ATerms1_6( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_ATerms1_6);
return make_nf2( lf_AUX_ATerms1_6sym , arg0 , arg1);
}
ATerm lf_AUX_ATerms1_5( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_5);
return make_nf1( lf_AUX_ATerms1_5sym , arg0);
}
ATerm lf_AUX_ATerms1_4( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_4);
return make_nf1( lf_AUX_ATerms1_4sym , arg0);
}
ATerm lf_AUX_ATerms1_3( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_3);
return make_nf1( lf_AUX_ATerms1_3sym , arg0);
}
ATerm lf_AUX_ATerms1_2( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_2);
return make_nf1( lf_AUX_ATerms1_2sym , arg0);
}
ATerm lf_AUX_ATerms1_1( ATerm arg0) {
PROF( prof_lf_AUX_ATerms1_1);
return make_nf1( lf_AUX_ATerms1_1sym , arg0);
}

