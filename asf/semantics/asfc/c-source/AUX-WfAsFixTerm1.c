#include "support.h"
static Symbol lf_AUX_WfAsFixTerm1_1sym;
static ATerm lf_AUX_WfAsFixTerm1_1( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef14sym;
static funcptr ef14;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef17sym;
static funcptr ef17;
static Symbol ef18sym;
static funcptr ef18;
static Symbol ef15sym;
static funcptr ef15;
static Symbol ef16sym;
static funcptr ef16;
static Symbol ef5sym;
static funcptr ef5;
void register_AUX_WfAsFixTerm1( ) {
lf_AUX_WfAsFixTerm1_1sym= ATmakeSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFixTerm1_1sym);
register_prod( ATparse( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm1_1 , lf_AUX_WfAsFixTerm1_1sym);
}
void resolve_AUX_WfAsFixTerm1( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"AsFixParseTrees\"),w(\"\"),[ql(\"ql\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"Literals\"),w(\"\"),[l(\"de-escape\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"Literals\"),w(\"\"),[l(\"de-escape\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef15= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef16= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef17= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef18= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef18sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
void init_AUX_WfAsFixTerm1( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
}
ATerm lf_AUX_WfAsFixTerm1_1( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_WfAsFixTerm1_1);
if( check_sym( arg0 , ef7sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef8sym)) {
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef9sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef3sym)) {
{
ATerm atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef10sym)) {
{
ATerm atmp01000= arg_0( atmp0100);
return lf_AUX_WfAsFixTerm1_1( ( * ef7)( ( constant0? constant0: ( constant0= ( * ef11)( ))) , ( * ef9)( ( * ef3)( ( * ef10)( ( * ef12)( atmp01000))))) , arg1);
}
}
}
}
}
}
}
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef13sym)) {
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef9sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef3sym)) {
{
ATerm atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef10sym)) {
{
ATerm atmp01000= arg_0( atmp0100);
return lf_AUX_WfAsFixTerm1_1( ( * ef7)( ( constant0? constant0: ( constant0= ( * ef11)( ))) , ( * ef9)( ( * ef3)( ( * ef10)( atmp01000)))) , arg1);
}
}
}
}
}
}
}
}
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef14sym)) {
{
ATerm atmp01= arg_1( arg0);
if( check_sym( atmp01 , ef9sym)) {
{
ATerm atmp010= arg_0( atmp01);
if( check_sym( atmp010 , ef3sym)) {
{
ATerm atmp0100= arg_0( atmp010);
if( check_sym( atmp0100 , ef10sym)) {
{
ATerm atmp01000= arg_0( atmp0100);
if( check_sym( arg1 , ef7sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef14sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef9sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef3sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef10sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
return ( constant1? constant1: ( constant1= ( * ef6)( )));
}
}
}
}
}
}
}
}
}
}
}
}
}
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
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef16sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef9sym)) {
{
ATerm atmp0000= arg_0( atmp000);
if( check_sym( arg1 , ef15sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef16sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef9sym)) {
{
ATerm atmp1000= arg_0( atmp100);
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
ATerm atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef17sym)) {
{
ATerm atmp0000= arg_0( atmp000);
{
ATerm atmp0001= arg_1( atmp000);
if( check_sym( arg1 , ef15sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef16sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef17sym)) {
{
ATerm atmp1000= arg_0( atmp100);
{
ATerm atmp1001= arg_1( atmp100);
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
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef8sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef9sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef3sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef10sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
return lf_AUX_WfAsFixTerm1_1( arg0 , ( * ef7)( ( constant0? constant0: ( constant0= ( * ef11)( ))) , ( * ef9)( ( * ef3)( ( * ef10)( ( * ef12)( atmp11000))))));
}
}
}
}
}
}
}
}
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef13sym)) {
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef9sym)) {
{
ATerm atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef3sym)) {
{
ATerm atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef10sym)) {
{
ATerm atmp11000= arg_0( atmp1100);
return lf_AUX_WfAsFixTerm1_1( arg0 , ( * ef7)( ( constant0? constant0: ( constant0= ( * ef11)( ))) , ( * ef9)( ( * ef3)( ( * ef10)( atmp11000)))));
}
}
}
}
}
}
}
}
}
}
}
if( term_equal( arg0 , arg1)) {
return ( * ef1)( ( * ef2)( arg0 , ( constant2? constant2: ( constant2= ( * ef3)( ( * ef4)( ))))) , ( constant3? constant3: ( constant3= ( * ef5)( ))) , ( constant1? constant1: ( constant1= ( * ef6)( ))));
}
return ( constant3? constant3: ( constant3= ( * ef5)( )));
}

