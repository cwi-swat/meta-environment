#include  "support.h"
static Symbol lf_AUX_TermAsFix2Sign3_1sym ;
static ATerm lf_AUX_TermAsFix2Sign3_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef8sym ;
static funcptr ef8 ;
static Symbol ef9sym ;
static funcptr ef9 ;
static Symbol ef10sym ;
static funcptr ef10 ;
static Symbol ef11sym ;
static funcptr ef11 ;
static Symbol ef12sym ;
static funcptr ef12 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef13sym ;
static funcptr ef13 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_TermAsFix2Sign3 ( ) {
lf_AUX_TermAsFix2Sign3_1sym = ATmakeSymbol ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-cffunc2sign\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_TermAsFix2Sign3_1sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-cffunc2sign\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_TermAsFix2Sign3_1 , lf_AUX_TermAsFix2Sign3_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_TermAsFix2Sign3 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-cffunc2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-cffunc2id\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"term-get-args-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"term-get-args-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-cfelems2args\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-cfelems2args\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncTermTableTuple\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef8 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"term-get-attrs-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef8sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFixAccess\"),w(\"\"),[ql(\"term-get-attrs-prod\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef9 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-attrs2terms\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef9sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"term-attrs2terms\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef10 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef10sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef11 = lookup_func ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef11sym = lookup_sym ( ATreadFromString ( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)" ) ) ;
ef12 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef12sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef13 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef13sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_TermAsFix2Sign3 ( ) {
}
ATerm lf_AUX_TermAsFix2Sign3_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 20 ] ;
FUNC_ENTRY ( lf_AUX_TermAsFix2Sign3_1sym , ATmakeAppl ( lf_AUX_TermAsFix2Sign3_1sym , arg0 , arg1 , arg2 ) ) ;
tmp [ 0 ] = ( * ef3 ) ( arg0 , arg1 ) ;
tmp [ 1 ] = ( * ef4 ) ( arg1 ) ;
tmp [ 2 ] = ( * ef5 ) ( tmp [ 1 ] , arg2 ) ;
if ( check_sym ( tmp [ 2 ] , ef6sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf2sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , ef7sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 7 ] , lf3sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 7 ] ) ;
tmp [ 9 ] = ( * ef8 ) ( arg1 ) ;
tmp [ 10 ] = ( * ef9 ) ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , ef7sym ) ) {
tmp [ 11 ] = arg_0 ( tmp [ 10 ] ) ;
if ( check_sym ( tmp [ 11 ] , lf3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ;
tmp [ 13 ] = ( * ef10 ) ( tmp [ 0 ] , ( * ef7 ) ( lf3 ( make_list ( tmp [ 12 ] ) ) ) , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 13 ] , ef11sym ) ) {
tmp [ 14 ] = arg_0 ( tmp [ 13 ] ) ;
tmp [ 15 ] = arg_1 ( tmp [ 13 ] ) ;
tmp [ 16 ] = ( * ef12 ) ( tmp [ 14 ] , ( * ef7 ) ( lf3 ( make_list ( tmp [ 8 ] ) ) ) ) ;
tmp [ 17 ] = ( * ef13 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 16 ] ) ) ) , ( * ef2 ) ( lf2 ( make_list ( tmp [ 6 ] ) ) ) ) ;
if ( check_sym ( tmp [ 17 ] , ef2sym ) ) {
tmp [ 18 ] = arg_0 ( tmp [ 17 ] ) ;
if ( check_sym ( tmp [ 18 ] , lf2sym ) ) {
tmp [ 19 ] = arg_0 ( tmp [ 18 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( ( * ef2 ) ( lf2 ( make_list ( tmp [ 19 ] ) ) ) , tmp [ 15 ] ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_TermAsFix2Sign3_1sym , arg0 , arg1 , arg2 ) ) ;
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

