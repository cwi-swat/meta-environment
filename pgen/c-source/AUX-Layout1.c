#include  "asc-support.h"
static Symbol lf_AUX_Layout1_1sym ;
static ATerm lf_AUX_Layout1_1 ( ) ;
void register_AUX_Layout1 ( ) {
lf_AUX_Layout1_1sym = ATmakeSymbol ( "prod(id(\"Layout\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"TagId\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Layout1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Layout\"),w(\"\"),[],w(\"\"),l(\"->\"),w(\"\"),sort(\"TagId\"),w(\"\"),no-attrs)" ) , lf_AUX_Layout1_1 , lf_AUX_Layout1_1sym ) ;
}
void resolve_AUX_Layout1 ( ) {
}
static ATerm constant0 = NULL ;
void init_AUX_Layout1 ( ) {
ATprotect ( & constant0 ) ;
}
ATerm lf_AUX_Layout1_1 ( ) {
CONS_ENTRY ( lf_AUX_Layout1_1sym , ATmakeAppl0 ( lf_AUX_Layout1_1sym ) ) ;
CONS_EXIT_CONST ( constant0 , make_nf0 ( lf_AUX_Layout1_1sym ) ) ;
}

