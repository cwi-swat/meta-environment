#include  "support.h"
static Symbol lf_AUX_Make_Assign_Conds_C7_2sym ;
static ATerm lf_AUX_Make_Assign_Conds_C7_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf_AUX_Make_Assign_Conds_C7_1sym ;
static ATerm lf_AUX_Make_Assign_Conds_C7_1 ( ATerm arg1 ) ;
void register_AUX_Make_Assign_Conds_C7 ( ) {
lf_AUX_Make_Assign_Conds_C7_2sym = ATmakeSymbol ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"inspect-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Make_Assign_Conds_C7_2sym ) ;
lf_AUX_Make_Assign_Conds_C7_1sym = ATmakeSymbol ( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Make_Assign_Conds_C7_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Term\"),ql(\",\"))" ) , lf_AUX_Make_Assign_Conds_C7_1 , lf_AUX_Make_Assign_Conds_C7_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"inspect-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" ) , lf_AUX_Make_Assign_Conds_C7_2 , lf_AUX_Make_Assign_Conds_C7_2sym ) ;
}
void resolve_AUX_Make_Assign_Conds_C7 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"inspect-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"inspect-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)" ) ) ;
}
void init_AUX_Make_Assign_Conds_C7 ( ) {
}
ATerm lf_AUX_Make_Assign_Conds_C7_2 ( ATerm arg0 , ATerm arg1 ) {
{
ATerm tmp [ 4 ] ;
PROF ( prof_lf_AUX_Make_Assign_Conds_C7_2 ) ;
if ( check_sym ( arg0 , lf_AUX_Make_Assign_Conds_C7_1sym ) ) {
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
tmp [ 2 ] = lf_AUX_Make_Assign_Conds_C7_2 ( lf_AUX_Make_Assign_Conds_C7_1 ( make_list ( tmp [ 0 ] ) ) , arg1 ) ;
tmp [ 3 ] = lf_AUX_Make_Assign_Conds_C7_2 ( lf_AUX_Make_Assign_Conds_C7_1 ( make_list ( tmp [ 1 ] ) ) , tmp [ 2 ] ) ;
return tmp [ 3 ] ;
}
}
}
}
return make_nf2 ( lf_AUX_Make_Assign_Conds_C7_2sym , arg0 , arg1 ) ;
}
}
ATerm lf_AUX_Make_Assign_Conds_C7_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_Make_Assign_Conds_C7_1 ) ;
return make_nf1 ( lf_AUX_Make_Assign_Conds_C7_1sym , arg0 ) ;
}

