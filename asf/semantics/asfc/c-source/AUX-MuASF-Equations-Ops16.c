#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Equations_Ops16_1sym ;
static ATerm lf_AUX_MuASF_Equations_Ops16_1 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef5sym ;
static funcptr ef5 ;
static Symbol ef6sym ;
static funcptr ef6 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_MuASF_Equations_Ops16 ( ) {
lf_AUX_MuASF_Equations_Ops16_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"term-contains-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Equations_Ops16_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"term-contains-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Equations_Ops16_1 , lf_AUX_MuASF_Equations_Ops16_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_MuASF_Equations_Ops16 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"is-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"args-contain-var\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"args-contain-var\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef5 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef5sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"get-funargs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef6 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
ef6sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_MuASF_Equations_Ops16 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_MuASF_Equations_Ops16_1 ( ATerm arg0 ) {
{
ATerm tmp [ 4 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Equations_Ops16_1sym , ATmakeAppl ( lf_AUX_MuASF_Equations_Ops16_1sym , arg0 ) ) ;
( tmp [ 0 ] = ( * ef2 ) ( arg0 ) ) ;
if ( term_equal ( tmp [ 0 ] , ( constant0 ? constant0 : ( constant0 = ( * ef1 ) ( ) ) ) ) ) {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ) ) ;
}
if ( term_equal ( tmp [ 0 ] , ( constant1 ? constant1 : ( constant1 = ( * ef4 ) ( ) ) ) ) ) {
( tmp [ 1 ] = ( * ef5 ) ( arg0 ) ) ;
if ( check_sym ( tmp [ 1 ] , ef6sym ) ) {
( tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ) ;
if ( check_sym ( tmp [ 2 ] , lf2sym ) ) {
( tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ) ;
FUNC_EXIT ( ( * ef3 ) ( lf2 ( make_list ( tmp [ 3 ] ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_MuASF_Equations_Ops16_1sym , arg0 ) ) ;
}
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

