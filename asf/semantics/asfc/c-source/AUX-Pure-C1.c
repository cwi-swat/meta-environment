#include "support.h"
static asymbol * lf_AUX_Pure_C1_1sym;
static aterm * lf_AUX_Pure_C1_1( aterm * arg1 , aterm * arg2);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
void register_AUX_Pure_C1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Pure_C1_1sym= TmkSymbol( "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"while\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C1_1 , lf_AUX_Pure_C1_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_Pure_C1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"if\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Pure_C1_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[32];
PROF( prof_lf_AUX_Pure_C1_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef3sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , ef4sym)) {
{
aterm * atmp00000= arg_0( atmp0000);
if( check_sym( atmp00000 , lf2sym)) {
{
aterm * atmp000000= arg_0( atmp00000);
{
aterm * atmp001= arg_1( atmp00);
if( check_sym( atmp001 , ef5sym)) {
{
aterm * atmp0010= arg_0( atmp001);
if( check_sym( atmp0010 , lf3sym)) {
{
aterm * atmp00100= arg_0( atmp0010);
if( check_sym( arg1 , ef6sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef7sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef8sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef9sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef9sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
if( check_sym( atmp11000 , ef9sym)) {
{
aterm * atmp110000= arg_0( atmp11000);
if( check_sym( atmp110000 , ef10sym)) {
{
aterm * atmp1100000= arg_0( atmp110000);
if( check_sym( atmp1100000 , ef11sym)) {
{
aterm * atmp11000000= arg_0( atmp1100000);
if( check_sym( atmp11000000 , ef1sym)) {
{
aterm * atmp110000000= arg_0( atmp11000000);
if( check_sym( atmp110000000 , ef2sym)) {
{
aterm * atmp1100000000= arg_0( atmp110000000);
if( check_sym( atmp1100000000 , ef3sym)) {
{
aterm * atmp11000000000= arg_0( atmp1100000000);
if( check_sym( atmp11000000000 , ef4sym)) {
{
aterm * atmp110000000000= arg_0( atmp11000000000);
if( check_sym( atmp110000000000 , lf2sym)) {
{
aterm * atmp1100000000000= arg_0( atmp110000000000);
{
aterm * atmp1100000001= arg_1( atmp110000000);
if( check_sym( atmp1100000001 , ef5sym)) {
{
aterm * atmp11000000010= arg_0( atmp1100000001);
if( check_sym( atmp11000000010 , lf3sym)) {
{
aterm * atmp110000000100= arg_0( atmp11000000010);
{
aterm * atmp11000001= arg_1( atmp1100000);
if( check_sym( atmp11000001 , ef6sym)) {
{
aterm * atmp110000010= arg_0( atmp11000001);
if( check_sym( atmp110000010 , ef7sym)) {
{
aterm * atmp110000011= arg_1( atmp11000001);
if( check_sym( atmp110000011 , ef8sym)) {
{
aterm * atmp1100000110= arg_0( atmp110000011);
{
aterm * atmp110001= arg_1( atmp11000);
{
aterm * atmp11001= arg_1( atmp1100);
{
aterm * atmp1101= arg_1( atmp110);
if( m_not_empty_list( atmp000000)) {
t_protect( atmp000000);
if( term_equal( list_head( atmp000000) , make_char( 109))) {
tmp[ 0]= m_list_tail( atmp000000);
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
if( m_is_single_element( atmp00100)) {
tmp[ 15]= m_list_head( atmp00100);
if( m_not_empty_list( atmp1100000000000)) {
t_protect( atmp1100000000000);
if( term_equal( list_head( atmp1100000000000) , make_char( 109))) {
tmp[ 16]= m_list_tail( atmp1100000000000);
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
if( m_is_single_element( atmp110000000100)) {
tmp[ 31]= m_list_head( atmp110000000100);
if( m_term_equal( tmp[ 15] , tmp[ 31])) {
t_protect( atmp1100000110);
t_protect( atmp110001);
t_protect( atmp11001);
t_protect( atmp1101);
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
return lf_AUX_Pure_C1_1( ( * ef1)( ( * ef2)( ( * ef3)( ( * ef4)( lf2( cons( make_list( make_char( 109)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 110)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 112)) , cons( make_list( make_char( 116)) , cons( make_list( make_char( 121)) , cons( make_list( make_char( 95)) , cons( make_list( make_char( 108)) , cons( make_list( make_char( 105)) , cons( make_list( make_char( 115)) , make_list( make_char( 116)))))))))))))))))))) , ( * ef5)( lf3( make_list( tmp[ 15]))))) , ( * ef6)( ( * ef7)( ) , ( * ef8)( ( * ef9)( ( * ef9)( ( * ef9)( atmp1100000110 , atmp110001) , atmp11001) , atmp1101))));
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
return make_nf2( lf_AUX_Pure_C1_1sym , arg0 , arg1);
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

