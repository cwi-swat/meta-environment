#include "support.h"
static asymbol * lf_AUX_MuASF_Basics28_3sym;
static aterm * lf_AUX_MuASF_Basics28_3( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_MuASF_Basics28_4sym;
static aterm * lf_AUX_MuASF_Basics28_4( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_MuASF_Basics28_5sym;
static aterm * lf_AUX_MuASF_Basics28_5( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_MuASF_Basics28_6sym;
static aterm * lf_AUX_MuASF_Basics28_6( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_MuASF_Basics28_8sym;
static aterm * lf_AUX_MuASF_Basics28_8( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * lf_AUX_MuASF_Basics28_1sym;
static aterm * lf_AUX_MuASF_Basics28_1( aterm * arg1);
static asymbol * lf_AUX_MuASF_Basics28_7sym;
static aterm * lf_AUX_MuASF_Basics28_7( aterm * arg1);
static asymbol * lf_AUX_MuASF_Basics28_9sym;
static aterm * lf_AUX_MuASF_Basics28_9( aterm * arg1 , aterm * arg2);
static asymbol * lf_AUX_MuASF_Basics28_2sym;
static aterm * lf_AUX_MuASF_Basics28_2( aterm * arg1);
void register_AUX_MuASF_Basics28( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics28_3sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Basics28_4sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRulePair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuASF_Basics28_5sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuASF_Basics28_6sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuASF_Basics28_8sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuASF_Basics28_1sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf_AUX_MuASF_Basics28_7sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_MuASF_Basics28_9sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_MuASF_Basics28_2sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_MuASF_Basics28_1 , lf_AUX_MuASF_Basics28_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_MuASF_Basics28_2 , lf_AUX_MuASF_Basics28_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics28_3 , lf_AUX_MuASF_Basics28_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRulePair\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics28_4 , lf_AUX_MuASF_Basics28_4sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics28_5 , lf_AUX_MuASF_Basics28_5sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics28_6 , lf_AUX_MuASF_Basics28_6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_MuASF_Basics28_7 , lf_AUX_MuASF_Basics28_7sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics28_8 , lf_AUX_MuASF_Basics28_8sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics28_9 , lf_AUX_MuASF_Basics28_9sym);
}
void resolve_AUX_MuASF_Basics28( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_MuASF_Basics28_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics28_2);
return make_nf1( lf_AUX_MuASF_Basics28_2sym , arg0);
}
aterm * lf_AUX_MuASF_Basics28_9( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_MuASF_Basics28_9);
return make_nf2( lf_AUX_MuASF_Basics28_9sym , arg0 , arg1);
}
aterm * lf_AUX_MuASF_Basics28_7( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics28_7);
return make_nf1( lf_AUX_MuASF_Basics28_7sym , arg0);
}
aterm * lf_AUX_MuASF_Basics28_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics28_1);
return make_nf1( lf_AUX_MuASF_Basics28_1sym , arg0);
}
aterm * lf_AUX_MuASF_Basics28_8( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_MuASF_Basics28_8);
return make_nf3( lf_AUX_MuASF_Basics28_8sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_MuASF_Basics28_6( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_MuASF_Basics28_6);
return make_nf3( lf_AUX_MuASF_Basics28_6sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_MuASF_Basics28_5( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_MuASF_Basics28_5);
return make_nf3( lf_AUX_MuASF_Basics28_5sym , arg0 , arg1 , arg2);
}
aterm * lf_AUX_MuASF_Basics28_4( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_MuASF_Basics28_4);
return make_nf2( lf_AUX_MuASF_Basics28_4sym , arg0 , arg1);
}
aterm * lf_AUX_MuASF_Basics28_3( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_MuASF_Basics28_3);
return make_nf3( lf_AUX_MuASF_Basics28_3sym , arg0 , arg1 , arg2);
}

