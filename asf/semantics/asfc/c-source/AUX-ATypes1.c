#include "support.h"
static Symbol lf_AUX_ATypes1_1sym;
static ATerm lf_AUX_ATypes1_1( );
static Symbol lf_AUX_ATypes1_2sym;
static ATerm lf_AUX_ATypes1_2( );
void register_AUX_ATypes1( ) {
lf_AUX_ATypes1_1sym= ATmakeSymbol( "prod(id(\"ATypes\"),w(\"\"),[l(\"int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATypes1_1sym);
lf_AUX_ATypes1_2sym= ATmakeSymbol( "prod(id(\"ATypes\"),w(\"\"),[l(\"str\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATypes1_2sym);
register_prod( ATparse( "prod(id(\"ATypes\"),w(\"\"),[l(\"int\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATypes1_1 , lf_AUX_ATypes1_1sym);
register_prod( ATparse( "prod(id(\"ATypes\"),w(\"\"),[l(\"str\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATypes1_2 , lf_AUX_ATypes1_2sym);
}
void resolve_AUX_ATypes1( ) {
}
void init_AUX_ATypes1( ) {
}
ATerm lf_AUX_ATypes1_2( ) {
PROF( prof_lf_AUX_ATypes1_2);
return make_nf0( lf_AUX_ATypes1_2sym);
}
ATerm lf_AUX_ATypes1_1( ) {
PROF( prof_lf_AUX_ATypes1_1);
return make_nf0( lf_AUX_ATypes1_1sym);
}

