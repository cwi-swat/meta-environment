#include  "asc-support.h"
static Symbol lf_AUX_Integers9_1sym ;
static ATerm lf_AUX_Integers9_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
void register_AUX_Integers9 ( ) {
lf_AUX_Integers9_1sym = ATmakeSymbol ( "prod(id(\"Integers\"),w(\"\"),[sort(\"NatCon\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Integers9_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Integers\"),w(\"\"),[sort(\"NatCon\"),w(\"\"),ql(\"-//\"),w(\"\"),sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) , lf_AUX_Integers9_1 , lf_AUX_Integers9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Integers9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
static ATerm constant6 = NULL ;
static ATerm constant7 = NULL ;
static ATerm constant8 = NULL ;
static ATerm constant9 = NULL ;
void init_AUX_Integers9 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
ATprotect ( & constant6 ) ;
ATprotect ( & constant7 ) ;
ATprotect ( & constant8 ) ;
ATprotect ( & constant9 ) ;
}
ATerm lf_AUX_Integers9_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 10 ] ;
FUNC_ENTRY ( lf_AUX_Integers9_1sym , ATmakeAppl ( lf_AUX_Integers9_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( is_single_element ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 50 ) ) ) {
if ( is_single_element ( atmp100 ) ) {
if ( term_equal ( list_head ( atmp100 ) , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
}
}
tmp [ 1 ] = make_char ( 51 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 1 ] ) ) {
if ( is_single_element ( atmp100 ) ) {
tmp [ 2 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 2 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ;
}
}
}
tmp [ 2 ] = make_char ( 52 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 2 ] ) ) {
if ( is_single_element ( atmp100 ) ) {
tmp [ 3 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 3 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 51 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 51 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
}
}
tmp [ 3 ] = make_char ( 53 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 3 ] ) ) {
if ( is_single_element ( atmp100 ) ) {
tmp [ 4 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 4 ] , make_char ( 52 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 4 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 52 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 4 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 51 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 4 ] , make_char ( 51 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ;
}
}
}
tmp [ 4 ] = make_char ( 54 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 4 ] ) ) {
if ( is_single_element ( atmp100 ) ) {
tmp [ 5 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 5 ] , make_char ( 52 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 5 ] , make_char ( 53 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 5 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant4 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 53 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 5 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 52 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 5 ] , make_char ( 51 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 51 ) ) ) ) ) ;
}
}
}
tmp [ 5 ] = make_char ( 55 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 5 ] ) ) {
if ( is_single_element ( atmp100 ) ) {
tmp [ 6 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 6 ] , make_char ( 52 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 51 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 6 ] , make_char ( 53 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 6 ] , make_char ( 54 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 6 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant5 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 54 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 6 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant4 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 53 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 6 ] , make_char ( 51 ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 52 ) ) ) ) ) ;
}
}
}
tmp [ 6 ] = make_char ( 56 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 6 ] ) ) {
if ( is_single_element ( atmp100 ) ) {
tmp [ 7 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 7 ] , make_char ( 52 ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 52 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 7 ] , make_char ( 53 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 51 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 7 ] , make_char ( 54 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 7 ] , make_char ( 55 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 7 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant6 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 55 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 7 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant5 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 54 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 7 ] , make_char ( 51 ) ) ) {
FUNC_EXIT_CONST ( constant4 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 53 ) ) ) ) ) ;
}
}
}
tmp [ 7 ] = make_char ( 57 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 7 ] ) ) {
if ( is_single_element ( atmp100 ) ) {
tmp [ 8 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 8 ] , make_char ( 52 ) ) ) {
FUNC_EXIT_CONST ( constant4 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 53 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 8 ] , make_char ( 53 ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 52 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 8 ] , make_char ( 54 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 51 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 8 ] , make_char ( 55 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 8 ] , make_char ( 56 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 8 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant7 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 56 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 8 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant6 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 55 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 8 ] , make_char ( 51 ) ) ) {
FUNC_EXIT_CONST ( constant5 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 54 ) ) ) ) ) ;
}
}
}
{
tmp [ 8 ] = list_head ( atmp000 ) ;
{
if ( is_single_element ( atmp100 ) ) {
tmp [ 9 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 8 ] , tmp [ 9 ] ) ) {
FUNC_EXIT_CONST ( constant8 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 48 ) ) ) ) ) ;
}
if ( term_equal ( list_head ( atmp100 ) , make_char ( 48 ) ) ) {
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 8 ] ) ) ) ) ;
}
}
}
}
}
{
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 49 ) ) ) {
tmp [ 1 ] = list_tail ( atmp000 ) ;
{
if ( is_single_element ( tmp [ 1 ] ) ) {
tmp [ 2 ] = list_head ( tmp [ 1 ] ) ;
if ( term_equal ( tmp [ 2 ] , make_char ( 48 ) ) ) {
if ( is_single_element ( atmp100 ) ) {
tmp [ 3 ] = list_head ( atmp100 ) ;
if ( term_equal ( tmp [ 3 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant7 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 56 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 51 ) ) ) {
FUNC_EXIT_CONST ( constant6 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 55 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 52 ) ) ) {
FUNC_EXIT_CONST ( constant5 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 54 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 53 ) ) ) {
FUNC_EXIT_CONST ( constant4 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 53 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 54 ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 52 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 55 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 51 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 56 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 50 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 57 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 49 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant9 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 57 ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Integers9_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

