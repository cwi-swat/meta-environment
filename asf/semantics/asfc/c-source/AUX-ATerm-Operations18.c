#include "support.h"
static Symbol lf_AUX_ATerm_Operations18_1sym;
static ATerm lf_AUX_ATerm_Operations18_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
void register_AUX_ATerm_Operations18( ) {
lf_AUX_ATerm_Operations18_1sym= ATmakeSymbol( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"yes\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerm_Operations18_1sym);
register_prod( ATparse( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"yes\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_ATerm_Operations18_1 , lf_AUX_ATerm_Operations18_1sym);
}
void resolve_AUX_ATerm_Operations18( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[ql(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_ATerm_Operations18( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_ATerm_Operations18_1( ATerm arg0) {
PROF( prof_lf_AUX_ATerm_Operations18_1);
return ( constant0? constant0: ( constant0= ( * ef1)( )));
}

