#include "support.h"
static Symbol lf_AUX_WfAsFixTerm7_1sym;
static ATerm lf_AUX_WfAsFixTerm7_1( );
static Symbol lf_AUX_WfAsFixTerm7_2sym;
static ATerm lf_AUX_WfAsFixTerm7_2( );
void register_AUX_WfAsFixTerm7( ) {
lf_AUX_WfAsFixTerm7_1sym= ATmakeSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFixTerm7_1sym);
lf_AUX_WfAsFixTerm7_2sym= ATmakeSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"wf-AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFixTerm7_2sym);
register_prod( ATparse( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm7_1 , lf_AUX_WfAsFixTerm7_1sym);
register_prod( ATparse( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"wf-AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm7_2 , lf_AUX_WfAsFixTerm7_2sym);
}
void resolve_AUX_WfAsFixTerm7( ) {
}
void init_AUX_WfAsFixTerm7( ) {
}
ATerm lf_AUX_WfAsFixTerm7_2( ) {
PROF( prof_lf_AUX_WfAsFixTerm7_2);
return make_nf0( lf_AUX_WfAsFixTerm7_2sym);
}
ATerm lf_AUX_WfAsFixTerm7_1( ) {
PROF( prof_lf_AUX_WfAsFixTerm7_1);
return make_nf0( lf_AUX_WfAsFixTerm7_1sym);
}

