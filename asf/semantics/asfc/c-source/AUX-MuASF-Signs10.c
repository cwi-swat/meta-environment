#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Signs10_1sym ;
static ATerm lf_AUX_MuASF_Signs10_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
void register_AUX_MuASF_Signs10 ( ) {
lf_AUX_MuASF_Signs10_1sym = ATmakeSymbol ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-new-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Signs10_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-new-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Signs10_1 , lf_AUX_MuASF_Signs10_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf2 , lf2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"SigArg\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_MuASF_Signs10 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"_\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SigArg\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"_\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SigArg\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_MuASF_Signs10 ( ) {
}
ATerm lf_AUX_MuASF_Signs10_1 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Signs10_1sym , ATmakeAppl ( lf_AUX_MuASF_Signs10_1sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , ef1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
{
ATerm atmp01 = arg_1 ( arg0 ) ;
if ( check_sym ( atmp01 , lf2sym ) ) {
{
ATerm atmp010 = arg_0 ( atmp01 ) ;
if ( is_single_element ( atmp010 ) ) {
tmp [ 0 ] = list_head ( atmp010 ) ;
FUNC_EXIT ( ( * ef2 ) ( arg1 , lf3 ( make_list ( ( * ef3 ) ( ) ) ) ) ) ;
}
if ( not_empty_list ( atmp010 ) ) {
tmp [ 0 ] = list_head ( atmp010 ) ;
tmp [ 1 ] = list_tail ( atmp010 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = lf_AUX_MuASF_Signs10_1 ( ( * ef1 ) ( atmp00 , lf2 ( make_list ( tmp [ 1 ] ) ) ) , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf3sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
FUNC_EXIT ( ( * ef2 ) ( tmp [ 3 ] , lf3 ( cons ( make_list ( ( * ef3 ) ( ) ) , make_list ( tmp [ 5 ] ) ) ) ) ) ;
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
FUNC_EXIT ( make_nf2 ( lf_AUX_MuASF_Signs10_1sym , arg0 , arg1 ) ) ;
}
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

