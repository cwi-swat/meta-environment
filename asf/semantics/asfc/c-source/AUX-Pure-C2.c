#include "support.h"
static Symbol lf_AUX_Pure_C2_1sym;
static ATerm lf_AUX_Pure_C2_1( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
void register_AUX_Pure_C2( ) {
lf_AUX_Pure_C2_1sym= ATmakeSymbol( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Pure_C2_1sym);
register_prod( ATparse( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Expression\"),w(\"\"),ql(\"=\"),w(\"\"),sort(\"Expression\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)") , lf_AUX_Pure_C2_1 , lf_AUX_Pure_C2_1sym);
}
void resolve_AUX_Pure_C2( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"flatten-list-of-chars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"flatten-list-of-chars\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Expression\"),w(\"\"),no-attrs)"));
}
void init_AUX_Pure_C2( ) {
}
ATerm lf_AUX_Pure_C2_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[1];
PROF( prof_lf_AUX_Pure_C2_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf_AUX_Pure_C2_1sym)) {
{
ATerm atmp000= arg_0( atmp00);
{
ATerm atmp001= arg_1( atmp00);
if( term_equal( atmp000 , arg1)) {
tmp[ 0]= ( * ef1)( atmp001);
return tmp[ 0];
}
}
}
}
}
}
return make_nf2( lf_AUX_Pure_C2_1sym , arg0 , arg1);
}
}

