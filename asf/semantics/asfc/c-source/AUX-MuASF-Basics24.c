#include "support.h"
static asymbol * lf_AUX_MuASF_Basics24_1sym;
static aterm * lf_AUX_MuASF_Basics24_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
void register_AUX_MuASF_Basics24( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Basics24_1sym= TmkSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics24_1 , lf_AUX_MuASF_Basics24_1sym);
}
void resolve_AUX_MuASF_Basics24( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"deslashed-lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"deslashed-lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Basics24_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Basics24_1);
return ( * ef1)( arg0);
}

