#include "support.h"
static Symbol lf_AUX_MuASF_Basics27_1sym;
static ATerm lf_AUX_MuASF_Basics27_1( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
void register_AUX_MuASF_Basics27( ) {
lf_AUX_MuASF_Basics27_1sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"qlit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics27_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"qlit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics27_1 , lf_AUX_MuASF_Basics27_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Basics27( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
void init_AUX_MuASF_Basics27( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
}
ATerm lf_AUX_MuASF_Basics27_1( ATerm arg0) {
{
ATerm tmp[9];
PROF( prof_lf_AUX_MuASF_Basics27_1);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
ATerm atmp000= arg_0( atmp00);
if( not_empty_list( atmp000)) {
tmp[ 0]= list_head( atmp000);
if( term_equal( tmp[ 0] , make_char( 34))) {
tmp[ 1]= list_tail( atmp000);
{
if( not_empty_list( tmp[ 1])) {
tmp[ 2]= list_head( tmp[ 1]);
if( term_equal( tmp[ 2] , make_char( 92))) {
tmp[ 3]= list_tail( tmp[ 1]);
{
if( not_empty_list( tmp[ 3])) {
tmp[ 4]= list_head( tmp[ 3]);
if( term_equal( tmp[ 4] , make_char( 34))) {
tmp[ 5]= list_tail( tmp[ 3]);
tmp[ 6]= list_prefix( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_last( tmp[ 5]) , make_char( 34))) {
tmp[ 7]= list_prefix( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
if( term_equal( list_last( tmp[ 6]) , make_char( 34))) {
tmp[ 8]= list_prefix( tmp[ 7]);
if( not_empty_list( tmp[ 8])) {
if( not_empty_list( tmp[ 7])) {
if( term_equal( list_last( tmp[ 7]) , make_char( 92))) {
return ( * ef4)( ( * ef1)( lf2( cons( ( constant0? constant0: ( constant0= make_list_char( 34))) , cons( make_list( tmp[ 8]) , ( constant1? constant1: ( constant1= make_list( make_char( 34)))))))));
}
}
}
}
}
}
}
if( not_empty_list( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 92))) {
tmp[ 6]= list_tail( tmp[ 5]);
if( not_empty_list( tmp[ 6])) {
if( term_equal( list_head( tmp[ 6]) , make_char( 34))) {
tmp[ 7]= list_tail( tmp[ 6]);
if( is_single_element( tmp[ 7])) {
if( term_equal( list_head( tmp[ 7]) , make_char( 34))) {
return ( constant2? constant2: ( constant2= ( * ef2)( ( * ef3)( lf2( (ATerm) ATmakeList( 4 , char_table[ 110] , char_table[ 117] , char_table[ 108] , char_table[ 108]))))));
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
}
}
}
}
}
return ( * ef4)( arg0);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

