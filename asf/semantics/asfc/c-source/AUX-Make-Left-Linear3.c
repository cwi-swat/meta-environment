#include "support.h"
static asymbol * lf_AUX_Make_Left_Linear3_2sym;
static aterm * lf_AUX_Make_Left_Linear3_2( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Make_Left_Linear3_1sym;
static aterm * lf_AUX_Make_Left_Linear3_1( aterm * arg1);
void register_AUX_Make_Left_Linear3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Make_Left_Linear3_2sym= TmkSymbol( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Make_Left_Linear3_1sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_Make_Left_Linear3_1 , lf_AUX_Make_Left_Linear3_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Make_Left_Linear3_2 , lf_AUX_Make_Left_Linear3_2sym);
}
void resolve_AUX_Make_Left_Linear3( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Make_Left_Linear3_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[6];
PROF( prof_lf_AUX_Make_Left_Linear3_2);
if( check_sym( arg0 , lf_AUX_Make_Left_Linear3_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 1]= ( * ef2)( tmp[ 0] , arg1);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf_AUX_Make_Left_Linear3_1( make_list( tmp[ 1])));
}
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 2]= ( * ef2)( tmp[ 0] , arg1);
t_protect( tmp[ 1]);
t_protect( arg1);
tmp[ 3]= lf_AUX_Make_Left_Linear3_2( lf_AUX_Make_Left_Linear3_1( make_list( tmp[ 1])) , arg1);
if( check_sym( tmp[ 3] , ef1sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_Make_Left_Linear3_1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 3]);
return ( * ef1)( lf_AUX_Make_Left_Linear3_1( cons( make_list( tmp[ 2]) , make_list( tmp[ 5]))));
}
}
}
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_Make_Left_Linear3_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Make_Left_Linear3_1( aterm * arg0) {
PROF( prof_lf_AUX_Make_Left_Linear3_1);
return make_nf1( lf_AUX_Make_Left_Linear3_1sym , arg0);
}

