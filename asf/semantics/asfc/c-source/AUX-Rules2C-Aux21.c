#include "support.h"
static asymbol * lf_AUX_Rules2C_Aux21_2sym;
static aterm * lf_AUX_Rules2C_Aux21_2( aterm * arg1);
static asymbol * lf_AUX_Rules2C_Aux21_1sym;
static aterm * lf_AUX_Rules2C_Aux21_1( aterm * arg1);
static asymbol * ef1sym;
static funcptr ef1;
static asymbol * ef3sym;
static funcptr ef3;
static asymbol * lf3sym;
static aterm * lf3( aterm * arg1);
static asymbol * lf5sym;
static aterm * lf5( aterm * arg1);
static asymbol * ef2sym;
static funcptr ef2;
static asymbol * lf4sym;
static aterm * lf4( aterm * arg1);
void register_AUX_Rules2C_Aux21( ) {
arena local;
TinitArena( NULL , & local);
lf_AUX_Rules2C_Aux21_2sym= TmkSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"get-first-vf-path\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"
 , SYM_STRING);
lf_AUX_Rules2C_Aux21_1sym= TmkSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , SYM_STRING);
lf3sym= TmkSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , SYM_STRING);
lf5sym= TmkSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , SYM_STRING);
lf4sym= TmkSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , SYM_STRING);
register_prod( TmakeSimple( & local , "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux21_1 , lf_AUX_Rules2C_Aux21_1sym);
register_prod( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"get-first-vf-path\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux21_2 , lf_AUX_Rules2C_Aux21_2sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"AInt\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( TmakeSimple( & local , "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
}
void resolve_AUX_Rules2C_Aux21( ) {
arena local;
TinitArena( NULL , & local);
ef1= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef3= lookup_func( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( TmakeSimple( & local , "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
}
aterm * lf_AUX_Rules2C_Aux21_2( aterm * arg0) {
{
aterm * tmp[18];
PROF( prof_lf_AUX_Rules2C_Aux21_2);
if( check_sym( arg0 , lf_AUX_Rules2C_Aux21_1sym)) {
{
aterm * atmp00= arg_0( arg0);
t_protect( atmp00);
if( not_empty_list( atmp00)) {
t_protect( atmp00);
tmp[ 0]= list_head( atmp00);
if( check_sym( tmp[ 0] , ef1sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
tmp[ 2]= arg_1( tmp[ 0]);
tmp[ 3]= arg_2( tmp[ 0]);
tmp[ 4]= arg_3( tmp[ 0]);
tmp[ 5]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 1] , lf3sym)) {
tmp[ 6]= arg_0( tmp[ 1]);
{
if( check_sym( tmp[ 2] , lf5sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
t_protect( tmp[ 6]);
if( not_empty_list( tmp[ 6])) {
t_protect( tmp[ 6]);
tmp[ 8]= list_head( tmp[ 6]);
if( check_sym( tmp[ 8] , ef3sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
if( check_sym( tmp[ 9] , lf3sym)) {
tmp[ 10]= arg_0( tmp[ 9]);
t_protect( tmp[ 10]);
if( not_empty_list( tmp[ 10])) {
t_protect( tmp[ 10]);
tmp[ 11]= list_head( tmp[ 10]);
if( check_sym( tmp[ 11] , ef2sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
tmp[ 13]= arg_1( tmp[ 11]);
if( check_sym( tmp[ 13] , lf4sym)) {
tmp[ 14]= arg_0( tmp[ 13]);
t_protect( tmp[ 10]);
tmp[ 15]= list_tail( tmp[ 10]);
t_protect( tmp[ 15]);
if( not_empty_list( tmp[ 15])) {
t_protect( tmp[ 6]);
tmp[ 16]= list_tail( tmp[ 6]);
t_protect( atmp00);
tmp[ 17]= list_tail( atmp00);
t_protect( tmp[ 12]);
t_protect( tmp[ 14]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 11]);
t_unprotect( tmp[ 15]);
t_unprotect( tmp[ 16]);
t_unprotect( tmp[ 17]);
return ( * ef2)( tmp[ 12] , lf4( make_list( tmp[ 14])));
}
t_unprotect( tmp[ 15]);
}
}
t_unprotect( tmp[ 11]);
}
}
}
if( check_sym( tmp[ 8] , ef2sym)) {
tmp[ 9]= arg_0( tmp[ 8]);
tmp[ 10]= arg_1( tmp[ 8]);
if( check_sym( tmp[ 10] , lf4sym)) {
tmp[ 11]= arg_0( tmp[ 10]);
t_protect( tmp[ 6]);
tmp[ 12]= list_tail( tmp[ 6]);
t_protect( atmp00);
tmp[ 13]= list_tail( atmp00);
t_protect( tmp[ 9]);
t_protect( tmp[ 11]);
t_unprotect( arg0);
t_unprotect( tmp[ 0]);
t_unprotect( tmp[ 8]);
t_unprotect( tmp[ 12]);
t_unprotect( tmp[ 13]);
return ( * ef2)( tmp[ 9] , lf4( make_list( tmp[ 11])));
}
}
t_unprotect( tmp[ 8]);
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
return make_nf1( lf_AUX_Rules2C_Aux21_2sym , arg0);
}
}
aterm * lf4( aterm * arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}
aterm * lf5( aterm * arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
aterm * lf3( aterm * arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
aterm * lf_AUX_Rules2C_Aux21_1( aterm * arg0) {
PROF( prof_lf_AUX_Rules2C_Aux21_1);
return make_nf1( lf_AUX_Rules2C_Aux21_1sym , arg0);
}

