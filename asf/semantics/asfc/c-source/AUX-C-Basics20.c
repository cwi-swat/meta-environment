#include  "support.h"
static Symbol lf_AUX_C_Basics20_1sym ;
static ATerm lf_AUX_C_Basics20_1 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef1sym ;
static funcptr ef1 ;
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
void register_AUX_C_Basics20 ( ) {
lf_AUX_C_Basics20_1sym = ATmakeSymbol ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"translate-char\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C_Basics20_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"translate-char\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) , lf_AUX_C_Basics20_1 , lf_AUX_C_Basics20_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_C_Basics20 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Cast-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cast-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Integer-constant\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"integer-constant\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Integer-constant\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"space\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"C-Basics\"),w(\"\"),[l(\"space\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
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
static ATerm constant98 = NULL ;
static ATerm constant99 = NULL ;
static ATerm constant100 = NULL ;
void init_AUX_C_Basics20 ( ) {
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
ATprotect ( & constant98 ) ;
ATprotect ( & constant99 ) ;
ATprotect ( & constant100 ) ;
}
ATerm lf_AUX_C_Basics20_1 ( ATerm arg0 ) {
{
ATerm tmp [ 4 ] ;
PROF ( prof_lf_AUX_C_Basics20_1 ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( term_equal ( tmp [ 0 ] , make_char ( 39 ) ) ) {
tmp [ 1 ] = list_tail ( atmp000 ) ;
{
if ( is_single_element ( tmp [ 1 ] ) ) {
tmp [ 2 ] = list_head ( tmp [ 1 ] ) ;
if ( term_equal ( tmp [ 2 ] , make_char ( 37 ) ) ) {
return ( constant0 ? constant0 : ( constant0 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 51 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 38 ) ) ) {
return ( constant1 ? constant1 : ( constant1 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 51 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 39 ) ) ) {
return ( constant2 ? constant2 : ( constant2 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 51 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 40 ) ) ) {
return ( constant3 ? constant3 : ( constant3 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 41 ) ) ) {
return ( constant4 ? constant4 : ( constant4 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 42 ) ) ) {
return ( constant5 ? constant5 : ( constant5 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 43 ) ) ) {
return ( constant6 ? constant6 : ( constant6 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 44 ) ) ) {
return ( constant7 ? constant7 : ( constant7 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 45 ) ) ) {
return ( constant8 ? constant8 : ( constant8 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 46 ) ) ) {
return ( constant9 ? constant9 : ( constant9 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 47 ) ) ) {
return ( constant10 ? constant10 : ( constant10 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 48 ) ) ) {
return ( constant11 ? constant11 : ( constant11 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 49 ) ) ) {
return ( constant12 ? constant12 : ( constant12 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 52 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 50 ) ) ) {
return ( constant13 ? constant13 : ( constant13 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 51 ) ) ) {
return ( constant14 ? constant14 : ( constant14 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 52 ) ) ) {
return ( constant15 ? constant15 : ( constant15 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 53 ) ) ) {
return ( constant16 ? constant16 : ( constant16 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 54 ) ) ) {
return ( constant17 ? constant17 : ( constant17 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 55 ) ) ) {
return ( constant18 ? constant18 : ( constant18 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 56 ) ) ) {
return ( constant19 ? constant19 : ( constant19 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 57 ) ) ) {
return ( constant20 ? constant20 : ( constant20 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 58 ) ) ) {
return ( constant21 ? constant21 : ( constant21 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 59 ) ) ) {
return ( constant22 ? constant22 : ( constant22 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 53 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 60 ) ) ) {
return ( constant23 ? constant23 : ( constant23 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 61 ) ) ) {
return ( constant24 ? constant24 : ( constant24 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 62 ) ) ) {
return ( constant25 ? constant25 : ( constant25 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 63 ) ) ) {
return ( constant26 ? constant26 : ( constant26 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 64 ) ) ) {
return ( constant27 ? constant27 : ( constant27 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 65 ) ) ) {
return ( constant28 ? constant28 : ( constant28 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 66 ) ) ) {
return ( constant29 ? constant29 : ( constant29 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 67 ) ) ) {
return ( constant30 ? constant30 : ( constant30 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 68 ) ) ) {
return ( constant31 ? constant31 : ( constant31 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 69 ) ) ) {
return ( constant32 ? constant32 : ( constant32 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 54 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 70 ) ) ) {
return ( constant33 ? constant33 : ( constant33 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 71 ) ) ) {
return ( constant34 ? constant34 : ( constant34 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 72 ) ) ) {
return ( constant35 ? constant35 : ( constant35 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 73 ) ) ) {
return ( constant36 ? constant36 : ( constant36 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 74 ) ) ) {
return ( constant37 ? constant37 : ( constant37 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 75 ) ) ) {
return ( constant38 ? constant38 : ( constant38 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 76 ) ) ) {
return ( constant39 ? constant39 : ( constant39 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 77 ) ) ) {
return ( constant40 ? constant40 : ( constant40 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 78 ) ) ) {
return ( constant41 ? constant41 : ( constant41 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 79 ) ) ) {
return ( constant42 ? constant42 : ( constant42 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 55 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 80 ) ) ) {
return ( constant43 ? constant43 : ( constant43 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 81 ) ) ) {
return ( constant44 ? constant44 : ( constant44 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 82 ) ) ) {
return ( constant45 ? constant45 : ( constant45 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 83 ) ) ) {
return ( constant46 ? constant46 : ( constant46 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 84 ) ) ) {
return ( constant47 ? constant47 : ( constant47 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 85 ) ) ) {
return ( constant48 ? constant48 : ( constant48 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 86 ) ) ) {
return ( constant49 ? constant49 : ( constant49 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 87 ) ) ) {
return ( constant50 ? constant50 : ( constant50 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 88 ) ) ) {
return ( constant51 ? constant51 : ( constant51 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 89 ) ) ) {
return ( constant52 ? constant52 : ( constant52 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 56 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 90 ) ) ) {
return ( constant53 ? constant53 : ( constant53 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 91 ) ) ) {
return ( constant54 ? constant54 : ( constant54 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 93 ) ) ) {
return ( constant55 ? constant55 : ( constant55 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 94 ) ) ) {
return ( constant56 ? constant56 : ( constant56 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 95 ) ) ) {
return ( constant57 ? constant57 : ( constant57 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 96 ) ) ) {
return ( constant58 ? constant58 : ( constant58 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 97 ) ) ) {
return ( constant59 ? constant59 : ( constant59 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 98 ) ) ) {
return ( constant60 ? constant60 : ( constant60 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 99 ) ) ) {
return ( constant61 ? constant61 : ( constant61 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 100 ) ) ) {
return ( constant62 ? constant62 : ( constant62 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 101 ) ) ) {
return ( constant63 ? constant63 : ( constant63 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 102 ) ) ) {
return ( constant64 ? constant64 : ( constant64 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 103 ) ) ) {
return ( constant65 ? constant65 : ( constant65 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 104 ) ) ) {
return ( constant66 ? constant66 : ( constant66 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 105 ) ) ) {
return ( constant67 ? constant67 : ( constant67 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 106 ) ) ) {
return ( constant68 ? constant68 : ( constant68 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 107 ) ) ) {
return ( constant69 ? constant69 : ( constant69 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 108 ) ) ) {
return ( constant70 ? constant70 : ( constant70 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 109 ) ) ) {
return ( constant71 ? constant71 : ( constant71 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 48 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 110 ) ) ) {
return ( constant72 ? constant72 : ( constant72 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 111 ) ) ) {
return ( constant73 ? constant73 : ( constant73 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 112 ) ) ) {
return ( constant74 ? constant74 : ( constant74 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 113 ) ) ) {
return ( constant75 ? constant75 : ( constant75 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 114 ) ) ) {
return ( constant76 ? constant76 : ( constant76 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 115 ) ) ) {
return ( constant77 ? constant77 : ( constant77 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 116 ) ) ) {
return ( constant78 ? constant78 : ( constant78 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 117 ) ) ) {
return ( constant79 ? constant79 : ( constant79 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 118 ) ) ) {
return ( constant80 ? constant80 : ( constant80 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 56 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 119 ) ) ) {
return ( constant81 ? constant81 : ( constant81 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 49 ] , char_table [ 57 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 120 ) ) ) {
return ( constant82 ? constant82 : ( constant82 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 50 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 121 ) ) ) {
return ( constant83 ? constant83 : ( constant83 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 50 ] , char_table [ 49 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 122 ) ) ) {
return ( constant84 ? constant84 : ( constant84 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 50 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 123 ) ) ) {
return ( constant85 ? constant85 : ( constant85 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 50 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 124 ) ) ) {
return ( constant86 ? constant86 : ( constant86 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 50 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 125 ) ) ) {
return ( constant87 ? constant87 : ( constant87 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 50 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 126 ) ) ) {
return ( constant88 ? constant88 : ( constant88 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 49 ] , char_table [ 50 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 33 ) ) ) {
return ( constant89 ? constant89 : ( constant89 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 51 ] , char_table [ 51 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 34 ) ) ) {
return ( constant90 ? constant90 : ( constant90 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 51 ] , char_table [ 52 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 35 ) ) ) {
return ( constant91 ? constant91 : ( constant91 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 51 ] , char_table [ 53 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 2 ] , make_char ( 36 ) ) ) {
return ( constant92 ? constant92 : ( constant92 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 51 ] , char_table [ 54 ] ) ) ) ) ) ) ) ) ;
}
tmp [ 3 ] = list_head ( tmp [ 1 ] ) ;
if ( term_equal ( ( * ef1 ) ( lf2 ( cons ( ( constant93 ? constant93 : ( constant93 = make_list_char ( 34 ) ) ) , cons ( make_list ( tmp [ 3 ] ) , ( constant94 ? constant94 : ( constant94 = make_list ( make_char ( 34 ) ) ) ) ) ) ) ) , ( constant95 ? constant95 : ( constant95 = ( * ef6 ) ( ) ) ) ) ) {
return ( constant96 ? constant96 : ( constant96 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 51 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
}
}
}
tmp [ 1 ] = make_char ( 92 ) ;
if ( term_equal ( tmp [ 0 ] , tmp [ 1 ] ) ) {
tmp [ 2 ] = list_tail ( atmp000 ) ;
{
if ( is_single_element ( tmp [ 2 ] ) ) {
tmp [ 3 ] = list_head ( tmp [ 2 ] ) ;
if ( term_equal ( tmp [ 3 ] , make_char ( 110 ) ) ) {
return ( constant97 ? constant97 : ( constant97 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 49 ] , char_table [ 48 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 92 ) ) ) {
return ( constant98 ? constant98 : ( constant98 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 2 , char_table [ 57 ] , char_table [ 50 ] ) ) ) ) ) ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , make_char ( 116 ) ) ) {
return ( constant99 ? constant99 : ( constant99 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( make_list ( make_char ( 57 ) ) ) ) ) ) ) ) ) ;
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
if ( not_empty_list ( atmp000 ) ) {
if ( term_equal ( list_head ( atmp000 ) , make_char ( 39 ) ) ) {
tmp [ 0 ] = list_tail ( atmp000 ) ;
if ( is_single_element ( tmp [ 0 ] ) ) {
tmp [ 1 ] = list_head ( tmp [ 0 ] ) ;
return ( constant100 ? constant100 : ( constant100 = ( * ef2 ) ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( lf2 ( ( ATerm ) ATmakeList ( 3 , char_table [ 55 ] , char_table [ 55 ] , char_table [ 55 ] ) ) ) ) ) ) ) ) ;
}
}
}
}
}
}
}
return make_nf1 ( lf_AUX_C_Basics20_1sym , arg0 ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}

