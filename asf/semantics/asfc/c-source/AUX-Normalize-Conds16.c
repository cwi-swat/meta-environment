#include "support.h"
static Symbol lf_AUX_Normalize_Conds16_3sym;
static ATerm lf_AUX_Normalize_Conds16_3( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Normalize_Conds16_1sym;
static ATerm lf_AUX_Normalize_Conds16_1( ATerm arg1);
static Symbol lf_AUX_Normalize_Conds16_2sym;
static ATerm lf_AUX_Normalize_Conds16_2( ATerm arg1);
void register_AUX_Normalize_Conds16( ) {
lf_AUX_Normalize_Conds16_3sym= ATmakeSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Normalize_Conds16_3sym);
lf_AUX_Normalize_Conds16_1sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Normalize_Conds16_1sym);
lf_AUX_Normalize_Conds16_2sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Normalize_Conds16_2sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Normalize_Conds16_1 , lf_AUX_Normalize_Conds16_1sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Normalize_Conds16_2 , lf_AUX_Normalize_Conds16_2sym);
register_prod( ATparse( "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds16_3 , lf_AUX_Normalize_Conds16_3sym);
}
void resolve_AUX_Normalize_Conds16( ) {
}
void init_AUX_Normalize_Conds16( ) {
}
ATerm lf_AUX_Normalize_Conds16_2( ATerm arg0) {
PROF( prof_lf_AUX_Normalize_Conds16_2);
return make_nf1( lf_AUX_Normalize_Conds16_2sym , arg0);
}
ATerm lf_AUX_Normalize_Conds16_1( ATerm arg0) {
PROF( prof_lf_AUX_Normalize_Conds16_1);
return make_nf1( lf_AUX_Normalize_Conds16_1sym , arg0);
}
ATerm lf_AUX_Normalize_Conds16_3( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Normalize_Conds16_3);
return make_nf3( lf_AUX_Normalize_Conds16_3sym , arg0 , arg1 , arg2);
}

