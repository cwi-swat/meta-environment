#include  "asc-support.h"
static Symbol lf_AUX_AsFix_Basics1_2sym ;
static ATerm lf_AUX_AsFix_Basics1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_AsFix_Basics1_1sym ;
static ATerm lf_AUX_AsFix_Basics1_1 ( ATerm arg1 ) ;
void register_AUX_AsFix_Basics1 ( ) {
lf_AUX_AsFix_Basics1_2sym = ATmakeSymbol ( "prod(id(\"AsFix-Basics\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SortList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix_Basics1_2sym ) ;
lf_AUX_AsFix_Basics1_1sym = ATmakeSymbol ( "listtype(sort(\"ATerm\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix_Basics1_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"ATerm\"),ql(\";\"))" ) , lf_AUX_AsFix_Basics1_1 , lf_AUX_AsFix_Basics1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix-Basics\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SortList\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix_Basics1_2 , lf_AUX_AsFix_Basics1_2sym ) ;
}
void resolve_AUX_AsFix_Basics1 ( ) {
}
void init_AUX_AsFix_Basics1 ( ) {
}
ATerm lf_AUX_AsFix_Basics1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_AsFix_Basics1_1sym , ATmakeAppl ( lf_AUX_AsFix_Basics1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_AsFix_Basics1_1sym , arg0 ) ) ;
}
ATerm lf_AUX_AsFix_Basics1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_AsFix_Basics1_2sym , ATmakeAppl ( lf_AUX_AsFix_Basics1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_AsFix_Basics1_2sym , arg0 ) ) ;
}

