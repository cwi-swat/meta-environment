#include "support.h"
static asymbol * lf_AUX_ATerms4_1sym;
static aterm * lf_AUX_ATerms4_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_ATerms4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ATerms4_1sym= TmkSymbol( "prod(id(\"ATerms\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ATerms\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms4_1 , lf_AUX_ATerms4_1sym);
}
void resolve_AUX_ATerms4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_ATerms4_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
PROF( prof_lf_AUX_ATerms4_1);
if( check_sym( arg0 , ef1sym)) {
t_unprotect( arg0);
t_unprotect( arg2);
return arg1;
}
if( check_sym( arg0 , ef2sym)) {
t_unprotect( arg0);
t_unprotect( arg1);
return arg2;
}
return make_nf3( lf_AUX_ATerms4_1sym , arg0 , arg1 , arg2);
}

