#include "support.h"
static asymbol * lf_AUX_Matching2_1sym;
static aterm * lf_AUX_Matching2_1( aterm * arg1);
static asymbol * lf_AUX_Matching2_2sym;
static aterm * lf_AUX_Matching2_2( );
void register_AUX_Matching2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Matching2_1sym= TmkSymbol( "prod(id(\"Matching\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Matching2_2sym= TmkSymbol( "prod(id(\"Matching\"),w(\"\"),[l(\"nomatch\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Matching\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)") , lf_AUX_Matching2_1 , lf_AUX_Matching2_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Matching\"),w(\"\"),[l(\"nomatch\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Subs\"),w(\"\"),no-attrs)") , lf_AUX_Matching2_2 , lf_AUX_Matching2_2sym);
}
void resolve_AUX_Matching2( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Matching2_2( ) {
PROF( prof_lf_AUX_Matching2_2);
return make_nf0( lf_AUX_Matching2_2sym);
}
aterm * lf_AUX_Matching2_1( aterm * arg0) {
PROF( prof_lf_AUX_Matching2_1);
return make_nf1( lf_AUX_Matching2_1sym , arg0);
}

