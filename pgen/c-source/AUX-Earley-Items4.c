#include  "support.h"
static Symbol lf_AUX_Earley_Items4_1sym ;
static ATerm lf_AUX_Earley_Items4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
void register_AUX_Earley_Items4 ( ) {
lf_AUX_Earley_Items4_1sym = ATmakeSymbol ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"(=\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Earley_Items4_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Item\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"ItemSet\"),w(\"\"),ql(\"(=\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_Earley_Items4_1 , lf_AUX_Earley_Items4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Item\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Earley_Items4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"Item\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ItemSet\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"Item\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Earley-Items\"),w(\"\"),[sort(\"Item\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"ItemSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Earley_Items4 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Earley_Items4_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Earley_Items4_1sym , ATmakeAppl ( lf_AUX_Earley_Items4_1sym , arg0 , arg1 ) ) ;
lbl_lf_AUX_Earley_Items4_1 : if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
if ( term_equal ( ( * ef3 ) ( tmp [ 0 ] , arg1 ) , ( * ef2 ) ( ) ) ) {
arg0 = ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ;
arg1 = arg1 ;
goto lbl_lf_AUX_Earley_Items4_1 ;
}
}
else {
FUNC_EXIT ( ( * ef2 ) ( ) ) ;
}
}
}
}
}
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , lf2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef4 ) ( ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Earley_Items4_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

