#include "support.h"
static Symbol lf_AUX_Locate_Constants22_1sym;
static ATerm lf_AUX_Locate_Constants22_1( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Locate_Constants22_3sym;
static ATerm lf_AUX_Locate_Constants22_3( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_Locate_Constants22_4sym;
static ATerm lf_AUX_Locate_Constants22_4( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Locate_Constants22_5sym;
static ATerm lf_AUX_Locate_Constants22_5( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Locate_Constants22_6sym;
static ATerm lf_AUX_Locate_Constants22_6( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Locate_Constants22_7sym;
static ATerm lf_AUX_Locate_Constants22_7( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Locate_Constants22_8sym;
static ATerm lf_AUX_Locate_Constants22_8( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Locate_Constants22_9sym;
static ATerm lf_AUX_Locate_Constants22_9( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_Locate_Constants22_2sym;
static ATerm lf_AUX_Locate_Constants22_2( ATerm arg1);
void register_AUX_Locate_Constants22( ) {
lf_AUX_Locate_Constants22_1sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_1sym);
lf_AUX_Locate_Constants22_3sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_3sym);
lf_AUX_Locate_Constants22_4sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_4sym);
lf_AUX_Locate_Constants22_5sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_5sym);
lf_AUX_Locate_Constants22_6sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_6sym);
lf_AUX_Locate_Constants22_7sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEELI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_7sym);
lf_AUX_Locate_Constants22_8sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_8sym);
lf_AUX_Locate_Constants22_9sym= ATmakeSymbol( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_9sym);
lf_AUX_Locate_Constants22_2sym= ATmakeSymbol( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_Locate_Constants22_2sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants22_1 , lf_AUX_Locate_Constants22_1sym);
register_prod( ATparse( "listtype(sort(\"CE-pair\"),ql(\",\"))") , lf_AUX_Locate_Constants22_2 , lf_AUX_Locate_Constants22_2sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants22_3 , lf_AUX_Locate_Constants22_3sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants22_4 , lf_AUX_Locate_Constants22_4sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants22_5 , lf_AUX_Locate_Constants22_5sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants22_6 , lf_AUX_Locate_Constants22_6sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEELI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants22_7 , lf_AUX_Locate_Constants22_7sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants22_8 , lf_AUX_Locate_Constants22_8sym);
register_prod( ATparse( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_Locate_Constants22_9 , lf_AUX_Locate_Constants22_9sym);
}
void resolve_AUX_Locate_Constants22( ) {
}
void init_AUX_Locate_Constants22( ) {
}
ATerm lf_AUX_Locate_Constants22_2( ATerm arg0) {
PROF( prof_lf_AUX_Locate_Constants22_2);
return make_nf1( lf_AUX_Locate_Constants22_2sym , arg0);
}
ATerm lf_AUX_Locate_Constants22_9( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Locate_Constants22_9);
return make_nf3( lf_AUX_Locate_Constants22_9sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_Locate_Constants22_8( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Locate_Constants22_8);
return make_nf3( lf_AUX_Locate_Constants22_8sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_Locate_Constants22_7( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Locate_Constants22_7);
return make_nf3( lf_AUX_Locate_Constants22_7sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_Locate_Constants22_6( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Locate_Constants22_6);
return make_nf3( lf_AUX_Locate_Constants22_6sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_Locate_Constants22_5( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Locate_Constants22_5);
return make_nf3( lf_AUX_Locate_Constants22_5sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_Locate_Constants22_4( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_Locate_Constants22_4);
return make_nf3( lf_AUX_Locate_Constants22_4sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_Locate_Constants22_3( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Locate_Constants22_3);
return make_nf2( lf_AUX_Locate_Constants22_3sym , arg0 , arg1);
}
ATerm lf_AUX_Locate_Constants22_1( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_Locate_Constants22_1);
return make_nf2( lf_AUX_Locate_Constants22_1sym , arg0 , arg1);
}

