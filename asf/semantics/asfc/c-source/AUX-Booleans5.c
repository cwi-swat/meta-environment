#include "support.h"
static asymbol * lf_AUX_Booleans5_1sym;
static aterm * lf_AUX_Booleans5_1( );
static asymbol * lf_AUX_Booleans5_2sym;
static aterm * lf_AUX_Booleans5_2( );
static asymbol * lf_AUX_Booleans5_3sym;
static aterm * lf_AUX_Booleans5_3( aterm * arg1);
void register_AUX_Booleans5( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Booleans5_1sym= TmkSymbol( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Booleans5_2sym= TmkSymbol( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_Booleans5_3sym= TmkSymbol( "prod(id(\"Booleans\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Booleans5_1 , lf_AUX_Booleans5_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Booleans5_2 , lf_AUX_Booleans5_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Bool\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_Booleans5_3 , lf_AUX_Booleans5_3sym);
}
void resolve_AUX_Booleans5( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Booleans5_3( aterm * arg0) {
PROF( prof_lf_AUX_Booleans5_3);
return make_nf1( lf_AUX_Booleans5_3sym , arg0);
}
aterm * lf_AUX_Booleans5_2( ) {
PROF( prof_lf_AUX_Booleans5_2);
return make_nf0( lf_AUX_Booleans5_2sym);
}
aterm * lf_AUX_Booleans5_1( ) {
PROF( prof_lf_AUX_Booleans5_1);
return make_nf0( lf_AUX_Booleans5_1sym);
}

