#include "support.h"
static asymbol * lf_AUX_Remove_Lists_C7_1sym;
static aterm * lf_AUX_Remove_Lists_C7_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_Remove_Lists_C7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_C7_1sym= TmkSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-simple-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-simple-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C7_1 , lf_AUX_Remove_Lists_C7_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf4 , lf4sym);
}
void resolve_AUX_Remove_Lists_C7( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-zero-or-one-list-vars-in-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"remove-simple-lists\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"remove-simple-lists\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-listvars-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-listvars-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"is-special-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"is-special-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[l(\"transform-special-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Set-Pats\"),w(\"\"),[l(\"transform-special-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_C7_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[16];
PROF( prof_lf_AUX_Remove_Lists_C7_1);
if( check_sym( arg0 , ef6sym)) {
t_protect( arg1);
tmp[ 0]= ( * ef7)( arg1);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , ( * ef3)( ))) {
t_protect( arg1);
tmp[ 1]= ( * ef8)( arg1 , ( * ef9)( lf4( make_list( make_char( 49)))));
if( check_sym( tmp[ 1] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
tmp[ 4]= arg_2( tmp[ 1]);
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
t_protect( tmp[ 6]);
tmp[ 7]= ( * ef10)( lf3( make_list( tmp[ 6])));
if( check_sym( tmp[ 7] , ef11sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( check_sym( tmp[ 8] , lf3sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
t_protect( tmp[ 9]);
t_protect( arg2);
tmp[ 10]= ( * ef12)( lf3( make_list( tmp[ 9])) , arg2);
if( check_sym( tmp[ 10] , ef1sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
tmp[ 12]= arg_1( tmp[ 10]);
tmp[ 13]= arg_2( tmp[ 10]);
if( check_sym( tmp[ 11] , lf2sym)) {
tmp[ 14]= arg_0( tmp[ 11]);
if( check_sym( tmp[ 12] , lf3sym)) {
tmp[ 15]= arg_0( tmp[ 12]);
t_protect( tmp[ 5]);
t_protect( tmp[ 14]);
t_protect( tmp[ 15]);
t_protect( tmp[ 13]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 10]);
return ( * ef1)( lf2( cons( make_list( tmp[ 5]) , make_list( tmp[ 14]))) , lf3( make_list( tmp[ 15])) , tmp[ 13]);
}
}
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 7]);
}
}
}
t_unprotect( tmp[ 1]);
}
if( m_term_equal( tmp[ 0] , arg0)) {
t_protect( arg1);
tmp[ 1]= ( * ef13)( arg1);
t_protect( arg1);
t_protect( tmp[ 1]);
if( ! term_equal( arg1 , tmp[ 1])) {
t_protect( tmp[ 1]);
tmp[ 2]= ( * ef10)( lf3( make_list( tmp[ 1])));
if( check_sym( tmp[ 2] , ef11sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( m_is_single_element( tmp[ 4])) {
tmp[ 5]= m_list_head( tmp[ 4]);
t_protect( arg0);
t_protect( tmp[ 5]);
t_protect( arg2);
tmp[ 6]= lf_AUX_Remove_Lists_C7_1( arg0 , tmp[ 5] , arg2);
if( check_sym( tmp[ 6] , ef1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
tmp[ 8]= arg_1( tmp[ 6]);
tmp[ 9]= arg_2( tmp[ 6]);
if( check_sym( tmp[ 7] , lf2sym)) {
tmp[ 10]= arg_0( tmp[ 7]);
if( check_sym( tmp[ 8] , lf3sym)) {
tmp[ 11]= arg_0( tmp[ 8]);
t_protect( tmp[ 10]);
t_protect( tmp[ 11]);
t_protect( tmp[ 9]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef1)( lf2( make_list( tmp[ 10])) , lf3( make_list( tmp[ 11])) , tmp[ 9]);
}
}
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
if( check_sym( arg0 , ef3sym)) {
t_protect( arg1);
tmp[ 0]= ( * ef13)( arg1);
t_protect( arg1);
t_protect( tmp[ 0]);
if( ! term_equal( arg1 , tmp[ 0])) {
t_protect( tmp[ 0]);
tmp[ 1]= ( * ef10)( lf3( make_list( tmp[ 0])));
if( check_sym( tmp[ 1] , ef11sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( m_is_single_element( tmp[ 3])) {
tmp[ 4]= m_list_head( tmp[ 3]);
t_protect( arg0);
t_protect( tmp[ 4]);
t_protect( arg2);
tmp[ 5]= lf_AUX_Remove_Lists_C7_1( arg0 , tmp[ 4] , arg2);
if( check_sym( tmp[ 5] , ef1sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
tmp[ 7]= arg_1( tmp[ 5]);
tmp[ 8]= arg_2( tmp[ 5]);
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , lf3sym)) {
tmp[ 10]= arg_0( tmp[ 7]);
t_protect( tmp[ 9]);
t_protect( tmp[ 10]);
t_protect( tmp[ 8]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( lf2( make_list( tmp[ 9])) , lf3( make_list( tmp[ 10])) , tmp[ 8]);
}
}
}
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 4]);
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
t_protect( arg1);
if( term_equal( ( * ef2)( arg1) , ( * ef3)( ))) {
t_protect( arg1);
tmp[ 0]= ( * ef4)( arg1);
t_protect( tmp[ 0]);
t_protect( arg2);
tmp[ 1]= ( * ef5)( tmp[ 0] , arg2);
if( check_sym( tmp[ 1] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
tmp[ 4]= arg_2( tmp[ 1]);
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef1)( lf2( make_list( tmp[ 5])) , lf3( make_list( tmp[ 6])) , tmp[ 4]);
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
t_unprotect( arg0);
return ( * ef1)( lf2( make_list( null( ))) , lf3( make_list( arg1)) , arg2);
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
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

