#include  "asc-support.h"
static Symbol lf_AUX_Improve_C_code1_1sym ;
static ATerm lf_AUX_Improve_C_code1_1 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_Improve_C_code1 ( ) {
lf_AUX_Improve_C_code1_1sym = ATmakeSymbol ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SB-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Improve_C_code1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Improve-C-code\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SB-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Improve_C_code1_1 , lf_AUX_Improve_C_code1_1sym ) ;
}
void resolve_AUX_Improve_C_code1 ( ) {
}
void init_AUX_Improve_C_code1 ( ) {
}
ATerm lf_AUX_Improve_C_code1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Improve_C_code1_1sym , ATmakeAppl ( lf_AUX_Improve_C_code1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Improve_C_code1_1sym , arg0 , arg1 ) ) ;
}

