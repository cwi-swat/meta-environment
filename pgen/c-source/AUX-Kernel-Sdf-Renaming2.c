#include  "asc-support.h"
static Symbol lf_AUX_Kernel_Sdf_Renaming2_1sym ;
static ATerm lf_AUX_Kernel_Sdf_Renaming2_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
void register_AUX_Kernel_Sdf_Renaming2 ( ) {
lf_AUX_Kernel_Sdf_Renaming2_1sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-Renaming\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Renaming2_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-Renaming\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_Renaming2_1 , lf_AUX_Kernel_Sdf_Renaming2_1sym ) ;
}
void resolve_AUX_Kernel_Sdf_Renaming2 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Projection\"),w(\"\"),[ql(\"proj\"),w(\"\"),ql(\"_\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Renamings\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Projection\"),w(\"\"),[ql(\"proj\"),w(\"\"),ql(\"_\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Renamings\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Renaming\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"]\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Renaming\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"]\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Kernel_Sdf_Renaming2 ( ) {
}
ATerm lf_AUX_Kernel_Sdf_Renaming2_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 1 ] ;
FUNC_ENTRY ( lf_AUX_Kernel_Sdf_Renaming2_1sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_Renaming2_1sym , arg0 , arg1 ) ) ;
tmp [ 0 ] = ( * ef1 ) ( arg0 , arg1 ) ;
if ( ! term_equal ( arg0 , tmp [ 0 ] ) ) {
FUNC_EXIT ( tmp [ 0 ] ) ;
}
FUNC_EXIT ( ( * ef2 ) ( arg0 , arg1 ) ) ;
FUNC_EXIT ( make_nf2 ( lf_AUX_Kernel_Sdf_Renaming2_1sym , arg0 , arg1 ) ) ;
}
}

