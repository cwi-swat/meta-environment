#include  "asc-support.h"
static Symbol lf_AUX_Vertices1_1sym ;
static ATerm lf_AUX_Vertices1_1 ( ) ;
static Symbol lf_AUX_Vertices1_2sym ;
static ATerm lf_AUX_Vertices1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Vertices1_4sym ;
static ATerm lf_AUX_Vertices1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_Vertices1_3sym ;
static ATerm lf_AUX_Vertices1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Vertices1_5sym ;
static ATerm lf_AUX_Vertices1_5 ( ATerm arg1 ) ;
void register_AUX_Vertices1 ( ) {
lf_AUX_Vertices1_1sym = ATmakeSymbol ( "prod(id(\"Vertices\"),w(\"\"),[l(\"new-vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices1_1sym ) ;
lf_AUX_Vertices1_2sym = ATmakeSymbol ( "prod(id(\"Vertices\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices1_2sym ) ;
lf_AUX_Vertices1_4sym = ATmakeSymbol ( "prod(id(\"Vertices\"),w(\"\"),[iter(sort(\"Vertex\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertices\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices1_4sym ) ;
lf_AUX_Vertices1_3sym = ATmakeSymbol ( "listtype(sort(\"Vertex\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices1_3sym ) ;
lf_AUX_Vertices1_5sym = ATmakeSymbol ( "prod(id(\"Vertices\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Vertices\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VertexSet\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"Vertices\"),w(\"\"),[l(\"new-vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) , lf_AUX_Vertices1_1 , lf_AUX_Vertices1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Vertices\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Vertices1_2 , lf_AUX_Vertices1_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Vertex\"))" ) , lf_AUX_Vertices1_3 , lf_AUX_Vertices1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Vertices\"),w(\"\"),[iter(sort(\"Vertex\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertices\"),w(\"\"),no-attrs)" ) , lf_AUX_Vertices1_4 , lf_AUX_Vertices1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Vertices\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Vertices\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VertexSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Vertices1_5 , lf_AUX_Vertices1_5sym ) ;
}
void resolve_AUX_Vertices1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_Vertices1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Vertices1_5 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Vertices1_5sym , ATmakeAppl ( lf_AUX_Vertices1_5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Vertices1_5sym , arg0 ) ) ;
}
ATerm lf_AUX_Vertices1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Vertices1_3sym , ATmakeAppl ( lf_AUX_Vertices1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Vertices1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Vertices1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Vertices1_4sym , ATmakeAppl ( lf_AUX_Vertices1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Vertices1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_Vertices1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Vertices1_2sym , ATmakeAppl ( lf_AUX_Vertices1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Vertices1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Vertices1_1 ( ) {
CONS_ENTRY ( lf_AUX_Vertices1_1sym , ATmakeAppl0 ( lf_AUX_Vertices1_1sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Vertices1_1sym ) ) ;
}

