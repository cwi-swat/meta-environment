#include "support.h"
static asymbol * lf_AUX_Remove_Lists_C8_1sym;
static aterm * lf_AUX_Remove_Lists_C8_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
void register_AUX_Remove_Lists_C8( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_C8_1sym= TmkSymbol( "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_C8_1 , lf_AUX_Remove_Lists_C8_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Rule\"),ql(\";\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf5 , lf5sym);
}
void resolve_AUX_Remove_Lists_C8( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-simple-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-C\"),w(\"\"),[l(\"rem-lists-from-simple-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncRuleTuple\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_C8_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[11];
PROF( prof_lf_AUX_Remove_Lists_C8_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
t_protect( atmp01);
t_protect( arg1);
tmp[ 0]= ( * ef3)( ( * ef4)( ) , ( * ef5)( atmp00 , atmp01) , arg1);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , lf2sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( m_is_single_element( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_protect( tmp[ 6]);
tmp[ 7]= ( * ef6)( tmp[ 6]);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
return ( * ef2)( lf2( make_list( tmp[ 4])) , lf3( make_list( tmp[ 7])) , arg1);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg0 , ef7sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef8sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf4sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
{
aterm * atmp02= arg_2( arg0);
if( m_not_empty_list( atmp0000)) {
if( check_sym( atmp01 , ef9sym)) {
tmp[ 0]= arg_0( atmp01);
tmp[ 1]= arg_1( atmp01);
if( check_sym( tmp[ 1] , lf5sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( atmp0000);
t_protect( atmp01);
t_protect( atmp02);
t_protect( arg1);
tmp[ 3]= ( * ef3)( ( * ef4)( ) , ( * ef10)( ( * ef8)( lf4( make_list( atmp0000))) , atmp01 , atmp02) , arg1);
if( check_sym( tmp[ 3] , ef2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
tmp[ 5]= arg_1( tmp[ 3]);
tmp[ 6]= arg_2( tmp[ 3]);
if( check_sym( tmp[ 4] , lf2sym)) {
tmp[ 7]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 8]= arg_0( tmp[ 5]);
if( m_is_single_element( tmp[ 8])) {
tmp[ 9]= m_list_head( tmp[ 8]);
t_protect( tmp[ 9]);
tmp[ 10]= ( * ef6)( tmp[ 9]);
t_protect( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 9]);
return ( * ef2)( lf2( make_list( tmp[ 7])) , lf3( make_list( tmp[ 10])) , arg1);
}
}
}
}
t_unprotect( tmp[ 3]);
}
}
}
}
}
}
}
}
}
}
}
}
return make_nf2( lf_AUX_Remove_Lists_C8_1sym , arg0 , arg1);
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
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

