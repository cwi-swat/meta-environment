#include "support.h"
static Symbol lf_AUX_MuASF_Basics20_2sym;
static ATerm lf_AUX_MuASF_Basics20_2( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_MuASF_Basics20_1sym;
static ATerm lf_AUX_MuASF_Basics20_1( ATerm arg1);
void register_AUX_MuASF_Basics20( ) {
lf_AUX_MuASF_Basics20_2sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics20_2sym);
lf_AUX_MuASF_Basics20_1sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics20_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_MuASF_Basics20_1 , lf_AUX_MuASF_Basics20_1sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-func\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics20_2 , lf_AUX_MuASF_Basics20_2sym);
}
void resolve_AUX_MuASF_Basics20( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
void init_AUX_MuASF_Basics20( ) {
}
ATerm lf_AUX_MuASF_Basics20_2( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_MuASF_Basics20_2);
if( check_sym( arg1 , lf_AUX_MuASF_Basics20_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp10)) {
return ( * ef2)( arg0 , lf_AUX_MuASF_Basics20_1( make_list( atmp10)));
}
else {
return ( * ef1)( arg0);
}
}
}
return make_nf2( lf_AUX_MuASF_Basics20_2sym , arg0 , arg1);
}
ATerm lf_AUX_MuASF_Basics20_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Basics20_1);
return make_nf1( lf_AUX_MuASF_Basics20_1sym , arg0);
}

