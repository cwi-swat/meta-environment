#include "support.h"
static asymbol * lf_AUX_WfAsFixTerm7_1sym;
static aterm * lf_AUX_WfAsFixTerm7_1( );
static asymbol * lf_AUX_WfAsFixTerm7_2sym;
static aterm * lf_AUX_WfAsFixTerm7_2( );
void register_AUX_WfAsFixTerm7( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_WfAsFixTerm7_1sym= TmkSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_WfAsFixTerm7_2sym= TmkSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"wf-AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm7_1 , lf_AUX_WfAsFixTerm7_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"wf-AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm7_2 , lf_AUX_WfAsFixTerm7_2sym);
}
void resolve_AUX_WfAsFixTerm7( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_WfAsFixTerm7_2( ) {
PROF( prof_lf_AUX_WfAsFixTerm7_2);
return make_nf0( lf_AUX_WfAsFixTerm7_2sym);
}
aterm * lf_AUX_WfAsFixTerm7_1( ) {
PROF( prof_lf_AUX_WfAsFixTerm7_1);
return make_nf0( lf_AUX_WfAsFixTerm7_1sym);
}

