#include  "support.h"
static Symbol lf_AUX_Vertices3_1sym ;
static ATerm lf_AUX_Vertices3_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_Vertices3 ( ) {
lf_AUX_Vertices3_1sym = ATmakeSymbol ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Vertices3_1 , lf_AUX_Vertices3_1sym ) ;
}
void resolve_AUX_Vertices3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Vertices3 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Vertices3_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Vertices3_1sym , ATmakeAppl ( lf_AUX_Vertices3_1sym , arg0 , arg1 ) ) ;
if ( term_equal ( arg0 , arg1 ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ) ) ;
}
if ( check_sym ( arg0 , ef3sym ) ) {
tmp [ 0 ] = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef3sym ) ) {
tmp [ 1 ] = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 0 ] , tmp [ 1 ] ) ) ;
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Vertices3_1sym , arg0 , arg1 ) ) ;
}
}

