#include  "asc-support.h"
static Symbol lf_AUX_Kernel_Sdf_Normalization7_1sym ;
static ATerm lf_AUX_Kernel_Sdf_Normalization7_1 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Kernel_Sdf_Normalization7 ( ) {
lf_AUX_Kernel_Sdf_Normalization7_1sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-Normalization\"),w(\"\"),[ql(\"filter-attributes\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Attributes\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Normalization7_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Attribute\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-Normalization\"),w(\"\"),[ql(\"filter-attributes\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Attributes\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_Normalization7_1 , lf_AUX_Kernel_Sdf_Normalization7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Attribute\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Kernel_Sdf_Normalization7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[l(\"id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[l(\"id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Kernel_Sdf_Normalization7 ( ) {
}
ATerm lf_AUX_Kernel_Sdf_Normalization7_1 ( ATerm arg0 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Kernel_Sdf_Normalization7_1sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_Normalization7_1sym , arg0 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
tmp [ 0 ] = arg_0 ( atmp00 ) ;
{
ATerm atmp00010 ;
ATerm atmp0000 [ 2 ] ;
atmp0000 [ 0 ] = tmp [ 0 ] ;
atmp0000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
atmp00010 = list_head ( tmp [ 0 ] ) ;
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
if ( check_sym ( atmp00010 , ef2sym ) ) {
tmp [ 1 ] = arg_0 ( atmp00010 ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( cons ( slice ( atmp0000 [ 0 ] , atmp0000 [ 1 ] ) , tmp [ 0 ] ) ) ) ) ;
}
atmp0000 [ 1 ] = list_tail ( atmp0000 [ 1 ] ) ;
tmp [ 0 ] = atmp0000 [ 1 ] ;
}
}
}
}
}
FUNC_EXIT ( arg0 ) ;
FUNC_EXIT ( make_nf1 ( lf_AUX_Kernel_Sdf_Normalization7_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

