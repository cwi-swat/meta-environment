#include "support.h"
static asymbol * lf_AUX_AsFix2muASF_C13_2sym;
static aterm * lf_AUX_AsFix2muASF_C13_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_AsFix2muASF_C13_1sym;
static aterm * lf_AUX_AsFix2muASF_C13_1( aterm * arg1);
void register_AUX_AsFix2muASF_C13( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFix2muASF_C13_2sym= TmkSymbol( "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-c-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_AsFix2muASF_C13_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_AsFix2muASF_C13_1 , lf_AUX_AsFix2muASF_C13_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"AsFix2muASF-C\"),w(\"\"),[l(\"make-c-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_AsFix2muASF_C13_2 , lf_AUX_AsFix2muASF_C13_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_AsFix2muASF_C13( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFix2muASF_C13_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[13];
PROF( prof_lf_AUX_AsFix2muASF_C13_2);
if( check_sym( arg0 , lf_AUX_AsFix2muASF_C13_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_AsFix2muASF_C13_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
t_protect( atmp10);
if( ! not_empty_list( atmp10)) {
t_unprotect( arg0);
t_unprotect( arg1);
return tmp[ 0];
}
if( m_is_single_element( atmp10)) {
tmp[ 1]= m_list_head( atmp10);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 4]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 4] , lf3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 3] , lf_AUX_AsFix2muASF_C13_1sym)) {
tmp[ 6]= arg_0( tmp[ 3]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 99))) {
tmp[ 7]= m_list_tail( tmp[ 5]);
if( m_not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 111))) {
tmp[ 8]= m_list_tail( tmp[ 7]);
if( m_not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 110))) {
tmp[ 9]= m_list_tail( tmp[ 8]);
if( m_is_single_element( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 115))) {
if( m_not_empty_list( tmp[ 6])) {
tmp[ 10]= m_list_head( tmp[ 6]);
tmp[ 11]= m_list_tail( tmp[ 6]);
if( m_is_single_element( tmp[ 11])) {
tmp[ 12]= m_list_head( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 11]);
return lf_AUX_AsFix2muASF_C13_2( lf_AUX_AsFix2muASF_C13_1( make_list( tmp[ 10])) , lf_AUX_AsFix2muASF_C13_1( make_list( ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf_AUX_AsFix2muASF_C13_1( cons( make_list( tmp[ 12]) , make_list( tmp[ 1])))))));
}
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 10]);
}
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
}
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
t_protect( atmp00);
if( ! not_empty_list( atmp00)) {
if( m_is_single_element( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return tmp[ 0];
}
}
}
}
}
}
if( check_sym( arg0 , lf_AUX_AsFix2muASF_C13_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_AsFix2muASF_C13_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_is_single_element( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
if( m_is_single_element( atmp10)) {
tmp[ 1]= m_list_head( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( ( * ef2)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf_AUX_AsFix2muASF_C13_1( cons( make_list( tmp[ 0]) , make_list( tmp[ 1]))));
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
return make_nf2( lf_AUX_AsFix2muASF_C13_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_AsFix2muASF_C13_1( aterm * arg0) {
PROF( prof_lf_AUX_AsFix2muASF_C13_1);
return make_nf1( lf_AUX_AsFix2muASF_C13_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

