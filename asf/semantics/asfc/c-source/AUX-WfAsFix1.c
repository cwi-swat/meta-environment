#include "support.h"
static Symbol lf_AUX_WfAsFix1_1sym;
static ATerm lf_AUX_WfAsFix1_1( ATerm arg1);
static Symbol lf_AUX_WfAsFix1_2sym;
static ATerm lf_AUX_WfAsFix1_2( );
static Symbol lf_AUX_WfAsFix1_3sym;
static ATerm lf_AUX_WfAsFix1_3( );
static Symbol lf_AUX_WfAsFix1_4sym;
static ATerm lf_AUX_WfAsFix1_4( );
void register_AUX_WfAsFix1( ) {
lf_AUX_WfAsFix1_1sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand-aprod\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix1_1sym);
lf_AUX_WfAsFix1_2sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix1_2sym);
lf_AUX_WfAsFix1_3sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix1_3sym);
lf_AUX_WfAsFix1_4sym= ATmakeSymbol( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_WfAsFix1_4sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"expand-aprod\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix1_1 , lf_AUX_WfAsFix1_1sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Module\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix1_2 , lf_AUX_WfAsFix1_2sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix1_3 , lf_AUX_WfAsFix1_3sym);
register_prod( ATparse( "prod(id(\"WfAsFix\"),w(\"\"),[l(\"wf-AsFix\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_WfAsFix1_4 , lf_AUX_WfAsFix1_4sym);
}
void resolve_AUX_WfAsFix1( ) {
}
void init_AUX_WfAsFix1( ) {
}
ATerm lf_AUX_WfAsFix1_4( ) {
PROF( prof_lf_AUX_WfAsFix1_4);
return make_nf0( lf_AUX_WfAsFix1_4sym);
}
ATerm lf_AUX_WfAsFix1_3( ) {
PROF( prof_lf_AUX_WfAsFix1_3);
return make_nf0( lf_AUX_WfAsFix1_3sym);
}
ATerm lf_AUX_WfAsFix1_2( ) {
PROF( prof_lf_AUX_WfAsFix1_2);
return make_nf0( lf_AUX_WfAsFix1_2sym);
}
ATerm lf_AUX_WfAsFix1_1( ATerm arg0) {
PROF( prof_lf_AUX_WfAsFix1_1);
return make_nf1( lf_AUX_WfAsFix1_1sym , arg0);
}

