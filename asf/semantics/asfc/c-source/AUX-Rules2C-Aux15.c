#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux15_2sym;
static aterm * lf_AUX_Rules2C_Aux15_2( aterm * arg1 , aterm * arg2);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Rules2C_Aux15_1sym;
static aterm * lf_AUX_Rules2C_Aux15_1( aterm * arg1);
void register_AUX_Rules2C_Aux15( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux15_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-conds-on-first-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux15_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux15_1 , lf_AUX_Rules2C_Aux15_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-conds-on-first-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux15_2 , lf_AUX_Rules2C_Aux15_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf6 , lf6sym);
}
void resolve_AUX_Rules2C_Aux15( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux15_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[35];
PROF( prof_lf_AUX_Rules2C_Aux15_2);
if( check_sym( arg1 , lf_AUX_Rules2C_Aux15_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_not_empty_list( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
tmp[ 1]= m_list_tail( atmp10);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf4sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
if( m_not_empty_list( tmp[ 8])) {
tmp[ 9]= m_list_head( tmp[ 8]);
tmp[ 10]= m_list_tail( tmp[ 8]);
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 11] , ef4sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
tmp[ 14]= arg_1( tmp[ 11]);
if( check_sym( tmp[ 13] , ef5sym)) {
tmp[ 15]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 15] , lf5sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( check_sym( tmp[ 14] , lf6sym)) {
tmp[ 17]= arg_0( tmp[ 14]);
if( m_not_empty_list( tmp[ 16])) {
t_protect( tmp[ 16]);
if( term_equal( list_head( tmp[ 16]) , make_char( 116))) {
tmp[ 18]= m_list_tail( tmp[ 16]);
if( m_not_empty_list( tmp[ 18])) {
t_protect( tmp[ 18]);
if( term_equal( list_head( tmp[ 18]) , make_char( 101))) {
tmp[ 19]= m_list_tail( tmp[ 18]);
if( m_not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
if( term_equal( list_head( tmp[ 19]) , make_char( 114))) {
tmp[ 20]= m_list_tail( tmp[ 19]);
if( m_not_empty_list( tmp[ 20])) {
t_protect( tmp[ 20]);
if( term_equal( list_head( tmp[ 20]) , make_char( 109))) {
tmp[ 21]= m_list_tail( tmp[ 20]);
if( m_not_empty_list( tmp[ 21])) {
t_protect( tmp[ 21]);
if( term_equal( list_head( tmp[ 21]) , make_char( 45))) {
tmp[ 22]= m_list_tail( tmp[ 21]);
if( m_not_empty_list( tmp[ 22])) {
t_protect( tmp[ 22]);
if( term_equal( list_head( tmp[ 22]) , make_char( 101))) {
tmp[ 23]= m_list_tail( tmp[ 22]);
if( m_not_empty_list( tmp[ 23])) {
t_protect( tmp[ 23]);
if( term_equal( list_head( tmp[ 23]) , make_char( 113))) {
tmp[ 24]= m_list_tail( tmp[ 23]);
if( m_not_empty_list( tmp[ 24])) {
t_protect( tmp[ 24]);
if( term_equal( list_head( tmp[ 24]) , make_char( 117))) {
tmp[ 25]= m_list_tail( tmp[ 24]);
if( m_not_empty_list( tmp[ 25])) {
t_protect( tmp[ 25]);
if( term_equal( list_head( tmp[ 25]) , make_char( 97))) {
tmp[ 26]= m_list_tail( tmp[ 25]);
if( m_is_single_element( tmp[ 26])) {
t_protect( tmp[ 26]);
if( term_equal( list_head( tmp[ 26]) , make_char( 108))) {
if( m_not_empty_list( tmp[ 17])) {
tmp[ 27]= m_list_head( tmp[ 17]);
tmp[ 28]= m_list_tail( tmp[ 17]);
if( m_is_single_element( tmp[ 28])) {
tmp[ 29]= m_list_head( tmp[ 28]);
if( m_term_equal( arg0 , tmp[ 27])) {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 30]= lf_AUX_Rules2C_Aux15_2( arg0 , lf_AUX_Rules2C_Aux15_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 30] , ef1sym)) {
tmp[ 31]= arg_0( tmp[ 30]);
tmp[ 32]= arg_1( tmp[ 30]);
if( check_sym( tmp[ 31] , lf_AUX_Rules2C_Aux15_1sym)) {
tmp[ 33]= arg_0( tmp[ 31]);
if( check_sym( tmp[ 32] , lf_AUX_Rules2C_Aux15_1sym)) {
tmp[ 34]= arg_0( tmp[ 32]);
t_protect( tmp[ 7]);
t_protect( tmp[ 12]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 33]);
t_protect( tmp[ 34]);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 18]);
t_unprotect( tmp[ 19]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 21]);
t_unprotect( tmp[ 22]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
t_unprotect( tmp[ 25]);
t_unprotect( tmp[ 26]);
t_unprotect( tmp[ 27]);
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 30]);
return ( * ef1)( lf_AUX_Rules2C_Aux15_1( cons( make_list( ( * ef2)( lf3( make_list( tmp[ 7])) , lf4( cons( make_list( ( * ef3)( ( * ef4)( ( * ef5)( lf5( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))) , lf6( cons( make_list( arg0) , make_list( tmp[ 29])))) , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 33]))) , lf_AUX_Rules2C_Aux15_1( make_list( tmp[ 34])));
}
}
}
t_unprotect( tmp[ 30]);
}
t_unprotect( tmp[ 29]);
}
t_unprotect( tmp[ 28]);
t_unprotect( tmp[ 27]);
}
}
}
t_unprotect( tmp[ 26]);
}
}
t_unprotect( tmp[ 25]);
}
}
t_unprotect( tmp[ 24]);
}
}
t_unprotect( tmp[ 23]);
}
}
t_unprotect( tmp[ 22]);
}
}
t_unprotect( tmp[ 21]);
}
}
t_unprotect( tmp[ 20]);
}
}
t_unprotect( tmp[ 19]);
}
}
t_unprotect( tmp[ 18]);
}
}
}
}
}
}
}
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 9]);
}
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg0);
t_unprotect( arg1);
return ( * ef1)( lf_AUX_Rules2C_Aux15_1( make_list( null( ))) , lf_AUX_Rules2C_Aux15_1( make_list( null( ))));
}
}
}
if( check_sym( arg1 , lf_AUX_Rules2C_Aux15_1sym)) {
{
aterm * atmp10= arg_0( arg1);
if( m_not_empty_list( atmp10)) {
tmp[ 0]= m_list_head( atmp10);
tmp[ 1]= m_list_tail( atmp10);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf4sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 9]= lf_AUX_Rules2C_Aux15_2( arg0 , lf_AUX_Rules2C_Aux15_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 9] , ef1sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 10] , lf_AUX_Rules2C_Aux15_1sym)) {
tmp[ 12]= arg_0( tmp[ 10]);
if( check_sym( tmp[ 11] , lf_AUX_Rules2C_Aux15_1sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
t_protect( tmp[ 12]);
t_protect( tmp[ 7]);
t_protect( tmp[ 8]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 13]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
return ( * ef1)( lf_AUX_Rules2C_Aux15_1( make_list( tmp[ 12])) , lf_AUX_Rules2C_Aux15_1( cons( make_list( ( * ef2)( lf3( make_list( tmp[ 7])) , lf4( make_list( tmp[ 8])) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 13]))));
}
}
}
t_unprotect( tmp[ 9]);
}
}
}
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 0]);
}
}
}
return make_nf2( lf_AUX_Rules2C_Aux15_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Rules2C_Aux15_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux15_1);
return make_nf1( lf_AUX_Rules2C_Aux15_1sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}

