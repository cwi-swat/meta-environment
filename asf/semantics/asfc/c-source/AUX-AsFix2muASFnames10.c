#include  "asc-support.h"
static Symbol lf_AUX_AsFix2muASFnames10_1sym ;
static ATerm lf_AUX_AsFix2muASFnames10_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_AsFix2muASFnames10 ( ) {
lf_AUX_AsFix2muASFnames10_1sym = ATmakeSymbol ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[ql(\"upper2lower\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2muASFnames10_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[ql(\"upper2lower\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2muASFnames10_1 , lf_AUX_AsFix2muASFnames10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_AsFix2muASFnames10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
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
static ATerm constant10 = NULL ;
static ATerm constant11 = NULL ;
static ATerm constant12 = NULL ;
static ATerm constant13 = NULL ;
static ATerm constant14 = NULL ;
static ATerm constant15 = NULL ;
static ATerm constant16 = NULL ;
static ATerm constant17 = NULL ;
static ATerm constant18 = NULL ;
static ATerm constant19 = NULL ;
static ATerm constant20 = NULL ;
static ATerm constant21 = NULL ;
static ATerm constant22 = NULL ;
static ATerm constant23 = NULL ;
static ATerm constant24 = NULL ;
static ATerm constant25 = NULL ;
void init_AUX_AsFix2muASFnames10 ( ) {
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
ATprotect ( & constant10 ) ;
ATprotect ( & constant11 ) ;
ATprotect ( & constant12 ) ;
ATprotect ( & constant13 ) ;
ATprotect ( & constant14 ) ;
ATprotect ( & constant15 ) ;
ATprotect ( & constant16 ) ;
ATprotect ( & constant17 ) ;
ATprotect ( & constant18 ) ;
ATprotect ( & constant19 ) ;
ATprotect ( & constant20 ) ;
ATprotect ( & constant21 ) ;
ATprotect ( & constant22 ) ;
ATprotect ( & constant23 ) ;
ATprotect ( & constant24 ) ;
ATprotect ( & constant25 ) ;
}
ATerm lf_AUX_AsFix2muASFnames10_1 ( ATerm arg0 ) {
{
ATerm tmp [ 9 ] ;
FUNC_ENTRY ( lf_AUX_AsFix2muASFnames10_1sym , ATmakeAppl ( lf_AUX_AsFix2muASFnames10_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( is_single_element ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 67 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 99 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 68 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 100 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 69 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 101 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 70 ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 102 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 71 ) ) ) {
FUNC_EXIT_CONST ( constant4 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 103 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 72 ) ) ) {
FUNC_EXIT_CONST ( constant5 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 104 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 73 ) ) ) {
FUNC_EXIT_CONST ( constant6 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 105 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 74 ) ) ) {
FUNC_EXIT_CONST ( constant7 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 106 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 75 ) ) ) {
FUNC_EXIT_CONST ( constant8 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 107 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 76 ) ) ) {
FUNC_EXIT_CONST ( constant9 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 108 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 77 ) ) ) {
FUNC_EXIT_CONST ( constant10 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 109 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 78 ) ) ) {
FUNC_EXIT_CONST ( constant11 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 110 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 79 ) ) ) {
FUNC_EXIT_CONST ( constant12 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 111 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 80 ) ) ) {
FUNC_EXIT_CONST ( constant13 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 112 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 81 ) ) ) {
FUNC_EXIT_CONST ( constant14 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 113 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 82 ) ) ) {
FUNC_EXIT_CONST ( constant15 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 114 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 83 ) ) ) {
FUNC_EXIT_CONST ( constant16 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 115 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 84 ) ) ) {
FUNC_EXIT_CONST ( constant17 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 116 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 85 ) ) ) {
FUNC_EXIT_CONST ( constant18 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 117 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 86 ) ) ) {
FUNC_EXIT_CONST ( constant19 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 118 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 87 ) ) ) {
FUNC_EXIT_CONST ( constant20 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 119 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 88 ) ) ) {
FUNC_EXIT_CONST ( constant21 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 120 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 89 ) ) ) {
FUNC_EXIT_CONST ( constant22 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 121 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 90 ) ) ) {
FUNC_EXIT_CONST ( constant23 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 122 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 65 ) ) ) {
FUNC_EXIT_CONST ( constant24 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 97 ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 66 ) ) ) {
FUNC_EXIT_CONST ( constant25 , ( * ef1 ) ( lf2 ( make_list ( make_char ( 98 ) ) ) ) ) ;
}
}
if ( not_empty_list ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
( tmp [ 1 ] = list_tail ( atmp000 ) ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
( tmp [ 2 ] = lf_AUX_AsFix2muASFnames10_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef1sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( is_single_element ( tmp [ 4 ] ) ) {
( tmp [ 5 ] = list_head ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = lf_AUX_AsFix2muASFnames10_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 6 ] , ef1sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , lf2sym ) ) {
( tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
FUNC_EXIT ( ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 5 ] ) , make_list ( tmp [ 8 ] ) ) ) ) ) ;
}
}
}
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
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( is_single_element ( atmp000 ) ) {
( tmp [ 0 ] = list_head ( atmp000 ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_AsFix2muASFnames10_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

