#include  "support.h"
static Symbol lf_AUX_Kernel_Sdf_Normalization4_1sym ;
static ATerm lf_AUX_Kernel_Sdf_Normalization4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Kernel_Sdf_Normalization4 ( ) {
lf_AUX_Kernel_Sdf_Normalization4_1sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-Normalization\"),w(\"\"),[l(\"merge1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Prod-Tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Normalization4_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-Normalization\"),w(\"\"),[l(\"merge1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Prod-Tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_Normalization4_1 , lf_AUX_Kernel_Sdf_Normalization4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Kernel_Sdf_Normalization4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Normalization\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Prod-Tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Normalization\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Prod-Tuple\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"->\"),w(\"\"),sort(\"Symbol\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Production\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[sort(\"Attributes\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[sort(\"Attributes\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Attributes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attributes\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Kernel_Sdf_Normalization4 ( ) {
}
ATerm lf_AUX_Kernel_Sdf_Normalization4_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 14 ] ;
FUNC_ENTRY ( lf_AUX_Kernel_Sdf_Normalization4_1sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_Normalization4_1sym , arg0 , arg1 ) ) ;
lbl_lf_AUX_Kernel_Sdf_Normalization4_1 : if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
if ( check_sym ( arg0 , ef3sym ) ) {
tmp [ 2 ] = arg_0 ( arg0 ) ;
tmp [ 3 ] = arg_1 ( arg0 ) ;
tmp [ 4 ] = arg_2 ( arg0 ) ;
if ( check_sym ( tmp [ 2 ] , ef4sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 0 ] , ef3sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 8 ] = arg_1 ( tmp [ 0 ] ) ;
tmp [ 9 ] = arg_2 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 7 ] , ef4sym ) ) {
tmp [ 10 ] = arg_0 ( tmp [ 7 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf3sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
if ( term_equal ( tmp [ 6 ] , tmp [ 11 ] ) ) {
if ( term_equal ( tmp [ 3 ] , tmp [ 8 ] ) ) {
tmp [ 12 ] = ( * ef5 ) ( tmp [ 4 ] , tmp [ 9 ] ) ;
tmp [ 13 ] = ( * ef3 ) ( ( * ef4 ) ( lf3 ( make_list ( tmp [ 6 ] ) ) ) , tmp [ 3 ] , tmp [ 12 ] ) ;
arg0 = tmp [ 13 ] ;
arg1 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
goto lbl_lf_AUX_Kernel_Sdf_Normalization4_1 ;
}
}
}
}
}
}
}
}
}
else {
FUNC_EXIT ( ( * ef2 ) ( arg0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ) ;
}
}
}
}
}
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
tmp [ 2 ] = lf_AUX_Kernel_Sdf_Normalization4_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef1sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
FUNC_EXIT ( ( * ef2 ) ( tmp [ 3 ] , ( * ef1 ) ( lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 6 ] ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Kernel_Sdf_Normalization4_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

