#include  "asc-support.h"
static Symbol lf_AUX_C1_2sym ;
static ATerm lf_AUX_C1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_C1_3sym ;
static ATerm lf_AUX_C1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_C1_1sym ;
static ATerm lf_AUX_C1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_C1_4sym ;
static ATerm lf_AUX_C1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_C1_5sym ;
static ATerm lf_AUX_C1_5 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_C1_6sym ;
static ATerm lf_AUX_C1_6 ( ATerm arg1 ) ;
static Symbol lf_AUX_C1_7sym ;
static ATerm lf_AUX_C1_7 ( ATerm arg1 ) ;
static Symbol lf_AUX_C1_8sym ;
static ATerm lf_AUX_C1_8 ( ATerm arg1 , ATerm arg2 ) ;
void register_AUX_C1 ( ) {
lf_AUX_C1_2sym = ATmakeSymbol ( "prod(id(\"caller\"),w(\"\"),[l(\"cdir\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CDir\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C1_2sym ) ;
lf_AUX_C1_3sym = ATmakeSymbol ( "prod(id(\"caller\"),w(\"\"),[l(\"cdirs\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CDirs\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C1_3sym ) ;
lf_AUX_C1_1sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C1_1sym ) ;
lf_AUX_C1_4sym = ATmakeSymbol ( "prod(id(\"caller\"),w(\"\"),[l(\"cfilename\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CFilename\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C1_4sym ) ;
lf_AUX_C1_5sym = ATmakeSymbol ( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDES\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C1_5sym ) ;
lf_AUX_C1_6sym = ATmakeSymbol ( "prod(id(\"C\"),w(\"\"),[ql(\"#include\"),w(\"\"),sort(\"CFilename\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDE\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C1_6sym ) ;
lf_AUX_C1_7sym = ATmakeSymbol ( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDE\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDES\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C1_7sym ) ;
lf_AUX_C1_8sym = ATmakeSymbol ( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDES\"),w(\"\"),sort(\"INCLUDE\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDES\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_C1_8sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf_AUX_C1_1 , lf_AUX_C1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"caller\"),w(\"\"),[l(\"cdir\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CDir\"),w(\"\"),no-attrs)" ) , lf_AUX_C1_2 , lf_AUX_C1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"caller\"),w(\"\"),[l(\"cdirs\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CDirs\"),w(\"\"),no-attrs)" ) , lf_AUX_C1_3 , lf_AUX_C1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"caller\"),w(\"\"),[l(\"cfilename\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CFilename\"),w(\"\"),no-attrs)" ) , lf_AUX_C1_4 , lf_AUX_C1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDES\"),w(\"\"),sort(\"Declaration-list-opt\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"CProgram\"),w(\"\"),no-attrs)" ) , lf_AUX_C1_5 , lf_AUX_C1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"C\"),w(\"\"),[ql(\"#include\"),w(\"\"),sort(\"CFilename\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDE\"),w(\"\"),no-attrs)" ) , lf_AUX_C1_6 , lf_AUX_C1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDE\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDES\"),w(\"\"),no-attrs)" ) , lf_AUX_C1_7 , lf_AUX_C1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"C\"),w(\"\"),[sort(\"INCLUDES\"),w(\"\"),sort(\"INCLUDE\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"INCLUDES\"),w(\"\"),no-attrs)" ) , lf_AUX_C1_8 , lf_AUX_C1_8sym ) ;
}
void resolve_AUX_C1 ( ) {
}
void init_AUX_C1 ( ) {
}
ATerm lf_AUX_C1_8 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_C1_8sym , ATmakeAppl ( lf_AUX_C1_8sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_C1_8sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_C1_7 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C1_7sym , ATmakeAppl ( lf_AUX_C1_7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C1_7sym , arg0 ) ) ;
}
ATerm lf_AUX_C1_6 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C1_6sym , ATmakeAppl ( lf_AUX_C1_6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C1_6sym , arg0 ) ) ;
}
ATerm lf_AUX_C1_5 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_C1_5sym , ATmakeAppl ( lf_AUX_C1_5sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_C1_5sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_C1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C1_4sym , ATmakeAppl ( lf_AUX_C1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_C1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C1_1sym , ATmakeAppl ( lf_AUX_C1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C1_1sym , arg0 ) ) ;
}
ATerm lf_AUX_C1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C1_3sym , ATmakeAppl ( lf_AUX_C1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_C1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_C1_2sym , ATmakeAppl ( lf_AUX_C1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_C1_2sym , arg0 ) ) ;
}

