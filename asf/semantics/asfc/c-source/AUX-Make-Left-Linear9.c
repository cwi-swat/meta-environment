#include "support.h"
static asymbol * lf_AUX_Make_Left_Linear9_1sym;
static aterm * lf_AUX_Make_Left_Linear9_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Make_Left_Linear9( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Make_Left_Linear9_1sym= TmkSymbol( "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Cond\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)") , lf_AUX_Make_Left_Linear9_1 , lf_AUX_Make_Left_Linear9_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_Make_Left_Linear9( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CList-VarEnv\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Make-Left-Linear\"),w(\"\"),[l(\"make-l-l-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term-CList-VarEnv\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Make_Left_Linear9_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[7];
PROF( prof_lf_AUX_Make_Left_Linear9_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp01);
t_protect( arg1);
t_protect( arg2);
tmp[ 0]= ( * ef3)( atmp01 , arg1 , arg2);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( m_is_single_element( tmp[ 4])) {
tmp[ 6]= m_list_head( tmp[ 4]);
t_protect( atmp00);
t_protect( tmp[ 5]);
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
return ( * ef2)( lf2( cons( make_list( ( * ef1)( atmp00 , tmp[ 6])) , make_list( tmp[ 5]))) , tmp[ 3]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
return make_nf3( lf_AUX_Make_Left_Linear9_1sym , arg0 , arg1 , arg2);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

