#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux44_2sym;
static aterm * lf_AUX_Rules2C_Aux44_2( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux44_1sym;
static aterm * lf_AUX_Rules2C_Aux44_1( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux44_4sym;
static aterm * lf_AUX_Rules2C_Aux44_4( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux44_5sym;
static aterm * lf_AUX_Rules2C_Aux44_5( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux44_7sym;
static aterm * lf_AUX_Rules2C_Aux44_7( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * lf_AUX_Rules2C_Aux44_3sym;
static aterm * lf_AUX_Rules2C_Aux44_3( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux44_6sym;
static aterm * lf_AUX_Rules2C_Aux44_6( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux44_9sym;
static aterm * lf_AUX_Rules2C_Aux44_9( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux44_10sym;
static aterm * lf_AUX_Rules2C_Aux44_10( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux44_11sym;
static aterm * lf_AUX_Rules2C_Aux44_11( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_Rules2C_Aux44_12sym;
static aterm * lf_AUX_Rules2C_Aux44_12( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux44_13sym;
static aterm * lf_AUX_Rules2C_Aux44_13( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * lf_AUX_Rules2C_Aux44_8sym;
static aterm * lf_AUX_Rules2C_Aux44_8( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux44_14sym;
static aterm * lf_AUX_Rules2C_Aux44_14( aterm * arg1 , aterm * arg2);
void register_AUX_Rules2C_Aux44( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux44_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Rules2C_Aux44_1sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux44_4sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux44_5sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux44_7sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux44_3sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux44_6sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux44_9sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux44_10sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux44_11sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux44_12sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux44_13sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux44_8sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux44_14sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf_AUX_Rules2C_Aux44_1 , lf_AUX_Rules2C_Aux44_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_2 , lf_AUX_Rules2C_Aux44_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf_AUX_Rules2C_Aux44_3 , lf_AUX_Rules2C_Aux44_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_4 , lf_AUX_Rules2C_Aux44_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_5 , lf_AUX_Rules2C_Aux44_5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Rules2C_Aux44_6 , lf_AUX_Rules2C_Aux44_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_7 , lf_AUX_Rules2C_Aux44_7sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux44_8 , lf_AUX_Rules2C_Aux44_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_9 , lf_AUX_Rules2C_Aux44_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_10 , lf_AUX_Rules2C_Aux44_10sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListTriple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_11 , lf_AUX_Rules2C_Aux44_11sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_12 , lf_AUX_Rules2C_Aux44_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_13 , lf_AUX_Rules2C_Aux44_13sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux44_14 , lf_AUX_Rules2C_Aux44_14sym);
}
void resolve_AUX_Rules2C_Aux44( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Rules2C_Aux44_14( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux44_14);
return make_nf2( lf_AUX_Rules2C_Aux44_14sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux44_8( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux44_8);
return make_nf1( lf_AUX_Rules2C_Aux44_8sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux44_13( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
PROF( prof_lf_AUX_Rules2C_Aux44_13);
return make_nf5( lf_AUX_Rules2C_Aux44_13sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
aterm * lf_AUX_Rules2C_Aux44_12( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux44_12);
return make_nf2( lf_AUX_Rules2C_Aux44_12sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux44_11( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_Rules2C_Aux44_11);
return make_nf3( lf_AUX_Rules2C_Aux44_11sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_Rules2C_Aux44_10( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux44_10);
return make_nf2( lf_AUX_Rules2C_Aux44_10sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux44_9( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux44_9);
return make_nf1( lf_AUX_Rules2C_Aux44_9sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux44_6( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux44_6);
return make_nf1( lf_AUX_Rules2C_Aux44_6sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux44_3( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux44_3);
return make_nf1( lf_AUX_Rules2C_Aux44_3sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux44_7( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
PROF( prof_lf_AUX_Rules2C_Aux44_7);
return make_nf5( lf_AUX_Rules2C_Aux44_7sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
aterm * lf_AUX_Rules2C_Aux44_5( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux44_5);
return make_nf1( lf_AUX_Rules2C_Aux44_5sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux44_4( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux44_4);
return make_nf1( lf_AUX_Rules2C_Aux44_4sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux44_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux44_1);
return make_nf1( lf_AUX_Rules2C_Aux44_1sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux44_2( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux44_2);
return make_nf2( lf_AUX_Rules2C_Aux44_2sym , arg0 , arg1);
}

