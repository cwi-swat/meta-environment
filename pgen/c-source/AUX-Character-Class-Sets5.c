#include  "asc-support.h"
static Symbol lf_AUX_Character_Class_Sets5_1sym ;
static ATerm lf_AUX_Character_Class_Sets5_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Character_Class_Sets5 ( ) {
lf_AUX_Character_Class_Sets5_1sym = ATmakeSymbol ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Character_Class_Sets5_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"CharClass\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Character_Class_Sets5_1 , lf_AUX_Character_Class_Sets5_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CharClass\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Character_Class_Sets5 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"CharClass\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),iter(sort(\"CharClass\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\"),w(\"\"),sep(\",\"),w(\"\"),l(\"memo\")],w(\"\"),l(\"}\")))" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Sets\"),w(\"\"),[sort(\"CharClassSet\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"CharClassSet\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClassSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Character_Class_Sets5 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Character_Class_Sets5_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Character_Class_Sets5_1sym , ATmakeAppl ( lf_AUX_Character_Class_Sets5_1sym , arg0 , arg1 ) ) ;
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
if ( is_single_element ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
if ( is_single_element ( atmp100 ) ) {
tmp [ 1 ] = list_head ( atmp100 ) ;
FUNC_EXIT ( ( * ef1 ) ( lf2 ( make_list ( ( * ef2 ) ( tmp [ 0 ] , tmp [ 1 ] ) ) ) ) ) ;
}
}
}
}
}
}
if ( not_empty_list ( atmp000 ) ) {
tmp [ 0 ] = list_head ( atmp000 ) ;
tmp [ 1 ] = list_tail ( atmp000 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf_AUX_Character_Class_Sets5_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) , arg1 ) , lf_AUX_Character_Class_Sets5_1 ( ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) , arg1 ) ) ) ;
}
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
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
if ( not_empty_list ( tmp [ 1 ] ) ) {
FUNC_EXIT ( ( * ef3 ) ( lf_AUX_Character_Class_Sets5_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( tmp [ 0 ] ) ) ) ) , lf_AUX_Character_Class_Sets5_1 ( arg0 , ( * ef1 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Character_Class_Sets5_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

