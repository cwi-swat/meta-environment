#include  "support.h"
static Symbol lf_AUX_RenameVars6_2sym ;
static ATerm lf_AUX_RenameVars6_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef2sym ;
static funcptr ef2 ;
static Symbol ef3sym ;
static funcptr ef3 ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_RenameVars6_1sym ;
static ATerm lf_AUX_RenameVars6_1 ( ATerm arg1 ) ;
void register_AUX_RenameVars6 ( ) {
lf_AUX_RenameVars6_2sym = ATmakeSymbol ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars6_2sym ) ;
lf_AUX_RenameVars6_1sym = ATmakeSymbol ( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_RenameVars6_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Cond\"),ql(\"&\"))" ) , lf_AUX_RenameVars6_1 , lf_AUX_RenameVars6_1sym ) ;
register_prod ( ATparse ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)" ) , lf_AUX_RenameVars6_2 , lf_AUX_RenameVars6_2sym ) ;
}
void resolve_AUX_RenameVars6 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVEs\"),w(\"\"),no-attrs)" ) ) ;
ef2 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" ) ) ;
ef2sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" ) ) ;
ef3 = lookup_func ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" ) ) ;
ef3sym = lookup_sym ( ATreadFromString ( "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CIVE\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_RenameVars6 ( ) {
}
ATerm lf_AUX_RenameVars6_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 9 ] ;
PROF ( prof_lf_AUX_RenameVars6_2 ) ;
if ( check_sym ( arg0 , lf_AUX_RenameVars6_1sym ) ) {
{
ATerm atmp00 = arg_0 ( arg0 ) ;
if ( is_single_element ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = ( * ef2 ) ( tmp [ 0 ] , arg1 ) ;
if ( check_sym ( tmp [ 1 ] , ef3sym ) ) {
tmp [ 2 ] = arg_0 ( tmp [ 1 ] ) ;
tmp [ 3 ] = arg_1 ( tmp [ 1 ] ) ;
return ( * ef1 ) ( lf_AUX_RenameVars6_1 ( make_list ( tmp [ 2 ] ) ) , tmp [ 3 ] ) ;
}
}
if ( not_empty_list ( atmp00 ) ) {
tmp [ 0 ] = list_head ( atmp00 ) ;
tmp [ 1 ] = list_tail ( atmp00 ) ;
if ( not_empty_list ( tmp [ 1 ] ) ) {
tmp [ 2 ] = ( * ef2 ) ( tmp [ 0 ] , arg1 ) ;
if ( check_sym ( tmp [ 2 ] , ef3sym ) ) {
tmp [ 3 ] = arg_0 ( tmp [ 2 ] ) ;
tmp [ 4 ] = arg_1 ( tmp [ 2 ] ) ;
tmp [ 5 ] = lf_AUX_RenameVars6_2 ( lf_AUX_RenameVars6_1 ( make_list ( tmp [ 1 ] ) ) , tmp [ 4 ] ) ;
if ( check_sym ( tmp [ 5 ] , ef1sym ) ) {
tmp [ 6 ] = arg_0 ( tmp [ 5 ] ) ;
tmp [ 7 ] = arg_1 ( tmp [ 5 ] ) ;
if ( check_sym ( tmp [ 6 ] , lf_AUX_RenameVars6_1sym ) ) {
tmp [ 8 ] = arg_0 ( tmp [ 6 ] ) ;
if ( not_empty_list ( tmp [ 8 ] ) ) {
return ( * ef1 ) ( lf_AUX_RenameVars6_1 ( cons ( make_list ( tmp [ 3 ] ) , make_list ( tmp [ 8 ] ) ) ) , tmp [ 7 ] ) ;
}
}
}
}
}
}
}
}
return make_nf2 ( lf_AUX_RenameVars6_2sym , arg0 , arg1 ) ;
}
}
ATerm lf_AUX_RenameVars6_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_RenameVars6_1 ) ;
return make_nf1 ( lf_AUX_RenameVars6_1sym , arg0 ) ;
}

