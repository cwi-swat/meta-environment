#include  "support.h"
static Symbol lf_AUX_AVars1_1sym ;
static ATerm lf_AUX_AVars1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_AVars1_2sym ;
static ATerm lf_AUX_AVars1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_AVars1_3sym ;
static ATerm lf_AUX_AVars1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_AVars1_4sym ;
static ATerm lf_AUX_AVars1_4 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_AVars1_5sym ;
static ATerm lf_AUX_AVars1_5 ( ATerm arg1 ) ;
static Symbol lf_AUX_AVars1_6sym ;
static ATerm lf_AUX_AVars1_6 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_AVars1_7sym ;
static ATerm lf_AUX_AVars1_7 ( ATerm arg1 ) ;
void register_AUX_AVars1 ( ) {
lf_AUX_AVars1_1sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AVars1_1sym ) ;
lf_AUX_AVars1_2sym = ATmakeSymbol ( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AVars1_2sym ) ;
lf_AUX_AVars1_3sym = ATmakeSymbol ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AVars1_3sym ) ;
lf_AUX_AVars1_4sym = ATmakeSymbol ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AVars1_4sym ) ;
lf_AUX_AVars1_5sym = ATmakeSymbol ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AVars1_5sym ) ;
lf_AUX_AVars1_6sym = ATmakeSymbol ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AVars1_6sym ) ;
lf_AUX_AVars1_7sym = ATmakeSymbol ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_AVars1_7sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf_AUX_AVars1_1 , lf_AUX_AVars1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"caller\"),w(\"\"),[l(\"aname\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AName\"),w(\"\"),no-attrs)" ) , lf_AUX_AVars1_2 , lf_AUX_AVars1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) , lf_AUX_AVars1_3 , lf_AUX_AVars1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) , lf_AUX_AVars1_4 , lf_AUX_AVars1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) , lf_AUX_AVars1_5 , lf_AUX_AVars1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AName\"),w(\"\"),ql(\":\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\"?\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AVar\"),w(\"\"),no-attrs)" ) , lf_AUX_AVars1_6 , lf_AUX_AVars1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"AVars\"),w(\"\"),[sort(\"AVar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_AVars1_7 , lf_AUX_AVars1_7sym ) ;
}
void resolve_AUX_AVars1 ( ) {
}
void init_AUX_AVars1 ( ) {
}
ATerm lf_AUX_AVars1_7 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_AVars1_7 ) ;
return make_nf1 ( lf_AUX_AVars1_7sym , arg0 ) ;
}
ATerm lf_AUX_AVars1_6 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_AVars1_6 ) ;
return make_nf2 ( lf_AUX_AVars1_6sym , arg0 , arg1 ) ;
}
ATerm lf_AUX_AVars1_5 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_AVars1_5 ) ;
return make_nf1 ( lf_AUX_AVars1_5sym , arg0 ) ;
}
ATerm lf_AUX_AVars1_4 ( ATerm arg0 , ATerm arg1 ) {
PROF ( prof_lf_AUX_AVars1_4 ) ;
return make_nf2 ( lf_AUX_AVars1_4sym , arg0 , arg1 ) ;
}
ATerm lf_AUX_AVars1_3 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_AVars1_3 ) ;
return make_nf1 ( lf_AUX_AVars1_3sym , arg0 ) ;
}
ATerm lf_AUX_AVars1_2 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_AVars1_2 ) ;
return make_nf1 ( lf_AUX_AVars1_2sym , arg0 ) ;
}
ATerm lf_AUX_AVars1_1 ( ATerm arg0 ) {
PROF ( prof_lf_AUX_AVars1_1 ) ;
return make_nf1 ( lf_AUX_AVars1_1sym , arg0 ) ;
}

