#include "support.h"
static Symbol lf_AUX_MuASF_Rules2C5_4sym;
static ATerm lf_AUX_MuASF_Rules2C5_4( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4);
static Symbol ef7sym;
static funcptr ef7;
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef6sym;
static funcptr ef6;
static Symbol ef8sym;
static funcptr ef8;
static Symbol lf_AUX_MuASF_Rules2C5_2sym;
static ATerm lf_AUX_MuASF_Rules2C5_2( ATerm arg1);
static Symbol lf_AUX_MuASF_Rules2C5_3sym;
static ATerm lf_AUX_MuASF_Rules2C5_3( ATerm arg1);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf_AUX_MuASF_Rules2C5_1sym;
static ATerm lf_AUX_MuASF_Rules2C5_1( ATerm arg1);
void register_AUX_MuASF_Rules2C5( ) {
lf_AUX_MuASF_Rules2C5_4sym= ATmakeSymbol( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"
 , 4 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Rules2C5_4sym);
lf_AUX_MuASF_Rules2C5_2sym= ATmakeSymbol( "listtype(sort(\"Rule\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Rules2C5_2sym);
lf_AUX_MuASF_Rules2C5_3sym= ATmakeSymbol( "listtype(sort(\"NamePair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Rules2C5_3sym);
lf_AUX_MuASF_Rules2C5_1sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Rules2C5_1sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C5_1 , lf_AUX_MuASF_Rules2C5_1sym);
register_prod( ATparse( "listtype(sort(\"Rule\"),ql(\";\"))") , lf_AUX_MuASF_Rules2C5_2 , lf_AUX_MuASF_Rules2C5_2sym);
register_prod( ATparse( "listtype(sort(\"NamePair\"),ql(\",\"))") , lf_AUX_MuASF_Rules2C5_3 , lf_AUX_MuASF_Rules2C5_3sym);
register_prod( ATparse( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Rules2C5_4 , lf_AUX_MuASF_Rules2C5_4sym);
}
void resolve_AUX_MuASF_Rules2C5( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration-list\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"Pure-C\"),w(\"\"),[sort(\"Declaration\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"RenameVars\"),w(\"\"),[l(\"rename-in-rules\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"RuleList\"),w(\"\"),no-attrs)"));
ef6= lookup_func( ATreadFromString( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfunc\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef6sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfunc\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration\"),w(\"\"),no-attrs)"));
ef7= lookup_func( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef7sym= lookup_sym( ATreadFromString( "prod(id(\"C-Basics\"),w(\"\"),[sort(\"Declaration-list-opt\"),w(\"\"),ql(\"++\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"left\")],w(\"\"),l(\"}\")))"));
ef8= lookup_func( ATreadFromString( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
ef8sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-Rules2C\"),w(\"\"),[l(\"asfrules2cfuncs\"),w(\"\"),l(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"Rule\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),l(\",\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"NamePair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)"));
}
void init_AUX_MuASF_Rules2C5( ) {
}
ATerm lf_AUX_MuASF_Rules2C5_4( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3) {
{
ATerm tmp[8];
PROF( prof_lf_AUX_MuASF_Rules2C5_4);
if( check_sym( arg0 , lf_AUX_MuASF_Rules2C5_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( check_sym( arg1 , lf_AUX_MuASF_Rules2C5_2sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( arg2 , lf_AUX_MuASF_Rules2C5_2sym)) {
{
ATerm atmp20= arg_0( arg2);
if( check_sym( arg3 , lf_AUX_MuASF_Rules2C5_3sym)) {
{
ATerm atmp30= arg_0( arg3);
if( not_empty_list( atmp10)) {
if( not_empty_list( atmp20)) {
tmp[ 0]= ( * ef4)( lf_AUX_MuASF_Rules2C5_2( make_list( atmp10)));
if( check_sym( tmp[ 0] , ef5sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf_AUX_MuASF_Rules2C5_2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= ( * ef6)( lf_AUX_MuASF_Rules2C5_2( make_list( tmp[ 2])) , lf_AUX_MuASF_Rules2C5_3( make_list( atmp30)));
tmp[ 4]= ( * ef8)( lf_AUX_MuASF_Rules2C5_1( make_list( atmp00)) , lf_AUX_MuASF_Rules2C5_2( make_list( atmp20)) , lf_AUX_MuASF_Rules2C5_3( make_list( atmp30)));
if( check_sym( tmp[ 4] , ef1sym)) {
tmp[ 5]= arg_0( tmp[ 4]);
tmp[ 6]= arg_1( tmp[ 4]);
if( check_sym( tmp[ 5] , lf_AUX_MuASF_Rules2C5_1sym)) {
tmp[ 7]= arg_0( tmp[ 5]);
return ( * ef1)( lf_AUX_MuASF_Rules2C5_1( make_list( tmp[ 7])) , ( * ef7)( tmp[ 6] , ( * ef2)( ( * ef3)( tmp[ 3]))));
}
}
}
}
}
}
else {
tmp[ 0]= ( * ef4)( lf_AUX_MuASF_Rules2C5_2( make_list( atmp10)));
if( check_sym( tmp[ 0] , ef5sym)) {
tmp[ 1]= arg_0( tmp[ 0]);
if( check_sym( tmp[ 1] , lf_AUX_MuASF_Rules2C5_2sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
if( not_empty_list( tmp[ 2])) {
tmp[ 3]= ( * ef6)( lf_AUX_MuASF_Rules2C5_2( make_list( tmp[ 2])) , lf_AUX_MuASF_Rules2C5_3( make_list( atmp30)));
return ( * ef1)( lf_AUX_MuASF_Rules2C5_1( make_list( atmp00)) , ( * ef2)( ( * ef3)( tmp[ 3])));
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
return make_nf4( lf_AUX_MuASF_Rules2C5_4sym , arg0 , arg1 , arg2 , arg3);
}
}
ATerm lf_AUX_MuASF_Rules2C5_1( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C5_1);
return make_nf1( lf_AUX_MuASF_Rules2C5_1sym , arg0);
}
ATerm lf_AUX_MuASF_Rules2C5_3( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C5_3);
return make_nf1( lf_AUX_MuASF_Rules2C5_3sym , arg0);
}
ATerm lf_AUX_MuASF_Rules2C5_2( ATerm arg0) {
PROF( prof_lf_AUX_MuASF_Rules2C5_2);
return make_nf1( lf_AUX_MuASF_Rules2C5_2sym , arg0);
}

