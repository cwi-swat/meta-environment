#include  "asc-support.h"
static Symbol lf_AUX_ATerms1_1sym ;
static ATerm lf_AUX_ATerms1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerms1_2sym ;
static ATerm lf_AUX_ATerms1_2 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_ATerms1_3sym ;
static ATerm lf_AUX_ATerms1_3 ( ) ;
static Symbol lf_AUX_ATerms1_4sym ;
static ATerm lf_AUX_ATerms1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerms1_5sym ;
static ATerm lf_AUX_ATerms1_5 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerms1_6sym ;
static ATerm lf_AUX_ATerms1_6 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerms1_7sym ;
static ATerm lf_AUX_ATerms1_7 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerms1_8sym ;
static ATerm lf_AUX_ATerms1_8 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_ATerms1_9sym ;
static ATerm lf_AUX_ATerms1_9 ( ATerm arg1 ) ;
static Symbol lf_AUX_ATerms1_10sym ;
static ATerm lf_AUX_ATerms1_10 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_ATerms1_11sym ;
static ATerm lf_AUX_ATerms1_11 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_ATerms1_12sym ;
static ATerm lf_AUX_ATerms1_12 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_ATerms1_13sym ;
static ATerm lf_AUX_ATerms1_13 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
void register_AUX_ATerms1 ( ) {
lf_AUX_ATerms1_1sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_1sym ) ;
lf_AUX_ATerms1_2sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_2sym ) ;
lf_AUX_ATerms1_3sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_3sym ) ;
lf_AUX_ATerms1_4sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_4sym ) ;
lf_AUX_ATerms1_5sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ACon\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_5sym ) ;
lf_AUX_ATerms1_6sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_6sym ) ;
lf_AUX_ATerms1_7sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_7sym ) ;
lf_AUX_ATerms1_8sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_8sym ) ;
lf_AUX_ATerms1_9sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_9sym ) ;
lf_AUX_ATerms1_10sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_10sym ) ;
lf_AUX_ATerms1_11sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_11sym ) ;
lf_AUX_ATerms1_12sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_12sym ) ;
lf_AUX_ATerms1_13sym = ATmakeSymbol ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_ATerms1_13sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_1 , lf_AUX_ATerms1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATerm\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"ATerms\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerms\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_2 , lf_AUX_ATerms1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_3 , lf_AUX_ATerms1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"[\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATermList\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_4 , lf_AUX_ATerms1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"IntCon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ACon\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_5 , lf_AUX_ATerms1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"Literal\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_6 , lf_AUX_ATerms1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_7 , lf_AUX_ATerms1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_8 , lf_AUX_ATerms1_8sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Ann\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_9 , lf_AUX_ATerms1_9sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ACon\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_10 , lf_AUX_ATerms1_10sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"ATermList\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_11 , lf_AUX_ATerms1_11sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_12 , lf_AUX_ATerms1_12sym ) ;
register_prod ( ATparse ( "prod(id(\"ATerms\"),w(\"\"),[sort(\"AFun\"),w(\"\"),ql(\"(\"),w(\"\"),sort(\"ATerms\"),w(\"\"),ql(\")\"),w(\"\"),sort(\"Ann\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ATerm\"),w(\"\"),no-attrs)" ) , lf_AUX_ATerms1_13 , lf_AUX_ATerms1_13sym ) ;
}
void resolve_AUX_ATerms1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_ATerms1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_ATerms1_13 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_ATerms1_13sym , ATmakeAppl ( lf_AUX_ATerms1_13sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_ATerms1_13sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_ATerms1_12 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_ATerms1_12sym , ATmakeAppl ( lf_AUX_ATerms1_12sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_ATerms1_12sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_ATerms1_11 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_ATerms1_11sym , ATmakeAppl ( lf_AUX_ATerms1_11sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_ATerms1_11sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_ATerms1_10 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_ATerms1_10sym , ATmakeAppl ( lf_AUX_ATerms1_10sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_ATerms1_10sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_ATerms1_9 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerms1_9sym , ATmakeAppl ( lf_AUX_ATerms1_9sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerms1_9sym , arg0 ) ) ;
}
ATerm lf_AUX_ATerms1_8 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_ATerms1_8sym , ATmakeAppl ( lf_AUX_ATerms1_8sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_ATerms1_8sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_ATerms1_7 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerms1_7sym , ATmakeAppl ( lf_AUX_ATerms1_7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerms1_7sym , arg0 ) ) ;
}
ATerm lf_AUX_ATerms1_6 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerms1_6sym , ATmakeAppl ( lf_AUX_ATerms1_6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerms1_6sym , arg0 ) ) ;
}
ATerm lf_AUX_ATerms1_5 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerms1_5sym , ATmakeAppl ( lf_AUX_ATerms1_5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerms1_5sym , arg0 ) ) ;
}
ATerm lf_AUX_ATerms1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerms1_4sym , ATmakeAppl ( lf_AUX_ATerms1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerms1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_ATerms1_3 ( ) {
CONS_ENTRY ( lf_AUX_ATerms1_3sym , ATmakeAppl0 ( lf_AUX_ATerms1_3sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_ATerms1_3sym ) ) ;
}
ATerm lf_AUX_ATerms1_2 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_ATerms1_2sym , ATmakeAppl ( lf_AUX_ATerms1_2sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_ATerms1_2sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_ATerms1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_ATerms1_1sym , ATmakeAppl ( lf_AUX_ATerms1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_ATerms1_1sym , arg0 ) ) ;
}

