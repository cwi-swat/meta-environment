#include  "asc-support.h"
static Symbol lf_AUX_ATerm_Operations1_1sym ;
static ATerm lf_AUX_ATerm_Operations1_1 ( ) ;
static Symbol lf_AUX_ATerm_Operations1_2sym ;
static ATerm lf_AUX_ATerm_Operations1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerm_Operations1_3sym ;
static ATerm lf_AUX_ATerm_Operations1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerm_Operations1_4sym ;
static ATerm lf_AUX_ATerm_Operations1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerm_Operations1_5sym ;
static ATerm lf_AUX_ATerm_Operations1_5 ( ) ;
static Symbol lf_AUX_ATerm_Operations1_6sym ;
static ATerm lf_AUX_ATerm_Operations1_6 ( ) ;
static Symbol lf_AUX_ATerm_Operations1_7sym ;
static ATerm lf_AUX_ATerm_Operations1_7 ( ) ;
static Symbol lf_AUX_ATerm_Operations1_8sym ;
static ATerm lf_AUX_ATerm_Operations1_8 ( ) ;
static Symbol lf_AUX_ATerm_Operations1_9sym ;
static ATerm lf_AUX_ATerm_Operations1_9 ( ) ;
static Symbol lf_AUX_ATerm_Operations1_10sym ;
static ATerm lf_AUX_ATerm_Operations1_10 ( ) ;
void register_AUX_ATerm_Operations1 ( ) {
lf_AUX_ATerm_Operations1_1sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"fail\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_1sym ) ;
lf_AUX_ATerm_Operations1_2sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_2sym ) ;
lf_AUX_ATerm_Operations1_3sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_3sym ) ;
lf_AUX_ATerm_Operations1_4sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_4sym ) ;
lf_AUX_ATerm_Operations1_5sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"applyf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_5sym ) ;
lf_AUX_ATerm_Operations1_6sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"eq\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_6sym ) ;
lf_AUX_ATerm_Operations1_7sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"identity\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_7sym ) ;
lf_AUX_ATerm_Operations1_8sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"yes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_8sym ) ;
lf_AUX_ATerm_Operations1_9sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"comp\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_9sym ) ;
lf_AUX_ATerm_Operations1_10sym = ATmakeSymbol ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"termf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerm_Operations1_10sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"fail\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations1_1 , lf_AUX_ATerm_Operations1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerm\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_ATerm_Operations1_2 , lf_AUX_ATerm_Operations1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_ATerm_Operations1_3 , lf_AUX_ATerm_Operations1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ATermList\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_ATerm_Operations1_4 , lf_AUX_ATerm_Operations1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"applyf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations1_5 , lf_AUX_ATerm_Operations1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"eq\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations1_6 , lf_AUX_ATerm_Operations1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"identity\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations1_7 , lf_AUX_ATerm_Operations1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"yes\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations1_8 , lf_AUX_ATerm_Operations1_8sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"comp\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations1_9 , lf_AUX_ATerm_Operations1_9sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerm-Operations\"),w(\"\"),[l(\"termf\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerm_Operations1_10 , lf_AUX_ATerm_Operations1_10sym ) ;
}
void resolve_AUX_ATerm_Operations1 ( ) {
}
void init_AUX_ATerm_Operations1 ( ) {
}
ATerm lf_AUX_ATerm_Operations1_10 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_10sym , ATmakeAppl0 ( lf_AUX_ATerm_Operations1_10sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Operations1_10sym ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_9 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_9sym , ATmakeAppl0 ( lf_AUX_ATerm_Operations1_9sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Operations1_9sym ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_8 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_8sym , ATmakeAppl0 ( lf_AUX_ATerm_Operations1_8sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Operations1_8sym ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_7 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_7sym , ATmakeAppl0 ( lf_AUX_ATerm_Operations1_7sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Operations1_7sym ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_6 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_6sym , ATmakeAppl0 ( lf_AUX_ATerm_Operations1_6sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Operations1_6sym ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_5 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_5sym , ATmakeAppl0 ( lf_AUX_ATerm_Operations1_5sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Operations1_5sym ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_4sym , ATmakeAppl ( lf_AUX_ATerm_Operations1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerm_Operations1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_3sym , ATmakeAppl ( lf_AUX_ATerm_Operations1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerm_Operations1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_2sym , ATmakeAppl ( lf_AUX_ATerm_Operations1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerm_Operations1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_ATerm_Operations1_1 ( ) {
CONS_ENTRY ( lf_AUX_ATerm_Operations1_1sym , ATmakeAppl0 ( lf_AUX_ATerm_Operations1_1sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_ATerm_Operations1_1sym ) ) ;
}

