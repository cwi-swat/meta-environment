#include "support.h"
static Symbol lf_AUX_ParseTrees12_2sym;
static ATerm lf_AUX_ParseTrees12_2( ATerm arg1 , ATerm arg2);
static Symbol ef2sym;
static funcptr ef2;
static Symbol ef3sym;
static funcptr ef3;
static Symbol ef4sym;
static funcptr ef4;
static Symbol ef5sym;
static funcptr ef5;
static Symbol ef1sym;
static funcptr ef1;
static Symbol lf_AUX_ParseTrees12_1sym;
static ATerm lf_AUX_ParseTrees12_1( ATerm arg1);
void register_AUX_ParseTrees12( ) {
lf_AUX_ParseTrees12_2sym= ATmakeSymbol( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees12_2sym);
lf_AUX_ParseTrees12_1sym= ATmakeSymbol( "listtype(sort(\"AFun\"),ql(\".\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ParseTrees12_1sym);
register_prod( ATparse( "listtype(sort(\"AFun\"),ql(\".\"))") , lf_AUX_ParseTrees12_1 , lf_AUX_ParseTrees12_1sym);
register_prod( ATparse( "prod(id(\"ParseTrees\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\"[\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"AFun\"),w(\"\"),ql(\".\"),w(\"\"),l(\"}\"),w(\"\"),l(\"+\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ParseTrees12_2 , lf_AUX_ParseTrees12_2sym);
}
void resolve_AUX_ParseTrees12( ) {
ef1= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef1sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"named-elem\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef2sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"named-elem\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\",\"),w(\"\"),sort(\"ATermList\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef3= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef3sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)"));
ef4= lookup_func( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"init\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef4sym= lookup_sym( ATreadFromString( "prod(id(\"ParseTrees\"),w(\"\"),[l(\"init\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"AFun\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5= lookup_func( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
ef5sym= lookup_sym( ATreadFromString( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)"));
}
void init_AUX_ParseTrees12( ) {
}
ATerm lf_AUX_ParseTrees12_2( ATerm arg0 , ATerm arg1) {
{
ATerm tmp[4];
PROF( prof_lf_AUX_ParseTrees12_2);
if( check_sym( arg0 , ef1sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
if( check_sym( arg1 , lf_AUX_ParseTrees12_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( is_single_element( atmp10)) {
tmp[ 0]= list_head( atmp10);
tmp[ 1]= ( * ef4)( atmp00);
if( check_sym( tmp[ 1] , ef1sym)) {
tmp[ 2]= arg_0( tmp[ 1]);
tmp[ 3]= arg_1( tmp[ 1]);
return ( * ef2)( tmp[ 0] , ( * ef3)( tmp[ 3]) , ( * ef3)( atmp01));
}
}
}
}
}
}
}
if( check_sym( arg0 , ef5sym)) {
{
ATerm atmp00= arg_0( arg0);
{
ATerm atmp01= arg_1( arg0);
{
ATerm atmp02= arg_2( arg0);
if( check_sym( arg1 , lf_AUX_ParseTrees12_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( is_single_element( atmp10)) {
tmp[ 0]= list_head( atmp10);
return lf_AUX_ParseTrees12_2( ( * ef1)( atmp00 , atmp01) , lf_AUX_ParseTrees12_1( make_list( tmp[ 0])));
}
}
}
}
}
}
}
if( check_sym( arg1 , lf_AUX_ParseTrees12_1sym)) {
{
ATerm atmp10= arg_0( arg1);
if( not_empty_list( atmp10)) {
tmp[ 0]= list_head( atmp10);
tmp[ 1]= list_tail( atmp10);
if( not_empty_list( tmp[ 1])) {
return lf_AUX_ParseTrees12_2( lf_AUX_ParseTrees12_2( arg0 , lf_AUX_ParseTrees12_1( make_list( tmp[ 0]))) , lf_AUX_ParseTrees12_1( make_list( tmp[ 1])));
}
}
}
}
return make_nf2( lf_AUX_ParseTrees12_2sym , arg0 , arg1);
}
}
ATerm lf_AUX_ParseTrees12_1( ATerm arg0) {
PROF( prof_lf_AUX_ParseTrees12_1);
return make_nf1( lf_AUX_ParseTrees12_1sym , arg0);
}

