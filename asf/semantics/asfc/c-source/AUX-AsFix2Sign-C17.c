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
static ATerm constant0 = NULL ;
void init_AUX_AsFix2Sign_C17 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_AsFix2Sign_C17_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 24 ] ;
PROF ( prof_lf_AUX_AsFix2Sign_C17_2 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf3sym ) ) {
tmp [ 0 ] = arg_0 ( atmp000 ) ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 1 ] = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( is_char ( tmp [ 1 ] , 100 ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 2 ] = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( is_char ( tmp [ 2 ] , 101 ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 3 ] = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( is_char ( tmp [ 3 ] , 108 ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 4 ] = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( is_char ( tmp [ 4 ] , 97 ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 5 ] = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( is_char ( tmp [ 5 ] , 121 ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 6 ] = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( is_char ( tmp [ 6 ] , 105 ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 7 ] = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( is_char ( tmp [ 7 ] , 110 ) ) {
if ( is_single_element ( tmp [ 0 ] ) ) {
tmp [ 8 ] = list_head ( tmp [ 0 ] ) ;
if ( is_char ( tmp [ 8 ] , 103 ) ) {
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , lf_AUX_AsFix2Sign_C17_1sym ) ) {
tmp [ 9 ] = arg_0 ( atmp01 ) ;
{
ATerm atmp010 ;
if ( is_single_element ( tmp [ 9 ] ) ) {
atmp010 = list_head ( tmp [ 9 ] ) ;
if ( check_sym ( arg1 , lf_AUX_AsFix2Sign_C17_1sym ) ) {
tmp [ 10 ] = arg_0 ( arg1 ) ;
{
ATerm atmp1010 ;
ATerm atmp100 [ 2 ] ;
atmp100 [ 0 ] = tmp [ 10 ] ;
atmp100 [ 1 ] = tmp [ 10 ] ;
while ( not_empty_list ( tmp [ 10 ] ) ) {
atmp1010 = list_head ( tmp [ 10 ] ) ;
tmp [ 10 ] = list_tail ( tmp [ 10 ] ) ;
if ( check_sym ( atmp1010 , ef1sym ) ) {
tmp [ 11 ] = arg_0 ( atmp1010 ) ;
tmp [ 12 ] = arg_1 ( atmp1010 ) ;
if ( check_sym ( tmp [ 11 ] , ef2sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 11 ] ) ;
if ( check_sym ( tmp [ 13 ] , lf3sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
if ( not_empty_list ( tmp [ 14 ] ) ) {
tmp [ 15 ] = list_head ( tmp [ 14 ] ) ;
tmp [ 14 ] = list_tail ( tmp [ 14 ] ) ;
if ( is_char ( tmp [ 15 ] , 100 ) ) {
if ( not_empty_list ( tmp [ 14 ] ) ) {
tmp [ 16 ] = list_head ( tmp [ 14 ] ) ;
tmp [ 14 ] = list_tail ( tmp [ 14 ] ) ;
if ( is_char ( tmp [ 16 ] , 101 ) ) {
if ( not_empty_list ( tmp [ 14 ] ) ) {
tmp [ 17 ] = list_head ( tmp [ 14 ] ) ;
tmp [ 14 ] = list_tail ( tmp [ 14 ] ) ;
if ( is_char ( tmp [ 17 ] , 108 ) ) {
if ( not_empty_list ( tmp [ 14 ] ) ) {
tmp [ 18 ] = list_head ( tmp [ 14 ] ) ;
tmp [ 14 ] = list_tail ( tmp [ 14 ] ) ;
if ( is_char ( tmp [ 18 ] , 97 ) ) {
if ( not_empty_list ( tmp [ 14 ] ) ) {
tmp [ 19 ] = list_head ( tmp [ 14 ] ) ;
tmp [ 14 ] = list_tail ( tmp [ 14 ] ) ;
if ( is_char ( tmp [ 19 ] , 121 ) ) {
if ( not_empty_list ( tmp [ 14 ] ) ) {
tmp [ 20 ] = list_head ( tmp [ 14 ] ) ;
tmp [ 14 ] = list_tail ( tmp [ 14 ] ) ;
if ( is_char ( tmp [ 20 ] , 105 ) ) {
if ( not_empty_list ( tmp [ 14 ] ) ) {
tmp [ 21 ] = list_head ( tmp [ 14 ] ) ;
tmp [ 14 ] = list_tail ( tmp [ 14 ] ) ;
if ( is_char ( tmp [ 21 ] , 110 ) ) {
if ( is_single_element ( tmp [ 14 ] ) ) {
tmp [ 22 ] = list_head ( tmp [ 14 ] ) ;
if ( is_char ( tmp [ 22 ] , 103 ) ) {
if ( check_sym ( tmp [ 12 ] , lf_AUX_AsFix2Sign_C17_1sym ) ) {
tmp [ 23 ] = arg_0 ( tmp [ 12 ] ) ;
return ( * ef3 ) ( lf_AUX_AsFix2Sign_C17_1 ( cons ( slice ( atmp100 [ 0 ] , atmp100 [ 1 ] ) , cons ( make_list ( ( * ef1 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef2 ) ( lf3 ( ( ATerm ) ATmakeList ( 8 , char_table [ 100 ] , char_table [ 101 ] , char_table [ 108 ] , char_table [ 97 ] , char_table [ 121 ] , char_table [ 105 ] , char_table [ 110 ] , char_table [ 103 ] ) ) ) ) ) , lf_AUX_AsFix2Sign_C17_1 ( cons ( make_list ( atmp010 ) , tmp [ 23 ] ) ) ) ) , tmp [ 10 ] ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
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
tmp [ 10 ] = atmp100 [ 1 ] ;
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
return ( * ef3 ) ( lf_AUX_AsFix2Sign_C17_1 ( cons ( make_list ( arg0 ) , make_list ( atmp10 ) ) ) ) ;
}
}
return make_nf2 ( lf_AUX_AsFix2Sign_C17_2sym , arg0 , arg1 ) ;
}
}
ATerm lf_AUX_AsFix2Sign_C17_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_AsFix2Sign_C17_1 ) ;
return make_nf1 ( lf_AUX_AsFix2Sign_C17_1sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}

