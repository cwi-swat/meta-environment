#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux45_2sym;
static aterm * lf_AUX_Rules2C_Aux45_2( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux45_1sym;
static aterm * lf_AUX_Rules2C_Aux45_1( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux45_4sym;
static aterm * lf_AUX_Rules2C_Aux45_4( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux45_5sym;
static aterm * lf_AUX_Rules2C_Aux45_5( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux45_7sym;
static aterm * lf_AUX_Rules2C_Aux45_7( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * lf_AUX_Rules2C_Aux45_3sym;
static aterm * lf_AUX_Rules2C_Aux45_3( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux45_6sym;
static aterm * lf_AUX_Rules2C_Aux45_6( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux45_9sym;
static aterm * lf_AUX_Rules2C_Aux45_9( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux45_10sym;
static aterm * lf_AUX_Rules2C_Aux45_10( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux45_11sym;
static aterm * lf_AUX_Rules2C_Aux45_11( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Rules2C_Aux45_12sym;
static aterm * lf_AUX_Rules2C_Aux45_12( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux45_13sym;
static aterm * lf_AUX_Rules2C_Aux45_13( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * lf_AUX_Rules2C_Aux45_8sym;
static aterm * lf_AUX_Rules2C_Aux45_8( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux45_14sym;
static aterm * lf_AUX_Rules2C_Aux45_14( aterm * arg1 , aterm * arg2);
void register_AUX_Rules2C_Aux45( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux45_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Rules2C_Aux45_1sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux45_4sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux45_5sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux45_7sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux45_3sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux45_6sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux45_9sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux45_10sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux45_11sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux45_12sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux45_13sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux45_8sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux45_14sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf_AUX_Rules2C_Aux45_1 , lf_AUX_Rules2C_Aux45_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_2 , lf_AUX_Rules2C_Aux45_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf_AUX_Rules2C_Aux45_3 , lf_AUX_Rules2C_Aux45_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_4 , lf_AUX_Rules2C_Aux45_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_5 , lf_AUX_Rules2C_Aux45_5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Rules2C_Aux45_6 , lf_AUX_Rules2C_Aux45_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_7 , lf_AUX_Rules2C_Aux45_7sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux45_8 , lf_AUX_Rules2C_Aux45_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_9 , lf_AUX_Rules2C_Aux45_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_10 , lf_AUX_Rules2C_Aux45_10sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_11 , lf_AUX_Rules2C_Aux45_11sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_12 , lf_AUX_Rules2C_Aux45_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_13 , lf_AUX_Rules2C_Aux45_13sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux45_14 , lf_AUX_Rules2C_Aux45_14sym);
}
void resolve_AUX_Rules2C_Aux45( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Rules2C_Aux45_14( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux45_14);
return make_nf2( lf_AUX_Rules2C_Aux45_14sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux45_8( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux45_8);
return make_nf1( lf_AUX_Rules2C_Aux45_8sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux45_13( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
PROF( prof_lf_AUX_Rules2C_Aux45_13);
return make_nf5( lf_AUX_Rules2C_Aux45_13sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
aterm * lf_AUX_Rules2C_Aux45_12( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux45_12);
return make_nf2( lf_AUX_Rules2C_Aux45_12sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux45_11( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Rules2C_Aux45_11);
return make_nf3( lf_AUX_Rules2C_Aux45_11sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Rules2C_Aux45_10( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux45_10);
return make_nf2( lf_AUX_Rules2C_Aux45_10sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux45_9( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux45_9);
return make_nf1( lf_AUX_Rules2C_Aux45_9sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux45_6( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux45_6);
return make_nf1( lf_AUX_Rules2C_Aux45_6sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux45_3( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux45_3);
return make_nf1( lf_AUX_Rules2C_Aux45_3sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux45_7( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
PROF( prof_lf_AUX_Rules2C_Aux45_7);
return make_nf5( lf_AUX_Rules2C_Aux45_7sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
aterm * lf_AUX_Rules2C_Aux45_5( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux45_5);
return make_nf1( lf_AUX_Rules2C_Aux45_5sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux45_4( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux45_4);
return make_nf1( lf_AUX_Rules2C_Aux45_4sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux45_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux45_1);
return make_nf1( lf_AUX_Rules2C_Aux45_1sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux45_2( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux45_2);
return make_nf2( lf_AUX_Rules2C_Aux45_2sym , arg0 , arg1);
}

