#include  "asc-support.h"
static Symbol lf_AUX_Locate_Constants1_1sym ;
static ATerm lf_AUX_Locate_Constants1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Locate_Constants1_3sym ;
static ATerm lf_AUX_Locate_Constants1_3 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Locate_Constants1_4sym ;
static ATerm lf_AUX_Locate_Constants1_4 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Locate_Constants1_5sym ;
static ATerm lf_AUX_Locate_Constants1_5 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Locate_Constants1_6sym ;
static ATerm lf_AUX_Locate_Constants1_6 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Locate_Constants1_7sym ;
static ATerm lf_AUX_Locate_Constants1_7 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Locate_Constants1_8sym ;
static ATerm lf_AUX_Locate_Constants1_8 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Locate_Constants1_9sym ;
static ATerm lf_AUX_Locate_Constants1_9 ( ATerm arg1 , ATerm arg2 , ATerm arg3 ) ;
static Symbol lf_AUX_Locate_Constants1_2sym ;
static ATerm lf_AUX_Locate_Constants1_2 ( ATerm arg1 ) ;
void register_AUX_Locate_Constants1 ( ) {
lf_AUX_Locate_Constants1_1sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_1sym ) ;
lf_AUX_Locate_Constants1_3sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_3sym ) ;
lf_AUX_Locate_Constants1_4sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_4sym ) ;
lf_AUX_Locate_Constants1_5sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_5sym ) ;
lf_AUX_Locate_Constants1_6sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_6sym ) ;
lf_AUX_Locate_Constants1_7sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEELI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_7sym ) ;
lf_AUX_Locate_Constants1_8sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_8sym ) ;
lf_AUX_Locate_Constants1_9sym = ATmakeSymbol ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" , 3 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_9sym ) ;
lf_AUX_Locate_Constants1_2sym = ATmakeSymbol ( "listtype(sort(\"CE-pair\"),ql(\",\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Locate_Constants1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants1_1 , lf_AUX_Locate_Constants1_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CE-pair\"),ql(\",\"))" ) , lf_AUX_Locate_Constants1_2 , lf_AUX_Locate_Constants1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants1_3 , lf_AUX_Locate_Constants1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants1_4 , lf_AUX_Locate_Constants1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Declaration-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEDLI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants1_5 , lf_AUX_Locate_Constants1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Expression\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEEI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants1_6 , lf_AUX_Locate_Constants1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Argument-expression-list\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CEELI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants1_7 , lf_AUX_Locate_Constants1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants1_8 , lf_AUX_Locate_Constants1_8sym ) ;
register_prod ( ATparse ( "prod(id(\"Locate-Constants\"),w(\"\"),[ql(\"(\"),w(\"\"),iter-sep(l(\"{\"),w(\"\"),sort(\"CE-pair\"),w(\"\"),ql(\",\"),w(\"\"),l(\"}\"),w(\"\"),l(\"*\")),w(\"\"),ql(\",\"),w(\"\"),sort(\"Statement-list-opt\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"IntCon\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CESLI-tuple\"),w(\"\"),no-attrs)" ) , lf_AUX_Locate_Constants1_9 , lf_AUX_Locate_Constants1_9sym ) ;
}
void resolve_AUX_Locate_Constants1 ( ) {
}
void init_AUX_Locate_Constants1 ( ) {
}
ATerm lf_AUX_Locate_Constants1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_2sym , ATmakeAppl ( lf_AUX_Locate_Constants1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Locate_Constants1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Locate_Constants1_9 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_9sym , ATmakeAppl ( lf_AUX_Locate_Constants1_9sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_Locate_Constants1_9sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_Locate_Constants1_8 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_8sym , ATmakeAppl ( lf_AUX_Locate_Constants1_8sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_Locate_Constants1_8sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_Locate_Constants1_7 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_7sym , ATmakeAppl ( lf_AUX_Locate_Constants1_7sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_Locate_Constants1_7sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_Locate_Constants1_6 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_6sym , ATmakeAppl ( lf_AUX_Locate_Constants1_6sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_Locate_Constants1_6sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_Locate_Constants1_5 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_5sym , ATmakeAppl ( lf_AUX_Locate_Constants1_5sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_Locate_Constants1_5sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_Locate_Constants1_4 ( ATerm arg0 , ATerm arg1 , ATerm arg2 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_4sym , ATmakeAppl ( lf_AUX_Locate_Constants1_4sym , arg0 , arg1 , arg2 ) ) ;
CONS_EXIT ( make_nf3 ( lf_AUX_Locate_Constants1_4sym , arg0 , arg1 , arg2 ) ) ;
}
ATerm lf_AUX_Locate_Constants1_3 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_3sym , ATmakeAppl ( lf_AUX_Locate_Constants1_3sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Locate_Constants1_3sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_Locate_Constants1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Locate_Constants1_1sym , ATmakeAppl ( lf_AUX_Locate_Constants1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Locate_Constants1_1sym , arg0 , arg1 ) ) ;
}

