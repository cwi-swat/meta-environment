#include "support.h"
static asymbol * lf_AUX_C_Basics1_2sym;
static aterm * lf_AUX_C_Basics1_2( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_C_Basics1_1sym;
static aterm * lf_AUX_C_Basics1_1( aterm * arg1);
void register_AUX_C_Basics1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics1_2sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[l(\"remove-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , SYM_STRING);
lf_AUX_C_Basics1_1sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_C_Basics1_1 , lf_AUX_C_Basics1_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"remove-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics1_2 , lf_AUX_C_Basics1_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"SigArg\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_C_Basics1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_C_Basics1_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[8];
PROF( prof_lf_AUX_C_Basics1_2);
if( check_sym( arg1 , lf_AUX_C_Basics1_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_not_empty_list( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
{
tmp[ 1]= m_list_tail( atmp10);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
if( m_term_equal( arg0 , tmp[ 2])) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf_AUX_C_Basics1_1( make_list( tmp[ 1])));
}
else {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 3]= lf_AUX_C_Basics1_2( arg0 , lf_AUX_C_Basics1_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 3] , ef1sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_C_Basics1_1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
t_protect( tmp[ 2]);
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 3]);
return ( * ef1)( lf_AUX_C_Basics1_1( cons( make_list( ( * ef2)( tmp[ 2])) , make_list( tmp[ 5]))));
}
}
t_unprotect( tmp[ 3]);
}
}
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 4])) {
if( m_term_equal( arg0 , tmp[ 2])) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf_AUX_C_Basics1_1( make_list( tmp[ 1])));
}
else {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 5]= lf_AUX_C_Basics1_2( arg0 , lf_AUX_C_Basics1_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 5] , ef1sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf_AUX_C_Basics1_1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
t_protect( tmp[ 2]);
t_protect( tmp[ 4]);
t_protect( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 5]);
return ( * ef1)( lf_AUX_C_Basics1_1( cons( make_list( ( * ef3)( tmp[ 2] , lf3( make_list( tmp[ 4])))) , make_list( tmp[ 7]))));
}
}
t_unprotect( tmp[ 5]);
}
}
}
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf_AUX_C_Basics1_1( make_list( null( ))));
}
}
}
return make_nf2( lf_AUX_C_Basics1_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_C_Basics1_1( aterm * arg0) {
PROF( prof_lf_AUX_C_Basics1_1);
return make_nf1( lf_AUX_C_Basics1_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

