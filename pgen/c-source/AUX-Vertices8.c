#include  "support.h"
static Symbol lf_AUX_Vertices8_1sym ;
static ATerm lf_AUX_Vertices8_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Vertices8 ( ) {
lf_AUX_Vertices8_1sym = ATmakeSymbol ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"VertexSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices8_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Vertex\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"VertexSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Vertices8_1 , lf_AUX_Vertices8_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Vertex\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Vertices8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Vertices\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VertexSet\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Vertices\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VertexSet\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[iter(sort(\"Vertex\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertices\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[iter(sort(\"Vertex\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertices\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"Vertices\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"Vertices\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Vertices8 ( ) {
}
ATerm lf_AUX_Vertices8_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Vertices8_1sym , ATmakeAppl ( lf_AUX_Vertices8_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
FUNC_EXIT ( ( * ef3 ) ( arg0 , ( * ef2 ) ( lf2 ( make_list ( atmp1000 ) ) ) ) ) ;
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Vertices8_1sym , arg0 , arg1 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

