#include  "asc-support.h"
static Symbol lf_AUX_AsFix2muASF4_1sym ;
static ATerm lf_AUX_AsFix2muASF4_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_AsFix2muASF4 ( ) {
lf_AUX_AsFix2muASF4_1sym = ATmakeSymbol ( "prod(id(\"AsFix2muASF\"),w(\"\"),[l(\"ceqeqs2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2muASF4_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2muASF\"),w(\"\"),[l(\"ceqeqs2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2muASF4_1 , lf_AUX_AsFix2muASF4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Rule\"),ql(\";\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_AsFix2muASF4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"get-iter-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"get-iter-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2muASF\"),w(\"\"),[l(\"pln-ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2muASF\"),w(\"\"),[l(\"pln-ceqeq2rules\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_AsFix2muASF4 ( ) {
}
ATerm lf_AUX_AsFix2muASF4_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 18 ] ;
FUNC_ENTRY ( lf_AUX_AsFix2muASF4_1sym , ATmakeAppl ( lf_AUX_AsFix2muASF4_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( null ( ) ) ) , lf3 ( make_list ( null ( ) ) ) , arg1 ) ) ;
}
if ( ! term_equal ( arg0 , ( * ef1 ) ( ) ) ) {
( tmp [ 0 ] = ( * ef3 ) ( arg0 ) ) ;
( tmp [ 1 ] = ( * ef4 ) ( arg0 ) ) ;
( tmp [ 2 ] = ( * ef5 ) ( tmp [ 1 ] , arg1 ) ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
( tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ) ;
( tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
( tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ) ;
if ( is_single_element ( tmp [ 7 ] ) ) {
( tmp [ 8 ] = list_head ( tmp [ 7 ] ) ) ;
( tmp [ 9 ] = lf_AUX_AsFix2muASF4_1 ( tmp [ 0 ] , tmp [ 5 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , ef2sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ) ;
( tmp [ 11 ] = arg_1 ( tmp [ 9 ] ) ) ;
( tmp [ 12 ] = arg_2 ( tmp [ 9 ] ) ) ;
if ( check_sym ( tmp [ 10 ] , lf2sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ) ;
if ( check_sym ( tmp [ 11 ] , lf3sym ) ) {
( tmp [ 14 ] = arg_0 ( tmp [ 11 ] ) ) ;
( tmp [ 15 ] = ( * ef6 ) ( ( * ef7 ) ( lf2 ( make_list ( tmp [ 6 ] ) ) ) , ( * ef7 ) ( lf2 ( make_list ( tmp [ 13 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 15 ] , ef7sym ) ) {
( tmp [ 16 ] = arg_0 ( tmp [ 15 ] ) ) ;
if ( check_sym ( tmp [ 16 ] , lf2sym ) ) {
( tmp [ 17 ] = arg_0 ( tmp [ 16 ] ) ) ;
FUNC_EXIT ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 17 ] ) ) , lf3 ( cons ( make_list ( tmp [ 8 ] ) , make_list ( tmp [ 14 ] ) ) ) , tmp [ 12 ] ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_AsFix2muASF4_1sym , arg0 , arg1 ) ) ;
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

