#include "support.h"
static asymbol * lf_AUX_C_Basics4_1sym;
static aterm * lf_AUX_C_Basics4_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_C_Basics4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics4_1sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++up\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++up\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))") , lf_AUX_C_Basics4_1 , lf_AUX_C_Basics4_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Expression\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_C_Basics4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Primary-expression\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Identifier\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Primary-expression\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"identifier\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Identifier\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"contains-unprotect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"contains-unprotect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"remove-unprotect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"remove-unprotect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"contains-protect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"contains-protect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"remove-protect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"remove-protect\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_C_Basics4_1( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[15];
PROF( prof_lf_AUX_C_Basics4_1);
if( check_sym( arg0 , ef1sym)) {
t_unprotect( arg0);
return arg1;
}
if( check_sym( arg0 , ef2sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef3sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef4sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef5sym)) {
{
aterm * atmp10000= arg_0( atmp1000);
if( check_sym( atmp10000 , ef6sym)) {
{
aterm * atmp100000= arg_0( atmp10000);
if( check_sym( atmp100000 , ef7sym)) {
{
aterm * atmp1000000= arg_0( atmp100000);
if( check_sym( atmp1000000 , ef8sym)) {
{
aterm * atmp10000000= arg_0( atmp1000000);
if( check_sym( atmp10000000 , lf2sym)) {
{
aterm * atmp100000000= arg_0( atmp10000000);
{
aterm * atmp100001= arg_1( atmp10000);
if( check_sym( atmp100001 , ef9sym)) {
{
aterm * atmp1000010= arg_0( atmp100001);
if( check_sym( atmp1000010 , lf3sym)) {
{
aterm * atmp10000100= arg_0( atmp1000010);
t_protect( atmp100000000);
if( not_empty_list( atmp100000000)) {
t_protect( atmp100000000);
tmp[ 0]= list_head( atmp100000000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 116))) {
t_protect( atmp100000000);
tmp[ 1]= list_tail( atmp100000000);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
tmp[ 2]= list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 95))) {
t_protect( tmp[ 1]);
tmp[ 3]= list_tail( tmp[ 1]);
t_protect( tmp[ 3]);
if( not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 4]= list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 112))) {
t_protect( tmp[ 3]);
tmp[ 5]= list_tail( tmp[ 3]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 114))) {
t_protect( tmp[ 5]);
tmp[ 6]= list_tail( tmp[ 5]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 111))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_tail( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_tail( tmp[ 7]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 101))) {
t_protect( tmp[ 8]);
tmp[ 9]= list_tail( tmp[ 8]);
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 99))) {
t_protect( tmp[ 9]);
tmp[ 10]= list_tail( tmp[ 9]);
t_protect( tmp[ 10]);
if( is_single_element( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 116))) {
t_protect( atmp10000100);
if( is_single_element( atmp10000100)) {
t_protect( atmp10000100);
tmp[ 11]= list_head( atmp10000100);
t_protect( tmp[ 11]);
t_protect( arg0);
if( term_equal( ( * ef10)( tmp[ 11] , arg0) , ( * ef11)( ))) {
t_protect( tmp[ 11]);
t_protect( arg0);
tmp[ 12]= ( * ef12)( tmp[ 11] , arg0);
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
return tmp[ 12];
}
t_unprotect( tmp[ 11]);
}
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
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 117))) {
t_protect( tmp[ 3]);
tmp[ 5]= list_tail( tmp[ 3]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 110))) {
t_protect( tmp[ 5]);
tmp[ 6]= list_tail( tmp[ 5]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 112))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_tail( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 114))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_tail( tmp[ 7]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 111))) {
t_protect( tmp[ 8]);
tmp[ 9]= list_tail( tmp[ 8]);
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 116))) {
t_protect( tmp[ 9]);
tmp[ 10]= list_tail( tmp[ 9]);
t_protect( tmp[ 10]);
if( not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 101))) {
t_protect( tmp[ 10]);
tmp[ 11]= list_tail( tmp[ 10]);
t_protect( tmp[ 11]);
if( not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 99))) {
t_protect( tmp[ 11]);
tmp[ 12]= list_tail( tmp[ 11]);
t_protect( tmp[ 12]);
if( is_single_element( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 116))) {
t_protect( atmp10000100);
if( is_single_element( atmp10000100)) {
t_protect( atmp10000100);
tmp[ 13]= list_head( atmp10000100);
t_protect( tmp[ 13]);
t_protect( arg0);
if( term_equal( ( * ef13)( tmp[ 13] , arg0) , ( * ef11)( ))) {
t_protect( tmp[ 13]);
t_protect( arg0);
tmp[ 14]= ( * ef14)( tmp[ 13] , arg0);
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
return tmp[ 14];
}
t_unprotect( tmp[ 13]);
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
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
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
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef15sym)) {
{
aterm * atmp100= arg_0( atmp10);
{
aterm * atmp101= arg_1( atmp10);
if( check_sym( atmp101 , ef4sym)) {
{
aterm * atmp1010= arg_0( atmp101);
if( check_sym( atmp1010 , ef5sym)) {
{
aterm * atmp10100= arg_0( atmp1010);
if( check_sym( atmp10100 , ef6sym)) {
{
aterm * atmp101000= arg_0( atmp10100);
if( check_sym( atmp101000 , ef7sym)) {
{
aterm * atmp1010000= arg_0( atmp101000);
if( check_sym( atmp1010000 , ef8sym)) {
{
aterm * atmp10100000= arg_0( atmp1010000);
if( check_sym( atmp10100000 , lf2sym)) {
{
aterm * atmp101000000= arg_0( atmp10100000);
{
aterm * atmp101001= arg_1( atmp10100);
if( check_sym( atmp101001 , ef9sym)) {
{
aterm * atmp1010010= arg_0( atmp101001);
if( check_sym( atmp1010010 , lf3sym)) {
{
aterm * atmp10100100= arg_0( atmp1010010);
t_protect( atmp101000000);
if( not_empty_list( atmp101000000)) {
t_protect( atmp101000000);
tmp[ 0]= list_head( atmp101000000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 116))) {
t_protect( atmp101000000);
tmp[ 1]= list_tail( atmp101000000);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
tmp[ 2]= list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 95))) {
t_protect( tmp[ 1]);
tmp[ 3]= list_tail( tmp[ 1]);
t_protect( tmp[ 3]);
if( not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 4]= list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 112))) {
t_protect( tmp[ 3]);
tmp[ 5]= list_tail( tmp[ 3]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 114))) {
t_protect( tmp[ 5]);
tmp[ 6]= list_tail( tmp[ 5]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 111))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_tail( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 116))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_tail( tmp[ 7]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 101))) {
t_protect( tmp[ 8]);
tmp[ 9]= list_tail( tmp[ 8]);
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 99))) {
t_protect( tmp[ 9]);
tmp[ 10]= list_tail( tmp[ 9]);
t_protect( tmp[ 10]);
if( is_single_element( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 116))) {
t_protect( atmp10100100);
if( is_single_element( atmp10100100)) {
t_protect( atmp10100100);
tmp[ 11]= list_head( atmp10100100);
t_protect( tmp[ 11]);
t_protect( arg0);
if( term_equal( ( * ef10)( tmp[ 11] , arg0) , ( * ef11)( ))) {
t_protect( tmp[ 11]);
t_protect( arg0);
tmp[ 12]= ( * ef12)( tmp[ 11] , arg0);
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
return lf_AUX_C_Basics4_1( tmp[ 12] , ( * ef2)( atmp100));
}
t_unprotect( tmp[ 11]);
}
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
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 117))) {
t_protect( tmp[ 3]);
tmp[ 5]= list_tail( tmp[ 3]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
if( term_equal( list_head( tmp[ 5]) , make_char( 110))) {
t_protect( tmp[ 5]);
tmp[ 6]= list_tail( tmp[ 5]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 112))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_tail( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 114))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_tail( tmp[ 7]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 111))) {
t_protect( tmp[ 8]);
tmp[ 9]= list_tail( tmp[ 8]);
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
if( term_equal( list_head( tmp[ 9]) , make_char( 116))) {
t_protect( tmp[ 9]);
tmp[ 10]= list_tail( tmp[ 9]);
t_protect( tmp[ 10]);
if( not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
if( term_equal( list_head( tmp[ 10]) , make_char( 101))) {
t_protect( tmp[ 10]);
tmp[ 11]= list_tail( tmp[ 10]);
t_protect( tmp[ 11]);
if( not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
if( term_equal( list_head( tmp[ 11]) , make_char( 99))) {
t_protect( tmp[ 11]);
tmp[ 12]= list_tail( tmp[ 11]);
t_protect( tmp[ 12]);
if( is_single_element( tmp[ 12])) {
t_protect( tmp[ 12]);
if( term_equal( list_head( tmp[ 12]) , make_char( 116))) {
t_protect( atmp10100100);
if( is_single_element( atmp10100100)) {
t_protect( atmp10100100);
tmp[ 13]= list_head( atmp10100100);
t_protect( tmp[ 13]);
t_protect( arg0);
if( term_equal( ( * ef13)( tmp[ 13] , arg0) , ( * ef11)( ))) {
t_protect( tmp[ 13]);
t_protect( arg0);
tmp[ 14]= ( * ef14)( tmp[ 13] , arg0);
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
return lf_AUX_C_Basics4_1( tmp[ 14] , ( * ef2)( atmp100));
}
t_unprotect( tmp[ 13]);
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
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
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
if( check_sym( arg1 , ef1sym)) {
t_unprotect( arg1);
return arg0;
}
if( check_sym( arg0 , ef2sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef3sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp00);
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef15)( atmp00 , atmp100));
}
}
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef15sym)) {
{
aterm * atmp100= arg_0( atmp10);
{
aterm * atmp101= arg_1( atmp10);
t_protect( arg0);
t_protect( atmp100);
tmp[ 0]= lf_AUX_C_Basics4_1( arg0 , ( * ef2)( atmp100));
t_protect( atmp101);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef16)( tmp[ 0] , ( * ef2)( ( * ef3)( atmp101)));
}
}
}
}
}
}
}
}
return make_nf2( lf_AUX_C_Basics4_1sym , arg0 , arg1);
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

