#include "support.h"
static asymbol * lf_AUX_Trans_Lookup_Pats4_1sym;
static aterm * lf_AUX_Trans_Lookup_Pats4_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef16sym;
static funcptr ef16;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef15sym;
static funcptr ef15;
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * ef14sym;
static funcptr ef14;
static asymbol * ef17sym;
static funcptr ef17;
static asymbol * ef20sym;
static funcptr ef20;
static asymbol * ef18sym;
static funcptr ef18;
static asymbol * ef21sym;
static funcptr ef21;
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef19sym;
static funcptr ef19;
static asymbol * ef22sym;
static funcptr ef22;
static asymbol * ef23sym;
static funcptr ef23;
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf2sym;
static aterm * lf2( aterm * arg1);
static asymbol * new__1__lf_AUX_Trans_Lookup_Pats4_1sym;
static aterm * new__1__lf_AUX_Trans_Lookup_Pats4_1( aterm * arg1 , aterm * arg2 , aterm * arg3);
void register_AUX_Trans_Lookup_Pats4( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Trans_Lookup_Pats4_1sym= TmkSymbol( "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[l(\"lookup-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"PatType\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf2sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
new__1__lf_AUX_Trans_Lookup_Pats4_1sym= TmkSymbol( "new__1__lf_AUX_Trans_Lookup_Pats4_1" , SYM_STRING);
register_prod( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[l(\"lookup-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"PatType\"),w(\"\"),l(\",\"),w(\"\"),sort(\"TermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)") , lf_AUX_Trans_Lookup_Pats4_1 , lf_AUX_Trans_Lookup_Pats4_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf2 , lf2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf3 , lf3sym);
}
void resolve_AUX_Trans_Lookup_Pats4( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Var\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[ql(\"*\"),w(\"\"),sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-list-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-star-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-star-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-lookup-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Check-List-Pats\"),w(\"\"),[l(\"contains-lookup-pattern\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"VarEnv\"),w(\"\"),[l(\"newvar\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"VarId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Var\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-plus-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-plus-var\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef14= lookup_func( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef14sym= lookup_sym( TmakeSimple( & local , "prod(id(\"ANumerals\"),w(\"\"),[l(\"succ\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"));
ef15= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-cond\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef15sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-cond\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef16= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef16sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef17= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-new\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef17sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"init-new\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef18= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef18sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"is-list-cons\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef19= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef19sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"false\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef20= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef20sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-lhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef21= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef21sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[ql(\"def-rhs\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PatType\"),w(\"\"),no-attrs)"));
ef22= lookup_func( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[l(\"lookup-patterns\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"PatType\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef22sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Trans-Lookup-Pats\"),w(\"\"),[l(\"lookup-patterns\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"PatType\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef23= lookup_func( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"add-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
ef23sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Remove-Lists-Aux\"),w(\"\"),[l(\"add-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FunId\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TermList\"),w(\"\"),no-attrs)"));
}
aterm * new__1__lf_AUX_Trans_Lookup_Pats4_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[1];
PROF( prof_new__1__lf_AUX_Trans_Lookup_Pats4_1);
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp100);
if( is_single_element( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
return ( * ef2)( lf2( make_list( tmp[ 0])));
}
}
}
}
}
return make_nf3( new__1__lf_AUX_Trans_Lookup_Pats4_1sym , arg0 , arg1 , arg2);
}
}
aterm * lf_AUX_Trans_Lookup_Pats4_1( aterm * arg0 , aterm * arg1 , aterm * arg2) {
{
aterm * tmp[34];
PROF( prof_lf_AUX_Trans_Lookup_Pats4_1);
if( check_sym( arg0 , ef1sym)) {
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp100);
if( is_single_element( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( is_single_element( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 4]= list_head( tmp[ 3]);
if( check_sym( tmp[ 4] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
{
if( check_sym( tmp[ 5] , ef4sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
{
if( check_sym( tmp[ 7] , lf3sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
{
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 10]= list_head( tmp[ 8]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 99))) {
t_protect( tmp[ 8]);
tmp[ 11]= list_tail( tmp[ 8]);
t_protect( tmp[ 11]);
if( not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
tmp[ 12]= list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 111))) {
t_protect( tmp[ 11]);
tmp[ 13]= list_tail( tmp[ 11]);
t_protect( tmp[ 13]);
if( not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
tmp[ 14]= list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 110))) {
t_protect( tmp[ 13]);
tmp[ 15]= list_tail( tmp[ 13]);
t_protect( tmp[ 15]);
if( is_single_element( tmp[ 15])) {
t_protect( tmp[ 15]);
tmp[ 16]= list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 115))) {
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
tmp[ 17]= list_head( tmp[ 9]);
{
t_protect( tmp[ 9]);
tmp[ 18]= list_tail( tmp[ 9]);
t_protect( tmp[ 18]);
if( is_single_element( tmp[ 18])) {
t_protect( tmp[ 18]);
tmp[ 19]= list_head( tmp[ 18]);
t_protect( tmp[ 1]);
tmp[ 20]= ( * ef7)( tmp[ 1]);
t_protect( tmp[ 20]);
if( term_equal( tmp[ 20] , ( * ef8)( ))) {
tmp[ 21]= ( * ef8)( );
t_protect( tmp[ 17]);
t_protect( tmp[ 21]);
if( term_equal( ( * ef13)( tmp[ 17]) , tmp[ 21])) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 19]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( tmp[ 19])))))))) , ( * ef8)( ))) {
t_protect( arg2);
tmp[ 22]= ( * ef11)( arg2);
if( check_sym( tmp[ 22] , ef5sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
if( check_sym( tmp[ 23] , ef12sym)) {
tmp[ 24]= arg_0( tmp[ 23]);
t_protect( arg2);
tmp[ 25]= ( * ef11)( ( * ef14)( arg2));
if( check_sym( tmp[ 25] , ef5sym)) {
tmp[ 26]= arg_0( tmp[ 25]);
if( check_sym( tmp[ 26] , ef12sym)) {
tmp[ 27]= arg_0( tmp[ 26]);
t_protect( tmp[ 1]);
t_protect( tmp[ 24]);
t_protect( tmp[ 27]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 25]);
return ( * ef2)( lf2( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( ( * ef5)( ( * ef12)( tmp[ 24]))) , make_list( ( * ef5)( ( * ef6)( tmp[ 27]))))))))))));
}
}
t_unprotect( tmp[ 25]);
}
}
t_unprotect( tmp[ 22]);
}
}
t_protect( tmp[ 17]);
t_protect( tmp[ 21]);
if( term_equal( ( * ef9)( tmp[ 17]) , tmp[ 21])) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 19]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( tmp[ 19])))))))) , ( * ef8)( ))) {
t_protect( arg2);
tmp[ 22]= ( * ef11)( arg2);
if( check_sym( tmp[ 22] , ef5sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
if( check_sym( tmp[ 23] , ef12sym)) {
tmp[ 24]= arg_0( tmp[ 23]);
t_protect( tmp[ 1]);
t_protect( tmp[ 24]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
return ( * ef2)( lf2( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef5)( ( * ef6)( tmp[ 24]))))))));
}
}
t_unprotect( tmp[ 22]);
}
}
t_unprotect( tmp[ 21]);
}
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 19]);
}
t_unprotect( tmp[ 18]);
}
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 16]);
}
t_unprotect( tmp[ 15]);
}
t_unprotect( tmp[ 14]);
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
}
}
}
}
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
if( check_sym( arg0 , ef15sym)) {
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp100);
if( is_single_element( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( is_single_element( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 4]= list_head( tmp[ 3]);
if( check_sym( tmp[ 4] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
{
if( check_sym( tmp[ 5] , ef4sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
{
if( check_sym( tmp[ 7] , lf3sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
{
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 10]= list_head( tmp[ 8]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 99))) {
t_protect( tmp[ 8]);
tmp[ 11]= list_tail( tmp[ 8]);
t_protect( tmp[ 11]);
if( not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
tmp[ 12]= list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 111))) {
t_protect( tmp[ 11]);
tmp[ 13]= list_tail( tmp[ 11]);
t_protect( tmp[ 13]);
if( not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
tmp[ 14]= list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 110))) {
t_protect( tmp[ 13]);
tmp[ 15]= list_tail( tmp[ 13]);
t_protect( tmp[ 15]);
if( is_single_element( tmp[ 15])) {
t_protect( tmp[ 15]);
tmp[ 16]= list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 115))) {
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
tmp[ 17]= list_head( tmp[ 9]);
{
t_protect( tmp[ 9]);
tmp[ 18]= list_tail( tmp[ 9]);
t_protect( tmp[ 18]);
if( is_single_element( tmp[ 18])) {
t_protect( tmp[ 18]);
tmp[ 19]= list_head( tmp[ 18]);
t_protect( tmp[ 1]);
tmp[ 20]= ( * ef7)( tmp[ 1]);
t_protect( tmp[ 20]);
if( term_equal( tmp[ 20] , ( * ef8)( ))) {
tmp[ 21]= ( * ef8)( );
t_protect( tmp[ 17]);
t_protect( tmp[ 21]);
if( term_equal( ( * ef13)( tmp[ 17]) , tmp[ 21])) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 19]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( tmp[ 19])))))))) , ( * ef8)( ))) {
t_protect( arg2);
tmp[ 22]= ( * ef11)( arg2);
if( check_sym( tmp[ 22] , ef5sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
if( check_sym( tmp[ 23] , ef12sym)) {
tmp[ 24]= arg_0( tmp[ 23]);
t_protect( arg2);
tmp[ 25]= ( * ef11)( ( * ef14)( arg2));
if( check_sym( tmp[ 25] , ef5sym)) {
tmp[ 26]= arg_0( tmp[ 25]);
if( check_sym( tmp[ 26] , ef12sym)) {
tmp[ 27]= arg_0( tmp[ 26]);
t_protect( tmp[ 1]);
t_protect( tmp[ 24]);
t_protect( tmp[ 1]);
t_protect( tmp[ 27]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 25]);
return ( * ef2)( lf2( cons( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef5)( ( * ef12)( tmp[ 24])))))) , make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef5)( ( * ef6)( tmp[ 27])))))))));
}
}
t_unprotect( tmp[ 25]);
}
}
t_unprotect( tmp[ 22]);
}
}
t_protect( tmp[ 17]);
t_protect( tmp[ 21]);
if( term_equal( ( * ef9)( tmp[ 17]) , tmp[ 21])) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 19]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( tmp[ 19])))))))) , ( * ef8)( ))) {
t_protect( arg2);
tmp[ 22]= ( * ef11)( arg2);
if( check_sym( tmp[ 22] , ef5sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
if( check_sym( tmp[ 23] , ef12sym)) {
tmp[ 24]= arg_0( tmp[ 23]);
t_protect( tmp[ 1]);
t_protect( tmp[ 1]);
t_protect( tmp[ 24]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
return ( * ef2)( lf2( cons( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef16)( ( * ef4)( lf3( cons( make_list( make_char( 110)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 108)) , make_list( make_char( 108)))))))))))) , make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef5)( ( * ef6)( tmp[ 24])))))))));
}
}
t_unprotect( tmp[ 22]);
}
}
t_unprotect( tmp[ 21]);
}
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 19]);
}
t_unprotect( tmp[ 18]);
}
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 16]);
}
t_unprotect( tmp[ 15]);
}
t_unprotect( tmp[ 14]);
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
}
}
}
}
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
if( check_sym( arg0 , ef17sym)) {
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp100);
if( is_single_element( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( is_single_element( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 4]= list_head( tmp[ 3]);
if( check_sym( tmp[ 4] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
{
if( check_sym( tmp[ 5] , ef4sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
{
if( check_sym( tmp[ 7] , lf3sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
{
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 10]= list_head( tmp[ 8]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 99))) {
t_protect( tmp[ 8]);
tmp[ 11]= list_tail( tmp[ 8]);
t_protect( tmp[ 11]);
if( not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
tmp[ 12]= list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 111))) {
t_protect( tmp[ 11]);
tmp[ 13]= list_tail( tmp[ 11]);
t_protect( tmp[ 13]);
if( not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
tmp[ 14]= list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 110))) {
t_protect( tmp[ 13]);
tmp[ 15]= list_tail( tmp[ 13]);
t_protect( tmp[ 15]);
if( is_single_element( tmp[ 15])) {
t_protect( tmp[ 15]);
tmp[ 16]= list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 115))) {
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
tmp[ 17]= list_head( tmp[ 9]);
{
t_protect( tmp[ 9]);
tmp[ 18]= list_tail( tmp[ 9]);
t_protect( tmp[ 18]);
if( is_single_element( tmp[ 18])) {
t_protect( tmp[ 18]);
tmp[ 19]= list_head( tmp[ 18]);
if( check_sym( tmp[ 19] , ef3sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
tmp[ 21]= arg_1( tmp[ 19]);
if( check_sym( tmp[ 20] , ef4sym)) {
tmp[ 22]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 22] , lf3sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
if( check_sym( tmp[ 21] , lf2sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
t_protect( tmp[ 23]);
if( not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 99))) {
t_protect( tmp[ 23]);
tmp[ 25]= list_tail( tmp[ 23]);
t_protect( tmp[ 25]);
if( not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 111))) {
t_protect( tmp[ 25]);
tmp[ 26]= list_tail( tmp[ 25]);
t_protect( tmp[ 26]);
if( not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 110))) {
t_protect( tmp[ 26]);
tmp[ 27]= list_tail( tmp[ 26]);
t_protect( tmp[ 27]);
if( is_single_element( tmp[ 27])) {
t_protect( tmp[ 27]);
if( term_equal( list_head( tmp[ 27]) , make_char( 115))) {
t_protect( tmp[ 24]);
if( not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
tmp[ 28]= list_head( tmp[ 24]);
t_protect( tmp[ 24]);
tmp[ 29]= list_tail( tmp[ 24]);
t_protect( tmp[ 29]);
if( is_single_element( tmp[ 29])) {
t_protect( tmp[ 29]);
tmp[ 30]= list_head( tmp[ 29]);
t_protect( tmp[ 1]);
if( term_equal( ( * ef7)( tmp[ 1]) , ( * ef8)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 28]);
t_protect( tmp[ 30]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 28]) , make_list( tmp[ 30])))))))))))) , ( * ef8)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 29]);
return ( * ef2)( lf2( cons( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( tmp[ 17])))) , make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 28]) , make_list( tmp[ 30])))))))))));
}
}
t_unprotect( tmp[ 30]);
}
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 28]);
}
}
}
t_unprotect( tmp[ 27]);
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
}
}
}
}
}
}
t_protect( tmp[ 19]);
if( term_equal( ( * ef18)( tmp[ 19]) , ( * ef19)( ))) {
t_protect( tmp[ 1]);
if( term_equal( ( * ef7)( tmp[ 1]) , ( * ef8)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 19]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( tmp[ 19])))))))) , ( * ef8)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
return ( * ef2)( lf2( cons( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( tmp[ 17])))) , make_list( ( * ef3)( tmp[ 1] , lf2( make_list( tmp[ 19])))))));
}
}
}
t_unprotect( tmp[ 19]);
}
t_unprotect( tmp[ 18]);
}
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 16]);
}
t_unprotect( tmp[ 15]);
}
t_unprotect( tmp[ 14]);
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
}
}
}
}
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
if( check_sym( arg0 , ef20sym)) {
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp100);
if( is_single_element( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( is_single_element( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 4]= list_head( tmp[ 3]);
if( check_sym( tmp[ 4] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
{
if( check_sym( tmp[ 5] , ef4sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
{
if( check_sym( tmp[ 7] , lf3sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
{
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 10]= list_head( tmp[ 8]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 99))) {
t_protect( tmp[ 8]);
tmp[ 11]= list_tail( tmp[ 8]);
t_protect( tmp[ 11]);
if( not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
tmp[ 12]= list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 111))) {
t_protect( tmp[ 11]);
tmp[ 13]= list_tail( tmp[ 11]);
t_protect( tmp[ 13]);
if( not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
tmp[ 14]= list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 110))) {
t_protect( tmp[ 13]);
tmp[ 15]= list_tail( tmp[ 13]);
t_protect( tmp[ 15]);
if( is_single_element( tmp[ 15])) {
t_protect( tmp[ 15]);
tmp[ 16]= list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 115))) {
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
tmp[ 17]= list_head( tmp[ 9]);
{
t_protect( tmp[ 9]);
tmp[ 18]= list_tail( tmp[ 9]);
t_protect( tmp[ 18]);
if( is_single_element( tmp[ 18])) {
t_protect( tmp[ 18]);
tmp[ 19]= list_head( tmp[ 18]);
if( check_sym( tmp[ 19] , ef3sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
tmp[ 21]= arg_1( tmp[ 19]);
if( check_sym( tmp[ 20] , ef4sym)) {
tmp[ 22]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 22] , lf3sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
if( check_sym( tmp[ 21] , lf2sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
t_protect( tmp[ 23]);
if( not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 99))) {
t_protect( tmp[ 23]);
tmp[ 25]= list_tail( tmp[ 23]);
t_protect( tmp[ 25]);
if( not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 111))) {
t_protect( tmp[ 25]);
tmp[ 26]= list_tail( tmp[ 25]);
t_protect( tmp[ 26]);
if( not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 110))) {
t_protect( tmp[ 26]);
tmp[ 27]= list_tail( tmp[ 26]);
t_protect( tmp[ 27]);
if( is_single_element( tmp[ 27])) {
t_protect( tmp[ 27]);
if( term_equal( list_head( tmp[ 27]) , make_char( 115))) {
t_protect( tmp[ 24]);
if( not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
tmp[ 28]= list_head( tmp[ 24]);
t_protect( tmp[ 24]);
tmp[ 29]= list_tail( tmp[ 24]);
t_protect( tmp[ 29]);
if( is_single_element( tmp[ 29])) {
t_protect( tmp[ 29]);
tmp[ 30]= list_head( tmp[ 29]);
t_protect( tmp[ 1]);
if( term_equal( ( * ef7)( tmp[ 1]) , ( * ef8)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 28]);
t_protect( tmp[ 30]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 28]) , make_list( tmp[ 30])))))))))))) , ( * ef8)( ))) {
t_protect( arg2);
tmp[ 31]= ( * ef11)( arg2);
if( check_sym( tmp[ 31] , ef5sym)) {
tmp[ 32]= arg_0( tmp[ 31]);
if( check_sym( tmp[ 32] , ef12sym)) {
tmp[ 33]= arg_0( tmp[ 32]);
t_protect( tmp[ 1]);
t_protect( tmp[ 1]);
t_protect( tmp[ 33]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 31]);
return ( * ef2)( lf2( cons( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( tmp[ 17])))) , make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( ( * ef5)( ( * ef12)( tmp[ 33]))) , make_list( tmp[ 30])))))))))));
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 28]);
}
}
}
t_unprotect( tmp[ 27]);
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
}
}
}
}
}
}
t_protect( tmp[ 19]);
if( term_equal( ( * ef18)( tmp[ 19]) , ( * ef19)( ))) {
t_protect( tmp[ 1]);
if( term_equal( ( * ef7)( tmp[ 1]) , ( * ef8)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 19]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( tmp[ 19])))))))) , ( * ef8)( ))) {
t_protect( arg2);
tmp[ 20]= ( * ef11)( arg2);
if( check_sym( tmp[ 20] , ef5sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 21] , ef12sym)) {
tmp[ 22]= arg_0( tmp[ 21]);
t_protect( tmp[ 1]);
t_protect( tmp[ 1]);
t_protect( tmp[ 22]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 20]);
return ( * ef2)( lf2( cons( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( tmp[ 17])))) , make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( ( * ef5)( ( * ef12)( tmp[ 22]))) , make_list( tmp[ 19])))))))))));
}
}
t_unprotect( tmp[ 20]);
}
}
}
t_unprotect( tmp[ 19]);
}
t_unprotect( tmp[ 18]);
}
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 16]);
}
t_unprotect( tmp[ 15]);
}
t_unprotect( tmp[ 14]);
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
}
}
}
}
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
if( check_sym( arg0 , ef21sym)) {
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp100);
if( is_single_element( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( is_single_element( tmp[ 3])) {
t_protect( tmp[ 3]);
tmp[ 4]= list_head( tmp[ 3]);
if( check_sym( tmp[ 4] , ef3sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
{
if( check_sym( tmp[ 5] , ef4sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
{
if( check_sym( tmp[ 7] , lf3sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
{
if( check_sym( tmp[ 6] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 6]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 10]= list_head( tmp[ 8]);
t_protect( tmp[ 10]);
if( term_equal( tmp[ 10] , make_char( 99))) {
t_protect( tmp[ 8]);
tmp[ 11]= list_tail( tmp[ 8]);
t_protect( tmp[ 11]);
if( not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
tmp[ 12]= list_head( tmp[ 11]);
t_protect( tmp[ 12]);
if( term_equal( tmp[ 12] , make_char( 111))) {
t_protect( tmp[ 11]);
tmp[ 13]= list_tail( tmp[ 11]);
t_protect( tmp[ 13]);
if( not_empty_list( tmp[ 13])) {
t_protect( tmp[ 13]);
tmp[ 14]= list_head( tmp[ 13]);
t_protect( tmp[ 14]);
if( term_equal( tmp[ 14] , make_char( 110))) {
t_protect( tmp[ 13]);
tmp[ 15]= list_tail( tmp[ 13]);
t_protect( tmp[ 15]);
if( is_single_element( tmp[ 15])) {
t_protect( tmp[ 15]);
tmp[ 16]= list_head( tmp[ 15]);
t_protect( tmp[ 16]);
if( term_equal( tmp[ 16] , make_char( 115))) {
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
tmp[ 17]= list_head( tmp[ 9]);
{
t_protect( tmp[ 9]);
tmp[ 18]= list_tail( tmp[ 9]);
t_protect( tmp[ 18]);
if( is_single_element( tmp[ 18])) {
t_protect( tmp[ 18]);
tmp[ 19]= list_head( tmp[ 18]);
if( check_sym( tmp[ 19] , ef3sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
tmp[ 21]= arg_1( tmp[ 19]);
if( check_sym( tmp[ 20] , ef4sym)) {
tmp[ 22]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 22] , lf3sym)) {
tmp[ 23]= arg_0( tmp[ 22]);
if( check_sym( tmp[ 21] , lf2sym)) {
tmp[ 24]= arg_0( tmp[ 21]);
t_protect( tmp[ 23]);
if( not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 99))) {
t_protect( tmp[ 23]);
tmp[ 25]= list_tail( tmp[ 23]);
t_protect( tmp[ 25]);
if( not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 111))) {
t_protect( tmp[ 25]);
tmp[ 26]= list_tail( tmp[ 25]);
t_protect( tmp[ 26]);
if( not_empty_list( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 110))) {
t_protect( tmp[ 26]);
tmp[ 27]= list_tail( tmp[ 26]);
t_protect( tmp[ 27]);
if( is_single_element( tmp[ 27])) {
t_protect( tmp[ 27]);
if( term_equal( list_head( tmp[ 27]) , make_char( 115))) {
t_protect( tmp[ 24]);
if( not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
tmp[ 28]= list_head( tmp[ 24]);
t_protect( tmp[ 24]);
tmp[ 29]= list_tail( tmp[ 24]);
t_protect( tmp[ 29]);
if( is_single_element( tmp[ 29])) {
t_protect( tmp[ 29]);
tmp[ 30]= list_head( tmp[ 29]);
t_protect( tmp[ 1]);
if( term_equal( ( * ef7)( tmp[ 1]) , ( * ef8)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 28]);
t_protect( tmp[ 30]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 28]) , make_list( tmp[ 30])))))))))))) , ( * ef8)( ))) {
t_protect( arg2);
tmp[ 31]= ( * ef11)( arg2);
if( check_sym( tmp[ 31] , ef5sym)) {
tmp[ 32]= arg_0( tmp[ 31]);
if( check_sym( tmp[ 32] , ef12sym)) {
tmp[ 33]= arg_0( tmp[ 32]);
t_protect( tmp[ 1]);
t_protect( tmp[ 33]);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 31]);
return ( * ef2)( lf2( cons( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( ( * ef5)( ( * ef12)( tmp[ 33])))))))))) , make_list( ( * ef3)( tmp[ 1] , lf2( make_list( tmp[ 30])))))));
}
}
t_unprotect( tmp[ 31]);
}
}
t_unprotect( tmp[ 30]);
}
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 28]);
}
}
}
t_unprotect( tmp[ 27]);
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
}
}
}
}
}
}
t_protect( tmp[ 19]);
if( term_equal( ( * ef18)( tmp[ 19]) , ( * ef19)( ))) {
t_protect( tmp[ 1]);
if( term_equal( ( * ef7)( tmp[ 1]) , ( * ef8)( ))) {
t_protect( tmp[ 1]);
t_protect( tmp[ 17]);
t_protect( tmp[ 19]);
if( term_equal( ( * ef10)( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( tmp[ 19])))))))) , ( * ef8)( ))) {
t_protect( arg2);
tmp[ 20]= ( * ef11)( arg2);
if( check_sym( tmp[ 20] , ef5sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
if( check_sym( tmp[ 21] , ef12sym)) {
tmp[ 22]= arg_0( tmp[ 21]);
t_protect( tmp[ 1]);
t_protect( tmp[ 22]);
t_protect( tmp[ 1]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 20]);
return ( * ef2)( lf2( cons( make_list( ( * ef3)( tmp[ 1] , lf2( make_list( ( * ef3)( ( * ef4)( lf3( cons( make_list( make_char( 99)) , cons( make_list( make_char( 111)) , cons( make_list( make_char( 110)) , make_list( make_char( 115))))))) , lf2( cons( make_list( tmp[ 17]) , make_list( ( * ef5)( ( * ef12)( tmp[ 22])))))))))) , make_list( ( * ef3)( tmp[ 1] , lf2( make_list( tmp[ 19])))))));
}
}
t_unprotect( tmp[ 20]);
}
}
}
t_unprotect( tmp[ 19]);
}
t_unprotect( tmp[ 18]);
}
t_unprotect( tmp[ 17]);
}
}
t_unprotect( tmp[ 16]);
}
t_unprotect( tmp[ 15]);
}
t_unprotect( tmp[ 14]);
}
t_unprotect( tmp[ 13]);
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 11]);
}
t_unprotect( tmp[ 10]);
}
}
}
}
}
}
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
}
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp100);
if( is_single_element( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
if( check_sym( tmp[ 2] , lf2sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
t_protect( tmp[ 3]);
if( not_empty_list( tmp[ 3])) {
t_protect( tmp[ 1]);
if( term_equal( ( * ef7)( tmp[ 1]) , ( * ef19)( ))) {
t_protect( arg0);
t_protect( tmp[ 3]);
t_protect( arg2);
tmp[ 4]= ( * ef22)( arg0 , lf2( make_list( tmp[ 3])) , arg2);
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
if( check_sym( tmp[ 5] , lf2sym)) {
tmp[ 6]= arg_0( tmp[ 5]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 1]);
t_protect( tmp[ 6]);
tmp[ 7]= ( * ef23)( tmp[ 1] , lf2( make_list( tmp[ 6])));
if( check_sym( tmp[ 7] , ef2sym)) {
tmp[ 8]= arg_0( tmp[ 7]);
if( check_sym( tmp[ 8] , lf2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
t_protect( tmp[ 9]);
if( not_empty_list( tmp[ 9])) {
t_protect( tmp[ 9]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 7]);
return ( * ef2)( lf2( make_list( tmp[ 9])));
}
}
}
t_unprotect( tmp[ 7]);
}
}
}
t_unprotect( tmp[ 4]);
}
}
}
}
t_unprotect( tmp[ 0]);
}
t_protect( atmp100);
if( not_empty_list( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
t_protect( atmp100);
tmp[ 1]= list_tail( atmp100);
t_protect( tmp[ 1]);
if( not_empty_list( tmp[ 1])) {
t_unprotect( arg1);
return ( * ef22)( arg0 , lf2( cons( make_list( tmp[ 0]) , make_list( tmp[ 1]))) , arg2);
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg1 , ef2sym)) {
{
aterm * atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
aterm * atmp100= arg_0( atmp10);
t_protect( atmp100);
if( is_single_element( atmp100)) {
t_protect( atmp100);
tmp[ 0]= list_head( atmp100);
t_unprotect( arg1);
return new__1__lf_AUX_Trans_Lookup_Pats4_1( arg0 , ( * ef2)( lf2( make_list( tmp[ 0]))) , arg2);
}
}
}
}
}
return make_nf3( lf_AUX_Trans_Lookup_Pats4_1sym , arg0 , arg1 , arg2);
}
}
aterm * lf2( aterm * arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

