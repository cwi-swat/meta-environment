#include "support.h"
static Symbol lf_AUX_MuASF_Basics23_1sym;
static ATerm lf_AUX_MuASF_Basics23_1( ATerm arg1 , ATerm arg2);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_MuASF_Basics23( ) {
lf_AUX_MuASF_Basics23_1sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-new-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics23_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-new-args\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics23_1 , lf_AUX_MuASF_Basics23_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Basics23( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_MuASF_Basics23( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_MuASF_Basics23_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[5];
PROF( prof_lf_AUX_MuASF_Basics23_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( not_empty_list( atmp000)) {
tmp[ 0]= list_head( atmp000);
tmp[ 1]= list_tail( atmp000);
tmp[ 2]= lf_AUX_MuASF_Basics23_1( ( * ef1)( lf2( make_list( tmp[ 1]))) , ( * ef3)( arg1));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
return ( * ef1)( lf2( cons( make_list( ( * ef2)( arg1)) , make_list( tmp[ 4]))));
}
}
}
else {
return ( constant0? constant0: ( constant0= ( * ef1)( lf2( make_list( null( ))))));
}
}
}
}
}
return make_nf2( lf_AUX_MuASF_Basics23_1sym , arg0 , arg1);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

