#include "support.h"
static asymbol * lf_AUX_VarEnv17_2sym;
static aterm * lf_AUX_VarEnv17_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_VarEnv17_1sym;
static aterm * lf_AUX_VarEnv17_1( aterm * arg1);
void register_AUX_VarEnv17( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_VarEnv17_2sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[l(\"pn-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_VarEnv17_1sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_VarEnv17_1 , lf_AUX_VarEnv17_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"pn-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv17_2 , lf_AUX_VarEnv17_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_VarEnv17( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_VarEnv17_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[4];
PROF( prof_lf_AUX_VarEnv17_2);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf3sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , lf_AUX_VarEnv17_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp10);
if( ! not_empty_list( atmp10)) {
t_protect( atmp000);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf3( cons( make_list( make_char( 34)) , cons( make_list( atmp000) , make_list( make_char( 34))))));
}
}
}
}
}
}
}
if( check_sym( arg1 , lf_AUX_VarEnv17_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_not_empty_list( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
{
tmp[ 1]= m_list_tail( atmp10);
{
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
t_protect( arg0);
t_protect( tmp[ 2]);
if( ! term_equal( arg0 , tmp[ 2])) {
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return lf_AUX_VarEnv17_2( arg0 , lf_AUX_VarEnv17_1( make_list( tmp[ 1])));
}
else {
t_protect( tmp[ 3]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return tmp[ 3];
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_VarEnv17_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_VarEnv17_1( aterm * arg0) {
PROF( prof_lf_AUX_VarEnv17_1);
return make_nf1( lf_AUX_VarEnv17_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

