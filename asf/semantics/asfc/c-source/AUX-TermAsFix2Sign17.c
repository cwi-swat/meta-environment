#include  "asc-support.h"
static Symbol lf_AUX_TermAsFix2Sign17_1sym ;
static ATerm lf_AUX_TermAsFix2Sign17_1 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef17sym ;
static funcptr ef17 ;
void register_AUX_TermAsFix2Sign17 ( ) {
lf_AUX_TermAsFix2Sign17_1sym = ATmakeSymbol ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"attrs2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFix2Sign17_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"attrs2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFix2Sign17_1 , lf_AUX_TermAsFix2Sign17_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_TermAsFix2Sign17 ( ) {
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
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-no-attr-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-no-attr-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"MuLiterals\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuLiterals\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-attr-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"is-attr-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"attrlist2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"attrlist2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_TermAsFix2Sign17 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_TermAsFix2Sign17_1 ( ATerm arg0 ) {
{
ATerm tmp [ 5 ] ;
FUNC_ENTRY ( lf_AUX_TermAsFix2Sign17_1sym , ATmakeAppl ( lf_AUX_TermAsFix2Sign17_1sym , arg0 ) ) ;
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
if ( term_equal ( ( * ef8 ) ( atmp010 ) , ( constant0 ? constant0 : ( constant0 = ( * ef9 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef7 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 34 ] , char_table [ 110 ] , char_table [ 111 ] , char_table [ 45 ] , char_table [ 97 ] , char_table [ 116 ] , char_table [ 116 ] , char_table [ 114 ] , char_table [ 115 ] , char_table [ 34 ] ) ) ) ) ;
}
}
{
ATerm atmp011100 = arg_0 ( atmp01110 ) ;
if ( check_sym ( atmp011100 , ef10sym ) ) {
{
ATerm atmp0111000 = arg_0 ( atmp011100 ) ;
if ( check_sym ( atmp0111000 , ef3sym ) ) {
{
ATerm atmp01110000 = arg_0 ( atmp0111000 ) ;
if ( check_sym ( atmp01110000 , ef1sym ) ) {
{
ATerm atmp011100000 = arg_0 ( atmp01110000 ) ;
if ( check_sym ( atmp011100000 , ef11sym ) ) {
{
ATerm atmp011100001 = arg_1 ( atmp01110000 ) ;
if ( check_sym ( atmp011100001 , ef4sym ) ) {
{
ATerm atmp0111000010 = arg_0 ( atmp011100001 ) ;
if ( check_sym ( atmp0111000010 , ef12sym ) ) {
{
ATerm atmp01110000100 = arg_0 ( atmp0111000010 ) ;
if ( check_sym ( atmp01110000100 , ef13sym ) ) {
{
ATerm atmp011100001000 = arg_0 ( atmp01110000100 ) ;
if ( check_sym ( atmp011100001000 , ef14sym ) ) {
{
ATerm atmp0111000010000 = arg_0 ( atmp011100001000 ) ;
if ( check_sym ( atmp0111000010000 , lf2sym ) ) {
{
ATerm atmp01110000100000 = arg_0 ( atmp0111000010000 ) ;
{
ATerm atmp01110001 = arg_1 ( atmp0111000 ) ;
if ( check_sym ( atmp01110001 , ef3sym ) ) {
{
ATerm atmp011100010 = arg_0 ( atmp01110001 ) ;
{
ATerm atmp011100011 = arg_1 ( atmp01110001 ) ;
if ( check_sym ( atmp011100011 , ef3sym ) ) {
{
ATerm atmp0111000110 = arg_0 ( atmp011100011 ) ;
{
ATerm atmp0111000111 = arg_1 ( atmp011100011 ) ;
if ( check_sym ( atmp0111000111 , ef3sym ) ) {
{
ATerm atmp01110001110 = arg_0 ( atmp0111000111 ) ;
{
ATerm atmp01110001111 = arg_1 ( atmp0111000111 ) ;
if ( check_sym ( atmp01110001111 , ef4sym ) ) {
{
ATerm atmp011100011110 = arg_0 ( atmp01110001111 ) ;
if ( check_sym ( atmp011100011110 , ef1sym ) ) {
{
ATerm atmp0111000111100 = arg_0 ( atmp011100011110 ) ;
if ( check_sym ( atmp0111000111100 , ef11sym ) ) {
{
ATerm atmp0111000111101 = arg_1 ( atmp011100011110 ) ;
if ( check_sym ( atmp0111000111101 , ef4sym ) ) {
{
ATerm atmp01110001111010 = arg_0 ( atmp0111000111101 ) ;
if ( check_sym ( atmp01110001111010 , ef12sym ) ) {
{
ATerm atmp011100011110100 = arg_0 ( atmp01110001111010 ) ;
if ( check_sym ( atmp011100011110100 , ef13sym ) ) {
{
ATerm atmp0111000111101000 = arg_0 ( atmp011100011110100 ) ;
if ( check_sym ( atmp0111000111101000 , ef14sym ) ) {
{
ATerm atmp01110001111010000 = arg_0 ( atmp0111000111101000 ) ;
if ( check_sym ( atmp01110001111010000 , lf2sym ) ) {
{
ATerm atmp011100011110100000 = arg_0 ( atmp01110001111010000 ) ;
if ( not_empty_list ( atmp01110000100000 ) ) {
if ( term_equal ( list_head ( atmp01110000100000 ) , make_char ( 34 ) ) ) {
( tmp [ 0 ] = list_tail ( atmp01110000100000 ) ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 123 ) ) ) {
( tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ) ;
if ( is_single_element ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 34 ) ) ) {
if ( not_empty_list ( atmp011100011110100000 ) ) {
if ( term_equal ( list_head ( atmp011100011110100000 ) , make_char ( 34 ) ) ) {
( tmp [ 2 ] = list_tail ( atmp011100011110100000 ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 125 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 34 ) ) ) {
if ( term_equal ( ( * ef16 ) ( atmp010 ) , ( constant0 ? constant0 : ( constant0 = ( * ef9 ) ( ) ) ) ) ) {
( tmp [ 4 ] = ( * ef17 ) ( atmp0111000110 ) ) ;
FUNC_EXIT ( ( * ef15 ) ( ( * ef15 ) ( ( * ef7 ) ( lf2 ( ( ATerm ) ATmakeList ( 25 , char_table [ 34 ] , char_table [ 97 ] , char_table [ 116 ] , char_table [ 116 ] , char_table [ 114 ] , char_table [ 115 ] , char_table [ 40 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 123 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) , tmp [ 4 ] ) , ( * ef7 ) ( lf2 ( ( ATerm ) ATmakeList ( 20 , char_table [ 34 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 125 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_TermAsFix2Sign17_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

