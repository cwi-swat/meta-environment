#include "support.h"
static asymbol * lf_AUX_MuASF_Basics18_1sym;
static aterm * lf_AUX_MuASF_Basics18_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_MuASF_Basics18( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics18_1sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"remove-trans-from-list-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"remove-trans-from-list-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics18_1 , lf_AUX_MuASF_Basics18_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Basics18( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Basics18_1( aterm * arg0) {
{
aterm * tmp[13];
PROF( prof_lf_AUX_MuASF_Basics18_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( m_not_empty_list( atmp000)) {
tmp[ 0]= m_list_head( atmp000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 34))) {
tmp[ 1]= m_list_tail( atmp000);
{
if( m_not_empty_list( tmp[ 1])) {
tmp[ 2]= m_list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 123))) {
tmp[ 3]= m_list_tail( tmp[ 1]);
{
t_protect( tmp[ 3]);
tmp[ 4]= list_prefix( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 5]= list_last( tmp[ 3]);
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , make_char( 34))) {
t_protect( tmp[ 4]);
tmp[ 6]= list_prefix( tmp[ 4]);
if( m_not_empty_list( tmp[ 6])) {
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_last( tmp[ 4]) , make_char( 125))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 123)) , cons( make_list( tmp[ 6]) , cons( make_list( make_char( 125)) , make_list( make_char( 34))))))));
}
}
}
t_unprotect( tmp[ 6]);
}
t_protect( tmp[ 5]);
if( term_equal( tmp[ 5] , make_char( 115))) {
t_protect( tmp[ 4]);
tmp[ 6]= list_prefix( tmp[ 4]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_last( tmp[ 4]) , make_char( 110))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_prefix( tmp[ 6]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_last( tmp[ 6]) , make_char( 97))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_prefix( tmp[ 7]);
if( m_not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_last( tmp[ 7]) , make_char( 114))) {
t_protect( tmp[ 8]);
tmp[ 9]= list_prefix( tmp[ 8]);
if( m_not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_last( tmp[ 8]) , make_char( 116))) {
t_protect( tmp[ 9]);
tmp[ 10]= list_prefix( tmp[ 9]);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_last( tmp[ 9]) , make_char( 45))) {
t_protect( tmp[ 10]);
tmp[ 11]= list_prefix( tmp[ 10]);
if( m_not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_last( tmp[ 10]) , make_char( 34))) {
t_protect( tmp[ 11]);
tmp[ 12]= list_prefix( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_last( tmp[ 11]) , make_char( 125))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
return ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 123)) , cons( make_list( tmp[ 12]) , cons( make_list( make_char( 125)) , make_list( make_char( 34))))))));
}
}
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 11]);
}
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
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
return make_nf1( lf_AUX_MuASF_Basics18_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

