#include  "support.h"
static Symbol lf_AUX_Make_Left_Linear4_2sym ;
static ATerm lf_AUX_Make_Left_Linear4_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Make_Left_Linear4_1sym ;
static ATerm lf_AUX_Make_Left_Linear4_1 ( ATerm arg1 ) ;
void register_AUX_Make_Left_Linear4 ( ) {
lf_AUX_Make_Left_Linear4_2sym = ATmakeSymbol ( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Make_Left_Linear4_2sym ) ;
lf_AUX_Make_Left_Linear4_1sym = ATmakeSymbol ( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Make_Left_Linear4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Rule\"),ql(\";\"))" ) , lf_AUX_Make_Left_Linear4_1 , lf_AUX_Make_Left_Linear4_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)" ) , lf_AUX_Make_Left_Linear4_2 , lf_AUX_Make_Left_Linear4_2sym ) ;
}
void resolve_AUX_Make_Left_Linear4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Make_Left_Linear4 ( ) {
}
ATerm lf_AUX_Make_Left_Linear4_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 6 ] ;
FUNC_ENTRY ( lf_AUX_Make_Left_Linear4_2sym , ATmakeAppl ( lf_AUX_Make_Left_Linear4_2sym , arg0 , arg1 ) ) ;
if ( check_sym ( arg0 , lf_AUX_Make_Left_Linear4_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = ( * ef2 ) ( tmp [ 0 ] , arg1 ) ;
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Make_Left_Linear4_1 ( make_list ( tmp [ 1 ] ) ) ) ) ;
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] , arg1 ) ;
tmp [ 3 ] = lf_AUX_Make_Left_Linear4_2 ( lf_AUX_Make_Left_Linear4_1 ( make_list ( tmp [ 1 ] ) ) , arg1 ) ;
if ( check_sym ( tmp [ 3 ] , ef1sym ) ) {
tmp [ 4 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf_AUX_Make_Left_Linear4_1sym ) ) {
tmp [ 5 ] = arg_0 ( tmp [ 4 ] ) ;
if ( not_empty_list ( tmp [ 5 ] ) ) {
FUNC_EXIT ( ( * ef1 ) ( lf_AUX_Make_Left_Linear4_1 ( cons ( make_list ( tmp [ 2 ] ) , make_list ( tmp [ 5 ] ) ) ) ) ) ;
}
}
}
}
}
}
}
FUNC_EXIT ( make_nf2 ( lf_AUX_Make_Left_Linear4_2sym , arg0 , arg1 ) ) ;
}
}
ATerm lf_AUX_Make_Left_Linear4_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Make_Left_Linear4_1sym , ATmakeAppl ( lf_AUX_Make_Left_Linear4_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Make_Left_Linear4_1sym , arg0 ) ) ;
}

