#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Equations_Ops17_2sym ;
static ATerm lf_AUX_MuASF_Equations_Ops17_2 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf_AUX_MuASF_Equations_Ops17_1sym ;
static ATerm lf_AUX_MuASF_Equations_Ops17_1 ( ATerm arg1 ) ;
void register_AUX_MuASF_Equations_Ops17 ( ) {
lf_AUX_MuASF_Equations_Ops17_2sym = ATmakeSymbol ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"args-contain-var\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Equations_Ops17_2sym ) ;
lf_AUX_MuASF_Equations_Ops17_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Equations_Ops17_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_MuASF_Equations_Ops17_1 , lf_AUX_MuASF_Equations_Ops17_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"args-contain-var\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Equations_Ops17_2 , lf_AUX_MuASF_Equations_Ops17_2sym ) ;
}
void resolve_AUX_MuASF_Equations_Ops17 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[ql(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"ATerm-Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"assoc\")],w(\"\"),l(\"}\")))" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"term-contains-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"term-contains-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_MuASF_Equations_Ops17 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_MuASF_Equations_Ops17_2 ( ATerm arg0 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Equations_Ops17_2sym , ATmakeAppl ( lf_AUX_MuASF_Equations_Ops17_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_MuASF_Equations_Ops17_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( not_empty_list ( atmp00 ) ) {
( tmp [ 0 ] = list_head ( atmp00 ) ) ;
( tmp [ 1 ] = list_tail ( atmp00 ) ) ;
FUNC_EXIT ( ( * ef2 ) ( ( * ef3 ) ( tmp [ 0 ] ) , lf_AUX_MuASF_Equations_Ops17_2 ( lf_AUX_MuASF_Equations_Ops17_1 ( make_list ( tmp [ 1 ] ) ) ) ) ) ;
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ) ) ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_MuASF_Equations_Ops17_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_MuASF_Equations_Ops17_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Equations_Ops17_1sym , ATmakeAppl ( lf_AUX_MuASF_Equations_Ops17_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Equations_Ops17_1sym , arg0 ) ) ;
}

