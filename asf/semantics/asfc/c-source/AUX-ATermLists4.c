#include "support.h"
static Symbol lf_AUX_ATermLists4_1sym;
static ATerm lf_AUX_ATermLists4_1( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
void register_AUX_ATermLists4( ) {
lf_AUX_ATermLists4_1sym= ATmakeSymbol( "prod(id(\"ATermLists\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_ATermLists4_1sym);
register_prod( ATparse( "prod(id(\"ATermLists\"),w(\"\"),[l(\"if\"),w(\"\"),sort(\"Bool\"),w(\"\"),l(\"then\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\"else\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\"fi\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_ATermLists4_1 , lf_AUX_ATermLists4_1sym);
}
void resolve_AUX_ATermLists4( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
void init_AUX_ATermLists4( ) {
}
ATerm lf_AUX_ATermLists4_1( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_ATermLists4_1);
if( check_sym( arg0 , ef1sym)) {
return arg1;
}
if( check_sym( arg0 , ef2sym)) {
return arg2;
}
return make_nf3( lf_AUX_ATermLists4_1sym , arg0 , arg1 , arg2);
}

