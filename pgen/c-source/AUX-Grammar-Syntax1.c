#include  "asc-support.h"
static Symbol lf_AUX_Grammar_Syntax1_1sym ;
static ATerm lf_AUX_Grammar_Syntax1_1 ( ) ;
static Symbol lf_AUX_Grammar_Syntax1_2sym ;
static ATerm lf_AUX_Grammar_Syntax1_2 ( ATerm arg1 ) ;
void register_AUX_Grammar_Syntax1 ( ) {
lf_AUX_Grammar_Syntax1_1sym = ATmakeSymbol ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Grammar_Syntax1_1sym ) ;
lf_AUX_Grammar_Syntax1_2sym = ATmakeSymbol ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Grammar_Syntax1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Grammar_Syntax1_1 , lf_AUX_Grammar_Syntax1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Grammar_Syntax1_2 , lf_AUX_Grammar_Syntax1_2sym ) ;
}
void resolve_AUX_Grammar_Syntax1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_Grammar_Syntax1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Grammar_Syntax1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Grammar_Syntax1_2sym , ATmakeAppl ( lf_AUX_Grammar_Syntax1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Grammar_Syntax1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Grammar_Syntax1_1 ( ) {
CONS_ENTRY ( lf_AUX_Grammar_Syntax1_1sym , ATmakeAppl0 ( lf_AUX_Grammar_Syntax1_1sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Grammar_Syntax1_1sym ) ) ;
}

