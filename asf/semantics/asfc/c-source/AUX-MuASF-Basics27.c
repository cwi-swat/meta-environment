#include "support.h"
static Symbol lf_AUX_MuASF_Basics27_1sym;
static ATerm lf_AUX_MuASF_Basics27_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
void register_AUX_MuASF_Basics27( ) {
lf_AUX_MuASF_Basics27_1sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics27_1sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics27_1 , lf_AUX_MuASF_Basics27_1sym);
}
void resolve_AUX_MuASF_Basics27( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"deslashed-lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"deslashed-lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
void init_AUX_MuASF_Basics27( ) {
}
ATerm lf_AUX_MuASF_Basics27_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Basics27_1);
return ( * ef1)( arg0);
}

