#include "support.h"
static Symbol lf_AUX_C_Basics20_2sym;
static ATerm lf_AUX_C_Basics20_2( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_C_Basics20_3sym;
static ATerm lf_AUX_C_Basics20_3( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_C_Basics20_1sym;
static ATerm lf_AUX_C_Basics20_1( ATerm arg1);
static Symbol lf_AUX_C_Basics20_4sym;
static ATerm lf_AUX_C_Basics20_4( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_C_Basics20_6sym;
static ATerm lf_AUX_C_Basics20_6( ATerm arg1);
static Symbol lf_AUX_C_Basics20_5sym;
static ATerm lf_AUX_C_Basics20_5( ATerm arg1);
static Symbol lf_AUX_C_Basics20_7sym;
static ATerm lf_AUX_C_Basics20_7( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_C_Basics20_8sym;
static ATerm lf_AUX_C_Basics20_8( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_C_Basics20_9sym;
static ATerm lf_AUX_C_Basics20_9( ATerm arg1 , ATerm arg2 , ATerm arg3);
static Symbol lf_AUX_C_Basics20_10sym;
static ATerm lf_AUX_C_Basics20_10( ATerm arg1);
static Symbol lf_AUX_C_Basics20_11sym;
static ATerm lf_AUX_C_Basics20_11( ATerm arg1 , ATerm arg2);
static Symbol lf_AUX_C_Basics20_13sym;
static ATerm lf_AUX_C_Basics20_13( ATerm arg1);
static Symbol lf_AUX_C_Basics20_12sym;
static ATerm lf_AUX_C_Basics20_12( ATerm arg1);
static Symbol lf_AUX_C_Basics20_14sym;
static ATerm lf_AUX_C_Basics20_14( ATerm arg1 , ATerm arg2 , ATerm arg3);
void register_AUX_C_Basics20( ) {
lf_AUX_C_Basics20_2sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)"
 , 3 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_2sym);
lf_AUX_C_Basics20_3sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_3sym);
lf_AUX_C_Basics20_1sym= ATmakeSymbol( "listtype(sort(\"FuncDef\"),ql(\";\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_1sym);
lf_AUX_C_Basics20_4sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_4sym);
lf_AUX_C_Basics20_6sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_6sym);
lf_AUX_C_Basics20_5sym= ATmakeSymbol( "listtype(sort(\"TE-pair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_5sym);
lf_AUX_C_Basics20_7sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_7sym);
lf_AUX_C_Basics20_8sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_8sym);
lf_AUX_C_Basics20_9sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_9sym);
lf_AUX_C_Basics20_10sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_10sym);
lf_AUX_C_Basics20_11sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EI-pair\"),w(\"\"),no-attrs)" , 2 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_11sym);
lf_AUX_C_Basics20_13sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"EI-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"A-set\"),w(\"\"),no-attrs)" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_13sym);
lf_AUX_C_Basics20_12sym= ATmakeSymbol( "listtype(sort(\"EI-pair\"),ql(\",\"))" , 1 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_12sym);
lf_AUX_C_Basics20_14sym= ATmakeSymbol( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue);
ATprotectSymbol( lf_AUX_C_Basics20_14sym);
register_prod( ATparse( "listtype(sort(\"FuncDef\"),ql(\";\"))") , lf_AUX_C_Basics20_1 , lf_AUX_C_Basics20_1sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FTS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_2 , lf_AUX_C_Basics20_2sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"FuncDef\"),w(\"\"),ql(\";\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"FT-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_3 , lf_AUX_C_Basics20_3sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Term\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_4 , lf_AUX_C_Basics20_4sym);
register_prod( ATparse( "listtype(sort(\"TE-pair\"),ql(\",\"))") , lf_AUX_C_Basics20_5 , lf_AUX_C_Basics20_5sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"TE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"C-env\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_6 , lf_AUX_C_Basics20_6sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"C-env\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"DCAS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_7 , lf_AUX_C_Basics20_7sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADS-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_8 , lf_AUX_C_Basics20_8sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Declaration-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ADSI-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_9 , lf_AUX_C_Basics20_9sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"E-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_10 , lf_AUX_C_Basics20_10sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"EI-pair\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_11 , lf_AUX_C_Basics20_11sym);
register_prod( ATparse( "listtype(sort(\"EI-pair\"),ql(\",\"))") , lf_AUX_C_Basics20_12 , lf_AUX_C_Basics20_12sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"EI-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"A-set\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_13 , lf_AUX_C_Basics20_13sym);
register_prod( ATparse( "prod(id(\"C-Basics\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Parameter-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"AInt\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"PA-tuple\"),w(\"\"),no-attrs)") , lf_AUX_C_Basics20_14 , lf_AUX_C_Basics20_14sym);
}
void resolve_AUX_C_Basics20( ) {
}
void init_AUX_C_Basics20( ) {
}
ATerm lf_AUX_C_Basics20_14( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_C_Basics20_14);
return make_nf3( lf_AUX_C_Basics20_14sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_C_Basics20_12( ATerm arg0) {
PROF( prof_lf_AUX_C_Basics20_12);
return make_nf1( lf_AUX_C_Basics20_12sym , arg0);
}
ATerm lf_AUX_C_Basics20_13( ATerm arg0) {
PROF( prof_lf_AUX_C_Basics20_13);
return make_nf1( lf_AUX_C_Basics20_13sym , arg0);
}
ATerm lf_AUX_C_Basics20_11( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_C_Basics20_11);
return make_nf2( lf_AUX_C_Basics20_11sym , arg0 , arg1);
}
ATerm lf_AUX_C_Basics20_10( ATerm arg0) {
PROF( prof_lf_AUX_C_Basics20_10);
return make_nf1( lf_AUX_C_Basics20_10sym , arg0);
}
ATerm lf_AUX_C_Basics20_9( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_C_Basics20_9);
return make_nf3( lf_AUX_C_Basics20_9sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_C_Basics20_8( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_C_Basics20_8);
return make_nf3( lf_AUX_C_Basics20_8sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_C_Basics20_7( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_C_Basics20_7);
return make_nf3( lf_AUX_C_Basics20_7sym , arg0 , arg1 , arg2);
}
ATerm lf_AUX_C_Basics20_5( ATerm arg0) {
PROF( prof_lf_AUX_C_Basics20_5);
return make_nf1( lf_AUX_C_Basics20_5sym , arg0);
}
ATerm lf_AUX_C_Basics20_6( ATerm arg0) {
PROF( prof_lf_AUX_C_Basics20_6);
return make_nf1( lf_AUX_C_Basics20_6sym , arg0);
}
ATerm lf_AUX_C_Basics20_4( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_C_Basics20_4);
return make_nf2( lf_AUX_C_Basics20_4sym , arg0 , arg1);
}
ATerm lf_AUX_C_Basics20_1( ATerm arg0) {
PROF( prof_lf_AUX_C_Basics20_1);
return make_nf1( lf_AUX_C_Basics20_1sym , arg0);
}
ATerm lf_AUX_C_Basics20_3( ATerm arg0 , ATerm arg1) {
PROF( prof_lf_AUX_C_Basics20_3);
return make_nf2( lf_AUX_C_Basics20_3sym , arg0 , arg1);
}
ATerm lf_AUX_C_Basics20_2( ATerm arg0 , ATerm arg1 , ATerm arg2) {
PROF( prof_lf_AUX_C_Basics20_2);
return make_nf3( lf_AUX_C_Basics20_2sym , arg0 , arg1 , arg2);
}

