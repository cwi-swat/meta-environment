#include  "asc-support.h"
static Symbol lf_AUX_Restrictions_Sdf_Syntax3_1sym ;
static ATerm lf_AUX_Restrictions_Sdf_Syntax3_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Restrictions_Sdf_Syntax3 ( ) {
lf_AUX_Restrictions_Sdf_Syntax3_1sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Lookaheads\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Syntax3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Lookahead\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Lookaheads\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Restrictions_Sdf_Syntax3_1 , lf_AUX_Restrictions_Sdf_Syntax3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Lookahead\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Restrictions_Sdf_Syntax3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Lookahead\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Lookahead\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"[[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[ql(\"[[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\".\"),w(\"\"),sort(\"Lookaheads\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Lookahead\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Restrictions_Sdf_Syntax3 ( ) {
}
ATerm lf_AUX_Restrictions_Sdf_Syntax3_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Restrictions_Sdf_Syntax3_1sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Syntax3_1sym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_Restrictions_Sdf_Syntax3_1 : ltmp [ 0 ] = arg0 ;
ltmp [ 1 ] = arg1 ;
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
arg0 = ( * ef3 ) ( lf2 ( make_list ( ( * ef2 ) ( atmp000 ) ) ) ) ;
goto lbl_lf_AUX_Restrictions_Sdf_Syntax3_1 ;
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef4sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
arg0 = ( * ef3 ) ( lf2 ( make_list ( ( * ef4 ) ( atmp000 , atmp001 ) ) ) ) ;
goto lbl_lf_AUX_Restrictions_Sdf_Syntax3_1 ;
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef3sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( ltmp [ 1 ] , ef3sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT ( ( * ef3 ) ( lf2 ( cons ( make_list ( atmp000 ) , make_list ( atmp100 ) ) ) ) ) ;
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
arg1 = ( * ef3 ) ( lf2 ( make_list ( ( * ef2 ) ( atmp100 ) ) ) ) ;
goto lbl_lf_AUX_Restrictions_Sdf_Syntax3_1 ;
}
}
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp101 = arg_1 ( atmp10 ) ;
arg1 = ( * ef3 ) ( lf2 ( make_list ( ( * ef4 ) ( atmp100 , atmp101 ) ) ) ) ;
goto lbl_lf_AUX_Restrictions_Sdf_Syntax3_1 ;
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Restrictions_Sdf_Syntax3_1sym , ltmp [ 0 ] , ltmp [ 1 ] ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

