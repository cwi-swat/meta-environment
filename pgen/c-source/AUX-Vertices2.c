#include  "asc-support.h"
static Symbol lf_AUX_Vertices2_1sym ;
static ATerm lf_AUX_Vertices2_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Vertices2 ( ) {
lf_AUX_Vertices2_1sym = ATmakeSymbol ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"Vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"Vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Vertices2_1 , lf_AUX_Vertices2_1sym ) ;
}
void resolve_AUX_Vertices2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Vertices2 ( ) {
}
ATerm lf_AUX_Vertices2_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Vertices2_1sym , ATmakeAppl ( lf_AUX_Vertices2_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
tmp [ 0 ] = arg_0 ( arg0 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
tmp [ 1 ] = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( tmp [ 0 ] , tmp [ 1 ] ) ) ) ;
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Vertices2_1sym , arg0 , arg1 ) ) ;
}
}

