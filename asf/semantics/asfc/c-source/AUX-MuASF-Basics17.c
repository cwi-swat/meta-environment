#include "support.h"
static Symbol lf_AUX_MuASF_Basics17_1sym;
static ATerm lf_AUX_MuASF_Basics17_1( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_MuASF_Basics17( ) {
lf_AUX_MuASF_Basics17_1sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-trans-list-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics17_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"make-trans-list-id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics17_1 , lf_AUX_MuASF_Basics17_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Basics17( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
void init_AUX_MuASF_Basics17( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
}
ATerm lf_AUX_MuASF_Basics17_1( ATerm arg0) {
{
ATerm tmp[4];
PROF( prof_lf_AUX_MuASF_Basics17_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( not_empty_list( atmp000)) {
if( term_equal( list_head( atmp000) , make_char( 34))) {
tmp[ 0]= list_tail( atmp000);
if( not_empty_list( tmp[ 0])) {
if( term_equal( list_head( tmp[ 0]) , make_char( 123))) {
tmp[ 1]= list_tail( tmp[ 0]);
tmp[ 2]= list_prefix( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
if( term_equal( list_last( tmp[ 1]) , make_char( 34))) {
tmp[ 3]= list_prefix( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( not_empty_list( tmp[ 2])) {
if( term_equal( list_last( tmp[ 2]) , make_char( 125))) {
return ( * ef1)( lf2( cons( ( constant0? constant0: ( constant0= make_list_char( 34))) , cons( ( constant1? constant1: ( constant1= make_list_char( 123))) , cons( make_list( tmp[ 3]) , ( constant2? constant2: ( constant2= (ATerm) ATmakeList( 8 , char_table[ 125] , char_table[ 34] , char_table[ 45] , char_table[ 116] , char_table[ 114] , char_table[ 97] , char_table[ 110] , char_table[ 115]))))))));
}
}
}
}
}
}
}
}
}
}
}
}
}
return make_nf1( lf_AUX_MuASF_Basics17_1sym , arg0);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

