#include  "asc-support.h"
static Symbol lf_AUX_Grammar_Normalization1_1sym ;
static ATerm lf_AUX_Grammar_Normalization1_1 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_Grammar_Normalization1 ( ) {
lf_AUX_Grammar_Normalization1_1sym = ATmakeSymbol ( "prod(id(\"Grammar-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar-Grammar\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Grammar_Normalization1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Grammar-Normalization\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Grammar\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar-Grammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Grammar_Normalization1_1 , lf_AUX_Grammar_Normalization1_1sym ) ;
}
void resolve_AUX_Grammar_Normalization1 ( ) {
}
void init_AUX_Grammar_Normalization1 ( ) {
}
ATerm lf_AUX_Grammar_Normalization1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Grammar_Normalization1_1sym , ATmakeAppl ( lf_AUX_Grammar_Normalization1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Grammar_Normalization1_1sym , arg0 , arg1 ) ) ;
}

