#include  "asc-support.h"
static Symbol lf_AUX_TermAsFix2Sign16_1sym ;
static ATerm lf_AUX_TermAsFix2Sign16_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef15sym ;
static funcptr ef15 ;
void register_AUX_TermAsFix2Sign16 ( ) {
lf_AUX_TermAsFix2Sign16_1sym = ATmakeSymbol ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"literal2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFix2Sign16_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"literal2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFix2Sign16_1 , lf_AUX_TermAsFix2Sign16_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_TermAsFix2Sign16 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-uqliteral-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-uqliteral-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lex\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"MuLiterals\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuLiterals\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_TermAsFix2Sign16 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_TermAsFix2Sign16_1 ( ATerm arg0 ) {
{
ATerm tmp [ 24 ] ;
FUNC_ENTRY ( lf_AUX_TermAsFix2Sign16_1sym , ATmakeAppl ( lf_AUX_TermAsFix2Sign16_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef3sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef3sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
{
ATerm atmp0111 = arg_1 ( atmp011 ) ;
if ( check_sym ( atmp0111 , ef4sym ) ) {
{
ATerm atmp01110 = arg_0 ( atmp0111 ) ;
if ( check_sym ( atmp01110 , ef5sym ) ) {
{
ATerm atmp011100 = arg_0 ( atmp01110 ) ;
if ( check_sym ( atmp011100 , ef6sym ) ) {
{
ATerm atmp0111000 = arg_0 ( atmp011100 ) ;
if ( check_sym ( atmp0111000 , ef4sym ) ) {
{
ATerm atmp01110000 = arg_0 ( atmp0111000 ) ;
if ( term_equal ( ( * ef7 ) ( atmp010 ) , ( constant0 ? constant0 : ( constant0 = ( * ef8 ) ( ) ) ) ) ) {
( tmp [ 0 ] = lf_AUX_TermAsFix2Sign16_1 ( atmp01110000 ) ) ;
FUNC_EXIT ( tmp [ 0 ] ) ;
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
if ( check_sym ( atmp00 , ef9sym ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef3sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef10sym ) ) {
{
ATerm atmp0100 = arg_0 ( atmp010 ) ;
if ( check_sym ( atmp0100 , ef11sym ) ) {
{
ATerm atmp01000 = arg_0 ( atmp0100 ) ;
if ( check_sym ( atmp01000 , ef12sym ) ) {
{
ATerm atmp010000 = arg_0 ( atmp01000 ) ;
if ( check_sym ( atmp010000 , lf2sym ) ) {
{
ATerm atmp0100000 = arg_0 ( atmp010000 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef4sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef1sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , ef13sym ) ) {
{
ATerm atmp01101 = arg_1 ( atmp0110 ) ;
if ( check_sym ( atmp01101 , ef4sym ) ) {
{
ATerm atmp011010 = arg_0 ( atmp01101 ) ;
if ( check_sym ( atmp011010 , ef10sym ) ) {
{
ATerm atmp0110100 = arg_0 ( atmp011010 ) ;
if ( check_sym ( atmp0110100 , ef11sym ) ) {
{
ATerm atmp01101000 = arg_0 ( atmp0110100 ) ;
if ( check_sym ( atmp01101000 , ef12sym ) ) {
{
ATerm atmp011010000 = arg_0 ( atmp01101000 ) ;
if ( check_sym ( atmp011010000 , lf2sym ) ) {
{
ATerm atmp0110100000 = arg_0 ( atmp011010000 ) ;
if ( not_empty_list ( atmp0100000 ) ) {
( tmp [ 0 ] = list_head ( atmp0100000 ) ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 34 ) ) ) {
( tmp [ 1 ] = list_tail ( atmp0100000 ) ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = list_head ( tmp [ 1 ] ) ) ;
if ( term_equal ( tmp [ 2 ] , make_char ( 92 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 1 ] ) ) ;
{
if ( not_empty_list ( tmp [ 3 ] ) ) {
( tmp [ 4 ] = list_head ( tmp [ 3 ] ) ) ;
if ( term_equal ( tmp [ 4 ] , make_char ( 34 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 3 ] ) ) ;
{
( tmp [ 6 ] = list_prefix ( tmp [ 5 ] ) ) ;
{
if ( not_empty_list ( tmp [ 5 ] ) ) {
( tmp [ 7 ] = list_last ( tmp [ 5 ] ) ) ;
if ( term_equal ( tmp [ 7 ] , make_char ( 34 ) ) ) {
( tmp [ 8 ] = list_prefix ( tmp [ 6 ] ) ) ;
{
if ( not_empty_list ( tmp [ 6 ] ) ) {
( tmp [ 9 ] = list_last ( tmp [ 6 ] ) ) ;
if ( term_equal ( tmp [ 9 ] , make_char ( 34 ) ) ) {
( tmp [ 10 ] = list_prefix ( tmp [ 8 ] ) ) ;
{
if ( not_empty_list ( tmp [ 8 ] ) ) {
( tmp [ 11 ] = list_last ( tmp [ 8 ] ) ) ;
if ( term_equal ( tmp [ 11 ] , make_char ( 92 ) ) ) {
if ( not_empty_list ( atmp0110100000 ) ) {
( tmp [ 12 ] = list_head ( atmp0110100000 ) ) ;
if ( term_equal ( tmp [ 12 ] , make_char ( 34 ) ) ) {
( tmp [ 13 ] = list_tail ( atmp0110100000 ) ) ;
{
if ( not_empty_list ( tmp [ 13 ] ) ) {
( tmp [ 14 ] = list_head ( tmp [ 13 ] ) ) ;
if ( term_equal ( tmp [ 14 ] , make_char ( 85 ) ) ) {
( tmp [ 15 ] = list_tail ( tmp [ 13 ] ) ) ;
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 81 ) ) ) {
( tmp [ 16 ] = list_tail ( tmp [ 15 ] ) ) ;
if ( not_empty_list ( tmp [ 16 ] ) ) {
if ( term_equal ( list_head ( tmp [ 16 ] ) , make_char ( 76 ) ) ) {
( tmp [ 17 ] = list_tail ( tmp [ 16 ] ) ) ;
if ( not_empty_list ( tmp [ 17 ] ) ) {
if ( term_equal ( list_head ( tmp [ 17 ] ) , make_char ( 105 ) ) ) {
( tmp [ 18 ] = list_tail ( tmp [ 17 ] ) ) ;
if ( not_empty_list ( tmp [ 18 ] ) ) {
if ( term_equal ( list_head ( tmp [ 18 ] ) , make_char ( 116 ) ) ) {
( tmp [ 19 ] = list_tail ( tmp [ 18 ] ) ) ;
if ( not_empty_list ( tmp [ 19 ] ) ) {
if ( term_equal ( list_head ( tmp [ 19 ] ) , make_char ( 101 ) ) ) {
( tmp [ 20 ] = list_tail ( tmp [ 19 ] ) ) ;
if ( not_empty_list ( tmp [ 20 ] ) ) {
if ( term_equal ( list_head ( tmp [ 20 ] ) , make_char ( 114 ) ) ) {
( tmp [ 21 ] = list_tail ( tmp [ 20 ] ) ) ;
if ( not_empty_list ( tmp [ 21 ] ) ) {
if ( term_equal ( list_head ( tmp [ 21 ] ) , make_char ( 97 ) ) ) {
( tmp [ 22 ] = list_tail ( tmp [ 21 ] ) ) ;
if ( not_empty_list ( tmp [ 22 ] ) ) {
if ( term_equal ( list_head ( tmp [ 22 ] ) , make_char ( 108 ) ) ) {
( tmp [ 23 ] = list_tail ( tmp [ 22 ] ) ) ;
if ( is_single_element ( tmp [ 23 ] ) ) {
if ( term_equal ( list_head ( tmp [ 23 ] ) , make_char ( 34 ) ) ) {
FUNC_EXIT ( ( * ef14 ) ( ( * ef14 ) ( ( * ef15 ) ( lf2 ( ( ATerm ) ATmakeList ( 7 , char_table [ 34 ] , char_table [ 113 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 34 ] ) ) ) , ( * ef15 ) ( lf2 ( cons ( make_list_char ( 34 ) , cons ( make_list ( tmp [ 10 ] ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) , ( * ef15 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ) ;
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
if ( term_equal ( tmp [ 14 ] , make_char ( 76 ) ) ) {
( tmp [ 15 ] = list_tail ( tmp [ 13 ] ) ) ;
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 105 ) ) ) {
( tmp [ 16 ] = list_tail ( tmp [ 15 ] ) ) ;
if ( not_empty_list ( tmp [ 16 ] ) ) {
if ( term_equal ( list_head ( tmp [ 16 ] ) , make_char ( 116 ) ) ) {
( tmp [ 17 ] = list_tail ( tmp [ 16 ] ) ) ;
if ( not_empty_list ( tmp [ 17 ] ) ) {
if ( term_equal ( list_head ( tmp [ 17 ] ) , make_char ( 101 ) ) ) {
( tmp [ 18 ] = list_tail ( tmp [ 17 ] ) ) ;
if ( not_empty_list ( tmp [ 18 ] ) ) {
if ( term_equal ( list_head ( tmp [ 18 ] ) , make_char ( 114 ) ) ) {
( tmp [ 19 ] = list_tail ( tmp [ 18 ] ) ) ;
if ( not_empty_list ( tmp [ 19 ] ) ) {
if ( term_equal ( list_head ( tmp [ 19 ] ) , make_char ( 97 ) ) ) {
( tmp [ 20 ] = list_tail ( tmp [ 19 ] ) ) ;
if ( not_empty_list ( tmp [ 20 ] ) ) {
if ( term_equal ( list_head ( tmp [ 20 ] ) , make_char ( 108 ) ) ) {
( tmp [ 21 ] = list_tail ( tmp [ 20 ] ) ) ;
if ( is_single_element ( tmp [ 21 ] ) ) {
if ( term_equal ( list_head ( tmp [ 21 ] ) , make_char ( 34 ) ) ) {
FUNC_EXIT ( ( * ef14 ) ( ( * ef14 ) ( ( * ef15 ) ( lf2 ( ( ATerm ) ATmakeList ( 7 , char_table [ 34 ] , char_table [ 113 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 34 ] ) ) ) , ( * ef15 ) ( lf2 ( cons ( make_list_char ( 34 ) , cons ( make_list ( tmp [ 10 ] ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) , ( * ef15 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ) ;
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
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef9sym ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef3sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef10sym ) ) {
{
ATerm atmp0100 = arg_0 ( atmp010 ) ;
if ( check_sym ( atmp0100 , ef11sym ) ) {
{
ATerm atmp01000 = arg_0 ( atmp0100 ) ;
if ( check_sym ( atmp01000 , ef12sym ) ) {
{
ATerm atmp010000 = arg_0 ( atmp01000 ) ;
if ( check_sym ( atmp010000 , lf2sym ) ) {
{
ATerm atmp0100000 = arg_0 ( atmp010000 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef4sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , ef1sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
if ( check_sym ( atmp01100 , ef13sym ) ) {
{
ATerm atmp01101 = arg_1 ( atmp0110 ) ;
if ( check_sym ( atmp01101 , ef4sym ) ) {
{
ATerm atmp011010 = arg_0 ( atmp01101 ) ;
if ( check_sym ( atmp011010 , ef10sym ) ) {
{
ATerm atmp0110100 = arg_0 ( atmp011010 ) ;
if ( check_sym ( atmp0110100 , ef11sym ) ) {
{
ATerm atmp01101000 = arg_0 ( atmp0110100 ) ;
if ( check_sym ( atmp01101000 , ef12sym ) ) {
{
ATerm atmp011010000 = arg_0 ( atmp01101000 ) ;
if ( check_sym ( atmp011010000 , lf2sym ) ) {
{
ATerm atmp0110100000 = arg_0 ( atmp011010000 ) ;
if ( not_empty_list ( atmp0100000 ) ) {
( tmp [ 0 ] = list_head ( atmp0100000 ) ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 34 ) ) ) {
( tmp [ 1 ] = list_tail ( atmp0100000 ) ) ;
{
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = list_prefix ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = list_last ( tmp [ 1 ] ) ) ;
if ( term_equal ( tmp [ 3 ] , make_char ( 34 ) ) ) {
if ( not_empty_list ( atmp0110100000 ) ) {
( tmp [ 4 ] = list_head ( atmp0110100000 ) ) ;
if ( term_equal ( tmp [ 4 ] , make_char ( 34 ) ) ) {
( tmp [ 5 ] = list_tail ( atmp0110100000 ) ) ;
{
if ( not_empty_list ( tmp [ 5 ] ) ) {
( tmp [ 6 ] = list_head ( tmp [ 5 ] ) ) ;
if ( term_equal ( tmp [ 6 ] , make_char ( 76 ) ) ) {
( tmp [ 7 ] = list_tail ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 105 ) ) ) {
( tmp [ 8 ] = list_tail ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 116 ) ) ) {
( tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ) ;
if ( not_empty_list ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 101 ) ) ) {
( tmp [ 10 ] = list_tail ( tmp [ 9 ] ) ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
if ( term_equal ( list_head ( tmp [ 10 ] ) , make_char ( 114 ) ) ) {
( tmp [ 11 ] = list_tail ( tmp [ 10 ] ) ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
if ( term_equal ( list_head ( tmp [ 11 ] ) , make_char ( 97 ) ) ) {
( tmp [ 12 ] = list_tail ( tmp [ 11 ] ) ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 108 ) ) ) {
( tmp [ 13 ] = list_tail ( tmp [ 12 ] ) ) ;
if ( is_single_element ( tmp [ 13 ] ) ) {
if ( term_equal ( list_head ( tmp [ 13 ] ) , make_char ( 34 ) ) ) {
FUNC_EXIT ( ( * ef14 ) ( ( * ef14 ) ( ( * ef15 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 34 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 34 ] ) ) ) , ( * ef15 ) ( lf2 ( cons ( make_list_char ( 34 ) , cons ( make_list ( tmp [ 2 ] ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) , ( * ef15 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ) ;
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
if ( term_equal ( tmp [ 6 ] , make_char ( 85 ) ) ) {
( tmp [ 7 ] = list_tail ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 81 ) ) ) {
( tmp [ 8 ] = list_tail ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 76 ) ) ) {
( tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ) ;
if ( not_empty_list ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 105 ) ) ) {
( tmp [ 10 ] = list_tail ( tmp [ 9 ] ) ) ;
if ( not_empty_list ( tmp [ 10 ] ) ) {
if ( term_equal ( list_head ( tmp [ 10 ] ) , make_char ( 116 ) ) ) {
( tmp [ 11 ] = list_tail ( tmp [ 10 ] ) ) ;
if ( not_empty_list ( tmp [ 11 ] ) ) {
if ( term_equal ( list_head ( tmp [ 11 ] ) , make_char ( 101 ) ) ) {
( tmp [ 12 ] = list_tail ( tmp [ 11 ] ) ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 114 ) ) ) {
( tmp [ 13 ] = list_tail ( tmp [ 12 ] ) ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
if ( term_equal ( list_head ( tmp [ 13 ] ) , make_char ( 97 ) ) ) {
( tmp [ 14 ] = list_tail ( tmp [ 13 ] ) ) ;
if ( not_empty_list ( tmp [ 14 ] ) ) {
if ( term_equal ( list_head ( tmp [ 14 ] ) , make_char ( 108 ) ) ) {
( tmp [ 15 ] = list_tail ( tmp [ 14 ] ) ) ;
if ( is_single_element ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 34 ) ) ) {
FUNC_EXIT ( ( * ef14 ) ( ( * ef14 ) ( ( * ef15 ) ( lf2 ( ( ATerm ) ATmakeList ( 7 , char_table [ 34 ] , char_table [ 113 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 34 ] ) ) ) , ( * ef15 ) ( lf2 ( cons ( make_list_char ( 34 ) , cons ( make_list ( tmp [ 2 ] ) , make_list ( make_char ( 34 ) ) ) ) ) ) ) , ( * ef15 ) ( lf2 ( ( ATerm ) ATmakeList ( 5 , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf1 ( lf_AUX_TermAsFix2Sign16_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

