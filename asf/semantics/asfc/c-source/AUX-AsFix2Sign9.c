#include  "asc-support.h"
static Symbol lf_AUX_AsFix2Sign9_1sym ;
static ATerm lf_AUX_AsFix2Sign9_1 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef7sym ;
static funcptr ef7 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_AsFix2Sign9 ( ) {
lf_AUX_AsFix2Sign9_1sym = ATmakeSymbol ( "prod(id(\"AsFix2Sign\"),w(\"\"),[l(\"cffuncs2sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AsFix2Sign9_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"AsFix2Sign\"),w(\"\"),[l(\"cffuncs2sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_AsFix2Sign9_1 , lf_AUX_AsFix2Sign9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"FuncDef\"),ql(\";\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_AsFix2Sign9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"TermAsFix2Sign\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"get-iter-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix-Basics\"),w(\"\"),[l(\"get-iter-tail\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"AsFix2Sign\"),w(\"\"),[l(\"cffunc2sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"AsFix2Sign\"),w(\"\"),[l(\"cffunc2sign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FNT-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Lists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) ) ;
ef7 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef7sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Signature-Ops\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
void init_AUX_AsFix2Sign9 ( ) {
}
ATerm lf_AUX_AsFix2Sign9_1 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
{
ATerm tmp [ 14 ] ;
FUNC_ENTRY ( lf_AUX_AsFix2Sign9_1sym , ATmakeAppl ( lf_AUX_AsFix2Sign9_1sym , arg0 , arg1 , arg2 ) ) ;
if ( check_sym ( arg1 , ef1sym ) ) {
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( make_list ( null ( ) ) ) ) , arg2 ) ) ;
}
if ( ! term_equal ( arg1 , ( * ef1 ) ( ) ) ) {
( tmp [ 0 ] = ( * ef4 ) ( arg1 ) ) ;
( tmp [ 1 ] = ( * ef5 ) ( arg0 , ( * ef6 ) ( arg1 ) , arg2 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef2sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
( tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
( tmp [ 4 ] = arg_0 ( tmp [ 2 ] ) ) ;
if ( check_sym ( tmp [ 4 ] , lf2sym ) ) {
( tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ) ;
( tmp [ 6 ] = lf_AUX_AsFix2Sign9_1 ( arg0 , tmp [ 0 ] , tmp [ 3 ] ) ) ;
if ( check_sym ( tmp [ 6 ] , ef2sym ) ) {
( tmp [ 7 ] = arg_0 ( tmp [ 6 ] ) ) ;
( tmp [ 8 ] = arg_1 ( tmp [ 6 ] ) ) ;
if ( check_sym ( tmp [ 7 ] , ef3sym ) ) {
( tmp [ 9 ] = arg_0 ( tmp [ 7 ] ) ) ;
if ( check_sym ( tmp [ 9 ] , lf2sym ) ) {
( tmp [ 10 ] = arg_0 ( tmp [ 9 ] ) ) ;
( tmp [ 11 ] = ( * ef7 ) ( ( * ef3 ) ( lf2 ( make_list ( tmp [ 5 ] ) ) ) , ( * ef3 ) ( lf2 ( make_list ( tmp [ 10 ] ) ) ) ) ) ;
if ( check_sym ( tmp [ 11 ] , ef3sym ) ) {
( tmp [ 12 ] = arg_0 ( tmp [ 11 ] ) ) ;
if ( check_sym ( tmp [ 12 ] , lf2sym ) ) {
( tmp [ 13 ] = arg_0 ( tmp [ 12 ] ) ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( lf2 ( make_list ( tmp [ 13 ] ) ) ) , tmp [ 8 ] ) ) ;
}
}
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf3 ( lf_AUX_AsFix2Sign9_1sym , arg0 , arg1 , arg2 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

