#include  "support.h"
static Symbol lf_AUX_Restrictions_Sdf_Projection4_1sym ;
static ATerm lf_AUX_Restrictions_Sdf_Projection4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Restrictions_Sdf_Projection4 ( ) {
lf_AUX_Restrictions_Sdf_Projection4_1sym = ATmakeSymbol ( "prod(id(\"Restrictions-Sdf-Projection\"),w(\"\"),[l(\"proj\"),w(\"\"),ql(\"_\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Restrictions_Sdf_Projection4_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Restriction\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Restrictions-Sdf-Projection\"),w(\"\"),[l(\"proj\"),w(\"\"),ql(\"_\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) , lf_AUX_Restrictions_Sdf_Projection4_1 , lf_AUX_Restrictions_Sdf_Projection4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Restriction\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Restrictions_Sdf_Projection4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Restriction\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Restriction\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restrictions\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"OptCharRanges\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"-/-\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restriction\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Restrictions-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"-/-\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Restriction\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Restrictions_Sdf_Projection4 ( ) {
}
ATerm lf_AUX_Restrictions_Sdf_Projection4_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 8 ] ;
FUNC_ENTRY ( lf_AUX_Restrictions_Sdf_Projection4_1sym , ATmakeAppl ( lf_AUX_Restrictions_Sdf_Projection4_1sym , arg0 , arg1 ) ) ;
lbl_lf_AUX_Restrictions_Sdf_Projection4_1 : if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
{
tmp [ 1 ] = list_tail ( atmp100 ) ;
{
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
{
if ( check_sym ( tmp [ 2 ] , ef5sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
{
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
{
if ( ! not_empty_list ( tmp [ 5 ] ) ) {
arg0 = arg0 ;
arg1 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
goto lbl_lf_AUX_Restrictions_Sdf_Projection4_1 ;
}
else {
tmp [ 6 ] = list_head ( tmp [ 5 ] ) ;
tmp [ 7 ] = list_tail ( tmp [ 5 ] ) ;
if ( term_equal ( arg0 , tmp [ 6 ] ) ) {
FUNC_EXIT ( ( * ef6 ) ( tmp [ 3 ] , lf_AUX_Restrictions_Sdf_Projection4_1 ( arg0 , ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef4 ) ( ( * ef5 ) ( lf3 ( make_list ( tmp [ 7 ] ) ) ) , tmp [ 3 ] ) ) , make_list ( tmp [ 1 ] ) ) ) ) ) ) ) ;
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
else {
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( ) ) ) ;
}
}
}
}
}
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef5sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
tmp [ 6 ] = list_head ( tmp [ 5 ] ) ;
tmp [ 7 ] = list_tail ( tmp [ 5 ] ) ;
arg0 = arg0 ;
arg1 = ( * ef1 ) ( lf2 ( cons ( make_list ( ( * ef4 ) ( ( * ef5 ) ( lf3 ( make_list ( tmp [ 7 ] ) ) ) , tmp [ 3 ] ) ) , make_list ( tmp [ 1 ] ) ) ) ) ;
goto lbl_lf_AUX_Restrictions_Sdf_Projection4_1 ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Restrictions_Sdf_Projection4_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

