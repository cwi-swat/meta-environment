#include  "support.h"
static Symbol lf_AUX_Normalize_Conds7_2sym ;
static ATerm lf_AUX_Normalize_Conds7_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol lf3sym ;
static ATerm lf3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Normalize_Conds7_1sym ;
static ATerm lf_AUX_Normalize_Conds7_1 ( ATerm arg1 ) ;
void register_AUX_Normalize_Conds7 ( ) {
lf_AUX_Normalize_Conds7_2sym = ATmakeSymbol ( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Normalize_Conds7_2sym ) ;
lf3sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf3sym ) ;
lf_AUX_Normalize_Conds7_1sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Normalize_Conds7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf_AUX_Normalize_Conds7_1 , lf_AUX_Normalize_Conds7_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Normalize_Conds7_2 , lf_AUX_Normalize_Conds7_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf3 , lf3sym ) ;
}
void resolve_AUX_Normalize_Conds7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
void init_AUX_Normalize_Conds7 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Normalize_Conds7_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 14 ] ;
PROF ( prof_lf_AUX_Normalize_Conds7_2 ) ;
if ( check_sym ( arg0 , lf_AUX_Normalize_Conds7_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
return ( * ef1 ) ( tmp [ 0 ] , arg1 ) ;
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef1 ) ( tmp [ 0 ] , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef2sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = arg_2 ( tmp [ 2 ] ) ;
if ( check_sym ( tmp [ 3 ] , lf3sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 3 ] ) ;
if ( check_sym ( tmp [ 4 ] , lf_AUX_Normalize_Conds7_1sym ) ) {
tmp [ 7 ] = arg_0 ( tmp [ 4 ] ) ;
if ( ! not_empty_list ( tmp [ 6 ] ) ) {
if ( not_empty_list ( tmp [ 7 ] ) ) {
tmp [ 8 ] = lf_AUX_Normalize_Conds7_2 ( lf_AUX_Normalize_Conds7_1 ( make_list ( tmp [ 1 ] ) ) , tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 8 ] , ef2sym ) ) {
tmp [ 9 ] = arg_0 ( tmp [ 8 ] ) ;
tmp [ 10 ] = arg_1 ( tmp [ 8 ] ) ;
tmp [ 11 ] = arg_2 ( tmp [ 8 ] ) ;
if ( check_sym ( tmp [ 9 ] , lf3sym ) ) {
tmp [ 12 ] = arg_0 ( tmp [ 9 ] ) ;
if ( check_sym ( tmp [ 10 ] , lf_AUX_Normalize_Conds7_1sym ) ) {
tmp [ 13 ] = arg_0 ( tmp [ 10 ] ) ;
if ( ! not_empty_list ( tmp [ 12 ] ) ) {
if ( not_empty_list ( tmp [ 13 ] ) ) {
return ( * ef2 ) ( ( constant0 ? constant0 : ( constant0 = lf3 ( make_list ( null ( ) ) ) ) ) , lf_AUX_Normalize_Conds7_1 ( cons ( make_list ( tmp [ 7 ] ) , make_list ( tmp [ 13 ] ) ) ) , tmp [ 11 ] ) ;
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
}
}
}
}
return make_nf2 ( lf_AUX_Normalize_Conds7_2sym , arg0 , arg1 ) ;
}
}
ATerm lf_AUX_Normalize_Conds7_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Normalize_Conds7_1 ) ;
return make_nf1 ( lf_AUX_Normalize_Conds7_1sym , arg0 ) ;
}
ATerm lf3 ( ATerm arg0 ) {
PROF ( prof_lf3 ) ;
return make_nf1 ( lf3sym , arg0 ) ;
}

