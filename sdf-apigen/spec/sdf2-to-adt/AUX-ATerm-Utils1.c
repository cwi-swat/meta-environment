/* This C code is generated by the AsfSdfCompiler version 1.3 */

#include  "asc-support.h"
static Symbol lf_AUX_ATerm_Utils1_1sym ;
static ATerm lf_AUX_ATerm_Utils1_1 ( ) ;
static Symbol lf_AUX_ATerm_Utils1_2sym ;
static ATerm lf_AUX_ATerm_Utils1_2 ( ) ;
static Symbol lf_AUX_ATerm_Utils1_3sym ;
static ATerm lf_AUX_ATerm_Utils1_3 ( ) ;
static Symbol lf_AUX_ATerm_Utils1_4sym ;
static ATerm lf_AUX_ATerm_Utils1_4 ( ) ;
void register_AUX_ATerm_Utils1 ( ) {
lf_AUX_ATerm_Utils1_1sym = ATmakeSymbol ( "prod(id(\"ATerm-Utils\"),w(\"\"),[ql(\"#int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermType\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Utils1_1sym ) ;
lf_AUX_ATerm_Utils1_2sym = ATmakeSymbol ( "prod(id(\"ATerm-Utils\"),w(\"\"),[ql(\"#list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermType\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Utils1_2sym ) ;
lf_AUX_ATerm_Utils1_3sym = ATmakeSymbol ( "prod(id(\"ATerm-Utils\"),w(\"\"),[ql(\"#appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermType\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Utils1_3sym ) ;
lf_AUX_ATerm_Utils1_4sym = ATmakeSymbol ( "prod(id(\"ATerm-Utils\"),w(\"\"),[ql(\"#placeholder\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermType\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Utils1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Utils\"),w(\"\"),[ql(\"#int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermType\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Utils1_1 , lf_AUX_ATerm_Utils1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Utils\"),w(\"\"),[ql(\"#list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermType\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Utils1_2 , lf_AUX_ATerm_Utils1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Utils\"),w(\"\"),[ql(\"#appl\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermType\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Utils1_3 , lf_AUX_ATerm_Utils1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Utils\"),w(\"\"),[ql(\"#placeholder\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermType\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Utils1_4 , lf_AUX_ATerm_Utils1_4sym ) ;
}
void resolve_AUX_ATerm_Utils1 ( ) {
}
void init_AUX_ATerm_Utils1 ( ) {
}
ATerm lf_AUX_ATerm_Utils1_4 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Utils1_4sym , ATmakeAppl0 ( lf_AUX_ATerm_Utils1_4sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Utils1_4sym ) ) ;
}
ATerm lf_AUX_ATerm_Utils1_3 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Utils1_3sym , ATmakeAppl0 ( lf_AUX_ATerm_Utils1_3sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Utils1_3sym ) ) ;
}
ATerm lf_AUX_ATerm_Utils1_2 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Utils1_2sym , ATmakeAppl0 ( lf_AUX_ATerm_Utils1_2sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Utils1_2sym ) ) ;
}
ATerm lf_AUX_ATerm_Utils1_1 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Utils1_1sym , ATmakeAppl0 ( lf_AUX_ATerm_Utils1_1sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Utils1_1sym ) ) ;
}

