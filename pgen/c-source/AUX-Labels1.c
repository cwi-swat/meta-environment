#include  "asc-support.h"
static Symbol lf_AUX_Labels1_2sym ;
static ATerm lf_AUX_Labels1_2 ( ATerm arg1 ) ;
static Symbol lf_AUX_Labels1_1sym ;
static ATerm lf_AUX_Labels1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Labels1_3sym ;
static ATerm lf_AUX_Labels1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Labels1_4sym ;
static ATerm lf_AUX_Labels1_4 ( ATerm arg1 ) ;
void register_AUX_Labels1 ( ) {
lf_AUX_Labels1_2sym = ATmakeSymbol ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Labels1_2sym ) ;
lf_AUX_Labels1_1sym = ATmakeSymbol ( "listtype(sort(\"Label\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Labels1_1sym ) ;
lf_AUX_Labels1_3sym = ATmakeSymbol ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Labels1_3sym ) ;
lf_AUX_Labels1_4sym = ATmakeSymbol ( "prod(id(\"Labels\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Labels1_4sym ) ;
register_prod ( ATparse ( "listtype(sort(\"Label\"))" ) , lf_AUX_Labels1_1 , lf_AUX_Labels1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Labels\"),w(\"\"),[iter(sort(\"Label\"),w(\"\"),l(\"*\"))],w(\"\"),l(\"->\"),w(\"\"),sort(\"Labels\"),w(\"\"),no-attrs)" ) , lf_AUX_Labels1_2 , lf_AUX_Labels1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Labels\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Labels\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Labels1_3 , lf_AUX_Labels1_3sym ) ;
register_prod ( ATparse ( "prod(id(\"Labels\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Labels1_4 , lf_AUX_Labels1_4sym ) ;
}
void resolve_AUX_Labels1 ( ) {
}
void init_AUX_Labels1 ( ) {
}
ATerm lf_AUX_Labels1_4 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Labels1_4sym , ATmakeAppl ( lf_AUX_Labels1_4sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Labels1_4sym , arg0 ) ) ;
}
ATerm lf_AUX_Labels1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Labels1_3sym , ATmakeAppl ( lf_AUX_Labels1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Labels1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Labels1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Labels1_1sym , ATmakeAppl ( lf_AUX_Labels1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Labels1_1sym , arg0 ) ) ;
}
ATerm lf_AUX_Labels1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Labels1_2sym , ATmakeAppl ( lf_AUX_Labels1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Labels1_2sym , arg0 ) ) ;
}

