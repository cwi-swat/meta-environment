#include "support.h"
static asymbol * lf_AUX_C_Basics7_1sym;
static aterm * lf_AUX_C_Basics7_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_C_Basics7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics7_1sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++d\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics7_1 , lf_AUX_C_Basics7_1sym);
}
void resolve_AUX_C_Basics7( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Statement\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_C_Basics7_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_C_Basics7_1);
if( check_sym( arg0 , ef1sym)) {
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef3sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef4sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef1sym)) {
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef2sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
t_protect( atmp10010);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( atmp10010);
}
}
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
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef3sym)) {
{
aterm * atmp100= arg_0( atmp10);
if( check_sym( atmp100 , ef4sym)) {
{
aterm * atmp1000= arg_0( atmp100);
if( check_sym( atmp1000 , ef1sym)) {
{
aterm * atmp1001= arg_1( atmp100);
if( check_sym( atmp1001 , ef2sym)) {
{
aterm * atmp10010= arg_0( atmp1001);
t_protect( atmp10010);
t_unprotect( arg1);
return ( * ef2)( ( * ef3)( ( * ef4)( arg0 , ( * ef2)( atmp10010))));
}
}
}
}
}
}
}
}
}
}
}
}
if( check_sym( arg0 , ef1sym)) {
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
t_unprotect( arg0);
return arg1;
}
}
}
if( check_sym( arg0 , ef5sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
return ( * ef2)( ( * ef3)( ( * ef4)( arg0 , arg1)));
}
}
}
}
return make_nf2( lf_AUX_C_Basics7_1sym , arg0 , arg1);
}

