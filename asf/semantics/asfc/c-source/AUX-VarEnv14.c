#include "support.h"
static asymbol * lf_AUX_VarEnv14_1sym;
static aterm * lf_AUX_VarEnv14_1( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_VarEnv14( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_VarEnv14_1sym= TmkSymbol( "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"nt-lookup\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv14_1 , lf_AUX_VarEnv14_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_VarEnv14( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NameTable\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"NameTable\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IdTablePair\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"FunId\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"NamePair\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_VarEnv14_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[12];
PROF( prof_lf_AUX_VarEnv14_1);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef2sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , lf3sym)) {
{
aterm * atmp1100= arg_0( atmp110);
{
aterm * atmp12= arg_2( arg1);
{
aterm * atmp13= arg_3( arg1);
t_protect( atmp100);
if( ! not_empty_list( atmp100)) {
if( check_sym( atmp12 , ef6sym)) {
tmp[ 0]= arg_0( atmp12);
if( check_sym( tmp[ 0] , lf3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
t_protect( atmp1100);
t_protect( tmp[ 1]);
t_protect( atmp1100);
t_protect( tmp[ 1]);
t_protect( atmp1100);
t_protect( atmp12);
t_protect( atmp13);
t_unprotect( arg1);
return ( * ef3)( ( * ef2)( lf3( cons( make_list( atmp1100) , make_list( tmp[ 1])))) , ( * ef1)( lf2( make_list( ( * ef4)( arg0 , ( * ef2)( lf3( cons( make_list( atmp1100) , make_list( tmp[ 1]))))))) , ( * ef2)( lf3( make_list( atmp1100))) , ( * ef5)( atmp12) , atmp13));
}
}
}
}
}
}
}
}
}
{
aterm * atmp11= arg_1( arg1);
{
aterm * atmp12= arg_2( arg1);
{
aterm * atmp13= arg_3( arg1);
if( m_not_empty_list( atmp100)) {
tmp[ 0]= m_list_head( atmp100);
{
tmp[ 1]= m_list_tail( atmp100);
{
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
t_protect( arg0);
t_protect( tmp[ 2]);
if( ! term_equal( arg0 , tmp[ 2])) {
t_protect( arg0);
t_protect( tmp[ 1]);
t_protect( atmp11);
t_protect( atmp12);
t_protect( atmp13);
tmp[ 4]= lf_AUX_VarEnv14_1( arg0 , ( * ef1)( lf2( make_list( tmp[ 1])) , atmp11 , atmp12 , atmp13));
if( check_sym( tmp[ 4] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 6] , ef1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= arg_1( tmp[ 6]);
tmp[ 9]= arg_2( tmp[ 6]);
tmp[ 10]= arg_3( tmp[ 6]);
if( check_sym( tmp[ 7] , lf2sym)) {
tmp[ 11]= arg_0( tmp[ 7]);
t_protect( tmp[ 5]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
t_protect( tmp[ 11]);
t_protect( tmp[ 8]);
t_protect( tmp[ 9]);
t_protect( tmp[ 10]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 4]);
return ( * ef3)( tmp[ 5] , ( * ef1)( lf2( cons( make_list( ( * ef4)( tmp[ 2] , tmp[ 3])) , make_list( tmp[ 11]))) , tmp[ 8] , tmp[ 9] , tmp[ 10]));
}
}
}
t_unprotect( tmp[ 4]);
}
else {
t_protect( tmp[ 3]);
t_protect( tmp[ 3]);
t_protect( atmp11);
t_protect( atmp12);
t_protect( atmp13);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef3)( tmp[ 3] , ( * ef1)( lf2( cons( make_list( ( * ef4)( arg0 , tmp[ 3])) , make_list( tmp[ 1]))) , atmp11 , atmp12 , atmp13));
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
}
}
}
return make_nf2( lf_AUX_VarEnv14_1sym , arg0 , arg1);
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

