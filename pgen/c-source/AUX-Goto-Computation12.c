#include  "support.h"
static Symbol lf_AUX_Goto_Computation12_1sym ;
static ATerm lf_AUX_Goto_Computation12_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
void register_AUX_Goto_Computation12 ( ) {
lf_AUX_Goto_Computation12_1sym = ATmakeSymbol ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"vertex\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Goto_Computation12_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"vertex\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Goto_Computation12_1 , lf_AUX_Goto_Computation12_1sym ) ;
}
void resolve_AUX_Goto_Computation12 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"states\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"States\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"states\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"States\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"States\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"State\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"States\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"States\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"State\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"States\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"states\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"States\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Parse-Table\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"states\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"States\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"States\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"States\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"kernel\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"kernel\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"closure\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"closure\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertex\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"outgoing\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"outgoing\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table-Goto-Table\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table-Goto-Table\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"gotos\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table-Goto-Table\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"gotos\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parse-Table-Goto-Table\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"actions\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Goto-Computation\"),w(\"\"),[l(\"actions\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parse-Table\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"parameter\")],w(\"\"),l(\"}\")))" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"actions\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"actions\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Action-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"gotos\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"gotos\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"closure\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"State\"),w(\"\"),ql(\"[\"),w(\"\"),l(\"closure\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Vertex\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"State\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Goto_Computation12 ( ) {
}
ATerm lf_AUX_Goto_Computation12_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 9 ] ;
FUNC_ENTRY ( lf_AUX_Goto_Computation12_1sym , ATmakeAppl ( lf_AUX_Goto_Computation12_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg2 , ef1sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
tmp [ 0 ] = ( * ef5 ) ( ( * ef4 ) ( arg1 ) , arg2 ) ;
tmp [ 1 ] = ( * ef6 ) ( tmp [ 0 ] ) ;
tmp [ 2 ] = ( * ef7 ) ( arg0 , tmp [ 1 ] ) ;
tmp [ 3 ] = ( * ef8 ) ( arg0 , tmp [ 2 ] ) ;
tmp [ 4 ] = ( * ef10 ) ( arg0 , arg1 , tmp [ 2 ] , tmp [ 3 ] ) ; 
if ( check_sym ( tmp [ 4 ] , ef9sym ) ) {
arg1 = NULL;
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
tmp [ 6 ] = arg_1 ( tmp [ 4 ] ) ;
tmp [ 7 ] = ( * ef11 ) ( arg0 , tmp [ 5 ] , tmp [ 2 ] , tmp [ 6 ] ) ;
tmp [ 8 ] = ( * ef12 ) ( ( * ef13 ) ( ( * ef14 ) ( tmp [ 0 ] , tmp [ 2 ] ) , tmp [ 6 ] ) , tmp [ 7 ] ) ;
tmp [ 6 ] = NULL;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 5 ] , ( * ef3 ) ( ( * ef4 ) ( tmp [ 5 ] ) , arg2 , tmp [ 8 ] ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Goto_Computation12_1sym , arg0 , arg1 , arg2 ) ) ;
}
}

