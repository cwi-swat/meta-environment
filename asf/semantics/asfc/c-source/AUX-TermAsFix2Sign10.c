#include  "asc-support.h"
static Symbol lf_AUX_TermAsFix2Sign10_1sym ;
static ATerm lf_AUX_TermAsFix2Sign10_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
void register_AUX_TermAsFix2Sign10 ( ) {
lf_AUX_TermAsFix2Sign10_1sym = ATmakeSymbol ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-cffunc2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFix2Sign10_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-cffunc2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFix2Sign10_1 , lf_AUX_TermAsFix2Sign10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_TermAsFix2Sign10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"id\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"MuLiterals\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuLiterals\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-production-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-production-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"symbols2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"symbols2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"symbol2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"symbol2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"attrs2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"attrs2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_TermAsFix2Sign10 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_TermAsFix2Sign10_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 9 ] ;
FUNC_ENTRY ( lf_AUX_TermAsFix2Sign10_1sym , ATmakeAppl ( lf_AUX_TermAsFix2Sign10_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef3sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( atmp010 , ef4sym ) ) {
{
ATerm atmp0100 = arg_0 ( atmp010 ) ;
if ( check_sym ( atmp0100 , ef5sym ) ) {
{
ATerm atmp01000 = arg_0 ( atmp0100 ) ;
if ( check_sym ( atmp01000 , ef6sym ) ) {
{
ATerm atmp010000 = arg_0 ( atmp01000 ) ;
if ( check_sym ( atmp010000 , lf2sym ) ) {
{
ATerm atmp0100000 = arg_0 ( atmp010000 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef7sym ) ) {
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , ef8sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
{
ATerm atmp111 = arg_1 ( atmp11 ) ;
if ( check_sym ( atmp111 , ef8sym ) ) {
{
ATerm atmp1110 = arg_0 ( atmp111 ) ;
if ( check_sym ( atmp1110 , ef1sym ) ) {
{
ATerm atmp11100 = arg_0 ( atmp1110 ) ;
if ( check_sym ( atmp11100 , ef9sym ) ) {
{
ATerm atmp11101 = arg_1 ( atmp1110 ) ;
if ( check_sym ( atmp11101 , ef3sym ) ) {
{
ATerm atmp111010 = arg_0 ( atmp11101 ) ;
if ( check_sym ( atmp111010 , ef4sym ) ) {
{
ATerm atmp1110100 = arg_0 ( atmp111010 ) ;
if ( check_sym ( atmp1110100 , ef5sym ) ) {
{
ATerm atmp11101000 = arg_0 ( atmp1110100 ) ;
if ( check_sym ( atmp11101000 , ef6sym ) ) {
{
ATerm atmp111010000 = arg_0 ( atmp11101000 ) ;
if ( check_sym ( atmp111010000 , lf2sym ) ) {
{
ATerm atmp1110100000 = arg_0 ( atmp111010000 ) ;
{
ATerm atmp1111 = arg_1 ( atmp111 ) ;
if ( check_sym ( atmp1111 , ef3sym ) ) {
{
ATerm atmp11110 = arg_0 ( atmp1111 ) ;
if ( check_sym ( atmp11110 , ef10sym ) ) {
{
ATerm atmp111100 = arg_0 ( atmp11110 ) ;
if ( check_sym ( atmp111100 , ef11sym ) ) {
{
ATerm atmp1111000 = arg_0 ( atmp111100 ) ;
if ( check_sym ( atmp1111000 , ef8sym ) ) {
{
ATerm atmp11110000 = arg_0 ( atmp1111000 ) ;
{
ATerm atmp11110001 = arg_1 ( atmp1111000 ) ;
if ( check_sym ( atmp11110001 , ef8sym ) ) {
{
ATerm atmp111100010 = arg_0 ( atmp11110001 ) ;
{
ATerm atmp111100011 = arg_1 ( atmp11110001 ) ;
if ( check_sym ( atmp111100011 , ef8sym ) ) {
{
ATerm atmp1111000110 = arg_0 ( atmp111100011 ) ;
if ( check_sym ( atmp1111000110 , ef1sym ) ) {
{
ATerm atmp11110001100 = arg_0 ( atmp1111000110 ) ;
if ( check_sym ( atmp11110001100 , ef12sym ) ) {
{
ATerm atmp11110001101 = arg_1 ( atmp1111000110 ) ;
if ( check_sym ( atmp11110001101 , ef3sym ) ) {
{
ATerm atmp111100011010 = arg_0 ( atmp11110001101 ) ;
if ( check_sym ( atmp111100011010 , ef4sym ) ) {
{
ATerm atmp1111000110100 = arg_0 ( atmp111100011010 ) ;
if ( check_sym ( atmp1111000110100 , ef5sym ) ) {
{
ATerm atmp11110001101000 = arg_0 ( atmp1111000110100 ) ;
if ( check_sym ( atmp11110001101000 , ef6sym ) ) {
{
ATerm atmp111100011010000 = arg_0 ( atmp11110001101000 ) ;
if ( check_sym ( atmp111100011010000 , lf2sym ) ) {
{
ATerm atmp1111000110100000 = arg_0 ( atmp111100011010000 ) ;
{
ATerm atmp1111000111 = arg_1 ( atmp111100011 ) ;
if ( check_sym ( atmp1111000111 , ef8sym ) ) {
{
ATerm atmp11110001110 = arg_0 ( atmp1111000111 ) ;
{
ATerm atmp11110001111 = arg_1 ( atmp1111000111 ) ;
if ( check_sym ( atmp11110001111 , ef8sym ) ) {
{
ATerm atmp111100011110 = arg_0 ( atmp11110001111 ) ;
{
ATerm atmp111100011111 = arg_1 ( atmp11110001111 ) ;
if ( check_sym ( atmp111100011111 , ef8sym ) ) {
{
ATerm atmp1111000111110 = arg_0 ( atmp111100011111 ) ;
{
ATerm atmp1111000111111 = arg_1 ( atmp111100011111 ) ;
if ( check_sym ( atmp1111000111111 , ef3sym ) ) {
{
ATerm atmp11110001111110 = arg_0 ( atmp1111000111111 ) ;
if ( not_empty_list ( atmp0100000 ) ) {
if ( term_equal ( list_head ( atmp0100000 ) , make_char ( 34 ) ) ) {
tmp [ 0 ] = list_tail ( atmp0100000 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 1 ] = list_prefix ( tmp [ 0 ] ) ;
if ( term_equal ( list_last ( tmp [ 0 ] ) , make_char ( 34 ) ) ) {
if ( not_empty_list ( atmp1110100000 ) ) {
if ( term_equal ( list_head ( atmp1110100000 ) , make_char ( 34 ) ) ) {
tmp [ 2 ] = list_tail ( atmp1110100000 ) ;
if ( is_single_element ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 34 ) ) ) {
if ( not_empty_list ( atmp1111000110100000 ) ) {
if ( term_equal ( list_head ( atmp1111000110100000 ) , make_char ( 34 ) ) ) {
tmp [ 3 ] = list_tail ( atmp1111000110100000 ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 45 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 62 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ;
if ( is_single_element ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 34 ) ) ) {
if ( term_equal ( ( * ef15 ) ( atmp110 ) , ( constant0 ? constant0 : ( constant0 = ( * ef16 ) ( ) ) ) ) ) {
tmp [ 6 ] = ( * ef17 ) ( atmp11110000 ) ;
tmp [ 7 ] = ( * ef18 ) ( atmp111100011110 ) ;
tmp [ 8 ] = ( * ef19 ) ( atmp11110001111110 ) ;
FUNC_EXIT ( ( * ef13 ) ( ( * ef13 ) ( ( * ef13 ) ( ( * ef13 ) ( ( * ef13 ) ( ( * ef13 ) ( ( * ef13 ) ( ( * ef13 ) ( ( * ef14 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 34 ] , char_table [ 112 ] , char_table [ 114 ] , char_table [ 111 ] , char_table [ 100 ] , char_table [ 40 ] , char_table [ 105 ] , char_table [ 100 ] , char_table [ 40 ] , char_table [ 34 ] ) ) ) , ( * ef14 ) ( lf2 ( cons ( make_list_char ( 34 ) , cons ( make_list_char ( 92 ) , cons ( make_list_char ( 34 ) , cons ( make_list ( tmp [ 1 ] ) , ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) , ( * ef14 ) ( lf2 ( ( ATerm ) ATmakeList ( 12 , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) ) , tmp [ 6 ] ) , ( * ef14 ) ( lf2 ( ( ATerm ) ATmakeList ( 29 , char_table [ 34 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 45 ] , char_table [ 62 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) ) , tmp [ 7 ] ) , ( * ef14 ) ( lf2 ( ( ATerm ) ATmakeList ( 11 , char_table [ 34 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) ) , tmp [ 8 ] ) , ( * ef14 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_TermAsFix2Sign10_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

