#include "support.h"
static Symbol lf_AUX_RenameVars7_1sym;
static ATerm lf_AUX_RenameVars7_1( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_RenameVars7_3sym;
static ATerm lf_AUX_RenameVars7_3( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_RenameVars7_2sym;
static ATerm lf_AUX_RenameVars7_2( ATerm arg1);
static Symbol lf_AUX_RenameVars7_4sym;
static ATerm lf_AUX_RenameVars7_4( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_RenameVars7_6sym;
static ATerm lf_AUX_RenameVars7_6( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_RenameVars7_5sym;
static ATerm lf_AUX_RenameVars7_5( ATerm arg1);
void register_AUX_RenameVars7( ) {
lf_AUX_RenameVars7_1sym= ATmakeSymbol( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_RenameVars7_1sym);
lf_AUX_RenameVars7_3sym= ATmakeSymbol( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_RenameVars7_3sym);
lf_AUX_RenameVars7_2sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_RenameVars7_2sym);
lf_AUX_RenameVars7_4sym= ATmakeSymbol( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_RenameVars7_4sym);
lf_AUX_RenameVars7_6sym= ATmakeSymbol( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_RenameVars7_6sym);
lf_AUX_RenameVars7_5sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_RenameVars7_5sym);
register_prod( ATparse( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars7_1 , lf_AUX_RenameVars7_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_RenameVars7_2 , lf_AUX_RenameVars7_2sym);
register_prod( ATparse( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars7_3 , lf_AUX_RenameVars7_3sym);
register_prod( ATparse( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars7_4 , lf_AUX_RenameVars7_4sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_RenameVars7_5 , lf_AUX_RenameVars7_5sym);
register_prod( ATparse( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars7_6 , lf_AUX_RenameVars7_6sym);
}
void resolve_AUX_RenameVars7( ) {
}
void init_AUX_RenameVars7( ) {
}
ATerm lf_AUX_RenameVars7_5( ATerm arg0) {
PROF( prof_lf_AUX_RenameVars7_5);
return make_nf1( lf_AUX_RenameVars7_5sym , arg0);
}
ATerm lf_AUX_RenameVars7_6( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_RenameVars7_6);
return make_nf2( lf_AUX_RenameVars7_6sym , arg0 , arg1);
}
ATerm lf_AUX_RenameVars7_4( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_RenameVars7_4);
return make_nf2( lf_AUX_RenameVars7_4sym , arg0 , arg1);
}
ATerm lf_AUX_RenameVars7_2( ATerm arg0) {
PROF( prof_lf_AUX_RenameVars7_2);
return make_nf1( lf_AUX_RenameVars7_2sym , arg0);
}
ATerm lf_AUX_RenameVars7_3( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_RenameVars7_3);
return make_nf2( lf_AUX_RenameVars7_3sym , arg0 , arg1);
}
ATerm lf_AUX_RenameVars7_1( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_RenameVars7_1);
return make_nf2( lf_AUX_RenameVars7_1sym , arg0 , arg1);
}

