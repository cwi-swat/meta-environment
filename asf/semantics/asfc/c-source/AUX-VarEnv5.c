#include "support.h"
static Symbol lf_AUX_VarEnv5_1sym;
static ATerm lf_AUX_VarEnv5_1( ATerm arg1 , ATerm arg2);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_VarEnv5( ) {
lf_AUX_VarEnv5_1sym= ATmakeSymbol( "prod(id(\"VarEnv\"),w(\"\"),[l(\"includes\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_VarEnv5_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"VarEnv\"),w(\"\"),[l(\"includes\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_VarEnv5_1 , lf_AUX_VarEnv5_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
}
void resolve_AUX_VarEnv5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"VarEnv\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
void init_AUX_VarEnv5( ) {
ATprotect( & constant0);
ATprotect( & constant1);
}
ATerm lf_AUX_VarEnv5_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[2];
PROF( prof_lf_AUX_VarEnv5_1);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( not_empty_list( atmp100)) {
tmp[ 0]= list_head( atmp100);
{
tmp[ 1]= list_tail( atmp100);
if( ! term_equal( arg0 , tmp[ 0])) {
return lf_AUX_VarEnv5_1( arg0 , ( * ef1)( lf2( make_list( tmp[ 1]))));
}
else {
return ( constant0? constant0: ( constant0= ( * ef3)( )));
}
}
}
else {
return ( constant1? constant1: ( constant1= ( * ef2)( )));
}
}
}
}
}
return make_nf2( lf_AUX_VarEnv5_1sym , arg0 , arg1);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

