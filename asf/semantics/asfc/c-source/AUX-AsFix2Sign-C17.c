#include  "support.h"
static Symbol lf_AUX_AsFix2Sign_C17_2sym ;
static ATerm lf_AUX_AsFix2Sign_C17_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf_AUX_AsFix2Sign_C17_1sym ;
static ATerm lf_AUX_AsFix2Sign_C17_1 ( ATerm arg1 ) ;
void register_AUX_AsFix2Sign_C17 ( ) {
lf_AUX_AsFix2Sign_C17_2sym = ATmakeSymbol ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"++\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2Sign_C17_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_AsFix2Sign_C17_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2Sign_C17_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_AsFix2Sign_C17_1 , lf_AUX_AsFix2Sign_C17_1sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2Sign-C\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"++\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2Sign_C17_2 , lf_AUX_AsFix2Sign_C17_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_AsFix2Sign_C17 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_AsFix2Sign_C17 ( ) {
}
ATerm lf_AUX_AsFix2Sign_C17_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 21 ] ;
FUNC_ENTRY ( lf_AUX_AsFix2Sign_C17_2sym , ATmakeAppl ( lf_AUX_AsFix2Sign_C17_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf3sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , lf_AUX_AsFix2Sign_C17_1sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( check_sym ( arg1 , lf_AUX_AsFix2Sign_C17_1sym ) ) {
tmp [ 0 ] = arg_0 ( arg1 ) ;
{
ATerm atmp1010 ;
ATerm atmp100 [ 2 ] ;
atmp100 [ 0 ] = tmp [ 0 ] ;
atmp100 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp1010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( not_empty_list ( atmp0000 ) ) {
if ( term_equal ( list_head ( atmp0000 ) , make_char ( 100 ) ) ) {
tmp [ 1 ] = list_tail ( atmp0000 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
if ( term_equal ( list_head ( tmp [ 1 ] ) , make_char ( 101 ) ) ) {
tmp [ 2 ] = list_tail ( tmp [ 1 ] ) ;
if ( not_empty_list ( tmp [ 2 ] ) ) {
if ( term_equal ( list_head ( tmp [ 2 ] ) , make_char ( 108 ) ) ) {
tmp [ 3 ] = list_tail ( tmp [ 2 ] ) ;
if ( not_empty_list ( tmp [ 3 ] ) ) {
if ( term_equal ( list_head ( tmp [ 3 ] ) , make_char ( 97 ) ) ) {
tmp [ 4 ] = list_tail ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 4 ] ) ) {
if ( term_equal ( list_head ( tmp [ 4 ] ) , make_char ( 121 ) ) ) {
tmp [ 5 ] = list_tail ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 105 ) ) ) {
tmp [ 6 ] = list_tail ( tmp [ 5 ] ) ;
if ( not_empty_list ( tmp [ 6 ] ) ) {
if ( term_equal ( list_head ( tmp [ 6 ] ) , make_char ( 110 ) ) ) {
tmp [ 7 ] = list_tail ( tmp [ 6 ] ) ;
if ( is_single_element ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 103 ) ) ) {
if ( is_single_element ( atmp010 ) ) {
tmp [ 8 ] = list_head ( atmp010 ) ;
if ( check_sym ( atmp1010 , ef1sym ) ) {
tmp [ 9 ] = arg_0 ( atmp1010 ) ;
tmp [ 10 ] = arg_1 ( atmp1010 ) ;
if ( check_sym ( tmp [ 9 ] , ef2sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf_AUX_AsFix2Sign_C17_1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ;
if ( not_empty_list ( tmp [ 12 ] ) ) {
if ( term_equal ( list_head ( tmp [ 12 ] ) , make_char ( 100 ) ) ) {
tmp [ 14 ] = list_tail ( tmp [ 12 ] ) ;
if ( not_empty_list ( tmp [ 14 ] ) ) {
if ( term_equal ( list_head ( tmp [ 14 ] ) , make_char ( 101 ) ) ) {
tmp [ 15 ] = list_tail ( tmp [ 14 ] ) ;
if ( not_empty_list ( tmp [ 15 ] ) ) {
if ( term_equal ( list_head ( tmp [ 15 ] ) , make_char ( 108 ) ) ) {
tmp [ 16 ] = list_tail ( tmp [ 15 ] ) ;
if ( not_empty_list ( tmp [ 16 ] ) ) {
if ( term_equal ( list_head ( tmp [ 16 ] ) , make_char ( 97 ) ) ) {
tmp [ 17 ] = list_tail ( tmp [ 16 ] ) ;
if ( not_empty_list ( tmp [ 17 ] ) ) {
if ( term_equal ( list_head ( tmp [ 17 ] ) , make_char ( 121 ) ) ) {
tmp [ 18 ] = list_tail ( tmp [ 17 ] ) ;
if ( not_empty_list ( tmp [ 18 ] ) ) {
if ( term_equal ( list_head ( tmp [ 18 ] ) , make_char ( 105 ) ) ) {
tmp [ 19 ] = list_tail ( tmp [ 18 ] ) ;
if ( not_empty_list ( tmp [ 19 ] ) ) {
if ( term_equal ( list_head ( tmp [ 19 ] ) , make_char ( 110 ) ) ) {
tmp [ 20 ] = list_tail ( tmp [ 19 ] ) ;
if ( is_single_element ( tmp [ 20 ] ) ) {
if ( term_equal ( list_head ( tmp [ 20 ] ) , make_char ( 103 ) ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf_AUX_AsFix2Sign_C17_1 ( cons ( slice ( atmp100 [ 0 ] , atmp100 [ 1 ] ) , cons ( make_list ( ( * ef1 ) ( ( * ef2 ) ( lf3 ( ( ATerm ) ATmakeList ( 8 , char_table [ 100 ] , char_table [ 101 ] , char_table [ 108 ] , char_table [ 97 ] , char_table [ 121 ] , char_table [ 105 ] , char_table [ 110 ] , char_table [ 103 ] ) ) ) , lf_AUX_AsFix2Sign_C17_1 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 13 ] ) ) ) ) ) , tmp [ 0 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
atmp100 [ 1 ] = list_tail ( atmp100 [ 1 ] ) ;
tmp [ 0 ] = atmp100 [ 1 ] ;
}
}
}
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg1 , lf_AUX_AsFix2Sign_C17_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
FUNC_EXIT ( ( * ef3 ) ( lf_AUX_AsFix2Sign_C17_1 ( cons ( make_list ( arg0 ) , make_list ( atmp10 ) ) ) ) ) ;
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_AsFix2Sign_C17_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_AsFix2Sign_C17_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_AsFix2Sign_C17_1sym , ATmakeAppl ( lf_AUX_AsFix2Sign_C17_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_AsFix2Sign_C17_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

