#include  "asc-support.h"
static Symbol lf_AUX_ATypes3_1sym ;
static ATerm lf_AUX_ATypes3_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef21sym ;
static funcptr ef21 ;
static Symbol ef23sym ;
static funcptr ef23 ;
static Symbol ef24sym ;
static funcptr ef24 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef25sym ;
static funcptr ef25 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef26sym ;
static funcptr ef26 ;
static Symbol ef22sym ;
static funcptr ef22 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef27sym ;
static funcptr ef27 ;
void register_AUX_ATypes3 ( ) {
lf_AUX_ATypes3_1sym = ATmakeSymbol ( "prod(id(\"ATypes\"),w(\"\"),[l(\"require-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATypes3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"ATypes\"),w(\"\"),[l(\"require-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_ATypes3_1 , lf_AUX_ATypes3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_ATypes3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"str\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"str\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Operations\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef21 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef21sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef22 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) ) ;
ef22sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) ) ;
ef23 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef23sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef24 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef24sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef25 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef25sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef26 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef26sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef27 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef27sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_ATypes3 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_ATypes3_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 3 ] ;
FUNC_ENTRY ( lf_AUX_ATypes3_1sym , ATmakeAppl ( lf_AUX_ATypes3_1sym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_ATypes3_1 : ltmp [ 0 ] = arg0 ;
( ltmp [ 1 ] = arg1 ) ;
if ( check_sym ( ltmp [ 0 ] , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
if ( check_sym ( ltmp [ 1 ] , ef3sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , ef5sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( check_sym ( atmp1000 , lf2sym ) ) {
{
ATerm atmp10000 = arg_0 ( atmp1000 ) ;
if ( not_empty_list ( atmp10000 ) ) {
if ( term_equal ( list_head ( atmp10000 ) , make_char ( 65 ) ) ) {
( tmp [ 0 ] = list_tail ( atmp10000 ) ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
if ( term_equal ( list_head ( tmp [ 0 ] ) , make_char ( 73 ) ) ) {
( tmp [ 1 ] = list_tail ( tmp [ 0 ] ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 110 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( is_single_element ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 116 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef6 ) ( ) ) ;
}
}
}
}
}
}
}
}
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
if ( check_sym ( atmp00 , ef7sym ) ) {
if ( check_sym ( ltmp [ 1 ] , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef8sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef6 ) ( ) ) ;
}
}
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef9sym ) ) {
if ( check_sym ( ltmp [ 1 ] , ef10sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef11sym ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef6 ) ( ) ) ;
}
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef12sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef6 ) ( ) ) ;
}
}
}
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef18sym ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef6 ) ( ) ) ;
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
FUNC_EXIT ( ( * ef19 ) ( ltmp [ 0 ] , ( * ef20 ) ( ltmp [ 1 ] ) ) ) ;
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef13sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef9sym ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef14sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( ltmp [ 1 ] , ef10sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef11sym ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef6 ) ( ) ) ;
}
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef12sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT ( ( * ef15 ) ( lf_AUX_ATypes3_1 ( atmp010 , ( * ef16 ) ( ( * ef12 ) ( atmp100 ) ) ) , lf_AUX_ATypes3_1 ( ltmp [ 0 ] , ( * ef10 ) ( ( * ef17 ) ( ( * ef12 ) ( atmp100 ) ) ) ) ) ) ;
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
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( ltmp [ 1 ] , ef13sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( term_equal ( atmp00 , atmp10 ) ) {
( arg0 = ( * ef10 ) ( ( * ef12 ) ( atmp01 ) ) ) ;
( arg1 = ( * ef10 ) ( ( * ef12 ) ( atmp11 ) ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef10sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef11sym ) ) {
if ( check_sym ( ltmp [ 1 ] , ef10sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef11sym ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef6 ) ( ) ) ;
}
}
}
}
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef12sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( ltmp [ 1 ] , ef10sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef12sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
FUNC_EXIT ( ( * ef15 ) ( lf_AUX_ATypes3_1 ( ( * ef16 ) ( ( * ef12 ) ( atmp000 ) ) , ( * ef16 ) ( ( * ef12 ) ( atmp100 ) ) ) , lf_AUX_ATypes3_1 ( ( * ef10 ) ( ( * ef17 ) ( ( * ef12 ) ( atmp000 ) ) ) , ( * ef10 ) ( ( * ef17 ) ( ( * ef12 ) ( atmp100 ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef21sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef22sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
( arg0 = ( * ef23 ) ( atmp00 ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef24sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef22sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
( arg0 = ( * ef1 ) ( atmp00 ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef25sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef22sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
( arg0 = ( * ef13 ) ( atmp00 , atmp01 ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , ef26sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef22sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
( arg0 = ( * ef10 ) ( atmp00 ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
if ( check_sym ( ltmp [ 1 ] , ef26sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , ef22sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
( arg1 = ( * ef10 ) ( atmp10 ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
if ( check_sym ( ltmp [ 1 ] , ef25sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
{
ATerm atmp12 = arg_2 ( arg1 ) ;
if ( check_sym ( atmp12 , ef22sym ) ) {
{
ATerm atmp120 = arg_0 ( atmp12 ) ;
( arg1 = ( * ef13 ) ( atmp10 , atmp11 ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
}
if ( check_sym ( ltmp [ 1 ] , ef24sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , ef22sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
( arg1 = ( * ef1 ) ( atmp10 ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
if ( check_sym ( ltmp [ 1 ] , ef21sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( check_sym ( atmp11 , ef22sym ) ) {
{
ATerm atmp110 = arg_0 ( atmp11 ) ;
( arg1 = ( * ef23 ) ( atmp10 ) ) ;
goto lbl_lf_AUX_ATypes3_1 ;
}
}
}
}
}
FUNC_EXIT_CONST ( constant1 , ( * ef27 ) ( ) ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_ATypes3_1sym , ltmp [ 0 ] , ltmp [ 1 ] ) ) ;
}
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

