#include  "asc-support.h"
static Symbol lf_AUX_Kernel_Sdf_Syntax3_1sym ;
static ATerm lf_AUX_Kernel_Sdf_Syntax3_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Kernel_Sdf_Syntax3 ( ) {
lf_AUX_Kernel_Sdf_Syntax3_1sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Syntax3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"syntax\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_Syntax3_1 , lf_AUX_Kernel_Sdf_Syntax3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Kernel_Sdf_Syntax3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Grammar-Syntax\"),w(\"\"),[ql(\"(/)\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Grammar\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Kernel_Sdf_Syntax3 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Kernel_Sdf_Syntax3_1 ( ATerm arg0 ) {
FUNC_ENTRY ( lf_AUX_Kernel_Sdf_Syntax3_1sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_Syntax3_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( ! not_empty_list ( atmp000 ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Kernel_Sdf_Syntax3_1sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

