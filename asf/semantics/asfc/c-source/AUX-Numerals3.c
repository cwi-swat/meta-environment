#include "support.h"
static asymbol * lf_AUX_Numerals3_1sym;
static aterm * lf_AUX_Numerals3_1( );
static asymbol * lf_AUX_Numerals3_2sym;
static aterm * lf_AUX_Numerals3_2( aterm * arg1);
void register_AUX_Numerals3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Numerals3_1sym= TmkSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Numerals3_2sym= TmkSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals3_1 , lf_AUX_Numerals3_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals3_2 , lf_AUX_Numerals3_2sym);
}
void resolve_AUX_Numerals3( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_Numerals3_2( aterm * arg0) {
PROF( prof_lf_AUX_Numerals3_2);
return make_nf1( lf_AUX_Numerals3_2sym , arg0);
}
aterm * lf_AUX_Numerals3_1( ) {
PROF( prof_lf_AUX_Numerals3_1);
return make_nf0( lf_AUX_Numerals3_1sym);
}

