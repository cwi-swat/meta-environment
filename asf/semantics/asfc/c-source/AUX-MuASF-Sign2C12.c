#include  "asc-support.h"
static Symbol lf_AUX_MuASF_Sign2C12_2sym ;
static ATerm lf_AUX_MuASF_Sign2C12_2 ( ATerm arg1 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf_AUX_MuASF_Sign2C12_1sym ;
static ATerm lf_AUX_MuASF_Sign2C12_1 ( ATerm arg1 ) ;
void register_AUX_MuASF_Sign2C12 ( ) {
lf_AUX_MuASF_Sign2C12_2sym = ATmakeSymbol ( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"countsigargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Sign2C12_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_MuASF_Sign2C12_1sym = ATmakeSymbol ( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_MuASF_Sign2C12_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"SigArg\"),ql(\",\"))" ) , lf_AUX_MuASF_Sign2C12_1 , lf_AUX_MuASF_Sign2C12_1sym ) ;
register_prod ( ATparse ( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"countsigargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) , lf_AUX_MuASF_Sign2C12_2 , lf_AUX_MuASF_Sign2C12_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_MuASF_Sign2C12 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_MuASF_Sign2C12 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_MuASF_Sign2C12_2 ( ATerm arg0 ) {
{
ATerm tmp [ 3 ] ;
FUNC_ENTRY ( lf_AUX_MuASF_Sign2C12_2sym , ATmakeAppl ( lf_AUX_MuASF_Sign2C12_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_MuASF_Sign2C12_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ( * ef2 ) ( lf3 ( make_list ( make_char ( 49 ) ) ) ) ) ) ;
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = lf_AUX_MuASF_Sign2C12_2 ( lf_AUX_MuASF_Sign2C12_1 ( make_list ( tmp [ 1 ] ) ) ) ;
FUNC_EXIT ( ( * ef3 ) ( tmp [ 2 ] ) ) ;
}
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_MuASF_Sign2C12_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_MuASF_Sign2C12_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_MuASF_Sign2C12_1sym , ATmakeAppl ( lf_AUX_MuASF_Sign2C12_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_MuASF_Sign2C12_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

