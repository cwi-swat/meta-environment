#include  "asc-support.h"
static Symbol lf_AUX_AsFix2muASF_C9_1sym ;
static ATerm lf_AUX_AsFix2muASF_C9_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef19sym ;
static funcptr ef19 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef20sym ;
static funcptr ef20 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol lf5sym ;
static ATerm lf5 ( ATerm arg1 ) ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf4sym ;
static ATerm lf4 ( ATerm arg1 ) ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol lf6sym ;
static ATerm lf6 ( ATerm arg1 ) ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef18sym ;
static funcptr ef18 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_AsFix2muASF_C9 ( ) {
lf_AUX_AsFix2muASF_C9_1sym = ATmakeSymbol ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"cond2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2muASF_C9_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf5sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf5sym ) ;
lf4sym = ATmakeSymbol ( "listtype(sort(\"AFun\"),ql(\".\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf4sym ) ;
lf6sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf6sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"cond2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2muASF_C9_1 , lf_AUX_AsFix2muASF_C9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf3 , lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"AFun\"),ql(\".\"))" ) , lf4 , lf4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf5 , lf5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf6 , lf6sym ) ;
}
void resolve_AUX_AsFix2muASF_C9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncCondTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"cop\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"cop\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"aterm2muasf\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef18 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef18sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef19 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef19sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef20 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
ef20sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"!=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
void init_AUX_AsFix2muASF_C9 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
}
ATerm lf_AUX_AsFix2muASF_C9_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 22 ] ;
FUNC_ENTRY ( lf_AUX_AsFix2muASF_C9_1sym , ATmakeAppl ( lf_AUX_AsFix2muASF_C9_1sym , arg0 , arg1 ) ) ;
tmp [ 0 ] = ( * ef3 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = lf4 ( make_list ( ( * ef4 ) ( ) ) ) ) ) ) ;
if ( term_equal ( tmp [ 0 ] , ( constant1 ? constant1 : ( constant1 = ( * ef5 ) ( ( * ef6 ) ( ) , ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf5 ( ( ATerm ) ATmakeList ( 4 , char_table [ 34 ] , char_table [ 61 ] , char_table [ 58 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 1 ] = ( * ef3 ) ( arg0 , ( constant2 ? constant2 : ( constant2 = lf4 ( make_list ( ( * ef11 ) ( ) ) ) ) ) ) ;
tmp [ 2 ] = ( * ef12 ) ( ( * ef13 ) ( tmp [ 1 ] ) , tmp [ 1 ] , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef14sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef15sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf6sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( is_single_element ( tmp [ 8 ] ) ) {
tmp [ 9 ] = list_head ( tmp [ 8 ] ) ;
tmp [ 10 ] = ( * ef3 ) ( arg0 , ( constant3 ? constant3 : ( constant3 = lf4 ( make_list ( ( * ef16 ) ( ) ) ) ) ) ) ;
tmp [ 11 ] = ( * ef12 ) ( ( * ef13 ) ( tmp [ 10 ] ) , tmp [ 10 ] , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 11 ] , ef14sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 11 ] ) ;
tmp [ 14 ] = arg_2 ( tmp [ 11 ] ) ;
if ( check_sym ( tmp [ 12 ] , lf2sym ) ) {
tmp [ 15 ] = arg_0 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 13 ] , ef15sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 13 ] ) ;
if ( check_sym ( tmp [ 16 ] , lf6sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ;
if ( is_single_element ( tmp [ 17 ] ) ) {
tmp [ 18 ] = list_head ( tmp [ 17 ] ) ;
tmp [ 19 ] = ( * ef17 ) ( ( * ef18 ) ( lf2 ( make_list ( tmp [ 6 ] ) ) ) , ( * ef18 ) ( lf2 ( make_list ( tmp [ 15 ] ) ) ) ) ;
if ( check_sym ( tmp [ 19 ] , ef18sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf2sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 21 ] ) ) , lf3 ( make_list ( ( * ef2 ) ( tmp [ 9 ] , tmp [ 18 ] ) ) ) , tmp [ 14 ] ) ) ;
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
if ( term_equal ( tmp [ 0 ] , ( constant4 ? constant4 : ( constant4 = ( * ef5 ) ( ( * ef6 ) ( ) , ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf5 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 61 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 1 ] = ( * ef3 ) ( arg0 , ( constant2 ? constant2 : ( constant2 = lf4 ( make_list ( ( * ef11 ) ( ) ) ) ) ) ) ;
tmp [ 2 ] = ( * ef12 ) ( ( * ef13 ) ( tmp [ 1 ] ) , tmp [ 1 ] , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef14sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef15sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf6sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( is_single_element ( tmp [ 8 ] ) ) {
tmp [ 9 ] = list_head ( tmp [ 8 ] ) ;
tmp [ 10 ] = ( * ef3 ) ( arg0 , ( constant3 ? constant3 : ( constant3 = lf4 ( make_list ( ( * ef16 ) ( ) ) ) ) ) ) ;
tmp [ 11 ] = ( * ef12 ) ( ( * ef13 ) ( tmp [ 10 ] ) , tmp [ 10 ] , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 11 ] , ef14sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 11 ] ) ;
tmp [ 14 ] = arg_2 ( tmp [ 11 ] ) ;
if ( check_sym ( tmp [ 12 ] , lf2sym ) ) {
tmp [ 15 ] = arg_0 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 13 ] , ef15sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 13 ] ) ;
if ( check_sym ( tmp [ 16 ] , lf6sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ;
if ( is_single_element ( tmp [ 17 ] ) ) {
tmp [ 18 ] = list_head ( tmp [ 17 ] ) ;
tmp [ 19 ] = ( * ef17 ) ( ( * ef18 ) ( lf2 ( make_list ( tmp [ 6 ] ) ) ) , ( * ef18 ) ( lf2 ( make_list ( tmp [ 15 ] ) ) ) ) ;
if ( check_sym ( tmp [ 19 ] , ef18sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf2sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 21 ] ) ) , lf3 ( make_list ( ( * ef19 ) ( tmp [ 9 ] , tmp [ 18 ] ) ) ) , tmp [ 14 ] ) ) ;
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
if ( term_equal ( tmp [ 0 ] , ( constant5 ? constant5 : ( constant5 = ( * ef5 ) ( ( * ef6 ) ( ) , ( * ef7 ) ( ( * ef8 ) ( ( * ef9 ) ( ( * ef10 ) ( lf5 ( ( ATerm ) ATmakeList ( 4 , char_table [ 34 ] , char_table [ 33 ] , char_table [ 61 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 1 ] = ( * ef3 ) ( arg0 , ( constant2 ? constant2 : ( constant2 = lf4 ( make_list ( ( * ef11 ) ( ) ) ) ) ) ) ;
tmp [ 2 ] = ( * ef12 ) ( ( * ef13 ) ( tmp [ 1 ] ) , tmp [ 1 ] , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef14sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef15sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf6sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
if ( is_single_element ( tmp [ 8 ] ) ) {
tmp [ 9 ] = list_head ( tmp [ 8 ] ) ;
tmp [ 10 ] = ( * ef3 ) ( arg0 , ( constant3 ? constant3 : ( constant3 = lf4 ( make_list ( ( * ef16 ) ( ) ) ) ) ) ) ;
tmp [ 11 ] = ( * ef12 ) ( ( * ef13 ) ( tmp [ 10 ] ) , tmp [ 10 ] , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 11 ] , ef14sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
tmp [ 13 ] = arg_1 ( tmp [ 11 ] ) ;
tmp [ 14 ] = arg_2 ( tmp [ 11 ] ) ;
if ( check_sym ( tmp [ 12 ] , lf2sym ) ) {
tmp [ 15 ] = arg_0 ( tmp [ 12 ] ) ;
if ( check_sym ( tmp [ 13 ] , ef15sym ) ) {
tmp [ 16 ] = arg_0 ( tmp [ 13 ] ) ;
if ( check_sym ( tmp [ 16 ] , lf6sym ) ) {
tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ;
if ( is_single_element ( tmp [ 17 ] ) ) {
tmp [ 18 ] = list_head ( tmp [ 17 ] ) ;
tmp [ 19 ] = ( * ef17 ) ( ( * ef18 ) ( lf2 ( make_list ( tmp [ 6 ] ) ) ) , ( * ef18 ) ( lf2 ( make_list ( tmp [ 15 ] ) ) ) ) ;
if ( check_sym ( tmp [ 19 ] , ef18sym ) ) {
tmp [ 20 ] = arg_0 ( tmp [ 19 ] ) ;
if ( check_sym ( tmp [ 20 ] , lf2sym ) ) {
tmp [ 21 ] = arg_0 ( tmp [ 20 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 21 ] ) ) , lf3 ( make_list ( ( * ef20 ) ( tmp [ 9 ] , tmp [ 18 ] ) ) ) , tmp [ 14 ] ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_AsFix2muASF_C9_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf6 ( ATerm arg0 ) {
CONS_ENTRY ( lf6sym , ATmakeAppl ( lf6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf6sym , arg0 ) ) ;
}
ATerm lf4 ( ATerm arg0 ) {
CONS_ENTRY ( lf4sym , ATmakeAppl ( lf4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf4sym , arg0 ) ) ;
}
ATerm lf5 ( ATerm arg0 ) {
CONS_ENTRY ( lf5sym , ATmakeAppl ( lf5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf5sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

