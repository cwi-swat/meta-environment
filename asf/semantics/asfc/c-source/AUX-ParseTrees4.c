#include "support.h"
static asymbol * lf_AUX_ParseTrees4_1sym;
static aterm * lf_AUX_ParseTrees4_1( aterm * arg1);
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef9sym;
static funcptr ef9;
void register_AUX_ParseTrees4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ParseTrees4_1sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"get-list-tail-with-sep\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees4_1 , lf_AUX_ParseTrees4_1sym);
}
void resolve_AUX_ParseTrees4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"w\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[ql(\"sep\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_ParseTrees4_1( aterm * arg0) {
PROF( prof_lf_AUX_ParseTrees4_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef2sym)) {
{
aterm * atmp000= arg_0( atmp00);
{
aterm * atmp001= arg_1( atmp00);
if( check_sym( atmp001 , ef2sym)) {
{
aterm * atmp0010= arg_0( atmp001);
if( check_sym( atmp0010 , ef3sym)) {
{
aterm * atmp00100= arg_0( atmp0010);
if( check_sym( atmp00100 , ef4sym)) {
{
aterm * atmp00101= arg_1( atmp0010);
if( check_sym( atmp00101 , ef5sym)) {
{
aterm * atmp001010= arg_0( atmp00101);
if( check_sym( atmp001010 , ef6sym)) {
{
aterm * atmp0010100= arg_0( atmp001010);
if( check_sym( atmp0010100 , ef7sym)) {
{
aterm * atmp00101000= arg_0( atmp0010100);
{
aterm * atmp0011= arg_1( atmp001);
if( check_sym( atmp0011 , ef2sym)) {
{
aterm * atmp00110= arg_0( atmp0011);
if( check_sym( atmp00110 , ef3sym)) {
{
aterm * atmp001100= arg_0( atmp00110);
if( check_sym( atmp001100 , ef8sym)) {
{
aterm * atmp001101= arg_1( atmp00110);
if( check_sym( atmp001101 , ef5sym)) {
{
aterm * atmp0011010= arg_0( atmp001101);
if( check_sym( atmp0011010 , ef6sym)) {
{
aterm * atmp00110100= arg_0( atmp0011010);
if( check_sym( atmp00110100 , ef7sym)) {
{
aterm * atmp001101000= arg_0( atmp00110100);
{
aterm * atmp00111= arg_1( atmp0011);
if( check_sym( atmp00111 , ef2sym)) {
{
aterm * atmp001110= arg_0( atmp00111);
if( check_sym( atmp001110 , ef3sym)) {
{
aterm * atmp0011100= arg_0( atmp001110);
if( check_sym( atmp0011100 , ef4sym)) {
{
aterm * atmp0011101= arg_1( atmp001110);
if( check_sym( atmp0011101 , ef5sym)) {
{
aterm * atmp00111010= arg_0( atmp0011101);
if( check_sym( atmp00111010 , ef6sym)) {
{
aterm * atmp001110100= arg_0( atmp00111010);
if( check_sym( atmp001110100 , ef7sym)) {
{
aterm * atmp0011101000= arg_0( atmp001110100);
{
aterm * atmp001111= arg_1( atmp00111);
t_protect( atmp00101000);
t_protect( atmp001101000);
t_protect( atmp0011101000);
t_protect( atmp001111);
t_unprotect( arg0);
return ( * ef1)( ( * ef2)( ( * ef3)( ( * ef4)( ) , ( * ef5)( ( * ef6)( ( * ef7)( atmp00101000)))) , ( * ef2)( ( * ef3)( ( * ef8)( ) , ( * ef5)( ( * ef6)( ( * ef7)( atmp001101000)))) , ( * ef2)( ( * ef3)( ( * ef4)( ) , ( * ef5)( ( * ef6)( ( * ef7)( atmp0011101000)))) , atmp001111))));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
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
if( check_sym( atmp00 , ef5sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_unprotect( arg0);
return ( * ef9)( );
}
}
}
}
}
return make_nf1( lf_AUX_ParseTrees4_1sym , arg0);
}

