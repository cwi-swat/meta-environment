#include "support.h"
static asymbol * lf_AUX_Remove_Lists_C6_1sym;
static aterm * lf_AUX_Remove_Lists_C6_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_Remove_Lists_C6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_C6_1sym= TmkSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-listvars-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-listvars-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C6_1 , lf_AUX_Remove_Lists_C6_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf3 , lf3sym);
}
void resolve_AUX_Remove_Lists_C6( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"rule-contains-list-vars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"rule-contains-list-vars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-simple-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-simple-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_C6_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[7];
PROF( prof_lf_AUX_Remove_Lists_C6_1);
t_protect( arg0);
tmp[ 0]= ( * ef2)( arg0);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , ( * ef3)( ))) {
t_protect( arg0);
tmp[ 1]= ( * ef4)( arg0);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( null( ))) , lf3( make_list( tmp[ 1])) , arg1);
}
tmp[ 1]= ( * ef6)( );
if( m_term_equal( tmp[ 0] , tmp[ 1])) {
t_protect( arg0);
tmp[ 2]= ( * ef7)( arg0);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef6)( ))) {
t_protect( arg0);
tmp[ 3]= ( * ef8)( lf3( make_list( arg0)));
if( check_sym( tmp[ 3] , ef9sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( m_is_single_element( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef10)( tmp[ 6] , arg1);
}
}
}
t_unprotect( tmp[ 3]);
}
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , ( * ef3)( ))) {
t_protect( arg0);
tmp[ 3]= ( * ef8)( lf3( make_list( arg0)));
if( check_sym( tmp[ 3] , ef9sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( m_is_single_element( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
return ( * ef5)( ( * ef3)( ) , tmp[ 6] , arg1);
}
}
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
return make_nf2( lf_AUX_Remove_Lists_C6_1sym , arg0 , arg1);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

