#include  "asc-support.h"
static Symbol lf_AUX_Improve_C_code2_1sym ;
static ATerm lf_AUX_Improve_C_code2_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Improve_C_code2 ( ) {
lf_AUX_Improve_C_code2_1sym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"remove-tail-rec\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code2_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Statement\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"remove-tail-rec\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code2_1 , lf_AUX_Improve_C_code2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Statement\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Improve_C_code2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Statement\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"remove-tail-rec-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SB-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"remove-tail-rec-stats\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SB-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SB-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SB-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"add-label\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Improve-C-code\"),w(\"\"),[l(\"add-label\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Identifier\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_Improve_C_code2 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_Improve_C_code2_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 13 ] ;
FUNC_ENTRY ( lf_AUX_Improve_C_code2_1sym , ATmakeAppl ( lf_AUX_Improve_C_code2_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( arg2 , ef3sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( not_empty_list ( atmp0000 ) ) {
if ( check_sym ( arg1 , ef4sym ) ) {
tmp [ 0 ] = arg_0 ( arg1 ) ;
if ( check_sym ( tmp [ 0 ] , lf3sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 2 ] = ( * ef4 ) ( lf3 ( cons ( ( constant0 ? constant0 : ( constant0 = make_list ( make_char ( 108 ) ) ) ) , cons ( ( constant1 ? constant1 : ( constant1 = make_list ( make_char ( 98 ) ) ) ) , cons ( ( constant0 ? constant0 : ( constant0 = make_list ( make_char ( 108 ) ) ) ) , cons ( ( constant2 ? constant2 : ( constant2 = make_list ( make_char ( 95 ) ) ) ) , make_list ( tmp [ 1 ] ) ) ) ) ) ) ) ;
tmp [ 3 ] = ( * ef5 ) ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( atmp0000 ) ) ) ) , arg1 , tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef6sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 6 ] , ef2sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf2sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = ( * ef7 ) ( tmp [ 5 ] , tmp [ 2 ] , ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 8 ] ) ) ) ) , arg2 ) ;
if ( check_sym ( tmp [ 9 ] , ef1sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , ef2sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf2sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 12 ] ) ) ) ) ;
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
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Improve_C_code2_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

