#include "support.h"
static asymbol * lf_AUX_WfAsFixEq1_1sym;
static aterm * lf_AUX_WfAsFixEq1_1( );
static asymbol * lf_AUX_WfAsFixEq1_2sym;
static aterm * lf_AUX_WfAsFixEq1_2( );
void register_AUX_WfAsFixEq1( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_WfAsFixEq1_1sym= TmkSymbol( "prod(id(\"WfAsFixEq\"),w(\"\"),[l(\"wf-CondEquation\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_WfAsFixEq1_2sym= TmkSymbol( "prod(id(\"WfAsFixEq\"),w(\"\"),[l(\"wf-Condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFixEq\"),w(\"\"),[l(\"wf-CondEquation\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixEq1_1 , lf_AUX_WfAsFixEq1_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"WfAsFixEq\"),w(\"\"),[l(\"wf-Condition\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixEq1_2 , lf_AUX_WfAsFixEq1_2sym);
}
void resolve_AUX_WfAsFixEq1( ) {
arena local;
TinitArena( NULL , & local);
}
aterm * lf_AUX_WfAsFixEq1_2( ) {
PROF( prof_lf_AUX_WfAsFixEq1_2);
return make_nf0( lf_AUX_WfAsFixEq1_2sym);
}
aterm * lf_AUX_WfAsFixEq1_1( ) {
PROF( prof_lf_AUX_WfAsFixEq1_1);
return make_nf0( lf_AUX_WfAsFixEq1_1sym);
}

