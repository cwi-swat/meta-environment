#include  "asc-support.h"
static Symbol lf_AUX_Pos_Constructors1_1sym ;
static ATerm lf_AUX_Pos_Constructors1_1 ( ) ;
static Symbol lf_AUX_Pos_Constructors1_2sym ;
static ATerm lf_AUX_Pos_Constructors1_2 ( ) ;
void register_AUX_Pos_Constructors1 ( ) {
lf_AUX_Pos_Constructors1_1sym = ATmakeSymbol ( "prod(id(\"Pos-Constructors\"),w(\"\"),[ql(\"pos-info\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)"
 , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Pos_Constructors1_1sym ) ;
lf_AUX_Pos_Constructors1_2sym = ATmakeSymbol ( "prod(id(\"Pos-Constructors\"),w(\"\"),[ql(\"pos\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" , 0 , ATtrue ) ;
ATprotectSymbol ( lf_AUX_Pos_Constructors1_2sym ) ;
register_prod ( ATparse ( "prod(id(\"Pos-Constructors\"),w(\"\"),[ql(\"pos-info\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_Pos_Constructors1_1 , lf_AUX_Pos_Constructors1_1sym ) ;
register_prod ( ATparse ( "prod(id(\"Pos-Constructors\"),w(\"\"),[ql(\"pos\")],w(\"\"),l(\"->\"),w(\"\"),sort(\"AFun\"),w(\"\"),no-attrs)" ) , lf_AUX_Pos_Constructors1_2 , lf_AUX_Pos_Constructors1_2sym ) ;
}
void resolve_AUX_Pos_Constructors1 ( ) {
}
void init_AUX_Pos_Constructors1 ( ) {
}
ATerm lf_AUX_Pos_Constructors1_2 ( ) {
CONS_ENTRY ( lf_AUX_Pos_Constructors1_2sym , ATmakeAppl0 ( lf_AUX_Pos_Constructors1_2sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_Pos_Constructors1_2sym ) ) ;
}
ATerm lf_AUX_Pos_Constructors1_1 ( ) {
CONS_ENTRY ( lf_AUX_Pos_Constructors1_1sym , ATmakeAppl0 ( lf_AUX_Pos_Constructors1_1sym ) ) ;
CONS_EXIT ( make_nf0 ( lf_AUX_Pos_Constructors1_1sym ) ) ;
}

