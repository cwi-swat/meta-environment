#include "support.h"
static asymbol * lf_AUX_Check_List_Pats21_2sym;
static aterm * lf_AUX_Check_List_Pats21_2( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf_AUX_Check_List_Pats21_1sym;
static aterm * lf_AUX_Check_List_Pats21_1( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * new__1__lf_AUX_Check_List_Pats21_2sym;
static aterm * new__1__lf_AUX_Check_List_Pats21_2( aterm * arg1);
void register_AUX_Check_List_Pats21( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Check_List_Pats21_2sym= TmkSymbol( "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"is-list-elem-list-elem-list\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_Check_List_Pats21_1sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
new__1__lf_AUX_Check_List_Pats21_2sym= TmkSymbol( "new__1__lf_AUX_Check_List_Pats21_2" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf_AUX_Check_List_Pats21_1 , lf_AUX_Check_List_Pats21_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"is-list-elem-list-elem-list\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)") , lf_AUX_Check_List_Pats21_2 , lf_AUX_Check_List_Pats21_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_Check_List_Pats21( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-var-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
}
aterm * new__1__lf_AUX_Check_List_Pats21_2( aterm * arg0) {
PROF( prof_new__1__lf_AUX_Check_List_Pats21_2);
if( check_sym( arg0 , lf_AUX_Check_List_Pats21_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_unprotect( arg0);
return ( * ef5)( );
}
}
return make_nf1( new__1__lf_AUX_Check_List_Pats21_2sym , arg0);
}
aterm * lf_AUX_Check_List_Pats21_2( aterm * arg0) {
{
aterm * tmp[45];
PROF( prof_lf_AUX_Check_List_Pats21_2);
if( check_sym( arg0 , lf_AUX_Check_List_Pats21_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( is_single_element( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
if( check_sym( tmp[ 1] , ef2sym)) {
tmp[ 3]= arg_0( tmp[ 1]);
if( check_sym( tmp[ 3] , lf3sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 2] , lf_AUX_Check_List_Pats21_1sym)) {
tmp[ 5]= arg_0( tmp[ 2]);
t_protect( tmp[ 4]);
if( not_empty_list( tmp[ 4])) {
t_protect( tmp[ 4]);
if( term_equal( list_head( tmp[ 4]) , make_char( 99))) {
t_protect( tmp[ 4]);
tmp[ 6]= list_tail( tmp[ 4]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
if( term_equal( list_head( tmp[ 6]) , make_char( 111))) {
t_protect( tmp[ 6]);
tmp[ 7]= list_tail( tmp[ 6]);
t_protect( tmp[ 7]);
if( not_empty_list( tmp[ 7])) {
t_protect( tmp[ 7]);
if( term_equal( list_head( tmp[ 7]) , make_char( 110))) {
t_protect( tmp[ 7]);
tmp[ 8]= list_tail( tmp[ 7]);
t_protect( tmp[ 8]);
if( is_single_element( tmp[ 8])) {
t_protect( tmp[ 8]);
if( term_equal( list_head( tmp[ 8]) , make_char( 115))) {
t_protect( tmp[ 5]);
if( not_empty_list( tmp[ 5])) {
t_protect( tmp[ 5]);
tmp[ 9]= list_head( tmp[ 5]);
t_protect( tmp[ 5]);
tmp[ 10]= list_tail( tmp[ 5]);
t_protect( tmp[ 10]);
if( is_single_element( tmp[ 10])) {
t_protect( tmp[ 10]);
tmp[ 11]= list_head( tmp[ 10]);
if( check_sym( tmp[ 11] , ef1sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
tmp[ 13]= arg_1( tmp[ 11]);
if( check_sym( tmp[ 12] , ef2sym)) {
tmp[ 14]= arg_0( tmp[ 12]);
if( check_sym( tmp[ 14] , lf3sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 13] , lf_AUX_Check_List_Pats21_1sym)) {
tmp[ 16]= arg_0( tmp[ 13]);
t_protect( tmp[ 15]);
if( not_empty_list( tmp[ 15])) {
t_protect( tmp[ 15]);
if( term_equal( list_head( tmp[ 15]) , make_char( 99))) {
t_protect( tmp[ 15]);
tmp[ 17]= list_tail( tmp[ 15]);
t_protect( tmp[ 17]);
if( not_empty_list( tmp[ 17])) {
t_protect( tmp[ 17]);
if( term_equal( list_head( tmp[ 17]) , make_char( 111))) {
t_protect( tmp[ 17]);
tmp[ 18]= list_tail( tmp[ 17]);
t_protect( tmp[ 18]);
if( not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 110))) {
t_protect( tmp[ 18]);
tmp[ 19]= list_tail( tmp[ 18]);
t_protect( tmp[ 19]);
if( is_single_element( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 115))) {
t_protect( tmp[ 16]);
if( not_empty_list( tmp[ 16])) {
t_protect( tmp[ 16]);
tmp[ 20]= list_head( tmp[ 16]);
t_protect( tmp[ 16]);
tmp[ 21]= list_tail( tmp[ 16]);
t_protect( tmp[ 21]);
if( is_single_element( tmp[ 21])) {
t_protect( tmp[ 21]);
tmp[ 22]= list_head( tmp[ 21]);
if( check_sym( tmp[ 22] , ef1sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
tmp[ 24]= arg_1( tmp[ 22]);
if( check_sym( tmp[ 23] , ef2sym)) {
tmp[ 25]= arg_0( tmp[ 23]);
if( check_sym( tmp[ 25] , lf3sym)) {
tmp[ 26]= arg_0( tmp[ 25]);
if( check_sym( tmp[ 24] , lf_AUX_Check_List_Pats21_1sym)) {
tmp[ 27]= arg_0( tmp[ 24]);
t_protect( tmp[ 26]);
if( not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 99))) {
t_protect( tmp[ 26]);
tmp[ 28]= list_tail( tmp[ 26]);
t_protect( tmp[ 28]);
if( not_empty_list( tmp[ 28])) {
t_protect( tmp[ 28]);
if( term_equal( list_head( tmp[ 28]) , make_char( 111))) {
t_protect( tmp[ 28]);
tmp[ 29]= list_tail( tmp[ 28]);
t_protect( tmp[ 29]);
if( not_empty_list( tmp[ 29])) {
t_protect( tmp[ 29]);
if( term_equal( list_head( tmp[ 29]) , make_char( 110))) {
t_protect( tmp[ 29]);
tmp[ 30]= list_tail( tmp[ 29]);
t_protect( tmp[ 30]);
if( is_single_element( tmp[ 30])) {
t_protect( tmp[ 30]);
if( term_equal( list_head( tmp[ 30]) , make_char( 115))) {
t_protect( tmp[ 27]);
if( not_empty_list( tmp[ 27])) {
t_protect( tmp[ 27]);
tmp[ 31]= list_head( tmp[ 27]);
t_protect( tmp[ 27]);
tmp[ 32]= list_tail( tmp[ 27]);
t_protect( tmp[ 32]);
if( is_single_element( tmp[ 32])) {
t_protect( tmp[ 32]);
tmp[ 33]= list_head( tmp[ 32]);
if( check_sym( tmp[ 33] , ef1sym)) {
tmp[ 34]= arg_0( tmp[ 33]);
tmp[ 35]= arg_1( tmp[ 33]);
if( check_sym( tmp[ 34] , ef2sym)) {
tmp[ 36]= arg_0( tmp[ 34]);
if( check_sym( tmp[ 36] , lf3sym)) {
tmp[ 37]= arg_0( tmp[ 36]);
if( check_sym( tmp[ 35] , lf_AUX_Check_List_Pats21_1sym)) {
tmp[ 38]= arg_0( tmp[ 35]);
t_protect( tmp[ 37]);
if( not_empty_list( tmp[ 37])) {
t_protect( tmp[ 37]);
if( term_equal( list_head( tmp[ 37]) , make_char( 99))) {
t_protect( tmp[ 37]);
tmp[ 39]= list_tail( tmp[ 37]);
t_protect( tmp[ 39]);
if( not_empty_list( tmp[ 39])) {
t_protect( tmp[ 39]);
if( term_equal( list_head( tmp[ 39]) , make_char( 111))) {
t_protect( tmp[ 39]);
tmp[ 40]= list_tail( tmp[ 39]);
t_protect( tmp[ 40]);
if( not_empty_list( tmp[ 40])) {
t_protect( tmp[ 40]);
if( term_equal( list_head( tmp[ 40]) , make_char( 110))) {
t_protect( tmp[ 40]);
tmp[ 41]= list_tail( tmp[ 40]);
t_protect( tmp[ 41]);
if( is_single_element( tmp[ 41])) {
t_protect( tmp[ 41]);
if( term_equal( list_head( tmp[ 41]) , make_char( 115))) {
t_protect( tmp[ 38]);
if( not_empty_list( tmp[ 38])) {
t_protect( tmp[ 38]);
tmp[ 42]= list_head( tmp[ 38]);
t_protect( tmp[ 38]);
tmp[ 43]= list_tail( tmp[ 38]);
t_protect( tmp[ 43]);
if( is_single_element( tmp[ 43])) {
t_protect( tmp[ 43]);
tmp[ 44]= list_head( tmp[ 43]);
t_protect( tmp[ 9]);
if( term_equal( ( * ef4)( tmp[ 9]) , ( * ef3)( ))) {
t_protect( tmp[ 20]);
if( term_equal( ( * ef4)( tmp[ 20]) , ( * ef5)( ))) {
t_protect( tmp[ 31]);
if( term_equal( ( * ef4)( tmp[ 31]) , ( * ef3)( ))) {
t_protect( tmp[ 42]);
if( term_equal( ( * ef4)( tmp[ 42]) , ( * ef5)( ))) {
t_protect( tmp[ 44]);
if( term_equal( ( * ef4)( tmp[ 44]) , ( * ef3)( ))) {
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 6]);
t_unprotect( tmp[ 7]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 31]);
t_unprotect( tmp[ 32]);
t_unprotect( tmp[ 33]);
t_unprotect( tmp[ 39]);
t_unprotect( tmp[ 40]);
t_unprotect( tmp[ 41]);
t_unprotect( tmp[ 42]);
t_unprotect( tmp[ 43]);
t_unprotect( tmp[ 44]);
return ( * ef3)( );
}
}
}
}
}
t_unprotect( tmp[ 44]);
}
t_unprotect( tmp[ 43]);
t_unprotect( tmp[ 42]);
}
}
}
t_unprotect( tmp[ 41]);
}
}
t_unprotect( tmp[ 40]);
}
}
t_unprotect( tmp[ 39]);
}
}
}
}
}
}
t_unprotect( tmp[ 33]);
}
t_unprotect( tmp[ 32]);
t_unprotect( tmp[ 31]);
}
}
}
t_unprotect( tmp[ 30]);
}
}
t_unprotect( tmp[ 29]);
}
}
t_unprotect( tmp[ 28]);
}
}
}
}
}
}
t_unprotect( tmp[ 22]);
}
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 20]);
}
}
}
t_unprotect( tmp[ 19]);
}
}
t_unprotect( tmp[ 18]);
}
}
t_unprotect( tmp[ 17]);
}
}
}
}
}
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
t_unprotect( tmp[ 8]);
}
}
t_unprotect( tmp[ 7]);
}
}
t_unprotect( tmp[ 6]);
}
}
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
if( check_sym( arg0 , lf_AUX_Check_List_Pats21_1sym)) {
{
aterm * atmp00= arg_0( arg0);
return new__1__lf_AUX_Check_List_Pats21_2( arg0);
}
}
return make_nf1( lf_AUX_Check_List_Pats21_2sym , arg0);
}
}
aterm * lf_AUX_Check_List_Pats21_1( aterm * arg0) {
PROF( prof_lf_AUX_Check_List_Pats21_1);
return make_nf1( lf_AUX_Check_List_Pats21_1sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

