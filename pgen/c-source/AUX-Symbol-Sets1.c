#include  "support.h"
static Symbol lf_AUX_Symbol_Sets1_1sym ;
static ATerm lf_AUX_Symbol_Sets1_1 ( ATerm arg1 ) ;
static Symbol lf_AUX_Symbol_Sets1_2sym ;
static ATerm lf_AUX_Symbol_Sets1_2 ( ATerm arg1 ) ;
void register_AUX_Symbol_Sets1 ( ) {
lf_AUX_Symbol_Sets1_1sym = ATmakeSymbol ( "prod(id(\"Symbol-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),no-attrs)"
 , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbol_Sets1_1sym ) ;
lf_AUX_Symbol_Sets1_2sym = ATmakeSymbol ( "prod(id(\"Symbol-Sets\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbol_Sets1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Symbol-Sets\"),w(\"\"),[ql(\"{\"),w(\"\"),sort(\"Symbols\"),w(\"\"),ql(\"}\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),no-attrs)" ) , lf_AUX_Symbol_Sets1_1 , lf_AUX_Symbol_Sets1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Symbol-Sets\"),w(\"\"),[ql(\"(\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),ql(\")\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"SymbolSet\"),w(\"\"),attrs(l(\"{\"),w(\"\"),[l(\"bracket\")],w(\"\"),l(\"}\")))" ) , lf_AUX_Symbol_Sets1_2 , lf_AUX_Symbol_Sets1_2sym ) ;
}
void resolve_AUX_Symbol_Sets1 ( ) {
}
void init_AUX_Symbol_Sets1 ( ) {
}
ATerm lf_AUX_Symbol_Sets1_2 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Symbol_Sets1_2sym , ATmakeAppl ( lf_AUX_Symbol_Sets1_2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Symbol_Sets1_2sym , arg0 ) ) ;
}
ATerm lf_AUX_Symbol_Sets1_1 ( ATerm arg0 ) {
CONS_ENTRY ( lf_AUX_Symbol_Sets1_1sym , ATmakeAppl ( lf_AUX_Symbol_Sets1_1sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf_AUX_Symbol_Sets1_1sym , arg0 ) ) ;
}

