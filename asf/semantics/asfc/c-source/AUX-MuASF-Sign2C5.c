#include "support.h"
static asymbol * lf_AUX_MuASF_Sign2C5_2sym;
static aterm * lf_AUX_MuASF_Sign2C5_2( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_MuASF_Sign2C5_1sym;
static aterm * lf_AUX_MuASF_Sign2C5_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_MuASF_Sign2C5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Sign2C5_2sym= TmkSymbol( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2idterms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_MuASF_Sign2C5_1sym= TmkSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"SigArg\"),ql(\",\"))") , lf_AUX_MuASF_Sign2C5_1 , lf_AUX_MuASF_Sign2C5_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"sigargs2idterms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Sign2C5_2 , lf_AUX_MuASF_Sign2C5_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_MuASF_Sign2C5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Sign2C5_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[8];
PROF( prof_lf_AUX_MuASF_Sign2C5_2);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf3sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C5_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_is_single_element( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
t_protect( atmp000);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
return ( * ef2)( lf3( cons( make_list( make_char( 34)) , cons( make_list( atmp000) , cons( make_list( make_char( 40)) , cons( make_list( make_char( 60)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 62)) , cons( make_list( make_char( 41)) , make_list( make_char( 34))))))))))))));
}
}
}
}
}
}
}
if( check_sym( arg1 , lf_AUX_MuASF_Sign2C5_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_not_empty_list( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
tmp[ 1]= m_list_tail( atmp10);
if( m_not_empty_list( tmp[ 1])) {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 2]= lf_AUX_MuASF_Sign2C5_2( arg0 , lf_AUX_MuASF_Sign2C5_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 2] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 34))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
t_protect( tmp[ 5]);
tmp[ 6]= list_prefix( tmp[ 5]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_last( tmp[ 5]) , make_char( 34))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_prefix( tmp[ 6]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_last( tmp[ 6]) , make_char( 41))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
return ( * ef2)( lf3( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 7]) , cons( make_list( make_char( 44)) , cons( make_list( make_char( 60)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 62)) , cons( make_list( make_char( 41)) , make_list( make_char( 34))))))))))))));
}
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 5]);
}
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
return make_nf2( lf_AUX_MuASF_Sign2C5_2sym , arg0 , arg1);
}
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf_AUX_MuASF_Sign2C5_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Sign2C5_1);
return make_nf1( lf_AUX_MuASF_Sign2C5_1sym , arg0);
}

