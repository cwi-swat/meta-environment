#include "support.h"
static asymbol * lf_AUX_WfAsFixTerm1_1sym;
static aterm * lf_AUX_WfAsFixTerm1_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef5sym;
static funcptr ef5;
void register_AUX_WfAsFixTerm1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_WfAsFixTerm1_1sym= TmkSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm1_1 , lf_AUX_WfAsFixTerm1_1sym);
}
void resolve_AUX_WfAsFixTerm1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Literals\"),w(\"\"),[l(\"de-escape\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Literals\"),w(\"\"),[l(\"de-escape\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_WfAsFixTerm1_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_WfAsFixTerm1_1);
if( check_sym( arg0 , ef7sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef8sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef9sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef3sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef10sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
t_protect( atmp01000);
t_unprotect( arg0);
return lf_AUX_WfAsFixTerm1_1( ( * ef7)( ( * ef11)( ) , ( * ef9)( ( * ef3)( ( * ef10)( ( * ef12)( atmp01000))))) , arg1);
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
if( check_sym( atmp00 , ef13sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef9sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef3sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef10sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
t_protect( atmp01000);
t_unprotect( arg0);
return lf_AUX_WfAsFixTerm1_1( ( * ef7)( ( * ef11)( ) , ( * ef9)( ( * ef3)( ( * ef10)( atmp01000)))) , arg1);
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
if( check_sym( atmp00 , ef14sym)) {
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef9sym)) {
{
aterm * atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef3sym)) {
{
aterm * atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef10sym)) {
{
aterm * atmp01000= arg_0( atmp0100);
if( check_sym( arg1 , ef7sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef14sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef9sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef3sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef10sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef6)( );
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef15sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef16sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef9sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( arg1 , ef15sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef16sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef9sym)) {
{
aterm * atmp1000= arg_0( atmp100);
t_protect( atmp0000);
t_protect( atmp1000);
t_unprotect( arg0);
t_unprotect( arg1);
return lf_AUX_WfAsFixTerm1_1( atmp0000 , atmp1000);
}
}
}
}
}
}
}
}
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef17sym)) {
{
aterm * atmp0000= arg_0( atmp000);
{
aterm * atmp0001= arg_1( atmp000);
if( check_sym( arg1 , ef15sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef16sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef17sym)) {
{
aterm * atmp1000= arg_0( atmp100);
{
aterm * atmp1001= arg_1( atmp100);
t_protect( atmp0000);
t_protect( atmp1000);
t_protect( atmp0001);
t_protect( atmp1001);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef18)( lf_AUX_WfAsFixTerm1_1( atmp0000 , atmp1000) , lf_AUX_WfAsFixTerm1_1( ( * ef15)( ( * ef16)( atmp0001)) , ( * ef15)( ( * ef16)( atmp1001))));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if( check_sym( arg1 , ef7sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef8sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef9sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef3sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef10sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
t_protect( atmp11000);
t_unprotect( arg1);
return lf_AUX_WfAsFixTerm1_1( arg0 , ( * ef7)( ( * ef11)( ) , ( * ef9)( ( * ef3)( ( * ef10)( ( * ef12)( atmp11000))))));
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
if( check_sym( atmp10 , ef13sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef9sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef3sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef10sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
t_protect( atmp11000);
t_unprotect( arg1);
return lf_AUX_WfAsFixTerm1_1( arg0 , ( * ef7)( ( * ef11)( ) , ( * ef9)( ( * ef3)( ( * ef10)( atmp11000)))));
}
}
}
}
}
}
}
}
}
}
}
t_protect( arg0);
t_protect( arg1);
if( term_equal( arg0 , arg1)) {
t_unprotect( arg1);
return ( * ef1)( ( * ef2)( arg0 , ( * ef3)( ( * ef4)( ))) , ( * ef5)( ) , ( * ef6)( ));
}
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef5)( );
}

