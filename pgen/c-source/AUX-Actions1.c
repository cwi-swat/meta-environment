#include  "asc-support.h"
static Symbol lf_AUX_Actions1_1sym ;
static ATerm lf_AUX_Actions1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Actions1_2sym ;
static ATerm lf_AUX_Actions1_2 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
static Symbol lf_AUX_Actions1_3sym ;
static ATerm lf_AUX_Actions1_3 ( ATerm arg1 , ATerm arg2 , ATerm arg3 , ATerm arg4 ) ;
static Symbol lf_AUX_Actions1_4sym ;
static ATerm lf_AUX_Actions1_4 ( ) ;
static Symbol lf_AUX_Actions1_5sym ;
static ATerm lf_AUX_Actions1_5 ( ) ;
static Symbol lf_AUX_Actions1_7sym ;
static ATerm lf_AUX_Actions1_7 ( ATerm arg1 ) ;
static Symbol lf_AUX_Actions1_6sym ;
static ATerm lf_AUX_Actions1_6 ( ATerm arg1 ) ;
static Symbol lf_AUX_Actions1_8sym ;
static ATerm lf_AUX_Actions1_8 ( ATerm arg1 ) ;
void register_AUX_Actions1 ( ) {
lf_AUX_Actions1_1sym = ATmakeSymbol ( "prod(id(\"Actions\"),w(\"\"),[l(\"shift\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions1_1sym ) ;
lf_AUX_Actions1_2sym = ATmakeSymbol ( "prod(id(\"Actions\"),w(\"\"),[l(\"reduce\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Label\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions1_2sym ) ;
lf_AUX_Actions1_3sym = ATmakeSymbol ( "prod(id(\"Actions\"),w(\"\"),[l(\"reduce\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" , 4 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions1_3sym ) ;
lf_AUX_Actions1_4sym = ATmakeSymbol ( "prod(id(\"Actions\"),w(\"\"),[l(\"accept\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions1_4sym ) ;
lf_AUX_Actions1_5sym = ATmakeSymbol ( "prod(id(\"Actions\"),w(\"\"),[l(\"error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions1_5sym ) ;
lf_AUX_Actions1_7sym = ATmakeSymbol ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions1_7sym ) ;
lf_AUX_Actions1_6sym = ATmakeSymbol ( "listtype(sort(\"Action\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions1_6sym ) ;
lf_AUX_Actions1_8sym = ATmakeSymbol ( "prod(id(\"Actions\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Actions1_8sym ) ;
register_prod ( ATparse ( "prod(id(\"Actions\"),w(\"\"),[l(\"shift\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) , lf_AUX_Actions1_1 , lf_AUX_Actions1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Actions\"),w(\"\"),[l(\"reduce\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Label\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) , lf_AUX_Actions1_2 , lf_AUX_Actions1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Actions\"),w(\"\"),[l(\"reduce\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Int\"),w(\"\"),l(\",\"),w(\"\"),sort(\"Lookaheads\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) , lf_AUX_Actions1_3 , lf_AUX_Actions1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Actions\"),w(\"\"),[l(\"accept\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) , lf_AUX_Actions1_4 , lf_AUX_Actions1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Actions\"),w(\"\"),[l(\"error\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Action\"),w(\"\"),no-attrs)" ) , lf_AUX_Actions1_5 , lf_AUX_Actions1_5sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Action\"))" ) , lf_AUX_Actions1_6 , lf_AUX_Actions1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"Actions\"),w(\"\"),[iter(sort(\"Action\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Actions\"),w(\"\"),no-attrs)" ) , lf_AUX_Actions1_7 , lf_AUX_Actions1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"Actions\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ActionSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Actions1_8 , lf_AUX_Actions1_8sym ) ;
}
void resolve_AUX_Actions1 ( ) {
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Actions1 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Actions1_8 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Actions1_8sym , ATmakeAppl ( lf_AUX_Actions1_8sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Actions1_8sym , arg0 ) ) ;
}
ATerm lf_AUX_Actions1_6 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Actions1_6sym , ATmakeAppl ( lf_AUX_Actions1_6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Actions1_6sym , arg0 ) ) ;
}
ATerm lf_AUX_Actions1_7 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Actions1_7sym , ATmakeAppl ( lf_AUX_Actions1_7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Actions1_7sym , arg0 ) ) ;
}
ATerm lf_AUX_Actions1_5 ( ) {
CONS_ENTRY ( lf_AUX_Actions1_5sym , ATmakeAppl0 ( lf_AUX_Actions1_5sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Actions1_5sym ) ) ;
}
ATerm lf_AUX_Actions1_4 ( ) {
CONS_ENTRY ( lf_AUX_Actions1_4sym , ATmakeAppl0 ( lf_AUX_Actions1_4sym ) ) ;
CONS_EXIT_CONST ( constant1 , make_nf0 ( lf_AUX_Actions1_4sym ) ) ;
}
ATerm lf_AUX_Actions1_3 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
CONS_ENTRY ( lf_AUX_Actions1_3sym , ATmakeAppl ( lf_AUX_Actions1_3sym , arg0 , arg1 , arg2 , arg3 ) ) ;
CONS_EXIT ( make_nf4 ( lf_AUX_Actions1_3sym , arg0 , arg1 , arg2 , arg3 ) ) ;
}
ATerm lf_AUX_Actions1_2 ( ATerm arg0 , ATerm arg1 , ATerm arg2 , ATerm arg3 ) {
CONS_ENTRY ( lf_AUX_Actions1_2sym , ATmakeAppl ( lf_AUX_Actions1_2sym , arg0 , arg1 , arg2 , arg3 ) ) ;
CONS_EXIT ( make_nf4 ( lf_AUX_Actions1_2sym , arg0 , arg1 , arg2 , arg3 ) ) ;
}
ATerm lf_AUX_Actions1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Actions1_1sym , ATmakeAppl ( lf_AUX_Actions1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Actions1_1sym , arg0 ) ) ;
}

