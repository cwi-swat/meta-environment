#include  "asc-support.h"
static Symbol lf_AUX_Kernel_Sdf_Syntax1_1sym ;
static ATerm lf_AUX_Kernel_Sdf_Syntax1_1 ( ) ;
static Symbol lf_AUX_Kernel_Sdf_Syntax1_2sym ;
static ATerm lf_AUX_Kernel_Sdf_Syntax1_2 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Kernel_Sdf_Syntax1_4sym ;
static ATerm lf_AUX_Kernel_Sdf_Syntax1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_Kernel_Sdf_Syntax1_3sym ;
static ATerm lf_AUX_Kernel_Sdf_Syntax1_3 ( ATerm arg1 ) ;
void register_AUX_Kernel_Sdf_Syntax1 ( ) {
lf_AUX_Kernel_Sdf_Syntax1_1sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Syntax1_1sym ) ;
lf_AUX_Kernel_Sdf_Syntax1_2sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Syntax1_2sym ) ;
lf_AUX_Kernel_Sdf_Syntax1_4sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Syntax1_4sym ) ;
lf_AUX_Kernel_Sdf_Syntax1_3sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Syntax1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_Syntax1_1 , lf_AUX_Kernel_Sdf_Syntax1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_Syntax1_2 , lf_AUX_Kernel_Sdf_Syntax1_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf_AUX_Kernel_Sdf_Syntax1_3 , lf_AUX_Kernel_Sdf_Syntax1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_Syntax1_4 , lf_AUX_Kernel_Sdf_Syntax1_4sym ) ;
}
void resolve_AUX_Kernel_Sdf_Syntax1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_Kernel_Sdf_Syntax1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Kernel_Sdf_Syntax1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Kernel_Sdf_Syntax1_3sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_Syntax1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Kernel_Sdf_Syntax1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Kernel_Sdf_Syntax1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Kernel_Sdf_Syntax1_4sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_Syntax1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Kernel_Sdf_Syntax1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_Kernel_Sdf_Syntax1_2 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_Kernel_Sdf_Syntax1_2sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_Syntax1_2sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_Kernel_Sdf_Syntax1_2sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_Kernel_Sdf_Syntax1_1 ( ) {
CONS_ENTRY ( lf_AUX_Kernel_Sdf_Syntax1_1sym , ATmakeAppl0 ( lf_AUX_Kernel_Sdf_Syntax1_1sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Kernel_Sdf_Syntax1_1sym ) ) ;
}

