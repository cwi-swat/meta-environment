#include "support.h"
static Symbol lf_AUX_WfAsFix4_1sym;
static ATerm lf_AUX_WfAsFix4_1( ATerm arg1);
static Symbol lf_AUX_WfAsFix4_2sym;
static ATerm lf_AUX_WfAsFix4_2( );
static Symbol lf_AUX_WfAsFix4_3sym;
static ATerm lf_AUX_WfAsFix4_3( );
static Symbol lf_AUX_WfAsFix4_4sym;
static ATerm lf_AUX_WfAsFix4_4( );
void register_AUX_WfAsFix4( ) {
lf_AUX_WfAsFix4_1sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand-aprod\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix4_1sym);
lf_AUX_WfAsFix4_2sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix4_2sym);
lf_AUX_WfAsFix4_3sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix4_3sym);
lf_AUX_WfAsFix4_4sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix4_4sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand-aprod\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix4_1 , lf_AUX_WfAsFix4_1sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix4_2 , lf_AUX_WfAsFix4_2sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix4_3 , lf_AUX_WfAsFix4_3sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix4_4 , lf_AUX_WfAsFix4_4sym);
}
void resolve_AUX_WfAsFix4( ) {
}
void init_AUX_WfAsFix4( ) {
}
ATerm lf_AUX_WfAsFix4_4( ) {
PROF( prof_lf_AUX_WfAsFix4_4);
return make_nf0( lf_AUX_WfAsFix4_4sym);
}
ATerm lf_AUX_WfAsFix4_3( ) {
PROF( prof_lf_AUX_WfAsFix4_3);
return make_nf0( lf_AUX_WfAsFix4_3sym);
}
ATerm lf_AUX_WfAsFix4_2( ) {
PROF( prof_lf_AUX_WfAsFix4_2);
return make_nf0( lf_AUX_WfAsFix4_2sym);
}
ATerm lf_AUX_WfAsFix4_1( ATerm arg0) {
PROF( prof_lf_AUX_WfAsFix4_1);
return make_nf1( lf_AUX_WfAsFix4_1sym , arg0);
}

