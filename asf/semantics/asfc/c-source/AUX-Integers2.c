#include "support.h"
static asymbol * lf_AUX_Integers2_1sym;
static aterm * lf_AUX_Integers2_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
void register_AUX_Integers2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Integers2_1sym= TmkSymbol( "prod(id(\"Integers\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[ql(\"+\"),w(\"\"),sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)") , lf_AUX_Integers2_1 , lf_AUX_Integers2_1sym);
}
void resolve_AUX_Integers2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Integers\"),w(\"\"),[sort(\"NAT\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INT\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Integers2_1( aterm * arg0) {
PROF( prof_lf_AUX_Integers2_1);
return ( * ef1)( arg0);
}

