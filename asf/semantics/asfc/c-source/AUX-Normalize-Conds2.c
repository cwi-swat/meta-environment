#include "support.h"
static asymbol * lf_AUX_Normalize_Conds2_1sym;
static aterm * lf_AUX_Normalize_Conds2_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
void register_AUX_Normalize_Conds2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Normalize_Conds2_1sym= TmkSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds2_1 , lf_AUX_Normalize_Conds2_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
}
void resolve_AUX_Normalize_Conds2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-conditional-rule\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-conditional-rule\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-default-rule\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Rule\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"default:\"),w(\"\"),sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"CondList\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-list-in-conds\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TC-tuple\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"CondList\"),w(\"\"),ql(\"==>\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Rule\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Normalize_Conds2_1( aterm * arg0) {
{
aterm * tmp[13];
PROF( prof_lf_AUX_Normalize_Conds2_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
tmp[ 0]= ( * ef2)( atmp00 , ( * ef3)( lf2( make_list( make_char( 49)))));
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( m_is_single_element( tmp[ 4])) {
tmp[ 6]= m_list_head( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( atmp01);
tmp[ 7]= ( * ef5)( lf4( make_list( tmp[ 5])) , ( * ef6)( tmp[ 6] , atmp01));
t_protect( tmp[ 7]);
tmp[ 8]= ( * ef7)( tmp[ 7]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
return tmp[ 8];
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg0 , ef6sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
tmp[ 0]= ( * ef2)( atmp00 , ( * ef3)( lf2( make_list( make_char( 49)))));
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( m_is_single_element( tmp[ 4])) {
tmp[ 6]= m_list_head( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( atmp01);
tmp[ 7]= ( * ef5)( lf4( make_list( tmp[ 5])) , ( * ef6)( tmp[ 6] , atmp01));
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
return tmp[ 7];
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg0 , ef8sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef9sym)) {
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
t_protect( atmp01);
tmp[ 0]= ( * ef2)( atmp01 , ( * ef3)( lf2( make_list( make_char( 49)))));
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( m_is_single_element( tmp[ 4])) {
tmp[ 6]= m_list_head( tmp[ 4]);
t_protect( atmp0000);
t_protect( tmp[ 3]);
tmp[ 7]= ( * ef10)( lf4( make_list( atmp0000)) , tmp[ 3]);
if( check_sym( tmp[ 7] , ef4sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
tmp[ 10]= arg_2( tmp[ 7]);
if( check_sym( tmp[ 8] , lf3sym)) {
tmp[ 11]= arg_0( tmp[ 8]);
if( check_sym( tmp[ 9] , lf4sym)) {
tmp[ 12]= arg_0( tmp[ 9]);
t_protect( tmp[ 11]);
if( ! not_empty_list( tmp[ 11])) {
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 5]);
t_protect( tmp[ 12]);
t_protect( atmp02);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 7]);
return ( * ef8)( ( * ef9)( lf4( cons( make_list( tmp[ 5]) , make_list( tmp[ 12])))) , tmp[ 6] , atmp02);
}
}
}
}
}
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
}
}
}
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
if( check_sym( arg0 , ef11sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef9sym)) {
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
t_protect( atmp01);
tmp[ 0]= ( * ef2)( atmp01 , ( * ef3)( lf2( make_list( make_char( 49)))));
if( check_sym( tmp[ 0] , ef4sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
if( m_is_single_element( tmp[ 4])) {
tmp[ 6]= m_list_head( tmp[ 4]);
t_protect( atmp0000);
t_protect( tmp[ 3]);
tmp[ 7]= ( * ef10)( lf4( make_list( atmp0000)) , tmp[ 3]);
if( check_sym( tmp[ 7] , ef4sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
tmp[ 9]= arg_1( tmp[ 7]);
tmp[ 10]= arg_2( tmp[ 7]);
if( check_sym( tmp[ 8] , lf3sym)) {
tmp[ 11]= arg_0( tmp[ 8]);
if( check_sym( tmp[ 9] , lf4sym)) {
tmp[ 12]= arg_0( tmp[ 9]);
t_protect( tmp[ 11]);
if( ! not_empty_list( tmp[ 11])) {
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 5]);
t_protect( tmp[ 12]);
t_protect( atmp02);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 7]);
return ( * ef11)( ( * ef9)( lf4( cons( make_list( tmp[ 5]) , make_list( tmp[ 12])))) , tmp[ 6] , atmp02);
}
}
}
}
}
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 6]);
}
}
}
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
return make_nf1( lf_AUX_Normalize_Conds2_1sym , arg0);
}
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

