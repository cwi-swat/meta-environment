#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Equations_Ops21_2sym ;
static ATerm lf_AUX_MuASF_Equations_Ops21_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_MuASF_Equations_Ops21_1sym ;
static ATerm lf_AUX_MuASF_Equations_Ops21_1 ( ATerm arg1 ) ;
void register_AUX_MuASF_Equations_Ops21 ( ) {
lf_AUX_MuASF_Equations_Ops21_2sym = ATmakeSymbol ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-list-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Equations_Ops21_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_MuASF_Equations_Ops21_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Equations_Ops21_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_MuASF_Equations_Ops21_1 , lf_AUX_MuASF_Equations_Ops21_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Equations-Ops\"),w(\"\"),[l(\"make-list-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Equations_Ops21_2 , lf_AUX_MuASF_Equations_Ops21_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_MuASF_Equations_Ops21 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_MuASF_Equations_Ops21 ( ) {
}
ATerm lf_AUX_MuASF_Equations_Ops21_2 ( ATerm arg0 , ATerm arg1 ) {
FUNC_ENTRY ( lf_AUX_MuASF_Equations_Ops21_2sym , ATmakeAppl ( lf_AUX_MuASF_Equations_Ops21_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , lf_AUX_MuASF_Equations_Ops21_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
FUNC_EXIT ( ( * ef1 ) ( arg0 , lf_AUX_MuASF_Equations_Ops21_1 ( make_list ( atmp10 ) ) ) ) ;
}
else {
FUNC_EXIT ( ( * ef1 ) ( arg0 , lf_AUX_MuASF_Equations_Ops21_1 ( make_list ( ( * ef2 ) ( ( * ef3 ) ( lf3 ( ( ATerm ) ATmakeList ( 4 , char_table [ 110 ] , char_table [ 117 ] , char_table [ 108 ] , char_table [ 108 ] ) ) ) ) ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_MuASF_Equations_Ops21_2sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_MuASF_Equations_Ops21_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Equations_Ops21_1sym , ATmakeAppl ( lf_AUX_MuASF_Equations_Ops21_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Equations_Ops21_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

