#include "support.h"
static asymbol * lf_AUX_Booleans3_1sym;
static aterm * lf_AUX_Booleans3_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
void register_AUX_Booleans3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Booleans3_1sym= TmkSymbol( "prod(id(\"Booleans\"),w(\"\"),[ql(\"~\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[ql(\"~\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Booleans3_1 , lf_AUX_Booleans3_1sym);
}
void resolve_AUX_Booleans3( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Booleans3_1( aterm * arg0) {
PROF( prof_lf_AUX_Booleans3_1);
if( check_sym( arg0 , ef1sym)) {
t_unprotect( arg0);
return ( * ef2)( );
}
if( check_sym( arg0 , ef2sym)) {
t_unprotect( arg0);
return ( * ef1)( );
}
return make_nf1( lf_AUX_Booleans3_1sym , arg0);
}

