#include "support.h"
static Symbol lf_AUX_ATerm_Tables1_1sym;
static ATerm lf_AUX_ATerm_Tables1_1( );
static Symbol lf_AUX_ATerm_Tables1_2sym;
static ATerm lf_AUX_ATerm_Tables1_2( );
static Symbol lf_AUX_ATerm_Tables1_3sym;
static ATerm lf_AUX_ATerm_Tables1_3( );
static Symbol lf_AUX_ATerm_Tables1_4sym;
static ATerm lf_AUX_ATerm_Tables1_4( );
static Symbol lf_AUX_ATerm_Tables1_5sym;
static ATerm lf_AUX_ATerm_Tables1_5( );
void register_AUX_ATerm_Tables1( ) {
lf_AUX_ATerm_Tables1_1sym= ATmakeSymbol( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"getf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATerm_Tables1_1sym);
lf_AUX_ATerm_Tables1_2sym= ATmakeSymbol( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"egetf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATerm_Tables1_2sym);
lf_AUX_ATerm_Tables1_3sym= ATmakeSymbol( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"putf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATerm_Tables1_3sym);
lf_AUX_ATerm_Tables1_4sym= ATmakeSymbol( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"cputf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATerm_Tables1_4sym);
lf_AUX_ATerm_Tables1_5sym= ATmakeSymbol( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"deff\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATerm_Tables1_5sym);
register_prod( ATparse( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"getf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATerm_Tables1_1 , lf_AUX_ATerm_Tables1_1sym);
register_prod( ATparse( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"egetf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATerm_Tables1_2 , lf_AUX_ATerm_Tables1_2sym);
register_prod( ATparse( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"putf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATerm_Tables1_3 , lf_AUX_ATerm_Tables1_3sym);
register_prod( ATparse( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"cputf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATerm_Tables1_4 , lf_AUX_ATerm_Tables1_4sym);
register_prod( ATparse( "prod(id(\"ATerm-Tables\"),w(\"\"),[l(\"deff\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATerm_Tables1_5 , lf_AUX_ATerm_Tables1_5sym);
}
void resolve_AUX_ATerm_Tables1( ) {
}
void init_AUX_ATerm_Tables1( ) {
}
ATerm lf_AUX_ATerm_Tables1_5( ) {
PROF( prof_lf_AUX_ATerm_Tables1_5);
return make_nf0( lf_AUX_ATerm_Tables1_5sym);
}
ATerm lf_AUX_ATerm_Tables1_4( ) {
PROF( prof_lf_AUX_ATerm_Tables1_4);
return make_nf0( lf_AUX_ATerm_Tables1_4sym);
}
ATerm lf_AUX_ATerm_Tables1_3( ) {
PROF( prof_lf_AUX_ATerm_Tables1_3);
return make_nf0( lf_AUX_ATerm_Tables1_3sym);
}
ATerm lf_AUX_ATerm_Tables1_2( ) {
PROF( prof_lf_AUX_ATerm_Tables1_2);
return make_nf0( lf_AUX_ATerm_Tables1_2sym);
}
ATerm lf_AUX_ATerm_Tables1_1( ) {
PROF( prof_lf_AUX_ATerm_Tables1_1);
return make_nf0( lf_AUX_ATerm_Tables1_1sym);
}

