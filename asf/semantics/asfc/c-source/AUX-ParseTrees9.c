#include "support.h"
static asymbol * lf_AUX_ParseTrees9_1sym;
static aterm * lf_AUX_ParseTrees9_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef3sym;
static funcptr ef3;
void register_AUX_ParseTrees9( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ParseTrees9_1sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"named-elem\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"named-elem\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees9_1 , lf_AUX_ParseTrees9_1sym);
}
void resolve_AUX_ParseTrees9( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"first\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_ParseTrees9_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_ParseTrees9_1);
t_protect( arg1);
t_protect( arg0);
if( term_equal( ( * ef1)( arg1) , ( * ef2)( arg0))) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( arg2);
}
if( check_sym( arg1 , ef3sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , ef4sym)) {
{
aterm * atmp100= arg_0( atmp10);
{
aterm * atmp101= arg_1( atmp10);
if( check_sym( arg2 , ef3sym)) {
{
aterm * atmp20= arg_0( arg2);
if( check_sym( atmp20 , ef4sym)) {
{
aterm * atmp200= arg_0( atmp20);
{
aterm * atmp201= arg_1( atmp20);
t_protect( atmp101);
t_protect( atmp201);
t_unprotect( arg1);
t_unprotect( arg2);
return lf_AUX_ParseTrees9_1( arg0 , ( * ef3)( atmp101) , ( * ef3)( atmp201));
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
return make_nf3( lf_AUX_ParseTrees9_1sym , arg0 , arg1 , arg2);
}

