#include "support.h"
static asymbol * lf_AUX_MuASF_Conds2C2_3sym;
static aterm * lf_AUX_MuASF_Conds2C2_3( aterm * arg1 , aterm * arg2 , aterm * arg3 , aterm * arg4);
static asymbol * ef6sym;
static funcptr ef6;
static asymbol * ef7sym;
static funcptr ef7;
static asymbol * ef8sym;
static funcptr ef8;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf7sym;
static aterm * lf7( aterm * arg1);
static asymbol * ef10sym;
static funcptr ef10;
static asymbol * lf6sym;
static aterm * lf6( aterm * arg1);
static asymbol * ef4sym;
static funcptr ef4;
static asymbol * ef11sym;
static funcptr ef11;
static asymbol * ef12sym;
static funcptr ef12;
static asymbol * ef9sym;
static funcptr ef9;
static asymbol * ef5sym;
static funcptr ef5;
static asymbol * ef13sym;
static funcptr ef13;
static asymbol * lf_AUX_MuASF_Conds2C2_1sym;
static aterm * lf_AUX_MuASF_Conds2C2_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf_AUX_MuASF_Conds2C2_2sym;
static aterm * lf_AUX_MuASF_Conds2C2_2( aterm * arg1);
void register_AUX_MuASF_Conds2C2( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_MuASF_Conds2C2_3sym= TmkSymbol( "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf7sym= TmkSymbol( "listtype(sort(\"Term\"),ql(\",\"))" , SYM_STRING);
lf6sym= TmkSymbol( "listtype(sort(\"CHAR\"))" , SYM_STRING);
lf_AUX_MuASF_Conds2C2_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_MuASF_Conds2C2_2sym= TmkSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_MuASF_Conds2C2_1 , lf_AUX_MuASF_Conds2C2_1sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Conds2C2_2 , lf_AUX_MuASF_Conds2C2_2sym);
register_prod( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Conds2C2_3 , lf_AUX_MuASF_Conds2C2_3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"CHAR\"))") , lf6 , lf6sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Term\"),ql(\",\"))") , lf7 , lf7sym);
}
void resolve_AUX_MuASF_Conds2C2( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"FunId\"),w(\"\"),ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Term\"),w(\"\"),no-attrs)"));
ef4= lookup_func( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( TmakeSimple( & local , "prod(id(\"caller\"),w(\"\"),[l(\"funid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef5= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef6= lookup_func( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef6sym= lookup_sym( TmakeSimple( & local , "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Statement-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Statement-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef7= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"find-common-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef7sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Term2C\"),w(\"\"),[l(\"find-common-terms\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef8= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SRI-tuple\"),w(\"\"),no-attrs)"));
ef9= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"test-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef9sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"test-cond2cstats\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef10= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef10sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"get-funid\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FunId\"),w(\"\"),no-attrs)"));
ef11= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-boolean-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef11sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Basics\"),w(\"\"),[l(\"is-boolean-term\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12= lookup_func( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef12sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Booleans\"),w(\"\"),[l(\"true\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Bool\"),w(\"\"),no-attrs)"));
ef13= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
ef13sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-Conds2C\"),w(\"\"),[l(\"first-cond2cstats2\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"A-set\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SlI-tuple\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_MuASF_Conds2C2_3( aterm * arg0 , aterm * arg1 , aterm * arg2 , aterm * arg3) {
{
aterm * tmp[70];
PROF( prof_lf_AUX_MuASF_Conds2C2_3);
if( check_sym( arg0 , lf_AUX_MuASF_Conds2C2_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , lf_AUX_MuASF_Conds2C2_2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
{
tmp[ 1]= m_list_tail( atmp00);
{
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
{
if( check_sym( tmp[ 3] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
{
if( m_not_empty_list( tmp[ 8])) {
tmp[ 9]= m_list_head( tmp[ 8]);
{
tmp[ 10]= m_list_tail( tmp[ 8]);
{
if( check_sym( tmp[ 9] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
{
if( check_sym( tmp[ 11] , ef3sym)) {
tmp[ 13]= arg_0( tmp[ 11]);
tmp[ 14]= arg_1( tmp[ 11]);
if( check_sym( tmp[ 13] , ef4sym)) {
tmp[ 15]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 15] , lf6sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
if( check_sym( tmp[ 14] , lf7sym)) {
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
t_protect( tmp[ 7]);
t_protect( tmp[ 27]);
t_protect( tmp[ 29]);
t_protect( tmp[ 12]);
t_protect( tmp[ 10]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 1]);
t_protect( arg1);
t_protect( atmp20);
t_protect( arg3);
tmp[ 30]= ( * ef7)( lf_AUX_MuASF_Conds2C2_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))) , lf7( cons( make_list( tmp[ 27]) , make_list( tmp[ 29])))) , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , arg1 , lf_AUX_MuASF_Conds2C2_2( make_list( atmp20)) , arg3);
if( check_sym( tmp[ 30] , ef8sym)) {
tmp[ 31]= arg_0( tmp[ 30]);
tmp[ 32]= arg_1( tmp[ 30]);
tmp[ 33]= arg_2( tmp[ 30]);
tmp[ 34]= arg_3( tmp[ 30]);
tmp[ 35]= arg_4( tmp[ 30]);
if( check_sym( tmp[ 33] , lf_AUX_MuASF_Conds2C2_1sym)) {
tmp[ 36]= arg_0( tmp[ 33]);
if( m_not_empty_list( tmp[ 36])) {
tmp[ 37]= m_list_head( tmp[ 36]);
tmp[ 38]= m_list_tail( tmp[ 36]);
if( check_sym( tmp[ 37] , ef1sym)) {
tmp[ 39]= arg_0( tmp[ 37]);
tmp[ 40]= arg_1( tmp[ 37]);
tmp[ 41]= arg_2( tmp[ 37]);
tmp[ 42]= arg_3( tmp[ 37]);
tmp[ 43]= arg_4( tmp[ 37]);
if( check_sym( tmp[ 39] , lf4sym)) {
tmp[ 44]= arg_0( tmp[ 39]);
if( check_sym( tmp[ 40] , lf5sym)) {
tmp[ 45]= arg_0( tmp[ 40]);
if( m_not_empty_list( tmp[ 45])) {
tmp[ 46]= m_list_head( tmp[ 45]);
tmp[ 47]= m_list_tail( tmp[ 45]);
if( check_sym( tmp[ 46] , ef2sym)) {
tmp[ 48]= arg_0( tmp[ 46]);
tmp[ 49]= arg_1( tmp[ 46]);
if( check_sym( tmp[ 48] , ef3sym)) {
tmp[ 50]= arg_0( tmp[ 48]);
tmp[ 51]= arg_1( tmp[ 48]);
if( check_sym( tmp[ 50] , ef4sym)) {
tmp[ 52]= arg_0( tmp[ 50]);
if( check_sym( tmp[ 52] , lf6sym)) {
tmp[ 53]= arg_0( tmp[ 52]);
if( check_sym( tmp[ 51] , lf7sym)) {
tmp[ 54]= arg_0( tmp[ 51]);
if( m_not_empty_list( tmp[ 53])) {
t_protect( tmp[ 53]);
if( term_equal( list_head( tmp[ 53]) , make_char( 116))) {
tmp[ 55]= m_list_tail( tmp[ 53]);
if( m_not_empty_list( tmp[ 55])) {
t_protect( tmp[ 55]);
if( term_equal( list_head( tmp[ 55]) , make_char( 101))) {
tmp[ 56]= m_list_tail( tmp[ 55]);
if( m_not_empty_list( tmp[ 56])) {
t_protect( tmp[ 56]);
if( term_equal( list_head( tmp[ 56]) , make_char( 114))) {
tmp[ 57]= m_list_tail( tmp[ 56]);
if( m_not_empty_list( tmp[ 57])) {
t_protect( tmp[ 57]);
if( term_equal( list_head( tmp[ 57]) , make_char( 109))) {
tmp[ 58]= m_list_tail( tmp[ 57]);
if( m_not_empty_list( tmp[ 58])) {
t_protect( tmp[ 58]);
if( term_equal( list_head( tmp[ 58]) , make_char( 45))) {
tmp[ 59]= m_list_tail( tmp[ 58]);
if( m_not_empty_list( tmp[ 59])) {
t_protect( tmp[ 59]);
if( term_equal( list_head( tmp[ 59]) , make_char( 101))) {
tmp[ 60]= m_list_tail( tmp[ 59]);
if( m_not_empty_list( tmp[ 60])) {
t_protect( tmp[ 60]);
if( term_equal( list_head( tmp[ 60]) , make_char( 113))) {
tmp[ 61]= m_list_tail( tmp[ 60]);
if( m_not_empty_list( tmp[ 61])) {
t_protect( tmp[ 61]);
if( term_equal( list_head( tmp[ 61]) , make_char( 117))) {
tmp[ 62]= m_list_tail( tmp[ 61]);
if( m_not_empty_list( tmp[ 62])) {
t_protect( tmp[ 62]);
if( term_equal( list_head( tmp[ 62]) , make_char( 97))) {
tmp[ 63]= m_list_tail( tmp[ 62]);
if( m_is_single_element( tmp[ 63])) {
t_protect( tmp[ 63]);
if( term_equal( list_head( tmp[ 63]) , make_char( 108))) {
if( m_not_empty_list( tmp[ 54])) {
tmp[ 64]= m_list_head( tmp[ 54]);
tmp[ 65]= m_list_tail( tmp[ 54]);
if( m_is_single_element( tmp[ 65])) {
tmp[ 66]= m_list_head( tmp[ 65]);
t_protect( tmp[ 44]);
t_protect( tmp[ 64]);
t_protect( tmp[ 66]);
t_protect( tmp[ 49]);
t_protect( tmp[ 47]);
t_protect( tmp[ 41]);
t_protect( tmp[ 42]);
t_protect( tmp[ 43]);
t_protect( tmp[ 38]);
t_protect( tmp[ 35]);
t_protect( atmp20);
t_protect( tmp[ 34]);
tmp[ 67]= ( * ef9)( lf_AUX_MuASF_Conds2C2_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 44])) , lf5( cons( make_list( ( * ef2)( ( * ef3)( ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))) , lf7( cons( make_list( tmp[ 64]) , make_list( tmp[ 66])))) , tmp[ 49])) , make_list( tmp[ 47]))) , tmp[ 41] , tmp[ 42] , tmp[ 43])) , make_list( tmp[ 38]))) , tmp[ 35] , lf_AUX_MuASF_Conds2C2_2( make_list( atmp20)) , tmp[ 34]);
if( check_sym( tmp[ 67] , ef5sym)) {
tmp[ 68]= arg_0( tmp[ 67]);
tmp[ 69]= arg_1( tmp[ 67]);
t_protect( tmp[ 31]);
t_protect( tmp[ 68]);
t_protect( tmp[ 32]);
t_protect( tmp[ 69]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
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
t_unprotect( tmp[ 29]);
t_unprotect( tmp[ 30]);
t_unprotect( tmp[ 37]);
t_unprotect( tmp[ 38]);
t_unprotect( tmp[ 46]);
t_unprotect( tmp[ 47]);
t_unprotect( tmp[ 55]);
t_unprotect( tmp[ 56]);
t_unprotect( tmp[ 57]);
t_unprotect( tmp[ 58]);
t_unprotect( tmp[ 59]);
t_unprotect( tmp[ 60]);
t_unprotect( tmp[ 61]);
t_unprotect( tmp[ 62]);
t_unprotect( tmp[ 63]);
t_unprotect( tmp[ 64]);
t_unprotect( tmp[ 65]);
t_unprotect( tmp[ 66]);
t_unprotect( tmp[ 67]);
return ( * ef5)( ( * ef6)( ( * ef6)( tmp[ 31] , tmp[ 68]) , tmp[ 32]) , tmp[ 69]);
}
t_unprotect( tmp[ 67]);
t_unprotect( tmp[ 66]);
}
t_unprotect( tmp[ 65]);
t_unprotect( tmp[ 64]);
}
}
}
t_unprotect( tmp[ 63]);
}
}
t_unprotect( tmp[ 62]);
}
}
t_unprotect( tmp[ 61]);
}
}
t_unprotect( tmp[ 60]);
}
}
t_unprotect( tmp[ 59]);
}
}
t_unprotect( tmp[ 58]);
}
}
t_unprotect( tmp[ 57]);
}
}
t_unprotect( tmp[ 56]);
}
}
t_unprotect( tmp[ 55]);
}
}
}
}
}
}
}
t_unprotect( tmp[ 47]);
t_unprotect( tmp[ 46]);
}
}
}
}
t_unprotect( tmp[ 38]);
t_unprotect( tmp[ 37]);
}
}
}
t_unprotect( tmp[ 30]);
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
t_protect( tmp[ 11]);
tmp[ 13]= ( * ef10)( tmp[ 11]);
t_protect( tmp[ 13]);
if( ! term_equal( tmp[ 13] , ( * ef4)( lf6( cons( make_list( make_char( 116)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 114)) , cons( make_list( make_char( 109)) , cons( make_list( make_char( 45)) , cons( make_list( make_char( 101)) , cons( make_list( make_char( 113)) , cons( make_list( make_char( 117)) , cons( make_list( make_char( 97)) , make_list( make_char( 108))))))))))))))) {
t_protect( tmp[ 12]);
if( term_equal( ( * ef11)( tmp[ 12]) , ( * ef12)( ))) {
t_protect( tmp[ 7]);
t_protect( tmp[ 11]);
t_protect( tmp[ 12]);
t_protect( tmp[ 10]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( tmp[ 1]);
t_protect( arg1);
t_protect( atmp20);
t_protect( arg3);
tmp[ 14]= ( * ef9)( lf_AUX_MuASF_Conds2C2_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( tmp[ 11] , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , arg1 , lf_AUX_MuASF_Conds2C2_2( make_list( atmp20)) , arg3);
if( check_sym( tmp[ 14] , ef5sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
tmp[ 16]= arg_1( tmp[ 14]);
t_protect( tmp[ 15]);
t_protect( tmp[ 16]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( arg2);
t_unprotect( arg3);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 10]);
t_unprotect( tmp[ 13]);
t_unprotect( tmp[ 14]);
return ( * ef5)( tmp[ 15] , tmp[ 16]);
}
t_unprotect( tmp[ 14]);
}
}
t_unprotect( tmp[ 13]);
}
}
}
t_unprotect( tmp[ 10]);
}
t_unprotect( tmp[ 9]);
}
}
}
}
}
}
}
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
}
}
}
}
if( check_sym( arg0 , lf_AUX_MuASF_Conds2C2_1sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( arg2 , lf_AUX_MuASF_Conds2C2_2sym)) {
{
aterm * atmp20= arg_0( arg2);
if( m_not_empty_list( atmp00)) {
tmp[ 0]= m_list_head( atmp00);
tmp[ 1]= m_list_tail( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 2] , lf4sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
if( m_not_empty_list( tmp[ 8])) {
tmp[ 9]= m_list_head( tmp[ 8]);
tmp[ 10]= m_list_tail( tmp[ 8]);
if( check_sym( tmp[ 9] , ef2sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
t_protect( tmp[ 7]);
t_protect( tmp[ 11]);
t_protect( tmp[ 12]);
t_protect( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_protect( atmp20);
t_unprotect( arg0);
t_unprotect( arg2);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 9]);
return ( * ef13)( lf_AUX_MuASF_Conds2C2_1( cons( make_list( ( * ef1)( lf4( make_list( tmp[ 7])) , lf5( cons( make_list( ( * ef2)( tmp[ 11] , tmp[ 12])) , make_list( tmp[ 10]))) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 1]))) , arg1 , lf_AUX_MuASF_Conds2C2_2( make_list( atmp20)) , arg3);
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
}
}
}
}
return make_nf4( lf_AUX_MuASF_Conds2C2_3sym , arg0 , arg1 , arg2 , arg3);
}
}
aterm * lf_AUX_MuASF_Conds2C2_2( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C2_2);
return make_nf1( lf_AUX_MuASF_Conds2C2_2sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf_AUX_MuASF_Conds2C2_1( aterm * arg0) {
PROF( prof_lf_AUX_MuASF_Conds2C2_1);
return make_nf1( lf_AUX_MuASF_Conds2C2_1sym , arg0);
}
aterm * lf6( aterm * arg0) {
PROF( prof_lf6);
return make_nf1( lf6sym , arg0);
}
aterm * lf7( aterm * arg0) {
PROF( prof_lf7);
return make_nf1( lf7sym , arg0);
}

