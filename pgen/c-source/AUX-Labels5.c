#include  "asc-support.h"
static Symbol lf_AUX_Labels5_1sym ;
static ATerm lf_AUX_Labels5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Labels5 ( ) {
lf_AUX_Labels5_1sym = ATmakeSymbol ( "prod(id(\"Labels\"),w(\"\"),[sort(\"Label\"),w(\"\"),ql(\"+1\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Labels5_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Label\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Labels\"),w(\"\"),[sort(\"Label\"),w(\"\"),ql(\"+1\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Labels5_1 , lf_AUX_Labels5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Label\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Labels5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"Label\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"Label\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Labels5 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Labels5_1 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_Labels5_1sym , ATmakeAppl ( lf_AUX_Labels5_1sym , arg0 , arg1 ) ) ;
if ( term_equal ( ( * ef1 ) ( arg0 , arg1 ) , ( constant0 ? constant0 : ( constant0 = ( * ef2 ) ( ) ) ) ) ) {
FUNC_EXIT ( arg1 ) ;
}
if ( check_sym ( arg1 , ef3sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , ef4sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( check_sym ( atmp100 , lf2sym ) ) {
{
ATerm atmp1000 = arg_0 ( atmp100 ) ;
FUNC_EXIT ( ( * ef3 ) ( ( * ef4 ) ( lf2 ( cons ( make_list ( arg0 ) , make_list ( atmp1000 ) ) ) ) ) ) ;
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Labels5_1sym , arg0 , arg1 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

