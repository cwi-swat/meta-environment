#include "support.h"
static Symbol lf_AUX_Rules2C_Aux19_2sym;
static ATerm lf_AUX_Rules2C_Aux19_2( ATerm arg1);
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef3sym;
static funcptr ef3;
static Symbol lf4sym;
static ATerm lf4( ATerm arg1);
static Symbol ef2sym;
static funcptr ef2;
static Symbol lf3sym;
static ATerm lf3( ATerm arg1);
static Symbol lf5sym;
static ATerm lf5( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf_AUX_Rules2C_Aux19_1sym;
static ATerm lf_AUX_Rules2C_Aux19_1( ATerm arg1);
void register_AUX_Rules2C_Aux19( ) {
lf_AUX_Rules2C_Aux19_2sym= ATmakeSymbol( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-ofs-first-arg\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux19_2sym);
lf4sym= ATmakeSymbol( "listtype(sort(\"AInt\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf4sym);
lf3sym= ATmakeSymbol( "listtype(sort(\"FV-Path\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf3sym);
lf5sym= ATmakeSymbol( "listtype(sort(\"Cond\"),ql(\"&\"))" , 1 , ATtrue);
ATprotectSymbol( lf5sym);
lf_AUX_Rules2C_Aux19_1sym= ATmakeSymbol( "listtype(sort(\"C-Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Rules2C_Aux19_1sym);
register_prod( ATparse( "listtype(sort(\"C-Rule\"),ql(\";\"))") , lf_AUX_Rules2C_Aux19_1 , lf_AUX_Rules2C_Aux19_1sym);
register_prod( ATparse( "prod(id(\"Rules2C-Aux\"),w(\"\"),[l(\"remove-ofs-first-arg\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)") , lf_AUX_Rules2C_Aux19_2 , lf_AUX_Rules2C_Aux19_2sym);
register_prod( ATparse( "listtype(sort(\"FV-Path\"),ql(\",\"))") , lf3 , lf3sym);
register_prod( ATparse( "listtype(sort(\"AInt\"),ql(\",\"))") , lf4 , lf4sym);
register_prod( ATparse( "listtype(sort(\"Cond\"),ql(\"&\"))") , lf5 , lf5sym);
}
void resolve_AUX_Rules2C_Aux19( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-RuleList\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Cond\"),w(\"\"),ql(\"&\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"|\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"|\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-Rule\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"Rules2C-Aux\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FV-Path\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_Rules2C_Aux19( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_Rules2C_Aux19_2( ATerm arg0) {
{
ATerm tmp[21];
PROF( prof_lf_AUX_Rules2C_Aux19_2);
if( check_sym( arg0 , lf_AUX_Rules2C_Aux19_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( not_empty_list( atmp00)) {
tmp[ 0]= list_head( atmp00);
{
tmp[ 1]= list_tail( atmp00);
{
if( check_sym( tmp[ 0] , ef2sym)) {
tmp[ 2]= arg_0( tmp[ 0]);
tmp[ 3]= arg_1( tmp[ 0]);
tmp[ 4]= arg_2( tmp[ 0]);
tmp[ 5]= arg_3( tmp[ 0]);
tmp[ 6]= arg_4( tmp[ 0]);
{
if( check_sym( tmp[ 2] , lf3sym)) {
tmp[ 7]= arg_0( tmp[ 2]);
{
if( check_sym( tmp[ 3] , lf5sym)) {
tmp[ 8]= arg_0( tmp[ 3]);
{
if( not_empty_list( tmp[ 7])) {
tmp[ 9]= list_head( tmp[ 7]);
{
tmp[ 10]= list_tail( tmp[ 7]);
{
if( check_sym( tmp[ 9] , ef4sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
if( check_sym( tmp[ 11] , lf3sym)) {
tmp[ 12]= arg_0( tmp[ 11]);
if( not_empty_list( tmp[ 12])) {
tmp[ 13]= list_head( tmp[ 12]);
tmp[ 14]= list_tail( tmp[ 12]);
if( not_empty_list( tmp[ 14])) {
if( check_sym( tmp[ 13] , ef3sym)) {
tmp[ 15]= arg_0( tmp[ 13]);
tmp[ 16]= arg_1( tmp[ 13]);
if( check_sym( tmp[ 16] , lf4sym)) {
tmp[ 17]= arg_0( tmp[ 16]);
tmp[ 18]= lf_AUX_Rules2C_Aux19_2( lf_AUX_Rules2C_Aux19_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 18] , ef1sym)) {
tmp[ 19]= arg_0( tmp[ 18]);
if( check_sym( tmp[ 19] , lf_AUX_Rules2C_Aux19_1sym)) {
tmp[ 20]= arg_0( tmp[ 19]);
return ( * ef1)( lf_AUX_Rules2C_Aux19_1( cons( make_list( ( * ef2)( lf3( cons( make_list( tmp[ 14]) , make_list( tmp[ 10]))) , lf5( make_list( tmp[ 8])) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 20]))));
}
}
}
}
}
}
}
}
if( not_empty_list( tmp[ 10])) {
if( check_sym( tmp[ 9] , ef3sym)) {
tmp[ 11]= arg_0( tmp[ 9]);
tmp[ 12]= arg_1( tmp[ 9]);
if( check_sym( tmp[ 12] , lf4sym)) {
tmp[ 13]= arg_0( tmp[ 12]);
tmp[ 14]= lf_AUX_Rules2C_Aux19_2( lf_AUX_Rules2C_Aux19_1( make_list( tmp[ 1])));
if( check_sym( tmp[ 14] , ef1sym)) {
tmp[ 15]= arg_0( tmp[ 14]);
if( check_sym( tmp[ 15] , lf_AUX_Rules2C_Aux19_1sym)) {
tmp[ 16]= arg_0( tmp[ 15]);
return ( * ef1)( lf_AUX_Rules2C_Aux19_1( cons( make_list( ( * ef2)( lf3( make_list( tmp[ 10])) , lf5( make_list( tmp[ 8])) , tmp[ 4] , tmp[ 5] , tmp[ 6])) , make_list( tmp[ 16]))));
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
else {
return ( constant0? constant0: ( constant0= ( * ef1)( lf_AUX_Rules2C_Aux19_1( make_list( null( ))))));
}
}
}
return make_nf1( lf_AUX_Rules2C_Aux19_2sym , arg0);
}
}
ATerm lf_AUX_Rules2C_Aux19_1( ATerm arg0) {
PROF( prof_lf_AUX_Rules2C_Aux19_1);
return make_nf1( lf_AUX_Rules2C_Aux19_1sym , arg0);
}
ATerm lf5( ATerm arg0) {
PROF( prof_lf5);
return make_nf1( lf5sym , arg0);
}
ATerm lf3( ATerm arg0) {
PROF( prof_lf3);
return make_nf1( lf3sym , arg0);
}
ATerm lf4( ATerm arg0) {
PROF( prof_lf4);
return make_nf1( lf4sym , arg0);
}

