/* This C code is generated by the AsfSdfCompiler version 1.3 */

#include  "asc-support.h"
static Symbol lf_AUX_Sdf2_to_ADT9_2_recursivesym ;
static ATerm lf_AUX_Sdf2_to_ADT9_2_recursive ( ATerm arg1 ) ;
static Symbol lf_AUX_Sdf2_to_ADT9_2sym ;
static ATerm lf_AUX_Sdf2_to_ADT9_2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf_AUX_Sdf2_to_ADT9_1sym ;
static ATerm lf_AUX_Sdf2_to_ADT9_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_Sdf2_to_ADT9 ( ) {
lf_AUX_Sdf2_to_ADT9_2_recursivesym = ATmakeSymbol ( "prod(id(\"Sdf2-to-ADT\"),w(\"\"),[ql(\"lexicals-to-adt\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"Production\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_to_ADT9_2_recursivesym ) ;
lf_AUX_Sdf2_to_ADT9_2sym = ATmakeSymbol ( "prod(id(\"Sdf2-to-ADT\"),w(\"\"),[ql(\"lexicals-to-adt\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"Production\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_to_ADT9_2sym ) ;
lf_AUX_Sdf2_to_ADT9_1sym = ATmakeSymbol ( "listtype(sort(\"Production\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Sdf2_to_ADT9_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"ATerm\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Production\"))" ) , lf_AUX_Sdf2_to_ADT9_1 , lf_AUX_Sdf2_to_ADT9_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-to-ADT\"),w(\"\"),[ql(\"lexicals-to-adt\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"Production\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_to_ADT9_2 , lf_AUX_Sdf2_to_ADT9_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Sdf2-to-ADT\"),w(\"\"),[ql(\"lexicals-to-adt\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"Production\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) , lf_AUX_Sdf2_to_ADT9_2_recursive , lf_AUX_Sdf2_to_ADT9_2_recursivesym ) ;
register_prod ( ATparse ( "listtype(sort(\"ATerm\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Sdf2_to_ADT9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"avoid\")],w(\"\"),l(\"}\")))" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Syntax\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"avoid\")],w(\"\"),l(\"}\")))" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Sdf2-to-ADT\"),w(\"\"),[ql(\"lexical-to-adt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Sdf2-to-ADT\"),w(\"\"),[ql(\"lexical-to-adt\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Production\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Sdf2_to_ADT9 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Sdf2_to_ADT9_2 ( ATerm arg0 ) {
{
ATerm tmp [ 8 ] ;
FUNC_ENTRY ( lf_AUX_Sdf2_to_ADT9_2sym , ATmakeAppl ( lf_AUX_Sdf2_to_ADT9_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Sdf2_to_ADT9_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
( tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef1sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
( tmp [ 5 ] = lf_AUX_Sdf2_to_ADT9_2 ( lf_AUX_Sdf2_to_ADT9_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 5 ] , ef1sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , lf3sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf3 ( cons ( make_list ( tmp [ 4 ] ) , make_list ( tmp [ 7 ] ) ) ) ) ) ;
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Sdf2_to_ADT9_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Sdf2_to_ADT9_2_recursive ( ATerm arg0 ) {
{
ATerm tmp [ 8 ] ;
FUNC_ENTRY ( lf_AUX_Sdf2_to_ADT9_2_recursivesym , ATmakeAppl ( lf_AUX_Sdf2_to_ADT9_2_recursivesym , arg0 ) ) ;
{
ATerm atmp00 = arg0 ;
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
( tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef1sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ) ;
( tmp [ 5 ] = lf_AUX_Sdf2_to_ADT9_2 ( lf_AUX_Sdf2_to_ADT9_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
if ( check_sym ( tmp [ 5 ] , ef1sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , lf3sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
FUNC_EXIT ( ( * ef1 ) ( lf3 ( cons ( make_list ( tmp [ 4 ] ) , make_list ( tmp [ 7 ] ) ) ) ) ) ;
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf3 ( make_list ( null ( ) ) ) ) ) ;
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Sdf2_to_ADT9_2_recursivesym , lf_AUX_Sdf2_to_ADT9_1 ( arg0 ) ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf_AUX_Sdf2_to_ADT9_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Sdf2_to_ADT9_1sym , ATmakeAppl ( lf_AUX_Sdf2_to_ADT9_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Sdf2_to_ADT9_1sym , arg0 ) ) ;
}

