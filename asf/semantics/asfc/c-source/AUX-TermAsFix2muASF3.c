#include  "asc-support.h"
static Symbol lf_AUX_TermAsFix2muASF3_2sym ;
static ATerm lf_AUX_TermAsFix2muASF3_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf_AUX_TermAsFix2muASF3_1sym ;
static ATerm lf_AUX_TermAsFix2muASF3_1 ( ATerm arg1 ) ;
void register_AUX_TermAsFix2muASF3 ( ) {
lf_AUX_TermAsFix2muASF3_2sym = ATmakeSymbol ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[l(\"make-c-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFix2muASF3_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_TermAsFix2muASF3_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFix2muASF3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_TermAsFix2muASF3_1 , lf_AUX_TermAsFix2muASF3_1sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFix2muASF\"),w(\"\"),[l(\"make-c-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFix2muASF3_2 , lf_AUX_TermAsFix2muASF3_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_TermAsFix2muASF3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_TermAsFix2muASF3 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_TermAsFix2muASF3_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 13 ] ;
FUNC_ENTRY ( lf_AUX_TermAsFix2muASF3_2sym , ATmakeAppl ( lf_AUX_TermAsFix2muASF3_2sym , arg0 , arg1 ) ) ;
{
ATerm ltmp [ 2 ] ;
lbl_lf_AUX_TermAsFix2muASF3_2 : ltmp [ 0 ] = arg0 ;
ltmp [ 1 ] = arg1 ;
if ( check_sym ( ltmp [ 0 ] , lf_AUX_TermAsFix2muASF3_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( ltmp [ 1 ] , lf_AUX_TermAsFix2muASF3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
{
if ( ! not_empty_list ( atmp10 ) ) {
FUNC_EXIT ( tmp [ 0 ] ) ;
}
if ( is_single_element ( atmp10 ) ) {
tmp [ 1 ] = list_head ( atmp10 ) ;
if ( check_sym ( tmp [ 0 ] , ef1sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_TermAsFix2muASF3_1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
if ( term_equal ( list_head ( tmp [ 5 ] ) , make_char ( 99 ) ) ) {
tmp [ 7 ] = list_tail ( tmp [ 5 ] ) ;
if ( not_empty_list ( tmp [ 7 ] ) ) {
if ( term_equal ( list_head ( tmp [ 7 ] ) , make_char ( 111 ) ) ) {
tmp [ 8 ] = list_tail ( tmp [ 7 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
if ( term_equal ( list_head ( tmp [ 8 ] ) , make_char ( 110 ) ) ) {
tmp [ 9 ] = list_tail ( tmp [ 8 ] ) ;
if ( is_single_element ( tmp [ 9 ] ) ) {
if ( term_equal ( list_head ( tmp [ 9 ] ) , make_char ( 115 ) ) ) {
if ( not_empty_list ( tmp [ 6 ] ) ) {
tmp [ 10 ] = list_head ( tmp [ 6 ] ) ;
tmp [ 11 ] = list_tail ( tmp [ 6 ] ) ;
if ( is_single_element ( tmp [ 11 ] ) ) {
tmp [ 12 ] = list_head ( tmp [ 11 ] ) ;
arg0 = lf_AUX_TermAsFix2muASF3_1 ( make_list ( tmp [ 10 ] ) ) ;
arg1 = lf_AUX_TermAsFix2muASF3_1 ( make_list ( ( * ef1 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef2 ) ( lf3 ( cons ( make_list ( make_char ( 99 ) ) , cons ( make_list ( make_char ( 111 ) ) , cons ( make_list ( make_char ( 110 ) ) , make_list ( make_char ( 115 ) ) ) ) ) ) ) ) ) , lf_AUX_TermAsFix2muASF3_1 ( cons ( make_list ( tmp [ 12 ] ) , make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
goto lbl_lf_AUX_TermAsFix2muASF3_2 ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if ( ! not_empty_list ( atmp00 ) ) {
if ( is_single_element ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
FUNC_EXIT ( tmp [ 0 ] ) ;
}
}
}
}
}
}
if ( check_sym ( ltmp [ 0 ] , lf_AUX_TermAsFix2muASF3_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( ltmp [ 1 ] , lf_AUX_TermAsFix2muASF3_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
if ( is_single_element ( atmp10 ) ) {
tmp [ 1 ] = list_head ( atmp10 ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf3 ( ( ATerm ) ATmakeList ( 4 , char_table [ 99 ] , char_table [ 111 ] , char_table [ 110 ] , char_table [ 115 ] ) ) ) , lf_AUX_TermAsFix2muASF3_1 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 1 ] ) ) ) ) ) ;
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_TermAsFix2muASF3_2sym , ltmp [ 0 ] , ltmp [ 1 ] ) ) ;
}
}
}
ATerm lf_AUX_TermAsFix2muASF3_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_TermAsFix2muASF3_1sym , ATmakeAppl ( lf_AUX_TermAsFix2muASF3_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_TermAsFix2muASF3_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

