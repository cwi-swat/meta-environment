#include  "asc-support.h"
static Symbol lf_AUX_Symbol_Tables1_1sym ;
static ATerm lf_AUX_Symbol_Tables1_1 ( ATerm arg1 , ATerm arg2 ) ;
static Symbol lf_AUX_Symbol_Tables1_3sym ;
static ATerm lf_AUX_Symbol_Tables1_3 ( ATerm arg1 ) ;
static Symbol lf_AUX_Symbol_Tables1_2sym ;
static ATerm lf_AUX_Symbol_Tables1_2 ( ATerm arg1 ) ;
void register_AUX_Symbol_Tables1 ( ) {
lf_AUX_Symbol_Tables1_1sym = ATmakeSymbol ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"STPair\"),w(\"\"),no-attrs)"
 , 2 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbol_Tables1_1sym ) ;
lf_AUX_Symbol_Tables1_3sym = ATmakeSymbol ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"STPair\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbol_Tables1_3sym ) ;
lf_AUX_Symbol_Tables1_2sym = ATmakeSymbol ( "listtype(sort(\"STPair\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbol_Tables1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"<\"),w(\"\"),sort(\"Label\"),w(\"\"),ql(\",\"),w(\"\"),sort(\"LabelSet\"),w(\"\"),ql(\">\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"STPair\"),w(\"\"),no-attrs)" ) , lf_AUX_Symbol_Tables1_1 , lf_AUX_Symbol_Tables1_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"STPair\"))" ) , lf_AUX_Symbol_Tables1_2 , lf_AUX_Symbol_Tables1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"STPair\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Symbol_Tables1_3 , lf_AUX_Symbol_Tables1_3sym ) ;
}
void resolve_AUX_Symbol_Tables1 ( ) {
}
void init_AUX_Symbol_Tables1 ( ) {
}
ATerm lf_AUX_Symbol_Tables1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Symbol_Tables1_2sym , ATmakeAppl ( lf_AUX_Symbol_Tables1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Symbol_Tables1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Symbol_Tables1_3 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Symbol_Tables1_3sym , ATmakeAppl ( lf_AUX_Symbol_Tables1_3sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Symbol_Tables1_3sym , arg0 ) ) ;
}
ATerm lf_AUX_Symbol_Tables1_1 ( ATerm arg0 , ATerm arg1 ) {
CONS_ENTRY ( lf_AUX_Symbol_Tables1_1sym , ATmakeAppl ( lf_AUX_Symbol_Tables1_1sym , arg0 , arg1 ) ) ;
CONS_EXIT ( make_nf2 ( lf_AUX_Symbol_Tables1_1sym , arg0 , arg1 ) ) ;
}

