#include  "support.h"
static Symbol lf_AUX_AsFix2muASFnames8_1sym ;
static ATerm lf_AUX_AsFix2muASFnames8_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef17sym ;
static funcptr ef17 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef14sym ;
static funcptr ef14 ;
static Symbol ef15sym ;
static funcptr ef15 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef16sym ;
static funcptr ef16 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef7sym ;
static funcptr ef7 ;
void register_AUX_AsFix2muASFnames8 ( ) {
lf_AUX_AsFix2muASFnames8_1sym = ATmakeSymbol ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"avar2muvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2muASFnames8_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"AFun\"),ql(\".\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"avar2muvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2muASFnames8_1 , lf_AUX_AsFix2muASFnames8_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"AFun\"),ql(\".\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_AsFix2muASFnames8 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"sym\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"sort\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"svar2muvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"svar2muvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarId\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Constructors\"),w(\"\"),[ql(\"name\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter-sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"iter\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"ParseTree-Constructors\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef14 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef14sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef15 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef15sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) ) ;
ef16 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef16sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef17 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
ef17sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
static ATerm constant6 = NULL ;
static ATerm constant7 = NULL ;
void init_AUX_AsFix2muASFnames8 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
ATprotect ( & constant6 ) ;
ATprotect ( & constant7 ) ;
}
ATerm lf_AUX_AsFix2muASFnames8_1 ( ATerm arg0 ) {
{
ATerm tmp [ 5 ] ;
PROF ( prof_lf_AUX_AsFix2muASFnames8_1 ) ;
tmp [ 0 ] = ( * ef2 ) ( arg0 , ( constant0 ? constant0 : ( constant0 = lf2 ( make_list ( ( * ef3 ) ( ) ) ) ) ) ) ;
tmp [ 1 ] = ( * ef4 ) ( tmp [ 0 ] ) ;
if ( term_equal ( tmp [ 1 ] , ( constant1 ? constant1 : ( constant1 = ( * ef9 ) ( ) ) ) ) ) {
tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] , ( constant2 ? constant2 : ( constant2 = lf2 ( make_list ( ( * ef10 ) ( ) ) ) ) ) ) ;
if ( term_equal ( tmp [ 2 ] , ( constant3 ? constant3 : ( constant3 = ( * ef11 ) ( ( * ef12 ) ( ) , ( * ef13 ) ( ( * ef14 ) ( ( * ef15 ) ( ( * ef16 ) ( lf3 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 43 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 3 ] = ( * ef6 ) ( ( * ef2 ) ( arg0 , ( constant4 ? constant4 : ( constant4 = lf2 ( make_list ( ( * ef7 ) ( ) ) ) ) ) ) ) ;
return ( * ef8 ) ( tmp [ 3 ] ) ;
}
if ( term_equal ( tmp [ 2 ] , ( constant5 ? constant5 : ( constant5 = ( * ef11 ) ( ( * ef12 ) ( ) , ( * ef13 ) ( ( * ef14 ) ( ( * ef15 ) ( ( * ef16 ) ( lf3 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 42 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 3 ] = ( * ef6 ) ( ( * ef2 ) ( arg0 , ( constant4 ? constant4 : ( constant4 = lf2 ( make_list ( ( * ef7 ) ( ) ) ) ) ) ) ) ;
return ( * ef17 ) ( tmp [ 3 ] ) ;
}
}
tmp [ 2 ] = ( constant6 ? constant6 : ( constant6 = ( * ef10 ) ( ) ) ) ;
if ( term_equal ( tmp [ 1 ] , tmp [ 2 ] ) ) {
tmp [ 3 ] = ( * ef2 ) ( tmp [ 0 ] , ( constant2 ? constant2 : ( constant2 = lf2 ( make_list ( ( * ef10 ) ( ) ) ) ) ) ) ;
if ( term_equal ( tmp [ 3 ] , ( constant5 ? constant5 : ( constant5 = ( * ef11 ) ( ( * ef12 ) ( ) , ( * ef13 ) ( ( * ef14 ) ( ( * ef15 ) ( ( * ef16 ) ( lf3 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 42 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 4 ] = ( * ef6 ) ( ( * ef2 ) ( arg0 , ( constant4 ? constant4 : ( constant4 = lf2 ( make_list ( ( * ef7 ) ( ) ) ) ) ) ) ) ;
return ( * ef17 ) ( tmp [ 4 ] ) ;
}
if ( term_equal ( tmp [ 3 ] , ( constant3 ? constant3 : ( constant3 = ( * ef11 ) ( ( * ef12 ) ( ) , ( * ef13 ) ( ( * ef14 ) ( ( * ef15 ) ( ( * ef16 ) ( lf3 ( ( ATerm ) ATmakeList ( 3 , char_table [ 34 ] , char_table [ 43 ] , char_table [ 34 ] ) ) ) ) ) ) ) ) ) ) ) {
tmp [ 4 ] = ( * ef6 ) ( ( * ef2 ) ( arg0 , ( constant4 ? constant4 : ( constant4 = lf2 ( make_list ( ( * ef7 ) ( ) ) ) ) ) ) ) ;
return ( * ef8 ) ( tmp [ 4 ] ) ;
}
}
if ( term_equal ( tmp [ 1 ] , ( constant7 ? constant7 : ( constant7 = ( * ef5 ) ( ) ) ) ) ) {
tmp [ 3 ] = ( * ef6 ) ( ( * ef2 ) ( arg0 , ( constant4 ? constant4 : ( constant4 = lf2 ( make_list ( ( * ef7 ) ( ) ) ) ) ) ) ) ;
return ( * ef1 ) ( tmp [ 3 ] ) ;
}
return make_nf1 ( lf_AUX_AsFix2muASFnames8_1sym , arg0 ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}

