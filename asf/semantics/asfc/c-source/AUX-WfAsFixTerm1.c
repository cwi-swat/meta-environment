#include "support.h"
static Symbol lf_AUX_WfAsFixTerm1_1sym;
static ATerm lf_AUX_WfAsFixTerm1_1( );
static Symbol lf_AUX_WfAsFixTerm1_2sym;
static ATerm lf_AUX_WfAsFixTerm1_2( );
void register_AUX_WfAsFixTerm1( ) {
lf_AUX_WfAsFixTerm1_1sym= ATmakeSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFixTerm1_1sym);
lf_AUX_WfAsFixTerm1_2sym= ATmakeSymbol( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"wf-AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFixTerm1_2sym);
register_prod( ATparse( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"asfix-type-error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm1_1 , lf_AUX_WfAsFixTerm1_1sym);
register_prod( ATparse( "prod(id(\"WfAsFixTerm\"),w(\"\"),[l(\"wf-AsFixTerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFixTerm1_2 , lf_AUX_WfAsFixTerm1_2sym);
}
void resolve_AUX_WfAsFixTerm1( ) {
}
void init_AUX_WfAsFixTerm1( ) {
}
ATerm lf_AUX_WfAsFixTerm1_2( ) {
PROF( prof_lf_AUX_WfAsFixTerm1_2);
return make_nf0( lf_AUX_WfAsFixTerm1_2sym);
}
ATerm lf_AUX_WfAsFixTerm1_1( ) {
PROF( prof_lf_AUX_WfAsFixTerm1_1);
return make_nf0( lf_AUX_WfAsFixTerm1_1sym);
}

