#include "support.h"
static Symbol lf_AUX_Normalize_Conds1_1sym;
static ATerm lf_AUX_Normalize_Conds1_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
void register_AUX_Normalize_Conds1( ) {
lf_AUX_Normalize_Conds1_1sym= ATmakeSymbol( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conditions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Normalize_Conds1_1sym);
register_prod( ATparse( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-conditions\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Module\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)") , lf_AUX_Normalize_Conds1_1 , lf_AUX_Normalize_Conds1_1sym);
}
void resolve_AUX_Normalize_Conds1( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModId\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),sort(\"RulesOpt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"module\"),w(\"\"),sort(\"ModId\"),w(\"\"),sort(\"SignatureOpt\"),w(\"\"),sort(\"RulesOpt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Module\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Normalize-Conds\"),w(\"\"),[l(\"normalize-rulesopt\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RulesOpt\"),w(\"\"),no-attrs)"));
}
void init_AUX_Normalize_Conds1( ) {
}
ATerm lf_AUX_Normalize_Conds1_1( ATerm arg0) {
{
ATerm tmp[1];
PROF( prof_lf_AUX_Normalize_Conds1_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
{
ATerm atmp02= arg_2( arg0);
tmp[ 0]= ( * ef2)( atmp02);
return ( * ef1)( atmp00 , atmp01 , tmp[ 0]);
}
}
}
}
return make_nf1( lf_AUX_Normalize_Conds1_1sym , arg0);
}
}

