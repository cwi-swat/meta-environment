#include "support.h"
static asymbol * lf_AUX_AsFix2muASFnames13_1sym;
static aterm * lf_AUX_AsFix2muASFnames13_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_AsFix2muASFnames13( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2muASFnames13_1sym= TmkSymbol( "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"upper2lower\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2muASFnames\"),w(\"\"),[l(\"upper2lower\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASFnames13_1 , lf_AUX_AsFix2muASFnames13_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_AsFix2muASFnames13( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFix2muASFnames13_1( aterm * arg0) {
{
aterm * tmp[9];
PROF( prof_lf_AUX_AsFix2muASFnames13_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( m_is_single_element( atmp000)) {
tmp[ 0]= m_list_head( atmp000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 67))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 99))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 68))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 100))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 69))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 101))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 70))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 102))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 71))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 103))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 72))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 104))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 73))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 105))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 74))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 106))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 75))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 107))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 76))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 108))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 77))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 109))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 78))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 110))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 79))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 111))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 80))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 112))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 81))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 113))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 82))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 114))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 83))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 115))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 84))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 116))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 85))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 117))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 86))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 118))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 87))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 119))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 88))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 120))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 89))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 121))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 90))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 122))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 65))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 97))));
}
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 66))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
return ( * ef1)( lf2( make_list( make_char( 98))));
}
t_unprotect( tmp[ 0]);
}
if( m_not_empty_list( atmp000)) {
tmp[ 0]= m_list_head( atmp000);
tmp[ 1]= m_list_tail( atmp000);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 0]);
tmp[ 2]= lf_AUX_AsFix2muASFnames13_1( ( * ef1)( lf2( make_list( tmp[ 0]))));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( m_is_single_element( tmp[ 4])) {
tmp[ 5]= m_list_head( tmp[ 4]);
t_protect( tmp[ 1]);
tmp[ 6]= lf_AUX_AsFix2muASFnames13_1( ( * ef1)( lf2( make_list( tmp[ 1]))));
if( check_sym( tmp[ 6] , ef1sym)) {
tmp[ 7]= arg_0( tmp[ 6]);
if( check_sym( tmp[ 7] , lf2sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( m_not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 6]);
return ( * ef1)( lf2( cons( make_list( tmp[ 5]) , make_list( tmp[ 8]))));
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
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( m_is_single_element( atmp000)) {
tmp[ 0]= m_list_head( atmp000);
t_unprotect( arg0);
return ( * ef1)( lf2( make_list( tmp[ 0])));
}
}
}
}
}
return make_nf1( lf_AUX_AsFix2muASFnames13_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

