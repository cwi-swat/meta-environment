#include "support.h"
static asymbol * lf_AUX_AFuns6_1sym;
static aterm * lf_AUX_AFuns6_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef10sym;
static funcptr ef10;
void register_AUX_AFuns6( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AFuns6_1sym= TmkSymbol( "prod(id(\"AFuns\"),w(\"\"),[l(\"replace\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AFuns\"),w(\"\"),[l(\"replace\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_AFuns6_1 , lf_AUX_AFuns6_1sym);
}
void resolve_AUX_AFuns6( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"aterm-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"aterm-list\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"rest\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_AFuns6_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[3];
PROF( prof_lf_AUX_AFuns6_1);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
{
aterm * atmp11= arg_1( arg1);
if( m_term_equal( arg0 , atmp10)) {
t_protect( atmp11);
t_unprotect( arg1);
return ( * ef1)( arg2 , ( * ef2)( ( * ef1)( arg0 , atmp11)));
}
else {
t_protect( arg0);
t_protect( atmp11);
t_protect( arg2);
tmp[ 0]= lf_AUX_AFuns6_1( arg0 , ( * ef3)( ( * ef4)( atmp11)) , arg2);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , ef4sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
t_protect( atmp10);
t_protect( tmp[ 2]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
return ( * ef1)( atmp10 , tmp[ 2]);
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
if( check_sym( arg1 , ef3sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef5sym)) {
t_unprotect( arg0);
t_unprotect( arg2);
return arg1;
}
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef4sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( arg0);
t_protect( atmp100);
t_protect( arg2);
t_protect( atmp100);
t_unprotect( arg1);
return ( * ef3)( ( * ef6)( ( * ef4)( ( * ef2)( lf_AUX_AFuns6_1( arg0 , ( * ef7)( ( * ef4)( atmp100)) , arg2))) , ( * ef8)( lf_AUX_AFuns6_1( arg0 , ( * ef3)( ( * ef9)( ( * ef4)( atmp100))) , arg2))));
}
}
}
}
}
if( check_sym( arg1 , ef10sym)) {
{
aterm * atmp10= arg_0( arg1);
{
aterm * atmp11= arg_1( arg1);
t_protect( atmp10);
t_protect( atmp11);
t_unprotect( arg1);
return ( * ef10)( atmp10 , lf_AUX_AFuns6_1( arg0 , atmp11 , arg2));
}
}
}
t_unprotect( arg0);
t_unprotect( arg2);
return arg1;
}
}

