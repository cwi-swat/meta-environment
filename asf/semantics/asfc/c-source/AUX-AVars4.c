#include  "asc-support.h"
static Symbol lf_AUX_AVars4_1sym ;
static ATerm lf_AUX_AVars4_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_AVars4 ( ) {
lf_AUX_AVars4_1sym = ATmakeSymbol ( "prod(id(\"AVars\"),w(\"\"),[l(\"avar-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AVars4_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"AVars\"),w(\"\"),[l(\"avar-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) , lf_AUX_AVars4_1 , lf_AUX_AVars4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_AVars4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_AVars4 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_AVars4_1 ( ATerm arg0 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_AVars4_1sym , ATmakeAppl ( lf_AUX_AVars4_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , lf2sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
if ( not_empty_list ( atmp00000 ) ) {
if ( term_equal ( list_head ( atmp00000 ) , make_char ( 65 ) ) ) {
tmp [ 0 ] = list_tail ( atmp00000 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 78 ) ) ) {
tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 97 ) ) ) {
tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 109 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 101 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 78 ] , char_table [ 97 ] , char_table [ 109 ] , char_table [ 101 ] ) ) ) ) ;
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
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef4sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , lf2sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( not_empty_list ( atmp00000 ) ) {
if ( term_equal ( list_head ( atmp00000 ) , make_char ( 65 ) ) ) {
tmp [ 0 ] = list_tail ( atmp00000 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 78 ) ) ) {
tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 97 ) ) ) {
tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 109 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 101 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 78 ] , char_table [ 97 ] , char_table [ 109 ] , char_table [ 101 ] ) ) ) ) ;
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
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef5sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , lf2sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
if ( not_empty_list ( atmp00000 ) ) {
if ( term_equal ( list_head ( atmp00000 ) , make_char ( 65 ) ) ) {
tmp [ 0 ] = list_tail ( atmp00000 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 78 ) ) ) {
tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 97 ) ) ) {
tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 109 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 101 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 78 ] , char_table [ 97 ] , char_table [ 109 ] , char_table [ 101 ] ) ) ) ) ;
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
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef6sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , lf2sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
{
ATerm atmp001 = arg_1 ( atmp00 ) ;
if ( not_empty_list ( atmp00000 ) ) {
if ( term_equal ( list_head ( atmp00000 ) , make_char ( 65 ) ) ) {
tmp [ 0 ] = list_tail ( atmp00000 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 78 ) ) ) {
tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 97 ) ) ) {
tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 109 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 101 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 78 ] , char_table [ 97 ] , char_table [ 109 ] , char_table [ 101 ] ) ) ) ) ;
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
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_AVars4_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

