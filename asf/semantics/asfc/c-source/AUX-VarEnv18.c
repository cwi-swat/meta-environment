#include "support.h"
static Symbol lf_AUX_VarEnv18_2sym;
static ATerm lf_AUX_VarEnv18_2( ATerm arg1);
static Symbol lf_AUX_VarEnv18_3sym;
static ATerm lf_AUX_VarEnv18_3( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_VarEnv18_4sym;
static ATerm lf_AUX_VarEnv18_4( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_VarEnv18_6sym;
static ATerm lf_AUX_VarEnv18_6( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_VarEnv18_5sym;
static ATerm lf_AUX_VarEnv18_5( ATerm arg1);
static Symbol lf_AUX_VarEnv18_7sym;
static ATerm lf_AUX_VarEnv18_7( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_VarEnv18_9sym;
static ATerm lf_AUX_VarEnv18_9( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_VarEnv18_1sym;
static ATerm lf_AUX_VarEnv18_1( ATerm arg1);
static Symbol lf_AUX_VarEnv18_10sym;
static ATerm lf_AUX_VarEnv18_10( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_VarEnv18_8sym;
static ATerm lf_AUX_VarEnv18_8( ATerm arg1);
static Symbol lf_AUX_VarEnv18_11sym;
static ATerm lf_AUX_VarEnv18_11( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_VarEnv18_13sym;
static ATerm lf_AUX_VarEnv18_13( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4);
static Symbol lf_AUX_VarEnv18_12sym;
static ATerm lf_AUX_VarEnv18_12( ATerm arg1);
static Symbol lf_AUX_VarEnv18_14sym;
static ATerm lf_AUX_VarEnv18_14( ATerm arg1 , ATerm arg2);
void register_AUX_VarEnv18( ) {
lf_AUX_VarEnv18_2sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_2sym);
lf_AUX_VarEnv18_3sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_3sym);
lf_AUX_VarEnv18_4sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_4sym);
lf_AUX_VarEnv18_6sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_6sym);
lf_AUX_VarEnv18_5sym= ATmakeSymbol( "listtype(sort(\"VV-Pair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_5sym);
lf_AUX_VarEnv18_7sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_7sym);
lf_AUX_VarEnv18_9sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_9sym);
lf_AUX_VarEnv18_1sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_1sym);
lf_AUX_VarEnv18_10sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_10sym);
lf_AUX_VarEnv18_8sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_8sym);
lf_AUX_VarEnv18_11sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_11sym);
lf_AUX_VarEnv18_13sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)" , 4 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_13sym);
lf_AUX_VarEnv18_12sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_12sym);
lf_AUX_VarEnv18_14sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv18_14sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_VarEnv18_1 , lf_AUX_VarEnv18_1sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_2 , lf_AUX_VarEnv18_2sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_3 , lf_AUX_VarEnv18_3sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_4 , lf_AUX_VarEnv18_4sym);
register_prod( ATparse( "listtype(sort(\"VV-Pair\"),ql(\",\"))") , lf_AUX_VarEnv18_5 , lf_AUX_VarEnv18_5sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_6 , lf_AUX_VarEnv18_6sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_7 , lf_AUX_VarEnv18_7sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_VarEnv18_8 , lf_AUX_VarEnv18_8sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_9 , lf_AUX_VarEnv18_9sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_10 , lf_AUX_VarEnv18_10sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_11 , lf_AUX_VarEnv18_11sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_VarEnv18_12 , lf_AUX_VarEnv18_12sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_13 , lf_AUX_VarEnv18_13sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_14 , lf_AUX_VarEnv18_14sym);
}
void resolve_AUX_VarEnv18( ) {
}
void init_AUX_VarEnv18( ) {
}
ATerm lf_AUX_VarEnv18_14( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_VarEnv18_14);
return make_nf2( lf_AUX_VarEnv18_14sym , arg0 , arg1);
}
ATerm lf_AUX_VarEnv18_12( ATerm arg0) {
PROF( prof_lf_AUX_VarEnv18_12);
return make_nf1( lf_AUX_VarEnv18_12sym , arg0);
}
ATerm lf_AUX_VarEnv18_13( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3) {
PROF( prof_lf_AUX_VarEnv18_13);
return make_nf4( lf_AUX_VarEnv18_13sym , arg0 , arg1 , arg2 , arg3);
}
ATerm lf_AUX_VarEnv18_11( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_VarEnv18_11);
return make_nf2( lf_AUX_VarEnv18_11sym , arg0 , arg1);
}
ATerm lf_AUX_VarEnv18_8( ATerm arg0) {
PROF( prof_lf_AUX_VarEnv18_8);
return make_nf1( lf_AUX_VarEnv18_8sym , arg0);
}
ATerm lf_AUX_VarEnv18_10( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_VarEnv18_10);
return make_nf2( lf_AUX_VarEnv18_10sym , arg0 , arg1);
}
ATerm lf_AUX_VarEnv18_1( ATerm arg0) {
PROF( prof_lf_AUX_VarEnv18_1);
return make_nf1( lf_AUX_VarEnv18_1sym , arg0);
}
ATerm lf_AUX_VarEnv18_9( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_VarEnv18_9);
return make_nf3( lf_AUX_VarEnv18_9sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_VarEnv18_7( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_VarEnv18_7);
return make_nf2( lf_AUX_VarEnv18_7sym , arg0 , arg1);
}
ATerm lf_AUX_VarEnv18_5( ATerm arg0) {
PROF( prof_lf_AUX_VarEnv18_5);
return make_nf1( lf_AUX_VarEnv18_5sym , arg0);
}
ATerm lf_AUX_VarEnv18_6( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_VarEnv18_6);
return make_nf2( lf_AUX_VarEnv18_6sym , arg0 , arg1);
}
ATerm lf_AUX_VarEnv18_4( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_VarEnv18_4);
return make_nf2( lf_AUX_VarEnv18_4sym , arg0 , arg1);
}
ATerm lf_AUX_VarEnv18_3( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_VarEnv18_3);
return make_nf2( lf_AUX_VarEnv18_3sym , arg0 , arg1);
}
ATerm lf_AUX_VarEnv18_2( ATerm arg0) {
PROF( prof_lf_AUX_VarEnv18_2);
return make_nf1( lf_AUX_VarEnv18_2sym , arg0);
}

