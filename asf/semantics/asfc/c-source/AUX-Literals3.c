#include "support.h"
static asymbol * lf_AUX_Literals3_1sym;
static aterm * lf_AUX_Literals3_1( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
void register_AUX_Literals3( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Literals3_1sym= TmkSymbol( "prod(id(\"Literals\"),w(\"\"),[l(\"de-escape\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Literals\"),w(\"\"),[l(\"de-escape\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Literal\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)") , lf_AUX_Literals3_1 , lf_AUX_Literals3_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf2 , lf2sym);
}
void resolve_AUX_Literals3( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"literal\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Literals\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Literals\"),w(\"\"),[sort(\"Literal\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Literal\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
}
aterm * lf_AUX_Literals3_1( aterm * arg0) {
{
aterm * tmp[7];
PROF( prof_lf_AUX_Literals3_1);
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp000);
tmp[ 0]= list_head( atmp000);
t_protect( tmp[ 0]);
if( term_equal( tmp[ 0] , make_char( 34))) {
t_protect( atmp000);
tmp[ 1]= list_tail( atmp000);
t_protect( tmp[ 1]);
if( is_single_element( tmp[ 1])) {
t_protect( tmp[ 1]);
if( term_equal( list_head( tmp[ 1]) , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
return ( * ef1)( lf2( cons( make_list( make_char( 34)) , make_list( make_char( 34)))));
}
}
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_protect( tmp[ 1]);
tmp[ 2]= list_head( tmp[ 1]);
t_protect( tmp[ 2]);
if( term_equal( tmp[ 2] , make_char( 92))) {
t_protect( tmp[ 1]);
tmp[ 3]= list_tail( tmp[ 1]);
t_protect( tmp[ 3]);
if( not_empty_list( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 4]= list_head( tmp[ 3]);
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 92))) {
t_protect( tmp[ 3]);
tmp[ 5]= list_tail( tmp[ 3]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
tmp[ 6]= list_prefix( tmp[ 5]);
t_protect( tmp[ 5]);
if( term_equal( list_last( tmp[ 5]) , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef2)( ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 92)) , make_list( make_char( 34)))))) , lf_AUX_Literals3_1( ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 6]) , make_list( make_char( 34))))))));
}
t_unprotect( tmp[ 6]);
}
t_unprotect( tmp[ 5]);
}
t_protect( tmp[ 4]);
if( term_equal( tmp[ 4] , make_char( 34))) {
t_protect( tmp[ 3]);
tmp[ 5]= list_tail( tmp[ 3]);
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
tmp[ 6]= list_prefix( tmp[ 5]);
t_protect( tmp[ 5]);
if( term_equal( list_last( tmp[ 5]) , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 5]);
return ( * ef2)( ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( make_char( 34)) , make_list( make_char( 34)))))) , lf_AUX_Literals3_1( ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 6]) , make_list( make_char( 34))))))));
}
t_unprotect( tmp[ 6]);
}
t_unprotect( tmp[ 5]);
}
t_unprotect( tmp[ 4]);
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg0 , ef1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf2sym)) {
{
aterm * atmp000= arg_0( atmp00);
t_protect( atmp000);
if( not_empty_list( atmp000)) {
t_protect( atmp000);
if( term_equal( list_head( atmp000) , make_char( 34))) {
t_protect( atmp000);
tmp[ 0]= list_tail( atmp000);
t_protect( tmp[ 0]);
if( not_empty_list( tmp[ 0])) {
t_protect( tmp[ 0]);
tmp[ 1]= list_head( tmp[ 0]);
t_protect( tmp[ 0]);
tmp[ 2]= list_tail( tmp[ 0]);
t_protect( tmp[ 2]);
if( not_empty_list( tmp[ 2])) {
t_protect( tmp[ 2]);
tmp[ 3]= list_prefix( tmp[ 2]);
t_protect( tmp[ 2]);
if( term_equal( list_last( tmp[ 2]) , make_char( 34))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 2]);
return ( * ef2)( ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 1]) , make_list( make_char( 34)))))) , lf_AUX_Literals3_1( ( * ef1)( lf2( cons( make_list( make_char( 34)) , cons( make_list( tmp[ 3]) , make_list( make_char( 34))))))));
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 2]);
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
return make_nf1( lf_AUX_Literals3_1sym , arg0);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

