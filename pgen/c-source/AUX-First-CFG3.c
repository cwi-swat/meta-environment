#include  "asc-support.h"
static Symbol lf_AUX_First_CFG3_1sym ;
static ATerm lf_AUX_First_CFG3_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef9sym ;
static funcptr ef9 ;
void register_AUX_First_CFG3 ( ) {
lf_AUX_First_CFG3_1sym = ATmakeSymbol ( "prod(id(\"First-CFG\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Labels\"),w(\"\"),l(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_First_CFG3_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Label\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"First-CFG\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Labels\"),w(\"\"),l(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) , lf_AUX_First_CFG3_1 , lf_AUX_First_CFG3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Label\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_First_CFG3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[sort(\"Symbol-Table\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[sort(\"Symbol-Table\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"Label\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"Label\"),w(\"\"),ql(\"(-\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"First-CFG\"),w(\"\"),[ql(\"'e\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"First-CFG\"),w(\"\"),[ql(\"'e\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Label\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"/\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[sort(\"LabelSet\"),w(\"\"),ql(\"/\"),w(\"\"),sort(\"LabelSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
static ATerm constant2 = NULL ;
void init_AUX_First_CFG3 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
ATprotect ( & constant2 ) ;
}
ATerm lf_AUX_First_CFG3_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_First_CFG3_1sym , ATmakeAppl ( lf_AUX_First_CFG3_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( check_sym ( atmp10 , lf2sym ) ) {
{
ATerm atmp100 = arg_0 ( atmp10 ) ;
if ( not_empty_list ( atmp100 ) ) {
tmp [ 0 ] = list_head ( atmp100 ) ;
tmp [ 1 ] = list_tail ( atmp100 ) ;
tmp [ 2 ] = ( * ef2 ) ( arg0 , tmp [ 0 ] ) ;
tmp [ 3 ] = ( * ef3 ) ( ( constant0 ? constant0 : ( constant0 = ( * ef4 ) ( ) ) ) , tmp [ 2 ] ) ;
if ( term_equal ( tmp [ 3 ] , ( constant1 ? constant1 : ( constant1 = ( * ef9 ) ( ) ) ) ) ) {
FUNC_EXIT ( ( * ef6 ) ( ( * ef7 ) ( tmp [ 2 ] , ( * ef8 ) ( ( * ef1 ) ( lf2 ( make_list ( ( * ef4 ) ( ) ) ) ) ) ) , lf_AUX_First_CFG3_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , arg2 ) ) ) ;
}
if ( term_equal ( tmp [ 3 ] , ( constant2 ? constant2 : ( constant2 = ( * ef5 ) ( ) ) ) ) ) {
FUNC_EXIT ( tmp [ 2 ] ) ;
}
}
else {
FUNC_EXIT ( arg2 ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_First_CFG3_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

