#include "support.h"
static asymbol * lf_AUX_C_Basics5_1sym;
static aterm * lf_AUX_C_Basics5_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_C_Basics5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics5_1sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++r\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++r\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics5_1 , lf_AUX_C_Basics5_1sym);
}
void resolve_AUX_C_Basics5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[l(\"return\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\";\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\"),w(\"\"),sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_C_Basics5_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_C_Basics5_1);
if( check_sym( arg0 , ef1sym)) {
t_unprotect( arg0);
return arg1;
}
if( check_sym( arg0 , ef2sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef3sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef4sym)) {
{
aterm * atmp0000= arg_0( atmp000);
t_protect( atmp0000);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( ( * ef4)( atmp0000)));
}
}
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( atmp000 , ef6sym)) {
{
aterm * atmp0000= arg_0( atmp000);
if( check_sym( atmp0000 , ef7sym)) {
{
aterm * atmp0001= arg_1( atmp000);
if( check_sym( atmp0001 , ef2sym)) {
{
aterm * atmp00010= arg_0( atmp0001);
if( check_sym( atmp00010 , ef3sym)) {
{
aterm * atmp000100= arg_0( atmp00010);
if( check_sym( atmp000100 , ef4sym)) {
{
aterm * atmp0001000= arg_0( atmp000100);
t_protect( atmp0001000);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( ( * ef6)( ( * ef7)( ) , ( * ef2)( ( * ef3)( ( * ef4)( atmp0001000))))));
}
}
}
}
{
aterm * atmp00010= arg_0( atmp0001);
if( check_sym( atmp00010 , ef5sym)) {
{
aterm * atmp000100= arg_0( atmp00010);
{
aterm * atmp000101= arg_1( atmp00010);
if( check_sym( atmp000101 , ef4sym)) {
{
aterm * atmp0001010= arg_0( atmp000101);
t_protect( atmp000100);
t_protect( atmp0001010);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( ( * ef6)( ( * ef7)( ) , ( * ef2)( ( * ef5)( atmp000100 , ( * ef4)( atmp0001010))))));
}
}
}
}
}
}
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
{
aterm * atmp001= arg_1( atmp00);
if( check_sym( atmp001 , ef4sym)) {
{
aterm * atmp0010= arg_0( atmp001);
t_protect( atmp000);
t_protect( atmp0010);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef5)( atmp000 , ( * ef4)( atmp0010)));
}
}
{
aterm * atmp001= arg_1( atmp00);
if( check_sym( atmp001 , ef6sym)) {
{
aterm * atmp0010= arg_0( atmp001);
if( check_sym( atmp0010 , ef7sym)) {
{
aterm * atmp0011= arg_1( atmp001);
if( check_sym( atmp0011 , ef2sym)) {
{
aterm * atmp00110= arg_0( atmp0011);
if( check_sym( atmp00110 , ef3sym)) {
{
aterm * atmp001100= arg_0( atmp00110);
if( check_sym( atmp001100 , ef4sym)) {
{
aterm * atmp0011000= arg_0( atmp001100);
t_protect( atmp000);
t_protect( atmp0011000);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef5)( atmp000 , ( * ef6)( ( * ef7)( ) , ( * ef2)( ( * ef3)( ( * ef4)( atmp0011000))))));
}
}
}
}
{
aterm * atmp00110= arg_0( atmp0011);
if( check_sym( atmp00110 , ef5sym)) {
{
aterm * atmp001100= arg_0( atmp00110);
{
aterm * atmp001101= arg_1( atmp00110);
if( check_sym( atmp001101 , ef4sym)) {
{
aterm * atmp0011010= arg_0( atmp001101);
t_protect( atmp000);
t_protect( atmp001100);
t_protect( atmp0011010);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef5)( atmp000 , ( * ef6)( ( * ef7)( ) , ( * ef2)( ( * ef5)( atmp001100 , ( * ef4)( atmp0011010))))));
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef2sym)) {
{
aterm * atmp00= arg_0( arg0);
return ( * ef8)( arg0 , arg1);
}
}
return make_nf2( lf_AUX_C_Basics5_1sym , arg0 , arg1);
}

