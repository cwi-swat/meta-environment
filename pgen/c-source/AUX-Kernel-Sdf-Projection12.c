#include  "support.h"
static Symbol lf_AUX_Kernel_Sdf_Projection12_1sym ;
static ATerm lf_AUX_Kernel_Sdf_Projection12_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Kernel_Sdf_Projection12 ( ) {
lf_AUX_Kernel_Sdf_Projection12_1sym = ATmakeSymbol ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[l(\"reachable\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Kernel_Sdf_Projection12_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[l(\"reachable\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),l(\",\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) , lf_AUX_Kernel_Sdf_Projection12_1 , lf_AUX_Kernel_Sdf_Projection12_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Kernel_Sdf_Projection12 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Production\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[sort(\"Productions\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[sort(\"Productions\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Productions\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Sets\"),w(\"\"),[sort(\"SymbolSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"SymbolSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Sets\"),w(\"\"),[sort(\"SymbolSet\"),w(\"\"),ql(\"||\"),w(\"\"),sort(\"SymbolSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Sets\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"SymbolSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Sets\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"SymbolSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),ql(\"_\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[ql(\"P\"),w(\"\"),ql(\"_\"),w(\"\"),sort(\"Symbol\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Productions\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Sets\"),w(\"\"),[sort(\"SymbolSet\"),w(\"\"),ql(\"/\"),w(\"\"),sort(\"SymbolSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Sets\"),w(\"\"),[sort(\"SymbolSet\"),w(\"\"),ql(\"/\"),w(\"\"),sort(\"SymbolSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[l(\"symbols\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"Kernel-Sdf-Projection\"),w(\"\"),[l(\"symbols\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Productions\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Kernel_Sdf_Projection12 ( ) {
}
ATerm lf_AUX_Kernel_Sdf_Projection12_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Kernel_Sdf_Projection12_1sym , ATmakeAppl ( lf_AUX_Kernel_Sdf_Projection12_1sym , arg0 , arg1 , arg2 ) ) ;
lbl_lf_AUX_Kernel_Sdf_Projection12_1 : if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( check_sym ( arg2 , ef3sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp1000 ) ) {
tmp [ 0 ] = list_head ( atmp1000 ) ;
tmp [ 1 ] = list_tail ( atmp1000 ) ;
if ( term_equal ( ( * ef6 ) ( tmp [ 0 ] , arg0 ) , ( * ef7 ) ( ) ) ) {
tmp [ 2 ] = ( * ef8 ) ( tmp [ 0 ] , ( * ef3 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = ( * ef9 ) ( ( * ef10 ) ( ( * ef3 ) ( lf3 ( make_list ( tmp [ 4 ] ) ) ) ) , arg0 ) ;
FUNC_EXIT ( ( * ef4 ) ( ( * ef3 ) ( lf3 ( make_list ( tmp [ 4 ] ) ) ) , lf_AUX_Kernel_Sdf_Projection12_1 ( ( * ef5 ) ( arg0 , ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) ) ) , ( * ef5 ) ( tmp [ 5 ] , ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) , ( * ef3 ) ( lf3 ( make_list ( atmp200 ) ) ) ) ) ) ;
}
}
}
}
else {
FUNC_EXIT ( ( * ef3 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
if ( check_sym ( arg2 , ef3sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( check_sym ( atmp20 , lf3sym ) ) {
{
ATerm atmp200 = arg_0 ( atmp20 ) ;
if ( not_empty_list ( atmp1000 ) ) {
tmp [ 0 ] = list_head ( atmp1000 ) ;
tmp [ 1 ] = list_tail ( atmp1000 ) ;
arg0 = arg0 ;
arg1 = ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ;
arg2 = ( * ef3 ) ( lf3 ( make_list ( atmp200 ) ) ) ;
goto lbl_lf_AUX_Kernel_Sdf_Projection12_1 ;
}
}
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Kernel_Sdf_Projection12_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

