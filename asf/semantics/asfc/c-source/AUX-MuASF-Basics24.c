#include "support.h"
static Symbol lf_AUX_MuASF_Basics24_2sym;
static ATerm lf_AUX_MuASF_Basics24_2( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf_AUX_MuASF_Basics24_1sym;
static ATerm lf_AUX_MuASF_Basics24_1( ATerm arg1);
void register_AUX_MuASF_Basics24( ) {
lf_AUX_MuASF_Basics24_2sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-list-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics24_2sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf_AUX_MuASF_Basics24_1sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics24_1sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_MuASF_Basics24_1 , lf_AUX_MuASF_Basics24_1sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-list-args\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics24_2 , lf_AUX_MuASF_Basics24_2sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_MuASF_Basics24( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_MuASF_Basics24( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_MuASF_Basics24_2( ATerm arg0) {
{
ATerm tmp[3];
PROF( prof_lf_AUX_MuASF_Basics24_2);
if( check_sym( arg0 , lf_AUX_MuASF_Basics24_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( is_single_element( atmp00)) {
tmp[ 0]= list_head( atmp00);
return tmp[ 0];
}
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
tmp[ 1]= list_tail( atmp00);
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= lf_AUX_MuASF_Basics24_2( lf_AUX_MuASF_Basics24_1( make_list( tmp[ 1])));
return ( * ef1)( ( constant0? constant0: ( constant0= ( * ef2)( lf3( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf_AUX_MuASF_Basics24_1( cons( make_list( tmp[ 0]) , make_list( tmp[ 2]))));
}
}
}
}
return make_nf1( lf_AUX_MuASF_Basics24_2sym , arg0);
}
}
ATerm lf_AUX_MuASF_Basics24_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Basics24_1);
return make_nf1( lf_AUX_MuASF_Basics24_1sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

