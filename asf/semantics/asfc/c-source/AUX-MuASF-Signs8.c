#include "support.h"
static asymbol * lf_AUX_MuASF_Signs8_1sym;
static aterm * lf_AUX_MuASF_Signs8_1( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
void register_AUX_MuASF_Signs8( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Signs8_1sym= TmkSymbol( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"make-external-funcdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Signs8_1 , lf_AUX_MuASF_Signs8_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"SigArg\"),ql(\",\"))") , lf4 , lf4sym);
}
void resolve_AUX_MuASF_Signs8( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"{\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Props\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\"),w(\"\"),sort(\"Props\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"_\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SigArg\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"_\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SigArg\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Signs8_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[20];
PROF( prof_lf_AUX_MuASF_Signs8_1);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( m_not_empty_list( atmp100)) {
tmp[ 0]= m_list_head( atmp100);
tmp[ 1]= m_list_tail( atmp100);
if( m_not_empty_list( tmp[ 1])) {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 2]= lf_AUX_MuASF_Signs8_1( arg0 , ( * ef1)( lf2( make_list( tmp[ 1]))));
if( check_sym( tmp[ 2] , ef6sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
tmp[ 5]= arg_2( tmp[ 2]);
if( check_sym( tmp[ 4] , lf4sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , ef3sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 7] , lf2sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( m_not_empty_list( tmp[ 6])) {
if( m_is_single_element( tmp[ 8])) {
tmp[ 9]= m_list_head( tmp[ 8]);
if( check_sym( tmp[ 9] , ef4sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 10] , ef5sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf3sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 101))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 120))) {
tmp[ 14]= m_list_tail( tmp[ 13]);
if( m_not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 116))) {
tmp[ 15]= m_list_tail( tmp[ 14]);
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
if( term_equal( list_head( tmp[ 15]) , make_char( 101))) {
tmp[ 16]= m_list_tail( tmp[ 15]);
if( m_not_empty_list( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 114))) {
tmp[ 17]= m_list_tail( tmp[ 16]);
if( m_not_empty_list( tmp[ 17])) {
t_protect( tmp[ 17]);
if( term_equal( list_head( tmp[ 17]) , make_char( 110))) {
tmp[ 18]= m_list_tail( tmp[ 17]);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 97))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_is_single_element( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 108))) {
t_protect( tmp[ 3]);
t_protect( tmp[ 6]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
return ( * ef6)( tmp[ 3] , lf4( cons( make_list( ( * ef7)( )) , make_list( tmp[ 6]))) , ( * ef3)( lf2( make_list( ( * ef4)( ( * ef5)( lf3( cons( make_list( make_char( 101)) , cons( make_list( make_char( 120)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))));
}
}
t_unprotect( tmp[ 19]);
}
}
t_unprotect( tmp[ 18]);
}
}
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 16]);
}
}
t_unprotect( tmp[ 15]);
}
}
t_unprotect( tmp[ 14]);
}
}
t_unprotect( tmp[ 13]);
}
}
}
}
}
t_unprotect( tmp[ 9]);
}
}
}
}
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg1);
return ( * ef2)( arg0 , ( * ef3)( lf2( make_list( ( * ef4)( ( * ef5)( lf3( cons( make_list( make_char( 101)) , cons( make_list( make_char( 120)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))));
}
if( m_is_single_element( atmp100)) {
tmp[ 0]= m_list_head( atmp100);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef6)( arg0 , lf4( make_list( ( * ef7)( ))) , ( * ef3)( lf2( make_list( ( * ef4)( ( * ef5)( lf3( cons( make_list( make_char( 101)) , cons( make_list( make_char( 120)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))));
}
}
}
}
}
return make_nf2( lf_AUX_MuASF_Signs8_1sym , arg0 , arg1);
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

