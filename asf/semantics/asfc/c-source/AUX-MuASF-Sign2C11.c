#include "support.h"
static Symbol lf_AUX_MuASF_Sign2C11_2sym;
static ATerm lf_AUX_MuASF_Sign2C11_2( ATerm arg1);
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_MuASF_Sign2C11_1sym;
static ATerm lf_AUX_MuASF_Sign2C11_1( ATerm arg1);
void register_AUX_MuASF_Sign2C11( ) {
lf_AUX_MuASF_Sign2C11_2sym= ATmakeSymbol( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"countsigargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Sign2C11_2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf_AUX_MuASF_Sign2C11_1sym= ATmakeSymbol( "listtype(sort(\"SigArg\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Sign2C11_1sym);
register_prod( ATparse( "listtype(sort(\"SigArg\"),ql(\",\"))") , lf_AUX_MuASF_Sign2C11_1 , lf_AUX_MuASF_Sign2C11_1sym);
register_prod( ATparse( "prod(id(\"MuASF-Sign2C\"),w(\"\"),[l(\"countsigargs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"SigArg\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Sign2C11_2 , lf_AUX_MuASF_Sign2C11_2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_MuASF_Sign2C11( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_MuASF_Sign2C11( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_MuASF_Sign2C11_2( ATerm arg0) {
{
ATerm tmp[3];
PROF( prof_lf_AUX_MuASF_Sign2C11_2);
if( check_sym( arg0 , lf_AUX_MuASF_Sign2C11_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
return ( constant0? constant0: ( constant0= ( * ef1)( lf3( make_list( make_char( 49))))));
}
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
tmp[ 1]= list_tail( atmp00);
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= lf_AUX_MuASF_Sign2C11_2( lf_AUX_MuASF_Sign2C11_1( make_list( tmp[ 1])));
return ( * ef2)( tmp[ 2]);
}
}
}
}
return make_nf1( lf_AUX_MuASF_Sign2C11_2sym , arg0);
}
}
ATerm lf_AUX_MuASF_Sign2C11_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Sign2C11_1);
return make_nf1( lf_AUX_MuASF_Sign2C11_1sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

