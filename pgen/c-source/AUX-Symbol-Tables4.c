#include  "asc-support.h"
static Symbol lf_AUX_Symbol_Tables4_1sym ;
static ATerm lf_AUX_Symbol_Tables4_1 ( ) ;
static Symbol ef1sym ;
static funcptr ef1 ;
static Symbol lf2sym ;
static ATerm lf2 ( ATerm arg1 ) ;
void register_AUX_Symbol_Tables4 ( ) {
lf_AUX_Symbol_Tables4_1sym = ATmakeSymbol ( "prod(id(\"Symbol-Tables\"),w(\"\"),[l(\"new-symbol-table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Symbol_Tables4_1sym ) ;
lf2sym = ATmakeSymbol ( "listtype(sort(\"STPair\"))" , 1 , ATtrue ) ;
ATprotectSymbol ( lf2sym ) ;
register_prod ( ATparse ( "prod(id(\"Symbol-Tables\"),w(\"\"),[l(\"new-symbol-table\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) , lf_AUX_Symbol_Tables4_1 , lf_AUX_Symbol_Tables4_1sym ) ;
register_prod ( ATparse ( "listtype(sort(\"STPair\"))" ) , lf2 , lf2sym ) ;
}
void resolve_AUX_Symbol_Tables4 ( ) {
ef1 = lookup_func ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"STPair\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
ef1sym = lookup_sym ( ATreadFromString ( "prod(id(\"Symbol-Tables\"),w(\"\"),[ql(\"[\"),w(\"\"),iter(sort(\"STPair\"),w(\"\"),l(\"*\")),w(\"\"),ql(\"]\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"Symbol-Table\"),w(\"\"),no-attrs)" ) ) ;
}
static ATerm constant0 = NULL ;
static ATerm constant1 = NULL ;
void init_AUX_Symbol_Tables4 ( ) {
ATprotect ( & constant0 ) ;
ATprotect ( & constant1 ) ;
}
ATerm lf_AUX_Symbol_Tables4_1 ( ) {
FUNC_ENTRY ( lf_AUX_Symbol_Tables4_1sym , ATmakeAppl0 ( lf_AUX_Symbol_Tables4_1sym ) ) ;
FUNC_EXIT_CONST ( constant0 , ( * ef1 ) ( lf2 ( make_list ( null ( ) ) ) ) ) ;
FUNC_EXIT_CONST ( constant1 , make_nf0 ( lf_AUX_Symbol_Tables4_1sym ) ) ;
}
ATerm lf2 ( ATerm arg0 ) {
CONS_ENTRY ( lf2sym , ATmakeAppl ( lf2sym , arg0 ) ) ;
CONS_EXIT ( make_nf1 ( lf2sym , arg0 ) ) ;
}

