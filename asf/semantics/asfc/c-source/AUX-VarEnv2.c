#include "support.h"
static asymbol * lf_AUX_VarEnv2_1sym;
static aterm * lf_AUX_VarEnv2_1( aterm * arg1 , aterm * arg2);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_VarEnv2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_VarEnv2_1sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[l(\"vv-enter\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"VV-Pair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"vv-enter\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv2_1 , lf_AUX_VarEnv2_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"VV-Pair\"),ql(\",\"))") , lf2 , lf2sym);
}
void resolve_AUX_VarEnv2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntVVarEnv\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Struct\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"VarId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VV-Pair\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_VarEnv2_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[10];
PROF( prof_lf_AUX_VarEnv2_1);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , lf2sym)) {
{
aterm * atmp110= arg_0( atmp11);
t_protect( atmp110);
if( not_empty_list( atmp110)) {
t_protect( atmp110);
tmp[ 0]= list_head( atmp110);
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
t_protect( atmp110);
tmp[ 3]= list_tail( atmp110);
t_protect( arg0);
t_protect( tmp[ 1]);
if( ! term_equal( arg0 , tmp[ 1])) {
t_protect( arg0);
t_protect( atmp10);
t_protect( tmp[ 3]);
tmp[ 4]= lf_AUX_VarEnv2_1( arg0 , ( * ef1)( atmp10 , lf2( make_list( tmp[ 3]))));
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 6] , ef1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= arg_1( tmp[ 6]);
if( check_sym( tmp[ 8] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
t_protect( tmp[ 5]);
t_protect( tmp[ 7]);
t_protect( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 9]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
return ( * ef2)( tmp[ 5] , ( * ef1)( tmp[ 7] , lf2( cons( make_list( ( * ef4)( tmp[ 1] , tmp[ 2])) , make_list( tmp[ 9])))));
}
}
}
t_unprotect( tmp[ 4]);
}
else {
t_protect( tmp[ 2]);
t_protect( atmp10);
t_protect( tmp[ 2]);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef2)( tmp[ 2] , ( * ef1)( atmp10 , lf2( cons( make_list( ( * ef4)( arg0 , tmp[ 2])) , make_list( tmp[ 3])))));
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 0]);
}
else {
t_protect( atmp10);
tmp[ 0]= ( * ef5)( atmp10);
if( check_sym( tmp[ 0] , ef6sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef7sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( atmp10);
t_protect( tmp[ 2]);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef2)( tmp[ 2] , ( * ef1)( ( * ef3)( atmp10) , lf2( make_list( ( * ef4)( arg0 , tmp[ 2])))));
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
return make_nf2( lf_AUX_VarEnv2_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

