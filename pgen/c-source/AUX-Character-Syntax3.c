#include  "support.h"
static Symbol lf_AUX_Character_Syntax3_1sym ;
static ATerm lf_AUX_Character_Syntax3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_Character_Syntax3 ( ) {
lf_AUX_Character_Syntax3_1sym = ATmakeSymbol ( "prod(id(\"Character-Syntax\"),w(\"\"),[sort(\"ShortChar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Syntax3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Syntax\"),w(\"\"),[sort(\"ShortChar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) , lf_AUX_Character_Syntax3_1 , lf_AUX_Character_Syntax3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Character_Syntax3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"shortchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ShortChar\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"shortchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ShortChar\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Syntax\"),w(\"\"),[sort(\"NumChar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Syntax\"),w(\"\"),[sort(\"NumChar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Character\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"numchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NumChar\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"numchar\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NumChar\"),w(\"\"),no-attrs)" ) ) ;
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
static ATerm constant26 = NULL ;
static ATerm constant27 = NULL ;
static ATerm constant28 = NULL ;
static ATerm constant29 = NULL ;
static ATerm constant30 = NULL ;
static ATerm constant31 = NULL ;
static ATerm constant32 = NULL ;
static ATerm constant33 = NULL ;
static ATerm constant34 = NULL ;
static ATerm constant35 = NULL ;
static ATerm constant36 = NULL ;
static ATerm constant37 = NULL ;
static ATerm constant38 = NULL ;
static ATerm constant39 = NULL ;
static ATerm constant40 = NULL ;
static ATerm constant41 = NULL ;
static ATerm constant42 = NULL ;
static ATerm constant43 = NULL ;
static ATerm constant44 = NULL ;
static ATerm constant45 = NULL ;
static ATerm constant46 = NULL ;
static ATerm constant47 = NULL ;
static ATerm constant48 = NULL ;
static ATerm constant49 = NULL ;
static ATerm constant50 = NULL ;
static ATerm constant51 = NULL ;
static ATerm constant52 = NULL ;
static ATerm constant53 = NULL ;
static ATerm constant54 = NULL ;
static ATerm constant55 = NULL ;
static ATerm constant56 = NULL ;
static ATerm constant57 = NULL ;
static ATerm constant58 = NULL ;
static ATerm constant59 = NULL ;
static ATerm constant60 = NULL ;
static ATerm constant61 = NULL ;
static ATerm constant62 = NULL ;
static ATerm constant63 = NULL ;
static ATerm constant64 = NULL ;
static ATerm constant65 = NULL ;
static ATerm constant66 = NULL ;
static ATerm constant67 = NULL ;
static ATerm constant68 = NULL ;
static ATerm constant69 = NULL ;
static ATerm constant70 = NULL ;
static ATerm constant71 = NULL ;
static ATerm constant72 = NULL ;
static ATerm constant73 = NULL ;
static ATerm constant74 = NULL ;
static ATerm constant75 = NULL ;
static ATerm constant76 = NULL ;
static ATerm constant77 = NULL ;
static ATerm constant78 = NULL ;
static ATerm constant79 = NULL ;
static ATerm constant80 = NULL ;
static ATerm constant81 = NULL ;
static ATerm constant82 = NULL ;
static ATerm constant83 = NULL ;
static ATerm constant84 = NULL ;
static ATerm constant85 = NULL ;
static ATerm constant86 = NULL ;
static ATerm constant87 = NULL ;
static ATerm constant88 = NULL ;
static ATerm constant89 = NULL ;
static ATerm constant90 = NULL ;
static ATerm constant91 = NULL ;
static ATerm constant92 = NULL ;
static ATerm constant93 = NULL ;
static ATerm constant94 = NULL ;
static ATerm constant95 = NULL ;
static ATerm constant96 = NULL ;
static ATerm constant97 = NULL ;
void init_AUX_Character_Syntax3 ( ) {
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
ATprotect ( & constant26 ) ;
ATprotect ( & constant27 ) ;
ATprotect ( & constant28 ) ;
ATprotect ( & constant29 ) ;
ATprotect ( & constant30 ) ;
ATprotect ( & constant31 ) ;
ATprotect ( & constant32 ) ;
ATprotect ( & constant33 ) ;
ATprotect ( & constant34 ) ;
ATprotect ( & constant35 ) ;
ATprotect ( & constant36 ) ;
ATprotect ( & constant37 ) ;
ATprotect ( & constant38 ) ;
ATprotect ( & constant39 ) ;
ATprotect ( & constant40 ) ;
ATprotect ( & constant41 ) ;
ATprotect ( & constant42 ) ;
ATprotect ( & constant43 ) ;
ATprotect ( & constant44 ) ;
ATprotect ( & constant45 ) ;
ATprotect ( & constant46 ) ;
ATprotect ( & constant47 ) ;
ATprotect ( & constant48 ) ;
ATprotect ( & constant49 ) ;
ATprotect ( & constant50 ) ;
ATprotect ( & constant51 ) ;
ATprotect ( & constant52 ) ;
ATprotect ( & constant53 ) ;
ATprotect ( & constant54 ) ;
ATprotect ( & constant55 ) ;
ATprotect ( & constant56 ) ;
ATprotect ( & constant57 ) ;
ATprotect ( & constant58 ) ;
ATprotect ( & constant59 ) ;
ATprotect ( & constant60 ) ;
ATprotect ( & constant61 ) ;
ATprotect ( & constant62 ) ;
ATprotect ( & constant63 ) ;
ATprotect ( & constant64 ) ;
ATprotect ( & constant65 ) ;
ATprotect ( & constant66 ) ;
ATprotect ( & constant67 ) ;
ATprotect ( & constant68 ) ;
ATprotect ( & constant69 ) ;
ATprotect ( & constant70 ) ;
ATprotect ( & constant71 ) ;
ATprotect ( & constant72 ) ;
ATprotect ( & constant73 ) ;
ATprotect ( & constant74 ) ;
ATprotect ( & constant75 ) ;
ATprotect ( & constant76 ) ;
ATprotect ( & constant77 ) ;
ATprotect ( & constant78 ) ;
ATprotect ( & constant79 ) ;
ATprotect ( & constant80 ) ;
ATprotect ( & constant81 ) ;
ATprotect ( & constant82 ) ;
ATprotect ( & constant83 ) ;
ATprotect ( & constant84 ) ;
ATprotect ( & constant85 ) ;
ATprotect ( & constant86 ) ;
ATprotect ( & constant87 ) ;
ATprotect ( & constant88 ) ;
ATprotect ( & constant89 ) ;
ATprotect ( & constant90 ) ;
ATprotect ( & constant91 ) ;
ATprotect ( & constant92 ) ;
ATprotect ( & constant93 ) ;
ATprotect ( & constant94 ) ;
ATprotect ( & constant95 ) ;
ATprotect ( & constant96 ) ;
ATprotect ( & constant97 ) ;
}
ATerm lf_AUX_Character_Syntax3_1 ( ATerm arg0 ) {
{
ATerm tmp [ 3 ] ;
FUNC_ENTRY ( lf_AUX_Character_Syntax3_1sym , ATmakeAppl ( lf_AUX_Character_Syntax3_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 92 ) ) ) {
tmp [ 1 ] = list_tail ( atmp000 ) ;
{
if ( is_single_element ( tmp [ 1 ] ) ) {
tmp [ 2 ] = list_head ( tmp [ 1 ] ) ;
if ( term_equal ( tmp [ 2 ] , make_char ( 36 ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 51 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 37 ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 51 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 38 ) ) ) {
FUNC_EXIT_CONST ( constant2 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 51 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 39 ) ) ) {
FUNC_EXIT_CONST ( constant3 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 51 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 40 ) ) ) {
FUNC_EXIT_CONST ( constant4 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 41 ) ) ) {
FUNC_EXIT_CONST ( constant5 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 42 ) ) ) {
FUNC_EXIT_CONST ( constant6 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 43 ) ) ) {
FUNC_EXIT_CONST ( constant7 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 44 ) ) ) {
FUNC_EXIT_CONST ( constant8 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 45 ) ) ) {
FUNC_EXIT_CONST ( constant9 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 46 ) ) ) {
FUNC_EXIT_CONST ( constant10 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 47 ) ) ) {
FUNC_EXIT_CONST ( constant11 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 58 ) ) ) {
FUNC_EXIT_CONST ( constant12 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 59 ) ) ) {
FUNC_EXIT_CONST ( constant13 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 60 ) ) ) {
FUNC_EXIT_CONST ( constant14 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 61 ) ) ) {
FUNC_EXIT_CONST ( constant15 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 62 ) ) ) {
FUNC_EXIT_CONST ( constant16 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 63 ) ) ) {
FUNC_EXIT_CONST ( constant17 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 64 ) ) ) {
FUNC_EXIT_CONST ( constant18 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 91 ) ) ) {
FUNC_EXIT_CONST ( constant19 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 92 ) ) ) {
FUNC_EXIT_CONST ( constant20 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 93 ) ) ) {
FUNC_EXIT_CONST ( constant21 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 94 ) ) ) {
FUNC_EXIT_CONST ( constant22 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 95 ) ) ) {
FUNC_EXIT_CONST ( constant23 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 96 ) ) ) {
FUNC_EXIT_CONST ( constant24 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 123 ) ) ) {
FUNC_EXIT_CONST ( constant25 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 50 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 124 ) ) ) {
FUNC_EXIT_CONST ( constant26 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 50 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 125 ) ) ) {
FUNC_EXIT_CONST ( constant27 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 50 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 126 ) ) ) {
FUNC_EXIT_CONST ( constant28 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 50 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 116 ) ) ) {
FUNC_EXIT_CONST ( constant29 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 92 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 110 ) ) ) {
FUNC_EXIT_CONST ( constant30 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 114 ) ) ) {
FUNC_EXIT_CONST ( constant31 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 32 ) ) ) {
FUNC_EXIT_CONST ( constant32 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 51 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 33 ) ) ) {
FUNC_EXIT_CONST ( constant33 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 51 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 34 ) ) ) {
FUNC_EXIT_CONST ( constant34 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 51 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 35 ) ) ) {
FUNC_EXIT_CONST ( constant35 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 51 ] , char_table [ 53 ] ) ) ) ) ) ;
}
}
}
}
}
{
if ( is_single_element ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 50 ) ) ) {
FUNC_EXIT_CONST ( constant36 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 51 ) ) ) {
FUNC_EXIT_CONST ( constant37 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 52 ) ) ) {
FUNC_EXIT_CONST ( constant38 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 53 ) ) ) {
FUNC_EXIT_CONST ( constant39 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 54 ) ) ) {
FUNC_EXIT_CONST ( constant40 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 55 ) ) ) {
FUNC_EXIT_CONST ( constant41 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 56 ) ) ) {
FUNC_EXIT_CONST ( constant42 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 57 ) ) ) {
FUNC_EXIT_CONST ( constant43 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 53 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 65 ) ) ) {
FUNC_EXIT_CONST ( constant44 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 66 ) ) ) {
FUNC_EXIT_CONST ( constant45 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 67 ) ) ) {
FUNC_EXIT_CONST ( constant46 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 68 ) ) ) {
FUNC_EXIT_CONST ( constant47 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 69 ) ) ) {
FUNC_EXIT_CONST ( constant48 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 54 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 70 ) ) ) {
FUNC_EXIT_CONST ( constant49 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 71 ) ) ) {
FUNC_EXIT_CONST ( constant50 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 72 ) ) ) {
FUNC_EXIT_CONST ( constant51 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 73 ) ) ) {
FUNC_EXIT_CONST ( constant52 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 74 ) ) ) {
FUNC_EXIT_CONST ( constant53 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 75 ) ) ) {
FUNC_EXIT_CONST ( constant54 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 76 ) ) ) {
FUNC_EXIT_CONST ( constant55 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 77 ) ) ) {
FUNC_EXIT_CONST ( constant56 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 78 ) ) ) {
FUNC_EXIT_CONST ( constant57 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 79 ) ) ) {
FUNC_EXIT_CONST ( constant58 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 55 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 80 ) ) ) {
FUNC_EXIT_CONST ( constant59 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 81 ) ) ) {
FUNC_EXIT_CONST ( constant60 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 82 ) ) ) {
FUNC_EXIT_CONST ( constant61 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 83 ) ) ) {
FUNC_EXIT_CONST ( constant62 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 84 ) ) ) {
FUNC_EXIT_CONST ( constant63 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 85 ) ) ) {
FUNC_EXIT_CONST ( constant64 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 86 ) ) ) {
FUNC_EXIT_CONST ( constant65 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 87 ) ) ) {
FUNC_EXIT_CONST ( constant66 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 88 ) ) ) {
FUNC_EXIT_CONST ( constant67 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 89 ) ) ) {
FUNC_EXIT_CONST ( constant68 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 56 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 90 ) ) ) {
FUNC_EXIT_CONST ( constant69 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 97 ) ) ) {
FUNC_EXIT_CONST ( constant70 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 98 ) ) ) {
FUNC_EXIT_CONST ( constant71 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 99 ) ) ) {
FUNC_EXIT_CONST ( constant72 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 57 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 100 ) ) ) {
FUNC_EXIT_CONST ( constant73 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 101 ) ) ) {
FUNC_EXIT_CONST ( constant74 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 102 ) ) ) {
FUNC_EXIT_CONST ( constant75 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 103 ) ) ) {
FUNC_EXIT_CONST ( constant76 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 104 ) ) ) {
FUNC_EXIT_CONST ( constant77 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 105 ) ) ) {
FUNC_EXIT_CONST ( constant78 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 106 ) ) ) {
FUNC_EXIT_CONST ( constant79 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 107 ) ) ) {
FUNC_EXIT_CONST ( constant80 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 108 ) ) ) {
FUNC_EXIT_CONST ( constant81 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 109 ) ) ) {
FUNC_EXIT_CONST ( constant82 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 48 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 110 ) ) ) {
FUNC_EXIT_CONST ( constant83 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 111 ) ) ) {
FUNC_EXIT_CONST ( constant84 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 112 ) ) ) {
FUNC_EXIT_CONST ( constant85 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 113 ) ) ) {
FUNC_EXIT_CONST ( constant86 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 51 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 114 ) ) ) {
FUNC_EXIT_CONST ( constant87 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 52 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 115 ) ) ) {
FUNC_EXIT_CONST ( constant88 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 53 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 116 ) ) ) {
FUNC_EXIT_CONST ( constant89 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 54 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 117 ) ) ) {
FUNC_EXIT_CONST ( constant90 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 55 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 118 ) ) ) {
FUNC_EXIT_CONST ( constant91 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 119 ) ) ) {
FUNC_EXIT_CONST ( constant92 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 49 ] , char_table [ 57 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 120 ) ) ) {
FUNC_EXIT_CONST ( constant93 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 50 ] , char_table [ 48 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 121 ) ) ) {
FUNC_EXIT_CONST ( constant94 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 50 ] , char_table [ 49 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 122 ) ) ) {
FUNC_EXIT_CONST ( constant95 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 4 , char_table [ 92 ] , char_table [ 49 ] , char_table [ 50 ] , char_table [ 50 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 48 ) ) ) {
FUNC_EXIT_CONST ( constant96 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 56 ] ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 0 ] , make_char ( 49 ) ) ) {
FUNC_EXIT_CONST ( constant97 , ( * ef2 ) ( ( * ef3 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 92 ] , char_table [ 52 ] , char_table [ 57 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Character_Syntax3_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

