#include  "support.h"
static Symbol lf_AUX_Symbols_Projection5_1sym ;
static ATerm lf_AUX_Symbols_Projection5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Symbols_Projection5 ( ) {
lf_AUX_Symbols_Projection5_1sym = ATmakeSymbol ( "prod(id(\"Symbols-Projection\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"nm-(-\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbols_Projection5_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Symbols-Projection\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"nm-(-\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Symbols_Projection5_1 , lf_AUX_Symbols_Projection5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Symbols_Projection5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Symbols_Projection5 ( ) {
}
ATerm lf_AUX_Symbols_Projection5_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Symbols_Projection5_1sym , ATmakeAppl ( lf_AUX_Symbols_Projection5_1sym , arg0 , arg1 ) ) ;
lbl_lf_AUX_Symbols_Projection5_1 : if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
{
tmp [ 1 ] = list_tail ( atmp100 ) ;
if ( ! term_equal ( arg0 , tmp [ 0 ] ) ) {
arg0 = arg0 ;
arg1 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
goto lbl_lf_AUX_Symbols_Projection5_1 ;
}
else {
FUNC_EXIT ( ( * ef3 ) ( ) ) ;
}
}
}
else {
FUNC_EXIT ( ( * ef2 ) ( ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Symbols_Projection5_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

