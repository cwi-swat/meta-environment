#include "support.h"
static asymbol * lf_AUX_Literals1_1sym;
static aterm * lf_AUX_Literals1_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Literals1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Literals1_1sym= TmkSymbol( "prod(id(\"Literals\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Literals\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))") , lf_AUX_Literals1_1 , lf_AUX_Literals1_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Literals1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Literals1_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[4];
PROF( prof_lf_AUX_Literals1_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( m_not_empty_list( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 34))) {
tmp[ 0]= m_list_tail( atmp000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
tmp[ 1]= list_prefix( tmp[ 0]);
t_protect( tmp[ 0]);
if( term_equal( list_last( tmp[ 0]) , make_char( 34))) {
if( m_not_empty_list( atmp100)) {
t_protect( atmp100);
if( term_equal( list_head( atmp100) , make_char( 34))) {
tmp[ 2]= m_list_tail( atmp100);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= list_prefix( tmp[ 2]);
t_protect( tmp[ 2]);
if( term_equal( list_last( tmp[ 2]) , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
return ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 1]) , cons( make_list( tmp[ 3]) , make_list( make_char( 34)))))));
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
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
}
}
}
}
}
return make_nf2( lf_AUX_Literals1_1sym , arg0 , arg1);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

