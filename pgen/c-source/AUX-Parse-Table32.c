#include  "support.h"
static Symbol lf_AUX_Parse_Table32_1sym ;
static ATerm lf_AUX_Parse_Table32_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
void register_AUX_Parse_Table32 ( ) {
lf_AUX_Parse_Table32_1sym = ATmakeSymbol ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Goto-Table\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"CharClass\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Parse_Table32_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Goto-Entry\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Parse-Table\"),w(\"\"),[sort(\"Goto-Table\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"CharClass\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"Int\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Parse_Table32_1 , lf_AUX_Parse_Table32_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Goto-Entry\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Parse_Table32 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"gotos\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"gotos\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Table\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entries\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"goto\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Parse-Table\"),w(\"\"),[l(\"goto\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"CharClass\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Goto-Entry\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"Character-Class-Syntax\"),w(\"\"),[sort(\"CharClass\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"CharClass\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CharClass\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_Parse_Table32 ( ) {
}
ATerm lf_AUX_Parse_Table32_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Parse_Table32_1sym , ATmakeAppl ( lf_AUX_Parse_Table32_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( arg2 , ef3sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( not_empty_list ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
tmp [ 1 ] = list_tail ( atmp0000 ) ;
if ( check_sym ( tmp [ 0 ] , ef4sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 0 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 0 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef3sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( term_equal ( tmp [ 4 ] , atmp20 ) ) {
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( cons ( make_list ( ( * ef4 ) ( ( * ef5 ) ( tmp [ 2 ] , arg1 ) , ( * ef3 ) ( tmp [ 4 ] ) ) ) , make_list ( tmp [ 1 ] ) ) ) ) ) ) ;
}
}
}
}
else {
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( ( * ef4 ) ( arg1 , arg2 ) ) ) ) ) ) ;
}
}
}
}
}
}
}
}
}
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( check_sym ( atmp00 , ef2sym ) ) {
{
ATerm atmp000 = arg_0 ( atmp00 ) ;
if ( check_sym ( atmp000 , lf2sym ) ) {
{
ATerm atmp0000 = arg_0 ( atmp000 ) ;
if ( check_sym ( arg2 , ef3sym ) ) {
{
ATerm atmp20 = arg_0 ( arg2 ) ;
if ( not_empty_list ( atmp0000 ) ) {
tmp [ 0 ] = list_head ( atmp0000 ) ;
tmp [ 1 ] = list_tail ( atmp0000 ) ;
tmp [ 2 ] = lf_AUX_Parse_Table32_1 ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 1 ] ) ) ) ) , arg1 , arg2 ) ;
if ( check_sym ( tmp [ 2 ] , ef1sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , ef2sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf2sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 5 ] ) ) ) ) ) ) ;
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
}
FUNC_EXIT ( make_nf3 ( lf_AUX_Parse_Table32_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

