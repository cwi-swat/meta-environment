#include "support.h"
static asymbol * lf_AUX_ATermLists5_1sym;
static aterm * lf_AUX_ATermLists5_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_ATermLists5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ATermLists5_1sym= TmkSymbol( "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))") , lf_AUX_ATermLists5_1 , lf_AUX_ATermLists5_1sym);
}
void resolve_AUX_ATermLists5( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"aterms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"aterms\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_ATermLists5_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_ATermLists5_1);
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
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp000);
t_protect( atmp10);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( ( * ef4)( atmp000 , atmp10));
}
}
}
}
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , ef4sym)) {
{
aterm * atmp000= arg_0( atmp00);
{
aterm * atmp001= arg_1( atmp00);
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp000);
t_protect( atmp001);
t_unprotect( arg0);
return ( * ef2)( ( * ef4)( atmp000 , ( * ef5)( ( * ef6)( lf_AUX_ATermLists5_1( ( * ef2)( atmp001) , arg1)))));
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
return make_nf2( lf_AUX_ATermLists5_1sym , arg0 , arg1);
}

