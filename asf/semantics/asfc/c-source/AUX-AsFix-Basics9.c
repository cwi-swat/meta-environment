#include "support.h"
static Symbol lf_AUX_AsFix_Basics9_2sym;
static ATerm lf_AUX_AsFix_Basics9_2( ATerm arg1);
static Symbol lf_AUX_AsFix_Basics9_1sym;
static ATerm lf_AUX_AsFix_Basics9_1( ATerm arg1);
void register_AUX_AsFix_Basics9( ) {
lf_AUX_AsFix_Basics9_2sym= ATmakeSymbol( "prod(id(\"AsFix-Basics\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SortList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix_Basics9_2sym);
lf_AUX_AsFix_Basics9_1sym= ATmakeSymbol( "listtype(sort(\"ATerm\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_AsFix_Basics9_1sym);
register_prod( ATparse( "listtype(sort(\"ATerm\"),ql(\";\"))") , lf_AUX_AsFix_Basics9_1 , lf_AUX_AsFix_Basics9_1sym);
register_prod( ATparse( "prod(id(\"AsFix-Basics\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SortList\"),w(\"\"),no-attrs)") , lf_AUX_AsFix_Basics9_2 , lf_AUX_AsFix_Basics9_2sym);
}
void resolve_AUX_AsFix_Basics9( ) {
}
void init_AUX_AsFix_Basics9( ) {
}
ATerm lf_AUX_AsFix_Basics9_1( ATerm arg0) {
PROF( prof_lf_AUX_AsFix_Basics9_1);
return make_nf1( lf_AUX_AsFix_Basics9_1sym , arg0);
}
ATerm lf_AUX_AsFix_Basics9_2( ATerm arg0) {
PROF( prof_lf_AUX_AsFix_Basics9_2);
return make_nf1( lf_AUX_AsFix_Basics9_2sym , arg0);
}

