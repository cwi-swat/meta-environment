#include "support.h"
static asymbol * lf_AUX_AsFixPrint1_1sym;
static aterm * lf_AUX_AsFixPrint1_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_AsFixPrint1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_AsFixPrint1_1sym= TmkSymbol( "prod(id(\"AsFixPrint\"),w(\"\"),[l(\"nws-print\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"AsFixPrint\"),w(\"\"),[l(\"nws-print\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_AsFixPrint1_1 , lf_AUX_AsFixPrint1_1sym);
}
void resolve_AUX_AsFixPrint1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"ATermPrint\"),w(\"\"),[l(\"print\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ATermPrint\"),w(\"\"),[l(\"print\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"RemAsFixWspace\"),w(\"\"),[l(\"change-all-ws\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"RemAsFixWspace\"),w(\"\"),[l(\"change-all-ws\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_AsFixPrint1_1( aterm * arg0) {
PROF( prof_lf_AUX_AsFixPrint1_1);
return ( * ef1)( ( * ef2)( arg0));
}

