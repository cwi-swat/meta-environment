#include  "support.h"
static Symbol lf_AUX_Rules2C_Aux36_2sym ;
static ATerm lf_AUX_Rules2C_Aux36_2 ( ATerm arg1 ) ;
static Symbol ef4sym ;
static funcptr ef4 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol lf_AUX_Rules2C_Aux36_1sym ;
static ATerm lf_AUX_Rules2C_Aux36_1 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux36 ( ) {
lf_AUX_Rules2C_Aux36_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"cnt-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux36_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_Rules2C_Aux36_1sym = ATmakeSymbol ( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux36_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Expression\"),ql(\",\"))" ) , lf_AUX_Rules2C_Aux36_1 , lf_AUX_Rules2C_Aux36_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"cnt-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux36_2 , lf_AUX_Rules2C_Aux36_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Rules2C_Aux36 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"IntCon\"),w(\"\"),[sort(\"NatCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntCon\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"caller\"),w(\"\"),[l(\"natcon\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NatCon\"),w(\"\"),no-attrs)" ) ) ;
ef4 = lookup_func ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
ef4sym = lookup_sym ( ATreadFromString ( "prod(id(\"Basic-Integers\"),w(\"\"),[sort(\"Int\"),w(\"\"),ql(\"+\"),w(\"\"),sort(\"Int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Int\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Rules2C_Aux36 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Rules2C_Aux36_2 ( ATerm arg0 ) {
{
ATerm tmp [ 2 ] ;
FUNC_ENTRY ( lf_AUX_Rules2C_Aux36_2sym , ATmakeAppl ( lf_AUX_Rules2C_Aux36_2sym , arg0 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Rules2C_Aux36_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
FUNC_EXIT ( ( * ef4 ) ( ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( lf3 ( make_list ( make_char ( 49 ) ) ) ) ) ) , lf_AUX_Rules2C_Aux36_2 ( lf_AUX_Rules2C_Aux36_1 ( make_list ( tmp [ 1 ] ) ) ) ) ) ;
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( ( * ef2 ) ( ( * ef3 ) ( lf3 ( make_list ( make_char ( 48 ) ) ) ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf1 ( lf_AUX_Rules2C_Aux36_2sym , arg0 ) ) ;
}
}
ATerm lf_AUX_Rules2C_Aux36_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Rules2C_Aux36_1sym , ATmakeAppl ( lf_AUX_Rules2C_Aux36_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Rules2C_Aux36_1sym , arg0 ) ) ;
}
ATerm lf3 ( ATerm arg0 ) {
CONS_ENTRY ( lf3sym , ATmakeAppl ( lf3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf3sym , arg0 ) ) ;
}

