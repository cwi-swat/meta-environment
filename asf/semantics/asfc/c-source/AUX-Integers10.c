#include "support.h"
static asymbol * lf_AUX_Integers10_1sym;
static aterm * lf_AUX_Integers10_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_Integers10( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers10_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"<=\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\"<=\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Integers10_1 , lf_AUX_Integers10_1sym);
}
void resolve_AUX_Integers10( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[ql(\"~\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[ql(\"~\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\">\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"INT\"),w(\"\"),ql(\">\"),w(\"\"),sort(\"INT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Integers10_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_Integers10_1);
return ( * ef1)( ( * ef2)( arg0 , arg1));
}

