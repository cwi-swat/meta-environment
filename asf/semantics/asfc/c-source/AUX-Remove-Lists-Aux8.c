#include "support.h"
static asymbol * lf_AUX_Remove_Lists_Aux8_1sym;
static aterm * lf_AUX_Remove_Lists_Aux8_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Remove_Lists_Aux8( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Remove_Lists_Aux8_1sym= TmkSymbol( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_Aux8_1 , lf_AUX_Remove_Lists_Aux8_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf2 , lf2sym);
}
void resolve_AUX_Remove_Lists_Aux8( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-internal-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-internal-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"remove-list-cons-from-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Remove_Lists_Aux8_1( aterm * arg0) {
{
aterm * tmp[6];
PROF( prof_lf_AUX_Remove_Lists_Aux8_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
tmp[ 0]= ( * ef2)( ( * ef3)( atmp00));
t_protect( tmp[ 0]);
t_protect( atmp00);
tmp[ 1]= ( * ef4)( tmp[ 0] , atmp00);
t_protect( tmp[ 0]);
t_protect( atmp01);
tmp[ 2]= ( * ef4)( tmp[ 0] , atmp01);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( tmp[ 1] , tmp[ 2]);
}
}
}
if( check_sym( arg0 , ef5sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
tmp[ 0]= ( * ef2)( ( * ef3)( atmp00));
t_protect( tmp[ 0]);
t_protect( atmp00);
tmp[ 1]= ( * ef4)( tmp[ 0] , atmp00);
t_protect( tmp[ 0]);
t_protect( atmp01);
tmp[ 2]= ( * ef4)( tmp[ 0] , atmp01);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef5)( tmp[ 1] , tmp[ 2]);
}
}
}
if( check_sym( arg0 , ef6sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef7sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
{
aterm * atmp02= arg_2( arg0);
if( m_not_empty_list( atmp0000)) {
t_protect( atmp01);
tmp[ 0]= ( * ef2)( ( * ef3)( atmp01));
t_protect( tmp[ 0]);
t_protect( atmp01);
tmp[ 1]= ( * ef4)( tmp[ 0] , atmp01);
t_protect( tmp[ 0]);
t_protect( atmp02);
tmp[ 2]= ( * ef4)( tmp[ 0] , atmp02);
t_protect( atmp0000);
tmp[ 3]= ( * ef8)( lf2( make_list( atmp0000)));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return ( * ef6)( ( * ef7)( lf2( make_list( tmp[ 5]))) , tmp[ 1] , tmp[ 2]);
}
}
}
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
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
if( check_sym( arg0 , ef9sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef7sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
{
aterm * atmp02= arg_2( arg0);
if( m_not_empty_list( atmp0000)) {
t_protect( atmp01);
tmp[ 0]= ( * ef2)( ( * ef3)( atmp01));
t_protect( tmp[ 0]);
t_protect( atmp01);
tmp[ 1]= ( * ef4)( tmp[ 0] , atmp01);
t_protect( tmp[ 0]);
t_protect( atmp02);
tmp[ 2]= ( * ef4)( tmp[ 0] , atmp02);
t_protect( atmp0000);
tmp[ 3]= ( * ef8)( lf2( make_list( atmp0000)));
if( check_sym( tmp[ 3] , ef7sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return ( * ef9)( ( * ef7)( lf2( make_list( tmp[ 5]))) , tmp[ 1] , tmp[ 2]);
}
}
}
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
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
return make_nf1( lf_AUX_Remove_Lists_Aux8_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

