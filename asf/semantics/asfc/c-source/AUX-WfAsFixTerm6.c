#include "support.h"
static asymbol * lf_AUX_WfAsFixTerm6_1sym;
static aterm * lf_AUX_WfAsFixTerm6_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef16sym;
static funcptr ef16;
void register_AUX_WfAsFixTerm6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_WfAsFixTerm6_1sym= TmkSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"match-list-type\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm6_1 , lf_AUX_WfAsFixTerm6_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_WfAsFixTerm6( ) {
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
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"/\\\\\\\\\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-type-in-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"eq-type-in-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-of\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_WfAsFixTerm6_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[2];
PROF( prof_lf_AUX_WfAsFixTerm6_1);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef2sym)) {
{
aterm * atmp11= arg_1( arg1);
if( check_sym( atmp11 , ef3sym)) {
{
aterm * atmp110= arg_0( atmp11);
if( check_sym( atmp110 , ef4sym)) {
{
aterm * atmp1100= arg_0( atmp110);
if( check_sym( atmp1100 , ef5sym)) {
{
aterm * atmp11000= arg_0( atmp1100);
if( check_sym( atmp11000 , ef6sym)) {
{
aterm * atmp110000= arg_0( atmp11000);
if( check_sym( atmp110000 , lf2sym)) {
{
aterm * atmp1100000= arg_0( atmp110000);
if( check_sym( arg2 , ef7sym)) {
if( m_not_empty_list( atmp1100000)) {
t_protect( atmp1100000);
if( term_equal( list_head( atmp1100000) , make_char( 34))) {
tmp[ 0]= m_list_tail( atmp1100000);
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
if( check_sym( arg2 , ef9sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , ef3sym)) {
{
aterm * atmp200= arg_0( atmp20);
t_protect( atmp200);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef13)( arg0 , ( * ef15)( atmp200) , ( * ef1)( ( * ef2)( ) , ( * ef3)( ( * ef4)( ( * ef5)( ( * ef6)( lf2( cons( make_list( make_char( 34)) , make_list( make_char( 34))))))))));
}
}
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , ef10sym)) {
{
aterm * atmp200= arg_0( atmp20);
{
aterm * atmp201= arg_1( atmp20);
if( check_sym( atmp201 , ef10sym)) {
{
aterm * atmp2010= arg_0( atmp201);
if( check_sym( atmp2010 , ef1sym)) {
{
aterm * atmp20100= arg_0( atmp2010);
if( check_sym( atmp20100 , ef11sym)) {
{
aterm * atmp20101= arg_1( atmp2010);
if( check_sym( atmp20101 , ef3sym)) {
{
aterm * atmp201010= arg_0( atmp20101);
if( check_sym( atmp201010 , ef4sym)) {
{
aterm * atmp2010100= arg_0( atmp201010);
if( check_sym( atmp2010100 , ef5sym)) {
{
aterm * atmp20101000= arg_0( atmp2010100);
{
aterm * atmp2011= arg_1( atmp201);
t_protect( arg0);
t_protect( atmp200);
t_protect( atmp2011);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef12)( ( * ef13)( arg0 , ( * ef14)( atmp200) , ( * ef1)( ( * ef2)( ) , ( * ef3)( ( * ef4)( ( * ef5)( ( * ef6)( lf2( cons( make_list( make_char( 34)) , make_list( make_char( 34)))))))))) , lf_AUX_WfAsFixTerm6_1( arg0 , ( * ef1)( ( * ef2)( ) , ( * ef3)( ( * ef4)( ( * ef5)( ( * ef6)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 42)) , make_list( make_char( 34)))))))))) , ( * ef9)( atmp2011)));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef16)( );
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

