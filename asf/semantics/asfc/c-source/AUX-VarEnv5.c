#include "support.h"
static Symbol lf_AUX_VarEnv5_1sym;
static ATerm lf_AUX_VarEnv5_1( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_VarEnv5( ) {
lf_AUX_VarEnv5_1sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[l(\"enter\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv5_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[l(\"enter\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv5_1 , lf_AUX_VarEnv5_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
}
void resolve_AUX_VarEnv5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"IntVarEnv\"),w(\"\"),no-attrs)"));
}
void init_AUX_VarEnv5( ) {
}
ATerm lf_AUX_VarEnv5_1( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_VarEnv5_1);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
{
ATerm atmp11= arg_1( arg1);
if( check_sym( atmp11 , lf2sym)) {
{
ATerm atmp110= arg_0( atmp11);
return ( * ef1)( atmp10 , lf2( cons( make_list( arg0) , make_list( atmp110))));
}
}
}
}
}
return make_nf2( lf_AUX_VarEnv5_1sym , arg0 , arg1);
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

