#include "support.h"
static Symbol lf_AUX_MuASF_Basics29_1sym;
static ATerm lf_AUX_MuASF_Basics29_1( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_MuASF_Basics29( ) {
lf_AUX_MuASF_Basics29_1sym= ATmakeSymbol( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"deslashed-lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Basics29_1sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"deslashed-lit2str\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Basics29_1 , lf_AUX_MuASF_Basics29_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
register_prod( ATparse( "listtype(sort(\"Term\"),ql(\",\"))") , lf3 , lf3sym);
}
void resolve_AUX_MuASF_Basics29( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"char2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"char2id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
static ATerm constant1= NULL;
static ATerm constant2= NULL;
static ATerm constant3= NULL;
static ATerm constant4= NULL;
static ATerm constant5= NULL;
static ATerm constant6= NULL;
static ATerm constant7= NULL;
void init_AUX_MuASF_Basics29( ) {
ATprotect( & constant0);
ATprotect( & constant1);
ATprotect( & constant2);
ATprotect( & constant3);
ATprotect( & constant4);
ATprotect( & constant5);
ATprotect( & constant6);
ATprotect( & constant7);
}
ATerm lf_AUX_MuASF_Basics29_1( ATerm arg0) {
{
ATerm tmp[8];
PROF( prof_lf_AUX_MuASF_Basics29_1);
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
if( term_equal( tmp[ 4] , make_char( 92))) {
tmp[ 5]= list_tail( tmp[ 3]);
{
if( is_single_element( tmp[ 5])) {
if( term_equal( list_head( tmp[ 5]) , make_char( 34))) {
return ( constant0? constant0: ( constant0= ( * ef2)( ( * ef3)( lf2( (ATerm) ATmakeList( 2 , char_table[ 92] , char_table[ 92]))))));
}
}
if( not_empty_list( tmp[ 5])) {
tmp[ 6]= list_prefix( tmp[ 5]);
if( not_empty_list( tmp[ 6])) {
if( term_equal( list_last( tmp[ 5]) , make_char( 34))) {
return ( * ef5)( ( constant1? constant1: ( constant1= ( * ef3)( lf2( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( ( constant2? constant2: ( constant2= make_list( ( * ef2)( ( * ef3)( lf2( (ATerm) ATmakeList( 2 , char_table[ 92] , char_table[ 92]))))))) , make_list( lf_AUX_MuASF_Basics29_1( ( * ef1)( lf2( cons( ( constant3? constant3: ( constant3= make_list_char( 34))) , cons( make_list( tmp[ 6]) , ( constant4? constant4: ( constant4= make_list( make_char( 34)))))))))))));
}
}
}
}
}
tmp[ 5]= make_char( 34);
if( term_equal( tmp[ 4] , tmp[ 5])) {
tmp[ 6]= list_tail( tmp[ 3]);
{
if( not_empty_list( tmp[ 6])) {
tmp[ 7]= list_prefix( tmp[ 6]);
if( not_empty_list( tmp[ 7])) {
if( term_equal( list_last( tmp[ 6]) , make_char( 34))) {
return ( * ef5)( ( constant1? constant1: ( constant1= ( * ef3)( lf2( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( ( constant5? constant5: ( constant5= make_list( ( * ef2)( ( * ef3)( lf2( (ATerm) ATmakeList( 2 , char_table[ 39] , char_table[ 34]))))))) , make_list( lf_AUX_MuASF_Basics29_1( ( * ef1)( lf2( cons( ( constant3? constant3: ( constant3= make_list_char( 34))) , cons( make_list( tmp[ 7]) , ( constant4? constant4: ( constant4= make_list( make_char( 34)))))))))))));
}
}
}
if( is_single_element( tmp[ 6])) {
if( term_equal( list_head( tmp[ 6]) , make_char( 34))) {
return ( constant6? constant6: ( constant6= ( * ef2)( ( * ef3)( lf2( (ATerm) ATmakeList( 2 , char_table[ 39] , char_table[ 34]))))));
}
}
}
}
}
}
}
tmp[ 3]= list_head( tmp[ 1]);
tmp[ 4]= list_tail( tmp[ 1]);
if( is_single_element( tmp[ 4])) {
if( term_equal( list_head( tmp[ 4]) , make_char( 34))) {
return ( * ef4)( ( * ef1)( lf2( cons( ( constant3? constant3: ( constant3= make_list_char( 34))) , cons( make_list( tmp[ 3]) , ( constant4? constant4: ( constant4= make_list( make_char( 34)))))))));
}
}
}
if( is_single_element( tmp[ 1])) {
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
return ( constant7? constant7: ( constant7= ( * ef2)( ( * ef3)( lf2( (ATerm) ATmakeList( 4 , char_table[ 110] , char_table[ 117] , char_table[ 108] , char_table[ 108]))))));
}
}
}
}
}
}
}
}
}
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
tmp[ 1]= list_head( tmp[ 0]);
tmp[ 2]= list_tail( tmp[ 0]);
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= list_prefix( tmp[ 2]);
if( not_empty_list( tmp[ 3])) {
if( term_equal( list_last( tmp[ 2]) , make_char( 34))) {
return ( * ef5)( ( constant1? constant1: ( constant1= ( * ef3)( lf2( (ATerm) ATmakeList( 4 , char_table[ 99] , char_table[ 111] , char_table[ 110] , char_table[ 115]))))) , lf3( cons( make_list( ( * ef4)( ( * ef1)( lf2( cons( ( constant3? constant3: ( constant3= make_list_char( 34))) , cons( make_list( tmp[ 1]) , ( constant4? constant4: ( constant4= make_list( make_char( 34)))))))))) , make_list( lf_AUX_MuASF_Basics29_1( ( * ef1)( lf2( cons( ( constant3? constant3: ( constant3= make_list_char( 34))) , cons( make_list( tmp[ 3]) , ( constant4? constant4: ( constant4= make_list( make_char( 34)))))))))))));
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
return make_nf1( lf_AUX_MuASF_Basics29_1sym , arg0);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

