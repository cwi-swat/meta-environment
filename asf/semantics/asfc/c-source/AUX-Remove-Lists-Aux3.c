#include "support.h"
static Symbol lf_AUX_Remove_Lists_Aux3_2sym;
static ATerm lf_AUX_Remove_Lists_Aux3_2( ATerm arg1 , ATerm arg2);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf_AUX_Remove_Lists_Aux3_1sym;
static ATerm lf_AUX_Remove_Lists_Aux3_1( ATerm arg1);
void register_AUX_Remove_Lists_Aux3( ) {
lf_AUX_Remove_Lists_Aux3_2sym= ATmakeSymbol( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"add-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Remove_Lists_Aux3_2sym);
lf_AUX_Remove_Lists_Aux3_1sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Remove_Lists_Aux3_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Remove_Lists_Aux3_1 , lf_AUX_Remove_Lists_Aux3_1sym);
register_prod( ATparse( "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"add-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)") , lf_AUX_Remove_Lists_Aux3_2 , lf_AUX_Remove_Lists_Aux3_2sym);
}
void resolve_AUX_Remove_Lists_Aux3( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
void init_AUX_Remove_Lists_Aux3( ) {
}
ATerm lf_AUX_Remove_Lists_Aux3_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[5];
PROF( prof_lf_AUX_Remove_Lists_Aux3_2);
if( check_sym( arg1 , lf_AUX_Remove_Lists_Aux3_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( is_single_element( atmp10)) {
tmp[ 0]= list_head( atmp10);
return ( * ef1)( lf_AUX_Remove_Lists_Aux3_1( make_list( ( * ef2)( arg0 , lf_AUX_Remove_Lists_Aux3_1( make_list( tmp[ 0]))))));
}
if( not_empty_list( atmp10)) {
tmp[ 0]= list_head( atmp10);
tmp[ 1]= list_tail( atmp10);
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= lf_AUX_Remove_Lists_Aux3_2( arg0 , lf_AUX_Remove_Lists_Aux3_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_Remove_Lists_Aux3_1sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( not_empty_list( tmp[ 4])) {
return ( * ef1)( lf_AUX_Remove_Lists_Aux3_1( cons( make_list( ( * ef2)( arg0 , lf_AUX_Remove_Lists_Aux3_1( make_list( tmp[ 0])))) , make_list( tmp[ 4]))));
}
}
}
}
}
}
}
return make_nf2( lf_AUX_Remove_Lists_Aux3_2sym , arg0 , arg1);
}
}
ATerm lf_AUX_Remove_Lists_Aux3_1( ATerm arg0) {
PROF( prof_lf_AUX_Remove_Lists_Aux3_1);
return make_nf1( lf_AUX_Remove_Lists_Aux3_1sym , arg0);
}

