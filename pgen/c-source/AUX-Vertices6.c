#include  "asc-support.h"
static Symbol lf_AUX_Vertices6_1sym ;
static ATerm lf_AUX_Vertices6_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Vertices6 ( ) {
lf_AUX_Vertices6_1sym = ATmakeSymbol ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"VertexSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"VertexSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VertexSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Vertices6_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Vertex\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"VertexSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"VertexSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VertexSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Vertices6_1 , lf_AUX_Vertices6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Vertex\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Vertices6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Vertices\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VertexSet\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Vertices\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VertexSet\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[iter(sort(\"Vertex\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertices\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[iter(sort(\"Vertex\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Vertices\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Vertices\"),w(\"\"),[sort(\"Vertex\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Vertex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Vertices6 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Vertices6_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Vertices6_1sym , ATmakeAppl ( lf_AUX_Vertices6_1sym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_Vertices6_1 : ltmp [ 0 ] = arg0 ;
ltmp [ 1 ] = arg1 ;
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( ltmp [ 1 ] , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
tmp [ 0 ] = arg_0 ( atmp100 ) ;
{
ATerm atmp100010 ;
ATerm atmp10000 [ 2 ] ;
atmp10000 [ 0 ] = tmp [ 0 ] ;
atmp10000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp100010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( is_single_element ( atmp0000 ) ) {
tmp [ 1 ] = list_head ( atmp0000 ) ;
if ( term_equal ( ( * ef3 ) ( tmp [ 1 ] , atmp100010 ) , ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( cons ( slice ( atmp10000 [ 0 ] , atmp10000 [ 1 ] ) , cons ( make_list ( tmp [ 1 ] ) , tmp [ 0 ] ) ) ) ) ) ) ;
}
}
atmp10000 [ 1 ] = list_tail ( atmp10000 [ 1 ] ) ;
tmp [ 0 ] = atmp10000 [ 1 ] ;
}
}
}
}
}
}
}
if ( ! not_empty_list ( atmp0000 ) ) {
FUNC_EXIT ( ltmp [ 1 ] ) ;
}
}
}
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
tmp [ 0 ] = arg_0 ( atmp000 ) ;
{
ATerm atmp00000 [ 2 ] ;
atmp00000 [ 0 ] = tmp [ 0 ] ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
atmp00000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
arg0 = ( * ef1 ) ( ( * ef2 ) ( lf2 ( slice ( atmp00000 [ 0 ] , atmp00000 [ 1 ] ) ) ) ) ;
arg1 = lf_AUX_Vertices6_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( tmp [ 0 ] ) ) ) , ltmp [ 1 ] ) ;
goto lbl_lf_AUX_Vertices6_1 ;
}
atmp00000 [ 1 ] = list_tail ( atmp00000 [ 1 ] ) ;
tmp [ 0 ] = atmp00000 [ 1 ] ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( ltmp [ 1 ] , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( ! not_empty_list ( atmp1000 ) ) {
FUNC_EXIT ( ltmp [ 0 ] ) ;
}
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( ltmp [ 1 ] , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( is_single_element ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( atmp1000 ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Vertices6_1sym , ltmp [ 0 ] , ltmp [ 1 ] ) ) ;
}
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

