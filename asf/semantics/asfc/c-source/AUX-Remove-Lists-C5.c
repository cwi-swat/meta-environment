#include "support.h"
static asymbol * lf_AUX_Remove_Lists_C5_2sym;
static aterm * lf_AUX_Remove_Lists_C5_2( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Remove_Lists_C5_1sym;
static aterm * lf_AUX_Remove_Lists_C5_1( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_Remove_Lists_C5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_C5_2sym= TmkSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-listvars-from-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Remove_Lists_C5_1sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_Remove_Lists_C5_1 , lf_AUX_Remove_Lists_C5_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-listvars-from-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C5_2 , lf_AUX_Remove_Lists_C5_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf3 , lf3sym);
}
void resolve_AUX_Remove_Lists_C5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-listvars-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-listvars-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[sort(\"FuncDefList\"),w(\"\"),ql(\"++_ss\"),w(\"\"),sort(\"FuncDefList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_C5_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[17];
PROF( prof_lf_AUX_Remove_Lists_C5_2);
if( check_sym( arg0 , lf_AUX_Remove_Lists_C5_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
t_protect( tmp[ 0]);
t_protect( arg1);
tmp[ 2]= ( * ef2)( tmp[ 0] , arg1);
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_Remove_Lists_C5_1sym)) {
tmp[ 7]= arg_0( tmp[ 4]);
t_protect( tmp[ 1]);
t_protect( tmp[ 5]);
tmp[ 8]= lf_AUX_Remove_Lists_C5_2( lf_AUX_Remove_Lists_C5_1( make_list( tmp[ 1])) , tmp[ 5]);
if( check_sym( tmp[ 8] , ef1sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
tmp[ 11]= arg_2( tmp[ 8]);
if( check_sym( tmp[ 9] , lf3sym)) {
tmp[ 12]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 10] , lf_AUX_Remove_Lists_C5_1sym)) {
tmp[ 13]= arg_0( tmp[ 10]);
t_protect( tmp[ 6]);
t_protect( tmp[ 12]);
tmp[ 14]= ( * ef3)( ( * ef4)( lf3( make_list( tmp[ 6]))) , ( * ef4)( lf3( make_list( tmp[ 12]))));
if( check_sym( tmp[ 14] , ef4sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 15] , lf3sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
t_protect( tmp[ 16]);
t_protect( tmp[ 7]);
t_protect( tmp[ 13]);
t_protect( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 14]);
return ( * ef1)( lf3( make_list( tmp[ 16])) , lf_AUX_Remove_Lists_C5_1( cons( make_list( tmp[ 7]) , make_list( tmp[ 13]))) , tmp[ 11]);
}
}
t_unprotect( tmp[ 14]);
}
}
}
t_unprotect( tmp[ 8]);
}
}
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
return ( * ef1)( lf3( make_list( null( ))) , lf_AUX_Remove_Lists_C5_1( make_list( null( ))) , arg1);
}
}
}
return make_nf2( lf_AUX_Remove_Lists_C5_2sym , arg0 , arg1);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf_AUX_Remove_Lists_C5_1( aterm * arg0) {
PROF( prof_lf_AUX_Remove_Lists_C5_1);
return make_nf1( lf_AUX_Remove_Lists_C5_1sym , arg0);
}

