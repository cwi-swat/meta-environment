#include "support.h"
static asymbol * lf_AUX_Check_List_Pats9_1sym;
static aterm * lf_AUX_Check_List_Pats9_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef5sym;
static funcptr ef5;
void register_AUX_Check_List_Pats9( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Check_List_Pats9_1sym= TmkSymbol( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"is-list-list-elem-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"is-list-list-elem-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Check_List_Pats9_1 , lf_AUX_Check_List_Pats9_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_Check_List_Pats9( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Check_List_Pats9_1( aterm * arg0) {
{
aterm * tmp[28];
PROF( prof_lf_AUX_Check_List_Pats9_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , lf2sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf3sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( m_not_empty_list( atmp0000)) {
t_protect( atmp0000);
if( term_equal( list_head( atmp0000) , make_char( 99))) {
tmp[ 0]= m_list_tail( atmp0000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 111))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 110))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_is_single_element( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 115))) {
if( m_not_empty_list( atmp010)) {
tmp[ 3]= m_list_head( atmp010);
tmp[ 4]= m_list_tail( atmp010);
if( m_is_single_element( tmp[ 4])) {
tmp[ 5]= m_list_head( tmp[ 4]);
if( check_sym( tmp[ 5] , ef1sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
tmp[ 7]= arg_1( tmp[ 5]);
if( check_sym( tmp[ 6] , ef2sym)) {
tmp[ 8]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 8] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
if( check_sym( tmp[ 7] , lf3sym)) {
tmp[ 10]= arg_0( tmp[ 7]);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 99))) {
tmp[ 11]= m_list_tail( tmp[ 9]);
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 111))) {
tmp[ 12]= m_list_tail( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 110))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_is_single_element( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 115))) {
if( m_not_empty_list( tmp[ 10])) {
tmp[ 14]= m_list_head( tmp[ 10]);
tmp[ 15]= m_list_tail( tmp[ 10]);
if( m_is_single_element( tmp[ 15])) {
tmp[ 16]= m_list_head( tmp[ 15]);
if( check_sym( tmp[ 16] , ef1sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
tmp[ 18]= arg_1( tmp[ 16]);
if( check_sym( tmp[ 17] , ef2sym)) {
tmp[ 19]= arg_0( tmp[ 17]);
if( check_sym( tmp[ 19] , lf2sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
if( check_sym( tmp[ 18] , lf3sym)) {
tmp[ 21]= arg_0( tmp[ 18]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 99))) {
tmp[ 22]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 111))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 110))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_is_single_element( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 115))) {
if( m_not_empty_list( tmp[ 21])) {
tmp[ 25]= m_list_head( tmp[ 21]);
tmp[ 26]= m_list_tail( tmp[ 21]);
if( m_is_single_element( tmp[ 26])) {
tmp[ 27]= m_list_head( tmp[ 26]);
t_protect( tmp[ 3]);
if( term_equal( ( * ef4)( tmp[ 3]) , ( * ef3)( ))) {
t_protect( tmp[ 14]);
if( term_equal( ( * ef4)( tmp[ 14]) , ( * ef3)( ))) {
t_protect( tmp[ 25]);
if( term_equal( ( * ef4)( tmp[ 25]) , ( * ef5)( ))) {
t_protect( tmp[ 27]);
if( term_equal( ( * ef4)( tmp[ 27]) , ( * ef3)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
return ( * ef3)( );
}
}
}
}
t_unprotect( tmp[ 27]);
}
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 25]);
}
}
}
t_unprotect( tmp[ 24]);
}
}
t_unprotect( tmp[ 23]);
}
}
t_unprotect( tmp[ 22]);
}
}
}
}
}
}
t_unprotect( tmp[ 16]);
}
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 14]);
}
}
}
t_unprotect( tmp[ 13]);
}
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 11]);
}
}
}
}
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 3]);
}
}
}
t_unprotect( tmp[ 2]);
}
}
t_unprotect( tmp[ 1]);
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
}
}
t_unprotect( arg0);
return ( * ef5)( );
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

