#include "support.h"
static asymbol * lf_AUX_Matching1_1sym;
static aterm * lf_AUX_Matching1_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef19sym;
static funcptr ef19;
void register_AUX_Matching1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Matching1_1sym= TmkSymbol( "prod(id(\"Matching\"),w(\"\"),[l(\"match1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Subs\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Matching\"),w(\"\"),[l(\"match1\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Subs\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)") , lf_AUX_Matching1_1 , lf_AUX_Matching1_1sym);
}
void resolve_AUX_Matching1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Matching\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Matching\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Substitution\"),w(\"\"),[l(\"assign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Substitution\"),w(\"\"),[l(\"assign\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Substitution\"),w(\"\"),[l(\"undefined\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Substitution\"),w(\"\"),[l(\"undefined\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"require-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"require-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"Substitution\"),w(\"\"),[l(\"value\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Substitution\"),w(\"\"),[l(\"value\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AVar\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Matching\"),w(\"\"),[l(\"nomatch\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Matching\"),w(\"\"),[l(\"nomatch\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Matching1_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_Matching1_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( m_term_equal( atmp00 , atmp10)) {
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
}
}
}
}
}
}
if( check_sym( arg0 , ef3sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef4sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef3sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef4sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( m_term_equal( atmp000 , atmp100)) {
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
}
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef5sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp00);
t_protect( atmp20);
if( term_equal( ( * ef7)( atmp00 , atmp20) , ( * ef8)( ))) {
t_protect( arg0);
t_protect( arg1);
if( term_equal( ( * ef9)( ( * ef10)( arg0) , arg1) , ( * ef8)( ))) {
t_protect( atmp00);
t_protect( atmp20);
t_unprotect( arg0);
t_unprotect( arg2);
return ( * ef2)( ( * ef6)( atmp00 , atmp20 , arg1));
}
}
t_protect( atmp00);
t_protect( atmp20);
t_protect( arg1);
if( term_equal( ( * ef11)( atmp00 , atmp20) , arg1)) {
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
}
}
}
}
if( check_sym( arg0 , ef12sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( arg1 , ef12sym)) {
{
aterm * atmp10= arg_0( arg1);
{
aterm * atmp11= arg_1( arg1);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( m_term_equal( atmp00 , atmp10)) {
t_protect( atmp01);
t_protect( atmp11);
t_unprotect( arg0);
t_unprotect( arg1);
return lf_AUX_Matching1_1( ( * ef13)( ( * ef14)( atmp01)) , ( * ef13)( ( * ef14)( atmp11)) , arg2);
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef13sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef15sym)) {
if( check_sym( arg1 , ef13sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef15sym)) {
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
}
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef14sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef13sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef14sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp000);
t_protect( atmp100);
t_protect( arg2);
tmp[ 0]= lf_AUX_Matching1_1( ( * ef17)( ( * ef14)( atmp000)) , ( * ef17)( ( * ef14)( atmp100)) , arg2);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
t_protect( atmp000);
t_protect( atmp100);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
return lf_AUX_Matching1_1( ( * ef13)( ( * ef16)( ( * ef14)( atmp000))) , ( * ef13)( ( * ef16)( ( * ef14)( atmp100))) , ( * ef2)( tmp[ 1]));
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
if( check_sym( arg0 , ef18sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp00);
t_protect( arg1);
if( term_equal( ( * ef9)( atmp00 , arg1) , ( * ef8)( ))) {
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
}
}
}
}
if( check_sym( arg1 , ef5sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp10);
t_protect( atmp20);
if( term_equal( ( * ef7)( atmp10 , atmp20) , ( * ef8)( ))) {
t_protect( arg1);
t_protect( arg0);
if( term_equal( ( * ef9)( ( * ef10)( arg1) , arg0) , ( * ef8)( ))) {
t_protect( atmp10);
t_protect( atmp20);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef2)( ( * ef6)( atmp10 , atmp20 , arg0));
}
}
t_protect( atmp10);
t_protect( atmp20);
t_protect( arg0);
if( term_equal( ( * ef11)( atmp10 , atmp20) , arg0)) {
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
}
}
}
}
if( check_sym( arg1 , ef18sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_protect( atmp10);
t_protect( arg0);
if( term_equal( ( * ef9)( atmp10 , arg0) , ( * ef8)( ))) {
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
}
}
}
}
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( m_term_equal( arg0 , arg1)) {
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
}
}
if( check_sym( arg2 , ef2sym)) {
{
aterm * atmp20= arg_0( arg2);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef19)( );
}
}
return make_nf3( lf_AUX_Matching1_1sym , arg0 , arg1 , arg2);
}
}

