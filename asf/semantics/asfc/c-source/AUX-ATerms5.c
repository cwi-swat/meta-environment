#include "support.h"
static Symbol lf_AUX_ATerms5_2sym;
static ATerm lf_AUX_ATerms5_2( ATerm arg1);
static Symbol lf_AUX_ATerms5_3sym;
static ATerm lf_AUX_ATerms5_3( ATerm arg1);
static Symbol lf_AUX_ATerms5_4sym;
static ATerm lf_AUX_ATerms5_4( ATerm arg1);
static Symbol lf_AUX_ATerms5_5sym;
static ATerm lf_AUX_ATerms5_5( ATerm arg1);
static Symbol lf_AUX_ATerms5_6sym;
static ATerm lf_AUX_ATerms5_6( ATerm arg1);
static Symbol lf_AUX_ATerms5_7sym;
static ATerm lf_AUX_ATerms5_7( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_ATerms5_8sym;
static ATerm lf_AUX_ATerms5_8( ATerm arg1);
static Symbol lf_AUX_ATerms5_9sym;
static ATerm lf_AUX_ATerms5_9( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_ATerms5_10sym;
static ATerm lf_AUX_ATerms5_10( ATerm arg1);
static Symbol lf_AUX_ATerms5_11sym;
static ATerm lf_AUX_ATerms5_11( ATerm arg1);
static Symbol lf_AUX_ATerms5_12sym;
static ATerm lf_AUX_ATerms5_12( );
static Symbol lf_AUX_ATerms5_13sym;
static ATerm lf_AUX_ATerms5_13( ATerm arg1);
static Symbol lf_AUX_ATerms5_14sym;
static ATerm lf_AUX_ATerms5_14( ATerm arg1);
static Symbol lf_AUX_ATerms5_15sym;
static ATerm lf_AUX_ATerms5_15( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_ATerms5_16sym;
static ATerm lf_AUX_ATerms5_16( ATerm arg1);
static Symbol lf_AUX_ATerms5_17sym;
static ATerm lf_AUX_ATerms5_17( ATerm arg1);
static Symbol lf_AUX_ATerms5_18sym;
static ATerm lf_AUX_ATerms5_18( ATerm arg1);
static Symbol lf_AUX_ATerms5_1sym;
static ATerm lf_AUX_ATerms5_1( ATerm arg1);
void register_AUX_ATerms5( ) {
lf_AUX_ATerms5_2sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)"
 , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_2sym);
lf_AUX_ATerms5_3sym= ATmakeSymbol( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_3sym);
lf_AUX_ATerms5_4sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_4sym);
lf_AUX_ATerms5_5sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_5sym);
lf_AUX_ATerms5_6sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_6sym);
lf_AUX_ATerms5_7sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_7sym);
lf_AUX_ATerms5_8sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_8sym);
lf_AUX_ATerms5_9sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_9sym);
lf_AUX_ATerms5_10sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_10sym);
lf_AUX_ATerms5_11sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_11sym);
lf_AUX_ATerms5_12sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , 0 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_12sym);
lf_AUX_ATerms5_13sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_13sym);
lf_AUX_ATerms5_14sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_14sym);
lf_AUX_ATerms5_15sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_15sym);
lf_AUX_ATerms5_16sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_16sym);
lf_AUX_ATerms5_17sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_17sym);
lf_AUX_ATerms5_18sym= ATmakeSymbol( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_18sym);
lf_AUX_ATerms5_1sym= ATmakeSymbol( "listtype(sort(\"CHAR\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_ATerms5_1sym);
register_prod( ATparse( "listtype(sort(\"CHAR\"))") , lf_AUX_ATerms5_1 , lf_AUX_ATerms5_1sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"aint\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AInt\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_2 , lf_AUX_ATerms5_2sym);
register_prod( ATparse( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_3 , lf_AUX_ATerms5_3sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_4 , lf_AUX_ATerms5_4sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AInt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_5 , lf_AUX_ATerms5_5sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_6 , lf_AUX_ATerms5_6sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_7 , lf_AUX_ATerms5_7sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_8 , lf_AUX_ATerms5_8sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_9 , lf_AUX_ATerms5_9sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_10 , lf_AUX_ATerms5_10sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_11 , lf_AUX_ATerms5_11sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_12 , lf_AUX_ATerms5_12sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_13 , lf_AUX_ATerms5_13sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_14 , lf_AUX_ATerms5_14sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_15 , lf_AUX_ATerms5_15sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_ATerms5_16 , lf_AUX_ATerms5_16sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)") , lf_AUX_ATerms5_17 , lf_AUX_ATerms5_17sym);
register_prod( ATparse( "prod(id(\"ATerms\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))") , lf_AUX_ATerms5_18 , lf_AUX_ATerms5_18sym);
}
void resolve_AUX_ATerms5( ) {
}
void init_AUX_ATerms5( ) {
}
ATerm lf_AUX_ATerms5_2( ATerm arg0) {
{
ATerm tmp[1];
PROF( prof_lf_AUX_ATerms5_2);
if( check_sym( arg0 , lf_AUX_ATerms5_1sym)) {
{
ATerm atmp00= arg_0( arg0);
if( not_empty_list( atmp00)) {
if( term_equal( list_head( atmp00) , make_char( 48))) {
tmp[ 0]= list_tail( atmp00);
if( not_empty_list( tmp[ 0])) {
return lf_AUX_ATerms5_2( lf_AUX_ATerms5_1( make_list( tmp[ 0])));
}
}
}
}
}
return make_nf1( lf_AUX_ATerms5_2sym , arg0);
}
}
ATerm lf_AUX_ATerms5_1( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_1);
return make_nf1( lf_AUX_ATerms5_1sym , arg0);
}
ATerm lf_AUX_ATerms5_18( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_18);
return make_nf1( lf_AUX_ATerms5_18sym , arg0);
}
ATerm lf_AUX_ATerms5_17( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_17);
return make_nf1( lf_AUX_ATerms5_17sym , arg0);
}
ATerm lf_AUX_ATerms5_16( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_16);
return make_nf1( lf_AUX_ATerms5_16sym , arg0);
}
ATerm lf_AUX_ATerms5_15( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_ATerms5_15);
return make_nf2( lf_AUX_ATerms5_15sym , arg0 , arg1);
}
ATerm lf_AUX_ATerms5_14( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_14);
return make_nf1( lf_AUX_ATerms5_14sym , arg0);
}
ATerm lf_AUX_ATerms5_13( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_13);
return make_nf1( lf_AUX_ATerms5_13sym , arg0);
}
ATerm lf_AUX_ATerms5_12( ) {
PROF( prof_lf_AUX_ATerms5_12);
return make_nf0( lf_AUX_ATerms5_12sym);
}
ATerm lf_AUX_ATerms5_11( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_11);
return make_nf1( lf_AUX_ATerms5_11sym , arg0);
}
ATerm lf_AUX_ATerms5_10( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_10);
return make_nf1( lf_AUX_ATerms5_10sym , arg0);
}
ATerm lf_AUX_ATerms5_9( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_ATerms5_9);
return make_nf2( lf_AUX_ATerms5_9sym , arg0 , arg1);
}
ATerm lf_AUX_ATerms5_8( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_8);
return make_nf1( lf_AUX_ATerms5_8sym , arg0);
}
ATerm lf_AUX_ATerms5_7( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_ATerms5_7);
return make_nf2( lf_AUX_ATerms5_7sym , arg0 , arg1);
}
ATerm lf_AUX_ATerms5_6( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_6);
return make_nf1( lf_AUX_ATerms5_6sym , arg0);
}
ATerm lf_AUX_ATerms5_5( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_5);
return make_nf1( lf_AUX_ATerms5_5sym , arg0);
}
ATerm lf_AUX_ATerms5_4( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_4);
return make_nf1( lf_AUX_ATerms5_4sym , arg0);
}
ATerm lf_AUX_ATerms5_3( ATerm arg0) {
PROF( prof_lf_AUX_ATerms5_3);
return make_nf1( lf_AUX_ATerms5_3sym , arg0);
}

