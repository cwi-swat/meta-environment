#include  "support.h"
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_1sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_2sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_3sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_4sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_5sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_5 ( ) ;
void register_AUX_Restrictions_Sdf_Syntax1 ( ) {
lf_AUX_Restrictions_Sdf_Syntax1_1sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_1sym ) ;
lf_AUX_Restrictions_Sdf_Syntax1_2sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Lookahead\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_2sym ) ;
lf_AUX_Restrictions_Sdf_Syntax1_3sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_3sym ) ;
lf_AUX_Restrictions_Sdf_Syntax1_4sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"restrictions\"),w(\"\"),sort(\"Restrictions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_4sym ) ;
lf_AUX_Restrictions_Sdf_Syntax1_5sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"reject\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Syntax1_1 , lf_AUX_Restrictions_Sdf_Syntax1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Lookahead\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Syntax1_2 , lf_AUX_Restrictions_Sdf_Syntax1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Restrictions_Sdf_Syntax1_3 , lf_AUX_Restrictions_Sdf_Syntax1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"restrictions\"),w(\"\"),sort(\"Restrictions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Syntax1_4 , lf_AUX_Restrictions_Sdf_Syntax1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"reject\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Syntax1_5 , lf_AUX_Restrictions_Sdf_Syntax1_5sym ) ;
}
void resolve_AUX_Restrictions_Sdf_Syntax1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_Restrictions_Sdf_Syntax1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Restrictions_Sdf_Syntax1_5 ( ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax1_5sym , ATmakeAppl0 ( lf_AUX_Restrictions_Sdf_Syntax1_5sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Restrictions_Sdf_Syntax1_5sym ) ) ;
}
ATerm lf_AUX_Restrictions_Sdf_Syntax1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax1_4sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Syntax1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_Restrictions_Sdf_Syntax1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax1_3sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Syntax1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Restrictions_Sdf_Syntax1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax1_2sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Syntax1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Restrictions_Sdf_Syntax1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax1_1sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Syntax1_1sym , arg0 ) ) ;
}

