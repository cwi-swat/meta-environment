#include "support.h"
static asymbol * lf_AUX_WfAsFixTerm5_1sym;
static aterm * lf_AUX_WfAsFixTerm5_1( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef20sym;
static funcptr ef20;
void register_AUX_WfAsFixTerm5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_WfAsFixTerm5_1sym= TmkSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm5_1 , lf_AUX_WfAsFixTerm5_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_WfAsFixTerm5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"l\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-asfix-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-type-in-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-type-in-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_WfAsFixTerm5_1( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_WfAsFixTerm5_1);
if( check_sym( arg2 , ef1sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , ef2sym)) {
{
aterm * atmp21= arg_1( arg2);
if( check_sym( atmp21 , ef3sym)) {
{
aterm * atmp210= arg_0( atmp21);
if( check_sym( atmp210 , ef4sym)) {
{
aterm * atmp2100= arg_0( atmp210);
if( check_sym( atmp2100 , ef5sym)) {
{
aterm * atmp21000= arg_0( atmp2100);
if( check_sym( atmp21000 , ef6sym)) {
{
aterm * atmp210000= arg_0( atmp21000);
if( check_sym( atmp210000 , lf2sym)) {
{
aterm * atmp2100000= arg_0( atmp210000);
if( check_sym( arg3 , ef7sym)) {
if( m_not_empty_list( atmp2100000)) {
t_protect( atmp2100000);
if( term_equal( list_head( atmp2100000) , make_char( 34))) {
tmp[ 0]= m_list_tail( atmp2100000);
if( m_not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
if( term_equal( list_head( tmp[ 0]) , make_char( 42))) {
tmp[ 1]= m_list_tail( tmp[ 0]);
if( m_is_single_element( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef8)( );
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
if( check_sym( arg3 , ef9sym)) {
{
aterm * atmp30= arg_0( arg3);
if( check_sym( atmp30 , ef3sym)) {
{
aterm * atmp300= arg_0( atmp30);
t_protect( atmp300);
t_unprotect( arg2);
t_unprotect( arg3);
return ( * ef15)( ( * ef16)( arg0) , ( * ef19)( atmp300) , arg1);
}
}
{
aterm * atmp30= arg_0( arg3);
if( check_sym( atmp30 , ef10sym)) {
{
aterm * atmp300= arg_0( atmp30);
{
aterm * atmp301= arg_1( atmp30);
if( check_sym( atmp301 , ef10sym)) {
{
aterm * atmp3010= arg_0( atmp301);
if( check_sym( atmp3010 , ef1sym)) {
{
aterm * atmp30100= arg_0( atmp3010);
if( check_sym( atmp30100 , ef11sym)) {
{
aterm * atmp30101= arg_1( atmp3010);
if( check_sym( atmp30101 , ef3sym)) {
{
aterm * atmp301010= arg_0( atmp30101);
if( check_sym( atmp301010 , ef4sym)) {
{
aterm * atmp3010100= arg_0( atmp301010);
if( check_sym( atmp3010100 , ef5sym)) {
{
aterm * atmp30101000= arg_0( atmp3010100);
{
aterm * atmp3011= arg_1( atmp301);
if( check_sym( atmp3011 , ef10sym)) {
{
aterm * atmp30110= arg_0( atmp3011);
if( check_sym( atmp30110 , ef1sym)) {
{
aterm * atmp301100= arg_0( atmp30110);
if( check_sym( atmp301100 , ef12sym)) {
{
aterm * atmp301101= arg_1( atmp30110);
if( check_sym( atmp301101 , ef3sym)) {
{
aterm * atmp3011010= arg_0( atmp301101);
if( check_sym( atmp3011010 , ef4sym)) {
{
aterm * atmp30110100= arg_0( atmp3011010);
if( check_sym( atmp30110100 , ef5sym)) {
{
aterm * atmp301101000= arg_0( atmp30110100);
{
aterm * atmp30111= arg_1( atmp3011);
if( check_sym( atmp30111 , ef10sym)) {
{
aterm * atmp301110= arg_0( atmp30111);
if( check_sym( atmp301110 , ef1sym)) {
{
aterm * atmp3011100= arg_0( atmp301110);
if( check_sym( atmp3011100 , ef11sym)) {
{
aterm * atmp3011101= arg_1( atmp301110);
if( check_sym( atmp3011101 , ef3sym)) {
{
aterm * atmp30111010= arg_0( atmp3011101);
if( check_sym( atmp30111010 , ef4sym)) {
{
aterm * atmp301110100= arg_0( atmp30111010);
if( check_sym( atmp301110100 , ef5sym)) {
{
aterm * atmp3011101000= arg_0( atmp301110100);
{
aterm * atmp301111= arg_1( atmp30111);
t_protect( arg1);
t_protect( atmp301101000);
t_protect( arg0);
t_protect( arg0);
t_protect( arg1);
t_protect( atmp301111);
t_unprotect( arg2);
t_unprotect( arg3);
return ( * ef13)( ( * ef13)( ( * ef14)( arg1 , ( * ef1)( ( * ef2)( ) , ( * ef3)( ( * ef4)( ( * ef5)( atmp301101000))))) , ( * ef15)( ( * ef16)( arg0) , ( * ef17)( ( * ef18)( arg0)) , arg1)) , lf_AUX_WfAsFixTerm5_1( arg0 , arg1 , ( * ef1)( ( * ef2)( ) , ( * ef3)( ( * ef4)( ( * ef5)( ( * ef6)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 42)) , make_list( make_char( 34)))))))))) , ( * ef9)( atmp301111)));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if( m_term_equal( arg0 , arg3)) {
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
return ( * ef20)( );
}
return make_nf4( lf_AUX_WfAsFixTerm5_1sym , arg0 , arg1 , arg2 , arg3);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

