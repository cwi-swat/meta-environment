#include  "asc-support.h"
static Symbol lf_AUX_Kernel_Sdf_ATerms4_2sym ;
static ATerm lf_AUX_Kernel_Sdf_ATerms4_2 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf_AUX_Kernel_Sdf_ATerms4_1sym ;
static ATerm lf_AUX_Kernel_Sdf_ATerms4_1 ( ATerm arg1 ) ;
void register_AUX_Kernel_Sdf_ATerms4 ( ) {
lf_AUX_Kernel_Sdf_ATerms4_2sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-ATerms\"),w(\"\"),[l(\"atermlist\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_ATerms4_2sym ) ;
lf_AUX_Kernel_Sdf_ATerms4_1sym = ATmakeSymbol ( "listtype(sort(\"Attribute\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_ATerms4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Attribute\"),ql(\",\"))" ) , lf_AUX_Kernel_Sdf_ATerms4_1 , lf_AUX_Kernel_Sdf_ATerms4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-ATerms\"),w(\"\"),[l(\"atermlist\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_ATerms4_2 , lf_AUX_Kernel_Sdf_ATerms4_2sym ) ;
}
void resolve_AUX_Kernel_Sdf_ATerms4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Attribute\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-ATerms\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Attribute\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-ATerms\"),w(\"\"),[l(\"aterm\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Attribute\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Kernel_Sdf_ATerms4 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Kernel_Sdf_ATerms4_2 ( ATerm arg0 ) {
{
ATerm tmp [ 1 ] ;
FUNC_ENTRY ( lf_AUX_Kernel_Sdf_ATerms4_2sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_ATerms4_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Kernel_Sdf_ATerms4_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( term_equal ( ( * ef2 ) ( lf_AUX_Kernel_Sdf_ATerms4_1 ( make_list ( atmp00 ) ) ) , ( constant0 ? constant0 : ( constant0 = ( * ef2 ) ( lf_AUX_Kernel_Sdf_ATerms4_1 ( make_list ( null ( ) ) ) ) ) ) ) ) {
FUNC_EXIT_CONST ( constant1 , ( * ef1 ) ( ) ) ;
}
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
FUNC_EXIT ( ( * ef3 ) ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 0 ] ) ) ) ) ;
}
}
}
if ( check_sym ( arg0 , lf_AUX_Kernel_Sdf_ATerms4_1sym ) ) {
tmp [ 0 ] = arg_0 ( arg0 ) ;
{
ATerm atmp000 [ 2 ] ;
atmp000 [ 0 ] = tmp [ 0 ] ;
if ( not_empty_list ( tmp [ 0 ] ) ) {
tmp [ 0 ] = list_tail ( tmp [ 0 ] ) ;
atmp000 [ 1 ] = tmp [ 0 ] ;
while ( not_empty_list ( tmp [ 0 ] ) ) {
if ( not_empty_list ( tmp [ 0 ] ) ) {
FUNC_EXIT ( ( * ef6 ) ( lf_AUX_Kernel_Sdf_ATerms4_2 ( lf_AUX_Kernel_Sdf_ATerms4_1 ( slice ( atmp000 [ 0 ] , atmp000 [ 1 ] ) ) ) , lf_AUX_Kernel_Sdf_ATerms4_2 ( lf_AUX_Kernel_Sdf_ATerms4_1 ( tmp [ 0 ] ) ) ) ) ;
}
atmp000 [ 1 ] = list_tail ( atmp000 [ 1 ] ) ;
tmp [ 0 ] = atmp000 [ 1 ] ;
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Kernel_Sdf_ATerms4_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Kernel_Sdf_ATerms4_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Kernel_Sdf_ATerms4_1sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_ATerms4_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Kernel_Sdf_ATerms4_1sym , arg0 ) ) ;
}

