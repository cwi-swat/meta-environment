#include  "asc-support.h"
static Symbol lf_AUX_ATerm_Tables1_1sym ;
static ATerm lf_AUX_ATerm_Tables1_1 ( ) ;
static Symbol lf_AUX_ATerm_Tables1_2sym ;
static ATerm lf_AUX_ATerm_Tables1_2 ( ) ;
static Symbol lf_AUX_ATerm_Tables1_3sym ;
static ATerm lf_AUX_ATerm_Tables1_3 ( ) ;
static Symbol lf_AUX_ATerm_Tables1_4sym ;
static ATerm lf_AUX_ATerm_Tables1_4 ( ) ;
static Symbol lf_AUX_ATerm_Tables1_5sym ;
static ATerm lf_AUX_ATerm_Tables1_5 ( ) ;
void register_AUX_ATerm_Tables1 ( ) {
lf_AUX_ATerm_Tables1_1sym = ATmakeSymbol ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"getf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Tables1_1sym ) ;
lf_AUX_ATerm_Tables1_2sym = ATmakeSymbol ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"egetf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Tables1_2sym ) ;
lf_AUX_ATerm_Tables1_3sym = ATmakeSymbol ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"putf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Tables1_3sym ) ;
lf_AUX_ATerm_Tables1_4sym = ATmakeSymbol ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"cputf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Tables1_4sym ) ;
lf_AUX_ATerm_Tables1_5sym = ATmakeSymbol ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"deff\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Tables1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"getf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Tables1_1 , lf_AUX_ATerm_Tables1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"egetf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Tables1_2 , lf_AUX_ATerm_Tables1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"putf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Tables1_3 , lf_AUX_ATerm_Tables1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"cputf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Tables1_4 , lf_AUX_ATerm_Tables1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"deff\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Tables1_5 , lf_AUX_ATerm_Tables1_5sym ) ;
}
void resolve_AUX_ATerm_Tables1 ( ) {
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
static ATerm constant3 = NULL ;
static ATerm constant4 = NULL ;
void init_AUX_ATerm_Tables1 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
ATprotect ( & constant3 ) ;
ATprotect ( & constant4 ) ;
}
ATerm lf_AUX_ATerm_Tables1_5 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Tables1_5sym , ATmakeAppl0 ( lf_AUX_ATerm_Tables1_5sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_ATerm_Tables1_5sym ) ) ;
}
ATerm lf_AUX_ATerm_Tables1_4 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Tables1_4sym , ATmakeAppl0 ( lf_AUX_ATerm_Tables1_4sym ) ) ;
CONS_EXIT_CONST ( constant1 , make_nf0 ( lf_AUX_ATerm_Tables1_4sym ) ) ;
}
ATerm lf_AUX_ATerm_Tables1_3 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Tables1_3sym , ATmakeAppl0 ( lf_AUX_ATerm_Tables1_3sym ) ) ;
CONS_EXIT_CONST ( constant2 , make_nf0 ( lf_AUX_ATerm_Tables1_3sym ) ) ;
}
ATerm lf_AUX_ATerm_Tables1_2 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Tables1_2sym , ATmakeAppl0 ( lf_AUX_ATerm_Tables1_2sym ) ) ;
CONS_EXIT_CONST ( constant3 , make_nf0 ( lf_AUX_ATerm_Tables1_2sym ) ) ;
}
ATerm lf_AUX_ATerm_Tables1_1 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Tables1_1sym , ATmakeAppl0 ( lf_AUX_ATerm_Tables1_1sym ) ) ;
CONS_EXIT_CONST ( constant4 , make_nf0 ( lf_AUX_ATerm_Tables1_1sym ) ) ;
}

