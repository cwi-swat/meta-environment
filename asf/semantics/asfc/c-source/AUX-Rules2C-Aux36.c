#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux36_2sym;
static aterm * lf_AUX_Rules2C_Aux36_2( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux36_1sym;
static aterm * lf_AUX_Rules2C_Aux36_1( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux36_4sym;
static aterm * lf_AUX_Rules2C_Aux36_4( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux36_6sym;
static aterm * lf_AUX_Rules2C_Aux36_6( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * lf_AUX_Rules2C_Aux36_3sym;
static aterm * lf_AUX_Rules2C_Aux36_3( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux36_5sym;
static aterm * lf_AUX_Rules2C_Aux36_5( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux36_8sym;
static aterm * lf_AUX_Rules2C_Aux36_8( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux36_9sym;
static aterm * lf_AUX_Rules2C_Aux36_9( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux36_10sym;
static aterm * lf_AUX_Rules2C_Aux36_10( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux36_11sym;
static aterm * lf_AUX_Rules2C_Aux36_11( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4 , aterm * arg5);
static asymbol * lf_AUX_Rules2C_Aux36_7sym;
static aterm * lf_AUX_Rules2C_Aux36_7( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux36_12sym;
static aterm * lf_AUX_Rules2C_Aux36_12( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_Rules2C_Aux36_13sym;
static aterm * lf_AUX_Rules2C_Aux36_13( aterm * arg1);
void register_AUX_Rules2C_Aux36( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux36_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Rules2C_Aux36_1sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux36_4sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux36_6sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux36_3sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux36_5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux36_8sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux36_9sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux36_10sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux36_11sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux36_7sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux36_12sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Rules2C_Aux36_13sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"is-special-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf_AUX_Rules2C_Aux36_1 , lf_AUX_Rules2C_Aux36_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_2 , lf_AUX_Rules2C_Aux36_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf_AUX_Rules2C_Aux36_3 , lf_AUX_Rules2C_Aux36_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_4 , lf_AUX_Rules2C_Aux36_4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Rules2C_Aux36_5 , lf_AUX_Rules2C_Aux36_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_6 , lf_AUX_Rules2C_Aux36_6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux36_7 , lf_AUX_Rules2C_Aux36_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_8 , lf_AUX_Rules2C_Aux36_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_9 , lf_AUX_Rules2C_Aux36_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FV-PathList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PathList-Cenv\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_10 , lf_AUX_Rules2C_Aux36_10sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_11 , lf_AUX_Rules2C_Aux36_11sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_12 , lf_AUX_Rules2C_Aux36_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"is-special-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux36_13 , lf_AUX_Rules2C_Aux36_13sym);
}
void resolve_AUX_Rules2C_Aux36( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Rules2C_Aux36_13( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux36_13);
return make_nf1( lf_AUX_Rules2C_Aux36_13sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux36_12( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux36_12);
return make_nf2( lf_AUX_Rules2C_Aux36_12sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux36_7( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux36_7);
return make_nf1( lf_AUX_Rules2C_Aux36_7sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux36_11( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
PROF( prof_lf_AUX_Rules2C_Aux36_11);
return make_nf5( lf_AUX_Rules2C_Aux36_11sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
aterm * lf_AUX_Rules2C_Aux36_10( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux36_10);
return make_nf2( lf_AUX_Rules2C_Aux36_10sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux36_9( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux36_9);
return make_nf2( lf_AUX_Rules2C_Aux36_9sym , arg0 , arg1);
}
aterm * lf_AUX_Rules2C_Aux36_8( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux36_8);
return make_nf1( lf_AUX_Rules2C_Aux36_8sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux36_5( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux36_5);
return make_nf1( lf_AUX_Rules2C_Aux36_5sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux36_3( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux36_3);
return make_nf1( lf_AUX_Rules2C_Aux36_3sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux36_6( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4) {
PROF( prof_lf_AUX_Rules2C_Aux36_6);
return make_nf5( lf_AUX_Rules2C_Aux36_6sym , arg0 , arg1 , arg2 , arg3 , arg4);
}
aterm * lf_AUX_Rules2C_Aux36_4( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux36_4);
return make_nf1( lf_AUX_Rules2C_Aux36_4sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux36_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux36_1);
return make_nf1( lf_AUX_Rules2C_Aux36_1sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux36_2( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Rules2C_Aux36_2);
return make_nf2( lf_AUX_Rules2C_Aux36_2sym , arg0 , arg1);
}

