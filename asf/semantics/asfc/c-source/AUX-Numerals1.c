#include "support.h"
static asymbol * lf_AUX_Numerals1_1sym;
static aterm * lf_AUX_Numerals1_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_Numerals1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Numerals1_1sym= TmkSymbol( "prod(id(\"Numerals\"),w(\"\"),[l(\"decr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"decr\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)") , lf_AUX_Numerals1_1 , lf_AUX_Numerals1_1sym);
}
void resolve_AUX_Numerals1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"s\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Num\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Numerals\"),w(\"\"),[l(\"zero\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Num\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Numerals1_1( aterm * arg0) {
PROF( prof_lf_AUX_Numerals1_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
t_unprotect( arg0);
return atmp00;
}
}
if( check_sym( arg0 , ef2sym)) {
return arg0;
}
return make_nf1( lf_AUX_Numerals1_1sym , arg0);
}

