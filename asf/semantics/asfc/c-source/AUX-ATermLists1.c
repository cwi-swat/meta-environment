#include "support.h"
static asymbol * lf_AUX_ATermLists1_1sym;
static aterm * lf_AUX_ATermLists1_1( aterm * arg1 , aterm * arg2);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef2sym;
static funcptr ef2;
void register_AUX_ATermLists1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ATermLists1_1sym= TmkSymbol( "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ATermLists\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"==\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_ATermLists1_1 , lf_AUX_ATermLists1_1sym);
}
void resolve_AUX_ATermLists1( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_ATermLists1_1( aterm * arg0 , aterm * arg1) {
PROF( prof_lf_AUX_ATermLists1_1);
if( m_term_equal( arg0 , arg1)) {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( );
}
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef2)( );
}

