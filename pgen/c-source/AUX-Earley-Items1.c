#include  "asc-support.h"
static Symbol lf_AUX_Earley_Items1_1sym ;
static ATerm lf_AUX_Earley_Items1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Earley_Items1_3sym ;
static ATerm lf_AUX_Earley_Items1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Earley_Items1_2sym ;
static ATerm lf_AUX_Earley_Items1_2 ( ATerm arg1 ) ;
void register_AUX_Earley_Items1 ( ) {
lf_AUX_Earley_Items1_1sym = ATmakeSymbol ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Earley_Items1_1sym ) ;
lf_AUX_Earley_Items1_3sym = ATmakeSymbol ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Earley_Items1_3sym ) ;
lf_AUX_Earley_Items1_2sym = ATmakeSymbol ( "listtype(sort(\"Item\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Earley_Items1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Item\"),w(\"\"),no-attrs)" ) , lf_AUX_Earley_Items1_1 , lf_AUX_Earley_Items1_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Item\"))" ) , lf_AUX_Earley_Items1_2 , lf_AUX_Earley_Items1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Earley_Items1_3 , lf_AUX_Earley_Items1_3sym ) ;
}
void resolve_AUX_Earley_Items1 ( ) {
}
void init_AUX_Earley_Items1 ( ) {
}
ATerm lf_AUX_Earley_Items1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Earley_Items1_2sym , ATmakeAppl ( lf_AUX_Earley_Items1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Earley_Items1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Earley_Items1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Earley_Items1_3sym , ATmakeAppl ( lf_AUX_Earley_Items1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Earley_Items1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Earley_Items1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Earley_Items1_1sym , ATmakeAppl ( lf_AUX_Earley_Items1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Earley_Items1_1sym , arg0 , arg1 ) ) ;
}

