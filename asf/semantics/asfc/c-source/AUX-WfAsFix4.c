#include "support.h"
static asymbol * lf_AUX_WfAsFix4_1sym;
static aterm * lf_AUX_WfAsFix4_1( aterm * arg1);
static asymbol * lf_AUX_WfAsFix4_2sym;
static aterm * lf_AUX_WfAsFix4_2( );
static asymbol * lf_AUX_WfAsFix4_3sym;
static aterm * lf_AUX_WfAsFix4_3( );
static asymbol * lf_AUX_WfAsFix4_4sym;
static aterm * lf_AUX_WfAsFix4_4( );
void register_AUX_WfAsFix4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_WfAsFix4_1sym= TmkSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand-aprod\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_WfAsFix4_2sym= TmkSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_WfAsFix4_3sym= TmkSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
lf_AUX_WfAsFix4_4sym= TmkSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand-aprod\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix4_1 , lf_AUX_WfAsFix4_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix4_2 , lf_AUX_WfAsFix4_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix4_3 , lf_AUX_WfAsFix4_3sym);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix4_4 , lf_AUX_WfAsFix4_4sym);
}
void resolve_AUX_WfAsFix4( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_WfAsFix4_4( ) {
PROF( prof_lf_AUX_WfAsFix4_4);
return make_nf0( lf_AUX_WfAsFix4_4sym);
}
aterm * lf_AUX_WfAsFix4_3( ) {
PROF( prof_lf_AUX_WfAsFix4_3);
return make_nf0( lf_AUX_WfAsFix4_3sym);
}
aterm * lf_AUX_WfAsFix4_2( ) {
PROF( prof_lf_AUX_WfAsFix4_2);
return make_nf0( lf_AUX_WfAsFix4_2sym);
}
aterm * lf_AUX_WfAsFix4_1( aterm * arg0) {
PROF( prof_lf_AUX_WfAsFix4_1);
return make_nf1( lf_AUX_WfAsFix4_1sym , arg0);
}

