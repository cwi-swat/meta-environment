#include  "asc-support.h"
static Symbol lf_AUX_Earley_Graphs1_1sym ;
static ATerm lf_AUX_Earley_Graphs1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Earley_Graphs1_2sym ;
static ATerm lf_AUX_Earley_Graphs1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Earley_Graphs1_3sym ;
static ATerm lf_AUX_Earley_Graphs1_3 ( ATerm arg1 ) ;
void register_AUX_Earley_Graphs1 ( ) {
lf_AUX_Earley_Graphs1_1sym = ATmakeSymbol ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Earley_Graphs1_1sym ) ;
lf_AUX_Earley_Graphs1_2sym = ATmakeSymbol ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Earley_Graphs1_2sym ) ;
lf_AUX_Earley_Graphs1_3sym = ATmakeSymbol ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Earley_Graphs1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) , lf_AUX_Earley_Graphs1_1 , lf_AUX_Earley_Graphs1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"Production\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) , lf_AUX_Earley_Graphs1_2 , lf_AUX_Earley_Graphs1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) , lf_AUX_Earley_Graphs1_3 , lf_AUX_Earley_Graphs1_3sym ) ;
}
void resolve_AUX_Earley_Graphs1 ( ) {
}
void init_AUX_Earley_Graphs1 ( ) {
}
ATerm lf_AUX_Earley_Graphs1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Earley_Graphs1_3sym , ATmakeAppl ( lf_AUX_Earley_Graphs1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Earley_Graphs1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Earley_Graphs1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Earley_Graphs1_2sym , ATmakeAppl ( lf_AUX_Earley_Graphs1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Earley_Graphs1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Earley_Graphs1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Earley_Graphs1_1sym , ATmakeAppl ( lf_AUX_Earley_Graphs1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Earley_Graphs1_1sym , arg0 ) ) ;
}

