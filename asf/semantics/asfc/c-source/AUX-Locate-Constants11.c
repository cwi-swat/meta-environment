#include "support.h"
static Symbol lf_AUX_Locate_Constants11_2sym;
static ATerm lf_AUX_Locate_Constants11_2( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf_AUX_Locate_Constants11_1sym;
static ATerm lf_AUX_Locate_Constants11_1( ATerm arg1);
void register_AUX_Locate_Constants11( ) {
lf_AUX_Locate_Constants11_2sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"expressions-contain-variables\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants11_2sym);
lf_AUX_Locate_Constants11_1sym= ATmakeSymbol( "listtype(sort(\"Expression\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants11_1sym);
register_prod( ATparse( "listtype(sort(\"Expression\"),ql(\",\"))") , lf_AUX_Locate_Constants11_1 , lf_AUX_Locate_Constants11_1sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"expressions-contain-variables\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants11_2 , lf_AUX_Locate_Constants11_2sym);
}
void resolve_AUX_Locate_Constants11( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Booleans\"),w(\"\"),[sort(\"Bool\"),w(\"\"),ql(\"\\\\\\\\/\"),w(\"\"),sort(\"Bool\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"expression-contains-variables\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Locate-Constants\"),w(\"\"),[l(\"expression-contains-variables\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_Locate_Constants11( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_Locate_Constants11_2( ATerm arg0) {
{
ATerm tmp[4];
PROF( prof_lf_AUX_Locate_Constants11_2);
if( check_sym( arg0 , lf_AUX_Locate_Constants11_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
tmp[ 1]= list_tail( atmp00);
tmp[ 2]= ( * ef3)( tmp[ 0]);
tmp[ 3]= lf_AUX_Locate_Constants11_2( lf_AUX_Locate_Constants11_1( make_list( tmp[ 1])));
return ( * ef2)( tmp[ 2] , tmp[ 3]);
}
else {
return ( constant0? constant0: ( constant0= ( * ef1)( )));
}
}
}
return make_nf1( lf_AUX_Locate_Constants11_2sym , arg0);
}
}
ATerm lf_AUX_Locate_Constants11_1( ATerm arg0) {
PROF( prof_lf_AUX_Locate_Constants11_1);
return make_nf1( lf_AUX_Locate_Constants11_1sym , arg0);
}

