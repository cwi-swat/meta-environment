#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux9_2sym;
static aterm * lf_AUX_Rules2C_Aux9_2( aterm * arg1 , aterm * arg2);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * lf_AUX_Rules2C_Aux9_1sym;
static aterm * lf_AUX_Rules2C_Aux9_1( aterm * arg1);
void register_AUX_Rules2C_Aux9( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux9_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-lhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf_AUX_Rules2C_Aux9_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux9_1 , lf_AUX_Rules2C_Aux9_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"select-same-lhs-cond\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux9_2 , lf_AUX_Rules2C_Aux9_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf4 , lf4sym);
}
void resolve_AUX_Rules2C_Aux9( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleListPair\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[sort(\"Term\"),w(\"\"),ql(\"=:\"),w(\"\"),sort(\"Term\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Cond\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux9_2( aterm * arg0 , aterm * arg1) {
{
aterm * tmp[29];
PROF( prof_lf_AUX_Rules2C_Aux9_2);
if( check_sym( arg0 , ef2sym)) {
{
aterm * atmp00= arg_0( arg0);
if( check_sym( atmp00 , lf3sym)) {
{
aterm * atmp000= arg_0( atmp00);
{
aterm * atmp01= arg_1( arg0);
if( check_sym( atmp01 , lf4sym)) {
{
aterm * atmp010= arg_0( atmp01);
{
aterm * atmp02= arg_2( arg0);
{
aterm * atmp03= arg_3( arg0);
{
aterm * atmp04= arg_4( arg0);
if( check_sym( arg1 , lf_AUX_Rules2C_Aux9_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp010);
if( not_empty_list( atmp010)) {
t_protect( atmp010);
tmp[ 0]= list_head( atmp010);
if( check_sym( tmp[ 0] , ef3sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
t_protect( atmp010);
tmp[ 3]= list_tail( atmp010);
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp10);
tmp[ 4]= list_head( atmp10);
if( check_sym( tmp[ 4] , ef2sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
tmp[ 7]= arg_2( tmp[ 4]);
tmp[ 8]= arg_3( tmp[ 4]);
tmp[ 9]= arg_4( tmp[ 4]);
if( check_sym( tmp[ 5] , lf3sym)) {
tmp[ 10]= arg_0( tmp[ 5]);
if( check_sym( tmp[ 6] , lf4sym)) {
tmp[ 11]= arg_0( tmp[ 6]);
t_protect( tmp[ 11]);
if( not_empty_list( tmp[ 11])) {
t_protect( tmp[ 11]);
tmp[ 12]= list_head( tmp[ 11]);
if( check_sym( tmp[ 12] , ef3sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
tmp[ 14]= arg_1( tmp[ 12]);
t_protect( tmp[ 11]);
tmp[ 15]= list_tail( tmp[ 11]);
t_protect( atmp10);
tmp[ 16]= list_tail( atmp10);
t_protect( tmp[ 1]);
t_protect( tmp[ 13]);
if( ! term_equal( tmp[ 1] , tmp[ 13])) {
t_protect( atmp000);
t_protect( tmp[ 1]);
t_protect( tmp[ 2]);
t_protect( tmp[ 3]);
t_protect( atmp02);
t_protect( atmp03);
t_protect( atmp04);
t_protect( tmp[ 16]);
tmp[ 17]= lf_AUX_Rules2C_Aux9_2( ( * ef2)( lf3( make_list( atmp000)) , lf4( cons( make_list( ( * ef3)( tmp[ 1] , tmp[ 2])) , make_list( tmp[ 3]))) , atmp02 , atmp03 , atmp04) , lf_AUX_Rules2C_Aux9_1( make_list( tmp[ 16])));
if( check_sym( tmp[ 17] , ef1sym)) {
tmp[ 18]= arg_0( tmp[ 17]);
tmp[ 19]= arg_1( tmp[ 17]);
if( check_sym( tmp[ 18] , lf_AUX_Rules2C_Aux9_1sym)) {
tmp[ 20]= arg_0( tmp[ 18]);
if( check_sym( tmp[ 19] , lf_AUX_Rules2C_Aux9_1sym)) {
tmp[ 21]= arg_0( tmp[ 19]);
t_protect( tmp[ 20]);
t_protect( tmp[ 10]);
t_protect( tmp[ 13]);
t_protect( tmp[ 14]);
t_protect( tmp[ 7]);
t_protect( tmp[ 8]);
t_protect( tmp[ 9]);
t_protect( tmp[ 21]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 3]);
t_unprotect( tmp[ 4]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
return ( * ef1)( lf_AUX_Rules2C_Aux9_1( make_list( tmp[ 20])) , lf_AUX_Rules2C_Aux9_1( cons( make_list( ( * ef2)( lf3( make_list( tmp[ 10])) , lf4( cons( make_list( ( * ef3)( tmp[ 13] , tmp[ 14])) , make_list( tmp[ 15]))) , tmp[ 7] , tmp[ 8] , tmp[ 9])) , make_list( tmp[ 21]))));
}
}
}
t_unprotect( tmp[ 17]);
}
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 15]);
}
t_unprotect( tmp[ 12]);
}
}
}
}
t_unprotect( tmp[ 4]);
}
t_unprotect( tmp[ 3]);
}
t_unprotect( tmp[ 0]);
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
if( check_sym( arg1 , lf_AUX_Rules2C_Aux9_1sym)) {
{
aterm * atmp10= arg_0( arg1);
t_protect( atmp10);
if( not_empty_list( atmp10)) {
t_protect( atmp10);
tmp[ 0]= list_head( atmp10);
{
t_protect( atmp10);
tmp[ 1]= list_tail( atmp10);
t_protect( arg0);
t_protect( tmp[ 0]);
if( ! term_equal( arg0 , tmp[ 0])) {
if( check_sym( arg0 , ef2sym)) {
tmp[ 2]= arg_0( arg0);
tmp[ 3]= arg_1( arg0);
tmp[ 4]= arg_2( arg0);
tmp[ 5]= arg_3( arg0);
tmp[ 6]= arg_4( arg0);
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf4sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
t_protect( tmp[ 8]);
if( not_empty_list( tmp[ 8])) {
t_protect( tmp[ 8]);
tmp[ 9]= list_head( tmp[ 8]);
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
tmp[ 11]= arg_1( tmp[ 9]);
t_protect( tmp[ 8]);
tmp[ 12]= list_tail( tmp[ 8]);
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 13]= arg_0( tmp[ 0]);
tmp[ 14]= arg_1( tmp[ 0]);
tmp[ 15]= arg_2( tmp[ 0]);
tmp[ 16]= arg_3( tmp[ 0]);
tmp[ 17]= arg_4( tmp[ 0]);
if( check_sym( tmp[ 13] , lf3sym)) {
tmp[ 18]= arg_0( tmp[ 13]);
if( check_sym( tmp[ 14] , lf4sym)) {
tmp[ 19]= arg_0( tmp[ 14]);
t_protect( tmp[ 19]);
if( not_empty_list( tmp[ 19])) {
t_protect( tmp[ 19]);
tmp[ 20]= list_head( tmp[ 19]);
if( check_sym( tmp[ 20] , ef3sym)) {
tmp[ 21]= arg_0( tmp[ 20]);
tmp[ 22]= arg_1( tmp[ 20]);
t_protect( tmp[ 19]);
tmp[ 23]= list_tail( tmp[ 19]);
t_protect( tmp[ 10]);
t_protect( tmp[ 21]);
if( term_equal( tmp[ 10] , tmp[ 21])) {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 24]= lf_AUX_Rules2C_Aux9_2( arg0 , lf_AUX_Rules2C_Aux9_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 24] , ef1sym)) {
tmp[ 25]= arg_0( tmp[ 24]);
tmp[ 26]= arg_1( tmp[ 24]);
if( check_sym( tmp[ 25] , lf_AUX_Rules2C_Aux9_1sym)) {
tmp[ 27]= arg_0( tmp[ 25]);
if( check_sym( tmp[ 26] , lf_AUX_Rules2C_Aux9_1sym)) {
tmp[ 28]= arg_0( tmp[ 26]);
t_protect( tmp[ 27]);
t_protect( tmp[ 28]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 9]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 20]);
t_unprotect( tmp[ 23]);
t_unprotect( tmp[ 24]);
return ( * ef1)( lf_AUX_Rules2C_Aux9_1( cons( make_list( tmp[ 0]) , make_list( tmp[ 27]))) , lf_AUX_Rules2C_Aux9_1( make_list( tmp[ 28])));
}
}
}
t_unprotect( tmp[ 24]);
}
t_unprotect( tmp[ 23]);
}
t_unprotect( tmp[ 20]);
}
}
}
}
t_unprotect( tmp[ 12]);
}
t_unprotect( tmp[ 9]);
}
}
}
}
}
else {
t_protect( arg0);
t_protect( tmp[ 1]);
tmp[ 2]= lf_AUX_Rules2C_Aux9_2( arg0 , lf_AUX_Rules2C_Aux9_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
tmp[ 4]= arg_1( tmp[ 2]);
if( check_sym( tmp[ 3] , lf_AUX_Rules2C_Aux9_1sym)) {
tmp[ 5]= arg_0( tmp[ 3]);
if( check_sym( tmp[ 4] , lf_AUX_Rules2C_Aux9_1sym)) {
tmp[ 6]= arg_0( tmp[ 4]);
t_protect( tmp[ 5]);
t_protect( tmp[ 6]);
t_unprotect( arg0);
t_unprotect( arg1);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 1]);
t_unprotect( tmp[ 2]);
return ( * ef1)( lf_AUX_Rules2C_Aux9_1( make_list( tmp[ 5])) , lf_AUX_Rules2C_Aux9_1( make_list( tmp[ 6])));
}
}
}
t_unprotect( tmp[ 2]);
}
t_unprotect( tmp[ 1]);
}
t_unprotect( tmp[ 0]);
}
else {
t_unprotect( arg1);
return ( * ef1)( lf_AUX_Rules2C_Aux9_1( make_list( arg0)) , lf_AUX_Rules2C_Aux9_1( make_list( null( ))));
}
}
}
return make_nf2( lf_AUX_Rules2C_Aux9_2sym , arg0 , arg1);
}
}
aterm * lf_AUX_Rules2C_Aux9_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux9_1);
return make_nf1( lf_AUX_Rules2C_Aux9_1sym , arg0);
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}

