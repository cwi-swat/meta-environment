#include "support.h"
static Symbol lf_AUX_MuASF_Signs7_1sym;
static ATerm lf_AUX_MuASF_Signs7_1( ATerm arg1 , ATerm arg2);
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf2sym;
static ATerm lf2( ATerm arg1);
void register_AUX_MuASF_Signs7( ) {
lf_AUX_MuASF_Signs7_1sym= ATmakeSymbol( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"remove-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_MuASF_Signs7_1sym);
lf2sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf2sym);
register_prod( ATparse( "prod(id(\"MuASF-Signs\"),w(\"\"),[l(\"remove-ssfuncdef\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),l(\",\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)") , lf_AUX_MuASF_Signs7_1 , lf_AUX_MuASF_Signs7_1sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf2 , lf2sym);
}
void resolve_AUX_MuASF_Signs7( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"MuASF-SingleSorted\"),w(\"\"),[iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"FuncDefList\"),w(\"\"),no-attrs)"));
}
static ATerm constant0= NULL;
void init_AUX_MuASF_Signs7( ) {
ATprotect( & constant0);
}
ATerm lf_AUX_MuASF_Signs7_1( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[5];
PROF( prof_lf_AUX_MuASF_Signs7_1);
if( check_sym( arg1 , ef1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( check_sym( atmp10 , lf2sym)) {
{
ATerm atmp100= arg_0( atmp10);
if( not_empty_list( atmp100)) {
tmp[ 0]= list_head( atmp100);
{
tmp[ 1]= list_tail( atmp100);
if( ! term_equal( arg0 , tmp[ 0])) {
tmp[ 2]= lf_AUX_MuASF_Signs7_1( arg0 , ( * ef1)( lf2( make_list( tmp[ 1]))));
if( check_sym( tmp[ 2] , ef1sym)) {
tmp[ 3]= arg_0( tmp[ 2]);
if( check_sym( tmp[ 3] , lf2sym)) {
tmp[ 4]= arg_0( tmp[ 3]);
return ( * ef1)( lf2( cons( make_list( tmp[ 0]) , make_list( tmp[ 4]))));
}
}
}
else {
return ( * ef1)( lf2( make_list( tmp[ 1])));
}
}
}
else {
return ( constant0? constant0: ( constant0= ( * ef1)( lf2( make_list( null( ))))));
}
}
}
}
}
return make_nf2( lf_AUX_MuASF_Signs7_1sym , arg0 , arg1);
}
}
ATerm lf2( ATerm arg0) {
PROF( prof_lf2);
return make_nf1( lf2sym , arg0);
}

