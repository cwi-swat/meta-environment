#include "support.h"
static Symbol lf_AUX_Rules2C_Aux23_2sym;
static ATerm lf_AUX_Rules2C_Aux23_2( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf_AUX_Rules2C_Aux23_1sym;
static ATerm lf_AUX_Rules2C_Aux23_1( ATerm arg1);
void register_AUX_Rules2C_Aux23( ) {
lf_AUX_Rules2C_Aux23_2sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"add-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux23_2sym);
lf_AUX_Rules2C_Aux23_1sym= ATmakeSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux23_1sym);
register_prod( ATparse( "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux23_1 , lf_AUX_Rules2C_Aux23_1sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"add-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux23_2 , lf_AUX_Rules2C_Aux23_2sym);
}
void resolve_AUX_Rules2C_Aux23( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_Rules2C_Aux23( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_Rules2C_Aux23_2( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Rules2C_Aux23_2);
if( check_sym( arg0 , lf_AUX_Rules2C_Aux23_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_Rules2C_Aux23_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp00)) {
if( ! not_empty_list( atmp10)) {
return ( constant0? constant0: ( constant0= ( * ef1)( lf_AUX_Rules2C_Aux23_1( make_list( null( ))))));
}
else {
return ( * ef1)( lf_AUX_Rules2C_Aux23_1( cons( make_list( atmp10) , make_list( atmp00))));
}
}
else {
return ( * ef1)( lf_AUX_Rules2C_Aux23_1( make_list( atmp10)));
}
}
}
}
}
return make_nf2( lf_AUX_Rules2C_Aux23_2sym , arg0 , arg1);
}
ATerm lf_AUX_Rules2C_Aux23_1( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux23_1);
return make_nf1( lf_AUX_Rules2C_Aux23_1sym , arg0);
}

