#include "support.h"
static asymbol * lf_AUX_Make_Assign_Conds_C7_2sym;
static aterm * lf_AUX_Make_Assign_Conds_C7_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_Make_Assign_Conds_C7_1sym;
static aterm * lf_AUX_Make_Assign_Conds_C7_1( aterm * arg1);
void register_AUX_Make_Assign_Conds_C7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Make_Assign_Conds_C7_2sym= TmkSymbol( "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Make_Assign_Conds_C7_1sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf_AUX_Make_Assign_Conds_C7_1 , lf_AUX_Make_Assign_Conds_C7_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Make_Assign_Conds_C7_2 , lf_AUX_Make_Assign_Conds_C7_2sym);
}
void resolve_AUX_Make_Assign_Conds_C7( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Make-Assign-Conds-C\"),w(\"\"),[l(\"make-mc-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Make_Assign_Conds_C7_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[11];
PROF( prof_lf_AUX_Make_Assign_Conds_C7_2);
if( check_sym( arg0 , lf_AUX_Make_Assign_Conds_C7_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_unprotect( arg0);
return ( * ef1)( tmp[ 0] , arg1);
}
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
t_protect( atmp00);
tmp[ 1]= list_tail( atmp00);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 2]= ( * ef1)( tmp[ 0] , arg1);
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_Make_Assign_Conds_C7_1sym)) {
tmp[ 5]= arg_0( tmp[ 3]);
t_protect( tmp[ 5]);
if( is_single_element( tmp[ 5])) {
t_protect( tmp[ 5]);
tmp[ 6]= list_head( tmp[ 5]);
t_protect( tmp[ 1]);
t_protect( tmp[ 4]);
tmp[ 7]= lf_AUX_Make_Assign_Conds_C7_2( lf_AUX_Make_Assign_Conds_C7_1( make_list( tmp[ 1])) , tmp[ 4]);
if( check_sym( tmp[ 7] , ef2sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
if( check_sym( tmp[ 8] , lf_AUX_Make_Assign_Conds_C7_1sym)) {
tmp[ 10]= arg_0( tmp[ 8]);
t_protect( tmp[ 10]);
if( not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
t_protect( tmp[ 9]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 7]);
return ( * ef2)( lf_AUX_Make_Assign_Conds_C7_1( cons( make_list( tmp[ 6]) , make_list( tmp[ 10]))) , tmp[ 9]);
}
}
}
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
}
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_Make_Assign_Conds_C7_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Make_Assign_Conds_C7_1( aterm * arg0) {
PROF( prof_lf_AUX_Make_Assign_Conds_C7_1);
return make_nf1( lf_AUX_Make_Assign_Conds_C7_1sym , arg0);
}

