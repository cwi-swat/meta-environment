#include "support.h"
static asymbol * lf_AUX_ATerms3_1sym;
static aterm * lf_AUX_ATerms3_1( aterm * arg1 , aterm * arg2);
void register_AUX_ATerms3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ATerms3_1sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"::\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"right\")],w(\"\"),l(\"}\")))") , lf_AUX_ATerms3_1 , lf_AUX_ATerms3_1sym);
}
void resolve_AUX_ATerms3( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_ATerms3_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_ATerms3_1);
if( check_sym( arg0 , lf_AUX_ATerms3_1sym)) {
{
aterm * atmp00= arg_0( arg0);
{
aterm * atmp01= arg_1( arg0);
t_protect( atmp00);
t_protect( atmp01);
t_unprotect( arg0);
return lf_AUX_ATerms3_1( atmp00 , lf_AUX_ATerms3_1( atmp01 , arg1));
}
}
}
return make_nf2( lf_AUX_ATerms3_1sym , arg0 , arg1);
}

