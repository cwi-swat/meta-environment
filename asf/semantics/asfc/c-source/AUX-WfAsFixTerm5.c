#include "support.h"
static Symbol lf_AUX_WfAsFixTerm5_1sym;
static ATerm lf_AUX_WfAsFixTerm5_1( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4);
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef8sym;
static funcptr ef8;
static Symbol ef12sym;
static funcptr ef12;
static Symbol ef10sym;
static funcptr ef10;
static Symbol ef11sym;
static funcptr ef11;
static Symbol ef13sym;
static funcptr ef13;
static Symbol ef14sym;
static funcptr ef14;
static Symbol ef17sym;
static funcptr ef17;
static Symbol ef18sym;
static funcptr ef18;
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef9sym;
static funcptr ef9;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef15sym;
static funcptr ef15;
static Symbol ef16sym;
static funcptr ef16;
static Symbol ef19sym;
static funcptr ef19;
static Symbol ef20sym;
static funcptr ef20;
void register_AUX_WfAsFixTerm5( ) {
lf_AUX_WfAsFixTerm5_1sym= ATmakeSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 4 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFixTerm5_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm5_1 , lf_AUX_WfAsFixTerm5_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_WfAsFixTerm5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef8= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef10= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef11= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef13sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef14= lookup_func( ATreadFromString( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( ATreadFromString( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef15= lookup_func( ATreadFromString( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-type-in-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( ATreadFromString( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-type-in-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17= lookup_func( ATreadFromString( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( ATreadFromString( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18= lookup_func( ATreadFromString( "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( ATreadFromString( "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef19= lookup_func( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( ATreadFromString( "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef20= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
void init_AUX_WfAsFixTerm5( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
}
ATerm lf_AUX_WfAsFixTerm5_1( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3) {
{
ATerm tmp[2];
PROF( prof_lf_AUX_WfAsFixTerm5_1);
if( check_sym( arg2 , ef1sym)) {
{
ATerm atmp20= arg_0( arg2);
if( check_sym( atmp20 , ef2sym)) {
{
ATerm atmp21= arg_1( arg2);
if( check_sym( atmp21 , ef3sym)) {
{
ATerm atmp210= arg_0( atmp21);
if( check_sym( atmp210 , ef4sym)) {
{
ATerm atmp2100= arg_0( atmp210);
if( check_sym( atmp2100 , ef5sym)) {
{
ATerm atmp21000= arg_0( atmp2100);
if( check_sym( atmp21000 , ef6sym)) {
{
ATerm atmp210000= arg_0( atmp21000);
if( check_sym( atmp210000 , lf2sym)) {
{
ATerm atmp2100000= arg_0( atmp210000);
if( check_sym( arg3 , ef7sym)) {
if( not_empty_list( atmp2100000)) {
if( term_equal( list_head( atmp2100000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp2100000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 42))) {
tmp[ 1]= list_tail( tmp[ 0]);
if( is_single_element( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
return ( constant0? constant0: ( constant0= ( * ef8)( )));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if( check_sym( arg3 , ef9sym)) {
{
ATerm atmp30= arg_0( arg3);
if( check_sym( atmp30 , ef3sym)) {
{
ATerm atmp300= arg_0( atmp30);
return ( * ef15)( ( * ef16)( arg0) , ( * ef19)( atmp300) , arg1);
}
}
{
ATerm atmp30= arg_0( arg3);
if( check_sym( atmp30 , ef10sym)) {
{
ATerm atmp300= arg_0( atmp30);
{
ATerm atmp301= arg_1( atmp30);
if( check_sym( atmp301 , ef10sym)) {
{
ATerm atmp3010= arg_0( atmp301);
if( check_sym( atmp3010 , ef1sym)) {
{
ATerm atmp30100= arg_0( atmp3010);
if( check_sym( atmp30100 , ef11sym)) {
{
ATerm atmp30101= arg_1( atmp3010);
if( check_sym( atmp30101 , ef3sym)) {
{
ATerm atmp301010= arg_0( atmp30101);
if( check_sym( atmp301010 , ef4sym)) {
{
ATerm atmp3010100= arg_0( atmp301010);
if( check_sym( atmp3010100 , ef5sym)) {
{
ATerm atmp30101000= arg_0( atmp3010100);
{
ATerm atmp3011= arg_1( atmp301);
if( check_sym( atmp3011 , ef10sym)) {
{
ATerm atmp30110= arg_0( atmp3011);
if( check_sym( atmp30110 , ef1sym)) {
{
ATerm atmp301100= arg_0( atmp30110);
if( check_sym( atmp301100 , ef12sym)) {
{
ATerm atmp301101= arg_1( atmp30110);
if( check_sym( atmp301101 , ef3sym)) {
{
ATerm atmp3011010= arg_0( atmp301101);
if( check_sym( atmp3011010 , ef4sym)) {
{
ATerm atmp30110100= arg_0( atmp3011010);
if( check_sym( atmp30110100 , ef5sym)) {
{
ATerm atmp301101000= arg_0( atmp30110100);
{
ATerm atmp30111= arg_1( atmp3011);
if( check_sym( atmp30111 , ef10sym)) {
{
ATerm atmp301110= arg_0( atmp30111);
if( check_sym( atmp301110 , ef1sym)) {
{
ATerm atmp3011100= arg_0( atmp301110);
if( check_sym( atmp3011100 , ef11sym)) {
{
ATerm atmp3011101= arg_1( atmp301110);
if( check_sym( atmp3011101 , ef3sym)) {
{
ATerm atmp30111010= arg_0( atmp3011101);
if( check_sym( atmp30111010 , ef4sym)) {
{
ATerm atmp301110100= arg_0( atmp30111010);
if( check_sym( atmp301110100 , ef5sym)) {
{
ATerm atmp3011101000= arg_0( atmp301110100);
{
ATerm atmp301111= arg_1( atmp30111);
return ( * ef13)( ( * ef13)( ( * ef14)( arg1 , ( * ef1)( ( constant1? constant1: ( constant1= ( * ef2)( ))) , ( * ef3)( ( * ef4)( ( * ef5)( atmp301101000))))) , ( * ef15)( ( * ef16)( arg0) , ( * ef17)( ( * ef18)( arg0)) , arg1)) , lf_AUX_WfAsFixTerm5_1( arg0 , arg1 , ( constant2? constant2: ( constant2= ( * ef1)( ( * ef2)( ) , ( * ef3)( ( * ef4)( ( * ef5)( ( * ef6)( lf2( (ATerm) ATmakeList( 3 , char_table[ 34] , char_table[ 42] , char_table[ 34]))))))))) , ( * ef9)( atmp301111)));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if( term_equal( arg0 , arg3)) {
return ( constant3? constant3: ( constant3= ( * ef20)( )));
}
return make_nf4( lf_AUX_WfAsFixTerm5_1sym , arg0 , arg1 , arg2 , arg3);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

