#include "support.h"
static asymbol * lf_AUX_Grammars1_1sym;
static aterm * lf_AUX_Grammars1_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Grammars1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Grammars1_1sym= TmkSymbol( "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Symbol\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[sort(\"Symbols\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Symbols\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))") , lf_AUX_Grammars1_1 , lf_AUX_Grammars1_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Symbol\"))") , lf2 , lf2sym);
}
void resolve_AUX_Grammars1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Grammars\"),w(\"\"),[iter(sort(\"Symbol\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbols\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Grammars1_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Grammars1_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
if( check_sym( arg1 , ef1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp000);
t_protect( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf2( cons( make_list( atmp000) , make_list( atmp100))));
}
}
}
}
}
}
}
}
return make_nf2( lf_AUX_Grammars1_1sym , arg0 , arg1);
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

