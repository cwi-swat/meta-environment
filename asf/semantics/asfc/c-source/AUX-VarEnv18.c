#include "support.h"
static asymbol * lf_AUX_VarEnv18_2sym;
static aterm * lf_AUX_VarEnv18_2( aterm * arg1);
static asymbol * lf_AUX_VarEnv18_3sym;
static aterm * lf_AUX_VarEnv18_3( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_VarEnv18_4sym;
static aterm * lf_AUX_VarEnv18_4( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_VarEnv18_6sym;
static aterm * lf_AUX_VarEnv18_6( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_VarEnv18_5sym;
static aterm * lf_AUX_VarEnv18_5( aterm * arg1);
static asymbol * lf_AUX_VarEnv18_7sym;
static aterm * lf_AUX_VarEnv18_7( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_VarEnv18_9sym;
static aterm * lf_AUX_VarEnv18_9( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_VarEnv18_1sym;
static aterm * lf_AUX_VarEnv18_1( aterm * arg1);
static asymbol * lf_AUX_VarEnv18_10sym;
static aterm * lf_AUX_VarEnv18_10( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_VarEnv18_8sym;
static aterm * lf_AUX_VarEnv18_8( aterm * arg1);
static asymbol * lf_AUX_VarEnv18_11sym;
static aterm * lf_AUX_VarEnv18_11( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_VarEnv18_13sym;
static aterm * lf_AUX_VarEnv18_13( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4);
static asymbol * lf_AUX_VarEnv18_12sym;
static aterm * lf_AUX_VarEnv18_12( aterm * arg1);
static asymbol * lf_AUX_VarEnv18_14sym;
static aterm * lf_AUX_VarEnv18_14( aterm * arg1 , aterm * arg2);
void register_AUX_VarEnv18( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_VarEnv18_2sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_VarEnv18_3sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_VarEnv18_4sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_VarEnv18_6sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_VarEnv18_5sym= TmkSymbol( "listtype(sort(\"VV-Pair\"),ql(\",\"))" , SYM_STRING);
lf_AUX_VarEnv18_7sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_VarEnv18_9sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_VarEnv18_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf_AUX_VarEnv18_10sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_VarEnv18_8sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_VarEnv18_11sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_VarEnv18_13sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_VarEnv18_12sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
lf_AUX_VarEnv18_14sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_VarEnv18_1 , lf_AUX_VarEnv18_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_2 , lf_AUX_VarEnv18_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_3 , lf_AUX_VarEnv18_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_4 , lf_AUX_VarEnv18_4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"VV-Pair\"),ql(\",\"))") , lf_AUX_VarEnv18_5 , lf_AUX_VarEnv18_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_6 , lf_AUX_VarEnv18_6sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_7 , lf_AUX_VarEnv18_7sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_VarEnv18_8 , lf_AUX_VarEnv18_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_9 , lf_AUX_VarEnv18_9sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_10 , lf_AUX_VarEnv18_10sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_11 , lf_AUX_VarEnv18_11sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_VarEnv18_12 , lf_AUX_VarEnv18_12sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_13 , lf_AUX_VarEnv18_13sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv18_14 , lf_AUX_VarEnv18_14sym);
}
void resolve_AUX_VarEnv18( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_VarEnv18_14( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_VarEnv18_14);
return make_nf2( lf_AUX_VarEnv18_14sym , arg0 , arg1);
}
aterm * lf_AUX_VarEnv18_12( aterm * arg0) {
PROF( prof_lf_AUX_VarEnv18_12);
return make_nf1( lf_AUX_VarEnv18_12sym , arg0);
}
aterm * lf_AUX_VarEnv18_13( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3) {
PROF( prof_lf_AUX_VarEnv18_13);
return make_nf4( lf_AUX_VarEnv18_13sym , arg0 , arg1 , arg2 , arg3);
}
aterm * lf_AUX_VarEnv18_11( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_VarEnv18_11);
return make_nf2( lf_AUX_VarEnv18_11sym , arg0 , arg1);
}
aterm * lf_AUX_VarEnv18_8( aterm * arg0) {
PROF( prof_lf_AUX_VarEnv18_8);
return make_nf1( lf_AUX_VarEnv18_8sym , arg0);
}
aterm * lf_AUX_VarEnv18_10( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_VarEnv18_10);
return make_nf2( lf_AUX_VarEnv18_10sym , arg0 , arg1);
}
aterm * lf_AUX_VarEnv18_1( aterm * arg0) {
PROF( prof_lf_AUX_VarEnv18_1);
return make_nf1( lf_AUX_VarEnv18_1sym , arg0);
}
aterm * lf_AUX_VarEnv18_9( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_VarEnv18_9);
return make_nf3( lf_AUX_VarEnv18_9sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_VarEnv18_7( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_VarEnv18_7);
return make_nf2( lf_AUX_VarEnv18_7sym , arg0 , arg1);
}
aterm * lf_AUX_VarEnv18_5( aterm * arg0) {
PROF( prof_lf_AUX_VarEnv18_5);
return make_nf1( lf_AUX_VarEnv18_5sym , arg0);
}
aterm * lf_AUX_VarEnv18_6( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_VarEnv18_6);
return make_nf2( lf_AUX_VarEnv18_6sym , arg0 , arg1);
}
aterm * lf_AUX_VarEnv18_4( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_VarEnv18_4);
return make_nf2( lf_AUX_VarEnv18_4sym , arg0 , arg1);
}
aterm * lf_AUX_VarEnv18_3( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_VarEnv18_3);
return make_nf2( lf_AUX_VarEnv18_3sym , arg0 , arg1);
}
aterm * lf_AUX_VarEnv18_2( aterm * arg0) {
PROF( prof_lf_AUX_VarEnv18_2);
return make_nf1( lf_AUX_VarEnv18_2sym , arg0);
}

