#include "support.h"
static Symbol lf_AUX_Rules2C_Aux40_2sym;
static ATerm lf_AUX_Rules2C_Aux40_2( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Rules2C_Aux40_1sym;
static ATerm lf_AUX_Rules2C_Aux40_1( ATerm arg1);
static Symbol lf_AUX_Rules2C_Aux40_4sym;
static ATerm lf_AUX_Rules2C_Aux40_4( ATerm arg1);
static Symbol lf_AUX_Rules2C_Aux40_5sym;
static ATerm lf_AUX_Rules2C_Aux40_5( ATerm arg1);
static Symbol lf_AUX_Rules2C_Aux40_7sym;
static ATerm lf_AUX_Rules2C_Aux40_7( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 , ATerm arg5);
static Symbol lf_AUX_Rules2C_Aux40_3sym;
static ATerm lf_AUX_Rules2C_Aux40_3( ATerm arg1);
static Symbol lf_AUX_Rules2C_Aux40_6sym;
static ATerm lf_AUX_Rules2C_Aux40_6( ATerm arg1);
static Symbol lf_AUX_Rules2C_Aux40_9sym;
static ATerm lf_AUX_Rules2C_Aux40_9( ATerm arg1);
static Symbol lf_AUX_Rules2C_Aux40_10sym;
static ATerm lf_AUX_Rules2C_Aux40_10( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Rules2C_Aux40_11sym;
static ATerm lf_AUX_Rules2C_Aux40_11( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Rules2C_Aux40_12sym;
static ATerm lf_AUX_Rules2C_Aux40_12( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Rules2C_Aux40_13sym;
static ATerm lf_AUX_Rules2C_Aux40_13( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4);
static Symbol lf_AUX_Rules2C_Aux40_8sym;
static ATerm lf_AUX_Rules2C_Aux40_8( ATerm arg1);
static Symbol lf_AUX_Rules2C_Aux40_14sym;
static ATerm lf_AUX_Rules2C_Aux40_14( ATerm arg1 , ATerm arg2);
void register_AUX_Rules2C_Aux40( ) {
lf_AUX_Rules2C_Aux40_2sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_2sym);
lf_AUX_Rules2C_Aux40_1sym= ATmakeSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_1sym);
lf_AUX_Rules2C_Aux40_4sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_4sym);
lf_AUX_Rules2C_Aux40_5sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_5sym);
lf_AUX_Rules2C_Aux40_7sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" , 5 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_7sym);
lf_AUX_Rules2C_Aux40_3sym= ATmakeSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_3sym);
lf_AUX_Rules2C_Aux40_6sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_6sym);
lf_AUX_Rules2C_Aux40_9sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_9sym);
lf_AUX_Rules2C_Aux40_10sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_10sym);
lf_AUX_Rules2C_Aux40_11sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_11sym);
lf_AUX_Rules2C_Aux40_12sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_12sym);
lf_AUX_Rules2C_Aux40_13sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)" , 4 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_13sym);
lf_AUX_Rules2C_Aux40_8sym= ATmakeSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_8sym);
lf_AUX_Rules2C_Aux40_14sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux40_14sym);
register_prod( ATparse( "listtype(sort(\"AInt\"),ql(\",\"))") , lf_AUX_Rules2C_Aux40_1 , lf_AUX_Rules2C_Aux40_1sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_2 , lf_AUX_Rules2C_Aux40_2sym);
register_prod( ATparse( "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf_AUX_Rules2C_Aux40_3 , lf_AUX_Rules2C_Aux40_3sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_4 , lf_AUX_Rules2C_Aux40_4sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_5 , lf_AUX_Rules2C_Aux40_5sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Rules2C_Aux40_6 , lf_AUX_Rules2C_Aux40_6sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_7 , lf_AUX_Rules2C_Aux40_7sym);
register_prod( ATparse( "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux40_8 , lf_AUX_Rules2C_Aux40_8sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_9 , lf_AUX_Rules2C_Aux40_9sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_10 , lf_AUX_Rules2C_Aux40_10sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_11 , lf_AUX_Rules2C_Aux40_11sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_12 , lf_AUX_Rules2C_Aux40_12sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_13 , lf_AUX_Rules2C_Aux40_13sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux40_14 , lf_AUX_Rules2C_Aux40_14sym);
}
void resolve_AUX_Rules2C_Aux40( ) {
}
void init_AUX_Rules2C_Aux40( ) {
}
ATerm lf_AUX_Rules2C_Aux40_14( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Rules2C_Aux40_14);
return make_nf2( lf_AUX_Rules2C_Aux40_14sym , arg0 , arg1);
}
ATerm lf_AUX_Rules2C_Aux40_8( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux40_8);
return make_nf1( lf_AUX_Rules2C_Aux40_8sym , arg0);
}
ATerm lf_AUX_Rules2C_Aux40_13( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3) {
PROF( prof_lf_AUX_Rules2C_Aux40_13);
return make_nf4( lf_AUX_Rules2C_Aux40_13sym , arg0 , arg1 , arg2 , arg3);
}
ATerm lf_AUX_Rules2C_Aux40_12( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Rules2C_Aux40_12);
return make_nf2( lf_AUX_Rules2C_Aux40_12sym , arg0 , arg1);
}
ATerm lf_AUX_Rules2C_Aux40_11( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Rules2C_Aux40_11);
return make_nf3( lf_AUX_Rules2C_Aux40_11sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_Rules2C_Aux40_10( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Rules2C_Aux40_10);
return make_nf2( lf_AUX_Rules2C_Aux40_10sym , arg0 , arg1);
}
ATerm lf_AUX_Rules2C_Aux40_9( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux40_9);
return make_nf1( lf_AUX_Rules2C_Aux40_9sym , arg0);
}
ATerm lf_AUX_Rules2C_Aux40_6( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux40_6);
return make_nf1( lf_AUX_Rules2C_Aux40_6sym , arg0);
}
ATerm lf_AUX_Rules2C_Aux40_3( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux40_3);
return make_nf1( lf_AUX_Rules2C_Aux40_3sym , arg0);
}
ATerm lf_AUX_Rules2C_Aux40_7( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4) {
PROF( prof_lf_AUX_Rules2C_Aux40_7);
return make_nf5( lf_AUX_Rules2C_Aux40_7sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
ATerm lf_AUX_Rules2C_Aux40_5( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux40_5);
return make_nf1( lf_AUX_Rules2C_Aux40_5sym , arg0);
}
ATerm lf_AUX_Rules2C_Aux40_4( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux40_4);
return make_nf1( lf_AUX_Rules2C_Aux40_4sym , arg0);
}
ATerm lf_AUX_Rules2C_Aux40_1( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux40_1);
return make_nf1( lf_AUX_Rules2C_Aux40_1sym , arg0);
}
ATerm lf_AUX_Rules2C_Aux40_2( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Rules2C_Aux40_2);
return make_nf2( lf_AUX_Rules2C_Aux40_2sym , arg0 , arg1);
}

