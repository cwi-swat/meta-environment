#include "support.h"
static asymbol * lf_AUX_ATypes3_1sym;
static aterm * lf_AUX_ATypes3_1( );
static asymbol * lf_AUX_ATypes3_2sym;
static aterm * lf_AUX_ATypes3_2( );
static asymbol * lf_AUX_ATypes3_3sym;
static aterm * lf_AUX_ATypes3_3( );
static asymbol * lf_AUX_ATypes3_4sym;
static aterm * lf_AUX_ATypes3_4( );
void register_AUX_ATypes3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_ATypes3_1sym= TmkSymbol( "prod(id(\"ATypes\"),w(\"\"),[l(\"int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_ATypes3_2sym= TmkSymbol( "prod(id(\"ATypes\"),w(\"\"),[l(\"str\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATypes3_3sym= TmkSymbol( "prod(id(\"ATypes\"),w(\"\"),[l(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_ATypes3_4sym= TmkSymbol( "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATypes3_1 , lf_AUX_ATypes3_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"str\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATypes3_2 , lf_AUX_ATypes3_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATypes3_3 , lf_AUX_ATypes3_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"ATypes\"),w(\"\"),[l(\"list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATypes3_4 , lf_AUX_ATypes3_4sym);
}
void resolve_AUX_ATypes3( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_ATypes3_4( ) {
PROF( prof_lf_AUX_ATypes3_4);
return make_nf0( lf_AUX_ATypes3_4sym);
}
aterm * lf_AUX_ATypes3_3( ) {
PROF( prof_lf_AUX_ATypes3_3);
return make_nf0( lf_AUX_ATypes3_3sym);
}
aterm * lf_AUX_ATypes3_2( ) {
PROF( prof_lf_AUX_ATypes3_2);
return make_nf0( lf_AUX_ATypes3_2sym);
}
aterm * lf_AUX_ATypes3_1( ) {
PROF( prof_lf_AUX_ATypes3_1);
return make_nf0( lf_AUX_ATypes3_1sym);
}

