#include  "asc-support.h"
static Symbol lf_AUX_Modular_Sdf_Normalization10_1sym ;
static ATerm lf_AUX_Modular_Sdf_Normalization10_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Modular_Sdf_Normalization10 ( ) {
lf_AUX_Modular_Sdf_Normalization10_1sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[l(\"ims\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Definition\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IG\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Normalization10_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Import\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[l(\"ims\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Definition\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IG\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Normalization10_1 , lf_AUX_Modular_Sdf_Normalization10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Import\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Modular_Sdf_Normalization10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Import\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Imports\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Import\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Imports\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IG\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IG\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[sort(\"Grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[sort(\"Grammar\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[l(\"imp\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Definition\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Import\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IG\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Modular-Sdf-Normalization\"),w(\"\"),[l(\"imp\"),w(\"\"),ql(\"[[\"),w(\"\"),sort(\"Definition\"),w(\"\"),ql(\"]]\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Imports\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Import\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IG\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Modular_Sdf_Normalization10 ( ) {
}
ATerm lf_AUX_Modular_Sdf_Normalization10_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 12 ] ;
FUNC_ENTRY ( lf_AUX_Modular_Sdf_Normalization10_1sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Normalization10_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( arg2 , ef1sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf2sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp200 ) ) {
tmp [ 0 ] = list_head ( atmp200 ) ;
tmp [ 1 ] = list_tail ( atmp200 ) ;
tmp [ 2 ] = ( * ef5 ) ( arg0 , ( * ef1 ) ( lf2 ( make_list ( atmp100 ) ) ) , tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef1sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
tmp [ 7 ] = lf_AUX_Modular_Sdf_Normalization10_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( tmp [ 6 ] ) ) ) , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 7 ] , ef2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = arg_1 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef1sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf2sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 11 ] ) ) ) , ( * ef4 ) ( tmp [ 4 ] , tmp [ 9 ] ) ) ) ;
}
}
}
}
}
}
}
else {
FUNC_EXIT ( ( * ef2 ) ( ( * ef1 ) ( lf2 ( make_list ( atmp100 ) ) ) , ( * ef3 ) ( ) ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Modular_Sdf_Normalization10_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

