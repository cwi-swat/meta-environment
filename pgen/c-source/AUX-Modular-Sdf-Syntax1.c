#include  "support.h"
static Symbol lf_AUX_Modular_Sdf_Syntax1_1sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_2sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_4sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_4 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_3sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_5sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_5 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_6sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_6 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_7sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_7 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_8sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_8 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_9sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_9 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_10sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_10 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_12sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_12 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_11sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_11 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_13sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_13 ( ATerm arg1 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_14sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_14 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Modular_Sdf_Syntax1_15sym ;
static ATerm lf_AUX_Modular_Sdf_Syntax1_15 ( ATerm arg1 ) ;
void register_AUX_Modular_Sdf_Syntax1 ( ) {
lf_AUX_Modular_Sdf_Syntax1_1sym = ATmakeSymbol ( "listtype(sort(\"CHAR\"))"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_1sym ) ;
lf_AUX_Modular_Sdf_Syntax1_2sym = ATmakeSymbol ( "prod(id(\"caller\"),w(\"\"),[l(\"moduleid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleId\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_2sym ) ;
lf_AUX_Modular_Sdf_Syntax1_4sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Module\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Definition\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_4sym ) ;
lf_AUX_Modular_Sdf_Syntax1_3sym = ATmakeSymbol ( "listtype(sort(\"Module\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_3sym ) ;
lf_AUX_Modular_Sdf_Syntax1_5sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"exports\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Section\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_5sym ) ;
lf_AUX_Modular_Sdf_Syntax1_6sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"hiddens\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Section\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_6sym ) ;
lf_AUX_Modular_Sdf_Syntax1_7sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_7sym ) ;
lf_AUX_Modular_Sdf_Syntax1_8sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_8sym ) ;
lf_AUX_Modular_Sdf_Syntax1_9sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[l(\"id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_9sym ) ;
lf_AUX_Modular_Sdf_Syntax1_10sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"imports\"),w(\"\"),sort(\"Imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ImpSection\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_10sym ) ;
lf_AUX_Modular_Sdf_Syntax1_12sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Import\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Imports\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_12sym ) ;
lf_AUX_Modular_Sdf_Syntax1_11sym = ATmakeSymbol ( "listtype(sort(\"Import\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_11sym ) ;
lf_AUX_Modular_Sdf_Syntax1_13sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Import\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_13sym ) ;
lf_AUX_Modular_Sdf_Syntax1_14sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleName\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Import\"),w(\"\"),no-attrs)" , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_14sym ) ;
lf_AUX_Modular_Sdf_Syntax1_15sym = ATmakeSymbol ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Import\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Import\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Modular_Sdf_Syntax1_15sym ) ;
register_prod ( ATparse ( "listtype(sort(\"CHAR\"))" ) , lf_AUX_Modular_Sdf_Syntax1_1 , lf_AUX_Modular_Sdf_Syntax1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"caller\"),w(\"\"),[l(\"moduleid\"),w(\"\"),ql(\"(\"),w(\"\"),iter(sort(\"CHAR\"),w(\"\"),l(\"+\")),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleId\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_2 , lf_AUX_Modular_Sdf_Syntax1_2sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Module\"))" ) , lf_AUX_Modular_Sdf_Syntax1_3 , lf_AUX_Modular_Sdf_Syntax1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Module\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Definition\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_4 , lf_AUX_Modular_Sdf_Syntax1_4sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"exports\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Section\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_5 , lf_AUX_Modular_Sdf_Syntax1_5sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"hiddens\"),w(\"\"),sort(\"Grammar\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Section\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_6 , lf_AUX_Modular_Sdf_Syntax1_6sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_7 , lf_AUX_Modular_Sdf_Syntax1_7sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleId\"),w(\"\"),ql(\"[\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_8 , lf_AUX_Modular_Sdf_Syntax1_8sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[l(\"id\"),w(\"\"),l(\"(\"),w(\"\"),sort(\"ModuleName\"),w(\"\"),l(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Attribute\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_9 , lf_AUX_Modular_Sdf_Syntax1_9sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"imports\"),w(\"\"),sort(\"Imports\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"ImpSection\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_10 , lf_AUX_Modular_Sdf_Syntax1_10sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Import\"))" ) , lf_AUX_Modular_Sdf_Syntax1_11 , lf_AUX_Modular_Sdf_Syntax1_11sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[iter(sort(\"Import\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Imports\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_12 , lf_AUX_Modular_Sdf_Syntax1_12sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleName\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Import\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_13 , lf_AUX_Modular_Sdf_Syntax1_13sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[sort(\"ModuleName\"),w(\"\"),sort(\"Renamings\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Import\"),w(\"\"),no-attrs)" ) , lf_AUX_Modular_Sdf_Syntax1_14 , lf_AUX_Modular_Sdf_Syntax1_14sym ) ;
register_prod ( ATparse ( "prod(id(\"Modular-Sdf-Syntax\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"Import\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Import\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Modular_Sdf_Syntax1_15 , lf_AUX_Modular_Sdf_Syntax1_15sym ) ;
}
void resolve_AUX_Modular_Sdf_Syntax1 ( ) {
}
void init_AUX_Modular_Sdf_Syntax1 ( ) {
}
ATerm lf_AUX_Modular_Sdf_Syntax1_15 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_15sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_15sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_15sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_14 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_14sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_14sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Modular_Sdf_Syntax1_14sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_13 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_13sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_13sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_13sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_11 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_11sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_11sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_11sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_12 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_12sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_12sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_12sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_10 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_10sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_10sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_10sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_9 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_9sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_9sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_9sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_8 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_8sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_8sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Modular_Sdf_Syntax1_8sym , arg0 , arg1 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_7 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_7sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_7sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_7sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_6 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_6sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_6sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_6sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_5 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_5sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_5sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_5sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_3sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_4sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_2sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Modular_Sdf_Syntax1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Modular_Sdf_Syntax1_1sym , ATmakeAppl ( lf_AUX_Modular_Sdf_Syntax1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Modular_Sdf_Syntax1_1sym , arg0 ) ) ;
}

