#include "support.h"
static Symbol lf_AUX_MuASF_Basics31_3sym;
static ATerm lf_AUX_MuASF_Basics31_3( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_MuASF_Basics31_4sym;
static ATerm lf_AUX_MuASF_Basics31_4( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_MuASF_Basics31_5sym;
static ATerm lf_AUX_MuASF_Basics31_5( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_MuASF_Basics31_6sym;
static ATerm lf_AUX_MuASF_Basics31_6( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_MuASF_Basics31_8sym;
static ATerm lf_AUX_MuASF_Basics31_8( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_MuASF_Basics31_1sym;
static ATerm lf_AUX_MuASF_Basics31_1( ATerm arg1);
static Symbol lf_AUX_MuASF_Basics31_7sym;
static ATerm lf_AUX_MuASF_Basics31_7( ATerm arg1);
static Symbol lf_AUX_MuASF_Basics31_9sym;
static ATerm lf_AUX_MuASF_Basics31_9( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_MuASF_Basics31_2sym;
static ATerm lf_AUX_MuASF_Basics31_2( ATerm arg1);
void register_AUX_MuASF_Basics31( ) {
lf_AUX_MuASF_Basics31_3sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_3sym);
lf_AUX_MuASF_Basics31_4sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRulePair\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_4sym);
lf_AUX_MuASF_Basics31_5sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_5sym);
lf_AUX_MuASF_Basics31_6sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_6sym);
lf_AUX_MuASF_Basics31_8sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_8sym);
lf_AUX_MuASF_Basics31_1sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_1sym);
lf_AUX_MuASF_Basics31_7sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_7sym);
lf_AUX_MuASF_Basics31_9sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_9sym);
lf_AUX_MuASF_Basics31_2sym= ATmakeSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics31_2sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_MuASF_Basics31_1 , lf_AUX_MuASF_Basics31_1sym);
register_prod( ATparse( "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_MuASF_Basics31_2 , lf_AUX_MuASF_Basics31_2sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics31_3 , lf_AUX_MuASF_Basics31_3sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRulePair\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics31_4 , lf_AUX_MuASF_Basics31_4sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics31_5 , lf_AUX_MuASF_Basics31_5sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics31_6 , lf_AUX_MuASF_Basics31_6sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_MuASF_Basics31_7 , lf_AUX_MuASF_Basics31_7sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics31_8 , lf_AUX_MuASF_Basics31_8sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics31_9 , lf_AUX_MuASF_Basics31_9sym);
}
void resolve_AUX_MuASF_Basics31( ) {
}
void init_AUX_MuASF_Basics31( ) {
}
ATerm lf_AUX_MuASF_Basics31_2( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Basics31_2);
return make_nf1( lf_AUX_MuASF_Basics31_2sym , arg0);
}
ATerm lf_AUX_MuASF_Basics31_9( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_MuASF_Basics31_9);
return make_nf2( lf_AUX_MuASF_Basics31_9sym , arg0 , arg1);
}
ATerm lf_AUX_MuASF_Basics31_7( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Basics31_7);
return make_nf1( lf_AUX_MuASF_Basics31_7sym , arg0);
}
ATerm lf_AUX_MuASF_Basics31_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Basics31_1);
return make_nf1( lf_AUX_MuASF_Basics31_1sym , arg0);
}
ATerm lf_AUX_MuASF_Basics31_8( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_MuASF_Basics31_8);
return make_nf3( lf_AUX_MuASF_Basics31_8sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_MuASF_Basics31_6( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_MuASF_Basics31_6);
return make_nf3( lf_AUX_MuASF_Basics31_6sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_MuASF_Basics31_5( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_MuASF_Basics31_5);
return make_nf3( lf_AUX_MuASF_Basics31_5sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_MuASF_Basics31_4( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_MuASF_Basics31_4);
return make_nf2( lf_AUX_MuASF_Basics31_4sym , arg0 , arg1);
}
ATerm lf_AUX_MuASF_Basics31_3( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_MuASF_Basics31_3);
return make_nf3( lf_AUX_MuASF_Basics31_3sym , arg0 , arg1 , arg2);
}

