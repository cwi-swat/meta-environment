#include "support.h"
static asymbol * lf_AUX_ParseTrees11_1sym;
static aterm * lf_AUX_ParseTrees11_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef5sym;
static funcptr ef5;
void register_AUX_ParseTrees11( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ParseTrees11_1sym= TmkSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\":=\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees11_1 , lf_AUX_ParseTrees11_1sym);
}
void resolve_AUX_ParseTrees11( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"init\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"init\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"replace\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[l(\"replace\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"position\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ParseTrees\"),w(\"\"),[l(\"position\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_ParseTrees11_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[5];
PROF( prof_lf_AUX_ParseTrees11_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
t_protect( atmp01);
t_unprotect( arg0);
return ( * ef1)( atmp00 , lf_AUX_ParseTrees11_1( atmp01 , arg1 , arg2));
}
}
}
if( check_sym( arg0 , ef2sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
tmp[ 0]= ( * ef3)( atmp00);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
if( m_term_equal( atmp00 , tmp[ 1])) {
t_protect( atmp01);
t_protect( arg1);
t_protect( tmp[ 2]);
t_protect( arg2);
tmp[ 3]= ( * ef4)( ( * ef5)( atmp01) , ( * ef6)( arg1 , ( * ef5)( tmp[ 2]) , ( * ef7)( )) , arg2);
if( check_sym( tmp[ 3] , ef5sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
t_protect( atmp00);
t_protect( tmp[ 4]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
return ( * ef2)( atmp00 , tmp[ 4]);
}
t_unprotect( tmp[ 3]);
}
}
t_unprotect( tmp[ 0]);
}
}
}
return make_nf3( lf_AUX_ParseTrees11_1sym , arg0 , arg1 , arg2);
}
}

