#include  "support.h"
static Symbol lf_AUX_Rules2C_Aux9_2sym ;
static ATerm lf_AUX_Rules2C_Aux9_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Rules2C_Aux9_1sym ;
static ATerm lf_AUX_Rules2C_Aux9_1 ( ATerm arg1 ) ;
void register_AUX_Rules2C_Aux9 ( ) {
lf_AUX_Rules2C_Aux9_2sym = ATmakeSymbol ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-ofs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux9_2sym ) ;
lf_AUX_Rules2C_Aux9_1sym = ATmakeSymbol ( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Rules2C_Aux9_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Rule\"),ql(\";\"))" ) , lf_AUX_Rules2C_Aux9_1 , lf_AUX_Rules2C_Aux9_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-on-ofs\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) , lf_AUX_Rules2C_Aux9_2 , lf_AUX_Rules2C_Aux9_2sym ) ;
}
void resolve_AUX_Rules2C_Aux9 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleListPair\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Rules2C_Aux9 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Rules2C_Aux9_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 8 ] ;
FUNC_ENTRY ( lf_AUX_Rules2C_Aux9_2sym , ATmakeAppl ( lf_AUX_Rules2C_Aux9_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg1 , lf_AUX_Rules2C_Aux9_1sym ) ) {
{
ATerm atmp10 = arg_0 ( arg1 ) ;
if ( not_empty_list ( atmp10 ) ) {
tmp [ 0 ] = list_head ( atmp10 ) ;
tmp [ 1 ] = list_tail ( atmp10 ) ;
tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] ) ;
if ( ! term_equal ( arg0 , tmp [ 2 ] ) ) {
tmp [ 3 ] = lf_AUX_Rules2C_Aux9_2 ( arg0 , lf_AUX_Rules2C_Aux9_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 3 ] , ef1sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
tmp [ 5 ] = arg_1 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf_AUX_Rules2C_Aux9_1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , lf_AUX_Rules2C_Aux9_1sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 5 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux9_1 ( make_list ( tmp [ 6 ] ) ) , lf_AUX_Rules2C_Aux9_1 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 7 ] ) ) ) ) ) ;
}
}
}
}
if ( term_equal ( ( * ef2 ) ( tmp [ 0 ] ) , arg0 ) ) {
tmp [ 2 ] = lf_AUX_Rules2C_Aux9_2 ( arg0 , lf_AUX_Rules2C_Aux9_1 ( make_list ( tmp [ 1 ] ) ) ) ;
if ( check_sym ( tmp [ 2 ] , ef1sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf_AUX_Rules2C_Aux9_1sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf_AUX_Rules2C_Aux9_1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 4 ] ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Rules2C_Aux9_1 ( cons ( make_list ( tmp [ 0 ] ) , make_list ( tmp [ 5 ] ) ) ) , lf_AUX_Rules2C_Aux9_1 ( make_list ( tmp [ 6 ] ) ) ) ) ;
}
}
}
}
}
else {
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf_AUX_Rules2C_Aux9_1 ( make_list ( null ( ) ) ) , lf_AUX_Rules2C_Aux9_1 ( make_list ( null ( ) ) ) ) ) ;
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Rules2C_Aux9_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Rules2C_Aux9_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Rules2C_Aux9_1sym , ATmakeAppl ( lf_AUX_Rules2C_Aux9_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Rules2C_Aux9_1sym , arg0 ) ) ;
}

