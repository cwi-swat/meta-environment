#include  "support.h"
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_1sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_3sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_2sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_4sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_Restrictions_Sdf_Syntax1_5sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax1_5 ( ) ;
void register_AUX_Restrictions_Sdf_Syntax1 ( ) {
lf_AUX_Restrictions_Sdf_Syntax1_1sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"-/-\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restriction\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_1sym ) ;
lf_AUX_Restrictions_Sdf_Syntax1_3sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Restriction\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_3sym ) ;
lf_AUX_Restrictions_Sdf_Syntax1_2sym = ATmakeSymbol ( "listtype(sort(\"Restriction\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_2sym ) ;
lf_AUX_Restrictions_Sdf_Syntax1_4sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"restrictions\"),w(\"\"),sort(\"Restrictions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_4sym ) ;
lf_AUX_Restrictions_Sdf_Syntax1_5sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"reject\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"-/-\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restriction\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Syntax1_1 , lf_AUX_Restrictions_Sdf_Syntax1_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Restriction\"))" ) , lf_AUX_Restrictions_Sdf_Syntax1_2 , lf_AUX_Restrictions_Sdf_Syntax1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Restriction\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Syntax1_3 , lf_AUX_Restrictions_Sdf_Syntax1_3sym ) ;
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
ATerm lf_AUX_Restrictions_Sdf_Syntax1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax1_2sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Syntax1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Restrictions_Sdf_Syntax1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax1_3sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Restrictions_Sdf_Syntax1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Restrictions_Sdf_Syntax1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax1_1sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Restrictions_Sdf_Syntax1_1sym , arg0 , arg1 ) ) ;
}

