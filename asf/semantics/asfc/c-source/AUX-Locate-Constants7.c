#include  "asc-support.h"
static Symbol lf_AUX_Locate_Constants7_1sym ;
static ATerm lf_AUX_Locate_Constants7_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef13sym ;
static funcptr ef13 ;
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
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
void register_AUX_Locate_Constants7 ( ) {
lf_AUX_Locate_Constants7_1sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-stat\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESI-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants7_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-stat\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants7_1 , lf_AUX_Locate_Constants7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CE-pair\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
}
void resolve_AUX_Locate_Constants7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"flatten-list-of-chars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"flatten-list-of-chars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-expression\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-stats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-stats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Locate_Constants7 ( ) {
}
ATerm lf_AUX_Locate_Constants7_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 16 ] ;
FUNC_ENTRY ( lf_AUX_Locate_Constants7_1sym , ATmakeAppl ( lf_AUX_Locate_Constants7_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , ef3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( atmp0000 , ef4sym ) ) {
{
ATerm atmp00000 = arg_0 ( atmp0000 ) ;
if ( check_sym ( atmp00000 , ef5sym ) ) {
{
ATerm atmp000000 = arg_0 ( atmp00000 ) ;
if ( check_sym ( atmp000000 , ef6sym ) ) {
{
ATerm atmp0000000 = arg_0 ( atmp000000 ) ;
if ( check_sym ( atmp0000000 , lf2sym ) ) {
{
ATerm atmp00000000 = arg_0 ( atmp0000000 ) ;
{
ATerm atmp00001 = arg_1 ( atmp0000 ) ;
if ( check_sym ( atmp00001 , ef7sym ) ) {
{
ATerm atmp000010 = arg_0 ( atmp00001 ) ;
if ( check_sym ( atmp000010 , lf3sym ) ) {
{
ATerm atmp0000100 = arg_0 ( atmp000010 ) ;
if ( check_sym ( arg1 , ef8sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( not_empty_list ( atmp00000000 ) ) {
( tmp [ 0 ] = list_head ( atmp00000000 ) ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 70 ) ) ) {
( tmp [ 1 ] = list_tail ( atmp00000000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 85 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 78 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 67 ) ) ) {
( tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 95 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 69 ) ) ) {
( tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 78 ) ) ) {
( tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 84 ) ) ) {
( tmp [ 8 ] = list_tail ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 82 ) ) ) {
( tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ) ;
if ( is_single_element ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 89 ) ) ) {
if ( not_empty_list ( atmp0000100 ) ) {
( tmp [ 10 ] = list_head ( atmp0000100 ) ) ;
( tmp [ 11 ] = list_tail ( atmp0000100 ) ) ;
if ( is_single_element ( tmp [ 11 ] ) ) {
( tmp [ 12 ] = list_head ( tmp [ 11 ] ) ) ;
FUNC_EXIT ( ( * ef9 ) ( lf4 ( make_list ( atmp100 ) ) , ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ( * ef6 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 70 ] , char_table [ 85 ] , char_table [ 78 ] , char_table [ 67 ] , char_table [ 95 ] , char_table [ 69 ] , char_table [ 78 ] , char_table [ 84 ] , char_table [ 82 ] , char_table [ 89 ] ) ) ) ) , ( * ef7 ) ( lf3 ( cons ( make_list ( tmp [ 10 ] ) , make_list ( tmp [ 12 ] ) ) ) ) ) ) ) ) , atmp11 ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if ( term_equal ( tmp [ 0 ] , make_char ( 67 ) ) ) {
( tmp [ 1 ] = list_tail ( atmp00000000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 79 ) ) ) {
( tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 78 ) ) ) {
( tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 83 ) ) ) {
( tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 95 ) ) ) {
( tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 69 ) ) ) {
( tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 78 ) ) ) {
( tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 84 ) ) ) {
( tmp [ 8 ] = list_tail ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 82 ) ) ) {
( tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ) ;
if ( is_single_element ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 89 ) ) ) {
if ( not_empty_list ( atmp0000100 ) ) {
( tmp [ 10 ] = list_head ( atmp0000100 ) ) ;
( tmp [ 11 ] = list_tail ( atmp0000100 ) ) ;
if ( is_single_element ( tmp [ 11 ] ) ) {
( tmp [ 12 ] = list_head ( tmp [ 11 ] ) ) ;
FUNC_EXIT ( ( * ef9 ) ( lf4 ( make_list ( atmp100 ) ) , ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( ( * ef6 ) ( lf2 ( ( ATerm ) ATmakeList ( 10 , char_table [ 67 ] , char_table [ 79 ] , char_table [ 78 ] , char_table [ 83 ] , char_table [ 95 ] , char_table [ 69 ] , char_table [ 78 ] , char_table [ 84 ] , char_table [ 82 ] , char_table [ 89 ] ) ) ) ) , ( * ef7 ) ( lf3 ( cons ( make_list ( tmp [ 10 ] ) , make_list ( tmp [ 12 ] ) ) ) ) ) ) ) ) , atmp11 ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef13sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( arg1 , ef8sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
( tmp [ 0 ] = ( * ef14 ) ( atmp01 , ( * ef8 ) ( lf4 ( make_list ( atmp100 ) ) , atmp11 ) ) ) ;
if ( check_sym ( tmp [ 0 ] , ef15sym ) ) {
( tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ) ;
( tmp [ 2 ] = arg_1 ( tmp [ 0 ] ) ) ;
( tmp [ 3 ] = arg_2 ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 1 ] , lf4sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 1 ] ) ) ;
FUNC_EXIT ( ( * ef9 ) ( lf4 ( make_list ( tmp [ 4 ] ) ) , ( * ef13 ) ( atmp00 , tmp [ 2 ] ) , tmp [ 3 ] ) ) ;
}
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef16sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( arg1 , ef8sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
( tmp [ 0 ] = ( * ef10 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef11 ) ( tmp [ 0 ] , ( * ef8 ) ( lf4 ( make_list ( atmp100 ) ) , atmp11 ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef12sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 6 ] = lf_AUX_Locate_Constants7_1 ( atmp01 , ( * ef8 ) ( lf4 ( make_list ( tmp [ 5 ] ) ) , tmp [ 4 ] ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef9sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
( tmp [ 8 ] = arg_1 ( tmp [ 6 ] ) ) ;
( tmp [ 9 ] = arg_2 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 7 ] ) ) ;
FUNC_EXIT ( ( * ef9 ) ( lf4 ( make_list ( tmp [ 10 ] ) ) , ( * ef16 ) ( tmp [ 3 ] , tmp [ 8 ] ) , tmp [ 9 ] ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef17sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( arg1 , ef8sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
( tmp [ 0 ] = ( * ef10 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef11 ) ( tmp [ 0 ] , ( * ef8 ) ( lf4 ( make_list ( atmp100 ) ) , atmp11 ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef12sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 6 ] = lf_AUX_Locate_Constants7_1 ( atmp01 , ( * ef8 ) ( lf4 ( make_list ( tmp [ 5 ] ) ) , tmp [ 4 ] ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef9sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
( tmp [ 8 ] = arg_1 ( tmp [ 6 ] ) ) ;
( tmp [ 9 ] = arg_2 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 7 ] ) ) ;
( tmp [ 11 ] = lf_AUX_Locate_Constants7_1 ( atmp02 , ( * ef8 ) ( lf4 ( make_list ( tmp [ 10 ] ) ) , tmp [ 9 ] ) ) ) ;
if ( check_sym ( tmp [ 11 ] , ef9sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ) ;
( tmp [ 13 ] = arg_1 ( tmp [ 11 ] ) ) ;
( tmp [ 14 ] = arg_2 ( tmp [ 11 ] ) ) ;
if ( check_sym ( tmp [ 12 ] , lf4sym ) ) {
( tmp [ 15 ] = arg_0 ( tmp [ 12 ] ) ) ;
FUNC_EXIT ( ( * ef9 ) ( lf4 ( make_list ( tmp [ 15 ] ) ) , ( * ef17 ) ( tmp [ 3 ] , tmp [ 8 ] , tmp [ 13 ] ) , tmp [ 14 ] ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef18sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( arg1 , ef8sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
( tmp [ 0 ] = ( * ef10 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef11 ) ( tmp [ 0 ] , ( * ef8 ) ( lf4 ( make_list ( atmp100 ) ) , atmp11 ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef12sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 6 ] = lf_AUX_Locate_Constants7_1 ( atmp01 , ( * ef8 ) ( lf4 ( make_list ( tmp [ 5 ] ) ) , tmp [ 4 ] ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef9sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
( tmp [ 8 ] = arg_1 ( tmp [ 6 ] ) ) ;
( tmp [ 9 ] = arg_2 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf4sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 7 ] ) ) ;
FUNC_EXIT ( ( * ef9 ) ( lf4 ( make_list ( tmp [ 10 ] ) ) , ( * ef18 ) ( tmp [ 3 ] , tmp [ 8 ] ) , tmp [ 9 ] ) ) ;
}
}
}
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
if ( check_sym ( arg1 , ef8sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
( tmp [ 0 ] = ( * ef10 ) ( atmp00 ) ) ;
( tmp [ 1 ] = ( * ef11 ) ( tmp [ 0 ] , ( * ef8 ) ( lf4 ( make_list ( atmp100 ) ) , atmp11 ) ) ) ;
if ( check_sym ( tmp [ 1 ] , ef12sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ) ;
( tmp [ 4 ] = arg_2 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf4sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ) ;
FUNC_EXIT ( ( * ef9 ) ( lf4 ( make_list ( tmp [ 5 ] ) ) , ( * ef1 ) ( tmp [ 3 ] ) , tmp [ 4 ] ) ) ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg1 , ef8sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
FUNC_EXIT ( ( * ef9 ) ( lf4 ( make_list ( atmp100 ) ) , arg0 , atmp11 ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Locate_Constants7_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

