#include  "support.h"
static Symbol lf_AUX_Modular_Sdf_Normalization1_1sym ;
static ATerm lf_AUX_Modular_Sdf_Normalization1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Modular_Sdf_Normalization1_3sym ;
static ATerm lf_AUX_Modular_Sdf_Normalization1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Normalization1_2sym ;
static ATerm lf_AUX_Modular_Sdf_Normalization1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Normalization1_4sym ;
static ATerm lf_AUX_Modular_Sdf_Normalization1_4 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_Modular_Sdf_Normalization1 ( ) {
lf_AUX_Modular_Sdf_Normalization1_1sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ipair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Normalization1_1sym ) ;
lf_AUX_Modular_Sdf_Normalization1_3sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[iter(sort(\"Ipair\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"ICL\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Normalization1_3sym ) ;
lf_AUX_Modular_Sdf_Normalization1_2sym = ATmakeSymbol ( "listtype(sort(\"Ipair\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Normalization1_2sym ) ;
lf_AUX_Modular_Sdf_Normalization1_4sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IG\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Normalization1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ipair\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Normalization1_1 , lf_AUX_Modular_Sdf_Normalization1_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Ipair\"))" ) , lf_AUX_Modular_Sdf_Normalization1_2 , lf_AUX_Modular_Sdf_Normalization1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[iter(sort(\"Ipair\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"ICL\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Normalization1_3 , lf_AUX_Modular_Sdf_Normalization1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IG\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Normalization1_4 , lf_AUX_Modular_Sdf_Normalization1_4sym ) ;
}
void resolve_AUX_Modular_Sdf_Normalization1 ( ) {
}
void init_AUX_Modular_Sdf_Normalization1 ( ) {
}
ATerm lf_AUX_Modular_Sdf_Normalization1_4 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Normalization1_4sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Normalization1_4sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Modular_Sdf_Normalization1_4sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Normalization1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Normalization1_2sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Normalization1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Normalization1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Normalization1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Normalization1_3sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Normalization1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Normalization1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Normalization1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Normalization1_1sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Normalization1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Modular_Sdf_Normalization1_1sym , arg0 , arg1 ) ) ;
}

