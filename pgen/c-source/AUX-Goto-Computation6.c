#include  "support.h"
static Symbol lf_AUX_Goto_Computation6_1sym ;
static ATerm lf_AUX_Goto_Computation6_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Goto_Computation6 ( ) {
lf_AUX_Goto_Computation6_1sym = ATmakeSymbol ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"shift\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_Computation6_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Item\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"shift\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Goto_Computation6_1 , lf_AUX_Goto_Computation6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Item\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Goto_Computation6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Graphs\"),w(\"\"),[sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"shift\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Earley\"),w(\"\"),[l(\"shift\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Item\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"Vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"Vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Goto_Computation6 ( ) {
}
ATerm lf_AUX_Goto_Computation6_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 3 ] ;
FUNC_ENTRY ( lf_AUX_Goto_Computation6_1sym , ATmakeAppl ( lf_AUX_Goto_Computation6_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
/* 
if ( is_single_element ( atmp1000 ) ) {
tmp [ 0 ] = list_head ( atmp1000 ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef3 ) ( arg0 , tmp [ 0 ] , arg2 ) ) ) ;
}
if ( not_empty_list ( atmp1000 ) ) {
tmp [ 0 ] = list_head ( atmp1000 ) ;
tmp [ 1 ] = list_tail ( atmp1000 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef4 ) ( ( * ef1 ) ( ( * ef3 ) ( arg0 , tmp [ 0 ] , arg2 ) ) , lf_AUX_Goto_Computation6_1 ( arg0 , ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) , arg2 ) ) ) ;
}
}
*/
if ( ATgetLength((ATermList) atmp1000 ) == 1) {
  tmp [ 0 ] = list_head ( atmp1000 ) ; 
  FUNC_EXIT ( ( * ef1 ) ( ( * ef3 ) ( arg0 , tmp [ 0 ] , arg2 ) ) );
}
else {
  tmp [ 2 ] = ( * ef2 ) ( lf2 ( null() ) );
  atmp1000 = (ATerm) ATreverse((ATermList) atmp1000 );
  while ( not_empty_list ( atmp1000 ) ) {
    tmp [ 0 ] = list_head ( atmp1000 ) ;
    tmp [ 1 ] = ( ( * ef3 ) ( arg0 , tmp [ 0 ] , arg2 ) ) ;
    tmp [ 2 ] = (*ef5)(tmp[1], tmp [ 2 ]);
    atmp1000 = list_tail ( atmp1000 ) ;
  }
  FUNC_EXIT ( ( * ef1 ) ( tmp [ 2 ] ) );
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Goto_Computation6_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

