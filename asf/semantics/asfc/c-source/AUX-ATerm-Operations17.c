#include "support.h"
static Symbol lf_AUX_ATerm_Operations17_1sym;
static ATerm lf_AUX_ATerm_Operations17_1( ATerm arg1);
void register_AUX_ATerm_Operations17( ) {
lf_AUX_ATerm_Operations17_1sym= ATmakeSymbol( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"identity\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerm_Operations17_1sym);
register_prod( ATparse( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"identity\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerm_Operations17_1 , lf_AUX_ATerm_Operations17_1sym);
}
void resolve_AUX_ATerm_Operations17( ) {
}
void init_AUX_ATerm_Operations17( ) {
}
ATerm lf_AUX_ATerm_Operations17_1( ATerm arg0) {
PROF( prof_lf_AUX_ATerm_Operations17_1);
return arg0;
}

