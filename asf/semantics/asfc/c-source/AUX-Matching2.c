#include  "asc-support.h"
static Symbol lf_AUX_Matching2_1sym ;
static ATerm lf_AUX_Matching2_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef19sym ;
static funcptr ef19 ;
void register_AUX_Matching2 ( ) {
lf_AUX_Matching2_1sym = ATmakeSymbol ( "prod(id(\"Matching\"),w(\"\"),[l(\"match1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Subs\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Matching2_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Matching\"),w(\"\"),[l(\"match1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Subs\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)" ) , lf_AUX_Matching2_1 , lf_AUX_Matching2_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Matching2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Matching\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Matching\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Substitution\"),w(\"\"),[l(\"assign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Substitution\"),w(\"\"),[l(\"assign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Substitution\"),w(\"\"),[l(\"undefined\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Substitution\"),w(\"\"),[l(\"undefined\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"require-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"require-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Substitution\"),w(\"\"),[l(\"value\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Substitution\"),w(\"\"),[l(\"value\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"Matching\"),w(\"\"),[l(\"nomatch\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"Matching\"),w(\"\"),[l(\"nomatch\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Matching2 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Matching2_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Matching2_1sym , ATmakeAppl ( lf_AUX_Matching2_1sym , arg0 , arg1 , arg2 ) ) ;
{
ATerm ltmp [ 3 ] ;
lbl_lf_AUX_Matching2_1 : ltmp [ 0 ] = arg0 ;
( ltmp [ 1 ] = arg1 ) ;
( ltmp [ 2 ] = arg2 ) ;
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
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
if ( check_sym ( ltmp [ 1 ] , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , ef3sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( check_sym ( atmp1000 , lf2sym ) ) {
{
ATerm atmp10000 = arg_0 ( atmp1000 ) ;
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( not_empty_list ( atmp00000 ) ) {
if ( term_equal ( list_head ( atmp00000 ) , make_char ( 65 ) ) ) {
( tmp [ 0 ] = list_tail ( atmp00000 ) ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 73 ) ) ) {
( tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 110 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( is_single_element ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 116 ) ) ) {
if ( not_empty_list ( atmp10000 ) ) {
if ( term_equal ( list_head ( atmp10000 ) , make_char ( 65 ) ) ) {
( tmp [ 3 ] = list_tail ( atmp10000 ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 73 ) ) ) {
( tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 110 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ) ;
if ( is_single_element ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 116 ) ) ) {
FUNC_EXIT ( ltmp [ 2 ] ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( term_equal ( ( * ef12 ) ( atmp00 , atmp20 ) , ltmp [ 1 ] ) ) {
FUNC_EXIT ( ltmp [ 2 ] ) ;
}
if ( term_equal ( ( * ef8 ) ( atmp00 , atmp20 ) , ( constant0 ? constant0 : ( constant0 = ( * ef9 ) ( ) ) ) ) ) {
if ( term_equal ( ( * ef10 ) ( ( * ef11 ) ( ltmp [ 0 ] ) , ltmp [ 1 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef9 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef4 ) ( ( * ef7 ) ( atmp00 , atmp20 , ltmp [ 1 ] ) ) ) ;
}
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef5sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef6sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( ltmp [ 1 ] , ef5sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef6sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( term_equal ( atmp000 , atmp100 ) ) {
FUNC_EXIT ( ltmp [ 2 ] ) ;
}
}
}
}
}
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef13sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( ltmp [ 1 ] , ef13sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( term_equal ( atmp00 , atmp10 ) ) {
( arg0 = ( * ef14 ) ( ( * ef15 ) ( atmp01 ) ) ) ;
( arg1 = ( * ef14 ) ( ( * ef15 ) ( atmp11 ) ) ) ;
goto lbl_lf_AUX_Matching2_1 ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef14sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef16sym ) ) {
if ( check_sym ( ltmp [ 1 ] , ef14sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef16sym ) ) {
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
FUNC_EXIT ( ltmp [ 2 ] ) ;
}
}
}
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef15sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( ltmp [ 1 ] , ef14sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef15sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
( tmp [ 0 ] = lf_AUX_Matching2_1 ( ( * ef18 ) ( ( * ef15 ) ( atmp000 ) ) , ( * ef18 ) ( ( * ef15 ) ( atmp100 ) ) , ltmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( arg0 = ( * ef14 ) ( ( * ef17 ) ( ( * ef15 ) ( atmp000 ) ) ) ) ;
( arg1 = ( * ef14 ) ( ( * ef17 ) ( ( * ef15 ) ( atmp100 ) ) ) ) ;
( arg2 = ( * ef4 ) ( tmp [ 1 ] ) ) ;
goto lbl_lf_AUX_Matching2_1 ;
}
}
}
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
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( term_equal ( ( * ef8 ) ( atmp10 , atmp20 ) , ( constant0 ? constant0 : ( constant0 = ( * ef9 ) ( ) ) ) ) ) {
if ( term_equal ( ( * ef10 ) ( ( * ef11 ) ( ltmp [ 1 ] ) , ltmp [ 0 ] ) , ( constant0 ? constant0 : ( constant0 = ( * ef9 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef4 ) ( ( * ef7 ) ( atmp10 , atmp20 , ltmp [ 0 ] ) ) ) ;
}
}
if ( term_equal ( ( * ef12 ) ( atmp10 , atmp20 ) , ltmp [ 0 ] ) ) {
FUNC_EXIT ( ltmp [ 2 ] ) ;
}
}
}
}
}
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( term_equal ( ltmp [ 0 ] , ltmp [ 1 ] ) ) {
FUNC_EXIT ( ltmp [ 2 ] ) ;
}
}
}
if ( check_sym ( ltmp [ 2 ] , ef4sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
FUNC_EXIT_CONST ( constant1 , ( * ef19 ) ( ) ) ;
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Matching2_1sym , ltmp [ 0 ] , ltmp [ 1 ] , ltmp [ 2 ] ) ) ;
}
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

