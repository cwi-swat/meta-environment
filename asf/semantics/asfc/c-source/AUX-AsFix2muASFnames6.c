#include  "support.h"
static Symbol lf_AUX_AsFix2muASFnames6_1sym ;
static ATerm lf_AUX_AsFix2muASFnames6_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_AsFix2muASFnames6 ( ) {
lf_AUX_AsFix2muASFnames6_1sym = ATmakeSymbol ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"make-caller-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2muASFnames6_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"make-caller-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2muASFnames6_1 , lf_AUX_AsFix2muASFnames6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_AsFix2muASFnames6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuLiterals\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuLiterals\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"literal2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"literal2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"upper2lower\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"upper2lower\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
static ATerm constant5 = NULL ;
static ATerm constant6 = NULL ;
static ATerm constant7 = NULL ;
void init_AUX_AsFix2muASFnames6 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
ATprotect ( & constant5 ) ;
ATprotect ( & constant6 ) ;
ATprotect ( & constant7 ) ;
}
ATerm lf_AUX_AsFix2muASFnames6_1 ( ATerm arg0 ) {
{
ATerm tmp [ 1 ] ;
PROF ( prof_lf_AUX_AsFix2muASFnames6_1 ) ;
tmp [ 0 ] = ( * ef4 ) ( arg0 ) ;
return ( * ef1 ) ( ( * ef1 ) ( ( * ef1 ) ( ( * ef1 ) ( ( * ef1 ) ( ( * ef1 ) ( ( * ef1 ) ( ( * ef1 ) ( ( * ef1 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 30 , char_table [ 34 ] , char_table [ 112 ] , char_table [ 114 ] , char_table [ 111 ] , char_table [ 100 ] , char_table [ 40 ] , char_table [ 105 ] , char_table [ 100 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 99 ] , char_table [ 97 ] , char_table [ 108 ] , char_table [ 108 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) , ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 7 , char_table [ 34 ] , char_table [ 91 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) , ( * ef3 ) ( tmp [ 0 ] ) ) , ( constant1 ? constant1 : ( constant1 = ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 14 , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) ) ) ) , ( constant2 ? constant2 : ( constant2 = ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 20 , char_table [ 34 ] , char_table [ 113 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) ) ) ) , ( constant3 ? constant3 : ( constant3 = ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 48 , char_table [ 34 ] , char_table [ 105 ] , char_table [ 116 ] , char_table [ 101 ] , char_table [ 114 ] , char_table [ 40 ] , char_table [ 115 ] , char_table [ 111 ] , char_table [ 114 ] , char_table [ 116 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 67 ] , char_table [ 72 ] , char_table [ 65 ] , char_table [ 82 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 43 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) ) ) ) , ( constant4 ? constant4 : ( constant4 = ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 21 , char_table [ 34 ] , char_table [ 113 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 93 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) ) ) ) , ( constant5 ? constant5 : ( constant5 = ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 20 , char_table [ 34 ] , char_table [ 108 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 45 ] , char_table [ 62 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 34 ] ) ) ) ) ) ) , ( constant6 ? constant6 : ( constant6 = ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 9 , char_table [ 34 ] , char_table [ 115 ] , char_table [ 111 ] , char_table [ 114 ] , char_table [ 116 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 34 ] ) ) ) ) ) ) , ( * ef3 ) ( arg0 ) ) , ( constant7 ? constant7 : ( constant7 = ( * ef2 ) ( lf2 ( ( ATerm ) ATmakeList ( 23 , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 119 ] , char_table [ 40 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 92 ] , char_table [ 34 ] , char_table [ 41 ] , char_table [ 44 ] , char_table [ 110 ] , char_table [ 111 ] , char_table [ 45 ] , char_table [ 97 ] , char_table [ 116 ] , char_table [ 116 ] , char_table [ 114 ] , char_table [ 115 ] , char_table [ 41 ] , char_table [ 34 ] ) ) ) ) ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
PROF ( prof_lf2 ) ;
return make_nf1 ( lf2sym , arg0 ) ;
}

