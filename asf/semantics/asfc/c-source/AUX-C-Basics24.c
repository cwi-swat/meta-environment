#include "support.h"
static asymbol * lf_AUX_C_Basics24_1sym;
static aterm * lf_AUX_C_Basics24_1( );
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
void register_AUX_C_Basics24( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_C_Basics24_1sym= TmkSymbol( "prod(id(\"C-Basics\"),w(\"\"),[l(\"space\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[l(\"space\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics24_1 , lf_AUX_C_Basics24_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_C_Basics24( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_C_Basics24_1( ) {
PROF( prof_lf_AUX_C_Basics24_1);
return ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 32)) , make_list( make_char( 34))))));
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

