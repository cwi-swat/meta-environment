#include  "asc-support.h"
static Symbol lf_AUX_Renaming_Sdf_Projection5_1sym ;
static ATerm lf_AUX_Renaming_Sdf_Projection5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Renaming_Sdf_Projection5 ( ) {
lf_AUX_Renaming_Sdf_Projection5_1sym = ATmakeSymbol ( "prod(id(\"Renaming-Sdf-Projection\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Renaming_Sdf_Projection5_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Renaming\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Symbol\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Renaming-Sdf-Projection\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),no-attrs)" ) , lf_AUX_Renaming_Sdf_Projection5_1 , lf_AUX_Renaming_Sdf_Projection5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Symbol\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Renaming\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Renaming_Sdf_Projection5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbols\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"Renaming\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"Renaming\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Projection\"),w(\"\"),[sort(\"Renamings\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Projection\"),w(\"\"),[sort(\"Renamings\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renamings\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renaming\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Renaming-Sdf-Syntax\"),w(\"\"),[sort(\"Symbol\"),w(\"\"),ql(\"=>\"),w(\"\"),sort(\"Symbol\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Renaming\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Renaming_Sdf_Projection5 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Renaming_Sdf_Projection5_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_Renaming_Sdf_Projection5_1sym , ATmakeAppl ( lf_AUX_Renaming_Sdf_Projection5_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( ! not_empty_list ( atmp000 ) ) {
if ( ! not_empty_list ( atmp100 ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
else {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 2 ] = list_head ( atmp100 ) ;
tmp [ 3 ] = list_tail ( atmp100 ) ;
FUNC_EXIT ( ( * ef3 ) ( ( * ef2 ) ( lf3 ( make_list ( ( * ef4 ) ( tmp [ 0 ] , tmp [ 2 ] ) ) ) ) , lf_AUX_Renaming_Sdf_Projection5_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , ( * ef1 ) ( lf2 ( make_list ( tmp [ 3 ] ) ) ) ) ) ) ;
}
}
if ( ! not_empty_list ( atmp100 ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef2 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Renaming_Sdf_Projection5_1sym , arg0 , arg1 ) ) ;
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

