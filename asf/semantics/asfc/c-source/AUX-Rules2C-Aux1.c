#include  "support.h"
static Symbol lf_AUX_Rules2C_Aux1_2sym ;
static ATerm lf_AUX_Rules2C_Aux1_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Rules2C_Aux1_1sym ;
static ATerm lf_AUX_Rules2C_Aux1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Rules2C_Aux1_4sym ;
static ATerm lf_AUX_Rules2C_Aux1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_Rules2C_Aux1_5sym ;
static ATerm lf_AUX_Rules2C_Aux1_5 ( ATerm arg1 ) ;
static Symbol lf_AUX_Rules2C_Aux1_7sym ;
static ATerm lf_AUX_Rules2C_Aux1_7 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 , ATerm arg5 , ATerm arg6 ) ;
static Symbol lf_AUX_Rules2C_Aux1_3sym ;
static ATerm lf_AUX_Rules2C_Aux1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Rules2C_Aux1_6sym ;
static ATerm lf_AUX_Rules2C_Aux1_6 ( ATerm arg1 ) ;
static Symbol lf_AUX_Rules2C_Aux1_9sym ;
static ATerm lf_AUX_Rules2C_Aux1_9 ( ATerm arg1 ) ;
static Symbol lf_AUX_Rules2C_Aux1_10sym ;
static ATerm lf_AUX_Rules2C_Aux1_10 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Rules2C_Aux1_11sym ;
static ATerm lf_AUX_Rules2C_Aux1_11 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Rules2C_Aux1_12sym ;
static ATerm lf_AUX_Rules2C_Aux1_12 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Rules2C_Aux1_13sym ;
static ATerm lf_AUX_Rules2C_Aux1_13 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
static Symbol lf_AUX_Rules2C_Aux1_8sym ;
static ATerm lf_AUX_Rules2C_Aux1_8 ( ATerm arg1 ) ;
static Symbol lf_AUX_Rules2C_Aux1_14sym ;
static ATerm lf_AUX_Rules2C_Aux1_14 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_Rules2C_Aux1 ( ) {
lf_AUX_Rules2C_Aux1_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_2sym ) ;
lf_AUX_Rules2C_Aux1_1sym = ATmakeSymbol ( "listtype(sort(\"IntCon\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_1sym ) ;
lf_AUX_Rules2C_Aux1_4sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_4sym ) ;
lf_AUX_Rules2C_Aux1_5sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_5sym ) ;
lf_AUX_Rules2C_Aux1_7sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" , 6 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_7sym ) ;
lf_AUX_Rules2C_Aux1_3sym = ATmakeSymbol ( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_3sym ) ;
lf_AUX_Rules2C_Aux1_6sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_6sym ) ;
lf_AUX_Rules2C_Aux1_9sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_9sym ) ;
lf_AUX_Rules2C_Aux1_10sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_10sym ) ;
lf_AUX_Rules2C_Aux1_11sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_11sym ) ;
lf_AUX_Rules2C_Aux1_12sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_12sym ) ;
lf_AUX_Rules2C_Aux1_13sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)" , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_13sym ) ;
lf_AUX_Rules2C_Aux1_8sym = ATmakeSymbol ( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_8sym ) ;
lf_AUX_Rules2C_Aux1_14sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux1_14sym ) ;
register_prod ( ATparse ( "listtype(sort(\"IntCon\"),ql(\",\"))" ) , lf_AUX_Rules2C_Aux1_1 , lf_AUX_Rules2C_Aux1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_2 , lf_AUX_Rules2C_Aux1_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FV-Path\"),ql(\",\"))" ) , lf_AUX_Rules2C_Aux1_3 , lf_AUX_Rules2C_Aux1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_4 , lf_AUX_Rules2C_Aux1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_5 , lf_AUX_Rules2C_Aux1_5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf_AUX_Rules2C_Aux1_6 , lf_AUX_Rules2C_Aux1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_7 , lf_AUX_Rules2C_Aux1_7sym ) ;
register_prod ( ATparse ( "listtype(sort(\"C-Rule\"),ql(\";\"))" ) , lf_AUX_Rules2C_Aux1_8 , lf_AUX_Rules2C_Aux1_8sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_9 , lf_AUX_Rules2C_Aux1_9sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_10 , lf_AUX_Rules2C_Aux1_10sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_11 , lf_AUX_Rules2C_Aux1_11sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_12 , lf_AUX_Rules2C_Aux1_12sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_13 , lf_AUX_Rules2C_Aux1_13sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux1_14 , lf_AUX_Rules2C_Aux1_14sym ) ;
}
void resolve_AUX_Rules2C_Aux1 ( ) {
}
void init_AUX_Rules2C_Aux1 ( ) {
}
ATerm lf_AUX_Rules2C_Aux1_14 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_14 ) ;
return make_nf2 ( lf_AUX_Rules2C_Aux1_14sym , arg0 , arg1 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_8 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_8 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux1_8sym , arg0 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_13 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_13 ) ;
return make_nf4 ( lf_AUX_Rules2C_Aux1_13sym , arg0 , arg1 , arg2 , arg3 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_12 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_12 ) ;
return make_nf2 ( lf_AUX_Rules2C_Aux1_12sym , arg0 , arg1 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_11 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_11 ) ;
return make_nf3 ( lf_AUX_Rules2C_Aux1_11sym , arg0 , arg1 , arg2 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_10 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_10 ) ;
return make_nf2 ( lf_AUX_Rules2C_Aux1_10sym , arg0 , arg1 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_9 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_9 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux1_9sym , arg0 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_6 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_6 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux1_6sym , arg0 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_3 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_3 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux1_3sym , arg0 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_7 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 , ATerm arg5 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_7 ) ;
return make_nf6 ( lf_AUX_Rules2C_Aux1_7sym , arg0 , arg1 , arg2 , arg3 , arg4 , arg5 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_5 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_5 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux1_5sym , arg0 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_4 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_4 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux1_4sym , arg0 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_1 ) ;
return make_nf1 ( lf_AUX_Rules2C_Aux1_1sym , arg0 ) ;
}
ATerm lf_AUX_Rules2C_Aux1_2 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_Rules2C_Aux1_2 ) ;
return make_nf2 ( lf_AUX_Rules2C_Aux1_2sym , arg0 , arg1 ) ;
}

