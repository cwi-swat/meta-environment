#include  "support.h"
static Symbol lf_AUX_MuASF_Term2C13_1sym ;
static ATerm lf_AUX_MuASF_Term2C13_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_MuASF_Term2C13 ( ) {
lf_AUX_MuASF_Term2C13_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"is-special-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Identifier\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Term2C13_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"is-special-name\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Identifier\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Term2C13_1 , lf_AUX_MuASF_Term2C13_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_MuASF_Term2C13 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_MuASF_Term2C13 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_MuASF_Term2C13_1 ( ATerm arg0 ) {
{
ATerm tmp [ 15 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Term2C13_1sym , ATmakeAppl ( lf_AUX_MuASF_Term2C13_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 110 ) ) ) {
tmp [ 1 ] = list_tail ( atmp000 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 117 ) ) ) {
tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 108 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ;
if ( is_single_element ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 108 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( ) ) ;
}
}
}
}
}
}
}
tmp [ 1 ] = make_char ( 109 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 1 ] ) ) {
tmp [ 2 ] = list_tail ( atmp000 ) ;
{
if ( not_empty_list ( tmp [ 2 ] ) ) {
tmp [ 3 ] = list_head ( tmp [ 2 ] ) ;
if ( term_equal ( tmp [ 3 ] , make_char ( 97 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 2 ] ) ;
{
if ( not_empty_list ( tmp [ 4 ] ) ) {
tmp [ 5 ] = list_head ( tmp [ 4 ] ) ;
if ( term_equal ( tmp [ 5 ] , make_char ( 107 ) ) ) {
tmp [ 6 ] = list_tail ( tmp [ 4 ] ) ;
{
if ( not_empty_list ( tmp [ 6 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 6 ] ) ;
if ( term_equal ( tmp [ 7 ] , make_char ( 101 ) ) ) {
tmp [ 8 ] = list_tail ( tmp [ 6 ] ) ;
{
if ( not_empty_list ( tmp [ 8 ] ) ) {
tmp [ 9 ] = list_head ( tmp [ 8 ] ) ;
if ( term_equal ( tmp [ 9 ] , make_char ( 95 ) ) ) {
tmp [ 10 ] = list_tail ( tmp [ 8 ] ) ;
{
if ( not_empty_list ( tmp [ 10 ] ) ) {
tmp [ 11 ] = list_head ( tmp [ 10 ] ) ;
if ( term_equal ( tmp [ 11 ] , make_char ( 110 ) ) ) {
tmp [ 12 ] = list_tail ( tmp [ 10 ] ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 102 ) ) ) {
tmp [ 13 ] = list_tail ( tmp [ 12 ] ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( ) ) ;
}
}
}
if ( term_equal ( tmp [ 11 ] , make_char ( 99 ) ) ) {
tmp [ 12 ] = list_tail ( tmp [ 10 ] ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 104 ) ) ) {
tmp [ 13 ] = list_tail ( tmp [ 12 ] ) ;
if ( not_empty_list ( tmp [ 13 ] ) ) {
if ( term_equal ( list_head ( tmp [ 13 ] ) , make_char ( 97 ) ) ) {
tmp [ 14 ] = list_tail ( tmp [ 13 ] ) ;
if ( is_single_element ( tmp [ 14 ] ) ) {
if ( term_equal ( list_head ( tmp [ 14 ] ) , make_char ( 114 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if ( term_equal ( tmp [ 0 ] , make_char ( 113 ) ) ) {
tmp [ 2 ] = list_tail ( atmp000 ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 117 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 111 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 116 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 101 ) ) ) {
tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
FUNC_EXIT_CONST ( constant1 , ( * ef3 ) ( ) ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_MuASF_Term2C13_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

