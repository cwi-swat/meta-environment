#include "support.h"
static asymbol * lf_AUX_RenameVars4_2sym;
static aterm * lf_AUX_RenameVars4_2( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_RenameVars4_1sym;
static aterm * lf_AUX_RenameVars4_1( aterm * arg1);
void register_AUX_RenameVars4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_RenameVars4_2sym= TmkSymbol( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_RenameVars4_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_RenameVars4_1 , lf_AUX_RenameVars4_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)") , lf_AUX_RenameVars4_2 , lf_AUX_RenameVars4_2sym);
}
void resolve_AUX_RenameVars4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVEs\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TIVE\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_RenameVars4_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[9];
PROF( prof_lf_AUX_RenameVars4_2);
if( check_sym( arg0 , lf_AUX_RenameVars4_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 1]= ( * ef2)( tmp[ 0] , arg1);
if( check_sym( tmp[ 1] , ef3sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef1)( lf_AUX_RenameVars4_1( make_list( tmp[ 2])) , tmp[ 3]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 2]= ( * ef2)( tmp[ 0] , arg1);
if( check_sym( tmp[ 2] , ef3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
t_protect( tmp[ 1]);
t_protect( tmp[ 4]);
tmp[ 5]= lf_AUX_RenameVars4_2( lf_AUX_RenameVars4_1( make_list( tmp[ 1])) , tmp[ 4]);
if( check_sym( tmp[ 5] , ef1sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
tmp[ 7]= arg_1( tmp[ 5]);
if( check_sym( tmp[ 6] , lf_AUX_RenameVars4_1sym)) {
tmp[ 8]= arg_0( tmp[ 6]);
if( m_not_empty_list( tmp[ 8])) {
t_protect( tmp[ 3]);
t_protect( tmp[ 8]);
t_protect( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 5]);
return ( * ef1)( lf_AUX_RenameVars4_1( cons( make_list( tmp[ 3]) , make_list( tmp[ 8]))) , tmp[ 7]);
}
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_RenameVars4_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_RenameVars4_1( aterm * arg0) {
PROF( prof_lf_AUX_RenameVars4_1);
return make_nf1( lf_AUX_RenameVars4_1sym , arg0);
}

