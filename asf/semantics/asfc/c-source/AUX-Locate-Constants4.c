#include  "support.h"
static Symbol lf_AUX_Locate_Constants4_1sym ;
static ATerm lf_AUX_Locate_Constants4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Locate_Constants4 ( ) {
lf_AUX_Locate_Constants4_1sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decl\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants4_1sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Type-specifier\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-decl\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Declaration\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants4_1 , lf_AUX_Locate_Constants4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Type-specifier\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Parameter-declaration\"),ql(\",\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CE-pair\"),ql(\",\"))" ) , lf5 , lf5sym ) ;
}
void resolve_AUX_Locate_Constants4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-specifiers\"),w(\"\"),sort(\"Declarator\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter(sort(\"Type-specifier\"),w(\"\"),l(\"+\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-specifiers\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Type-specifier\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declarator\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Parameter-declaration\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-stats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"locate-constants-in-stats\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\",\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
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
void init_AUX_Locate_Constants4 ( ) {
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
ATerm lf_AUX_Locate_Constants4_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 15 ] ;
PROF ( prof_lf_AUX_Locate_Constants4_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , ef5sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
{
ATerm atmp011 = arg_1 ( atmp01 ) ;
if ( check_sym ( atmp011 , ef6sym ) ) {
{
ATerm atmp0110 = arg_0 ( atmp011 ) ;
if ( check_sym ( atmp0110 , lf4sym ) ) {
{
ATerm atmp01100 = arg_0 ( atmp0110 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef7sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
if ( check_sym ( atmp020 , ef8sym ) ) {
{
ATerm atmp021 = arg_1 ( atmp02 ) ;
if ( check_sym ( arg1 , ef9sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf5sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( is_single_element ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
if ( ! not_empty_list ( atmp01100 ) ) {
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 65 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 84 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 101 ) ) ) {
tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 114 ) ) ) {
tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ;
if ( is_single_element ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 109 ) ) ) {
tmp [ 8 ] = ( * ef11 ) ( atmp021 , ( * ef9 ) ( lf5 ( make_list ( atmp100 ) ) , atmp11 ) ) ;
if ( check_sym ( tmp [ 8 ] , ef12sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ;
tmp [ 11 ] = arg_2 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf5sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ;
return ( * ef10 ) ( lf5 ( make_list ( tmp [ 12 ] ) ) , ( * ef1 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef2 ) ( lf2 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf3 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) ) , ( * ef5 ) ( atmp010 , ( constant1 ? constant1 : ( constant1 = ( * ef6 ) ( lf4 ( make_list ( null ( ) ) ) ) ) ) ) , ( * ef7 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef8 ) ( ) ) ) , tmp [ 10 ] ) ) , tmp [ 11 ] ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp011 = arg_1 ( atmp01 ) ;
{
ATerm atmp02 = arg_2 ( arg0 ) ;
if ( check_sym ( atmp02 , ef7sym ) ) {
{
ATerm atmp020 = arg_0 ( atmp02 ) ;
if ( check_sym ( atmp020 , ef13sym ) ) {
{
ATerm atmp0200 = arg_0 ( atmp020 ) ;
{
ATerm atmp021 = arg_1 ( atmp02 ) ;
if ( check_sym ( arg1 , ef9sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf5sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( is_single_element ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 65 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 84 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 101 ) ) ) {
tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 114 ) ) ) {
tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ;
if ( is_single_element ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 109 ) ) ) {
tmp [ 8 ] = ( * ef11 ) ( atmp021 , ( * ef9 ) ( lf5 ( make_list ( atmp100 ) ) , atmp11 ) ) ;
if ( check_sym ( tmp [ 8 ] , ef12sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ;
tmp [ 11 ] = arg_2 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf5sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( atmp010 , ef4sym ) ) {
tmp [ 13 ] = arg_0 ( atmp010 ) ;
if ( check_sym ( tmp [ 13 ] , lf3sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
return ( * ef10 ) ( lf5 ( cons ( make_list ( ( * ef14 ) ( ( * ef15 ) ( ( * ef16 ) ( ( * ef17 ) ( ( * ef4 ) ( lf3 ( cons ( ( constant3 ? constant3 : ( constant3 = make_list_char ( 116 ) ) ) , cons ( ( constant4 ? constant4 : ( constant4 = make_list_char ( 97 ) ) ) , cons ( ( constant5 ? constant5 : ( constant5 = make_list_char ( 98 ) ) ) , cons ( ( constant6 ? constant6 : ( constant6 = make_list_char ( 108 ) ) ) , cons ( ( constant7 ? constant7 : ( constant7 = make_list_char ( 101 ) ) ) , cons ( ( constant8 ? constant8 : ( constant8 = make_list_char ( 95 ) ) ) , make_list ( tmp [ 14 ] ) ) ) ) ) ) ) ) ) ) ) ) , ( constant9 ? constant9 : ( constant9 = ( * ef15 ) ( ( * ef16 ) ( ( * ef17 ) ( ( * ef4 ) ( lf3 ( ( ATerm ) ATmakeList ( 4 , char_table [ 78 ] , char_table [ 85 ] , char_table [ 76 ] , char_table [ 76 ] ) ) ) ) ) ) ) ) ) ) , make_list ( tmp [ 12 ] ) ) ) , ( * ef1 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef2 ) ( lf2 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf3 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) ) , ( * ef5 ) ( atmp010 , atmp011 ) , ( * ef7 ) ( ( * ef13 ) ( atmp0200 ) , tmp [ 10 ] ) ) , tmp [ 11 ] ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp020 = arg_0 ( atmp02 ) ;
if ( check_sym ( atmp020 , ef8sym ) ) {
{
ATerm atmp021 = arg_1 ( atmp02 ) ;
if ( check_sym ( arg1 , ef9sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf5sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
{
ATerm atmp11 = arg_1 ( arg1 ) ;
if ( is_single_element ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 1 ] = arg_0 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 1 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
if ( check_sym ( tmp [ 2 ] , lf3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 65 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 84 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 101 ) ) ) {
tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 114 ) ) ) {
tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ;
if ( is_single_element ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 109 ) ) ) {
tmp [ 8 ] = ( * ef11 ) ( atmp021 , ( * ef9 ) ( lf5 ( make_list ( atmp100 ) ) , atmp11 ) ) ;
if ( check_sym ( tmp [ 8 ] , ef12sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ;
tmp [ 11 ] = arg_2 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf5sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ;
return ( * ef10 ) ( lf5 ( make_list ( tmp [ 12 ] ) ) , ( * ef1 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef2 ) ( lf2 ( make_list ( ( * ef3 ) ( ( * ef4 ) ( lf3 ( ( ATerm ) ATmakeList ( 5 , char_table [ 65 ] , char_table [ 84 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 109 ] ) ) ) ) ) ) ) ) ) , ( * ef5 ) ( atmp010 , atmp011 ) , ( * ef7 ) ( ( constant2 ? constant2 : ( constant2 = ( * ef8 ) ( ) ) ) , tmp [ 10 ] ) ) , tmp [ 11 ] ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
return make_nf2 ( lf_AUX_Locate_Constants4_1sym , arg0 , arg1 ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}
ATerm lf5 ( ATerm arg0 ) {
PROF ( prof_lf5 ) ;
return make_nf1 ( lf5sym , arg0 ) ;
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}
ATerm lf4 ( ATerm arg0 ) {
PROF ( prof_lf4 ) ;
return make_nf1 ( lf4sym , arg0 ) ;
}

