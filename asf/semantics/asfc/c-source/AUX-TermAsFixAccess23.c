#include  "asc-support.h"
static Symbol lf_AUX_TermAsFixAccess23_1sym ;
static ATerm lf_AUX_TermAsFixAccess23_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
void register_AUX_TermAsFixAccess23 ( ) {
lf_AUX_TermAsFixAccess23_1sym = ATmakeSymbol ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-symbol-iter\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFixAccess23_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-symbol-iter\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFixAccess23_1 , lf_AUX_TermAsFixAccess23_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_TermAsFixAccess23 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_TermAsFixAccess23 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_TermAsFixAccess23_1 ( ATerm arg0 ) {
{
ATerm tmp [ 10 ] ;
FUNC_ENTRY ( lf_AUX_TermAsFixAccess23_1sym , ATmakeAppl ( lf_AUX_TermAsFixAccess23_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef3sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef1sym ) ) {
{
ATerm atmp0100 = arg_0 ( atmp010 ) ;
if ( check_sym ( atmp0100 , ef4sym ) ) {
{
ATerm atmp0101 = arg_1 ( atmp010 ) ;
if ( check_sym ( atmp0101 , ef5sym ) ) {
{
ATerm atmp01010 = arg_0 ( atmp0101 ) ;
if ( check_sym ( atmp01010 , ef6sym ) ) {
{
ATerm atmp010100 = arg_0 ( atmp01010 ) ;
if ( check_sym ( atmp010100 , ef7sym ) ) {
{
ATerm atmp0101000 = arg_0 ( atmp010100 ) ;
if ( check_sym ( atmp0101000 , ef8sym ) ) {
{
ATerm atmp01010000 = arg_0 ( atmp0101000 ) ;
if ( check_sym ( atmp01010000 , lf2sym ) ) {
{
ATerm atmp010100000 = arg_0 ( atmp01010000 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef3sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef1sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , ef9sym ) ) {
{
ATerm atmp01101 = arg_1 ( atmp0110 ) ;
if ( check_sym ( atmp01101 , ef5sym ) ) {
{
ATerm atmp011010 = arg_0 ( atmp01101 ) ;
if ( check_sym ( atmp011010 , ef6sym ) ) {
{
ATerm atmp0110100 = arg_0 ( atmp011010 ) ;
if ( check_sym ( atmp0110100 , ef7sym ) ) {
{
ATerm atmp01101000 = arg_0 ( atmp0110100 ) ;
if ( check_sym ( atmp01101000 , ef8sym ) ) {
{
ATerm atmp011010000 = arg_0 ( atmp01101000 ) ;
if ( check_sym ( atmp011010000 , lf2sym ) ) {
{
ATerm atmp0110100000 = arg_0 ( atmp011010000 ) ;
{
ATerm atmp0111 = arg_1 ( atmp011 ) ;
if ( check_sym ( atmp0111 , ef5sym ) ) {
{
ATerm atmp01110 = arg_0 ( atmp0111 ) ;
if ( check_sym ( atmp01110 , ef1sym ) ) {
{
ATerm atmp011100 = arg_0 ( atmp01110 ) ;
if ( check_sym ( atmp011100 , ef10sym ) ) {
{
ATerm atmp011101 = arg_1 ( atmp01110 ) ;
if ( check_sym ( atmp011101 , ef5sym ) ) {
{
ATerm atmp0111010 = arg_0 ( atmp011101 ) ;
if ( check_sym ( atmp0111010 , ef6sym ) ) {
{
ATerm atmp01110100 = arg_0 ( atmp0111010 ) ;
if ( check_sym ( atmp01110100 , ef7sym ) ) {
{
ATerm atmp011101000 = arg_0 ( atmp01110100 ) ;
if ( check_sym ( atmp011101000 , ef8sym ) ) {
{
ATerm atmp0111010000 = arg_0 ( atmp011101000 ) ;
if ( check_sym ( atmp0111010000 , lf2sym ) ) {
{
ATerm atmp01110100000 = arg_0 ( atmp0111010000 ) ;
if ( not_empty_list ( atmp010100000 ) ) {
if ( term_equal ( list_head ( atmp010100000 ) , make_char ( 34 ) ) ) {
tmp [ 0 ] = list_tail ( atmp010100000 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 83 ) ) ) {
tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 121 ) ) ) {
tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 109 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 98 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 111 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 108 ) ) ) {
tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ;
if ( is_single_element ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 34 ) ) ) {
if ( not_empty_list ( atmp0110100000 ) ) {
if ( term_equal ( list_head ( atmp0110100000 ) , make_char ( 34 ) ) ) {
tmp [ 7 ] = list_tail ( atmp0110100000 ) ;
if ( is_single_element ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 34 ) ) ) {
if ( not_empty_list ( atmp01110100000 ) ) {
if ( term_equal ( list_head ( atmp01110100000 ) , make_char ( 34 ) ) ) {
tmp [ 8 ] = list_tail ( atmp01110100000 ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 42 ) ) ) {
tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ;
if ( is_single_element ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 34 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef11 ) ( ) ) ;
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
FUNC_EXIT_CONST ( constant1 , ( * ef12 ) ( ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_TermAsFixAccess23_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

