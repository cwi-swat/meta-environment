#include "support.h"
static asymbol * lf_AUX_Pure_C2_1sym;
static aterm * lf_AUX_Pure_C2_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
void register_AUX_Pure_C2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Pure_C2_1sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C2_1 , lf_AUX_Pure_C2_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_Pure_C2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Pure_C2_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[36];
PROF( prof_lf_AUX_Pure_C2_1);
if( check_sym( arg0 , ef10sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef12sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef2sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , ef3sym)) {
{
aterm * atmp00000= arg_0( atmp0000);
if( check_sym( atmp00000 , ef4sym)) {
{
aterm * atmp000000= arg_0( atmp00000);
if( check_sym( atmp000000 , ef5sym)) {
{
aterm * atmp0000000= arg_0( atmp000000);
if( check_sym( atmp0000000 , lf2sym)) {
{
aterm * atmp00000000= arg_0( atmp0000000);
{
aterm * atmp00001= arg_1( atmp0000);
if( check_sym( atmp00001 , ef6sym)) {
{
aterm * atmp000010= arg_0( atmp00001);
if( check_sym( atmp000010 , lf3sym)) {
{
aterm * atmp0000100= arg_0( atmp000010);
if( check_sym( arg1 , ef11sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( m_not_empty_list( atmp00000000)) {
tmp[ 0]= m_list_head( atmp00000000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 116))) {
tmp[ 1]= m_list_tail( atmp00000000);
{
if( m_not_empty_list( tmp[ 1])) {
tmp[ 2]= m_list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 95))) {
tmp[ 3]= m_list_tail( tmp[ 1]);
{
if( m_not_empty_list( tmp[ 3])) {
tmp[ 4]= m_list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 112))) {
tmp[ 5]= m_list_tail( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 114))) {
tmp[ 7]= m_list_tail( tmp[ 5]);
{
if( m_not_empty_list( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 111))) {
tmp[ 9]= m_list_tail( tmp[ 7]);
{
if( m_not_empty_list( tmp[ 9])) {
tmp[ 10]= m_list_head( tmp[ 9]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 116))) {
tmp[ 11]= m_list_tail( tmp[ 9]);
{
if( m_not_empty_list( tmp[ 11])) {
tmp[ 12]= m_list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 101))) {
tmp[ 13]= m_list_tail( tmp[ 11]);
{
if( m_not_empty_list( tmp[ 13])) {
tmp[ 14]= m_list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 99))) {
tmp[ 15]= m_list_tail( tmp[ 13]);
{
if( m_is_single_element( tmp[ 15])) {
tmp[ 16]= m_list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 116))) {
if( m_is_single_element( atmp0000100)) {
tmp[ 17]= m_list_head( atmp0000100);
{
if( m_not_empty_list( atmp1000000)) {
tmp[ 18]= m_list_head( atmp1000000);
t_protect( tmp[ 18]);
if( term_equal( tmp[ 18] , make_char( 105))) {
tmp[ 19]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 115))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 95))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 115))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 105))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 110))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 103))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 108))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 101))) {
tmp[ 27]= m_list_tail( tmp[ 26]);
if( m_not_empty_list( tmp[ 27])) {
t_protect( tmp[ 27]);
if( term_equal( list_head( tmp[ 27]) , make_char( 95))) {
tmp[ 28]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 28])) {
t_protect( tmp[ 28]);
if( term_equal( list_head( tmp[ 28]) , make_char( 101))) {
tmp[ 29]= m_list_tail( tmp[ 28]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 108))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_not_empty_list( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 101))) {
tmp[ 31]= m_list_tail( tmp[ 30]);
if( m_not_empty_list( tmp[ 31])) {
t_protect( tmp[ 31]);
if( term_equal( list_head( tmp[ 31]) , make_char( 109))) {
tmp[ 32]= m_list_tail( tmp[ 31]);
if( m_not_empty_list( tmp[ 32])) {
t_protect( tmp[ 32]);
if( term_equal( list_head( tmp[ 32]) , make_char( 101))) {
tmp[ 33]= m_list_tail( tmp[ 32]);
if( m_not_empty_list( tmp[ 33])) {
t_protect( tmp[ 33]);
if( term_equal( list_head( tmp[ 33]) , make_char( 110))) {
tmp[ 34]= m_list_tail( tmp[ 33]);
if( m_is_single_element( tmp[ 34])) {
t_protect( tmp[ 34]);
if( term_equal( list_head( tmp[ 34]) , make_char( 116))) {
if( m_is_single_element( atmp100100)) {
tmp[ 35]= m_list_head( atmp100100);
if( m_term_equal( tmp[ 17] , tmp[ 35])) {
t_protect( atmp1110);
t_unprotect( arg0);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
t_unprotect( tmp[ 33]);
t_unprotect( tmp[ 34]);
t_unprotect( tmp[ 35]);
return ( * ef10)( ( * ef11)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 103)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 116))))))))))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 17]))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110))));
}
t_unprotect( tmp[ 35]);
}
}
}
t_unprotect( tmp[ 34]);
}
}
t_unprotect( tmp[ 33]);
}
}
t_unprotect( tmp[ 32]);
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
}
t_unprotect( tmp[ 28]);
}
}
t_unprotect( tmp[ 27]);
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
}
t_protect( tmp[ 18]);
if( term_equal( tmp[ 18] , make_char( 110))) {
tmp[ 19]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 111))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 116))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 95))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 101))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 109))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 112))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 116))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 121))) {
tmp[ 27]= m_list_tail( tmp[ 26]);
if( m_not_empty_list( tmp[ 27])) {
t_protect( tmp[ 27]);
if( term_equal( list_head( tmp[ 27]) , make_char( 95))) {
tmp[ 28]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 28])) {
t_protect( tmp[ 28]);
if( term_equal( list_head( tmp[ 28]) , make_char( 108))) {
tmp[ 29]= m_list_tail( tmp[ 28]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 105))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_not_empty_list( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 115))) {
tmp[ 31]= m_list_tail( tmp[ 30]);
if( m_is_single_element( tmp[ 31])) {
t_protect( tmp[ 31]);
if( term_equal( list_head( tmp[ 31]) , make_char( 116))) {
if( m_is_single_element( atmp100100)) {
tmp[ 32]= m_list_head( atmp100100);
if( m_term_equal( tmp[ 17] , tmp[ 32])) {
t_protect( atmp1110);
t_unprotect( arg0);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
return ( * ef10)( ( * ef11)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 17]))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110))));
}
t_unprotect( tmp[ 32]);
}
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
}
t_unprotect( tmp[ 28]);
}
}
t_unprotect( tmp[ 27]);
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
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
t_unprotect( tmp[ 14]);
}
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
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
}
}
}
}
}
}
}
}
if( check_sym( arg1 , ef13sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
{
aterm * atmp12= arg_2( arg1);
if( check_sym( atmp12 , ef7sym)) {
{
aterm * atmp120= arg_0( atmp12);
if( check_sym( atmp120 , ef8sym)) {
{
aterm * atmp121= arg_1( atmp12);
if( check_sym( atmp121 , ef9sym)) {
{
aterm * atmp1210= arg_0( atmp121);
if( m_not_empty_list( atmp00000000)) {
t_protect( atmp00000000);
if( term_equal( list_head( atmp00000000) , make_char( 116))) {
tmp[ 0]= m_list_tail( atmp00000000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 95))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 112))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 114))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 111))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 101))) {
tmp[ 6]= m_list_tail( tmp[ 5]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 99))) {
tmp[ 7]= m_list_tail( tmp[ 6]);
if( m_is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
if( m_is_single_element( atmp0000100)) {
tmp[ 8]= m_list_head( atmp0000100);
if( m_not_empty_list( atmp1000000)) {
t_protect( atmp1000000);
if( term_equal( list_head( atmp1000000) , make_char( 110))) {
tmp[ 9]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 111))) {
tmp[ 10]= m_list_tail( tmp[ 9]);
if( m_not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 116))) {
tmp[ 11]= m_list_tail( tmp[ 10]);
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 95))) {
tmp[ 12]= m_list_tail( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 101))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 109))) {
tmp[ 14]= m_list_tail( tmp[ 13]);
if( m_not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 112))) {
tmp[ 15]= m_list_tail( tmp[ 14]);
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
if( term_equal( list_head( tmp[ 15]) , make_char( 116))) {
tmp[ 16]= m_list_tail( tmp[ 15]);
if( m_not_empty_list( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 121))) {
tmp[ 17]= m_list_tail( tmp[ 16]);
if( m_not_empty_list( tmp[ 17])) {
t_protect( tmp[ 17]);
if( term_equal( list_head( tmp[ 17]) , make_char( 95))) {
tmp[ 18]= m_list_tail( tmp[ 17]);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 108))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 105))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 115))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_is_single_element( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 116))) {
if( m_is_single_element( atmp100100)) {
tmp[ 22]= m_list_head( atmp100100);
if( m_term_equal( tmp[ 8] , tmp[ 22])) {
t_protect( atmp1110);
t_protect( atmp1210);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
return ( * ef10)( ( * ef13)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 8]))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110)) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1210))));
}
t_unprotect( tmp[ 22]);
}
}
}
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
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
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
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
if( check_sym( arg1 , ef12sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef14sym)) {
{
aterm * atmp100= arg_0( atmp10);
{
aterm * atmp101= arg_1( atmp10);
if( check_sym( atmp101 , ef2sym)) {
{
aterm * atmp1010= arg_0( atmp101);
if( check_sym( atmp1010 , ef3sym)) {
{
aterm * atmp10100= arg_0( atmp1010);
if( check_sym( atmp10100 , ef4sym)) {
{
aterm * atmp101000= arg_0( atmp10100);
if( check_sym( atmp101000 , ef5sym)) {
{
aterm * atmp1010000= arg_0( atmp101000);
if( check_sym( atmp1010000 , lf2sym)) {
{
aterm * atmp10100000= arg_0( atmp1010000);
{
aterm * atmp10101= arg_1( atmp1010);
if( check_sym( atmp10101 , ef6sym)) {
{
aterm * atmp101010= arg_0( atmp10101);
if( check_sym( atmp101010 , lf3sym)) {
{
aterm * atmp1010100= arg_0( atmp101010);
if( m_not_empty_list( atmp00000000)) {
tmp[ 0]= m_list_head( atmp00000000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 116))) {
tmp[ 1]= m_list_tail( atmp00000000);
{
if( m_not_empty_list( tmp[ 1])) {
tmp[ 2]= m_list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 95))) {
tmp[ 3]= m_list_tail( tmp[ 1]);
{
if( m_not_empty_list( tmp[ 3])) {
tmp[ 4]= m_list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 112))) {
tmp[ 5]= m_list_tail( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 114))) {
tmp[ 7]= m_list_tail( tmp[ 5]);
{
if( m_not_empty_list( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 111))) {
tmp[ 9]= m_list_tail( tmp[ 7]);
{
if( m_not_empty_list( tmp[ 9])) {
tmp[ 10]= m_list_head( tmp[ 9]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 116))) {
tmp[ 11]= m_list_tail( tmp[ 9]);
{
if( m_not_empty_list( tmp[ 11])) {
tmp[ 12]= m_list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 101))) {
tmp[ 13]= m_list_tail( tmp[ 11]);
{
if( m_not_empty_list( tmp[ 13])) {
tmp[ 14]= m_list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 99))) {
tmp[ 15]= m_list_tail( tmp[ 13]);
{
if( m_is_single_element( tmp[ 15])) {
tmp[ 16]= m_list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 116))) {
if( m_is_single_element( atmp0000100)) {
tmp[ 17]= m_list_head( atmp0000100);
{
if( m_not_empty_list( atmp10100000)) {
tmp[ 18]= m_list_head( atmp10100000);
t_protect( tmp[ 18]);
if( term_equal( tmp[ 18] , make_char( 108))) {
tmp[ 19]= m_list_tail( atmp10100000);
{
if( m_not_empty_list( tmp[ 19])) {
tmp[ 20]= m_list_head( tmp[ 19]);
t_protect( tmp[ 20]);
if( term_equal( tmp[ 20] , make_char( 105))) {
tmp[ 21]= m_list_tail( tmp[ 19]);
{
if( m_not_empty_list( tmp[ 21])) {
tmp[ 22]= m_list_head( tmp[ 21]);
t_protect( tmp[ 22]);
if( term_equal( tmp[ 22] , make_char( 115))) {
tmp[ 23]= m_list_tail( tmp[ 21]);
{
if( m_not_empty_list( tmp[ 23])) {
tmp[ 24]= m_list_head( tmp[ 23]);
t_protect( tmp[ 24]);
if( term_equal( tmp[ 24] , make_char( 116))) {
tmp[ 25]= m_list_tail( tmp[ 23]);
{
if( m_not_empty_list( tmp[ 25])) {
tmp[ 26]= m_list_head( tmp[ 25]);
t_protect( tmp[ 26]);
if( term_equal( tmp[ 26] , make_char( 95))) {
tmp[ 27]= m_list_tail( tmp[ 25]);
{
if( m_not_empty_list( tmp[ 27])) {
tmp[ 28]= m_list_head( tmp[ 27]);
t_protect( tmp[ 28]);
if( term_equal( tmp[ 28] , make_char( 104))) {
tmp[ 29]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 101))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_not_empty_list( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 97))) {
tmp[ 31]= m_list_tail( tmp[ 30]);
if( m_is_single_element( tmp[ 31])) {
t_protect( tmp[ 31]);
if( term_equal( list_head( tmp[ 31]) , make_char( 100))) {
if( m_is_single_element( atmp1010100)) {
tmp[ 32]= m_list_head( atmp1010100);
if( m_term_equal( tmp[ 17] , tmp[ 32])) {
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
return ( * ef10)( ( * ef12)( ( * ef14)( atmp100 , ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 17]))))))));
}
t_unprotect( tmp[ 32]);
}
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
t_protect( tmp[ 28]);
if( term_equal( tmp[ 28] , make_char( 116))) {
tmp[ 29]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 97))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_not_empty_list( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 105))) {
tmp[ 31]= m_list_tail( tmp[ 30]);
if( m_is_single_element( tmp[ 31])) {
t_protect( tmp[ 31]);
if( term_equal( list_head( tmp[ 31]) , make_char( 108))) {
if( m_is_single_element( atmp1010100)) {
tmp[ 32]= m_list_head( atmp1010100);
if( m_term_equal( tmp[ 17] , tmp[ 32])) {
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
return ( * ef10)( ( * ef12)( ( * ef14)( atmp100 , ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 17]))))))));
}
t_unprotect( tmp[ 32]);
}
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
t_unprotect( tmp[ 28]);
}
}
t_unprotect( tmp[ 27]);
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
}
t_unprotect( tmp[ 24]);
}
}
t_unprotect( tmp[ 23]);
}
t_unprotect( tmp[ 22]);
}
}
t_unprotect( tmp[ 21]);
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
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
t_unprotect( tmp[ 14]);
}
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
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
if( check_sym( arg0 , lf_AUX_Pure_C2_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef10sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef12sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , ef2sym)) {
{
aterm * atmp00000= arg_0( atmp0000);
if( check_sym( atmp00000 , ef3sym)) {
{
aterm * atmp000000= arg_0( atmp00000);
if( check_sym( atmp000000 , ef4sym)) {
{
aterm * atmp0000000= arg_0( atmp000000);
if( check_sym( atmp0000000 , ef5sym)) {
{
aterm * atmp00000000= arg_0( atmp0000000);
if( check_sym( atmp00000000 , lf2sym)) {
{
aterm * atmp000000000= arg_0( atmp00000000);
{
aterm * atmp000001= arg_1( atmp00000);
if( check_sym( atmp000001 , ef6sym)) {
{
aterm * atmp0000010= arg_0( atmp000001);
if( check_sym( atmp0000010 , lf3sym)) {
{
aterm * atmp00000100= arg_0( atmp0000010);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef12sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef2sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef3sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
if( check_sym( atmp01000 , ef4sym)) {
{
aterm * atmp010000= arg_0( atmp01000);
if( check_sym( atmp010000 , ef5sym)) {
{
aterm * atmp0100000= arg_0( atmp010000);
if( check_sym( atmp0100000 , lf2sym)) {
{
aterm * atmp01000000= arg_0( atmp0100000);
{
aterm * atmp01001= arg_1( atmp0100);
if( check_sym( atmp01001 , ef6sym)) {
{
aterm * atmp010010= arg_0( atmp01001);
if( check_sym( atmp010010 , lf3sym)) {
{
aterm * atmp0100100= arg_0( atmp010010);
if( check_sym( arg1 , ef11sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( m_not_empty_list( atmp000000000)) {
t_protect( atmp000000000);
if( term_equal( list_head( atmp000000000) , make_char( 116))) {
tmp[ 0]= m_list_tail( atmp000000000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 95))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 112))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 114))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 111))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 101))) {
tmp[ 6]= m_list_tail( tmp[ 5]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 99))) {
tmp[ 7]= m_list_tail( tmp[ 6]);
if( m_is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
if( m_is_single_element( atmp00000100)) {
tmp[ 8]= m_list_head( atmp00000100);
if( m_not_empty_list( atmp01000000)) {
t_protect( atmp01000000);
if( term_equal( list_head( atmp01000000) , make_char( 116))) {
tmp[ 9]= m_list_tail( atmp01000000);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 95))) {
tmp[ 10]= m_list_tail( tmp[ 9]);
if( m_not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 112))) {
tmp[ 11]= m_list_tail( tmp[ 10]);
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 114))) {
tmp[ 12]= m_list_tail( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 111))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 116))) {
tmp[ 14]= m_list_tail( tmp[ 13]);
if( m_not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 101))) {
tmp[ 15]= m_list_tail( tmp[ 14]);
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
if( term_equal( list_head( tmp[ 15]) , make_char( 99))) {
tmp[ 16]= m_list_tail( tmp[ 15]);
if( m_is_single_element( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 116))) {
if( m_is_single_element( atmp0100100)) {
tmp[ 17]= m_list_head( atmp0100100);
if( m_not_empty_list( atmp1000000)) {
t_protect( atmp1000000);
if( term_equal( list_head( atmp1000000) , make_char( 116))) {
tmp[ 18]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 101))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 114))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 109))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 95))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 101))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 113))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 117))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 97))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_is_single_element( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 108))) {
if( m_not_empty_list( atmp100100)) {
tmp[ 27]= m_list_head( atmp100100);
tmp[ 28]= m_list_tail( atmp100100);
if( m_is_single_element( tmp[ 28])) {
tmp[ 29]= m_list_head( tmp[ 28]);
if( m_term_equal( tmp[ 8] , tmp[ 27])) {
if( m_term_equal( tmp[ 17] , tmp[ 29])) {
t_protect( atmp1110);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
return ( * ef10)( ( * ef11)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))) , ( * ef6)( lf3( cons( make_list( tmp[ 8]) , make_list( tmp[ 17])))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110))));
}
}
t_unprotect( tmp[ 29]);
}
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 27]);
}
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
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
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
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
}
}
}
if( check_sym( arg1 , ef13sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
{
aterm * atmp12= arg_2( arg1);
if( check_sym( atmp12 , ef7sym)) {
{
aterm * atmp120= arg_0( atmp12);
if( check_sym( atmp120 , ef8sym)) {
{
aterm * atmp121= arg_1( atmp12);
if( check_sym( atmp121 , ef9sym)) {
{
aterm * atmp1210= arg_0( atmp121);
if( m_not_empty_list( atmp000000000)) {
t_protect( atmp000000000);
if( term_equal( list_head( atmp000000000) , make_char( 116))) {
tmp[ 0]= m_list_tail( atmp000000000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 95))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 112))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 114))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 111))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 101))) {
tmp[ 6]= m_list_tail( tmp[ 5]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 99))) {
tmp[ 7]= m_list_tail( tmp[ 6]);
if( m_is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
if( m_is_single_element( atmp00000100)) {
tmp[ 8]= m_list_head( atmp00000100);
if( m_not_empty_list( atmp01000000)) {
t_protect( atmp01000000);
if( term_equal( list_head( atmp01000000) , make_char( 116))) {
tmp[ 9]= m_list_tail( atmp01000000);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 95))) {
tmp[ 10]= m_list_tail( tmp[ 9]);
if( m_not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 112))) {
tmp[ 11]= m_list_tail( tmp[ 10]);
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 114))) {
tmp[ 12]= m_list_tail( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 111))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 116))) {
tmp[ 14]= m_list_tail( tmp[ 13]);
if( m_not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 101))) {
tmp[ 15]= m_list_tail( tmp[ 14]);
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
if( term_equal( list_head( tmp[ 15]) , make_char( 99))) {
tmp[ 16]= m_list_tail( tmp[ 15]);
if( m_is_single_element( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 116))) {
if( m_is_single_element( atmp0100100)) {
tmp[ 17]= m_list_head( atmp0100100);
if( m_not_empty_list( atmp1000000)) {
t_protect( atmp1000000);
if( term_equal( list_head( atmp1000000) , make_char( 116))) {
tmp[ 18]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 101))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 114))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 109))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 95))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 101))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 113))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 117))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 97))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_is_single_element( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 108))) {
if( m_not_empty_list( atmp100100)) {
tmp[ 27]= m_list_head( atmp100100);
tmp[ 28]= m_list_tail( atmp100100);
if( m_is_single_element( tmp[ 28])) {
tmp[ 29]= m_list_head( tmp[ 28]);
if( m_term_equal( tmp[ 8] , tmp[ 27])) {
if( m_term_equal( tmp[ 17] , tmp[ 29])) {
t_protect( atmp1110);
t_protect( atmp1210);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
return ( * ef10)( ( * ef13)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))) , ( * ef6)( lf3( cons( make_list( tmp[ 8]) , make_list( tmp[ 17])))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110)) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1210))));
}
}
t_unprotect( tmp[ 29]);
}
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 27]);
}
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
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
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
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
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf_AUX_Pure_C2_1sym)) {
{
aterm * atmp000= arg_0( atmp00);
{
aterm * atmp001= arg_1( atmp00);
if( check_sym( atmp001 , ef12sym)) {
{
aterm * atmp0010= arg_0( atmp001);
if( check_sym( atmp0010 , ef2sym)) {
{
aterm * atmp00100= arg_0( atmp0010);
if( check_sym( atmp00100 , ef3sym)) {
{
aterm * atmp001000= arg_0( atmp00100);
if( check_sym( atmp001000 , ef4sym)) {
{
aterm * atmp0010000= arg_0( atmp001000);
if( check_sym( atmp0010000 , ef5sym)) {
{
aterm * atmp00100000= arg_0( atmp0010000);
if( check_sym( atmp00100000 , lf2sym)) {
{
aterm * atmp001000000= arg_0( atmp00100000);
{
aterm * atmp001001= arg_1( atmp00100);
if( check_sym( atmp001001 , ef6sym)) {
{
aterm * atmp0010010= arg_0( atmp001001);
if( check_sym( atmp0010010 , lf3sym)) {
{
aterm * atmp00100100= arg_0( atmp0010010);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef12sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef2sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef3sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
if( check_sym( atmp01000 , ef4sym)) {
{
aterm * atmp010000= arg_0( atmp01000);
if( check_sym( atmp010000 , ef5sym)) {
{
aterm * atmp0100000= arg_0( atmp010000);
if( check_sym( atmp0100000 , lf2sym)) {
{
aterm * atmp01000000= arg_0( atmp0100000);
{
aterm * atmp01001= arg_1( atmp0100);
if( check_sym( atmp01001 , ef6sym)) {
{
aterm * atmp010010= arg_0( atmp01001);
if( check_sym( atmp010010 , lf3sym)) {
{
aterm * atmp0100100= arg_0( atmp010010);
if( check_sym( arg1 , ef11sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( m_not_empty_list( atmp001000000)) {
t_protect( atmp001000000);
if( term_equal( list_head( atmp001000000) , make_char( 116))) {
tmp[ 0]= m_list_tail( atmp001000000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 95))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 112))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 114))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 111))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 101))) {
tmp[ 6]= m_list_tail( tmp[ 5]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 99))) {
tmp[ 7]= m_list_tail( tmp[ 6]);
if( m_is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
if( m_is_single_element( atmp00100100)) {
tmp[ 8]= m_list_head( atmp00100100);
if( m_not_empty_list( atmp01000000)) {
t_protect( atmp01000000);
if( term_equal( list_head( atmp01000000) , make_char( 116))) {
tmp[ 9]= m_list_tail( atmp01000000);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 95))) {
tmp[ 10]= m_list_tail( tmp[ 9]);
if( m_not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 112))) {
tmp[ 11]= m_list_tail( tmp[ 10]);
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 114))) {
tmp[ 12]= m_list_tail( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 111))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 116))) {
tmp[ 14]= m_list_tail( tmp[ 13]);
if( m_not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 101))) {
tmp[ 15]= m_list_tail( tmp[ 14]);
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
if( term_equal( list_head( tmp[ 15]) , make_char( 99))) {
tmp[ 16]= m_list_tail( tmp[ 15]);
if( m_is_single_element( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 116))) {
if( m_is_single_element( atmp0100100)) {
tmp[ 17]= m_list_head( atmp0100100);
if( m_not_empty_list( atmp1000000)) {
t_protect( atmp1000000);
if( term_equal( list_head( atmp1000000) , make_char( 116))) {
tmp[ 18]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 101))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 114))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 109))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 95))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 101))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 113))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 117))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 97))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_is_single_element( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 108))) {
if( m_not_empty_list( atmp100100)) {
tmp[ 27]= m_list_head( atmp100100);
tmp[ 28]= m_list_tail( atmp100100);
if( m_is_single_element( tmp[ 28])) {
tmp[ 29]= m_list_head( tmp[ 28]);
if( m_term_equal( tmp[ 8] , tmp[ 27])) {
if( m_term_equal( tmp[ 17] , tmp[ 29])) {
t_protect( atmp000);
t_protect( atmp1110);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
return lf_AUX_Pure_C2_1( atmp000 , ( * ef11)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))) , ( * ef6)( lf3( cons( make_list( tmp[ 8]) , make_list( tmp[ 17])))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110))));
}
}
t_unprotect( tmp[ 29]);
}
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 27]);
}
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
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
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
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
}
}
}
if( check_sym( arg1 , ef13sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
{
aterm * atmp12= arg_2( arg1);
if( check_sym( atmp12 , ef7sym)) {
{
aterm * atmp120= arg_0( atmp12);
if( check_sym( atmp120 , ef8sym)) {
{
aterm * atmp121= arg_1( atmp12);
if( check_sym( atmp121 , ef9sym)) {
{
aterm * atmp1210= arg_0( atmp121);
if( m_not_empty_list( atmp001000000)) {
t_protect( atmp001000000);
if( term_equal( list_head( atmp001000000) , make_char( 116))) {
tmp[ 0]= m_list_tail( atmp001000000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 95))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 112))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 114))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 111))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 101))) {
tmp[ 6]= m_list_tail( tmp[ 5]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 99))) {
tmp[ 7]= m_list_tail( tmp[ 6]);
if( m_is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
if( m_is_single_element( atmp00100100)) {
tmp[ 8]= m_list_head( atmp00100100);
if( m_not_empty_list( atmp01000000)) {
t_protect( atmp01000000);
if( term_equal( list_head( atmp01000000) , make_char( 116))) {
tmp[ 9]= m_list_tail( atmp01000000);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 95))) {
tmp[ 10]= m_list_tail( tmp[ 9]);
if( m_not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 112))) {
tmp[ 11]= m_list_tail( tmp[ 10]);
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 114))) {
tmp[ 12]= m_list_tail( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 111))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 116))) {
tmp[ 14]= m_list_tail( tmp[ 13]);
if( m_not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 101))) {
tmp[ 15]= m_list_tail( tmp[ 14]);
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
if( term_equal( list_head( tmp[ 15]) , make_char( 99))) {
tmp[ 16]= m_list_tail( tmp[ 15]);
if( m_is_single_element( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 116))) {
if( m_is_single_element( atmp0100100)) {
tmp[ 17]= m_list_head( atmp0100100);
if( m_not_empty_list( atmp1000000)) {
t_protect( atmp1000000);
if( term_equal( list_head( atmp1000000) , make_char( 116))) {
tmp[ 18]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 101))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 114))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 109))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 95))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 101))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 113))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 117))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 97))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_is_single_element( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 108))) {
if( m_not_empty_list( atmp100100)) {
tmp[ 27]= m_list_head( atmp100100);
tmp[ 28]= m_list_tail( atmp100100);
if( m_is_single_element( tmp[ 28])) {
tmp[ 29]= m_list_head( tmp[ 28]);
if( m_term_equal( tmp[ 8] , tmp[ 27])) {
if( m_term_equal( tmp[ 17] , tmp[ 29])) {
t_protect( atmp000);
t_protect( atmp1110);
t_protect( atmp1210);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
return lf_AUX_Pure_C2_1( atmp000 , ( * ef13)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108)))))))))))))))) , ( * ef6)( lf3( cons( make_list( tmp[ 8]) , make_list( tmp[ 17])))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110)) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1210))));
}
}
t_unprotect( tmp[ 29]);
}
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 27]);
}
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
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
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
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
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef12sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef2sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef3sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
if( check_sym( atmp01000 , ef4sym)) {
{
aterm * atmp010000= arg_0( atmp01000);
if( check_sym( atmp010000 , ef5sym)) {
{
aterm * atmp0100000= arg_0( atmp010000);
if( check_sym( atmp0100000 , lf2sym)) {
{
aterm * atmp01000000= arg_0( atmp0100000);
{
aterm * atmp01001= arg_1( atmp0100);
if( check_sym( atmp01001 , ef6sym)) {
{
aterm * atmp010010= arg_0( atmp01001);
if( check_sym( atmp010010 , lf3sym)) {
{
aterm * atmp0100100= arg_0( atmp010010);
if( check_sym( arg1 , ef11sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( m_not_empty_list( atmp01000000)) {
tmp[ 0]= m_list_head( atmp01000000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 116))) {
tmp[ 1]= m_list_tail( atmp01000000);
{
if( m_not_empty_list( tmp[ 1])) {
tmp[ 2]= m_list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 95))) {
tmp[ 3]= m_list_tail( tmp[ 1]);
{
if( m_not_empty_list( tmp[ 3])) {
tmp[ 4]= m_list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 112))) {
tmp[ 5]= m_list_tail( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 114))) {
tmp[ 7]= m_list_tail( tmp[ 5]);
{
if( m_not_empty_list( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 111))) {
tmp[ 9]= m_list_tail( tmp[ 7]);
{
if( m_not_empty_list( tmp[ 9])) {
tmp[ 10]= m_list_head( tmp[ 9]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 116))) {
tmp[ 11]= m_list_tail( tmp[ 9]);
{
if( m_not_empty_list( tmp[ 11])) {
tmp[ 12]= m_list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 101))) {
tmp[ 13]= m_list_tail( tmp[ 11]);
{
if( m_not_empty_list( tmp[ 13])) {
tmp[ 14]= m_list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 99))) {
tmp[ 15]= m_list_tail( tmp[ 13]);
{
if( m_is_single_element( tmp[ 15])) {
tmp[ 16]= m_list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 116))) {
if( m_is_single_element( atmp0100100)) {
tmp[ 17]= m_list_head( atmp0100100);
{
if( m_not_empty_list( atmp1000000)) {
tmp[ 18]= m_list_head( atmp1000000);
t_protect( tmp[ 18]);
if( term_equal( tmp[ 18] , make_char( 105))) {
tmp[ 19]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 115))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 95))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 115))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 105))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 110))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 103))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 108))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 101))) {
tmp[ 27]= m_list_tail( tmp[ 26]);
if( m_not_empty_list( tmp[ 27])) {
t_protect( tmp[ 27]);
if( term_equal( list_head( tmp[ 27]) , make_char( 95))) {
tmp[ 28]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 28])) {
t_protect( tmp[ 28]);
if( term_equal( list_head( tmp[ 28]) , make_char( 101))) {
tmp[ 29]= m_list_tail( tmp[ 28]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 108))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_not_empty_list( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 101))) {
tmp[ 31]= m_list_tail( tmp[ 30]);
if( m_not_empty_list( tmp[ 31])) {
t_protect( tmp[ 31]);
if( term_equal( list_head( tmp[ 31]) , make_char( 109))) {
tmp[ 32]= m_list_tail( tmp[ 31]);
if( m_not_empty_list( tmp[ 32])) {
t_protect( tmp[ 32]);
if( term_equal( list_head( tmp[ 32]) , make_char( 101))) {
tmp[ 33]= m_list_tail( tmp[ 32]);
if( m_not_empty_list( tmp[ 33])) {
t_protect( tmp[ 33]);
if( term_equal( list_head( tmp[ 33]) , make_char( 110))) {
tmp[ 34]= m_list_tail( tmp[ 33]);
if( m_is_single_element( tmp[ 34])) {
t_protect( tmp[ 34]);
if( term_equal( list_head( tmp[ 34]) , make_char( 116))) {
if( m_is_single_element( atmp100100)) {
tmp[ 35]= m_list_head( atmp100100);
if( m_term_equal( tmp[ 17] , tmp[ 35])) {
t_protect( atmp00);
t_protect( atmp1110);
t_unprotect( arg0);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
t_unprotect( tmp[ 33]);
t_unprotect( tmp[ 34]);
t_unprotect( tmp[ 35]);
return lf_AUX_Pure_C2_1( atmp00 , ( * ef11)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 103)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 110)) , make_list( make_char( 116))))))))))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 17]))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110))));
}
t_unprotect( tmp[ 35]);
}
}
}
t_unprotect( tmp[ 34]);
}
}
t_unprotect( tmp[ 33]);
}
}
t_unprotect( tmp[ 32]);
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
}
t_unprotect( tmp[ 28]);
}
}
t_unprotect( tmp[ 27]);
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
}
t_protect( tmp[ 18]);
if( term_equal( tmp[ 18] , make_char( 110))) {
tmp[ 19]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 111))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 116))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 95))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 101))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 109))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 112))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 116))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 121))) {
tmp[ 27]= m_list_tail( tmp[ 26]);
if( m_not_empty_list( tmp[ 27])) {
t_protect( tmp[ 27]);
if( term_equal( list_head( tmp[ 27]) , make_char( 95))) {
tmp[ 28]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 28])) {
t_protect( tmp[ 28]);
if( term_equal( list_head( tmp[ 28]) , make_char( 108))) {
tmp[ 29]= m_list_tail( tmp[ 28]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 105))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_not_empty_list( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 115))) {
tmp[ 31]= m_list_tail( tmp[ 30]);
if( m_is_single_element( tmp[ 31])) {
t_protect( tmp[ 31]);
if( term_equal( list_head( tmp[ 31]) , make_char( 116))) {
if( m_is_single_element( atmp100100)) {
tmp[ 32]= m_list_head( atmp100100);
if( m_term_equal( tmp[ 17] , tmp[ 32])) {
t_protect( atmp00);
t_protect( atmp1110);
t_unprotect( arg0);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
return lf_AUX_Pure_C2_1( atmp00 , ( * ef11)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 17]))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110))));
}
t_unprotect( tmp[ 32]);
}
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
}
t_unprotect( tmp[ 28]);
}
}
t_unprotect( tmp[ 27]);
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
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
t_unprotect( tmp[ 14]);
}
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
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
}
}
}
}
}
}
}
}
if( check_sym( arg1 , ef13sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
{
aterm * atmp12= arg_2( arg1);
if( check_sym( atmp12 , ef7sym)) {
{
aterm * atmp120= arg_0( atmp12);
if( check_sym( atmp120 , ef8sym)) {
{
aterm * atmp121= arg_1( atmp12);
if( check_sym( atmp121 , ef9sym)) {
{
aterm * atmp1210= arg_0( atmp121);
if( m_not_empty_list( atmp01000000)) {
t_protect( atmp01000000);
if( term_equal( list_head( atmp01000000) , make_char( 116))) {
tmp[ 0]= m_list_tail( atmp01000000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 95))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 112))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 114))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 111))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 116))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 101))) {
tmp[ 6]= m_list_tail( tmp[ 5]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 99))) {
tmp[ 7]= m_list_tail( tmp[ 6]);
if( m_is_single_element( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
if( m_is_single_element( atmp0100100)) {
tmp[ 8]= m_list_head( atmp0100100);
if( m_not_empty_list( atmp1000000)) {
t_protect( atmp1000000);
if( term_equal( list_head( atmp1000000) , make_char( 110))) {
tmp[ 9]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 111))) {
tmp[ 10]= m_list_tail( tmp[ 9]);
if( m_not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 116))) {
tmp[ 11]= m_list_tail( tmp[ 10]);
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 95))) {
tmp[ 12]= m_list_tail( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 101))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 109))) {
tmp[ 14]= m_list_tail( tmp[ 13]);
if( m_not_empty_list( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 112))) {
tmp[ 15]= m_list_tail( tmp[ 14]);
if( m_not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
if( term_equal( list_head( tmp[ 15]) , make_char( 116))) {
tmp[ 16]= m_list_tail( tmp[ 15]);
if( m_not_empty_list( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 121))) {
tmp[ 17]= m_list_tail( tmp[ 16]);
if( m_not_empty_list( tmp[ 17])) {
t_protect( tmp[ 17]);
if( term_equal( list_head( tmp[ 17]) , make_char( 95))) {
tmp[ 18]= m_list_tail( tmp[ 17]);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 108))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 105))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 115))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_is_single_element( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 116))) {
if( m_is_single_element( atmp100100)) {
tmp[ 22]= m_list_head( atmp100100);
if( m_term_equal( tmp[ 8] , tmp[ 22])) {
t_protect( atmp00);
t_protect( atmp1110);
t_protect( atmp1210);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
return lf_AUX_Pure_C2_1( atmp00 , ( * ef13)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 8]))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1110)) , ( * ef7)( ( * ef8)( ) , ( * ef9)( atmp1210))));
}
t_unprotect( tmp[ 22]);
}
}
}
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
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
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
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
if( check_sym( arg1 , ef12sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef14sym)) {
{
aterm * atmp100= arg_0( atmp10);
{
aterm * atmp101= arg_1( atmp10);
if( check_sym( atmp101 , ef2sym)) {
{
aterm * atmp1010= arg_0( atmp101);
if( check_sym( atmp1010 , ef3sym)) {
{
aterm * atmp10100= arg_0( atmp1010);
if( check_sym( atmp10100 , ef4sym)) {
{
aterm * atmp101000= arg_0( atmp10100);
if( check_sym( atmp101000 , ef5sym)) {
{
aterm * atmp1010000= arg_0( atmp101000);
if( check_sym( atmp1010000 , lf2sym)) {
{
aterm * atmp10100000= arg_0( atmp1010000);
{
aterm * atmp10101= arg_1( atmp1010);
if( check_sym( atmp10101 , ef6sym)) {
{
aterm * atmp101010= arg_0( atmp10101);
if( check_sym( atmp101010 , lf3sym)) {
{
aterm * atmp1010100= arg_0( atmp101010);
if( m_not_empty_list( atmp01000000)) {
tmp[ 0]= m_list_head( atmp01000000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 116))) {
tmp[ 1]= m_list_tail( atmp01000000);
{
if( m_not_empty_list( tmp[ 1])) {
tmp[ 2]= m_list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 95))) {
tmp[ 3]= m_list_tail( tmp[ 1]);
{
if( m_not_empty_list( tmp[ 3])) {
tmp[ 4]= m_list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 112))) {
tmp[ 5]= m_list_tail( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 5])) {
tmp[ 6]= m_list_head( tmp[ 5]);
t_protect( tmp[ 6]);
if( term_equal( tmp[ 6] , make_char( 114))) {
tmp[ 7]= m_list_tail( tmp[ 5]);
{
if( m_not_empty_list( tmp[ 7])) {
tmp[ 8]= m_list_head( tmp[ 7]);
t_protect( tmp[ 8]);
if( term_equal( tmp[ 8] , make_char( 111))) {
tmp[ 9]= m_list_tail( tmp[ 7]);
{
if( m_not_empty_list( tmp[ 9])) {
tmp[ 10]= m_list_head( tmp[ 9]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 116))) {
tmp[ 11]= m_list_tail( tmp[ 9]);
{
if( m_not_empty_list( tmp[ 11])) {
tmp[ 12]= m_list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 101))) {
tmp[ 13]= m_list_tail( tmp[ 11]);
{
if( m_not_empty_list( tmp[ 13])) {
tmp[ 14]= m_list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 99))) {
tmp[ 15]= m_list_tail( tmp[ 13]);
{
if( m_is_single_element( tmp[ 15])) {
tmp[ 16]= m_list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 116))) {
if( m_is_single_element( atmp0100100)) {
tmp[ 17]= m_list_head( atmp0100100);
{
if( m_not_empty_list( atmp10100000)) {
tmp[ 18]= m_list_head( atmp10100000);
t_protect( tmp[ 18]);
if( term_equal( tmp[ 18] , make_char( 108))) {
tmp[ 19]= m_list_tail( atmp10100000);
{
if( m_not_empty_list( tmp[ 19])) {
tmp[ 20]= m_list_head( tmp[ 19]);
t_protect( tmp[ 20]);
if( term_equal( tmp[ 20] , make_char( 105))) {
tmp[ 21]= m_list_tail( tmp[ 19]);
{
if( m_not_empty_list( tmp[ 21])) {
tmp[ 22]= m_list_head( tmp[ 21]);
t_protect( tmp[ 22]);
if( term_equal( tmp[ 22] , make_char( 115))) {
tmp[ 23]= m_list_tail( tmp[ 21]);
{
if( m_not_empty_list( tmp[ 23])) {
tmp[ 24]= m_list_head( tmp[ 23]);
t_protect( tmp[ 24]);
if( term_equal( tmp[ 24] , make_char( 116))) {
tmp[ 25]= m_list_tail( tmp[ 23]);
{
if( m_not_empty_list( tmp[ 25])) {
tmp[ 26]= m_list_head( tmp[ 25]);
t_protect( tmp[ 26]);
if( term_equal( tmp[ 26] , make_char( 95))) {
tmp[ 27]= m_list_tail( tmp[ 25]);
{
if( m_not_empty_list( tmp[ 27])) {
tmp[ 28]= m_list_head( tmp[ 27]);
t_protect( tmp[ 28]);
if( term_equal( tmp[ 28] , make_char( 104))) {
tmp[ 29]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 101))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_not_empty_list( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 97))) {
tmp[ 31]= m_list_tail( tmp[ 30]);
if( m_is_single_element( tmp[ 31])) {
t_protect( tmp[ 31]);
if( term_equal( list_head( tmp[ 31]) , make_char( 100))) {
if( m_is_single_element( atmp1010100)) {
tmp[ 32]= m_list_head( atmp1010100);
if( m_term_equal( tmp[ 17] , tmp[ 32])) {
t_protect( atmp00);
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
return lf_AUX_Pure_C2_1( atmp00 , ( * ef12)( ( * ef14)( atmp100 , ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 104)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 97)) , make_list( make_char( 100))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 17]))))))));
}
t_unprotect( tmp[ 32]);
}
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
t_protect( tmp[ 28]);
if( term_equal( tmp[ 28] , make_char( 116))) {
tmp[ 29]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 97))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_not_empty_list( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 105))) {
tmp[ 31]= m_list_tail( tmp[ 30]);
if( m_is_single_element( tmp[ 31])) {
t_protect( tmp[ 31]);
if( term_equal( list_head( tmp[ 31]) , make_char( 108))) {
if( m_is_single_element( atmp1010100)) {
tmp[ 32]= m_list_head( atmp1010100);
if( m_term_equal( tmp[ 17] , tmp[ 32])) {
t_protect( atmp00);
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
return lf_AUX_Pure_C2_1( atmp00 , ( * ef12)( ( * ef14)( atmp100 , ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 97)) , cons( make_list( make_char( 105)) , make_list( make_char( 108))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 17]))))))));
}
t_unprotect( tmp[ 32]);
}
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
t_unprotect( tmp[ 28]);
}
}
t_unprotect( tmp[ 27]);
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
}
t_unprotect( tmp[ 24]);
}
}
t_unprotect( tmp[ 23]);
}
t_unprotect( tmp[ 22]);
}
}
t_unprotect( tmp[ 21]);
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
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
t_unprotect( tmp[ 14]);
}
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
t_unprotect( tmp[ 9]);
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
t_unprotect( tmp[ 6]);
}
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
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
}
}
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef3sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef4sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef5sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , lf2sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef6sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
if( check_sym( atmp10010 , lf3sym)) {
{
aterm * atmp100100= arg_0( atmp10010);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef7sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef8sym)) {
{
aterm * atmp111= arg_1( atmp11);
if( check_sym( atmp111 , ef9sym)) {
{
aterm * atmp1110= arg_0( atmp111);
if( check_sym( atmp1110 , lf_AUX_Pure_C2_1sym)) {
{
aterm * atmp11100= arg_0( atmp1110);
if( check_sym( atmp11100 , lf_AUX_Pure_C2_1sym)) {
{
aterm * atmp111000= arg_0( atmp11100);
if( check_sym( atmp111000 , lf_AUX_Pure_C2_1sym)) {
{
aterm * atmp1110000= arg_0( atmp111000);
if( check_sym( atmp1110000 , ef10sym)) {
{
aterm * atmp11100000= arg_0( atmp1110000);
if( check_sym( atmp11100000 , ef11sym)) {
{
aterm * atmp111000000= arg_0( atmp11100000);
if( check_sym( atmp111000000 , ef2sym)) {
{
aterm * atmp1110000000= arg_0( atmp111000000);
if( check_sym( atmp1110000000 , ef3sym)) {
{
aterm * atmp11100000000= arg_0( atmp1110000000);
if( check_sym( atmp11100000000 , ef4sym)) {
{
aterm * atmp111000000000= arg_0( atmp11100000000);
if( check_sym( atmp111000000000 , ef5sym)) {
{
aterm * atmp1110000000000= arg_0( atmp111000000000);
if( check_sym( atmp1110000000000 , lf2sym)) {
{
aterm * atmp11100000000000= arg_0( atmp1110000000000);
{
aterm * atmp11100000001= arg_1( atmp1110000000);
if( check_sym( atmp11100000001 , ef6sym)) {
{
aterm * atmp111000000010= arg_0( atmp11100000001);
if( check_sym( atmp111000000010 , lf3sym)) {
{
aterm * atmp1110000000100= arg_0( atmp111000000010);
{
aterm * atmp111000001= arg_1( atmp11100000);
if( check_sym( atmp111000001 , ef7sym)) {
{
aterm * atmp1110000010= arg_0( atmp111000001);
if( check_sym( atmp1110000010 , ef8sym)) {
{
aterm * atmp1110000011= arg_1( atmp111000001);
if( check_sym( atmp1110000011 , ef9sym)) {
{
aterm * atmp11100000110= arg_0( atmp1110000011);
{
aterm * atmp1110001= arg_1( atmp111000);
{
aterm * atmp111001= arg_1( atmp11100);
{
aterm * atmp11101= arg_1( atmp1110);
if( m_not_empty_list( atmp1000000)) {
t_protect( atmp1000000);
if( term_equal( list_head( atmp1000000) , make_char( 109))) {
tmp[ 0]= m_list_tail( atmp1000000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 95))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 110))) {
tmp[ 2]= m_list_tail( tmp[ 1]);
if( m_not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
if( term_equal( list_head( tmp[ 2]) , make_char( 111))) {
tmp[ 3]= m_list_tail( tmp[ 2]);
if( m_not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
if( term_equal( list_head( tmp[ 3]) , make_char( 116))) {
tmp[ 4]= m_list_tail( tmp[ 3]);
if( m_not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 95))) {
tmp[ 5]= m_list_tail( tmp[ 4]);
if( m_not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 101))) {
tmp[ 6]= m_list_tail( tmp[ 5]);
if( m_not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 109))) {
tmp[ 7]= m_list_tail( tmp[ 6]);
if( m_not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 112))) {
tmp[ 8]= m_list_tail( tmp[ 7]);
if( m_not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 116))) {
tmp[ 9]= m_list_tail( tmp[ 8]);
if( m_not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 121))) {
tmp[ 10]= m_list_tail( tmp[ 9]);
if( m_not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 95))) {
tmp[ 11]= m_list_tail( tmp[ 10]);
if( m_not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 108))) {
tmp[ 12]= m_list_tail( tmp[ 11]);
if( m_not_empty_list( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 105))) {
tmp[ 13]= m_list_tail( tmp[ 12]);
if( m_not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
if( term_equal( list_head( tmp[ 13]) , make_char( 115))) {
tmp[ 14]= m_list_tail( tmp[ 13]);
if( m_is_single_element( tmp[ 14])) {
t_protect( tmp[ 14]);
if( term_equal( list_head( tmp[ 14]) , make_char( 116))) {
if( m_is_single_element( atmp100100)) {
tmp[ 15]= m_list_head( atmp100100);
if( m_not_empty_list( atmp11100000000000)) {
t_protect( atmp11100000000000);
if( term_equal( list_head( atmp11100000000000) , make_char( 109))) {
tmp[ 16]= m_list_tail( atmp11100000000000);
if( m_not_empty_list( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 95))) {
tmp[ 17]= m_list_tail( tmp[ 16]);
if( m_not_empty_list( tmp[ 17])) {
t_protect( tmp[ 17]);
if( term_equal( list_head( tmp[ 17]) , make_char( 110))) {
tmp[ 18]= m_list_tail( tmp[ 17]);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 111))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 116))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 95))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 101))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 109))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 112))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 116))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 121))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 95))) {
tmp[ 27]= m_list_tail( tmp[ 26]);
if( m_not_empty_list( tmp[ 27])) {
t_protect( tmp[ 27]);
if( term_equal( list_head( tmp[ 27]) , make_char( 108))) {
tmp[ 28]= m_list_tail( tmp[ 27]);
if( m_not_empty_list( tmp[ 28])) {
t_protect( tmp[ 28]);
if( term_equal( list_head( tmp[ 28]) , make_char( 105))) {
tmp[ 29]= m_list_tail( tmp[ 28]);
if( m_not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 115))) {
tmp[ 30]= m_list_tail( tmp[ 29]);
if( m_is_single_element( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 116))) {
if( m_is_single_element( atmp1110000000100)) {
tmp[ 31]= m_list_head( atmp1110000000100);
if( m_term_equal( tmp[ 15] , tmp[ 31])) {
t_protect( atmp11100000110);
t_protect( atmp1110001);
t_protect( atmp111001);
t_protect( atmp11101);
t_unprotect( arg1);
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
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
return lf_AUX_Pure_C2_1( arg0 , ( * ef1)( ( * ef2)( ( * ef3)( ( * ef4)( ( * ef5)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))))) , ( * ef6)( lf3( make_list( tmp[ 15]))))) , ( * ef7)( ( * ef8)( ) , ( * ef9)( lf_AUX_Pure_C2_1( lf_AUX_Pure_C2_1( lf_AUX_Pure_C2_1( atmp11100000110 , atmp1110001) , atmp111001) , atmp11101)))));
}
t_unprotect( tmp[ 31]);
}
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
}
t_unprotect( tmp[ 28]);
}
}
t_unprotect( tmp[ 27]);
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
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
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
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
}
t_unprotect( tmp[ 14]);
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
}
t_unprotect( tmp[ 5]);
}
}
t_unprotect( tmp[ 4]);
}
}
t_unprotect( tmp[ 3]);
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
}
}
return make_nf2( lf_AUX_Pure_C2_1sym , arg0 , arg1);
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

