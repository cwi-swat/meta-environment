#include "support.h"
static Symbol lf_AUX_Make_Assign_Conds_C7_2sym;
static ATerm lf_AUX_Make_Assign_Conds_C7_2( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_Make_Assign_Conds_C7_1sym;
static ATerm lf_AUX_Make_Assign_Conds_C7_1( ATerm arg1);
void register_AUX_Make_Assign_Conds_C7( ) {
lf_AUX_Make_Assign_Conds_C7_2sym= ATmakeSymbol( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Make_Assign_Conds_C7_2sym);
lf_AUX_Make_Assign_Conds_C7_1sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Make_Assign_Conds_C7_1sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Make_Assign_Conds_C7_1 , lf_AUX_Make_Assign_Conds_C7_1sym);
register_prod( ATparse( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Make_Assign_Conds_C7_2 , lf_AUX_Make_Assign_Conds_C7_2sym);
}
void resolve_AUX_Make_Assign_Conds_C7( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
}
void init_AUX_Make_Assign_Conds_C7( ) {
}
ATerm lf_AUX_Make_Assign_Conds_C7_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[11];
PROF( prof_lf_AUX_Make_Assign_Conds_C7_2);
if( check_sym( arg0 , lf_AUX_Make_Assign_Conds_C7_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
return ( * ef1)( tmp[ 0] , arg1);
}
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
tmp[ 1]= list_tail( atmp00);
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= ( * ef1)( tmp[ 0] , arg1);
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_Make_Assign_Conds_C7_1sym)) {
tmp[ 5]= arg_0( tmp[ 3]);
if( is_single_element( tmp[ 5])) {
tmp[ 6]= list_head( tmp[ 5]);
tmp[ 7]= lf_AUX_Make_Assign_Conds_C7_2( lf_AUX_Make_Assign_Conds_C7_1( make_list( tmp[ 1])) , tmp[ 4]);
if( check_sym( tmp[ 7] , ef2sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
if( check_sym( tmp[ 8] , lf_AUX_Make_Assign_Conds_C7_1sym)) {
tmp[ 10]= arg_0( tmp[ 8]);
if( not_empty_list( tmp[ 10])) {
return ( * ef2)( lf_AUX_Make_Assign_Conds_C7_1( cons( make_list( tmp[ 6]) , make_list( tmp[ 10]))) , tmp[ 9]);
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
return make_nf2( lf_AUX_Make_Assign_Conds_C7_2sym , arg0 , arg1);
}
}
ATerm lf_AUX_Make_Assign_Conds_C7_1( ATerm arg0) {
PROF( prof_lf_AUX_Make_Assign_Conds_C7_1);
return make_nf1( lf_AUX_Make_Assign_Conds_C7_1sym , arg0);
}

